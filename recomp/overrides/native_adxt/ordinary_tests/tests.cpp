// Actual ordinary adapter/native workers; original calls, registry, mount
// acquisition and selected factory are declared ports. No game/device launch.
#include "ordinary_runtime_body.cpp"
#include "handle_fixture.hpp"
#include <windows.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>

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
std::array<Asset,2> assets;
void pending(Memory& memory,unsigned slot,unsigned asset){
    const auto at=b::handles.base+slot*b::handles.stride;const auto& data=assets[asset];
    memory.bytes[at+1]=1;memory.bytes[at+2]=1;memory.bytes[at+0xac]=1;
    constexpr auto name=0x1900100;std::memcpy(memory.bytes+name,"netbio01.dat",12);
    b::store(memory.bytes,at+0xb4,std::uint32_t(name));b::store(memory.bytes,at+0xb8,0u);b::store(memory.bytes,at+0xbc,data.start);b::store(memory.bytes,at+0xc0,data.count);
}
void close(PS2Runtime& runtime){runtime.requestStop();depth=0;check(runtime.join());depth=1;}
template<class F>void until(F&& done){const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(30);while(!done()){check(std::chrono::steady_clock::now()<end);std::this_thread::yield();}}
void group(PS2Runtime& runtime){b::store(runtime.storage.ram,0x20f3c4,b::load<std::uint32_t>(runtime.storage.ram,0x20f3c4)+1);(void)call(runtime,0x132c08);}
void install(PS2Runtime& runtime){const auto result=b::install_ordinary_before_run(runtime,{},{});check(result.status==sr::InstallStatus::installed && factory_calls==1 && runtime.workers.size()==2 && b::current()->active);}
void prepare_handles(Memory& memory){for(unsigned i=0;i<3;++i)construct(memory,i,i==2?1:2);declared_order->routes={0x1e0100,0x1e0000,0x1e0080};b::store(memory.bytes,0x21b788,6000u);}
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
    if(mode=="ordinary" || mode=="metadata_three")ordinary(memory,runtime,mode=="metadata_three");
    else if(mode=="missing_one" || mode=="missing_two")missing_order(memory,runtime,mode=="missing_one"?1:2);
    else if(mode=="phase" || mode=="image" || mode=="entry" || mode=="mount" || mode=="worker" || mode=="registry" || mode=="factory")admission(mode,memory,runtime);
    else refusal(mode,memory,runtime);
    close(runtime);std::cout<<"ordinary ABI declared-port "<<mode<<" checks="<<checks<<'\n';return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
