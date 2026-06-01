#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    SYS_INIT = 0,
    SYS_PRECHARGE,
    SYS_START_FC,
    SYS_HYBRID_RUN,
    SYS_REFUEL_SWAP,
    SYS_SHUTDOWN,
    SYS_FAULT_LATCH
} system_state_t;

typedef enum {
    FAULT_NONE = 0,
    FAULT_H2_LEAK,
    FAULT_OVERPRESSURE,
    FAULT_OVERTEMP,
    FAULT_SHORT_CIRCUIT,
    FAULT_SENSOR_DISAGREE,
    FAULT_COMMS_TIMEOUT
} fault_code_t;

typedef struct {
    float h2_pressure_bar;
    uint32_t h2_ppm;
    float stack_temp_c;
    float battery_temp_c;
    uint32_t bus_voltage_mv;
    int32_t bus_current_ma;
    bool tilt_detected;
} sensor_snapshot_t;

typedef struct {
    bool valve_main_open;
    bool valve_purge_open;
    bool blower_enable;
    uint8_t blower_pwm_pct;
    bool contactor_main_closed;
    bool inverter_enable;
} actuator_command_t;

#endif
