// Controlled guest runtime for production escapeTimers plus owned generated code.
// Guest instructions are staged privately by escape_timer_check.py.
#include <windows.h>
#include <array>
#include <atomic>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <map>
#include <stdexcept>
#include <vector>

struct Register { uint64_t lo=0,hi=0; };
struct R5900Context { Register r[32]{};uint32_t pc=0,branch_pc=0;bool in_delay_slot=false; };
constexpr uint32_t PS2_RAM_SIZE=32u*1024u*1024u;
template<class T> T load(const uint8_t* ram,uint32_t address) { T v;std::memcpy(&v,ram+(address&0x1fffffffu),sizeof(v));return v; }
template<class T> void store(uint8_t* ram,uint32_t address,T v) { std::memcpy(ram+(address&0x1fffffffu),&v,sizeof(v)); }
struct PS2Runtime {
    using Function=void(*)(uint8_t*,R5900Context*,PS2Runtime*);
    struct Memory { uint8_t* ram=nullptr;uint8_t* getRDRAM() { return ram; } } memoryView;
    struct Overlay { uint32_t base,magic,idOffset,id,address;Function function; };
    std::map<uint32_t,Function> functions;
    std::vector<Overlay> overlays;
    bool preempt=false;
    Memory& memory() { return memoryView; }
    Function lookupFunction(uint32_t pc) {
        for(auto it=overlays.rbegin();it!=overlays.rend();++it)
            if(it->address==pc && memoryView.ram && load<uint32_t>(memoryView.ram,it->base)==it->magic &&
               load<uint32_t>(memoryView.ram,it->base+it->idOffset)==it->id) return it->function;
        return functions.at(pc);
    }
    bool hasFunction(uint32_t pc) { return functions.contains(pc); }
    void registerFunction(uint32_t pc,Function f) { functions[pc]=f; }
    void registerOverlayFunction(uint32_t base,uint32_t magic,uint32_t idOffset,uint32_t id,uint32_t address,Function f) {
        overlays.push_back({base,magic,idOffset,id,address,f});
    }
    bool shouldPreemptGuestExecution() { bool result=preempt;preempt=false;return result; }
};
#define GPR_U32(c,n) uint32_t((c)->r[n].lo)
#define GPR_U64(c,n) ((c)->r[n].lo)
#define GPR_S64(c,n) int64_t((c)->r[n].lo)
#define GPR_VEC(c,n) ((c)->r[n])
#define SET_GPR_U32(c,n,v) ((c)->r[n].lo=uint32_t(v))
#define SET_GPR_S32(c,n,v) ((c)->r[n].lo=uint64_t(int64_t(int32_t(v))))
#define SET_GPR_U64(c,n,v) ((c)->r[n].lo=uint64_t(v))
#define SET_GPR_S64(c,n,v) ((c)->r[n].lo=uint64_t(v))
#define SET_GPR_VEC(c,n,v) ((c)->r[n]=(v))
#define ADD32(a,b) uint32_t(uint32_t(a)+uint32_t(b))
#define SLL32(a,b) (uint32_t(a) << (uint32_t(b)&31u))
#define READ8(a) load<uint8_t>(rdram,a)
#define READ16(a) load<uint16_t>(rdram,a)
#define READ64(a) load<uint64_t>(rdram,a)
#define READ128(a) load<Register>(rdram,a)
#define WRITE8(a,v) store<uint8_t>(rdram,a,v)
#define WRITE16(a,v) store<uint16_t>(rdram,a,v)
#define WRITE64(a,v) store<uint64_t>(rdram,a,v)
#define WRITE128(a,v) store<Register>(rdram,a,v)
#include "../../recomp/overrides/reo_cheats.h"
namespace reo_parent_natural {
std::atomic<std::size_t> actualOwnerBindingCount{0};
[[noreturn]] void refuseUnguardedSource(uint32_t) { throw std::runtime_error("Unexpected natural owner in controlled runtime"); }
}
struct Expiry { unsigned bank,id,value; };
std::vector<Expiry> expiryCalls;
unsigned checks=0,frameCalls=0,foreignCalls=0;
void check(bool ok,const char* message) { ++checks;if(!ok)throw std::runtime_error(message); }
void frame(uint8_t*,R5900Context* c,PS2Runtime*) { ++frameCalls;c->pc=GPR_U32(c,31); }
void foreign(uint8_t*,R5900Context* c,PS2Runtime*) { ++foreignCalls;c->pc=GPR_U32(c,31); }
#include "owned_escape_timer.inc"

