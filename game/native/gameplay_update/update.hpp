#pragma once
#include "../gameplay_world/world.hpp"
#include "../gameplay_scenario/offline.hpp"
#include "../gameplay_tasks/events.hpp"

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
    transition_control,scenario_events
};
class Owner;
class Services {
public:
    virtual ~Services()=default;
    virtual void run(Worker,Owner&)=0;
};
struct State {
    bool limit_override{};
    bool scripts_enabled{true};
    std::int16_t session_work_gate{};
};
enum class Status {completed,busy,closed,actor_failure,script_failure,task_failure,flag_failure};
struct Result {
    Status status{Status::completed};
    std::size_t worker_calls{},script_operations{};
    world::Result actors;
    tasks::PassResult linked,events;
};
class Owner final {
public:
    // Borrowed native world and notification target must outlive this owner.
    Owner(world::World&,scenario::FlagNotifications&);
    ~Owner();
    Owner(const Owner&)=delete;
    Owner& operator=(const Owner&)=delete;
    Result run_workers(Services&,world::Services&,scenario::Providers={},
                       std::size_t script_budget=4096,std::size_t task_budget=1024);
    Status close()noexcept;
    world::World& world()noexcept{return world_;}
    tasks::Scheduler& linked()noexcept{return linked_;}
    tasks::EventTasks& events()noexcept{return events_;}
    tasks::FlagTimers& timers()noexcept{return timers_;}
    tasks::SimulationClock& clock()noexcept{return clock_;}
    scenario::Interpreter& scripts()noexcept{return scripts_;}
    scenario::OfflineCoordinator& offline()noexcept{return offline_;}
    scenario::FlagState& flags()noexcept{return flags_;}
    State state;
private:
    world::World& world_;
    tasks::Scheduler linked_;
    tasks::EventTasks events_;
    tasks::FlagTimers timers_;
    tasks::SimulationClock clock_;
    scenario::FlagState flags_;
    scenario::Interpreter scripts_;
    scenario::OfflineCoordinator offline_;
    bool running_{},closed_{};
    Status run_script(std::size_t,scenario::Providers,std::size_t,Result&)noexcept;
    Status script_service(Services&,scenario::Providers,std::size_t,Result&);
};
}
