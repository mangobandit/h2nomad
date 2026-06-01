#include "interfaces.h"
#include "config.h"

static system_state_t g_state = SYS_INIT;

static bool precharge_ready(const sensor_snapshot_t* s) {
    return s->bus_voltage_mv >= BUS_VOLTAGE_PRECHARGE_MV;
}

void state_machine_init(void) {
    g_state = SYS_INIT;
}

system_state_t state_machine_get(void) {
    return g_state;
}

void state_machine_step(const sensor_snapshot_t* s, actuator_command_t* out) {
    if (fault_manager_is_latched()) {
        g_state = SYS_FAULT_LATCH;
    }

    switch (g_state) {
        case SYS_INIT:
            out->contactor_main_closed = false;
            out->inverter_enable = false;
            out->valve_main_open = false;
            out->blower_enable = false;
            g_state = SYS_PRECHARGE;
            break;

        case SYS_PRECHARGE:
            out->contactor_main_closed = true;
            if (precharge_ready(s)) {
                g_state = SYS_START_FC;
            }
            break;

        case SYS_START_FC:
            out->valve_main_open = true;
            out->blower_enable = true;
            out->blower_pwm_pct = 35;
            if (s->h2_pressure_bar >= H2_PRESSURE_MIN_BAR) {
                g_state = SYS_HYBRID_RUN;
            }
            break;

        case SYS_HYBRID_RUN:
            out->inverter_enable = true;
            break;

        case SYS_REFUEL_SWAP:
            out->inverter_enable = false;
            out->valve_main_open = false;
            out->valve_purge_open = true;
            out->contactor_main_closed = false;
            break;

        case SYS_SHUTDOWN:
            out->inverter_enable = false;
            out->valve_main_open = false;
            out->blower_pwm_pct = 20;
            break;

        case SYS_FAULT_LATCH:
        default:
            out->inverter_enable = false;
            out->valve_main_open = false;
            out->valve_purge_open = false;
            out->blower_enable = false;
            out->contactor_main_closed = false;
            break;
    }
}
