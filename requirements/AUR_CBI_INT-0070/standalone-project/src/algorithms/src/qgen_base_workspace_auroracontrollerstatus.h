/* Copyright (C) Your Company Name */
/*
 * @generated with QGen Code Generator 23.0w (20211221)
 * Command line arguments: ./xmi/calculate_pid.xmi
 *   --gen-entrypoint
 *   --wrap-io
 *   --pre-process-xmi
 *   --incremental
 *   --no-misra
 *   --language c
 *   --output src
*/

#ifndef QGEN_BASE_WORKSPACE_AURORACONTROLLERSTATUS_H
#define QGEN_BASE_WORKSPACE_AURORACONTROLLERSTATUS_H
#include "qgen_types.h"

typedef struct {
   GAREAL payload_temperature;
   GAREAL payload_flow_rate;
   GAREAL battery_capacity;
   GAREAL solar_panel_voltage;
   GAREAL solar_panel_current;
} AuroraControllerStatus;

#endif
/*  @EOF  */
