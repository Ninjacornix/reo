#pragma once
// Test-only observations. No mirror is consulted by the bridge's PCM algorithm.
#include "session_bridge.hpp"
#include <deque>
#include <map>
#include <vector>
float reoAudioMasterGain();
float reoAudioStreamGain(std::uint32_t);
void reoAudioPoll();
void reoAudioResetStreams();
namespace ps2_cri_audio {
namespace b=reo::native::pcm_bridge;
inline void require(b::Status value) {
    if(value!=b::Status::ok)throw std::runtime_error("session bridge refused "+std::to_string(static_cast<int>(value)));
}
struct TestHost final:b::Host {
    std::int64_t now_ns() noexcept override{return controlled_clock::nanoseconds;}
    void poll_settings() noexcept override{reoAudioPoll();}
    void ensure_output() noexcept override{}
    bool output_ready() noexcept override{return false;}
    float stream_gain(std::uint32_t id) noexcept override{return reoAudioStreamGain(id);}
    void mix_banks(float* p,std::uint32_t n) noexcept override{ps2_reo_sound::mix(p,n);}
    float master_gain() noexcept override{return reoAudioMasterGain();}
    void reset_stream_routes() noexcept override{reoAudioResetStreams();}
    bool stop_join_output() noexcept override{return true;}
    void reset_banks() noexcept override{ps2_reo_sound::reset();}
};
inline auto test_host=std::make_shared<TestHost>();
inline b::Session bridge(test_host);
struct ChannelView {std::deque<std::int16_t> pcm;std::uint64_t queued{},consumed{};};
struct VoiceView {
    std::uint32_t left{},right{},channels{},frequency{},volume{};
    float mixerGain{1};bool playing{},draining{};double phase{};
    std::uint64_t lateSamples{},skippedSamples{};
};
inline std::map<std::uint32_t,ChannelView> channels;
inline std::map<std::uint32_t,VoiceView> voices;
inline std::vector<std::uint32_t> raw_channels;
inline std::uint64_t outputFrames{},signalFrames{},underrunFrames{};
inline bool externalClock{};
inline pcm_test_std::chrono::steady_clock::time_point lastTick;
inline std::vector<std::uint32_t> raw_order() {
    std::vector<std::uint32_t> ids(64);
    auto result=bridge.copy_order(ids);require(result.status);ids.resize(result.value);return ids;
}
inline void refresh() {
    channels.clear();voices.clear();
    for(auto id:raw_channels) {
        auto c=bridge.inspect_channel(id);if(!c.source_visible)continue;
        std::vector<std::int16_t> pcm(c.info.samples);require(bridge.copy_samples(id,pcm));
        channels.emplace(id,ChannelView{{pcm.begin(),pcm.end()},c.info.queued_bytes,c.info.consumed_bytes});
    }
    for(auto id:raw_order()) {
        const auto v=bridge.inspect_voice(id);
        voices.emplace(id,VoiceView{v.left,v.right,static_cast<std::uint32_t>(v.info.channels),
            v.info.frequency,v.info.volume,v.info.gain,v.info.playing,v.info.draining,v.info.phase,
            v.info.late_samples,v.info.skipped_samples});
    }
    auto s=bridge.statistics();outputFrames=s.output_frames;signalFrames=s.signal_frames;underrunFrames=s.underrun_frames;
    auto c=bridge.clock();externalClock=c.frame_clock;
    lastTick=decltype(lastTick)(std::chrono::nanoseconds(c.last_tick_ns));
}
inline void ensureHostOutput(){require(bridge.ensureHostOutput());refresh();}
inline bool queue(std::uint32_t id,const std::uint8_t* p,std::uint32_t n,std::uint64_t& end) {
    const auto status=bridge.queue(id,p,n,end);
    if(status==b::Status::ok||status==b::Status::queue_full) {
        if(std::find(raw_channels.begin(),raw_channels.end(),id)==raw_channels.end())raw_channels.push_back(id);
    }
    refresh();
    if(status==b::Status::invalid_input||status==b::Status::queue_full)return false;
    require(status);return true;
}
inline void configure(std::uint32_t id,std::uint32_t left,std::uint32_t right,std::uint32_t nch,
                       std::uint32_t freq,std::uint32_t vol,bool playing) {
    require(bridge.configure(id,left,right,nch,freq,vol,playing));refresh();
}
inline void render(float* p,unsigned n){require(bridge.render(p,n));refresh();}
inline std::uint64_t consumed(std::uint32_t id){auto r=bridge.consumed(id);require(r.status);refresh();return r.value;}
inline std::size_t queuedSamples(std::uint32_t id){auto r=bridge.queuedSamples(id);require(r.status);return r.value;}
inline void discard(std::uint32_t id){require(bridge.discard(id));refresh();}
inline void drain(std::uint32_t id){require(bridge.drain(id));refresh();}
inline void release(std::uint32_t id){require(bridge.release(id));refresh();}
inline void reset(){require(bridge.reset());raw_channels.clear();refresh();}
inline void shutdown(){require(bridge.shutdown());raw_channels.clear();refresh();}
} // namespace ps2_cri_audio
