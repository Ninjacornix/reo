#include "game/native/gameplay_world/pose_motion.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <vector>
namespace g=reo::native::gameplay_world;
unsigned checks{},cases{},calls{},retirements{};bool retired{};constexpr unsigned work_at=0x20000;
void check(bool v,std::source_location p=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Pose motion "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,unsigned at,T v){transform_write(p,at,v);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x582de0:check(GPR_U32(context,4)==work_at);retired=true;break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted pose motion helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);g::Actor actor;actor.pose_work.emplace();
    for(unsigned kind:{11u,19u})for(unsigned n=0;n<262144;++n){
        actor.primary=std::uint8_t(n/65536==3?255:n/65536);actor.visible=n&1;actor.auxiliary_status=std::uint8_t(n>>8);actor.response_class=std::uint8_t(n>>8);actor.contact.serial=std::uint8_t(n>>10);actor.position={float(int(n%59)-29)*.125f,float(int(n%71)-35)*.25f,float(int(n%43)-21)*.5f};auto& state=*actor.pose_work;state.timer=std::bit_cast<std::int16_t>(std::uint16_t(n));state.lifetime=std::int16_t(n*13);state.velocity={.25f,float(int(n%37)-18)*.125f,-.5f};state.acceleration={1,float(int(n%23)-11)*.0625f,2};
        memory[work_at+8]=actor.primary;memory[work_at+1]=actor.visible;memory[work_at+0x115]=std::uint8_t(actor.auxiliary_status);memory[work_at+0x13f]=actor.response_class;memory[work_at+0x116]=actor.contact.serial;put(memory,work_at+0x38,actor.position);put(memory,work_at+12,state.timer);put(memory,work_at+18,state.lifetime);put(memory,work_at+0xc0,state.velocity);put(memory,work_at+0xcc,state.acceleration);memory[0x74f200]=std::uint8_t(n);retired=false;
        R5900Context c;PS2Runtime runtime;c.pc=kind==11?0x584160:0x583bf0;SET_GPR_U32(&c,4,work_at);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0x1234);original_transform_port(memory,&c,&runtime);check(c.pc==0x1234&&GPR_U32(&c,29)==0x1f00000);
        const auto step=g::advance_pose_motion(actor,std::uint8_t(kind),std::uint8_t(n));check(step==(retired?g::PoseMotionStep::retire:g::PoseMotionStep::completed));check(actor.primary==memory[work_at+8]&&actor.visible==bool(memory[work_at+1])&&actor.auxiliary_status==memory[work_at+0x115]);check(state.timer==get<std::int16_t>(memory,work_at+12)&&state.lifetime==get<std::int16_t>(memory,work_at+18));check(std::memcmp(&actor.position,memory+work_at+0x38,12)==0&&std::memcmp(&state.velocity,memory+work_at+0xc0,12)==0&&std::memcmp(&state.acceleration,memory+work_at+0xcc,12)==0);retirements+=retired;++cases;
    }
    actor.primary=0;actor.visible=false;actor.pose_work->timer=17;actor.pose_work->velocity.y=9;check(g::advance_pose_motion(actor,11,{})==g::PoseMotionStep::unavailable&&actor.primary==1&&actor.visible&&actor.pose_work->timer==17&&actor.pose_work->velocity.y==std::bit_cast<float>(0xbf4ccccdu));
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"retirements\":"<<retirements<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
