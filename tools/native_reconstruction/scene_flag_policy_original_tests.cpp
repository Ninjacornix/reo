#include "scene_flag_policy_reference.hpp"
#include "game/native/gameplay_application/native_session.hpp"
#include "game/native/gameplay_application/session_rooms.hpp"
#include "game/native/gameplay_application/session_scene_query_effects.hpp"
#include "game/native/gameplay_scene/records.hpp"
#include "game/native/gameplay_scenario/scene_control_types.hpp"
#include "runtime/assets/virtual_afs.h"
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {
std::vector<std::uint32_t> notifications, events;
unsigned checks{}, cases{};
namespace app=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace scene=reo::native::gameplay_scene;
namespace scenario=reo::native::gameplay_scenario;
struct NativeNotices final:scenario::FlagNotifications {
 std::vector<scenario::ScenarioFlagChange> changes;
 bool changed(const scenario::ScenarioFlagChange& value)noexcept override{changes.push_back(value);return true;}
 bool changed(const scenario::StridedFlagChange&)noexcept override{return true;}
} native_notices;
struct MemorySource final:reo::assets::PositionedSource {
 std::vector<std::uint8_t> bytes;
 std::uint64_t size()const noexcept override{return bytes.size();}
 std::size_t read(std::uint64_t at,std::size_t count,void* out)const override{
  if(at>bytes.size()||count>bytes.size()-at)throw std::runtime_error("fixture archive range");
  std::memcpy(out,bytes.data()+at,count);return count;
 }
};
std::shared_ptr<const reo::assets::Source> native_archive(){
 auto memory=std::make_shared<MemorySource>();memory->bytes.resize(6*4096);auto& b=memory->bytes;
 std::memcpy(b.data(),"AFS\0",4);reo::assets::put32(b.data()+4,5);
 const std::array names{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs"};
 for(unsigned i=0;i<5;++i){const auto base=4096*(i+1);reo::assets::put32(b.data()+8+8*i,base);reo::assets::put32(b.data()+12+8*i,4096);std::memcpy(b.data()+512+48*i,names[i],8);std::memcpy(b.data()+base,"AFS\0",4);reo::assets::put32(b.data()+base+4,1);reo::assets::put32(b.data()+base+8,2048);reo::assets::put32(b.data()+base+12,1);}
 reo::assets::put32(b.data()+48,512);reo::assets::put32(b.data()+52,5*48);
 return std::make_shared<const reo::assets::Source>("5C3FE0 fixture",memory);
}
std::shared_ptr<app::NativeSession> native_session;
std::unique_ptr<app::SessionRooms> native_rooms;
std::unique_ptr<app::SessionSceneQueryEffects> native_effects;
void check(bool value,const char* text){++checks;if(!value){std::fprintf(stderr,"5C3FE0 original mismatch case=%u: %s\n",cases,text);std::exit(1);}}
R5900Context make_context(){R5900Context c{};SET_GPR_U32(&c,29,0x70000);SET_GPR_U32(&c,31,0xdeadbeef);return c;}
void run(std::uint8_t* pristine,std::uint8_t category,std::uint8_t mode,std::uint8_t slot,
         std::uint8_t selected,std::uint8_t character,std::uint8_t gate,std::uint32_t expected,
         std::uint32_t inequality,std::uint32_t operation,std::uint16_t event){
 ++cases;std::vector<std::uint8_t> ram(pristine,pristine+0x800000);constexpr std::uint32_t proxy=0x50000,actor=0x60000,id=37;
 ref_write(ram.data(),proxy+0x34,actor);ref_write(ram.data(),proxy+0x40,id);ref_write(ram.data(),proxy+0x44,operation);
 ref_write(ram.data(),proxy+0x4c,std::uint32_t(gate));ref_write(ram.data(),proxy+0x50,expected);ref_write(ram.data(),proxy+0x54,inequality);ref_write(ram.data(),proxy+0x58,std::uint32_t(event));
 ram[actor+2]=category;ram[actor+3]=slot;ram[actor+0xb98]=character;ram[0x3243f2]=mode;ram[0x4baded]=selected;
 std::memset(ram.data()+0x4b9c00,0,0x80);std::memset(ram.data()+0x4b9a80,0,0x400);
 notifications.clear();events.clear();auto c=make_context();SET_GPR_U32(&c,4,proxy);PS2Runtime runtime;o2_005C3FE0_0x5c3fe0(ram.data(),&c,&runtime);
 check(c.pc==0xdeadbeef,"function return");
 const bool local=category==0&&slot==(mode==0?0:selected);
 bool admit=category==0;
 if(admit)switch(gate){case 0:break;case 1:admit=(std::uint32_t(slot!=expected)==inequality);break;
 case 2:admit=(std::uint32_t(character!=expected)==inequality);break;case 3:admit=mode==0&&!local;break;case 4:admit=local;break;default:break;}
 const bool scene=admit&&(operation==0||operation==2);const bool actor_flag=admit&&(operation==1||operation==3)&&(mode==0||local);
 const auto mask=std::uint32_t(1)<<(id&31);const auto scene_word=ref_read<std::uint32_t>(ram.data(),0x4b9c00+(id/32)*4);
 check(bool(scene_word&mask)==scene,"scenario flag bank");
 const std::uint8_t bank=mode==0?slot:0;const auto actor_word=ref_read<std::uint32_t>(ram.data(),0x4b9a80+bank*64+(id/32)*4);
 check(bool(actor_word&mask)==actor_flag,"actor flag bank");
 if(scene){check(notifications.size()==3,"selected actor notification count");check(notifications[0]==id&&notifications[1]==1&&notifications[2]==std::uint8_t(selected+1),"selected actor notification args");}
 else check(notifications.empty(),"no notification when scenario flag skipped");
 const bool text=admit&&(operation==2||operation==3)&&event!=0xffff&&local;
 if(text){check(events.size()==3&&events[0]==event&&events[1]==60&&events[2]==4,"570120 event/60/4 args");}
 else check(events.empty(),"no event on skipped branch");

 // Directly invoke the product callback with the same canonical inputs. This
 // compares the actual session-owned flag and text owners, not a copied policy.
 auto& flags=native_session->update().flags();flags.restore({});native_notices.changes.clear();
 auto& native_world=native_session->world();native_world.mode=mode;native_world.selected_actor=selected;
 w::Actor native_actor;native_actor.category=category;native_actor.slot=slot;native_actor.character=character;
 scene::Record native_record;native_record.authored_id=id;native_record.body=scenario::ControlTypeThree{operation,0xffff};
 native_record.flag_policy=scene::FlagPolicyCallback{gate,expected,inequality,event};
 const auto result=native_effects->dispatch(native_world,native_actor,{},native_record);
 const bool native_scene=flags.get(scenario::FlagBank::scenario,id).value_or(false);
 check(native_scene==scene,"native scenario flag bank");
 const auto native_bank=std::uint8_t(mode==0?slot:0);
 check(flags.actor_flag(scenario::ActorFlagFamily::primary,std::uint8_t(native_bank+1),id).value_or(false)==actor_flag,"native primary actor flag bank");
 if(native_notices.changes.size()!=notifications.size()/3)std::fprintf(stderr,"notice sizes native=%zu original-words=%zu result=%d native-scene=%d expected-scene=%d category=%u mode=%u slot=%u gate=%u op=%u\n",native_notices.changes.size(),notifications.size(),int(result.has_value()&&*result),int(native_scene),int(scene),unsigned(category),unsigned(mode),unsigned(slot),unsigned(gate),unsigned(operation));
 check(native_notices.changes.size()==notifications.size()/3,"native scenario notification count");
 if(scene&&!native_notices.changes.empty()){
   const auto& change=native_notices.changes.front();
   check(change.id==notifications[0]&&change.value==notifications[1]&&change.actor_owner==notifications[2],"native notification arguments");
 }
 if(text){
   check(!result.has_value(),"unloaded typed text catalog refuses after flag prefix");
   check((scene?native_scene:actor_flag)&&native_session->timed_scene_text().snapshot().tasks==0,"text refusal preserves flag prefix and queues no task");
 }else check(result.has_value()&&*result,"native callback completed without unavailable text request");
}

void run_inventory(std::uint8_t* pristine,std::uint8_t category,std::uint8_t mode,
                   std::uint8_t slot,std::uint8_t selected,std::uint8_t gate,
                   std::uint32_t expected,std::uint32_t inequality,
                   std::uint32_t operation){
 ++cases;std::vector<std::uint8_t> ram(pristine,pristine+0x800000);
 constexpr std::uint32_t proxy=0x51000,actor=0x61000,id=83;
 ref_write(ram.data(),proxy+0x34,actor);ref_write(ram.data(),proxy+0x40,id);
 ref_write(ram.data(),proxy+0x4c,operation);ref_write(ram.data(),proxy+0x58,std::uint32_t(gate));
 ref_write(ram.data(),proxy+0x5c,expected);ref_write(ram.data(),proxy+0x60,inequality);
 ref_write(ram.data(),proxy+0x64,std::uint32_t(0));ref_write(ram.data(),proxy+0x68,0xffffffffu);
 ref_write(ram.data(),proxy+0x48,19);ref_write(ram.data(),proxy+0x54,23);
 ram[actor+2]=category;ram[actor+3]=slot;ram[actor+0xb98]=7;ram[0x3243f2]=mode;ram[0x4baded]=selected;
 std::memset(ram.data()+0x4b9c00,0,0x80);std::memset(ram.data()+0x4b9a80,0,0x400);
 notifications.clear();events.clear();auto c=make_context();SET_GPR_U32(&c,4,proxy);PS2Runtime runtime;o2_005C4230_0x5c4230(ram.data(),&c,&runtime);
 check(c.pc==0xdeadbeef,"5C4230 function return");
 const bool local=category==0&&slot==(mode==0?0:selected);
 bool admit=category==0;
 if(admit)switch(gate){case 0:break;case 1:admit=(std::uint32_t(slot!=expected)==inequality);break;
 case 2:admit=(std::uint32_t(7u!=expected)==inequality);break;
 case 3:admit=mode==0&&!local;break;case 4:admit=local;break;default:break;}
 const bool scenario=admit&&operation==0;
 const auto mask=std::uint32_t(1)<<(id&31);const auto original_word=ref_read<std::uint32_t>(ram.data(),0x4b9c00+(id/32)*4);
 check(bool(original_word&mask)==scenario,"5C4230 scenario flag bank");
 if(scenario){check(notifications.size()==3&&notifications[0]==id&&notifications[1]==1&&notifications[2]==std::uint8_t(selected+1),"5C4230 notify args");}
 else check(notifications.empty(),"5C4230 no notification");

 auto& flags=native_session->update().flags();flags.restore({});native_notices.changes.clear();
 auto& native_world=native_session->world();native_world.mode=mode;native_world.selected_actor=selected;
 w::Actor native_actor;native_actor.category=category;native_actor.slot=slot;native_actor.character=7;
 scene::Record native_record;native_record.authored_id=id;native_record.body=scenario::ControlTypeFour{operation,0};
 native_record.inventory_policy=scene::InventoryPolicyCallback{gate,expected,inequality,operation,0,23,0xffffffffu};
 const auto result=native_effects->dispatch(native_world,native_actor,{},native_record);
 check(result.has_value()&&bool(*result)==(category!=0||admit),"5C4230 native admission result");
 check(flags.get(scenario::FlagBank::scenario,id).value_or(false)==scenario,"5C4230 native scenario flag");
 check(native_notices.changes.size()==notifications.size()/3,"5C4230 native notify count");
 if(scenario&&!native_notices.changes.empty()){
   const auto& change=native_notices.changes.front();
   check(change.id==notifications[0]&&change.value==notifications[1]&&change.actor_owner==notifications[2],"5C4230 native notify args");
 }
}
}

void original_port(std::uint8_t* rdram,R5900Context* c,PS2Runtime*){
 const auto at=c->pc;
 if(at==0x1b02d0){SET_GPR_U32(c,2,READ8(0x3243f2)==0);}
 else if(at==0x1b0340){const auto actor=GPR_U32(c,4);SET_GPR_U32(c,2,READ8(actor+2)==0&&READ8(actor+3)==(READ8(0x3243f2)==0?0:READ8(0x4baded)));}
 else if(at==0x67dbd0){notifications.insert(notifications.end(),{GPR_U32(c,4),GPR_U32(c,5),GPR_U32(c,6)});SET_GPR_U32(c,2,0);}
 else if(at==0x570120){events.insert(events.end(),{GPR_U32(c,4),GPR_U32(c,5),GPR_U32(c,6)});SET_GPR_U32(c,2,0);}
 else {std::fprintf(stderr,"unexpected original call 0x%x\n",at);std::exit(2);}
 c->pc=GPR_U32(c,31);
}

int main(){
 reo::native::gameplay_world::Profile profile;profile.layouts.push_back({});
 native_session=std::make_shared<app::NativeSession>(native_archive(),std::move(profile),native_notices,0);
 native_rooms=std::make_unique<app::SessionRooms>(native_session);
 native_effects=std::make_unique<app::SessionSceneQueryEffects>(*native_session,*native_rooms);
 check(bool(native_session->world().spawn_primary(0,std::make_unique<w::Actor>()).id),"selected publication actor fixture");
 std::vector<std::uint8_t> image(0x800000);
 // The generated bodies touch only their owned globals and the fixture.  Each
 // case receives a clean image so original calls cannot leak state across rows.
 for(std::uint8_t category:{std::uint8_t(0),std::uint8_t(1)})
 for(auto [mode,slot]:std::array<std::pair<std::uint8_t,std::uint8_t>,3>{{{0,0},{0,1},{1,0}}})
 for(std::uint8_t gate=0;gate<=5;++gate)
 for(std::uint32_t op=0;op<=4;++op)
 for(std::uint16_t event:{std::uint16_t(0xffff),std::uint16_t(73)}){
   const std::uint8_t selected=0,character=7;
   for(auto [expected,inequality]:std::array<std::pair<std::uint32_t,std::uint32_t>,4>{{{slot,1},{slot,0},{character,1},{character,0}}})
     run(image.data(),category,mode,slot,selected,character,gate,expected,inequality,op,event);
 }
 for(std::uint8_t category:{std::uint8_t(0),std::uint8_t(1)})
 for(auto [mode,slot]:std::array<std::pair<std::uint8_t,std::uint8_t>,2>{{{0,1},{1,1}}})
 for(std::uint8_t gate=0;gate<=5;++gate)
 for(std::uint32_t operation:{0u,4u})
 for(auto [expected,inequality]:std::array<std::pair<std::uint32_t,std::uint32_t>,4>{{{slot,1},{slot,0},{7,1},{7,0}}})
   run_inventory(image.data(),category,mode,slot,0,gate,expected,inequality,operation);
 std::printf("{\"original\":\"5C3FE0+5C4230\",\"cases\":%u,\"checks\":%u,\"complete_helpers\":true,\"game_run\":false}\n",cases,checks);
}
