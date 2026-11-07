#pragma once
#include "../movie_audio_clock/clock.hpp"
namespace reo::native::movie_timing_context {
enum class AudioStage {none,status,frequency,pause,discard,filter};
struct AudioCommands {
    // Prepared presence of the channel-7 and decoder-3 interfaces. Their
    // complete creation/destruction remains the movie graph owner's job.
    bool channel{true},decoder{true};
    std::uint32_t requested_pause{},residual{};
    AudioStage stage{AudioStage::none};
    movie_audio_clock::ProviderStatus provider{movie_audio_clock::ProviderStatus::completed};
};
}
