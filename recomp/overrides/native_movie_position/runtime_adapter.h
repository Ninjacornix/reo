#pragma once
class PS2Runtime;
namespace reo_native_movie_position {
#if defined(REO_GAME_FILE1) && defined(REO_BUILD_NATIVE_MOVIE_POSITION) && REO_BUILD_NATIVE_MOVIE_POSITION
// Bootstrap only, after original registration and before first run. Also needs
// exact REO_NATIVE_MOVIE_POSITION=1. One runtime/RAM lifetime, known caller only.
bool install(PS2Runtime& runtime) noexcept;
#else
inline bool install(PS2Runtime&) noexcept { return false; }
#endif
}
