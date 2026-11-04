#pragma once
#include "input.h"

namespace reo::macos_input {
// Capture AppKit/GameController state on the window thread, then consume a
// copied snapshot from the pad worker. No AppKit calls run on the pad worker.
bool display_available();
void capture();
void rumble(uint32_t motors);
DualShock2State read(int port, bool keyboard = true);
}
