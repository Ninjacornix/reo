#include "visibility.hpp"
#include <cmath>
#include <exception>
#include <utility>
namespace reo::native::gameplay_navigation {
namespace {
bool finite(Position p)noexcept{return std::isfinite(p.x)&&std::isfinite(p.y)&&std::isfinite(p.z);}
}
VisibilityResult navigation_visibility(const VisibilityRoom& room,Position from,Position to)noexcept{
    if(!finite(from)||!finite(to))return {};
    from.y+=10.f;to.y=from.y+10.f;if(!finite(from)||!finite(to))return {};
    auto filter=room.filter;filter.include=0x1ffff;filter.exclude=0;filter.dynamic_kind_gate=false;
    try{
        const auto hit=gameplay_collision::trace::any(room.walls,{from.x,from.y,from.z},{to.x,to.y,to.z},filter,room.dynamic);
        if(hit.status!=gameplay_collision::trace::SamplingStatus::complete)return {};
        if(!hit.hit)return {QueryStatus::completed,false,{}};
        const auto kind=std::uint16_t(hit.hit->type);
        switch(kind){
        case 0x1000:case 0x200:case 0x800:case 0x80:case 0x100:case 0x40:case 0x20:case 8:case 0x10:case 4:return {QueryStatus::completed,false,kind};
        default:return {QueryStatus::completed,true,kind};
        }
    }catch(const std::exception&){return {};}
}
NodeResult nearest_visible_node(const RoomGraph& graph,Position query,std::int8_t group,const VisibilityRoom& room)noexcept{
    if(!finite(query))return {};
    struct Candidate {float distance;std::int8_t node;};
    std::array<Candidate,128> candidates;std::size_t count{};std::int8_t fallback=-1;
    for(std::size_t i=0;i<graph.nodes().size();++i){
        const auto& node=graph.nodes()[i];if(!node.active||(group>=0&&node.group!=std::uint16_t(group)))continue;
        const float x=node.position.x-query.x,y=node.position.y-query.y,z=node.position.z-query.z;
        const float xx=x*x,yy=y*y,zz=z*z,sum=xx+yy,total=sum+zz;
        if(!std::isfinite(total)||count==candidates.size())return {};
        candidates[count++]={std::sqrt(total),std::int8_t(i)};
    }
    for(std::size_t i=0;i+1<count;++i)for(std::size_t j=i+1;j<count;++j){
        if(candidates[i].distance<=candidates[j].distance)continue;
        fallback=candidates[i].node;std::swap(candidates[i],candidates[j]);
    }
    for(std::size_t i=0;i<count;++i){
        const auto candidate=candidates[i].node;
        const auto visible=navigation_visibility(room,query,graph.nodes()[std::size_t(candidate)].position);
        if(visible.status!=QueryStatus::completed)return {};
        if(!visible.blocked)return {QueryStatus::completed,candidate};
    }
    return {QueryStatus::completed,fallback};
}
bool node_selection_prefers_unfiltered(std::uint8_t motion,std::uint32_t status,std::uint32_t auxiliary)noexcept{
    switch(motion){
    case 0:case 1:case 2:case 3:case 4:case 5:case 0x21:case 0x22:case 0x23:case 0x24:case 0x2d:case 0x2e:case 0x2f:case 0x3b:
        return (auxiliary&0x04030000)!=0||(status&0x200)!=0;
    default:return true;
    }
}
NodeResult choose_actor_node(const Bank& bank,const RouteActorFacts& actor,std::uint32_t policy,
    const VisibilityRoom& room,ActorRouteState& state)noexcept{
    const auto graph=bank.room(actor.room);if(!graph)return {};
    if(policy==2)return nearest_visible_node(*graph,actor.position,0,room);
    const bool unfiltered=policy==1||state.selection_mode||node_selection_prefers_unfiltered(actor.motion_class,actor.status,actor.auxiliary_status);
    const auto first=unfiltered?nearest_node(*graph,actor.position,0):nearest_visible_node(*graph,actor.position,0,room);
    if(first.status!=QueryStatus::completed||first.node>=0)return first;
    const auto second=unfiltered?nearest_visible_node(*graph,actor.position,0,room):nearest_node(*graph,actor.position,0);
    if(unfiltered){if(second.status==QueryStatus::completed)state.current_node=second.node;return {second.status,first.node};}
    return second;
}
}
