#pragma once
#include "object_interactions.hpp"
namespace reo::native::gameplay_collision::room_objects {
struct ObjectInstance final : gameplay_actors::Entity {
    ObjectId object;
    bool active{true}, visible{};
    std::uint8_t category{8}, subtype{2}, object_ordinal{}, model_slot{255}, material{255};
    std::uint16_t type{}, yaw{};
    std::uint32_t flags{};
    Vec3 position, scale{1, 1, 1};
    actors::Basis basis;
};
class ModelBindings {
  public:
    virtual ~ModelBindings() = default;
    virtual std::uint8_t resolve(std::uint8_t authored_model_slot) const noexcept = 0;
    virtual void mark(std::uint8_t resolved_slot) noexcept = 0;
    virtual void bind(std::uint8_t resolved_slot, gameplay_actors::EntityId) noexcept = 0;
    virtual void unbind(std::uint8_t resolved_slot) noexcept = 0;
    virtual void retain_pose(std::uint8_t resolved_slot, const actors::Basis&) noexcept = 0;
};
enum class InstanceStatus {
    complete,
    invalid_object,
    explicit_shape,
    missing_grid,
    already_bound,
    pool_full,
    allocation_failed,
    stale_instance,
    closed
};
struct InstanceResult {
    InstanceStatus status{InstanceStatus::complete};
    gameplay_actors::EntityId instance{};
    std::uint8_t missing_proxies{};
};
struct InstanceUpdate {
    InstanceStatus status{InstanceStatus::complete};
    bool geometry_changed{};
};
// Synchronous scene-owner thread only. The dedicated scene-instance EntityStore,
// object owner, proxy owner, grids and bindings outlive this object. Close before
// replacing room objects or retiring the scene-owner domain. No Actor/Session is
// copied or owned here. Geometry/model services consume native IDs and values.
class InteractionOwner::Lifetime final {
  public:
    Lifetime(InteractionOwner&, gameplay_actors::EntityStore& scene_instances, ownership::Proxies&,
             ModelBindings&, const response::Grid& walls, const response::Grid& floors);
    ~Lifetime();
    Lifetime(const Lifetime&) = delete;
    Lifetime& operator=(const Lifetime&) = delete;
    InstanceResult create(const ObjectId&);
    InstanceResult recreate_proxies(const ObjectId&);
    InstanceResult enable(std::int8_t external_id);
    InstanceStatus disable(std::int8_t external_id);
    InstanceUpdate update(gameplay_actors::EntityId);
    InstanceStatus publish_center(const ObjectId&);
    InstanceStatus reset_requests(std::uint8_t full_source_slot);
    std::shared_ptr<ObjectInstance> acquire(gameplay_actors::EntityId) const noexcept;
    const room_geometry::Dynamic& dynamic() const noexcept {
        return dynamic_;
    }
    void rebuild_dynamic();
    void close() noexcept;

  private:
    InteractionOwner& interactions_;
    gameplay_actors::EntityStore& scene_;
    ownership::Proxies& proxies_;
    ModelBindings& bindings_;
    const response::Grid& walls_;
    const response::Grid& floors_;
    struct Owned {
        ObjectId object;
        gameplay_actors::EntityId instance;
    };
    std::array<Owned, 32> owned_;
    room_geometry::Dynamic dynamic_;
    bool closed_{};
    std::optional<ObjectId> external(std::int8_t) const noexcept;
    void refresh_quad(const ownership::Handle&, const Quad&);
};
} // namespace reo::native::gameplay_collision::room_objects
