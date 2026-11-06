#include "player.hpp"
#include <algorithm>
#include <limits>
#include <mutex>
#include <optional>
#include <stdexcept>

namespace reo::native::adxt_player {
namespace {
pcm::Config output_config(std::uint32_t channels) {
    pcm::Config c;c.max_channels=channels;c.max_voices=1;c.channel_samples=8192;
    // Keep the qualified core's >=12000-frame configuration domain. This
    // wrapper separately admits only the provider's <=512-frame callbacks.
    c.max_enqueue_bytes=16384;
    return c;
}
// Deliberately private: no channel, voice, PCM owner or producer alias escapes.
// The outer mutex makes a stereo copy atomic with respect to rendering; the
// unchanged PCM core's own mutex remains inside it in one consistent order.
class Output final:public audio_output::Renderer,public adxt_playback::Output {
public:
    std::shared_ptr<audio_output::CallbackSlot> slot=std::make_shared<audio_output::CallbackSlot>();
    explicit Output(std::uint32_t channels):channels_(channels),core_(output_config(channels)) {
        if(channels<1 || channels>2)throw std::invalid_argument("Native stream channels");
        for(std::uint32_t c=0;c<channels;++c){
            auto h=core_.create_channel();if(h.status!=pcm::Status::ok)throw std::logic_error("Native channel creation");
            channel_[c]=std::move(h.value);
        }
        auto voice=core_.create_voice();if(voice.status!=pcm::Status::ok)throw std::logic_error("Native voice creation");
        voice_=std::move(voice.value);
        if(core_.select_frame_clock()!=pcm::Status::ok)throw std::logic_error("Native callback clock");
        config_.left=channel_[0];if(channels==2)config_.right=channel_[1];
        config_.channels=channels==1?pcm::Channels::mono:pcm::Channels::stereo;
        if(core_.configure(voice_,config_,0)!=pcm::Status::ok)throw std::logic_error("Native output preparation");
    }
    bool configure(std::uint32_t rate) noexcept {
        std::lock_guard lock(mutex_);if(fault_ || closed_)return false;
        config_.frequency=rate;return core_.configure(voice_,config_,0)==pcm::Status::ok;
    }
    adxt_playback::Status queued_samples(std::uint32_t& n) noexcept override {
        std::lock_guard lock(mutex_);return counts(n);
    }
    adxt_playback::Status free_samples(std::uint32_t& n) noexcept override {
        std::lock_guard lock(mutex_);const auto result=counts(n);if(result==adxt_playback::Status::completed)n=8192-n;
        return result;
    }
    adxt_playback::Status play(bool value) noexcept override {
        std::lock_guard lock(mutex_);if(fault_ || closed_)return adxt_playback::Status::fault;
        config_.playing=value;
        if(core_.configure(voice_,config_,0)!=pcm::Status::ok){fault_=true;return adxt_playback::Status::fault;}
        return adxt_playback::Status::completed;
    }
    adxt_playback::Status stop_transfer() noexcept override {
        // Copies are synchronous and serialized by this same mutex. Completion
        // fences accepted copies; audio callbacks have a separate Owner fence.
        std::lock_guard lock(mutex_);transfer_open_=false;
        return adxt_playback::Status::completed;
    }
    adxt_playback::Status through() noexcept override {
        std::lock_guard lock(mutex_);through_=true;return adxt_playback::Status::completed;
    }
    bool accept(const std::array<std::span<const std::byte>,2>& bytes) noexcept {
        std::lock_guard lock(mutex_);
        if(fault_ || closed_ || !transfer_open_ || bytes[0].empty() || bytes[0].size()%64 || bytes[0].size()>16384 ||
           (channels_==2 && bytes[0].size()!=bytes[1].size()))return false;
        std::uint32_t queued{};if(counts(queued)!=adxt_playback::Status::completed || bytes[0].size()/2>8192-queued)return false;
        // Frame-clock mode does not advance time during enqueue. The private
        // owner prevents close/reconfigure/another producer between channels.
        for(std::uint32_t c=0;c<channels_;++c){
            const auto info=core_.inspect(channel_[c]);
            if(info.status!=pcm::Status::ok || bytes[c].size()>std::numeric_limits<std::uint64_t>::max()-info.value.queued_bytes)return false;
        }
        for(std::uint32_t c=0;c<channels_;++c)
            if(core_.enqueue(channel_[c],bytes[c],0).status!=pcm::Status::ok){fault_=true;return false;}
        return true;
    }
    void render(float* stereo,std::uint32_t frames) noexcept override {
        std::lock_guard lock(mutex_);
        if(!stereo || frames>audio_output::maximum_callback_frames)return;
        auto out=std::span(stereo,std::size_t(frames)*2);
        if(fault_ || closed_ || core_.render(out)!=pcm::Status::ok){fault_=true;std::fill(out.begin(),out.end(),0.0f);}
    }
    void observe(Snapshot& s) const noexcept {
        std::lock_guard lock(mutex_);
        if(closed_){s.output=final_;s.output_statistics=final_stats_;s.output_voice=final_voice_;}
        else {
            for(std::uint32_t c=0;c<channels_;++c){const auto info=core_.inspect(channel_[c]);if(info.status==pcm::Status::ok)s.output[c]=info.value;}
            s.output_statistics=core_.statistics();
            const auto voice=core_.inspect(voice_);if(voice.status==pcm::Status::ok)s.output_voice=voice.value;
        }
        s.fault=s.fault || fault_;
    }
    void close_after_provider_join() noexcept {
        std::lock_guard lock(mutex_);transfer_open_=false;
        for(std::uint32_t c=0;c<channels_;++c){const auto info=core_.inspect(channel_[c]);if(info.status==pcm::Status::ok)final_[c]=info.value;}
        final_stats_=core_.statistics();const auto voice=core_.inspect(voice_);if(voice.status==pcm::Status::ok)final_voice_=voice.value;
        closed_=true;core_.shutdown(0);
    }
private:
    std::uint32_t channels_;pcm::Session core_;std::array<pcm::Channel,2> channel_;pcm::Voice voice_;
    pcm::VoiceConfig config_;mutable std::mutex mutex_;bool transfer_open_{true},through_{},fault_{},closed_{};
    std::array<pcm::ChannelInfo,2> final_{};pcm::Statistics final_stats_{};
    pcm::VoiceInfo final_voice_{};
    adxt_playback::Status counts(std::uint32_t& n) noexcept {
        if(fault_ || closed_)return adxt_playback::Status::fault;
        const auto a=core_.inspect(channel_[0]);
        if(a.status!=pcm::Status::ok || a.value.samples>8192){fault_=true;return adxt_playback::Status::fault;}
        if(channels_==2){const auto b=core_.inspect(channel_[1]);
            if(b.status!=pcm::Status::ok || b.value.samples!=a.value.samples){fault_=true;return adxt_playback::Status::fault;}}
        n=static_cast<std::uint32_t>(a.value.samples);return adxt_playback::Status::completed;
    }
};
Config checked(Config c) {
    if(c.decoder.downmix || c.decoder.seamless_enabled || c.decoder.pitch_offset ||
       c.decoder.channels<1 || c.decoder.channels>2)throw std::invalid_argument("Native player profile");
    return c;
}
}
class Player::State {
public:
    Config config;std::shared_ptr<Output> output;std::shared_ptr<audio_output::Owner> provider;
    window::StreamWindowOwner decoder;window::Request request;
    std::optional<adxt_playback::Playback> playback;
    std::optional<window::pcm::ReadLease> held;
    std::array<std::array<std::uint8_t,16384>,2> copy{};
    std::array<std::uint64_t,2> digest{1469598103934665603ull,1469598103934665603ull};
    std::uint64_t copied{},first{};
    bool configured{},stopping{},provider_joined{},retired{},fault{},busy{};
    State(Config c,std::shared_ptr<const resources::ByteView> view,
          std::unique_ptr<adxt_shared_source::Backend> backend,std::shared_ptr<adx_header::KeyContext> keys,
          std::shared_ptr<audio_output::Provider> host)
        :config(checked(c)),output(std::make_shared<Output>(c.decoder.channels)),
         provider(audio_output::Owner::create(*output->slot,std::move(host),output)),
         decoder(config.decoder,std::move(view),std::move(backend),std::move(keys)),request(decoder.request()) {
        if(!provider)throw std::invalid_argument("Qualified output provider contract required");
    }
    Status fail() noexcept { fault=true;provider->request_stop();return Status::fault; }
    Status pump() noexcept {
        for(;;){
            std::uint32_t free{};
            if(output->free_samples(free)!=adxt_playback::Status::completed)return fail();
            const auto before=decoder.snapshot();
            const auto samples=std::min(free,static_cast<std::uint32_t>(before.pcm.rings[0].data)/2)/32*32;
            if(!samples)return Status::completed;
            if(held || samples>8192 || samples>std::numeric_limits<std::uint64_t>::max()-copied)return fail();
            auto read=decoder.borrow_pcm(static_cast<std::int32_t>(samples*2));
            if(read.status!=window::pcm::Status::completed)return fail();
            held.emplace(std::move(read.lease));
            const auto bytes=held->grant(0).bytes;
            if(bytes<=0 || bytes%64 || bytes>16384)return fail();
            std::array<std::span<const std::byte>,2> spans;
            for(std::uint32_t c=0;c<config.decoder.channels;++c){
                if(held->grant(c).bytes!=bytes || held->read_into(c,std::span(copy[c]).first(static_cast<std::size_t>(bytes)))!=window::pcm::Status::completed)return fail();
                spans[c]=std::as_bytes(std::span(copy[c]).first(static_cast<std::size_t>(bytes)));
            }
            if(!output->accept(spans))return fail();
            // Queue accepted its own copy. Only now return the source PCM
            // credit. A later fault retains this real token until fenced cut.
            if(decoder.finish_pcm(*held)!=window::Status::completed)return fail();
            held.reset();copied+=static_cast<unsigned>(bytes)/2;
            const auto total=before.header.base.total_samples;
            const auto prefix=std::min<std::uint64_t>(static_cast<unsigned>(bytes)/2,total-first);
            for(std::uint32_t c=0;c<config.decoder.channels;++c)
                for(std::size_t i=0;i<prefix*2;++i){digest[c]^=copy[c][i];digest[c]*=1099511628211ull;}
            first+=prefix;
        }
    }
};
Player::Player(Config c,std::shared_ptr<const resources::ByteView> view,
               std::unique_ptr<adxt_shared_source::Backend> backend,std::shared_ptr<adx_header::KeyContext> keys,
               std::shared_ptr<audio_output::Provider> provider)
    :state_(std::make_unique<State>(c,std::move(view),std::move(backend),std::move(keys),std::move(provider))) {}
Player::~Player() { request_stop();(void)retire_on_control_thread(); }
Status Player::service(std::uint32_t tick) noexcept {
    auto& s=*state_;
    if(s.busy)return Status::busy;
    if(s.fault)return Status::fault;
    if(s.stopping || s.retired)return Status::closed;
    if(s.playback && s.playback->state().phase==adxt_playback::Phase::ended)return Status::ended;
    s.busy=true;struct Exit{bool& b;~Exit(){b=false;}}exit{s.busy};
    if(s.decoder.service_source().status!=adxt_shared_source::Status::completed)return s.fail();
    const auto decoded=s.decoder.service(s.request);
    if(decoded!=window::Status::completed && decoded!=window::Status::inactive && decoded!=window::Status::backpressure)return s.fail();
    if(!s.configured){
        if(s.decoder.snapshot().outer.phase==window::OuterPhase::header)return Status::waiting_header;
        if(s.decoder.configure_ready()!=window::Status::completed)return s.fail();
        const auto ready=s.decoder.snapshot();
        if(ready.ready.pitch || ready.ready.pans[0]!=(s.config.decoder.channels==1?0:-15) ||
           (s.config.decoder.channels==2 && ready.ready.pans[1]!=15)){
            s.fail();return Status::unsupported_profile;
        }
        if(!s.output->configure(static_cast<std::uint32_t>(ready.ready.frequency)))return s.fail();
        adxt_playback::State control;control.request_samples=ready.outer.max_request;
        s.playback.emplace(control);
        if(s.provider->start()!=audio_output::StartResult::started)return s.fail();
        s.configured=true;
    }
    if(s.pump()!=Status::completed)return Status::fault;
    const auto ready=s.decoder.snapshot();
    const auto controlled=s.playback->service({ready.outer.phase==window::OuterPhase::ended,s.config.decoder.channels,
                                               ready.header.active_samples_per_block,tick},s.decoder,*s.output);
    if(controlled==adxt_playback::Status::pending)return Status::pending;
    if(controlled!=adxt_playback::Status::completed)return s.fail();
    return s.playback->state().phase==adxt_playback::Phase::ended?Status::ended:Status::completed;
}
Snapshot Player::snapshot() const noexcept {
    const auto& s=*state_;Snapshot result;result.decoder=s.decoder.snapshot();
    if(s.playback)result.playback=s.playback->state();
    result.first_payload_digest=s.digest;result.copied_samples=s.copied;result.first_payload_samples=s.first;
    result.configured=s.configured;result.stop_requested=s.stopping;result.provider_joined=s.provider_joined;
    result.retired=s.retired;result.fault=s.fault;s.output->observe(result);return result;
}
void Player::request_stop() noexcept { state_->stopping=true;state_->provider->request_stop(); }
Status Player::retire_on_control_thread() noexcept {
    auto& s=*state_;
    if(s.busy)return Status::busy;
    if(s.retired)return Status::completed;
    s.busy=true;struct Exit{bool& b;~Exit(){b=false;}}exit{s.busy};
    s.stopping=true;s.provider->request_stop();
    if(!s.provider_joined){
        // No output/PCM/source mutex is held across the actual provider fence.
        if(s.provider->join()!=audio_output::JoinResult::joined)return Status::pending;
        s.provider_joined=true;s.output->close_after_provider_join();
    }
    if(s.held){if(s.decoder.finish_pcm(*s.held)!=window::Status::completed)return s.fail();s.held.reset();}
    const auto stopped=s.decoder.stop_decode();
    if(stopped!=window::Status::completed && stopped!=window::Status::retirement_pending && stopped!=window::Status::owned_fault)return s.fail();
    // Explicit cut after provider join. On natural end these bytes are padding;
    // a manual stop deliberately cuts remaining audio. No audible drain claim.
    while(s.decoder.snapshot().pcm.rings[0].data){
        auto read=s.decoder.borrow_pcm(16384);if(read.status!=window::pcm::Status::completed)return s.fail();
        if(!read.lease.grant(0).bytes)return s.fail();
        if(s.decoder.finish_pcm(read.lease)!=window::Status::completed)return s.fail();
    }
    const auto retired=s.decoder.retire_on_control_thread();
    if(retired==window::Status::retirement_pending)return Status::pending;
    if(retired!=window::Status::completed)return s.fail();
    s.retired=true;return Status::completed;
}
} // namespace reo::native::adxt_player
