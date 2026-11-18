#include "composite_backend.h"
#include "recomp/overrides/native_adxt/runtime_observer.h"
#include "recomp/overrides/native_adxt/ordinary_runtime.h"
#include "runtime_memory.h"
#include "capture_provider_v3.h"
#include "game/native/adxt_control_owner/owner.hpp"
#include "recomp/overrides/native_audio/v4/aggregate.h"
#include "runtime/audio/native_stream_provider.h"
#include "ps2_runtime.h"
#include "ps2_syscalls.h"
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <thread>
#include <utility>

#if !defined(REO_BUILD_NATIVE_SOUND_RAM_CAPTURE) || REO_BUILD_NATIVE_SOUND_RAM_CAPTURE < 2
#error The complete sound capture candidate requires the coordinated flag2 build
#endif
#if !defined(REO_GAME_FILE1) || defined(REO_GAME_FILE2)
#error The initial complete sound candidate is restricted to File1
#endif

float reoAudioMasterGain();
float reoAudioStreamGain(std::uint32_t);
float reoAudioBankGain(unsigned,unsigned,std::uint64_t);
std::uint32_t ps2IoRegLockDepth()noexcept;
std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*)noexcept;
void reoAudioResetStreams();
void reoAudioPoll();

namespace reo::native::adxt_binding {
using NativeTickReader=bool(*)(const adxt_control_owner::Owner*,std::uint32_t&,std::shared_ptr<void>&)noexcept;
using NativeServiceWork=adxt_instances::Status(*)(const std::shared_ptr<void>&,adxt_instances::Instances&,std::uint32_t)noexcept;
namespace {
struct ServiceCallbacks {NativeTickReader reader;NativeServiceWork work;};
std::atomic<const ServiceCallbacks*> service_callbacks{};
}
bool register_native_service_callbacks(NativeTickReader reader,NativeServiceWork work)noexcept{
    if(!reader || !work)return false;
    static const ServiceCallbacks callbacks{reader,work};
    if(callbacks.reader!=reader || callbacks.work!=work)return false;
    service_callbacks.store(&callbacks,std::memory_order_release);return true;
}
bool read_registered_tick(const adxt_control_owner::Owner* owner,std::uint32_t& tick,std::shared_ptr<void>& context)noexcept{
    const auto* callbacks=service_callbacks.load(std::memory_order_acquire);
    return callbacks && callbacks->reader(owner,tick,context);
}
adxt_instances::Status run_registered_service(const std::shared_ptr<void>& context,adxt_instances::Instances& players,std::uint32_t tick)noexcept{
    const auto* callbacks=service_callbacks.load(std::memory_order_acquire);
    return callbacks?callbacks->work(context,players,tick):adxt_instances::Status::fault;
}
}

