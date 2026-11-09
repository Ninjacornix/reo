#pragma once
#include <array>
#include <cstdint>
namespace reo::native::gameplay_world {class World;}
namespace reo::native::gameplay_scenario {
// Actual shared native effect-owner consumer for the room modulation command.
// A positive admission requires the canonical World/RNG and population owner.
class SurfaceEffects {
public:
    virtual ~SurfaceEffects()=default;
    virtual bool bound_to(const gameplay_world::World&)const noexcept=0;
    virtual bool configure_surface(std::uint32_t selector,const std::array<std::uint32_t,4>&)noexcept=0;
};
}
