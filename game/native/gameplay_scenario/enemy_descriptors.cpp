#include "enemy_descriptors.hpp"
#include "../gameplay_world/world.hpp"
#include <bit>
#include <limits>

namespace reo::native::gameplay_scenario {
namespace {
#include "enemy_spawn_profiles.inc"

std::uint32_t word(std::span<const std::byte> bytes,std::size_t offset) noexcept {
    return std::to_integer<std::uint32_t>(bytes[offset]) |
        std::to_integer<std::uint32_t>(bytes[offset+1])<<8 |
        std::to_integer<std::uint32_t>(bytes[offset+2])<<16 |
        std::to_integer<std::uint32_t>(bytes[offset+3])<<24;
}
std::int32_t coordinate(std::span<const std::byte> bytes,std::size_t offset) noexcept {
    const auto rounded=float(std::bit_cast<std::int32_t>(word(bytes,offset)));
    if (rounded>=2147483648.f) return std::numeric_limits<std::int32_t>::max();
    return std::int32_t(rounded);
}
}

EnemyImported EnemyDescriptors::import(std::span<const std::byte> bytes,
    gameplay_world::Session& session,bool offline,std::uint8_t row) noexcept {
    if (bytes.size()<4) return {};
    const auto header=std::bit_cast<std::int32_t>(word(bytes,0));
    if (header<4) return {};
    std::size_t offset=std::uint32_t(header)&~3u;
    if (offset>bytes.size()) return {EnemyImportStatus::malformed,0,offset};
    EnemyDescriptors staged;
    staged.expiry_.fill(255);
    auto random=session.random;
    auto controls=session.ai_control_requests;
    auto seed=std::uint8_t(random.request(0)&7u);
    const auto group=offline ? row&3u : random.request(2)&3u;
    const auto mask=std::uint8_t(1u<<(row&31u));
    std::size_t count=0;
    std::uint16_t previous_room=255;
    while (offset<=bytes.size() && bytes.size()-offset>=3) {
        if (bytes[offset+2]==std::byte{255}) {
            staged.count_=std::uint8_t(count);
            staged.assignments_.reset();
            *this=staged;
            session.random=random;
            session.ai_control_requests=controls;
            return {EnemyImportStatus::completed,count,offset};
        }
        if (bytes.size()-offset<96) return {EnemyImportStatus::malformed,count,offset};
        const auto source=bytes.subspan(offset,96);
        const auto byte=[&](std::size_t index) { return std::to_integer<std::uint8_t>(source[index]); };
        if (byte(0x1e)!=group || !(byte(0x49)&mask)) { offset+=96;continue; }
        if (count==capacity) return {EnemyImportStatus::full,count,offset};
        auto& descriptor=staged.records_[count];
        descriptor.ordinal=std::uint8_t(count);
        descriptor.family=byte(2);
        descriptor.variant=byte(3);
        descriptor.condition=byte(0x22);
        descriptor.parameter4=byte(4);
        descriptor.orientation={word(source,8),word(source,12)};
        descriptor.position={coordinate(source,0x10),coordinate(source,0x14),coordinate(source,0x18)};
        descriptor.room=byte(0x1c);
        if (descriptor.room>=128) return {EnemyImportStatus::unavailable,count,offset};
        descriptor.parameter1f=byte(0x1f);
        descriptor.parameter20=byte(0x20);
        descriptor.parameter5=byte(5);
        descriptor.parameter21=std::bit_cast<std::int8_t>(byte(0x21));
        descriptor.parameter23=byte(0x23);
        descriptor.parameter24=byte(0x24);
        descriptor.parameter25=byte(0x25);
        descriptor.parameter26=byte(0x26);
        for (unsigned index=0;index<10;++index) descriptor.auxiliary_ids[index]=byte(0x27+index);
        const auto health_selector=byte(0x33);
        std::int16_t health=32767;
        if (health_selector<8) {
            if (descriptor.family>=62) return {EnemyImportStatus::unavailable,count,offset};
            const auto index=32u*descriptor.family+8u*(row&3u)+health_selector;
            health=offline ? offline_health[index] : ordinary_health[index];
        }
        descriptor.health=descriptor.maximum=health;
        descriptor.route_wait=byte(0x44);
        descriptor.owner_mode=byte(0x1d);
        descriptor.parameter31=byte(0x31);
        descriptor.parameter32=byte(0x32);
        for (unsigned index=0;index<13;++index) descriptor.parameters34_to40[index]=byte(0x34+index);
        descriptor.parameters42_to43={byte(0x42),byte(0x43)};
        for (unsigned index=0;index<3;++index) {
            const auto id=byte(0x45+index);
            descriptor.linked_ids[index]=id ? std::uint8_t(id+49u) : 0;
        }
        descriptor.parameter48=byte(0x48);
        descriptor.choice_mask=byte(0x49);
        descriptor.mapped_parameter=spawn_parameters[byte(0x4a)];
        descriptor.route_selector=byte(0x4b);
        if (previous_room!=descriptor.room) {
            previous_room=descriptor.room;
            staged.room_starts_[descriptor.room]=std::uint8_t(count);
        }
        if (descriptor.owner_mode) (void)controls.register_control(2,std::uint32_t(count));
        ++staged.room_counts_[descriptor.room];
        descriptor.route_seed=seed;
        seed=std::uint8_t((seed+1u)&7u);
        if (descriptor.owner_mode) {
            const auto route=session.enemy_routes.position(session.scenario,descriptor.family,
                                                           descriptor.room,descriptor.route_selector);
            if (!route.available) return {EnemyImportStatus::unavailable,count,offset};
            descriptor.route_position=route.position;
        }
        ++count;
        offset+=96;
    }
    return {EnemyImportStatus::malformed,count,offset};
}
}
