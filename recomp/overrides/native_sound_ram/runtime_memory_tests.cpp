// The verifier supplies exact production method bodies and exact public
// contracts, but substitutes explicitly FAKE acquisition/context dependencies.
// This does not mint a real Runtime, CD seal, GS lease, or SDK SoundCall.
#include <algorithm>
#include <array>
#include <atomic>
#include <condition_variable>
#include <cstring>
#include <iostream>
#include <memory>
#include <mutex>
#include <span>
#include <thread>
#include <vector>
#include "game/native/ram_capture/v2/cpu_authority_gate.hpp"
#include "recomp/overrides/native_geometry/reo_vu_native_sha256.h"
#include "game/native/audio_banks/v2/test_inputs.hpp"
#include "unit_contracts.inc"

thread_local unsigned fake_guest_depth=0;
std::atomic<bool> fake_cd_valid{true},fake_gs_valid{true},fake_owner{false},fake_enrollment{false};
std::atomic<unsigned> fake_gs_releases{0};
class PS2Runtime {
public:
    struct Memory {
        std::vector<std::uint8_t> ee=std::vector<std::uint8_t>(32u*1024u*1024u);
        std::vector<std::uint8_t> iop=std::vector<std::uint8_t>(2u*1024u*1024u);
        std::uint8_t* getRDRAM(){return ee.data();}std::uint8_t* getIOPRAM(){return iop.data();}
    } backing;
    Memory& memory(){return backing;}
    bool stopped{};
};
std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*)noexcept{return fake_guest_depth;}
std::uint32_t ps2IoRegLockDepth()noexcept{return 0;}
namespace reo_cd_async {
class ConfigurationReceipt{};
class SyncRamWriteSeal {
public:
    SyncRamWriteSeal()=default;SyncRamWriteSeal(SyncRamWriteSeal&&)=default;
    SyncRamWriteSeal& operator=(SyncRamWriteSeal&&)=default;
    bool matches(PS2Runtime&,const std::uint8_t*,std::size_t)const noexcept{return fake_cd_valid;}
};
}
namespace gs_backend_bridge {
class SoundRamSelectionLeaseV1 {
public:
    bool matches(PS2Runtime&,const void*,const void*)const noexcept{return fake_gs_valid;}
    void release()noexcept{++fake_gs_releases;}
};
}
namespace reo_parent_natural {
bool anyActualOwnerBound()noexcept{return fake_owner;}
bool actualFirstEntryEnrollmentRequested()noexcept{return fake_enrollment;}
}
#include "runtime_memory_impl.inc"

