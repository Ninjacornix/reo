#include "actor_routes.hpp"
namespace reo::native::gameplay_navigation {
CrossRoomResult refresh_actor_route(Bank& bank,ActorFacts actor,std::uint32_t status,
    std::uint16_t room,const RoomFlags& flags,ActorRouteState& state,CrossRoomProfile profile)noexcept{
    CrossRoomResult result;
    if(room==state.destination_room){
        if(room>=flags.size())return result;
        auto& route=state.output.route;
        RouteOutput output{route.first,route.second,route.first_position,route.second_position,0};
        const auto local=local_route(bank,room,state.current_node,state.destination_node,actor,status,flags[room],0,output,state.output.link);
        route={output.first,output.second,output.first_position,output.second_position};
        result.status=local.status;result.selected=local.selected;
        if(local.status==QueryStatus::completed)result.failure=CrossRoomFailure::none;
    }else result=cross_room_route(bank,actor,status,flags,room,state.destination_room,state.current_node,state.destination_node,state.output,profile);
    if(result.status==QueryStatus::completed)state.last_current_node=state.current_node;
    return result;
}
CrossRoomResult update_actor_route_action(Bank& bank,ActorFacts actor,std::uint32_t status,
    std::uint16_t room,const RoomFlags& flags,ActorRouteState& state,CrossRoomProfile profile)noexcept{
    auto result=refresh_actor_route(bank,actor,status,room,flags,state,profile);
    if(result.status!=QueryStatus::completed||result.selected==-1)return result;
    const auto unavailable=[&]{result.status=QueryStatus::unavailable;result.failure=CrossRoomFailure::state;return result;};
    const auto current=std::int32_t(state.current_node);
    const auto occupancy=bank.occupancy(room,std::uint32_t(current));if(!occupancy)return unavailable();
    bank.occupancy(room,std::uint32_t(current),std::uint8_t(*occupancy|std::uint8_t(std::uint32_t(1)<<(actor.slot&31))));
    const auto graph=bank.room(room);if(!graph||current<0||std::size_t(current)>=graph->nodes().size())return unavailable();
    const auto& node=graph->nodes()[std::size_t(current)];std::uint16_t action=0;
    for(std::int32_t i=0;i<node.neighbor_count;++i)if(node.neighbors[std::size_t(i)]==state.output.route.first){action=node.actions[std::size_t(i)];break;}
    if(state.output.link!=-1){
        const auto asset=bank.asset();if(!asset||state.output.link<0||std::size_t(state.output.link)>=asset->links().size())return unavailable();
        const auto& link=asset->links()[std::size_t(state.output.link)];
        if(link.room==std::int32_t(room)&&link.node==current){
            for(std::int32_t i=0;i<node.neighbor_count;++i){
                const auto neighbor=std::int32_t(node.neighbors[std::size_t(i)]);
                if(neighbor<0||std::size_t(neighbor)>=graph->nodes().size())return unavailable();
                const auto& reverse=graph->nodes()[std::size_t(neighbor)];
                for(std::int32_t j=0;j<reverse.neighbor_count;++j)if(reverse.neighbors[std::size_t(j)]==current)action=reverse.actions[std::size_t(j)];
            }
        }
    }
    state.action=action;
    if(room==state.destination_room&&state.destination_node==state.output.route.first){
        state.output.route.first_position=state.output.route.second_position=state.final_position;
    }
    result.selected=0;return result;
}
}
