#include "algorithms_vm_if.h"
#include "controller_vm_if.h"
#include "dataview-uniq.h"

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#define MEGA 1000000L

static double flow_rate_value;
static double battery_capacity;
static double solar_panel_voltage;
static double solar_panel_current;
static double solar_panel_pwm;

static int electric_power_supply_step_count;
static double electric_power_supply_amp_40;
static double electric_power_supply_amp_20;
static double electric_power_supply_amp_10;
static double electric_power_supply_amp_5;

static double payload_temperature;
static double payload_flow_rate;
static double payload_target_flow_rate;

static int payload_step_count;

static double payload_amp_100;
static double payload_amp_50;
static double payload_amp_25;

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

void vm_controller_controller_status(asn1SccPID pid, void *status, size_t status_size)
{
    if (status_size != sizeof(asn1SccAuroraControllerStatus)) {
        printf("Invalid data in status\n");
        fflush(stdout);
    } else {
        asn1SccAuroraControllerStatus *controller_status = (asn1SccAuroraControllerStatus *)status;
        printf("Status | Temp: %03.6f | Flow: %03.6f | Capacity: %03.6f | Voltage: %03.6f | Current: %03.6f\n",
                controller_status->payload_temperature, controller_status->payload_flow_rate,
                controller_status->battery_capacity, controller_status->solar_panel_voltage,
                controller_status->solar_panel_current);
        fflush(stdout);
    }
}

void vm_controller_get_battery_capacity(asn1SccPID pid, void *capacity, size_t *capacity_size)
{
    asn1SccAuroraReal *capacity_value = (asn1SccAuroraReal *)capacity;
    *capacity_value = battery_capacity;
    *capacity_size = sizeof(asn1SccAuroraReal);
}

void vm_controller_get_payload_status(
        asn1SccPID pid, void *temperature, size_t *temperature_size, void *flow_rate, size_t *flow_rate_size)
{
    asn1SccAuroraReal *temperature_value = (asn1SccAuroraReal *)temperature;
    *temperature_value = payload_temperature;
    *temperature_size = sizeof(asn1SccAuroraReal);
    asn1SccAuroraReal *flow_rate_value = (asn1SccAuroraReal *)flow_rate;
    *flow_rate_value = payload_flow_rate;
    *flow_rate_size = sizeof(asn1SccAuroraReal);
}

void vm_controller_get_solar_panel_status(
        asn1SccPID pid, void *voltage, size_t *voltage_size, void *current, size_t *current_size)
{
    asn1SccAuroraReal *voltage_value = (asn1SccAuroraReal *)voltage;
    *voltage_value = solar_panel_voltage;
    *voltage_size = sizeof(asn1SccAuroraReal);
    asn1SccAuroraReal *current_value = (asn1SccAuroraReal *)current;
    *current_value = solar_panel_current;
    *current_size = sizeof(asn1SccAuroraReal);
}

void vm_controller_set_flow_controller(asn1SccPID pid, void *pwm, size_t pwm_size)
{
    if (pwm_size != sizeof(asn1SccAuroraReal)) {
        printf("Invalid data in set_flow_controller\n");
    } else {
        payload_target_flow_rate = *((asn1SccAuroraReal *)pwm);
        flow_rate_value = payload_target_flow_rate;
    }
}

void vm_controller_set_power_point(asn1SccPID pid, void *pwm, size_t pwm_size)
{
    if (pwm_size != sizeof(asn1SccAuroraReal)) {
        printf("Invalid data in set_power_point\n");
    } else {
        solar_panel_pwm = *((asn1SccAuroraReal *)pwm);
    }
}

asn1SccPID controller_step_get_sender()
{
    return PID_master_clock;
}

asn1SccPID algorithms_calculate_mppt_get_sender()
{
    return PID_controller;
}

asn1SccPID algorithms_calculate_pid_get_sender()
{
    return PID_controller;
}

void init_eps()
{
    srand(time(NULL));
    flow_rate_value = 0.0;
    battery_capacity = 0.48;
    solar_panel_voltage = 9.3;
    solar_panel_current = 1.3;
    solar_panel_pwm = 0.0;

    electric_power_supply_step_count = 0;
    electric_power_supply_amp_40 = 0.0;
    electric_power_supply_amp_20 = 0.0;
    electric_power_supply_amp_10 = 0.0;
    electric_power_supply_amp_5 = 0.0;
}

void init_payload()
{
    payload_temperature = 18.0;
    payload_flow_rate = 4.0;
    payload_target_flow_rate = 0.0;

    payload_step_count = 0;
    payload_amp_100 = 0.0;
    payload_amp_50 = 0.0;
    payload_amp_25 = 0.0;
}

