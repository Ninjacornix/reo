#pragma once
#include "humanoid_motion_assets.hpp"
namespace reo::native::gameplay_world {
enum class HumanoidPublicationStatus {completed,busy,closed,stale,unavailable,no_memory};
struct HumanoidPublished {HumanoidPublicationStatus status{HumanoidPublicationStatus::unavailable};std::size_t actors{},bindings{};bool changed{};};
// Simulation-owner publication of off-thread prepared immutable content.
// No preparation callback runs here, and no animation channel is reconfigured.
class HumanoidMotionOwner final:public HumanoidMotionSource {
public:
    explicit HumanoidMotionOwner(World&);
    ~HumanoidMotionOwner();
    HumanoidMotionOwner(const HumanoidMotionOwner&)=delete;
    HumanoidMotionOwner& operator=(const HumanoidMotionOwner&)=delete;
    bool bound_to(const World& world)const noexcept{return &world_==&world;}
    HumanoidPublished publish(std::shared_ptr<const HumanoidMotionBanks>)noexcept;
    std::shared_ptr<const animation::MotionBank> bank(HumanoidMotionAlias)const noexcept override;
    std::shared_ptr<const HumanoidMotionBanks> snapshot()const noexcept{return current_;}
    HumanoidPublicationStatus close()noexcept;
private:
    friend class PrimaryActorModels;
    friend class gameplay_application::SessionRoomMotions;
    HumanoidPublished publish_nested(std::shared_ptr<const HumanoidMotionBanks>,bool nested)noexcept;
    World& world_;std::shared_ptr<const HumanoidMotionBanks> current_;
    bool closed_{},running_{};
};
}
