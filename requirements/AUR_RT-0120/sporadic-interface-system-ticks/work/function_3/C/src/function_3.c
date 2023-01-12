/* Body file for function Function_3
 * Generated by TASTE on 2022-10-07 15:26:42
 * You can edit this file, it will not be overwritten
 * Provided interfaces : PI_1, PI_2, PI_3
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Startup_Priority = 1
 * Timers              : 
 */

#include "function_3.h"
#include <Perfmon.h>
#include <rtems/bspIo.h>
#include <stdbool.h>
#include <string.h>

Perf_Mon G_perf_mon_ctx;

void print_rtems(const char *str)
{
  while (*str != '\0') {
    rtems_putc( *(str++));
  }
}

bool check_test_data(const Interface_Usage_Data data, const char *interface_name)
{
    if(strcmp(data.interface_name, interface_name) != 0)
    {
        print_rtems("Error: interface_name is not consistent");
        return false;
    }

    if(data.system_ticks_spent_by_interface_min_val <= 0)
    {
        print_rtems("Error: system_ticks_spent_by_interface_min_val is 0 or less");
        return false;
    }

    if(data.system_ticks_spent_by_interface_max_val <= 0.0 ||
        data.system_ticks_spent_by_interface_max_val < data.system_ticks_spent_by_interface_min_val)
    {
        print_rtems("Error: system_ticks_spent_by_interface_max_val is less than 0 or is inconsistent");
        return false;
    }

    if(data.cpu_usage_mean_val <= 0.0 ||
        data.system_ticks_spent_by_interface_mean_val < data.system_ticks_spent_by_interface_min_val ||
        data.system_ticks_spent_by_interface_mean_val > data.system_ticks_spent_by_interface_max_val)
    {
        print_rtems("Error: system_ticks_spent_by_interface_mean_val is less than 0 or is inconsistent");
        return false;
    }

    return true;
}


void function_3_startup(void)
{
    Perf_Mon_init(&G_perf_mon_ctx);
}

void function_3_PI_PerfMon(void)
{
    static uint32_t test_iterator = 0;

    Perf_Mon_tick(&G_perf_mon_ctx);

    if(test_iterator == 10)
    {
        const Interface_Usage_Data data_function_1_pi_1 =
                Perf_Mon_getUsageData(&G_perf_mon_ctx, function_1_pi_1, 1000000);
        const Interface_Usage_Data data_function_1_pi_2 =
                Perf_Mon_getUsageData(&G_perf_mon_ctx, function_1_pi_2, 1000000);

        if(check_test_data(data_function_1_pi_1, "function_1_pi_1") &&
                check_test_data(data_function_1_pi_2, "function_1_pi_2"))
        {
            print_rtems("perfmon test - OK\n");
        }
    }
    test_iterator++;
}


