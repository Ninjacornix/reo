#include "game/native/gameplay_world/linked_pose_timing.hpp"
#include "game/native/gameplay_world/linked_updates.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;namespace c=reo::native::gameplay_collision;
unsigned checks{},cases{},calls{},boundaries{};
void check(bool value,std::source_location p=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Linked pose timing "+std::to_string(p.line())+" case "+std::to_string(cases));}
std::vector<std::byte> grid(std::uint8_t type){std::vector<std::byte> out(120);const auto write=[&]<class T>(unsigned at,T v){std::memcpy(out.data()+at,&v,sizeof v);};write(8,1024u);write(12,1024u);write(16,1u);write(20,1u);write(32,32u);write(36,56u);write(40,40u);write(48,0u);write(52,UINT32_MAX);write(64,unsigned(type));write(68,c::Vec3{-100,0,-100});write(80,c::Vec3{-100,0,1000});write(92,c::Vec3{1000,0,-100});write(104,c::Vec3{0,1,0});return out;}

void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++calls;switch(context->pc){
 case 0x6409c0:case 0x6409d0:++boundaries;break;
#include "original_dispatch.hpp"
 default:throw std::runtime_error("Unadmitted linked timing helper "+std::to_string(context->pc));
 }context->pc=GPR_U32(context,31);
}
int main()try{
 std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();g::Profile p;p.layouts.push_back({});auto session=std::make_shared<g::Session>();g::World world(p,session);g::LinkedPoseTimingQuantum timing(world);const auto floors=std::make_shared<const c::response::Grid>(c::response::Grid::import(grid(0)));g::LinkedActorUpdates linked(world,{},floors);
 check(timing.bound_to(world)&&!timing.read());std::optional<std::uint8_t> last;
 for(unsigned mode=0;mode<256;++mode){
  session->clock_mode=std::uint8_t(mode);check(timing.read()==last);for(unsigned i=0;i<4;++i){session->linked_updates.work_counters[i]=std::uint8_t(mode+i);memory[0x755350+i]=std::uint8_t(mode+i);}memory[0x3243cc]=std::uint8_t(mode);memory[0x4bae02]=0;memory[0x3b5040]=0;memory[0x37fd80]=5;
  R5900Context context;PS2Runtime runtime;context.pc=0x6bbba0;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);const auto result=linked.run();check(result.status==g::LinkedUpdateStatus::completed&&!result.periodic&&!result.visited&&!result.called);last=memory[0x74f200];check(timing.read()==last&&*last==(mode?2:1));for(unsigned i=0;i<4;++i)check(session->linked_updates.work_counters[i]==memory[0x755350+i]);const auto before=session->linked_updates;session->clock_mode=std::uint8_t(mode^255);check(timing.read()==last&&session->linked_updates.clock_factor==before.clock_factor&&session->linked_updates.work_counters==before.work_counters&&session->linked_updates.expiry_countdown==before.expiry_countdown);++cases;
 }
 check(boundaries==512);check(linked.close()==g::LinkedUpdateStatus::completed);check(world.close()==g::Status::completed&&!timing.bound_to(world)&&!timing.read());std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"renderer_boundaries\":"<<boundaries<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
