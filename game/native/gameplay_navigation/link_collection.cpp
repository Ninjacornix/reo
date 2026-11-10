#include "link_collection.hpp"
#include <utility>
namespace reo::native::gameplay_navigation {
CollectionResult collect_links(const Bank& bank,std::uint32_t room,std::int32_t variant,std::int32_t node,
    ActorFacts actor,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags,
    std::span<const std::uint8_t> visits,CollectionProfile profile)noexcept{
    CollectionResult result;result.last_cost=profile.initial_cost;
    const auto asset=bank.asset();
    if(!asset||visits.size()!=asset->links().size()||profile.maximum_results>result.candidates.size())return result;
    RouteOutput work;work.cost=profile.initial_cost.value_or(0);std::int16_t ignored_link{};
    for(std::size_t i=0;i<asset->links().size();++i){
        if(visits[i])continue;
        const auto& link=asset->links()[i];if(link.room!=std::int32_t(room)||link.variant!=variant)continue;
        result.unavailable_link=i;
        const auto graph=bank.room(room);if(!graph)return result;
        const auto admitted=admit_condition(*graph,link.condition,actor,room_flags);
        if(admitted.status!=QueryStatus::completed)return result;
        if(!admitted.allowed)continue;
        const auto routed=local_route(bank,room,profile.reverse?link.node:node,profile.reverse?node:link.node,
            actor,actor_status,room_flags,1,work,ignored_link);
        if(routed.cost_written)result.last_cost=work.cost;
        if(routed.status!=QueryStatus::completed)return result;
        if(routed.selected==-1)continue;
        if(!result.last_cost){result.failure=CollectionFailure::unknown_cost;return result;}
        if(result.count==profile.maximum_results){result.failure=CollectionFailure::capacity;return result;}
        LinkCandidate candidate{std::uint16_t(i),*result.last_cost,{}};
        if(!profile.omit_metadata)candidate.projection=RouteProjection{work.first,work.second,work.first_position,work.second_position};
        result.candidates[result.count++]=candidate;
    }
    for(std::size_t i=0;i+1<result.count;++i)for(std::size_t j=i+1;j<result.count;++j){
        if(result.candidates[i].cost<=result.candidates[j].cost)continue;
        // The original swap reads the old id's low byte. Current admitted
        // asset ids fit0..255; retain the operation when swapping full metadata.
        const auto low=std::uint8_t(result.candidates[i].link);result.last_cost=result.candidates[i].cost;
        std::swap(result.candidates[i],result.candidates[j]);result.candidates[j].link=low;
    }
    result.status=QueryStatus::completed;result.failure=CollectionFailure::none;result.unavailable_link.reset();return result;
}
}
