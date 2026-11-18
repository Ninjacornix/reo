#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
// Complete5D6A60. Source gates precede model/state admission. Modifies the real
// retained model's local nodes24/26; the subsequent model pass publishes them.
void update_behavior_attachment(World&,Actor&,float step=1.f);
// Complete5D6ED0; ordinary66B500 requests selector3. Other callers use0..2.
// The source masks the selector to its low byte before its branch dispatch.
void update_terminal_attachment(Actor&,std::uint32_t selector=3);
}
