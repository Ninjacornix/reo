#pragma once
#include "work.hpp"
namespace reo::native::gameplay_effects {
struct ProjectileTrailState {
    std::uint8_t phase{};
    bool visible{};
    transform_math::Matrix basis;
};
// Immutable renderer handoff for the controller's actual resource/root and
// basis. Rendering this recipe belongs to the native rendering stage.
struct ProjectileTrailOutput {
    ProjectileTrailState state;
    std::size_t geometry_root{};
    std::uint32_t flags{0x8193};
    std::uint16_t resource{0x12};
    std::uint8_t draw_kind{26};
};
struct ProjectileTrailMotion {
    bool active{};std::uint8_t kind{};
    transform_math::Matrix basis;
    transform_math::Vector position;
};
class ProjectileTrailEmission {
public:
    virtual ~ProjectileTrailEmission()=default;
    virtual WorkStatus emit(const WorkRequest&)=0;
};
struct ProjectileTrailStep {bool available{true},retire{};};
// Complete653CC0 CPU policy. The caller supplies the actual7123B0 byte.
ProjectileTrailStep advance_projectile_trail(ProjectileTrailState&,const ProjectileTrailMotion&,std::uint8_t variant,ProjectileTrailEmission&);
}
