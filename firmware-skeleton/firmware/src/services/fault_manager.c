#include "interfaces.h"

static fault_code_t g_fault = FAULT_NONE;

void fault_manager_raise(fault_code_t code) {
    if (g_fault == FAULT_NONE) {
        g_fault = code;
    }
}

bool fault_manager_is_latched(void) {
    return g_fault != FAULT_NONE;
}

fault_code_t fault_manager_active(void) {
    return g_fault;
}

void fault_manager_clear_if_allowed(void) {
    /* Keep latched until explicit service logic is implemented. */
}
