#include "game/native/gameplay_world/enemy_initialization.hpp"
#include "game/native/gameplay_world/linked_models.hpp"

namespace {
std::size_t enemy_priority_calls{},enemy_priority_refusals{},linked_definition_cases{};

void enemy_initialization_tests() {
    namespace world = reo::native::gameplay_world;
    std::vector<std::uint8_t> ram(0x900000);
    owned_enemy_constants(ram.data());
    owned_linked_definition_constants(ram.data());
    world::File1LinkedModelProfiles profiles;
    for (unsigned type = 0; type < 64; ++type) {
        const auto pointer = type < 62 ? fixture_read<std::uint32_t>(ram.data(),0x387e90+8*type) : 0u;
        auto end = 0x387e90u;
        for (unsigned next = 0; next < 62; ++next) {
            const auto candidate = fixture_read<std::uint32_t>(ram.data(),0x387e90+8*next);
            if (candidate > pointer && candidate < end) end = candidate;
        }
        for (unsigned variant = 0; variant < 256; ++variant) {
            const bool available = type < 62 && variant < (end-pointer)/16;
            bool admitted = false;
            try {
                const auto& definition = profiles.definition(std::uint8_t(type),std::uint16_t(variant));
                admitted = true;
                check(available);
                const auto at = pointer+16*variant;
                check(definition.model == ram[at]);
                check(definition.texture == ram[at+1]);
                check(definition.sound == ram[at+2]);
                check(std::bit_cast<std::uint32_t>(definition.scale) == fixture_read<std::uint32_t>(ram.data(),at+8));
                check(definition.visibility_selector == fixture_read<std::int8_t>(ram.data(),at+12));
            } catch (const std::out_of_range&) {}
            check(admitted == available);
            if (type == 1 && variant < 100)
                check(profiles.skip_type1_correction(std::uint16_t(variant)) == (ram[pointer+16*variant+5] == 1));
            ++linked_definition_cases;
        }
    }
    ActorFixture actors;
    const auto actor = actors.world.primary(0);
    const auto id = actors.world.identity_of(*actor);
    constexpr std::uint32_t at = 0x70000;
    for (unsigned mode = 0; mode < 256; ++mode) {
        for (unsigned seed = 0; seed < 256; ++seed) {
            assertion_context = "Enemy priority mode="+std::to_string(mode)+" seed="+std::to_string(seed);
            actor->character = std::uint8_t(seed*19+mode);
            actor->auxiliary_status = 0x89abcd00u|mode;
            actor->contact_flags = 0xf17e;
            actor->gauge_modifier_one = 0xcdef;
            actor->gauge_modifier_two = 0x1234;
            actors.session->enemy_descriptors.record(actor->character)->route_seed = std::uint8_t(seed);
            const bool available = mode > 2 || seed < 8;
            check(world::initialize_enemy_priorities(actors.world,id) == available);
            if (!available) {
                check(actor->auxiliary_status == (0x89abcd00u|mode));
                check(actor->contact_flags == 0xf17e);
                check(actor->gauge_modifier_one == 0xcdef);
                check(actor->gauge_modifier_two == 0x1234);
                ++enemy_priority_refusals;
                continue;
            }
            std::memset(ram.data()+at,0x65,0xd90);
            ram[at+0xb98] = actor->character;
            ram[0x74f292+96*actor->character] = std::uint8_t(seed);
            fixture_write(ram.data(),at+0xba4,0x89abcd00u|mode);
            fixture_write(ram.data(),at+0x54a,actor->contact_flags);
            fixture_write(ram.data(),at+0xbb6,std::uint16_t(0xcdef));
            fixture_write(ram.data(),at+0xbb8,std::uint16_t(0x1234));
            const std::vector<std::uint8_t> before(ram.begin()+at,ram.begin()+at+0xd90);
            invoke_npc_original(ram,o2_006BB9F0_0x6bb9f0,{at,0,0,0});
            check(actor->auxiliary_status == fixture_read<std::uint32_t>(ram.data(),at+0xba4));
            check(actor->contact_flags == fixture_read<std::uint16_t>(ram.data(),at+0x54a));
            check(actor->gauge_modifier_one == fixture_read<std::uint16_t>(ram.data(),at+0xbb6));
            check(actor->gauge_modifier_two == fixture_read<std::uint16_t>(ram.data(),at+0xbb8));
            for (unsigned byte = 0; byte < before.size(); ++byte) {
                if (byte == 0xba4 || (byte >= 0xbb6 && byte < 0xbba)) continue;
                check(ram[at+byte] == before[byte]);
            }
            ++enemy_priority_calls;
        }
    }
    ActorFixture foreign;
    check(!world::initialize_enemy_priorities(foreign.world,id));
    check(!world::initialize_enemy_priorities(actors.world,{}));
    check(actors.world.close() == world::Status::completed);
    check(!world::initialize_enemy_priorities(actors.world,id));
    enemy_priority_refusals += 3;
}
}
