#include "scene_lookup.hpp"
#include <bit>
namespace reo::native::gameplay_navigation {
namespace {
std::optional<std::int32_t> wanted(const Bank& bank,ActorFacts actor,std::uint32_t room,std::int32_t condition)noexcept{
    const auto graph=bank.room(room);if(!graph)return {};
    const auto applicable=applicable_condition(*graph,condition,actor);
    if(applicable.status!=QueryStatus::completed)return {};
    return applicable.index+1;
}
bool matches(const gameplay_scene::Record& record,std::int32_t target)noexcept{
    return std::int32_t(std::bit_cast<std::int8_t>(record.condition_ordinal))==target;
}
}
SceneLookupResult find_scene_candidate(const Bank& bank,ActorFacts actor,std::uint32_t room,std::int32_t condition,const gameplay_scene::Records& records,const SceneCandidates& candidates)noexcept{
    SceneLookupResult result;const auto target=wanted(bank,actor,room,condition);
    if(!target||candidates.status!=QueryStatus::completed||candidates.count>candidates.records.size())return result;
    for(std::size_t i=0;i<candidates.count;++i){
        const auto node=records.acquire(candidates.records[i]);if(!node)return result;
        ++result.visited;if(matches(node->value,*target)){result.record=node->id;break;}
    }
    result.status=QueryStatus::completed;return result;
}
SceneLookupResult find_global_scene_candidate(const Bank& bank,ActorFacts actor,std::uint32_t room,std::int32_t condition,const gameplay_scene::Records& records)noexcept{
    SceneLookupResult result;const auto target=wanted(bank,actor,room,condition);if(!target)return result;
    for(auto node=records.first();node;node=node->next){
        ++result.visited;if(matches(node->value,*target)){result.record=node->id;break;}
    }
    result.status=QueryStatus::completed;return result;
}
}
