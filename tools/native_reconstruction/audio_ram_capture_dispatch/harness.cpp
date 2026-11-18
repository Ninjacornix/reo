// Exact126 facades and source-extracted transport with declared fake memory.
// This provider is a test double, NOT a production coherence capability.
#define main prior_dispatch_main
#include "prior/harness.cpp"
#undef main
#include "capture_outer.inc"
static_assert(!std::is_constructible_v<ps2_cri_audio::NativeSoundRamCallV1,ps2_cri_audio::SoundCall&&,PS2Runtime*,uint8_t*,ps2_cri_audio::NativeSoundRamUseV1>);
static_assert(!std::is_constructible_v<ps2_cri_audio::NativeSoundRamCallV1,const ps2_cri_audio::SoundCall&&,PS2Runtime*,uint8_t*,ps2_cri_audio::NativeSoundRamUseV1>);
static_assert(std::is_constructible_v<ps2_cri_audio::NativeSoundRamCallV1,const ps2_cri_audio::SoundCall&,PS2Runtime*,uint8_t*,ps2_cri_audio::NativeSoundRamUseV1>);
namespace c=capture_fixture;
using Status=a::BankStatusV2;
using Space=a::NativeSoundRamSpaceV1;
struct CaptureOwner:Owner {
    std::vector<uint8_t> ee=std::vector<uint8_t>(32u*1024u*1024u);
    std::array<uint8_t,65536> packet{};
    Status begin_result=Status::ok;
    unsigned begins{},ends{},reads{},controls{},copies{},snapshots{},logs{},reports{};
    unsigned reset_at_snapshot{};std::size_t copy_bytes{};
    bool reject_read{},reject_control{},reject_copy{},reject_log{},hold_read{},bad_snapshot{};
    Event read_entered,read_resume;
    a::NativeSoundRamDiagnosticV1 diagnostic{};
};
CaptureOwner& captureOwner(void* p){return *static_cast<CaptureOwner*>(p);}
uint8_t* part(CaptureOwner& o,Space space,uint32_t address,std::size_t bytes){
    const std::size_t at=space==Space::ee?address&0x1fffffffu:address;
    auto* base=space==Space::ee?o.ee.data():o.runtime->memory().getIOPRAM();
    const std::size_t size=space==Space::ee?o.ee.size():2u*1024u*1024u;
    if(at>size||bytes>size-at)return nullptr;return base+at;
}
a::NativeSoundRamApiV1 capability(){
    a::NativeSoundRamApiV1 api;api.abi_version=a::nativeSoundRamAbiVersionV1;api.structure_bytes=sizeof(api);
    api.capabilities=a::nativeSoundRamCapabilitiesV1;api.max_packet_bytes=65536;
    api.begin=[](void* p,const a::SoundCall& accepted,PS2Runtime* r,uint8_t* ram,a::NativeSoundRamUseV1,a::NativeSoundRamTokenV1& token)noexcept{
        auto& o=captureOwner(p);++o.begins;if(!accepted||r!=o.runtime||ram!=o.ee.data())return Status::foreign_runtime;
        token.opaque[0]=0xcafe;return o.begin_result;};
    api.end=[](void* p,const a::SoundCall&,a::NativeSoundRamTokenV1& t)noexcept{auto& o=captureOwner(p);++o.ends;t={};};
    api.read_batch=[](void* p,const a::SoundCall&,a::NativeSoundRamTokenV1& token,std::span<const a::NativeSoundRamReadV1> reads)noexcept{
        auto& o=captureOwner(p);++o.reads;if(token.opaque[0]!=0xcafe)return Status::invalid_input;
        if(o.hold_read){o.read_entered.signal();o.read_resume.wait();}
        if(o.reject_read)return Status::unsupported;
        for(const auto& read:reads)if(!part(o,read.space,read.address,read.destination.size()))return Status::invalid_input;
        for(const auto& read:reads)std::memcpy(read.destination.data(),part(o,read.space,read.address,read.destination.size()),read.destination.size());return Status::ok;};
    api.control_batch=[](void* p,const a::SoundCall&,a::NativeSoundRamTokenV1&,a::NativeSoundRamControlV1,std::span<const a::NativeSoundRamControlOpV1> ops)noexcept{
        auto& o=captureOwner(p);++o.controls;if(o.reject_control)return Status::unsupported;
        for(const auto& op:ops)if(!part(o,op.space,op.address,op.bytes)||(op.kind==a::NativeSoundRamControlKindV1::write&&op.source.size()!=op.bytes))return Status::invalid_input;
        for(const auto& op:ops){auto* dest=part(o,op.space,op.address,op.bytes);if(op.kind==a::NativeSoundRamControlKindV1::zero)std::memset(dest,0,op.bytes);else std::memcpy(dest,op.source.data(),op.bytes);}return Status::ok;};
    api.copy_forward=[](void* p,const a::SoundCall&,a::NativeSoundRamTokenV1&,Space ss,uint32_t src,Space ds,uint32_t dst,std::size_t n)noexcept{
        auto& o=captureOwner(p);++o.copies;o.copy_bytes=n;if(o.reject_copy)return Status::unsupported;
        auto* source=part(o,ss,src,n);auto* target=part(o,ds,dst,n);if(!source||!target)return Status::invalid_input;
        for(std::size_t i=0;i<n;++i)target[i]=source[i];return Status::ok;};
    api.snapshot_packet=[](void* p,const a::SoundCall&,a::NativeSoundRamTokenV1&,uint32_t at,std::size_t n,a::NativeSoundRamPacketV1& out)noexcept{
        auto& o=captureOwner(p);++o.snapshots;o.reset_at_snapshot=o.calls[BankReset];if(n>o.packet.size())return Status::capacity;
        auto* source=part(o,Space::ee,at,n);if(!source)return Status::invalid_input;std::memcpy(o.packet.data(),source,n);out={o.packet.data(),n+(o.bad_snapshot?1:0)};return Status::ok;};
    api.log_owned_packet=[](void* p,const a::SoundCall&,a::NativeSoundRamTokenV1&,a::NativeSoundRamPacketV1 packet)noexcept{
        auto& o=captureOwner(p);++o.logs;if(packet.data!=o.packet.data()||packet.bytes>o.packet.size())return Status::invalid_input;return o.reject_log?Status::no_memory:Status::ok;};
    api.report=[](void* p,const a::SoundCall&,a::NativeSoundRamTokenV1&,a::NativeSoundRamDiagnosticV1 d)noexcept{auto& o=captureOwner(p);++o.reports;o.diagnostic=d;};
    return api;
}
struct CaptureSetup {
    PS2Runtime runtime;std::shared_ptr<CaptureOwner> value=std::make_shared<CaptureOwner>();
    CaptureSetup(){value->runtime=&runtime;runtime.memory().rdram=value->ee.data();}
    auto registration(){return ::registration(value);}
    void install(){check(a::installBackendWithNativeSoundRamBeforeRunV1(runtime,registration(),capability())==a::BackendInstallStatusV1::installed);}
    ~CaptureSetup(){check(runtime.join());}
};
constexpr uint32_t clientAt=0x20000,serverAt=0x21000,sendAt=0x30000,recvAt=0x40000,stackAt=0x50000;
template<class T>void store(CaptureOwner& o,uint32_t at,const T& value){std::memcpy(o.ee.data()+at,&value,sizeof(value));}
template<class T>T readAt(CaptureOwner& o,uint32_t at){T value{};std::memcpy(&value,o.ee.data()+at,sizeof(value));return value;}
c::R5900Context context(CaptureSetup& s,uint32_t sid=0,uint32_t rpc=0,uint32_t count=8){
    c::t_SifRpcClientData cd{};cd.server=serverAt;cd.hdr.sema_id=7;store(*s.value,clientAt,cd);
    c::t_SifRpcServerData sd{};sd.buf=sendAt+2;store(*s.value,serverAt,sd);
    {std::lock_guard lock(c::g_rpc_mutex);c::g_rpc_clients[clientAt].sid=sid;}
    std::memcpy(s.value->ee.data()+sendAt,"ABCDEFGH",8);
    c::R5900Context ctx;ctx.regs[4]=clientAt;ctx.regs[5]=rpc;ctx.regs[6]=0;ctx.regs[7]=sendAt;
    ctx.regs[8]=count;ctx.regs[9]=recvAt;ctx.regs[10]=8;ctx.regs[29]=stackAt;return ctx;
}
void invalid_capture(){CaptureSetup s;for(unsigned i=0;i<12;++i){auto api=capability();switch(i){
    case 0:api.begin=nullptr;break;case 1:api.end=nullptr;break;case 2:api.read_batch=nullptr;break;case 3:api.control_batch=nullptr;break;
    case 4:api.copy_forward=nullptr;break;case 5:api.snapshot_packet=nullptr;break;case 6:api.log_owned_packet=nullptr;break;case 7:api.report=nullptr;break;
    case 8:api.structure_bytes--;break;case 9:api.abi_version++;break;case 10:api.capabilities=0;break;case 11:api.max_packet_bytes=0;break;}
    check(a::installBackendWithNativeSoundRamBeforeRunV1(s.runtime,s.registration(),api)==a::BackendInstallStatusV1::invalid_api);}
    check(!a::nativeSoundRamSelectedV1()&&s.value->begins==0);s.install();check(a::nativeSoundRamSelectedV1());}
