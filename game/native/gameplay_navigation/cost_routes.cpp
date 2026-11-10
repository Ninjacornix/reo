#include "cost_routes.hpp"
namespace reo::native::gameplay_navigation {
namespace {
struct FollowCost {QueryStatus status{QueryStatus::completed};float cost{10000};std::int32_t immediate{-1};};
struct Search {
    const Bank& bank;const RoomGraph& graph;std::uint32_t room;std::int32_t destination;
    ActorFacts actor;std::uint32_t status;std::optional<std::uint16_t> flags;std::size_t maximum;
    std::size_t considered{};bool exhausted{};std::array<std::int8_t,128> scratch{};
    bool take()noexcept{if(considered==maximum){exhausted=true;return false;}++considered;return true;}
    FollowCost follow(std::int32_t current,float incoming,unsigned depth)noexcept{
        if(depth>=scratch.size())return {QueryStatus::unavailable};
        scratch[std::size_t(current)]=1;
        struct Clear {std::int8_t& value;~Clear(){value=-1;}} clear{scratch[std::size_t(current)]};
        FollowCost best;const auto& node=graph.nodes()[std::size_t(current)];
        for(std::size_t slot=0;slot<4;++slot){
            if(!take())return {QueryStatus::unavailable};
            const auto next=node.neighbors[slot];if(next<0)continue;
            if(std::size_t(next)>=graph.nodes().size())return {QueryStatus::unavailable};
            if(scratch[std::size_t(next)]!=-1)continue;
            const auto admitted=admit_edge(bank,room,current,next,actor,status,flags);
            if(admitted.status!=QueryStatus::completed)return {QueryStatus::unavailable};
            if(!admitted.allowed)continue;
            const float accumulated=incoming+float(node.costs[slot]);
            // A direct target exits immediately, even if an earlier branch had
            // a lower cost. This is the source policy, not general Dijkstra.
            if(next==destination){best.cost=accumulated;best.immediate=next;break;}
            const auto child=follow(next,accumulated,depth+1);
            if(child.status!=QueryStatus::completed)return child;
            if(child.cost<best.cost){best.cost=child.cost;best.immediate=next;}
        }
        return best;
    }
};
}
CostRouteResult bounded_cost_route(const Bank& bank,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts actor,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags,RouteOutput& output,std::size_t maximum_edges)noexcept{
    const auto graph=bank.room(room);
    if(!graph||source<0||destination<0||std::size_t(source)>=graph->nodes().size()||std::size_t(destination)>=graph->nodes().size())return {};
    Search search{bank,*graph,room,destination,actor,actor_status,room_flags,maximum_edges};
    float best=10000;std::int32_t selected=-1,secondary=-1;
    const auto unavailable=[&]{return CostRouteResult{QueryStatus::unavailable,-1,search.exhausted,search.considered};};
    if(source==destination)selected=source;
    else{
        const auto& node=graph->nodes()[std::size_t(source)];
        for(std::size_t slot=0;slot<4;++slot){
            if(!search.take())return unavailable();
            const auto next=node.neighbors[slot];if(next<0)continue;
            if(std::size_t(next)>=graph->nodes().size())return unavailable();
            const auto admitted=admit_edge(bank,room,source,next,actor,actor_status,room_flags);
            if(admitted.status!=QueryStatus::completed)return unavailable();
            if(!admitted.allowed)continue;
            // Retain an earlier candidate's best cost and secondary when this
            // later direct-target branch exits; neither is reset by the source.
            if(next==destination){selected=next;break;}
            search.scratch.fill(-1);search.scratch[std::size_t(source)]=1;
            const auto child=search.follow(next,float(node.costs[slot]),0);
            if(child.status!=QueryStatus::completed)return unavailable();
            if(child.cost<best){best=child.cost;selected=next;secondary=child.immediate;}
        }
    }
    output.first=std::int8_t(selected==-1?source:selected);
    output.second=std::int8_t(selected==-1?source:secondary==-1?destination:secondary);
    output.first_position=graph->nodes()[std::size_t(output.first)].position;
    output.second_position=graph->nodes()[std::size_t(output.second)].position;
    if(selected!=-1)output.cost=best;
    return {QueryStatus::completed,std::int8_t(selected),false,search.considered};
}
}
