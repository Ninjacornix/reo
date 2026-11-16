#include "scene_anchor_reference.hpp"
#include "game/native/gameplay_application/native_session.hpp"
#include "game/native/gameplay_application/session_rooms.hpp"
#include "game/native/gameplay_application/session_scene_query_effects.hpp"
#include "game/native/gameplay_scene/records.hpp"
#include "game/native/gameplay_scenario/scene_control_types.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace app=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace scene=reo::native::gameplay_scene;
namespace scenario=reo::native::gameplay_scenario;
void unused_scene_transform(std::uint8_t*,R5900Context* context,PS2Runtime*){context->pc=GPR_U32(context,31);}
void local_control_gate(std::uint8_t*,R5900Context* context,PS2Runtime*){SET_GPR_U32(context,2,1);context->pc=GPR_U32(context,31);}
namespace {
unsigned cases{},checks{};
struct Notices final:scenario::FlagNotifications {
 bool changed(const scenario::ScenarioFlagChange&)noexcept override{return true;}
 bool changed(const scenario::StridedFlagChange&)noexcept override{return true;}
} notices;
struct Memory final:reo::assets::PositionedSource {
 std::vector<std::uint8_t> bytes;
 std::uint64_t size()const noexcept override{return bytes.size();}
 std::size_t read(std::uint64_t at,std::size_t n,void* out)const override{
  if(at>bytes.size()||n>bytes.size()-at)throw std::runtime_error("fixture source range");
  std::memcpy(out,bytes.data()+at,n);return n;
 }
};
std::shared_ptr<const reo::assets::Source> archive(){
 auto m=std::make_shared<Memory>();m->bytes.resize(6*4096);auto& b=m->bytes;
 std::memcpy(b.data(),"AFS\0",4);reo::assets::put32(b.data()+4,5);
 const std::array names{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs"};
 for(unsigned i=0;i<5;++i){auto base=4096*(i+1);reo::assets::put32(b.data()+8+8*i,base);reo::assets::put32(b.data()+12+8*i,4096);std::memcpy(b.data()+512+48*i,names[i],8);std::memcpy(b.data()+base,"AFS\0",4);reo::assets::put32(b.data()+base+4,1);reo::assets::put32(b.data()+base+8,2048);reo::assets::put32(b.data()+base+12,1);}
 reo::assets::put32(b.data()+48,512);reo::assets::put32(b.data()+52,5*48);
 return std::make_shared<const reo::assets::Source>("type6 early-exit fixture",m);
}
void check(bool value,const char* label){++checks;if(!value){std::fprintf(stderr,"5C4940 mismatch case=%u: %s\n",cases,label);std::exit(1);}}
void run(std::uint8_t category,std::uint32_t mode){
 ++cases;std::vector<std::uint8_t> ram(0x800000);constexpr std::uint32_t proxy=0x50000,actor_addr=0x60000;
 ref_write(ram.data(),proxy+0x34,actor_addr);ref_write(ram.data(),proxy+0x4c,mode);ram[actor_addr+2]=category;
 for(unsigned i=0;i<0x40;++i)ram[actor_addr+0xab0+i]=std::uint8_t(i*7+3);
 auto before=ram;R5900Context context{};SET_GPR_U32(&context,29,0x70000);SET_GPR_U32(&context,31,0xdeadbeef);SET_GPR_U32(&context,4,proxy);PS2Runtime runtime;
 o2_005C4940_0x5c4940(ram.data(),&context,&runtime);
 check(context.pc==0xdeadbeef,"original returns");
 check(std::equal(ram.begin()+actor_addr,ram.begin()+actor_addr+0x1000,before.begin()+actor_addr),"original early return leaves actor record unchanged");
 for(auto address:{0x4bae05u,0x4bae07u,0x3243e0u,0x3243e2u})check(ref_read<std::uint16_t>(ram.data(),address)==ref_read<std::uint16_t>(before.data(),address),"original early return leaves transition globals unchanged");
 w::Profile profile;profile.layouts.push_back({});auto host=std::make_shared<app::NativeSession>(archive(),std::move(profile),notices,0);app::SessionRooms rooms(host);app::SessionSceneQueryEffects effects(*host,rooms);
 auto& world=host->world();world.mode=0;world.session().scenario=19;w::Actor native_actor;native_actor.category=category;native_actor.interaction_request=w::InteractionRequest{};native_actor.transient_action=0;native_actor.scene_model=scenario::ModelReference{37};
 scene::Record record;record.body=scenario::ControlTypeSix{0,0,0};record.ladder_entry=scene::LadderEntryDetails{mode,scenario::ModelReference{0}};
 const auto old_request=*native_actor.interaction_request;const auto old_model=native_actor.scene_model;const bool had_transition=bool(world.session().scene_transition_publication);
 const auto result=effects.dispatch(world,native_actor,{},record);
 check(result&&*result,"native early return completes");check(native_actor.interaction_request->kind==old_request.kind&&native_actor.interaction_request->parameter==old_request.parameter&&native_actor.interaction_request->anchor.x==old_request.anchor.x&&native_actor.interaction_request->anchor.y==old_request.anchor.y&&native_actor.interaction_request->anchor.z==old_request.anchor.z,"native request unchanged");
 check(native_actor.transient_action==0&&native_actor.scene_model==old_model,"native actor outputs unchanged");check(bool(world.session().scene_transition_publication)==had_transition,"native transition presence unchanged");
}
void run_positive_special_transition(const char* asset_path){
 ++cases;constexpr std::uint32_t proxy=0x50000,actor_addr=0x60000;
 auto source=std::make_shared<const reo::assets::Source>(asset_path);w::Profile profile;profile.layouts.push_back({});
 auto host=std::make_shared<app::NativeSession>(source,std::move(profile),notices,0);
 check(host->install_room({41,73,0})==app::SessionStatus::completed,"positive type6 room and matrix import");
 const auto imported=host->scene_matrices().inspect(0);check(bool(imported),"positive type6 matrix index zero available");
 std::vector<std::uint8_t> ram(0x800000);ref_write(ram.data(),proxy+0x34,actor_addr);
 ref_write(ram.data(),proxy+0x4c,std::uint32_t(5));ref_write(ram.data(),proxy+0x48,std::uint32_t(0x2345));
 ref_write(ram.data(),proxy+0x58,std::uint32_t(0x5678));ref_write(ram.data(),proxy+0x5c,std::uint32_t(0x36));ref_write(ram.data(),proxy+0x60,std::uint32_t(0));
 ram[actor_addr+2]=0;ram[actor_addr+0x54f]=0x1a;ram[actor_addr+0xab8]=0xa1;ram[actor_addr+0xab9]=0xa2;ram[actor_addr+0xaba]=0xa3;
 ref_write(ram.data(),0x3243da,std::uint16_t(0x1234));ref_write(ram.data(),0x3243e0,std::uint16_t(0xaaaa));ref_write(ram.data(),0x3243e2,std::uint16_t(0xbbbb));
 ram[0x4bae05]=0xc1;ram[0x4bae07]=0xc2;
 R5900Context context{};SET_GPR_U32(&context,29,0x70000);SET_GPR_U32(&context,31,0xdeadbeef);SET_GPR_U32(&context,4,proxy);PS2Runtime runtime;
 o2_005C4940_0x5c4940(ram.data(),&context,&runtime);
 check(context.pc==0xdeadbeef,"positive original callback returns");
 check(ram[actor_addr+0xab8]==1&&ram[actor_addr+0xab9]==0x10&&ram[actor_addr+0xaba]==1,"original mode5 special actor request output");
 check(ref_read<std::uint16_t>(ram.data(),0x3243e0)==0x1234&&ref_read<std::uint16_t>(ram.data(),0x3243e2)==0x5678,"original scenario transition output");
 check(ram[0x4bae05]==0x36&&ram[0x4bae07]==4,"original transition publication bytes");

 auto& world=host->world();world.mode=0;world.session().scenario=0x1234;w::Actor actor;actor.category=0;actor.slot=0;actor.motion_class=0x1a;
 actor.interaction_request=w::InteractionRequest{};actor.transient_action=0;actor.scene_model=scenario::ModelReference{37};
 scene::Record record;record.body=scenario::ControlTypeSix{0,0x36,0};record.other_content=0x2345;record.other_resource_class=0x5678;
 record.collision=scene::CollisionShape{};record.ladder_entry=scene::LadderEntryDetails{5,scenario::ModelReference{0}};
 app::SessionRooms rooms(host);app::SessionSceneQueryEffects effects(*host,rooms);const auto result=effects.dispatch(world,actor,{},record);
 check(result&&*result,"native positive type6 callback completes");
 check(actor.transient_action==ram[actor_addr+0xab8]&&actor.interaction_request->kind==ram[actor_addr+0xab9]&&actor.interaction_request->parameter==ram[actor_addr+0xaba],"native request matches original actor bytes");
 check(world.session().scene_transition_publication.has_value(),"native transition publication present");
 const auto& transition=*world.session().scene_transition_publication;
 check(transition.kind==ram[0x4bae07]&&transition.variant==ram[0x4bae05]&&transition.scenario==ref_read<std::uint16_t>(ram.data(),0x3243e0)&&transition.destination==0x5678,"native transition matches original publications");
}
}
void original_port(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("unexpected original helper reached");}
int main(int argc,char** argv){
 if(argc!=2){std::fprintf(stderr,"usage: scene-anchor-original <NETBIO00.DAT>\n");return 2;}
 for(auto category:{std::uint8_t(0),std::uint8_t(1)})run(category,3);
 for(auto category:{std::uint8_t(2),std::uint8_t(255)})for(std::uint32_t mode:{0u,3u,4u,5u,6u})run(category,mode);
 run_positive_special_transition(argv[1]);
 std::printf("{\"original\":\"5C4940 source callback and controlled positive mode5 path\",\"cases\":%u,\"checks\":%u,\"game_run\":false}\n",cases,checks);
}