void missing_capture(){CaptureSetup s;check(a::installBackendBeforeRunV2(s.runtime,s.registration())==a::BackendInstallStatusV1::installed);
    check(!a::nativeSoundRamSelectedV1());auto call=a::acquireSoundCall(&s.runtime);a::NativeSoundRamCallV1 cap(call,&s.runtime,s.value->ee.data(),a::NativeSoundRamUseV1::query);
    check(!cap&&!cap.selected()&&cap.status()==Status::unsupported&&s.value->begins==0);}
void foreign_capture(){CaptureSetup s;s.install();PS2Runtime other;auto call=a::acquireSoundCall(&s.runtime);
    {a::NativeSoundRamCallV1 cap(call,&other,s.value->ee.data(),a::NativeSoundRamUseV1::query);check(!cap&&cap.status()==Status::foreign_runtime);}
    {a::NativeSoundRamCallV1 cap(call,&s.runtime,s.value->ee.data()+1,a::NativeSoundRamUseV1::query);check(!cap);}
    check(s.value->begins==0&&s.value->ends==0);}
void unavailable_capture(){CaptureSetup s;s.install();auto ctx=context(s);s.value->begin_result=Status::unsupported;
    const auto before=s.value->ee;check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));
    check(ctx.result==-1&&s.value->ee==before&&s.value->begins==1&&s.value->ends==1&&s.value->reads==0&&s.value->controls==0&&s.value->snapshots==0);
    check(s.value->calls[PacketSubmit]==0&&s.value->calls[BankReset]==0&&c::signals==0&&!c::g_rpc_clients[clientAt].busy&&s.value->reports==1);}
