#include "update.hpp"
#include <bit>
#include <exception>
#include <stdexcept>

namespace reo::native::gameplay_update {
namespace {
struct FlagExpiry final:tasks::FlagSink {
    scenario::FlagState& flags;world::World& world;bool failed{};
    FlagExpiry(scenario::FlagState& f,world::World& w):flags(f),world(w){}
    void expired(const tasks::FlagExpiry& expiry)noexcept override{
        if(expiry.target.scope==tasks::FlagScope::scenario)
            failed|=!flags.scenario(expiry.target.id,1,scenario::NotifyOwner::selected_actor_plus_one,
                                   std::uint8_t(world.selected_actor+1));
        else failed|=!flags.actor_flag(scenario::ActorFlagFamily::primary,{false,0},expiry.target.id,true);
    }
};
bool script_ok(scenario::Status s){return s==scenario::Status::completed || s==scenario::Status::yielded || s==scenario::Status::disabled;}
}
Owner::Owner(world::World& world,scenario::FlagNotifications& notifications):world_(world),flags_(&notifications){
    if(world_.session().timing)throw std::invalid_argument("Native world already has a timing owner");
    world_.session().timing=this;
}
Owner::~Owner(){if(running_)std::terminate();(void)close();}
Status Owner::close()noexcept{
    if(running_ || !events_.idle() || !linked_.idle())return Status::busy;
    closed_=true;(void)events_.seal();(void)linked_.seal();
    cooperative_.close();
    (void)events_.clear();(void)linked_.clear();
    if(world_.session().timing==this)world_.session().timing=nullptr;
    return Status::completed;
}
Status Owner::run_script(std::size_t channel,scenario::Providers providers,std::size_t budget,Result& result)noexcept{
    providers.flags=&flags_;providers.canonical_flags=&flags_;providers.timers=&timers_;
    if(world_.mode==0){
        std::array<scenario::OfflinePartyActor,3> party;
        for(std::size_t i=0;i<party.size();++i){const auto actor=world_.primary(i);if(actor)party[i]={actor->active,actor->slot,actor->room};}
        const auto step=offline_.tick(scripts_,channel,state.scripts_enabled,party,world_.room,world_.selected_actor,flags_,providers,budget,state.audio_tick);
        result.script_operations+=step.operations;return script_ok(step.status)?Status::completed:Status::script_failure;
    }
    auto context=scenario::TickContext{state.scripts_enabled,false,world_.selected_actor,world_.room};
    context.stream_tick=state.audio_tick;
    const auto step=scripts_.tick(channel,context,providers,budget);
    result.script_operations+=step.operations;return script_ok(step.status)?Status::completed:Status::script_failure;
}
Status Owner::script_service(Services& services,scenario::Providers providers,std::size_t budget,Result& result){
    if(std::bit_cast<std::int32_t>(clock_.update_counter())>=0x83d60 && !state.limit_override){
        services.run(Worker::limit_action,*this);++result.worker_calls;return Status::completed;
    }
    FlagExpiry sink(flags_,world_);
    if(timers_.tick(sink)!=tasks::Status::completed)return Status::task_failure;
    if(sink.failed)return Status::flag_failure;
    auto status=run_script(0,providers,budget,result);if(status!=Status::completed)return status;
    services.run(Worker::clear_interaction_activity,*this);++result.worker_calls;
    status=run_script(1,providers,budget,result);if(status!=Status::completed)return status;
    services.run(Worker::clear_proxy_work,*this);++result.worker_calls;return Status::completed;
}
Result Owner::run_workers(Services& services,world::Services& actors,scenario::Providers providers,
                          std::size_t script_budget,std::size_t task_budget){
    if(running_){Result busy;busy.status=Status::busy;return busy;}
    if(closed_){Result closed;closed.status=Status::closed;return closed;}
    running_=true;
    struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    return workers(services,actors,providers,script_budget,task_budget);
}
Result Owner::workers(Services& services,world::Services& actors,scenario::Providers providers,
                       std::size_t script_budget,std::size_t task_budget){
    Result result;
    const auto work=[&](Worker stage){services.run(stage,*this);++result.worker_calls;};
    work(Worker::reset_entity_queues);work(Worker::armed_request);
    result.status=script_service(services,providers,script_budget,result);if(result.status!=Status::completed)return result;
    if(world_.paused){work(Worker::scenario_events);return result;}
    work(Worker::target_caches);
    result.actors=world_.update_primary(actors);
    if(result.actors.status!=world::Status::completed){result.status=Status::actor_failure;return result;}
    for(const auto stage:{Worker::auxiliary_actors,Worker::scenario_actors,Worker::actor_collision_shapes,
        Worker::collision_heights,Worker::primary_model_poses,Worker::auxiliary_model_poses,
        Worker::scenario_model_poses,Worker::primary_actor_postprocess,Worker::auxiliary_actor_postprocess,
        Worker::primary_hit_regions,Worker::auxiliary_hit_regions,Worker::scenario_hit_regions,Worker::camera_modes})work(stage);
    auto selected=tasks::OwnerSelection::borrow(world_.selected_actor);
    result.events=events_.run(world_.mode==0?tasks::EventMode::owner_banks:tasks::EventMode::shared_bank,selected);
    if(result.events.status!=tasks::Status::completed){result.status=Status::task_failure;return result;}
    work(Worker::model_interactions);work(Worker::resource_instances);work(Worker::scene_pose_tasks);
    result.linked=linked_.run(tasks::Pass::update,task_budget);
    if(result.linked.status!=tasks::Status::completed){result.status=Status::task_failure;return result;}
    for(const auto stage:{Worker::render_work_banks,Worker::large_callbacks,Worker::gameplay_ui,
                         Worker::room_sound_callbacks,Worker::sequences})work(stage);
    if(state.session_work_gate==0){
        for(const auto stage:{Worker::room_occupancy,Worker::contact_candidates,Worker::contact_packets,
                             Worker::room_entity_ownership,Worker::actor_action_publication,Worker::transition_control})work(stage);
        work(Worker::scenario_events);
    }
    return result;
}
Result Owner::advance(PhaseServices& services,world::Services& actors,scenario::Providers providers,
                       std::size_t script_budget,std::size_t task_budget){
    Result result;
    if(running_){result.status=Status::busy;return result;}
    if(closed_){result.status=Status::closed;return result;}
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    const auto effect=[&](PhaseEffect operation,std::uint32_t argument=0){services.effect(operation,*this,argument);};
    bool work=true;
    if(services.button(Button::primary,*this))state.control_armed=0;
    else if(state.control_armed){
        effect(PhaseEffect::request_actor_ui,world_.selected_actor);effect(PhaseEffect::update_ui);
        if(state.control_state==2){
            effect(PhaseEffect::finish_request);effect(PhaseEffect::reset_audio_request);
            effect(PhaseEffect::stop_audio_group,3);effect(PhaseEffect::enter_phase,15);return result;
        }
        work=false;
    }
    if(work){
        result=workers(services,actors,providers,script_budget,task_budget);
        if(result.status!=Status::completed)return result;
        if(world_.paused){
            effect(PhaseEffect::paused_transition);effect(PhaseEffect::finish_request);
            effect(PhaseEffect::enter_phase,4);return result;
        }
        if(state.transition_gate){
            effect(PhaseEffect::finish_request);effect(PhaseEffect::stop_streams);
            effect(PhaseEffect::finish_audio);effect(PhaseEffect::enter_phase,12);return result;
        }
        if(clock_.commit_update(world_.session().clock_mode?tasks::ClockStep::two:tasks::ClockStep::one)!=tasks::Status::completed){result.status=Status::task_failure;return result;}
        result.clock_committed=true;
        if(state.exit_requested){
            effect(PhaseEffect::close_ui);effect(PhaseEffect::publish_statistics);state.notification_pending=1;
            effect(PhaseEffect::enter_phase,3);
            if(world_.mode!=0)clock_.adjust_update_counter(state.short_exit_adjustment?150:360);
        }
        if(services.button(Button::secondary,*this) && (state.request_flags&0x100))state.pause_latched=1;
        if(state.pause_latched){
            state.notification_pending=state.transition_gate=1;
            effect(PhaseEffect::finish_request);effect(PhaseEffect::enter_phase,12);return result;
        }
    }
    if(services.button(Button::primary,*this) || world_.mode==1 || world_.session().session_state!=0)return result;
    if(state.control_state==1)state.control_armed=1;
    else if(services.transition_request(*this)){
        if(state.control_armed)effect(PhaseEffect::close_ui);
        state.control_armed=0;
    }else if(state.control_flags&0x4000){
        if(state.control_armed)effect(PhaseEffect::close_ui);
        state.control_armed^=1;
    }
    return result;
}
}
