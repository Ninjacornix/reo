#include "routes.hpp"
namespace reo::native::gameplay_navigation {
namespace {
struct FollowResult {QueryStatus status{QueryStatus::completed};bool found{};std::int32_t immediate{-1};};
struct Search {
    const Bank& bank;const RoomGraph& graph;std::uint32_t room;std::int32_t destination;
    ActorFacts actor;std::uint32_t status;std::optional<std::uint16_t> flags;
    std::array<std::int8_t,128> scratch{};
    FollowResult follow(std::int32_t current,float& cost,unsigned depth)noexcept{
        if(depth>=scratch.size())return {QueryStatus::unavailable};
        scratch[std::size_t(current)]=1;
        struct Clear {std::int8_t& value;~Clear(){value=-1;}} clear{scratch[std::size_t(current)]};
        // The original recursive loop examines only rank0, in both policies.
        const auto slot=graph.routes()[std::size_t(destination)*graph.nodes().size()+std::size_t(current)][0];
        if(slot==255)return {};
        if(slot>=4)return {QueryStatus::unavailable};
        const auto& node=graph.nodes()[std::size_t(current)];const auto next=node.neighbors[slot];
        if(next<0)return {};
        if(std::size_t(next)>=graph.nodes().size())return {QueryStatus::unavailable};
        if(scratch[std::size_t(next)]!=-1)return {};
        const auto admitted=admit_edge(bank,room,current,next,actor,status,flags);
        if(admitted.status!=QueryStatus::completed)return {QueryStatus::unavailable};
        if(!admitted.allowed)return {};
        // Cost indexes the candidate rank, not the selected neighbor slot.
        cost=cost+float(node.costs[0]);
        if(next==destination)return {QueryStatus::completed,true,next};
        const auto child=follow(next,cost,depth+1);
        if(child.status!=QueryStatus::completed)return child;
        return child.found?FollowResult{QueryStatus::completed,true,next}:FollowResult{};
    }
};
}
RouteResult ranked_route(const Bank& bank,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts actor,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags,RankedPolicy policy,RouteOutput& output)noexcept{
    if(policy!=RankedPolicy::four_candidates&&policy!=RankedPolicy::first_candidate)return {};
    const auto graph=bank.room(room);
    if(!graph||source<0||destination<0||std::size_t(source)>=graph->nodes().size()||std::size_t(destination)>=graph->nodes().size())return {};
    std::int32_t selected=-1,secondary=-1;
    if(source==destination)selected=source;
    else{
        const auto mask=std::uint32_t(1)<<(actor.slot&31);const auto& node=graph->nodes()[std::size_t(source)];
        const auto& candidates=graph->routes()[std::size_t(destination)*graph->nodes().size()+std::size_t(source)];
        const std::size_t limit=policy==RankedPolicy::four_candidates?4:1;
        for(std::size_t rank=0;rank<limit;++rank){
            const auto slot=candidates[rank];if(slot==255)continue;if(slot>=4)return {};
            const auto next=node.neighbors[slot];if(next<0)continue;if(std::size_t(next)>=graph->nodes().size())return {};
            const auto occupied=bank.occupancy(room,std::uint32_t(next));if(!occupied)return {};
            if(*occupied&mask)continue;
            const auto admitted=admit_edge(bank,room,source,next,actor,actor_status,room_flags);
            if(admitted.status!=QueryStatus::completed)return {};
            if(!admitted.allowed)continue;
            output.cost=float(node.costs[rank]);
            if(next==destination){selected=next;break;}
            Search search{bank,*graph,room,destination,actor,actor_status,room_flags};
            for(std::size_t i=0;i<search.scratch.size();++i){const auto occupancy=bank.occupancy(room,std::uint32_t(i));if(!occupancy)return {};search.scratch[i]=*occupancy&mask?1:-1;}
            search.scratch[std::size_t(source)]=1;
            const auto followed=search.follow(next,output.cost,0);
            if(followed.status!=QueryStatus::completed)return {};
            if(followed.found){selected=next;secondary=followed.immediate;break;}
        }
    }
    output.first=std::int8_t(selected==-1?source:selected);
    output.second=std::int8_t(selected==-1?source:secondary==-1?destination:secondary);
    output.first_position=graph->nodes()[std::size_t(output.first)].position;
    output.second_position=graph->nodes()[std::size_t(output.second)].position;
    return {QueryStatus::completed,std::int8_t(selected)};
}
}
