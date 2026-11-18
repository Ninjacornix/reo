#include "local_routes.hpp"
namespace reo::native::gameplay_navigation {
CostRouteResult local_route(const Bank& bank,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts actor,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags,std::uint32_t policy,
    RouteOutput& output,std::int16_t& destination_link,std::size_t maximum_edges)noexcept{
    const auto graph=bank.room(room);const auto asset=bank.asset();
    if(!graph||!asset||source<0||destination<0||std::size_t(source)>=graph->nodes().size()||std::size_t(destination)>=graph->nodes().size())return {};
    CostRouteResult result;
    if(source==destination){
        output.first=output.second=std::int8_t(source);
        output.first_position=output.second_position=graph->nodes()[std::size_t(source)].position;
        result={QueryStatus::completed,std::int8_t(source),false,0};
    }else{
        const auto variant=bank.current_variant(room);if(!variant)return {};
        if(find_link(*asset,std::int32_t(room),*variant,destination)){
            const auto admitted=admit_edge(bank,room,destination,-1,actor,actor_status,room_flags);
            if(admitted.status!=QueryStatus::completed)return {};
            if(!admitted.allowed)return {QueryStatus::completed,-1,false,0};
        }
        if(policy==0||policy==1){
            const auto ranked=ranked_route(bank,room,source,destination,actor,actor_status,room_flags,
                policy==0?RankedPolicy::four_candidates:RankedPolicy::first_candidate,output);
            result={ranked.status,ranked.selected,false,0,ranked.cost_written};
        }else result=bounded_cost_route(bank,room,source,destination,actor,actor_status,room_flags,output,maximum_edges);
        if(result.status!=QueryStatus::completed)return result;
    }
    destination_link=-1;
    if(result.selected!=-1){
        const auto variant=bank.current_variant(room);if(!variant){result.status=QueryStatus::unavailable;result.selected=-1;return result;}
        const auto link=find_admitted_link(bank,actor,std::int32_t(room),*variant,destination,room_flags);
        if(link.status!=QueryStatus::completed){result.status=QueryStatus::unavailable;result.selected=-1;return result;}
        if(link.index)destination_link=std::int16_t(*link.index);
    }
    return result;
}
}
