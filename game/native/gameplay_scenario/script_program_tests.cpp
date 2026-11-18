#include "script_program.hpp"
#include "flags.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
#include <sstream>
#include <stdexcept>

namespace vm = reo::native::gameplay_scenario;
namespace content = vm::content;
namespace {
std::size_t checks{};
void check(bool value, std::source_location source = std::source_location::current()) {
    ++checks;
    if (!value) throw std::runtime_error("Stock script program check " + std::to_string(checks) +
        " at line " + std::to_string(source.line()));
}

void put(std::vector<std::byte>& data, std::size_t offset, std::uint32_t word) {
    for (unsigned byte = 0; byte < 4; ++byte)
        data.at(offset + byte) = std::byte((word >> (8 * byte)) & 255);
}

content::ScriptProgram admit(content::Bytes bytes, vm::DispatchProfile profile = vm::DispatchProfile::ordinary) {
    return content::admit_script_program(content::ScriptBank(std::move(bytes), content::BankFormat::room_section), profile);
}

void fixtures() {
    auto bytes = std::make_shared<std::vector<std::byte>>(120);
    check(admit(bytes).status == content::ScriptAdmission::absent);
    put(*bytes, 32, 64);
    put(*bytes, 36, 80);
    put(*bytes, 48, 104);
    put(*bytes, 64, 0xd);
    put(*bytes, 80, 1);
    put(*bytes, 84, 0xa);
    put(*bytes, 88, 0xffffffff);
    put(*bytes, 104, 1);
    put(*bytes, 108, 0xa);
    put(*bytes, 112, 0xffffffff);
    auto loaded = admit(bytes);
    check(loaded.status == content::ScriptAdmission::admitted);
    check(loaded.entries[0] == vm::Position{8, 0} && loaded.entries[1] == vm::Position{12, 0});
    check(loaded.program->blocks() == 16 && !loaded.program->record({0, 0}));
    check(!loaded.program->record({9, 8}) && !loaded.program->record({12, 8}));
    vm::Interpreter interpreter;
    check(interpreter.install(1, loaded.program, *loaded.entries[0]) == vm::Status::completed);
    check(interpreter.tick(1, {}).status == vm::Status::yielded);
    check(interpreter.channels()[1].current == vm::Position{9, 0});
    check(interpreter.channels()[1].block_index == 9);
    check(interpreter.tick(1, {}).status == vm::Status::yielded);
    check(interpreter.channels()[1].saved == vm::Position{9, 4});
    check(interpreter.install(5, loaded.program, *loaded.entries[1]) == vm::Status::completed);
    check(interpreter.tick(5, {}).status == vm::Status::yielded);
    check(interpreter.channels()[5].saved == vm::Position{12, 4});
    put(*bytes, 80, 0xa);
    auto refusal = admit(bytes);
    check(refusal.status == content::ScriptAdmission::unknown_continuation && refusal.failure == vm::Position{9, 0});
    put(*bytes, 80, 1);
    put(*bytes, 36, 0);
    refusal = admit(bytes);
    check(refusal.status == content::ScriptAdmission::unbound_block && refusal.failure == vm::Position{9, 0});
    put(*bytes, 36, 80);
    put(*bytes, 80, 0xf2);
    check(admit(bytes).status == content::ScriptAdmission::invalid_payload);
    put(*bytes, 80, 0x020000f2);
    put(*bytes, 84, 128);
    put(*bytes, 96, 1);
    put(*bytes, 100, 0xa);
    check(admit(bytes).status == content::ScriptAdmission::invalid_payload);
    put(*bytes, 80, 0xd0);
    check(admit(bytes).status == content::ScriptAdmission::invalid_payload);
    put(*bytes, 80, 0x3b);
    check(admit(bytes).status == content::ScriptAdmission::unsupported_opcode);
    put(*bytes, 80, 0x1f000000);
    check(admit(bytes).status == content::ScriptAdmission::invalid_record);

    auto conditional = std::make_shared<std::vector<std::byte>>(116);
    put(*conditional, 32, 64);
    put(*conditional, 64, 1);
    put(*conditional, 68, 0x02000008);
    put(*conditional, 84, 0x01000110);
    check(admit(conditional).status == content::ScriptAdmission::invalid_payload);
    put(*conditional, 84, 0x02000110);
    put(*conditional, 100, 0xe5);
    put(*conditional, 104, 0xa);
    put(*conditional, 108, 0xffffffff);
    check(admit(conditional).status == content::ScriptAdmission::admitted);
    put(*conditional, 100, 0x3b);
    check(admit(conditional).status == content::ScriptAdmission::unsupported_opcode);
    put(*conditional, 84, 0x01000003);
    put(*conditional, 88, 4097);
    put(*conditional, 92, 0xe5);
    put(*conditional, 96, 0xa);
    check(admit(conditional).status == content::ScriptAdmission::work_limit);
}

void ordinal_loops() {
    // Executing E5 increments the original counter. A non-yielding loop must
    // converge in the admission proof without erasing that runtime behavior.
    auto bytes = std::make_shared<std::vector<std::byte>>(80);
    put(*bytes, 32, 64);
    put(*bytes, 64, 1);
    put(*bytes, 68, 0xe5);
    put(*bytes, 72, 2);
    put(*bytes, 76, 0xffffffff);
    auto loaded = admit(bytes);
    check(loaded.status == content::ScriptAdmission::admitted);
    vm::Interpreter interpreter;
    check(interpreter.install(1, loaded.program, *loaded.entries[0]) == vm::Status::completed);
    auto tick = interpreter.tick(1, {}, {}, 1001);
    check(tick.status == vm::Status::budget_exhausted && tick.operations == 1001);
    check(interpreter.channels()[1].condition == 500);
    check(interpreter.channels()[1].current == vm::Position{8, 4});
    check(interpreter.channels()[1].saved == vm::Position{8, 4});

    // Both predicate outcomes revisit the same loop with different absolute
    // counters. The false outcome uses the real scanner; true executes E5.
    bytes = std::make_shared<std::vector<std::byte>>(96);
    put(*bytes, 32, 64);
    put(*bytes, 64, 1);
    put(*bytes, 68, 0x02000008);
    put(*bytes, 76, 1);
    put(*bytes, 84, 0xe5);
    put(*bytes, 88, 2);
    put(*bytes, 92, 0xffffffff);
    loaded = admit(bytes);
    check(loaded.status == content::ScriptAdmission::admitted);
    for (const bool value : {false, true}) {
        vm::FlagState flags;
        check(flags.write(vm::FlagBank::scenario, 0, value));
        vm::Providers providers;
        providers.flags = &flags;
        vm::Interpreter loop;
        check(loop.install(1, loaded.program, *loaded.entries[0]) == vm::Status::completed);
        tick = loop.tick(1, {}, providers, 61);
        check(tick.status == vm::Status::budget_exhausted && tick.operations == 61);
        check(loop.channels()[1].current == vm::Position{8, 4});
        check(loop.channels()[1].condition == (value ? 40u : 0u));
    }

    // A looping true branch must not hide unsupported work on the false branch.
    bytes->resize(108);
    put(*bytes, 84, 2);
    put(*bytes, 88, 0xe4);
    put(*bytes, 92, 0x3b);
    put(*bytes, 96, 0xe5);
    put(*bytes, 100, 0xa);
    const auto refused = admit(bytes);
    check(refused.status == content::ScriptAdmission::unsupported_opcode);
    check(refused.failure == vm::Position{8, 28} && refused.opcode == 0x3b);

    // These actor predicates execute the same scanner. If classified as
    // ordinary fallthrough, their looping true branch hides the false branch.
    for (const auto opcode : {0x150u, 0x151u, 0x153u, 0x156u}) {
        const auto record_size = opcode == 0x156 ? 32u : 16u;
        bytes = std::make_shared<std::vector<std::byte>>(68 + record_size + 24);
        put(*bytes, 32, 64);
        put(*bytes, 64, 1);
        put(*bytes, 68, (opcode == 0x156 ? 0x03000000u : 0x02000000u) | opcode);
        const auto tail = 68 + record_size;
        put(*bytes, tail, 2);
        put(*bytes, tail + 4, 0xe4);
        put(*bytes, tail + 8, 0x3b);
        put(*bytes, tail + 12, 0xe5);
        put(*bytes, tail + 16, 0xa);
        auto predicate = admit(bytes);
        check(predicate.status == content::ScriptAdmission::unsupported_opcode);
        check(predicate.opcode == 0x3b && predicate.failure == vm::Position{8, tail + 8 - 64});
        put(*bytes, tail + 8, 0);
        check(admit(bytes).status == content::ScriptAdmission::admitted);
    }

    // The resource bound remains enforced for genuinely distinct positions.
    bytes = std::make_shared<std::vector<std::byte>>(64 + 20002 * 4);
    put(*bytes, 32, 64);
    put(*bytes, 64, 1);
    put(*bytes, bytes->size() - 4, 2);
    check(admit(bytes).status == content::ScriptAdmission::work_limit);
}

void startup_entry() {
    // EVB has 32 table entries. Configured entry0 loops; entry1 is independent.
    auto bytes = std::make_shared<std::vector<std::byte>>(160);
    put(*bytes, 0, 128);
    put(*bytes, 4, 144);
    put(*bytes, 128, 1);
    put(*bytes, 132, 0xa);
    put(*bytes, 136, 0xffffffff);
    put(*bytes, 144, 1);
    put(*bytes, 148, 0xa);
    put(*bytes, 152, 0xffffffff);
    const auto load = [&](content::ScriptRoots roots) {
        return content::admit_script_program(content::ScriptBank(bytes, content::BankFormat::scenario_evb),
                                             vm::DispatchProfile::ordinary, roots);
    };
    auto configured = load(content::ScriptRoots::configured);
    auto startup = load(content::ScriptRoots::scenario_startup);
    check(configured.status == content::ScriptAdmission::admitted);
    check(configured.entries[0] == vm::Position{0, 0});
    check(!configured.program->record({1, 0}));
    check(startup.status == content::ScriptAdmission::admitted);
    check(startup.entries[0] == vm::Position{1, 0} && !startup.entries[1]);
    check(!startup.program->record({0, 0}));
    vm::Interpreter interpreter;
    check(interpreter.install(0, startup.program, *startup.entries[0]) == vm::Status::completed);
    check(interpreter.tick(0, {}).status == vm::Status::yielded);
    check(interpreter.channels()[0].current == vm::Position{1, 4});
    check(interpreter.channels()[0].block_index == 1);
    // A null secondary EVB entry retains inert source metadata. It must not
    // become executable or accept a fabricated current/saved continuation.
    vm::Channel unbound;
    unbound.block_index = 4;
    unbound.condition = UINT32_MAX;
    check(interpreter.restore_channel(4, unbound) == vm::Status::completed);
    check(interpreter.channels()[4].block_index == 4 && interpreter.channels()[4].condition == UINT32_MAX);
    const auto missing = interpreter.tick(4, {});
    check(missing.status == vm::Status::invalid_program && !missing.operations);
    for (unsigned invalid = 0; invalid < 3; ++invalid) {
        auto bad = unbound;
        if (invalid == 0) bad.current = {1, 0};
        if (invalid == 1) bad.saved = {1, 4};
        if (invalid == 2) bad.countdown = 1;
        check(interpreter.restore_channel(4, bad) == vm::Status::invalid_program);
        check(!interpreter.channels()[4].program && interpreter.channels()[4].block_index == 4 &&
              interpreter.channels()[4].condition == UINT32_MAX && !interpreter.channels()[4].countdown);
    }
    put(*bytes, 144, 0x3b);
    check(load(content::ScriptRoots::configured).status == content::ScriptAdmission::admitted);
    check(load(content::ScriptRoots::scenario_startup).status == content::ScriptAdmission::unsupported_opcode);
    put(*bytes, 4, 0);
    check(load(content::ScriptRoots::scenario_startup).status == content::ScriptAdmission::unbound_block);
    check(content::admit_script_program(content::ScriptBank(bytes, content::BankFormat::room_section),
          vm::DispatchProfile::ordinary, content::ScriptRoots::scenario_startup).status == content::ScriptAdmission::unbound_block);
}

void stock(const char* path) {
    std::ifstream manifest(path);
    check(bool(manifest));
    std::string line;
    bool first = true;
    std::cout << '[';
    while (std::getline(manifest, line)) {
        std::istringstream row(line);
        std::string format, file, offset, extent;
        check(bool(std::getline(row, format, '\t') && std::getline(row, file, '\t') &&
                   std::getline(row, offset, '\t') && std::getline(row, extent, '\t')));
        const auto bytes = std::stoull(extent);
        check(bytes <= 16 * 1024 * 1024);
        auto source = std::make_shared<std::vector<std::byte>>(bytes);
        std::ifstream archive(file, std::ios::binary);
        archive.seekg(std::streamoff(std::stoull(offset)));
        check(bool(archive.read(reinterpret_cast<char*>(source->data()), std::streamsize(bytes))));
        content::Bytes backing = source;
        if (format == "R") {
            const auto section = content::RdtDirectory(backing).section(1);
            backing = section ? std::make_shared<const std::vector<std::byte>>(section->begin(), section->end()) : nullptr;
        }
        check(format == "R" || format == "E");
        if (!first) std::cout << ',';
        first = false;
        std::cout << '[';
        bool first_profile = true;
        for (const auto profile : {vm::DispatchProfile::ordinary, vm::DispatchProfile::offline_actor}) {
            content::ScriptProgram result;
            if (backing) {
                const content::ScriptBank bank(backing, format == "E" ? content::BankFormat::scenario_evb :
                                                                        content::BankFormat::room_section);
                result = content::admit_script_program(bank, profile);
            }
            if (result.status == content::ScriptAdmission::admitted) {
                check(bool(result.program) && !result.program->unsupported());
                vm::Interpreter vm;
                for (std::size_t channel = 0; channel < result.entries.size(); ++channel)
                    if (result.entries[channel])
                        check(vm.install(channel, result.program, *result.entries[channel]) == vm::Status::completed);
            } else check(!result.program);
            if (!first_profile) std::cout << ',';
            first_profile = false;
            std::cout << "{\"status\":" << unsigned(result.status) << ",\"block\":" << result.failure.block
                      << ",\"offset\":" << result.failure.offset << ",\"opcode\":" << result.opcode << '}';
        }
        std::cout << ']';
    }
    std::cout << "]\n";
}
}

int main(int argc, char** argv) try {
    fixtures();
    ordinal_loops();
    startup_entry();
    if (argc == 2) stock(argv[1]);
    else std::cout << checks << " native script admission checks passed\n";
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
}
