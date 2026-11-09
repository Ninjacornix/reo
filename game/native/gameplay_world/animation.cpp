#include "animation.hpp"
#include <cmath>
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
float finite(float value) {
    if (!std::isfinite(value))
        throw std::domain_error("Native descriptor application finite profile required");
    return value;
}
animation::Playback& playback(Actor& actor) {
    if (!actor.animation || actor.animation->model() != actor.model)
        throw std::runtime_error("Canonical native animation/model owner unavailable or stale");
    return *actor.animation;
}
animation::MotionIdentity identity(const Actor& actor) {
    return {actor.status,         actor.resource_action, actor.category,
            actor.motion_subtype, actor.character,       actor.class_marker};
}
animation::RootMotionRef root(Actor& actor) {
    return {actor.root_motion_delta.x, actor.root_motion_delta.y, actor.root_motion_delta.z};
}
std::shared_ptr<Actor> retain(World& world, const actors::EntityId& id) {
    auto actor = world.resolve(id);
    if (!actor)
        throw std::runtime_error("Native animation actor foreign or retired");
    return actor;
}
} // namespace
void WorldAnimation::apply_named(const actors::EntityId& id,
                                 const animation::PackedMotion& descriptor, float initial,
                                 float blend) {
    const auto actor = retain(world_, id);
    playback(*actor).motion = std::bit_cast<std::int16_t>(
        std::uint16_t(descriptor.bytes[6] | (unsigned(descriptor.bytes[7]) << 8)));
    apply(id, descriptor, initial, blend);
}
void WorldAnimation::apply(const actors::EntityId& id, const animation::PackedMotion& descriptor,
                           float initial, float blend) {
    const auto actor = retain(world_, id);
    const auto owner = actor->animation;
    auto& state = playback(*actor);
    const auto decoded = descriptors_.unpack(identity(*actor), descriptor);
    if (actor->category > 1)
        throw std::domain_error(
            "Original primary descriptor body-profile registers unassigned for this category");
    const auto profile = actor->category == 0 ? actor->character : actor->motion_subtype;
    const auto body = profiles_.body(profile, decoded.offset_selector);
    if (world_.resolve(id) != actor || actor->animation != owner || owner->model() != actor->model)
        throw std::runtime_error("Native motion owner replaced during body metadata observation");
    actor->collision.body_definition = body;
    const auto shape = profiles_.shape(profile, decoded.shape_selector);
    if (world_.resolve(id) != actor || actor->animation != owner || owner->model() != actor->model)
        throw std::runtime_error("Native motion owner replaced during shape metadata observation");
    auto& collision = actor->collision;
    collision.interpolation_target = shape.target;
    collision.interpolation_step = {finite(shape.target.center.x - collision.local_center.x),
                                    finite(shape.target.center.y - collision.local_center.y),
                                    finite(shape.target.center.z - collision.local_center.z)};
    collision.interpolation_ticks = shape.ticks;
    if (shape.ticks) {
        const float count = float(shape.ticks);
        collision.interpolation_step.x = finite(collision.interpolation_step.x / count);
        collision.interpolation_step.y = finite(collision.interpolation_step.y / count);
        collision.interpolation_step.z = finite(collision.interpolation_step.z / count);
    } else {
        collision.local_center = shape.target.center;
        collision.radius = shape.target.radius;
    }
    for (unsigned channel = 0; channel < 2; ++channel) {
        auto& flags = state.channel(animation::ModelBank::primary, channel).timing.flags;
        if (flags & 128)
            flags &= 127;
        else if ((channel ? decoded.channel_one : decoded.channel_zero) != 0)
            flags = 0;
    }
    if (decoded.flags)
        state.or_packed_primary_flags(decoded.flags);
    const auto resource = resources_.resolve(id, decoded.family);
    if (!resource)
        return;
    if (actor->category == 0 && (state.progress_flags & 0x20))
        blend = finite(blend + 13.f);
    if (actor->auxiliary_status & 2) {
        actor->auxiliary_status &= ~2u;
        blend = 0;
    }
    const animation::MotionClock clock{world_.session().clock_mode, actor->category,
                                       actor->motion_rate};
    (void)state.configure(*resource, std::int32_t(decoded.channel_one), 1,
                          decoded.channel_one
                              ? initial
                              : state.channel(animation::ModelBank::primary, 1).timing.frame,
                          blend, clock, root(*actor));
    (void)state.configure(*resource, std::int32_t(decoded.channel_zero), 0,
                          decoded.channel_zero
                              ? initial
                              : state.channel(animation::ModelBank::primary, 0).timing.frame,
                          blend, clock, root(*actor));
    state.channel(animation::ModelBank::primary, 1).selector = decoded.channel_one;
    state.channel(animation::ModelBank::primary, 0).selector = decoded.channel_zero;
    for (unsigned channel = 2; channel < 5; ++channel)
        state.clear_primary(std::uint16_t(channel));
    for (unsigned channel = 2; channel < 5; ++channel)
        (void)state.configure(*resource, std::int32_t(decoded.channel_one), std::uint16_t(channel),
                              initial, blend, clock, root(*actor));
    if (actor->category == 0) {
        state.progress_threshold =
            actor->motion_style ? decoded.alternate_threshold : decoded.threshold;
        state.progress_flags = 0;
    }
}
void WorldAnimation::apply_blended(const actors::EntityId& id,
                                   const animation::PackedMotion& primary,
                                   const animation::PackedMotion& secondary, float weight) {
    apply(id, primary, 0, 0);
    const auto actor = retain(world_, id);
    auto& state = playback(*actor);
    root(*actor).set({});
    const auto decoded = descriptors_.unpack(identity(*actor), secondary);
    const auto resource = resources_.resolve(id, decoded.family);
    if (!resource)
        return;
    (void)state.bind_plain(animation::ModelBank::secondary, *resource, decoded.channel_one, 1, 0);
    (void)state.bind_plain(animation::ModelBank::secondary, *resource, decoded.channel_zero, 0, 0);
    state.channel(animation::ModelBank::primary, 0).blend_position =
        state.channel(animation::ModelBank::primary, 1).blend_position = weight;
    const float other = animation::motion_complement(weight);
    state.blend_banks(1, weight, other);
    state.blend_banks(0, weight, other);
}
std::int8_t WorldAnimation::tick(const actors::EntityId& id, float step) {
    const auto actor = retain(world_, id);
    prelude_.run(world_, *actor, step);
    if (world_.resolve(id) != actor)
        throw std::runtime_error("Native animation actor retired during required prelude");
    auto& state = playback(*actor);
    return state.advance_channels_after_prelude(
        state.channel_count, step, world_.session().clock_mode, actor->category,
        actor->slot == world_.selected_actor, actor->input.held, root(*actor));
}
std::int8_t WorldAnimation::tick_blended(const actors::EntityId& id, float step, float weight) {
    const auto actor = retain(world_, id);
    prelude_.run(world_, *actor, step);
    if (world_.resolve(id) != actor)
        throw std::runtime_error("Native animation actor retired during required prelude");
    auto& state = playback(*actor);
    return state.advance_four_after_prelude(step, weight, world_.session().clock_mode,
                                            actor->category, actor->slot == world_.selected_actor,
                                            actor->input.held);
}
} // namespace reo::native::gameplay_world
