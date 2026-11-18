#pragma once
#include "camera_math.hpp"
#include <optional>

namespace reo::native::gameplay_scenario {
// The consumed fields of one authored56-byte camera record. Type0 binds the
// eye curve; every other type binds the aim curve.
struct CameraKey {
    std::uint8_t type{};
    std::uint16_t frame{};
    transform_math::Vector point{},control{};
    float lens{},roll_control{},lens_control{};
    std::uint32_t roll{};
};
struct CameraSegment {CameraKey current,next;};
struct CameraParameters {
    CameraPose pose;
    float far_plane{},near_plane{},lens{};
    // Remaining semantic375650 state, shared by ordinary and cinematic views.
    transform_math::Vector offset{},secondary_up{};
    float distance{};
    std::uint32_t pitch{},yaw{};
};
// Complete5C09A0 parameter evaluation. Both bound curves are required. The
// caller publishes the result through the real projection/display owner;
// neither this component nor375A50 advances the borrowed simulation frame.
bool sample_camera_parameters(CameraParameters&,const std::optional<CameraSegment>& eye,
                              const std::optional<CameraSegment>& aim,std::uint32_t frame) noexcept;
} // namespace reo::native::gameplay_scenario