namespace reo::native::sound_ram {
// This friend creates a protocol fixture, deliberately bypassing actual prepare.
// Production CompositeBackend has a different definition in a different binary.
class CompositeBackend {
public:
    static std::shared_ptr<RuntimeMemory> fixture(PS2Runtime& r,ram_capture::v2::Coordinator& gate) {
        packet::MemoryIdentity id;id.ram_bytes=AddressDomain::ee_bytes;id.runtime_incarnation=1;id.ram_incarnation=1;
        id.session.fill(1);id.executable_sha256.fill(2);id.native_build_sha256.fill(3);
        auto state=std::make_unique<RuntimeMemory::State>(r,r.memory().getRDRAM(),r.memory().getIOPRAM(),id,gate,
            reo_cd_async::SyncRamWriteSeal{},gs_backend_bridge::SoundRamSelectionLeaseV1{},nonce());
        return std::shared_ptr<RuntimeMemory>(new RuntimeMemory(std::move(state)));
    }
    static void exhaust_generation(RuntimeMemory& m,std::size_t i){m.state_->slots[i].generation=UINTPTR_MAX;}
};
}
namespace sr=reo::native::sound_ram;
namespace sdk=ps2_cri_audio;
namespace gate=reo::native::ram_capture::v2;
namespace pkt=reo::native::bank_packets::v3;
namespace agg=reo::native::audio_aggregate::v2;
using Status=sdk::BankStatusV2;
using Token=sdk::NativeSoundRamTokenV1;
using Space=sdk::NativeSoundRamSpaceV1;
bool empty(const Token& t){return std::all_of(std::begin(t.opaque),std::end(t.opaque),[](auto n){return n==0;});}
unsigned assertions=0;
#define CHECK(x) do{++assertions;if(!(x)){std::cerr<<"FAIL line "<<__LINE__<<": " #x "\n";return false;}}while(false)
struct Fixture {
    PS2Runtime runtime;gate::Coordinator coordinator;sdk::SoundCall call;
    std::shared_ptr<sr::RuntimeMemory> memory=sr::CompositeBackend::fixture(runtime,coordinator);
    std::uint8_t* ee=runtime.memory().getRDRAM();std::uint8_t* iop=runtime.memory().getIOPRAM();
    Fixture(){fake_guest_depth=1;fake_cd_valid=true;fake_gs_valid=true;fake_owner=false;fake_enrollment=false;}
    Status begin(Token& t){return memory->begin(call,&runtime,ee,sdk::NativeSoundRamUseV1::command,t);}
    ~Fixture(){fake_guest_depth=0;(void)memory->retire_after_outer_drain();}
};
bool tokens() {
    Fixture f;Token t{};
    auto& guest_token=*reinterpret_cast<Token*>(f.ee+0x200);
    CHECK(f.begin(guest_token)==Status::invalid_input);
    auto& guest_call=*reinterpret_cast<sdk::SoundCall*>(f.ee+0x100);
    CHECK(f.memory->begin(guest_call,&f.runtime,f.ee,sdk::NativeSoundRamUseV1::command,t)==Status::invalid_input);
    CHECK(f.begin(t)==Status::ok);auto saved=t;
    CHECK(f.begin(t)==Status::invalid_input);CHECK(std::memcmp(&saved,&t,sizeof(t))==0);
    CHECK(!f.memory->retire_after_outer_drain());
    std::array<std::uint8_t,4> out{};sdk::NativeSoundRamReadV1 read{Space::ee,0x100,out};
    sdk::SoundCall other;CHECK(f.memory->read_batch(other,t,{&read,1})==Status::foreign_runtime);
    CHECK(f.memory->read_batch(f.call,guest_token,{&read,1})==Status::invalid_input);
    auto copied=t;CHECK(f.memory->read_batch(f.call,copied,{&read,1})==Status::foreign_runtime);
    f.memory->end(f.call,copied);CHECK(f.memory->statistics().active_slots==1);
    CHECK(f.memory->read_batch(f.call,t,{&read,1})==Status::ok);
    auto bad=t;bad.opaque[3]^=1;CHECK(f.memory->read_batch(f.call,bad,{&read,1})==Status::foreign_runtime);
    Status cross=Status::ok;std::thread thread([&]{fake_guest_depth=1;cross=f.memory->read_batch(f.call,t,{&read,1});});thread.join();
    CHECK(cross==Status::foreign_runtime);
    f.runtime.stopped=true;CHECK(f.memory->read_batch(f.call,t,{&read,1})==Status::ok);
    fake_guest_depth=0;CHECK(f.memory->read_batch(f.call,t,{&read,1})==Status::foreign_runtime);
    f.memory->end(f.call,t);CHECK(empty(t));fake_guest_depth=1;
    CHECK(f.begin(t)==Status::ok);CHECK(f.memory->read_batch(f.call,saved,{&read,1})==Status::foreign_runtime);
    f.memory->end(f.call,t);
    std::array<Token,16> all{};for(auto& token:all)CHECK(f.begin(token)==Status::ok);
    CHECK(f.begin(t)==Status::capacity);CHECK(empty(t));for(auto& token:all)f.memory->end(f.call,token);
    sr::CompositeBackend::exhaust_generation(*f.memory,0);
    for(std::size_t i=0;i<15;++i)CHECK(f.begin(all[i])==Status::ok);
    CHECK(f.begin(t)==Status::capacity);for(std::size_t i=0;i<15;++i)f.memory->end(f.call,all[i]);
    fake_guest_depth=0;CHECK(f.memory->retire_after_outer_drain());auto releases=fake_gs_releases.load();
    CHECK(f.memory->retire_after_outer_drain());CHECK(fake_gs_releases==releases);
    return true;
}
bool batches() {
    Fixture f;Token t{};CHECK(f.begin(t)==Status::ok);
    for(unsigned i=0;i<16;++i)f.ee[0x100+i]=std::uint8_t(i+1);
    std::array<std::uint8_t,8> out{};
    std::array<sdk::NativeSoundRamReadV1,2> reads{{{Space::ee,0x100,out},{Space::ee,0x01000000,{out.data(),1}}}};
    CHECK(f.memory->read_batch(f.call,t,reads)==Status::unsupported);CHECK(out==decltype(out){});
    reads[1]={Space::iop,0,{out.data()+4,4}};
    CHECK(f.memory->read_batch(f.call,t,reads)==Status::invalid_input);CHECK(out==decltype(out){});
    reads[0]={Space::ee,0x80000100,{out.data(),4}};f.iop[0]=19;
    CHECK(f.memory->read_batch(f.call,t,reads)==Status::ok);CHECK(out[0]==1&&out[3]==4&&out[4]==19);
    sdk::NativeSoundRamReadV1 alias{Space::ee,0x100,{f.ee+0x200,4}};
    CHECK(f.memory->read_batch(f.call,t,{&alias,1})==Status::invalid_input);
    alias.destination={reinterpret_cast<std::uint8_t*>(&t),4};CHECK(f.memory->read_batch(f.call,t,{&alias,1})==Status::invalid_input);
    alias.destination={reinterpret_cast<std::uint8_t*>(&f.call),1};CHECK(f.memory->read_batch(f.call,t,{&alias,1})==Status::invalid_input);
    alias.destination={reinterpret_cast<std::uint8_t*>(f.memory.get()),sizeof(void*)};CHECK(f.memory->read_batch(f.call,t,{&alias,1})==Status::invalid_input);
    CHECK(f.memory->read_batch(f.call,t,{reinterpret_cast<const sdk::NativeSoundRamReadV1*>(f.ee),1})==Status::invalid_input);
    std::array<sdk::NativeSoundRamReadV1,17> too_many{};CHECK(f.memory->read_batch(f.call,t,too_many)==Status::capacity);
    std::array<std::uint8_t,4> source{21,22,23,24};
    std::array<sdk::NativeSoundRamControlOpV1,2> writes{{{sdk::NativeSoundRamControlKindV1::write,Space::ee,0x300,source,4},
        {sdk::NativeSoundRamControlKindV1::zero,Space::iop,0x200000,{},1}}};
    CHECK(f.memory->control_batch(f.call,t,sdk::NativeSoundRamControlV1::rpc_metadata,writes)==Status::unsupported);CHECK(f.ee[0x300]==0);
    CHECK(f.memory->control_batch(f.call,t,sdk::NativeSoundRamControlV1::rpc_metadata,{reinterpret_cast<const sdk::NativeSoundRamControlOpV1*>(f.ee),1})==Status::invalid_input);
    writes[1].address=0;CHECK(f.memory->control_batch(f.call,t,sdk::NativeSoundRamControlV1::rpc_metadata,writes)==Status::ok);
    CHECK(f.ee[0x300]==21&&f.ee[0x303]==24&&f.iop[0]==0);
    writes[0].source={f.ee+0x100,4};CHECK(f.memory->control_batch(f.call,t,sdk::NativeSoundRamControlV1::query_reply,{writes.data(),1})==Status::invalid_input);
    fake_owner=true;CHECK(f.memory->read_batch(f.call,t,{reads.data(),1})==Status::foreign_runtime);fake_owner=false;
    fake_enrollment=true;CHECK(f.memory->read_batch(f.call,t,{reads.data(),1})==Status::foreign_runtime);fake_enrollment=false;
    fake_cd_valid=false;CHECK(f.memory->read_batch(f.call,t,{reads.data(),1})==Status::foreign_runtime);fake_cd_valid=true;
    fake_gs_valid=false;CHECK(f.memory->read_batch(f.call,t,{reads.data(),1})==Status::foreign_runtime);fake_gs_valid=true;
    CHECK(f.coordinator.observe(f.ee).cpu_groups==0);f.memory->end(f.call,t);return true;
}
bool forward() {
    Fixture f;Token t{};CHECK(f.begin(t)==Status::ok);std::memcpy(f.ee+0x100,"ABCDEFGH",8);
    CHECK(f.memory->copy_forward(f.call,t,Space::ee,0x100,Space::ee,0x102,6)==Status::ok);
    CHECK(std::memcmp(f.ee+0x100,"ABABABAB",8)==0);
    std::array<std::uint8_t,8> saved{};std::memcpy(saved.data(),f.ee+0x100,8);
    CHECK(f.memory->copy_forward(f.call,t,Space::ee,0x100,Space::ee,0x1ffffff,8)==Status::unsupported);
    CHECK(std::memcmp(saved.data(),f.ee+0x100,8)==0);
    // No invented 1MiB/2MiB provider clamp. Full eligible extents remain valid.
    constexpr std::size_t large=3*1024*1024;
    std::fill_n(f.ee+0x200000,large,0x5a);
    CHECK(f.memory->copy_forward(f.call,t,Space::ee,0x200000,Space::ee,0x600000,large)==Status::ok);
    CHECK(f.ee[0x600000]==0x5a&&f.ee[0x600000+large-1]==0x5a);
    CHECK(f.memory->copy_forward(f.call,t,Space::ee,0x200000,Space::iop,0,0x200000)==Status::ok);
    CHECK(f.iop[0]==0x5a&&f.iop[0x1fffff]==0x5a);
    f.memory->end(f.call,t);return true;
}
struct PacketOp final:agg::PacketOperation {
    Fixture& f;Token& token;unsigned calls{};bool valid{};
    PacketOp(Fixture& v,Token& t):f(v),token(t){}
    pkt::PacketResult run(const pkt::CaptureSource& source)noexcept override {
        ++calls;std::array<std::uint8_t,4> out{};
        valid=f.coordinator.observe(f.ee).cpu_groups==0&&source.packet_present()&&source.packet_bytes()==4&&source.copy_packet(out)&&out[0]==7;
        f.memory->end(f.call,token);fake_guest_depth=0;
        valid=valid&&!empty(token)&&!f.memory->retire_after_outer_drain();fake_guest_depth=1;
        std::array<std::uint8_t,2> hd{},bd{},tq{};
        std::array<pkt::PartCopyV1,3> parts{{{pkt::CopySourceV1::ram,0x400,hd},{pkt::CopySourceV1::ram,0x500,bd},{pkt::CopySourceV1::ram,0x600,tq}}};
        valid=valid&&source.copy_parts_v1(parts)==pkt::Status::ok&&hd[0]==11&&bd[0]==12&&tq[0]==13&&f.coordinator.observe(f.ee).cpu_groups==0;
        auto before=hd;parts[2].offset=0x01000000;
        valid=valid&&source.copy_parts_v1(parts)==pkt::Status::unsupported&&hd==before;
        return {pkt::Status::invalid_asset,true,3,2};
    }
};
bool packets() {
    Fixture f;Token t{};CHECK(f.begin(t)==Status::ok);f.ee[0x100]=7;f.ee[0x400]=11;f.ee[0x500]=12;f.ee[0x600]=13;
    sdk::NativeSoundRamPacketV1 loan{};CHECK(f.memory->snapshot_packet(f.call,t,0x100,4,loan)==Status::ok);
    CHECK(loan.bytes==4&&loan.data!=f.ee+0x100);f.ee[0x100]=99;CHECK(loan.data[0]==7);
    sdk::NativeSoundRamPacketV1 unchanged{reinterpret_cast<const std::uint8_t*>(1),9};
    CHECK(f.memory->snapshot_packet(f.call,t,0x100,4,unchanged)==Status::capacity);CHECK(unchanged.bytes==9);
    CHECK(f.memory->log_owned_packet(f.call,t,loan)==Status::unsupported);
    auto fake=loan;fake.data=f.ee+0x100;CHECK(f.memory->log_owned_packet(f.call,t,fake)==Status::invalid_input);
    sdk::NativeSoundRamReadV1 bad{Space::ee,0,{const_cast<std::uint8_t*>(loan.data),1}};
    CHECK(f.memory->read_batch(f.call,t,{&bad,1})==Status::invalid_input);
    PacketOp operation(f,t);agg::PacketBorrow borrow{f.ee,sr::AddressDomain::ee_bytes,loan.data,loan.bytes};
    auto result=f.memory->with_packet(borrow,operation);
    CHECK(operation.calls==1&&operation.valid);CHECK(result.status==pkt::Status::invalid_asset&&result.parser_accepted&&result.consumed==3&&result.commands_applied==2);
    borrow.packet=f.ee+0x100;CHECK(f.memory->with_packet(borrow,operation).status==pkt::Status::invalid_input);CHECK(operation.calls==1);
    f.memory->end(f.call,t);borrow.packet=loan.data;CHECK(f.memory->with_packet(borrow,operation).status==pkt::Status::invalid_input);
    return true;
}
struct BankOp final:agg::BankOperation {
    Fixture& f;unsigned calls{};bool valid{};BankOp(Fixture& v):f(v){}
    pkt::Status run(const pkt::CaptureSource& source)noexcept override {
        ++calls;std::array<std::uint8_t,2> a{},b{},c{};
        std::array<pkt::PartCopyV1,3> parts{{{pkt::CopySourceV1::direct_hd,0,a},{pkt::CopySourceV1::bd,0,b},{pkt::CopySourceV1::tq,0,c}}};
        valid=!source.packet_present()&&source.direct_bank_sizes().hd==2&&f.coordinator.observe(f.ee).cpu_groups==0&&
            source.copy_parts_v1(parts)==pkt::Status::ok&&a[0]==1&&b[0]==2&&c[0]==3&&f.coordinator.observe(f.ee).cpu_groups==0;
        return pkt::Status::invalid_asset;
    }
};
struct PcmOp final:sr::PcmOperation {
    Fixture& f;bool result;unsigned calls{};bool valid{};PcmOp(Fixture& x,bool r):f(x),result(r){}
    bool run(std::span<const std::uint8_t> bytes)noexcept override {
        ++calls;valid=f.coordinator.observe(f.ee).cpu_groups==0&&bytes.data()!=f.ee+0x400&&bytes.size()==4&&bytes[0]==1;
        fake_guest_depth=0;valid=valid&&!f.memory->retire_after_outer_drain();fake_guest_depth=1;
        f.ee[0x400]=99;valid=valid&&bytes[0]==1;return result;
    }
};
bool banks_pcm() {
    Fixture f;f.ee[0x400]=1;f.ee[0x500]=2;f.ee[0x600]=3;BankOp bank(f);
    agg::BankBorrow borrow{0,f.ee+0x400,2,f.ee+0x500,2,f.ee+0x600,2};
    CHECK(f.memory->with_bank(borrow,bank)==pkt::Status::invalid_asset);CHECK(bank.calls==1&&bank.valid);
    std::array<std::uint8_t,2> host{};borrow.hd=host.data();CHECK(f.memory->with_bank(borrow,bank)==pkt::Status::unsupported);CHECK(bank.calls==1);
    PcmOp pcm(f,false);CHECK(!f.memory->with_pcm(f.ee+0x400,4,pcm));CHECK(pcm.calls==1&&pcm.valid);
    f.ee[0x400]=1;PcmOp yes(f,true);CHECK(f.memory->with_pcm(f.ee+0x400,4,yes));CHECK(yes.calls==1&&yes.valid);
    CHECK(!f.memory->with_pcm(host.data(),2,yes));CHECK(!f.memory->with_pcm(f.ee+0x400,0x4002,yes));CHECK(!f.memory->with_pcm(f.ee+0x400,3,yes));CHECK(yes.calls==1);
    return true;
}
bool writer_wait() {
    Fixture f;std::mutex mutex;std::condition_variable cv;bool entered=false,release=false;std::atomic<bool> complete=false;
    std::thread writer([&]{auto held=f.coordinator.begin_cpu_writer(f.ee);if(!held.value)std::terminate();
        {std::lock_guard lock(mutex);entered=true;}cv.notify_all();
        {std::unique_lock lock(mutex);cv.wait(lock,[&]{return release;});}f.ee[0x100]=42;});
    {std::unique_lock lock(mutex);cv.wait(lock,[&]{return entered;});}
    std::uint8_t output=0;Status result=Status::rejected;
    std::thread reader([&]{fake_guest_depth=1;Token t{};if(f.begin(t)!=Status::ok)std::terminate();
        sdk::NativeSoundRamReadV1 r{Space::ee,0x100,{&output,1}};result=f.memory->read_batch(f.call,t,{&r,1});f.memory->end(f.call,t);complete=true;});
    while(!f.coordinator.observe(f.ee).readers_waiting)std::this_thread::yield();
    CHECK(!complete);CHECK(f.coordinator.observe(f.ee).cpu_groups==0);CHECK(f.memory->statistics().active_slots==1);
    fake_guest_depth=0;CHECK(!f.memory->retire_after_outer_drain());fake_guest_depth=1;
    {std::lock_guard lock(mutex);release=true;}cv.notify_all();writer.join();reader.join();
    CHECK(complete&&result==Status::ok&&output==42);CHECK(f.coordinator.observe(f.ee).cpu_groups==0);
    auto graphics=f.coordinator.begin_graphics(f.ee);CHECK(bool(graphics.value));Token t{};CHECK(f.begin(t)==Status::ok);
    sdk::NativeSoundRamReadV1 r{Space::ee,0x100,{&output,1}};CHECK(f.memory->read_batch(f.call,t,{&r,1})==Status::unsupported);
    f.memory->end(f.call,t);return true;
}
struct AdapterOp final:agg::PacketOperation {
    pkt::PacketAdapter& adapter;pkt::Call& call;
    AdapterOp(pkt::PacketAdapter& a,pkt::Call& c):adapter(a),call(c){}
    pkt::PacketResult run(const pkt::CaptureSource& source)noexcept override{return adapter.submit_packet(call,source);}
};
bool real_adapter() {
    Fixture f;auto session=std::make_shared<pkt::banks::Session>();pkt::PacketAdapter adapter(session,f.memory->identity());
    auto admitted=adapter.begin_call();CHECK(admitted.status==pkt::Status::ok);AdapterOp operation(adapter,admitted.value);
    InputBank input=bank();for(auto* part:{&input.hd,&input.bd,&input.tq})part->resize((part->size()+15)&~std::size_t(15));
    const std::array<std::size_t,3> offsets{0x100,0x2000,0x2100};
    std::copy(input.hd.begin(),input.hd.end(),f.ee+offsets[0]);std::copy(input.bd.begin(),input.bd.end(),f.ee+offsets[1]);std::copy(input.tq.begin(),input.tq.end(),f.ee+offsets[2]);
    std::array<std::uint8_t,21> wire{};wire[0]=0x4d;
    const std::array<std::size_t,3> sizes{input.hd.size(),input.bd.size(),input.tq.size()};
    for(unsigned i=0;i<3;++i){auto* d=wire.data()+3+i*6;auto at=offsets[i],n=sizes[i];
        d[0]=std::uint8_t(at>>24);d[1]=std::uint8_t(at>>16);d[2]=std::uint8_t(at>>8);d[3]=std::uint8_t((at&240)|((n>>20)&15));d[4]=std::uint8_t(n>>12);d[5]=std::uint8_t(n>>4);}
    auto submit=[&](std::span<const std::uint8_t> bytes){
        std::memcpy(f.ee+0x3000,bytes.data(),bytes.size());Token t{};
        if(f.begin(t)!=Status::ok)return pkt::PacketResult{pkt::Status::capture_failed};
        sdk::NativeSoundRamPacketV1 snapshot{};
        if(f.memory->snapshot_packet(f.call,t,0x3000,bytes.size(),snapshot)!=Status::ok){f.memory->end(f.call,t);return pkt::PacketResult{pkt::Status::capture_failed};}
        auto result=f.memory->with_packet({f.ee,sr::AddressDomain::ee_bytes,snapshot.data,snapshot.bytes},operation);
        f.memory->end(f.call,t);return result;
    };
    auto result=submit(wire);CHECK(result.status==pkt::Status::ok&&result.parser_accepted);
    auto budget=session->budget_observer()->snapshot();
    wire.fill(255);wire[0]=0x4e;wire[1]=wire[2]=0; // All unused descriptors deliberately unsupported.
    result=submit(wire);CHECK(result.status==pkt::Status::ok&&result.parser_accepted);
    auto after=session->budget_observer()->snapshot();CHECK(after.bytes==budget.bytes&&after.allocations==budget.allocations);
    const std::array<std::uint8_t,8> prefix{0x29,2,0,0x4c,255,1,0,0x77};
    result=submit(prefix);CHECK(result.status==pkt::Status::invalid_input&&!result.parser_accepted&&result.commands_applied==2&&result.consumed==7);
    CHECK(session->snapshot().ports[0].volume==512);CHECK(f.coordinator.observe(f.ee).cpu_groups==0);
    admitted.value={};adapter.join();return true;
}
int main(){if(!tokens()||!batches()||!forward()||!packets()||!banks_pcm()||!writer_wait())return 1;
    if(!real_adapter())return 1;
    std::cout<<"simulated_context_assertions="<<assertions<<" actual_runtime_acquisition=NOT_EXERCISED\n";return 0;}
