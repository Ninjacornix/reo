#include "npc_actor_construction.hpp"
#include "model_constraints.hpp"
#include <algorithm>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
template<class T>T read(std::span<const std::byte> bytes,std::size_t at){T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;}
}
std::vector<std::optional<CutsceneNpcRequest>> cutscene_npc_requests(const gameplay_scenario::CutsceneDescriptor& descriptor){
    std::vector<std::optional<CutsceneNpcRequest>> result(descriptor.actor_groups().size());
    for(std::size_t group=0;group<result.size();++group){
        const auto header=descriptor.section(descriptor.actor_groups()[group][7]);
        if(header.size()<36)throw std::invalid_argument("Native cutscene NPC header unavailable");
        if(read<std::uint16_t>(header,2)==65535||read<std::int16_t>(header,4)!=1)continue;
        result[group]=CutsceneNpcRequest{read<std::uint16_t>(header,6),std::uint8_t(read<std::int16_t>(header,10)^1)};
    }
    return result;
}
std::shared_ptr<const PreparedCutsceneNpcActors> NpcActorConstruction::prepare_cutscene_npcs(
    const gameplay_scenario::CutsceneDescriptor& descriptor,const ActorAssets& assets,const NpcMotionBindings& banks)const{
    auto result=std::shared_ptr<PreparedCutsceneNpcActors>(new PreparedCutsceneNpcActors);
    const auto requests=cutscene_npc_requests(descriptor);result->entries_.resize(requests.size());
    for(std::size_t group=0;group<requests.size();++group){
        if(!requests[group])continue;
        auto& entry=result->entries_[group];const auto header=descriptor.section(descriptor.actor_groups()[group][7]);entry.request=requests[group];
        entry.actor=prepare(entry.request->id,entry.request->model_class,assets,banks);
        entry.scale_profile=std::uint8_t(read<std::uint32_t>(header,20));entry.visibility=read<std::uint32_t>(header,24);
        entry.parameters=descriptor.actor_parameters(group);++result->count_;
    }
    return result;
}
NpcConstructed NpcActorConstruction::create_cutscene_npc(const PreparedCutsceneNpcActors& prepared,std::size_t group,NpcSceneGraphics* graphics)noexcept{
    if(world_.closed())return{NpcConstructionStatus::closed,{}};
    if(world_.busy())return{NpcConstructionStatus::busy,{}};
    if(group>=prepared.entries_.size()||!prepared.entries_[group].actor)return{};
    if(!world_.session().asset_loading_mode)return{};
    if(*world_.session().asset_loading_mode==0&&!graphics)return{};
    const auto& entry=prepared.entries_[group];auto result=create(*entry.actor);
    if(result.status!=NpcConstructionStatus::completed)return result;
    auto& pool=world_.auxiliary_actors();world_.updating_=true;pool.mutating_=true;
    struct Reset {bool& world;bool& pool;~Reset(){world=false;pool=false;}}reset{world_.updating_,pool.mutating_};
    try{
        const auto actor=world_.resolve(result.id);const auto model=actor->model;
        std::fill(actor->scripted->part_visibility.begin(),actor->scripted->part_visibility.end(),1);
        actor->scripted->scale_profile=entry.scale_profile;
        if(!entry.scale_profile){actor->model_scale={1,1,1};initialize_model_constraints(world_,*actor);}
        // Source3243D7 is an asset-loading mode, independent of pause4BADF8.
        // Constraint initialization above continues to consult actual pause.
        if(!world_.session().asset_loading_mode)return{NpcConstructionStatus::unavailable,result.id};
        if(*world_.session().asset_loading_mode==0){
            if(!graphics||!graphics->prepare_shadow(world_,result.id,actor->model_variant))return{NpcConstructionStatus::unavailable,result.id};
            if(world_.resolve(result.id)!=actor||actor->model!=model||!actor->npc||!actor->scripted)return{NpcConstructionStatus::unavailable,result.id};
        }
        for(unsigned part=0;part<std::min<std::size_t>(actor->scripted->part_visibility.size(),32);++part)actor->scripted->part_visibility[part]=std::uint8_t((entry.visibility>>part)&1u);
        return result;
    }catch(const std::bad_alloc&){return{NpcConstructionStatus::no_memory,result.id};}
    catch(...){return{NpcConstructionStatus::unavailable,result.id};}
}
}
