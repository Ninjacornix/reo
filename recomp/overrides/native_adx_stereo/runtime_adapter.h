#pragma once
class PS2Runtime;
namespace reo_native_adx_stereo {
#if defined(REO_GAME_FILE1) && defined(REO_BUILD_NATIVE_ADX_STEREO) && REO_BUILD_NATIVE_ADX_STEREO
// Final-ELF/pre-run bootstrap only. Exact REO_NATIVE_ADX_STEREO=1 required.
// Installs the two lower kernels without changing the original selector flag.
bool install(PS2Runtime& runtime) noexcept;
#else
inline bool install(PS2Runtime&) noexcept { return false; }
#endif
}
