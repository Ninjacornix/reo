// Offline complete-body execution. Production contains only the recovered
// semantic selectors/events, never this register or memory environment.
#include "reference.hpp"
#include <fstream>
#include <iostream>
#include <vector>
struct Item{std::uint32_t kind{},frame{},a{},b{},c{};};
std::vector<Item> trace;
constexpr std::uint32_t actor=0x100000;
bool upper_pass{},lower_reached{};
struct ReachedLower{};
template<class T>T observed_read(std::uint8_t* p,std::uint32_t at){
    const auto value=transform_read<T>(p,at);
    if constexpr(sizeof(T)==2){
        if(at==actor+0x1f2){
            if(upper_pass)throw ReachedLower{};
            if(!lower_reached){trace.clear();lower_reached=true;}
        }
    }
    if constexpr(sizeof(T)==1){
        if(at==actor+9)trace.push_back({0x103,0,std::uint32_t(value==15)});
    }
    return value;
}
#undef READ8
#undef READ16
#define READ8(at) observed_read<std::uint8_t>(rdram,at)
#define READ16(at) observed_read<std::uint16_t>(rdram,at)
#include "functions.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
void original_transform_port(std::uint8_t*,R5900Context* c,PS2Runtime*){
    Item item{c->pc,GPR_U32(c,4)};
    switch(c->pc){
    case 0x595b70:item.a=GPR_U32(c,6);break;
    case 0x595c90:case 0x596060:item.a=GPR_U32(c,6);item.b=GPR_U32(c,7);break;
    case 0x595dd0:item.b=GPR_U32(c,7);break;
    case 0x595eb0:break;
    case 0x596180:item.a=GPR_U32(c,6);item.b=GPR_U32(c,7);item.c=GPR_U32(c,8);break;
    default:throw std::runtime_error("Undeclared character event consumer");
    }
    if(GPR_U32(c,5)!=actor||c->f[12]!=1.25f)throw std::runtime_error("Character schedule actor/step mismatch");
    trace.push_back(item);c->pc=GPR_U32(c,31);
}
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("Owned overlay required");
    std::vector<std::uint8_t> ram(0x2000000);std::ifstream input(argv[1],std::ios::binary);
    input.read(reinterpret_cast<char*>(ram.data()+0x570000),0x1d3100);if(!input)throw std::runtime_error("Owned overlay extent");
    using Fn=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*);
    const std::array<Fn,8> functions{o2_005EC3E0_0x5ec3e0,o2_005BAFF0_0x5baff0,o2_005BB480_0x5bb480,o2_005BB780_0x5bb780,
        o2_005BBAD0_0x5bbad0,o2_005EC7A0_0x5ec7a0,o2_005BBFA0_0x5bbfa0,o2_005BC380_0x5bc380};
    PS2Runtime runtime;unsigned calls{},rows{};
    for(unsigned family=0;family<8;++family)for(unsigned pass=0;pass<2;++pass)
        for(unsigned selector=0;selector<65536;++selector)for(unsigned variant=0;variant<2;++variant){
            trace.clear();upper_pass=pass==0;lower_reached=false;
            transform_write(ram.data(),actor+0x212,std::uint16_t(upper_pass?selector:65535));
            transform_write(ram.data(),actor+0x1f2,std::uint16_t(upper_pass?65535:selector));ram[actor+9]=variant?15:0;
            R5900Context c{};SET_GPR_U32(&c,4,actor);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);c.f[12]=1.25f;
            try{functions[family](ram.data(),&c,&runtime);if(c.pc!=0xabcdef)throw std::runtime_error("Original schedule did not return");}
            catch(const ReachedLower&){}
            ++calls;
            if(!upper_pass&&!lower_reached&&!trace.empty())throw std::runtime_error("Nonempty upper default would contaminate extraction");
            if(trace.empty())continue;
            ++rows;std::cout<<family*2+pass<<' '<<selector<<' '<<variant;
            for(const auto& item:trace)std::cout<<' '<<item.kind<<','<<item.frame<<','<<item.a<<','<<item.b<<','<<item.c;
            std::cout<<'\n';
        }
    std::cerr<<"{\"original_calls\":"<<calls<<",\"nonempty_rows\":"<<rows<<"}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
