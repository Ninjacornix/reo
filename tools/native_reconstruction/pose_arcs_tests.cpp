#include "game/native/gameplay_world/pose_arcs.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <vector>
namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;namespace c=reo::native::gameplay_collision;
unsigned checks{},cases{},calls{},retirements{},queries{},trails{};bool retired{};constexpr unsigned work_at=0x20000,parent_at=0x22000;
void check(bool v,std::source_location p=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Pose arcs "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,unsigned at,T v){transform_write(p,at,v);}
std::vector<m::Vector> original_queries;std::vector<unsigned> original_trails;
struct Effects final:g::PoseArcEffects {
    c::response::Floor sampled;std::vector<m::Vector> points;std::vector<unsigned> modes;unsigned reject{};
    std::optional<c::response::Floor> floor(m::Vector p)override{points.push_back(p);if(reject==3)return{};return sampled;}
    bool trail(const g::actors::EntityId&,const g::actors::EntityId&,std::uint8_t mode)override{modes.push_back(mode);return reject!=unsigned(mode)+1;}
} effects;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x582de0:check(GPR_U32(context,4)==work_at);retired=true;break;
    case 0x616f20:check(GPR_U32(context,6)==255);original_queries.push_back(get<m::Vector>(memory,GPR_U32(context,4)));memory[GPR_U32(context,5)]=effects.sampled.type;context->f[0]=effects.sampled.height;break;
    case 0x578620:check(GPR_U32(context,4)==parent_at&&GPR_U32(context,5)==work_at&&GPR_U32(context,6)<2&&!GPR_U32(context,7)&&!GPR_U32(context,8));original_trails.push_back(GPR_U32(context,6));break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted pose arc helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);g::Actor actor;actor.pose_work.emplace();
    for(unsigned kind:{13u,16u})for(unsigned n=0;n<196608;++n){
        actor.primary=std::uint8_t(n/65536==2?255:n/65536);actor.visible=n&1;actor.auxiliary_status=std::uint8_t(n>>8);actor.position={float(int(n%59)-29)*.125f,float(int(n%71)-35)*.25f,float(int(n%43)-21)*.5f};actor.orientation={std::bit_cast<std::int16_t>(std::uint16_t(n*19)),std::bit_cast<std::int16_t>(std::uint16_t(n*257)),std::bit_cast<std::int16_t>(std::uint16_t(n*251+7)),-17};actor.sampled_surface_height=-991;auto& state=*actor.pose_work;state.variant=std::uint8_t(n);state.timer=std::bit_cast<std::int16_t>(std::uint16_t(n));state.lifetime=std::int16_t(n*13);state.velocity={float(int(n%13)-6)*.25f,float(int(n%37)-18)*.125f,float(int(n%23)-11)*.5f};state.acceleration={1,float(int(n%23)-11)*.0625f,-.25f};effects.sampled.height=float(int(n%41)-20)*.5f;effects.sampled.type=std::uint8_t(n);
        memory[work_at+8]=actor.primary;memory[work_at+1]=actor.visible;memory[work_at+5]=state.variant;memory[work_at+0x115]=std::uint8_t(actor.auxiliary_status);put(memory,work_at+0x28,parent_at);put(memory,work_at+0x38,actor.position);put(memory,work_at+0x90,actor.orientation);put(memory,work_at+12,state.timer);put(memory,work_at+18,state.lifetime);put(memory,work_at+0xc0,state.velocity);put(memory,work_at+0xcc,state.acceleration);put(memory,work_at+0x170,actor.sampled_surface_height);retired=false;original_queries.clear();original_trails.clear();effects.points.clear();effects.modes.clear();
        R5900Context context;PS2Runtime runtime;context.pc=kind==13?0x583430:0x5835e0;SET_GPR_U32(&context,4,work_at);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
        const auto step=g::advance_quarter_turn_pose_arc(actor,std::uint8_t(kind),{},effects);check(step==(retired?g::PoseArcStep::retire:g::PoseArcStep::completed));check(actor.primary==memory[work_at+8]&&actor.visible==bool(memory[work_at+1])&&actor.auxiliary_status==memory[work_at+0x115]);check(state.timer==get<std::int16_t>(memory,work_at+12)&&state.lifetime==get<std::int16_t>(memory,work_at+18));check(std::memcmp(&actor.position,memory+work_at+0x38,12)==0&&std::memcmp(&state.velocity,memory+work_at+0xc0,12)==0&&std::memcmp(&state.acceleration,memory+work_at+0xcc,12)==0&&std::memcmp(actor.orientation.data(),memory+work_at+0x90,8)==0&&actor.sampled_surface_height==get<float>(memory,work_at+0x170));check(effects.modes==original_trails&&effects.points.size()==original_queries.size());if(!effects.points.empty())check(std::memcmp(effects.points.data(),original_queries.data(),12)==0);retirements+=retired;queries+=unsigned(effects.points.size());trails+=unsigned(effects.modes.size());++cases;
    }
    for(unsigned refusal=1;refusal<=3;++refusal){actor.primary=refusal==3?1:0;actor.pose_work->velocity={0,1,0};effects.reject=refusal;check(g::advance_quarter_turn_pose_arc(actor,16,{},effects)==g::PoseArcStep::unavailable&&actor.primary==1);}
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"retirements\":"<<retirements<<",\"floor_queries\":"<<queries<<",\"trail_requests\":"<<trails<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
