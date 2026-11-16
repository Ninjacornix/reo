#pragma once
class PS2Runtime;
namespace reo::native::room_camera_adapter {
// Hybrid swap for the ordinary room camera (o2 0x5BED30) and its record
// import (o2 0x5BE3E0). See docs/native-gameplay/HYBRID_INTEGRATION_PLAN.md.
//   shadow        original authoritative; native compared on projected state
//   shadow_writes shadow plus a full-RAM diff of original writes outside the
//                 declared output set (slow, diagnostic only)
//   native        native authoritative; refusals run the original and count
enum class Mode { shadow, shadow_writes, native };
bool install_before_run(PS2Runtime&, Mode) noexcept;
}
