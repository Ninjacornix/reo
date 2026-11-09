#pragma once
#include "../gameplay_session/session.hpp"
#include <array>
#include <cstdint>
#include <optional>

namespace reo::native::gameplay_scenario {
struct ActionChoiceState {
    std::array<std::uint16_t,8> used{};
    std::uint8_t count{},table_row{};
};
// Shared scenario selection state, not a private RNG or actor-state copy.
class ActionChoices final {
public:
    bool restore(const ActionChoiceState& state)noexcept{
        if(state.table_row>=4)return false;
        state_=state;return true;
    }
    const ActionChoiceState& state()const noexcept{return state_;}
    std::optional<std::uint16_t> choose(const std::array<std::uint32_t,4>& authored,
        std::uint8_t character,gameplay_session::Random& random)const noexcept{
        if(state_.count>=8)return{};
        // Owned table717820. Selector2 reads the existing observed byte; it
        // does not advance either shared RNG seed.
        constexpr std::array<std::uint8_t,16> table{0,0,1,1,0,0,1,1,2,2,3,3,2,2,3,3};
        const auto selected=authored[table[state_.table_row*4+(random.request(2)&3u)]];
        if(selected==UINT32_MAX)return{};
        const auto id=std::uint16_t(selected);
        for(unsigned i=0;i<state_.count;++i)if(state_.used[i]==id)return{};
        const auto wanted=std::uint16_t(selected>>16);
        if(wanted!=8&&wanted!=character)return{};
        return id;
    }
private:
    ActionChoiceState state_;
};
} // namespace reo::native::gameplay_scenario
