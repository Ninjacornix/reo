#include "cost_graph.hpp"
#include <limits>
namespace reo::native::gameplay_navigation {
namespace {
constexpr auto infinity=std::numeric_limits<std::uint32_t>::max();
struct Edge {std::uint8_t source;std::uint16_t cost;std::int16_t next;};
struct Graph {
    const RoomGraph& input;std::int32_t destination;GraphCostResult& result;
    std::array<std::array<bool,4>,128> admitted{};
    std::array<std::int8_t,128> direct{};
    std::array<std::int16_t,128> heads{};std::array<Edge,512> incoming{};std::size_t edges{};
    void add(std::size_t from,std::int32_t to,std::uint16_t cost)noexcept{
        incoming[edges]={std::uint8_t(from),cost,heads[std::size_t(to)]};heads[std::size_t(to)]=std::int16_t(edges++);
    }
    void build()noexcept{
        heads.fill(-1);
        for(std::size_t from=0;from<input.nodes().size();++from){
            const auto& node=input.nodes()[from];
            // Any admitted direct target is a terminal recursive state: the
            // source overwrites earlier branch results and returns immediately.
            if(direct[from]!=-1){const auto slot=std::size_t(direct[from]);add(from,destination,node.costs[slot]);}
            else for(std::size_t slot=0;slot<4;++slot)if(admitted[from][slot])add(from,node.neighbors[slot],node.costs[slot]);
        }
    }
    std::array<std::uint32_t,128> distances(std::int32_t exclude,std::int32_t second=-1)noexcept{
        std::array<std::uint32_t,128> distance;distance.fill(infinity);distance[std::size_t(destination)]=0;
        std::array<bool,128> settled{};const auto count=input.nodes().size();
        for(std::size_t step=0;step<count;++step){
            std::int32_t selected=-1;std::uint32_t best=infinity;
            for(std::size_t node=0;node<count;++node){
                ++result.vertex_scans;if(std::int32_t(node)==exclude||std::int32_t(node)==second||settled[node]||distance[node]>=best)continue;
                best=distance[node];selected=std::int32_t(node);
            }
            if(selected==-1)break;
            settled[std::size_t(selected)]=true;
            for(auto edge=heads[std::size_t(selected)];edge!=-1;edge=incoming[std::size_t(edge)].next){
                ++result.relaxations;const auto& candidate=incoming[std::size_t(edge)];const auto node=candidate.source;
                if(node==exclude||node==second||settled[node])continue;
                const auto cost=best+candidate.cost;if(cost<distance[node])distance[node]=cost;
            }
        }
        return distance;
    }
};
}
GraphCostResult graph_cost_route(const Bank& bank,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts actor,std::uint32_t status,std::optional<std::uint16_t> flags,RouteOutput& output)noexcept{
    GraphCostResult result;const auto graph=bank.room(room);
    if(!graph||source<0||destination<0||std::size_t(source)>=graph->nodes().size()||std::size_t(destination)>=graph->nodes().size())return result;
    Graph query{*graph,destination,result};query.direct.fill(-1);
    if(source!=destination){
        for(std::size_t node=0;node<graph->nodes().size();++node)for(std::size_t slot=0;slot<4;++slot){
            ++result.admission_checks;const auto next=graph->nodes()[node].neighbors[slot];if(next<0)continue;
            if(std::size_t(next)>=graph->nodes().size())return result;
            const auto admitted=admit_edge(bank,room,std::int32_t(node),next,actor,status,flags);
            if(admitted.status!=QueryStatus::completed)return result;
            query.admitted[node][slot]=admitted.allowed;
            if(admitted.allowed&&next==destination&&query.direct[node]==-1)query.direct[node]=std::int8_t(slot);
        }
    }
    std::int32_t selected=-1,secondary=-1,owner=-1;std::uint32_t best=10000;
    if(source==destination)selected=source;
    else{
        query.build();const auto distance=query.distances(source);const auto& root=graph->nodes()[std::size_t(source)];
        for(std::size_t slot=0;slot<4;++slot){
            if(!query.admitted[std::size_t(source)][slot])continue;
            const auto next=root.neighbors[slot];
            // Root direct target chooses its node but leaves earlier best cost
            // and secondary intact. It is distinct from recursive terminals.
            if(next==destination){selected=next;break;}
            auto remaining=distance[std::size_t(next)];
            if(next==source){
                // The root can call its recursive helper on a self edge even
                // though source was already marked. Within that helper the
                // source is then forbidden for further neighbors as usual.
                const auto terminal=query.direct[std::size_t(source)];
                if(terminal!=-1)remaining=root.costs[std::size_t(terminal)];
                else for(std::size_t branch=0;branch<4;++branch){
                    if(!query.admitted[std::size_t(source)][branch])continue;
                    const auto child=root.neighbors[branch];if(child==source||distance[std::size_t(child)]==infinity)continue;
                    const auto cost=std::uint32_t(root.costs[branch])+distance[std::size_t(child)];if(cost<remaining)remaining=cost;
                }
            }
            if(remaining==infinity)continue;
            const auto cost=std::uint32_t(root.costs[slot])+remaining;
            if(cost<best){best=cost;selected=next;owner=next;}
        }
        if(owner!=-1){
            if(query.direct[std::size_t(owner)]!=-1)secondary=destination;
            else{
                const auto child_distance=query.distances(source,owner);const auto& child=graph->nodes()[std::size_t(owner)];std::uint32_t child_best=infinity;
                for(std::size_t slot=0;slot<4;++slot){
                    if(!query.admitted[std::size_t(owner)][slot])continue;
                    const auto next=child.neighbors[slot];if(next==source||next==owner)continue;
                    const auto remaining=child_distance[std::size_t(next)];if(remaining==infinity)continue;
                    const auto cost=std::uint32_t(child.costs[slot])+remaining;
                    if(cost<child_best){child_best=cost;secondary=next;}
                }
            }
        }
    }
    output.first=std::int8_t(selected==-1?source:selected);output.second=std::int8_t(selected==-1?source:secondary==-1?destination:secondary);
    output.first_position=graph->nodes()[std::size_t(output.first)].position;output.second_position=graph->nodes()[std::size_t(output.second)].position;
    if(selected!=-1)output.cost=float(best);
    result.status=QueryStatus::completed;result.selected=std::int8_t(selected);result.cost_written=selected!=-1;return result;
}
}
