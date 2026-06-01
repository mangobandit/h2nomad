#ifndef CONFIG_H
#define CONFIG_H

#define CTRL_TICK_HZ                (100U)
#define SAFETY_TICK_HZ              (1000U)
#define TELEMETRY_TICK_HZ           (10U)

#define BUS_VOLTAGE_NOMINAL_MV      (24000U)
#define BUS_VOLTAGE_PRECHARGE_MV    (22000U)

#define STACK_TEMP_MAX_C            (75.0f)
#define BATTERY_TEMP_MAX_C          (60.0f)
#define H2_PRESSURE_MIN_BAR         (5.0f)
#define H2_PRESSURE_MAX_BAR         (10.0f)

#define H2_LEAK_THRESHOLD_PPM       (2000U)

#endif
