#include "game/native/gameplay_actors/health_class.hpp"
#include "class_runtime.hpp"
#include <bit>
#include <iostream>
#include <vector>
#define MTC1(c,n,v) ((c)->f[n]=std::bit_cast<float>(std::uint32_t(v)))
#define FPR_F32(c,n) ((c)->f[n])
#define SET_FPR_F32(c,n,v) ((c)->f[n]=float(v))
#define FPU_CVT_S_W(v) static_cast<float>(v)
#define FPU_MUL_S(a,b) ((a)*(b))
#define FPU_DIV_S(a,b) ((a)/(b))
#define FPU_C_OLT_S(a,b) ((a)<(b))
void original_port(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unexpected health-class provider");}
#include "original_class.cpp"
namespace g=reo::native::gameplay_actors;
constexpr std::uint32_t base=0x4a5c30;
std::uint32_t next(std::uint32_t& s){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000,0xa5);std::uint32_t random=0x67df1321;std::uint64_t cases{},invalid{};constexpr float thresholds[]{50,25};
    oracle_write(ram.data(),0x71b030,thresholds[0]);oracle_write(ram.data(),0x71b034,thresholds[1]);
    constexpr std::int16_t maxima[]{-32768,-1,1,2,3,4,100,1000,32767};
    for(std::uint32_t bits=0;bits<65536;++bits)for(auto maximum:maxima){
        g::HealthState a{std::bit_cast<std::int16_t>(std::uint16_t(bits)),maximum,next(random),0,std::uint8_t(bits%4),0,0x79};
        if(bits&1)a.status=bits%32;
        oracle_write(ram.data(),base+0x544,a.current);oracle_write(ram.data(),base+0x546,a.maximum);oracle_write(ram.data(),base+0xba0,a.status);ram[base+2]=a.category;ram[base+0xb9b]=a.class_marker;
        const auto before=a;const auto result=g::derive_health_class(a,thresholds);
        R5900Context ctx;ctx.r[4][0]=base;ctx.r[31][0]=0xdead0000;PS2Runtime runtime;o2_0065FAB0_0x65fab0(ram.data(),&ctx,&runtime);
        if(ram[base+0xb9b]!=a.class_marker || ctx.pc!=0xdead0000 || GPR_U32(&ctx,2)!=0 || a.current!=before.current || a.maximum!=before.maximum || a.status!=before.status || result==g::ClassResult::invalid_maximum)throw std::runtime_error("health class original mismatch "+std::to_string(bits));
        ++cases;
    }
    for(std::uint32_t category=0;category<4;++category)for(std::uint32_t status=0;status<16;++status){
        g::HealthState a{0,0,status,0,std::uint8_t(category),0,0x56};const auto result=g::derive_health_class(a,thresholds);
        const bool refusal=category<2 && !(status&10);
        if((result==g::ClassResult::invalid_maximum)!=refusal || (refusal&&a.class_marker!=0x56))throw std::runtime_error("health class zero-maximum admission");
        ++invalid;
    }
    std::cout<<"{\"cases\":"<<cases<<",\"zero_maximum_cases\":"<<invalid<<",\"original_bodies_executed\":1,\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