namespace reo::native::sound_ram {
namespace audio=audio_aggregate::v2;
namespace sdk=ps2_cri_audio;
namespace output=reo::audio_output;
namespace media=audio_aggregate::v4;
namespace sources=adxt_control_owner;
namespace {
class RuntimeHooks final:public audio::HostHooks {
public:
    std::int64_t now_ns() noexcept override {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();
    }
    void poll_settings() noexcept override { reoAudioPoll(); }
    float stream_gain(std::uint32_t raw) noexcept override { return reoAudioStreamGain(raw); }
    float bank_gain(unsigned port,unsigned sequence,std::uint64_t fingerprint) noexcept override {
        return reoAudioBankGain(port,sequence,fingerprint);
    }
    float master_gain() noexcept override { return reoAudioMasterGain(); }
    void reset_stream_routes() noexcept override { reoAudioResetStreams(); }
    void report_bank_paths(const audio::bank::Snapshot& value,bool counters) noexcept override {
        std::fprintf(stderr,"[NATIVE-AUDIO-BANKS] path_counters_enabled=%u voices=%zu\n",
                     unsigned(counters),value.voice_count);
    }
    void report_joined(const audio::Report& value) noexcept override {
        std::fprintf(stderr,"[NATIVE-AUDIO-REPORT] owner_joined=%u output_started=%u frames=%llu signal_frames=%llu underrun_frames=%llu hard_failures=%llu queue_rejections=%llu\n",
            unsigned(value.owner_joined),unsigned(value.host_output_started),
            static_cast<unsigned long long>(value.pcm_statistics.output_frames),
            static_cast<unsigned long long>(value.pcm_statistics.signal_frames),
            static_cast<unsigned long long>(value.pcm_statistics.underrun_frames),
            static_cast<unsigned long long>(value.hard_failures),
            static_cast<unsigned long long>(value.queue_rejections));
    }
};
class RuntimeStreamGains final:public adxt_output_session::StreamGains {
public:float factor(std::uint32_t key)noexcept override{return reoAudioStreamGain(key);}
};
class MediaHooks final:public media::HostHooks {
public:
    std::int64_t now_ns()noexcept override{return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();}
    void poll_settings()noexcept override{reoAudioPoll();}
    float stream_gain(std::uint32_t key)noexcept override{return reoAudioStreamGain(key);}
    float bank_gain(unsigned port,unsigned sequence,std::uint64_t fingerprint)noexcept override{return reoAudioBankGain(port,sequence,fingerprint);}
    float master_gain()noexcept override{return reoAudioMasterGain();}
    void reset_stream_routes()noexcept override{reoAudioResetStreams();}
    void report_bank_paths(const media::bank::Snapshot& value,bool counters)noexcept override{
        std::fprintf(stderr,"[NATIVE-AUDIO-BANKS] path_counters_enabled=%u voices=%zu\n",unsigned(counters),value.voice_count);
    }
    // The root reads the child's synchronized final report after both fences.
    // Raw legacy PCM stats are empty in the native-source profile.
    void report_joined(const media::Report&)noexcept override{}
};
// REO_NATIVE_SOURCE_SERVICE_BEGIN
// This exact block is compiled by the isolated control-starvation regression.
// All mutable native player work uses the canonical admission fence. It never
// borrows guest state, invokes a guest control or invents a clock tick.
class NativeSourceService final {
public:
    using TickReader=bool(*)(const sources::Owner*,std::uint32_t&,std::shared_ptr<void>&)noexcept;
    using Work=adxt_instances::Status(*)(const std::shared_ptr<void>&,adxt_instances::Instances&,std::uint32_t)noexcept;
    using Failure=void(*)(void*)noexcept;
    NativeSourceService(std::shared_ptr<sources::Owner> owner,TickReader reader,Work work,Failure failure,void* context)
        :owner_(std::move(owner)),reader_(reader),work_(work),failure_(failure),context_(context),worker_([this]{run();}){}
    ~NativeSourceService(){request_stop();join();}
    NativeSourceService(const NativeSourceService&)=delete;
    NativeSourceService& operator=(const NativeSourceService&)=delete;
    void request_stop()noexcept{stopping_.store(true,std::memory_order_release);wake_.notify_all();}
    void join()noexcept{if(worker_.joinable())worker_.join();}
    std::uint64_t visits()const noexcept{return visits_.load(std::memory_order_relaxed);}
    std::uint64_t order_deferrals()const noexcept{return deferrals_.load(std::memory_order_relaxed);}
private:
    struct Pump final:sources::Operation {
        std::uint32_t tick;Work work;std::shared_ptr<void> context;adxt_instances::Status status{adxt_instances::Status::completed};
        Pump(std::uint32_t value,Work fn,std::shared_ptr<void> retained):tick(value),work(fn),context(std::move(retained)){}
        void run(adxt_instances::Instances& players)noexcept override{
            status=work(context,players,tick);
            if(status==adxt_instances::Status::completed || status==adxt_instances::Status::pending)status=players.service(tick);
        }
    };
    void run()noexcept{
        while(!stopping_.load(std::memory_order_acquire)){
            std::uint32_t tick{};std::shared_ptr<void> context;
            if(reader_(owner_.get(),tick,context)){
                // The snapshot retains native feeder ownership BEFORE admission;
                // no registry lock or guest-state lookup occurs under the gate.
                Pump pump(tick,work_,std::move(context));const auto admission=owner_->run(pump);
                if(admission==sources::Admission::closed)break;
                if(admission==sources::Admission::accepted && pump.status==adxt_instances::Status::closed)break;
                if(admission==sources::Admission::accepted){
                    if(pump.status==adxt_instances::Status::order_required)++deferrals_;
                    else if(pump.status==adxt_instances::Status::completed || pump.status==adxt_instances::Status::pending)++visits_;
                }
                if(admission==sources::Admission::accepted && pump.status!=adxt_instances::Status::completed &&
                   pump.status!=adxt_instances::Status::pending && pump.status!=adxt_instances::Status::order_required){
                    if(!stopping_.load(std::memory_order_acquire))failure_(context_);
                    break;
                }
                // A third source can be between guest adoption and explicit
                // order publication. Defer; never synthesize a summation order.
            }
            std::unique_lock lock(wait_);
            wake_.wait_for(lock,std::chrono::milliseconds(4),[this]{return stopping_.load(std::memory_order_acquire);});
        }
    }
    std::shared_ptr<sources::Owner> owner_;TickReader reader_;Work work_;Failure failure_;void* context_;
    std::atomic<bool> stopping_{};std::mutex wait_;std::condition_variable wake_;
    std::atomic<std::uint64_t> visits_{},deferrals_{};
    std::thread worker_;
};
// REO_NATIVE_SOURCE_SERVICE_END
class SourceWorker final:public PS2Runtime::ExternalWorker {
    PS2Runtime* runtime_;std::shared_ptr<sources::Owner> owner_;
    NativeSourceService service_;
public:
    SourceWorker(PS2Runtime& runtime,std::shared_ptr<sources::Owner> owner):runtime_(&runtime),owner_(std::move(owner)),
        service_(owner_,adxt_binding::read_registered_tick,adxt_binding::run_registered_service,[](void* context)noexcept{
            std::fputs("[NATIVE-AUDIO-SERVICE-ERROR] native refill service failed; stopping candidate\n",stderr);
            static_cast<PS2Runtime*>(context)->requestStop();
        },&runtime){}
    void requestStop()noexcept override{service_.request_stop();owner_->request_stop();}
    bool join()noexcept override{
        if(ps2ActualGuestExecutionDepth(runtime_) || ps2IoRegLockDepth() || !sources::Owner::join_allowed_on_current_thread())return false;
        requestStop();service_.join();
        if(owner_->join()!=sources::Join::completed)return false;
        const auto report=owner_->report();
        if(report.final && !reported_.exchange(true,std::memory_order_relaxed)){
            std::fprintf(stderr,"[NATIVE-AUDIO-SERVICE-REPORT] joined=1 visits=%llu order_deferrals=%llu\n",
                (unsigned long long)service_.visits(),(unsigned long long)service_.order_deferrals());
            const auto& stats=report.final->session.output.statistics;
            std::fprintf(stderr,"[NATIVE-ADXT-SOURCE-REPORT] joined=%u frames=%llu signal_frames=%llu underrun_frames=%llu\n",
                unsigned(report.joined),(unsigned long long)stats.output_frames,
                (unsigned long long)stats.signal_frames,(unsigned long long)stats.underrun_frames);
        }
        return true;
    }
private:std::atomic<bool> reported_{};
};
class MediaPcmOrder final:public MediaInstallResult::PcmOrder {
    std::shared_ptr<media::Aggregate> owner_;
public:
    explicit MediaPcmOrder(std::shared_ptr<media::Aggregate> owner):owner_(std::move(owner)){}
    pcm_bridge::Result<std::size_t> copy(std::span<std::uint32_t> out)const noexcept override{return owner_->copy_order(out);}
};
bool observed_layout_supported() {
    const auto value=ps2_syscalls::dtxCompatLayoutSnapshot();
    return value.rpcSid==0x90000200 && value.urpcObjBase==0x001e0000 &&
        value.urpcObjLimit==0x001eff00 && value.urpcObjStride==0x20 &&
        !value.urpcFnTableBase && !value.urpcObjTableBase && !value.dispatcherFuncAddr;
}
}

// One SDK registration owns this wrapper, its child and the RAM owner. The
// child DeviceRenderer still enters the public facade, whose admitted render
// comes back through this wrapper with the SAME SoundCall for its bank stage.
class CompositeBackend final:public std::enable_shared_from_this<CompositeBackend> {
    friend struct CompositeBackendTests;
public:
    static InstallResult install(PS2Runtime& runtime,const reo_cd_async::ConfigurationReceipt& cd,
                                 bank_packets::v3::MemoryIdentity identity,
                                 std::shared_ptr<sources::Owner> native_sources={},
                                 std::shared_ptr<const MediaInstallResult::PcmOrder>* order_result=nullptr) noexcept {
        const auto* requested=std::getenv("REO_NATIVE_AUDIO");
        if(!requested || std::strcmp(requested,"1")) return {};
        try {
            // Covers preparation, allocation, SDK registration/publication and
            // explicit failure cleanup. A naked prepared profile never escapes
            // into run without its real external-worker lifetime owner.
            auto setup=runtime.acquirePreRunSetup();
            if(!setup) return {InstallStatus::phase_closed};
            if(!observed_layout_supported()) return {InstallStatus::unsupported_layout};
            auto prepared=RuntimeMemory::prepare(runtime,cd,identity);
            if(prepared.status!=MemoryPrepareStatus::ready || !prepared.owner) {
                std::fprintf(stderr,"[NATIVE-AUDIO-ERROR] memory_prepare=%u\n",unsigned(prepared.status));
                return {InstallStatus::memory_unavailable};
            }
            auto memory=std::move(prepared.owner);
            // Declaration order guarantees failure cleanup before setup ends.
            struct UnpublishedMemory {
                std::shared_ptr<RuntimeMemory> memory;
                bool installed{};
                ~UnpublishedMemory() { if(!installed) (void)memory->retire_after_outer_drain(); }
            } cleanup{memory};
            auto provider=output::NativeStreamProvider::create();
            if(!provider) return {InstallStatus::output_unavailable};
            // This is the actual process-stable slot used by the pinned native
            // provider trampoline, whose storage survives the complete Runtime.
            auto slot=std::shared_ptr<output::CallbackSlot>(&output::native_stream_callback_slot(),
                                                            [](output::CallbackSlot*) noexcept {});
            sdk::BackendRegistrationV2 child;std::shared_ptr<media::Aggregate> media_owner;
            if(native_sources){
                media::Inputs inputs;inputs.host=std::make_shared<MediaHooks>();
                inputs.capture=std::make_shared<CaptureProviderV3>(memory);inputs.provider=std::move(provider);
                inputs.slot=std::move(slot);inputs.native_streams=native_sources->submix();
                auto built=media::create(std::move(inputs));
                if(built.status!=media::BuildStatus::ready_composition || !built.owner)return {InstallStatus::aggregate_unavailable};
                child=built.owner->registration();
                media_owner=std::move(built.owner);
            }else{
                audio::Inputs inputs;inputs.host=std::make_shared<RuntimeHooks>();inputs.capture=memory;
                inputs.provider=std::move(provider);inputs.slot=std::move(slot);
                auto built=audio::create(std::move(inputs));
                if(built.status!=audio::BuildStatus::ready_composition || !built.owner)return {InstallStatus::aggregate_unavailable};
                child=built.owner->registration();
            }
            // Allocate the read-only capability BEFORE publication. Failure
            // cannot leave an installed backend without its required adapter.
            std::shared_ptr<const MediaInstallResult::PcmOrder> order;
            if(media_owner && order_result)order=std::make_shared<MediaPcmOrder>(media_owner);
            auto owner=std::shared_ptr<CompositeBackend>(new CompositeBackend(runtime,memory,std::move(child),native_sources,std::move(media_owner)));
            // Runtime requests every stop before joining workers in registration
            // order. Sources precede the SDK/device binding, including teardown
            // before run. A failed later publication leaves this stopped worker
            // inert and retained by Runtime; it is not an unregistration claim.
            if(native_sources && !runtime.registerExternalWorker(std::make_shared<SourceWorker>(runtime,native_sources))){
                (void)owner->join();return {InstallStatus::publication_refused};
            }
            const auto selected=sdk::installBackendWithNativeSoundRamBeforeRunV1(
                runtime,owner->registration(),owner->companion());
            if(selected!=sdk::BackendInstallStatusV1::installed) {
                // The SDK may retain an inert unpublished worker; it skips
                // backend shutdown/join for that state. Explicitly drain here
                // so it cannot retain our selection lease until GS teardown.
                (void)owner->join();
                return {InstallStatus::publication_refused,selected};
            }
            cleanup.installed=true;
            if(order_result)*order_result=std::move(order);
            std::fprintf(stderr,"[NATIVE-AUDIO] complete PCM/bank/RAM candidate installed pcm_bytes=%llu native_sources=%u\n",
                         static_cast<unsigned long long>(audio::production_pcm_bytes),unsigned(bool(native_sources)));
            return {InstallStatus::installed,selected};
        } catch(...) { return {InstallStatus::allocation_failed}; }
    }
private:
    std::shared_ptr<RuntimeMemory> memory_;
    PS2Runtime* runtime_;
    std::shared_ptr<sources::Owner> sources_;
    std::shared_ptr<media::Aggregate> media_;
    sdk::BackendRegistrationV2 table_;
    std::mutex lifecycle_;
    bool joined_{};
    CompositeBackend(PS2Runtime& runtime,std::shared_ptr<RuntimeMemory> memory,sdk::BackendRegistrationV2 child,
                     std::shared_ptr<sources::Owner> sources,std::shared_ptr<media::Aggregate> media)
        :memory_(std::move(memory)),runtime_(&runtime),sources_(std::move(sources)),media_(std::move(media)),table_(std::move(child)) {}
    bool join() noexcept {
        if(ps2ActualGuestExecutionDepth(runtime_) || ps2IoRegLockDepth() || !sources::Owner::join_allowed_on_current_thread())return false;
        std::lock_guard lock(lifecycle_);
        if(joined_) return true;
        // Called by Binding only after every outer facade/SoundCall drains.
        // A failed device fence retains child, pool, mappings and both seals.
        if(!table_.api.pcm.join(table_.owner.get())) return false;
        if(sources_ && sources_->join()!=sources::Join::completed)return false;
        if(media_ && (!media_->report().owner_joined || !sources_->report().final))return false;
        if(!memory_->retire_after_outer_drain()) return false;
        joined_=true;
        if(media_){
            const auto source=sources_->report();
            const auto aggregate=media_->report();
            const auto& stats=source.final->session.output.statistics;
            std::fprintf(stderr,"[NATIVE-AUDIO-REPORT] owner_joined=%u output_started=%u frames=%llu signal_frames=%llu underrun_frames=%llu hard_failures=%llu queue_rejections=%llu native_sources=1 source_joined=1 submix_calls=%llu submix_failures=%llu\n",
                unsigned(aggregate.owner_joined),unsigned(aggregate.host_output_started),
                static_cast<unsigned long long>(stats.output_frames),static_cast<unsigned long long>(stats.signal_frames),
                static_cast<unsigned long long>(stats.underrun_frames),static_cast<unsigned long long>(aggregate.hard_failures),
                static_cast<unsigned long long>(aggregate.queue_rejections),static_cast<unsigned long long>(aggregate.native_submix_calls),
                static_cast<unsigned long long>(aggregate.native_submix_failures));
        }
        const auto stats=memory_->statistics();
        std::fprintf(stderr,"[NATIVE-SOUND-RAM-REPORT] retired=%u active_slots=%llu active_operations=%llu diagnostic_reports=%llu first_refusal_or_diagnostic=%llu attempts=",
            unsigned(stats.retired),static_cast<unsigned long long>(stats.active_slots),
            static_cast<unsigned long long>(stats.active_operations),
            static_cast<unsigned long long>(stats.diagnostic_reports),
            static_cast<unsigned long long>(stats.first_failure));
        for(std::size_t i=0;i<memory_operation_count;++i)
            std::fprintf(stderr,"%s%llu",i?",":"",static_cast<unsigned long long>(stats.attempts[i]));
        std::fputs(" refused=",stderr);
        for(std::size_t i=0;i<memory_operation_count;++i)
            std::fprintf(stderr,"%s%llu",i?",":"",static_cast<unsigned long long>(stats.refused[i]));
        std::fputs(" order=begin,end,read,control,forward,snapshot,log,packet,bank,pcm,retire\n",stderr);
        return true;
    }
    bool queue(std::uint32_t channel,const std::uint8_t* bytes,std::uint32_t count,std::uint64_t& end) noexcept {
        struct Operation final:PcmOperation {
            const sdk::BackendRegistrationV2& child;
            std::uint32_t channel;
            std::uint64_t& end;
            Operation(const sdk::BackendRegistrationV2& c,std::uint32_t k,std::uint64_t& e):child(c),channel(k),end(e) {}
            bool run(std::span<const std::uint8_t> owned) noexcept override {
                return child.api.pcm.queue(child.owner.get(),channel,owned.data(),std::uint32_t(owned.size()),end);
            }
        } operation{table_,channel,end};
        return memory_->with_pcm(bytes,count,operation);
    }
    void reset_pcm()noexcept {
        if(!sources_){table_.api.pcm.reset(table_.owner.get());return;}
        struct Reset final:sources::EmptyOperation {
            media::Aggregate& media;
            explicit Reset(media::Aggregate& value):media(value){}
            void run(const sources::Quiescent& proof)noexcept override{(void)media.reset_native(&proof);}
        } reset(*media_);
        // Void SDK reset retains its diagnostic refusal on an occupied/closed
        // source owner; it cannot clear mappings or imply source completion.
        if(sources_->when_empty(reset)!=sources::Empty::completed)(void)media_->reset_native(nullptr);
    }
    sdk::BackendRegistrationV2 registration() noexcept {
        auto result=table_.api;
        auto& p=result.pcm;
        p.ensure_host_output=[](void* x) noexcept {auto& s=*static_cast<CompositeBackend*>(x);s.table_.api.pcm.ensure_host_output(s.table_.owner.get());};
        p.queue=[](void* x,std::uint32_t k,const std::uint8_t* b,std::uint32_t n,std::uint64_t& e) noexcept {return static_cast<CompositeBackend*>(x)->queue(k,b,n,e);};
        p.configure=[](void* x,std::uint32_t v,std::uint32_t l,std::uint32_t r,std::uint32_t n,std::uint32_t f,std::uint32_t volume,bool play) noexcept {auto& s=*static_cast<CompositeBackend*>(x);s.table_.api.pcm.configure(s.table_.owner.get(),v,l,r,n,f,volume,play);};
        p.consumed=[](void* x,std::uint32_t k) noexcept {auto& s=*static_cast<CompositeBackend*>(x);return s.table_.api.pcm.consumed(s.table_.owner.get(),k);};
        p.render=[](void* x,float* out,unsigned n) noexcept {auto& s=*static_cast<CompositeBackend*>(x);s.table_.api.pcm.render(s.table_.owner.get(),out,n);};
        p.discard=[](void* x,std::uint32_t k) noexcept {auto& s=*static_cast<CompositeBackend*>(x);s.table_.api.pcm.discard(s.table_.owner.get(),k);};
        p.drain=[](void* x,std::uint32_t k) noexcept {auto& s=*static_cast<CompositeBackend*>(x);s.table_.api.pcm.drain(s.table_.owner.get(),k);};
        p.release=[](void* x,std::uint32_t k) noexcept {auto& s=*static_cast<CompositeBackend*>(x);s.table_.api.pcm.release(s.table_.owner.get(),k);};
        p.queued_samples=[](void* x,std::uint32_t k) noexcept {auto& s=*static_cast<CompositeBackend*>(x);return s.table_.api.pcm.queued_samples(s.table_.owner.get(),k);};
        p.reset=[](void* x) noexcept {static_cast<CompositeBackend*>(x)->reset_pcm();};
        p.shutdown=[](void* x) noexcept {auto& s=*static_cast<CompositeBackend*>(x);if(s.sources_)s.sources_->request_stop();s.table_.api.pcm.shutdown(s.table_.owner.get());};
        p.request_stop=[](void* x) noexcept {auto& s=*static_cast<CompositeBackend*>(x);if(s.sources_)s.sources_->request_stop();s.table_.api.pcm.request_stop(s.table_.owner.get());};
        p.join=[](void* x) noexcept {return static_cast<CompositeBackend*>(x)->join();};
        auto& b=result.banks;
        b.submit_bank=[](void* x,unsigned p,const std::uint8_t* h,std::size_t hn,const std::uint8_t* d,std::size_t dn,const std::uint8_t* q,std::size_t qn) noexcept {auto& s=*static_cast<CompositeBackend*>(x);return s.table_.api.banks.submit_bank(s.table_.owner.get(),p,h,hn,d,dn,q,qn);};
        b.submit_packet=[](void* x,const std::uint8_t* r,std::size_t rn,const std::uint8_t* p,std::size_t pn) noexcept {auto& s=*static_cast<CompositeBackend*>(x);return s.table_.api.banks.submit_packet(s.table_.owner.get(),r,rn,p,pn);};
        b.mix=[](void* x,float* out,unsigned n) noexcept {auto& s=*static_cast<CompositeBackend*>(x);return s.table_.api.banks.mix(s.table_.owner.get(),out,n);};
        b.reset=[](void* x) noexcept {auto& s=*static_cast<CompositeBackend*>(x);return s.table_.api.banks.reset(s.table_.owner.get());};
        b.pending_loads=[](void* x) noexcept {auto& s=*static_cast<CompositeBackend*>(x);return s.table_.api.banks.pending_loads(s.table_.owner.get());};
        b.port_state=[](void* x,unsigned p,std::uint32_t& n) noexcept {auto& s=*static_cast<CompositeBackend*>(x);return s.table_.api.banks.port_state(s.table_.owner.get(),p,n);};
        b.se_state=[](void* x,unsigned p,unsigned q,unsigned g) noexcept {auto& s=*static_cast<CompositeBackend*>(x);return s.table_.api.banks.se_state(s.table_.owner.get(),p,q,g);};
        b.report_audio_paths=[](void* x) noexcept {auto& s=*static_cast<CompositeBackend*>(x);return s.table_.api.banks.report_audio_paths(s.table_.owner.get());};
        result.render_admitted=[](void* x,sdk::SoundCall& call,float* out,unsigned n) noexcept {auto& s=*static_cast<CompositeBackend*>(x);s.table_.api.render_admitted(s.table_.owner.get(),call,out,n);};
        return {result,shared_from_this()};
    }
    sdk::NativeSoundRamApiV1 companion() noexcept {
        sdk::NativeSoundRamApiV1 result;
        result.abi_version=sdk::nativeSoundRamAbiVersionV1;result.structure_bytes=sizeof(result);
        result.capabilities=sdk::nativeSoundRamCapabilitiesV1;result.max_packet_bytes=65536;
        result.begin=[](void* x,const sdk::SoundCall& c,PS2Runtime* r,std::uint8_t* b,sdk::NativeSoundRamUseV1 u,sdk::NativeSoundRamTokenV1& t) noexcept {return static_cast<CompositeBackend*>(x)->memory_->begin(c,r,b,u,t);};
        result.end=[](void* x,const sdk::SoundCall& c,sdk::NativeSoundRamTokenV1& t) noexcept {static_cast<CompositeBackend*>(x)->memory_->end(c,t);};
        result.read_batch=[](void* x,const sdk::SoundCall& c,sdk::NativeSoundRamTokenV1& t,std::span<const sdk::NativeSoundRamReadV1> reads) noexcept {return static_cast<CompositeBackend*>(x)->memory_->read_batch(c,t,reads);};
        result.control_batch=[](void* x,const sdk::SoundCall& c,sdk::NativeSoundRamTokenV1& t,sdk::NativeSoundRamControlV1 kind,std::span<const sdk::NativeSoundRamControlOpV1> ops) noexcept {return static_cast<CompositeBackend*>(x)->memory_->control_batch(c,t,kind,ops);};
        result.copy_forward=[](void* x,const sdk::SoundCall& c,sdk::NativeSoundRamTokenV1& t,sdk::NativeSoundRamSpaceV1 ss,std::uint32_t s,sdk::NativeSoundRamSpaceV1 ds,std::uint32_t d,std::size_t n) noexcept {return static_cast<CompositeBackend*>(x)->memory_->copy_forward(c,t,ss,s,ds,d,n);};
        result.snapshot_packet=[](void* x,const sdk::SoundCall& c,sdk::NativeSoundRamTokenV1& t,std::uint32_t at,std::size_t n,sdk::NativeSoundRamPacketV1& p) noexcept {return static_cast<CompositeBackend*>(x)->memory_->snapshot_packet(c,t,at,n,p);};
        result.log_owned_packet=[](void* x,const sdk::SoundCall& c,sdk::NativeSoundRamTokenV1& t,sdk::NativeSoundRamPacketV1 p) noexcept {return static_cast<CompositeBackend*>(x)->memory_->log_owned_packet(c,t,p);};
        result.report=[](void* x,const sdk::SoundCall& c,sdk::NativeSoundRamTokenV1& t,sdk::NativeSoundRamDiagnosticV1 d) noexcept {static_cast<CompositeBackend*>(x)->memory_->report(c,t,d);};
        return result;
    }
};
InstallResult install(PS2Runtime& runtime,const reo_cd_async::ConfigurationReceipt& cd,
                      bank_packets::v3::MemoryIdentity identity) noexcept {
    const auto* ordinary=std::getenv("REO_NATIVE_ADXT");
    if(ordinary && !std::strcmp(ordinary,"1")){
#if defined(REO_BUILD_NATIVE_RESOURCE_READS) && REO_BUILD_NATIVE_RESOURCE_READS
        return adxt_binding::install_ordinary_before_run(runtime,cd,identity);
#else
        std::fputs("[NATIVE-ADXT-ERROR] ordinary source candidate requires the coherent native resource handoff build\n",stderr);
        return {InstallStatus::unsupported_layout};
#endif
    }
    const auto result=CompositeBackend::install(runtime,cd,identity);
    if(result.status==InstallStatus::installed){
        const auto* path=std::getenv("REO_ADXT_OBSERVE_PATH");
        if(path && *path && !adxt_binding::observe_before_run(runtime))
            std::fprintf(stderr,"[ADXT-OBSERVE-ERROR] original ABI observation unavailable\n");
    }
    return result;
}
MediaInstallResult install_native_sources(PS2Runtime& runtime,const reo_cd_async::ConfigurationReceipt& cd,
                                           bank_packets::v3::MemoryIdentity identity)noexcept{
    std::shared_ptr<sources::Owner> owner;
    try{
        adxt_control_session::Config config;config.output.stream_gains=std::make_shared<RuntimeStreamGains>();
        owner=std::make_shared<sources::Owner>(std::move(config));
        auto result=install_prepared_native_sources(runtime,cd,identity,owner);
        if(result.backend.status==InstallStatus::installed)return result;
        (void)owner->join();return result;
    }catch(...){if(owner)(void)owner->join();return {{InstallStatus::allocation_failed},{},{}};}
}
MediaInstallResult install_prepared_native_sources(PS2Runtime& runtime,const reo_cd_async::ConfigurationReceipt& cd,
    bank_packets::v3::MemoryIdentity identity,const std::shared_ptr<sources::Owner>& owner)noexcept{
    try{
        auto setup=runtime.acquirePreRunSetup();if(!setup)return {{InstallStatus::phase_closed},{},{}};
        if(!owner)return {{InstallStatus::aggregate_unavailable},{},{}};
        struct Check final:sources::Operation {
            bool empty{};
            void run(adxt_instances::Instances& players)noexcept override{
                const auto state=players.snapshot();empty=!state.closing && !state.instances && !state.pending && !state.retiring && !state.session.records && !state.session.retiring && !state.session.service_busy && !state.session.guard_fault && !state.session.output.occupied;
            }
        } check;
        if(owner->run(check)!=sources::Admission::accepted || !check.empty)return {{InstallStatus::aggregate_unavailable},{},{}};
        std::shared_ptr<const MediaInstallResult::PcmOrder> order;
        const auto result=CompositeBackend::install(runtime,cd,identity,owner,&order);
        if(result.status==InstallStatus::installed)return {result,owner,std::move(order)};
        return {result,{},{}};
    }catch(...){return {{InstallStatus::allocation_failed},{},{}};}
}
} // namespace reo::native::sound_ram
