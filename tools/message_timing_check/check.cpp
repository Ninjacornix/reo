// Production resident hook, with controlled guest services. Optional owned
// functions execute the original task, message producers and queue updates.
#include <atomic>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <map>
#include <stdexcept>
#include <vector>
struct Register { uint64_t lo=0,hi=0; };
struct R5900Context { Register r[32]{};float f[32]{};uint64_t lo=0,hi=0;uint32_t pc=0,branch_pc=0;bool in_delay_slot=false; };
struct PS2Runtime {
    using Function=void(*)(uint8_t*,R5900Context*,PS2Runtime*);
    std::map<uint32_t,Function> functions;
    bool preempt=false;
    bool hasFunction(uint32_t pc) { return functions.contains(pc); }
    Function lookupFunction(uint32_t pc) {
        if(!functions.contains(pc)) {
            char message[80];std::snprintf(message,sizeof(message),"Unregistered controlled guest PC %x",pc);
            throw std::runtime_error(message);
        }
        return functions.at(pc);
    }
    void registerFunction(uint32_t pc,Function f) { functions[pc]=f; }
    bool shouldPreemptGuestExecution() { bool value=preempt;preempt=false;return value; }
};
constexpr uint32_t PS2_RAM_SIZE=32u*1024u*1024u;
#define GPR_U32(c,n) uint32_t((c)->r[n].lo)
#define GPR_U64(c,n) ((c)->r[n].lo)
#define GPR_S64(c,n) int64_t((c)->r[n].lo)
#define GPR_S32(c,n) int32_t((c)->r[n].lo)
#define GPR_VEC(c,n) ((c)->r[n])
#define SET_GPR_U32(c,n,v) ((c)->r[n].lo=uint32_t(v))
#define SET_GPR_S32(c,n,v) ((c)->r[n].lo=uint64_t(int64_t(int32_t(v))))
#define SET_GPR_U64(c,n,v) ((c)->r[n].lo=uint64_t(v))
#define SET_GPR_S64(c,n,v) ((c)->r[n].lo=uint64_t(v))
#define SET_GPR_VEC(c,n,v) ((c)->r[n]=(v))
#define ADD32(a,b) (uint32_t(uint32_t(a)+uint32_t(b)))
#define SUB32(a,b) (uint32_t(uint32_t(a)-uint32_t(b)))
#define SLL32(a,b) (uint32_t(a)<<uint32_t(b))
#define FPU_CVT_W_S(v) (int32_t(std::nearbyint(v)))
template<class T> T load(const uint8_t* ram,uint32_t a) { T v;std::memcpy(&v,ram+(a&0x1fffffffu),sizeof(v));return v; }
template<class T> void store(uint8_t* ram,uint32_t a,T v) { std::memcpy(ram+(a&0x1fffffffu),&v,sizeof(v)); }
#define READ8(a) load<uint8_t>(rdram,a)
#define READ16(a) load<uint16_t>(rdram,a)
#define READ32(a) load<uint32_t>(rdram,a)
#define READ64(a) load<uint64_t>(rdram,a)
#define READ128(a) load<Register>(rdram,a)
#define WRITE8(a,v) store<uint8_t>(rdram,a,v)
#define WRITE16(a,v) store<uint16_t>(rdram,a,v)
#define WRITE32(a,v) store<uint32_t>(rdram,a,v)
#define WRITE64(a,v) store<uint64_t>(rdram,a,v)
#define WRITE128(a,v) store<Register>(rdram,a,v)
#include "../../recomp/overrides/reo_subtitles.h"
unsigned checks=0,draws=0,taskFrees=0;
void check(bool ok,const char* message) { ++checks;if(!ok)throw std::runtime_error(message); }
void drawStub(uint8_t*,R5900Context* c,PS2Runtime*) { ++draws;c->pc=GPR_U32(c,31); }
uint32_t nextSlot=reo::subtitles::slots;
uint16_t requestedTicks=4;
bool rejectAllocation=false,yieldAllocation=false;
void allocateStub(uint8_t* ram,R5900Context* c,PS2Runtime*) {
    if(yieldAllocation) {
        yieldAllocation=false;store<uint32_t>(ram,GPR_U32(c,29)-0x10,GPR_U32(c,31));
        SET_GPR_U32(c,29,GPR_U32(c,29)-0x90);c->pc=reo::subtitles::allocator+0x64;return;
    }
    if(c->pc!=reo::subtitles::allocator) {
        SET_GPR_U32(c,31,load<uint32_t>(ram,GPR_U32(c,29)+0x80));SET_GPR_U32(c,29,GPR_U32(c,29)+0x90);
    }
    if(!rejectAllocation) { store<uint16_t>(ram,nextSlot,1);store<uint16_t>(ram,nextSlot+6,requestedTicks); }
    SET_GPR_U32(c,2,rejectAllocation?0:nextSlot+10);c->pc=GPR_U32(c,31);
}
void configureEnvironment(const char* value) {
#ifdef _WIN32
    _putenv_s("REO_MOD_EXAMINE_TIME_SCALE",value?value:"");
#else
    if(value)setenv("REO_MOD_EXAMINE_TIME_SCALE",value,1);else unsetenv("REO_MOD_EXAMINE_TIME_SCALE");
#endif
}
#ifdef REO_GENERATED_QUEUE
namespace reo_parent_natural {
std::atomic<std::size_t> actualOwnerBindingCount{0};
[[noreturn]] void refuseUnguardedSource(uint32_t) { throw std::runtime_error("Unexpected natural owner in controlled guest test"); }
}
#include "owned_queue.inc"
void ownedChecks() {
    using namespace reo::subtitles;
    namespace timing=reo::message_timing;
#if defined(REO_GAME_FILE2)
    constexpr uint32_t update=0x13f7f0,bankPointer=0x3009cc,cancel=0x4db3ca,cancelInput=0x4db3ae;
    constexpr uint32_t drawFlag=0x300956,updateFlag=0x30096b;
#else
    constexpr uint32_t update=0x1b3e00,bankPointer=0x32443c,cancel=0x4bae0a,cancelInput=0x4badee;
    constexpr uint32_t drawFlag=0x3243d6,updateFlag=0x3243eb;
#endif
    PS2Runtime runtime;std::vector<uint8_t> ram(PS2_RAM_SIZE);R5900Context ctx;
    constexpr uint32_t task=0x20000,bank=0x30000;
    auto setup=[&](unsigned scale,int lines=2,int ttl=4,int delay=0,int bankId=0) {
        runtime.functions.clear();ram.assign(PS2_RAM_SIZE,0);taskFrees=0;
#include "timing_registration.inc"
        install(runtime);timing::scale=scale;
#include "timing_witnesses.inc"
        ram[drawFlag]=ram[updateFlag]=ram[cancel]=1;
        store<uint32_t>(ram.data(),bankPointer,bank);store<uint32_t>(ram.data(),bank+4,0x20);
        store<uint32_t>(ram.data(),bank+8,lines);
        for(int i=0;i<lines;++i) {
            store<uint32_t>(ram.data(),bank+0x20+i*4,0x40+i*0x40);
            std::snprintf((char*)ram.data()+bank+0x40+i*0x40,40,"Examine line %d",i);
        }
        std::strcpy((char*)ram.data()+0x40000,"Examine system message");
        store<uint16_t>(ram.data(),task+0x0c,ttl);store<uint16_t>(ram.data(),task+0x0e,bankId);
        store<uint16_t>(ram.data(),task+0x10,delay);store<float>(ram.data(),task+0x70,64.f);
        store<float>(ram.data(),task+0x74,380.f);
    };
    auto invoke=[&](uint32_t pc,bool preempt=false) {
        ctx={};ctx.pc=pc;SET_GPR_U32(&ctx,29,0x10000);SET_GPR_U32(&ctx,31,0xabcdef);SET_GPR_U32(&ctx,4,task);
        runtime.preempt=preempt;unsigned resumes=0;
        do { runtime.lookupFunction(ctx.pc)(ram.data(),&ctx,&runtime);++resumes; }
        while(ctx.pc!=0xabcdef&&resumes<10000);
        check(ctx.pc==0xabcdef,"Original message task returns through ordinary guest continuations");
        return resumes;
    };
    for(unsigned scale:{1000u,1500u,2000u,10000u}) {
        setup(scale);invoke(timing::taskHandler);
        const unsigned ticks=(4*scale+999)/1000;
        if(ram[task+8]!=1||load<uint16_t>(ram.data(),task+0xc)!=ticks-1)
            std::fprintf(stderr,"owned scale=%u state=%u taskTTL=%u slot0=%u/%u slot1=%u/%u\n",scale,ram[task+8],load<uint16_t>(ram.data(),task+0xc),load<uint16_t>(ram.data(),slots),load<uint16_t>(ram.data(),slots+6),load<uint16_t>(ram.data(),slots+0x8c),load<uint16_t>(ram.data(),slots+0x8c+6));
        check(ram[task+8]==1&&load<uint16_t>(ram.data(),task+0xc)==ticks-1,"Original task timer extends once for all lines");
        check(load<uint16_t>(ram.data(),slots+6)==ticks&&load<uint16_t>(ram.data(),slots+0x8c+6)==ticks,
              "Every original allocated line receives the same extended duration");
        invoke(update);
        for(unsigned tick=1;tick<ticks;++tick) { invoke(timing::taskHandler);invoke(update); }
        check(ram[task+8]==2&&load<uint16_t>(ram.data(),slots)==0&&load<uint16_t>(ram.data(),slots+0x8c)==0,
              "Original task and queue expiration stay aligned at the selected multiplier");
        invoke(timing::taskHandler);check(taskFrees==1,"Original task cleanup remains active");
    }
    setup(2000,1,4,2);invoke(timing::taskHandler);invoke(timing::taskHandler);
    check(load<uint16_t>(ram.data(),task+0xc)==4&&load<uint16_t>(ram.data(),slots)==0,"Original start delay does not scale");
    invoke(timing::taskHandler);check(load<uint16_t>(ram.data(),task+0xc)==7,"Message scales only after its original delay");
    setup(2000);const auto resumes=invoke(timing::taskHandler,true);
    check(resumes>1&&load<uint16_t>(ram.data(),task+0xc)==7,"Actual guest preemption preserves timer provenance");
    setup(2000,1,4,0,2);invoke(timing::taskHandler);
    check(load<uint16_t>(ram.data(),task+0xc)==7&&load<uint16_t>(ram.data(),slots+6)==8,"System-string bank uses the same verified timing task");
    check(std::strcmp((char*)ram.data()+slots+12,"Examine system message")==0,"System-string callback supplies actual queued text");
    setup(10000,1,32760);invoke(timing::taskHandler);
    check(load<uint16_t>(ram.data(),task+0xc)==32766&&load<uint16_t>(ram.data(),slots+6)==32767,"Signed guest timer saturation avoids overflow");
    setup(2000);store<uint32_t>(ram.data(),timing::wrapperReturn-8,0);invoke(timing::taskHandler);
    check(load<uint16_t>(ram.data(),task+0xc)==3&&load<uint16_t>(ram.data(),slots+6)==4,"Unverified producer instructions leave timing unchanged");
    setup(2000);invoke(timing::taskHandler);ram[cancel]=ram[cancelInput]=1;invoke(timing::taskHandler);
    check(taskFrees==1&&load<uint16_t>(ram.data(),slots)==0&&load<uint16_t>(ram.data(),slots+0x8c)==0,
          "Original cancellation clears extended lines and frees the task");
    setup(2000);originalAllocator=allocateStub;rejectAllocation=true;invoke(timing::taskHandler);rejectAllocation=false;
    check(load<uint16_t>(ram.data(),task+0xc)==3,"Rejected allocations do not extend an invisible task");
}
#endif
int main() try {
    using namespace reo::subtitles;namespace timing=reo::message_timing;
    configureEnvironment(nullptr);
    check(timing::parseScale(nullptr)==1000,"No mod retains original duration");
    for(const char* bad:{"","999","10001","-1500","1.5","1500 "," 1500","1e3","999999999999999999999"}) {
        bool rejected=false;try { (void)timing::parseScale(bad); } catch(const std::runtime_error&) { rejected=true; }
        check(rejected,"Invalid native timing configuration rejected");
    }
    configureEnvironment("1500");timing::initialize();check(timing::scale==1500,"Mod environment initializes native duration policy");
    configureEnvironment(nullptr);timing::initialize();check(timing::scale==1000,"Missing mod configuration resets timing default");
    timing::scale=1500;check(timing::duration(3)==5,"Fractional tick durations round upward");
    timing::scale=10000;check(timing::duration(32767)==32767,"Native multiplier saturates signed timers");
    check(timing::duration(0)==0&&timing::duration(65535)==65535,"Zero and signed sentinel durations are preserved");
    PS2Runtime runtime;runtime.functions[allocator]=allocateStub;runtime.functions[allocator+0x64]=allocateStub;
    runtime.functions[drawLeaf]=drawStub;install(runtime);timing::scale=2000;
    std::vector<uint8_t> ram(PS2_RAM_SIZE);constexpr uint32_t sp=0x10000,task=0x20000;
    auto frame=[&](uint32_t source=timing::queueReturns[0],uint32_t ticks=4) {
        ram.assign(PS2_RAM_SIZE,0);requestedTicks=uint16_t(ticks);nextSlot=slots;
        store<uint32_t>(ram.data(),timing::timingFrontReturn-8,0x0c000000|(timing::timingAllocator>>2));
        store<uint32_t>(ram.data(),sp+0x60,source);store<uint32_t>(ram.data(),source-8,0x0c000000|(timing::timingFront>>2));
        store<uint32_t>(ram.data(),sp+0xd0,timing::scriptReturn);store<uint32_t>(ram.data(),timing::scriptReturn-8,0x0c000000|(timing::script>>2));
        store<uint32_t>(ram.data(),sp+0x100,timing::wrapperReturn);store<uint32_t>(ram.data(),timing::wrapperReturn-8,0x0c000000|(timing::wrapper>>2));
        store<uint32_t>(ram.data(),timing::taskDurationLoad,0x8608000c);store<uint32_t>(ram.data(),timing::taskDurationStore,0xa603000c);
        store<uint32_t>(ram.data(),sp+0xe0,task);store<uint32_t>(ram.data(),sp+0x120,ticks);store<uint16_t>(ram.data(),task+0xc,ticks);
    };
    auto invoke=[&](bool preempt=false) {
        R5900Context c;c.pc=allocator;SET_GPR_U32(&c,29,sp);SET_GPR_U32(&c,31,timing::timingFrontReturn);
        yieldAllocation=preempt;runtime.lookupFunction(c.pc)(ram.data(),&c,&runtime);
        if(preempt) { check(c.pc==allocator+0x64,"Allocation yields before timing changes");runtime.lookupFunction(c.pc)(ram.data(),&c,&runtime); }
        check(c.pc==timing::timingFrontReturn,"Timing preserves original guest return");
    };
    frame();invoke(true);check(load<uint16_t>(ram.data(),slots+6)==8&&load<uint16_t>(ram.data(),task+0xc)==8,"Successful allocation scales both timers after resume");
    nextSlot+=0x8c;invoke();check(load<uint16_t>(ram.data(),slots+0x8c+6)==8&&load<uint16_t>(ram.data(),task+0xc)==8,"Multiple lines never compound the task multiplier");
    frame();timing::scale=1000;invoke();check(load<uint16_t>(ram.data(),slots+6)==4&&load<uint16_t>(ram.data(),task+0xc)==4,"Unmodded timing remains unchanged");timing::scale=2000;
    auto expected=ram;store<uint16_t>(expected.data(),slots+6,8);store<uint16_t>(expected.data(),task+0xc,8);
    frame();invoke();check(ram==expected,"Full guest RAM differs only at the task and allocated-line timers");
    frame(spokenReturns[0]);invoke();check(load<uint16_t>(ram.data(),slots+6)==4&&load<uint16_t>(ram.data(),task+0xc)==4,"Spoken producers keep their original timing");
    frame(0x123456);invoke();check(load<uint16_t>(ram.data(),slots+6)==4,"Unrelated menus and choices keep their original timing");
    for(uint32_t pc:{timing::queueReturns[0]-8,timing::scriptReturn-8,timing::wrapperReturn-8,timing::taskDurationLoad,timing::taskDurationStore}) {
        frame();store<uint32_t>(ram.data(),pc,0);invoke();check(load<uint16_t>(ram.data(),task+0xc)==4,"Every original callsite witness is required");
    }
    frame();rejectAllocation=true;invoke();rejectAllocation=false;check(load<uint16_t>(ram.data(),task+0xc)==4,"Failed allocation leaves original task timer intact");
    frame();ram[task+8]=1;invoke();check(load<uint16_t>(ram.data(),task+0xc)==4,"An already-running task is not scaled again");
    frame();store<uint16_t>(ram.data(),task+0x10,1);invoke();check(load<uint16_t>(ram.data(),task+0xc)==4,"Unexpected delayed task provenance is rejected");
    for(uint32_t ticks:{0u,0xffffffffu}) { frame(timing::queueReturns[0],ticks);invoke();check(load<uint16_t>(ram.data(),task+0xc)==uint16_t(ticks),"Nonpositive task durations are not extended"); }
    frame();check(!timing::request(ram.data(),timing::timingFrontReturn,PS2_RAM_SIZE-8).task,"Truncated guest stack rejected");
    store<uint32_t>(ram.data(),sp+0xe0,PS2_RAM_SIZE-8);check(!timing::request(ram.data(),timing::timingFrontReturn,sp).task,"Truncated task record rejected");
#ifdef REO_GENERATED_QUEUE
    ownedChecks();
#endif
    std::printf("PASS %u message timing checks\n",checks);return 0;
} catch(const std::exception& error) { std::fprintf(stderr,"FAIL: %s\n",error.what());return 1; }
