#pragma once
#include "ps2_runtime.h"
namespace ps2_syscalls {
inline std::atomic<unsigned> fallback_calls{0};
inline void sceSifCallRpc(std::uint8_t*, R5900Context* context, PS2Runtime*) {
    ++fallback_calls;
    context->gpr[2] = static_cast<std::uint64_t>(-7LL); // Mock sentinel, not original behavior.
}
}
