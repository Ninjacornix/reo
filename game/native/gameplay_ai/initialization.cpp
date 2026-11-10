#include "initialization.hpp"
namespace reo::native::gameplay_ai {
InitializationResult initialize(gameplay_navigation::Bank& bank,ControlRequests& controls,
    std::uint8_t ai_control,std::uint8_t actor_slot,ExecutionState* state,gameplay_navigation::ActorRouteState* route)noexcept{
    InitializationResult result;if(!bank.clear_header_byte())return result;
    result.enabled=ai_control!=0;
    if(!ai_control){result.status=Status::completed;return result;}
    if(!state||!route)return result;
    result.registration=controls.register_control(0,actor_slot);
    result.publication=publish_actor_control(controls,actor_slot,0);
    route->selection_mode=255;route->refresh=0;
    state->inhibited=0;state->reaction=0;state->pending_reaction=0;state->reaction_countdown=0;
    state->room_memo=65535;state->observation_flags=0;state->periodic_counter=60;
    state->action_counter=0;state->forced_priority=-1;
    set_goal(*state,0);set_action(*state,0);(void)select_weight_profile(*state,0);
    result.status=Status::completed;return result;
}
}
