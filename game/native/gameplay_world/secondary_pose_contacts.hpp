#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
enum class SecondaryPoseContactsStatus {unchanged,applied,unavailable,no_memory};
// Complete61B920's character7 ordinary/high model contact pass. The caller
// owns scene admission/order; this function does not invent a visibility gate.
SecondaryPoseContactsStatus apply_secondary_pose_contacts(Actor&)noexcept;
}
