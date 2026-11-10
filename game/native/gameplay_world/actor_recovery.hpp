#pragma once
#include "actor_resource_operations.hpp"
#include "behavior.hpp"
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_world {
class WorldAnimation;
// Remaining6E1430 UI consumer, after the original inventory-owner clear.
class RecoveryUi {
public:
    virtual ~RecoveryUi()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual bool close()=0;
};
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
