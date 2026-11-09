#include "delivery.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_collision::delivery {
namespace {
std::uint8_t byte(std::span<const std::byte> bytes, std::size_t at) {
    return std::to_integer<std::uint8_t>(bytes[at]);
}
std::int16_t half(std::span<const std::byte> bytes, std::size_t at) {
    return std::bit_cast<std::int16_t>(
        std::uint16_t(byte(bytes, at) | (std::uint16_t(byte(bytes, at + 1)) << 8)));
}
std::uint32_t truncate(float value) noexcept {
    // The admitted native FP32 profile uses original fixed-truncation CVT.W.S.
    if (!std::isfinite(value) || value >= 2147483648.0f || value < -2147483648.0f)
        return 0x80000000u;
    return std::bit_cast<std::uint32_t>(std::int32_t(value));
}
std::int16_t low_signed(float value) noexcept {
    return std::bit_cast<std::int16_t>(std::uint16_t(truncate(value)));
}
bool boosted_id(std::uint8_t value) noexcept {
    switch (value) {
        case 0x22:
        case 0x23:
        case 0x26:
        case 0x27:
        case 0x29:
        case 0x2a:
        case 0x35:
        case 0x36:
        case 0x37:
            return true;
        default:
            return false;
    }
}
Calculated calculate(View first, View second, const Template& t, float factor, const Tables& tables,
                     bool category) {
    if (t.value_id >= 200)
        return {
            Status::completed,
            {category ? low_signed(float(t.base) * second.contact.damage_scale) : t.base, t.kind}};
    if (t.value_id >= 128)
        return {};
    const auto a = Vec3(first.position), b = Vec3(second.position);
    const float x = a.x - b.x, y = a.y - b.y, z = a.z - b.z;
    const float distance = std::sqrt((x * x + y * y) + z * z);
    const unsigned bin = distance < 200 ? 0 : distance < 600 ? 1 : 2;
    Value selected{100, 0};
    if (category) {
        const auto& admitted = tables.categories[first.actor.slot];
        if (!admitted.admitted)
            return {Status::unadmitted_content, {}};
        if (admitted.entries)
            selected = (*admitted.entries)[t.value_id].bins[bin];
    } else {
        if (!tables.flat)
            return {Status::unadmitted_content, {}};
        selected = (*tables.flat)[t.value_id].bins[bin];
    }
    const auto weighted = std::bit_cast<std::int16_t>(std::uint16_t(
        (std::int32_t(selected.amount) * std::int32_t(tables.weights[t.value_id])) / 100));
    float base = float(weighted);
    if (second.actor.category == 0 && second.character == 1 && boosted_id(t.value_id))
        base = float(low_signed(1.5f * base));
    float result = (base * second.contact.damage_scale) * factor;
    if (result < -32767.0f)
        result = -32767.0f;
    else if (!(result <= 32767.0f))
        result = 32767.0f;
    if (!(factor <= 1) && selected.kind < 2)
        ++selected.kind;
    selected.amount = low_signed(result);
    return {Status::completed, selected};
}
} // namespace
Identity identity(View actor) noexcept {
    return {actor.actor.category,
            actor.actor.category == 2 ? actor.character : actor.contact.authored_id};
}
bool prepare(View actor, hit_regions::Queue& queue) noexcept {
    actor.actor.damage_word = 0;
    actor.actor.progression_amount = 0;
    actor.contact.priority = 0;
    actor.actor.pending_hit = 0;
    actor.contact.serial = 0;
    if (actor.cooldown) {
        if (actor.cooldown != 255)
            --actor.cooldown;
        return false;
    }
    return actor.contact.regions.present() && queue.add(actor.id);
}
Template import_template(std::span<const std::byte> bytes) {
    if (bytes.size() < 32)
        throw std::invalid_argument("Truncated native contact response descriptor");
    return {half(bytes, 2),    half(bytes, 0x14), byte(bytes, 4),    byte(bytes, 6),
            byte(bytes, 7),    byte(bytes, 8),    byte(bytes, 0xa),  byte(bytes, 0xb),
            byte(bytes, 0xd),  byte(bytes, 0xf),  byte(bytes, 0x11), byte(bytes, 0x12),
            byte(bytes, 0x13), byte(bytes, 0x16), byte(bytes, 0x17), byte(bytes, 0x18),
            byte(bytes, 0x19), byte(bytes, 0x1a)};
}
Status record_provenance(View receiver, const Packet& packet, Actors& actors) {
    auto source = actors.find(packet.source);
    if (!source)
        return Status::missing_actor;
    auto owner = source->contact.related ? actors.find(source->contact.related) : source;
    auto receiver_related =
        receiver.contact.related ? actors.find(receiver.contact.related) : std::optional<View>{};
    if (!owner || (receiver.contact.related && !receiver_related))
        return Status::missing_actor;
    receiver.actor.special_kind = packet.bank;
    const auto from = identity(*source);
    receiver.actor.source_kind = from.category;
    receiver.actor.source_slot = from.token;
    receiver.contact.source_related = source->contact.related ? identity(*owner) : Identity{};
    ++owner->contact.serial;
    owner->contact.recipient = identity(receiver);
    owner->contact.related_recipient =
        receiver_related ? Identity{owner->actor.category, receiver_related->actor.category == 2
                                                               ? owner->character
                                                               : owner->contact.authored_id}
                         : Identity{};
    if (owner->id != source->id) {
        source->contact.serial = owner->contact.serial;
        source->contact.recipient = owner->contact.recipient;
        source->contact.related_recipient = owner->contact.related_recipient;
    }
    return Status::completed;
}
Status restore_provenance(const Packet& packet, Actors& actors) {
    auto source = actors.find(packet.source);
    if (!source)
        return Status::missing_actor;
    auto owner = source->contact.related ? actors.find(source->contact.related) : source;
    if (!owner)
        return Status::missing_actor;
    owner->contact.serial = packet.event;
    owner->contact.recipient = {};
    owner->contact.related_recipient = {};
    if (owner->id != source->id) {
        source->contact.serial = owner->contact.serial;
        source->contact.recipient = {};
        source->contact.related_recipient = {};
    }
    return Status::completed;
}
void roll_response(View actor, const Template& t, gameplay_session::Random& random) noexcept {
    if (random.request(1) % 100 < t.probability)
        actor.actor.response_flags |= 4;
}
void convert_response(View actor) noexcept {
    if ((actor.actor.category == 2 || actor.actor.category == 3) &&
        actor.contact.response_code == 3)
        actor.contact.response_code = 9;
}
std::uint8_t pair_kind(const gameplay_actors::HitActor* source,
                       const gameplay_actors::HitActor& target) noexcept {
    if (!source)
        return 99;
    if (source->category == 0)
        return target.category == 2 ? 0 : target.category == 0 ? 2 : 99;
    if (source->category == 2)
        return target.category == 0 ? 1 : target.category == 2 ? 3 : 99;
    return 99;
}
float multiplier(View actor, const Packet& packet, const Tables& tables,
                 gameplay_session::Random& random, Feedback& feedback) {
    const float initial = packet.key < 100 ? tables.probabilities[packet.key] : 0;
    if (initial == 0)
        return 1;
    float chance = initial + actor.contact.probability_bonus;
    if (!(chance < 100))
        chance = 100;
    if (chance < 0)
        chance = 0;
    if (!(actor.actor.auxiliary_status & 0x800) && !(float(random.request(1) % 100) < chance))
        return 1;
    if (feedback.authority(actor))
        feedback.vibration(actor, 8);
    return 2;
}
Calculated category_value(View first, View second, const Template& t, float factor,
                          const Tables& tables) {
    return calculate(first, second, t, factor, tables, true);
}
Calculated flat_value(View first, View second, const Template& t, float factor,
                      const Tables& tables) {
    return calculate(first, second, t, factor, tables, false);
}
} // namespace reo::native::gameplay_collision::delivery
