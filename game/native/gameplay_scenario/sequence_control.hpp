#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include "room_view_masks.hpp"
#include "../transform_math/transform_math.hpp"

namespace reo::native::gameplay_scenario {
class RoomCameraRecords;
struct SequenceControlState {
    // 5BE3E0 clears a 0x34-byte header and 32 records of 0x198 bytes.
    // The byte-sized script selector does not establish 256 owned records.
    std::array<std::uint8_t,32> active{};
    std::int8_t count{};
    std::uint8_t restart_byte{},condition_id{},selected_id{},phase{},mode{};
    std::uint16_t selection{},parameter_a{},parameter_b{};
    float fraction{};
    // Remaining canonical room-camera header fields, initialized by5BE3E0.
    std::uint8_t initialized{},selection_changed{},actor{},progress{};
    float distance{};
    // Mutable camera state belongs to this same header/record owner. Authored
    // geometry remains immutable;5BF300/5BF7B0 update the per-record anchors.
    std::array<float,2> camera_progress{},camera_target{};
    std::optional<std::uint8_t> previous_camera;
    std::array<transform_math::Vector,32> camera_anchors{};
    RoomViewMasks view_masks;
};
// Canonical native command state, distinct from the eventual animation/camera
// sequence consumer. Numeric field roles are preserved without inventing units.
class SequenceControl final {
public:
    const SequenceControlState& snapshot()const noexcept{return state_;}
    bool restore(const SequenceControlState& value)noexcept{
        if(value.count>std::int8_t(value.active.size()))return false;
        state_=value;return true;
    }
    void install_camera_records(std::shared_ptr<const RoomCameraRecords>,std::uint8_t selected_actor)noexcept;
    const std::shared_ptr<const RoomCameraRecords>& camera_records()const noexcept{return records_;}
    RoomViewMasks& room_view_masks()noexcept{return state_.view_masks;}
    //6621F0 consumes the same one-shot byte written by ordinary camera selection.
    std::uint8_t& camera_change_latch()noexcept{return state_.selection_changed;}
    bool active(std::uint32_t index,bool value)noexcept;
    void enable_all()noexcept;
    bool select(std::uint8_t id,std::uint16_t selection)noexcept;
    bool cancel_if_selected(std::uint8_t id)noexcept;
    void percentage(std::uint8_t mode,std::int16_t first,std::int16_t second,std::uint32_t amount)noexcept;
    // Complete5BE980: these are the same timer/mode fields written by script13
    // and script16, not a second room-camera reset state.
    void reset_camera_override()noexcept{state_.selection=0;state_.phase=0;}
    bool phase_matches(std::uint32_t desired)const noexcept{return (state_.phase!=4)==(desired!=0);}
    bool id_matches(std::uint32_t expected,std::uint32_t desired)const noexcept{
        return desired==1?state_.condition_id==expected:desired==0?state_.condition_id!=expected:false;
    }
private:
    friend class RoomCamera;
    SequenceControlState state_;
    std::shared_ptr<const RoomCameraRecords> records_;
};
} // namespace reo::native::gameplay_scenario
