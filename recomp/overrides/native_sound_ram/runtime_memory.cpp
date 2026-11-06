#include "runtime_memory.h"
#include "ps2_runtime.h"
#include "gs_sound_ram_profile.h"
#include "parent_natural_runtime.h"
#include "parent_first_entry.h"
#include "../reo_hw_bridge.h"
#include "tools/parallel_gs_backend/parallel_backend.h"
#include "game/native/ram_capture/v2/cpu_authority_gate.hpp"
#include "../native_geometry/reo_vu_native_sha256.h"
#include <algorithm>
#include <atomic>
#include <cstring>
#include <limits>
#include <mutex>
#include <thread>
#include <utility>

std::uint32_t ps2IoRegLockDepth()noexcept;

#if !defined(REO_BUILD_NATIVE_SOUND_RAM_CAPTURE) || REO_BUILD_NATIVE_SOUND_RAM_CAPTURE < 2
#error RuntimeMemory requires the cooperating Pad/graphics flag2 cohort
#endif
#if !defined(REO_GAME_FILE1) || defined(REO_GAME_FILE2)
#error RuntimeMemory currently admits only the qualified File1 profile
#endif

namespace reo::native::sound_ram {
namespace sdk=ps2_cri_audio;
namespace gate=ram_capture::v2;
using Status=sdk::BankStatusV2;
using Token=sdk::NativeSoundRamTokenV1;
using Call=sdk::SoundCall;
namespace {
void increment(std::atomic<std::uint64_t>& value)noexcept {
    auto n=value.load(std::memory_order_relaxed);
    while(n!=UINT64_MAX&&!value.compare_exchange_weak(n,n+1,std::memory_order_relaxed)){}
}
std::atomic<std::uintptr_t> next_nonce{1};
std::uintptr_t nonce()noexcept {
    auto n=next_nonce.load(std::memory_order_relaxed);
    while(n&&n!=UINTPTR_MAX) {
        if(next_nonce.compare_exchange_weak(n,n+1,std::memory_order_relaxed))return n;
    }
    return 0;
}
bool accepted(const Call& call)noexcept{return call.native()&&call.status()==Status::ok;}
bool empty(const Token& token)noexcept {
    return token.opaque[0]==0&&token.opaque[1]==0&&token.opaque[2]==0&&token.opaque[3]==0;
}
bool map_space(sdk::NativeSoundRamSpaceV1 value,Space& out)noexcept {
    switch(value){case sdk::NativeSoundRamSpaceV1::ee:out=Space::ee;return true;
    case sdk::NativeSoundRamSpaceV1::iop:out=Space::iop;return true;}return false;
}
reo_native_image_identity::Digest hex_digest(const char* text)noexcept {
    reo_native_image_identity::Digest result{};
    auto nib=[](char c){return c<='9'?c-'0':c-'a'+10;};
    for(std::size_t i=0;i<result.size();++i)result[i]=std::uint8_t(nib(text[i*2])*16+nib(text[i*2+1]));
    return result;
}
Status group_status(gate::Status value)noexcept {
    switch(value){case gate::Status::ok:return Status::ok;
    case gate::Status::capacity:return Status::capacity;
    case gate::Status::self_wait:return Status::rejected;
    default:return Status::unsupported;}
}
}

struct RuntimeMemory::State {
    enum class Kind{native,bank,pcm};
    struct Slot {
        std::array<std::uint8_t,packet_capacity> bytes{};
        std::thread::id thread{};const Call* call{};const Token* token{};
        std::uintptr_t generation{};std::size_t packet_bytes{};
        bool used{},snapshot{};Kind kind{};std::uint32_t operations{};
    };
    PS2Runtime* runtime;std::uint8_t* ee;std::uint8_t* iop;
    AddressDomain addresses;packet::MemoryIdentity metadata;
    gate::Coordinator* coordinator;
    reo_cd_async::SyncRamWriteSeal cd;
    gs_backend_bridge::SoundRamSelectionLeaseV1 gs;
    const std::uintptr_t nonce_value;
    HostExtent facade{}; // Immutable after the private RuntimeMemory constructor.
    mutable std::mutex mutex;
    std::array<Slot,scope_capacity> slots{};
    bool retiring{},retired{};std::uint64_t operations{};
    std::array<std::atomic<std::uint64_t>,memory_operation_count> attempts{},refused{};
    std::atomic<std::uint64_t> reports{},first_failure{};
    State(PS2Runtime& r,std::uint8_t* e,std::uint8_t* i,packet::MemoryIdentity m,
          gate::Coordinator& c,reo_cd_async::SyncRamWriteSeal d,
          gs_backend_bridge::SoundRamSelectionLeaseV1 g,std::uintptr_t n)
        :runtime(&r),ee(e),iop(i),addresses(e,i),metadata(m),coordinator(&c),
         cd(std::move(d)),gs(std::move(g)),nonce_value(n){}
    void attempt(MemoryOperation op)noexcept{increment(attempts[std::size_t(op)]);}
    Status fail(MemoryOperation op,Status status)noexcept {
        if(status==Status::ok)return status;
        increment(refused[std::size_t(op)]);
        std::uint64_t expected=0;
        first_failure.compare_exchange_strong(expected,1+(std::uint64_t(op)<<8)+std::uint64_t(status),std::memory_order_relaxed);
        return status;
    }
    // Qualification is retained across WAIT and copy by the surrounding real
    // SDK owner + configuration leases. No Runtime.stop predicate here.
    bool context()const noexcept {
        return ps2ActualGuestExecutionDepth(runtime)>0&&
            runtime->memory().getRDRAM()==ee&&runtime->memory().getIOPRAM()==iop&&
            cd.matches(*runtime,ee,AddressDomain::ee_bytes)&&gs.matches(*runtime,ee,iop)&&
            !reo_parent_natural::anyActualOwnerBound()&&
            !reo_parent_natural::actualFirstEntryEnrollmentRequested();
    }
    bool protected_host(const void* pointer,std::size_t bytes,const Token* token=nullptr,const Call* call=nullptr)const noexcept {
        if(addresses.validate_host(pointer,bytes)!=AddressStatus::ok)return false;
        HostExtent value{},self{},other{};
        if(!checked_host_extent(pointer,bytes,value)||!checked_host_extent(this,sizeof(*this),self)||overlaps(value,self)||overlaps(value,facade))return false;
        if(token&&(!checked_host_extent(token,sizeof(*token),other)||overlaps(value,other)))return false;
        if(call&&(!checked_host_extent(call,sizeof(*call),other)||overlaps(value,other)))return false;
        return true;
    }
    std::uint8_t* data(Region r)const noexcept{return (r.space==Space::ee?ee:iop)+r.offset;}
    bool region(sdk::NativeSoundRamSpaceV1 space,std::uint32_t address,std::size_t bytes,Region& out)const noexcept {
        Space s;if(!map_space(space,s))return false;
        auto r=addresses.resolve(s,address,bytes);out=r.region;return r.status==AddressStatus::ok;
    }
    bool ee_pointer(const std::uint8_t* pointer,std::size_t bytes,Region& out)const noexcept {
        if(!pointer){if(bytes)return false;out={Space::ee,0,0};return true;}
        HostExtent value{},ram{};
        if(!checked_host_extent(pointer,bytes,value)||!checked_host_extent(ee,AddressDomain::ee_bytes,ram)||
           value.begin<ram.begin||value.begin>ram.end||value.end>ram.end)return false;
        auto r=addresses.resolve(Space::ee,std::uint32_t(value.begin-ram.begin),bytes);
        out=r.region;return r.status==AddressStatus::ok;
    }
    Status reserve(Kind kind,const Call* call,std::size_t& index,const Token* token=nullptr)noexcept {
        std::lock_guard lock(mutex);
        if(retiring||retired)return Status::closed;
        for(std::size_t i=0;i<slots.size();++i){auto& slot=slots[i];
            if(slot.used||slot.generation==UINTPTR_MAX)continue;
            ++slot.generation;slot.used=true;slot.thread=std::this_thread::get_id();slot.call=call;slot.token=token;
            slot.kind=kind;slot.snapshot=false;slot.packet_bytes=0;slot.operations=0;index=i;return Status::ok;
        }return Status::capacity;
    }
    bool matches_locked(const Token& token,const Call& call)const noexcept {
        if(token.opaque[0]!=reinterpret_cast<std::uintptr_t>(this)||token.opaque[3]!=nonce_value||token.opaque[1]>=slots.size())return false;
        const auto& slot=slots[token.opaque[1]];
        return slot.used&&slot.kind==Kind::native&&slot.generation==token.opaque[2]&&slot.call==&call&&slot.token==&token&&
            slot.thread==std::this_thread::get_id()&&accepted(call);
    }
    struct Use {
        State* state{};std::size_t slot{};
        Use()=default;Use(const Use&)=delete;Use& operator=(const Use&)=delete;
        ~Use(){if(state){std::lock_guard lock(state->mutex);--state->slots[slot].operations;--state->operations;}}
    };
    Status use(const Token& token,const Call& call,Use& use)noexcept {
        if(!protected_host(&call,sizeof(call))||!protected_host(&token,sizeof(token),nullptr,&call))return Status::invalid_input;
        std::lock_guard lock(mutex);
        if(retiring||retired)return Status::closed;
        if(!matches_locked(token,call))return Status::foreign_runtime;
        auto& slot=slots[token.opaque[1]];
        // No concurrent/reentrant operations on one mutable token. A Source
        // borrow is the sole outer use; its internal copies reuse that use.
        if(slot.operations)return Status::rejected;
        ++slot.operations;++operations;use.state=this;use.slot=token.opaque[1];return Status::ok;
    }
    void release(std::size_t index)noexcept {
        std::lock_guard lock(mutex);auto& slot=slots[index];
        slot.used=false;slot.call=nullptr;slot.token=nullptr;slot.snapshot=false;slot.packet_bytes=0;
    }
    template<class F>Status copy_group(F&& f)noexcept {
        if(!context())return Status::foreign_runtime;
        try {
            auto group=coordinator->wait_cpu_group(ee);
            if(group.status!=gate::Status::ok)return group_status(group.status);
            if(!context())return Status::foreign_runtime;
            f();return Status::ok;
        }catch(...){return Status::rejected;}
    }
    struct Source final:packet::CaptureSource {
        State& owner;std::size_t slot_index;
        bool packet_mode;aggregate::BankBorrow bank{};
        Source(State& s,std::size_t i):owner(s),slot_index(i),packet_mode(true){}
        Source(State& s,std::size_t i,const aggregate::BankBorrow& b):owner(s),slot_index(i),packet_mode(false),bank(b){}
        packet::MemoryIdentity identity()const noexcept override{return owner.metadata;}
        bool packet_present()const noexcept override{return packet_mode;}
        std::size_t packet_bytes()const noexcept override{return packet_mode?owner.slots[slot_index].packet_bytes:0;}
        std::size_t ram_view_bytes()const noexcept override{return AddressDomain::ee_bytes;}
        bool ram_present()const noexcept override{return true;}
        bool copy_packet(std::span<std::uint8_t> destination)const noexcept override {
            if(!packet_mode||destination.size()!=packet_bytes()||!owner.context()||
                !owner.protected_host(destination.data(),destination.size(),nullptr,owner.slots[slot_index].call))return false;
            if(!destination.empty())std::memcpy(destination.data(),owner.slots[slot_index].bytes.data(),destination.size());
            return true;
        }
        packet::banks::BankSizes direct_bank_sizes()const noexcept override {
            return packet_mode?packet::banks::BankSizes{}:packet::banks::BankSizes{bank.hd_bytes,bank.bd_bytes,bank.tq_bytes};
        }
        packet::Status copy_parts_v1(std::span<const packet::PartCopyV1> parts)const noexcept override {
            if(parts.size()>maximum_part_ranges)return packet::Status::capacity;
            if(!owner.protected_host(parts.data(),parts.size_bytes(),nullptr,owner.slots[slot_index].call))return packet::Status::invalid_input;
            struct Plan{Region source;std::uint8_t* destination;HostExtent host;};
            std::array<Plan,maximum_part_ranges> plans{};std::size_t count=0;
            for(const auto& part:parts){Region r{};
                if(!owner.protected_host(part.destination.data(),part.destination.size(),nullptr,owner.slots[slot_index].call))return packet::Status::invalid_input;
                if(part.source==packet::CopySourceV1::ram){
                    if(part.offset>UINT32_MAX)return packet::Status::invalid_input;
                    auto a=owner.addresses.resolve(Space::ee,std::uint32_t(part.offset),part.destination.size());
                    if(a.status!=AddressStatus::ok)return packet::Status::unsupported;r=a.region;
                }else {
                    if(packet_mode)return packet::Status::unsupported;
                    const std::uint8_t* base=nullptr;std::size_t size=0;
                    switch(part.source){case packet::CopySourceV1::direct_hd:base=bank.hd;size=bank.hd_bytes;break;
                    case packet::CopySourceV1::bd:base=bank.bd;size=bank.bd_bytes;break;
                    case packet::CopySourceV1::tq:base=bank.tq;size=bank.tq_bytes;break;
                    default:return packet::Status::invalid_input;}
                    Region whole{};if(part.offset>size||part.destination.size()>size-part.offset||!owner.ee_pointer(base,size,whole))return packet::Status::invalid_input;
                    r={Space::ee,whole.offset+part.offset,part.destination.size()};
                }
                HostExtent host{};if(!checked_host_extent(part.destination.data(),part.destination.size(),host))return packet::Status::invalid_input;
                for(std::size_t i=0;i<count;++i)if(overlaps(host,plans[i].host))return packet::Status::invalid_input;
                plans[count++]={r,part.destination.data(),host};
            }
            const auto result=owner.copy_group([&]{for(std::size_t i=0;i<count;++i)if(plans[i].source.bytes)
                std::memcpy(plans[i].destination,owner.data(plans[i].source),plans[i].source.bytes);});
            switch(result){case Status::ok:return packet::Status::ok;case Status::capacity:return packet::Status::capacity;
            case Status::foreign_runtime:return packet::Status::foreign_runtime;default:return packet::Status::capture_failed;}
        }
    };
};

RuntimeMemory::RuntimeMemory(std::unique_ptr<State> value)noexcept:state_(std::move(value)){
    (void)checked_host_extent(this,sizeof(*this),state_->facade);
}
RuntimeMemory::~RuntimeMemory()=default;
packet::MemoryIdentity RuntimeMemory::identity()const noexcept{return state_->metadata;}

MemoryPrepareResult RuntimeMemory::prepare(PS2Runtime& runtime,const reo_cd_async::ConfigurationReceipt& receipt,packet::MemoryIdentity identity)noexcept {
    try {
        if(ps2ActualGuestExecutionDepth(&runtime)||ps2IoRegLockDepth())return {MemoryPrepareStatus::phase_closed,{}};
        auto setup=runtime.acquirePreRunSetup();if(!setup)return {MemoryPrepareStatus::phase_closed,{}};
        auto* ee=runtime.memory().getRDRAM();auto* iop=runtime.memory().getIOPRAM();
        if(ps2RamBackingBytes!=AddressDomain::ee_bytes||!AddressDomain(ee,iop).valid())return {MemoryPrepareStatus::invalid_profile,{}};
        auto cd=receipt.try_seal(runtime,ee,AddressDomain::ee_bytes);
        if(!cd)return {MemoryPrepareStatus::cd_unavailable,{}};
        auto gs=gs_backend_bridge::acquireSoundRamProfileBeforeRunV1(runtime);
        if(gs.status!=gs_backend_bridge::SoundRamProfileStatusV1::ok||!gs.lease)return {MemoryPrepareStatus::gs_unavailable,{}};
        auto* bridge=ReoHwBridge::instance();
        auto* coordinator=bridge?bridge->nativeSoundRamWriterCoordinator(runtime):nullptr;
        if(!coordinator||coordinator!=&gate::process_coordinator()||
            coordinator!=reo_parallel_backend::nativeSoundRamWriterCoordinatorV2()||
            reo_parent_natural::anyActualOwnerBound()||reo_parent_natural::actualFirstEntryEnrollmentRequested())return {MemoryPrepareStatus::writer_unavailable,{}};
        auto n=nonce();if(!n)return {MemoryPrepareStatus::capacity,{}};
        identity.runtime_incarnation=gs.lease.incarnation();identity.ram_incarnation=n;
        identity.ram_bytes=AddressDomain::ee_bytes;
        auto state=std::make_unique<State>(runtime,ee,iop,identity,*coordinator,std::move(cd),std::move(gs.lease),n);
        std::array<std::uint8_t,0x40> pcm_code{};std::array<std::uint8_t,0xf8> adx_code{};
        {
            PS2Runtime::GuestExecutionScope guest(&runtime);
            auto status=state->copy_group([&]{std::memcpy(pcm_code.data(),ee+0x1392f8,pcm_code.size());std::memcpy(adx_code.data(),ee+0x135078,adx_code.size());});
            if(status!=Status::ok)return {MemoryPrepareStatus::writer_unavailable,{}};
        }
        if(reo_native_image_identity::sha256(pcm_code.data(),pcm_code.size())!=hex_digest("48af9491776a966a35a3dd46ed6122d2aa237c85f2a1967c38f204a488517be8")||
           reo_native_image_identity::sha256(adx_code.data(),adx_code.size())!=hex_digest("a6ac3b23bfac0c9862d0facae8e02be99f08a69e6e20cb2dda05a10ffd3813bd"))return {MemoryPrepareStatus::invalid_profile,{}};
        return {MemoryPrepareStatus::ready,std::shared_ptr<RuntimeMemory>(new RuntimeMemory(std::move(state)))};
    }catch(const std::bad_alloc&){return {MemoryPrepareStatus::no_memory,{}};}
    catch(...){return {MemoryPrepareStatus::invalid_profile,{}};}
}

Status RuntimeMemory::begin(const Call& call,PS2Runtime* runtime,std::uint8_t* ram,sdk::NativeSoundRamUseV1 use,Token& token)noexcept {
    auto& s=*state_;s.attempt(MemoryOperation::begin);
    if(!s.protected_host(&call,sizeof(call))||!s.protected_host(&token,sizeof(token),nullptr,&call))return s.fail(MemoryOperation::begin,Status::invalid_input);
    if(!empty(token))return s.fail(MemoryOperation::begin,Status::invalid_input);
    if(unsigned(use)>unsigned(sdk::NativeSoundRamUseV1::status_transfer))return s.fail(MemoryOperation::begin,Status::invalid_input);
    if(runtime!=s.runtime||ram!=s.ee||!accepted(call)||!s.context())return s.fail(MemoryOperation::begin,Status::foreign_runtime);
    std::size_t index=0;auto result=s.reserve(State::Kind::native,&call,index,&token);
    if(result!=Status::ok)return s.fail(MemoryOperation::begin,result);
    token.opaque[0]=reinterpret_cast<std::uintptr_t>(&s);token.opaque[1]=index;
    token.opaque[2]=s.slots[index].generation;token.opaque[3]=s.nonce_value;return Status::ok;
}
void RuntimeMemory::end(const Call& call,Token& token)noexcept {
    auto& s=*state_;s.attempt(MemoryOperation::end);
    if(!s.protected_host(&call,sizeof(call))||!s.protected_host(&token,sizeof(token),nullptr,&call)){s.fail(MemoryOperation::end,Status::invalid_input);return;}
    if(empty(token))return;
    std::lock_guard lock(s.mutex);
    if(!s.matches_locked(token,call)||s.slots[token.opaque[1]].operations){s.fail(MemoryOperation::end,Status::rejected);return;}
    auto& slot=s.slots[token.opaque[1]];slot.used=false;slot.call=nullptr;slot.token=nullptr;slot.snapshot=false;slot.packet_bytes=0;token={};
}
Status RuntimeMemory::read_batch(const Call& call,Token& token,std::span<const sdk::NativeSoundRamReadV1> reads)noexcept {
    auto& s=*state_;constexpr auto op=MemoryOperation::read;s.attempt(op);State::Use use;
    auto status=s.use(token,call,use);if(status!=Status::ok)return s.fail(op,status);
    if(reads.size()>maximum_ranges)return s.fail(op,Status::capacity);
    if(!s.protected_host(reads.data(),reads.size_bytes(),&token,&call))return s.fail(op,Status::invalid_input);
    struct Plan{Region source;std::uint8_t* destination;HostExtent host;};std::array<Plan,maximum_ranges> plans{};std::size_t count=0;
    for(const auto& read:reads){Region r{};HostExtent h{};
        if(!s.region(read.space,read.address,read.destination.size(),r))return s.fail(op,Status::unsupported);
        if(!s.protected_host(read.destination.data(),read.destination.size(),&token,&call)||!checked_host_extent(read.destination.data(),read.destination.size(),h))return s.fail(op,Status::invalid_input);
        for(std::size_t i=0;i<count;++i)if(overlaps(h,plans[i].host))return s.fail(op,Status::invalid_input);
        plans[count++]={r,read.destination.data(),h};
    }
    return s.fail(op,s.copy_group([&]{for(std::size_t i=0;i<count;++i)if(plans[i].source.bytes)std::memcpy(plans[i].destination,s.data(plans[i].source),plans[i].source.bytes);}));
}
Status RuntimeMemory::control_batch(const Call& call,Token& token,sdk::NativeSoundRamControlV1 role,std::span<const sdk::NativeSoundRamControlOpV1> writes)noexcept {
    auto& s=*state_;constexpr auto op=MemoryOperation::control;s.attempt(op);State::Use use;
    auto status=s.use(token,call,use);if(status!=Status::ok)return s.fail(op,status);
    if(unsigned(role)>unsigned(sdk::NativeSoundRamControlV1::rpc_metadata))return s.fail(op,Status::invalid_input);
    if(writes.size()>maximum_ranges)return s.fail(op,Status::capacity);
    if(!s.protected_host(writes.data(),writes.size_bytes(),&token,&call))return s.fail(op,Status::invalid_input);
    struct Plan{Region destination;const std::uint8_t* source;bool zero;};std::array<Plan,maximum_ranges> plans{};std::size_t count=0;
    for(const auto& write:writes){Region r{};
        if(!s.region(write.space,write.address,write.bytes,r))return s.fail(op,Status::unsupported);
        bool zero=write.kind==sdk::NativeSoundRamControlKindV1::zero;
        if(!zero&&write.kind!=sdk::NativeSoundRamControlKindV1::write)return s.fail(op,Status::invalid_input);
        if((zero&&!write.source.empty())||(!zero&&(write.source.size()!=write.bytes||!s.protected_host(write.source.data(),write.bytes,&token,&call))))return s.fail(op,Status::invalid_input);
        plans[count++]={r,write.source.data(),zero};
    }
    return s.fail(op,s.copy_group([&]{for(std::size_t i=0;i<count;++i){auto& p=plans[i];if(!p.destination.bytes)continue;
        if(p.zero)std::memset(s.data(p.destination),0,p.destination.bytes);else std::memcpy(s.data(p.destination),p.source,p.destination.bytes);}}));
}
Status RuntimeMemory::copy_forward(const Call& call,Token& token,sdk::NativeSoundRamSpaceV1 src_space,std::uint32_t src,sdk::NativeSoundRamSpaceV1 dst_space,std::uint32_t dst,std::size_t bytes)noexcept {
    auto& s=*state_;constexpr auto op=MemoryOperation::forward;s.attempt(op);State::Use use;
    auto status=s.use(token,call,use);if(status!=Status::ok)return s.fail(op,status);Region a{},b{};
    if(!s.region(src_space,src,bytes,a)||!s.region(dst_space,dst,bytes,b))return s.fail(op,Status::unsupported);
    return s.fail(op,s.copy_group([&]{auto* from=s.data(a);auto* to=s.data(b);for(std::size_t i=0;i<bytes;++i)to[i]=from[i];}));
}
Status RuntimeMemory::snapshot_packet(const Call& call,Token& token,std::uint32_t address,std::size_t bytes,sdk::NativeSoundRamPacketV1& out)noexcept {
    auto& s=*state_;constexpr auto op=MemoryOperation::snapshot;s.attempt(op);State::Use use;
    auto status=s.use(token,call,use);if(status!=Status::ok)return s.fail(op,status);
    auto& slot=s.slots[use.slot];if(bytes>packet_capacity||slot.snapshot)return s.fail(op,Status::capacity);
    Region r{};if(!s.region(sdk::NativeSoundRamSpaceV1::ee,address,bytes,r))return s.fail(op,Status::unsupported);
    // Output is caller-owned host metadata, never guest RAM or provider state.
    if(!s.protected_host(&out,sizeof(out),&token,&call))return s.fail(op,Status::invalid_input);
    status=s.copy_group([&]{if(bytes)std::memcpy(slot.bytes.data(),s.data(r),bytes);});
    if(status!=Status::ok)return s.fail(op,status);
    slot.packet_bytes=bytes;slot.snapshot=true;out={slot.bytes.data(),bytes};return Status::ok;
}
Status RuntimeMemory::log_owned_packet(const Call& call,Token& token,sdk::NativeSoundRamPacketV1 packet)noexcept {
    auto& s=*state_;constexpr auto op=MemoryOperation::log;s.attempt(op);State::Use use;
    auto status=s.use(token,call,use);if(status!=Status::ok)return s.fail(op,status);
    const auto& slot=s.slots[use.slot];
    if(!slot.snapshot||packet.data!=slot.bytes.data()||packet.bytes!=slot.packet_bytes)return s.fail(op,Status::invalid_input);
    // Logging is intentionally absent. This diagnostic is separate from packet
    // handling; the SDK continues gameplay and never logs borrowed guest bytes.
    return s.fail(op,Status::unsupported);
}
void RuntimeMemory::report(const Call&,Token&,sdk::NativeSoundRamDiagnosticV1 diagnostic)noexcept {
    auto& s=*state_;increment(s.reports);std::uint64_t expected=0;
    s.first_failure.compare_exchange_strong(expected,1+(std::uint64_t(diagnostic.stage)<<16)+std::uint64_t(diagnostic.status),std::memory_order_relaxed);
}

packet::PacketResult RuntimeMemory::with_packet(const aggregate::PacketBorrow& borrow,aggregate::PacketOperation& operation)noexcept {
    auto& s=*state_;constexpr auto op=MemoryOperation::packet;s.attempt(op);State::Use use;
    if(borrow.ram!=s.ee||borrow.ram_bytes!=AddressDomain::ee_bytes||!s.context()){s.fail(op,Status::foreign_runtime);return {packet::Status::foreign_runtime};}
    {
        std::lock_guard lock(s.mutex);
        if(s.retiring||s.retired){s.fail(op,Status::closed);return {packet::Status::closed};}
        for(std::size_t i=0;i<s.slots.size();++i){auto& slot=s.slots[i];
            if(slot.used&&slot.kind==State::Kind::native&&slot.thread==std::this_thread::get_id()&&slot.call&&accepted(*slot.call)&&
               slot.snapshot&&borrow.packet==slot.bytes.data()&&borrow.packet_bytes==slot.packet_bytes&&!slot.operations){
                ++slot.operations;++s.operations;use.state=&s;use.slot=i;break;
            }
        }
    }
    if(!use.state){s.fail(op,Status::invalid_input);return {packet::Status::invalid_input};}
    State::Source source(s,use.slot);return operation.run(source);
}
packet::Status RuntimeMemory::with_bank(const aggregate::BankBorrow& borrow,aggregate::BankOperation& operation)noexcept {
    auto& s=*state_;constexpr auto op=MemoryOperation::bank;s.attempt(op);Region r{};
    if(!s.context()){s.fail(op,Status::foreign_runtime);return packet::Status::foreign_runtime;}
    if(!s.ee_pointer(borrow.hd,borrow.hd_bytes,r)||!s.ee_pointer(borrow.bd,borrow.bd_bytes,r)||!s.ee_pointer(borrow.tq,borrow.tq_bytes,r)){
        s.fail(op,Status::unsupported);return packet::Status::unsupported;}
    std::size_t index=0;auto status=s.reserve(State::Kind::bank,nullptr,index);
    if(status!=Status::ok){s.fail(op,status);return status==Status::closed?packet::Status::closed:packet::Status::capacity;}
    struct Release{State& s;std::size_t i;~Release(){s.release(i);}} release{s,index};
    State::Source source(s,index,borrow);return operation.run(source);
}
bool RuntimeMemory::with_pcm(const std::uint8_t* pointer,std::size_t bytes,PcmOperation& operation)noexcept {
    auto& s=*state_;constexpr auto op=MemoryOperation::pcm;s.attempt(op);Region r{};
    if(!pointer||!bytes||(bytes&1)||bytes>pcm_capacity||!s.ee_pointer(pointer,bytes,r)){s.fail(op,Status::unsupported);return false;}
    if(!s.context()){s.fail(op,Status::foreign_runtime);return false;}
    std::size_t index=0;auto status=s.reserve(State::Kind::pcm,nullptr,index);
    if(status!=Status::ok){s.fail(op,status);return false;}
    struct Release{State& s;std::size_t i;~Release(){s.release(i);}} release{s,index};
    auto& slot=s.slots[index];status=s.copy_group([&]{std::memcpy(slot.bytes.data(),s.data(r),bytes);});
    if(status!=Status::ok){s.fail(op,status);return false;}
    return operation.run({slot.bytes.data(),bytes});
}
MemoryStatistics RuntimeMemory::statistics()const noexcept {
    auto& s=*state_;MemoryStatistics out;
    for(std::size_t i=0;i<memory_operation_count;++i){out.attempts[i]=s.attempts[i].load(std::memory_order_relaxed);out.refused[i]=s.refused[i].load(std::memory_order_relaxed);}
    out.diagnostic_reports=s.reports.load(std::memory_order_relaxed);out.first_failure=s.first_failure.load(std::memory_order_relaxed);
    std::lock_guard lock(s.mutex);for(const auto& slot:s.slots)if(slot.used)++out.active_slots;
    out.active_operations=s.operations;out.retired=s.retired;return out;
}
bool RuntimeMemory::retire_after_outer_drain()noexcept {
    auto& s=*state_;constexpr auto op=MemoryOperation::retire;s.attempt(op);
    {
        std::lock_guard lock(s.mutex);if(s.retired)return true;
        if(s.retiring){s.fail(op,Status::rejected);return false;}
        if(s.operations||std::any_of(s.slots.begin(),s.slots.end(),[](const auto& slot){return slot.used;})||
           ps2ActualGuestExecutionDepth(s.runtime)||ps2IoRegLockDepth()){s.fail(op,Status::rejected);return false;}
        s.retiring=true;
    }
    // Whole outer drain prevents concurrent acquisition. Never release GS/CD
    // selection under metadata, guest, RPC, bank, PCM or device locks.
    s.gs.release();s.cd=reo_cd_async::SyncRamWriteSeal{};
    {std::lock_guard lock(s.mutex);s.retired=true;s.retiring=false;}
    return true;
}
} // namespace reo::native::sound_ram
