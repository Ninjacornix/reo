#pragma once
#include "../gameplay_tasks/tasks.hpp"
#include "../gameplay_world/world.hpp"

namespace reo::native::gameplay_update {
// Borrows the actual World and shared 32-entry Scheduler. Both must outlive
// this owner. Tasks retain generation-safe identities, never actor pointers.
class MaterialAnimations final {
public:
    MaterialAnimations(gameplay_world::World&,gameplay_tasks::Scheduler&);
    ~MaterialAnimations();
    MaterialAnimations(const MaterialAnimations&)=delete;
    MaterialAnimations& operator=(const MaterialAnimations&)=delete;
    gameplay_tasks::Created create(const gameplay_world::actors::EntityId&)noexcept;
    bool bound_to(const gameplay_world::World&)const noexcept;
    std::optional<gameplay_world::MaterialAnimationState> snapshot(const gameplay_tasks::Handle&)const noexcept;
    void close()noexcept;
private:
    struct Shared;
    class Work;
    std::shared_ptr<Shared> shared_;
};
}
