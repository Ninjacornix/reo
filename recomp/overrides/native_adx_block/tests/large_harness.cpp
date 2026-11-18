#if defined(LARGE_STEREO)
#include "recomp/overrides/native_adx_stereo/runtime_adapter.h"
#else
#include "recomp/overrides/native_adx_block/runtime_adapter.h"
#endif
#include <ps2_runtime.h>
#include <ps2_runtime_macros.h>
#include <ps2_stubs.h>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#define CHECK(x) do{if(!(x))throw std::runtime_error(#x);}while(false)
std::vector<std::uint8_t> expected_ram;
R5900Context expected_context;
unsigned fallbacks{},accepted{},refused{},range_checks{};
std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime* p)noexcept{return p?p->depth:0;}
void original(std::uint8_t* ram,R5900Context* c,PS2Runtime* r){
    CHECK(r->depth>=1);CHECK(*c==expected_context);CHECK(std::memcmp(ram,expected_ram.data(),PS2_RAM_SIZE)==0);
    ++fallbacks;SET_GPR_S32(c,2,0x13579);c->pc=GPR_U32(c,31);
}
void sub_001276D8_0x1276d8(std::uint8_t* ram,R5900Context* c,PS2Runtime* r){original(ram,c,r);}
void sub_00127C80_0x127c80(std::uint8_t* ram,R5900Context* c,PS2Runtime* r){original(ram,c,r);}
void sub_001278B8_0x1278b8(std::uint8_t* ram,R5900Context* c,PS2Runtime* r){original(ram,c,r);}
template<class T>T read(std::istream& in){T v;in.read(reinterpret_cast<char*>(&v),sizeof(v));CHECK(in.good());return v;}
template<class T>void put(std::uint8_t* ram,std::uint32_t at,T v){std::memcpy(ram+at,&v,sizeof(v));}
void segments(std::istream& in,std::uint8_t* ram){
    const auto count=read<std::uint32_t>(in);CHECK(count<=16);
    for(unsigned i=0;i<count;++i){const auto at=read<std::uint32_t>(in),size=read<std::uint32_t>(in);
        CHECK(size<=65536);CHECK(std::uint64_t(at)+size<=PS2_RAM_SIZE);
        in.read(reinterpret_cast<char*>(ram+at),size);CHECK(in.good());}
}
void fallback(PS2Runtime& runtime,R5900Context c){
    expected_context=c;expected_ram=runtime.memory().bytes;
    const auto before=fallbacks;
    {PS2Runtime::GuestExecutionScope scope(&runtime);runtime.lookupFunction(c.pc)(runtime.memory().getRDRAM(),&c,&runtime);}
    CHECK(fallbacks==before+1);CHECK(GPR_U32(&c,2)==0x13579);++refused;
}
int main(int argc,char** argv){try{
    CHECK(argc==3);PS2Runtime runtime;
    std::ifstream identities(argv[1],std::ios::binary);CHECK(identities.good());
    auto identity=runtime.memory().bytes;segments(identities,identity.data());CHECK(identities.peek()==EOF);
    runtime.memory().bytes=identity;
#if defined(LARGE_STEREO)
    runtime.functions[0x127C80]=sub_00127C80_0x127c80;runtime.functions[0x1278B8]=sub_001278B8_0x1278b8;
    _putenv_s("REO_NATIVE_ADX_STEREO","1");_putenv_s("REO_NATIVE_ADX_STEREO_TRACE","0");
    CHECK(reo_native_adx_stereo::install(runtime));
#else
    runtime.functions[0x1276D8]=sub_001276D8_0x1276d8;
    _putenv_s("REO_NATIVE_ADX_BLOCK","1");_putenv_s("REO_NATIVE_ADX_BLOCK_TRACE","0");
    CHECK(reo_native_adx_block::install(runtime));
#endif
    std::ifstream in(argv[2],std::ios::binary);CHECK(in.good());const auto cases=read<std::uint32_t>(in);
    for(unsigned row=0;row<cases;++row){
        runtime.memory().bytes=identity;auto* ram=runtime.memory().getRDRAM();
        const bool admitted=read<std::uint32_t>(in)!=0;R5900Context context;
        for(unsigned n=0;n<32;++n){context.r[n].low=read<std::uint64_t>(in);context.r[n].high=0x8877665500000000ULL+n;}
        for(unsigned n=0;n<context.unrelated.size();++n)context.unrelated[n]=0x1234567800000000ULL+n;
        context.pc=read<std::uint32_t>(in);context.branch_pc=0xDEAD1234;
        segments(in,ram);auto want=runtime.memory().bytes;segments(in,want.data());
        const auto result=read<std::int32_t>(in);const auto pc=read<std::uint32_t>(in),branch=read<std::uint32_t>(in);
        if(!admitted){CHECK(GPR_U32(&context,5)==513);fallback(runtime,context);continue;}
        auto expected=context;SET_GPR_S32(&expected,2,result);expected.pc=pc;expected.branch_pc=branch;
        const auto before=fallbacks;
        {PS2Runtime::GuestExecutionScope scope(&runtime);runtime.lookupFunction(context.pc)(ram,&context,&runtime);}
        CHECK(fallbacks==before);CHECK(context==expected);CHECK(runtime.memory().bytes==want);++accepted;
        if(GPR_U32(&context,5)==512){
            // Reuse the actual large invocation with an inadmissible expanded
            // extent/alias. Original is called once before RAM/context effects.
            for(unsigned variant=0;variant<4;++variant){auto c=expected_context=context;
                c.pc=branch==0x1278AC?0x1276D8:branch==0x127FC0?0x127C80:0x1278B8;
                if(variant==0)c.r[4].low=PS2_RAM_SIZE-18;
                if(variant==1)c.r[6].low=PS2_RAM_SIZE-64;
                if(variant==2)c.r[7].low=GPR_U32(&c,6)+8192;
#if defined(LARGE_STEREO)
                if(variant==3)put(ram,GPR_U32(&c,29),GPR_U32(&c,4)+4096);
#else
                if(variant==3)c.r[10].low=GPR_U32(&c,4)+4096;
#endif
                fallback(runtime,c);++range_checks;
            }
        }
    }
    CHECK(in.peek()==EOF);
    std::cout<<"accepted="<<accepted<<" refused="<<refused<<" expanded_range_checks="<<range_checks<<'\n';
    return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