void accepted_stop(){CaptureSetup s;s.install();auto call=a::acquireSoundCall(&s.runtime);s.runtime.stop();
    {a::NativeSoundRamCallV1 cap(call,&s.runtime,s.value->ee.data(),a::NativeSoundRamUseV1::query);check(bool(cap));uint32_t v=3;
        a::NativeSoundRamWriteV1 w{Space::ee,0x10000,{reinterpret_cast<const uint8_t*>(&v),4}};check(cap.write({&w,1},a::NativeSoundRamControlV1::query_reply)==Status::ok);}
    check(s.value->begins==1&&s.value->ends==1&&readAt<uint32_t>(*s.value,0x10000)==3);call={};check(s.runtime.join());}
void paused_capture(){CaptureSetup s;s.install();s.value->hold_read=true;auto weak=std::weak_ptr<CaptureOwner>(s.value);std::atomic<bool> joined{};
    std::thread producer([&]{auto call=a::acquireSoundCall(&s.runtime);a::NativeSoundRamCallV1 cap(call,&s.runtime,s.value->ee.data(),a::NativeSoundRamUseV1::query);
        uint32_t v{};a::NativeSoundRamReadV1 r{Space::ee,0x10000,{reinterpret_cast<uint8_t*>(&v),4}};check(cap.read({&r,1})==Status::ok);});
    s.value->read_entered.wait();s.runtime.stop();std::thread joiner([&]{check(s.runtime.join());joined=true;});
    check(!joined&&s.value->calls[Shutdown]==0&&s.value->calls[Join]==0&&!weak.expired());s.value->read_resume.signal();producer.join();joiner.join();
    check(joined&&s.value->ends==1&&s.value->calls[Shutdown]==1&&s.value->calls[Join]==1);}
