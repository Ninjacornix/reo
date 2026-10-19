#pragma once
#include "ps2_runtime.h"
#include "../../runtime/cheats/outbreak_cheats.h"
#include <filesystem>
#include <fstream>
#include <cstdio>
#include <cstdlib>

namespace reo::cheats {
inline std::vector<Write> active;
inline unsigned builtinFlags = 0;
inline void (*originalService)(uint8_t*, R5900Context*, PS2Runtime*) = nullptr;
inline void service(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    // Original per-frame service, on the guest owner. Never write from a host timer.
    if (ctx->pc == 0x19f6c0u) {
        apply(active, ram, false);
        const auto result = applyBuiltins(builtinFlags, ram);
        static unsigned gameplayFrames = 0;
        if (result.active) {
            static const bool diagnostic = std::getenv("REO_CHEAT_DIAG") != nullptr;
            if (gameplayFrames++ == 0 || (diagnostic && gameplayFrames % 300 == 0))
                std::fprintf(
                    stderr,
                    "[CHEATS] player=%u builtins=%u health=%u/%u virus=%u firearmSlots=%u\n",
                    result.player, builtinFlags, result.health, result.maximum, result.virus,
                    result.ammunitionSlots);
        }
        static bool reported = false;
        if (!reported) {
            reported = true;
            std::fprintf(stderr, "[CHEATS] frame data writes active on guest service\n");
        }
    }
    originalService(ram, ctx, runtime);
}
inline void install(PS2Runtime& runtime) {
#ifdef _WIN32
    const wchar_t* file = _wgetenv(L"REO_CHEATS_FILE");
#else
    const char* file = std::getenv("REO_CHEATS_FILE");
#endif
    if (!file || !*file)
        return;
    std::ifstream input{std::filesystem::path(file)};
    if (!input)
        throw std::runtime_error("Cannot open selected cheat manifest");
    auto program = parseProgram(input);
    active = std::move(program.writes);
    builtinFlags = program.builtins;
    if (active.empty() && !builtinFlags)
        return;
    originalService = runtime.lookupFunction(0x19f6c0u);
    if (!originalService || originalService == service)
        throw std::runtime_error("Cheat frame service unavailable");
    apply(active, runtime.memory().getRDRAM(), true);
    runtime.registerFunction(0x19f6c0u, service);
    std::fprintf(stderr,
                 "[CHEATS] loaded %zu data writes, builtins=%u; original frame service retained\n",
                 active.size(), builtinFlags);
}
} // namespace reo::cheats
