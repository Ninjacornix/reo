#include "contacts.hpp"
#include <stdexcept>
namespace reo::native::gameplay_contact_world {
namespace {
std::shared_ptr<world::World> required(std::shared_ptr<world::World> value) {
    if (!value)
        throw std::invalid_argument("Native contact invocation requires a World owner");
    return value;
}
delivery::View view(actors::EntityId id, world::Actor& actor) {
    return {id, actor, actor.contact, actor.character, actor.position, actor.normalized_marker};
}
} // namespace
Invocation::Invocation(std::shared_ptr<world::World> owner, std::shared_ptr<RoomInvocation> room)
    : world_(required(std::move(owner))), room_(std::move(room)),
      room_id_(room_ ? room_->identity() : RoomId{}), poses_(*world_) {}
std::shared_ptr<world::Actor> Invocation::resolve(const actors::EntityId& id) {
    auto actor = world_->resolve(id);
    if (!actor)
        return {};
    for (const auto& retained : actors_)
        if (retained.id == id)
            return actor;
    actors_.push_back({id, actor});
    return actor;
}
std::shared_ptr<world::Actor> Invocation::resolve(delivery::PacketOwner candidate) {
    auto actor = resolve(candidate.contact.id);
    if (!actor)
        return {};
    const auto& supplied = candidate.contact;
    if (&supplied.actor != static_cast<actors::HitActor*>(actor.get()) ||
        &supplied.contact != &actor->contact || &supplied.character != &actor->character ||
        &supplied.cooldown != &actor->normalized_marker ||
        &supplied.position.x != &actor->position.x || &supplied.position.y != &actor->position.y ||
        &supplied.position.z != &actor->position.z)
        return {};
    return actor;
}
std::optional<delivery::PacketOwner> Invocation::owner(const actors::EntityId& id) {
    auto actor = resolve(id);
    if (!actor)
        return {};
    return delivery::PacketOwner{view(id, *actor), actor->active};
}
bool Invocation::enroll(const actors::EntityId& id, gameplay_collision::hit_regions::Queue& queue) {
    auto actor = owner(id);
    return actor && delivery::prepare(actor->contact, queue);
}
delivery::CreatedPacket Invocation::attach(delivery::Packets& packets,
                                           const delivery::Catalog& catalog, std::uint8_t bank,
                                           std::int32_t ordinal, const actors::EntityId& id) {
    auto actor = owner(id);
    if (!actor)
        return {delivery::PacketStatus::missing_actor, {}};
    return packets.attach(catalog, bank, ordinal, actor->contact);
}
std::optional<delivery::ShapePose> Invocation::pose(delivery::PacketOwner candidate) {
    auto actor = resolve(candidate);
    if (!actor || !actor->collision.pose_ready)
        return {};
    std::span<const gameplay_collision::actors::Basis> joints;
    auto model = actor->model;
    auto snapshot = model ? model->retain() : nullptr;
    if (snapshot) {
        for (const auto& cached : pose_leases_) {
            if (cached.id == candidate.contact.id && cached.model == model &&
                cached.snapshot == snapshot) {
                joints = cached.joints->joints;
                break;
            }
        }
        if (joints.empty()) {
            auto retained = poses_.retain(candidate.contact.id, *actor);
            if (!retained)
                return {};
            joints = retained->joints;
            // Retain actual model and snapshot as well as converted joints.
            // A callback can replace/rebuild the model without invalidating
            // old views; a new snapshot is converted on the next query.
            pose_leases_.push_back({candidate.contact.id, model, snapshot, retained});
        }
    }
    // Root geometry does not read a model. An absent/unpublished model gives
    // an empty joint span: root queries work, selected joint queries refuse.
    return delivery::ShapePose{actor->collision.basis, joints, actor->projectile_contact.point,
                               actor->projectile_contact.normal, actor->sampled_surface_valid};
}
bool Invocation::room_current() const noexcept {
    return room_ && room_id_ && room_->current(room_id_) && room_->identity() == room_id_ &&
           world_->room == room_->room_number();
}
std::optional<delivery::ShapeScene> Invocation::scene(delivery::PacketOwner candidate) {
    if (!resolve(candidate) || !room_current())
        return {};
    auto programs = room_->programs();
    if (!programs)
        return {};
    const auto& geometry = room_->geometry();
    auto filter = geometry.filter;
    for (std::uint8_t i = 0; i < 16; ++i) {
        auto channel = programs->channel(i);
        if (!channel)
            return {};
        filter.slots[i].state = channel->gate;
    }
    if (!room_current())
        return {};
    program_leases_.push_back(programs);
    return delivery::ShapeScene{geometry.walls, geometry.floors, geometry.dynamic, filter,
                                *programs};
}
delivery::ServiceReport Invocation::run(delivery::Packets& packets,
                                        gameplay_collision::hit_regions::Queue& targets,
                                        const delivery::Tables& tables, delivery::Effects& effects,
                                        gameplay_effects::WorkBackend& work,
                                        delivery::ImpactParameters& parameters,
                                        delivery::ShapeDebug& debug, delivery::PacketEvents& events,
                                        ScanSettings settings) {
    if (started_)
        return {delivery::ServiceStatus::query_failed, delivery::Status::invalid_roster};
    if (!work.bound_to(world_->session().random))
        return {delivery::ServiceStatus::query_failed, delivery::Status::unadmitted_content};
    started_ = true;
    // Every consumer, including constructor and population policies, must bind
    // this same canonical session RNG. No alternate shadow session is created.
    delivery::Context context{*this,
                              tables,
                              world_->session().random,
                              effects,
                              settings.class_masks,
                              settings.special_mode,
                              settings.difficulty,
                              settings.obstacles,
                              settings.direction_policy};
    delivery::ContactVisuals visuals(work, world_->session().random, parameters);
    delivery::ImpactShapeEffects shape_effects(*this, visuals, debug);
    delivery::ShapePipeline shapes(context, targets, *this, *this, shape_effects);
    return delivery::service(packets, *this, world_->session(), targets, shapes, events);
}
std::unique_ptr<Invocation> retain(std::shared_ptr<world::World> owner, RoomResources& resources) {
    if (!owner)
        return {};
    auto room = resources.retain(owner->room);
    if (!room)
        return {};
    const auto id = room->identity();
    if (!id || !room->current(id) || room->room_number() != owner->room)
        return {};
    return std::make_unique<Invocation>(std::move(owner), std::move(room));
}
} // namespace reo::native::gameplay_contact_world
