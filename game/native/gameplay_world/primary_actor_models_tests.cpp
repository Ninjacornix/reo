#include "primary_actor_models.hpp"
#include "actor_ownership_copy.hpp"
#include "scene_primary_actors.hpp"
#include "../gameplay_scenario/cutscene_roster_preparation.hpp"
#include "../animation/constraints.hpp"
#include "../gameplay_update/update.hpp"
#include "../gameplay_scenario/scenario_archive.hpp"
#include "runtime/assets/virtual_afs.h"
#include <bit>
#include <cstring>
#include <iostream>
#include <fstream>
#include <source_location>
namespace g=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace {
std::uint64_t checks{},loads{},reuses{},replacements{},shared_releases{},refusals{},original_cases{},original_calls{};
std::uint64_t scene_cases{},scene_parameters{},scene_original_cases{};
std::uint64_t retirements{},retirement_noops{},reloads{},detached_refusals{},retirement_original_cases{},generation_handoffs{};
std::uint64_t entry_cases{},entry_retirements{},entry_original_cases{},entry_guard_checks{},entry_refusals{};
std::uint64_t direct_guard_checks{};
std::uint64_t independent_detached_copies{};
std::uint64_t owned_actor_copies{},actor_copy_refusals{};
std::uint64_t construction_cases{},construction_original_cases{},construction_refusals{},construction_guards{};
std::uint64_t roster_world_cases{},roster_world_original_cases{},roster_world_refusals{};
std::uint64_t resident_lifetimes{},resident_stale_refusals{},resident_close_guards{},resident_retained_leases{},resident_prefixes{};
std::uint64_t scene_scope_cache_cases{},scene_scope_reuses{},scene_scope_rebuilds{},scene_scope_resets{},scene_scope_releases{},scene_scope_returns{},scene_scope_refusals{},scene_scope_reinitializations{};
std::uint64_t scene_scope_guards{},scene_scope_capacity_refusals{},scene_scope_absent_returns{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error(std::string("Primary model check ")+at.file_name()+":"+std::to_string(at.line()));
}
g::Profile profile(){g::Profile p;p.layouts.push_back({});return p;}
using Keys=std::array<g::PrimaryActorModels::CacheKey,8>;
Keys keys(const g::PrimaryActorModels& owner){Keys result;for(unsigned i=0;i<8;++i)result[i]=owner.key(i);return result;}
void compare_cache(const Keys&,const Keys&,unsigned,std::uint8_t,std::uint8_t,std::uint8_t,std::int8_t,const g::PrimaryModelApplied&);
void compare_primary_scene(const reo::native::gameplay_scenario::CutsceneDescriptor&,std::size_t,const g::Actor&,std::span<const reo::native::gameplay_scenario::CutsceneActorParameter>,std::uint16_t,std::int8_t);
void compare_release(const Keys&,const Keys&,unsigned,const g::PrimaryModelApplied&);
void compare_entry(const Keys&,const Keys&,const std::array<std::uint8_t,8>&,const std::array<std::uint8_t,8>&,const g::PrimarySceneEntryReleased&);
void compare_construction(const g::Actor&,const g::Actor&,const g::Actor&,const reo::native::gameplay_scenario::CutscenePrimaryRoster&,const reo::native::gameplay_scenario::CutscenePrimaryRoster&,const reo::native::gameplay_scenario::CutscenePrimaryChoice&,std::uint16_t,const g::PrimarySceneConstructed&);
void compare_roster_world(const g::World&,const reo::native::gameplay_scenario::CutsceneRosterState&,const reo::native::gameplay_scenario::CutsceneRosterState&,std::int32_t);
void basic(){
    g::Actor fresh;fresh.current=123;fresh.position={4,5,6};fresh.primary_state.emplace();fresh.primary_state->part_visibility={1,0,1};
    const auto copied=g::copy_actor_owned(fresh);check(copied.status==g::ActorCopyStatus::completed&&copied.actor&&copied.actor->current==123&&copied.actor->position.y==5&&!copied.actor->animation&&!copied.actor->model&&!copied.actor->constraints&&!copied.actor->scripted);
    copied.actor->primary_state->part_visibility[0]=0;check(fresh.primary_state->part_visibility[0]==1);++owned_actor_copies;
    g::World world(profile(),std::make_shared<g::Session>());g::HumanoidMotionOwner motions(world);g::PrimaryActorModels owner(world,motions);
    bool rejected{};try{g::PrimaryActorModels duplicate(world,motions);}catch(const std::invalid_argument&){rejected=true;}
    check(rejected&&!owner.capture({})&&owner.close()==g::PrimaryModelStatus::completed);
    g::World foreign(profile(),std::make_shared<g::Session>());rejected=false;
    try{g::PrimaryActorModels invalid(foreign,motions);}catch(const std::invalid_argument&){rejected=true;}check(rejected);
    check(!owner.capture({})&&motions.close()==g::HumanoidPublicationStatus::completed&&world.close()==g::Status::completed);
}
void owned(const char* archive){
    auto source=std::make_shared<reo::assets::Source>(archive);g::ActorAssets assets(source);g::HumanoidMotionAssets content(source);
    const auto base=content.base();const std::array<std::uint8_t,8> characters{0,1,2,3,4,5,6,7};const auto banks=content.overlay(1,characters,*base);
    for(unsigned slot=0;slot<8;++slot)for(unsigned character=0;character<8;++character)for(unsigned loading:{1u,128u})for(unsigned paused:{0u,1u}){
        g::World world(profile(),std::make_shared<g::Session>());world.session().asset_loading_mode=std::uint8_t(loading);world.paused=std::int8_t(paused);
        g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);g::PrimaryActorModels owner(world,motions);
        auto initial=std::make_unique<g::Actor>();initial->slot=std::uint8_t(slot);initial->character=std::uint8_t(character);initial->visible=true;
        const auto id=world.spawn_primary(slot,std::move(initial)).id;const auto actor=world.resolve(id);check(bool(actor));
        reo::native::gameplay_update::State state;
        const auto empty_release=g::PrimaryActorModels::prepare(owner.capture_release(id).value(),assets,content);const auto empty_before=keys(owner);
        const auto no_op=owner.apply(*empty_release,state);check(no_op.status==g::PrimaryModelStatus::completed&&!no_op.retired&&!no_op.character_released);
        compare_release(empty_before,keys(owner),slot,no_op);++retirement_noops;
        const auto request=owner.capture(id);check(bool(request));const auto prepared=g::PrimaryActorModels::prepare(*request,assets,content);
        const auto before=keys(owner);
        const auto loaded=owner.apply(*prepared,state);check(loaded.status==g::PrimaryModelStatus::completed&&loaded.replaced&&!loaded.character_released&&loaded.initialized);
        compare_cache(before,keys(owner),slot,std::uint8_t(character),0,std::uint8_t(loading),world.paused,loaded);++loads;
        check(actor->model&&actor->animation&&actor->animation->model()==actor->model&&actor->visible&&actor->primary_state&&actor->animation->resources_known&&!world.busy());
        const auto owned_copy=g::copy_actor_owned(*actor);check(owned_copy.status==g::ActorCopyStatus::completed&&owned_copy.actor&&!world.identity_of(*owned_copy.actor));
        const auto& clone=*owned_copy.actor;
        check(clone.model!=actor->model&&clone.animation!=actor->animation&&clone.animation->model()==clone.model&&clone.model_asset==actor->model_asset&&clone.motion_bank_aliases==actor->motion_bank_aliases&&clone.primary_state->part_visibility==actor->primary_state->part_visibility);
        check(bool(clone.constraints)==bool(actor->constraints)&&(!clone.constraints||(clone.constraints!=actor->constraints&&clone.constraints->model()==clone.model)));
        const auto old_translation=actor->model->local_translation(0);owned_copy.actor->model->local_translation(0,{111,222,333});const auto unchanged_translation=actor->model->local_translation(0);check(std::memcmp(&old_translation,&unchanged_translation,sizeof old_translation)==0);++owned_actor_copies;
        const auto canonical_model=actor->model;actor->model.reset();const auto refused_copy=g::copy_actor_owned(*actor);check(refused_copy.status==g::ActorCopyStatus::inconsistent_model&&!refused_copy.actor&&actor->animation->model()==canonical_model);actor->model=canonical_model;++actor_copy_refusals;
        if(slot==0&&character==0&&loading==1&&paused==0){
            g::Actor unbound=*actor;unbound.animation.reset();const auto unbound_copy=g::copy_actor_owned(unbound);
            check(unbound_copy.status==g::ActorCopyStatus::completed&&unbound_copy.actor->model!=unbound.model&&!unbound_copy.actor->animation&&unbound_copy.actor->constraints->model()==unbound_copy.actor->model);++owned_actor_copies;
            g::Actor secondary=*actor;secondary.constraints=std::make_shared<a::Constraints>(secondary.animation->secondary_model());const auto secondary_copy=g::copy_actor_owned(secondary);
            check(secondary_copy.status==g::ActorCopyStatus::completed&&secondary_copy.actor->constraints->model()==secondary_copy.actor->animation->secondary_model()&&secondary_copy.actor->constraints->model()!=secondary.constraints->model());++owned_actor_copies;
        }
        check(owner.apply(*prepared,state).status==g::PrimaryModelStatus::stale);++refusals;
        auto& channel=actor->animation->channel(a::ModelBank::primary,0);channel.timing.frame=3.25f;channel.selector=17;channel.blend_remaining=9;
        a::PoseBlend::root_reference(*actor->model,{12,34,56});actor->root_motion_delta={7,8,9};
        const auto old_model=actor->model,old_secondary=actor->animation->secondary_model();const auto old_asset=actor->model_asset;const auto old_playback=actor->animation;
        // Original cache keys exclude appearance and BB4. Even an unavailable
        // new filename must not be read when character/class still match.
        actor->appearance_variant=255;const auto reuse=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);const auto before_reuse=keys(owner);
        const auto reused=owner.apply(*reuse,state);check(reused.status==g::PrimaryModelStatus::completed&&!reused.replaced&&!reused.character_released);
        compare_cache(before_reuse,keys(owner),slot,std::uint8_t(character),0,std::uint8_t(loading),world.paused,reused);++reuses;
        check(actor->model==old_model&&actor->model_asset==old_asset&&actor->animation==old_playback&&actor->animation->secondary_model()==old_secondary&&channel.timing.frame==3.25f);
        // A second cache row uses the same character. Replacing the first must
        // still clear that character's shared bank and rebind both actors.
        const auto peer_slot=(slot+1)%8;auto peer_initial=std::make_unique<g::Actor>();peer_initial->slot=std::uint8_t(peer_slot);peer_initial->character=std::uint8_t(character);
        const auto peer_id=world.spawn_primary(peer_slot,std::move(peer_initial)).id;const auto peer=world.resolve(peer_id);
        const auto peer_prepared=g::PrimaryActorModels::prepare(owner.capture(peer_id).value(),assets,content);check(owner.apply(*peer_prepared,state).status==g::PrimaryModelStatus::completed);
        const auto old_bank=motions.snapshot()->character(character);const auto old_constraints=actor->constraints;if(old_constraints)old_constraints->floor_height(0,17);
        bool direct_retired{};
        peer->animation->resources[0]=std::shared_ptr<const a::MotionBank>(new a::MotionBank,[&](const a::MotionBank* bank){
            if(!world.busy()||owner.close()!=g::PrimaryModelStatus::busy||motions.close()!=g::HumanoidPublicationStatus::busy||owner.key(slot)!=g::PrimaryActorModels::CacheKey{std::uint8_t((character+1)%8),1}||actor->model==old_model||actor->animation!=old_playback||actor->animation->model()!=actor->model||actor->visible||peer->animation->resources[0]!=motions.snapshot()->bank({g::HumanoidMotionFamily::primary,0})){std::terminate();}
            direct_retired=true;delete bank;
        });
        actor->appearance_variant=0;actor->character=std::uint8_t((character+1)%8);actor->model_pose_class=1;
        const auto replacement=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);const auto before_replacement=keys(owner);
        const auto replaced=owner.apply(*replacement,state);check(replaced.status==g::PrimaryModelStatus::completed&&replaced.replaced&&replaced.character_released&&replaced.initialized);
        compare_cache(before_replacement,keys(owner),slot,actor->character,1,std::uint8_t(loading),world.paused,replaced);++replacements;
        check(direct_retired);++direct_guard_checks;
        check(actor->model!=old_model&&actor->model_asset!=old_asset&&actor->animation==old_playback&&actor->animation->secondary_model()!=old_secondary&&!actor->visible);
        const auto history=a::PoseBlend::root_reference(*actor->model);check(history.x==12&&history.y==34&&history.z==56&&actor->root_motion_delta.y==8);
        check(channel.timing.frame==3.25f&&channel.selector==17&&channel.blend_remaining==9);
        check(motions.snapshot()->character(character)!=old_bank&&motions.snapshot()->character(character)->cleared()&&!old_bank->cleared());
        check(peer->animation->resources[2]==motions.snapshot()->character(character)&&actor->animation->resources[2]==motions.snapshot()->character(actor->character));++shared_releases;
        if(!paused)check(actor->constraints&&actor->constraints!=old_constraints&&actor->constraints->model()==actor->model&&actor->constraints->floor_heights()[0]==17&&old_constraints->model()==old_model);
        // Class-only replacement must release the SAME character bank. Resume
        // notification and pause are independent: zero pause selects restore,
        // nonzero pause selects the fresh initializer even with notification.
        const auto same_character_bank=motions.snapshot()->character(actor->character);
        state.notification_pending=1;actor->model_pose_class=0;actor->current=123;
        actor->saved_action_position={2,3,4};actor->position={9,9,9};
        const auto class_prepared=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);const auto before_class=keys(owner);
        const auto class_changed=owner.apply(*class_prepared,state);
        check(class_changed.status==g::PrimaryModelStatus::completed&&class_changed.replaced&&class_changed.character_released);
        compare_cache(before_class,keys(owner),slot,actor->character,0,std::uint8_t(loading),world.paused,class_changed);++replacements;
        check(motions.snapshot()->character(actor->character)!=same_character_bank&&actor->animation->resources[2]->cleared()&&!same_character_bank->cleared());++shared_releases;
        check(paused?actor->position.x==9:actor->current==123&&actor->position.x==2);
        const auto release=g::PrimaryActorModels::prepare(owner.capture_release(id).value(),assets,content);const auto before_release=keys(owner);
        const auto release_playback=actor->animation;const auto release_model=actor->model;const auto history_before=release_playback->root_reference();
        world.session().asset_loading_mode.reset();const auto released=owner.apply(*release,state);
        check(released.status==g::PrimaryModelStatus::completed&&released.retired&&released.character_released&&!released.initialized&&!released.replaced);
        compare_release(before_release,keys(owner),slot,released);++retirements;
        const auto history_after=release_playback->root_reference();
        check(!actor->model&&!actor->model_asset&&!actor->visible&&actor->animation==release_playback&&!release_playback->model()&&!release_playback->secondary_model()&&release_playback->secondary_bank_enabled());
        check(std::memcmp(&history_before,&history_after,sizeof history_before)==0&&channel.timing.frame==3.25f&&channel.selector==17);
        bool detached_rejected{};try{(void)release_playback->advance_primary(0,1,0,{actor->root_motion_delta.x,actor->root_motion_delta.y,actor->root_motion_delta.z});}catch(const std::runtime_error&){detached_rejected=true;}
        check(detached_rejected&&channel.timing.frame==3.25f);++detached_refusals;
        const auto detached_copy=release_playback->clone_independent();const auto copy_history=detached_copy->root_reference();
        check(detached_copy!=release_playback&&!detached_copy->model()&&!detached_copy->secondary_model()&&detached_copy->secondary_bank_enabled()&&detached_copy->resources==release_playback->resources&&std::memcmp(&copy_history,&history_after,sizeof copy_history)==0);
        detached_copy->channel(a::ModelBank::primary,0).selector=111;check(channel.selector==17);
        bool copy_rejected{};try{(void)detached_copy->advance_primary(0,1,0,{actor->root_motion_delta.x,actor->root_motion_delta.y,actor->root_motion_delta.z});}catch(const std::runtime_error&){copy_rejected=true;}
        check(copy_rejected&&detached_copy->channel(a::ModelBank::primary,0).timing.frame==3.25f);++independent_detached_copies;
        const auto detached_actor=g::copy_actor_owned(*actor);check(detached_actor.status==g::ActorCopyStatus::completed&&detached_actor.actor&&!detached_actor.actor->model&&detached_actor.actor->animation!=release_playback&&!detached_actor.actor->animation->model());
        check(bool(detached_actor.actor->constraints)==bool(actor->constraints)&&(!actor->constraints||(detached_actor.actor->constraints!=actor->constraints&&detached_actor.actor->constraints->model()!=actor->constraints->model()&&&detached_actor.actor->constraints->model()->skeleton()==&actor->constraints->model()->skeleton())));++owned_actor_copies;
        world.session().asset_loading_mode=std::uint8_t(loading);
        const auto reconstruction=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);const auto before_reload=keys(owner);const auto reloaded=owner.apply(*reconstruction,state);
        check(reloaded.status==g::PrimaryModelStatus::completed&&reloaded.replaced&&!reloaded.character_released&&actor->model!=release_model&&actor->animation==release_playback&&actor->animation->secondary_model());
        check(!detached_copy->model()&&!detached_copy->secondary_model()&&detached_copy->channel(a::ModelBank::primary,0).selector==111&&channel.selector==17);
        compare_cache(before_reload,keys(owner),slot,actor->character,0,std::uint8_t(loading),world.paused,reloaded);++reloads;
        const auto restored_history=release_playback->root_reference();check(std::memcmp(&history_before,&restored_history,sizeof history_before)==0&&channel.timing.frame==3.25f);
        const auto pending=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);const auto pending_model=actor->model;
        const auto overlaid=content.overlay(1,{},*motions.snapshot());check(motions.publish(overlaid).status==g::HumanoidPublicationStatus::completed);
        check(owner.apply(*pending,state).status==g::PrimaryModelStatus::stale&&actor->model==pending_model);++refusals;
        const auto capture=owner.capture(id).value();const auto stale=g::PrimaryActorModels::prepare(capture,assets,content);const auto current=actor->model;
        actor->appearance_variant=1;check(owner.apply(*stale,state).status==g::PrimaryModelStatus::stale&&actor->model==current);actor->appearance_variant=0;++refusals;
        const auto late=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);check(world.retire_primary(slot)==g::actors::EntityStatus::completed);
        auto next=std::make_unique<g::Actor>();next->slot=std::uint8_t(slot);next->character=actor->character;const auto next_id=world.spawn_primary(slot,std::move(next)).id;
        check(next_id!=id&&owner.apply(*late,state).status==g::PrimaryModelStatus::stale&&!owner.capture(next_id));++refusals;
        if(slot<4){const auto before_entry=motions.snapshot();const auto failed_entry=owner.release_scene_entry(content);check(failed_entry.status==g::PrimaryModelStatus::unavailable&&failed_entry.visited==0&&failed_entry.failed_slot==slot&&motions.snapshot()==before_entry);++entry_refusals;}
        check(owner.close()==g::PrimaryModelStatus::completed&&motions.close()==g::HumanoidPublicationStatus::completed&&world.close()==g::Status::completed);
    }
    check(loads==256&&reuses==256&&replacements==512&&shared_releases==512);
    // Unknown and development resident modes are explicit unavailable profiles;
    // changing pause never supplies a missing asset-loading fact.
    g::World world(profile(),std::make_shared<g::Session>());g::HumanoidMotionOwner motions(world);check(motions.publish(banks).status==g::HumanoidPublicationStatus::completed);g::PrimaryActorModels owner(world,motions);
    auto initial=std::make_unique<g::Actor>();const auto id=world.spawn_primary(0,std::move(initial)).id;
    check(!owner.capture(id));world.session().asset_loading_mode=0;check(!owner.capture(id));world.paused=1;check(!owner.capture(id));++refusals;
    world.session().asset_loading_mode=1;world.paused=0;const auto actor=world.resolve(id);actor->model_pose_class=255;actor->visible=true;reo::native::gameplay_update::State state;
    const auto sentinel=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);check(owner.apply(*sentinel,state).status==g::PrimaryModelStatus::completed);const auto sentinel_model=actor->model;
    const auto sentinel_release=g::PrimaryActorModels::prepare(owner.capture_release(id).value(),assets,content);const auto sentinel_before=keys(owner);const auto sentinel_result=owner.apply(*sentinel_release,state);
    check(sentinel_result.status==g::PrimaryModelStatus::completed&&!sentinel_result.retired&&actor->model==sentinel_model&&actor->visible);compare_release(sentinel_before,keys(owner),0,sentinel_result);++retirement_noops;
    actor->model_pose_class=0;const auto normal=g::PrimaryActorModels::prepare(owner.capture(id).value(),assets,content);check(owner.apply(*normal,state).status==g::PrimaryModelStatus::completed);
    const auto retirement=g::PrimaryActorModels::prepare(owner.capture_release(id).value(),assets,content);check(owner.apply(*retirement,state).retired);const auto old_actor=actor;
    check(world.retire_primary(0)==g::actors::EntityStatus::completed);auto replacement=std::make_unique<g::Actor>();const auto new_id=world.spawn_primary(0,std::move(replacement)).id;check(new_id!=id);
    const auto new_model=g::PrimaryActorModels::prepare(owner.capture(new_id).value(),assets,content);check(owner.apply(*new_model,state).status==g::PrimaryModelStatus::completed&&world.resolve(new_id)->model&&world.resolve(new_id)->animation!=old_actor->animation&&!old_actor->model);++generation_handoffs;
}
}
#include "primary_scene_actor_models_tests.inc"
#include "primary_scene_entry_tests.inc"
#include "primary_scene_construction_tests.inc"
#include "primary_scene_roster_tests.inc"
#include "primary_resident_resources_tests.inc"
#include "primary_scene_scope_tests.inc"
#ifdef REO_PRIMARY_MODELS_ORIGINAL
#include "primary_models_reference.inc"
#else
namespace {void compare_roster_world(const g::World&,const reo::native::gameplay_scenario::CutsceneRosterState&,const reo::native::gameplay_scenario::CutsceneRosterState&,std::int32_t){}}
namespace {void compare_construction(const g::Actor&,const g::Actor&,const g::Actor&,const reo::native::gameplay_scenario::CutscenePrimaryRoster&,const reo::native::gameplay_scenario::CutscenePrimaryRoster&,const reo::native::gameplay_scenario::CutscenePrimaryChoice&,std::uint16_t,const g::PrimarySceneConstructed&){}}
namespace {void compare_cache(const Keys&,const Keys&,unsigned,std::uint8_t,std::uint8_t,std::uint8_t,std::int8_t,const g::PrimaryModelApplied&) {}}
namespace {void compare_primary_scene(const reo::native::gameplay_scenario::CutsceneDescriptor&,std::size_t,const g::Actor&,std::span<const reo::native::gameplay_scenario::CutsceneActorParameter>,std::uint16_t,std::int8_t) {}}
namespace {void compare_release(const Keys&,const Keys&,unsigned,const g::PrimaryModelApplied&) {}}
namespace {void compare_entry(const Keys&,const Keys&,const std::array<std::uint8_t,8>&,const std::array<std::uint8_t,8>&,const g::PrimarySceneEntryReleased&) {}}
#endif
int main(int argc,char** argv)try{
    basic();owned_roster_world();if(argc>=2)resident_ownership(argv[1]);if(argc>=2){owned(argv[1]);owned_entry(argv[1]);}else check(argc==1);if(argc>=2){construction_owned(argv[1]);construction_lifetimes(argv[1]);}if(argc==3){owned_scenes(argv[1],argv[2]);scene_scopes(argv[1],argv[2]);}else check(argc<=2);
    std::cout<<"{\"scene_scope_guards\":"<<scene_scope_guards<<",\"scene_scope_capacity_refusals\":"<<scene_scope_capacity_refusals<<",\"scene_scope_absent_returns\":"<<scene_scope_absent_returns<<",\"scene_scope_cache_cases\":"<<scene_scope_cache_cases<<",\"scene_scope_reuses\":"<<scene_scope_reuses<<",\"scene_scope_rebuilds\":"<<scene_scope_rebuilds<<",\"scene_scope_resets\":"<<scene_scope_resets<<",\"scene_scope_releases\":"<<scene_scope_releases<<",\"scene_scope_returns\":"<<scene_scope_returns<<",\"scene_scope_refusals\":"<<scene_scope_refusals<<",\"scene_scope_reinitializations\":"<<scene_scope_reinitializations<<",\"resident_lifetimes\":"<<resident_lifetimes<<",\"resident_stale_refusals\":"<<resident_stale_refusals<<",\"resident_close_guards\":"<<resident_close_guards<<",\"resident_retained_leases\":"<<resident_retained_leases<<",\"resident_prefixes\":"<<resident_prefixes<<",\"roster_world_cases\":"<<roster_world_cases<<",\"roster_world_original_cases\":"<<roster_world_original_cases<<",\"roster_world_refusals\":"<<roster_world_refusals<<",\"construction_cases\":"<<construction_cases<<",\"construction_original_cases\":"<<construction_original_cases<<",\"construction_refusals\":"<<construction_refusals<<",\"construction_guards\":"<<construction_guards<<",\"owned_actor_copies\":"<<owned_actor_copies<<",\"actor_copy_refusals\":"<<actor_copy_refusals<<",\"independent_detached_copies\":"<<independent_detached_copies<<",\"direct_guard_checks\":"<<direct_guard_checks<<",\"entry_cases\":"<<entry_cases<<",\"entry_retirements\":"<<entry_retirements<<",\"entry_original_cases\":"<<entry_original_cases<<",\"entry_guard_checks\":"<<entry_guard_checks<<",\"entry_refusals\":"<<entry_refusals<<",\"retirements\":"<<retirements<<",\"retirement_noops\":"<<retirement_noops<<",\"reloads\":"<<reloads<<",\"detached_refusals\":"<<detached_refusals<<",\"retirement_original_cases\":"<<retirement_original_cases<<",\"generation_handoffs\":"<<generation_handoffs<<",\"checks\":"<<checks<<",\"loads\":"<<loads<<",\"reuses\":"<<reuses<<",\"replacements\":"<<replacements<<",\"shared_releases\":"<<shared_releases<<",\"refusals\":"<<refusals<<",\"original_cases\":"<<original_cases<<",\"original_calls\":"<<original_calls<<",\"scene_cases\":"<<scene_cases<<",\"scene_parameters\":"<<scene_parameters<<",\"scene_original_cases\":"<<scene_original_cases<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
