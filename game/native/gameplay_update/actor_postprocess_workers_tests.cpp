#include "actor_postprocess_workers.hpp"
#include "../gameplay_scenario/scene_model_bindings.hpp"
#include <algorithm>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace u=reo::native::gameplay_update;namespace w=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;namespace e=reo::native::gameplay_events;
unsigned checks{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Actor postprocess worker check "+std::to_string(at.line()));}
struct Notifications final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
struct Remaining final:u::PhaseServices {
    std::shared_ptr<w::Actor> actor;std::vector<u::Worker> calls;unsigned buttons{},effects{},transitions{},frames{};
    void run(u::Worker stage,u::Owner& owner)override{
        check(stage!=u::Worker::primary_actor_postprocess);calls.push_back(stage);
        // Declared frame surroundings only: keep unrelated actor behavior out
        // of this owner-adoption proof, then admit the post-model actor.
        if(stage==u::Worker::reset_entity_queues)actor->active=false;
        if(stage==u::Worker::primary_model_poses)actor->active=true;
        if(stage==u::Worker::primary_hit_regions){++frames;check(owner.completion_statistics().state().actors.forward_distance==frames);}
    }
    bool button(u::Button,u::Owner&)override{++buttons;return false;}
    bool transition_request(u::Owner&)override{++transitions;return false;}
    void effect(u::PhaseEffect,u::Owner&,std::uint32_t argument)override{++effects;check(argument==73);}
};
struct ActorSurroundings final:w::Services {
    void begin_offline_frame(w::World&)override{std::terminate();}
    void run(w::Stage,w::World&,w::Actor&)override{std::terminate();}
    bool remote_motion(w::World&,w::Actor&)override{std::terminate();}
    bool find_grid(w::World&,w::Actor&,std::int8_t&)override{std::terminate();}
    void switch_grid(w::World&,std::int32_t,std::int32_t)override{std::terminate();}
    float grid_response(w::World&,std::uint8_t)override{std::terminate();}
};
int main()try{
    w::Profile profile;profile.layouts.push_back({});w::World world(profile,std::make_shared<w::Session>());world.mode=1;world.room=7;world.selected_actor=0;world.session().session_state=1;world.session().scenario=0;Notifications notifications;
    u::Owner owner(world,notifications,e::RuleBook::create({e::RuleGroup{}},{0}));owner.state.scripts_enabled=false;owner.state.session_work_gate=1;check(owner.initialize_completion_statistics()==e::StatisticsStatus::completed);
    const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{{std::byte{1},std::byte{},std::byte{},std::byte{},std::byte{0xa},std::byte{},std::byte{},std::byte{}}});
    for(unsigned channel=0;channel<2;++channel)check(owner.scripts().install(channel,program)==s::Status::completed);
    auto records=std::make_shared<reo::native::gameplay_scene::Records>();s::SceneControls controls(records);s::SceneModelState state;s::RoomModelRemap remap{};s::SceneModels models(state,remap);reo::native::gameplay_actors::EntityStore objects;s::SceneModelBindings bindings(models,objects);s::SceneMatrixPrograms programs(controls,models,bindings,owner.flags(),world.room);
    auto actor=std::make_unique<w::Actor>();actor->category=0;actor->slot=0;actor->room=7;actor->primary=1;actor->motion_class=0;actor->contact_flags=2;actor->secondary_pose_category_override=2;actor->root_motion_delta.z=1.5f;actor->current=actor->maximum=100;const auto id=world.spawn_primary(0,std::move(actor)).id;check(bool(id));Remaining remaining;remaining.actor=world.resolve(id);ActorSurroundings actor_surroundings;
    u::ActorPostprocessWorkers workers(owner,remaining,*records,programs);
    for(unsigned frame=0;frame<32;++frame){remaining.calls.clear();const auto result=owner.run_workers(workers,actor_surroundings);check(result.status==u::Status::completed);check(workers.last_result()&&workers.last_result()->status==w::PrimaryPostprocessStatus::completed&&workers.last_result()->statistics==1&&workers.last_result()->reactions==1);const auto models_at=std::find(remaining.calls.begin(),remaining.calls.end(),u::Worker::scenario_model_poses),hits_at=std::find(remaining.calls.begin(),remaining.calls.end(),u::Worker::primary_hit_regions);check(models_at!=remaining.calls.end()&&hits_at!=remaining.calls.end()&&models_at<hits_at);check(owner.completion_statistics().state().actors.forward_distance==frame+1);}
    check(remaining.frames==32&&!world.busy());check(!workers.button(u::Button::primary,owner)&&!workers.transition_request(owner));workers.effect(u::PhaseEffect::enter_phase,owner,73);check(remaining.buttons==1&&remaining.transitions==1&&remaining.effects==1);
    w::World foreign_world(profile,std::make_shared<w::Session>());u::Owner foreign(foreign_world,notifications,e::RuleBook::create({e::RuleGroup{}},{0}));bool refused=false;try{workers.run(u::Worker::primary_actor_postprocess,foreign);}catch(const std::invalid_argument&){refused=true;}check(refused&&owner.completion_statistics().state().actors.forward_distance==32);
    auto live=world.resolve(id);live->active=true;live->status=0x80000000u;live->selected_resource=1;live->auxiliary_status|=0x80;refused=false;try{workers.run(u::Worker::primary_actor_postprocess,owner);}catch(const std::runtime_error&){refused=true;}check(refused&&workers.last_result()&&workers.last_result()->status==w::PrimaryPostprocessStatus::unavailable&&workers.last_result()->failed==id);check(!(live->status&0x80000000u)&&!(live->auxiliary_status&0x80)&&!world.busy());
    workers.run(u::Worker::reset_entity_queues,owner);check(!workers.last_result());live->active=true;live->status=0x80000000u;live->selected_resource=0;workers.run(u::Worker::primary_actor_postprocess,owner);check(workers.last_result()->status==w::PrimaryPostprocessStatus::completed&&owner.completion_statistics().state().actors.forward_distance==33);
    check(workers.close()==u::Status::completed&&!workers.last_result());refused=false;try{workers.run(u::Worker::primary_actor_postprocess,owner);}catch(const std::invalid_argument&){refused=true;}check(refused&&owner.close()==u::Status::completed);const auto retained=live;check(world.close()==w::Status::completed&&retained->current==100);
    std::cout<<"{\"checks\":"<<checks<<",\"canonical_owner_frames\":32,\"declared_remaining_phase_surroundings\":true,\"game_run\":false}\n";
}catch(const std::exception& x){std::cerr<<x.what()<<'\n';return 1;}
