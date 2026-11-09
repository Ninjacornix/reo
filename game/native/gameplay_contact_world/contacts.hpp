#pragma once
#include "../gameplay_collision/impact_populations.hpp"
#include "../gameplay_collision/impact_shape_effects.hpp"
#include "../gameplay_world/collision.hpp"
#include "../gameplay_world/model_poses.hpp"
#include "../gameplay_scenario/scene_matrix_programs.hpp"
namespace reo::native::gameplay_contact_world {
namespace delivery = gameplay_collision::delivery;
namespace world = gameplay_world;
namespace actors = gameplay_actors;
struct RoomId {
    actors::EntityId entity;
    explicit operator bool() const noexcept {
        return bool(entity);
    }
    friend bool operator==(const RoomId&, const RoomId&) = default;
};
// Required actual room-resource invocation. Implementations retain the native
// immutable geometry/dynamic storage and all borrowed matrix-program backing
// owners (controls/models/bindings/flags/session), even after retirement.
// current() rejects retired/reused identities; retained data stays readable.
// No positive implementation or runtime room installer is supplied here.
class RoomInvocation {
  public:
    virtual ~RoomInvocation() = default;
    virtual RoomId identity() const noexcept = 0;
    virtual bool current(RoomId) const noexcept = 0;
    virtual std::uint16_t room_number() const noexcept = 0;
    virtual const world::CollisionRoom& geometry() const = 0;
    virtual std::shared_ptr<gameplay_scenario::SceneMatrixPrograms> programs() const = 0;
};
class RoomResources {
  public:
    virtual ~RoomResources() = default;
    virtual std::shared_ptr<RoomInvocation> retain(std::uint16_t room) = 0;
};
struct ScanSettings {
    std::span<const std::uint8_t> class_masks;
    bool special_mode{};
    std::uint8_t difficulty{};
    const gameplay_collision::spatial::Occlusion* obstacles{};
    delivery::DirectionPolicy direction_policy{delivery::DirectionPolicy::require_known_tail};
};
// One synchronous native contact invocation, not a long-lived cache. Every
// lookup rechecks World generation before retaining canonical actor references.
// Model snapshots and room/program leases last through all synchronous effects.
class Invocation final : public delivery::PacketActors,
                         public delivery::PacketPoses,
                         public delivery::PacketScenes {
  public:
    Invocation(std::shared_ptr<world::World>, std::shared_ptr<RoomInvocation>);
    Invocation(const Invocation&) = delete;
    Invocation& operator=(const Invocation&) = delete;
    std::optional<delivery::PacketOwner> owner(const actors::EntityId&) override;
    bool enroll(const actors::EntityId&, gameplay_collision::hit_regions::Queue&);
    delivery::CreatedPacket attach(delivery::Packets&, const delivery::Catalog&, std::uint8_t bank,
                                   std::int32_t ordinal, const actors::EntityId&);
    std::optional<delivery::ShapePose> pose(delivery::PacketOwner) override;
    std::optional<delivery::ShapeScene> scene(delivery::PacketOwner) override;
    delivery::ServiceReport run(delivery::Packets&, gameplay_collision::hit_regions::Queue&,
                                const delivery::Tables&, delivery::Effects&,
                                gameplay_effects::WorkBackend&, delivery::ImpactParameters&,
                                delivery::ShapeDebug&, delivery::PacketEvents&, ScanSettings);

  private:
    struct ActorLease {
        actors::EntityId id;
        std::shared_ptr<world::Actor> actor;
    };
    struct PoseLease {
        actors::EntityId id;
        std::shared_ptr<animation::Instance> model;
        std::shared_ptr<const animation::JointSnapshot> snapshot;
        std::shared_ptr<const world::JointPose> joints;
    };
    std::shared_ptr<world::World> world_;
    std::shared_ptr<RoomInvocation> room_;
    RoomId room_id_;
    world::WorldModelPoses poses_;
    std::vector<ActorLease> actors_;
    std::vector<PoseLease> pose_leases_;
    std::vector<std::shared_ptr<gameplay_scenario::SceneMatrixPrograms>> program_leases_;
    bool started_{};
    std::shared_ptr<world::Actor> resolve(const actors::EntityId&);
    std::shared_ptr<world::Actor> resolve(delivery::PacketOwner);
    bool room_current() const noexcept;
};
std::unique_ptr<Invocation> retain(std::shared_ptr<world::World>, RoomResources&);
} // namespace reo::native::gameplay_contact_world
