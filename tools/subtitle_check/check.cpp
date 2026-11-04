// Controlled guest runtime: exercise production hooks and Windows IPC without
// starting the game. run.py can also inject owned generated queue functions.
#include <windows.h>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <map>
#include <stdexcept>
#include <vector>
struct Register { uint64_t lo=0,hi=0; };
struct R5900Context { Register r[32]{};uint32_t pc=0,branch_pc=0;bool in_delay_slot=false; };
struct PS2Runtime {
    using Function=void(*)(uint8_t*,R5900Context*,PS2Runtime*);
    std::map<uint32_t,Function> functions;
    bool preempt=false;
    bool hasFunction(uint32_t pc) { return functions.contains(pc); }
    Function lookupFunction(uint32_t pc) { return functions.at(pc); }
    void registerFunction(uint32_t pc,Function f) { functions[pc]=f; }
    bool shouldPreemptGuestExecution() { bool value=preempt;preempt=false;return value; }
};
constexpr uint32_t PS2_RAM_SIZE=32u*1024u*1024u;
#define GPR_U32(c,n) uint32_t((c)->r[n].lo)
#define GPR_U64(c,n) ((c)->r[n].lo)
#define GPR_S64(c,n) int64_t((c)->r[n].lo)
#define GPR_VEC(c,n) ((c)->r[n])
#define SET_GPR_U32(c,n,v) ((c)->r[n].lo=uint32_t(v))
#define SET_GPR_S32(c,n,v) ((c)->r[n].lo=uint64_t(int64_t(int32_t(v))))
#define SET_GPR_U64(c,n,v) ((c)->r[n].lo=uint64_t(v))
#define SET_GPR_S64(c,n,v) ((c)->r[n].lo=uint64_t(v))
#define SET_GPR_VEC(c,n,v) ((c)->r[n]=(v))
#define ADD32(a,b) (uint32_t(uint32_t(a)+uint32_t(b)))
template<class T> T load(const uint8_t* ram,uint32_t address) { T v;std::memcpy(&v,ram+(address&0x1fffffffu),sizeof(v));return v; }
template<class T> void store(uint8_t* ram,uint32_t address,T v) { std::memcpy(ram+(address&0x1fffffffu),&v,sizeof(v)); }
#define READ8(a) load<uint8_t>(rdram,a)
#define READ16(a) load<uint16_t>(rdram,a)
#define READ64(a) load<uint64_t>(rdram,a)
#define READ128(a) load<Register>(rdram,a)
#define WRITE8(a,v) store<uint8_t>(rdram,a,v)
#define WRITE16(a,v) store<uint16_t>(rdram,a,v)
#define WRITE64(a,v) store<uint64_t>(rdram,a,v)
#define WRITE128(a,v) store<Register>(rdram,a,v)
#include "../../recomp/overrides/reo_subtitles.h"
unsigned checks=0,draws=0,allocations=0;
bool yieldAllocation=false;
uint32_t resultPointer=0;
void check(bool ok,const char* message) { ++checks;if(!ok)throw std::runtime_error(message); }
void originalDraw(uint8_t*,R5900Context* c,PS2Runtime*) { ++draws;c->pc=GPR_U32(c,31); }
void originalAllocate(uint8_t* ram,R5900Context* c,PS2Runtime*) {
    using namespace reo::subtitles;
    ++allocations;
    if(yieldAllocation) {
        yieldAllocation=false;store<uint32_t>(ram,GPR_U32(c,29)-0x10,GPR_U32(c,31));
        SET_GPR_U32(c,29,GPR_U32(c,29)-0x90);c->pc=allocator+0x64;return;
    }
    if(c->pc!=allocator) { SET_GPR_U32(c,31,load<uint32_t>(ram,GPR_U32(c,29)+0x80));SET_GPR_U32(c,29,GPR_U32(c,29)+0x90); }
    SET_GPR_U32(c,2,resultPointer);c->pc=GPR_U32(c,31);
}
#ifdef REO_GENERATED_QUEUE
namespace reo_parent_natural {
std::atomic<std::size_t> actualOwnerBindingCount{0};
[[noreturn]] void refuseUnguardedSource(uint32_t) { throw std::runtime_error("Unexpected natural owner in controlled guest test"); }
}
#include "owned_queue.inc"
#endif
int main() {
    try {
        using namespace reo::subtitles;
        check(enabled.load(),"Default on");
        for(const char* bad:{"","false","2","01","1 ","-1"})check(!applyEnvironment(bad)&&enabled.load(),"Invalid startup setting");
        check(!applyEnvironment(nullptr),"Missing startup setting");
        check(applyEnvironment("0")&&!enabled.load(),"Startup off");
        check(applyEnvironment("1")&&enabled.load(),"Startup on");
        const std::array<uint32_t,4> good{magic,version,2,0};
        for(unsigned i=0;i<5;++i) {
            auto bad=good;if(i==0)++bad[0];if(i==1)++bad[1];if(i==2)bad[2]=3;if(i==3)bad[3]=2;
            check(!accept(bad,i==4?4:bad[2])&&enabled.load(),"Invalid or torn snapshot");
        }
        char name[100];std::snprintf(name,sizeof(name),"Local\\REO-Subtitle-check-%lu",GetCurrentProcessId());
        HANDLE mapping=CreateFileMappingA(INVALID_HANDLE_VALUE,nullptr,PAGE_READWRITE,0,16,name);
        check(mapping!=nullptr,"Create real Windows mapping");
        auto* words=static_cast<uint32_t*>(MapViewOfFile(mapping,FILE_MAP_ALL_ACCESS,0,0,16));
        check(words!=nullptr,"View real Windows mapping");std::memset(words,0,16);
        _putenv_s("REO_SUBTITLE_MAP",name);_putenv_s("REO_SUBTITLES","1");
        auto publish=[&](bool value) {
            std::atomic_ref<uint32_t>(words[2]).store(1,std::memory_order_release);
            words[0]=magic;words[1]=version;words[3]=value?1:0;
            std::atomic_ref<uint32_t>(words[2]).store(2,std::memory_order_release);
        };
        PS2Runtime runtime;runtime.functions[allocator]=originalAllocate;runtime.functions[allocator+0x64]=originalAllocate;runtime.functions[drawLeaf]=::originalDraw;
        install(runtime);check(enabled.load(),"Invalid empty map preserves startup on");
        check(runtime.lookupFunction(allocator+0x64)==enqueue,"Allocator continuation hooked");
        std::vector<uint8_t> ram(PS2_RAM_SIZE);R5900Context ctx;
        auto allocate=[&](uint32_t source,bool typed=false,bool resumed=false) {
            const auto returnPc=typed?customReturn:frontReturn;
            const auto target=typed?custom:front;
            ctx={};ctx.pc=allocator;SET_GPR_U32(&ctx,29,0x10000);SET_GPR_U32(&ctx,31,returnPc);
            store<uint32_t>(ram.data(),0x10000+(typed?0x10:0x60),source);
            if(source>=8)store<uint32_t>(ram.data(),source-8,0x0c000000u|(target>>2));
            yieldAllocation=resumed;
            runtime.lookupFunction(ctx.pc)(ram.data(),&ctx,&runtime);
            if(resumed) { check(ctx.pc==allocator+0x64,"Simulated guest yield");runtime.lookupFunction(ctx.pc)(ram.data(),&ctx,&runtime); }
        };
        auto render=[&](uint32_t text) {
            ctx={};ctx.pc=drawLeaf;SET_GPR_U32(&ctx,7,text);SET_GPR_U32(&ctx,31,0x1234);
            runtime.lookupFunction(ctx.pc)(ram.data(),&ctx,&runtime);check(ctx.pc==0x1234,"Draw returns to guest caller");
        };
        for(auto source:spokenReturns) {
            resultPointer=slots+10;allocate(source);check(spokenSlots[0],"Callout source tagged");
        }
        for(auto source:typedReturns) {
            resultPointer=slots+0x8c+10;allocate(source,true,true);check(spokenSlots[1],"Typed dialogue tagged after guest resume");
        }
        const auto before=draws;render(slots+12);check(draws==before+1,"Default on forwards glyph renderer");
        publish(false);const auto oldQueue=ram;render(slots+12);render(slots+0x8c+12);
        check(draws==before+1,"Off skips both spoken glyph submissions");check(ram==oldQueue,"Suppression leaves guest queue and dialogue state untouched");
        render(slots+2*0x8c+12);render(0x20000);check(draws==before+3,"Prompts menus and non-spoken slots still render");
        resultPointer=slots+10;allocate(0x123456);check(!spokenSlots[0],"Normal text reuse clears spoken tag");
        render(slots+12);check(draws==before+4,"Reused slot renders ordinary text when off");
        resultPointer=0;allocate(spokenReturns[0]);check(!spokenSlots[0],"Rejected allocation does not tag stale V0");
        publish(true);render(slots+0x8c+12);check(draws==before+5,"Live re-enable forwards pending caption");
        words[2]=3;words[3]=0;poll();check(enabled.load(),"Pending IPC update preserves last valid choice");
#ifdef REO_GENERATED_QUEUE
        runOwnedQueueChecks(runtime,ram,ctx,publish);
#endif
        UnmapViewOfFile(words);CloseHandle(mapping);
        std::printf("PASS %u subtitle checks\n",checks);return 0;
    } catch(const std::exception& error) { std::fprintf(stderr,"FAIL: %s\n",error.what());return 1; }
}
