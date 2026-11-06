#include "packet_adapter.h"
#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <stdexcept>
#include <utility>

namespace reo::native::bank_packets {
namespace {
Status translated(banks::Status s)noexcept {
    switch(s){
    case banks::Status::ok:case banks::Status::skipped:return Status::ok;
    case banks::Status::closed:return Status::closed;
    case banks::Status::invalid_input:return Status::invalid_input;
    case banks::Status::invalid_asset:return Status::invalid_asset;
    case banks::Status::invalid_submission:return Status::rejected;
    case banks::Status::stale_generation:return Status::stale_generation;
    case banks::Status::capacity:case banks::Status::counter_limit:return Status::capacity;
    case banks::Status::no_memory:return Status::no_memory;
    default:return Status::unsupported;
    }
}
bool nonzero(const auto& values){return std::any_of(values.begin(),values.end(),[](auto x){return x!=0;});}
struct Slot {
    bool busy{};
    banks::AssetVector<std::uint8_t> packet;
    Slot(const std::shared_ptr<banks::Budget>& b,std::uint32_t size):packet(banks::AssetAllocator<std::uint8_t>(b)){packet.resize(size);}
};
struct PacketLoadUnlock final {
    std::unique_lock<std::mutex>* lock;
    explicit PacketLoadUnlock(std::unique_lock<std::mutex>* value):lock(value){if(lock)lock->unlock();}
    ~PacketLoadUnlock(){if(lock&&!lock->owns_lock())lock->lock();}
};
}
struct State {
    std::shared_ptr<banks::Session> bank;
    const MemoryIdentity identity;
    const std::uint32_t max_packet_bytes;
    std::shared_ptr<banks::Budget> control;
    std::vector<Slot,banks::AssetAllocator<Slot>> slots;
    std::mutex gate,transaction;
    std::condition_variable changed;
    std::atomic<bool> closed{};
    std::size_t calls{};
    State(std::shared_ptr<banks::Session> b,MemoryIdentity id,Config c,std::shared_ptr<banks::Budget> budget)
        :bank(std::move(b)),identity(id),max_packet_bytes(c.max_packet_bytes),control(std::move(budget)),slots(banks::AssetAllocator<Slot>(control)) {
        slots.reserve(c.max_calls);for(std::uint32_t n=0;n<c.max_calls;++n)slots.emplace_back(control,c.max_packet_bytes);
    }
};
Call::Call(std::shared_ptr<State> s,std::uint32_t slot,banks::Submission submission)noexcept
    :state_(std::move(s)),slot_(slot),submission_(std::move(submission)){}
Call::Call(Call&& other)noexcept:state_(std::move(other.state_)),slot_(std::exchange(other.slot_,UINT32_MAX)),submission_(std::move(other.submission_)){}
Call& Call::operator=(Call&& other)noexcept {
    if(this!=&other){release();state_=std::move(other.state_);slot_=std::exchange(other.slot_,UINT32_MAX);submission_=std::move(other.submission_);}return *this;
}
Call::~Call(){release();}
void Call::release()noexcept {
    auto state=std::move(state_);if(!state)return;
    submission_={}; // No bank/resource callback or destruction under pool gate.
    {std::lock_guard lock(state->gate);state->slots[slot_].busy=false;--state->calls;state->changed.notify_all();}
    slot_=UINT32_MAX;
}
PacketAdapter::PacketAdapter(std::shared_ptr<banks::Session> bank,MemoryIdentity id,Config c) {
    if(!bank||id.schema!=1||!nonzero(id.session)||!nonzero(id.executable_sha256)||!nonzero(id.native_build_sha256)||
       !id.runtime_incarnation||!id.ram_incarnation||!id.ram_bytes||id.ram_bytes>32u*1024u*1024u||!c.max_calls||!c.max_packet_bytes||!c.control_byte_budget)
        throw std::invalid_argument("Explicit bounded bank capture identity/domain required");
    auto control=std::make_shared<banks::Budget>(c.control_byte_budget,1,c.control_allocation_source);
    state_=std::allocate_shared<State>(banks::AssetAllocator<State>(control),std::move(bank),id,c,control);
}
Result<Call> PacketAdapter::begin_call()noexcept {
    auto state=state_;std::uint32_t index=UINT32_MAX;
    {std::lock_guard lock(state->gate);if(state->closed.load(std::memory_order_acquire))return {Status::closed,{}};
        for(std::size_t n=0;n<state->slots.size();++n)if(!state->slots[n].busy){index=std::uint32_t(n);state->slots[n].busy=true;++state->calls;break;}}
    if(index==UINT32_MAX)return {Status::capacity,{}};
    auto submission=state->bank->begin_submission();
    if(submission.status!=banks::Status::ok){std::lock_guard lock(state->gate);state->slots[index].busy=false;--state->calls;state->changed.notify_all();return {translated(submission.status),{}};}
    Call result(state,index,std::move(submission.value));
    if(state->closed.load(std::memory_order_acquire))return {Status::closed,{}};
    return {Status::ok,std::move(result)};
}
namespace {
Status call_status(const State& expected,const std::shared_ptr<State>& actual)noexcept {
    if(actual.get()!=&expected)return Status::rejected;
    return expected.closed.load(std::memory_order_acquire)?Status::closed:Status::ok;
}
Status source_status(const State& s,const CaptureSource& source)noexcept {
    if(s.closed.load(std::memory_order_acquire))return Status::closed;
    return source.identity()==s.identity?Status::ok:Status::foreign_runtime;
}
Status apply(State& s,const banks::Submission& token,banks::Command command)noexcept {
    if(s.closed.load(std::memory_order_acquire))return Status::closed;
    auto result=s.bank->apply(token,{&command,1});return translated(result.status);
}
Status prepare_install(State& s,const banks::Submission& token,unsigned port,const CaptureSource& source,banks::BankSizes sizes,
                       const std::array<std::size_t,3>* offsets,std::unique_lock<std::mutex>* packet_lock=nullptr)noexcept {
    // Declared before every staged resource: on failure those resources free
    // while unlocked, THEN the original packet transaction is reacquired before
    // returning to the parser/caller, just as source relocks after failed load.
    PacketLoadUnlock unlocked(packet_lock);
    auto status=source_status(s,source);if(status!=Status::ok)return status;
    auto capture=s.bank->capture(token,sizes);if(capture.status!=banks::Status::ok)return translated(capture.status);
    std::array<std::span<std::uint8_t>,3> parts{capture.value.hd(),capture.value.bd(),capture.value.tq()};
    for(unsigned n=0;n<3;++n){
        status=source_status(s,source);if(status!=Status::ok)return status;
        const bool copied=offsets?source.copy_ram((*offsets)[n],parts[n]):source.copy_bank(Part(n),parts[n]);
        if(!copied)return Status::capture_failed;
        status=source_status(s,source);if(status!=Status::ok)return status;
    }
    auto prepared=s.bank->prepare(token,std::move(capture.value));if(prepared.status!=banks::Status::ok)return translated(prepared.status);
    status=source_status(s,source);if(status!=Status::ok)return status;
    // CaptureSource callbacks and decode run without an adapter gate held.
    // Core install atomically checks its token/epoch under its existing lock.
    // Stop is a signal: an admitted commit may finish before join drains it.
    std::unique_lock<std::mutex> own;
    if(packet_lock)packet_lock->lock();else own=std::unique_lock<std::mutex>(s.transaction);
    if(s.closed.load(std::memory_order_acquire))return Status::closed;
    return translated(s.bank->install(token,port,prepared.value));
}
}
Status PacketAdapter::submit_bank(Call& call,unsigned port,const CaptureSource& source)noexcept {
    auto& s=*state_;auto status=call_status(s,call.state_);if(status!=Status::ok)return status;
    if(port>=banks::port_count)return Status::invalid_input;
    status=source_status(s,source);if(status!=Status::ok)return status;
    return prepare_install(s,call.submission_,port,source,source.direct_bank_sizes(),nullptr);
}
PacketResult PacketAdapter::submit_packet(Call& call,const CaptureSource& source)noexcept {
    auto& s=*state_;PacketResult result;result.status=call_status(s,call.state_);if(result.status!=Status::ok)return result;
    result.status=source_status(s,source);if(result.status!=Status::ok)return result;
    const bool ramPresent=source.ram_present();
    const auto bytes=source.packet_bytes();
    if(!source.packet_present()||!bytes){result.status=Status::invalid_input;return result;}
    if(bytes>s.max_packet_bytes){result.status=Status::capacity;return result;}
    const auto ramBytes=source.ram_view_bytes();
    auto packet=std::span<std::uint8_t>(s.slots[call.slot_].packet.data(),bytes);
    if(!source.copy_packet(packet)){result.status=Status::capture_failed;return result;}
    result.status=source_status(s,source);if(result.status!=Status::ok)return result;
    std::unique_lock transaction(s.transaction);
    auto command=[&](banks::Command c){return apply(s,call.submission_,std::move(c));};
    auto report=[&](unsigned value){return command(banks::UnsupportedControl{banks::DiagnosticKind::global_control,value});};
    for(std::size_t at=0;at<bytes&&packet[at]!=255;){
        result.consumed=at;if(s.closed.load(std::memory_order_acquire)){result.status=Status::closed;return result;}
        const auto* cmd=packet.data()+at;const std::uint8_t op=*cmd;std::size_t length=0;
        if((op&0xF0)==0)length=op==8?4:5+((op&1)?1:0)+((op&2)?1:0)+((op&4)?2:0);
        else if(op==0x28||op==0x40||op==0x43)length=1;
        else if(op==0x29||op==0x4B)length=3;
        else if(op==0x41||op==0x42||(op>=0x47&&op<=0x4A))length=2;
        else if(op==0x44)length=6;
        else if(op==0x45||op==0x4C)length=4;
        else if(op==0x4D||op==0x4E)length=21;
        if(!length||length>bytes-at){auto reported=report(op);result.status=reported==Status::ok?Status::invalid_input:reported;return result;}
        Status status=Status::ok;
        if((op&0xF0)==0){
            std::size_t pos=4;bool change=(op&8)!=0;std::uint8_t volume=change?255:127,pan=change?255:64;std::uint16_t pitch=change?65535:0x2000;
            if(op!=8){if(op&1)volume=cmd[pos++];if(op&2)pan=cmd[pos++];if(op&4){pitch=std::uint16_t(cmd[pos])<<8|cmd[pos+1];pos+=2;}}
            if(op==8)status=command(banks::CancelRequest{cmd[1],cmd[2],cmd[3]});
            else if(change)status=command(banks::ChangeRequest{cmd[1],cmd[2],cmd[3],volume,pan,pitch});
            else status=command(banks::StartRequest{cmd[1],cmd[2],cmd[3],volume,pan,pitch,cmd[pos]});
        }else if(op==0x4D||op==0x4E){
            const unsigned port=unsigned(cmd[1])<<8|cmd[2];if(port>=banks::port_count){auto reported=report(port);result.status=reported==Status::ok?Status::invalid_input:reported;return result;}
            std::uint32_t sequences{};auto loaded=s.bank->port_state(port,sequences);if(loaded.status!=banks::Status::ok){result.status=translated(loaded.status);return result;}
            // Source conditional admission precedes ALL unused descriptor
            // validation, RAM reads, asset count and asset byte allocation.
            if(op==0x4D||!loaded.value){
                if(ramBytes>s.identity.ram_bytes){result.status=Status::invalid_input;return result;}
                std::array<std::size_t,3> offsets{},sizes{};
                for(unsigned n=0;n<3;++n){const auto* p=cmd+3+n*6;
                    offsets[n]=(std::uint32_t(p[0])<<24|std::uint32_t(p[1])<<16|std::uint32_t(p[2])<<8|(p[3]&240))&0x1FFFFFF;
                    sizes[n]=std::size_t(p[3]&15)<<20|std::size_t(p[4])<<12|std::size_t(p[5])<<4;
                    if(!ramPresent||offsets[n]>ramBytes||sizes[n]>ramBytes-offsets[n]){result.status=Status::invalid_input;return result;}
                }
                status=prepare_install(s,call.submission_,port,source,{sizes[0],sizes[1],sizes[2]},&offsets,&transaction);
            }
        }else if(op==0x29)status=command(banks::SetAllVolumes{std::uint16_t(unsigned(cmd[1])<<8|cmd[2])});
        else if(op==0x41)status=command(banks::SetMuted{cmd[1]!=0});
        else if(op==0x42)status=command(banks::SetMono{cmd[1]==0});
        else if(op==0x4C){if(cmd[1]<banks::port_count)status=command(banks::SetPortVolume{cmd[1],std::uint16_t(unsigned(cmd[2])<<8|cmd[3])});}
        else if(op==0x28||op==0x40||op==0x43)status=command(banks::StopAll{op==0x43});
        else if(op>=0x47&&op<=0x4A&&cmd[1]<banks::port_count)status=command(banks::StopPort{cmd[1],op<0x4A});
        else if(op==0x44)status=command(banks::UnsupportedControl{banks::DiagnosticKind::reverb,cmd[1]});
        else status=report(op);
        if(status!=Status::ok){result.status=status;return result;}
        at+=length;result.consumed=at;++result.commands_applied;
    }
    result.status=Status::ok;result.parser_accepted=true;return result;
}
Result<std::uint32_t> PacketAdapter::pending_loads(Call& call)noexcept {
    auto& s=*state_;std::lock_guard transaction(s.transaction);auto status=call_status(s,call.state_);if(status!=Status::ok)return {status,0};auto r=s.bank->pending_loads();return {translated(r.status),r.value};
}
Result<std::uint32_t> PacketAdapter::port_state(Call& call,unsigned port,std::uint32_t& count)noexcept {
    auto& s=*state_;std::lock_guard transaction(s.transaction);auto status=call_status(s,call.state_);if(status!=Status::ok)return {status,0};auto r=s.bank->port_state(port,count);return {translated(r.status),r.value};
}
Result<std::uint32_t> PacketAdapter::sequence_state(Call& call,unsigned port,unsigned index,unsigned group)noexcept {
    auto& s=*state_;std::lock_guard transaction(s.transaction);auto status=call_status(s,call.state_);if(status!=Status::ok)return {status,0};auto r=s.bank->sequence_state(port,index,group);return {translated(r.status),r.value};
}
Status PacketAdapter::reset(Call& call)noexcept {
    auto& s=*state_;std::lock_guard transaction(s.transaction);auto status=call_status(s,call.state_);if(status!=Status::ok)return status;return translated(s.bank->reset());
}
Status PacketAdapter::mix_add(float* output,std::uint32_t frames,banks::GainProvider& gains)noexcept {
    auto& s=*state_;if(!output||!frames)return translated(s.bank->mix_add(output,frames,gains));
    std::lock_guard transaction(s.transaction);return translated(s.bank->mix_add(output,frames,gains));
}
void PacketAdapter::request_stop()noexcept {state_->closed.store(true,std::memory_order_release);}
void PacketAdapter::join()noexcept {request_stop();auto& s=*state_;std::unique_lock lock(s.gate);s.changed.wait(lock,[&]{return !s.calls;});}
banks::BudgetSnapshot PacketAdapter::control_budget()const noexcept{return state_->control->snapshot();}
} // namespace reo::native::bank_packets
