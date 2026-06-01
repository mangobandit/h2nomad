#ifndef INTERFACES_H
#define INTERFACES_H

#include "types.h"

void hal_init(void);
void hal_read_sensors(sensor_snapshot_t* out);
void hal_apply_actuators(const actuator_command_t* cmd);
uint32_t hal_get_ms(void);

void fault_manager_raise(fault_code_t code);
bool fault_manager_is_latched(void);
fault_code_t fault_manager_active(void);
void fault_manager_clear_if_allowed(void);

void state_machine_init(void);
void state_machine_step(const sensor_snapshot_t* s, actuator_command_t* out);
system_state_t state_machine_get(void);

void power_dispatch_step(const sensor_snapshot_t* s, actuator_command_t* out);

#endif
