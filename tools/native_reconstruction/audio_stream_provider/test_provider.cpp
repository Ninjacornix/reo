// Links the real adapter to fake device primitives and focused exact raylib
// source functions supplied by verify.py. No real audio library is linked.
#include "runtime/audio/native_stream_provider.h"
#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <new>
#include <thread>
#include <vector>

using namespace reo::audio_output;
#define CHECK(x) do { if (!(x)) { std::cerr << "Failed line " << __LINE__ << ": " #x "\n"; std::abort(); } } while (0)
struct Event {
    std::mutex mutex;
    std::condition_variable changed;
    bool signalled = false;
    void signal() { std::lock_guard lock(mutex); signalled = true; changed.notify_all(); }
    void wait() { std::unique_lock lock(mutex); changed.wait(lock, [&] { return signalled; }); }
};
using ma_uint8 = unsigned char;
using ma_uint32 = unsigned int;
using ma_uint64 = unsigned long long;
using ma_format = int;
constexpr ma_format ma_format_u8 = 1, ma_format_s16 = 2, ma_format_f32 = 3;
constexpr int AUDIO_BUFFER_USAGE_STREAM = 1;
struct Converter { ma_format formatIn; unsigned channelsIn, channelsOut; };
struct rAudioBuffer {
    AudioCallback callback = nullptr;
    Converter converter{};
    bool looping = false, playing = false;
    unsigned sizeInFrames = 0;
    void* data = nullptr;
    rAudioBuffer* prev = nullptr;
    rAudioBuffer* next = nullptr;
};
using AudioBuffer = rAudioBuffer;
struct {
    struct {
        std::mutex lock;
        struct { unsigned sampleRate = 48000;
                 struct { unsigned internalPeriodSizeInFrames = 128; } playback; } device;
    } System;
    struct { unsigned defaultSize = 0; AudioBuffer* first = nullptr; AudioBuffer* last = nullptr; } Buffer;
} AUDIO;
bool ready = false, fail_load = false;
unsigned loads = 0, plays = 0, stops = 0, converter_destroys = 0, frees = 0;
std::atomic<bool> watch_detach = false;
Event detach_entered;

void ma_mutex_lock(std::mutex* lock) {
    if (watch_detach) detach_entered.signal();
    lock->lock();
}
void ma_mutex_unlock(std::mutex* lock) { lock->unlock(); }
void TrackAudioBuffer(AudioBuffer*);
void UntrackAudioBuffer(AudioBuffer*);
AudioBuffer* LoadAudioBuffer(ma_format format, ma_uint32 channels, ma_uint32 rate,
                            ma_uint32 frames, int usage) {
    ++loads;
    CHECK(format == ma_format_f32 && channels == 2 && rate == 48000);
    CHECK(usage == AUDIO_BUFFER_USAGE_STREAM && AUDIO.Buffer.defaultSize == 512);
    if (fail_load) { fail_load = false; return nullptr; }
    auto* buffer = new (std::malloc(sizeof(AudioBuffer))) AudioBuffer{};
    buffer->data = std::malloc(1);
    buffer->sizeInFrames = frames;
    buffer->converter = {format, channels, channels};
    TrackAudioBuffer(buffer);
    return buffer;
}
void ma_data_converter_uninit(Converter*, void*) {
    CHECK(AUDIO.Buffer.first == nullptr && AUDIO.Buffer.last == nullptr);
    ++converter_destroys;
}
void counted_free(void* memory) { ++frees; std::free(memory); }
#undef RL_FREE
#define RL_FREE counted_free
#define TRACELOG(...) ((void)0)
void PlayAudioBuffer(AudioBuffer* buffer) {
    std::lock_guard lock(AUDIO.System.lock);
    CHECK(buffer && buffer->callback);
    buffer->playing = true;
    ++plays;
}
void StopAudioBuffer(AudioBuffer* buffer) {
    std::lock_guard lock(AUDIO.System.lock);
    CHECK(buffer && !buffer->callback);
    buffer->playing = false;
    ++stops;
}
extern "C" bool IsAudioDeviceReady(void) { return ready; }

unsigned ma_get_bytes_per_frame(ma_format format, unsigned channels) {
    CHECK(format == ma_format_f32);
    return 4 * channels;
}
void ma_data_converter_get_required_input_frame_count(Converter*, ma_uint64 output,
                                                     ma_uint64* input) { *input = output; }
void ma_data_converter_process_pcm_frames(Converter* converter, void* input,
                                         ma_uint64* inputs, float* output,
                                         ma_uint64* outputs) {
    const auto frames = std::min(*inputs, *outputs);
    std::memcpy(output, input, static_cast<std::size_t>(frames) * converter->channelsIn * sizeof(float));
    *inputs = *outputs = frames;
}
// Models only the real internal reader's callback branch; the outer mixing
// cap/loop and the source-level callback setter/unload functions below are exact.
ma_uint32 ReadAudioBufferFramesInInternalFormat(AudioBuffer* buffer, void* output,
                                               ma_uint32 frames) {
    CHECK(buffer->callback);
    buffer->callback(output, frames);
    return frames;
}
#include "qualified_raudio.inc"

struct TestRenderer final : Renderer {
    bool pause = false, self_join = false;
    Owner* owner = nullptr;
    JoinResult callback_join = JoinResult::joined;
    unsigned calls = 0, maximum_frames = 0, total_frames = 0;
    Event entered, finish;
    void render(float* output, std::uint32_t frames) noexcept override {
        ++calls;
        maximum_frames = std::max(maximum_frames, frames);
        total_frames += frames;
        if (self_join) callback_join = owner->join();
        entered.signal();
        if (pause) finish.wait();
        std::fill_n(output, frames * 2, 0.25f);
    }
};

