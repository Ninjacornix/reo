// SPDX-License-Identifier: GPL-3.0-only
#include "world_sync.h"
#include "native_netcode.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <array>
#include <atomic>
#include <cstdio>
#include <cstring>
#include <deque>
#include <mutex>
#include <stdexcept>

namespace reo_network::native {
thread_local bool reliableRefresh = false;
namespace {
constexpr uint32_t RamBytes = 0x02000000, RecordBytes = 96, StackBytes = 4096;
constexpr uint32_t ReturnPc = 0x01ff0ff0;
constexpr uint64_t RefreshCooldown = 3000000, RequestLifetime = 10000000;
struct Layout {
    uint32_t table, count, scenario, room, local, phase, online, owners, queued;
    uint32_t actors, end, stride, spawn, lifecycle, health, lookup, producer, sender, packet;
};
// Corroborated original constructors 6BAA40/6BB040 and 6E80B0/6E8710;
// group-8 producer/receiver 637C10/63ACA0 and 754750/754DD0.
constexpr Layout File1{0x74f250,0x4bae8e,0x3243da,0x3243dc,0x4baded,0x4badd0,
    0x3243fb,0x815830,0x815d48,0x42eb00,0x459120,0xd90,0xb98,0xb9a,0x544,
    0x63ed80,0x637c10,0x63abb0,0x74f210};
constexpr Layout File2{0x7aff80,0x4db44e,0x30095a,0x30095c,0x4db3ad,0x4db390,
    0x30097b,0x815c30,0x816148,0x44de90,0x478af0,0xdb0,0xbb0,0xbb2,0x540,
    0x75c730,0x754750,0x7545c0,0x7aff40};
template<class T> T get(const uint8_t* ram, uint32_t at) {
    T value; std::memcpy(&value, ram + at, sizeof(value)); return value;
}
bool range(uint32_t address, size_t bytes) { return address < RamBytes && bytes <= RamBytes-address; }
bool ready(const uint8_t* ram, const Layout& g, uint16_t& room, uint8_t& owner) {
    // The raw owner queue belongs to backend 1. Other original backends use
    // different ownership tables even when their online predicate is true.
    if (!ram || ram[g.online]!=1 || ram[g.online-9]!=1 || ram[g.phase]!=2 ||
        ram[g.local]>=4 || ram[g.local+1] || ram[g.local+11]) return false;
    room=get<uint16_t>(ram,g.room);
    if (room>=128) return false;
    owner=ram[g.owners+4*room];
    const bool file2=g.stride==0xdb0;
    const auto player=(file2?0x4c5e10u:0x4a5c30u)+(file2?0x1100u:0x10e0u)*ram[g.local];
    return owner<4 && ram[player] && ram[player+2]==0 && ram[player+3]==ram[g.local] &&
        get<uint16_t>(ram,player+0x1e2)==room;
}
struct Request { uint16_t room; uint8_t authority; };
std::mutex requestMutex;
std::deque<Request> requests;
std::atomic<uint64_t> resetGeneration{1};
uint64_t disabledGeneration=0; // Guest owner only; reset starts a new session.
std::atomic<uint64_t> requested{0}, rejected{0}, completed{0}, refreshed{0}, packets{0}, skipped{0};
struct Observation { uint8_t kind=0, family=0, model=0; };
// Guest-owner state contains value copies only; never retains RAM/context.
struct GuestState {
    uint64_t generation=0, started=0, lastCompleted=0;
    uint16_t scenario=0, room=0;
    bool initialized=false, file2=false, active=false;
    uint8_t authority=0;
    unsigned cursor=0;
    std::array<Observation,256> observed{};
} guest;
void synchronize(const uint8_t* ram, bool file2, const Layout& g, uint16_t room) {
    const auto generation=resetGeneration.load(std::memory_order_acquire);
    const auto scenario=get<uint16_t>(ram,g.scenario);
    if (!guest.initialized || guest.generation!=generation || guest.file2!=file2 ||
        guest.scenario!=scenario || guest.room!=room) {
        guest={}; guest.initialized=true; guest.generation=generation;
        guest.file2=file2; guest.scenario=scenario; guest.room=room;
    }
}
bool absolute(uint8_t kind) {
    switch(kind) {
        case 1: case 2: case 6: case 7:
        case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: return true;
        default: return false;
    }
}
uint8_t length(uint8_t kind) {
    switch(kind) {
        case 1: case 2: case 0x28: case 0x2b: return 30;
        case 6: return 42;
        case 7: case 0x2a: case 0x2d: return 32;
        case 0x29: case 0x2c: return 40;
        case 8: return 6;
        default: return 0;
    }
}
// These helpers only pack, look up or enqueue. None loads models or yields to
// asynchronous I/O. Preserve the entire interrupted context and reserve guest
// stack memory below its current frame, including helper callees' stack space.
class Calls {
    uint8_t* ram_; R5900Context* context_; PS2Runtime* runtime_;
    R5900Context saved_;
    uint32_t bottom_, sp_;
    std::array<uint8_t,StackBytes> stack_{};
    unsigned remaining_=12;
public:
    Calls(uint8_t* ram,R5900Context* context,PS2Runtime* runtime)
        :ram_(ram),context_(context),runtime_(runtime),saved_(*context),
         bottom_(GPR_U32(context,29)-StackBytes),sp_(GPR_U32(context,29)-256) {
        std::memcpy(stack_.data(),ram_+bottom_,StackBytes);
    }
    ~Calls() { std::memcpy(ram_+bottom_,stack_.data(),StackBytes); *context_=saved_; }
    uint32_t scratch() const { return sp_+128; }
    uint32_t call(uint32_t entry,uint32_t a0,uint32_t a1=0,uint32_t a2=0) {
        if (!remaining_--) throw std::runtime_error("World refresh exceeded its original helper budget");
        *context_=saved_;
        SET_GPR_U32(context_,29,sp_); SET_GPR_U32(context_,31,ReturnPc);
        SET_GPR_U32(context_,4,a0); SET_GPR_U32(context_,5,a1); SET_GPR_U32(context_,6,a2);
        context_->pc=entry;
        runtime_->lookupFunction(entry)(ram_,context_,runtime_);
        if (context_->pc!=ReturnPc)
            throw std::runtime_error("World refresh original helper unexpectedly suspended");
        return GPR_U32(context_,2);
    }
};
bool living(const uint8_t* ram,const Layout& g,uint32_t actor,unsigned id,uint16_t room) {
    return actor>=g.actors && actor<g.end && (actor-g.actors)%g.stride==0 &&
        ram[actor]!=0 && ram[actor+2]==2 && ram[actor+8]!=0 &&
        ram[actor+g.spawn]==id && ram[actor+g.lifecycle]==0 &&
        get<int16_t>(ram,actor+g.health)>0 && get<uint16_t>(ram,actor+0x1e2)==room;
}
bool send(uint8_t* ram,const Layout& g,Calls& calls,uint32_t actor,uint8_t kind,unsigned id) {
    ram[calls.scratch()]=0;
    calls.call(g.producer,actor,kind,calls.scratch());
    if (!ram[calls.scratch()] || ram[g.packet]!=kind || ram[g.packet+1]!=length(kind) ||
        ram[g.packet+3]!=id) return false;
    struct Reliable {
        bool previous=reliableRefresh;
        Reliable() { reliableRefresh=true; }
        ~Reliable() { reliableRefresh=previous; }
    } reliable;
    calls.call(g.sender,actor);
    ++packets;
    return true;
}
} // namespace

bool worldCapture(uint8_t* ram,bool file2,uint64_t now,WorldDigest& out) {
    (void)now;
    const auto& g=file2?File2:File1; uint16_t room; uint8_t owner;
    if (!ready(ram,g,room,owner)) { guest={}; return false; }
    synchronize(ram,file2,g,room);
    // Original loader clears 0x6000 bytes and writes its populated count to an
    // unsigned byte (6BAFC0 / corresponding File2 loader). Do not infer entries
    // from renderer slots, nor scan uninitialized trailing zero records.
    return worldDigestRecords(ram+g.table,size_t(ram[g.count])*RecordBytes,room,owner,out);
}
bool worldRequest(uint16_t room,uint8_t authority) {
    if (room>=128 || authority>=4) { ++rejected; return false; }
    std::lock_guard lock(requestMutex);
    for (const auto& value:requests) if(value.room==room && value.authority==authority) return true;
    if (requests.size()>=8) { ++rejected; return false; }
    requests.push_back({room,authority}); ++requested; return true;
}
void worldObserve(const uint8_t* ram,bool file2,uint32_t group,uint32_t record) {
    if (group!=8 || !ram || !range(record,4) || reliableRefresh) return;
    const auto kind=ram[record];
    if (!absolute(kind) || ram[record+1]!=length(kind) || !range(record,length(kind))) return;
    const auto& g=file2?File2:File1; uint16_t room; uint8_t owner;
    if (!ready(ram,g,room,owner) || owner!=ram[g.local]) return;
    synchronize(ram,file2,g,room);
    const auto id=ram[record+3];
    if (id>=ram[g.count]) return;
    const auto* r=ram+g.table+id*RecordBytes;
    if (r[0]!=id || r[0x22]!=room || r[0x26]!=0) return;
    guest.observed[id]={kind,r[2],r[3]};
}
void worldTick(uint8_t* ram,R5900Context* context,PS2Runtime* runtime,
               bool file2,uint64_t now) {
    const auto& g=file2?File2:File1; uint16_t room; uint8_t owner;
    if (!context || !runtime || !ready(ram,g,room,owner)) { guest={}; return; }
    synchronize(ram,file2,g,room);
    if(disabledGeneration==guest.generation) return;
    if (!reo_network::native::runtime().enhanced(now)) { guest.active=false; return; }
    if (!guest.active) {
        Request request{};
        {
            std::lock_guard lock(requestMutex);
            if(requests.empty()) return;
            request=requests.front(); requests.pop_front();
        }
        if (request.room!=room || request.authority!=owner || owner!=ram[g.local] ||
            (guest.lastCompleted && now-guest.lastCompleted<RefreshCooldown)) { ++rejected; return; }
        guest.active=true; guest.authority=owner; guest.cursor=0; guest.started=now;
    }
    if(owner!=guest.authority || owner!=ram[g.local] || now<guest.started || now-guest.started>RequestLifetime) {
        guest.active=false; ++rejected; return;
    }
    // Leave headroom in the original 512-byte application staging allowance.
    // Two enemies add at most 2*(42+6+2*16)=160 bytes of SDK records.
    if(get<uint32_t>(ram,g.queued)>256) return;
    const auto sp=GPR_U32(context,29);
    if (sp<0x100000+StackBytes || sp>RamBytes || (sp&15) || !range(sp-StackBytes,StackBytes)) {
        guest.active=false; ++rejected; return;
    }
    auto disable=[&](const char* reason) {
        guest.active=false; disabledGeneration=guest.generation; ++rejected;
        std::fprintf(stderr,"[native-world] Automatic enemy refresh disabled for this session: %s\n",reason);
    };
    if(!runtime->hasFunction(g.lookup) || !runtime->hasFunction(g.producer) || !runtime->hasFunction(g.sender)) {
        disable("original helper is unavailable"); return;
    }
    try {
        Calls calls(ram,context,runtime);
        unsigned budget=2;
        const auto count=ram[g.count];
        while(guest.cursor<count && budget) {
            const unsigned id=guest.cursor++;
            const auto record=g.table+id*RecordBytes;
            if(ram[record]!=id || ram[record+0x22]!=room || ram[record+0x26]!=0 ||
                get<int16_t>(ram,record+0x1c)<=0) continue;
            --budget;
            // Original lookup also checks loading state, local allocation marker,
            // active actor and current-room identity. It never creates an enemy.
            const auto actor=calls.call(g.lookup,record);
            if(!living(ram,g,actor,id,room)) { ++skipped; continue; }
            const auto observation=guest.observed[id];
            if(absolute(observation.kind) && observation.family==ram[record+2] &&
                observation.model==ram[record+3]) send(ram,g,calls,actor,observation.kind,id);
            // Subtype8 is an absolute HP value, not damage replay (63B888/756C10).
            if(send(ram,g,calls,actor,8,id)) ++refreshed;
        }
        if(guest.cursor>=count) { guest.active=false; guest.lastCompleted=now; ++completed; }
    } catch(const std::exception& error) {
        // Calls restores the interrupted context and reserved stack first. A
        // peer's request must not stop gameplay when this optional subset is
        // unavailable; never retry a helper with an unexpected continuation.
        disable(error.what());
    } catch(...) {
        disable("unexpected original helper failure");
    }
}
void worldReset() {
    { std::lock_guard lock(requestMutex); requests.clear(); }
    resetGeneration.fetch_add(1,std::memory_order_release);
}
WorldStats worldStats() {
    return {requested.load(),rejected.load(),completed.load(),refreshed.load(),packets.load(),skipped.load()};
}
} // namespace reo_network::native
