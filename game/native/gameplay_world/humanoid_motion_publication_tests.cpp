#include "humanoid_motion_owner.hpp"
#include "npc_updates.hpp"
#include "surface_orientation.hpp"
#include "linked_models.hpp"
#include "motion_resources.hpp"
#include "runtime/assets/virtual_afs.h"
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace g=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace {
std::uint64_t checks{},publications{},refusals{},rebindings{},busy_checks{},scripted_checks{},retirements{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Humanoid publication check "+std::to_string(at.line()));
}
g::Profile profile(){g::Profile result;result.layouts.push_back({});return result;}
void contracts(){
    g::World world(profile(),std::make_shared<g::Session>());g::HumanoidMotionOwner owner(world);
    const auto direct=std::make_shared<a::MotionBank>();
    check(!owner.snapshot()&&!g::resolve_humanoid_motion_bank(world,{g::HumanoidMotionFamily::scene_body,0},direct));
    check(owner.publish({}).status==g::HumanoidPublicationStatus::unavailable);++refusals;
    bool duplicate=false;try{g::HumanoidMotionOwner other(world);}catch(const std::invalid_argument&){duplicate=true;}check(duplicate);++refusals;
    check(owner.close()==g::HumanoidPublicationStatus::completed&&!world.humanoid_motion_source()&&world.humanoid_motion_source_closed());
    check(!g::resolve_humanoid_motion_bank(world,{g::HumanoidMotionFamily::scene_body,0},direct));++refusals;
    check(owner.publish({}).status==g::HumanoidPublicationStatus::closed);
    g::HumanoidMotionOwner replacement(world);check(!world.humanoid_motion_source_closed());check(owner.close()==g::HumanoidPublicationStatus::completed&&world.humanoid_motion_source()==&replacement);
    check(replacement.close()==g::HumanoidPublicationStatus::completed&&world.close()==g::Status::completed);
}
void owned(const char* archive){
    auto source=std::make_shared<reo::assets::Source>(archive);g::HumanoidMotionAssets assets(source);g::ActorAssets models(source);
    const auto base=assets.base();const std::array<std::uint8_t,2> characters{3,5};const auto common=assets.overlay(1,characters,*base);const auto ready=assets.scene(1,2,*common).banks;
    const auto next=assets.scene(1,1,*ready).banks;const auto later=assets.scene(1,0,*next).banks;const auto stale=assets.overlay(2,characters,*ready);
    check(next->follows(*ready)&&later->follows(*next)&&!later->follows(*ready)&&!stale->follows(*next));
    g::World world(profile(),std::make_shared<g::Session>());g::NpcActorConstruction factory(world);
    // Prepared before binding/publication, then deliberately created after a
    // different live publication. Its fixed bank aliases must resolve afresh.
    const auto prepared=factory.prepare(103,0,models,ready->npc_bindings());
    g::HumanoidMotionOwner owner(world);check(owner.publish(ready).status==g::HumanoidPublicationStatus::completed);++publications;
    const auto first=factory.create(*prepared),second=factory.create(*factory.prepare(88,1,models,ready->npc_bindings()));
    check(first.status==g::NpcConstructionStatus::completed&&second.status==g::NpcConstructionStatus::completed);
    const auto actor=world.resolve(first.id),head=world.resolve(second.id);auto& channel=actor->animation->channel(a::ModelBank::primary,0);
    actor->phase=19;actor->root_motion_delta={.25f,.5f,.75f};actor->animation->motion=-42;actor->animation->progress_flags=0x89;
    channel.timing={3.25f,20,2,1,0x82};channel.selector=6;channel.blend_position=.25f;channel.blend_remaining=17;
    const auto original_model=actor->model;
    // These mutable gameplay fields do not retarget the constructor's fixed
    // original bank pointers. Publication follows explicit aliases instead.
    actor->motion_style=1;actor->character=0;
    const auto direct=std::make_shared<a::MotionBank>();auto unaliased=std::make_unique<g::Actor>();unaliased->model=prepared->asset()->make_instance();unaliased->animation=std::make_shared<a::Playback>(unaliased->model);unaliased->animation->resources_known=true;unaliased->animation->resources[0]=direct;
    const auto direct_id=world.spawn_linked(std::move(unaliased)).id;
    const auto adopted=owner.publish(next);check(adopted.status==g::HumanoidPublicationStatus::completed&&adopted.actors==2&&adopted.bindings==6&&adopted.changed);++publications;rebindings+=adopted.bindings;
    check(actor->animation->resources[0]==next->scripted().mode_one&&actor->animation->resources[1]==next->scripted().other_modes&&actor->animation->resources[2]==next->character(3));
    check(head->animation->resources[1]==next->alternate_style()&&head->animation->resources[2]==next->character(5)&&world.resolve(direct_id)->animation->resources[0]==direct);
    check(actor->phase==19&&actor->model==original_model&&actor->root_motion_delta.x==.25f&&actor->animation->motion==-42&&actor->animation->progress_flags==0x89&&channel.timing.frame==3.25f&&channel.timing.end==20&&channel.timing.restart==2&&channel.timing.loop==1&&channel.timing.flags==0x82&&channel.selector==6&&channel.blend_position==.25f&&channel.blend_remaining==17);
    g::WorldMotionResources resources(world);check(resources.resolve(first.id,0)==next->scripted().other_modes&&actor->animation->source_slot==1);
    actor->motion_style=0;actor->character=3;
    const auto third=factory.create(*prepared);check(third.status==g::NpcConstructionStatus::completed&&world.resolve(third.id)->animation->resources[0]==next->scripted().mode_one);
    check(owner.publish(stale).status==g::HumanoidPublicationStatus::stale&&owner.snapshot()==next&&actor->animation->resources[0]==next->scripted().mode_one);++refusals;
    const auto alias=head->motion_bank_aliases[2];head->motion_bank_aliases[2]=g::HumanoidMotionAlias{g::HumanoidMotionFamily::character,255};
    check(owner.publish(later).status==g::HumanoidPublicationStatus::unavailable&&owner.snapshot()==next&&actor->animation->resources[0]==next->scripted().mode_one);++refusals;head->motion_bank_aliases[2]=alias;
    // A controlled old-resource deleter observes only a complete publication.
    // Retiring previous pointers must keep both owners protected from reentry.
    bool retired=false;
    actor->animation->resources[0]=std::shared_ptr<const a::MotionBank>(new a::MotionBank,[&](const a::MotionBank* bank){
        if(owner.snapshot()!=later||actor->animation->resources[0]!=later->scripted().mode_one||head->animation->resources[0]!=later->scripted().mode_one||!world.busy()||owner.close()!=g::HumanoidPublicationStatus::busy||world.close()!=g::Status::busy||owner.publish(later).status!=g::HumanoidPublicationStatus::busy)std::terminate();
        retired=true;delete bank;
    });
    const auto committed=owner.publish(later);check(committed.status==g::HumanoidPublicationStatus::completed&&committed.actors==3&&committed.bindings==9&&retired&&!world.busy());++publications;rebindings+=committed.bindings;++retirements;
    // Actual scripted phase0 selects from the adopted source even though this
    // consumer was constructed with old banks. The invalid selector refuses
    // after recording its real binding; no curve/playback success is claimed.
    const auto linked_id=world.linked_models().allocate(true).id;const auto linked=world.resolve(linked_id);linked->category=2;linked->scripted.emplace();linked->scripted->motion_rate_mode=1;linked->scripted->motion_selector=-1;
    linked->model=prepared->asset()->make_instance();linked->animation=std::make_shared<a::Playback>(linked->model);linked->animation->resources_known=true;
    g::ScriptedActorMotion motion(world,ready->scripted());bool failed=false;try{motion.tick(linked_id);}catch(const std::exception&){failed=true;}
    check(failed&&linked->phase==1&&linked->motion_bank_aliases[0]==g::HumanoidMotionAlias{g::HumanoidMotionFamily::scene_body,0}&&linked->animation->resources[0]==later->scripted().mode_one);++scripted_checks;
    linked->scripted->motion_rate_mode=0;const auto final=assets.scene(1,2,*later).banks;
    const auto final_result=owner.publish(final);check(final_result.status==g::HumanoidPublicationStatus::completed&&final_result.actors==4&&final_result.bindings==10&&linked->phase==1&&linked->animation->resources[0]==final->scripted().mode_one&&linked->animation->resources[0]!=final->scripted().other_modes);++publications;rebindings+=final_result.bindings;++scripted_checks;
    struct Behavior final:g::Services {
        g::HumanoidMotionOwner& owner;std::shared_ptr<const g::HumanoidMotionBanks> candidate;unsigned calls{};
        Behavior(g::HumanoidMotionOwner& value,std::shared_ptr<const g::HumanoidMotionBanks> banks):owner(value),candidate(std::move(banks)){}
        void begin_offline_frame(g::World&)override{throw std::runtime_error("unexpected publication fixture begin");}
        void run(g::Stage stage,g::World& world,g::Actor&)override{check(stage==g::Stage::update_behavior&&owner.publish(candidate).status==g::HumanoidPublicationStatus::busy&&owner.close()==g::HumanoidPublicationStatus::busy&&world.close()==g::Status::busy);++calls;}
        bool remote_motion(g::World&,g::Actor&)override{throw std::runtime_error("unexpected publication fixture remote");}
        bool find_grid(g::World&,g::Actor&,std::int8_t&)override{throw std::runtime_error("unexpected publication fixture grid");}
        void switch_grid(g::World&,std::int32_t,std::int32_t)override{throw std::runtime_error("unexpected publication fixture switch");}
        float grid_response(g::World&,std::uint8_t)override{throw std::runtime_error("unexpected publication fixture grid response");}
    }behavior(owner,assets.overlay(2,characters,*final));
    actor->visible=true;const reo::native::gameplay_collision::response::Grid floors{};g::GridSurfaceOrientation pose(floors);const g::Position camera{};const std::uint8_t inhibition{};
    {g::NpcActorUpdates updates(world,behavior,pose,camera,inhibition);check(updates.run().status==g::NpcUpdateStatus::completed&&behavior.calls==1);++busy_checks;}
    const auto old_character=actor->animation->resources[2];const auto old_frame=channel.timing.frame;
    const auto released=assets.release_character(3,*final);const auto cleared=owner.publish(released);
    check(cleared.status==g::HumanoidPublicationStatus::completed&&cleared.actors==4&&cleared.bindings==10&&resources.resolve(first.id,5)==released->character(3)&&actor->animation->resources[2]->cleared()&&!actor->animation->resources[2]->find(0,0));++publications;rebindings+=cleared.bindings;
    check(head->animation->resources[2]==released->character(5)&&!old_character->cleared()&&channel.timing.frame==old_frame&&world.resolve(third.id)->animation->resources[2]==released->character(3));
    const auto reloaded=assets.overlay(1,characters,*released);check(owner.publish(reloaded).status==g::HumanoidPublicationStatus::completed&&!resources.resolve(first.id,5)->cleared()&&resources.resolve(first.id,5)==reloaded->character(3)&&channel.timing.frame==old_frame);++publications;rebindings+=10;
    const auto previous_model=actor->model;const auto previous_common=actor->animation->resources[1];const auto previous_character=actor->animation->resources[2];
    const auto base_released=assets.release_base(*reloaded);const auto base_result=owner.publish(base_released);
    check(base_result.status==g::HumanoidPublicationStatus::completed&&base_result.actors==4&&base_result.bindings==10&&!base_released->base_loaded()&&channel.timing.frame==old_frame&&actor->model==previous_model);
    check(actor->animation->resources[1]!=previous_common&&actor->animation->resources[2]!=previous_character&&actor->animation->resources[2]->track_count()==previous_character->track_count()&&actor->animation->resources[2]->kind()==previous_character->kind()&&linked->animation->resources[0]==reloaded->scripted().mode_one);++publications;rebindings+=10;
    const auto families=assets.release_scene_families(*base_released);const auto families_result=owner.publish(families);
    check(families_result.status==g::HumanoidPublicationStatus::completed&&families_result.actors==4&&families_result.bindings==10&&!families->base_loaded()&&actor->animation->resources[1]->zero_header_known()&&actor->animation->resources[1]->track_count()==0&&resources.resolve(first.id,5)==families->character(3));
    check(actor->animation->resources[2]->zero_header_known()&&actor->animation->resources[2]->track_count()==0&&channel.timing.frame==old_frame&&actor->model==previous_model&&linked->animation->resources[0]==reloaded->scripted().mode_one);++publications;rebindings+=10;
    const auto restored=assets.ensure_base(families);const auto restored_result=owner.publish(restored);
    check(restored_result.status==g::HumanoidPublicationStatus::completed&&restored_result.bindings==10&&restored->base_loaded()&&actor->animation->resources[1]->track_count()!=0&&channel.timing.frame==old_frame&&actor->model==previous_model);++publications;rebindings+=10;
    check(owner.close()==g::HumanoidPublicationStatus::completed&&!owner.snapshot());
    failed=false;try{(void)resources.resolve(first.id,0);}catch(const std::runtime_error&){failed=true;}check(failed);++refusals;
    failed=false;try{motion.tick(linked_id);}catch(const std::runtime_error&){failed=true;}check(failed);++refusals;
    const auto remaining=world.auxiliary_actors().remaining();check(factory.create(*prepared).status==g::NpcConstructionStatus::unavailable&&world.auxiliary_actors().remaining()==remaining);++refusals;
    check(world.close()==g::Status::completed);
}
}
int main(int argc,char** argv)try{
    contracts();if(argc==2)owned(argv[1]);else check(argc==1);
    std::cout<<"{\"checks\":"<<checks<<",\"publications\":"<<publications<<",\"rebindings\":"<<rebindings<<",\"refusals\":"<<refusals<<",\"scripted_bindings\":"<<scripted_checks<<",\"busy_checks\":"<<busy_checks<<",\"retirements\":"<<retirements<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
