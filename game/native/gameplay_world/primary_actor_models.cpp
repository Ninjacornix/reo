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
    closed_=true;if(world_.primary_model_owner_==this)world_.primary_model_owner_=nullptr;
    rows_={};return PrimaryModelStatus::completed;
}
std::optional<PrimaryModelRequest> PrimaryActorModels::capture(actors::EntityId id)const noexcept{
    return capture(std::move(id),false);
}
std::optional<PrimaryModelRequest> PrimaryActorModels::capture_release(actors::EntityId id)const noexcept{
    return capture(std::move(id),true);
}
std::optional<PrimaryModelRequest> PrimaryActorModels::capture(actors::EntityId id,bool retirement,bool nested)const noexcept{
    if(closed_||world_.closed()||(!nested&&(running_||world_.busy()))||(nested&&(!running_||!world_.updating_))||motions_.closed_||world_.humanoid_motion_source_!=&motions_||!motions_.snapshot()||(!retirement&&(!world_.session().asset_loading_mode||!*world_.session().asset_loading_mode)))return{};
    const auto actor=world_.resolve(id);
    if(!actor||actor->slot>=8||world_.primary(actor->slot)!=actor||(!retirement&&actor->character>=8)||(actor->model&&!actor->animation)||(actor->animation&&actor->animation->model()!=actor->model))return{};
    const auto& row=rows_[actor->slot];
    if(row.key.character!=255&&row.actor!=id)return{};
    PrimaryModelRequest result;result.domain_=domain_;result.revision_=revision_;result.actor_=std::move(id);
    result.playback_=actor->animation;result.model_=actor->model;result.asset_=actor->model_asset;result.banks_=motions_.snapshot();
    result.secondary_policy_=!actor->animation||actor->animation->secondary_bank_enabled();
    result.slot_=actor->slot;result.character_=actor->character;result.model_class_=actor->model_pose_class;
    result.variant_=actor->model_variant;result.appearance_=actor->appearance_variant;result.loading_mode_=world_.session().asset_loading_mode.value_or(0);
    result.expected_appearance_=actor->appearance_variant;
    result.previous_character_=row.key.character;
    result.previous_model_class_=row.key.model_class;result.retirement_=retirement;
    result.rebuild_=row.key.character==255||row.key.character!=actor->character||row.key.model_class!=actor->model_pose_class;
    if(!retirement&&!result.rebuild_&&(!actor->model_asset||!actor->model||!actor->animation))return{};
    return result;
}
std::optional<PrimaryModelRequest> PrimaryActorModels::capture_scene(actors::EntityId id,const gameplay_scenario::CutsceneDescriptor& descriptor,std::size_t group)const{
    if(group>=descriptor.actor_groups().size())return{};
    const auto bytes=descriptor.section(descriptor.actor_groups()[group][7]);
    if(bytes.size()<36)throw std::invalid_argument("Native primary scene header unavailable");
    std::uint16_t active;std::int16_t kind;std::memcpy(&active,bytes.data()+2,2);std::memcpy(&kind,bytes.data()+4,2);
    if(active==65535||kind!=0)return{};
    auto request=capture(std::move(id));if(!request)return{};
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
    }
    if(request.scene_){
        const auto asset=request.rebuild_?result->asset_:request.asset_;
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
    const auto actor=world_.resolve(request.actor_);
    if(!actor||world_.primary(request.slot_)!=actor||actor->slot!=request.slot_||actor->character!=request.character_||actor->model_pose_class!=request.model_class_||actor->model_variant!=request.variant_||actor->appearance_variant!=request.expected_appearance_||actor->model!=request.model_||actor->model_asset!=request.asset_||actor->animation!=request.playback_||(!request.retirement_&&world_.session().asset_loading_mode!=request.loading_mode_)||world_.humanoid_motion_source_!=&motions_)return{PrimaryModelStatus::stale};
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
        if(request.rebuild_){
            if(!prepared.asset_||!prepared.model_||!prepared.banks_)return{};
            // Validate the retained root history before any shared publication.
            if(actor->animation)animation::PoseBlend::root_reference(*prepared.model_,actor->animation->root_reference());
            if(request.previous_character_!=255){
                const auto published=motions_.publish_nested(prepared.banks_,true);
                if(published.status!=HumanoidPublicationStatus::completed)return{published.status==HumanoidPublicationStatus::no_memory?PrimaryModelStatus::no_memory:PrimaryModelStatus::unavailable};
                result.character_released=true;
            }
            // Source5EC010 clears visibility on replacement. Initial cache fill
            // and reuse preserve that byte. Rendering-resource retirement is a
            // separate required Stage5 boundary, never a successful fake call.
            if(request.previous_character_!=255)actor->visible=false;
            rows_[request.slot_]={};
            if(actor->animation)actor->animation->replace_model_prepared(prepared.model_,prepared.secondary_);
            else actor->animation=prepared.first_playback_;
            actor->model=prepared.model_;actor->model_asset=prepared.asset_;
            actor->collision.joint_two_position.reset();actor->collision.pose_ready=false;
            result.replaced=true;
        }
        const auto initialized=PrimaryActorInitialization::select(world_,state,request.actor_,request.character_,*prepared.banks_,equipment,true);
        if(initialized!=PrimaryInitializationStatus::completed){result.status=initialized==PrimaryInitializationStatus::no_memory?PrimaryModelStatus::no_memory:PrimaryModelStatus::unavailable;return result;}
        result.initialized=true;
        rows_[request.slot_]={CacheKey{actor->character,actor->model_pose_class},request.actor_};
        if(request.scene_){
            if(!actor->primary_state)return result;
            if(!actor->scripted)actor->scripted.emplace();
            actor->scripted->scale_profile=request.scene_->scale_profile;
            if(!request.scene_->scale_profile){actor->model_scale={1,1,1};initialize_model_constraints(world_,*actor);}
            actor->primary_state->part_visibility=std::move(scene_visibility);
        }
        result.status=PrimaryModelStatus::completed;return result;
    }catch(const std::bad_alloc&){result.status=PrimaryModelStatus::no_memory;return result;}catch(...){return result;}
}
PrimarySceneEntryReleased PrimaryActorModels::release_scene_entry(const HumanoidMotionAssets& content)noexcept{
    if(closed_||world_.closed()||motions_.closed_)return{PrimaryModelStatus::closed};
    if(running_||world_.busy())return{PrimaryModelStatus::busy};
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
    if(choice.group>=32||choice.temporary_slot>=8||roster.population>8||world_.humanoid_motion_source_!=&motions_)return{};
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
        script.motion_rate_mode=script.scale_lock=script.motion_selector=0;script.request_phase=0;script.motion_blend_duration=0;
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
        if(retirement){
            const gameplay_update::State unused{};const auto released=apply(*retirement,unused,nullptr,true);
            result.retirement_completed=released.status==PrimaryModelStatus::completed;result.main_model_retired=released.retired;
            if(!result.retirement_completed){result.status=released.status;return result;}
            roster.characters[*matched]=255;
        }
        result.status=PrimaryModelStatus::completed;return result;
    }catch(const std::bad_alloc&){result.status=PrimaryModelStatus::no_memory;return result;}catch(...){return result;}
}
}
