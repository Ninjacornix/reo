#pragma once
#include <cstdint>
class PS2Runtime;
struct R5900Context;
namespace reo_gpu_movie {
// Call once during GAME function installation, before original movie init.
// Default activation policy belongs to Root's REO_GPU_MOVIE configuration.
bool installNativeMovieGame(PS2Runtime&);
void nativeMovieQuiescent(uint8_t*, R5900Context*, PS2Runtime*);
void nativeMovieIssued(const uint8_t*, R5900Context*, PS2Runtime*, uint32_t originalReturnPC);
void nativeMovieReleaseFrame(uint8_t*, R5900Context*, PS2Runtime*, uint32_t originalSofdec,
                             uint32_t originalFrame, uint32_t originalReturnPC);
void nativeMovieReturned(const uint8_t*, R5900Context*, PS2Runtime*, uint32_t originalReturnPC);
// Compressed/control metadata only: Runtime's real IMAGE source adapter can
// obtain this without including any Vulkan or decoder types or reading pixels.
struct NativeMovieImageSource {
    uint64_t epoch = 0, generation = 0, picture = 0, outputEventSerial = 0;
    int64_t pts90k = 0;
    uint32_t sofdec = 0, work = 0, descriptor = 0, destination = 0, width = 0, height = 0;
    uint32_t sourceAddress = 0, sourceByteOffset = 0, sourceBytes = 0, sourceLayout = 2;
};
enum class NativeMovieImageOwnership { Unowned, Owned, Stale };
NativeMovieImageOwnership lookupNativeMovieImage(PS2Runtime&, uint32_t originalSource,
                                                 uint32_t originalBytes, NativeMovieImageSource&);
void retireNativeMovieImage(PS2Runtime&, const NativeMovieImageSource&);
} // namespace reo_gpu_movie
