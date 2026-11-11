#pragma once
#include "update.hpp"
#include "../gameplay_world/npc_updates.hpp"
#include "../gameplay_world/surface_orientation.hpp"
namespace reo::native::gameplay_update {
// Compose the actual auxiliary-actor worker in the existing Update pass.
// Borrowed behavior/camera/inhibition/attachment owners must outlive this layer.
class NpcActorWorkers final:public PhaseServices {
public:
    NpcActorWorkers(world::World&,PhaseServices&,world::Services&,
        std::shared_ptr<const gameplay_collision::response::Grid>,
        const world::Position& camera,const std::uint8_t& inhibition,world::NpcAttachmentFrames* = nullptr);
    ~NpcActorWorkers();
    NpcActorWorkers(const NpcActorWorkers&)=delete;
    NpcActorWorkers& operator=(const NpcActorWorkers&)=delete;
    void run(Worker,Owner&)override;
    bool button(Button,Owner&)override;
    bool transition_request(Owner&)override;
    void effect(PhaseEffect,Owner&,std::uint32_t=0)override;
    Status close()noexcept;
    const std::optional<world::NpcUpdated>& last_actors()const noexcept{return last_;}
private:
    void verify(Owner&)const;
    world::World& world_;PhaseServices& remaining_;
    std::shared_ptr<const gameplay_collision::response::Grid> floors_;
    world::GridSurfaceOrientation pose_;world::NpcActorUpdates updates_;
    std::optional<world::NpcUpdated> last_;
    bool closed_{},running_{};
};
}
