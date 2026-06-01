#include "interfaces.h"
#include "config.h"

void task_safety_1khz(void) {
    sensor_snapshot_t s = {0};
    hal_read_sensors(&s);

    if (s.h2_ppm >= H2_LEAK_THRESHOLD_PPM) {
        fault_manager_raise(FAULT_H2_LEAK);
    }
    if (s.stack_temp_c >= STACK_TEMP_MAX_C || s.battery_temp_c >= BATTERY_TEMP_MAX_C) {
        fault_manager_raise(FAULT_OVERTEMP);
    }
    if (s.h2_pressure_bar > H2_PRESSURE_MAX_BAR) {
        fault_manager_raise(FAULT_OVERPRESSURE);
    }
}
