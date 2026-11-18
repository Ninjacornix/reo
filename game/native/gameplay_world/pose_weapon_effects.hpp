#pragma once
#include "weapon_fire.hpp"
#include "resource_pose_work.hpp"
namespace reo::native::gameplay_world {
// Supplies actual5823E0 through the canonical scene pose and packet owners.
// The other effect families require their actual composed consumers.
class PoseWeaponEffects final:public WeaponEffects {
public:
    PoseWeaponEffects(World&,ResourcePoseWork&,WeaponEffects* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool pose_work(const actors::EntityId&,const animation::Matrix&,animation::Vector,std::uint32_t)override;
    bool transient_light(const actors::EntityId&,animation::Vector)override;
    bool contact_style(const actors::EntityId&,const animation::Matrix&,animation::Vector,std::uint8_t)override;
    bool flight(const actors::EntityId&,const animation::Matrix&,std::uint32_t)override;
private:
    World& world_;ResourcePoseWork& poses_;WeaponEffects* remaining_;
};
}
