#pragma once
#include "../transform_math/transform_math.hpp"
#include <memory>
#include <optional>
#include <span>

namespace reo::native::gameplay_scenario {
using CameraIntegerPoint = std::array<std::int32_t,3>;
struct CameraPlanarBoundary {
    transform_math::Vector first,last,first_normal,last_normal;
};
// Immutable authored camera geometry. Active bytes and the room-camera header
// belong to SequenceControl; no second copy of those script-visible fields.
struct RoomCameraRecord {
    std::uint8_t type{},policy{};
    std::array<std::uint32_t,4> parameters{}; // Original record +4..+10.
    float lens{},distance{};
    transform_math::Vector anchor;
    std::array<CameraIntegerPoint,8> volume;
    std::array<std::array<CameraIntegerPoint,2>,4> endpoints;
    std::array<float,2> endpoint_distance{};
    std::uint32_t boundary_policy{};
    std::array<CameraPlanarBoundary,2> boundaries;
    std::array<std::byte,16> view_controls{};
    std::uint8_t duration{},previous{},next{},interpolation{};
    transform_math::Vector first_control,last_control;
    float sequence_time{};
    std::optional<std::uint8_t> sequence_root;
    std::array<std::byte,8> auxiliary{};
    std::array<std::uint32_t,2> extra{};
};
class RoomCameraRecords final {
public:
    static constexpr std::size_t capacity=32;
    // Complete5BE3E0 record import and its5C0330 preparation. The native profile
    // admits the actual32-slot allocation, bounded section offsets and finite
    // geometry, and refuses cyclic/out-of-pool reached sequence links.
    static std::shared_ptr<const RoomCameraRecords> import(std::span<const std::byte>);
    std::uint8_t count()const noexcept{return count_;}
    const auto& records()const noexcept{return records_;}
    // Complete5BE930 within the owned record pool; step count is the low byte.
    std::optional<std::uint8_t> follow(std::uint8_t start,std::uint32_t steps)const noexcept;
    //5C0800's unclamped ratio at the selected actor's actual X/Z position.
    std::optional<float> boundary_ratio(std::uint8_t record,std::uint8_t boundary,
                                       transform_math::Vector position)const noexcept;
    //5BFCA0 tests the actual six oriented faces at actor Y+10, not an AABB.
    std::optional<bool> contains(std::uint8_t record,transform_math::Vector position)const noexcept;
private:
    std::array<RoomCameraRecord,capacity> records_{};
    std::uint8_t count_{};
};
}
