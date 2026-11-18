#include "../runtime_adapter.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_stubs.h"
#include <atomic>
#include <bit>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <new>
#include <string>

// Probe only a normal core vector allocation, with wrappers kept out of line.
thread_local bool fail_new=false;
[[gnu::noinline]] void* operator new(std::size_t bytes){if(fail_new)throw std::bad_alloc();if(auto* p=std::malloc(bytes?bytes:1))return p;throw std::bad_alloc();}
[[gnu::noinline]] void operator delete(void* p)noexcept{std::free(p);}
[[gnu::noinline]] void operator delete(void* p,std::size_t)noexcept{std::free(p);}
[[gnu::noinline]] void* operator new[](std::size_t bytes){return ::operator new(bytes);}
[[gnu::noinline]] void operator delete[](void* p)noexcept{::operator delete(p);}
[[gnu::noinline]] void operator delete[](void* p,std::size_t)noexcept{::operator delete(p);}

#define CHECK(x) do{if(!(x))throw std::runtime_error(#x);}while(false)
constexpr std::uint32_t entry=0x1276D8,input=0x400000,output=0x410000,history=0x420000,key=0x430000,sp=0x1F00000;
unsigned checks{},fallbacks{};R5900Context expected_context;
std::vector<std::uint8_t> expected_ram;
std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime* p)noexcept{return p?p->depth:0;}
void sub_001276D8_0x1276d8(std::uint8_t* ram,R5900Context* c,PS2Runtime* p){
    CHECK(p->depth>=1);CHECK(*c==expected_context);CHECK(std::memcmp(ram,expected_ram.data(),PS2_RAM_SIZE)==0);
    ++fallbacks;SET_GPR_S32(c,2,0x13579);c->pc=GPR_U32(c,31);
}
void different(std::uint8_t*,R5900Context*,PS2Runtime*){}
std::uint64_t extended(std::int32_t v){return static_cast<std::uint64_t>(static_cast<std::int64_t>(v));}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T value){std::memcpy(p+at,&value,sizeof(value));}
template<class T>T read(std::istream& in){T v;in.read(reinterpret_cast<char*>(&v),sizeof(v));CHECK(in.good());return v;}
R5900Context context(){
    R5900Context c;
    for(unsigned i=0;i<32;++i)c.r[i]={0x1122334400000000ULL+i,0x9988776600000000ULL+i};
    for(unsigned i=0;i<c.unrelated.size();++i)c.unrelated[i]=0x56780000+i;
    c.r[4].low=input;c.r[5].low=1;c.r[6].low=output;c.r[7].low=history;
    c.r[8].low=4096;c.r[9].low=0;c.r[10].low=key;c.r[11].low=7;
    c.r[29].low=sp;c.r[31].low=0x120000;c.pc=entry;c.branch_pc=0xDEAD1234;
    return c;
}
void seed(PS2Runtime& runtime){auto* ram=runtime.memory().getRDRAM();std::memset(ram+input,0,18*16);std::memset(ram+output,0xA5,64*16);
    put<std::int16_t>(ram,history,1234);put<std::int16_t>(ram,history+2,-5678);put<std::uint16_t>(ram,key,23456);put<std::int16_t>(ram,sp,-9);}
