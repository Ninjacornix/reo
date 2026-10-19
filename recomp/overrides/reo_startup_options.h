#pragma once
#include "ps2_runtime.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

extern void o1_00580010_0x580010(uint8_t*, R5900Context*, PS2Runtime*);
extern void o1_00580110_0x580110(uint8_t*, R5900Context*, PS2Runtime*);

namespace reo_startup {
inline void logo(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    uint32_t task = 0;
    std::memcpy(&task, &ctx->r[4], sizeof(task));
    if (ctx->pc == 0x580010u && task >= 0x100000u && task < 0x1fffff0u && ram[task] == 0 &&
        ram[task + 1] == 0 && ram[task + 2] < 2) {
        // Phase 0 only starts the logo fade/timer; phase 1 draws the logo.
        // Enter phase 2 instead: original fade cleanup and title transition.
        ram[task + 2] = 2;
        std::fprintf(stderr, "[STARTUP] logo display bypassed; original title transition\n");
    }
    o1_00580010_0x580010(ram, ctx, runtime);
}
inline void title(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    o1_00580110_0x580110(ram, ctx, runtime);
    static bool reported = false;
    uint32_t task = 0;
    std::memcpy(&task, ram + 0x5d4898u, sizeof(task));
    if (!reported && task >= 0x100000u && task < 0x1fffff0u && ram[task] == 0 &&
        ram[task + 1] == 2 && ram[task + 2] == 3) {
        reported = true;
        std::fprintf(stderr, "[STARTUP] title-ready; PRESS START input remains manual\n");
    }
}
inline void install(PS2Runtime& runtime) {
    const char* value = std::getenv("REO_SKIP_INTROS");
    if (!value || std::strcmp(value, "1") != 0)
        return;
    // File #1, MWo3 front-end overlay identity. Never alter generated game code.
    runtime.registerOverlayFunction(0x570000u, 0x336f574du, 4, 2, 0x580010u, logo);
    runtime.registerOverlayFunction(0x570000u, 0x336f574du, 4, 2, 0x580110u, title);
    std::fprintf(stderr, "[STARTUP] skip-intros enabled (original title video retained)\n");
}
} // namespace reo_startup
