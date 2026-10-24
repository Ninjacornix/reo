#pragma once
#include <cstdint>
// Disable unrelated diagnostics, retaining the actual production audio source.
namespace ps2_vblank_music_diag {
enum class Kind { AudioReport,Voice,PcmPush };
template<class... T> inline void note(Kind,T...) {}
}
