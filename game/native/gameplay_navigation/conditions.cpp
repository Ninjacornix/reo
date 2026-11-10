#include "conditions.hpp"
namespace reo::native::gameplay_navigation {
ConditionResult applicable_condition(const RoomGraph& graph,std::int32_t index,ActorFacts actor)noexcept{
    if(index<0||std::size_t(index)>=graph.conditions().size())return {};
    const auto& condition=graph.conditions()[std::size_t(index)];
    bool allowed=condition[0]!=0;
    if(allowed&&condition[1]==1){
        switch(condition[6]){
        case 2:allowed=condition[7]==actor.character;break;
        case 3:allowed=condition[7]==actor.slot;break;
        case 4:allowed=actor.ai_control!=0;break;
        case 5:allowed=actor.ai_control&&condition[7]==actor.character;break;
        case 6:allowed=actor.ai_control&&condition[7]==actor.slot;break;
        case 7:case 8:allowed=false;break;
        default:break;
        }
    }
    return {QueryStatus::completed,allowed?index:-1};
}
AdmissionResult admit_condition(const RoomGraph& graph,std::int32_t index,ActorFacts actor,std::optional<std::uint16_t> room_flags)noexcept{
    if(index<0||std::size_t(index)>=graph.conditions().size())return {};
    const auto& condition=graph.conditions()[std::size_t(index)];
    const auto active=[&]{return applicable_condition(graph,index,actor).index!=-1;};
    switch(condition[1]){
    case 0:case 2:
        if(!active())return {QueryStatus::completed,false};
        if(!room_flags)return {};
        return {QueryStatus::completed,(*room_flags&(std::uint32_t(1)<<(condition[2]&31)))==0};
    case 1:case 6:case 13:return {QueryStatus::completed,active()};
    case 7:if(condition[3]==19||condition[3]==20)return {QueryStatus::completed,active()};break;
    default:break;
    }
    return {QueryStatus::completed,true};
}
std::optional<std::size_t> find_link(const Asset& asset,std::int32_t room,std::int32_t variant,std::int32_t node)noexcept{
    for(std::size_t i=0;i<asset.links().size();++i){const auto& link=asset.links()[i];if(link.room==room&&link.variant==variant&&link.node==node)return i;}
    return {};
}
LinkResult find_admitted_link(const Bank& bank,ActorFacts actor,std::int32_t room,std::int32_t variant,std::int32_t node,std::optional<std::uint16_t> room_flags)noexcept{
    const auto asset=bank.asset();if(!asset)return {};
    for(std::size_t i=0;i<asset->links().size();++i){
        const auto& link=asset->links()[i];if(link.room!=room||link.variant!=variant||link.node!=node)continue;
        const auto graph=bank.room(std::uint32_t(room));if(!graph)return {};
        const auto admitted=admit_condition(*graph,link.condition,actor,room_flags);
        if(admitted.status!=QueryStatus::completed)return {};
        if(admitted.allowed)return {QueryStatus::completed,i};
    }
    return {QueryStatus::completed,{}};
}
}
