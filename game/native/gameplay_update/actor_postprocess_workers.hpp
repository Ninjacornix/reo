#pragma once
#include "update.hpp"
#include "../gameplay_world/primary_actor_postprocess.hpp"
namespace reo::native::gameplay_update {
// Adopts actual66A3A0 at its existing phase position, using this Update owner's
// World, flag state and statistics. Other workers retain their required owner.
class ActorPostprocessWorkers final:public PhaseServices {
public:
    ActorPostprocessWorkers(Owner&,PhaseServices&,gameplay_scene::Records&,
        scenario::SceneMatrixPrograms&,std::shared_ptr<const gameplay_collision::response::Grid> = {},
        world::ActorWeaponActions* = nullptr);
    ~ActorPostprocessWorkers();
    ActorPostprocessWorkers(const ActorPostprocessWorkers&)=delete;
    ActorPostprocessWorkers& operator=(const ActorPostprocessWorkers&)=delete;
    void run(Worker,Owner&)override;
    bool button(Button,Owner&)override;
    bool transition_request(Owner&)override;
    void effect(PhaseEffect,Owner&,std::uint32_t=0)override;
    Status close()noexcept;
    const std::optional<world::PrimaryPostprocessReport>& last_result()const noexcept{return result_;}
private:
    Owner& owner_;PhaseServices& remaining_;
    std::shared_ptr<const gameplay_collision::response::Grid> floors_;
    world::PrimaryActorPostprocess pass_;
    std::optional<world::PrimaryPostprocessReport> result_{};
    bool running_{},closed_{};
    void verify(Owner&)const;
};
}