void forward_alias(){CaptureSetup s;s.install();auto call=a::acquireSoundCall(&s.runtime);a::NativeSoundRamCallV1 cap(call,&s.runtime,s.value->ee.data(),a::NativeSoundRamUseV1::command);
    std::memcpy(s.value->ee.data()+sendAt,"ABCDEFGH",8);check(cap.forward(Space::ee,sendAt,Space::ee,sendAt+2,6)==Status::ok);
    check(std::memcmp(s.value->ee.data()+sendAt,"ABABABAB",8)==0);std::array<char,8> wrong{'A','B','C','D','E','F','G','H'};
    std::memmove(wrong.data()+2,wrong.data(),6);check(std::memcmp(wrong.data(),s.value->ee.data()+sendAt,8)!=0);}
void packet_order(){CaptureSetup s;s.install();auto ctx=context(s);check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));
    check(ctx.result==0&&s.value->snapshots==1&&s.value->logs==1&&s.value->calls[PacketSubmit]==1&&s.value->reset_at_snapshot==1);
    check(std::memcmp(s.value->packet.data(),"ABABABAB",8)==0&&rpc_fixture::log_count==0&&rpc_fixture::read_count==0&&s.value->ends==1);}
void nonzero_server(){CaptureSetup s;s.install();auto ctx=context(s);auto sd=readAt<c::t_SifRpcServerData>(*s.value,serverAt);sd.func=0x123456;store(*s.value,serverAt,sd);
    const auto before=s.value->ee;check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==-1&&s.value->ee==before&&s.value->controls==0&&s.value->copies==0&&s.value->calls[PacketSubmit]==0&&c::signals==0);check(s.value->diagnostic.status==Status::unsupported);}
void descriptor_alias(){CaptureSetup s;s.install();auto ctx=context(s);auto cd=readAt<c::t_SifRpcClientData>(*s.value,clientAt);cd.server=clientAt;store(*s.value,clientAt,cd);
    const auto before=s.value->ee;check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==-1&&s.value->ee==before&&s.value->controls==0&&s.value->copies==0);}
void payload_metadata(){CaptureSetup s;s.install();auto ctx=context(s);auto sd=readAt<c::t_SifRpcServerData>(*s.value,serverAt);sd.buf=clientAt;store(*s.value,serverAt,sd);
    const auto before=s.value->ee;check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==-1&&s.value->ee==before&&s.value->controls==0&&s.value->copies==0);}
void refusal_read(){CaptureSetup s;s.install();auto ctx=context(s);s.value->reject_read=true;const auto before=s.value->ee;
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==-1&&s.value->ee==before&&s.value->controls==0&&s.value->calls[BankReset]==0&&c::signals==0);}
void refusal_control(){CaptureSetup s;s.install();auto ctx=context(s);s.value->reject_control=true;const auto before=s.value->ee;
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==-1&&s.value->ee==before&&s.value->copies==0&&s.value->calls[BankReset]==0&&c::signals==0);}
void log_failure(){CaptureSetup s;s.install();auto ctx=context(s);s.value->reject_log=true;check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));
    check(ctx.result==0&&s.value->calls[PacketSubmit]==1&&s.value->reports==1&&s.value->diagnostic.stage==a::NativeSoundRamStageV1::log);}
void query_capture(){CaptureSetup s;s.install();auto ctx=context(s,1,6,4);auto sd=readAt<c::t_SifRpcServerData>(*s.value,serverAt);sd.buf=0;store(*s.value,serverAt,sd);
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==0&&readAt<uint32_t>(*s.value,recvAt)==1&&readAt<uint32_t>(*s.value,recvAt+4)==7&&s.value->calls[Port]==1&&s.value->snapshots==0);}
void clamp_capture(){CaptureSetup s;s.install();auto ctx=context(s,1,6,0x100001);auto sd=readAt<c::t_SifRpcServerData>(*s.value,serverAt);sd.buf=0x100000;store(*s.value,serverAt,sd);
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==0&&s.value->copy_bytes==0x100000);}
void status_capture(){CaptureSetup s;s.install();auto ctx=context(s,1,0x12,0);auto sd=readAt<c::t_SifRpcServerData>(*s.value,serverAt);sd.buf=0;store(*s.value,serverAt,sd);
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));const uint32_t status=readAt<uint32_t>(*s.value,recvAt);check(ctx.result==0&&status!=0&&rpc_fixture::g_soundDriverRpcState.initialized);
    s.runtime.memory().getIOPRAM()[status+1]=0x57;rpc_fixture::R5900Context transfer;transfer.regs[4]=0x60000;transfer.regs[5]=status;transfer.regs[6]=0x70000;transfer.regs[7]=4;
    sif_fixture::sceSifGetOtherData(s.value->ee.data(),&transfer,&s.runtime);check(transfer.result==0&&s.value->ee[0x70001]==0x57&&readAt<uint32_t>(*s.value,0x60010)==status&&s.value->copy_bytes==4);}
