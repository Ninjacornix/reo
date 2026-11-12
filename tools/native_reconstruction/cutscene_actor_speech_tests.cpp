#include "game/native/gameplay_scenario/facial_motions.hpp"
#include "game/native/gameplay_scenario/cutscene_actor_speech.hpp"
#include "game/native/gameplay_scenario/cutscene_playback.hpp"
#include "game/native/gameplay_scenario/flags.hpp"
#include "game/native/gameplay_scenario/cutscene_actor_tracks.hpp"
#include "game/native/animation/model.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <source_location>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;namespace a=reo::native::animation;
std::uint64_t checks{},calls{},speech_misses{},frames{},model_patches{},loads{},claims{},guards{};unsigned serial{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Facial owner case "+std::to_string(serial)+" line "+std::to_string(at.line()));}
std::map<std::string,std::vector<std::byte>> oracle_assets;
std::string requested_voice;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++calls;const auto done=[&](unsigned value=0){SET_GPR_U32(context,2,value);context->pc=GPR_U32(context,31);};
 switch(context->pc){
#include "original_dispatch.hpp"
 case 0x107c68:std::memset(memory+GPR_U32(context,4),int(GPR_U32(context,5)&255),GPR_U32(context,6));done(GPR_U32(context,4));return;
 case 0x10a830:{const auto format=reinterpret_cast<const char*>(memory+GPR_U32(context,5));const auto at=GPR_U32(context,4);int size;
  if(std::string_view(format)=="data\\rom\\motion\\face\\hp%02d.mat"||std::string_view(format)=="data\\rom\\motion\\face\\hn%02d.mat")size=std::snprintf(reinterpret_cast<char*>(memory+at),256,format,GPR_U32(context,6));
  else if(std::string_view(format)=="VO%03d%02d%02d_%01d.adx"||std::string_view(format)=="data\\rom\\motion\\face\\r%03d\\lip%02d_%02d_%01d.bin")size=std::snprintf(reinterpret_cast<char*>(memory+at),256,format,GPR_U32(context,6),GPR_U32(context,7),GPR_U32(context,8),GPR_U32(context,9));
  else{throw std::runtime_error("Unadmitted facial format:"+std::string(format));}
  check(size>0&&size<256);if(std::string_view(format)=="VO%03d%02d%02d_%01d.adx")requested_voice=reinterpret_cast<const char*>(memory+at);done(unsigned(size));return;}
 case 0x1cc8f0:{check(GPR_U32(context,6)==0x20001&&GPR_U32(context,7)==0);const std::string name(reinterpret_cast<char*>(memory+GPR_U32(context,4)));const auto found=oracle_assets.find(name);if(found==oracle_assets.end()){done();return;}check(GPR_U32(context,5)>=0x400000&&GPR_U32(context,5)+found->second.size()<=0x410000);std::memcpy(memory+GPR_U32(context,5),found->second.data(),found->second.size());done(unsigned(found->second.size()));return;}
 default:throw std::runtime_error("Unadmitted facial owner original call "+std::to_string(context->pc));
 }
}
void invoke(std::uint8_t* memory,unsigned address,unsigned actor=0,unsigned first=0,unsigned second=0,unsigned third=0){R5900Context context;PS2Runtime runtime;context.pc=address;SET_GPR_U32(&context,4,actor);SET_GPR_U32(&context,5,first);SET_GPR_U32(&context,6,second);SET_GPR_U32(&context,7,third);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);}
struct Backend final:s::StreamBackend {
 s::StreamValue phase(std::uint8_t)noexcept override{return{s::StreamStatus::unbound,0};}
 s::StreamStatus start(std::uint8_t,s::StreamRequest,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus stop(std::uint8_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus pause(std::uint8_t,bool,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus attenuation(std::uint8_t,std::int32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus service(std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
};
struct Services final:s::CutscenePlaybackServices {
 s::CutsceneSpeech* speech_target{};bool camera_prefix{};
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
 s::CutsceneSpeech* speech()noexcept override{return speech_target;}
 s::CutscenePlaybackStatus frame_work(s::CutsceneFrameWork work,s::CutscenePlaybackState&,std::int8_t)override{return camera_prefix&&work==s::CutsceneFrameWork::camera_selection?s::CutscenePlaybackStatus::completed:s::CutscenePlaybackStatus::unavailable;}
};
struct GuardSource final:reo::assets::PositionedSource {
 std::shared_ptr<const reo::assets::Source> actual;s::FacialMotions* owner{};s::CutscenePlayback* playback{};w::World* world{};
 explicit GuardSource(std::shared_ptr<const reo::assets::Source> value):actual(std::move(value)){}
 std::uint64_t size()const noexcept override{return actual->size;}
 std::size_t read(std::uint64_t at,std::size_t n,void* out)const override{
  if(owner){check(owner->reset()==s::FacialStatus::busy);check(owner->tick().status==s::FacialStatus::busy);check(owner->load({},0,0,0).status==s::FacialStatus::busy);check(owner->claim({},0,0,0).status==s::FacialStatus::busy);check(playback->unbind_facial_motions()==s::CutscenePlaybackStatus::busy);check(playback->unbind_actor_speech()==s::CutscenePlaybackStatus::busy);std::unique_ptr<s::CutsceneActorSpeech> speech_attempt;check(playback->bind_actor_speech(speech_attempt)==s::CutscenePlaybackStatus::busy);check(world->close()==w::Status::busy);++guards;}
  actual->read(at,n,out);return n;
 }
};
struct Asset {unsigned kind,character,scenario,cue,voice,speaker;std::uint64_t offset;unsigned logical,storage;std::string name;};
int main(int argc,char** argv)try{
 check(argc==5);auto file=std::make_shared<reo::assets::Source>(argv[1]);auto guarded=std::make_shared<GuardSource>(file);auto source=std::make_shared<reo::assets::Source>("actual File1 guarded",guarded);auto assets=std::make_shared<s::File1FacialAssets>(source);
 std::ifstream manifest(argv[2]);std::vector<Asset> lip_assets;
 for(Asset asset;manifest>>asset.kind>>asset.character>>asset.scenario>>asset.cue>>asset.voice>>asset.speaker>>asset.offset>>asset.logical>>asset.storage>>asset.name;){
  auto& bytes=oracle_assets[asset.name];bytes.resize(asset.storage);file->read(asset.offset,asset.storage,bytes.data());if(asset.kind==2)lip_assets.push_back(asset);
 }
 check(lip_assets.size()==33);std::ifstream models(argv[3]);std::map<std::pair<unsigned,unsigned>,std::shared_ptr<const a::Skeleton>> skeletons;
 for(unsigned kind,character,length;models>>kind>>character>>length;){std::vector<std::byte> bytes(length);for(auto& byte:bytes){unsigned value;models>>value;byte=std::byte(value);}skeletons[{kind,character}]=a::Skeleton::import_raw(bytes);}
 check(skeletons.size()==18);w::Profile profile;profile.layouts.push_back({});auto session=std::make_shared<w::Session>();w::World world(profile,session);s::FlagState flags;s::StreamChannels channels({});Backend backend;Services services;std::optional<std::uint32_t> audio=0;s::CutscenePlayback playback(world,flags,audio,channels,backend,services);
 s::CutscenePlaybackState other_state;auto foreign=std::make_unique<s::FacialMotions>(world,other_state,assets);check(playback.bind_facial_motions(foreign)==s::CutscenePlaybackStatus::unavailable&&foreign);check(foreign->tick().status==s::FacialStatus::unavailable);
 auto registration=std::make_unique<s::FacialMotions>(world,playback.state(),assets);auto& owner=*registration;check(owner.reset()==s::FacialStatus::unavailable);check(playback.bind_facial_motions(registration)==s::CutscenePlaybackStatus::completed&&!registration);check(owner.tick().status==s::FacialStatus::completed);guarded->owner=&owner;guarded->playback=&playback;guarded->world=&world;
 std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());transform_write(memory.data(),0x324434,0x400000u);
 const auto reset=[&]{check(owner.reset()==s::FacialStatus::completed);invoke(memory.data(),0x67c250);};
 const auto compare=[&]{
  check(owner.matrix_count()==transform_read<unsigned>(memory.data(),0x744860)&&owner.lip_count()==transform_read<unsigned>(memory.data(),0x744750));check(std::memcmp(owner.workspace().data(),memory.data()+0x400000,65536)==0);
  for(unsigned slot=0;slot<8;++slot){const auto& instance=owner.instances()[slot];const auto at=0x7448b0+slot*32;check(instance.cursor.active==bool(memory[at])&&instance.matrix==memory[at+2]&&instance.cursor.frame==transform_read<unsigned>(memory.data(),at+28));check(bool(instance.actor)==bool(transform_read<unsigned>(memory.data(),at+4)));
   for(unsigned channel=0;channel<5;++channel)check(transform_read<unsigned>(memory.data(),at+8+channel*4)==(instance.origins[channel]?0x400000u+unsigned(instance.origins[channel]+instance.cursor.positions[channel]*8):0u));
  }
 };
 unsigned npc_index{};
 for(const auto& asset:lip_assets){
  ++serial;reset();auto actor=std::make_unique<w::Actor>();actor->category=std::uint8_t(asset.speaker?0:1);actor->model_pose_class=1;actor->character=std::uint8_t(asset.speaker?asset.speaker-1:3);actor->model_variant=std::array<unsigned,10>{29,34,39,46,54,57,62,100,103,106}[npc_index++%10];const auto key=std::pair<unsigned,unsigned>{asset.speaker?0u:1u,asset.speaker?unsigned(actor->character):unsigned(actor->model_variant)};actor->model=std::make_shared<a::Instance>(skeletons.at(key));actor->model->rebuild(reo::native::transform_math::identity());const auto spawned=world.spawn_primary(0,std::move(actor));check(spawned.status==w::actors::EntityStatus::completed);const auto native_actor=world.resolve(spawned.id);session->scenario=std::uint16_t(asset.scenario);memory[0x1000002]=native_actor->category;memory[0x100054d]=1;memory[0x1000b98]=native_actor->character;transform_write(memory.data(),0x1000bb4,native_actor->model_variant);transform_write(memory.data(),0x3243da,std::uint16_t(asset.scenario));transform_write(memory.data(),0x1000034,0x1100000u);transform_write(memory.data(),0x1100000,0x1200000u);transform_write(memory.data(),0x1100816,std::uint16_t(native_actor->model->nodes().size()));
  for(unsigned node=0;node<native_actor->model->nodes().size();++node){transform_write(memory.data(),0x1200000+node*4,0x1300000u+node*256);transform_write(memory.data(),0x1300000+node*256+0xc6,native_actor->model->track_ids()[node]);transform_write(memory.data(),0x1300000+node*256+0x40,native_actor->model->nodes()[node].world);}
  invoke(memory.data(),0x67c2e0,0x1000000,asset.cue,asset.voice,serial);const auto loaded=owner.load(spawned.id,std::uint16_t(asset.cue),std::uint16_t(asset.voice),std::uint16_t(serial));check(loaded.status==s::FacialStatus::completed&&loaded.matrix_loaded&&loaded.lip_loaded);++loads;compare();
  // Matching repeats still preload a LIP, while the sole matching matrix
  // key suppresses a second MAT read. Both real sector extents are retained.
  if(asset.storage<=20480){invoke(memory.data(),0x67c2e0,0x1000000,asset.cue,asset.voice,serial);const auto repeated=owner.load(spawned.id,std::uint16_t(asset.cue),std::uint16_t(asset.voice),std::uint16_t(serial));check(repeated.status==s::FacialStatus::completed&&!repeated.matrix_loaded&&repeated.lip_loaded);++loads;compare();}
  const unsigned population=serial==1?8:1;
  for(unsigned slot=0;slot<population;++slot){invoke(memory.data(),0x67c590,0x1000000,serial,asset.cue,asset.voice);const auto claimed=owner.claim(spawned.id,std::uint16_t(serial),std::uint16_t(asset.cue),std::uint16_t(asset.voice));check(claimed.status==s::FacialStatus::completed&&claimed.slot==slot);++claims;compare();}
  if(population==8){invoke(memory.data(),0x67c590,0x1000000,serial,asset.cue,asset.voice);check(!owner.claim(spawned.id,std::uint16_t(serial),std::uint16_t(asset.cue),std::uint16_t(asset.voice)).slot);compare();}
  const auto local=native_actor->model->nodes()[0].local;auto retained=native_actor->model->retain();std::vector<reo::native::transform_math::Matrix> prior=retained?retained->joints:std::vector<reo::native::transform_math::Matrix>{};
  for(unsigned tick=0;;++tick){check(tick<65536);invoke(memory.data(),0x67c6d0);const auto updated=owner.tick();check(updated.status==s::FacialStatus::completed);compare();++frames;model_patches+=updated.patched;
   for(unsigned node=0;node<native_actor->model->nodes().size();++node)check(std::memcmp(&native_actor->model->nodes()[node].world,memory.data()+0x1300000+node*256+0x40,64)==0);
   check(std::memcmp(&native_actor->model->nodes()[0].local,&local,64)==0);if(retained)check(retained->joints.size()==prior.size()&&std::memcmp(retained->joints.data(),prior.data(),prior.size()*64)==0);
   if(std::none_of(owner.instances().begin(),owner.instances().end(),[](const auto& entry){return entry.cursor.active;}))break;
  }
  check(world.retire_primary(0)==w::actors::EntityStatus::completed);
 }
 reset();session->scenario=1;transform_write(memory.data(),0x3243da,std::uint16_t(1));
 std::array<w::actors::EntityId,2> identities;
 for(unsigned slot=0;slot<2;++slot){auto actor=std::make_unique<w::Actor>();actor->category=1;actor->model_pose_class=1;actor->model_variant=std::uint16_t(100+slot*3);actor->model=std::make_shared<a::Instance>(skeletons.at({1,actor->model_variant}));const auto made=world.spawn_primary(slot,std::move(actor));check(made.status==w::actors::EntityStatus::completed);identities[slot]=made.id;const auto at=0x1000000+slot*0x1000;memory[at+2]=1;memory[at+0x54d]=1;transform_write(memory.data(),at+0xbb4,std::uint16_t(100+slot*3));}
 for(unsigned slot:{0u,1u,0u}){invoke(memory.data(),0x67c2e0,0x1000000+slot*0x1000,20,2,13);const auto loaded=owner.load(identities[slot],20,2,13);check(loaded.status==s::FacialStatus::completed&&loaded.matrix_loaded&&loaded.lip_loaded);++loads;compare();}
 check(owner.matrix_count()==3);for(unsigned slot=0;slot<2;++slot){invoke(memory.data(),0x67c590,0x1000000+slot*0x1000,13,20,2);check(owner.claim(identities[slot],13,20,2).slot==slot);check(owner.instances()[slot].matrix==slot);++claims;compare();}
 // A genuine default-catalogue miss preserves previously loaded workspace
 // bytes while still appending the source metadata/count prefix.
 auto actor=world.resolve(identities[0]);actor->model_variant=65000;transform_write(memory.data(),0x1000bb4,std::uint16_t(65000));invoke(memory.data(),0x67c2e0,0x1000000,99,9000,300);const auto missing=owner.load(identities[0],99,9000,300);check(missing.status==s::FacialStatus::completed&&!missing.matrix_loaded&&!missing.lip_loaded);++loads;compare();
 const auto matrix_count=owner.matrix_count(),lip_count=owner.lip_count();actor->model_pose_class=0;memory[0x100054d]=0;invoke(memory.data(),0x67c2e0,0x1000000,99,9000,300);check(owner.load(identities[0],99,9000,300).status==s::FacialStatus::completed);check(owner.matrix_count()==matrix_count&&owner.lip_count()==lip_count);compare();
 check(world.retire_primary(0)==w::actors::EntityStatus::completed);check(owner.tick().status==s::FacialStatus::unavailable);check(owner.instances()[0].cursor.frame==2);check(world.retire_primary(1)==w::actors::EntityStatus::completed);
 reset();session->scenario=1;auto missing_actor=std::make_unique<w::Actor>();missing_actor->category=1;missing_actor->model_pose_class=1;missing_actor->model_variant=65000;const auto missing_id=world.spawn_primary(0,std::move(missing_actor));check(missing_id.status==w::actors::EntityStatus::completed);memory[0x1000002]=1;memory[0x100054d]=1;transform_write(memory.data(),0x1000bb4,std::uint16_t(65000));
 for(unsigned index=0;index<32;++index){invoke(memory.data(),0x67c2e0,0x1000000,99,9000,13);const auto result=owner.load(missing_id.id,99,9000,13);check(result.status==s::FacialStatus::completed&&!result.matrix_loaded&&!result.lip_loaded);++loads;compare();}
 check(owner.lip_count()==32&&owner.matrix_count()==1);check(owner.load(missing_id.id,99,9000,13).status==s::FacialStatus::unavailable&&owner.lip_count()==32);check(world.retire_primary(0)==w::actors::EntityStatus::completed);
 reset();auto speaking=std::make_unique<w::Actor>();speaking->category=1;speaking->character=3;speaking->model_pose_class=1;speaking->model_variant=100;speaking->scripted.emplace();const auto speaker=world.spawn_primary(0,std::move(speaking));check(speaker.status==w::actors::EntityStatus::completed);memory[0x1000002]=1;memory[0x100054d]=1;transform_write(memory.data(),0x1000bb4,std::uint16_t(100));invoke(memory.data(),0x67c2e0,0x1000000,7,0,13);check(owner.load(speaker.id,7,0,13).status==s::FacialStatus::completed);
 struct Speech final:s::CutsceneSpeech {s::FacialMotions& faces;unsigned queued{},animated{};explicit Speech(s::FacialMotions& value):faces(value){}
  bool queue_voice(const s::CutsceneSpeechRequest& request)override{check(request.scenario==1&&request.scene==7&&request.voice==0&&request.character==0);++queued;return false;}
  bool animate_face(const s::CutsceneSpeechRequest& request)override{check(request.scene==7&&request.facial==13&&request.voice==0);++animated;const auto result=faces.claim(request.actor,request.facial,request.scene,std::uint16_t(request.voice));return result.status==s::FacialStatus::completed;}
 }speech(owner);services.speech_target=&speech;services.camera_prefix=true;s::CutsceneActorTracks tracks(world);std::array<std::byte,72> commands{};commands[1]=std::byte(3);const auto facial_id=std::uint16_t(13),terminal=std::uint16_t(65535);std::memcpy(commands.data()+8,&facial_id,2);std::memcpy(commands.data()+38,&terminal,2);s::CutsceneActorTrackGroup group;group.actor=speaker.id;group.streams[3]=s::CutsceneActorStream::import(commands);check(tracks.install(std::span(&group,1))==s::CutsceneTrackStatus::completed);
 transform_write(memory.data(),0x38ecd0,std::uint8_t(7));std::memcpy(memory.data()+0x1500000,commands.data(),commands.size());invoke(memory.data(),0x5eec50,0x1000000,0x1500000);check(requested_voice=="VO0010700_0.adx");playback.state().subphase=3;playback.state().request.current={7,99,0};playback.state().end_frame=1000;const auto routed=playback.advance();check(routed.status==s::CutscenePlaybackStatus::unavailable&&routed.work_calls==2);check(speech.queued==1&&speech.animated==1&&owner.instances()[0].cursor.active);check(world.resolve(speaker.id)->scripted->request_flags==transform_read<unsigned>(memory.data(),0x1000b3c));++claims;compare();check(!world.busy());check(tracks.close()==s::CutsceneTrackStatus::completed);check(world.retire_primary(0)==w::actors::EntityStatus::completed);
 reset();auto actual_actor=std::make_unique<w::Actor>();actual_actor->category=1;actual_actor->character=3;actual_actor->model_pose_class=1;actual_actor->model_variant=100;actual_actor->scripted.emplace();const auto actual_id=world.spawn_primary(0,std::move(actual_actor));check(actual_id.status==w::actors::EntityStatus::completed);check(owner.load(actual_id.id,7,0,13).status==s::FacialStatus::completed);
 auto speech_candidate=std::make_unique<s::CutsceneActorSpeech>(world,playback);auto& actual_speech=*speech_candidate;check(!actual_speech.queue_voice({}));check(playback.bind_actor_speech(speech_candidate)==s::CutscenePlaybackStatus::completed&&!speech_candidate);const s::CutsceneSpeechRequest speech_request{actual_id.id,1,13,7,0,0};check(actual_speech.queue_voice(speech_request)&&actual_speech.last_result().voice_missing);check(actual_speech.animate_face(speech_request)&&owner.instances()[0].cursor.active);check(owner.reset()==s::FacialStatus::completed);check(owner.load(actual_id.id,7,0,13).status==s::FacialStatus::completed);
 services.speech_target=&speech;
s::CutsceneActorTracks actual_tracks(world);
group.actor=actual_id.id;
check(actual_tracks.install(std::span(&group,1))==s::CutsceneTrackStatus::completed);
const auto actual_routed=playback.advance();
check(actual_routed.status==s::CutscenePlaybackStatus::unavailable&&actual_routed.work_calls==3);
check(!actual_tracks.cursor(0,3)&&owner.instances()[0].cursor.active&&!actual_tracks.failed());check(speech.queued==1&&speech.animated==1);
check(actual_tracks.close()==s::CutsceneTrackStatus::completed);
std::ifstream cue_file(argv[4]);unsigned requested_scenario,requested_cue;int requested_number;
while(cue_file>>requested_scenario>>requested_cue>>requested_number){for(unsigned suffix=0;suffix<=8;++suffix){auto mutable_actor=world.resolve(actual_id.id);mutable_actor->category=std::uint8_t(suffix?0:1);mutable_actor->character=std::uint8_t(suffix?suffix-1:3);session->scenario=std::uint16_t(requested_scenario);playback.state().request.current.area=std::uint8_t(requested_cue);const s::CutsceneSpeechRequest typed{actual_id.id,std::uint16_t(requested_scenario),13,std::uint8_t(requested_cue),std::int16_t(requested_number),std::int8_t(suffix)};check(actual_speech.queue_voice(typed)&&actual_speech.last_result().status==s::CutsceneActorSpeechStatus::completed&&actual_speech.last_result().voice_missing);char name[128];check(std::snprintf(name,sizeof name,"VO%03d%02d%02d_%01d.adx",requested_scenario,requested_cue,requested_number,suffix)>0);std::memcpy(memory.data()+0x1510000,name,std::strlen(name)+1);invoke(memory.data(),0x1adb30,2,0x1510000);++speech_misses;}}
check(cue_file.eof()&&speech_misses==693);session->scenario=1;playback.state().request.current.area=7;check(world.retire_primary(0)==w::actors::EntityStatus::completed);
check(!actual_speech.queue_voice(speech_request)&&actual_speech.last_result().status==s::CutsceneActorSpeechStatus::unavailable);

 bool foreign_speech=false;w::World foreign_world(profile,std::make_shared<w::Session>());try{s::CutsceneActorSpeech bad(foreign_world,playback);}catch(const std::invalid_argument&){foreign_speech=true;}check(foreign_speech);
 auto temporary=std::make_unique<s::CutscenePlayback>(foreign_world,flags,audio,channels,backend,services);auto foreign_candidate=std::make_unique<s::CutsceneActorSpeech>(foreign_world,*temporary);check(playback.bind_actor_speech(foreign_candidate)==s::CutscenePlaybackStatus::unavailable&&foreign_candidate);check(temporary->bind_actor_speech(foreign_candidate)==s::CutscenePlaybackStatus::completed&&!foreign_candidate);check(temporary->unbind_actor_speech()==s::CutscenePlaybackStatus::completed&&!temporary->actor_speech());temporary.reset();check(foreign_world.close()==w::Status::completed);check(playback.unbind_actor_speech()==s::CutscenePlaybackStatus::completed&&!playback.actor_speech());
 guarded->owner=nullptr;reset();check(playback.unbind_facial_motions()==s::CutscenePlaybackStatus::completed);check(!playback.facial_motions());check(world.close()==w::Status::completed);
 std::cout<<"{\"checks\":"<<checks<<",\"owned_clips\":"<<lip_assets.size()<<",\"loads\":"<<loads<<",\"claims\":"<<claims<<",\"frames\":"<<frames<<",\"model_patches\":"<<model_patches<<",\"callback_guards\":"<<guards<<",\"original_calls\":"<<calls<<",\"speech_misses\":"<<speech_misses<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
