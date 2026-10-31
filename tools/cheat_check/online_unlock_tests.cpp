#include "../../runtime/cheats/outbreak_cheats.h"
#include <fstream>
#include <iostream>

int main(int argc, char** argv) try {
    using namespace reo::cheats;
    unsigned checks = 0;
    auto check = [&](bool ok, const char* reason) {
        if (!ok) throw std::runtime_error(reason);
        ++checks;
    };
    std::istringstream fixture("REO-CHEATS-2\nbuiltin unlock\n");
    std::ifstream file;
    if (argc > 1) { file.open(argv[1]); check(bool(file), "Cannot open launcher manifest"); }
    const auto program = parseProgram(argc > 1 ? static_cast<std::istream&>(file) : static_cast<std::istream&>(fixture));
    check(program.builtins == UnlockEverything && program.writes.empty(), "Online manifest must contain only progression unlocks");
    for (Game game : {Game::File1, Game::File2}) {
        const bool file2 = game == Game::File2;
        for (unsigned player = 0; player < 4; ++player) {
            std::vector<uint8_t> ram(32 * 1024 * 1024, 0x24);
            const uint32_t state = file2 ? 0x4db390u : 0x4badd0u;
            const uint32_t actor = file2 ? 0x4c5e10u + player * 0x1100u : 0x4a5c30u + player * 0x10e0u;
            const uint32_t health = file2 ? 0x540u : 0x544u;
            ram[state] = 2; ram[state + 0x1d] = uint8_t(player);
            ram[actor] = 1; ram[actor + 8] = 0; ram[actor + (file2 ? 0xbe8u : 0xbd0u)] = 0;
            setHalf(ram.data(), actor + health, 500); setHalf(ram.data(), actor + health + 2, 1200);
            const auto before = ram;
            const auto result = applyBuiltins(program.builtins, ram.data(), game);
            check(result.unlocks && result.active && result.player == player, "Unlocks must work with a living gameplay actor");
            auto allowed = [&](uint32_t address) {
                if (file2) return (address >= 0x2feea8 && address < 0x2feec0) || address == 0x2feec3 || address == 0x2feec5 ||
                    (address >= 0x30022c && address < 0x300230) || (address >= 0x300248 && address < 0x300310);
                if ((address >= 0x31fb64 && address < 0x31fb6c) || (address >= 0x31fb6d && address < 0x31fb79) ||
                    address == 0x31fb7f || address == 0x31fb83 || (address >= 0x323bd8 && address < 0x323bdc)) return true;
                for (unsigned bank = 0; bank < 3; ++bank)
                    for (uint32_t start : {0x323bf4u, 0x323c54u})
                        if (address >= start + bank * 32 && address < start + bank * 32 + 24) return true;
                return false;
            };
            for (uint32_t address = 0; address < ram.size(); ++address)
                if (ram[address] != before[address] && !allowed(address)) throw std::runtime_error("Unlocks changed non-progression RAM");
            check(true, "Full RAM preserves actor health, infection, inventory, points, options and network state");
            const uint32_t scenarios = word(ram.data(), file2 ? 0x30022cu : 0x323bd8u), mask = file2 ? 0xfffu : 0x1fu;
            check((scenarios & mask) == mask, "Scenario progression bits are not available");
            const auto once = ram;
            applyBuiltins(program.builtins, ram.data(), game);
            check(ram == once, "Repeated unlock application must be idempotent");
        }
    }
    std::cout << "PASS " << checks << " unlock-only native checks\n";
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n'; return 1;
}
