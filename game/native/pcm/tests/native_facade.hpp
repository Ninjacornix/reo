#pragma once
#include "game/native/pcm/pcm.hpp"
#include <deque>
#include <map>
#include <vector>
float reoAudioMasterGain();
float reoAudioStreamGain(std::uint32_t);
namespace ps2_cri_audio {
namespace core = reo::native::pcm;
inline core::Session native;
struct ChannelView {
    std::deque<std::int16_t> pcm;
    std::uint64_t queued{}, consumed{};
};
struct VoiceView {
    std::uint32_t left{}, right{}, channels{}, frequency{}, volume{};
    bool playing{}, draining{};
    double phase{};
    std::uint64_t lateSamples{}, skippedSamples{};
};
struct ChannelBinding {
    core::Channel handle;
    bool visible{};
};
struct VoiceBinding {
    core::Voice handle;
    std::uint32_t left{}, right{};
};
inline std::map<std::uint32_t, ChannelBinding> channel_bindings;
inline std::map<std::uint32_t, VoiceBinding> voice_bindings;
// Diagnostic mirrors only: never consulted for native decoding or consumption.
inline std::map<std::uint32_t, ChannelView> channels;
inline std::map<std::uint32_t, VoiceView> voices;
inline std::uint64_t outputFrames{}, signalFrames{}, underrunFrames{};
inline bool externalClock{};
inline pcm_test_std::chrono::steady_clock::time_point lastTick;
inline void require(core::Status status) {
    if (status != core::Status::ok)
        throw std::runtime_error("native PCM operation refused");
}
inline core::Channel channel(std::uint32_t id) {
    if (!id)
        return {};
    auto found = channel_bindings.find(id);
    if (found != channel_bindings.end())
        return found->second.handle;
    auto made = native.create_channel();
    require(made.status);
    channel_bindings.emplace(id, ChannelBinding{made.value, false});
    return made.value;
}
inline core::Voice voice(std::uint32_t id) {
    auto found = voice_bindings.find(id);
    if (found != voice_bindings.end())
        return found->second.handle;
    auto made = native.create_voice();
    require(made.status);
    voice_bindings.emplace(id, VoiceBinding{made.value, 0, 0});
    return made.value;
}
inline void apply_gains() {
    for (auto& pair : voice_bindings)
        require(native.gain(pair.second.handle, reoAudioStreamGain(pair.first)));
}
inline void refresh() {
    channels.clear();
    voices.clear();
    for (const auto& pair : channel_bindings) {
        if (!pair.second.visible)
            continue;
        auto info = native.inspect(pair.second.handle);
        if (info.status != core::Status::ok)
            continue;
        std::vector<std::int16_t> copy(info.value.samples);
        require(native.copy_samples(pair.second.handle, copy));
        channels.emplace(pair.first,
                         ChannelView{std::deque<std::int16_t>(copy.begin(), copy.end()),
                                     info.value.queued_bytes, info.value.consumed_bytes});
    }
    for (auto i = voice_bindings.begin(); i != voice_bindings.end();) {
        auto info = native.inspect(i->second.handle);
        if (info.status != core::Status::ok) {
            i = voice_bindings.erase(i);
            continue;
        }
        const auto& v = info.value;
        voices.emplace(i->first, VoiceView{i->second.left, i->second.right,
                                           static_cast<std::uint32_t>(v.channels), v.frequency,
                                           v.volume, v.playing, v.draining, v.phase, v.late_samples,
                                           v.skipped_samples});
        ++i;
    }
    auto stats = native.statistics();
    outputFrames = stats.output_frames;
    signalFrames = stats.signal_frames;
    underrunFrames = stats.underrun_frames;
    auto timing = native.clock();
    externalClock = timing.frame_clock;
    lastTick = decltype(lastTick)(std::chrono::nanoseconds(timing.last_tick_ns));
}
inline void ensureHostOutput() {}
inline bool queue(std::uint32_t id, const std::uint8_t* data, std::uint32_t bytes,
                  std::uint64_t& end) {
    if (!id || !data || !bytes || bytes % 2 || bytes > 0x4000)
        return false;
    auto h = channel(id);
    apply_gains();
    const auto result = native.enqueue(h, {reinterpret_cast<const std::byte*>(data), bytes},
                                       controlled_clock::nanoseconds);
    channel_bindings.at(id).visible = true;
    refresh();
    if (result.status == core::Status::capacity)
        return false;
    require(result.status);
    end = result.value;
    return true;
}
inline void configure(std::uint32_t id, std::uint32_t left, std::uint32_t right,
                      std::uint32_t count, std::uint32_t frequency, std::uint32_t volume,
                      bool playing) {
    auto h = voice(id);
    auto l = channel(left), r = channel(right);
    apply_gains();
    require(native.configure(
        h, {l, r, static_cast<core::Channels>(std::min(count, 2u)), frequency, volume, playing},
        controlled_clock::nanoseconds));
    voice_bindings.at(id).left = left;
    voice_bindings.at(id).right = right;
    refresh();
}
inline void render(float* output, unsigned frames) {
    apply_gains();
    if (output)
        require(native.render({output, std::size_t(frames) * 2}));
    else
        require(native.advance_frames(frames));
    ps2_reo_sound::mix(output, frames);
    if (output)
        for (std::size_t i = 0; i < std::size_t(frames) * 2; ++i)
            output[i] = std::clamp(output[i] * reoAudioMasterGain(), -1.0f, 1.0f);
    refresh();
}
inline std::size_t queuedSamples(std::uint32_t id) {
    auto found = channel_bindings.find(id);
    if (found == channel_bindings.end())
        return 0;
    auto info = native.inspect(found->second.handle);
    return info.status == core::Status::ok ? info.value.samples : 0;
}
inline std::uint64_t consumed(std::uint32_t id) {
    auto found = channel_bindings.find(id);
    if (found == channel_bindings.end())
        return 0;
    apply_gains();
    auto value = native.consumed(found->second.handle, controlled_clock::nanoseconds);
    require(value.status);
    refresh();
    return value.value;
}
inline void drain(std::uint32_t id) {
    auto found = voice_bindings.find(id);
    if (found != voice_bindings.end())
        require(native.drain(found->second.handle));
    refresh();
}
inline void discard(std::uint32_t id) {
    auto found = channel_bindings.find(id);
    if (found != channel_bindings.end())
        require(native.discard(found->second.handle));
    refresh();
}
inline void release(std::uint32_t id) {
    auto found = voice_bindings.find(id);
    if (found != voice_bindings.end()) {
        require(native.release(found->second.handle));
        voice_bindings.erase(found);
    }
    refresh();
}
inline void native_stop(std::uint32_t id, bool unreturned, std::uint32_t frequency) {
    auto found = voice_bindings.find(id);
    if (found != voice_bindings.end())
        require(native.stop(found->second.handle, unreturned, frequency).status);
    refresh();
}
inline void reset() {
    require(native.reset(controlled_clock::nanoseconds));
    channel_bindings.clear();
    voice_bindings.clear();
    refresh();
}
inline void shutdown() {
    native.shutdown(controlled_clock::nanoseconds);
    channel_bindings.clear();
    voice_bindings.clear();
    refresh();
    ps2_reo_sound::reset();
}
} // namespace ps2_cri_audio
