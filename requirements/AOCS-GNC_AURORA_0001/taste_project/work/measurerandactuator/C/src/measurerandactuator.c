//  ------------------------------------------------------------------------
//
//                           Q G e n   T u t o r i a l
//
//                        Measurer and Actuator component
//
//           Copyright (C) 2022 Universidad Politécnica de Madrid
//
//  This is free software;  you can redistribute it  and/or modify it  under
//  terms of the  GNU General Public License as published  by the Free Soft-
//  ware  Foundation;  either version 3,  or (at your option) any later ver-
//  sion.  This software is distributed in the hope  that it will be useful,
//  but WITHOUT ANY WARRANTY;  without even the implied warranty of MERCHAN-
//  TABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
//  License for  more details.  You should have  received  a copy of the GNU
//  General  Public  License  distributed  with  this  software;   see  file
//  COPYING3.  If not, go to http://www.gnu.org/licenses for a complete copy
//  of the license.
//
//  ------------------------------------------------------------------------

/* Body file for function Measurer_And_Actuator
 * Provided interfaces : Tick
 * Required interfaces : Read_MGM, Step, control_MGT
 * User-defined properties for this function:
 * Timers              :
 */

#include "measurerandactuator.h"

#include <stdio.h>

static volatile bool is_simulation_run = false;

// ==================================
// Provided interfaces implementation
// ==================================

void measurerandactuator_startup(void)
{
    puts ("[Measurer_And_Actuator] Startup");
}

void measurerandactuator_PI_TC( const asn1SccT_Telecommand *IN_telecommand)
{
    asn1SccT_UInteger32 step_value = 0;

    switch(IN_telecommand->kind)
    {
        case T_Telecommand_m_start_PRESENT:
            printf("the simulation has been started\n");
            is_simulation_run = true;
            break;
        case T_Telecommand_m_pause_PRESENT:
            printf("the simulation has been paused\n");
            is_simulation_run = false;
            break;

        case T_Telecommand_m_restart_PRESENT:
            printf("the simulation has been restarted\n");
            step_value = 0;
            measurerandactuator_RI_set_step( &step_value );
            break;

        case T_Telecommand_m_stop_PRESENT:
            printf("the simulation has been stopped\n");
            step_value = 1000;
            measurerandactuator_RI_set_step( &step_value );
            break;
    }
}

void measurerandactuator_PI_Tick(void)
{
    if(!is_simulation_run)
        return;

    asn1SccT_B_b_T bbt;
    asn1SccT_Omega omega = {
        .arr = {0.0F, 0.0F, 0.1F}
    };
    asn1SccT_Float k_pb = 2.0F;
    asn1SccT_Float k_pe = 8.0F;
    asn1SccT_Float m_m  = 15.0F;
    asn1SccT_MT_Working mt_working = {
        .arr = {1.0F, 1.0F, 1.0F}
    };
    asn1SccT_Control control;
    asn1SccT_UInteger32 step;

    measurerandactuator_RI_Read_MGM(&bbt);
    measurerandactuator_RI_Step(&bbt, &omega, &k_pb, &k_pe, &m_m, &mt_working, &control);
    measurerandactuator_RI_control_MGT(&control);
    measurerandactuator_RI_get_step(&step);

    asn1SccT_Telemetry report = {bbt, control, step};

    for(int i = 0; i < 15; ++i) {
        report.m_sensors.arr[i] *= 10000;
    }

    measurerandactuator_RI_TM(&report);
}
