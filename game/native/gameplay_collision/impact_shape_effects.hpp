#pragma once
#include "impact_policy.hpp"
#include "packet_shapes.hpp"
namespace reo::native::gameplay_collision::delivery {
class ShapeDebug {
  public:
    virtual ~ShapeDebug() = default;
    virtual bool enabled() = 0;
    virtual Status line(Vec3 start, Vec3 end) = 0;
};
// Compose the full impact policy with shape callers. The event1 reference is
// the actual packet impact; the policy keeps event2's floor point local.
class ImpactShapeEffects final : public PacketShapeEffects {
  public:
    ImpactShapeEffects(Actors& actors, ImpactVisuals& visuals, ShapeDebug& debug)
        : actors_(actors), visuals_(visuals), debug_(debug) {}
    Status scene_contact(const Packet& packet, PacketOwner, Vec3& impact,
                         const std::optional<trace::Hit>& wall,
                         const std::optional<trace::Hit>& floor) override {
        return emit_contact_impact(packet, impact, actors_, visuals_, wall, floor);
    }
    bool debug_enabled() override {
        return debug_.enabled();
    }
    Status debug_line(Vec3 start, Vec3 end) override {
        return debug_.line(start, end);
    }

  private:
    Actors& actors_;
    ImpactVisuals& visuals_;
    ShapeDebug& debug_;
};
} // namespace reo::native::gameplay_collision::delivery
