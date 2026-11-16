#include "weighted_destination.hpp"
#include "local_routes.hpp"
#include <bit>
#include <utility>
namespace reo::native::gameplay_navigation {
namespace {
std::optional<std::uint8_t> weight(const RoomGraph& graph,std::size_t node,std::uint32_t policy)noexcept{
    // Negative full-word selectors are real816460 stores. Preserve bounded
    // reads such as-1 selecting byte31, rather than rejecting by sign alone.
    const auto at=std::int64_t(12+64*node+32)+std::bit_cast<std::int32_t>(policy);
    const auto bytes=graph.encoding();if(at<0||std::uint64_t(at)>=bytes.size())return{};
    return bytes[std::size_t(at)];
}
}
NodeResult weighted_destination_node(Bank& bank,const RouteActorFacts& actor,const ActorRouteState& state,std::int32_t excluded,
    std::uint32_t target_room,std::uint32_t mode,const RoomFlags& flags,gameplay_session::Random& random)noexcept{
    if(!bank.clear_actor_visits(actor.identity.slot))return{};
    const auto variant=bank.current_variant(actor.room);if(!variant)return{};
    const auto policy=bank.descriptor_policy(actor.room,*variant);if(!policy)return{};
    const auto graph=bank.room(target_room);if(!graph||!bank.asset())return{};
    std::array<std::uint32_t,128> candidates{};std::size_t count{};std::int32_t total{};
    for(std::size_t node=0;node<graph->nodes().size();++node){
        if(!graph->nodes()[node].active)continue;
        const auto value=weight(*graph,node,*policy);if(!value)return{};if(!*value)continue;
        if(mode==1){const auto destination_variant=bank.current_variant(target_room);if(!destination_variant)return{};
            if(find_link(*bank.asset(),std::int32_t(target_room),*destination_variant,std::int32_t(node)))continue;}
        RouteOutput output;std::int16_t link{};
        const auto route=local_route(bank,actor.room,state.current_node,std::int32_t(node),actor.identity,actor.status,
            actor.room<flags.size()?flags[actor.room]:std::nullopt,1,output,link);
        if(route.status!=QueryStatus::completed)return{};
        if(route.selected==-1||excluded==std::int32_t(node))continue;
        if(count>=candidates.size())return{};candidates[count++]=std::uint32_t(node);total+=*value;
    }
    if(!count)return{QueryStatus::completed,-1};
    //8166E0 bounds the outer loop by count-1;816738's inner bound is count.
    for(std::size_t i=0;i+1<count;++i)for(std::size_t j=i+1;j<count;++j){
        const auto a=weight(*graph,candidates[i],*policy),b=weight(*graph,candidates[j],*policy);if(!a||!b)return{};
        if(*a<*b)std::swap(candidates[i],candidates[j]);
    }
    auto selected=std::int32_t(random.request(1));if(total&&selected)selected%=total;
    std::uint32_t result{};std::int32_t sum{};
    for(std::size_t i=0;i<count;++i){const auto value=weight(*graph,candidates[i],*policy);if(!value)return{};sum+=*value;
        if(sum>=selected){result=candidates[i];break;}}
    return{QueryStatus::completed,std::bit_cast<std::int8_t>(std::uint8_t(result))};
}
}
