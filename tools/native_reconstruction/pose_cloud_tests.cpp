#include "game/native/gameplay_world/pose_cloud.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <vector>
namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;
unsigned checks{},cases{},calls{},retirements{},visuals{},lights{};bool retired{};constexpr unsigned work_at=0x20000,parent_at=0x22000;
void check(bool v,std::source_location p=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Pose cloud "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,unsigned at,T v){transform_write(p,at,v);}
std::vector<m::Vector> source_points,source_lights;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x6525c0:check(!GPR_U32(context,4)&&GPR_U32(context,6)==0xc0&&GPR_U32(context,7)==0x55&&!GPR_U32(context,8)&&GPR_U32(context,9)==0x1a193);source_points.push_back(get<m::Vector>(memory,GPR_U32(context,5)));SET_GPR_U32(context,2,0);break;
    case 0x6b2680:check(GPR_U32(context,4)==parent_at);source_lights.push_back(get<m::Vector>(memory,GPR_U32(context,5)));break;
    case 0x582de0:check(GPR_U32(context,4)==work_at);retired=true;break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted pose cloud helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
struct Effects final:g::PoseCloudEffects {
    std::vector<m::Vector> points,light_points;unsigned reject{};
    bool visual(m::Vector p)override{points.push_back(p);return reject!=1;}
    bool light(const g::actors::EntityId&,m::Vector p)override{light_points.push_back(p);return reject!=2;}
};
bool same(const std::vector<m::Vector>& a,const std::vector<m::Vector>& b){return a.size()==b.size()&&(a.empty()||std::memcmp(a.data(),b.data(),a.size()*sizeof(m::Vector))==0);}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);Effects effects;g::Actor actor;actor.pose_work.emplace();
    for(unsigned n=0;n<262144;++n){
        actor.primary=std::uint8_t(n/65536==3?255:n/65536);actor.visible=n&1;actor.auxiliary_status=std::uint8_t(n>>8);actor.position={float(int(n%59)-29)*.125f,float(int(n%71)-35)*.25f,float(int(n%43)-21)*.5f};auto& state=*actor.pose_work;state.timer=std::bit_cast<std::int16_t>(std::uint16_t(n));state.lifetime=std::int16_t(n*13);
        memory[work_at+8]=actor.primary;memory[work_at+1]=actor.visible;memory[work_at+0x115]=std::uint8_t(actor.auxiliary_status);put(memory,work_at+0x38,actor.position);put(memory,work_at+0x28,parent_at);put(memory,work_at+12,state.timer);put(memory,work_at+18,state.lifetime);retired=false;source_points.clear();source_lights.clear();effects.points.clear();effects.light_points.clear();
        R5900Context c;PS2Runtime runtime;c.pc=0x5846c0;SET_GPR_U32(&c,4,work_at);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0x1234);original_transform_port(memory,&c,&runtime);check(c.pc==0x1234&&GPR_U32(&c,29)==0x1f00000);
        const auto step=g::advance_pose_cloud(actor,effects);check(step==(retired?g::PoseCloudStep::retire:g::PoseCloudStep::completed));check(actor.primary==memory[work_at+8]&&actor.visible==bool(memory[work_at+1])&&actor.auxiliary_status==memory[work_at+0x115]);check(state.timer==get<std::int16_t>(memory,work_at+12)&&state.lifetime==get<std::int16_t>(memory,work_at+18));check(same(effects.points,source_points)&&same(effects.light_points,source_lights));visuals+=unsigned(source_points.size());lights+=unsigned(source_lights.size());retirements+=retired;++cases;
    }
    for(unsigned rejection=1;rejection<=2;++rejection){actor.primary=0;actor.visible=true;actor.pose_work->timer=17;actor.pose_work->lifetime=2;effects.reject=rejection;check(g::advance_pose_cloud(actor,effects)==g::PoseCloudStep::unavailable&&actor.primary==1&&!actor.visible);check(actor.pose_work->timer==(rejection==1?17:75)&&actor.pose_work->lifetime==(rejection==1?2:75));}
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"retirements\":"<<retirements<<",\"visual_requests\":"<<visuals<<",\"light_requests\":"<<lights<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
