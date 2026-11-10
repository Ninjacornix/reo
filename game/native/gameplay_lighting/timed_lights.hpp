#pragma once
#include "lights.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_tasks/tasks.hpp"
namespace reo::native::gameplay_lighting {
struct TimedState {
    std::uint8_t phase{};
    std::int16_t remaining{},wobble{},fade_remaining{},fade_duration{};
    std::array<float,2> saved{};
};
// Source7202C0 definition with the caller's three position components.
Definition timed_definition(const std::array<float,3>&)noexcept;
// Complete5D8630 timing policy. Returns retirement without touching pool/task
// ownership. Runtime calls it only for a live light and actor generation.
bool advance_timed_light(TimedState&,Definition&,std::uint8_t clock_mode);
enum class TimedStatus {completed,skipped,task_full,light_full,actor_unavailable,tag_unavailable,closed,no_memory,task_unavailable,light_unavailable};
struct TimedCreated {
    TimedStatus status{TimedStatus::closed};
    gameplay_tasks::Status task_status{gameplay_tasks::Status::invalid};
    gameplay_tasks::Handle task;
    LightId light;
};
struct TimedSnapshot {TimedState state;LightId light;};
// Borrowed owners outlive this component and its tasks. Uses the scene's
// existing scheduler and lighting facade, never private replacement pools.
class TimedLights final {
public:
    TimedLights(gameplay_world::World&,gameplay_tasks::Scheduler&,Pool&);
    ~TimedLights();
    TimedLights(const TimedLights&)=delete;
    TimedLights& operator=(const TimedLights&)=delete;
    TimedCreated create(const gameplay_actors::EntityId&,const std::array<float,3>&)noexcept;
    std::optional<TimedSnapshot> snapshot(const gameplay_tasks::Handle&)const noexcept;
    bool bound_to(const gameplay_world::World&,const gameplay_tasks::Scheduler&,const Pool&)const noexcept;
    TimedStatus failure()const noexcept;
    void close()noexcept;
private:
    struct Shared;
    class Work;
    std::shared_ptr<Shared> shared_;
};
}
