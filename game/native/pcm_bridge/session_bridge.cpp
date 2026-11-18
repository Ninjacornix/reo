#include "session_bridge.hpp"
#include <algorithm>
#include <atomic>
#include <cmath>
#include <condition_variable>
#include <limits>
#include <memory_resource>
#include <mutex>
#include <stdexcept>
#include <unordered_map>
#include <vector>

namespace reo::native::pcm_bridge {
namespace {
struct ChannelBinding { core::Channel handle; bool visible{}; };
struct VoiceBinding { core::Voice handle; std::uint32_t left{}, right{}; };
// The source uses default unordered_map insertion/erase/clear, without reserve.
// A bounded resource changes allocation ownership, not those map operations.
template<class T> struct BoundedMap {
    std::vector<std::byte> storage;
    std::pmr::monotonic_buffer_resource arena;
    std::pmr::unsynchronized_pool_resource pool;
    std::pmr::unordered_map<std::uint32_t,T> values;
    BoundedMap(std::size_t bytes, std::uint32_t count)
        : storage(bytes), arena(storage.data(), storage.size(), std::pmr::null_memory_resource()),
          pool(&arena), values(&pool) {
        // Prime allocation classes with a TEMPORARY map. Do not reserve/rehash
        // the real map: its bucket history is part of the float-order contract.
        std::pmr::unordered_map<std::uint32_t,T> temporary(&pool);
        for (std::uint32_t n=0; n<count; ++n) temporary.emplace(n,T{});
    }
};
core::Config config(Domain d) {
    if (d.version!=1 || !d.max_channels || !d.max_voices ||
        d.max_render_frames<12000 || !d.channel_metadata_bytes || !d.voice_metadata_bytes)
        throw std::invalid_argument("Invalid PCM bridge bounded domain");
    core::Config c;
    c.max_channels=d.max_channels; c.max_voices=d.max_voices;
    c.max_render_frames=d.max_render_frames;
    c.allow_shared_channels=true; c.allow_missing_channels=true;
    return c;
}
// A linked stack avoids allocation and detects self-shutdown across nested
// ensure_output -> render calls, without mistaking another session for this one.
struct CallFrame {
    const void* owner;
    CallFrame* previous;
    static thread_local CallFrame* current;
    explicit CallFrame(const void* p):owner(p),previous(current){current=this;}
    ~CallFrame(){current=previous;}
    static bool contains(const void* p) {
        for (auto* f=current;f;f=f->previous) if(f->owner==p) return true;
        return false;
    }
};
thread_local CallFrame* CallFrame::current=nullptr;
}
struct Session::State {
    std::shared_ptr<Host> host;
    Domain domain;
    core::Session core;
    BoundedMap<ChannelBinding> channels;
    BoundedMap<VoiceBinding> voices;
    std::vector<core::Voice> ordered;
    std::vector<float> gains;
    mutable std::mutex data, gate;
    std::mutex shutdown_gate;
    std::condition_variable changed;
    std::size_t active{};
    bool first_used{}, admission_open{true}, finished{};
    std::atomic<Status> fault{Status::ok};
    State(std::shared_ptr<Host> h, Domain d)
      :host(std::move(h)),domain(d),core(config(d),host ? host->now_ns():0),
       channels(d.channel_metadata_bytes,d.max_channels),
       voices(d.voice_metadata_bytes,d.max_voices),ordered(d.max_voices),gains(d.max_voices) {
        if(!host)throw std::invalid_argument("PCM bridge needs an owned host");
    }
    struct Lease {
        State& s;
        bool accepted{};
        CallFrame frame;
        Status status;
        explicit Lease(State& value):s(value),frame(&value) {
            std::lock_guard lock(s.gate);
            s.first_used=true;
            const auto fault=s.fault.load();
            status=fault!=Status::ok?fault:(!s.admission_open?Status::closed:Status::ok);
            if(status==Status::ok){++s.active;accepted=true;}
        }
        ~Lease(){if(accepted){std::lock_guard lock(s.gate);--s.active;s.changed.notify_all();}}
    };
    Status fail(Status value) {
        std::lock_guard lock(gate);
        fault=value; admission_open=false;
        return value;
    }
    Status checked(core::Status value) {
        return value==core::Status::ok?Status::ok:fail(Status::core_refused);
    }
    Status order() {
        std::size_t n=0;
        for(const auto& row:voices.values) ordered[n++]=row.second.handle;
        return checked(core.set_mix_order({ordered.data(),n}));
    }
    Status refresh_gains() {
        std::size_t n=0;
        // All source gain reads happen before any frame. Stage the values so an
        // unsupported hook result cannot apply just a prefix of a gain batch.
        bool valid=true;
        for(const auto& row:voices.values) {
            const float gain=host->stream_gain(row.first);
            gains[n++]=gain;
            valid&=std::isfinite(gain)&&gain>=0&&gain<=8;
        }
        if(!valid)return fail(Status::unsupported_gain);
        n=0;
        for(const auto& row:voices.values) {
            auto status=checked(core.gain(row.second.handle,gains[n++]));
            if(status!=Status::ok)return status;
        }
        return order();
    }
    Status tick() {
        host->poll_settings();
        const auto now=host->now_ns();
        const auto clock=core.clock();
        if(host->output_ready() || clock.frame_clock || now<=clock.last_tick_ns)return Status::ok;
        const auto elapsed=std::uint64_t(now)-std::uint64_t(clock.last_tick_ns);
        if(elapsed>std::numeric_limits<std::uint64_t>::max()/48000)
            return fail(Status::core_refused);
        if(elapsed*48000/1000000000ULL) {
            const auto status=refresh_gains();
            if(status!=Status::ok)return status;
        }
        return checked(core.advance_headless(now));
    }
    bool channel_room(std::uint32_t left, std::uint32_t right) const {
        std::size_t extra=left&&!channels.values.contains(left);
        extra+=right&&right!=left&&!channels.values.contains(right);
        return extra<=domain.max_channels-channels.values.size();
    }
    core::Channel channel(std::uint32_t raw) {
        if(!raw)return {};
        auto [i,added]=channels.values.try_emplace(raw);
        if(added) {
            auto made=core.create_channel();
            if(made.status!=core::Status::ok){channels.values.erase(i);fail(Status::core_refused);return {};}
            i->second.handle=made.value;
        }
        return i->second.handle;
    }
    Status reset_locked() {
        host->reset_stream_routes();
        auto status=checked(core.reset(host->now_ns()));
        channels.values.clear(); voices.values.clear();
        return status;
    }
};

Session::Session(std::shared_ptr<Host> host, Domain domain)
    :state_(std::make_unique<State>(std::move(host),domain)){}
Session::~Session()=default;
PreRunState Session::pre_run_state() const noexcept {
    const auto& s=*state_;std::lock_guard lock(s.gate);
    return {s.domain,!s.first_used,s.fault==Status::ok,s.admission_open,false};
}
Status Session::ensureHostOutput() noexcept {
    auto& s=*state_;State::Lease lease(s);if(!lease.accepted)return lease.status;
    s.host->poll_settings();s.host->ensure_output();return Status::ok;
}
Status Session::queue(std::uint32_t raw,const std::uint8_t* bytes,std::uint32_t length,
                       std::uint64_t& end) noexcept {
    auto& s=*state_;State::Lease lease(s);if(!lease.accepted)return lease.status;
    if(!raw||!bytes||!length||(length&1)||length>0x4000)return Status::invalid_input;
    s.host->ensure_output();
    std::lock_guard lock(s.data);
    if(!s.channel_room(raw,0))return Status::domain_capacity;
    const auto tick=s.tick();if(tick!=Status::ok)return tick;
    try {
        auto h=s.channel(raw);
        if(s.fault!=Status::ok)return s.fault;
        s.channels.values.at(raw).visible=true;
        const auto result=s.core.enqueue(h,{reinterpret_cast<const std::byte*>(bytes),length},
                                         s.core.clock().last_tick_ns);
        if(result.status==core::Status::capacity)return Status::queue_full;
        const auto status=s.checked(result.status);
        if(status==Status::ok)end=result.value;
        return status;
    } catch(const std::bad_alloc&) {return s.fail(Status::metadata_capacity);}
}
Status Session::configure(std::uint32_t raw,std::uint32_t left,std::uint32_t right,
                           std::uint32_t count,std::uint32_t frequency,
                           std::uint32_t volume,bool playing) noexcept {
    auto& s=*state_;State::Lease lease(s);if(!lease.accepted)return lease.status;
    const auto nch=std::min(count,2u);
    if(nch==2 && left && left==right)return Status::unsupported_alias;
    s.host->ensure_output();
    std::lock_guard lock(s.data);
    if((!s.voices.values.contains(raw)&&s.voices.values.size()==s.domain.max_voices)||
       !s.channel_room(left,nch==2?right:0))return Status::domain_capacity;
    // Tick OLD configuration/order before creating a raw voice, latent channel
    // or rehash. Frozen last_tick suppresses the core's second implicit tick.
    const auto tick=s.tick();if(tick!=Status::ok)return tick;
    try {
        const auto l=s.channel(left),r=nch==2?s.channel(right):core::Channel{};
        if(s.fault!=Status::ok)return s.fault;
        auto [i,added]=s.voices.values.try_emplace(raw);
        if(added) {
            auto made=s.core.create_voice();
            if(made.status!=core::Status::ok){s.voices.values.erase(i);return s.fail(Status::core_refused);}
            i->second.handle=made.value;
        }
        auto status=s.checked(s.core.configure(i->second.handle,
            {l,r,static_cast<core::Channels>(nch),frequency,volume,playing},s.core.clock().last_tick_ns));
        if(status!=Status::ok)return status;
        i->second.left=left;i->second.right=right;
        return s.order();
    } catch(const std::bad_alloc&) {return s.fail(Status::metadata_capacity);}
}
Result<std::uint64_t> Session::consumed(std::uint32_t raw) noexcept {
    auto& s=*state_;State::Lease lease(s);if(!lease.accepted)return {lease.status,0};
    std::lock_guard lock(s.data);
    auto status=s.tick();if(status!=Status::ok)return {status,0};
    const auto i=s.channels.values.find(raw);
    if(i==s.channels.values.end()||!i->second.visible)return {Status::ok,0};
    const auto result=s.core.consumed(i->second.handle,s.core.clock().last_tick_ns);
    return {s.checked(result.status),result.value};
}
Status Session::render(float* stereo,std::uint32_t frames) noexcept {
    auto& s=*state_;State::Lease lease(s);if(!lease.accepted)return lease.status;
    if(frames>s.domain.max_render_frames)return Status::invalid_input;
    {
        std::lock_guard lock(s.data);
        auto status=s.refresh_gains();if(status!=Status::ok)return status;
        status=s.checked(stereo?s.core.render({stereo,std::size_t(frames)*2}):s.core.advance_frames(frames));
        if(status!=Status::ok)return status;
    }
    s.host->mix_banks(stereo,frames);
    const float master=s.host->master_gain();
    if(!std::isfinite(master)||master<0||master>8)return s.fail(Status::unsupported_gain);
    if(stereo)for(std::size_t n=0;n<std::size_t(frames)*2;++n)
        stereo[n]=std::clamp(stereo[n]*master,-1.0f,1.0f);
    return Status::ok;
}
Status Session::discard(std::uint32_t raw) noexcept {
    auto& s=*state_;State::Lease lease(s);if(!lease.accepted)return lease.status;
    std::lock_guard lock(s.data);const auto i=s.channels.values.find(raw);
    return i==s.channels.values.end()?Status::ok:s.checked(s.core.discard(i->second.handle));
}
Status Session::drain(std::uint32_t raw) noexcept {
    auto& s=*state_;State::Lease lease(s);if(!lease.accepted)return lease.status;
    std::lock_guard lock(s.data);const auto i=s.voices.values.find(raw);
    return i==s.voices.values.end()?Status::ok:s.checked(s.core.drain(i->second.handle));
}
Status Session::release(std::uint32_t raw) noexcept {
    auto& s=*state_;State::Lease lease(s);if(!lease.accepted)return lease.status;
    std::lock_guard lock(s.data);const auto i=s.voices.values.find(raw);
    if(i==s.voices.values.end())return Status::ok;
    auto status=s.checked(s.core.release(i->second.handle));if(status!=Status::ok)return status;
    s.voices.values.erase(i);return s.order();
}
Result<std::size_t> Session::queuedSamples(std::uint32_t raw) noexcept {
    auto& s=*state_;State::Lease lease(s);if(!lease.accepted)return {lease.status,0};
    std::lock_guard lock(s.data);const auto i=s.channels.values.find(raw);
    if(i==s.channels.values.end()||!i->second.visible)return {Status::ok,0};
    const auto result=s.core.inspect(i->second.handle);
    return {s.checked(result.status),result.value.samples};
}
Status Session::reset() noexcept {
    auto& s=*state_;State::Lease lease(s);if(!lease.accepted)return lease.status;
    std::lock_guard lock(s.data);return s.reset_locked();
}
void Session::close_admission() noexcept {
    auto& s=*state_;std::lock_guard lock(s.gate);s.admission_open=false;
}
Status Session::shutdown() noexcept {
    auto& s=*state_;
    if(CallFrame::contains(&s))return Status::reentrant_shutdown;
    std::lock_guard lifecycle(s.shutdown_gate);
    CallFrame frame(&s);
    {
        std::unique_lock lock(s.gate);
        s.first_used=true;s.admission_open=false;
        while(s.active)s.changed.wait(lock);
        if(s.finished)return Status::ok;
    }
    if(!s.host->stop_join_output())return Status::output_fence_required;
    {
        std::lock_guard lock(s.data);
        const auto status=s.reset_locked();if(status!=Status::ok)return status;
    }
    s.host->reset_banks();
    std::lock_guard lock(s.gate);s.finished=true;return Status::ok;
}
ChannelObservation Session::inspect_channel(std::uint32_t raw) const noexcept {
    auto& s=*state_;std::lock_guard lock(s.data);const auto i=s.channels.values.find(raw);
    return i==s.channels.values.end()?ChannelObservation{}:
        ChannelObservation{i->second.visible,s.core.inspect(i->second.handle).value};
}
VoiceObservation Session::inspect_voice(std::uint32_t raw) const noexcept {
    auto& s=*state_;std::lock_guard lock(s.data);const auto i=s.voices.values.find(raw);
    return i==s.voices.values.end()?VoiceObservation{}:
        VoiceObservation{i->second.left,i->second.right,s.core.inspect(i->second.handle).value};
}
Status Session::copy_samples(std::uint32_t raw,std::span<std::int16_t> dst) const noexcept {
    auto& s=*state_;std::lock_guard lock(s.data);const auto i=s.channels.values.find(raw);
    if(i==s.channels.values.end())return dst.empty()?Status::ok:Status::invalid_input;
    return s.core.copy_samples(i->second.handle,dst)==core::Status::ok?Status::ok:Status::invalid_input;
}
Result<std::size_t> Session::copy_order(std::span<std::uint32_t> dst) const noexcept {
    auto& s=*state_;std::lock_guard lock(s.data);
    if(dst.size()<s.voices.values.size())return {Status::invalid_input,s.voices.values.size()};
    std::size_t n=0;for(const auto& row:s.voices.values)dst[n++]=row.first;
    return {Status::ok,n};
}
std::size_t Session::voice_bucket_count() const noexcept {
    auto& s=*state_;std::lock_guard lock(s.data);return s.voices.values.bucket_count();
}
core::Statistics Session::statistics() const noexcept {
    auto& s=*state_;std::lock_guard lock(s.data);return s.core.statistics();
}
core::Clock Session::clock() const noexcept {
    auto& s=*state_;std::lock_guard lock(s.data);return s.core.clock();
}
} // namespace reo::native::pcm_bridge
