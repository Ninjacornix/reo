#pragma once
#include "ps2_runtime.h"
namespace ps2_stubs {
inline std::unordered_map<std::uint32_t,PS2Runtime::RecompiledFunction> overrides;
inline void registerStubOverride(std::uint32_t pc,PS2Runtime::RecompiledFunction fn){overrides[pc]=fn;}
}
