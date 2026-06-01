# H2NOMAD Firmware Skeleton (Fuel Module V1)

This repository skeleton provides a production-oriented starting point for the H2NOMAD control firmware.

## Architecture Summary
- Safety-first dual-domain design: real-time safety core plus non-critical services.
- Event-driven state machine for fuel-cell lifecycle and fault latching.
- Clear separation of hardware abstraction, drivers, services, and tasks.

## Suggested Target Stack
- MCU: STM32G4 / STM32H7 / NXP S32K (or equivalent)
- RTOS: FreeRTOS
- Comms: CAN-FD backbone, UART for debug, optional BLE/LTE gateway

## Build Notes
This is a scaffold, not board-specific firmware. Replace `hal_*` stubs with your BSP and wire into your build system.
