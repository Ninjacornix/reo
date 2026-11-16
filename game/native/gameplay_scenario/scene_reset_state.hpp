#pragma once
#include "../transform_math/transform_math.hpp"
#include <array>
#include <cstdint>
#include <optional>

namespace reo::native::gameplay_scenario {
// Mutable globals outside the existing per-model pose/style/visibility banks.
// Their first admitted producer is5D7D60. Unresolved control-byte meanings are
// retained as explicit controls rather than inferred renderer behavior.
struct SceneModelResetValues {
    std::array<std::uint8_t,3> controls; //49EEF0..2
    std::uint8_t control{}; //49EF0C
    std::array<std::uint8_t,8> deferred_actor_cleanup; //4A5C25
    transform_math::Vector translation; //49F770, consumed by grouped drawing
    std::uint32_t style_override{}; //49F784
};
class SceneModelGlobals final {
public:
    SceneModelGlobals()noexcept=default;
    explicit SceneModelGlobals(SceneModelResetValues initial)noexcept:state_(initial){}
    const std::optional<SceneModelResetValues>& state()const noexcept{return state_;}
    void reset()noexcept{state_=SceneModelResetValues{{1,1,4},0,{}, {},UINT32_MAX};}
private:
    std::optional<SceneModelResetValues> state_;
};
// 5BE980 resets the canonical SequenceControl timer/mode. It has no separate
// room-camera state here; cinematic camera curve parameters remain distinct.
// The priority-SPK task's active gate is distinct from the16 dialogue records
// and the32 cached-text entries. Resetting it does not delete an existing task.
class PriorityTextState final {
public:
    PriorityTextState()noexcept=default;
    explicit PriorityTextState(std::uint8_t initial)noexcept:active_(initial){}
    std::optional<std::uint8_t> active()const noexcept{return active_;}
    void publish_active(std::uint8_t value)noexcept{active_=value;} //570204/6B68C0
    void reset_active()noexcept{active_=0;} //5D7D60; task retirement is6B6880
private:
    std::optional<std::uint8_t> active_;
};
} // namespace reo::native::gameplay_scenario
