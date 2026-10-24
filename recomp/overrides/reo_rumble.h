#pragma once
#include "ps2_runtime.h"
#include <cstdio>

void reoPad2RumbleFrame();
namespace reo::rumble {
inline void (*originalFrame)(uint8_t*,R5900Context*,PS2Runtime*)=nullptr;
inline void frame(uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    // Refresh from the guest's original frame service, so a frozen or exited
    // guest stops the launcher's output heartbeat even if host input still polls.
    if(ctx->pc==0x19f6c0u) reoPad2RumbleFrame();
    originalFrame(ram,ctx,runtime);
}
inline void install(PS2Runtime& runtime) {
    originalFrame=runtime.lookupFunction(0x19f6c0u);
    if(!originalFrame || originalFrame==frame) throw std::runtime_error("Pad output frame service unavailable");
    runtime.registerFunction(0x19f6c0u,frame);
    std::fprintf(stderr,"[PAD-RUMBLE-1] libpad2 output enabled\n");
}
} // namespace reo::rumble
