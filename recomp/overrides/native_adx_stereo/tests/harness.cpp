#include "../runtime_adapter.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_stubs.h"
#include <bit>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <new>
#include <string>

thread_local int fail_allocation=-1;
[[gnu::noinline]] void* operator new(std::size_t n){if(fail_allocation>=0&&fail_allocation--==0)throw std::bad_alloc();if(auto* p=std::malloc(n?n:1))return p;throw std::bad_alloc();}
[[gnu::noinline]] void operator delete(void* p)noexcept{std::free(p);}
[[gnu::noinline]] void operator delete(void* p,std::size_t)noexcept{std::free(p);}
[[gnu::noinline]] void* operator new[](std::size_t n){return ::operator new(n);}
[[gnu::noinline]] void operator delete[](void* p)noexcept{::operator delete(p);}
[[gnu::noinline]] void operator delete[](void* p,std::size_t)noexcept{::operator delete(p);}

#define CHECK(x) do{if(!(x))throw std::runtime_error(#x);}while(false)
constexpr std::uint32_t normal_entry=0x127C80,downmix_entry=0x1278B8,input=0x400000,left_output=0x410000,
    right_output=0x420000,left_history=0x430000,right_history=0x430004,key=0x440000,sp=0x701000;
unsigned checks{},fallbacks{};R5900Context expected_context;
std::vector<std::uint8_t> expected_ram;
std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime* p)noexcept{return p?p->depth:0;}
void original(std::uint8_t* ram,R5900Context* c,PS2Runtime* p){
    CHECK(p->depth>=1);CHECK(*c==expected_context);CHECK(std::memcmp(ram,expected_ram.data(),PS2_RAM_SIZE)==0);
    ++fallbacks;SET_GPR_S32(c,2,0x13579);c->pc=GPR_U32(c,31);
}
void sub_00127C80_0x127c80(std::uint8_t* ram,R5900Context* c,PS2Runtime* p){original(ram,c,p);}
void sub_001278B8_0x1278b8(std::uint8_t* ram,R5900Context* c,PS2Runtime* p){original(ram,c,p);}
void different(std::uint8_t*,R5900Context*,PS2Runtime*){}
std::uint64_t extended(std::int32_t v){return static_cast<std::uint64_t>(static_cast<std::int64_t>(v));}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T v){std::memcpy(p+at,&v,sizeof(v));}
template<class T>T read(std::istream& in){T v;in.read(reinterpret_cast<char*>(&v),sizeof(v));CHECK(in.good());return v;}
R5900Context context(bool downmix=false){
    R5900Context c;
    for(unsigned i=0;i<32;++i)c.r[i]={0x1122334400000000ULL+i,0x9988776600000000ULL+i};
    for(unsigned i=0;i<c.unrelated.size();++i)c.unrelated[i]=0x56780000+i;
    c.r[4].low=input;c.r[5].low=2;c.r[6].low=left_output;c.r[7].low=left_history;
    c.r[8].low=right_output;c.r[9].low=right_history;c.r[10].low=4096;c.r[11].low=0;
    c.r[29].low=sp;c.r[31].low=0x120000;c.pc=downmix?downmix_entry:normal_entry;c.branch_pc=0xDEAD1234;
    return c;
}
void seed(PS2Runtime& r){auto* ram=r.memory().getRDRAM();std::memset(ram+input,0,36*8);
    std::memset(ram+left_output,0xA5,64*8);std::memset(ram+right_output,0xA5,64*8);
    std::memset(ram+sp-112,0xD3,112);std::memset(ram+sp,0xE7,18);
    put<std::int16_t>(ram,left_history,1234);put<std::int16_t>(ram,left_history+2,-5678);
    put<std::int16_t>(ram,right_history,-321);put<std::int16_t>(ram,right_history+2,987);
    put<std::uint16_t>(ram,key,23456);put(ram,sp,key);put<std::int16_t>(ram,sp+8,7);put<std::int16_t>(ram,sp+16,-9);
}
void identity(PS2Runtime& r,const char* path){std::ifstream in(path,std::ios::binary);CHECK(in.good());
    while(in.peek()!=EOF){auto at=read<std::uint32_t>(in),bytes=read<std::uint32_t>(in);CHECK(at+bytes<PS2_RAM_SIZE);
        in.read(reinterpret_cast<char*>(r.memory().getRDRAM()+at),bytes);CHECK(in.good());}
    r.functions[normal_entry]=sub_00127C80_0x127c80;r.functions[downmix_entry]=sub_001278B8_0x1278b8;
}
void fallback(PS2Runtime& r,R5900Context c,int allocation=-1,bool guest=true,PS2Runtime::RecompiledFunction f=nullptr,std::uint8_t* memory=nullptr){
    auto* ram=memory?memory:r.memory().getRDRAM();expected_context=c;expected_ram.assign(ram,ram+PS2_RAM_SIZE);const auto before=fallbacks;
    if(!f)f=r.lookupFunction(c.pc==downmix_entry?downmix_entry:normal_entry);
    fail_allocation=allocation;
    try{if(guest){PS2Runtime::GuestExecutionScope scope(&r);f(ram,&c,&r);}else f(ram,&c,&r);}
    catch(...){fail_allocation=-1;throw;}
    fail_allocation=-1;CHECK(fallbacks==before+1);CHECK(GPR_U32(&c,2)==0x13579);++checks;
}
struct Expected {
    std::int32_t result{};std::array<std::int16_t,4> history{};std::uint16_t key_value{};
    std::vector<std::int16_t> left,right;std::uint32_t completed_pairs{};
    std::array<std::uint8_t,112> original_frame{};bool has_original_frame{};
    std::uint32_t original_pc{},original_branch_pc{};
};
void success(PS2Runtime& r,R5900Context c,const Expected& e){
    auto want=r.memory().bytes;auto* dst=want.data();const bool downmix=c.pc==downmix_entry;
    const auto frame=GPR_U32(&c,29)-112;
    if(e.has_original_frame) {
        // Actual original-word final bytes, including untouched holes. No native
        // frame algorithm or pointer relocation supplies fixture expectations.
        std::memcpy(dst+frame,e.original_frame.data(),e.original_frame.size());
    } else {
        // Manual trace/failure-reuse scenarios use this independently read static
        // store contract; the166fixturecases above use original-word bytes only.
        for(unsigned i=0;i<9;++i){const auto reg=i==8?30:16+i;put(dst,frame+0x20+8*i,c.r[reg].low);}
        const auto load_half=[&](std::uint32_t at){std::int16_t v;std::memcpy(&v,dst+at,2);return static_cast<std::uint32_t>(static_cast<std::int32_t>(v));};
        const std::array<std::uint32_t,7> actual_locals{GPR_U32(&c,5),GPR_U32(&c,7),GPR_U32(&c,9),load_half(sp+8),load_half(sp+16),
            downmix?GPR_U32(&c,5)/2:e.completed_pairs,GPR_U32(&c,5)/2};
        for(unsigned i=0;i<(downmix?6u:7u);++i)put(dst,frame+4*i,actual_locals[i]);
    }
    if(!e.left.empty())std::memcpy(dst+GPR_U32(&c,6),e.left.data(),e.left.size()*2);
    if(!e.right.empty())std::memcpy(dst+GPR_U32(&c,8),e.right.data(),e.right.size()*2);
    put(dst,GPR_U32(&c,7),e.history[0]);put(dst,GPR_U32(&c,7)+2,e.history[1]);
    put(dst,GPR_U32(&c,9),e.history[2]);put(dst,GPR_U32(&c,9)+2,e.history[3]);put(dst,key,e.key_value);
    auto expected=c;SET_GPR_S32(&expected,2,e.result);expected.pc=GPR_U32(&c,31);expected.branch_pc=downmix?0x127C74:0x127FC0;
    if(e.has_original_frame){expected.pc=e.original_pc;expected.branch_pc=e.original_branch_pc;}
    const auto before=fallbacks;{PS2Runtime::GuestExecutionScope scope(&r);r.lookupFunction(c.pc)(r.memory().getRDRAM(),&c,&r);}
    CHECK(fallbacks==before);CHECK(c==expected);CHECK(r.memory().bytes==want);++checks;
}
void fixture_cases(PS2Runtime& r,const char* path){std::ifstream in(path,std::ios::binary);CHECK(in.good());auto cases=read<std::uint32_t>(in);
    for(unsigned i=0;i<cases;++i){seed(r);const auto mode=read<std::uint32_t>(in);auto c=context(mode!=0);auto* ram=r.memory().getRDRAM();
        c.r[5].low=extended(read<std::int32_t>(in));
        for(auto at:{left_history,left_history+2,right_history,right_history+2})put(ram,at,static_cast<std::int16_t>(read<std::int32_t>(in)));
        c.r[10].low=extended(read<std::int32_t>(in));c.r[11].low=extended(read<std::int32_t>(in));
        put(ram,key,static_cast<std::uint16_t>(read<std::uint32_t>(in)));put(ram,sp+8,static_cast<std::int16_t>(read<std::int32_t>(in)));
        put(ram,sp+16,static_cast<std::int16_t>(read<std::int32_t>(in)));
        auto bytes=read<std::uint32_t>(in);CHECK(bytes<=36*8);in.read(reinterpret_cast<char*>(ram+input),bytes);CHECK(in.good());
        CHECK(read<std::uint32_t>(in)==sp);c.r[31].low=read<std::uint32_t>(in);
        in.read(reinterpret_cast<char*>(ram+sp-112),112);in.read(reinterpret_cast<char*>(ram+sp),24);CHECK(in.good());
        for(unsigned reg:{16u,17u,18u,19u,20u,21u,22u,23u,30u})c.r[reg].low=read<std::uint64_t>(in);
        Expected e;e.result=read<std::int32_t>(in);for(auto& h:e.history)h=static_cast<std::int16_t>(read<std::int32_t>(in));
        e.key_value=static_cast<std::uint16_t>(read<std::uint32_t>(in));e.completed_pairs=read<std::uint32_t>(in);
        const auto count=read<std::uint32_t>(in);CHECK(count<=32*8);e.left.resize(count);e.right.resize(count);
        in.read(reinterpret_cast<char*>(e.left.data()),count*2);in.read(reinterpret_cast<char*>(e.right.data()),count*2);CHECK(in.good());
        e.has_original_frame=true;in.read(reinterpret_cast<char*>(e.original_frame.data()),112);CHECK(in.good());
        e.original_pc=read<std::uint32_t>(in);e.original_branch_pc=read<std::uint32_t>(in);
        success(r,c,e);
    }
    CHECK(in.peek()==EOF);std::cout<<"oracle cases="<<cases<<'\n';
}
int main(int argc,char** argv){try{
    CHECK(argc==4);const std::string scenario=argv[3];PS2Runtime r;identity(r,argv[1]);seed(r);
    _putenv_s("REO_NATIVE_ADX_STEREO",scenario=="off"?"0":"1");
    _putenv_s("REO_NATIVE_ADX_STEREO_TRACE",scenario=="trace"||scenario=="refusals"?"1":"0");
    if(scenario=="off"||scenario=="disabled"){CHECK(!reo_native_adx_stereo::install(r));CHECK(r.workers.empty());return 0;}
    if(scenario=="text"||scenario=="downmix-text"||scenario=="table"){
        r.memory().bytes[scenario=="table"?0x239BE8:(scenario=="text"?normal_entry:downmix_entry)]^=1;
        CHECK(!reo_native_adx_stereo::install(r));CHECK(r.workers.empty());return 0;}
    if(scenario=="missing"||scenario=="missing-normal"||scenario=="wrong-binding"||scenario=="wrong-downmix"){
        if(scenario=="missing"||scenario=="missing-normal")r.functions.erase(scenario=="missing"?downmix_entry:normal_entry);
        else r.functions[scenario=="wrong-binding"?normal_entry:downmix_entry]=different;
        CHECK(!reo_native_adx_stereo::install(r));CHECK(r.workers.empty());return 0;}
    if(scenario=="late"){r.started=true;CHECK(!reo_native_adx_stereo::install(r));return 0;}
    if(scenario.starts_with("partial-")){
        if(scenario=="partial-runtime1")r.throw_on_publish=1;
        if(scenario=="partial-runtime2")r.throw_on_publish=2;
        if(scenario=="partial-stub1")ps2_stubs::throw_on_registration=1;
        if(scenario=="partial-stub2")ps2_stubs::throw_on_registration=2;
        CHECK(!reo_native_adx_stereo::install(r));fallback(r,context());fallback(r,context(true));
        CHECK(!reo_native_adx_stereo::install(r));return 0;
    }
    CHECK(reo_native_adx_stereo::install(r));CHECK(reo_native_adx_stereo::install(r));CHECK(r.workers.size()==1);
    if(scenario=="fixtures")fixture_cases(r,argv[2]);
    else if(scenario=="trace")for(bool downmix:{false,true})for(unsigned i=0;i<20;++i){seed(r);r.memory().bytes[input]=0x80;success(r,context(downmix),{0,{1234,-5678,-321,987},23456,{},{},0});}
    else if(scenario=="allocation")for(bool downmix:{false,true})for(int n:{0,1}){seed(r);fallback(r,context(downmix),n);seed(r);r.memory().bytes[input]=0x80;success(r,context(downmix),{0,{1234,-5678,-321,987},23456,{},{},0});}
    else if(scenario=="changed-identity"||scenario=="changed-normal"||scenario=="changed-table"){
        r.memory().bytes[scenario=="changed-table"?0x239BE8:(scenario=="changed-normal"?normal_entry:downmix_entry)]^=1;fallback(r,context());fallback(r,context(true));}
    else if(scenario=="stop"){r.requestStop();fallback(r,context());fallback(r,context(true));CHECK(!reo_native_adx_stereo::install(r));}
    else if(scenario=="manual"){fallback(r,context(),-1,false);fallback(r,context(true),-1,false);}
    else if(scenario=="binding-change"){
        const auto f=r.lookupFunction(normal_entry),g=r.lookupFunction(downmix_entry);r.functions[downmix_entry]=different;
        fallback(r,context(),-1,true,f);fallback(r,context(true),-1,true,g);}
    else if(scenario=="runtime-identity"){
        PS2Runtime other;identity(other,argv[1]);seed(other);CHECK(!reo_native_adx_stereo::install(other));
        fallback(other,context(),-1,true,r.lookupFunction(normal_entry));}
    else if(scenario=="memory-identity"){
        PS2Runtime other;identity(other,argv[1]);seed(other);fallback(r,context(),-1,true,nullptr,other.memory().getRDRAM());}
    else if(scenario=="refusals")for(bool downmix:{false,true}){
        for(unsigned reg:{4u,5u,6u,7u,8u,9u,10u,11u,29u,31u}){auto c=context(downmix);c.r[reg].low|=1ULL<<32;fallback(r,c);}
        for(std::int32_t n:{0,-1,513}){auto c=context(downmix);c.r[5].low=extended(n);fallback(r,c);}
        for(unsigned reg:{10u,11u})for(std::int32_t n:{32768,-32769}){auto c=context(downmix);c.r[reg].low=extended(n);fallback(r,c);}
        for(unsigned reg:{4u,6u,7u,8u,9u})for(auto at:{0u,0xFFFFFFFEu,PS2_RAM_SIZE-1,input+1}){auto c=context(downmix);c.r[reg].low=at;fallback(r,c);}
        for(auto at:{0u,PS2_RAM_SIZE-1,input+1}){seed(r);put(r.memory().getRDRAM(),sp,at);fallback(r,context(downmix));}seed(r);
        for(auto at:{input,left_output,right_output,left_history,right_history,sp-112,sp,normal_entry,downmix_entry,0x239BE8u}){
            seed(r);put(r.memory().getRDRAM(),sp,at);fallback(r,context(downmix));}seed(r);
        for(auto at:{0u,96u,sp+8,PS2_RAM_SIZE-16}){auto c=context(downmix);c.r[29].low=at;fallback(r,c);}
        for(auto at:{0u,0x120001u,PS2_RAM_SIZE,normal_entry,downmix_entry,input,left_output,right_output,sp-112,0x239BE8u}){auto c=context(downmix);c.r[31].low=at;fallback(r,c);}
        auto c=context(downmix);c.in_delay_slot=true;fallback(r,c);c=context(downmix);c.pc+=4;fallback(r,c);
        for(unsigned a:{4u,6u,7u,8u,9u})for(unsigned b:{4u,6u,7u,8u,9u})if(a!=b){c=context(downmix);c.r[a].low=c.r[b].low;fallback(r,c);}
        for(unsigned reg:{4u,6u,7u,8u,9u})for(auto at:{key,sp-112,sp,normal_entry,downmix_entry,0x239BE8u}){c=context(downmix);c.r[reg].low=at;fallback(r,c);}
    }else throw std::runtime_error("unknown scenario");
    std::cout<<scenario<<": "<<checks<<" full-RAM/context checks passed\n";return 0;
}catch(const std::exception& e){fail_allocation=-1;std::cerr<<e.what()<<'\n';return 1;}}
