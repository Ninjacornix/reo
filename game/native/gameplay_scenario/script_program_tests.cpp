#include "script_program.hpp"
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
    put(*conditional, 100, 0xd0);
    check(admit(conditional).status == content::ScriptAdmission::unsupported_opcode);
    put(*conditional, 84, 0x01000003);
    put(*conditional, 88, 4097);
    put(*conditional, 92, 0xe5);
    put(*conditional, 96, 0xa);
    check(admit(conditional).status == content::ScriptAdmission::work_limit);
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
    if (argc == 2) stock(argv[1]);
    else std::cout << checks << " native script admission checks passed\n";
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
}
