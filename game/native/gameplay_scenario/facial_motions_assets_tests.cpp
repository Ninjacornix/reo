#include "facial_motions.hpp"
#include "cutscene_playback.hpp"
#include "flags.hpp"
#include "../animation/model.hpp"
#include "../../../runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <map>
#include <source_location>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;namespace a=reo::native::animation;
std::uint64_t checks{},frames{},patches{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Facial native assets line "+std::to_string(at.line()));}
struct Backend final:s::StreamBackend {
 s::StreamValue phase(std::uint8_t)noexcept override{return{s::StreamStatus::unbound,0};}
 s::StreamStatus start(std::uint8_t,s::StreamRequest,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus stop(std::uint8_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus pause(std::uint8_t,bool,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus attenuation(std::uint8_t,std::int32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus service(std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
};
struct Services final:s::CutscenePlaybackServices {
 s::CutscenePlaybackStatus start_movie(const s::CutsceneBatch&)override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackValue movie_state()override{return{};}
 s::CutscenePlaybackValue movie_busy()override{return{};}
 s::CutscenePlaybackStatus stop_movie()override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackStatus retire_movie()override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackStatus stop_stream_tasks()override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackStatus fade(bool,std::int16_t,std::uint32_t)override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackValue fade_finished()override{return{};}
 s::CutscenePlaybackStatus fullscreen_color(std::uint32_t)override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackStatus transition_audio_reset()override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackStatus select_scene(s::CutscenePlaybackState&)override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackStatus close_actor_notice()override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackStatus clear_actor_descriptors()override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackStatus retire_scene()override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackStatus reset_scene()override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutscenePlaybackValue load_scene(s::CutscenePlaybackState&)override{return{};}
 s::CutscenePlaybackStatus publish_scene_notice()override{return s::CutscenePlaybackStatus::unavailable;}
 s::CutsceneSpeech* speech()noexcept override{return nullptr;}
 s::CutscenePlaybackStatus frame_work(s::CutsceneFrameWork,s::CutscenePlaybackState&,std::int8_t)override{return s::CutscenePlaybackStatus::unavailable;}
};
int main(int argc,char** argv)try{
 check(argc==4);auto source=std::make_shared<reo::assets::Source>(argv[1]);auto assets=std::make_shared<s::File1FacialAssets>(source);
 std::ifstream models(argv[3]);std::map<std::pair<unsigned,unsigned>,std::shared_ptr<const a::Skeleton>> skeletons;
 for(unsigned kind,character,length;models>>kind>>character>>length;){std::vector<std::byte> bytes(length);for(auto& byte:bytes){unsigned value;models>>value;byte=std::byte(value);}skeletons[{kind,character}]=a::Skeleton::import_raw(bytes);}
 check(skeletons.size()==18);w::Profile profile;profile.layouts.push_back({});auto session=std::make_shared<w::Session>();w::World world(profile,session);s::FlagState flags;s::StreamChannels channels({});Backend backend;Services services;std::optional<std::uint32_t> audio=0;s::CutscenePlayback playback(world,flags,audio,channels,backend,services);
 auto registration=std::make_unique<s::FacialMotions>(world,playback.state(),assets);auto& owner=*registration;check(owner.reset()==s::FacialStatus::unavailable);check(playback.bind_facial_motions(registration)==s::CutscenePlaybackStatus::completed&&!registration);
 std::ifstream manifest(argv[2]);unsigned kind,character,scenario,cue,voice,speaker,logical,storage;std::uint64_t offset;std::string name;unsigned clips{},npc_index{};
 while(manifest>>kind>>character>>scenario>>cue>>voice>>speaker>>offset>>logical>>storage>>name){
  if(kind!=2)continue;
  check(owner.reset()==s::FacialStatus::completed);auto actor=std::make_unique<w::Actor>();actor->category=std::uint8_t(speaker?0:1);actor->model_pose_class=1;actor->character=std::uint8_t(speaker?speaker-1:3);actor->model_variant=std::array<unsigned,10>{29,34,39,46,54,57,62,100,103,106}[npc_index++%10];const auto key=std::pair<unsigned,unsigned>{speaker?0u:1u,speaker?unsigned(actor->character):unsigned(actor->model_variant)};actor->model=std::make_shared<a::Instance>(skeletons.at(key));actor->model->rebuild(reo::native::transform_math::identity());const auto created=world.spawn_primary(0,std::move(actor));check(created.status==w::actors::EntityStatus::completed);auto actual=world.resolve(created.id);session->scenario=std::uint16_t(scenario);
  const auto loaded=owner.load(created.id,std::uint16_t(cue),std::uint16_t(voice),std::uint16_t(clips));check(loaded.status==s::FacialStatus::completed&&loaded.matrix_loaded&&loaded.lip_loaded);check(owner.matrix_count()==1&&owner.lip_count()==1&&owner.lip_end()==0x6000+storage);
  const auto claimed=owner.claim(created.id,std::uint16_t(clips),std::uint16_t(cue),std::uint16_t(voice));check(claimed.status==s::FacialStatus::completed&&claimed.slot==0);
  const auto retained=actual->model->retain();check(bool(retained));const auto retained_joints=retained->joints;std::vector<a::NodePose> initial(actual->model->nodes().begin(),actual->model->nodes().end());
  for(unsigned tick=0;owner.instances()[0].cursor.active;++tick){check(tick<65536);const auto result=owner.tick();check(result.status==s::FacialStatus::completed&&result.visited==1);++frames;patches+=result.patched;
   const auto nodes=actual->model->nodes();for(unsigned node=0;node<nodes.size();++node){check(std::memcmp(&initial[node].local,&nodes[node].local,64)==0);check(std::memcmp(&initial[node].parameters,&nodes[node].parameters,sizeof nodes[node].parameters)==0);if(actual->model->track_ids()[node]!=4)check(std::memcmp(&initial[node].world,&nodes[node].world,64)==0);}
   check(retained->joints.size()==retained_joints.size()&&std::memcmp(retained->joints.data(),retained_joints.data(),retained_joints.size()*64)==0);
  }
  check(!owner.instances()[0].actor);check(world.retire_primary(0)==w::actors::EntityStatus::completed);++clips;
 }
 check(clips==33);check(playback.unbind_facial_motions()==s::CutscenePlaybackStatus::completed);check(!playback.facial_motions());check(world.close()==w::Status::completed);
 std::cout<<"{\"checks\":"<<checks<<",\"owned_clips\":"<<clips<<",\"frames\":"<<frames<<",\"model_patches\":"<<patches<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
