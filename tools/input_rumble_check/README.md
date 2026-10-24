# Controller rumble checks

Compile `main.cpp` with a C++20 compiler and run the resulting executable. No game data, controller or SDK is required. The fixtures exercise File #1's libdbc output-profile query and packed actuator packets, all 256 large-motor strengths, small-motor on/off, partial updates, stops, socket isolation and invalid/truncated requests.

The native game also needs `recomp/overrides/reo_rumble.h`, `runtime/input/pad2_rumble.h`, and updated bootstrap/hardware-bridge sources. The original frame service refreshes the launcher's motor heartbeat. Updating only the launcher cannot add output to older native game builds.

Launcher `--self-test` checks the shared-memory input/output ABI, stale/disabled output, selected Xbox slots, USB/Bluetooth DualSense framing and CRC, health-colour coexistence and motor-stop watchdogs. These fixtures use mock Xbox routing; they do not establish physical Xbox or Bluetooth feedback.

The Controls page has a global **Rumble** switch, enabled by default for existing settings. Disabling it immediately sends zero motor output while preserving input and health colours; the saved preference applies to both DualSense and XInput controllers.

For a live USB test, run the launcher's existing `--smoke-launch` route with `--display-test --test-enemy-combat --test-no-mods --test-memory-card --test-physical-pad`. This retains the selected physical controller while using an isolated test memory card. Diagnostic logs include native `[PAD-RUMBLE]` events and `controller-rumble.jsonl` with requested motors and successful DualSense output writes. Confirmation of physical vibration must come from the person holding the controller.
