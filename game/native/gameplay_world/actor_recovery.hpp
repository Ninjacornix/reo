#pragma once
#include "actor_resource_operations.hpp"
#include "behavior.hpp"
#include "recovery_ui.hpp"
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_world {
class WorldAnimation;
class ActorRecovery final:public ZeroHealthApplication {
public:
    ActorRecovery(gameplay_update::Owner&,ActorResourceOperations&,WorldAnimation* = nullptr,RecoveryUi* = nullptr);
    bool bound_to(const World&)const noexcept;
    void apply(const actors::EntityId&,std::uint32_t mode); // complete65FCB0 policy
    void enter_zero_health(const actors::EntityId&,std::uint32_t phase); // complete65FBA0
    bool apply_zero_health(World&,Actor&,actors::StatusServices&)override;
private:
    gameplay_update::Owner& update_;ActorResourceOperations& operations_;World& world_;
    WorldAnimation* animation_{};RecoveryUi* ui_{};
};
}
