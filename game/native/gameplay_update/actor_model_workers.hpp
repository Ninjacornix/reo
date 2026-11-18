#pragma once
#include "update.hpp"
#include "../gameplay_world/actor_model_passes.hpp"
namespace reo::native::gameplay_update {
// Owns actual3769F0/376AE0 at their existing frame-worker positions.
// All other phase operations remain with their explicit remaining owner.
class ActorModelWorkers final:public PhaseServices {
public:
    ActorModelWorkers(world::World&,PhaseServices&,const world::ModelCorrectionScales&,
                      world::WorldResourceAttachments&,
                      std::shared_ptr<const gameplay_collision::response::Grid> = {});
    ~ActorModelWorkers();
    void run(Worker,Owner&)override;
    bool button(Button,Owner&)override;
    bool transition_request(Owner&)override;
    void effect(PhaseEffect,Owner&,std::uint32_t=0)override;
    Status close()noexcept;
    const std::optional<world::ActorModelsPublished>& primary_result()const noexcept{return primary_;}
    const std::optional<world::ActorModelsPublished>& auxiliary_result()const noexcept{return auxiliary_;}
private:
    world::World& world_;PhaseServices& remaining_;world::ActorModelPasses passes_;
    std::optional<world::ActorModelsPublished> primary_{},auxiliary_{};
    bool running_{},closed_{};
    void verify(Owner&)const;
};
}
