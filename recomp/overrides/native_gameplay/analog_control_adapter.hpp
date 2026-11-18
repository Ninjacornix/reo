#pragma once
// Hybrid swap of the player's analog control (File #1 o2 0x6621F0) to the native
// reo::native::gameplay_world::update_analog_control. See
// docs/native-gameplay/HYBRID_INTEGRATION_PLAN.md, step 3.
//
// REO_NATIVE_ANALOG=shadow  original runs; native runs on the same pre-state and
//                           its outputs are compared (and unexpected original writes
//                           to the actor record are counted).
// REO_NATIVE_ANALOG=1       native runs; the original runs only where native
//                           reports unavailable (the head-target path 0x65F0C0).
class PS2Runtime;
namespace reo::native::analog_control_adapter {
enum class Mode { shadow, native };
bool install_before_run(PS2Runtime&, Mode) noexcept;
}