void pump(float* output, unsigned frames) {
    // Models the actual OnSendAudioDataToDevice lock held over the source mixer.
    std::lock_guard lock(AUDIO.System.lock);
    auto* buffer = AUDIO.Buffer.first;
    if (buffer && buffer->playing && buffer->callback)
        CHECK(ReadAudioBufferFramesInMixingFormat(buffer, output, frames) == frames);
}

void lifecycle() {
    ready = true;
    auto provider = NativeStreamProvider::create();
    CHECK(provider && provider->source_sha256() == provider_source_sha256);
    auto renderer = std::make_shared<TestRenderer>();
    renderer->pause = true;
    auto owner = Owner::create(native_stream_callback_slot(), provider, renderer);
    CHECK(owner->start() == StartResult::started);
    CHECK(provider->status() == NativeStreamStatus::active && loads == 1 && plays == 1);
    float output[8]{};
    std::thread callback([&] { pump(output, 4); });
    renderer->entered.wait();
    owner->request_stop();
    watch_detach = true;
    std::atomic<bool> joined = false;
    std::thread control([&] { CHECK(owner->join() == JoinResult::joined); joined = true; });
    detach_entered.wait();
    CHECK(!joined && native_stream_callback_slot().occupied());
    renderer->finish.signal();
    callback.join(); control.join();
    CHECK(provider->status() == NativeStreamStatus::unloaded);
    CHECK(output[0] == 0.25f && renderer->calls == 1);
    CHECK(stops == 1 && converter_destroys == 1 && frees == 2);
    CHECK(AUDIO.Buffer.first == nullptr && !native_stream_callback_slot().occupied());
    CHECK(owner->join() == JoinResult::joined);
    CHECK(provider->detach() && provider->stop() && provider->unload());
    CHECK(stops == 1 && converter_destroys == 1 && frees == 2);
    CHECK(!NativeStreamProvider::create());
}

void headless_retry() {
    auto provider = NativeStreamProvider::create();
    CHECK(provider && !provider->attach(native_stream_callback_slot()));
    CallbackSlot foreign;
    CHECK(!provider->attach(foreign));
    auto renderer = std::make_shared<TestRenderer>();
    auto owner = Owner::create(native_stream_callback_slot(), provider, renderer);
    CHECK(owner->start() == StartResult::attach_failed);
    CHECK(provider->status() == NativeStreamStatus::unavailable);
    CHECK(loads == 0 && AUDIO.Buffer.defaultSize == 0 && !native_stream_callback_slot().occupied());
    ready = true; fail_load = true;
    CHECK(owner->start() == StartResult::attach_failed);
    CHECK(provider->status() == NativeStreamStatus::load_failed);
    CHECK(loads == 1 && plays == 0 && AUDIO.Buffer.first == nullptr && frees == 0);
    CHECK(owner->start() == StartResult::started && loads == 2 && plays == 1);
    CHECK(owner->start() == StartResult::already_started && loads == 2);
    CHECK(!provider->stop() && !provider->unload()); // no implicit unfenced cleanup
    CHECK(owner->join() == JoinResult::joined);
    CHECK(stops == 1 && converter_destroys == 1 && frees == 2);
}

void source_callback_cap() {
    ready = true;
    AUDIO.System.device.playback.internalPeriodSizeInFrames = 1024;
    auto provider = NativeStreamProvider::create();
    auto renderer = std::make_shared<TestRenderer>();
    auto owner = Owner::create(native_stream_callback_slot(), provider, renderer);
    CHECK(owner->start() == StartResult::started);
    CHECK(AUDIO.Buffer.first->sizeInFrames == 2048); // period overrides default512
    std::vector<float> output(2057 * 2);
    pump(output.data(), 2057);
    CHECK(renderer->calls == 5 && renderer->maximum_frames == 512 && renderer->total_frames == 2057);
    for (auto sample : output) CHECK(sample == 0.25f);
    CHECK(owner->join() == JoinResult::joined);
}

void callback_self_join() {
    ready = true;
    auto provider = NativeStreamProvider::create();
    auto renderer = std::make_shared<TestRenderer>();
    auto owner = Owner::create(native_stream_callback_slot(), provider, renderer);
    renderer->self_join = true; renderer->owner = owner.get();
    CHECK(owner->start() == StartResult::started);
    float output[8]{};
    pump(output, 4);
    CHECK(renderer->callback_join == JoinResult::callback_thread && stops == 0);
    CHECK(owner->join() == JoinResult::joined);
}

void reservation() {
    auto provider = NativeStreamProvider::create();
    CHECK(provider && !NativeStreamProvider::create());
    provider.reset();
    CHECK(!NativeStreamProvider::create());
    CHECK(loads == 0 && plays == 0 && stops == 0 && frees == 0);
}

int main(int argc, char** argv) {
    CHECK(argc == 2);
    const std::string_view mode = argv[1];
    if (mode == "lifecycle") lifecycle();
    else if (mode == "headless") headless_retry();
    else if (mode == "bounds") source_callback_cap();
    else if (mode == "selfjoin") callback_self_join();
    else if (mode == "reservation") reservation();
    else CHECK(false);
    std::cout << "native_stream_provider: " << mode << " passed (mock device)\n";
}
