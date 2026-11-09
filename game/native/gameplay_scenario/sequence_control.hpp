#pragma once
#include <array>
#include <cstddef>
#include <cstdint>

namespace reo::native::gameplay_scenario {
struct SequenceControlState {
    std::array<std::uint8_t,256> active{};
    std::int8_t count{};
    std::uint8_t restart_byte{},condition_id{},selected_id{},phase{},mode{};
    std::uint16_t selection{},parameter_a{},parameter_b{};
    float fraction{};
};
// Canonical native command state, distinct from the eventual animation/camera
// sequence consumer. Numeric field roles are preserved without inventing units.
class SequenceControl final {
public:
    const SequenceControlState& snapshot()const noexcept{return state_;}
    void restore(const SequenceControlState& value)noexcept{state_=value;}
    bool active(std::uint32_t index,bool value)noexcept;
    void enable_all()noexcept;
    void select(std::uint8_t id,std::uint16_t selection)noexcept;
    void cancel_if_selected(std::uint8_t id)noexcept;
    void percentage(std::uint8_t mode,std::int16_t first,std::int16_t second,std::uint32_t amount)noexcept;
    bool phase_matches(std::uint32_t desired)const noexcept{return (state_.phase!=4)==(desired!=0);}
    bool id_matches(std::uint32_t expected,std::uint32_t desired)const noexcept{
        return desired==1?state_.condition_id==expected:desired==0?state_.condition_id!=expected:false;
    }
private:
    SequenceControlState state_;
};
} // namespace reo::native::gameplay_scenario
