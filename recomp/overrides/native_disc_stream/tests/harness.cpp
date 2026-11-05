#include "../runtime_adapter.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_stubs.h"
#include <bit>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#define CHECK(x) do{if(!(x))throw std::runtime_error(#x);}while(false)
constexpr std::array<std::uint32_t,4> entries{0x139C30,0x139CC8,0x139FA8,0x139FE8};
constexpr std::array<std::uint32_t,4> branches{0x139CBC,0x139CF8,0x139FD8,0x13A02C};
constexpr std::uint32_t slot=0x21CC60+39*0x48,busy=0x207934;
unsigned fallbacks{};
R5900Context expected_context{};
std::vector<std::uint8_t> expected_memory;
void original(std::uint8_t* ram,R5900Context* context,PS2Runtime* runtime) {
    CHECK(runtime->depth==1);
    CHECK(*context==expected_context);
    CHECK(std::memcmp(ram,expected_memory.data(),PS2_RAM_SIZE)==0);
    ++fallbacks;
    SET_GPR_S32(context,2,0x13579);
    context->pc=GPR_U32(context,31);
}
std::uint64_t extended(std::uint32_t v){return static_cast<std::uint64_t>(static_cast<std::int64_t>(std::bit_cast<std::int32_t>(v)));}
void put(std::uint8_t* p,std::uint32_t at,std::uint32_t v){std::memcpy(p+at,&v,4);}
R5900Context call_context(unsigned which) {
    R5900Context c{};
    for(unsigned i=0;i<32;++i){c.r[i].low=0x11110000+i;c.r[i].high=0xABCD000000000000ULL+i;}
    for(unsigned i=0;i<c.preserved.size();++i)c.preserved[i]=0x56780000+i;
    c.r[4].low=slot;c.r[5].low=7;c.r[6].low=0;c.r[29].low=0x1F00000;c.r[31].low=0x120000;
    c.pc=entries[which];c.branch_pc=0xDEAD1234;
    return c;
}
void seed(std::uint8_t* ram,unsigned state=1) {
    std::memset(ram+slot,0x5A,0x48);ram[slot]=1;ram[slot+2]=static_cast<std::uint8_t>(state);
    put(ram,slot+8,20);put(ram,slot+12,3);put(ram,slot+20,0x100001);put(ram,slot+28,0);
    put(ram,busy,0);
}
void load_identity(PS2Runtime& runtime,const char* path) {
    std::ifstream in(path,std::ios::binary);CHECK(in.good());
    while(in.peek()!=EOF) {
        std::uint32_t pc{},bytes{};in.read(reinterpret_cast<char*>(&pc),4);in.read(reinterpret_cast<char*>(&bytes),4);
        CHECK(in.good()&&std::uint64_t(pc)+bytes<=PS2_RAM_SIZE);
        in.read(reinterpret_cast<char*>(runtime.memory().getRDRAM()+pc),bytes);CHECK(in.good());
    }
    for(auto pc:entries)runtime.functions[pc]=original;
}
void fallback(PS2Runtime& runtime,unsigned which,R5900Context c,std::uint8_t* ram=nullptr) {
    if(!ram)ram=runtime.memory().getRDRAM();
    expected_context=c;expected_memory.assign(ram,ram+PS2_RAM_SIZE);
    const auto count=fallbacks;
    runtime.lookupFunction(entries[which])(ram,&c,&runtime);
    CHECK(fallbacks==count+1&&GPR_U32(&c,2)==0x13579);
}
void success(PS2Runtime& runtime,unsigned which,R5900Context c,std::int32_t result) {
    auto* ram=runtime.memory().getRDRAM();
    auto want=runtime.memory().bytes;
    const auto saved=c.r[31].low;
    std::memcpy(want.data()+GPR_U32(&c,29)-16,&saved,8);
    if(which==0){put(want.data(),slot+12,static_cast<std::uint32_t>(result));put(want.data(),slot+20,0);}
    auto context=c;SET_GPR_S32(&context,2,result);context.pc=GPR_U32(&c,31);context.branch_pc=branches[which];
    const auto count=fallbacks;
    runtime.lookupFunction(entries[which])(ram,&c,&runtime);
    CHECK(fallbacks==count);
    CHECK(runtime.memory().bytes==want);
    CHECK(c==context);
}
int main(int argc,char** argv) {
    try {
        CHECK(argc==3);
        PS2Runtime runtime;load_identity(runtime,argv[1]);auto* ram=runtime.memory().getRDRAM();seed(ram);
        const std::string scenario=argv[2];
#ifdef _WIN32
        _putenv_s("REO_NATIVE_DISC_STREAM",scenario=="off"?"0":"1");
        _putenv_s("REO_NATIVE_DISC_STREAM_TRACE",
                    scenario=="trace"||scenario=="refusals"||scenario=="off"?"1":"0");
#else
        setenv("REO_NATIVE_DISC_STREAM",scenario=="off"?"0":"1",1);
        setenv("REO_NATIVE_DISC_STREAM_TRACE",
                    scenario=="trace"||scenario=="refusals"||scenario=="off"?"1":"0",1);
#endif
        if(scenario=="off"){CHECK(!reo_native_disc_stream::install(runtime));CHECK(ps2_stubs::overrides.empty());return 0;}
        if(scenario=="identity"){ram[0x139C30]^=1;CHECK(!reo_native_disc_stream::install(runtime));CHECK(ps2_stubs::overrides.empty());return 0;}
        if(scenario=="missing"){runtime.functions.erase(entries[3]);CHECK(!reo_native_disc_stream::install(runtime));CHECK(ps2_stubs::overrides.empty());return 0;}
        if(scenario=="partial"){
            runtime.throw_registration=2;CHECK(!reo_native_disc_stream::install(runtime));
            CHECK(runtime.lookupFunction(entries[0])!=original);fallback(runtime,0,call_context(0));return 0;
        }
        CHECK(reo_native_disc_stream::install(runtime));CHECK(reo_native_disc_stream::install(runtime));
        if(scenario=="operations"||scenario=="trace") {
            for(unsigned state:{0u,1u,3u})for(unsigned which=1;which<4;++which) {
                seed(ram,state);
                success(runtime,which,call_context(which),which==1?3:which==2?static_cast<std::int32_t>(state):
                    state==1?std::bit_cast<std::int32_t>(0x80000800u):0);
            }
            for(const auto& test:std::array<std::array<std::int32_t,3>,7>{{
                {7,0,7},{-7,0,0},{99,0,20},{4,1,7},{-9,1,0},{-3,2,17},{123,7,3}}}) {
                seed(ram);auto c=call_context(0);c.r[5].low=extended(static_cast<std::uint32_t>(test[0]));
                c.r[6].low=extended(static_cast<std::uint32_t>(test[1]));success(runtime,0,c,test[2]);
            }
            seed(ram);auto c=call_context(0);c.r[5].low=0x7FFFFFFF;c.r[6].low=1;success(runtime,0,c,0);
            // Clear/reuse the same slot; no cached FileState is allowed.
            std::memset(ram+slot,0,0x48);seed(ram);put(ram,slot+12,17);success(runtime,1,call_context(1),17);
        } else if(scenario=="refusals") {
            for(unsigned which=0;which<4;++which) {
                seed(ram);auto c=call_context(which);c.r[4].low=0;fallback(runtime,which,c);
                c=call_context(which);c.r[4].low|=1ULL<<32;fallback(runtime,which,c);
                c=call_context(which);c.r[4].low=slot+1;fallback(runtime,which,c);
                c=call_context(which);c.in_delay_slot=true;fallback(runtime,which,c);
                c=call_context(which);c.pc+=4;fallback(runtime,which,c);
                c=call_context(which);c.r[29].low=slot+16;fallback(runtime,which,c);
                c=call_context(which);c.r[31].low=entries[which];fallback(runtime,which,c);
                for(unsigned state:{2u,0xFFu}){seed(ram,state);fallback(runtime,which,call_context(which));}
                seed(ram);put(ram,slot+28,0x21BB88);fallback(runtime,which,call_context(which));
                seed(ram);put(ram,busy,1);fallback(runtime,which,call_context(which));
                seed(ram);ram[slot]=0;fallback(runtime,which,call_context(which));
            }
            seed(ram);auto c=call_context(0);c.r[5].low=0xFFFFFFFFu;fallback(runtime,0,c);
            seed(ram);put(ram,slot+8,0x7FFFFFFF);fallback(runtime,0,call_context(0));
            seed(ram);put(ram,slot+12,21);fallback(runtime,0,call_context(0));
            seed(ram,3);fallback(runtime,0,call_context(0));
        } else if(scenario=="text-change") {
            ram[entries[0]+4]^=1;fallback(runtime,0,call_context(0));
        } else if(scenario=="binding-change") {
            runtime.functions[entries[1]]=original;CHECK(!reo_native_disc_stream::install(runtime));
            fallback(runtime,0,call_context(0));
        } else if(scenario=="runtime-identity") {
            PS2Runtime another;load_identity(another,argv[1]);CHECK(!reo_native_disc_stream::install(another));
            auto replacement=runtime.memory().bytes;runtime.memory().bytes.swap(replacement);
            fallback(runtime,0,call_context(0));
        } else if(scenario=="stop") {
            runtime.stopping=true;fallback(runtime,0,call_context(0));CHECK(!reo_native_disc_stream::install(runtime));
        } else throw std::runtime_error("unknown test scenario");
        std::cout<<scenario<<": PASS fallbacks="<<fallbacks<<"\n";
        return 0;
    } catch(const std::exception& error){std::cerr<<error.what()<<"\n";return 1;}
}
