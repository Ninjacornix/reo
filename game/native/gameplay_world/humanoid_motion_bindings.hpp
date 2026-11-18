#pragma once
#include <cstdint>
#include <memory>
namespace reo::native::animation {class MotionBank;}
namespace reo::native::gameplay_world {
class World;
enum class HumanoidMotionFamily:std::uint8_t {scene_body,scene_face,general,alternate,character,primary,scenario_auxiliary};
// A native semantic binding to a shared bank owner, not a captured bank version
// or an original RAM address. Character is meaningful only for that family.
struct HumanoidMotionAlias {
    HumanoidMotionFamily family{};std::uint8_t character{};
    friend bool operator==(const HumanoidMotionAlias&,const HumanoidMotionAlias&)=default;
};
class HumanoidMotionSource {
public:
    virtual ~HumanoidMotionSource()=default;
    virtual std::shared_ptr<const animation::MotionBank> bank(HumanoidMotionAlias)const noexcept=0;
};
// Standalone components retain their explicit direct bindings until a World
// adopts a canonical source. A closed adopted source never falls back silently.
std::shared_ptr<const animation::MotionBank> resolve_humanoid_motion_bank(const World&,
    HumanoidMotionAlias,const std::shared_ptr<const animation::MotionBank>& fallback={})noexcept;
}
