# Firmware Architecture Details

## Runtime Domains
1. Safety Domain (high priority): leak, pressure, temperature, valve shutoff, contactor control.
2. Energy Domain: fuel-cell dispatch, battery assist, inverter enable policy.
3. UX/Telemetry Domain: display, logging, optional cloud uplink.

## Main Loop Strategy
- 1 kHz safety tick
- 100 Hz control loop
- 10 Hz telemetry/UI update

## Control State Machine
- `INIT`
- `PRECHARGE`
- `START_FC`
- `HYBRID_RUN`
- `REFUEL_SWAP`
- `SHUTDOWN`
- `FAULT_LATCH`
