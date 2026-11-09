#include "animation_events.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world::animation_events {
namespace {
struct ActionMetadata {
    std::uint32_t flags;
    std::uint8_t contact;
};
#include "animation_event_metadata.inc"
const ActionMetadata& action(std::uint16_t index) {
    if (index >= metadata.size())
        throw std::out_of_range("Native File1 animation action metadata profile");
    return metadata[index];
}
struct Context {
    Actor& actor;
    animation::Playback& playback;
    const Metadata& metadata;
    Consumer& consumer;
    float step;
    void emit(const Event& event) {
        consumer.apply(actor, event, step);
        if (actor.animation.get() != &playback || actor.animation->model() != actor.model)
            throw std::runtime_error("Native animation owner replaced during event consumer");
    }
};
#include "player_event_schedule.inc"
} // namespace
std::uint32_t File1Metadata::action_flags(std::uint16_t i) const {
    return action(i).flags;
}
std::uint8_t File1Metadata::contact_id(std::uint16_t i) const {
    return action(i).contact;
}
Family family(std::uint8_t category, bool visible, std::uint8_t type, std::uint8_t kind,
              std::uint8_t slot) noexcept {
    if (category < 2) {
        if (kind != 255) {
            constexpr std::array normal{
                Family::player_zero,    Family::player_one,     Family::civilian_two,
                Family::civilian_three, Family::civilian_four,  Family::civilian_five,
                Family::civilian_six,   Family::civilian_seven, Family::civilian_eight,
                Family::civilian_nine,  Family::civilian_ten};
            return slot < normal.size() ? normal[slot] : Family::none;
        }
        switch (slot) {
            case 0:
                return Family::extended_zero;
            case 1:
                return Family::extended_one;
            case 2:
                return Family::extended_two;
            case 0xc:
                return Family::extended_twelve;
            case 0x10:
                return Family::extended_sixteen;
            case 0x12:
                return Family::extended_eighteen;
            case 0x14:
                return Family::extended_twenty;
            case 0x16:
                return Family::extended_twenty_two;
            case 0x1a:
                return Family::extended_twenty_six;
            case 0x1b:
                return Family::extended_twenty_seven;
            case 0x1d:
                return Family::extended_twenty_nine;
            case 0x24:
                return Family::extended_thirty_six;
            case 0x2b:
                return Family::extended_forty_three;
            default:
                return Family::none; // Includes actual one-instruction5/23 no-ops.
        }
    }
    if (category != 2 || !visible)
        return Family::none;
    switch (type) {
        case 0:
            return Family::actor_zero;
        case 1:
            return Family::actor_one;
        case 2:
            return Family::actor_two;
        case 4:
            return Family::actor_four;
        case 5:
            return Family::actor_five;
        case 6:
            return Family::actor_six;
        case 7:
            return Family::actor_seven;
        case 9:
            return Family::actor_nine;
        case 0xa:
            return Family::actor_ten;
        case 0x12:
            return Family::actor_eighteen;
        case 0x13:
            return Family::actor_nineteen;
        case 0x14:
            return Family::actor_twenty;
        case 0x16:
            return Family::actor_twenty_two;
        case 0x17:
            return Family::actor_twenty_three;
        case 0x1a:
            return Family::actor_twenty_six;
        case 0x1b:
            return Family::actor_twenty_seven;
        case 0x1d:
            return Family::actor_twenty_nine;
        case 0x1e:
            return Family::actor_thirty;
        case 0x24:
            return Family::actor_thirty_six;
        case 0x29:
            return Family::actor_forty_one;
        case 0x2b:
            return Family::actor_forty_three;
        case 0x37:
            return Family::actor_fifty_five;
        case 0x3b:
            return Family::actor_fifty_nine;
        default:
            return Family::none;
    }
}
void run_player(Family selected, Actor& actor, const Metadata& metadata, Consumer& consumer,
                float step) {
    if (selected != Family::player_zero && selected != Family::player_one)
        throw std::domain_error("Native animation event family consumer not implemented");
    const auto owner = actor.animation;
    if (!owner || owner->model() != actor.model)
        throw std::runtime_error("Native canonical animation/model unavailable or stale");
    Context ctx{actor, *owner, metadata, consumer, step};
    const auto first = owner->channel(animation::ModelBank::primary, 0).selector;
    if (selected == Family::player_zero)
        lower_zero(ctx, first);
    else
        lower_one(ctx, first);
    const auto second = owner->channel(animation::ModelBank::primary, 1).selector;
    if (selected == Family::player_zero)
        upper_zero(ctx, second);
    else
        upper_one(ctx, second);
}
void Prelude::run(World& world, Actor& actor, float step) {
    if (&world != &world_)
        throw std::invalid_argument("Native animation prelude belongs to another World");
    if (actor.category > 2 || (actor.category == 2 && !actor.visible))
        return;
    std::uint8_t kind{}, slot{};
    if (actor.category < 2) {
        if (!actor.animation || actor.animation->model() != actor.model)
            throw std::runtime_error("Native animation family owner unavailable or stale");
        kind = actor.animation->source_kind;
        slot = actor.animation->source_slot;
    }
    const auto selected = family(actor.category, actor.visible, actor.slot, kind, slot);
    if (selected == Family::none)
        return;
    run_player(selected, actor, metadata_, consumer_, step);
}
} // namespace reo::native::gameplay_world::animation_events
