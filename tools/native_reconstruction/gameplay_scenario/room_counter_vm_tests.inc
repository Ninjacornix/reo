#include "game/native/gameplay_scenario/content.hpp"
#include <fstream>

namespace {
std::size_t room_counter_handler_calls{}, room_counter_dispatches{}, room_counter_resets{};
void room_counter_vm_tests(const char* policy_path) {
    using namespace vm::content;
    assertion_context = "room counter policy";
    ActorFixture actors;
    vm::FlagState flags;
    auto& contacts = actors.session->room_contacts;
    std::vector<std::uint8_t> ram(0x800000);
    constexpr std::uint32_t bank_base = 0x690000, policy_base = 0x691000, counter_base = 0x4a1df0;
    std::memcpy(ram.data() + 0x717690, original_room_counter_policy.data(), 128);
    fixture_write(ram.data(), 0x324424, bank_base);
    fixture_write(ram.data(), bank_base + 0x34, policy_base);
    ram[counter_base - 1] = 0x9c;
    ram[counter_base + 128 * 24 * 2] = 0xa1;
    contacts.pending[0] = 0xa1;
    check(!contacts.initialize_counters(4) && !contacts.counters_ready(false));
    std::ifstream policies(policy_path, std::ios::binary);
    check(bool(policies));
    for (unsigned profile = 0; profile < 6; ++profile) {
        auto evb = std::make_shared<std::vector<std::byte>>();
        if (profile == 5) {
            evb->resize(128);
            (*evb)[0x34] = std::byte{128};
            for (unsigned i = 0; i < 64; ++i) put(*evb, 0xabcdff00u + i);
        } else {
            std::array<std::uint8_t, 4> extent{};
            check(bool(policies.read(reinterpret_cast<char*>(extent.data()), extent.size())));
            evb->resize(fixture_read<std::uint32_t>(extent.data(), 0));
            check(bool(policies.read(reinterpret_cast<char*>(evb->data()), evb->size())));
        }
        const auto imported = import_room_counter_rows(ScriptBank(evb, BankFormat::scenario_evb));
        check(imported.has_value());
        const auto offset = fixture_read<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(evb->data()), 0x34);
        std::memcpy(ram.data() + policy_base, evb->data() + offset, 256);
        for (std::uint8_t row = 0; row < 4; ++row) {
            ram[0x4bae8a] = row;
            R5900Context original;
            PS2Runtime runtime;
            SET_GPR_U32(&original, 31, 0xdeadbeef);
            o2_005D7CF0_0x5d7cf0(ram.data(), &original, &runtime);
            check(original.pc == 0xdeadbeef && contacts.initialize_counters(row, imported));
            ++room_counter_resets;
            const auto compare_bank = [&] {
                check(std::memcmp(ram.data() + counter_base, contacts.counters.snapshot().data(), 128 * 24 * 2) == 0);
                check(ram[counter_base - 1] == 0x9c && ram[counter_base + 128 * 24 * 2] == 0xa1);
                check(contacts.pending[0] == 0xa1);
            };
            compare_bank();
            for (unsigned room = 0; room < 128; ++room) {
                for (unsigned edge = 0; edge < 24; ++edge) {
                    const auto column = (room + edge) & 15u;
                    const std::uint32_t selectors[]{0x80000000u | column, 96u + (column & 3u),
                        100u + column, 0x7ffffff0u + column};
                    const auto selector = selectors[(room + edge / 4) & 3u];
                    fixture_write(ram.data(), 0x10000, room);
                    fixture_write(ram.data(), 0x10004, edge);
                    fixture_write(ram.data(), 0x10008, selector);
                    SET_GPR_U32(&original, 4, 0x10000);
                    o2_00691D20_0x691d20(ram.data(), &original, &runtime);
                    check(original.pc == 0xdeadbeef && GPR_U32(&original, 2) == 0);
                    check(contacts.set_from_policy(room, edge, std::bit_cast<std::int32_t>(selector)));
                    check(contacts.counters.get(room, edge) == fixture_read<std::int16_t>(
                        ram.data(), counter_base + 48 * room + 2 * edge));
                    ++room_counter_handler_calls;
                }
            }
            compare_bank();
            install_original_tables(ram);
            ram[0x3243e8] = 1;
            for (auto mode : {vm::DispatchProfile::ordinary, vm::DispatchProfile::offline_actor}) {
                for (unsigned category = 0; category < 4; ++category) {
                    std::vector<std::byte> block;
                    emit(block, 0xf2, {127, 23, 103});
                    emit(block, 0xf2, {0, 0, 0xffffffff});
                    const auto tail = emit(block, 0xa);
                    check(contacts.counters.set(127, 23, -321) && contacts.counters.set(0, 0, -321));
                    fixture_write<std::int16_t>(ram.data(), counter_base, -321);
                    fixture_write<std::int16_t>(ram.data(), counter_base + 48 * 127 + 2 * 23, -321);
                    vm::Interpreter native;
                    const auto program = std::make_shared<const vm::Program>(
                        std::vector<std::vector<std::byte>>{block}, mode);
                    check(native.restore_channel(0, {program,{0,0},{0,tail},0,0,0}) == vm::Status::completed);
                    std::memcpy(ram.data() + 0x10000, block.data(), block.size());
                    fixture_write(ram.data(), 0x4bace0, 0x10000u);
                    fixture_write(ram.data(), 0x4bad28, 0x10000u + tail);
                    fixture_write(ram.data(), 0x75a4b0, category);
                    fixture_write(ram.data(), 0x75a4c0, 0u);
                    vm::Providers providers;
                    providers.world = &actors.world;
                    providers.flags = &flags;
                    providers.canonical_flags = &flags;
                    vm::TickResult result;
                    if (mode == vm::DispatchProfile::offline_actor) {
                        original_offline_call(ram, 0, false);
                        result = native.tick_offline_channel(0, {}, {category,0,0}, providers);
                    } else {
                        R5900Context dispatch;
                        SET_GPR_U32(&dispatch, 29, 0x7f0000);
                        SET_GPR_U32(&dispatch, 31, 0xdeadbeef);
                        o2_0068C660_0x68c660(ram.data(), &dispatch, &runtime);
                        check(dispatch.pc == 0xdeadbeef);
                        result = native.tick(0, {}, providers);
                    }
                    check(result.status == vm::Status::yielded && result.position.offset == tail);
                    check(fixture_read<std::uint32_t>(ram.data(), 0x4bace0) == 0x10000u + tail);
                    compare_bank();
                    ++room_counter_dispatches;
                }
            }
        }
    }
    check(policies.peek() == std::char_traits<char>::eof());
    check(contacts.initialize_counters(0) && contacts.counters_ready(false) && !contacts.counters_ready(true));
    std::vector<std::byte> block;
    emit(block, 0x110, {0, 77});
    emit(block, 0xf2, {0, 0, 100});
    emit(block, 0xa);
    vm::Interpreter native;
    check(native.install(0, std::make_shared<const vm::Program>(
        std::vector<std::vector<std::byte>>{block})) == vm::Status::completed);
    vm::Providers providers;
    providers.world = &actors.world;
    check(native.tick(0, {}, providers).status == vm::Status::provider_unavailable && native.counters()[0] == 0);
    for (const auto& destination : {std::pair{128u, 0u}, std::pair{0u, 24u}, std::pair{0xffffffffu, 0u}}) {
        block.clear();
        emit(block, 0xf2, {destination.first, destination.second, 0});
        bool rejected = false;
        try { const vm::Program invalid({block}); }
        catch (const std::invalid_argument&) { rejected = true; }
        check(rejected);
    }
    auto truncated = std::make_shared<std::vector<std::byte>>(129, std::byte{});
    (*truncated)[0x34] = std::byte{128};
    bool rejected = false;
    try { (void)import_room_counter_rows(ScriptBank(truncated, BankFormat::scenario_evb)); }
    catch (const std::invalid_argument&) { rejected = true; }
    check(rejected);
    assertion_context.clear();
}
}
