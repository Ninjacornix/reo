#pragma once
#include "cinematic_objects.hpp"
namespace reo::native::gameplay_world {
struct CinematicObjectAttachment {
    animation::Vector offset{};
    transform_math::Angles rotation{};
    static CinematicObjectAttachment read(std::span<const std::byte>);
};
//5717C0 after the caller resolves its actual actor/object parent and full node
// ordinal. parent_scale is the caller-owned sourceB4/B8/BC view; this helper
// does not infer model-work metadata or substitute a default object scale.
// It preserves copied matrix W/translation lanes while updating position.
void attach_cinematic_object(CinematicObject&,const animation::Instance& parent,
    std::uint32_t node,animation::Vector parent_scale,const CinematicObjectAttachment&);
}