void snapshot_contract(){CaptureSetup s;s.install();auto call=a::acquireSoundCall(&s.runtime);a::NativeSoundRamCallV1 cap(call,&s.runtime,s.value->ee.data(),a::NativeSoundRamUseV1::command);
    a::NativeSoundRamPacketV1 p;check(cap.snapshot(sendAt,65537,p)==Status::capacity&&s.value->snapshots==0);}
void busy_capture(){CaptureSetup s;s.install();auto ctx=context(s);s.value->begin_result=Status::rejected;const auto before=s.value->ee;
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==-1&&s.value->ee==before&&s.value->reads==0&&s.value->ends==1&&s.value->diagnostic.status==Status::rejected&&c::signals==0);}
void strong_capture(){CaptureSetup s;s.install();auto call=a::acquireSoundCall(&s.runtime);auto* value=s.value.get();auto weak=std::weak_ptr<CaptureOwner>(s.value);
    s.value.reset();check(!weak.expired());{a::NativeSoundRamCallV1 cap(call,&s.runtime,value->ee.data(),a::NativeSoundRamUseV1::query);check(bool(cap));}
    check(value->ends==1);call={};check(s.runtime.join());s.runtime.workers.clear();check(weak.expired());}
void transport_refusal(){CaptureSetup s;s.install();auto ctx=context(s);s.value->reject_copy=true;const auto payload=std::array<uint8_t,8>{'A','B','C','D','E','F','G','H'};
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==-1&&std::memcmp(s.value->ee.data()+sendAt,payload.data(),8)==0&&s.value->snapshots==0&&s.value->logs==0&&s.value->calls[PacketSubmit]==0&&s.value->calls[BankReset]==0&&c::signal_ids==std::vector<uint32_t>({7}));}
void malformed_snapshot(){CaptureSetup s;s.install();auto ctx=context(s);s.value->bad_snapshot=true;check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));
    check(ctx.result==-1&&s.value->calls[PacketSubmit]==0&&s.value->logs==0&&s.value->diagnostic.status==Status::invalid_input);}
void iop_extent_refusal(){CaptureSetup s;s.install();auto ctx=context(s,1,0x12,0);auto sd=readAt<c::t_SifRpcServerData>(*s.value,serverAt);sd.buf=0;store(*s.value,serverAt,sd);
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));const auto status=readAt<uint32_t>(*s.value,recvAt);const auto before=s.value->ee;const auto copies=s.value->copies;
    rpc_fixture::R5900Context transfer;transfer.regs[4]=0x60000;transfer.regs[5]=status-1;transfer.regs[6]=0x70000;transfer.regs[7]=4;
    sif_fixture::sceSifGetOtherData(s.value->ee.data(),&transfer,&s.runtime);check(transfer.result==-1&&s.value->ee==before&&s.value->copies==copies);}
void install_run(){CaptureSetup s;Event registered,resume,run_started;std::atomic<bool> run_done{};a::BackendInstallStatusV1 result{};
    s.runtime.registered=[&]{registered.signal();resume.wait();};
    std::thread installer([&]{result=a::installBackendWithNativeSoundRamBeforeRunV1(s.runtime,s.registration(),capability());});registered.wait();
    {std::lock_guard lock(s.runtime.m_externalWorkersMutex);check(s.runtime.m_preRunSetupCount==1&&!s.runtime.m_externalWorkersSealed);}
    std::thread runner([&]{run_started.signal();s.runtime.beginExternalWorkerRun();run_done=true;});run_started.wait();
    check(!run_done&&!a::nativeSoundRamSelectedV1());resume.signal();installer.join();runner.join();
    check(result==a::BackendInstallStatusV1::installed&&run_done&&a::nativeSoundRamSelectedV1()&&s.runtime.m_preRunSetupCount==0&&s.runtime.m_externalWorkersSealed);}
