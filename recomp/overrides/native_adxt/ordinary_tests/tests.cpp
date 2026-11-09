// Actual ordinary adapter/native workers; original calls, registry, mount
// acquisition and selected factory are declared ports. No game/device launch.
#include "ordinary_runtime_body.cpp"
#include "handle_fixture.hpp"
#include <windows.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

namespace b=reo::native::adxt_binding;
namespace sr=reo::native::sound_ram;
namespace inst=reo::native::adxt_instances;
namespace own=reo::native::adxt_control_owner;
namespace res=reo::native::resources::win32;
thread_local std::uint32_t depth=1;
std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*)noexcept{return depth;}
float reoAudioStreamGain(std::uint32_t){return 1;}
PS2Runtime* prepared_runtime{};std::uint8_t* prepared_ram{};
std::shared_ptr<const res::MountedResources> prepared_mount;
bool mount_allowed=true,factory_allowed=true;unsigned mount_calls{},factory_calls{},original_calls{},original_stops{},original_children{};
b::NativeTickReader declared_tick_reader{};
b::NativeServiceWork declared_native_work{};
unsigned callback_registrations{};
bool callbacks_allowed=true;
namespace reo::native::adxt_binding {
bool register_native_service_callbacks(NativeTickReader reader,NativeServiceWork work)noexcept{
    ++callback_registrations;
    if(!callbacks_allowed || !reader || !work)return false;
    declared_tick_reader=reader;declared_native_work=work;return true;
}
}
struct Order final:sr::MediaInstallResult::PcmOrder {
    std::vector<std::uint32_t> routes;
    reo::native::pcm_bridge::Result<std::size_t> copy(std::span<std::uint32_t> out)const noexcept override{
        if(out.size()<routes.size())return{reo::native::pcm_bridge::Status::invalid_input,routes.size()};
        std::copy(routes.begin(),routes.end(),out.begin());return{reo::native::pcm_bridge::Status::ok,routes.size()};
    }
};
std::shared_ptr<Order> declared_order=std::make_shared<Order>();
bool metadata_allowed=true,metadata_recover=false;unsigned metadata_calls{};
std::vector<std::uint32_t> recovered_routes;
namespace ps2_syscalls {
RnaMetadataResultV1 refreshMutedRnaMetadataV1(PS2Runtime* runtime)noexcept{
    ++metadata_calls;
    if(!metadata_allowed || runtime!=prepared_runtime)return{RnaMetadataStatusV1::control_refused,0,0,0};
    if(metadata_recover){declared_order->routes.swap(recovered_routes);metadata_recover=false;}
    return{RnaMetadataStatusV1::ok,0,0,0};
}
}
class SourceWorker final:public PS2Runtime::ExternalWorker {
    std::shared_ptr<own::Owner> owner_;
public:explicit SourceWorker(std::shared_ptr<own::Owner> owner):owner_(std::move(owner)){}
    void requestStop()noexcept override{owner_->request_stop();}
    bool join()noexcept override{return depth==0 && owner_->join()==own::Join::completed;}
};
namespace reo_native_resource_reads {
SharedMount retain_mount_before_run(PS2Runtime& runtime,const std::uint8_t* ram,std::size_t size)noexcept{
    ++mount_calls;return mount_allowed && &runtime==prepared_runtime && ram==prepared_ram && size==b::ram_bytes?prepared_mount:SharedMount{};
}
}
namespace reo::native::sound_ram {
MediaInstallResult install_prepared_native_sources(PS2Runtime& runtime,const reo_cd_async::ConfigurationReceipt&,
    bank_packets::v3::MemoryIdentity,const std::shared_ptr<own::Owner>& owner)noexcept{
    ++factory_calls;if(!factory_allowed)return{{InstallStatus::publication_refused},{},{}};
    if(!runtime.registerExternalWorker(std::make_shared<SourceWorker>(owner)))return{{InstallStatus::publication_refused},{},{}};
    return{{InstallStatus::installed,ps2_cri_audio::BackendInstallStatusV1::installed},owner,declared_order};
}
}
void original(std::uint32_t entry,std::uint8_t* ram,R5900Context* c){
    ++original_calls;
    if(entry==0x131d98){++original_stops;ram[GPR_U32(c,4)+1]=0;ram[GPR_U32(c,4)+0xac]=0;}
    if(entry==0x12c680){++original_children;check(b::current()->mapped.counts().destroying==0);ram[GPR_U32(c,4)]=0;}
    c->pc=GPR_U32(c,31);
}
#define X(address,name,action) void name(std::uint8_t* ram,R5900Context* c,PS2Runtime*){original(address,ram,c);}
#include "recomp/overrides/native_adxt/ordinary_entries.inc"
#undef X
struct Memory {
    std::uint8_t* bytes=static_cast<std::uint8_t*>(VirtualAlloc(nullptr,b::ram_bytes,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));
    ~Memory(){if(bytes)VirtualFree(bytes,0,MEM_RELEASE);}
    void protect(DWORD mode){DWORD old{};check(VirtualProtect(bytes,b::ram_bytes,mode,&old)!=0);}
};
void load_image(Memory& memory,const char* path){
    check(memory.bytes!=nullptr);std::ifstream in(path,std::ios::binary);std::uint32_t count{};in.read(reinterpret_cast<char*>(&count),4);check(in && count==4);
    for(unsigned i=0;i<count;++i){std::uint32_t at{},size{};in.read(reinterpret_cast<char*>(&at),4);in.read(reinterpret_cast<char*>(&size),4);check(in && at<=b::ram_bytes && size<=b::ram_bytes-at);in.read(reinterpret_cast<char*>(memory.bytes+at),size);check(bool(in));}
}
void configure(PS2Runtime& runtime,Memory& memory){runtime.storage.ram=memory.bytes;prepared_runtime=&runtime;prepared_ram=memory.bytes;for(const auto& entry:b::entries)runtime.registerFunction(entry.address,entry.original);runtime.changes=0;}
R5900Context call(PS2Runtime& runtime,std::uint32_t entry,std::array<std::uint32_t,3> args={}){
    R5900Context c{};for(unsigned i=1;i<32;++i)c.r[i]={0x1234000000000000ull+i,0xfedcba9876543210ull+i};
    for(unsigned i=0;i<args.size();++i)c.r[4+i][0]=args[i];c.r[29][0]=0x1ff0000;c.r[31][0]=0x100008;c.pc=entry;
    runtime.lookupFunction(entry)(runtime.storage.ram,&c,&runtime);check(c.pc==0x100008);return c;
}
void construct(Memory& memory,unsigned slot,unsigned channels){
    Fixture f(slot,channels);const auto copy=[&](std::uint32_t at,std::size_t n){std::memcpy(memory.bytes+at,f.ram.data()+at,n);};
    copy(f.handle,0xc4);copy(f.decoder,0x9c);copy(f.file,0x5c);copy(f.rna,0x60);copy(0x221438,4);
    for(unsigned c=0;c<channels;++c){copy(f.dtr[c],0x40);copy(f.psj[c],0x18);}
    b::store(memory.bytes,f.handle+0x38,30);b::store(memory.bytes,f.handle+0x42,std::int16_t(-128));if(channels==2)b::store(memory.bytes,f.handle+0x44,std::int16_t(-128));memory.bytes[f.handle+0x6c]=1;
}
struct Asset {std::uint32_t start{},count{},channels{},rate{},total{};std::array<std::uint64_t,2> digest{};};
std::array<Asset,3> assets;
void pending(Memory& memory,unsigned slot,unsigned asset){
    const auto at=b::handles.base+slot*b::handles.stride;const auto& data=assets[asset];
    memory.bytes[at+1]=1;memory.bytes[at+2]=1;memory.bytes[at+0xac]=1;
    constexpr auto name=0x1900100;std::memcpy(memory.bytes+name,"netbio01.dat",12);
    b::store(memory.bytes,at+0xb4,std::uint32_t(name));b::store(memory.bytes,at+0xb8,0u);b::store(memory.bytes,at+0xbc,data.start);b::store(memory.bytes,at+0xc0,data.count);
}
void close(PS2Runtime& runtime){runtime.requestStop();depth=0;check(runtime.join());depth=1;}
template<class F>void until(F&& done){const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(30);while(!done()){check(std::chrono::steady_clock::now()<end);std::this_thread::yield();}}
void group(PS2Runtime& runtime){b::store(runtime.storage.ram,0x20f3c4,b::load<std::uint32_t>(runtime.storage.ram,0x20f3c4)+1);(void)call(runtime,0x132c08);}
void install(PS2Runtime& runtime){const auto result=b::install_ordinary_before_run(runtime,{},{});check(result.status==sr::InstallStatus::installed && factory_calls==1 && runtime.workers.size()==(b::current()->trace.enabled()?4u:3u) && b::current()->active);}
void prepare_handles(Memory& memory){for(unsigned i=0;i<3;++i)construct(memory,i,i==2?1:2);declared_order->routes={0x1e0100,0x1e0000,0x1e0080};b::store(memory.bytes,0x21b788,6000u);}
void cue_descriptor(Memory& memory,bool invalid_member=false,unsigned asset=0){
    constexpr std::uint32_t descriptor=0x1910000;
    b::store(memory.bytes,0x20cd00+3*4,descriptor);b::store(memory.bytes,descriptor+8,1u);memory.bytes[descriptor+15]=1;
    std::memcpy(memory.bytes+descriptor+16,"netbio01.dat",12);
    b::store(memory.bytes,descriptor+0x110,0u);b::store(memory.bytes,descriptor+0x114,0u);
    b::store(memory.bytes,descriptor+0x118,assets[asset].start);b::store(memory.bytes,descriptor+0x11c,invalid_member?0u:assets[asset].count);
}
void queued(Memory& memory,PS2Runtime& runtime,const std::string& mode){
    install(runtime);prepare_handles(memory);
    const auto& expected=assets[mode=="queue_e3"?2:0];cue_descriptor(memory,false,mode=="queue_e3"?2:0);const auto handle=b::handles.base;
    const auto initial_count=call(runtime,0x12a8f0,{handle});check(GPR_U32((&initial_count),2)==0);
    const auto entered=call(runtime,0x12a6b8,{handle,3,0});check(GPR_U32((&entered),2)==1);
    if(mode=="queue_append"){const auto second=call(runtime,0x12a6b8,{handle,3,0});check(GPR_U32((&second),2)==2);}
    if(mode=="queue_repeat")(void)call(runtime,0x12a830,{handle,1});
    const auto count=call(runtime,0x12a8f0,{handle});check(GPR_U32((&count),2)==(mode=="queue_append"?2u:1u));
    (void)call(runtime,0x12a780,{handle});check(memory.bytes[handle+1]==1 && memory.bytes[handle+2]==4 && original_calls==0);
    const auto binding=b::current();
    until([&]{group(runtime);const auto s=binding->inspect(binding->records[0]).source;return s && s->configured && s->output.channel[0].samples>=1024;});
    (void)call(runtime,0x132e50,{handle,1});const auto paused=binding->inspect(binding->records[0]).source->output.channel[0].consumed_bytes;
    std::array<float,1024> output{};check(binding->source_owner->submix()->render_add(output.data(),512)==reo::native::adxt_output_session::Status::completed);
    check(binding->inspect(binding->records[0]).source->output.channel[0].consumed_bytes==paused);
    (void)call(runtime,0x132e50,{handle,0});bool repeated{};
    until([&]{group(runtime);const auto s=binding->inspect(binding->records[0]).source;if(!s)return false;
        if(mode=="queue_repeat" && !repeated && s->first_payload_samples>=std::uint64_t(expected.total)*2){(void)call(runtime,0x12a830,{handle,0});repeated=true;}
        if(s->playback.phase==reo::native::adxt_playback::Phase::ended)return true;
        if(s->output.channel[0].samples>=512){output.fill(0);check(binding->source_owner->submix()->render_add(output.data(),512)==reo::native::adxt_output_session::Status::completed);}return false;
    });
    const auto terminal=binding->inspect(binding->records[0]).source;
    if(mode=="queue_finite" || mode=="queue_e3")check(terminal->first_payload_samples==expected.total && terminal->first_payload_digest==expected.digest);
    else if(mode=="queue_append")check(terminal->first_payload_samples==std::uint64_t(expected.total)*2);
    else check(repeated && terminal->first_payload_samples>=std::uint64_t(expected.total)*2);
    check(original_calls==0 && binding->records[0].queue && binding->cue_loader->snapshot().records==0);
    const auto emptied=call(runtime,0x12a8f0,{handle});check(GPR_U32((&emptied),2)==0);
    (void)call(runtime,0x131d98,{handle});(void)call(runtime,0x12a928,{handle});check(memory.bytes[handle+1]==0 && original_stops==1);
    memory.protect(PAGE_NOACCESS);close(runtime);check(binding->source_owner->report().joined && binding->cue_loader->snapshot().joined);memory.protect(PAGE_READWRITE);
}
void queued_refusal(Memory& memory,PS2Runtime& runtime,const std::string& mode){
    install(runtime);prepare_handles(memory);
    cue_descriptor(memory,mode=="queue_bad_member");if(mode=="queue_bad_descriptor")b::store(memory.bytes,0x20cd00+3*4,b::ram_bytes-4);
    bool refused{};try{(void)call(runtime,0x12a6b8,{b::handles.base,3,0});}catch(const std::runtime_error&){refused=true;}
    check(refused && runtime.stopped && original_calls==0 && b::current()->cue_loader->snapshot().accepted==0);
}
// Block one real metadata-loader task before the queued ABI request is made.
// The selected queue still receives its actual immutable imported member.
class MetadataGate final:public reo::native::resources::ByteView {
    std::shared_ptr<const reo::native::resources::ByteView> source_;
public:
    mutable std::atomic<bool> entered{},released{};
    explicit MetadataGate(std::shared_ptr<const reo::native::resources::ByteView> source):source_(std::move(source)){}
    std::uint64_t size()const noexcept override{return source_->size();}
    reo::native::resources::ReadResult read(std::uint64_t offset,std::span<std::byte> destination)const override{
        entered.store(true,std::memory_order_release);
        while(!released.load(std::memory_order_acquire))std::this_thread::yield();
        return source_->read(offset,destination);
    }
};
void native_queue_case(Memory& memory,PS2Runtime& runtime,const std::string& mode){
    install(runtime);prepare_handles(memory);const auto binding=b::current();
    check(callback_registrations==1 && declared_tick_reader && declared_native_work);
    std::uint32_t observed_tick{};std::shared_ptr<void> context;
    check(!declared_tick_reader(binding->source_owner.get(),observed_tick,context));
    auto foreign=std::make_shared<own::Owner>(reo::native::adxt_control_session::Config{});
    b::Operation foreign_order([](auto& players){check(players.set_order({})==inst::Status::completed);});
    check(foreign->run(foreign_order)==own::Admission::accepted);
    check(!declared_tick_reader(foreign.get(),observed_tick,context));
    const auto third_address=b::handles.base+2*b::handles.stride;
    const auto third_decoder=b::load<std::uint32_t>(memory.bytes,third_address+0xc);
    if(mode=="native_queue_order")b::store(memory.bytes,third_address+0xc,0u);
    group(runtime);const auto frozen_tick=b::load<std::uint32_t>(memory.bytes,0x20f3c4);
    if(mode=="native_queue_order"){
        check(binding->mapped.counts().mapped==2);
        b::store(memory.bytes,third_address+0xc,third_decoder);binding->adopt();
        check(binding->mapped.counts().mapped==3);
    }
    std::array<inst::Key,3> published_order;
    for(unsigned i=0;i<3;++i)binding->with(binding->records[i],[&](auto&,const auto& key,const auto&){published_order[i]=key;});
    check(declared_tick_reader(binding->source_owner.get(),observed_tick,context) && observed_tick==frozen_tick && context.get()==binding.get());
    const auto source=b::prepare_file_source(binding->mount,{"netbio01.dat",0,assets[0].start,assets[0].count});
    check(source.status==b::FileStatus::ready);
    const auto gate=std::make_shared<MetadataGate>(source.view);
    struct Release{std::shared_ptr<MetadataGate> gate;~Release(){gate->released.store(true,std::memory_order_release);}}release{gate};
    const auto blocking=binding->cue_loader->prepare(gate);
    check(blocking.status==reo::native::audio_clip_loader::Status::accepted);
    until([&]{return gate->entered.load(std::memory_order_acquire);});
    cue_descriptor(memory);const auto handle=b::handles.base;
    const auto enqueued=call(runtime,0x12a6b8,{handle,3,0});check(GPR_U32((&enqueued),2)==1);
    (void)call(runtime,0x12a780,{handle});
    const auto queue=binding->records[0].queue;check(bool(queue));
    inst::Key key;binding->with(binding->records[0],[&](auto&,const auto& native_key,const auto&){key=native_key;});
    reo::native::audio_cue_queue::Snapshot queue_state;
    inst::Observation observation;
    auto inspect=[&]{binding->control([&](auto& p){queue_state=queue->snapshot();observation=p.inspect(key);});};
    inspect();check(queue_state.preparing==1 && queue_state.play_requested && !queue_state.source_submitted);
    std::vector<std::uint8_t> before(memory.bytes,memory.bytes+b::ram_bytes);
    auto pass=[&](const std::shared_ptr<own::Owner>& owner,const std::shared_ptr<void>& selected){
        inst::Status feeder=inst::Status::fault,serviced=inst::Status::fault;
        b::Operation operation([&](auto& players){feeder=declared_native_work(selected,players,frozen_tick);
            if(feeder==inst::Status::completed)serviced=players.service(frozen_tick);
            if(owner==binding->source_owner){queue_state=queue->snapshot();observation=players.inspect(key);}
        });
        check(owner->run(operation)==own::Admission::accepted);
        if(feeder==inst::Status::completed)check(serviced==inst::Status::completed || serviced==inst::Status::pending);
        return feeder;
    };
    memory.protect(PAGE_NOACCESS);
    const auto before_header=pass(binding->source_owner,context);
    check(before_header==(mode=="native_queue_order"?inst::Status::order_required:inst::Status::completed) && queue_state.preparing==1 && !queue_state.source_submitted);
    check(pass(foreign,context)==inst::Status::fault);
    check(pass(binding->source_owner,{})==inst::Status::fault);
    gate->released.store(true,std::memory_order_release);
    until([&]{return binding->cue_loader->poll(blocking.key).status==reo::native::audio_clip_loader::Status::ready;});
    check(binding->cue_loader->release(blocking.key)==reo::native::audio_clip_loader::Status::completed);
    until([&]{return binding->cue_loader->snapshot().finished>=2;});
    if(mode=="native_queue_order"){
        check(pass(binding->source_owner,context)==inst::Status::order_required && queue_state.preparing==1 && !queue_state.source_submitted && !queue_state.failed);
        binding->control([&](auto& players){check(players.set_order(published_order)==inst::Status::completed);});
    }
    check(pass(binding->source_owner,context)==inst::Status::completed && queue_state.preparing==0 && queue_state.source_submitted);
    until([&]{check(declared_tick_reader(binding->source_owner.get(),observed_tick,context) && observed_tick==frozen_tick);
        check(pass(binding->source_owner,context)==inst::Status::completed);
        return observation.source && observation.source->configured && observation.source->output.channel[0].samples>=1024;
    });
    check(queue_state.preparing==0 && queue_state.source_submitted && queue_state.registered_assets==1);
    memory.protect(PAGE_READWRITE);check(std::equal(before.begin(),before.end(),memory.bytes));
    (void)call(runtime,0x132e50,{handle,1});inspect();const auto paused=observation.source->output.channel[0].consumed_bytes;
    before.assign(memory.bytes,memory.bytes+b::ram_bytes);memory.protect(PAGE_NOACCESS);
    std::array<float,1024> output{};
    for(unsigned i=0;i<12;++i){check(pass(binding->source_owner,context)==inst::Status::completed);
        check(binding->source_owner->submix()->render_add(output.data(),512)==reo::native::adxt_output_session::Status::completed);
    }
    check(pass(binding->source_owner,context)==inst::Status::completed && observation.source->output.channel[0].consumed_bytes==paused);
    memory.protect(PAGE_READWRITE);check(std::equal(before.begin(),before.end(),memory.bytes));
    (void)call(runtime,0x132e50,{handle,0});
    if(mode!="native_queue_destroy"){
        before.assign(memory.bytes,memory.bytes+b::ram_bytes);memory.protect(PAGE_NOACCESS);
        until([&]{check(pass(binding->source_owner,context)==inst::Status::completed);
            if(observation.source && observation.source->playback.phase==reo::native::adxt_playback::Phase::ended)return true;
            if(observation.source && observation.source->output.channel[0].samples>=512){output.fill(0);check(binding->source_owner->submix()->render_add(output.data(),512)==reo::native::adxt_output_session::Status::completed);}return false;
        });
        check(observation.source->first_payload_samples==assets[0].total && observation.source->first_payload_digest==assets[0].digest);
        memory.protect(PAGE_READWRITE);check(std::equal(before.begin(),before.end(),memory.bytes));
        (void)call(runtime,0x131d98,{handle});(void)call(runtime,0x12a928,{handle});
        memory.protect(PAGE_NOACCESS);check(pass(binding->source_owner,context)==inst::Status::completed && !queue_state.play_requested && !queue_state.preparing);
        memory.protect(PAGE_READWRITE);
        pending(memory,0,0);group(runtime);
        check(!binding->records[0].queue);
        binding->control([&](auto&){check(!binding->native_queues[0]);});
        memory.protect(PAGE_NOACCESS);check(pass(binding->source_owner,context)==inst::Status::completed);
        memory.protect(PAGE_READWRITE);
    }else{
        check(mode=="native_queue_destroy");const auto rna=binding->records[0].handle.rna;
        (void)call(runtime,0x12c680,{rna});check(original_children==1 && !binding->records[0].owned);
        binding->control([&](auto&){check(!binding->native_queues[0] && queue->snapshot().closed);});
        memory.protect(PAGE_NOACCESS);const auto after_destroy=pass(binding->source_owner,context);
        check((after_destroy==inst::Status::completed || after_destroy==inst::Status::order_required) && observation.status==inst::Status::invalid_key);
        memory.protect(PAGE_READWRITE);
    }
    check(b::load<std::uint32_t>(memory.bytes,0x20f3c4)==frozen_tick+(mode!="native_queue_destroy"?1:0));
    check(original_calls==original_stops+original_children && binding->cue_loader->snapshot().records==0);
    binding->stopping.store(true,std::memory_order_release);
    check(!declared_tick_reader(binding->source_owner.get(),observed_tick,context));
    check(pass(binding->source_owner,context)==inst::Status::closed);
    memory.protect(PAGE_NOACCESS);close(runtime);check(binding->source_owner->report().joined && binding->cue_loader->snapshot().joined);
    memory.protect(PAGE_READWRITE);check(foreign->join()==own::Join::completed);
}
void ordinary(Memory& memory,PS2Runtime& runtime,bool recover=false){
    install(runtime);prepare_handles(memory);for(unsigned i=0;i<3;++i)pending(memory,i,i==2?1:0);
    if(recover){recovered_routes=declared_order->routes;declared_order->routes.clear();metadata_recover=true;}
    memory.bytes[b::handles.base+0x70]=1;
    group(runtime);check(original_calls==0 && b::current()->mapped.counts().mapped==3 && metadata_calls && !metadata_recover);
    // Original mono construction leaves this second-channel field untouched.
    // Both the real zero value and later stale bytes must be irrelevant.
    check(b::load<std::int16_t>(memory.bytes,b::handles.base+2*b::handles.stride+0x44)==0);
    b::store(memory.bytes,b::handles.base+2*b::handles.stride+0x44,std::int16_t(0x4321));
    const auto binding=b::current();bool ready{};
    until([&]{group(runtime);ready=true;for(auto& r:binding->records)if(r.owned){const auto s=binding->inspect(r).source;ready&=s && s->output.channel[0].samples>=1024 && (r.handle.slot==0?s->playback.started:s->output.voice.playing);}return ready;});
    const auto first=b::handles.base;const auto peer=b::handles.base+b::handles.stride;
    check(memory.bytes[first+0x71]==1 && memory.bytes[first+1]==2 && !binding->inspect(binding->records[0]).source->output.voice.playing);
    memory.bytes[first+0x70]=0;group(runtime);check(memory.bytes[first+1]==3 && binding->inspect(binding->records[0]).source->output.voice.playing && binding->inspect(binding->records[0]).source->clock.tick_base==binding->tick());
    const auto shared=[&]{reo::native::adxt_instances::Snapshot value;binding->control([&](auto& p){value=p.snapshot();});return value.session;};
    const auto unpaused=shared();const auto idle_discard=call(runtime,0x133058,{first,0xffffffff});
    check(GPR_U32((&idle_discard),2)==0 && original_calls==0 && shared().group_visits==unpaused.group_visits && shared().discard_diagnostics==unpaused.discard_diagnostics);
    const auto own_before=binding->inspect(binding->records[0]).source->output.channel[0].consumed_bytes;
    (void)call(runtime,0x132e50,{first,1});check(memory.bytes[first+0x72]==1 && !binding->inspect(binding->records[0]).source->output.voice.playing);
    const auto paused=shared();b::store(memory.bytes,0x20f3c4,binding->tick()+2);
    const auto discarded=call(runtime,0x133058,{first,0x12345678});
    check(GPR_U32((&discarded),2)==0 && original_calls==0 && shared().group_visits==paused.group_visits+1 && shared().discard_diagnostics==paused.discard_diagnostics+1);
    check(binding->inspect(binding->records[0]).source->clock.tick_base==binding->tick() && b::load<std::uint32_t>(memory.bytes,first+0xa0)==binding->tick());
    check(binding->inspect(binding->records[0]).source->output.channel[0].consumed_bytes==own_before && !binding->inspect(binding->records[0]).source->output.voice.playing);
    std::array<float,1024> output{};check(binding->source_owner->submix()->render_add(output.data(),512)==reo::native::adxt_output_session::Status::completed);
    check(binding->inspect(binding->records[0]).source->output.channel[0].consumed_bytes==own_before && binding->inspect(binding->records[1]).source->output.channel[0].consumed_bytes==1024);
    (void)call(runtime,0x132e50,{first,2});const auto raw_paused=shared();
    const auto raw_discard=call(runtime,0x133058,{first,7});
    check(GPR_U32((&raw_discard),2)==0 && memory.bytes[first+0x72]==2 && shared().group_visits==raw_paused.group_visits+1 && shared().discard_diagnostics==raw_paused.discard_diagnostics+1 && original_calls==0);
    (void)call(runtime,0x132e50,{first,0});check(!memory.bytes[first+0x72] && binding->inspect(binding->records[0]).source->output.voice.playing);
    (void)call(runtime,0x132028,{peer,0x1ff0100,0x1ff0104});check(b::load<std::uint32_t>(memory.bytes,0x1ff0100)==512 && b::load<std::uint32_t>(memory.bytes,0x1ff0104)==48000);
    const auto channels=call(runtime,0x132548,{first});check(GPR_U32((&channels),2)==2);
    const auto total=call(runtime,0x1324a8,{first});check(GPR_U32((&total),2)==assets[0].total);
    const auto frequency=call(runtime,0x1324f8,{b::handles.base+2*b::handles.stride});check(GPR_U32((&frequency),2)==assets[1].rate);
    until([&]{
        group(runtime);bool ended=true,can_render=true,playing=false;
        for(auto& r:binding->records)if(r.owned){const auto s=binding->inspect(r).source;check(s && !s->fault);ended&=s->playback.phase==reo::native::adxt_playback::Phase::ended;if(s->output.voice.playing){playing=true;can_render&=s->output.channel[0].samples>=512;}}
        if(!ended && playing && can_render){output.fill(0);check(binding->source_owner->submix()->render_add(output.data(),512)==reo::native::adxt_output_session::Status::completed);}return ended;
    });
    for(unsigned i=0;i<3;++i){const auto s=binding->inspect(binding->records[i]).source;const auto& expected=assets[i==2?1:0];check(s && s->first_payload_samples==expected.total && s->first_payload_digest==expected.digest);}
    (void)call(runtime,0x131f60,{first,0x1ff0100,0x1ff0104});check(b::load<std::uint32_t>(memory.bytes,0x1ff0100)==assets[0].total && b::load<std::uint32_t>(memory.bytes,0x1ff0104)==assets[0].rate);
    const auto centis=call(runtime,0x132458,{first});check(GPR_U32((&centis),2)==std::uint64_t(assets[0].total)*100/assets[0].rate);
    (void)call(runtime,0x131d98,{first});check(original_stops==1 && !memory.bytes[first+1] && !binding->records[0].source);
    pending(memory,0,0);until([&]{group(runtime);const auto s=binding->inspect(binding->records[0]);return s.starts==2 && s.source && s.source->configured;});
    const auto child=binding->records[0].handle.rna;
    // Exact destructor delay-slot condition: C4+C is already clear before the
    // first child call. Native retirement must use its retained game identity.
    b::store(memory.bytes,first+0xc,0u);(void)call(runtime,0x12c680,{child});
    check(original_children==1 && !binding->records[0].owned && binding->mapped.counts().mapped==2 && !memory.bytes[child]);
    check(original_calls==2);
    // A real joined child destruction permits later original pool reuse with
    // a different remote route and a fresh native generation.
    construct(memory,0,2);const auto fresh=b::inspect_handle({memory.bytes,b::ram_bytes},first);check(fresh.status==b::HandleStatus::ready);
    b::store(memory.bytes,fresh.value.rna+0x20,0x1e0200u);declared_order->routes={0x1e0200,0x1e0100,0x1e0080};pending(memory,0,0);
    until([&]{group(runtime);const auto state=binding->inspect(binding->records[0]);return state.starts==1 && state.source && state.source->configured;});
    check(binding->records[0].handle.route==0x1e0200 && binding->mapped.counts().mapped==3 && original_calls==2);
    // Teardown must not dereference RAM; external source workers retain only
    // immutable native views, and binding join never waits for guest work.
    memory.protect(PAGE_NOACCESS);close(runtime);check(binding->source_owner->report().joined);memory.protect(PAGE_READWRITE);
}
void missing_order(Memory& memory,PS2Runtime& runtime,unsigned streams){
    install(runtime);prepare_handles(memory);declared_order->routes.clear();
    const std::array<unsigned,2> available{0,2};const auto active=std::span(available).first(streams);
    for(unsigned slot:active)pending(memory,slot,slot==0?0:1);
    const auto binding=b::current();bool ready{};
    until([&]{group(runtime);ready=true;for(unsigned slot:active){const auto s=binding->inspect(binding->records[slot]).source;ready&=s && s->output.voice.playing && s->output.channel[0].samples>=1024;}return ready;});
    check(original_calls==0 && binding->mapped.counts().mapped==3);
    unsigned records{};binding->control([&](auto& p){records=p.snapshot().session.records;});check(records==streams);
    std::array<float,1024> output{};check(binding->source_owner->submix()->render_add(output.data(),512)==reo::native::adxt_output_session::Status::completed && std::any_of(output.begin(),output.end(),[](float x){return x!=0;}));
    for(unsigned slot:active)check(binding->inspect(binding->records[slot]).source->output.channel[0].consumed_bytes==1024);
    until([&]{group(runtime);bool ended=true,ready=true;for(unsigned slot:active){const auto s=binding->inspect(binding->records[slot]).source;check(s && !s->fault);ended&=s->playback.phase==reo::native::adxt_playback::Phase::ended;if(s->output.voice.playing)ready&=s->output.channel[0].samples>=512;}
        if(!ended && ready){output.fill(0);check(binding->source_owner->submix()->render_add(output.data(),512)==reo::native::adxt_output_session::Status::completed);}return ended;});
    for(unsigned slot:active){const auto s=binding->inspect(binding->records[slot]).source;const auto& a=assets[slot==0?0:1];check(s->first_payload_samples==a.total && s->first_payload_digest==a.digest);}
}
void admission(const std::string& mode,Memory& memory,PS2Runtime& runtime){
    if(mode=="phase")runtime.phase_open=false;
    if(mode=="image")memory.bytes[0x1315e0]^=1;
    if(mode=="entry")runtime.registerFunction(0x132c08,b::entries[1].original);
    if(mode=="mount")mount_allowed=false;
    if(mode=="worker")runtime.worker_allowed=false;
    if(mode=="registry")runtime.fail_change=3;
    if(mode=="factory")factory_allowed=false;
    const auto result=b::install_ordinary_before_run(runtime,{},{});check(result.status!=sr::InstallStatus::installed);
    for(const auto& entry:b::entries)if(mode!="entry" || entry.address!=0x132c08)check(runtime.lookupFunction(entry.address)==entry.original);
    check(original_calls==0 && factory_calls==(mode=="factory"?1u:0u));
    if(mode=="factory" || mode=="registry"){const auto bound=b::current();check(bound && !bound->active && bound->stopping && bound->source_owner->report().joined && runtime.workers.size()==1);}
    else check(runtime.workers.empty());
}
void refusal(const std::string& mode,Memory& memory,PS2Runtime& runtime){
    install(runtime);prepare_handles(memory);
    if(mode=="partial"){
        b::store(memory.bytes,b::handles.base+0xc,0u);group(runtime);check(b::current()->mapped.counts().mapped==2 && !original_calls);return;
    }
    group(runtime);const auto before=original_calls;bool refused{};
    try{
        if(mode=="metadata"){metadata_allowed=false;group(runtime);}
        else if(mode=="stereo_pan"){b::store(memory.bytes,b::handles.base+0x44,std::int16_t(0));group(runtime);}
        else if(mode=="mono_pan"){b::store(memory.bytes,b::handles.base+2*b::handles.stride+0x42,std::int16_t(0));group(runtime);}
        else if(mode=="callback")(void)call(runtime,0x133158,{b::handles.base,0x100100});
        else if(mode=="producer")(void)call(runtime,0x131d18,{b::handles.base,0x1800000});
        else if(mode=="changed_child"){
            const auto child=b::current()->records[0].handle.rna;b::store(memory.bytes,child+0x20,0x1e0200u);(void)call(runtime,0x132548,{b::handles.base});
        }else if(mode=="order" || mode=="order_partial"){
            declared_order->routes.clear();if(mode=="order_partial")declared_order->routes={0x1e0000,0x1e0080};
            for(unsigned slot=0;slot<3;++slot)pending(memory,slot,slot==2?1:0);group(runtime);
        }else if(mode=="foreign"){
            PS2Runtime foreign;foreign.storage.ram=memory.bytes;R5900Context c{};c.pc=0x132c08;c.r[31][0]=0x100008;runtime.lookupFunction(0x132c08)(memory.bytes,&c,&foreign);
        }else if(mode=="guest_depth"){
            depth=0;try{group(runtime);}catch(...){depth=1;throw;}depth=1;
        }else if(mode=="query_alias"){
            pending(memory,0,0);until([&]{group(runtime);return b::current()->inspect(b::current()->records[0]).source->configured;});
            (void)call(runtime,0x132028,{b::handles.base,b::handles.base+0x88,0x1ff0104});
        }else throw std::runtime_error("unknown refusal case");
    }catch(const std::runtime_error&){refused=true;}
    check(refused && runtime.stopped && original_calls==before);
    const auto binding=b::current();check(binding && binding->source_owner->report().stopping);
}
int main(int argc,char** argv)try{
    check(argc==5);Memory memory;load_image(memory,argv[1]);PS2Runtime runtime;configure(runtime,memory);
    auto opened=res::MountedResources::open_file1_windows(std::filesystem::path(argv[2]));check(opened.status==res::MountStatus::ok);prepared_mount=std::move(opened.mount);
    std::ifstream plan(argv[3]);for(auto& asset:assets){plan>>asset.start>>asset.count>>asset.channels>>asset.rate>>asset.total>>asset.digest[0]>>asset.digest[1];check(bool(plan));}
    const std::string mode=argv[4];
    std::filesystem::path trace_path=std::filesystem::path(argv[0]).parent_path()/(mode+".csv");
    if(mode.starts_with("trace"))check(_wputenv_s(L"REO_NATIVE_ADXT_TRACE_FILE",trace_path.c_str())==0);
    if(mode=="trace_bounds" || mode=="trace_existing" || mode=="trace_unjoined" || mode=="trace_generation"){
        b::AudioTrace trace;check(trace.enabled());reo::native::adxt_output_session::Snapshot value;
        value.statistics={4800,4500,13};auto& stream=value.streams[2];stream.slot=2;stream.generation=7;stream.active=true;stream.voice.playing=true;stream.channel[0].samples=17;stream.voice.late_samples=9;
        trace.sources[2]={mode=="trace_generation"?8u:7u,123,9,448,2,1,4096,4096,8192,4,8192,480};
        const unsigned count=mode=="trace_bounds"?32770:1;
        for(unsigned i=0;i<count;++i)trace.record(b::AudioTrace::now(),i,value);
        check(trace.rows.size()==std::min(count,32768u) && trace.dropped==count-trace.rows.size());
        check(trace.rows.front().output.streams[2].channel[0].samples==17 && trace.rows.front().output.statistics.underrun_frames==13);
        if(mode=="trace_existing"){std::ofstream(trace_path)<<"preserve prior evidence";trace.save(true);std::ifstream in(trace_path);std::string line;std::getline(in,line);check(line=="preserve prior evidence");}
        else if(mode=="trace_unjoined"){trace.save(false);check(!std::filesystem::exists(trace_path));}
        else {trace.save(true);check(std::filesystem::file_size(trace_path)>100);std::ifstream in(trace_path);std::string line;for(unsigned i=0;i<3;++i)check(bool(std::getline(in,line)));std::istringstream record(line);std::string field;for(unsigned i=0;i<=18;++i)check(bool(std::getline(record,field,',')));check(field==(mode=="trace_generation"?"0":"1"));}
    }
    else if(mode=="ordinary" || mode=="metadata_three" || mode=="trace"){
        ordinary(memory,runtime,mode=="metadata_three");
        if(mode=="trace"){check(b::current()->source_owner->report().joined && b::current()->trace.saved && !b::current()->trace.rows.empty());check(std::filesystem::file_size(trace_path)>100);}
    }
    else if(mode=="queue_finite" || mode=="queue_e3" || mode=="queue_append" || mode=="queue_repeat")queued(memory,runtime,mode);
    else if(mode=="queue_bad_descriptor" || mode=="queue_bad_member")queued_refusal(memory,runtime,mode);
    else if(mode=="native_queue_feed" || mode=="native_queue_destroy" || mode=="native_queue_order")native_queue_case(memory,runtime,mode);
    else if(mode=="missing_one" || mode=="missing_two")missing_order(memory,runtime,mode=="missing_one"?1:2);
    else if(mode=="phase" || mode=="image" || mode=="entry" || mode=="mount" || mode=="worker" || mode=="registry" || mode=="factory")admission(mode,memory,runtime);
    else refusal(mode,memory,runtime);
    close(runtime);std::cout<<"ordinary ABI declared-port "<<mode<<" checks="<<checks<<'\n';return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
