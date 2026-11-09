#include "game/native/gameplay_actors/status.hpp"
#include "status_runtime.hpp"
#include <bit>
#include <iostream>
#include <vector>
namespace g=reo::native::gameplay_actors;
namespace gs=reo::native::gameplay_session;
constexpr std::uint32_t base=0x4a5c30;
template<class T>T get(const std::uint8_t* r,std::uint32_t at){return oracle_read<T>(r,at);}
template<class T>void put(std::uint8_t* r,std::uint32_t at,T v){oracle_write(r,at,v);}
g::StatusActor read(const std::uint8_t* r){
    g::StatusActor a;a.current=get<std::int16_t>(r,base+0x544);a.maximum=get<std::int16_t>(r,base+0x546);
    a.status=get<std::uint32_t>(r,base+0xba0);a.auxiliary_status=get<std::uint32_t>(r,base+0xba4);
    a.room=get<std::uint16_t>(r,base+0x1e2);a.category=r[base+2];a.slot=r[base+3];a.class_marker=r[base+0xb9b];
    a.primary=r[base+8];a.secondary=r[base+9];a.phase=r[base+10];a.subphase=r[base+11];
    a.motion_class=r[base+0x54f];a.response_class=r[base+0x140];
    a.damage_interval_one=get<std::uint16_t>(r,base+0xc60);a.damage_interval_two=get<std::uint16_t>(r,base+0xc58);
    a.status_duration=get<std::uint16_t>(r,base+0xc5a);a.recovery_timer=get<std::uint16_t>(r,base+0xc5e);return a;
}
void write(std::uint8_t* r,const g::StatusActor& a){
    put(r,base+0x544,a.current);put(r,base+0x546,a.maximum);put(r,base+0xba0,a.status);put(r,base+0xba4,a.auxiliary_status);
    put(r,base+0x1e2,a.room);r[base+2]=a.category;r[base+3]=a.slot;r[base+0xb9b]=a.class_marker;
    r[base+8]=a.primary;r[base+9]=a.secondary;r[base+10]=a.phase;r[base+11]=a.subphase;
    r[base+0x54f]=a.motion_class;r[base+0x140]=a.response_class;
    put(r,base+0xc60,a.damage_interval_one);put(r,base+0xc58,a.damage_interval_two);put(r,base+0xc5a,a.status_duration);put(r,base+0xc5e,a.recovery_timer);
}
g::StatusSession read_session(const std::uint8_t* r){
    g::StatusSession s;const auto mode=std::bit_cast<std::int8_t>(r[0x3243fb]);
    s.selected_actor=r[0x4baded];s.room=get<std::uint16_t>(r,0x3243dc);s.authority_filter=mode==1||mode==2;
    s.paused=r[0x4badf8]!=0;s.clock_mode=r[0x3243cc];s.feedback_phase=r[0x4bae02];s.feedback_suppressed=r[0x4bae03];s.session_state=get<std::int16_t>(r,0x324200);return s;
}
void write_session(std::uint8_t* r,const g::StatusSession& s){
    r[0x4baded]=s.selected_actor;put(r,0x3243dc,s.room);r[0x3243fb]=s.authority_filter?1:0;
    r[0x4badf8]=s.paused?1:0;r[0x3243cc]=s.clock_mode;r[0x4bae02]=s.feedback_phase;r[0x4bae03]=s.feedback_suppressed;put(r,0x324200,s.session_state);
}
struct Ports final:g::StatusServices {
    std::uint32_t seed{};std::vector<std::uint32_t> trace;
    bool authority_filter(g::HealthSession& s)override{trace.push_back(0x1b0310);return s.authority_filter;}
    std::int32_t selected_authority(g::HealthSession&,std::uint8_t selected)override{trace.push_back(0x1b0110);trace.push_back(selected);return seed%3==0?0:seed%3==1?1:-1;}
    void refresh_class(g::HealthState& a,g::HealthSession&)override{trace.push_back(0x65fab0);trace.push_back(a.status);a.class_marker=std::uint8_t(a.current);}
    void feedback(g::StatusActor& a,g::StatusSession& s,std::uint8_t kind)override{
        trace.insert(trace.end(),{0x665ca0,kind,a.status,a.damage_interval_one,a.damage_interval_two});
        if(seed&32)a.status^=2;
        if(seed&64)a.damage_interval_one=1;
        if(seed&128)s.feedback_suppressed=1;
    }
    void publish(g::StatusActor& a,g::StatusSession&,std::uint8_t kind)override{trace.insert(trace.end(),{0x67e230,kind,a.status,std::uint32_t(a.current)});if(seed&256)a.recovery_timer=71;}
    void cleanup(g::StatusActor& a,g::StatusSession&)override{trace.insert(trace.end(),{0x5f6800,a.status});if(seed&32)a.phase=77;}
    void recover(g::StatusActor& a,g::StatusSession&)override{trace.insert(trace.end(),{0x65fba0,a.status});a.current=17;}
    void snapshot(g::StatusActor& a,g::StatusSession&)override{trace.insert(trace.end(),{0x667370,a.primary,a.secondary,a.phase,a.subphase,a.response_class});if(seed&128)a.subphase=32;}
};
void o2_0065FEB0_0x65feb0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_0065FF70_0x65ff70(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_00660240_0x660240(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_006605B0_0x6605b0(std::uint8_t*,R5900Context*,PS2Runtime*);
Ports* original_ports{};gs::Random* original_random{};std::uint64_t random_calls{};
void original_port(std::uint8_t* r,R5900Context* c,PS2Runtime* runtime){
    switch(c->pc){
    case 0x65feb0:o2_0065FEB0_0x65feb0(r,c,runtime);return;
    case 0x65ff70:o2_0065FF70_0x65ff70(r,c,runtime);return;
    case 0x660240:o2_00660240_0x660240(r,c,runtime);return;
    case 0x6605b0:o2_006605B0_0x6605b0(r,c,runtime);return;
    case 0x1aec80:++random_calls;SET_GPR_U32(c,2,original_random->request(GPR_U32(c,4)));return;
    default:break;
    }
    auto a=read(r);auto s=read_session(r);const auto arg=std::uint8_t(GPR_U32(c,5));
    switch(c->pc){
    case 0x1b0310:SET_GPR_U32(c,2,original_ports->authority_filter(s));break;
    case 0x1b0110:SET_GPR_S32(c,2,original_ports->selected_authority(s,std::uint8_t(GPR_U32(c,4))));break;
    case 0x65fab0:original_ports->refresh_class(a,s);break;
    case 0x665ca0:original_ports->feedback(a,s,arg);break;
    case 0x67e230:original_ports->publish(a,s,arg);break;
    case 0x5f6800:if(arg)throw std::runtime_error("cleanup arg");original_ports->cleanup(a,s);break;
    case 0x65fba0:if(arg)throw std::runtime_error("recover arg");original_ports->recover(a,s);break;
    case 0x667370:original_ports->snapshot(a,s);break;
    default:throw std::runtime_error("undeclared status port "+std::to_string(c->pc));
    }
    write(r,a);write_session(r,s);
    c->pc=GPR_U32(c,31);
}
#include "original_status.cpp"
std::uint32_t next(std::uint32_t& s){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000,0xa5),expected(ram);
    constexpr std::uint32_t targets[]{0x6606bc,0x6605d8,0x6605e4,0x6605f8,0x66060c,0x660638,0x66065c,0x660678,0x6606bc,0x660694};
    for(std::size_t i=0;i<10;++i)put(ram.data(),0x740340+std::uint32_t(i*4),targets[i]);
    std::uint64_t cases{},calls{};std::uint32_t random=0x6b25ce31;PS2Runtime runtime;runtime.port=&original_port;
    constexpr std::uint8_t motions[]{1,2,3,7,0x0b,0x1a,0x22,0x23,0x24,0x27,0x28,0x2e,0x2f,0x30,0x31,0x80};
    constexpr std::uint8_t seconds[]{0,1,0x34,0x47,0xc5,0xc8,0xff};
    constexpr std::int16_t health[]{-32768,-1,0,1,2,5,100,32767};
    for(std::uint32_t seed=0;seed<32768;++seed)for(unsigned operation=0;operation<5;++operation){
        g::StatusActor a;a.current=health[seed%8];a.maximum=std::int16_t(10+seed%2000);a.status=next(random);
        // Alternate full random bits and exhaustive low masks without invulnerability.
        if(seed&1)a.status=(seed/2)%512;
        a.auxiliary_status=next(random);a.room=std::uint16_t(seed%3);a.category=std::uint8_t(seed%4);a.slot=std::uint8_t(seed%8);a.class_marker=19;
        a.primary=std::uint8_t(seed%6);a.secondary=seconds[(seed/8)%7];a.phase=29;a.subphase=30;a.motion_class=motions[(seed/4)%16];a.response_class=31;
        constexpr std::uint16_t timers[]{0,1,2,10,20,30,60,1200,2400,4500,9000,65535};
        a.damage_interval_one=timers[(seed/7)%12];a.damage_interval_two=timers[(seed/9)%12];a.status_duration=timers[(seed/11)%12];a.recovery_timer=timers[(seed/13)%12];
        g::StatusSession s;s.selected_actor=std::uint8_t((seed/4)%8);s.room=std::uint16_t((seed/3)%3);s.authority_filter=seed&16;
        s.paused=seed%17==0;s.clock_mode=std::uint8_t(seed%2);s.feedback_phase=std::uint8_t(seed/3);s.feedback_suppressed=std::uint8_t((seed/64)%2);s.session_state=std::int16_t((seed/23)%3);
        write(ram.data(),a);write_session(ram.data(),s);const auto random_state=gs::RandomState{std::uint16_t(next(random)),std::uint16_t(next(random)),std::uint8_t(next(random))};
        gs::Random native_rng(random_state),original_rng(random_state);Ports native,original;native.seed=seed;original.seed=seed;original_ports=&original;original_random=&original_rng;
        bool result{};std::uint32_t address{};
        switch(operation){
        case 0:address=0x660240;result=g::periodic_damage_admitted(a);break;
        case 1:address=0x6605b0;g::clear_status(a,s,native,std::uint8_t(seed));break;
        case 2:address=0x660310;g::tick_status(a,s,native,native_rng);break;
        case 3:address=0x6607d0;g::select_zero_health_action(a,s,native);break;
        case 4:address=0x660980;result=g::override_hit_response(a,s,native);break;
        }
        write(expected.data(),a);write_session(expected.data(),s);
        R5900Context ctx;ctx.pc=address;ctx.r[4][0]=base;ctx.r[5][0]=seed;ctx.r[29][0]=0x1f00000;ctx.r[31][0]=0xdead0000;
        switch(operation){
        case 0:o2_00660240_0x660240(ram.data(),&ctx,&runtime);break;
        case 1:o2_006605B0_0x6605b0(ram.data(),&ctx,&runtime);break;
        case 2:o2_00660310_0x660310(ram.data(),&ctx,&runtime);break;
        case 3:o2_006607D0_0x6607d0(ram.data(),&ctx,&runtime);break;
        case 4:o2_00660980_0x660980(ram.data(),&ctx,&runtime);break;
        }
        if(native.trace!=original.trace || native_rng.state()!=original_rng.state() || ctx.pc!=0xdead0000 || ctx.r[29][0]!=0x1f00000 ||
           ((operation==0 || operation==4) && GPR_U32(&ctx,2)!=unsigned(result)) ||
           !std::equal(ram.begin()+base,ram.begin()+base+0x10e0,expected.begin()+base) ||
           ram[0x4bae03]!=expected[0x4bae03]){
            std::cerr<<"operation="<<operation<<" seed="<<seed<<" native_trace="<<native.trace.size()<<" original_trace="<<original.trace.size()<<'\n';
            std::cerr<<"pc="<<std::hex<<ctx.pc<<" sp="<<ctx.r[29][0]<<" result="<<GPR_U32(&ctx,2)<<std::dec<<'\n';
            for(std::size_t i=0;i<std::min(native.trace.size(),original.trace.size());++i)if(native.trace[i]!=original.trace[i])std::cerr<<"trace "<<i<<" native="<<native.trace[i]<<" original="<<original.trace[i]<<'\n';
            for(std::uint32_t at=base;at<base+0x10e0;++at)if(ram[at]!=expected[at])std::cerr<<"offset="<<std::hex<<at-base<<" actual="<<unsigned(ram[at])<<" expected="<<unsigned(expected[at])<<std::dec<<'\n';
            throw std::runtime_error("status original comparison");
        }
        ++cases;calls+=native.trace.size();
    }
    if(random_calls!=32768)throw std::runtime_error("unconditional shared RNG count");
    std::cout<<"{\"cases\":"<<cases<<",\"ordered_trace_words\":"<<calls<<",\"rng_requests\":"<<random_calls<<",\"original_bodies_executed\":7,\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
