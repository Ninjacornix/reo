#include "game/native/gameplay_world/pose_trail_admission.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <vector>
namespace g=reo::native::gameplay_world;
unsigned checks{},cases{},calls{},no_effect{},required{},constructors{},floor_queries{};unsigned requested{},queried{},resource{};
constexpr unsigned parent_at=0x20000,motion_at=0x22000;
void check(bool v,std::source_location p=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Pose trail admission "+std::to_string(p.line())+" case "+std::to_string(cases));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x6525c0:case 0x6525d0:resource=GPR_U32(context,7);check(resource<512&&GPR_U32(context,6)==memory[0x7123a0+resource]&&!GPR_U32(context,8)&&GPR_U32(context,9)==0x1a193);if(context->pc==0x6525d0)check(GPR_U32(context,10)==0x5789c0);SET_GPR_U32(context,2,0);++requested;break;
    case 0x616f20:check(GPR_U32(context,6)==0x81);memory[GPR_U32(context,5)]=0x81;context->f[0]=42;++queried;break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted pose trail helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
struct Consumer final:g::PoseTrails {g::World& world;unsigned calls{};explicit Consumer(g::World& w):world(w){}bool bound_to(const g::World& w)const noexcept override{return &world==&w;}bool emit(const g::actors::EntityId&,const g::actors::EntityId&,std::uint8_t)override{++calls;return false;}};
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);g::Profile p;p.layouts.push_back({});p.entities.capacity=16;g::World world(p,std::make_shared<g::Session>());const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(id));g::PoseTrailAdmission admission(world);Consumer consumer(world);g::PoseTrailAdmission composed(world,&consumer);
    for(unsigned mode=0;mode<256;++mode)for(unsigned type=0;type<256;++type){
        world.resolve(id)->slot=memory[parent_at+3]=std::uint8_t(type);requested=queried=0;resource=0;R5900Context context;PS2Runtime runtime;context.pc=0x578620;SET_GPR_U32(&context,4,parent_at);SET_GPR_U32(&context,5,motion_at);SET_GPR_U32(&context,6,mode);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
        const auto selection=g::select_pose_trail(std::uint8_t(type),std::uint8_t(mode));check(bool(selection)==bool(requested));check(admission.emit(id,{},std::uint8_t(mode))==!bool(requested));const auto before=consumer.calls;check(composed.emit(id,{},std::uint8_t(mode))==!bool(requested)&&consumer.calls-before==unsigned(bool(requested)));
        if(selection){check(selection->resource==resource&&requested==(mode==1?5u:1u));++required;}else{check(!queried);++no_effect;}constructors+=requested;floor_queries+=queried;++cases;
    }
    check(required==15&&constructors==35&&floor_queries==1);check(admission.emit({}, {},4)&&!admission.emit({}, {},0));check(world.retire_primary(0)==g::actors::EntityStatus::completed&&!admission.emit(id,{},0));check(world.close()==g::Status::completed&&!admission.bound_to(world)&&!admission.emit({}, {},4));
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"no_effect\":"<<no_effect<<",\"required_consumer\":"<<required<<",\"constructor_attempts\":"<<constructors<<",\"floor_queries\":"<<floor_queries<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
