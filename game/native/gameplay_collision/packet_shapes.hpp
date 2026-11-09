#pragma once
#include "packet_service.hpp"
#include "contact_scan.hpp"
#include "radius.hpp"
#include "room_damage.hpp"
namespace reo::native::gameplay_collision::delivery {
struct ShapePose {
    const actors::Basis& root;
    std::span<const actors::Basis> joints;
    postmove::VectorRef projectile_point, projectile_normal;
    bool& surface_valid;
};
class PacketPoses {
  public:
    virtual ~PacketPoses() = default;
    // Invocation retains the actual native actor/model pose owners. No model
    // address or borrowed joint survives query(), including effect callbacks.
    virtual std::optional<ShapePose> pose(PacketOwner) = 0;
};
struct ShapeScene {
    const response::Grid& walls;
    const response::Grid& floors;
    std::span<const response::Triangle> dynamic;
    // Canonical grid disabled mask and channel states. slots[i].state is the
    // SAME channel gate byte borrowed below, not an independent saved option.
    response::Filter filter;
    RouteChannels& channels;
};
class PacketScenes {
  public:
    virtual ~PacketScenes() = default;
    virtual std::optional<ShapeScene> scene(PacketOwner) = 0;
};
class PacketShapeEffects {
  public:
    virtual ~PacketShapeEffects() = default;
    // Required typed5DD580 policy. Event1 uses wall normal and packet impact;
    // event2 uses floor point/normal/type. Unused caller locals are not inputs.
    virtual Status scene_contact(const Packet&, PacketOwner, const std::optional<trace::Hit>& wall,
                                 const std::optional<trace::Hit>& floor) = 0;
    virtual bool debug_enabled() = 0;
    virtual Status debug_line(Vec3 start, Vec3 end) = 0;
};
// Retains the qualified native scanner context and original enrollment order;
// every mutation is applied through the canonical actor/component references.
class ShapePipeline final : public PacketShapes {
  public:
    ShapePipeline(Context&, hit_regions::Queue&, PacketPoses&, PacketScenes&, PacketShapeEffects&);
    ShapeResult query(PacketState&, PacketOwner) override;

  private:
    Context& context_;
    hit_regions::Queue& targets_;
    PacketPoses& poses_;
    PacketScenes& scenes_;
    PacketShapeEffects& effects_;
};
namespace shape_geometry {
// Original segment/margin caller clips its endpoint to nonnegative X/Z. The
// interpolation factor is max(abs(negativeX/deltaX),abs(negativeZ/deltaZ)); it
// also changes Y and finally clamps residual negative X/Z to zero.
void clip_endpoint(Vec3 start, Vec3& end) noexcept;
struct Transformed {
    Vec3 origin, direction;
};
std::optional<Transformed> transform(Vec3 local_origin, Vec3 local_direction,
                                     std::optional<std::uint16_t> joint, ShapePose,
                                     postmove::VectorRef actor_position) noexcept;
} // namespace shape_geometry
} // namespace reo::native::gameplay_collision::delivery
