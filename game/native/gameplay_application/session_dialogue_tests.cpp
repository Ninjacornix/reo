#include "session_dialogue.hpp"
#include "../gameplay_world/primary_actor_records.hpp"
#include "runtime/assets/virtual_afs.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
namespace app=reo::native::gameplay_application;namespace w=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;namespace s=reo::native::gameplay_scenario;
namespace {
unsigned checks{};void check(bool value,const char* role="contract"){++checks;if(!value)throw std::runtime_error("Canonical session dialogue "+std::to_string(checks)+": "+role);}
w::Profile profile(){w::Profile p;p.layouts.push_back({});return p;}
struct Catalog final:reo::assets::PositionedSource {std::vector<std::uint8_t> bytes;std::uint64_t size()const noexcept override{return bytes.size();}std::size_t read(std::uint64_t at,std::size_t n,void* out)const override{if(at>bytes.size()||n>bytes.size()-at)throw std::runtime_error("Dialogue catalog bounds");std::memcpy(out,bytes.data()+at,n);return n;}};
std::shared_ptr<const reo::assets::Source> catalog(){auto data=std::make_shared<Catalog>();data->bytes.resize(6*4096);auto& b=data->bytes;std::memcpy(b.data(),"AFS\0",4);reo::assets::put32(b.data()+4,5);const std::array names{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs"};for(unsigned i=0;i<5;++i){const auto at=4096*(i+1);reo::assets::put32(b.data()+8+8*i,at);reo::assets::put32(b.data()+12+8*i,4096);std::memcpy(b.data()+512+48*i,names[i],8);std::memcpy(b.data()+at,"AFS\0",4);reo::assets::put32(b.data()+at+4,1);reo::assets::put32(b.data()+at+8,2048);reo::assets::put32(b.data()+at+12,1);}reo::assets::put32(b.data()+48,512);reo::assets::put32(b.data()+52,240);return std::make_shared<const reo::assets::Source>("session-dialogue-catalog",data);}
struct Notifications final:s::FlagNotifications {bool changed(const s::ScenarioFlagChange&)noexcept override{return false;}bool changed(const s::StridedFlagChange&)noexcept override{return false;}};
struct UnboundAudio final:s::StreamBackend {
 s::StreamValue phase(std::uint8_t)noexcept override{return{s::StreamStatus::unbound,0};}
 s::StreamStatus start(std::uint8_t,s::StreamRequest,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus stop(std::uint8_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus pause(std::uint8_t,bool,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus attenuation(std::uint8_t,std::int32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus service(std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
};
struct Remaining final:u::PhaseServices {
 app::SessionDialogue* dialogue{};app::NativeSession* session{};w::Services* actors{};unsigned calls{},busy_checks{};
 void run(u::Worker stage,u::Owner& owner)override{++calls;check(!session||&owner==&session->update());if(stage==u::Worker::room_sound_callbacks&&dialogue){check(dialogue->close()==w::DialogueStatus::busy&&dialogue->cold_clear()==w::DialogueStatus::busy&&dialogue->clear_text_cache()==w::DialogueStatus::busy&&dialogue->advance(actors).status==app::SessionStatus::busy&&session->close()==app::SessionStatus::busy);++busy_checks;}}
 bool button(u::Button,u::Owner&)override{return true;}bool transition_request(u::Owner&)override{return false;}void effect(u::PhaseEffect,u::Owner&,std::uint32_t)override{}
};
struct InactiveActors final:w::Services {void begin_offline_frame(w::World&)override{throw std::runtime_error("Unexpected offline actors");}void run(w::Stage,w::World&,w::Actor&)override{throw std::runtime_error("Unexpected active actor");}bool remote_motion(w::World&,w::Actor&)override{throw std::runtime_error("Unexpected remote actor");}bool find_grid(w::World&,w::Actor&,std::int8_t&)override{throw std::runtime_error("Unexpected grid query");}void switch_grid(w::World&,std::int32_t,std::int32_t)override{throw std::runtime_error("Unexpected grid switch");}float grid_response(w::World&,std::uint8_t)override{throw std::runtime_error("Unexpected grid response");}};
}
int main(int argc,char** argv)try{
 check(argc==1||argc==2);auto source=argc==2?std::make_shared<const reo::assets::Source>(argv[1]):catalog();Notifications notifications;app::NativeSession session(source,profile(),notifications),other(source,profile(),notifications);check(w::initialize_primary_records(session.world()).status==w::PrimaryRecordsStatus::completed);session.world().session().primary_population=2;session.world().primary(1)->slot=session.world().primary(1)->character=1;
 UnboundAudio backend;s::StreamChannels channels(s::file1_stream_gain_curve()),foreign_channels(s::file1_stream_gain_curve());reo::native::gameplay_audio::SpatialContext spatial;std::optional<std::uint32_t> tick;w::ActorVoiceRequests voice(session.world(),channels,backend,spatial,tick),foreign_voice(other.world(),foreign_channels,backend,spatial,tick);Remaining remaining;InactiveActors actors;w::input::Frame menu;std::optional<std::uint32_t> actions=0;
 bool refused{};try{app::SessionDialogue invalid(session,foreign_voice,remaining,&menu,actions);}catch(const std::invalid_argument&){refused=true;}check(refused);
 app::SessionDialogue dialogue(session,voice,remaining,&menu,actions);check(dialogue.open()&&dialogue.bound_to(session)&&!dialogue.bound_to(other)&&!dialogue.text_cache().initialized());refused=false;try{app::SessionDialogue duplicate(session,voice,remaining,&menu,actions);}catch(const std::invalid_argument&){refused=true;}check(refused);
 check(dialogue.cold_clear()==w::DialogueStatus::completed&&dialogue.pool().record(0)&&!dialogue.pool().bank_snapshot());check(dialogue.clear_text_cache()==w::DialogueStatus::completed&&dialogue.text_cache().initialized());remaining.dialogue=&dialogue;remaining.session=&session;remaining.actors=&actors;
 check(dialogue.advance(&actors).status==app::SessionStatus::missing_room);
 if(argc==2){
  session.world().mode=1; // This inactive-actor fixture uses the normal script coordinator.
  check(session.install_room({41,73,0})==app::SessionStatus::completed);session.update().state.scripts_enabled=false;check(session.update().initialize_completion_statistics()==reo::native::gameplay_events::StatisticsStatus::completed);check(session.inventory_ui().configure_requests(1)==w::InventoryUiStatus::completed);auto& shared=session.world().session().auxiliary_scene;check(shared.set_timer(91,true));
  const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{{std::byte{1},{},{},{},std::byte{0xa},{},{},{}}});
  check(session.update().scripts().install(0,program)==s::Status::completed&&session.update().scripts().install(1,program)==s::Status::completed,"controlled script channels");
  const auto step=dialogue.advance(&actors);if(step.status!=app::SessionStatus::completed)std::cerr<<"Step status "<<int(step.status)<<" update "<<int(step.update.status)<<" callbacks "<<remaining.calls<<"\n";check(step.status==app::SessionStatus::completed&&step.update.clock_committed&&dialogue.last_response()&&dialogue.last_response()->status==w::DialogueStatus::completed&&shared.timer(91)==1&&remaining.busy_checks==1,"complete inactive-actor frame");
  const auto bank=session.archive().scenario_scripts(41);check(bool(bank));session.world().session().asset_loading_mode=1;session.world().session().room_variant.reset();const auto loaded=dialogue.finish_banks(*bank);check(loaded.status==w::DialogueStatus::completed&&loaded.section&&shared.timer(91)==1);const auto retained=dialogue.pool().bank_snapshot();check(loaded.cache_hit||retained);if(retained)check((*retained)[8].cues||loaded.loaded==0);
  check(dialogue.finish_banks(*bank).cache_hit);const auto cache=dialogue.text_cache().snapshot();check(cache&&session.close()==app::SessionStatus::completed&&!dialogue.open()&&dialogue.cold_clear()==w::DialogueStatus::closed&&dialogue.clear_text_cache()==w::DialogueStatus::closed&&dialogue.finish_banks(*bank).status==w::DialogueStatus::closed&&dialogue.advance(&actors).status==app::SessionStatus::closed);check(cache->size()==s::TextCache::capacity);
 }
 check(dialogue.close()==w::DialogueStatus::completed&&!dialogue.open()&&dialogue.advance(&actors).status==app::SessionStatus::closed);check(session.close()==app::SessionStatus::completed);std::cout<<"Canonical session dialogue passed "<<checks<<" checks\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
