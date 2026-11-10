#include "destination.hpp"
#include "../transform_math/heading.hpp"
#include <cmath>
#include <exception>
namespace reo::native::gameplay_navigation {
namespace {
bool finite(Position p)noexcept{return std::isfinite(p.x)&&std::isfinite(p.y)&&std::isfinite(p.z);}
std::optional<std::uint16_t> route_heading(Position from,Position to)noexcept{
    // Complete370140 biases a zero Z delta. The previously qualified contact
    // heading helper biases X instead; using it unchanged here is incorrect.
    if(!finite(from)||!finite(to))return {};
    const float x=to.x-from.x,z=to.z-from.z;
    if(!std::isfinite(x)||!std::isfinite(z))return {};
    try{
        return transform_math::position_direction_turn(x,z);
    }catch(const std::exception&){return {};}
}
std::optional<float> distance(Position from,Position to)noexcept{
    if(!finite(from)||!finite(to))return {};
    const float x=from.x-to.x,y=from.y-to.y,z=from.z-to.z;
    const float xx=x*x,yy=y*y,zz=z*z,sum=xx+yy,total=sum+zz;
    if(!std::isfinite(total))return {};
    return std::sqrt(total);
}
}
CrossRoomResult begin_actor_route(Bank& bank,const RouteActorFacts& actor,std::uint16_t session_room,
    const RoomFlags& flags,ActorRouteState& state,Position destination,std::uint16_t destination_room,CrossRoomProfile profile)noexcept{
    CrossRoomResult result;
    state.completed=0;state.refresh=0;state.output.link=-1;
    state.final_position=destination;state.destination_room=destination_room;
    const auto graph=bank.room(destination_room);if(!graph)return result;
    const auto nearest=nearest_node(*graph,destination,0);if(nearest.status!=QueryStatus::completed)return result;
    state.destination_node=nearest.node;
    if(!bank.clear_actor_visits(actor.identity.slot))return result;
    result=update_actor_route_action(bank,actor.identity,actor.status,actor.room,flags,state,profile);
    if(result.status!=QueryStatus::completed||result.selected==-1)return result;
    const auto unavailable=[&]{result.status=QueryStatus::unavailable;result.failure=CrossRoomFailure::state;return result;};
    const auto action=std::uint8_t(state.action);
    switch(actor.motion_class){
    case 0x1a:if(action!=1&&action!=2&&action!=8&&action!=9)state.action=1;break;
    case 0x27:if(action!=6&&action!=7)state.action=6;break;
    case 0x31:if(action!=13)state.action=13;break;
    default:break;
    }
    state.previous_action=state.action;state.completed=0;
    if(actor.room==session_room){
        const auto variant=bank.current_variant(actor.room);if(!variant)return unavailable();
        if(!find_link(*bank.asset(),actor.room,*variant,state.current_node)){
            const auto current_graph=bank.room(actor.room);
            if(!current_graph||state.current_node<0||std::size_t(state.current_node)>=current_graph->nodes().size())return unavailable();
            const auto current_position=current_graph->nodes()[std::size_t(state.current_node)].position;
            bool replace=false;const auto previous=std::uint8_t(state.previous_action);
            if(previous==1||previous==2||previous==8||previous==9){
                if(!std::isfinite(actor.position.y)||!std::isfinite(state.output.route.first_position.y))return unavailable();
                replace=actor.position.y<current_position.y?actor.position.y<state.output.route.first_position.y:!(actor.position.y<state.output.route.first_position.y);
            }else{
                const auto first=route_heading(actor.position,current_position),second=route_heading(actor.position,state.output.route.first_position);
                if(!first||!second)return unavailable();
                if(std::uint16_t(std::uint16_t(*first-*second)+0x4000)<0x8000){
                    const auto length=distance(actor.position,current_position);if(!length)return unavailable();
                    const float threshold=actor.motion_class==0x1a||(actor.auxiliary_status&0x10000)?100.f:50.f;
                    replace=*length>=threshold;
                }
            }
            if(replace){
                auto& route=state.output.route;route.second=route.first;route.second_position=route.first_position;
                route.first=state.current_node;route.first_position=current_position;
            }
        }
        if(actor.transient_marker){result.selected=-1;return result;}
    }
    if(actor.room==state.destination_room&&state.destination_node==state.output.route.first){
        auto& route=state.output.route;route.first_position=route.second_position=state.final_position;
        route.first=route.second=state.destination_node;
    }
    return result;
}
}
