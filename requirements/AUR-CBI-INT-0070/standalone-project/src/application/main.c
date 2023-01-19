#include "algorithms_vm_if.h"
#include "controller_vm_if.h"
#include "dataview-uniq.h"

#include <stddef.h>
#include <stdio.h>

// functions required by controller
void vm_controller_calculate_mppt(asn1SccPID pid, void *voltage, size_t voltage_size, void *current,
        size_t current_size, void *pwm, size_t *pwm_size)
{
    algorithms_calculate_mppt(voltage, voltage_size, current, current_size, pwm, pwm_size);
}

void vm_controller_calculate_pid(asn1SccPID pid, void *output_value, size_t *output_value_size, void *k_p,
        size_t k_p_size, void *k_i, size_t k_i_size, void *k_d, size_t k_d_size, void *input_value,
        size_t input_value_size, void *target_value, size_t target_value_size)
{
    algorithms_calculate_pid(output_value, output_value_size, k_p, k_p_size, k_i, k_i_size, k_d, k_d_size, input_value,
            input_value_size, target_value, target_value_size);
}
void vm_controller_controller_status(asn1SccPID pid, void *status, size_t status_size) {}
void vm_controller_get_battery_capacity(asn1SccPID pid, void *capacity, size_t *capacity_size) {}
void vm_controller_get_payload_status(
        asn1SccPID pid, void *temperature, size_t *temperature_size, void *flow_rate, size_t *flow_rate_size)
{
}
void vm_controller_get_solar_panel_status(
        asn1SccPID pid, void *voltatge, size_t *voltage_size, void *current, size_t *current_size)
{
}
void vm_controller_set_flow_controller(asn1SccPID pid, void *pwm, size_t pwm_size) {}
void vm_controller_set_power_point(asn1SccPID pid, void *pwm, size_t pwm_size) {}

void controller_step_get_sender(asn1SccPID *sender_pid) {}

void algorithms_calculate_mppt_get_sender(asn1SccPID *sender_pid)
{
}

void algorithms_calculate_pid_get_sender(asn1SccPID *sender_pid)
{
}

int main(int argc, char *argv[])
{
    init_algorithms();
    init_controller();
    printf("Hello world\n");
    return 0;
}
