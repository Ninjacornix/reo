#pragma once
#include <cstdint>
#include <limits>
#include <stdexcept>

namespace reo_gpu_movie {
inline constexpr int64_t UnboundMoviePts = std::numeric_limits<int64_t>::min();
struct MoviePictureIdentity {
    uint64_t generation = 0, picture = 0;
    uint64_t compressedBegin = 0, compressedEnd = 0;
    uint64_t forwardGeneration = 0, backwardGeneration = 0;
    uint32_t sofdec = 0, work = 0, outputDescriptor = 0, guestDestination = 0;
    int64_t pts90k = 0;
    bool truePictureBoundaries = false, truePlayerPts = false;
    // The actual original header/ref descriptor permits numerical production
    // before146C60 assigns a timestamp to a picture without its own PES PTS.
    uint64_t originalHeaderSerial = 0;
    uint32_t originalReferenceMetadata = 0;
    int32_t originalDisplayIndex = 0;
    bool pendingPlayerPts = false;
    int64_t originalPlayerPts90k = UnboundMoviePts;
    bool originalPlayerTimeObserved = false, originalPlayerTimeAbsent = false;
};
struct MovieTextureTicket {
    uint64_t generation = 0, picture = 0, slotSerial = 0;
    uint32_t slot = 0;
    int64_t pts90k = 0;
    bool gpuSubmitted = false;
};
inline bool hasMovieProductionTime(const MoviePictureIdentity& identity) {
    return (identity.truePlayerPts && !identity.pendingPlayerPts &&
            identity.pts90k != UnboundMoviePts) ||
           (!identity.truePlayerPts && identity.pendingPlayerPts &&
            identity.pts90k == UnboundMoviePts && identity.originalHeaderSerial &&
            identity.originalReferenceMetadata) ||
           (!identity.pendingPlayerPts && identity.originalPlayerTimeObserved &&
            identity.originalPlayerTimeAbsent && identity.pts90k == -1);
}
inline bool originalMovieTimeAbsent(int64_t outputPts, int64_t referencePts, uint32_t clockEnabled,
                                    int32_t lastClockPts) {
    // Literal146C60:146D24 copies missing ref+18 when clock mode is disabled;
    //146CB8 also copies it when no previous clock PTS exists. Preserve -1.
    return outputPts == -1 && referencePts == -1 && (!clockEnabled || lastClockPts < 0);
}
inline bool hasMovieConsumerTime(const MoviePictureIdentity& identity) {
    return !identity.pendingPlayerPts &&
           (identity.truePlayerPts || (identity.originalPlayerTimeObserved &&
                                       identity.originalPlayerTimeAbsent && identity.pts90k == -1));
}
inline void bindOriginalMovieTime(MoviePictureIdentity& identity, MovieTextureTicket& ticket,
                                  uint32_t referenceMetadata, int64_t originalPts,
                                  bool absent = false) {
    if (!identity.originalHeaderSerial || !referenceMetadata ||
        referenceMetadata != identity.originalReferenceMetadata || !ticket.gpuSubmitted ||
        ticket.generation != identity.generation || ticket.picture != identity.picture ||
        (originalPts < 0 && !(absent && originalPts == -1)) || (absent && originalPts != -1) ||
        !hasMovieProductionTime(identity))
        throw std::invalid_argument(
            "Original146C60 timestamp lacks exact decoded header/reference ownership");
    if (identity.truePlayerPts && originalPts >= 0 && identity.pts90k != originalPts)
        throw std::invalid_argument(
            "Original146C60 timestamp differs from the picture's explicit PES PTS");
    identity.originalPlayerPts90k = originalPts;
    identity.originalPlayerTimeObserved = true;
    identity.originalPlayerTimeAbsent = absent;
    if (!identity.truePlayerPts) {
        identity.pts90k = originalPts;
        identity.truePlayerPts = originalPts >= 0;
    }
    identity.pendingPlayerPts = false;
    ticket.pts90k = identity.pts90k;
}
} // namespace reo_gpu_movie
