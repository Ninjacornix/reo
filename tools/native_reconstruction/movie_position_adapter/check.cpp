#include "recomp/overrides/native_movie_position/runtime_adapter.h"
#include <ps2_runtime.h>
#include <ps2_runtime_macros.h>
#include <ps2_stubs.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#define CHECK(x) do { if(!(x)) throw std::runtime_error(#x); } while(false)
constexpr std::uint32_t entry=0x16F338,caller_return=0x16EDF8;
std::vector<std::uint8_t> expected_ram;
R5900Context expected_context;
unsigned fallbacks=0,accepted=0,refusals=0;
std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime* runtime) noexcept {return runtime?runtime->depth:0;}
void original(std::uint8_t* ram,R5900Context* context,PS2Runtime* runtime) {
    CHECK(runtime->depth>=1);CHECK(*context==expected_context);
    CHECK(std::memcmp(ram,expected_ram.data(),PS2_RAM_SIZE)==0);
    ++fallbacks;SET_GPR_S32(context,2,0x13579);context->pc=GPR_U32(context,31);
}
void sub_0016F338_0x16f338(std::uint8_t* r,R5900Context* c,PS2Runtime* p){original(r,c,p);}
void sub_00171530_0x171530(std::uint8_t*,R5900Context*,PS2Runtime*){}
void sub_00171E58_0x171e58(std::uint8_t*,R5900Context*,PS2Runtime*){}
void sub_0015BA80_0x15ba80(std::uint8_t*,R5900Context*,PS2Runtime*){}
void sub_0010FB18_0x10fb18(std::uint8_t*,R5900Context*,PS2Runtime*){}
void sub_0016EC90_0x16ec90(std::uint8_t*,R5900Context*,PS2Runtime*){}
void sub_0016F438_0x16f438(std::uint8_t*,R5900Context*,PS2Runtime*){}
void wrong(std::uint8_t*,R5900Context*,PS2Runtime*){}
template<class T>T read(std::istream& stream){T value;stream.read(reinterpret_cast<char*>(&value),sizeof(value));CHECK(stream.good());return value;}
template<class T>void put(std::uint8_t* ram,std::uint32_t at,T value){std::memcpy(ram+at,&value,sizeof(value));}
void segments(std::istream& stream,std::uint8_t* ram) {
    const auto count=read<std::uint32_t>(stream);CHECK(count<=32);
    for(unsigned i=0;i<count;++i){const auto at=read<std::uint32_t>(stream),bytes=read<std::uint32_t>(stream);
        CHECK(bytes<=16384&&std::uint64_t(at)+bytes<=PS2_RAM_SIZE);
        stream.read(reinterpret_cast<char*>(ram+at),bytes);CHECK(stream.good());}
}
void register_originals(PS2Runtime& runtime) {
    runtime.functions={{entry,sub_0016F338_0x16f338},{0x171530,sub_00171530_0x171530},
        {0x171E58,sub_00171E58_0x171e58},{0x15BA80,sub_0015BA80_0x15ba80},
        {0x10FB18,sub_0010FB18_0x10fb18},{0x16EC90,sub_0016EC90_0x16ec90},{0x16F438,sub_0016F438_0x16f438}};
}
void fallback(PS2Runtime& runtime,PS2Runtime::RecompiledFunction function,R5900Context context,bool guest=true) {
    expected_context=context;expected_ram=runtime.memory().bytes;const auto before=fallbacks;
    if(guest){PS2Runtime::GuestExecutionScope scope(&runtime);function(runtime.memory().getRDRAM(),&context,&runtime);}
    else function(runtime.memory().getRDRAM(),&context,&runtime);
    CHECK(fallbacks==before+1);CHECK(GPR_U32(&context,2)==0x13579);++refusals;
}
int main(int argc,char** argv){try{
    CHECK(argc==4);const std::string scenario=argv[3];PS2Runtime runtime;
    std::ifstream image(argv[1],std::ios::binary);CHECK(image.good());segments(image,runtime.memory().getRDRAM());CHECK(image.peek()==EOF);
    register_originals(runtime);
    _putenv_s("REO_NATIVE_MOVIE_POSITION",scenario=="off"?"0":"1");
    _putenv_s("REO_NATIVE_MOVIE_POSITION_TRACE",scenario=="trace"?"1":"0");
    if(scenario=="text")runtime.memory().bytes[0x16F338]^=1;
    if(scenario=="table")runtime.memory().bytes[0x240AF0]^=1;
    if(scenario=="helper")runtime.functions[0x10FB18]=wrong;
    if(scenario=="missing")runtime.functions.erase(0x171E58);
    if(scenario=="late")runtime.started=true;
    if(scenario=="backing-install")ps2RamBackingBytes=64u*1024u*1024u;
    if(scenario=="partial-runtime")runtime.throw_after_publish=true;
    if(scenario=="partial-stub")ps2_stubs::throw_registration=true;
    const bool installed=reo_native_movie_position::install(runtime);
    const bool installation_refused=scenario=="off"||scenario=="text"||scenario=="table"||scenario=="helper"||scenario=="missing"||scenario=="late"||scenario=="backing-install"||scenario=="partial-runtime"||scenario=="partial-stub"||scenario=="disabled";
    CHECK(installed!=installation_refused);
    if(scenario=="disabled"||scenario=="off"||scenario=="text"||scenario=="table"||scenario=="helper"||scenario=="missing"||scenario=="late"||scenario=="backing-install"){
        if(scenario=="backing-install"){CHECK(runtime.workers.empty());CHECK(!ps2_stubs::overrides.contains(entry));}
        CHECK(runtime.lookupFunction(entry)==sub_0016F338_0x16f338);std::cout<<scenario<<" refused\n";return 0;}
    const auto function=runtime.lookupFunction(entry);
    auto identity=runtime.memory().bytes;
    std::ifstream fixtures(argv[2],std::ios::binary);CHECK(fixtures.good());const auto count=read<std::uint32_t>(fixtures);
    R5900Context first;std::vector<std::uint8_t> first_ram;
    for(unsigned row=0;row<count;++row) {
        runtime.memory().bytes=identity;auto* ram=runtime.memory().getRDRAM();R5900Context context;
        for(unsigned n=0;n<32;++n){context.r[n].low=read<std::uint64_t>(fixtures);context.r[n].high=0x8877665500000000ULL+n;}
        for(unsigned n=0;n<context.unrelated.size();++n)context.unrelated[n]=0x1234567800000000ULL+n;
        context.pc=entry;context.branch_pc=0xBAD0BAD0;
        segments(fixtures,ram);auto expected=runtime.memory().bytes;segments(fixtures,expected.data());
        const auto v0=read<std::uint64_t>(fixtures);auto want=context;want.r[2].low=v0;want.pc=caller_return;want.branch_pc=0x16F42C;
        if(row==0){first=context;first_ram=runtime.memory().bytes;}
        if(scenario=="partial-runtime"||scenario=="partial-stub"){fallback(runtime,function,context);break;}
        if(scenario!="fixtures"&&scenario!="trace")break;
        const auto prior=fallbacks;
        {PS2Runtime::GuestExecutionScope scope(&runtime);function(ram,&context,&runtime);}
        CHECK(prior==fallbacks);CHECK(runtime.memory().bytes==expected);CHECK(context==want);++accepted;
    }
    if(scenario=="fixtures"||scenario=="trace"){CHECK(fixtures.peek()==EOF);CHECK(accepted==26);}
    if(scenario=="refusals") {
        for(unsigned variant=0;variant<29;++variant){runtime.memory().bytes=first_ram;auto c=first;auto* ram=runtime.memory().getRDRAM();
            if(variant==0)c.r[4].low=PS2_RAM_SIZE-0x100;
            if(variant==1)c.r[5].low=PS2_RAM_SIZE-0x10;
            if(variant==2)put(ram,0x400000+0x1B30,PS2_RAM_SIZE-0x10);
            if(variant==3)c.r[29].low=32;
            if(variant==4)c.r[29].low=PS2_RAM_SIZE-16;
            if(variant==5)c.r[29].low+=4;
            if(variant==6)c.r[4].low=0x100000000ULL+0x400000;
            if(variant==7)c.r[5].low=0x100000000ULL+0x500000;
            if(variant==8)c.r[31].low=0x100000000ULL+caller_return;
            if(variant==9)c.r[31].low=0x16EE08;
            if(variant==10)c.r[19].low=0x400004;
            if(variant==11)put(ram,0x701030,0x500004u);
            if(variant==12)c.r[4].low+=2;
            if(variant==13)c.r[5].low=0x400D00;
            if(variant==14)put(ram,0x401B30,0x400800u);
            if(variant==15)c.r[5].low=0x600900;
            if(variant==16)c.r[5].low=0x240AF0;
            if(variant==17)c.in_delay_slot=true;
            if(variant==18)c.pc=0x16F39C;
            if(variant==19)put(ram,0x600178,9u);
            if(variant==20)put(ram,0x600178,0xFFFFFFFFu);
            if(variant==21)c.r[29].low=0x600180;
            if(variant==22)std::memset(ram+0x22F18C,0,32);
            if(variant==23)put(ram,0x400048,0u);
            if(variant==24)put(ram,0x600138,0u);
            if(variant==25)put(ram,0x600138,17u);
            if(variant==26)put(ram,0x600138,0xFFFFFFFFu);
            if(variant==27)c.r[5].low+=4;
            if(variant==28){c.r[5].low+=128;put(ram,0x600138,1u);}
            if(variant==13||variant==15||variant==16)put(ram,0x701030,GPR_U32(&c,5));
            if(variant==21)put(ram,0x6001B0,GPR_U32(&c,5));
            if(variant==27||variant==28)put(ram,0x701030,GPR_U32(&c,5));
            fallback(runtime,function,c);
        }
    }
    if(scenario=="changed-image"){runtime.memory().bytes=first_ram;runtime.memory().bytes[0x171530]^=1;fallback(runtime,function,first);}
    if(scenario=="changed-table"){runtime.memory().bytes=first_ram;runtime.memory().bytes[0x240AF0]^=1;fallback(runtime,function,first);}
    if(scenario=="changed-binding"){runtime.memory().bytes=first_ram;runtime.functions[0x171E58]=wrong;fallback(runtime,function,first);}
    if(scenario=="backing-dispatch"){runtime.memory().bytes=first_ram;ps2RamBackingBytes=64u*1024u*1024u;
        fallback(runtime,function,first);}
    if(scenario=="stop"){runtime.memory().bytes=first_ram;runtime.requestStop();fallback(runtime,function,first);}
    if(scenario=="manual"){runtime.memory().bytes=first_ram;fallback(runtime,function,first,false);}
    if(scenario=="memory"){std::vector<std::uint8_t> replacement=first_ram;runtime.memory().bytes.swap(replacement);fallback(runtime,function,first);}
    if(scenario=="runtime"){PS2Runtime other;other.memory().bytes=first_ram;register_originals(other);
        CHECK(!reo_native_movie_position::install(other));CHECK(other.lookupFunction(entry)==sub_0016F338_0x16f338);
        fallback(other,function,first);}
    if(scenario=="repeat"){CHECK(reo_native_movie_position::install(runtime));runtime.requestStop();CHECK(!reo_native_movie_position::install(runtime));}
    std::cout<<"accepted="<<accepted<<" refused="<<refusals<<" fallback_calls="<<fallbacks<<'\n';return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
