#pragma once
#include "ps2_runtime_macros.h"
namespace ps2_stubs {
inline unsigned installed = 0;
inline void registerStubOverride(std::uint32_t, PS2Runtime::RecompiledFunction) {
    ++installed;
}
} // namespace ps2_stubs
