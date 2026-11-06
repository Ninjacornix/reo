#pragma once
// Input-only transport and READ-ONLY observer adaptation, authored after the
// independent core/API freeze. No expected JSON or DSP is used by this code.
#include <atomic>
#include <condition_variable>
#include <memory_resource>
#include <span>
#include <variant>
#include <string_view>
#include <limits>
#define private public
#include "aggregate.h"
#undef private
#include "aggregate.cpp"
#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp"
#include "snapshot/Kernel/Syscalls/Helpers/ReoSoundBanks.cpp"
#include "recomp/overrides/native_banks/test_capture.h"

float reoAudioMasterGain();float reoAudioStreamGain(std::uint32_t);float reoAudioBankGain(unsigned,unsigned,std::uint64_t);
void reoAudioPoll();void reoAudioResetStreams();
namespace controlled_clock {inline std::int64_t nanoseconds=0;}
namespace native_environment {
namespace n=reo::native::audio_aggregate;
namespace p=n::packet;
struct Hooks final:n::HostHooks {
    std::int64_t now_ns()noexcept override{return controlled_clock::nanoseconds;}
    void poll_settings()noexcept override{reoAudioPoll();}
    float stream_gain(std::uint32_t key)noexcept override{return reoAudioStreamGain(key);}
    float bank_gain(unsigned port,unsigned index,std::uint64_t fp)noexcept override{return reoAudioBankGain(port,index,fp);}
    float master_gain()noexcept override{return reoAudioMasterGain();}
    void reset_stream_routes()noexcept override{reoAudioResetStreams();}
    void report_bank_paths(const n::bank::Snapshot&,bool)noexcept override{}
    void report_joined(const n::Report&)noexcept override{}
};
struct Headless final:n::output::Provider {
    std::string_view source_sha256()const noexcept override{return n::output::provider_source_sha256;}
    bool attach(n::output::CallbackSlot&)noexcept override{return false;}
    bool detach()noexcept override{return true;}bool stop()noexcept override{return true;}bool unload()noexcept override{return true;}
};
struct SyntheticCapture final:n::QualifiedCaptureProvider {
    p::MemoryIdentity identity()const noexcept override{return packet_test::identity();}
    p::PacketResult with_packet(const n::PacketBorrow& b,n::PacketOperation& op)noexcept override {
        if((!b.packet&&b.packet_bytes)||(!b.ram&&b.ram_bytes))return {p::Status::invalid_input};
        packet_test::Capture source;source.present=b.packet!=nullptr;source.has_ram=b.ram!=nullptr;source.ram_extent=b.ram_bytes;
        if(b.packet)source.packet={b.packet,b.packet_bytes};if(b.ram)source.ram={b.ram,b.ram_bytes};return op.run(source);
    }
    p::Status with_bank(const n::BankBorrow& b,n::BankOperation& op)noexcept override {
        if((!b.hd&&b.hd_bytes)||(!b.bd&&b.bd_bytes)||(!b.tq&&b.tq_bytes))return p::Status::invalid_input;
        packet_test::Capture source;source.bank={std::span<const uint8_t>(b.hd,b.hd_bytes),std::span<const uint8_t>(b.bd,b.bd_bytes),std::span<const uint8_t>(b.tq,b.tq_bytes)};return op.run(source);
    }
};
inline PS2Runtime runtime;
inline std::shared_ptr<n::Aggregate> owner;
inline void initialize(){
    n::Inputs inputs;inputs.host=std::make_shared<Hooks>();inputs.capture=std::make_shared<SyntheticCapture>();inputs.provider=std::make_shared<Headless>();inputs.slot=std::make_shared<n::output::CallbackSlot>();
    auto result=n::create_for_tests(std::move(inputs),{});if(result.status!=n::BuildStatus::ready_composition)throw std::runtime_error("aggregate creation");owner=std::move(result.owner);
    if(ps2_cri_audio::installBackendBeforeRunV2(runtime,owner->registration())!=ps2_cri_audio::BackendInstallStatusV1::installed)throw std::runtime_error("aggregate publication");
}
inline void finish(){if(!runtime.join())throw std::runtime_error("aggregate join");}
}
namespace native_pcm {
using ps2_cri_audio::reset;using ps2_cri_audio::queue;using ps2_cri_audio::configure;using ps2_cri_audio::discard;
using ps2_cri_audio::drain;using ps2_cri_audio::release;using ps2_cri_audio::consumed;using ps2_cri_audio::queuedSamples;
using ps2_cri_audio::ensureHostOutput;using ps2_cri_audio::render;using ps2_cri_audio::shutdown;
struct Channel {std::uint64_t queued{},consumed{};std::vector<std::int16_t> pcm;};
struct Voice {std::uint32_t left{},right{},channels{},frequency{},volume{};bool playing{},draining{};double phase{};std::uint64_t lateSamples{},skippedSamples{};};
inline std::unordered_map<std::uint32_t,Channel> channels;
inline std::unordered_map<std::uint32_t,Voice> voices;
inline std::uint64_t outputFrames{},signalFrames{},underrunFrames{};
inline bool externalClock{};
struct Time {std::chrono::nanoseconds value{};std::chrono::nanoseconds time_since_epoch()const{return value;}};
inline Time lastTick;
}
namespace native_bank {
using ps2_reo_sound::submitBank;using ps2_reo_sound::submitPacket;using ps2_reo_sound::reset;
using ps2_reo_sound::portState;using ps2_reo_sound::seState;
inline std::uint64_t frameClock{},requestAge{};inline bool muted{},mono{};
struct Voices {std::size_t count{};std::size_t size()const{return count;}};inline Voices voices;
struct Port {bool loaded{};unsigned volume{};std::uint64_t fingerprint{};};inline std::array<Port,14> ports;
}
namespace native_environment {
inline void observe(const std::set<std::uint32_t>& channelKeys,const std::set<std::uint32_t>& voiceKeys){
    // Access is observation-only. Mutations use the ACTUAL selected V2 facade;
    // this snapshot neither substitutes DSP nor changes any queue/order/clock.
    auto& bridge=owner->state_->bridge;native_pcm::channels.clear();native_pcm::voices.clear();
    for(auto key:channelKeys){const auto c=bridge.inspect_channel(key);if(!c.source_visible)continue;native_pcm::Channel row;row.queued=c.info.queued_bytes;row.consumed=c.info.consumed_bytes;row.pcm.resize(c.info.samples);
        if(bridge.copy_samples(key,row.pcm)!=reo::native::pcm_bridge::Status::ok)throw std::runtime_error("copy observation");native_pcm::channels.emplace(key,std::move(row));}
    std::array<std::uint32_t,8> order{};const auto ordered=bridge.copy_order(order);if(ordered.status!=reo::native::pcm_bridge::Status::ok)throw std::runtime_error("voice order observation");
    for(auto key:voiceKeys){if(std::find(order.begin(),order.begin()+ordered.value,key)==order.begin()+ordered.value)continue;const auto v=bridge.inspect_voice(key);const auto& i=v.info;
        native_pcm::voices.emplace(key,native_pcm::Voice{v.left,v.right,unsigned(i.channels),i.frequency,i.volume,i.playing,i.draining,i.phase,i.late_samples,i.skipped_samples});}
    const auto stats=bridge.statistics();native_pcm::outputFrames=stats.output_frames;native_pcm::signalFrames=stats.signal_frames;native_pcm::underrunFrames=stats.underrun_frames;
    const auto clock=bridge.clock();native_pcm::externalClock=clock.frame_clock;native_pcm::lastTick.value=std::chrono::nanoseconds(clock.last_tick_ns);
    const auto bank=owner->inspect_banks();native_bank::frameClock=bank.frame_clock;native_bank::requestAge=bank.request_age;native_bank::muted=bank.muted;native_bank::mono=bank.mono;native_bank::voices.count=bank.voice_count;
    for(unsigned p=0;p<14;++p)native_bank::ports[p]={bank.ports[p].loaded,bank.ports[p].volume,bank.ports[p].fingerprint};
}
}
