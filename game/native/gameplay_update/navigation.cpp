#include "update.hpp"
#include <bit>
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
nav::CostRouteResult Owner::bounded_navigation_route(const world::actors::EntityId& id,std::uint32_t room,std::int32_t source,std::int32_t destination,nav::RouteOutput& output,std::size_t maximum_edges){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    return nav::bounded_cost_route(world_.navigation(),room,source,destination,{actor->character,actor->slot,actor->ai_control},actor->status,flags_.strided_half(room,0),output,maximum_edges);
}
nav::CostRouteResult Owner::local_navigation_route(const world::actors::EntityId& id,std::uint32_t room,std::int32_t source,std::int32_t destination,std::uint32_t policy,nav::RouteOutput& output,std::int16_t& link,std::size_t maximum_edges){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    return nav::local_route(world_.navigation(),room,source,destination,{actor->character,actor->slot,actor->ai_control},actor->status,flags_.strided_half(room,0),policy,output,link,maximum_edges);
}
nav::CollectionResult Owner::collect_navigation_links(const world::actors::EntityId& id,std::uint32_t room,std::int32_t node,nav::CollectionProfile profile){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    auto& bank=world_.navigation();const auto variant=bank.current_variant(room);if(!variant)return {};
    return nav::collect_links(bank,room,*variant,node,{actor->character,actor->slot,actor->ai_control},actor->status,flags_.strided_half(room,0),bank.visits(actor->slot),profile);
}
nav::CrossRoomResult Owner::cross_room_navigation_route(const world::actors::EntityId& id,std::uint32_t source_room,std::uint32_t destination_room,std::int32_t source_node,std::int32_t destination_node,nav::CrossRoomOutput& output,nav::CrossRoomProfile profile){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    nav::RoomFlags flags;for(std::uint32_t room=0;room<flags.size();++room)flags[room]=flags_.strided_half(room,0);
    return nav::cross_room_route(world_.navigation(),{actor->character,actor->slot,actor->ai_control},actor->status,flags,source_room,destination_room,source_node,destination_node,output,profile);
}
nav::CrossRoomResult Owner::refresh_actor_navigation(const world::actors::EntityId& id,bool update_action,nav::CrossRoomProfile profile){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor||!actor->navigation_route)return {};
    nav::RoomFlags flags;for(std::uint32_t room=0;room<flags.size();++room)flags[room]=flags_.strided_half(room,0);
    const nav::ActorFacts facts{actor->character,actor->slot,actor->ai_control};
    if(update_action)return nav::update_actor_route_action(world_.navigation(),facts,actor->status,actor->room,flags,*actor->navigation_route,profile);
    return nav::refresh_actor_route(world_.navigation(),facts,actor->status,actor->room,flags,*actor->navigation_route,profile);
}
nav::CrossRoomResult Owner::begin_actor_navigation(const world::actors::EntityId& id,nav::Position destination,std::uint16_t destination_room,nav::CrossRoomProfile profile){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor||!actor->navigation_route)return {};
    nav::RoomFlags flags;for(std::uint32_t room=0;room<flags.size();++room)flags[room]=flags_.strided_half(room,0);
    const nav::RouteActorFacts facts{{actor->character,actor->slot,actor->ai_control},actor->status,actor->auxiliary_status,actor->room,{actor->position.x,actor->position.y,actor->position.z},actor->motion_class,actor->transient_marker};
    return nav::begin_actor_route(world_.navigation(),facts,world_.session().room,flags,*actor->navigation_route,destination,destination_room,profile);
}
nav::SceneCandidates Owner::collect_actor_scene_candidates(const world::actors::EntityId& id,const gameplay_scene::Records& records){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    return nav::collect_actor_scene_candidates(records,{actor->position.x,actor->position.y,actor->position.z},actor->motion_class,std::bit_cast<std::uint16_t>(actor->orientation[1]),actor->collision.local_center.z);
}
nav::NodeResult Owner::refresh_current_navigation_node(const world::actors::EntityId& id,const nav::VisibilityRoom& room){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor||!actor->navigation_route)return {};
    const nav::RouteActorFacts facts{{actor->character,actor->slot,actor->ai_control},actor->status,actor->auxiliary_status,actor->room,{actor->position.x,actor->position.y,actor->position.z},actor->motion_class,actor->transient_marker};
    const auto result=nav::choose_actor_node(world_.navigation(),facts,0,room,*actor->navigation_route);
    // Actual812540 entry prefix publishes the selector return immediately.
    // The remainder of that AI caller is still a required native consumer.
    if(result.status==nav::QueryStatus::completed)actor->navigation_route->current_node=result.node;
    return result;
}
}
