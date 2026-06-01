#include "interfaces.h"

void power_dispatch_step(const sensor_snapshot_t* s, actuator_command_t* out) {
    (void)s;
    if (state_machine_get() == SYS_HYBRID_RUN) {
        out->blower_enable = true;
        if (out->blower_pwm_pct < 45) {
            out->blower_pwm_pct = 45;
        }
    }
}
