#include "interfaces.h"

void task_control_100hz(void) {
    sensor_snapshot_t s = {0};
    actuator_command_t a = {0};

    hal_read_sensors(&s);
    state_machine_step(&s, &a);
    power_dispatch_step(&s, &a);
    hal_apply_actuators(&a);
}
