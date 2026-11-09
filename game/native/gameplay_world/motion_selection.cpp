#include "animation.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
constexpr std::array<animation::PackedMotion, 2> override_descriptors{
    {{{16, 0, 0, 0, 244, 0, 244, 0}}, {{16, 0, 0, 0, 245, 0, 245, 0}}}};
std::int16_t motion(std::uint32_t value) {
    return std::bit_cast<std::int16_t>(std::uint16_t(value));
}
std::uint16_t primary_key(const animation::PackedMotion& p) {
    return std::uint16_t(p.bytes[6] | (unsigned(p.bytes[7]) << 8));
}
animation::MotionIdentity identity(const Actor& a) {
    return {a.status, a.resource_action, a.category, a.motion_subtype, a.character, a.class_marker};
}
std::shared_ptr<Actor> retain(World& world, const actors::EntityId& id) {
    auto actor = world.resolve(id);
    if (!actor || !actor->animation || actor->animation->model() != actor->model)
        throw std::runtime_error("Canonical actor/motion selection owner unavailable or stale");
    return actor;
}
} // namespace
bool WorldAnimation::override_motion(const actors::EntityId& id, std::uint32_t requested,
                                     float initial, float blend) {
    const auto actor = retain(world_, id);
    const auto code = motion(requested);
    const animation::PackedMotion* descriptor{};
    if (code == 0x2050 || code == 0x2051 || code == 0x2002)
        descriptor = &override_descriptors[0];
    else if (code == 0x2003 || code == 0x2005 || (code >= 0x2010 && code <= 0x2015))
        descriptor = &override_descriptors[1];
    else
        return false;
    if (actor->animation->channel(animation::ModelBank::primary, 0).selector !=
        primary_key(*descriptor))
        apply_named(id, *descriptor, initial, blend);
    return true;
}
void WorldAnimation::select(const actors::EntityId& id, std::uint32_t requested, float initial,
                            float blend) {
    const auto actor = retain(world_, id);
    const auto owner = actor->animation;
    auto& state = *owner;
    const auto old_auxiliary = actor->auxiliary_status;
    const auto code = motion(requested);
    if ((actor->status & 0x80) && override_motion(id, requested, initial, blend))
        return;
    actor->previous_motion_class = actor->class_marker;
    if (actor->status & 8)
        actor->previous_motion_class = 3;
    state.motion = code;
    const auto apply_resolved = [&](std::uint32_t selected, float frame) {
        const auto descriptor = descriptors_.resolve(identity(*actor), selected);
        apply(id, descriptor, frame, blend);
    };
    if (code == 0x2050 || code == 0x2051) {
        const auto resource_class = descriptors_.resource_class(actor->resource_action);
        if (resource_class == 1 && actor->class_marker < 2) {
            apply_resolved(std::uint16_t(code), initial);
            if (old_auxiliary & 2)
                actor->auxiliary_status |= 2;
            select(id, 0x2002, 0, 10);
            state.channel(animation::ModelBank::primary, 1).timing.loop = 1;
            state.motion = code;
            return;
        }
        if (actor->class_marker == 1) {
            const auto saved = state.channel(animation::ModelBank::primary, 1);
            actor->class_marker = 0;
            apply_resolved(code == 0x2050 ? 0x200c : 0x200d, initial);
            actor->class_marker = 1;
            if (saved.selector == 0x82) {
                state.channel(animation::ModelBank::primary, 1) = saved;
                return;
            }
        }
        if (old_auxiliary & 2)
            actor->auxiliary_status |= 2;
        apply_resolved(std::uint16_t(code), initial);
        return;
    }
    if (code == 0x2003 && actor->character == 5 && initial < 1 &&
        descriptors_.resource_class(actor->resource_action) == 1 && actor->class_marker < 2) {
        apply_resolved(std::uint16_t(code), 62);
        return;
    }
    apply_resolved(std::uint16_t(code), initial);
}
void WorldAnimation::select_blended(const actors::EntityId& id, std::uint32_t primary,
                                    std::uint32_t secondary, float weight) {
    const auto actor = retain(world_, id);
    const auto owner = actor->animation;
    auto& state = *owner;
    actor->previous_motion_class = actor->class_marker;
    if (actor->status & 8)
        actor->previous_motion_class = actor->class_marker = 3;
    select(id, std::uint16_t(primary), 0, 0);
    actor->root_motion_delta = {};
    const auto packed = descriptors_.resolve(identity(*actor), std::uint16_t(secondary));
    const auto decoded = descriptors_.unpack(identity(*actor), packed);
    state.motion = motion(secondary);
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
} // namespace reo::native::gameplay_world
