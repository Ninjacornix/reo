#pragma once
#include "../transform_math/transform_math.hpp"
#include <optional>
namespace reo::native::gameplay_world {
// Exact ordinary387E90 definition byte5 selects joint14 for1, otherwise21.
std::optional<std::uint8_t> ground_pose_attachment_joint(std::uint8_t type,std::uint16_t variant)noexcept;
struct GroundPoseAttachment {transform_math::Matrix basis;transform_math::Vector position;};
// Shared complete57F990/57FAA0 value prefix, after actual joint selection.
GroundPoseAttachment prepare_ground_pose_attachment(std::int16_t yaw,const transform_math::Matrix& joint,bool trail);
}
