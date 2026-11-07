// Derived from frozen Aggregate2; native stream-only composition profile.
// Mechanically derived from frozen Aggregate1 by derive.py; grouped packet3 contract.
#include "aggregate.h"
#include "Kernel/Syscalls/Helpers/CriAudio.h"
#include "recomp/overrides/native_banks/v3/backend_status.h"
#include <algorithm>
#include <atomic>
#include <mutex>
#include <stdexcept>
#include <utility>

namespace reo::native::audio_aggregate::v3 {
namespace a=ps2_cri_audio;
namespace {
struct Frame {
    const void* owner;bool device;Frame* previous;static thread_local Frame* current;
    Frame(const void* p,bool d=false):owner(p),device(d),previous(current){current=this;}
    ~Frame(){current=previous;}
    static bool contains(const void* p){for(auto* f=current;f;f=f->previous)if(f->owner==p)return true;return false;}
    static bool device_thread(){for(auto* f=current;f;f=f->previous)if(f->device)return true;return false;}
};
thread_local Frame* Frame::current=nullptr;
struct Metrics {
    std::array<std::atomic<std::uint64_t>,operation_count> attempts{},completed{},refused{};
    std::atomic<std::uint64_t> hard{},first_hard{},queue_rejections{},device_calls{},device_frames{},device_completed{},
        stops{},joins{},self_refused{},fence_failures{},packets{},commands{},consumed{};
    void hard_failure(Operation op,unsigned code,std::uint32_t raw=0)noexcept {
        ++hard;
        std::uint64_t empty=0;first_hard.compare_exchange_strong(empty,(std::uint64_t(unsigned(op)+1)<<56)|(std::uint64_t(code)<<48)|raw);
    }
    void refuse(Operation op,unsigned code,std::uint32_t raw=0,bool hard_fault=true)noexcept {++refused[std::size_t(op)];if(hard_fault)hard_failure(op,code,raw);}
    bool checked(Operation op,pcm::Status status,std::uint32_t raw=0)noexcept {
        if(status==pcm::Status::ok){++completed[std::size_t(op)];return true;}
        if(status==pcm::Status::queue_full){++queue_rejections;refuse(op,unsigned(status),raw,false);}
        else refuse(op,unsigned(status),raw);
        return false;
    }
    std::atomic<std::uint64_t> native_calls{},native_frames{},native_failures{};
    packet::Status checked(Operation op,packet::Status status)noexcept {
        if(status==packet::Status::ok)++completed[std::size_t(op)];
        else refuse(op,128+unsigned(status),0,status==packet::Status::unsupported||status==packet::Status::foreign_runtime||status==packet::Status::capture_failed);
        return status;
    }
};
struct OperationFrame {
    Metrics& m;Operation op;Frame frame;
    OperationFrame(Metrics& v,Operation o,const void* state):m(v),op(o),frame(state){++m.attempts[std::size_t(op)];}
};
struct Host final:pcm::Host {
    std::shared_ptr<HostHooks> hooks;
    std::shared_ptr<Metrics> metrics;
    std::shared_ptr<output::Owner> output;
    std::shared_ptr<packet::PacketAdapter> packets;
    std::shared_ptr<bank::Session> banks;
    std::shared_ptr<TestRenderProbe> test_probe;
    std::shared_ptr<adxt_output_session::Submix> native_streams;
    std::atomic<bool> ready{},ever_started{},closing{};
    std::mutex ensure_mutex,render_mutex;
    const a::SoundCall* render_call{}; // ONLY within render_mutex, never TLS selection
    a::BankStatusV2 bank_result{a::BankStatusV2::ok};
    bool inner_joined{};
    Host(std::shared_ptr<HostHooks> h,std::shared_ptr<Metrics> m,std::shared_ptr<packet::PacketAdapter> p,std::shared_ptr<bank::Session> b)
        :hooks(std::move(h)),metrics(std::move(m)),packets(std::move(p)),banks(std::move(b)){}
    std::int64_t now_ns()noexcept override{return hooks->now_ns();}
    void poll_settings()noexcept override{hooks->poll_settings();}
    float stream_gain(std::uint32_t raw)noexcept override{return hooks->stream_gain(raw);}
    float master_gain()noexcept override{return hooks->master_gain();}
    void reset_stream_routes()noexcept override{hooks->reset_stream_routes();}
    void ensure_output()noexcept override {
        std::lock_guard lock(ensure_mutex);if(closing.load(std::memory_order_acquire))return;
        ready.store(true,std::memory_order_release); // callback may start during attach
        const auto result=output->start();
        if(result==output::StartResult::started||result==output::StartResult::already_started){ever_started.store(true);ready.store(true);}
        else if(!ever_started.load())ready.store(false,std::memory_order_release);
    }
    bool output_ready()noexcept override{return ready.load(std::memory_order_acquire);}
    void mix_banks(float* out,std::uint32_t frames)noexcept override {
        if(!render_call){bank_result=a::BankStatusV2::rejected;return;}
        if(test_probe)test_probe->after_pcm_before_banks();
        if(native_streams){
            ++metrics->native_calls;
            const auto status=native_streams->render_add(out,frames);
            if(status==adxt_output_session::Status::completed)metrics->native_frames.fetch_add(frames);
            else if(status!=adxt_output_session::Status::closed && status!=adxt_output_session::Status::pending){
                ++metrics->native_failures;bank_result=a::BankStatusV2::rejected;return;
            }
        }
        bank_result=render_call->mix(out,frames);
    }
    bool stop_join_output()noexcept override {
        const bool joined=output->join()==output::JoinResult::joined;
        if(joined)ready.store(false,std::memory_order_release);return joined;
    }
    void reset_banks()noexcept override {
        packets->request_stop();packets->join();banks->request_stop();inner_joined=banks->join();
    }
    void signal_stop()noexcept {closing.store(true,std::memory_order_release);output->request_stop();}
};
struct RenderScope {
    Host& host;
    explicit RenderScope(Host& h,const a::SoundCall& call):host(h){host.render_call=&call;host.bank_result=a::BankStatusV2::ok;}
    ~RenderScope(){host.render_call=nullptr;}
};
struct Gains final:bank::GainProvider {
    HostHooks& hooks;explicit Gains(HostHooks& h):hooks(h){}
    float gain(unsigned p,unsigned q,std::uint64_t fingerprint)noexcept override{return hooks.bank_gain(p,q,fingerprint);}
};
}
pcm::Domain production_domain()noexcept {
    pcm::Domain d;d.max_channels=production_channels;d.max_voices=production_voices;d.max_render_frames=16384;
    d.channel_metadata_bytes=d.voice_metadata_bytes=2u*1024u*1024u;return d;
}
struct Aggregate::State {
    Inputs inputs;const pcm::Domain domain;const bool testing;const packet::MemoryIdentity capture_identity;
    std::shared_ptr<Metrics> metrics=std::make_shared<Metrics>();
    std::shared_ptr<bank::Session> banks;
    std::shared_ptr<packet::PacketAdapter> packets;
    std::shared_ptr<Host> host;
    pcm::Session bridge;
    std::mutex lifecycle;mutable std::mutex report_mutex;
    bool finished{},snapshot_taken{},reported{},shutdown_accounted{};
    Report saved,published;
    State(Inputs i,pcm::Domain d,bool test,std::shared_ptr<TestRenderProbe> probe):inputs(std::move(i)),domain(d),testing(test),capture_identity(inputs.capture->identity()),
        banks(std::make_shared<bank::Session>(inputs.banks)),
        packets(std::make_shared<packet::PacketAdapter>(banks,capture_identity,inputs.packets)),
        host(std::make_shared<Host>(inputs.host,metrics,packets,banks)),bridge(host,d){host->test_probe=std::move(probe);host->native_streams=inputs.native_streams;}
    bool raw(Operation op,std::uint32_t id)noexcept {
        if(testing||id==0||(id>=0x1e0000&&id<0x1eff00&&(id-0x1e0000)%0x20==0))return true;
        metrics->refuse(op,254,id);return false;
    }
    void capture_report()noexcept {
        saved.testing_profile=testing;saved.pcm_domain=domain;saved.capture_identity=capture_identity;saved.declared_pcm_bytes=std::uint64_t(domain.max_channels)*96000*2;
        saved.captured_after_fence=true;saved.host_output_started=host->ever_started.load();saved.stream_fenced=saved.host_output_started;
        saved.bank_path_counters_enabled=inputs.banks.path_counters;
        saved.pcm_statistics=bridge.statistics();saved.pcm_clock=bridge.clock();saved.banks=banks->snapshot();saved.asset_budget=banks->budget_observer()->snapshot();saved.control_budget=packets->control_budget();
        snapshot_taken=true;
        {std::lock_guard lock(report_mutex);published=saved;}
    }
    void counters(Report& r)const noexcept {
        r.native_streams_bound=bool(inputs.native_streams);r.native_submix_calls=metrics->native_calls.load();r.native_submix_frames=metrics->native_frames.load();r.native_submix_failures=metrics->native_failures.load();
        const auto& m=*metrics;for(std::size_t n=0;n<operation_count;++n){r.attempts[n]=m.attempts[n].load();r.completed[n]=m.completed[n].load();r.refused[n]=m.refused[n].load();}
        r.hard_failures=m.hard.load();r.first_hard_failure=m.first_hard.load();r.queue_rejections=m.queue_rejections.load();
        r.device_renderer_calls=m.device_calls.load();r.device_frame_requests=m.device_frames.load();r.device_renders_completed=m.device_completed.load();
        r.stop_signals=m.stops.load();r.join_attempts=m.joins.load();r.self_join_refusals=m.self_refused.load();r.fence_failures=m.fence_failures.load();
        r.packets_accepted=m.packets.load();r.packet_commands=m.commands.load();r.packet_consumed_bytes=m.consumed.load();
    }
};
class DeviceRenderer final:public output::Renderer {
    std::weak_ptr<Aggregate> owner_;
public:
    explicit DeviceRenderer(const std::shared_ptr<Aggregate>& owner):owner_(owner){}
    void render(float* out,std::uint32_t frames)noexcept override {
        if(auto owner=owner_.lock()){
            auto& s=*owner->state_;Frame frame(&s,true);++s.metrics->device_calls;s.metrics->device_frames.fetch_add(frames);
            // CRITICAL: do not call Aggregate::render_admitted directly.
            a::render(out,frames);
        }else if(out&&frames<=output::maximum_callback_frames)std::fill_n(out,std::size_t(frames)*2,0.0f);
    }
};
Aggregate::Aggregate(Inputs i,pcm::Domain d,bool t,std::shared_ptr<TestRenderProbe> probe):state_(std::make_unique<State>(std::move(i),d,t,std::move(probe))){}
Aggregate::~Aggregate()=default;
bool Aggregate::initialize_output(){auto& s=*state_;s.host->output=output::Owner::create(*s.inputs.slot,s.inputs.provider,std::make_shared<DeviceRenderer>(shared_from_this()));return bool(s.host->output);}
BuildResult create(Inputs inputs)noexcept {
    if(!inputs.host||!inputs.capture||!inputs.provider||!inputs.slot)return {BuildStatus::invalid_inputs,{}};
    if(inputs.banks.max_render_frames<production_domain().max_render_frames)return {BuildStatus::invalid_inputs,{}};
    if(inputs.provider->source_sha256()!=output::provider_source_sha256)return {BuildStatus::provider_rejected,{}};
    try{auto owner=std::shared_ptr<Aggregate>(new Aggregate(std::move(inputs),production_domain(),false));if(!owner->initialize_output())return {BuildStatus::provider_rejected,{}};return {BuildStatus::ready_composition,std::move(owner)};}
    catch(const std::invalid_argument&){return {BuildStatus::invalid_inputs,{}};}catch(...){return {BuildStatus::allocation_failed,{}};}
}
BuildResult create_for_tests(Inputs inputs,TestDomain t)noexcept {
    if(!inputs.host||!inputs.capture||!inputs.provider||!inputs.slot||!t.channels||!t.voices||t.max_render_frames<12000||!t.metadata_bytes||inputs.banks.max_render_frames<t.max_render_frames)return {BuildStatus::invalid_inputs,{}};
    if(inputs.provider->source_sha256()!=output::provider_source_sha256)return {BuildStatus::provider_rejected,{}};
    pcm::Domain d;d.max_channels=t.channels;d.max_voices=t.voices;d.max_render_frames=t.max_render_frames;d.channel_metadata_bytes=d.voice_metadata_bytes=t.metadata_bytes;
    try{auto owner=std::shared_ptr<Aggregate>(new Aggregate(std::move(inputs),d,true,std::move(t.render_probe)));if(!owner->initialize_output())return {BuildStatus::provider_rejected,{}};return {BuildStatus::ready_composition,std::move(owner)};}
    catch(const std::invalid_argument&){return {BuildStatus::invalid_inputs,{}};}catch(...){return {BuildStatus::allocation_failed,{}};}
}
void Aggregate::signal_stop()noexcept {++state_->metrics->stops;state_->host->signal_stop();/* keep bridge/packet/bank admission OPEN until outer drain */}
bool Aggregate::finish_after_outer_drain()noexcept {
    auto& s=*state_;++s.metrics->joins;signal_stop();
    if(Frame::contains(&s)){++s.metrics->self_refused;return false;}
    Report report;bool emit=false;
    {
        std::lock_guard lifecycle(s.lifecycle);if(s.finished)return true;
        // Only the selected Binding lifecycle invokes this after ALL SoundCalls
        // drain. No PCM/bank/render/RPC/guest lock may be held by its caller.
        if(!s.host->stop_join_output()){++s.metrics->fence_failures;return false;}
        if(!s.snapshot_taken)s.capture_report();
        if(s.bridge.shutdown()!=pcm::Status::ok){s.metrics->refuse(Operation::shutdown,253);return false;}
        if(!s.host->inner_joined)s.host->reset_banks();
        if(!s.host->inner_joined){s.metrics->refuse(Operation::shutdown,252);return false;}
        s.finished=true;
        if(!s.shutdown_accounted&&s.metrics->attempts[std::size_t(Operation::shutdown)].load()){++s.metrics->completed[std::size_t(Operation::shutdown)];s.shutdown_accounted=true;}
        s.saved.owner_joined=true;s.counters(s.saved);
        {std::lock_guard lock(s.report_mutex);s.published=s.saved;report=s.published;}
        emit=!std::exchange(s.reported,true);
    }
    if(emit)s.inputs.host->report_joined(report);return true;
}
void Aggregate::ensure_output()noexcept {auto& s=*state_;OperationFrame f(*s.metrics,Operation::ensure_output,&s);s.metrics->checked(Operation::ensure_output,s.bridge.ensureHostOutput());}
bool Aggregate::queue(std::uint32_t id,const std::uint8_t* bytes,std::uint32_t count,std::uint64_t& end)noexcept {
    auto& s=*state_;OperationFrame f(*s.metrics,Operation::queue,&s);if(s.inputs.native_streams){s.metrics->refuse(Operation::queue,249,id);return false;}if(!s.raw(Operation::queue,id))return false;
    return s.metrics->checked(Operation::queue,s.bridge.queue(id,bytes,count,end),id);
}
void Aggregate::configure(std::uint32_t id,std::uint32_t l,std::uint32_t r,std::uint32_t n,std::uint32_t rate,std::uint32_t volume,bool playing)noexcept {
    auto& s=*state_;OperationFrame f(*s.metrics,Operation::configure,&s);
    if(s.inputs.native_streams && playing){s.metrics->refuse(Operation::configure,249,id);return;}
    if(s.raw(Operation::configure,id)&&s.raw(Operation::configure,l)&&(std::min(n,2u)!=2||s.raw(Operation::configure,r)))s.metrics->checked(Operation::configure,s.bridge.configure(id,l,r,n,rate,volume,playing),id);
}
std::uint64_t Aggregate::consumed(std::uint32_t id)noexcept {auto& s=*state_;OperationFrame f(*s.metrics,Operation::consumed,&s);if(!s.raw(Operation::consumed,id))return 0;auto r=s.bridge.consumed(id);return s.metrics->checked(Operation::consumed,r.status,id)?r.value:0;}
void Aggregate::render_admitted(a::SoundCall& call,float* out,unsigned frames)noexcept {
    auto& s=*state_;OperationFrame f(*s.metrics,Operation::render,&s);
    if(frames>s.domain.max_render_frames){s.metrics->refuse(Operation::render,unsigned(pcm::Status::invalid_input));return;}
    if(out)std::fill_n(out,std::size_t(frames)*2,0.0f);
    std::lock_guard lock(s.host->render_mutex);RenderScope render(*s.host,call);
    const auto status=s.bridge.render(out,frames);
    if(status!=pcm::Status::ok||s.host->bank_result!=a::BankStatusV2::ok){
        if(status!=pcm::Status::ok)s.metrics->checked(Operation::render,status);
        else s.metrics->refuse(Operation::render,128+unsigned(s.host->bank_result));
        if(out)std::fill_n(out,std::size_t(frames)*2,0.0f);return;
    }
    ++s.metrics->completed[std::size_t(Operation::render)];if(Frame::device_thread())++s.metrics->device_completed;
}
void Aggregate::compatibility_render(float* out,unsigned frames)noexcept {auto& s=*state_;++s.metrics->attempts[std::size_t(Operation::render)];s.metrics->refuse(Operation::render,251);if(out&&frames<=s.domain.max_render_frames)std::fill_n(out,std::size_t(frames)*2,0.0f);}
void Aggregate::discard(std::uint32_t id)noexcept {auto& s=*state_;OperationFrame f(*s.metrics,Operation::discard,&s);if(s.raw(Operation::discard,id))s.metrics->checked(Operation::discard,s.bridge.discard(id),id);}
void Aggregate::drain(std::uint32_t id)noexcept {auto& s=*state_;OperationFrame f(*s.metrics,Operation::drain,&s);if(s.raw(Operation::drain,id))s.metrics->checked(Operation::drain,s.bridge.drain(id),id);}
void Aggregate::release(std::uint32_t id)noexcept {auto& s=*state_;OperationFrame f(*s.metrics,Operation::release,&s);if(s.raw(Operation::release,id))s.metrics->checked(Operation::release,s.bridge.release(id),id);}
std::size_t Aggregate::queued_samples(std::uint32_t id)noexcept {auto& s=*state_;OperationFrame f(*s.metrics,Operation::queued_samples,&s);if(!s.raw(Operation::queued_samples,id))return 0;auto r=s.bridge.queuedSamples(id);return s.metrics->checked(Operation::queued_samples,r.status,id)?r.value:0;}
void Aggregate::reset_pcm()noexcept {auto& s=*state_;OperationFrame f(*s.metrics,Operation::reset,&s);if(s.inputs.native_streams){s.metrics->refuse(Operation::reset,249);return;}s.metrics->checked(Operation::reset,s.bridge.reset());}
namespace {
struct PacketWork final:PacketOperation {
    packet::PacketAdapter& adapter;packet::Call& call;unsigned invocations{};packet::PacketResult result;
    PacketWork(packet::PacketAdapter& a,packet::Call& c):adapter(a),call(c){}
    packet::PacketResult run(const packet::CaptureSource& source)noexcept override {if(++invocations!=1)return {packet::Status::rejected};return result=adapter.submit_packet(call,source);}
};
struct BankWork final:BankOperation {
    packet::PacketAdapter& adapter;packet::Call& call;unsigned port,invocations{};packet::Status result{packet::Status::rejected};
    BankWork(packet::PacketAdapter& a,packet::Call& c,unsigned p):adapter(a),call(c),port(p){}
    packet::Status run(const packet::CaptureSource& source)noexcept override {if(++invocations!=1)return packet::Status::rejected;return result=adapter.submit_bank(call,port,source);}
};
}
a::BankStatusV2 Aggregate::submit_packet(const PacketBorrow& borrow)noexcept {
    auto& s=*state_;OperationFrame f(*s.metrics,Operation::submit_packet,&s);auto call=s.packets->begin_call();packet::PacketResult result;
    if(call.status!=packet::Status::ok)result.status=call.status;
    else {PacketWork work(*s.packets,call.value);result=s.inputs.capture->with_packet(borrow,work);
        if(work.invocations>1||(result.status==packet::Status::ok&&work.invocations!=1)||(work.invocations==1&&(result.status!=work.result.status||result.parser_accepted!=work.result.parser_accepted||result.consumed!=work.result.consumed||result.commands_applied!=work.result.commands_applied))){s.metrics->hard_failure(Operation::submit_packet,250);result.status=packet::Status::rejected;}
        s.metrics->commands.fetch_add(work.result.commands_applied);s.metrics->consumed.fetch_add(work.result.consumed);if(work.result.parser_accepted)++s.metrics->packets;
    }
    return packet::to_backend(s.metrics->checked(Operation::submit_packet,result.status));
}
a::BankStatusV2 Aggregate::submit_bank(const BankBorrow& borrow)noexcept {
    auto& s=*state_;OperationFrame f(*s.metrics,Operation::submit_bank,&s);packet::Status status;
    if(borrow.port>=bank::port_count)status=packet::Status::invalid_input;
    else {auto call=s.packets->begin_call();status=call.status;
        if(status==packet::Status::ok){BankWork work(*s.packets,call.value,borrow.port);status=s.inputs.capture->with_bank(borrow,work);
            if(work.invocations>1||(status==packet::Status::ok&&work.invocations!=1)||(work.invocations==1&&status!=work.result)){s.metrics->hard_failure(Operation::submit_bank,250);status=packet::Status::rejected;}}
    }
    return packet::to_backend(s.metrics->checked(Operation::submit_bank,status));
}
a::BankStatusV2 Aggregate::mix_banks(float* out,unsigned frames)noexcept {auto& s=*state_;OperationFrame f(*s.metrics,Operation::mix_banks,&s);Gains gains(*s.inputs.host);return packet::to_backend(s.metrics->checked(Operation::mix_banks,s.packets->mix_add(out,frames,gains)));}
a::BankStatusV2 Aggregate::reset_banks()noexcept {auto& s=*state_;OperationFrame f(*s.metrics,Operation::reset_banks,&s);auto call=s.packets->begin_call();const auto status=call.status==packet::Status::ok?s.packets->reset(call.value):call.status;return packet::to_backend(s.metrics->checked(Operation::reset_banks,status));}
a::BankQueryV2 Aggregate::query(Operation op,unsigned p,unsigned q,unsigned group,std::uint32_t* count)noexcept {
    auto& s=*state_;OperationFrame f(*s.metrics,op,&s);auto call=s.packets->begin_call();packet::Result<std::uint32_t> result{call.status,0};
    if(call.status==packet::Status::ok){if(op==Operation::pending_loads)result=s.packets->pending_loads(call.value);else if(op==Operation::port_state)result=s.packets->port_state(call.value,p,*count);else result=s.packets->sequence_state(call.value,p,q,group);}
    s.metrics->checked(op,result.status);return packet::to_backend(result);
}
a::BankStatusV2 Aggregate::report_paths()noexcept {
    auto& s=*state_;OperationFrame f(*s.metrics,Operation::report_paths,&s);
    if(Frame::device_thread()){s.metrics->refuse(Operation::report_paths,128+unsigned(packet::Status::unsupported));return a::BankStatusV2::unsupported;}
    const auto snapshot=s.banks->snapshot();s.inputs.host->report_bank_paths(snapshot,s.inputs.banks.path_counters);
    ++s.metrics->completed[std::size_t(Operation::report_paths)];return a::BankStatusV2::ok;
}
a::BackendRegistrationV2 Aggregate::registration()noexcept {
    a::BackendApiV2 api;api.abi_version=a::backendAbiVersionV2;api.structure_bytes=sizeof(api);api.capabilities=a::backendRequiredCapabilitiesV2;
    auto& p=api.pcm;p.abi_version=a::backendAbiVersionV1;p.structure_bytes=sizeof(p);p.capabilities=a::backendRequiredCapabilitiesV1;
    p.ensure_host_output=[](void* x)noexcept{static_cast<Aggregate*>(x)->ensure_output();};
    p.queue=[](void* x,std::uint32_t k,const std::uint8_t* b,std::uint32_t n,std::uint64_t& e)noexcept{return static_cast<Aggregate*>(x)->queue(k,b,n,e);};
    p.configure=[](void* x,std::uint32_t v,std::uint32_t l,std::uint32_t r,std::uint32_t n,std::uint32_t f,std::uint32_t vol,bool play)noexcept{static_cast<Aggregate*>(x)->configure(v,l,r,n,f,vol,play);};
    p.consumed=[](void* x,std::uint32_t k)noexcept{return static_cast<Aggregate*>(x)->consumed(k);};
    p.render=[](void* x,float* out,unsigned n)noexcept{static_cast<Aggregate*>(x)->compatibility_render(out,n);};
    p.discard=[](void* x,std::uint32_t k)noexcept{static_cast<Aggregate*>(x)->discard(k);};p.drain=[](void* x,std::uint32_t k)noexcept{static_cast<Aggregate*>(x)->drain(k);};p.release=[](void* x,std::uint32_t k)noexcept{static_cast<Aggregate*>(x)->release(k);};
    p.queued_samples=[](void* x,std::uint32_t k)noexcept{return static_cast<Aggregate*>(x)->queued_samples(k);};p.reset=[](void* x)noexcept{static_cast<Aggregate*>(x)->reset_pcm();};
    p.request_stop=[](void* x)noexcept{static_cast<Aggregate*>(x)->signal_stop();};
    p.shutdown=[](void* x)noexcept{auto& owner=*static_cast<Aggregate*>(x);++owner.state_->metrics->attempts[std::size_t(Operation::shutdown)];(void)owner.finish_after_outer_drain();};
    p.join=[](void* x)noexcept{return static_cast<Aggregate*>(x)->finish_after_outer_drain();};
    auto& b=api.banks;
    b.submit_bank=[](void* x,unsigned port,const std::uint8_t* hd,std::size_t hn,const std::uint8_t* bd,std::size_t bn,const std::uint8_t* tq,std::size_t tn)noexcept{return static_cast<Aggregate*>(x)->submit_bank({port,hd,hn,bd,bn,tq,tn});};
    b.submit_packet=[](void* x,const std::uint8_t* ram,std::size_t rn,const std::uint8_t* packet,std::size_t pn)noexcept{return static_cast<Aggregate*>(x)->submit_packet({ram,rn,packet,pn});};
    b.mix=[](void* x,float* out,unsigned n)noexcept{return static_cast<Aggregate*>(x)->mix_banks(out,n);};b.reset=[](void* x)noexcept{return static_cast<Aggregate*>(x)->reset_banks();};
    b.pending_loads=[](void* x)noexcept{return static_cast<Aggregate*>(x)->query(Operation::pending_loads);};
    b.port_state=[](void* x,unsigned p,std::uint32_t& n)noexcept{return static_cast<Aggregate*>(x)->query(Operation::port_state,p,0,0,&n);};
    b.se_state=[](void* x,unsigned p,unsigned q,unsigned g)noexcept{return static_cast<Aggregate*>(x)->query(Operation::sequence_state,p,q,g);};
    b.report_audio_paths=[](void* x)noexcept{return static_cast<Aggregate*>(x)->report_paths();};
    api.render_admitted=[](void* x,a::SoundCall& call,float* out,unsigned n)noexcept{static_cast<Aggregate*>(x)->render_admitted(call,out,n);};
    return {api,weak_from_this().lock()};
}
Report Aggregate::report()const noexcept {auto& s=*state_;std::lock_guard lock(s.report_mutex);Report result=s.published;
    result.testing_profile=s.testing;result.pcm_domain=s.domain;result.capture_identity=s.capture_identity;result.declared_pcm_bytes=std::uint64_t(s.domain.max_channels)*96000*2;result.host_output_started=s.host->ever_started.load();s.counters(result);return result;}
pcm::ChannelObservation Aggregate::inspect_channel(std::uint32_t raw)const noexcept{return state_->bridge.inspect_channel(raw);}
pcm::VoiceObservation Aggregate::inspect_voice(std::uint32_t raw)const noexcept{return state_->bridge.inspect_voice(raw);}
pcm::Status Aggregate::copy_samples(std::uint32_t raw,std::span<std::int16_t> out)const noexcept{return state_->bridge.copy_samples(raw,out);}
pcm::Result<std::size_t> Aggregate::copy_order(std::span<std::uint32_t> out)const noexcept{return state_->bridge.copy_order(out);}
bank::Snapshot Aggregate::inspect_banks()const noexcept{return state_->banks->snapshot();}
} // namespace reo::native::audio_aggregate::v3
