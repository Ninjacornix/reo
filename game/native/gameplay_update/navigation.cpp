#include "update.hpp"
namespace reo::native::gameplay_update {
namespace nav=gameplay_navigation;
nav::ConditionResult Owner::applicable_navigation_condition(const world::actors::EntityId& id,std::uint32_t room,std::int32_t index){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    const auto graph=world_.navigation().room(room);if(!graph)return {};
    return nav::applicable_condition(*graph,index,{actor->character,actor->slot,actor->ai_control});
}
nav::AdmissionResult Owner::admit_navigation_condition(const world::actors::EntityId& id,std::uint32_t room,std::int32_t index){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    const auto graph=world_.navigation().room(room);if(!graph)return {};
    return nav::admit_condition(*graph,index,{actor->character,actor->slot,actor->ai_control},flags_.strided_half(room,0));
}
nav::LinkResult Owner::admitted_navigation_link(const world::actors::EntityId& id,std::int32_t room,std::int32_t variant,std::int32_t node){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    return nav::find_admitted_link(world_.navigation(),{actor->character,actor->slot,actor->ai_control},room,variant,node,flags_.strided_half(std::uint32_t(room),0));
}
nav::AdmissionResult Owner::admit_navigation_edge(const world::actors::EntityId& id,std::uint32_t room,std::int32_t source,std::int32_t destination){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    return nav::admit_edge(world_.navigation(),room,source,destination,{actor->character,actor->slot,actor->ai_control},actor->status,flags_.strided_half(room,0));
}
nav::RouteResult Owner::ranked_navigation_route(const world::actors::EntityId& id,std::uint32_t room,std::int32_t source,std::int32_t destination,nav::RankedPolicy policy,nav::RouteOutput& output){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    return nav::ranked_route(world_.navigation(),room,source,destination,{actor->character,actor->slot,actor->ai_control},actor->status,flags_.strided_half(room,0),policy,output);
}
}