// application
void init_application()
{
    init_eps();
    init_payload();
}

void eps_calculate_random_coefficients()
{
    if (electric_power_supply_step_count == 0) {
        electric_power_supply_amp_40 = 0.8 * (rand() / (RAND_MAX - 2.0) - 1.0);
    }
    if (electric_power_supply_step_count % 20 == 0) {
        electric_power_supply_amp_20 = 0.6 * (rand() / (RAND_MAX - 2.0) - 1.0);
    }
    if (electric_power_supply_step_count % 10 == 0) {
        electric_power_supply_amp_10 = 0.4 * (rand() / (RAND_MAX - 2.0) - 1.0);
    }
    if (electric_power_supply_step_count % 5 == 0) {
        electric_power_supply_amp_5 = 0.2 * (rand() / (RAND_MAX - 2.0) - 1.0);
    }
}

void eps_simulate_solar_panel_voltage()
{
    solar_panel_voltage = 5.0;

    solar_panel_voltage +=
            2.5 * electric_power_supply_amp_40 * sin(2 * M_PI * ((electric_power_supply_step_count % 40) * 0.025));
    solar_panel_voltage +=
            2.5 * electric_power_supply_amp_20 * sin(2 * M_PI * ((electric_power_supply_step_count % 20) * 0.05));
    solar_panel_voltage +=
            2.5 * electric_power_supply_amp_10 * sin(2 * M_PI * ((electric_power_supply_step_count % 10) * 0.1));
    solar_panel_voltage +=
            2.5 * electric_power_supply_amp_5 * sin(2 * M_PI * ((electric_power_supply_step_count % 5) * 0.2));
}

void eps_step()
{
    eps_calculate_random_coefficients();
    eps_simulate_solar_panel_voltage();

    double power = sin(M_PI * solar_panel_pwm * solar_panel_pwm);
    solar_panel_current = power * solar_panel_voltage / 20.0;

    double outpower = flow_rate_value * 3.0;

    battery_capacity += (power - outpower) / 1000.0;

    if (battery_capacity < 0.0) {
        battery_capacity = 0.0;
    }
    if (battery_capacity > 1.0) {
        battery_capacity = 1.0;
    }

    ++electric_power_supply_step_count;
    if (electric_power_supply_step_count == 40) {
        electric_power_supply_step_count = 0;
    }
}

void payload_calculate_random_coefficients()
{
    if (payload_step_count == 0) {
        payload_amp_100 = 0.5 * (rand() / (RAND_MAX - 2.0) - 1.0);
    }

    if (payload_step_count % 50 == 0) {
        payload_amp_50 = 0.4 * (rand() / (RAND_MAX - 2.0) - 1.0);
    }

    if (payload_step_count % 25 == 0) {
        payload_amp_25 = 0.2 * (rand() / (RAND_MAX - 2.0) - 1.0);
    }
}

void payload_step()
{
    payload_calculate_random_coefficients();
    payload_flow_rate = payload_target_flow_rate * 20;

    payload_temperature = 305.0 + 20.0 * payload_amp_100 * sin(2.0 * M_PI * ((payload_step_count % 100) * 0.001))
            + 20.0 * payload_amp_50 * sin(2.0 * M_PI * ((payload_step_count % 50) * 0.02))
            + 20.0 * payload_amp_25 * sin(2.0 * M_PI * ((payload_step_count % 25) * 0.04)) + payload_flow_rate / 5.0;

    ++payload_step_count;

    if (payload_step_count == 100) {
        payload_step_count = 0;
    }
}

void application_step()
{
    eps_step();
    payload_step();
}

useconds_t calculate_sleep_time(struct timeval *start_tv, struct timeval *end_tv)
{
    if (start_tv->tv_sec == end_tv->tv_sec) {
        int usec = end_tv->tv_usec - start_tv->tv_usec;

        return MEGA - usec;
    }
    if (start_tv->tv_sec + 1 == end_tv->tv_sec) {
        int usec = MEGA - start_tv->tv_usec + end_tv->tv_usec;

        return MEGA - usec;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    init_algorithms();
    init_controller();

    init_application();

    struct timeval start_tv;
    struct timeval end_tv;

    struct timespec sleep_ts;
    struct timespec remaining_ts;

    useconds_t usec;

    while (true) {
        gettimeofday(&start_tv, NULL);

        application_step();
        controller_step();

        gettimeofday(&end_tv, NULL);

        usec = calculate_sleep_time(&start_tv, &end_tv);

        usleep(usec * 1UL);
    }

    return 0;
}
