#include "interfaces.h"
#include "config.h"

int main(void) {
    sensor_snapshot_t sensors = {0};
    actuator_command_t actuators = {0};

    hal_init();
    state_machine_init();

    while (1) {
        hal_read_sensors(&sensors);
        state_machine_step(&sensors, &actuators);
        power_dispatch_step(&sensors, &actuators);
        hal_apply_actuators(&actuators);
    }

    return 0;
}
