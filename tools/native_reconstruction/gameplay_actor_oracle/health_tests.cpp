#include "game/native/gameplay_actors/health.hpp"
#include "runtime.hpp"
#include <bit>
#include <iostream>
#include <vector>
namespace g=reo::native::gameplay_actors;
constexpr std::uint32_t base=0x4a5c30;
struct Ports final:g::HealthServices {
    std::uint32_t seed{};std::vector<std::uint32_t> trace;
    bool authority_filter(g::HealthSession& s) override {
        trace.push_back(0x1b0310);return s.authority_filter;
    }
    std::int32_t selected_authority(g::HealthSession& s,std::uint8_t selected) override {
        trace.push_back(0x1b0110);trace.push_back(selected);
        if(seed&1)s.room^=1;
        return seed%3==0?0:seed%3==1?1:-1;
    }
    void refresh_class(g::HealthState& a,g::HealthSession& s) override {
        trace.push_back(0x65fab0);trace.push_back(a.status);
        a.class_marker=std::uint8_t(a.current);a.status^=seed;
        if(seed&2)s.selected_actor^=1;
    }
};
g::HealthState read(const std::uint8_t* ram) {
    return {oracle_read<std::int16_t>(ram,base+0x544),oracle_read<std::int16_t>(ram,base+0x546),
        oracle_read<std::uint32_t>(ram,base+0xba0),oracle_read<std::uint16_t>(ram,base+0x1e2),
        ram[base+2],ram[base+3],ram[base+0xb9b]};
}
void write(std::uint8_t* ram,const g::HealthState& a) {
    oracle_write(ram,base+0x544,a.current);oracle_write(ram,base+0x546,a.maximum);
    oracle_write(ram,base+0xba0,a.status);oracle_write(ram,base+0x1e2,a.room);
    ram[base+2]=a.category;ram[base+3]=a.slot;ram[base+0xb9b]=a.class_marker;
}
g::HealthSession read_session(const std::uint8_t* ram) {
    const auto mode=std::bit_cast<std::int8_t>(ram[0x3243fb]);
    return {ram[0x4baded],oracle_read<std::uint16_t>(ram,0x3243dc),mode==1||mode==2};
}
void write_session(std::uint8_t* ram,const g::HealthSession& s) {
    ram[0x4baded]=s.selected_actor;oracle_write(ram,0x3243dc,s.room);
    ram[0x3243fb]=s.authority_filter?1:0;
}
Ports* original_ports{};
void o2_0065FEB0_0x65feb0(std::uint8_t*,R5900Context*,PS2Runtime*);
void original_port(std::uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime) {
    if(ctx->pc==0x65feb0){o2_0065FEB0_0x65feb0(ram,ctx,runtime);return;}
    auto s=read_session(ram);const auto call=ctx->pc;
    if(call==0x1b0310)SET_GPR_U32(ctx,2,original_ports->authority_filter(s));
    else if(call==0x1b0110)SET_GPR_S32(ctx,2,original_ports->selected_authority(s,std::uint8_t(GPR_U32(ctx,4))));
    else if(call==0x65fab0){
        if(GPR_U32(ctx,4)!=base)throw std::runtime_error("refresh actor identity");
        auto a=read(ram);original_ports->refresh_class(a,s);write(ram,a);
    }else throw std::runtime_error("undeclared health service");
    write_session(ram,s);
}
#include "original_health.cpp"
std::uint32_t next(std::uint32_t& s){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
bool equal(const g::HealthState& a,const g::HealthState& b){
    return a.current==b.current&&a.maximum==b.maximum&&a.status==b.status&&a.room==b.room&&
        a.category==b.category&&a.slot==b.slot&&a.class_marker==b.class_marker;
}
int main()try {
    std::vector<std::uint8_t> ram(0x2000000,0xa5);std::uint64_t cases{},wrapper_cases{},calls{};
    std::uint32_t random=0x9174d5ab;PS2Runtime runtime;runtime.port=&original_port;
    constexpr std::uint32_t amounts[]{0,1,2,32767,32768,65535,0xdead0001,0x10000};
    constexpr std::uint32_t modes[]{0,1,2,255,0x100,0x101};
    for(std::uint32_t bits=0;bits<65536;++bits)for(auto amount:amounts)for(auto mode:modes){
        g::HealthState a{std::bit_cast<std::int16_t>(std::uint16_t(bits)),
            std::bit_cast<std::int16_t>(std::uint16_t(next(random))),next(random),3,0,0,7};
        write(ram.data(),a);const auto result=g::adjust_health(a,amount,mode);
        R5900Context ctx;ctx.r[4][0]=base;ctx.r[5][0]=amount;ctx.r[6][0]=mode;ctx.r[31][0]=0xdead0000;
        o2_0065FEB0_0x65feb0(ram.data(),&ctx,&runtime);
        if(!equal(a,read(ram.data())) || GPR_S64(&ctx,2)!=result || ctx.pc!=0xdead0000)
            throw std::runtime_error("health arithmetic mismatch at "+std::to_string(bits));
        ++cases;
    }
    for(std::uint32_t seed=0;seed<65536;++seed){
        g::HealthState a{std::bit_cast<std::int16_t>(std::uint16_t(next(random))),
            std::bit_cast<std::int16_t>(std::uint16_t(next(random))),next(random),
            std::uint16_t(seed%3),std::uint8_t(seed%4),std::uint8_t(seed%8),0x57};
        g::HealthSession session{std::uint8_t((seed/4)%8),std::uint16_t((seed/3)%3),bool(seed&16)};
        write(ram.data(),a);write_session(ram.data(),session);Ports native;native.seed=seed;
        const auto amount=next(random),mode=modes[seed%6];
        const auto result=g::apply_health(a,session,native,amount,mode);
        Ports original;original.seed=seed;original_ports=&original;
        R5900Context ctx;ctx.r[4][0]=base;ctx.r[5][0]=amount;ctx.r[6][0]=mode;
        ctx.r[29][0]=0x1f00000;ctx.r[31][0]=0xdead0000;
        o2_0065FF70_0x65ff70(ram.data(),&ctx,&runtime);
        const auto observed=read_session(ram.data());
        if(!equal(a,read(ram.data())) || GPR_S64(&ctx,2)!=result || native.trace!=original.trace ||
           session.selected_actor!=observed.selected_actor || session.room!=observed.room ||
           session.authority_filter!=observed.authority_filter || ctx.pc!=0xdead0000 || ctx.r[29][0]!=0x1f00000)
            throw std::runtime_error("health authority mismatch at "+std::to_string(seed));
        ++wrapper_cases;calls+=native.trace.size();
    }
    std::cout<<"{\"arithmetic_cases\":"<<cases<<",\"authority_cases\":"<<wrapper_cases<<",\"ordered_trace_words\":"<<calls<<",\"original_bodies_executed\":2,\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
