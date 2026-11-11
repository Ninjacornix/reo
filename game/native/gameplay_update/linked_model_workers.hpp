#pragma once
#include "update.hpp"
#include "../gameplay_world/linked_models.hpp"
namespace reo::native::gameplay_update {
enum class LinkedModelProgress {never_run,acquiring,completed,failed};
// Native376B80 adoption at its actual worker position. Remaining workers and
// phase effects retain their required provider; this layer does not claim
// that those unrelated scene/gameplay consumers have migrated.
class LinkedModelWorkers final:public PhaseServices {
public:
    LinkedModelWorkers(world::World&,PhaseServices&,std::shared_ptr<const gameplay_collision::response::Grid>);
    ~LinkedModelWorkers();
    LinkedModelWorkers(const LinkedModelWorkers&)=delete;
    LinkedModelWorkers& operator=(const LinkedModelWorkers&)=delete;
    void run(Worker,Owner&)override;
    bool button(Button,Owner&)override;
    bool transition_request(Owner&)override;
    void effect(PhaseEffect,Owner&,std::uint32_t=0)override;
    void select_root(world::actors::EntityId);
    const world::actors::EntityId& selected_root()const noexcept{return root_.selected();}
    const world::actors::EntityId& observed_root()const noexcept{return root_.observed();}
    const std::optional<world::LinkedModelReport>& last_models()const noexcept{return models_;}
    LinkedModelProgress progress()const noexcept{return progress_;}
    Status close()noexcept;
private:
    void verify(Owner&)const;
    world::World& world_;PhaseServices& remaining_;
    std::shared_ptr<const gameplay_collision::response::Grid> floors_;
    world::LinkedPoseRoot root_;
    world::File1ModelCorrectionScales scales_;
    std::optional<world::LinkedModelReport> models_;
    LinkedModelProgress progress_{};
    bool closed_{},running_{};
};
}
