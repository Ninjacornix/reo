#include "session.hpp"
#include "../audio_mix_tail/mixer.hpp"
#include <algorithm>
#include <atomic>
#include <limits>
#include <mutex>
#include <stdexcept>
#include <vector>

namespace reo::native::adxt_output_session {
namespace {
Config checked(Config c) {
    if(!c.streams || c.streams>maximum_streams || !c.maximum_counter)
        throw std::invalid_argument("Native stream output domain");
    return c;
}
pcm::Config core_config(Config c) {
    pcm::Config value;value.max_channels=c.streams*2;value.max_voices=c.streams;
    value.channel_samples=samples_per_channel;value.max_enqueue_bytes=16384;
    value.max_counter=c.maximum_counter;return value;
}
using Control=adxt_playback::Status;
}
struct Producer::Identity {};
struct Record {
    std::array<pcm::Channel,2> channels;pcm::Voice voice;pcm::VoiceConfig config;
    std::weak_ptr<void> producer;
    std::array<std::uint64_t,2> byte_origin{};
    StreamSnapshot final;
    std::uint64_t generation{1};std::uint32_t channel_count{};
    bool active{}, exhausted{}, transfer_open{}, through{}, fault{}, has_voice{true};
};
struct State {
    Config config;pcm::Session pcm;mutable std::mutex mutex;
    std::shared_ptr<audio_output::CallbackSlot> slot;
    std::array<Record,maximum_streams> records;
    std::array<std::uint32_t,maximum_streams> order{};
    pcm::Statistics final_statistics;
    std::atomic<bool> closing{};
    bool provider_joined{},closed{},order_required{},render_fault{},bank_mix_fault{};
    pcm::Status last_render_status{pcm::Status::ok};
    const bool external_output;
    bool submix_started{},submix_fenced{},source_epoch_started{};
    std::vector<float> scratch;
    State(Config c,std::shared_ptr<audio_output::CallbackSlot> s,bool external=false)
        :config(checked(c)),pcm(core_config(config)),slot(std::move(s)),external_output(external),
         scratch(external?std::size_t(audio_output::maximum_callback_frames)*2:0) {
        if((!slot && !external) || (external && (slot || config.bank_mix)))throw std::invalid_argument("One actual output owner and bank renderer required");
        if(pcm.select_frame_clock()!=pcm::Status::ok)throw std::logic_error("Stream frame clock");
        for(std::uint32_t i=0;i<config.streams;++i){
            order[i]=i;
            auto& r=records[i];
            for(auto& channel:r.channels){auto h=pcm.create_channel();
                if(h.status!=pcm::Status::ok)throw std::logic_error("Stream channel reservation");
                channel=std::move(h.value);}
            auto voice=pcm.create_voice();if(voice.status!=pcm::Status::ok)throw std::logic_error("Stream voice reservation");
            r.voice=std::move(voice.value);
        }
        if(!publish_order(order))throw std::logic_error("Initial stream order");
        if(config.bank_mix && !config.bank_mix->bind())throw std::invalid_argument("One-use bank output binding required");
    }
    bool mix_banks(float* output,std::uint32_t frames) noexcept {
        if(!config.bank_mix)return true;
        const auto result=config.bank_mix->render(output,frames);
        if(result==audio_mix_tail::Status::completed)return true;
        if(!closing.load(std::memory_order_acquire))bank_mix_fault=true;
        return false;
    }
    bool valid(std::uint32_t slot_index,std::uint64_t generation) const noexcept {
        return slot_index<config.streams && records[slot_index].active &&
            records[slot_index].generation==generation && !closed;
    }
    StreamSnapshot observe(std::uint32_t i) const noexcept {
        const auto& r=records[i];
        if(!r.active)return r.final;
        StreamSnapshot s;s.slot=i;s.generation=r.generation;s.channels=r.channel_count;
        s.frequency=r.config.frequency;s.active=true;s.transfer_open=r.transfer_open;
        s.through=r.through;s.fault=r.fault;s.orphaned=r.producer.expired();
        for(std::uint32_t c=0;c<r.channel_count;++c){const auto info=pcm.inspect(r.channels[c]);
            if(info.status==pcm::Status::ok){s.channel[c]=info.value;
                s.channel[c].queued_bytes-=r.byte_origin[c];s.channel[c].consumed_bytes-=r.byte_origin[c];}
            else s.fault=true;}
        const auto voice=pcm.inspect(r.voice);if(voice.status==pcm::Status::ok)s.voice=voice.value;else s.fault=true;
        return s;
    }
    bool count(std::uint32_t i,std::uint32_t& samples) const noexcept {
        const auto s=observe(i);
        if(!s.active || s.fault || s.channel[0].samples>samples_per_channel ||
           (s.channels==2 && s.channel[0].samples!=s.channel[1].samples))return false;
        samples=static_cast<std::uint32_t>(s.channel[0].samples);return true;
    }
    void fail(std::uint32_t i) noexcept {
        auto& r=records[i];r.fault=true;r.transfer_open=false;r.config.playing=false;
        // Private frame-clocked handles/configuration remain valid. Mute the
        // affected stream before unlocking even after a partial copy failure.
        (void)pcm.configure(r.voice,r.config,0);
    }
    bool publish_order(const std::array<std::uint32_t,maximum_streams>& proposed) noexcept {
        std::array<pcm::Voice,maximum_streams> voices;std::size_t count{};
        for(std::uint32_t i=0;i<config.streams;++i){const auto& r=records[proposed[i]];
            if(r.has_voice)voices[count++]=r.voice;}
        return pcm.set_mix_order(std::span<const pcm::Voice>(voices).first(count))==pcm::Status::ok;
    }
};
namespace {
class Renderer final:public audio_output::Renderer {
public:
    explicit Renderer(std::shared_ptr<State> state):state_(std::move(state)){}
    void render(float* output,std::uint32_t frames) noexcept override {
        auto& s=*state_;std::lock_guard lock(s.mutex);
        if(!output || frames>audio_output::maximum_callback_frames)return;
        auto out=std::span(output,std::size_t(frames)*2);
        if(s.closing.load(std::memory_order_acquire) || s.closed){std::fill(out.begin(),out.end(),0.0f);return;}
        s.last_render_status=s.pcm.render(out);
        if(s.last_render_status!=pcm::Status::ok || !s.mix_banks(output,frames)){
            if(!s.closing.load(std::memory_order_acquire))s.render_fault=true;
            s.closing.store(true,std::memory_order_release);
            std::fill(out.begin(),out.end(),0.0f);}
    }
private:std::shared_ptr<State> state_;
};
}
Status Submix::render_add(float* output,std::uint32_t frames)noexcept {
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(!output || frames>audio_output::maximum_callback_frames)return Status::invalid_input;
    if(s.closing.load(std::memory_order_acquire) || s.closed)return Status::closed;
    if(!s.submix_started)return Status::pending;
    if(!frames)return Status::completed;
    const auto count=std::size_t(frames)*2;
    s.last_render_status=s.pcm.render(std::span(s.scratch).first(count));
    if(s.last_render_status!=pcm::Status::ok){s.render_fault=true;s.closing.store(true,std::memory_order_release);return Status::fault;}
    for(std::size_t i=0;i<count;++i)output[i]+=s.scratch[i];
    return Status::completed;
}
bool Submix::source_epoch_started()const noexcept {
    const auto& s=*state_;std::lock_guard lock(s.mutex);return s.source_epoch_started;
}
Producer::Producer(std::shared_ptr<State> state,std::shared_ptr<Identity> identity)
    :state_(std::move(state)),identity_(std::move(identity)){}
Producer::~Producer()=default; // An orphan retains its bounded record until session join.
Status Producer::configure(std::uint32_t rate) noexcept {
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(!s.valid(slot_,generation_))return Status::stale_producer;
    if(s.closing.load(std::memory_order_acquire))return Status::closed;
    if(rate!=24000 && rate!=44100 && rate!=48000)return Status::invalid_input;
    auto& r=s.records[slot_];if(r.fault)return Status::fault;
    auto proposed=r.config;proposed.frequency=rate;
    if(s.pcm.configure(r.voice,proposed,0)!=pcm::Status::ok)return Status::fault;
    r.config=proposed;return Status::completed;
}
Status Producer::copy(std::span<const std::byte> left,std::span<const std::byte> right) noexcept {
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(!s.valid(slot_,generation_))return Status::stale_producer;
    if(s.closing.load(std::memory_order_acquire))return Status::closed;
    auto& r=s.records[slot_];if(r.fault)return Status::fault;
    if(!r.transfer_open)return Status::closed;
    if(left.empty() || !left.data() || left.size()%64 || left.size()>16384 ||
       (r.channel_count==1?!right.empty():right.size()!=left.size() || !right.data()))return Status::invalid_input;
    std::uint32_t samples{};
    if(!s.count(slot_,samples)){s.fail(slot_);return Status::fault;}
    if(left.size()/2>samples_per_channel-samples)return Status::capacity;
    const std::array<std::span<const std::byte>,2> planes{left,right};
    for(std::uint32_t c=0;c<r.channel_count;++c){
        const auto info=s.pcm.inspect(r.channels[c]);
        if(info.status!=pcm::Status::ok || info.value.queued_bytes>s.config.maximum_counter ||
           planes[c].size()>s.config.maximum_counter-info.value.queued_bytes)return Status::copy_refused;
    }
    for(std::uint32_t c=0;c<r.channel_count;++c)
        if(s.pcm.enqueue(r.channels[c],planes[c],0).status!=pcm::Status::ok){s.fail(slot_);return Status::fault;}
    return Status::completed;
}
Status Producer::gain(float value) noexcept {
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(!s.valid(slot_,generation_))return Status::stale_producer;
    if(s.closing.load(std::memory_order_acquire))return Status::closed;
    return s.pcm.gain(s.records[slot_].voice,value)==pcm::Status::ok?Status::completed:Status::invalid_input;
}
StreamSnapshot Producer::snapshot() const noexcept {
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(final_)return *final_;
    if(slot_>=s.config.streams || s.records[slot_].generation!=generation_){StreamSnapshot result;result.fault=true;return result;}
    return s.observe(slot_);
}
Control Producer::queued_samples(std::uint32_t& n) noexcept {
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(!s.valid(slot_,generation_) || s.closing.load(std::memory_order_acquire) || !s.count(slot_,n))return Control::fault;
    return Control::completed;
}
Control Producer::free_samples(std::uint32_t& n) noexcept {
    const auto result=queued_samples(n);if(result==Control::completed)n=samples_per_channel-n;return result;
}
Control Producer::play(bool value) noexcept {
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(!s.valid(slot_,generation_) || s.closing.load(std::memory_order_acquire))return Control::fault;
    auto& r=s.records[slot_];if(r.fault)return Control::fault;
    unsigned playing=0;
    for(std::uint32_t i=0;i<s.config.streams;++i)
        if(i!=slot_ && s.records[i].active && s.records[i].config.playing)++playing;
    if(value && playing>=2 && s.order_required)return Control::invalid_input;
    auto proposed=r.config;proposed.playing=value;
    if(s.pcm.configure(r.voice,proposed,0)!=pcm::Status::ok){s.fail(slot_);return Control::fault;}
    r.config=proposed;return Control::completed;
}
Control Producer::stop_transfer() noexcept {
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(!s.valid(slot_,generation_))return Control::fault;
    s.records[slot_].transfer_open=false;return Control::completed;
}
Control Producer::through() noexcept {
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(!s.valid(slot_,generation_))return Control::fault;
    s.records[slot_].through=true;return Control::completed;
}
Status Producer::retire() noexcept {
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(final_)return Status::completed;
    if(!s.valid(slot_,generation_))return s.closed?Status::closed:Status::stale_producer;
    auto& r=s.records[slot_];auto retained=s.observe(slot_);
    pcm::VoiceConfig disabled;disabled.channels=pcm::Channels::disabled;
    if(s.pcm.configure(r.voice,disabled,0)!=pcm::Status::ok)return Status::fault;
    for(auto& channel:r.channels)if(s.pcm.discard(channel)!=pcm::Status::ok)return Status::fault;
    if(s.pcm.release(r.voice)!=pcm::Status::ok)return Status::fault;
    r.has_voice=false;
    retained.active=false;retained.retired=true;retained.transfer_open=false;
    r.final=retained;final_=retained;r.active=false;r.transfer_open=false;r.config=disabled;r.producer.reset();
    if(r.generation==UINT64_MAX)r.exhausted=true;else ++r.generation;
    return s.publish_order(s.order)?Status::completed:Status::fault;
}
Session::Session(Config c,std::shared_ptr<audio_output::CallbackSlot> slot,std::shared_ptr<audio_output::Provider> provider)
    :state_(std::make_shared<State>(c,std::move(slot))),
     owner_(audio_output::Owner::create(*state_->slot,std::move(provider),std::make_shared<Renderer>(state_))) {
    if(!owner_)throw std::invalid_argument("Qualified session provider required");
}
Session::Session(Config c):state_(std::make_shared<State>(c,nullptr,true)),
    submix_(new Submix(state_)){}
Session::~Session(){request_stop();(void)join();}
OpenResult Session::open(std::uint32_t channels) noexcept {
    if(channels<1 || channels>2)return{Status::invalid_input,{}};
    std::unique_ptr<Producer> producer;
    try{auto identity=std::make_shared<Producer::Identity>();producer.reset(new Producer(state_,std::move(identity)));}
    catch(...){return{Status::allocation_failure,{}};}
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(s.closed || s.closing.load(std::memory_order_acquire))return{Status::closed,{}};
    for(std::uint32_t i=0;i<s.config.streams;++i){auto& r=s.records[i];if(r.active || r.exhausted)continue;
        if(!r.has_voice){auto voice=s.pcm.create_voice();if(voice.status!=pcm::Status::ok)return{Status::fault,{}};
            r.voice=std::move(voice.value);r.has_voice=true;}
        pcm::VoiceConfig config;config.left=r.channels[0];if(channels==2)config.right=r.channels[1];
        config.channels=channels==1?pcm::Channels::mono:pcm::Channels::stereo;
        if(s.pcm.configure(r.voice,config,0)!=pcm::Status::ok)return{Status::fault,{}};
        if(!s.publish_order(s.order))return{Status::fault,{}};
        for(std::uint32_t c=0;c<2;++c){const auto info=s.pcm.inspect(r.channels[c]);
            if(info.status!=pcm::Status::ok)return{Status::fault,{}};
            r.byte_origin[c]=info.value.queued_bytes;}
        producer->slot_=i;producer->generation_=r.generation;
        r.config=config;r.channel_count=channels;r.active=true;r.transfer_open=true;r.through=r.fault=false;
        r.producer=producer->identity_;s.order_required=true;s.source_epoch_started=true;
        return{Status::completed,std::move(producer)};
    }
    return{Status::capacity,{}};
}
Status Session::set_order(std::span<const Producer* const> order) noexcept {
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(s.closed || s.closing.load(std::memory_order_acquire))return Status::closed;
    std::array<bool,maximum_streams> used{};std::array<std::uint32_t,maximum_streams> proposed{};std::size_t count{};
    unsigned active=0;for(std::uint32_t i=0;i<s.config.streams;++i)active+=s.records[i].active;
    if(order.size()!=active)return Status::invalid_input;
    for(auto* producer:order){
        if(!producer || producer->state_!=state_ || !s.valid(producer->slot_,producer->generation_) || used[producer->slot_])return Status::invalid_input;
        used[producer->slot_]=true;proposed[count++]=producer->slot_;
    }
    for(std::uint32_t i=0;i<s.config.streams;++i)if(!used[i])proposed[count++]=i;
    if(!s.publish_order(proposed))return Status::fault;
    s.order=proposed;
    s.order_required=false;return Status::completed;
}
Status Session::start() noexcept {
    if(state_->closing.load(std::memory_order_acquire))return Status::closed;
    if(state_->external_output){std::lock_guard lock(state_->mutex);
        if(state_->closed || state_->closing.load(std::memory_order_acquire))return Status::closed;
        state_->submix_started=true;return Status::completed;}
    const auto result=owner_->start();
    return result==audio_output::StartResult::started || result==audio_output::StartResult::already_started?Status::completed:Status::provider_refused;
}
void Session::request_stop() noexcept {
    state_->closing.store(true,std::memory_order_release);if(owner_)owner_->request_stop();
    if(state_->config.bank_mix)state_->config.bank_mix->request_stop();
}
Status Session::join() noexcept {
    request_stop();
    if(owner_ && owner_->join()!=audio_output::JoinResult::joined)return Status::pending;
    // Provider fence first; no stream/PCM/bank data lock is held while joining.
    if(state_->config.bank_mix && !state_->config.bank_mix->join())return Status::pending;
    auto& s=*state_;std::lock_guard lock(s.mutex);
    if(s.closed)return Status::completed;
    s.provider_joined=!s.external_output;s.submix_fenced=s.external_output;s.final_statistics=s.pcm.statistics();
    for(std::uint32_t i=0;i<s.config.streams;++i){auto& r=s.records[i];if(!r.active)continue;
        r.final=s.observe(i);r.final.active=false;r.final.retired=true;r.final.transfer_open=false;r.active=false;r.transfer_open=false;}
    s.pcm.shutdown(0);s.closed=true;return Status::completed;
}
Snapshot Session::snapshot() const noexcept {
    const auto& s=*state_;std::lock_guard lock(s.mutex);Snapshot result;
    result.closing=s.closing.load(std::memory_order_acquire);result.closed=s.closed;result.provider_joined=s.provider_joined;
    result.order_required=s.order_required;result.statistics=s.closed?s.final_statistics:s.pcm.statistics();
    result.render_fault=s.render_fault;result.last_render_status=s.last_render_status;result.bank_mix_fault=s.bank_mix_fault;
    result.external_output=s.external_output;result.submix_started=s.submix_started;result.submix_fenced=s.submix_fenced;
    for(std::uint32_t i=0;i<s.config.streams;++i){result.streams[i]=s.observe(i);result.occupied+=s.records[i].active;
        result.playing+=s.records[i].active && s.records[i].config.playing;}
    return result;
}
} // namespace reo::native::adxt_output_session