void run_first(){CaptureSetup s;s.runtime.beginExternalWorkerRun();check(a::installBackendWithNativeSoundRamBeforeRunV1(s.runtime,s.registration(),capability())==a::BackendInstallStatusV1::runtime_rejected);
    check(!a::nativeSoundRamSelectedV1()&&a::backendStatusV1().selection==a::BackendSelectionV1::unselected&&s.runtime.workers.empty());}
void stop_install(){CaptureSetup s;s.runtime.registered=[&]{s.runtime.stop();};check(a::installBackendWithNativeSoundRamBeforeRunV1(s.runtime,s.registration(),capability())==a::BackendInstallStatusV1::runtime_rejected);
    check(!a::nativeSoundRamSelectedV1()&&a::backendStatusV1().selection==a::BackendSelectionV1::unselected&&s.value->begins==0&&s.value->calls[Stop]==0&&s.value->calls[Shutdown]==0&&s.value->calls[Join]==0);}
void stack_capture(){CaptureSetup s;s.install();auto ctx=context(s,1,6,4);auto sd=readAt<c::t_SifRpcServerData>(*s.value,serverAt);sd.buf=0;store(*s.value,serverAt,sd);
    ctx.regs[8]=0xffffffffu;const uint32_t words[]{4,recvAt,8,0,0};std::memcpy(s.value->ee.data()+stackAt+0x10,words,sizeof(words));
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==0&&readAt<uint32_t>(*s.value,recvAt)==1&&readAt<uint32_t>(*s.value,recvAt+4)==7);}
void callback_capture(){CaptureSetup s;s.install();auto ctx=context(s,1,6,4);auto sd=readAt<c::t_SifRpcServerData>(*s.value,serverAt);sd.buf=0;store(*s.value,serverAt,sd);
    constexpr uint32_t callback=0x123450,busy=0x80000;ctx.regs[11]=callback;c::g_soundDriverCompatLayout.completionCallbacks[0]=callback;c::g_soundDriverCompatLayout.clearBusyCallbacks[0]=callback;c::g_soundDriverCompatLayout.busyFlagAddr=busy;
    store(*s.value,busy,1u);c::callback=[&]{store(*s.value,clientAt+offsetof(c::t_SifRpcClientData,hdr)+offsetof(c::t_SifRpcHeader,sema_id),19u);};
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==0&&readAt<uint32_t>(*s.value,busy)==0&&c::signal_ids==std::vector<uint32_t>({19,19}));}
void callback_alias(){CaptureSetup s;s.install();auto ctx=context(s,1,6,4);auto sd=readAt<c::t_SifRpcServerData>(*s.value,serverAt);sd.buf=0;store(*s.value,serverAt,sd);
    constexpr uint32_t callback=0x123450,busy=clientAt+offsetof(c::t_SifRpcClientData,hdr)+offsetof(c::t_SifRpcHeader,sema_id);
    ctx.regs[11]=callback;store(*s.value,stackAt,23u);c::g_soundDriverCompatLayout.completionCallbacks[0]=callback;c::g_soundDriverCompatLayout.clearBusyCallbacks[0]=callback;c::g_soundDriverCompatLayout.busyFlagAddr=busy;
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==0&&readAt<uint32_t>(*s.value,busy)==0&&c::signal_ids==std::vector<uint32_t>({7,23}));}
void backfill_capture(){CaptureSetup s;s.install();auto ctx=context(s,1,0x12,0);auto sd=readAt<c::t_SifRpcServerData>(*s.value,serverAt);sd.buf=0;store(*s.value,serverAt,sd);
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));const auto status=readAt<uint32_t>(*s.value,recvAt);
    auto& layout=c::g_soundDriverCompatLayout;layout.primarySeCheckAddr=0x80000;layout.primaryMidiCheckAddr=0x80100;layout.fallbackSeCheckAddr=0x80200;layout.fallbackMidiCheckAddr=0x80300;
    for(unsigned scenario=0;scenario<3;++scenario){
        std::fill_n(s.value->ee.data()+0x80000,0x400,0);std::fill_n(s.runtime.memory().getIOPRAM()+status,0x42,0);
        const int16_t se[]{1,-2,0,4,5},midi[]{6,0,-8,9};const auto sa=scenario==1?layout.fallbackSeCheckAddr:layout.primarySeCheckAddr;const auto ma=scenario==1?layout.fallbackMidiCheckAddr:layout.primaryMidiCheckAddr;
        std::memcpy(s.value->ee.data()+sa,se,sizeof(se));std::memcpy(s.value->ee.data()+ma,midi,sizeof(midi));
        if(scenario==2){std::fill_n(s.value->ee.data()+layout.primarySeCheckAddr,sizeof(se),0);std::memcpy(s.value->ee.data()+layout.fallbackSeCheckAddr,se,sizeof(se));}
        const int16_t live=77;std::memcpy(s.runtime.memory().getIOPRAM()+status+rpc_fixture::kSoundDriverSeSumOffset,&live,2);
        std::array<uint8_t,0x42> before{},expected{};std::memcpy(before.data(),s.runtime.memory().getIOPRAM()+status,before.size());
        original_status_fixture::backfillSoundDriverStatusFromCompatUnlocked(s.value->ee.data());std::memcpy(expected.data(),s.runtime.memory().getIOPRAM()+status,expected.size());
        std::memcpy(s.runtime.memory().getIOPRAM()+status,before.data(),before.size());auto call=a::acquireSoundCall(&s.runtime);a::NativeSoundRamCallV1 cap(call,&s.runtime,s.value->ee.data(),a::NativeSoundRamUseV1::status_transfer);
        check(rpc_fixture::backfillSoundDriverStatusCaptured(cap));check(std::memcmp(expected.data(),s.runtime.memory().getIOPRAM()+status,expected.size())==0);
    }}
