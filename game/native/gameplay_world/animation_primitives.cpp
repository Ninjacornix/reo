#include "animation_primitives.hpp"
#include "resource_programs.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world::animation_events {
namespace {
[[noreturn]] void unavailable(const char* why) {
    throw std::runtime_error(why);
}
} // namespace
Audio& NativeConsumer::audio() {
    if (!audio_)
        unavailable("Native animation audio consumer unavailable");
    return *audio_;
}
bool NativeConsumer::crosses(Actor& actor, const Event& event, float step, unsigned channel) {
    if (!actor.animation || actor.animation->model() != actor.model)
        unavailable("Native animation event owner unavailable or stale");
    return animation::crosses_frame(
        actor.animation->channel(animation::ModelBank::primary, channel).timing, float(event.frame),
        step, world_.session().clock_mode);
}
void NativeConsumer::attach(Actor& actor, std::uint8_t key) {
    if (!packets_ || !catalog_)
        unavailable("Native animation contact packet/catalog unavailable");
    const auto id = world_.identity_of(actor);
    if (!id)
        unavailable("Native animation contact actor retired or foreign");
    const auto result = packets_->attach(
        *catalog_, 0, key,
        {id, actor, actor.contact, actor.character, actor.position, actor.normalized_marker});
    using S = gameplay_collision::delivery::PacketStatus;
    if (result.status != S::completed && result.status != S::full && result.status != S::no_memory)
        unavailable("Native animation contact packet attachment refused");
}
bool NativeConsumer::resource_present(const Actor& actor) const {
    if (!resources_)
        unavailable("Native animation resource table unavailable");
    const auto id = resources_->slot(actor.selected_resource);
    if (!id)
        unavailable("Native animation resource slot unavailable");
    const auto descriptor = resources_->get(*id);
    if (!descriptor)
        unavailable("Native animation resource identity stale");
    return bool(descriptor->primary);
}
void NativeConsumer::resource_program(Actor& actor, unsigned mode) {
    if (!actor.selected_resource)
        return;
    if (!resource_present(actor))
        return;
    if(!programs_||!programs_->bound_to(world_,*resources_))
        unavailable("Native animation resource program owner unavailable or foreign");
    programs_->select(actor,mode);
}
void NativeConsumer::apply(Actor& actor, const Event& event, float step) {
    const auto id = world_.identity_of(actor);
    const auto lease = world_.resolve(id);
    if (!lease || lease.get() != &actor)
        unavailable("Native animation event actor retired or foreign");
    // The real model action fetches model34->node820 before the crossing gate.
    if (event.kind == EventKind::model_action && !actor.model)
        unavailable("Native animation model action requires the actual model before gate");
    const unsigned channel = event.kind == EventKind::surface_pair_zero ? 0 : 1;
    if (!crosses(actor, event, step, channel))
        return;
    const auto kind = std::uint16_t(event.argument);
    switch (event.kind) {
        case EventKind::surface_pair_one:
        case EventKind::surface_pair_zero: {
            audio().surface(actor, std::bit_cast<std::int8_t>(std::uint8_t(event.argument)));
            const auto cue = 12u + (world_.session().random.request(1) & 1u);
            if (actor.category == 0)
                audio().actor(actor, cue, false);
            return;
        }
        case EventKind::actor_audio:
        case EventKind::alternate_audio: {
            std::uint32_t cue = std::uint16_t(event.auxiliary);
            if (event.argument) {
                const auto range = std::uint16_t(event.argument);
                if (!range)
                    throw std::domain_error(
                        "Original event nonzero range narrowed to zero divisor");
                cue += world_.session().random.request(1) % range;
            }
            const bool alternate = event.kind == EventKind::alternate_audio;
            if (actor.category == (alternate ? 1 : 0))
                audio().actor(actor, cue, alternate);
            return;
        }
        case EventKind::resource_audio:
            if (actor.category < 2)
                audio().resource(actor, std::uint16_t(event.auxiliary));
            return;
        case EventKind::node_audio:
            audio().node(actor, kind);
            return;
        case EventKind::position_audio:
            audio().position(actor, event.argument);
            return;
        case EventKind::resource_callback:
            if (!actor.selected_resource)
                return;
            unavailable("Native animation resource-follow callback task owner not implemented");
        case EventKind::contact_action:
            switch (kind) {
                case 0:
                    actor.notice_flags &= std::uint8_t(~1u);
                    attach(actor, std::uint8_t(event.auxiliary));
                    return;
                case 1: {
                    const auto action = actor.resource_action;
                    const auto flags = actor.notice_flags;
                    const auto key = metadata_.contact_id(action);
                    actor.notice_flags = std::uint8_t(flags & ~1u);
                    attach(actor, key);
                    return;
                }
                case 2:
                    actor.notice_flags &= std::uint8_t(~1u);
                    unavailable("Native animation resource projectile action not implemented");
                case 3:
                    actor.notice_flags |= 1;
                    return;
                default:
                    return;
            }
        case EventKind::model_action:
            switch (kind) {
                case 1:
                    actor.status |= 0x80000000u;
                    notify_equipment_selection(actor, world_.selected_actor);
                    return;
                case 4:
                case 5:
                    if (!resource_present(actor))
                        return;
                    unavailable("Native animation resource model visual consumer not implemented");
                case 6:
                    if (!world_.scenario)
                        unavailable("Native animation scenario identity unavailable");
                    if (*world_.scenario != 0x23 || (std::uint16_t(event.auxiliary) & 0x40))
                        return;
                    unavailable("Native animation scenario surface controller not implemented");
                default:
                    if (kind >= 7)
                        return;
                    unavailable("Native animation model visual consumer not implemented");
            }
        case EventKind::resource_program:
            switch (kind) {
                case 2:
                case 3:
                case 4:
                    resource_program(actor, unsigned(kind) - 1);
                    return;
                case 5:
                    if (actor.auxiliary_status & 0x100000u) {
                        resource_program(actor, 0);
                        actor.auxiliary_status &= ~0x100000u;
                    }
                    return;
                default:
                    return;
            }
    }
    throw std::logic_error("Invalid native animation event kind");
}
} // namespace reo::native::gameplay_world::animation_events
