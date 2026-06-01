#include "interfaces.h"

void hal_init(void) {}
void hal_read_sensors(sensor_snapshot_t* out) { (void)out; }
void hal_apply_actuators(const actuator_command_t* cmd) { (void)cmd; }
uint32_t hal_get_ms(void) { return 0U; }