void unknown_capture(uint32_t sid){CaptureSetup s;s.install();auto ctx=context(s,sid,0xdeadbeefu);const auto before=s.value->ee;
    check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==-1&&s.value->ee==before&&s.value->reads==0&&s.value->controls==0&&s.value->copies==0&&s.value->snapshots==0&&s.value->logs==0&&s.value->calls[PacketSubmit]==0&&s.value->calls[BankReset]==0&&c::signals==0&&s.value->begins==1&&s.value->ends==1&&s.value->diagnostic.status==Status::unsupported);
    uint32_t result=123;bool signal=true;check(rpc_fixture::handleSoundDriverRpcService(s.value->ee.data(),&s.runtime,sid,0xdeadbeefu,sendAt,8,recvAt,8,result,signal));
    check(result==0&&!signal&&s.value->reads==0&&s.value->controls==0&&s.value->begins==2&&s.value->ends==2&&s.value->ee==before);}
int main(int argc,char** argv){try{check(argc==2);const std::string name=argv[1];
    if(name=="invalid")invalid_capture();else if(name=="missing")missing_capture();else if(name=="foreign")foreign_capture();else if(name=="unavailable")unavailable_capture();
    else if(name=="accepted_stop")accepted_stop();else if(name=="paused")paused_capture();else if(name=="alias")forward_alias();else if(name=="packet")packet_order();
    else if(name=="server")nonzero_server();else if(name=="descriptor_alias")descriptor_alias();else if(name=="payload_metadata")payload_metadata();
    else if(name=="read_refusal")refusal_read();else if(name=="control_refusal")refusal_control();else if(name=="log_failure")log_failure();
    else if(name=="query")query_capture();else if(name=="clamp")clamp_capture();else if(name=="status")status_capture();else if(name=="snapshot")snapshot_contract();
    else if(name=="busy")busy_capture();else if(name=="strong")strong_capture();else if(name=="transport_refusal")transport_refusal();else if(name=="malformed_snapshot")malformed_snapshot();else if(name=="iop_extent")iop_extent_refusal();
    else if(name=="install_run")install_run();else if(name=="run_first")run_first();else if(name=="stop_install")stop_install();
    else if(name=="stack")stack_capture();else if(name=="callback")callback_capture();else if(name=="backfill")backfill_capture();
    else if(name=="unknown0")unknown_capture(0);else if(name=="unknown1")unknown_capture(1);
    else if(name=="callback_alias")callback_alias();
    else throw std::runtime_error("unknown scenario");std::cout<<"pass "<<name<<'\n';return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