void identity(PS2Runtime& r,const char* path){std::ifstream in(path,std::ios::binary);CHECK(in.good());
    while(in.peek()!=EOF){auto at=read<std::uint32_t>(in),bytes=read<std::uint32_t>(in);CHECK(at+bytes<PS2_RAM_SIZE);
        in.read(reinterpret_cast<char*>(r.memory().getRDRAM()+at),bytes);CHECK(in.good());}
    r.functions[entry]=sub_001276D8_0x1276d8;
}
void fallback(PS2Runtime& r,R5900Context c,bool allocation_failure=false,bool guest=true,PS2Runtime::RecompiledFunction f=nullptr,std::uint8_t* memory=nullptr){
    auto* ram=memory?memory:r.memory().getRDRAM();expected_context=c;expected_ram.assign(ram,ram+PS2_RAM_SIZE);auto before=fallbacks;
    if(!f)f=r.lookupFunction(entry);
    fail_new=allocation_failure;
    try{if(guest){PS2Runtime::GuestExecutionScope scope(&r);f(ram,&c,&r);}else f(ram,&c,&r);}
    catch(...){fail_new=false;throw;}
    fail_new=false;CHECK(fallbacks==before+1);CHECK(GPR_U32(&c,2)==0x13579);++checks;
}
void success(PS2Runtime& r,R5900Context c,const std::vector<std::int16_t>& pcm,std::int32_t result,std::int16_t h1,std::int16_t h2,std::uint16_t k){
    auto want=r.memory().bytes;auto* dst=want.data();const auto frame=GPR_U32(&c,29)-80;
    for(unsigned i=0;i<9;++i){const auto reg=i==8?30:16+i;put(dst,frame+8*i,c.r[reg].low);}
    if(!pcm.empty())std::memcpy(dst+GPR_U32(&c,6),pcm.data(),pcm.size()*2);
    put(dst,GPR_U32(&c,7),h1);put(dst,GPR_U32(&c,7)+2,h2);put(dst,GPR_U32(&c,10),k);
    auto expected=c;SET_GPR_S32(&expected,2,result);expected.pc=GPR_U32(&c,31);expected.branch_pc=0x1278AC;
    const auto before=fallbacks;{PS2Runtime::GuestExecutionScope scope(&r);r.lookupFunction(entry)(r.memory().getRDRAM(),&c,&r);}
    CHECK(fallbacks==before);CHECK(c==expected);CHECK(r.memory().bytes==want);++checks;
}
void fixture_cases(PS2Runtime& r,const char* path){std::ifstream in(path,std::ios::binary);CHECK(in.good());auto cases=read<std::uint32_t>(in);
    for(unsigned i=0;i<cases;++i){seed(r);auto c=context();auto* ram=r.memory().getRDRAM();
        c.r[5].low=extended(read<std::int32_t>(in));put(ram,history,static_cast<std::int16_t>(read<std::int32_t>(in)));put(ram,history+2,static_cast<std::int16_t>(read<std::int32_t>(in)));
        c.r[8].low=extended(read<std::int32_t>(in));c.r[9].low=extended(read<std::int32_t>(in));put(ram,key,static_cast<std::uint16_t>(read<std::uint32_t>(in)));
        c.r[11].low=extended(read<std::int32_t>(in));put(ram,sp,static_cast<std::int16_t>(read<std::int32_t>(in)));
        auto bytes=read<std::uint32_t>(in);CHECK(bytes<=18*16);in.read(reinterpret_cast<char*>(ram+input),bytes);CHECK(in.good());
        auto count=read<std::uint32_t>(in);auto result=read<std::int32_t>(in),h1=read<std::int32_t>(in),h2=read<std::int32_t>(in);auto k=read<std::uint32_t>(in);
        CHECK(count<=32*16);std::vector<std::int16_t> pcm(count);in.read(reinterpret_cast<char*>(pcm.data()),count*2);CHECK(in.good());
        success(r,c,pcm,result,static_cast<std::int16_t>(h1),static_cast<std::int16_t>(h2),static_cast<std::uint16_t>(k));
    }
    CHECK(in.peek()==EOF);CHECK(cases==101);
}
int main(int argc,char** argv){try{
    CHECK(argc==4);const std::string scenario=argv[3];PS2Runtime r;identity(r,argv[1]);seed(r);
    _putenv_s("REO_NATIVE_ADX_BLOCK",scenario=="off"?"0":"1");
    _putenv_s("REO_NATIVE_ADX_BLOCK_TRACE",scenario=="trace"||scenario=="refusals"||scenario=="off"?"1":"0");
    if(scenario=="off"||scenario=="disabled"){CHECK(!reo_native_adx_block::install(r));CHECK(r.workers.empty());CHECK(r.lookupFunction(entry)==sub_001276D8_0x1276d8);return 0;}
    if(scenario=="text"||scenario=="table"){r.memory().bytes[scenario=="text"?entry:0x239BE8]^=1;CHECK(!reo_native_adx_block::install(r));CHECK(r.workers.empty());return 0;}
    if(scenario=="missing"||scenario=="wrong-binding"){if(scenario=="missing")r.functions.erase(entry);else r.functions[entry]=different;CHECK(!reo_native_adx_block::install(r));CHECK(r.workers.empty());return 0;}
    if(scenario=="late"){r.started=true;CHECK(!reo_native_adx_block::install(r));CHECK(r.lookupFunction(entry)==sub_001276D8_0x1276d8);return 0;}
    if(scenario=="partial-runtime"||scenario=="partial-stub"){
        r.throw_after_publish=scenario=="partial-runtime";ps2_stubs::throw_registration=scenario=="partial-stub";
        CHECK(!reo_native_adx_block::install(r));CHECK(r.lookupFunction(entry)!=sub_001276D8_0x1276d8);fallback(r,context());CHECK(!reo_native_adx_block::install(r));return 0;
    }
    CHECK(reo_native_adx_block::install(r));CHECK(reo_native_adx_block::install(r));CHECK(r.workers.size()==1);
    if(scenario=="fixtures")fixture_cases(r,argv[2]);
    else if(scenario=="trace")for(unsigned i=0;i<20;++i){seed(r);auto c=context();r.memory().bytes[input]=0x80;success(r,c,{},0,1234,-5678,23456);}
    else if(scenario=="allocation"){fallback(r,context(),true);seed(r);r.memory().bytes[input]=0x80;success(r,context(),{},0,1234,-5678,23456);}
    else if(scenario=="changed-identity"){r.memory().bytes[entry]^=1;fallback(r,context());}
    else if(scenario=="changed-table"){r.memory().bytes[0x239BE8]^=1;fallback(r,context());}
    else if(scenario=="stop"){r.requestStop();fallback(r,context());CHECK(!reo_native_adx_block::install(r));}
    else if(scenario=="manual")fallback(r,context(),false,false);
    else if(scenario=="binding-change"){const auto f=r.lookupFunction(entry);r.functions[entry]=different;fallback(r,context(),false,true,f);}
    else if(scenario=="runtime-identity"){PS2Runtime other;identity(other,argv[1]);seed(other);CHECK(!reo_native_adx_block::install(other));fallback(other,context(),false,true,r.lookupFunction(entry));}
    else if(scenario=="memory-identity"){PS2Runtime other;identity(other,argv[1]);seed(other);fallback(r,context(),false,true,nullptr,other.memory().getRDRAM());}
    else if(scenario=="refusals"){
        for(unsigned n:{4u,5u,6u,7u,8u,9u,10u,11u,29u,31u}){auto c=context();c.r[n].low|=1ULL<<32;fallback(r,c);}
        for(std::int32_t n:{0,-1,513}){auto c=context();c.r[5].low=extended(n);fallback(r,c);}
        for(unsigned reg:{8u,9u,11u})for(std::int32_t n:{32768,-32769}){auto c=context();c.r[reg].low=extended(n);fallback(r,c);}
        for(unsigned reg:{4u,6u,7u,10u})for(std::uint32_t at:{0u,0xFFFFFFFEu,PS2_RAM_SIZE-1,input+1}){auto c=context();c.r[reg].low=at;fallback(r,c);}
        for(std::uint32_t at:{0u,64u,sp+8,PS2_RAM_SIZE}){auto c=context();c.r[29].low=at;fallback(r,c);}
        for(std::uint32_t at:{0u,0x120001u,PS2_RAM_SIZE,entry,input,output,sp-80,0x239BE8u}){auto c=context();c.r[31].low=at;fallback(r,c);}
        auto c=context();c.in_delay_slot=true;fallback(r,c);c=context();c.pc=entry+4;fallback(r,c);
        for(unsigned a:{4u,6u,7u,10u})for(unsigned b:{4u,6u,7u,10u})if(a!=b){c=context();c.r[a].low=c.r[b].low;fallback(r,c);}
        for(unsigned reg:{4u,6u,7u,10u})for(auto at:{sp-80,sp,entry,0x239BE8u}){c=context();c.r[reg].low=at;fallback(r,c);}
        for(auto at:{input+80,output+80,history+80,key+80,0x127730u,0x239C00u}){c=context();c.r[29].low=at;fallback(r,c);}
    }else throw std::runtime_error("Unknown scenario");
    std::cout<<scenario<<": "<<checks<<" full-RAM/context checks passed\n";return 0;
}catch(const std::exception& e){fail_new=false;std::cerr<<e.what()<<'\n';return 1;}}
