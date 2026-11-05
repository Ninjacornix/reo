#pragma once
class PS2Runtime;
namespace reo_native_adx_block {
#if defined(REO_GAME_FILE1) && defined(REO_BUILD_NATIVE_ADX_BLOCK) && REO_BUILD_NATIVE_ADX_BLOCK
// Bootstrap only, after final ELF/function registration and before first run.
// Exact REO_NATIVE_ADX_BLOCK=1 is also required. One runtime/RAM lifetime only.
bool install(PS2Runtime& runtime) noexcept;
#else
inline bool install(PS2Runtime&) noexcept { return false; }
#endif
}
