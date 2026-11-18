#include "game/native/gameplay_effects/resource_flight.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
namespace e=reo::native::gameplay_effects;namespace m=reo::native::transform_math;
unsigned checks{},cases{},calls{},queries{},cues{},retirements{},constructors{};
bool original_created{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Flight policy check "+std::to_string(at.line()));}
template<class T>T get(const std::uint8_t* memory,unsigned address){return transform_read<T>(memory,address);}
template<class T>void put(std::uint8_t* memory,unsigned address,T value){transform_write(memory,address,value);}
struct Query {bool floor{};m::Vector start,end;};
struct FlightQueries final:e::FlightQueries {
    std::optional<e::FlightHit> wall_hit,floor_hit;std::vector<Query> calls;
    e::FlightTrace wall(m::Vector start,m::Vector end)override{calls.push_back({false,start,end});return{true,wall_hit};}
    e::FlightTrace floor(m::Vector start,m::Vector end)override{calls.push_back({true,start,end});return{true,floor_hit};}
};
FlightQueries source_queries;bool original_retire{};std::optional<m::Vector> original_cue;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;const auto done=[&]{context->pc=GPR_U32(context,31);};
    switch(context->pc){
    case 0x372720:SET_GPR_U32(context,2,100+GPR_U32(context,4));done();return;
    case 0x652390:{
        check(!original_created);original_created=true;const auto effect=GPR_U32(context,4);std::memset(memory+0x10000,0,0x300);
        R5900Context defaults;defaults.pc=0x652f00;SET_GPR_U32(&defaults,4,0x10000);SET_GPR_U32(&defaults,5,100+effect);SET_GPR_U32(&defaults,31,0x1234);
        o2_00652F00_0x652f00(memory,&defaults,runtime);check(defaults.pc==0x1234);SET_GPR_U32(context,2,0x10000);done();return;
    }
    case 0x5795e0:case 0x57d560:{
        const bool floor=context->pc==0x57d560;
        check(GPR_U32(context,8)==(floor?0u:0x2ffffu)&&GPR_U32(context,9)==0);
        const auto start=get<m::Vector>(memory,GPR_U32(context,4)),end=get<m::Vector>(memory,GPR_U32(context,5));
        const auto result=floor?source_queries.floor(start,end):source_queries.wall(start,end);
        if(result.hit){put(memory,GPR_U32(context,6),result.hit->point);put(memory,GPR_U32(context,7),m::Vector{0,1,0});if(floor)memory[GPR_U32(context,10)]=result.hit->type;else put(memory,GPR_U32(context,10),unsigned(result.hit->type));}
        SET_GPR_U32(context,2,result.hit?1:0);done();return;
    }
    case 0x1b93d0:check(GPR_U32(context,4)==10&&GPR_U32(context,5)==4&&GPR_U32(context,6)==2&&GPR_U32(context,8)==1&&!GPR_U32(context,9)&&!GPR_U32(context,10));original_cue=get<m::Vector>(memory,GPR_U32(context,7));done();return;
    case 0x651d00:check(GPR_U32(context,4)==0x10000);original_retire=true;done();return;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted resource flight helper "+std::to_string(context->pc));
    }
}
void invoke(std::uint8_t* memory,unsigned pc=0x58e850,std::array<unsigned,3> args={0x10000,0,0}){R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);}
void export_state(std::uint8_t* memory,const e::ResourceFlightState& state){
    constexpr unsigned at=0x10000;memory[at+1]=std::uint8_t(state.visible);memory[at+4]=state.style;memory[at+8]=state.phase;memory[at+0x33]=state.sticky;
    put(memory,at+0xc,state.lifetime);put(memory,at+0xe,state.cooldown);put(memory,at+0x204,state.effect);
    put(memory,at+0x50,state.basis);put(memory,at+0x38,state.position);put(memory,at+0x44,state.previous_position);put(memory,at+0xd8,state.displacement);
    put(memory,at+0xc0,state.velocity);put(memory,at+0xcc,state.acceleration);put(memory,at+0xb4,state.scale);put(memory,at+0x208,state.color);put(memory,at+0x90,state.angles);
    put(memory,at+0x24,0x20000u);memory[0x20002]=0;memory[0x20003]=2;put(memory,at+0x1f4,0x392670u);put(memory,0x392688,0xdead1000u);
}
void compare_state(const std::uint8_t* memory,const e::ResourceFlightState& state){
    constexpr unsigned at=0x10000;check(state.visible==bool(memory[at+1])&&state.phase==memory[at+8]&&state.sticky==memory[at+0x33]);
    check(state.lifetime==get<std::int16_t>(memory,at+0xc)&&state.cooldown==get<std::int16_t>(memory,at+0xe));
    const auto same=[&](unsigned offset,const auto& value){check(std::memcmp(&value,memory+at+offset,sizeof value)==0);};
    same(0x50,state.basis);same(0x38,state.position);same(0x44,state.previous_position);same(0xd8,state.displacement);same(0xc0,state.velocity);same(0xcc,state.acceleration);same(0xb4,state.scale);same(0x208,state.color);same(0x90,state.angles);
}
int main()try{
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());
    for(unsigned style=0;style<32;++style){const auto profile=e::resource_flight_profile(style);const auto raw=memory[0x709460+style];check(bool(profile)==(raw!=255));if(profile){check(profile->style==raw&&profile->effect==memory[0x7093d8+raw]);check(std::memcmp(&profile->offset,memory.data()+0x7093f0+12*raw,12)==0);}}
    for(unsigned phase:{0u,1u,2u,3u,255u})for(unsigned pattern=0;pattern<4;++pattern)for(unsigned n=0;n<65536;++n){
        e::ResourceFlightState state;state.phase=std::uint8_t(phase);state.style=std::uint8_t(n%9);state.effect=std::uint16_t(0x14+n%4);
        state.visible=n%3!=0;state.sticky=std::uint8_t(n%5==0);state.lifetime=std::bit_cast<std::int16_t>(std::uint16_t(n));state.cooldown=std::bit_cast<std::int16_t>(std::uint16_t(n*257));
        state.basis=m::identity();m::compose_euler_radians(state.basis,{float(int(n%17)-8)*.07f,float(int(n%19)-9)*.05f,float(int(n%13)-6)*.09f});
        state.basis[3]={50,-25,75,1};state.position={11,22,33};state.previous_position={-1,-2,-3};state.displacement={float(int(n%19)-9),4,-2};state.velocity={-1,2,5};state.acceleration={.25f,-.5f,.125f};state.scale={2,3,4};state.color={.1f,.2f,.3f,.4f};state.angles={std::uint16_t(n),std::uint16_t(n*17),std::uint16_t(n*31)};
        FlightQueries native_queries;native_queries.wall_hit=pattern&1?std::optional(e::FlightHit{{100,200,300},0}):std::nullopt;
        native_queries.floor_hit=pattern&2?std::optional(e::FlightHit{{50,-10,90},std::uint8_t(n%2?0x81:2)}):std::nullopt;
        source_queries=native_queries;original_retire=false;original_cue.reset();export_state(memory.data(),state);
        reo::native::gameplay_session::Random random({std::uint16_t(n),std::uint16_t(n*257),std::uint8_t(n)});
        put(memory.data(),0x3244b0,random.state().primary);put(memory.data(),0x3244b8,random.state().secondary);memory[0x2b8de8]=random.state().observed;
        invoke(memory.data());const auto result=e::advance_resource_flight(state,native_queries,random);
        check(result.available&&result.retire==original_retire&&bool(result.cue_position)==bool(original_cue));
        compare_state(memory.data(),state);check(source_queries.calls.size()==native_queries.calls.size());
        for(unsigned i=0;i<source_queries.calls.size();++i){const auto& a=source_queries.calls[i];const auto& b=native_queries.calls[i];check(a.floor==b.floor&&std::memcmp(&a.start,&b.start,12)==0&&std::memcmp(&a.end,&b.end,12)==0);++queries;}
        if(original_cue){check(std::memcmp(&*result.cue_position,&*original_cue,12)==0);++cues;}
        check(random.state()==reo::native::gameplay_session::RandomState{get<std::uint16_t>(memory.data(),0x3244b0),get<std::uint16_t>(memory.data(),0x3244b8),memory[0x2b8de8]});
        if(original_retire)++retirements;
        ++cases;
    }
    for(unsigned n=0;n<32768;++n){
        auto matrix=m::identity();m::compose_euler_radians(matrix,{float(int(n%31)-15)*.11f,float(int(n%37)-18)*.07f,float(int(n%29)-14)*.13f});
        for(unsigned i=0;i<3;++i)for(unsigned j=0;j<3;++j)matrix[i][j]*=float(1+(n+i)%3);
        matrix[3]={-50,25,75,1};put(memory.data(),0x30000,matrix);original_created=false;
        invoke(memory.data(),0x58e6d0,{0x20000,0x30000,n%32});const auto native=e::prepare_resource_flight(matrix,n%32);
        check(bool(native)==original_created);
        if(native){compare_state(memory.data(),*native);check(native->style==memory[0x10004]&&native->effect==get<std::uint16_t>(memory.data(),0x10204));check(memory[0x10000]==1&&memory[0x10002]==6&&memory[0x10003]==7&&get<unsigned>(memory.data(),0x10200)==0x8193);}
        ++constructors;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"constructors\":"<<constructors<<",\"queries\":"<<queries<<",\"cues\":"<<cues<<",\"retirements\":"<<retirements<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
