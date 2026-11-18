#include "primary_actor_models.hpp"
#include "primary_actor_initialization_internal.hpp"
#include "../gameplay_update/update.hpp"
#include "model_constraints.hpp"
#include "scene_primary_actors.hpp"
#include "actor_ownership_copy.hpp"
#include <cstring>
#include <limits>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_world {
struct PrimaryModelDomain {};
PrimaryActorModels::PrimaryActorModels(World& world,HumanoidMotionOwner& motions)
    :world_(world),motions_(motions),domain_(std::make_shared<const PrimaryModelDomain>()){
    if(world_.closed()||world_.busy()||world_.primary_model_owner_||&motions_.world_!=&world_||motions_.closed_||world_.humanoid_motion_source_!=&motions_)
        throw std::invalid_argument("Native primary model owner unavailable or foreign");
    world_.primary_model_owner_=this;
}
PrimaryActorModels::~PrimaryActorModels(){if(running_||world_.busy())std::terminate();(void)close();}
PrimaryModelStatus PrimaryActorModels::close()noexcept{
    if(running_||world_.busy())return PrimaryModelStatus::busy;
    running_=world_.updating_=true;
    struct Reset{bool& running;bool& world;~Reset(){world=false;running=false;}}reset{running_,world_.updating_};
    closed_=true;if(world_.primary_model_owner_==this)world_.primary_model_owner_=nullptr;
    scene_open_=scene_reset_=false;scene_records_={};return_bindings_={};
    const auto previous=std::move(rows_);rows_={};(void)previous;
    return PrimaryModelStatus::completed;
}
std::optional<PrimaryModelRequest> PrimaryActorModels::capture(actors::EntityId id)const noexcept{
    return capture(std::move(id),false);
}
std::optional<PrimaryModelRequest> PrimaryActorModels::capture_release(actors::EntityId id)const noexcept{
    return capture(std::move(id),true);
}
std::optional<PrimaryModelRequest> PrimaryActorModels::capture(actors::EntityId id,bool retirement,bool nested,bool temporary)const noexcept{
    if(closed_||world_.closed()||(!nested&&(running_||world_.busy()))||(nested&&(!running_||!world_.updating_))||motions_.closed_||world_.humanoid_motion_source_!=&motions_||!motions_.snapshot()||(!retirement&&(!world_.session().asset_loading_mode||!*world_.session().asset_loading_mode)))return{};
    if(scene_open_!=temporary)return{};
    const auto actor=world_.resolve(id);
    if(!actor||actor->slot>=8||(!retirement&&actor->character>=8)||(actor->model&&!actor->animation)||(actor->animation&&actor->animation->model()!=actor->model))return{};
    if(temporary){if(!world_.scene_primary_actors_||world_.scene_primary_actors_->physical_slot(id)!=actor->slot||scene_records_[actor->slot].construction.id!=id||!actor->active)return{};}
    else if(world_.primary(actor->slot)!=actor)return{};
    const auto& row=rows_[actor->slot];
    if(!temporary&&(row.key.character!=255||row.resources.primary)&&row.actor!=id)return{};
    if(!temporary&&row.resources.primary&&(row.resources.primary!=actor->model||row.resources.asset!=actor->model_asset||
       !actor->animation||row.resources.secondary!=actor->animation->secondary_model()))return{};
    PrimaryModelRequest result;result.domain_=domain_;result.revision_=revision_;result.actor_=std::move(id);
    result.playback_=actor->animation;result.model_=actor->model;result.asset_=actor->model_asset;result.banks_=motions_.snapshot();
    result.secondary_policy_=!actor->animation||actor->animation->secondary_bank_enabled();
    result.slot_=actor->slot;result.character_=actor->character;result.model_class_=actor->model_pose_class;
    result.variant_=actor->model_variant;result.appearance_=actor->appearance_variant;result.loading_mode_=world_.session().asset_loading_mode.value_or(0);
    result.expected_appearance_=actor->appearance_variant;
    result.previous_character_=row.key.character;
    result.previous_model_class_=row.key.model_class;result.retirement_=retirement;
    result.temporary_=temporary;result.physical_=row.resources;
    result.rebuild_=row.key.character==255||row.key.character!=actor->character||row.key.model_class!=actor->model_pose_class;
    if(!retirement&&!result.rebuild_&&(temporary?(!row.resources.asset||!row.resources.primary):(!actor->model_asset||!actor->model||!actor->animation)))return{};
    return result;
}
std::optional<PrimaryModelRequest> PrimaryActorModels::capture_scene(actors::EntityId id,const gameplay_scenario::CutsceneDescriptor& descriptor,std::size_t group)const{
    return capture_scene(std::move(id),descriptor,group,false);
}
std::optional<PrimaryModelRequest> PrimaryActorModels::capture_scene(actors::EntityId id,const gameplay_scenario::CutsceneDescriptor& descriptor,std::size_t group,bool temporary)const{
    if(group>=descriptor.actor_groups().size())return{};
    const auto bytes=descriptor.section(descriptor.actor_groups()[group][7]);
    if(bytes.size()<36)throw std::invalid_argument("Native primary scene header unavailable");
    std::uint16_t active;std::int16_t kind;std::memcpy(&active,bytes.data()+2,2);std::memcpy(&kind,bytes.data()+4,2);
    if(active==65535||(kind!=0&&kind!=3))return{};
    auto request=capture(std::move(id),false,false,temporary);if(!request)return{};
    if(temporary){std::int16_t definition;std::memcpy(&definition,bytes.data()+10,2);if(std::uint8_t(definition^1)!=request->model_class_)return{};}
    const auto actor=world_.resolve(request->actor_);if(!actor||actor->category!=0)return{};
    PrimarySceneActorProfile scene;std::uint32_t scale;std::memcpy(&scale,bytes.data()+20,4);scene.scale_profile=std::uint8_t(scale);std::memcpy(&scene.visibility,bytes.data()+24,4);
    scene.parameters=descriptor.actor_parameters(group);request->scene_=std::move(scene);request->appearance_=0;
    return request;
}
std::shared_ptr<const PreparedPrimaryModel> PrimaryActorModels::prepare(const PrimaryModelRequest& request,const ActorAssets& assets,const HumanoidMotionAssets& motions){
    if(!request.domain_||!request.banks_)throw std::invalid_argument("Native primary model request unavailable");
    if(request.retirement_)return prepare_release(request,motions);
    auto result=std::shared_ptr<PreparedPrimaryModel>(new PreparedPrimaryModel);result->request_=request;result->banks_=request.banks_;
    if(request.rebuild_){
        result->asset_=request.variant_?assets.read_substituted_model(request.variant_,request.model_class_,request.character_):assets.read_primary(request.character_,request.appearance_,request.model_class_);
        if(!result->asset_||(result->model_=result->asset_->make_instance())==nullptr)throw std::invalid_argument("Native primary model skeleton unavailable");
        if(request.playback_){if(request.secondary_policy_)result->secondary_=animation::PoseBlend::create_sibling(*result->model_);}
        else result->first_playback_=std::make_shared<animation::Playback>(result->model_);
        if(request.previous_character_!=255)result->banks_=motions.release_character(request.previous_character_,*request.banks_);
    }else if(request.temporary_){
        if(!request.physical_.asset||!request.physical_.primary)throw std::invalid_argument("Native resident scene work unavailable");
        result->asset_=request.physical_.asset;result->model_=std::make_shared<animation::Instance>(*request.physical_.primary);
        if(request.playback_){
            if(request.secondary_policy_)result->secondary_=request.physical_.secondary?std::make_shared<animation::Instance>(*request.physical_.secondary):animation::PoseBlend::create_sibling(*result->model_);
        }else result->first_playback_=std::make_shared<animation::Playback>(result->model_);
    }
    if(request.scene_){
        const auto asset=(request.rebuild_||request.temporary_)?result->asset_:request.asset_;
        if(!asset||asset->part_count()>32)throw std::invalid_argument("Native primary scene visibility extent unavailable");
        result->scene_visibility_.resize(asset->part_count());
        for(unsigned part=0;part<asset->part_count();++part)result->scene_visibility_[part]=std::uint8_t((request.scene_->visibility>>part)&1u);
    }
    return result;
}
std::shared_ptr<const PreparedPrimaryModel> PrimaryActorModels::prepare_release(const PrimaryModelRequest& request,const HumanoidMotionAssets& motions){
    if(!request.domain_||!request.banks_||!request.retirement_)throw std::invalid_argument("Native primary retirement request unavailable");
    auto result=std::shared_ptr<PreparedPrimaryModel>(new PreparedPrimaryModel);result->request_=request;result->banks_=request.banks_;
    if(request.previous_character_!=255&&request.previous_model_class_!=255)result->banks_=motions.release_character(request.previous_character_,*request.banks_);
    return result;
}
std::vector<std::array<std::shared_ptr<const animation::MotionBank>,3>> PrimaryActorModels::retain_resources()const{
    std::vector<std::array<std::shared_ptr<const animation::MotionBank>,3>> retained;retained.reserve(world_.entities_.size());
    for(const auto& id:world_.entities_.identities()){const auto actor=world_.resolve(id);if(actor&&actor->animation)retained.push_back(actor->animation->resources);}
    return retained;
}
PrimaryModelApplied PrimaryActorModels::apply(const PreparedPrimaryModel& prepared,const gameplay_update::State& state,const PrimaryEquipmentContext* equipment)noexcept{
    return apply(prepared,state,equipment,false);
}
PrimaryModelApplied PrimaryActorModels::apply(const PreparedPrimaryModel& prepared,const gameplay_update::State& state,const PrimaryEquipmentContext* equipment,bool nested)noexcept{
    if(closed_||world_.closed()||motions_.closed_)return{PrimaryModelStatus::closed};
    if((!nested&&(running_||world_.busy()))||(nested&&(!running_||!world_.updating_)))return{PrimaryModelStatus::busy};
    const auto& request=prepared.request_;
    if(request.domain_!=domain_||request.revision_!=revision_||request.banks_!=motions_.snapshot())return{PrimaryModelStatus::stale};
    if(scene_open_!=request.temporary_)return{PrimaryModelStatus::stale};
    const auto actor=world_.resolve(request.actor_);
    if(!actor||actor->slot!=request.slot_||actor->character!=request.character_||actor->model_pose_class!=request.model_class_||actor->model_variant!=request.variant_||actor->appearance_variant!=request.expected_appearance_||actor->model!=request.model_||actor->model_asset!=request.asset_||actor->animation!=request.playback_||(!request.retirement_&&world_.session().asset_loading_mode!=request.loading_mode_)||world_.humanoid_motion_source_!=&motions_)return{PrimaryModelStatus::stale};
    if(request.temporary_){
        if(!world_.scene_primary_actors_||world_.scene_primary_actors_->physical_slot(request.actor_)!=request.slot_||scene_records_[request.slot_].construction.id!=request.actor_)return{PrimaryModelStatus::stale};
        if(state.notification_pending&&world_.paused==0)return{}; // Borrowed-slot restore requires its own pointer association profile.
    }else if(world_.primary(request.slot_)!=actor)return{PrimaryModelStatus::stale};
    if(revision_==std::numeric_limits<std::uint64_t>::max())return{};
    const bool previous_running=running_,previous_busy=world_.updating_;running_=world_.updating_=true;
    struct Reset{bool& running;bool& world;bool previous_running,previous_world;~Reset(){world=previous_world;running=previous_running;}}reset{running_,world_.updating_,previous_running,previous_busy};
    PrimaryModelApplied result;
    try{
        // Shared publication changes aliases on other actors too. Their old
        // custom leases must survive the entire model/cache operation. A
        // nested scene-entry call is covered by that outer owner's retention.
        const auto previous_resources=nested?decltype(retain_resources()){}:retain_resources();(void)previous_resources;
        // Retire every old lease only after canonical pointers/cache agree and
        // while reentrant public mutations still observe the outer busy guard.
        const auto previous_model=actor->model,previous_secondary=actor->animation?actor->animation->secondary_model():nullptr;
        const auto previous_resident=rows_[request.slot_].resources;(void)previous_resident;
        const auto previous_asset=actor->model_asset;const auto previous_constraints=actor->constraints;
        (void)previous_model;(void)previous_secondary;(void)previous_asset;(void)previous_constraints;
        // Allocate postlude storage before changing the live actor. Authored
        // parameters remain immutable in the prepared scene-group result.
        auto scene_visibility=prepared.scene_visibility_;
        ++revision_;
        if(request.retirement_){
            if(request.previous_character_!=255&&request.previous_model_class_!=255){
                const auto published=motions_.publish_nested(prepared.banks_,true);
                if(published.status!=HumanoidPublicationStatus::completed)return{published.status==HumanoidPublicationStatus::no_memory?PrimaryModelStatus::no_memory:PrimaryModelStatus::unavailable};
                result.character_released=true;
                if(!actor->animation)return result;
                actor->animation->retire_model();actor->model.reset();actor->model_asset.reset();actor->visible=false;
                actor->collision.joint_two_position.reset();actor->collision.pose_ready=false;rows_[request.slot_]={};result.retired=true;
            }
            result.status=PrimaryModelStatus::completed;return result;
        }
        if(request.scene_){actor->room=world_.room;actor->appearance_variant=0;actor->movement_enabled=1;}
        if(request.rebuild_||request.temporary_){
            if(!prepared.asset_||!prepared.model_||!prepared.banks_)return{};
            // Validate the retained root history before any shared publication.
            if(actor->animation)animation::PoseBlend::root_reference(*prepared.model_,actor->animation->root_reference());
            if(request.rebuild_&&request.previous_character_!=255){
                const auto published=motions_.publish_nested(prepared.banks_,true);
                if(published.status!=HumanoidPublicationStatus::completed)return{published.status==HumanoidPublicationStatus::no_memory?PrimaryModelStatus::no_memory:PrimaryModelStatus::unavailable};
                result.character_released=true;
            }
            // Source5EC010 clears visibility on replacement. Initial cache fill
            // and reuse preserve that byte. Rendering-resource retirement is a
            // separate required Stage5 boundary, never a successful fake call.
            if(request.rebuild_&&request.previous_character_!=255)actor->visible=false;
            if(request.rebuild_)rows_[request.slot_]={};
            if(actor->animation)actor->animation->replace_model_prepared(prepared.model_,prepared.secondary_);
            else actor->animation=prepared.first_playback_;
            actor->model=prepared.model_;actor->model_asset=prepared.asset_;
            // Physical resources are resident independently of the Actor ID.
            // Even a later initializer refusal leaves this committed prefix
            // owned; an invalid cache key must not discard allocated work.
            rows_[request.slot_].actor=request.actor_;
            rows_[request.slot_].resources={actor->model_asset,actor->model,actor->animation->secondary_model()};
            actor->collision.joint_two_position.reset();actor->collision.pose_ready=false;
            result.replaced=request.rebuild_;result.rebound=request.temporary_;
        }
        const auto initialized=PrimaryActorInitialization::select(world_,state,request.actor_,request.character_,*prepared.banks_,equipment,true,request.temporary_);
        if(initialized!=PrimaryInitializationStatus::completed){result.status=initialized==PrimaryInitializationStatus::no_memory?PrimaryModelStatus::no_memory:PrimaryModelStatus::unavailable;return result;}
        result.initialized=true;
        rows_[request.slot_]={CacheKey{actor->character,actor->model_pose_class},request.actor_,
            {actor->model_asset,actor->model,actor->animation->secondary_model()}};
        if(request.scene_){
            if(!actor->primary_state)return result;
            if(!actor->scripted)actor->scripted.emplace();
            actor->scripted->scale_profile=request.scene_->scale_profile;
            if(!request.scene_->scale_profile){actor->model_scale={1,1,1};initialize_model_constraints(world_,*actor);}
            actor->primary_state->part_visibility=std::move(scene_visibility);
        }
        if(request.temporary_)scene_records_[request.slot_].bound=true;
        result.status=PrimaryModelStatus::completed;return result;
    }catch(const std::bad_alloc&){result.status=PrimaryModelStatus::no_memory;return result;}catch(...){return result;}
}
PrimarySceneEntryReleased PrimaryActorModels::release_scene_entry(const HumanoidMotionAssets& content)noexcept{
    if(closed_||world_.closed()||motions_.closed_)return{PrimaryModelStatus::closed};
    if(running_||world_.busy())return{PrimaryModelStatus::busy};
    if(scene_open_)return{};
    if(world_.humanoid_motion_source_!=&motions_||!motions_.snapshot())return{};
    // Reject a missing/stale live cache row before releasing any other slot.
    for(unsigned slot=0;slot<4;++slot){
        const auto& row=rows_[slot];if(row.key.character==255||row.key.model_class==255)continue;
        const auto actor=world_.resolve(row.actor);
        if(!actor||actor!=world_.primary(slot)||actor->slot!=slot||!actor->animation||actor->animation->model()!=actor->model)return{PrimaryModelStatus::unavailable,0,0,0,false,slot};
    }
    running_=world_.updating_=true;
    struct Reset{bool& running;bool& world;~Reset(){world=false;running=false;}}reset{running_,world_.updating_};
    PrimarySceneEntryReleased result;
    try{
        const auto previous_resources=retain_resources();(void)previous_resources;
        const gameplay_update::State unused{};
        for(unsigned slot=0;slot<4;++slot){
            ++result.visited;const auto actor=world_.primary(slot);
            if(!actor)continue; // Known absent native actor + invalid cache is source no-op.
            const auto request=capture(world_.identity_of(*actor),true,true);
            if(!request){result.failed_slot=slot;return result;}
            const auto prepared=prepare_release(*request,content);const auto released=apply(*prepared,unused,nullptr,true);
            result.retired+=released.retired;result.character_releases+=released.character_released;
            if(released.status!=PrimaryModelStatus::completed){result.status=released.status;result.failed_slot=slot;return result;}
        }
        const auto banks=content.release_base(*motions_.snapshot());const auto published=motions_.publish_nested(banks,true);
        if(published.status!=HumanoidPublicationStatus::completed){result.status=published.status==HumanoidPublicationStatus::no_memory?PrimaryModelStatus::no_memory:PrimaryModelStatus::unavailable;return result;}
        result.base_released=true;result.status=PrimaryModelStatus::completed;return result;
    }catch(const std::bad_alloc&){result.status=PrimaryModelStatus::no_memory;return result;}catch(...){return result;}
}
PrimarySceneConstructed PrimaryActorModels::construct_scene_primary(
    const gameplay_scenario::CutscenePrimaryChoice& choice,
    gameplay_scenario::CutscenePrimaryRoster& roster,const HumanoidMotionAssets& content)noexcept{
    if(closed_||world_.closed()||motions_.closed_)return{PrimaryModelStatus::closed};
    if(running_||world_.busy())return{PrimaryModelStatus::busy};
    if(scene_open_)return{};
    if(choice.group>=32||choice.temporary_slot>=8||roster.eligible_count>8||world_.humanoid_motion_source_!=&motions_)return{};
    PrimarySceneConstructed result;
    try{
        auto& pool=world_.scene_primary_actors();if(pool.closed_)return{PrimaryModelStatus::closed};if(!pool.initialized())return{};
        actors::EntityId old_id;std::shared_ptr<Actor> destination;
        for(unsigned slot=0;slot<8;++slot){
            const auto actor=world_.resolve(pool.slots_[slot]);if(!actor)return{};
            if(actor->active)continue;
            if(slot!=choice.temporary_slot)return{PrimaryModelStatus::stale};
            old_id=pool.slots_[slot];destination=actor;break;
        }
        if(!destination)return{PrimaryModelStatus::full};
        std::optional<std::uint8_t> matched;
        for(unsigned i=0;i<8;++i)if(roster.characters[i]==choice.character){matched=std::uint8_t(i);break;}
        if(matched!=choice.cloned_roster_slot)return{PrimaryModelStatus::stale};
        auto source=matched?world_.primary(*matched):destination;if(!source)return{};
        auto copied=copy_actor_owned(*source);
        if(copied.status!=ActorCopyStatus::completed)return{copied.status==ActorCopyStatus::no_memory?PrimaryModelStatus::no_memory:PrimaryModelStatus::unavailable};
        auto& actor=*copied.actor;actor.slot=choice.temporary_slot;
        actor.active=true;actor.visible=false;actor.primary=6;actor.secondary=actor.phase=actor.subphase=0;
        actor.model_variant=0;actor.character=choice.character;actor.room=world_.room;actor.model_pose_class=choice.model_class;
        if(!actor.scripted)actor.scripted.emplace();
        auto& script=*actor.scripted;script.cue_phase=0;script.request_flags=0;
        actor.model_correction_skip=0;script.scale_lock=script.motion_selector=0;script.request_phase=0;script.motion_blend_duration=0;
        script.relation_mode=0;script.related_actor={};script.relation_options=script.relation_parameter=0;script.relation_offset={};
        script.command_angles={};script.movement_angles={};script.forward_step=0;script.yaw_step=script.movement_remaining=0;
        script.track_two_motion=0;script.scale_profile=0;
        std::shared_ptr<const PreparedPrimaryModel> prepared_retirement;
        if(matched&&choice.model_class==1){
            const auto request=capture_release(world_.identity(*matched));if(!request)return{};
            prepared_retirement=prepare_release(*request,content);
        }
        running_=world_.updating_=pool.mutating_=true;
        struct Reset{bool& running;bool& world;bool& pool;~Reset(){pool=false;world=false;running=false;}}reset{running_,world_.updating_,pool.mutating_};
        const auto previous_destination=std::move(destination),previous_source=std::move(source);
        const auto retirement=std::move(prepared_retirement);const auto previous_resources=retain_resources();
        (void)previous_destination;(void)previous_source;(void)previous_resources;
        const auto created=world_.entities_.create(std::move(copied.actor));
        if(created.status!=actors::EntityStatus::completed)return{created.status==actors::EntityStatus::no_memory?PrimaryModelStatus::no_memory:PrimaryModelStatus::full};
        pool.slots_[choice.temporary_slot]=created.id;(void)world_.entities_.retire(old_id);
        result.id=created.id;result.roster_slot=matched;result.release_on_exit=!matched||choice.model_class==1;
        scene_records_[choice.temporary_slot]={result,choice.group,false,false};
        if(retirement){
            const gameplay_update::State unused{};const auto released=apply(*retirement,unused,nullptr,true);
            result.retirement_completed=released.status==PrimaryModelStatus::completed;result.main_model_retired=released.retired;
            if(!result.retirement_completed){result.status=released.status;scene_records_[choice.temporary_slot].construction=result;return result;}
            roster.characters[*matched]=255;
        }
        result.status=PrimaryModelStatus::completed;scene_records_[choice.temporary_slot].construction=result;return result;
    }catch(const std::bad_alloc&){result.status=PrimaryModelStatus::no_memory;return result;}catch(...){return result;}
}
bool PrimaryActorModels::owns(const PrimarySceneModelScope& scope)const noexcept{
    return !closed_&&scene_open_&&scope.domain_==domain_&&scope.epoch_==scene_epoch_;
}
std::optional<PrimarySceneModelScope> PrimaryActorModels::open_scene_models()noexcept{
    if(closed_||world_.closed()||running_||world_.busy()||scene_open_||motions_.closed_||
       !motions_.snapshot()||scene_epoch_==std::numeric_limits<std::uint64_t>::max()||revision_==std::numeric_limits<std::uint64_t>::max())return{};
    const auto* pool=world_.scene_primary_actors_.get();if(!pool||!pool->initialized())return{};
    std::array<actors::EntityId,8> returning{};std::array<bool,32> groups{};
    for(unsigned slot=0;slot<8;++slot){
        const auto temporary=world_.resolve(pool->identity_at(slot));if(!temporary)return{};
        const auto& record=scene_records_[slot];
        if(temporary->active){
            if(record.construction.id!=pool->identity_at(slot)||record.construction.status!=PrimaryModelStatus::completed||record.group>=groups.size()||groups[record.group])return{};
            groups[record.group]=true;
        }else if(record.construction.id)return{};
        const auto main=world_.primary(slot);const auto& row=rows_[slot];
        if(row.resources.primary&&(!main||world_.identity(slot)!=row.actor||main->model!=row.resources.primary||main->model_asset!=row.resources.asset||!main->animation||main->animation->secondary_model()!=row.resources.secondary))return{};
        if(main&&main->active&&main->animation&&main->primary_state&&main->animation->model()==main->model)returning[slot]=world_.identity(slot);
    }
    return_bindings_=std::move(returning);scene_open_=true;scene_reset_=false;++scene_epoch_;++revision_;
    PrimarySceneModelScope result;result.domain_=domain_;result.epoch_=scene_epoch_;return result;
}
std::optional<PrimaryModelRequest> PrimaryActorModels::capture_scene(const PrimarySceneModelScope& scope,actors::EntityId id,
    const gameplay_scenario::CutsceneDescriptor& descriptor,std::size_t group)const{
    if(!owns(scope)||scene_reset_)return{};
    const auto actor=world_.resolve(id);if(!actor||actor->slot>=8||scene_records_[actor->slot].group!=group||scene_records_[actor->slot].released)return{};
    return capture_scene(std::move(id),descriptor,group,true);
}
PrimaryModelStatus PrimaryActorModels::reset_scene_actors(const PrimarySceneModelScope& scope)noexcept{
    if(closed_||world_.closed()||motions_.closed_)return PrimaryModelStatus::closed;
    if(running_||world_.busy())return PrimaryModelStatus::busy;
    if(!owns(scope))return PrimaryModelStatus::stale;
    if(scene_reset_)return PrimaryModelStatus::completed;
    if(revision_==std::numeric_limits<std::uint64_t>::max()||!world_.scene_primary_actors_)return PrimaryModelStatus::unavailable;
    running_=world_.updating_=true;
    struct Reset{bool& running;bool& world;~Reset(){world=false;running=false;}}reset{running_,world_.updating_};
    const auto status=world_.scene_primary_actors_->initialize(true,true);
    if(status!=ScenePrimaryStatus::completed)return status==ScenePrimaryStatus::no_memory?PrimaryModelStatus::no_memory:status==ScenePrimaryStatus::entity_capacity?PrimaryModelStatus::full:PrimaryModelStatus::unavailable;
    scene_reset_=true;++revision_;return PrimaryModelStatus::completed;
}
PrimaryModelApplied PrimaryActorModels::release_scene_model(const PrimarySceneModelScope& scope,std::size_t slot,const HumanoidMotionAssets& content)noexcept{
    if(closed_||world_.closed()||motions_.closed_)return{PrimaryModelStatus::closed};
    if(running_||world_.busy())return{PrimaryModelStatus::busy};
    if(!owns(scope)||slot>=8)return{PrimaryModelStatus::stale};
    if(!scene_reset_)return{};
    auto& record=scene_records_[slot];
    if(!record.construction.id||!record.construction.release_on_exit||record.group>=16)return{};
    if(record.released)return{PrimaryModelStatus::completed};
    if(revision_==std::numeric_limits<std::uint64_t>::max()||world_.humanoid_motion_source_!=&motions_||!motions_.snapshot())return{};
    running_=world_.updating_=true;
    struct Reset{bool& running;bool& world;~Reset(){world=false;running=false;}}reset{running_,world_.updating_};
    PrimaryModelApplied result;
    try{
        const auto previous_resources=retain_resources();const auto previous=rows_[slot];(void)previous_resources;
        const auto actor=world_.resolve(record.construction.id);
        const auto previous_actor_model=actor?actor->model:nullptr,previous_secondary=actor&&actor->animation?actor->animation->secondary_model():nullptr;
        const auto previous_asset=actor?actor->model_asset:nullptr;(void)previous_actor_model;(void)previous_secondary;(void)previous_asset;
        ++revision_;
        if(previous.key.character!=255&&previous.key.model_class!=255){
            const auto candidate=content.release_character(previous.key.character,*motions_.snapshot());
            const auto published=motions_.publish_nested(candidate,true);
            if(published.status!=HumanoidPublicationStatus::completed){result.status=published.status==HumanoidPublicationStatus::no_memory?PrimaryModelStatus::no_memory:PrimaryModelStatus::unavailable;return result;}
            result.character_released=true;
            if(actor&&actor->animation&&actor->model==previous.resources.primary){
                actor->animation->retire_model();actor->model.reset();actor->model_asset.reset();actor->visible=false;
                actor->collision.joint_two_position.reset();actor->collision.pose_ready=false;
            }
            rows_[slot]={};result.retired=true;
        }
        record.released=true;result.status=PrimaryModelStatus::completed;return result;
    }catch(const std::bad_alloc&){result.status=PrimaryModelStatus::no_memory;return result;}catch(...){return result;}
}
PrimaryModelStatus PrimaryActorModels::return_scene_models(const PrimarySceneModelScope& scope)noexcept{
    return return_scene_models(scope,true);
}
PrimaryModelStatus PrimaryActorModels::continue_scene_models(const PrimarySceneModelScope& scope)noexcept{
    return return_scene_models(scope,false);
}
PrimaryModelStatus PrimaryActorModels::return_scene_models(const PrimarySceneModelScope& scope,bool final_exit)noexcept{
    if(closed_||world_.closed()||motions_.closed_)return PrimaryModelStatus::closed;
    if(running_||world_.busy())return PrimaryModelStatus::busy;
    if(!owns(scope))return PrimaryModelStatus::stale;
    if(!scene_reset_)return PrimaryModelStatus::unavailable;
    if(revision_==std::numeric_limits<std::uint64_t>::max())return PrimaryModelStatus::unavailable;
    if(final_exit)for(const auto& record:scene_records_)if(record.construction.id&&record.construction.release_on_exit&&record.group<16&&!record.released)return PrimaryModelStatus::unavailable;
    running_=world_.updating_=true;
    struct Reset{bool& running;bool& world;~Reset(){world=false;running=false;}}reset{running_,world_.updating_};
    try{
        struct Plan {std::shared_ptr<Actor> actor;std::shared_ptr<animation::Instance> primary,secondary,previous,previous_secondary;std::shared_ptr<const ActorModelAsset> previous_asset;};
        std::array<Plan,8> plans;
        for(unsigned slot=0;slot<8;++slot){
            if(!return_bindings_[slot])continue;
            const auto actor=world_.resolve(return_bindings_[slot]);
            if(!actor||actor!=world_.primary(slot)||!actor->animation||actor->animation->model()!=actor->model)return PrimaryModelStatus::stale;
            auto& plan=plans[slot];plan.actor=actor;plan.previous=actor->model;plan.previous_secondary=actor->animation->secondary_model();plan.previous_asset=actor->model_asset;
            const auto& resource=rows_[slot].resources;
            if(resource.primary){
                if(!resource.asset)return PrimaryModelStatus::unavailable;
                plan.primary=std::make_shared<animation::Instance>(*resource.primary);
                animation::PoseBlend::root_reference(*plan.primary,actor->animation->root_reference());
                if(actor->animation->secondary_bank_enabled())plan.secondary=resource.secondary?std::make_shared<animation::Instance>(*resource.secondary):animation::PoseBlend::create_sibling(*plan.primary);
            }
        }
        const auto previous_rows=rows_;(void)previous_rows;
        ++revision_;
        for(unsigned slot=0;slot<8;++slot){
            auto& plan=plans[slot];auto& row=rows_[slot];row.actor=return_bindings_[slot];
            if(!plan.actor)continue;
            auto& actor=*plan.actor;
            if(plan.primary){
                actor.animation->replace_model_prepared(plan.primary,plan.secondary);
                actor.model=plan.primary;actor.model_asset=row.resources.asset;
                row.resources={actor.model_asset,plan.primary,plan.secondary};
            }else{actor.animation->retire_model();actor.model.reset();actor.model_asset.reset();}
            actor.visible=false;actor.collision.joint_two_position.reset();actor.collision.pose_ready=false;
        }
        scene_open_=scene_reset_=false;scene_records_={};return_bindings_={};return PrimaryModelStatus::completed;
    }catch(const std::bad_alloc&){return PrimaryModelStatus::no_memory;}catch(...){return PrimaryModelStatus::unavailable;}
}
}
