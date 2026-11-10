#pragma once
#include "../gameplay_world/world.hpp"
#include "../gameplay_scenario/offline.hpp"
#include "../gameplay_tasks/events.hpp"
#include "../gameplay_events/events.hpp"
#include "../gameplay_events/statistics.hpp"
#include "completion_conditions.hpp"
#include "scenario_publication.hpp"
#include "actor_gauge.hpp"
#include "../gameplay_world/behavior.hpp"
#include "../gameplay_world/alignment.hpp"
#include "../gameplay_world/interaction_transitions.hpp"
#include "../gameplay_navigation/conditions.hpp"
#include "../gameplay_navigation/edges.hpp"
#include "../gameplay_navigation/routes.hpp"
#include "../gameplay_navigation/cost_routes.hpp"

namespace reo::native::gameplay_update {
namespace tasks=gameplay_tasks;
namespace scenario=gameplay_scenario;
namespace world=gameplay_world;
// Named native boundaries retain the source service order. Their precise
// content/effect owners remain required until migrated; no default no-ops.
enum class Worker {
    reset_entity_queues,armed_request,limit_action,clear_interaction_activity,
    clear_proxy_work,target_caches,auxiliary_actors,scenario_actors,
    actor_collision_shapes,collision_heights,primary_model_poses,
    auxiliary_model_poses,scenario_model_poses,primary_actor_postprocess,
    auxiliary_actor_postprocess,primary_hit_regions,auxiliary_hit_regions,
    scenario_hit_regions,camera_modes,model_interactions,resource_instances,
    scene_pose_tasks,render_work_banks,large_callbacks,gameplay_ui,
    room_sound_callbacks,sequences,room_occupancy,contact_candidates,
    contact_packets,room_entity_ownership,actor_action_publication,
    transition_control
};
class Owner;
class Services {
public:
    virtual ~Services()=default;
    virtual void run(Worker,Owner&)=0;
};
enum class Button {primary,secondary};
enum class PhaseEffect {
    request_actor_ui,update_ui,finish_request,reset_audio_request,stop_audio_group,
    close_ui,publish_statistics,enter_phase,paused_transition,stop_streams,finish_audio
};
class PhaseServices : public Services {
public:
    virtual bool button(Button,Owner&)=0;
    virtual bool transition_request(Owner&)=0;
    virtual void effect(PhaseEffect,Owner&,std::uint32_t argument=0)=0;
};
struct State {
    bool limit_override{};
    bool scripts_enabled{true};
    std::int16_t session_work_gate{};
    std::uint8_t control_armed{},control_state{},short_exit_adjustment{};
    std::uint8_t notification_pending{},transition_gate{},pause_latched{};
    std::uint32_t request_flags{},control_flags{};
    // Supplied by the actual native audio/SDK tick owner. Simulation updates
    // and presentation counts are not substitutes; an absent tick stays absent.
    std::optional<std::uint32_t> audio_tick;
};
enum class Status {completed,busy,closed,actor_failure,script_failure,task_failure,flag_failure,statistics_failure};
struct Result {
    Status status{Status::completed};
    std::size_t worker_calls{},script_operations{};
    world::Result actors;
    tasks::PassResult linked,events;
    bool clock_committed{};
    bool completion_checked{};
    gameplay_events::Recorded completion;
};
class Owner final:public world::actors::StatusTiming,public world::ActivityPublication,public world::GaugeApplication,private scenario::FlagNotifications {
public:
    // Borrowed native world and notification target must outlive this owner.
    Owner(world::World&,scenario::FlagNotifications&,std::shared_ptr<const gameplay_events::RuleBook> = gameplay_events::RuleBook::file1(),GameplayMessageSink* = nullptr,const gameplay_collision::room_objects::Owner* = nullptr);
    ~Owner();
    Owner(const Owner&)=delete;
    Owner& operator=(const Owner&)=delete;
    Result run_workers(Services&,world::Services&,scenario::Providers={},
                       std::size_t script_budget=4096,std::size_t task_budget=1024);
    Result advance(PhaseServices&,world::Services&,scenario::Providers={},
                   std::size_t script_budget=4096,std::size_t task_budget=1024);
    Status close()noexcept;
    world::World& world()noexcept{return world_;}
    tasks::Scheduler& linked()noexcept{return linked_;}
    tasks::EventTasks& events()noexcept{return events_;}
    tasks::FlagTimers& timers()noexcept{return timers_;}
    tasks::SimulationClock& clock()noexcept{return clock_;}
    gameplay_events::Events& cooperative_events()noexcept{return cooperative_;}
    gameplay_events::Statistics& completion_statistics()noexcept{return statistics_;}
    world::InteractionTransition consume_actor_interaction_request(const world::actors::EntityId& id,std::uint32_t selector)noexcept{
        return open()?publication_.consume_interaction_request(id,selector):world::InteractionTransition{};
    }
    scenario::ActionChoices& action_choices()noexcept{return choices_;}
    PublicationStatus record_resource_operation(std::uint32_t resource,std::uint32_t actor,std::uint32_t operation)noexcept{
        if(!open())return PublicationStatus::unavailable;
        return publication_.resource_operation(resource,actor,operation);
    }
    PublicationStatus record_resource_position(std::uint32_t resource,std::uint32_t actor,std::uint32_t operation,std::optional<world::Position> position)noexcept{
        if(!open())return PublicationStatus::unavailable;
        return publication_.resource_position(resource,actor,operation,position);
    }
    PublicationStatus record_actor_status(const world::actors::EntityId& actor)noexcept{
        if(!open())return PublicationStatus::unavailable;
        return publication_.actor_status(actor);
    }
    PublicationStatus record_actor_action(const world::actors::EntityId& actor)noexcept{
        if(!open())return PublicationStatus::unavailable;
        return publication_.actor_action(actor);
    }
    PublicationStatus record_actor_message(const world::actors::EntityId& actor,ActorMessageSelector selector)noexcept{
        if(!open())return PublicationStatus::unavailable;
        return publication_.actor_message(actor,selector);
    }
    std::optional<bool> prepare_actor_contact_alignment(const world::actors::EntityId& id,std::uint32_t limit,float offset){
        if(!open())return std::nullopt;
        const auto actor=world_.resolve(id);if(!actor)return std::nullopt;
        return world::prepare_contact_alignment(*actor,limit,offset);
    }
    PublicationStatus record_periodic_actor_state(const world::actors::EntityId& actor)noexcept{
        if(!open())return PublicationStatus::unavailable;
        return publication_.periodic_actor_state(actor);
    }
    bool publish_activity(world::World& source,world::Actor& actor)noexcept override{
        if(&source!=&world_)return false;
        const auto id=world_.identity_of(actor);if(!id)return false;
        return record_periodic_actor_state(id)==PublicationStatus::completed;
    }
    GaugeStatus record_gauge_crossing(const world::actors::EntityId&,std::uint32_t before,std::uint32_t after);
    GaugeResult adjust_actor_gauge(const world::actors::EntityId&,std::uint32_t amount,std::uint32_t mode);
    bool apply_hit_gauge(world::World& source,world::Actor& actor,std::uint16_t amount)override{
        if(&source!=&world_)return false;
        const auto id=world_.identity_of(actor);if(!id)return false;
        return adjust_actor_gauge(id,amount,0).status==GaugeStatus::completed;
    }
    PublicationStatus clear_actor_status(const world::actors::EntityId& id,std::uint32_t selector)noexcept{
        if(!open())return PublicationStatus::unavailable;
        const auto actor=world_.resolve(id);if(!actor)return PublicationStatus::unavailable;
        world::actors::clear_status_fields(*actor,selector);
        return publication_.actor_status(id);
    }
    gameplay_events::Recorded check_scenario_events(){
        if(!open()||!world_.session().scenario)return{gameplay_events::StatisticsStatus::unavailable};
        return statistics_.automatic(*world_.session().scenario,CompletionConditions(world_,flags_,choices_),cooperative_,clock_.update_counter());
    }
    gameplay_events::StatisticsStatus initialize_completion_statistics(){
        if(!open()||!world_.session().scenario)return gameplay_events::StatisticsStatus::unavailable;
        return statistics_.initialize(*world_.session().scenario,cooperative_);
    }
    gameplay_events::Recorded record_scenario_event(std::uint32_t content){
        if(!open()||!world_.session().scenario)return{gameplay_events::StatisticsStatus::unavailable};
        return statistics_.explicit_id(*world_.session().scenario,content,cooperative_,clock_.update_counter());
    }
    bool open()const noexcept{return !closed_&&!world_.closed();}
    // Actual cooperative event producers borrow this owner's committed update
    // counter and canonical room, never display frames or a second clock.
    gameplay_events::Created record_event(std::uint32_t id,std::uint32_t first,std::uint32_t second){
        if(!open())return{gameplay_events::Status::closed,{}};
        return cooperative_.typed(id,first,second,clock_.update_counter(),world_.room);
    }
    gameplay_events::Created record_simple_event(std::uint32_t id){
        if(!open())return{gameplay_events::Status::closed,{}};
        return cooperative_.simple(id,clock_.update_counter());
    }
    std::uint8_t seconds()const noexcept override{return clock_.play_time().seconds;}
    std::uint8_t subseconds()const noexcept override{return clock_.play_time().sixtieths;}
    scenario::Interpreter& scripts()noexcept{return scripts_;}
    scenario::OfflineCoordinator& offline()noexcept{return offline_;}
    scenario::FlagState& flags()noexcept{return flags_;}
    gameplay_navigation::ConditionResult applicable_navigation_condition(const world::actors::EntityId&,std::uint32_t room,std::int32_t index);
    gameplay_navigation::AdmissionResult admit_navigation_condition(const world::actors::EntityId&,std::uint32_t room,std::int32_t index);
    gameplay_navigation::LinkResult admitted_navigation_link(const world::actors::EntityId&,std::int32_t room,std::int32_t variant,std::int32_t node);
    gameplay_navigation::AdmissionResult admit_navigation_edge(const world::actors::EntityId&,std::uint32_t room,std::int32_t source,std::int32_t destination);
    gameplay_navigation::RouteResult ranked_navigation_route(const world::actors::EntityId&,std::uint32_t room,std::int32_t source,std::int32_t destination,gameplay_navigation::RankedPolicy,gameplay_navigation::RouteOutput&);
    gameplay_navigation::CostRouteResult bounded_navigation_route(const world::actors::EntityId&,std::uint32_t room,std::int32_t source,std::int32_t destination,gameplay_navigation::RouteOutput&,std::size_t maximum_edges=65536);
    State state;
private:
    world::World& world_;
    tasks::Scheduler linked_;
    tasks::EventTasks events_;
    tasks::FlagTimers timers_;
    tasks::SimulationClock clock_;
    gameplay_events::Events cooperative_;
    gameplay_events::Statistics statistics_;
    scenario::FlagNotifications& notifications_;
    scenario::FlagState flags_;
    StatePublication publication_;
    scenario::ActionChoices choices_;
    scenario::Interpreter scripts_;
    scenario::OfflineCoordinator offline_;
    bool running_{},closed_{};
    bool changed(const scenario::ScenarioFlagChange& value)noexcept override{
        if(!open())return false;
        if(publication_.publish(value.id,value.value,value.actor_owner)!=PublicationStatus::completed)return false;
        return notifications_.changed(value);
    }
    bool changed(const scenario::StridedFlagChange& value)noexcept override{return notifications_.changed(value);}
    Status run_script(std::size_t,scenario::Providers,std::size_t,Result&)noexcept;
    Status script_service(Services&,scenario::Providers,std::size_t,Result&);
    Result workers(Services&,world::Services&,scenario::Providers,std::size_t,std::size_t);
};
}
