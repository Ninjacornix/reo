#include "scripted_actor_construction.hpp"
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_update {
namespace {
template<class T>T read(std::span<const std::byte> bytes,std::size_t at){T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;}
}
std::vector<std::optional<ScriptedActorRequest>> cutscene_scripted_requests(const gameplay_scenario::CutsceneDescriptor& descriptor){
    std::vector<std::optional<ScriptedActorRequest>> result(descriptor.actor_groups().size());std::uint32_t ordinal{};
    for(std::size_t group=0;group<result.size();++group){
        const auto header=descriptor.section(descriptor.actor_groups()[group][7]);
        if(header.size()<36)throw std::invalid_argument("Native cutscene actor header unavailable");
        if(read<std::uint16_t>(header,2)==65535||read<std::int16_t>(header,4)!=2)continue;
        const auto code=read<std::int16_t>(header,6);
        // Signed decimal quotient/remainder, then separate low-byte narrowing.
        // In particular5500 means type55/variant0, not a16-bit model identity.
        result[group]=ScriptedActorRequest{ordinal++,std::uint8_t(code/100),std::uint8_t(code%100),std::uint8_t(read<std::int16_t>(header,10)^1)};
    }
    return result;
}
std::shared_ptr<const PreparedCutsceneScriptedActors> ScriptedActorConstruction::prepare_cutscene_scripted(
    const gameplay_scenario::CutsceneDescriptor& descriptor,const gameplay_world::ActorAssets& assets)const{
    auto result=std::shared_ptr<PreparedCutsceneScriptedActors>(new PreparedCutsceneScriptedActors);
    const auto requests=cutscene_scripted_requests(descriptor);result->entries_.resize(requests.size());
    for(std::size_t group=0;group<requests.size();++group){
        if(!requests[group])continue;
        const auto header=descriptor.section(descriptor.actor_groups()[group][7]);auto& entry=result->entries_[group];entry.request=requests[group];
        entry.scale_profile=std::uint8_t(read<std::uint32_t>(header,20));
        entry.visibility=read<std::uint32_t>(header,24);
        entry.actor=prepare(*entry.request,assets);++result->scripted_count_;
    }
    return result;
}
ScriptedConstructed ScriptedActorConstruction::create_cutscene_scripted(const PreparedCutsceneScriptedActors& prepared,std::size_t group)noexcept{
    if(group>=prepared.entries_.size())return{};
    const auto& entry=prepared.entries_[group];if(!entry.actor)return{};
    auto result=create(*entry.actor);if(result.status!=ScriptedConstructionStatus::completed)return result;
    const auto actor=world_.resolve(result.id);
    actor->scripted->scene_marker=1;actor->scripted->scale_profile=entry.scale_profile;
    if(!entry.scale_profile)actor->model_scale={1,1,1};
    for(unsigned part=0;part<actor->scripted->part_visibility.size();++part)
        actor->scripted->part_visibility[part]=std::uint8_t((entry.visibility>>part)&1);
    return result;
}
}
