#include "goal_route.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_navigation/visibility.hpp"
#include <bit>
namespace reo::native::gameplay_ai {
std::optional<bool> route_goal_interrupted(const gameplay_world::Actor& actor,
    const gameplay_world::Actor* reference,std::uint32_t mask)noexcept{
    if(gameplay_navigation::node_selection_prefers_unfiltered(actor.motion_class,actor.status,actor.auxiliary_status))return false;
    if(!actor.ai_execution)return{};const auto& state=*actor.ai_execution;
    if((mask&0x80)&&(actor.status&8))return true;
    if((mask&0x100)&&actor.motion_class==0x3b)return true;
    if((mask&0x200)&&state.reference_request==1)return true;
    if((mask&0x400)&&state.owned_request)return true;
    if((mask&0x800)&&(actor.status&0x200))return true;
    if(state.observation_cooldown)return false;
    if(!mask)return true;
    if((mask&1)&&state.observation_flags)return true;
    if(mask&2){
        if(!reference||!reference->ai_execution)return{};const auto& other=*reference->ai_execution;
        if(other.health_band_1078!=other.previous_health_band_1079||other.gauge_band_107a!=other.previous_gauge_band_107b)return true;
    }
    if((mask&4)&&(state.health_band_1078!=state.previous_health_band_1079||state.gauge_band_107a!=state.previous_gauge_band_107b))return true;
    if((mask&8)&&!state.previous_room_reaction_gate&&state.room_reaction_gate)return true;
    if((mask&0x10)&&state.threat_band!=state.previous_threat_band)return true;
    return false;
}
namespace {
constexpr std::array<std::uint16_t,8> route_durations{9000,5400,900,5400,2700,2700,18000,11700}; //828F90
std::uint16_t delay(gameplay_session::Random& random,std::int32_t limit,std::int32_t range)noexcept{
    auto value=std::int32_t(random.request(1));if(value)value%=range;
    ++value;if(value<limit)value=limit;return std::uint16_t(std::uint32_t(value)*30u); //815CE0
}
}
Status update_route_goal(gameplay_world::Actor& actor,const gameplay_world::Actor* reference,
    gameplay_navigation::Bank& bank,gameplay_session::Random& random,const GoalRouteContext* context)noexcept{
    if(!actor.ai_execution)return Status::unavailable;auto& state=*actor.ai_execution;
    const auto reset=[&]{set_action(state,0);set_goal(state,0);return Status::completed;};
    auto phase=state.goal_phases[0];
    if(!phase){
        state.goal_phases[0]=1;state.goal_parameters[0]=450;
        if(actor.character>=route_durations.size())return Status::unavailable;
        state.goal_parameters[1]=route_durations[actor.character];state.observation_cooldown=150;set_action(state,1);
    }else{
        if(phase==1){
            if(state.goal_parameters[0])--state.goal_parameters[0];
            else{state.goal_phases[0]=2;phase=2;}
        }
        if(phase==2){
            if(!context||!actor.navigation_route)return Status::unavailable;
            auto& route=*actor.navigation_route;
            const gameplay_navigation::RouteActorFacts facts{{actor.character,actor.slot,actor.ai_control},actor.status,actor.auxiliary_status,
                actor.room,{actor.position.x,actor.position.y,actor.position.z},actor.motion_class,actor.transient_marker};
            const auto selected=gameplay_navigation::weighted_destination_node(bank,facts,route,route.current_node,actor.room,1,context->flags,random);
            if(selected.status!=gameplay_navigation::QueryStatus::completed)return Status::unavailable;
            if(selected.node==-1){set_goal(state,0);return Status::completed;}
            const auto graph=bank.room(actor.room);if(!graph||selected.node<0||std::size_t(selected.node)>=graph->nodes().size())return Status::unavailable;
            const auto begun=gameplay_navigation::begin_actor_route(bank,facts,context->session_room,context->flags,route,
                graph->nodes()[std::size_t(selected.node)].position,actor.room);
            if(begun.status!=gameplay_navigation::QueryStatus::completed)return Status::unavailable;
            if(begun.selected==-1){set_goal(state,0);return Status::completed;}
            set_action(state,2);state.observation_cooldown=90;++state.goal_phases[0];
        }else if(phase==3){
            if(!context||!actor.navigation_route)return Status::unavailable;auto& route=*actor.navigation_route;
            const gameplay_navigation::RouteActorFacts facts{{actor.character,actor.slot,actor.ai_control},actor.status,actor.auxiliary_status,
                actor.room,{actor.position.x,actor.position.y,actor.position.z},actor.motion_class,actor.transient_marker};
            const auto continued=gameplay_navigation::continue_actor_route(bank,facts,context->session_room,context->flags,route);
            if(continued.status!=gameplay_navigation::QueryStatus::completed)return Status::unavailable;
            route.completed=std::uint8_t(continued.selected);
            if(std::bit_cast<std::int8_t>(route.completed)<0)return reset();
            if(!state.action){
                if(route.completed==1){
                    if(!state.goal_parameters[1]){set_goal(state,0);return Status::completed;}
                    state.goal_phases[0]=1;
                }
                state.goal_parameters[0]=delay(random,1,4);set_action(state,1);
            }
        }
    }
    if(state.goal_parameters[1])--state.goal_parameters[1];
    if(!(state.action_counter&1))state.steering_button_10=0;
    const auto interrupted=route_goal_interrupted(actor,reference,0xfff);if(!interrupted)return Status::unavailable;
    return *interrupted?reset():Status::completed;
}
}
