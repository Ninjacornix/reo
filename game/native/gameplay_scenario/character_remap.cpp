#include "character_remap.hpp"
#include "../gameplay_world/world.hpp"
#include <bit>

namespace reo::native::gameplay_scenario {
bool character_remap_ready(const gameplay_world::World& world) noexcept {
    if (world.closed() || !world.session().primary_population) return false;
    const auto population=std::bit_cast<std::int32_t>(*world.session().primary_population);
    if (population>std::int32_t(gameplay_world::World::primary_capacity)) return false;
    for (std::int32_t index=0;index<population;++index)
        if (!world.primary(std::uint16_t(index))) return false;
    for (const auto& descriptor:world.session().npc_descriptors.records())
        if (descriptor.active && descriptor.template_id>=210) return false;
    for (unsigned room=0;room<RoomActorAssets::room_count;++room)
        for (const auto& entry:*world.session().room_actor_assets.row(room))
            if (entry.id!=65535 && entry.id>=210) return false;
    return true;
}

bool remap_missing_characters(gameplay_world::World& world,std::uint8_t script_channel) noexcept {
    if (!character_remap_ready(world)) return false;
    auto& session=world.session();
    auto remap=session.missing_characters;
    const auto population=std::bit_cast<std::int32_t>(*session.primary_population);
    std::size_t missing=0;
    for (unsigned character=0;character<8;++character) {
        bool present=false;
        for (std::int32_t index=0;index<population;++index)
            present|=world.primary(std::uint16_t(index))->character==character;
        if (!present) remap.values[missing++]=std::uint8_t(character);
    }
    session.missing_characters=remap;
    const auto resolve=[&](std::uint16_t id) {
        return *remap.resolve(id,session.actor_placements.selected_request,script_channel);
    };
    for (std::size_t index=0;index<NpcDescriptors::capacity;++index) {
        auto& descriptor=*session.npc_descriptors.record(index);
        if (descriptor.active && descriptor.template_id>=200)
            descriptor.template_id=resolve(descriptor.template_id);
    }
    for (unsigned room=0;room<RoomActorAssets::room_count;++room)
        for (auto& entry:*session.room_actor_assets.row(room))
            if (entry.id>=200 && entry.id!=65535) entry.id=resolve(entry.id);
    for (std::size_t index=0;index<EnemyDescriptors::capacity;++index) {
        auto& descriptor=*session.enemy_descriptors.record(index);
        if (descriptor.family!=1 || descriptor.variant<60 || descriptor.variant>=70) continue;
        const auto missing_index=std::uint16_t(descriptor.variant-60u);
        const auto mapped=std::uint16_t(resolve(std::uint16_t(200u+missing_index))-200u);
        descriptor.variant=std::uint8_t(70u+mapped);
    }
    return true;
}
}
