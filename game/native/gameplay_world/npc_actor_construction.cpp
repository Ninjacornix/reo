#include "npc_actor_construction.hpp"
#include "motion_profiles.hpp"
#include <algorithm>
#include <bit>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
#include "npc_actor_definitions.inc"
#include "npc_actor_hit_definitions.inc"
}
const NpcDefinitionRecord& npc_actor_definition(std::uint16_t id){
    const auto found=std::lower_bound(npc_definitions.begin(),npc_definitions.end(),id,[](const auto& entry,auto value){return entry.id<value;});
    if(found==npc_definitions.end()||found->id!=id)throw std::out_of_range("Native NPC construction identity unavailable");
    return *found;
}
NpcActorConstruction::NpcActorConstruction(World& world):world_(world){(void)world_.auxiliary_actors();}
std::shared_ptr<const PreparedNpcActor> NpcActorConstruction::prepare(std::uint32_t identity,std::uint32_t model_class,
    const ActorAssets& assets,const NpcMotionBindings& bindings)const{
    auto result=std::shared_ptr<PreparedNpcActor>(new PreparedNpcActor);
    result->definition_=npc_actor_definition(std::uint16_t(identity));result->model_class_=std::uint8_t(model_class);
    result->character_=result->definition_.motion_style?5:3;
    if(result->definition_.contact_selector!=0)throw std::out_of_range("Native NPC construction contact profile unavailable");
    result->banks_={bindings.primary,bindings.style[result->definition_.motion_style?1:0],bindings.actor_type[result->character_]};
    if(std::any_of(result->banks_.begin(),result->banks_.end(),[](const auto& bank){return !bank;}))throw std::invalid_argument("Native NPC construction motion bindings unavailable");
    result->asset_=assets.read_npc(std::uint16_t(identity),result->model_class_);
    if(!result->asset_||!result->asset_->skeleton()||result->asset_->part_count()>255)throw std::invalid_argument("Native NPC construction model profile unavailable");
    return result;
}
NpcConstructed NpcActorConstruction::create(const PreparedNpcActor& prepared)noexcept{
    if(world_.closed())return{NpcConstructionStatus::closed,{}};
    if(world_.busy())return{NpcConstructionStatus::busy,{}};
    try{
        auto& pool=world_.auxiliary_actors();if(!pool.remaining())return{NpcConstructionStatus::full,{}};
        const std::array<HumanoidMotionAlias,3> aliases{{{HumanoidMotionFamily::scene_body,0},
            {prepared.definition_.motion_style?HumanoidMotionFamily::alternate:HumanoidMotionFamily::general,0},
            {HumanoidMotionFamily::character,prepared.character_}}};
        auto banks=prepared.banks_;
        for(unsigned index=0;index<aliases.size();++index){banks[index]=resolve_humanoid_motion_bank(world_,aliases[index],banks[index]);if(!banks[index])return{};}
        auto model=prepared.asset_->make_instance();auto playback=std::make_shared<animation::Playback>(model);
        playback->resources=std::move(banks);playback->resources_known=true;playback->channel_count=1;
        ScriptedActorState scripted;scripted.part_visibility.assign(prepared.asset_->part_count(),1);
        if(prepared.model_class_!=1&&scripted.part_visibility.size()>1)scripted.part_visibility[1]=0;
        gameplay_collision::hit_regions::Regions regions;regions.set(std::vector(npc_hit_definitions.begin(),npc_hit_definitions.end()));
        const File1MotionProfiles profiles;const auto body=profiles.body(0,0);const auto shape=profiles.shape(0,0).target;
        const auto created=pool.allocate(1);
        if(created.status==AuxiliaryStatus::full)return{NpcConstructionStatus::full,{}};
        if(created.status==AuxiliaryStatus::no_memory)return{NpcConstructionStatus::no_memory,{}};
        if(created.status!=AuxiliaryStatus::completed)return{};
        const auto actor=world_.resolve(created.id);const auto& definition=prepared.definition_;
        actor->active=true;actor->category=1;actor->character=prepared.character_;actor->ai_control=prepared.character_;
        actor->model_variant=definition.id;actor->model_pose_class=prepared.model_class_;
        actor->current=actor->maximum=definition.health;actor->motion_style=definition.motion_style;actor->motion_subtype=definition.motion_subtype;
        actor->model_scale={definition.scale,definition.scale,definition.scale};actor->motion_multiplier=1;
        actor->model_asset=prepared.asset_;actor->model=std::move(model);actor->animation=std::move(playback);
        actor->motion_bank_aliases={aliases[0],aliases[1],aliases[2]};
        actor->scripted=std::move(scripted);actor->npc=NpcActorState{definition.height_parameter,{},1};
        if(prepared.model_class_==1)actor->npc->attachment=pool.claim_attachment().slot;
        actor->collision.body_definition=body;actor->collision.local_center=actor->collision.previous_local_center=shape.center;
        actor->collision.radius=actor->collision.previous_radius=shape.radius;actor->collision.interpolation_target=shape;
        actor->contact.regions=std::move(regions);actor->auxiliary_status|=2;actor->room=world_.room;
        actor->targeting=TargetingState{0,false,std::uint8_t(0)};
        return{NpcConstructionStatus::completed,created.id};
    }catch(const std::bad_alloc&){return{NpcConstructionStatus::no_memory,{}};}
    catch(const std::exception&){return{};}
}
}
