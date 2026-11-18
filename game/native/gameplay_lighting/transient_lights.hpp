#pragma once
#include "lights.hpp"
#include "../gameplay_tasks/tasks.hpp"
#include "../gameplay_actors/entity.hpp"
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_collision::response {class Grid;}
namespace reo::native::gameplay_lighting {
struct TransientState {
    std::uint8_t phase{};
    std::array<std::int16_t,2> remaining{};
};
struct TransientStep {
    bool retire{};
    std::array<bool,2> release{};
    std::array<std::optional<float>,2> attenuation;
};
// Actual5D83D0 lifetime, with independent nullable primary/auxiliary children.
TransientStep advance_transient_light(TransientState&,std::array<bool,2> present);
Definition transient_definition(const std::array<float,3>&)noexcept;
enum class TransientStatus {completed,task_full,unavailable,busy,no_memory,closed};
struct TransientCreated {
    TransientStatus status{TransientStatus::unavailable};
    gameplay_tasks::Handle task;
    std::array<bool,2> lights{};
};
struct TransientSnapshot {TransientState state;std::array<std::optional<Light>,2> lights;};
//6B24F0 uses the canonical Update scheduler and the scene's two existing light
// arrays. Allocation failures of either child remain independent and normal.
class TransientLights final {
public:
    TransientLights(gameplay_update::Owner&,gameplay_scenario::Lighting&);
    ~TransientLights();
    TransientLights(const TransientLights&)=delete;
    TransientLights& operator=(const TransientLights&)=delete;
    bool bound_to(const gameplay_update::Owner&,const gameplay_scenario::Lighting&)const noexcept;
    TransientCreated create(const gameplay_actors::EntityId&,const std::array<float,3>&)noexcept;
    // Actual6B25B0 uses the retained room floor material, without an actor.
    // Task admission precedes the floor sample; both child pools are optional.
    TransientCreated create_projectile(const std::array<float,3>&,const gameplay_collision::response::Grid&)noexcept;
    std::optional<TransientSnapshot> snapshot(const gameplay_tasks::Handle&)const noexcept;
    TransientStatus failure()const noexcept;
    TransientStatus close()noexcept;
private:
    struct Shared;class Work;
    std::shared_ptr<Shared> shared_;
    TransientCreated create_impl(const std::array<float,3>&,std::uint8_t,const gameplay_collision::response::Grid*)noexcept;
};
}
