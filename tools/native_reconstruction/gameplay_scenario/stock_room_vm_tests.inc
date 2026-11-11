#include "game/native/gameplay_scenario/script_program.hpp"
#include <fstream>

namespace {
std::size_t stock_room_dispatches{};
void stock_room_vm_tests(const char* path) {
    using namespace vm::content;
    std::ifstream input(path, std::ios::binary | std::ios::ate);
    check(bool(input) && input.tellg() == 295388);
    auto room = std::make_shared<std::vector<std::byte>>(295388);
    input.seekg(0);
    check(bool(input.read(reinterpret_cast<char*>(room->data()), room->size())));
    const auto script = RdtDirectory(room).section(1);
    check(script && script->size() == 204);
    const ScriptBank bank(std::make_shared<const std::vector<std::byte>>(script->begin(), script->end()),
        BankFormat::room_section);
    constexpr std::uint32_t base = 0x10000, channel = 1;
    for (const auto profile : {vm::DispatchProfile::ordinary, vm::DispatchProfile::offline_actor}) {
        const auto admitted = admit_script_program(bank, profile);
        check(admitted.status == ScriptAdmission::admitted && admitted.entries[0] == vm::Position{8,0});
        check(!admitted.entries[1] && !admitted.program->record({9,12}));
        for (unsigned setup = 0; setup < 6; ++setup) {
            const bool offline = profile == vm::DispatchProfile::offline_actor;
            assertion_context = "stock r0417300 profile=" + std::to_string(offline) + " setup=" + std::to_string(setup);
            std::vector<std::uint8_t> ram(0x900000);
            install_original_tables(ram);
            std::memcpy(ram.data() + base, script->data(), script->size());
            for (std::size_t i = 0; i < bank.table_size(); ++i) {
                const auto offset = fixture_read<std::uint32_t>(ram.data(), base + 4 * i);
                if (offset) fixture_write(ram.data(), base + 4 * i, base + offset);
            }
            fixture_write(ram.data(), 0x4bace0 + 4 * channel, base + bank.object(8)->bound.offset);
            fixture_write(ram.data(), 0x4bad40 + 4 * channel, base);
            fixture_write(ram.data(), 0x4bad10 + 4 * channel, 8u);
            fixture_write(ram.data(), 0x75a4b0, setup % 5);
            fixture_write(ram.data(), 0x75a4c0, setup % 3);
            ram[0x3243e8] = 1;
            ActorFixture actors(setup, 2, offline);
            export_rule_context(ram, actors.world, 41, 73, offline ? 0 : 1);
            vm::FlagState flags;
            flags.restore(initial_flags());
            export_flags(ram, flags.snapshot());
            ControlFixture controls(setup);
            controls.ids.push_back(*controls.owner.append({0, 0x80, vm::ControlTypeZero{}}));
            controls.ids.push_back(*controls.owner.append({1, 0x80, vm::ControlTypeZero{}}));
            controls.export_original(ram);
            SequenceFixture sequences(setup);
            sequences.export_original(ram);
            LightingFixture lighting;
            lighting.export_original(ram);
            vm::SceneChannels scene_channels;
            scene_channels.restore(0xf1234567u);
            fixture_write(ram.data(), 0x4b9d0c, scene_channels.mask());
            vm::Providers providers;
            providers.world = &actors.world;
            providers.flags = &flags;
            providers.canonical_flags = &flags;
            providers.scene_controls = &controls.owner;
            providers.control_effects = &controls;
            providers.sequences = &sequences.owner;
            providers.lighting = &lighting.owner;
            providers.scene_channels = &scene_channels;
            vm::Interpreter native;
            check(native.install(channel, admitted.program, *admitted.entries[0]) == vm::Status::completed);
            for (unsigned pass = 0; pass < 3; ++pass) {
                const vm::TickContext context{true,false,2,73};
                vm::TickResult result;
                if (offline) {
                    original_offline_call(ram, channel, false);
                    result = native.tick_offline_channel(channel, context, {setup % 5,setup % 3,73}, providers);
                } else {
                    R5900Context original;
                    PS2Runtime runtime;
                    SET_GPR_U32(&original, 4, channel);
                    SET_GPR_U32(&original, 29, 0x7f0000);
                    SET_GPR_U32(&original, 31, 0xdeadbeef);
                    o2_0068C660_0x68c660(ram.data(), &original, &runtime);
                    check(original.pc == 0xdeadbeef);
                    ++invocations;
                    result = native.tick(channel, context, providers);
                }
                check(result.status == vm::Status::yielded);
                const auto& state = native.channels()[channel];
                const auto compare_pointer = [&](std::uint32_t at, vm::Position position) {
                    const auto object = bank.object(position.block);
                    check(object && fixture_read<std::uint32_t>(ram.data(), at + 4 * channel) ==
                        base + object->bound.offset + position.offset);
                };
                compare_pointer(0x4bace0, state.current);
                compare_pointer(0x4bad28, state.saved);
                check(fixture_read<std::uint32_t>(ram.data(), 0x4bad10 + 4 * channel) == state.block_index);
                compare_flags(ram, flags.snapshot());
                controls.compare_original(ram);
                sequences.compare_original(ram);
                lighting.compare_original(ram);
                check(scene_channels.mask() == fixture_read<std::uint32_t>(ram.data(), 0x4b9d0c));
                ++stock_room_dispatches;
            }
        }
    }
    assertion_context.clear();
}
}
