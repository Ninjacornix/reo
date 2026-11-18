#pragma once
#include "ps2_runtime.h"
namespace ps2_stubs {
inline std::unordered_map<std::uint32_t,PS2Runtime::RecompiledFunction> overrides;
inline bool throw_registration{};
inline unsigned registrations{},throw_on_registration{};
inline void registerStubOverride(std::uint32_t pc,PS2Runtime::RecompiledFunction f){if(throw_registration||++registrations==throw_on_registration)throw std::runtime_error("stub failure");overrides[pc]=f;}
}
