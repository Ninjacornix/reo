#include <array>
#include <atomic>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <memory>
#include <new>
#include <malloc.h>
#include "source/composite_backend.cpp"
// Empty fixture token only. No real Binding admission or facade is linked.
namespace ps2_cri_audio {SoundCall::~SoundCall()=default;}
namespace n=reo::native::sound_ram;namespace a=ps2_cri_audio;
using Status=a::BankStatusV2;
thread_local bool track{};unsigned allocations{},frees{},checks{};
void* operator new(std::size_t z){if(track)++allocations;if(auto*p=std::malloc(z?z:1))return p;throw std::bad_alloc();}
void operator delete(void*p)noexcept{if(track&&p)++frees;std::free(p);}void operator delete(void*p,std::size_t)noexcept{::operator delete(p);}
void* operator new(std::size_t z,std::align_val_t a){if(track)++allocations;if(auto*p=_aligned_malloc(z?z:1,std::size_t(a)))return p;throw std::bad_alloc();}
void operator delete(void*p,std::align_val_t)noexcept{if(track&&p)++frees;_aligned_free(p);}void operator delete(void*p,std::size_t,std::align_val_t a)noexcept{::operator delete(p,a);}
void check(bool v){++checks;if(!v)throw std::runtime_error("composite wrapper assertion "+std::to_string(checks));}
enum Op {ensure,queue,configure,consumed,render,discard,drain,release,queued,reset,shutdown,bank,packet,mix,bank_reset,pending,port,sequence,paths,stop,join,admitted,count};
struct Child;Child* expectedChild{};const a::SoundCall* expectedCall{};
struct Child {
    std::array<unsigned,count> calls{};std::array<std::uint64_t,8> args{};
    const void* first{};const void* second{};const void* third{};const a::SoundCall* call{};
    n::RuntimeMemory* memory{};bool permit_join=true;bool queue_ready{};unsigned join_attempts{};
    static Child& get(void*p,Op op){if(p!=expectedChild){std::fputs("composite wrapper child owner mismatch\n",stderr);std::_Exit(41);}auto& c=*static_cast<Child*>(p);++c.calls[op];c.args={};return c;}
    a::BackendRegistrationV2 registration(std::shared_ptr<Child> self){
        a::BackendApiV2 api;api.abi_version=a::backendAbiVersionV2;api.structure_bytes=sizeof(api);api.capabilities=a::backendRequiredCapabilitiesV2;
        auto&p=api.pcm;p.abi_version=a::backendAbiVersionV1;p.structure_bytes=sizeof(p);p.capabilities=a::backendRequiredCapabilitiesV1;
        p.ensure_host_output=[](void*x)noexcept{get(x,ensure);};
        p.queue=[](void*x,std::uint32_t k,const std::uint8_t*b,std::uint32_t size,std::uint64_t& end)noexcept{auto&c=get(x,::queue);c.args={k,size};c.first=b;
            c.queue_ready=c.memory&&!c.memory->pin_active&&c.memory->operation_active&&b==c.memory->owned.data();end=0x123456789ull;return true;};
        p.configure=[](void*x,std::uint32_t v,std::uint32_t l,std::uint32_t r,std::uint32_t channels,std::uint32_t f,std::uint32_t volume,bool play)noexcept{auto&c=get(x,::configure);c.args={v,l,r,channels,f,volume,std::uint64_t(play)};};
        p.consumed=[](void*x,std::uint32_t k)noexcept{auto&c=get(x,::consumed);c.args[0]=k;return std::uint64_t(0xabcdef0123ull);};
        p.render=[](void*x,float*out,unsigned frames)noexcept{auto&c=get(x,::render);c.first=out;c.args[0]=frames;};
        p.discard=[](void*x,std::uint32_t k)noexcept{get(x,::discard).args[0]=k;};
        p.drain=[](void*x,std::uint32_t k)noexcept{get(x,::drain).args[0]=k;};
        p.release=[](void*x,std::uint32_t k)noexcept{get(x,::release).args[0]=k;};
        p.queued_samples=[](void*x,std::uint32_t k)noexcept{get(x,::queued).args[0]=k;return std::size_t(876543);};
        p.reset=[](void*x)noexcept{get(x,::reset);};p.shutdown=[](void*x)noexcept{get(x,::shutdown);};
        p.request_stop=[](void*x)noexcept{get(x,::stop);};p.join=[](void*x)noexcept{auto&c=get(x,::join);++c.join_attempts;return c.permit_join;};
        auto&b=api.banks;
        b.submit_bank=[](void*x,unsigned port,const std::uint8_t*h,std::size_t hn,const std::uint8_t*d,std::size_t dn,const std::uint8_t*t,std::size_t tn)noexcept{auto&c=get(x,::bank);c.args={port,hn,dn,tn};c.first=h;c.second=d;c.third=t;return Status::capacity;};
        b.submit_packet=[](void*x,const std::uint8_t*r,std::size_t rn,const std::uint8_t*p,std::size_t pn)noexcept{auto&c=get(x,::packet);c.args={rn,pn};c.first=r;c.second=p;return Status::invalid_asset;};
        b.mix=[](void*x,float*out,unsigned frames)noexcept{auto&c=get(x,::mix);c.args[0]=frames;c.first=out;return Status::stale_generation;};
        b.reset=[](void*x)noexcept{get(x,::bank_reset);return Status::closed;};
        b.pending_loads=[](void*x)noexcept{get(x,::pending);return a::BankQueryV2{Status::unsupported,51};};
        b.port_state=[](void*x,unsigned p,std::uint32_t&n)noexcept{get(x,::port).args[0]=p;n=53;return a::BankQueryV2{Status::ok,52};};
        b.se_state=[](void*x,unsigned p,unsigned s,unsigned g)noexcept{get(x,::sequence).args={p,s,g};return a::BankQueryV2{Status::invalid_input,54};};
        b.report_audio_paths=[](void*x)noexcept{get(x,::paths);return Status::foreign_runtime;};
        api.render_admitted=[](void*x,a::SoundCall&call,float*out,unsigned frames)noexcept{auto&c=get(x,::admitted);if(&call!=expectedCall){std::fputs("composite wrapper admitted call mismatch\n",stderr);std::_Exit(42);}c.call=&call;c.first=out;c.args[0]=frames;};
        return {api,std::move(self)};
    }
};
namespace reo::native::sound_ram {
struct CompositeBackendTests {
    static auto make(std::shared_ptr<RuntimeMemory> memory,a::BackendRegistrationV2 child){return std::shared_ptr<CompositeBackend>(new CompositeBackend(std::move(memory),std::move(child)));}
    static auto registration(const std::shared_ptr<CompositeBackend>&owner){return owner->registration();}
    static auto companion(const std::shared_ptr<CompositeBackend>&owner){return owner->companion();}
    static bool join(const std::shared_ptr<CompositeBackend>&owner){return owner->join();}
};
}
struct Fixture {
    std::shared_ptr<n::RuntimeMemory> memory=std::make_shared<n::RuntimeMemory>();std::shared_ptr<Child> child=std::make_shared<Child>();
    std::shared_ptr<n::CompositeBackend> owner;
    a::BackendRegistrationV2 registration;a::NativeSoundRamApiV1 companion;
    Fixture(){expectedChild=child.get();child->memory=memory.get();owner=n::CompositeBackendTests::make(memory,child->registration(child));registration=n::CompositeBackendTests::registration(owner);companion=n::CompositeBackendTests::companion(owner);
        check(registration.owner.get()==owner.get()&&registration.owner.get()!=child.get());}
    void* context(){return registration.owner.get();}
};
void all_relays(){
    Fixture f;auto&p=f.registration.api.pcm;auto&b=f.registration.api.banks;auto*x=f.context();auto&c=*f.child;
    check(f.registration.api.abi_version==a::backendAbiVersionV2&&f.registration.api.capabilities==a::backendRequiredCapabilitiesV2);
    p.ensure_host_output(x);check(c.calls[ensure]==1);
    const std::array<std::uint8_t,4> pcm{1,2,3,4};std::uint64_t end=9;
    check(p.queue(x,17,pcm.data(),pcm.size(),end)&&end==0x123456789ull&&c.queue_ready);
    check(c.args[0]==17&&c.args[1]==pcm.size()&&c.first!=pcm.data()&&f.memory->borrowed_pcm==pcm.data());check(std::equal(pcm.begin(),pcm.end(),f.memory->owned.begin()));
    p.configure(x,1,2,3,4,5,6,true);check(c.args==std::array<std::uint64_t,8>{1,2,3,4,5,6,1,0});
    check(p.consumed(x,21)==0xabcdef0123ull&&c.args[0]==21);std::array<float,16> out{};
    track=true;p.render(x,out.data(),7);track=false;check(c.first==out.data()&&c.args[0]==7);
    p.discard(x,22);check(c.args[0]==22);p.drain(x,23);check(c.args[0]==23);p.release(x,24);check(c.args[0]==24);
    check(p.queued_samples(x,25)==876543&&c.args[0]==25);p.reset(x);p.shutdown(x);check(f.memory->retires==0);
    std::array<std::uint8_t,5> hd{};std::array<std::uint8_t,6> bd{};std::array<std::uint8_t,7> tq{};
    check(b.submit_bank(x,3,hd.data(),hd.size(),bd.data(),bd.size(),tq.data(),tq.size())==Status::capacity);
    check(c.args[0]==3&&c.args[1]==5&&c.args[2]==6&&c.args[3]==7&&c.first==hd.data()&&c.second==bd.data()&&c.third==tq.data());
    check(b.submit_packet(x,hd.data(),5,bd.data(),6)==Status::invalid_asset&&c.first==hd.data()&&c.second==bd.data()&&c.args[0]==5&&c.args[1]==6);
    track=true;auto mixed=b.mix(x,out.data(),8);track=false;check(mixed==Status::stale_generation&&c.first==out.data()&&c.args[0]==8);
    check(b.reset(x)==Status::closed);auto q=b.pending_loads(x);check(q.status==Status::unsupported&&q.value==51);std::uint32_t count=99;q=b.port_state(x,4,count);check(q.status==Status::ok&&q.value==52&&count==53&&c.args[0]==4);
    q=b.se_state(x,5,6,7);check(q.status==Status::invalid_input&&q.value==54&&c.args[0]==5&&c.args[1]==6&&c.args[2]==7);check(b.report_audio_paths(x)==Status::foreign_runtime);
    a::SoundCall call;expectedCall=&call;track=true;f.registration.api.render_admitted(x,call,out.data(),9);track=false;check(c.call==&call&&c.first==out.data()&&c.args[0]==9);
    for(unsigned n=0;n<19;++n)check(c.calls[n]==1);check(c.calls[admitted]==1&&allocations==0&&frees==0);
}
void companion_relays(){
    Fixture f;auto&v=f.companion;auto*x=f.context();auto&m=*f.memory;a::SoundCall call;a::NativeSoundRamTokenV1 token;std::array<std::uint8_t,8> bytes{};
    auto*r=reinterpret_cast<PS2Runtime*>(uintptr_t(0x1234));using Space=a::NativeSoundRamSpaceV1;
    check(v.abi_version==a::nativeSoundRamAbiVersionV1&&v.structure_bytes==sizeof(v)&&v.capabilities==a::nativeSoundRamCapabilitiesV1&&v.max_packet_bytes==65536);
    m.status=Status::foreign_runtime;check(v.begin(x,call,r,bytes.data(),a::NativeSoundRamUseV1::status_transfer,token)==Status::foreign_runtime);
    check(m.call==&call&&m.runtime==r&&m.ram==bytes.data()&&m.use==a::NativeSoundRamUseV1::status_transfer&&m.token==&token&&token.opaque[0]==0x12345678);
    a::NativeSoundRamReadV1 reads[]{ {Space::ee,0x2345,bytes} };m.status=Status::capacity;
    check(v.read_batch(x,call,token,{reads,1})==Status::capacity&&m.read_ops.data()==reads&&m.read_ops.size()==1&&m.call==&call&&m.token==&token);
    a::NativeSoundRamControlOpV1 ops[]{ {a::NativeSoundRamControlKindV1::write,Space::iop,0x3456,bytes,bytes.size()} };
    check(v.control_batch(x,call,token,a::NativeSoundRamControlV1::rpc_metadata,{ops,1})==Status::capacity&&m.control_ops.data()==ops&&m.control_kind==a::NativeSoundRamControlV1::rpc_metadata);
    check(v.copy_forward(x,call,token,Space::iop,0x4567,Space::ee,0x5678,777)==Status::capacity&&m.source_space==Space::iop&&m.source==0x4567&&m.destination_space==Space::ee&&m.destination==0x5678&&m.bytes==777);
    a::NativeSoundRamPacketV1 packet;check(v.snapshot_packet(x,call,token,0x6789,7,packet)==Status::capacity&&m.source==0x6789&&m.bytes==7&&packet.data==m.owned.data()&&packet.bytes==7);
    check(v.log_owned_packet(x,call,token,packet)==Status::capacity&&m.packet_value.data==packet.data&&m.packet_value.bytes==packet.bytes);
    v.report(x,call,token,{a::NativeSoundRamStageV1::snapshot,Status::unsupported});check(m.diagnostic.stage==a::NativeSoundRamStageV1::snapshot&&m.diagnostic.status==Status::unsupported);
    v.end(x,call,token);check(m.ends==1&&m.stats.active_slots==0&&token.opaque[0]==0);check(m.begins==1&&m.reads==1&&m.controls==1&&m.forwards==1&&m.snapshots==1&&m.logs==1&&m.reports==1);
}
void lifecycle(){
    Fixture f;auto&p=f.registration.api.pcm;auto*x=f.context();p.request_stop(x);check(f.child->calls[stop]==1&&f.memory->retires==0&&!f.memory->stats.retired);
    f.child->permit_join=false;check(!p.join(x)&&f.memory->retires==0&&!f.memory->stats.retired);f.child->permit_join=true;
    a::SoundCall call;a::NativeSoundRamTokenV1 token;check(f.companion.begin(x,call,nullptr,nullptr,a::NativeSoundRamUseV1::command,token)==Status::ok);
    check(!p.join(x)&&f.memory->retires==1&&!f.memory->stats.retired&&f.memory->stats.active_slots==1);
    f.companion.end(x,call,token);check(p.join(x)&&f.memory->stats.retired&&f.memory->retires==2);auto joins=f.child->join_attempts;
    check(p.join(x)&&f.child->join_attempts==joins&&f.memory->retires==2);
}
void refused_stage(){
    Fixture f;const std::array<std::uint8_t,4> bytes{1,2,3,4};std::uint64_t end=0x98765;f.memory->permit_pcm=false;
    check(!f.registration.api.pcm.queue(f.context(),1,bytes.data(),bytes.size(),end)&&end==0x98765&&f.child->calls[queue]==0);
}
void lifetimes(){
    auto memory=std::make_shared<n::RuntimeMemory>();auto child=std::make_shared<Child>();expectedChild=child.get();child->memory=memory.get();std::weak_ptr<n::RuntimeMemory> wm=memory;std::weak_ptr<Child>wc=child;
    auto owner=n::CompositeBackendTests::make(memory,child->registration(child));std::weak_ptr<n::CompositeBackend>wo=owner;auto reg=n::CompositeBackendTests::registration(owner);
    memory.reset();child.reset();owner.reset();check(!wm.expired()&&!wc.expired()&&!wo.expired());check(reg.api.pcm.join(reg.owner.get()));reg={};check(wm.expired()&&wc.expired()&&wo.expired());
}
int main(int argc,char**argv)try{check(argc==2);std::string mode=argv[1];if(mode=="relays")all_relays();else if(mode=="companion")companion_relays();else if(mode=="lifecycle")lifecycle();else if(mode=="stage")refused_stage();else if(mode=="lifetime")lifetimes();else throw std::runtime_error("wrapper mode");std::cout<<"wrapper checks="<<checks<<'\n';return 0;}catch(const std::exception&e){std::cerr<<e.what()<<'\n';return 1;}