int main(int argc,char** argv) {
    std::filesystem::path manifest;
    try {
        using namespace reo::cheats;
        constexpr uint32_t returnPc=0x1234;
#if defined(REO_GAME_FILE2)
        constexpr uint32_t timers=0x4db338,flags=0x4db348,scriptWait=0x4db2a8,elapsed=0x4db3a8,wallet=0x2feea4;
#else
        constexpr uint32_t timers=0x4bad88,flags=0x4bad98,scriptWait=0x4bacf8,elapsed=0x4bade8,wallet=0x31fb60;
#endif
        PS2Runtime runtime;std::vector<uint8_t> ram(PS2_RAM_SIZE);runtime.memoryView.ram=ram.data();R5900Context ctx;
        registerExpiryCallbacks(runtime);
        runtime.functions[frameService]=frame;
        runtime.functions[escapeTimerService]=foreign;
        manifest=std::filesystem::path(argc>0?argv[0]:"escape-test");manifest.replace_extension(".manifest");
        { std::ofstream file(manifest);file<<"REO-CHEATS-2\nbuiltin points\nbuiltin escape\n"; }
        check(_wputenv_s(L"REO_CHEATS_FILE",manifest.c_str())==0,"Publish owned manifest path");
        install(runtime);
        check(builtinFlags==(InfiniteEscapeTime|MaxResultsPoints),"Production install parses points and escape manifest tokens together");
        check(runtime.overlays.size()==1,"Production install registers one overlay entry");
        const auto& hook=runtime.overlays[0];
        check(hook.base==gameplayOverlayBase&&hook.magic==0x336f574d&&hook.idOffset==4&&hook.id==3&&
              hook.address==escapeTimerService&&hook.function==escapeTimers,"Production hook identifies gameplay overlay base, signature, ID and service");
        check(runtime.functions[frameService]==service&&originalService==frame,"Original frame service is chained");
        store<uint32_t>(ram.data(),wallet,5);
        store<uint32_t>(ram.data(),wallet-4,0x12345678);store<uint32_t>(ram.data(),wallet+4,0x87654321);
        auto expectedPointsRam=ram;store<uint32_t>(expectedPointsRam.data(),wallet,maximumResultsPoints);
        ctx.pc=frameService;SET_GPR_U32(&ctx,31,returnPc);
        runtime.lookupFunction(ctx.pc)(ram.data(),&ctx,&runtime);
        check(frameCalls==1&&ctx.pc==returnPc,"Production frame service forwards original callback exactly once and retains guest return");
        check(ram==expectedPointsRam,"Production points service changes only verified wallet, preserving lifetime and adjacent data");
        store<uint32_t>(ram.data(),wallet,123);ctx.pc=frameService;
        runtime.lookupFunction(ctx.pc)(ram.data(),&ctx,&runtime);
        check(frameCalls==2&&load<uint32_t>(ram.data(),wallet)==maximumResultsPoints,"Production points service refills spendable points after spending");
        builtinFlags=InfiniteEscapeTime;store<uint32_t>(ram.data(),wallet,456);ctx.pc=frameService;
        runtime.lookupFunction(ctx.pc)(ram.data(),&ctx,&runtime);
        check(frameCalls==3&&load<uint32_t>(ram.data(),wallet)==456,"Escape cheat alone does not refill results points");
        store<uint32_t>(ram.data(),gameplayOverlayBase,0x336f574d);
        store<uint32_t>(ram.data(),gameplayOverlayBase+4,3);
        check(runtime.lookupFunction(escapeTimerService)==escapeTimers,"Matching resident gameplay overlay selects production hook");
        store<uint32_t>(ram.data(),gameplayOverlayBase+4,1);
        check(runtime.lookupFunction(escapeTimerService)==foreign,"Other resident overlays retain their own function");
        store<uint32_t>(ram.data(),gameplayOverlayBase+4,3);
        const std::array<int16_t,8> initial{-1,0,1,2,32767,-32768,60,0};
        auto seed=[&] {
            expiryCalls.clear();
            for(unsigned i=0;i<8;++i) {
                store<int16_t>(ram.data(),timers+i*2,initial[i]);
                store<uint16_t>(ram.data(),flags+i*2,uint16_t(0x120+i|(i==3?0x8000:0)));
            }
            store<uint32_t>(ram.data(),scriptWait,47);store<uint32_t>(ram.data(),elapsed,9213);
            ctx={};ctx.pc=escapeTimerService;
            for(unsigned i=1;i<32;++i)ctx.r[i]={0x10000000u+i,0x20000000u+i};
            SET_GPR_U32(&ctx,29,0x10000);SET_GPR_U32(&ctx,31,returnPc);
        };
        auto call=[&] { ctx.pc=escapeTimerService;runtime.lookupFunction(ctx.pc)(ram.data(),&ctx,&runtime);check(ctx.pc==returnPc,"Timer updater returns to original guest caller"); };
        auto preserved=[&](const R5900Context& before) {
            for(unsigned i=16;i<=23;++i)check(std::memcmp(&ctx.r[i],&before.r[i],sizeof(Register))==0,"Callee-saved registers preserved");
            check(GPR_U32(&ctx,29)==GPR_U32(&before,29)&&GPR_U32(&ctx,31)==GPR_U32(&before,31),"Stack and return address preserved");
        };
        seed();builtinFlags=0;const auto originalRegisters=ctx;call();preserved(originalRegisters);
        for(unsigned i=0;i<8;++i)check(load<int16_t>(ram.data(),timers+i*2)==(initial[i]>0?initial[i]-1:initial[i]),"Disabled cheat executes actual original countdown rules");
        check(expiryCalls.size()==1&&expiryCalls[0].bank==0&&expiryCalls[0].id==0x122&&expiryCalls[0].value==1,"Original 1-to-0 expiry sets primary flag");
        call();
        check(expiryCalls.size()==2&&expiryCalls[1].bank==1&&expiryCalls[1].id==0x123&&expiryCalls[1].value==1,"Original alternate-bank expiry masks ID and sets flag");
        for(unsigned selected:{unsigned(InfiniteEscapeTime),unsigned(InfiniteEscapeTime|MaxResultsPoints)}) {
            seed();builtinFlags=selected;const auto frozenRegisters=ctx;const auto frozenRam=ram;call();
            check(ram==frozenRam,"Enabled production cheat leaves entire RAM byte-identical, including inactive and expired countdowns");
            check(expiryCalls.empty(),"Enabled production cheat dispatches no expiry flags");
            check(std::memcmp(ctx.r,frozenRegisters.r,sizeof(ctx.r))==0,"Enabled production cheat preserves all guest registers");
            check(load<uint32_t>(ram.data(),scriptWait)==47&&load<uint32_t>(ram.data(),elapsed)==9213,"Ordinary script wait and elapsed time remain untouched");
        }
        seed();builtinFlags=MaxResultsPoints;call();
        check(load<int16_t>(ram.data(),timers+6)==1&&expiryCalls.size()==1,"Points cheat alone does not freeze escape countdowns");
        // A preempted original must finish its existing stack frame even if the
        // selected flag changes before a non-entry continuation is dispatched.
        seed();builtinFlags=0;runtime.preempt=true;const auto beforeResume=ctx;
        escapeTimers(ram.data(),&ctx,&runtime);
        check(ctx.pc==escapeTimerService+0x10&&GPR_U32(&ctx,29)==0xffe0,"Actual original countdown yields with its guest frame intact");
        builtinFlags=InfiniteEscapeTime;escapeTimers(ram.data(),&ctx,&runtime);
        check(ctx.pc==returnPc&&load<int16_t>(ram.data(),timers+12)==59,"Non-entry continuation forwards actual original even with escape selected");
        preserved(beforeResume);
        check(load<uint32_t>(ram.data(),scriptWait)==47&&load<uint32_t>(ram.data(),elapsed)==9213,"Original countdown updater excludes script wait and elapsed clocks");
        PS2Runtime unlockRuntime;
        unlockRuntime.functions[frameService]=frame;
        { std::ofstream file(manifest);file<<"REO-CHEATS-2\nbuiltin unlock\n"; }
        install(unlockRuntime);
        check(builtinFlags==UnlockEverything && unlockRuntime.functions[frameService]==service,
              "Production installation preserves progression unlocks alongside the new points/escape hooks");
        std::filesystem::remove(manifest);
        std::printf("PASS %u production escape timer checks\n",checks);return 0;
    } catch(const std::exception& error) {
        if(!manifest.empty())std::filesystem::remove(manifest);
        std::fprintf(stderr,"FAIL: %s\n",error.what());return 1;
    }
}
