#include "fake_audio.h"
#include <cstdlib>

#define REQUIRE(x) do { if (!(x)) std::abort(); } while (0)
struct rAudioBuffer { AudioCallback callback{}; bool playing{}; };
namespace fake_audio {
std::atomic<bool> ready{false}, callback_on_play{false};
std::atomic<unsigned> loads{0}, plays{0}, stops{0}, unloads{0};
std::mutex device;
rAudioBuffer buffer;
unsigned default_size{};
void pump(float* output, unsigned frames) {
    std::lock_guard lock(device);
    if (buffer.playing && buffer.callback) buffer.callback(output, frames);
}
}
extern "C" {
bool IsAudioDeviceReady(void) { return fake_audio::ready; }
void SetAudioStreamBufferSizeDefault(int size) { fake_audio::default_size = unsigned(size); }
AudioStream LoadAudioStream(unsigned rate, unsigned bits, unsigned channels) {
    REQUIRE(rate == 48000 && bits == 32 && channels == 2 && fake_audio::default_size == 512);
    ++fake_audio::loads;
    AudioStream stream{};
    stream.buffer = &fake_audio::buffer;
    stream.sampleRate = rate; stream.sampleSize = bits; stream.channels = channels;
    return stream;
}
bool IsAudioStreamValid(AudioStream stream) { return stream.buffer != nullptr; }
void SetAudioStreamCallback(AudioStream stream, AudioCallback callback) {
    std::lock_guard lock(fake_audio::device);
    REQUIRE(stream.buffer == &fake_audio::buffer);
    stream.buffer->callback = callback;
}
void PlayAudioStream(AudioStream stream) {
    {
        std::lock_guard lock(fake_audio::device);
        REQUIRE(stream.buffer->callback);
        stream.buffer->playing = true;
        ++fake_audio::plays;
    }
    // Stronger startup interleaving than real asynchronous playback: callback
    // runs before Play returns while provider-control remains held.
    if (fake_audio::callback_on_play) { float output[2]{}; fake_audio::pump(output, 1); }
}
void StopAudioStream(AudioStream stream) {
    std::lock_guard lock(fake_audio::device);
    REQUIRE(!stream.buffer->callback);
    stream.buffer->playing = false;
    ++fake_audio::stops;
}
void UnloadAudioStream(AudioStream stream) {
    std::lock_guard lock(fake_audio::device);
    REQUIRE(!stream.buffer->callback && !stream.buffer->playing);
    ++fake_audio::unloads;
}
}
