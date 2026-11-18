#include "execution.hpp"
namespace reo::native::gameplay_ai {
namespace {
constexpr std::array<WeightProfile,20> profiles{{
#include "weight_profiles.inc"
}};
}
const WeightProfile* weight_profile(std::uint8_t index)noexcept{
    return index<profiles.size()?&profiles[index]:nullptr;
}
void set_goal(ExecutionState& state,std::uint32_t requested)noexcept{
    state.goal_phases.fill(0);state.goal_parameters.fill(0);
    const auto next=std::uint16_t(requested);
    if(next)state.goal_refresh=0;
    else{state.goal_refresh=1;state.previous_goal=state.goal;}
    state.goal=next;
}
void clear_action_phases(ExecutionState& state)noexcept{
    state.action_phases.fill(0);state.action_marker=0;
}
void set_action(ExecutionState& state,std::uint32_t requested)noexcept{
    state.previous_action=state.action;state.action=std::uint16_t(requested);clear_action_phases(state);
}
std::uint32_t finish_goal_six(ExecutionState& state)noexcept{
    set_goal(state,0);return 0;
}
Status select_weight_profile(ExecutionState& state,std::int32_t requested)noexcept{
    if(requested>=20)return Status::completed;
    if(requested<0)return Status::unavailable;
    const auto index=std::uint8_t(requested);state.weight_profile=index;
    state.base_weights=profiles[index].base;state.reactive_weights.fill(0);state.status_weights.fill(0);
    return Status::completed;
}
}
