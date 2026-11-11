#include "humanoid_motion_bindings.hpp"
#include "world.hpp"
namespace reo::native::gameplay_world {
std::shared_ptr<const animation::MotionBank> resolve_humanoid_motion_bank(const World& world,
    HumanoidMotionAlias alias,const std::shared_ptr<const animation::MotionBank>& fallback)noexcept{
    if(world.closed())return{};
    if(const auto* source=world.humanoid_motion_source())return source->bank(alias);
    return world.humanoid_motion_source_closed()?nullptr:fallback;
}
}
