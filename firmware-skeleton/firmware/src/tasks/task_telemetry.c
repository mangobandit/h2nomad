#include "interfaces.h"

void task_telemetry_10hz(void) {
    (void)fault_manager_active();
    /* Hook in CAN/UART logging and local display updates. */
}
