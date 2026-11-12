#include "game/native/gameplay_scenario/cutscene_playback.hpp"
#include "game/native/gameplay_scenario/cutscene_actor_tracks.hpp"
#include "game/native/gameplay_scenario/cutscene_object_tracks.hpp"
#include "game/native/gameplay_scenario/flags.hpp"
#include "game/native/gameplay_world/world.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;
struct Event {unsigned id{};std::int64_t first{},second{},third{};friend bool operator==(const Event&,const Event&)=default;};
std::vector<Event> native_events,source_events;
std::uint64_t checks{},controller_cases{},advance_cases{},ack_cases{},calls{},worker_calls{},refusals{};unsigned case_id{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Cutscene playback case "+std::to_string(case_id)+" line "+std::to_string(at.line()));}
struct Inputs {int ready{},movie_state{},movie_busy{},fade{},load{};bool mutate_frame{},mutate_clock{};unsigned fail_at{};}inputs;
constexpr unsigned controller=0x38eca0;
template<class T>void put(std::uint8_t* memory,unsigned at,const T& value){transform_write(memory,at,value);}
std::array<unsigned,16> callback_ids{0x5ee950,0x5eeb00,0x5ef120,0x5ef500,0x5ef8b0,0x5ef640,0x5ef740,0x5efa40,0x5efb80,0x5efae0,0x5efc40,0x5c09a0,0x6b3bb0,0x5c0e50,0x1bbba0,0x5f0110};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++calls;const auto done=[&](int result=0){SET_GPR_S32(context,2,result);context->pc=GPR_U32(context,31);};const auto emit=[&](unsigned id,std::int64_t a=0,std::int64_t b=0,std::int64_t c=0){source_events.push_back({id,a,b,c});};
 switch(context->pc){
#include "original_dispatch.hpp"
 case 0x6d73f0:case 0x6d7470:emit(context->pc);done();return;
 case 0x37a1b0:emit(context->pc);done();return;
 case 0x37a9b0:emit(context->pc);done(inputs.movie_state);return;
 case 0x37aa10:emit(context->pc);done(inputs.movie_busy);return;
 case 0x37a490:case 0x37a4e0:emit(context->pc);done();return;
 case 0x1acf70:case 0x1b4a60:case 0x1b3d90:case 0x5ed340:case 0x5eb8b0:emit(context->pc);done();return;
 case 0x1bbb10:emit(context->pc,GPR_U32(context,4));done();return;
 case 0x1bb5c0:case 0x1bb650:emit(context->pc,std::int16_t(GPR_U32(context,4)),GPR_U32(context,5));done();return;
 case 0x1bb8d0:emit(context->pc);done(inputs.fade);return;
 case 0x1af6a0:emit(context->pc,GPR_U32(context,4));done();return;
 case 0x107c68:check(GPR_U32(context,4)==0x38edd8&&GPR_U32(context,5)==0&&GPR_U32(context,6)==0x9d8);emit(context->pc);std::fill_n(memory+0x38edd8,0x9d8,0);done();return;
 case 0x5ecf90:emit(context->pc);put(memory,controller+0x10,1234u);done(inputs.load);return;
 case 0x371b70:case 0x6de480:case 0x371ad0:emit(context->pc);done();return;
 case 0x6de590:emit(context->pc,GPR_U32(context,4),GPR_U32(context,5));check(GPR_U32(context,6)==0&&GPR_U32(context,7)==0);done();return;
 case 0x5f1b30:done();return; // Complete audited empty callback.
 case 0x131e38:emit(context->pc,(GPR_U32(context,4)-0x10000u)/8);done();return;
 case 0x1327b8:emit(context->pc,(GPR_U32(context,4)-0x10000u)/8,GPR_S32(context,5));done();return;
 case 0x132e50:emit(context->pc,(GPR_U32(context,4)-0x10000u)/8,GPR_S32(context,5));done();return;
 default:
  if(std::find(callback_ids.begin(),callback_ids.end(),context->pc)!=callback_ids.end()){
   emit(context->pc,context->pc==0x6b3bb0?std::int8_t(GPR_U32(context,4)):0);
   if(context->pc==0x5efae0){if(inputs.mutate_frame)put(memory,controller+8,transform_read<unsigned>(memory,controller+8)+17u);if(inputs.mutate_clock)put(memory,0x3243cc,std::uint8_t(255));}
   done();return;
  }
  throw std::runtime_error("Undeclared playback source call "+std::to_string(context->pc));
 }
}
unsigned invoke(std::uint8_t* memory,unsigned pc){R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);}
struct Backend final:s::StreamBackend {
 s::StreamValue instance_available(std::uint8_t)noexcept override{return{s::StreamStatus::completed,1};}
 s::StreamValue start_ready(std::uint8_t)noexcept override{return{s::StreamStatus::completed,inputs.ready};}
 s::StreamStatus start_inhibit(std::uint8_t,bool)noexcept override{return s::StreamStatus::completed;}
 s::StreamValue phase(std::uint8_t)noexcept override{return{s::StreamStatus::completed,0};}
 s::StreamStatus start(std::uint8_t,s::StreamRequest,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus stop(std::uint8_t channel)noexcept override{native_events.push_back({0x131e38,channel});return s::StreamStatus::completed;}
 s::StreamStatus pause(std::uint8_t channel,bool flag,std::uint32_t)noexcept override{native_events.push_back({0x132e50,channel,flag});return s::StreamStatus::completed;}
 s::StreamStatus attenuation(std::uint8_t channel,std::int32_t value)noexcept override{native_events.push_back({0x1327b8,channel,value});return s::StreamStatus::completed;}
 s::StreamStatus service(std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
};
struct Services final:s::CutscenePlaybackServices {
 s::CutscenePlaybackState* state{};bool try_close{};unsigned close_refusals{};w::World& world;explicit Services(w::World& value):world(value){}
 s::CutscenePlaybackStatus emit(unsigned id,std::int64_t a=0,std::int64_t b=0,std::int64_t c=0){if(try_close){check(world.close()==w::Status::busy&&!world.closed());++close_refusals;}native_events.push_back({id,a,b,c});return inputs.fail_at&&native_events.size()==inputs.fail_at?s::CutscenePlaybackStatus::unavailable:s::CutscenePlaybackStatus::completed;}
 s::CutscenePlaybackStatus prepare_voice(const s::CutsceneBatch&,bool playlist)override{return emit(playlist?0x6d7470:0x6d73f0);}
 s::CutscenePlaybackStatus start_movie(const s::CutsceneBatch&)override{return emit(0x37a1b0);}
 s::CutscenePlaybackValue movie_state()override{return{emit(0x37a9b0),inputs.movie_state};}
 s::CutscenePlaybackValue movie_busy()override{return{emit(0x37aa10),inputs.movie_busy};}
 s::CutscenePlaybackStatus stop_movie()override{return emit(0x37a490);}
 s::CutscenePlaybackStatus retire_movie()override{return emit(0x37a4e0);}
 s::CutscenePlaybackStatus stop_stream_tasks()override{return emit(0x1acf70);}
 s::CutscenePlaybackStatus fade(bool rising,std::int16_t duration,std::uint32_t color)override{return emit(rising?0x1bb5c0:0x1bb650,duration,color);}
 s::CutscenePlaybackValue fade_finished()override{return{emit(0x1bb8d0),inputs.fade};}
 s::CutscenePlaybackStatus fullscreen_color(std::uint32_t color)override{return emit(0x1bbb10,color);}
 s::CutscenePlaybackStatus transition_audio_reset()override{return emit(0x1af6a0,0);}
 s::CutscenePlaybackStatus select_scene(s::CutscenePlaybackState& value)override{if(value.request.mode==1){auto status=emit(0x371b70);if(status!=s::CutscenePlaybackStatus::completed)return status;return emit(0x6de480);}auto status=emit(0x371ad0);if(status!=s::CutscenePlaybackStatus::completed)return status;return emit(0x6de590,value.request.current.area,value.request.current.scene);}
 s::CutscenePlaybackStatus close_actor_notice()override{return emit(0x1b4a60);}
 s::CutscenePlaybackStatus clear_actor_descriptors()override{return emit(0x107c68);}
 s::CutscenePlaybackStatus retire_scene()override{return emit(0x5ed340);}
 s::CutscenePlaybackStatus reset_scene()override{return emit(0x5eb8b0);}
 s::CutscenePlaybackValue load_scene(s::CutscenePlaybackState& value)override{value.end_frame=1234;return{emit(0x5ecf90),inputs.load};}
 s::CutscenePlaybackStatus publish_scene_notice()override{return emit(0x1b3d90);}
 s::CutsceneSpeech* speech()noexcept override{return nullptr;}
 s::CutscenePlaybackStatus frame_work(s::CutsceneFrameWork work,s::CutscenePlaybackState& value,std::int8_t group)override{const auto pc=callback_ids[std::size_t(work)];++worker_calls;if(work==s::CutsceneFrameWork::byte_controls){if(inputs.mutate_frame)value.frame+=17;if(inputs.mutate_clock)world.session().clock_mode=255;}return emit(pc,work==s::CutsceneFrameWork::light_interpolation?group:0);}
};
void project(std::uint8_t* memory,const s::CutscenePlaybackState& state,w::World& world,const s::FlagState& flags,const s::StreamChannels& channels){
 put(memory,0x38ecb6,std::int16_t(0));put(memory,0x38ecb8,std::int16_t(0));put(memory,0x7434c8,controller);put(memory,controller,state.phase);put(memory,controller+1,state.subphase);put(memory,controller+2,state.detail);put(memory,controller+3,state.entry_detail);put(memory,controller+4,state.completion_word);put(memory,controller+8,state.frame);put(memory,controller+0x10,state.end_frame);put(memory,controller+0x24,state.camera_selection);put(memory,controller+0x25,state.camera_ended);put(memory,controller+0x28,state.loaded_identity);put(memory,controller+0x2b,state.previous_identity);put(memory,controller+0x2f,state.request.mode);put(memory,controller+0x30,state.request.current.area);put(memory,controller+0x31,state.request.current.scene);put(memory,controller+0x32,state.request.current.variant);put(memory,controller+0x34,unsigned(state.request.selector));put(memory,controller+0x3c,state.selected_actor);put(memory,controller+0x40,unsigned(state.request.actor_selection));put(memory,controller+0x1c,state.light_groups);put(memory,0x4bae0e,state.acknowledgement_mask);put(memory,0x4bae9a,state.cinematic_enabled);put(memory,0x4bae09,state.voice_requested);put(memory,0x4bae0b,std::uint8_t(state.request.audio_count));
 for(unsigned i=0;i<state.request.audio_count;++i){put(memory,0x4bae36+3*i,state.request.audio_cues[i].area);put(memory,0x4bae37+3*i,state.request.audio_cues[i].scene);put(memory,0x4bae38+3*i,state.request.audio_cues[i].variant);}
 put(memory,0x4badf8,world.paused);put(memory,0x3243cc,world.session().clock_mode);put(memory,0x3243f2,world.mode);put(memory,0x4bae32,world.session().single_roster_setup);put(memory,0x3243fb,world.session().message_phase);put(memory,0x4baded,world.selected_actor);
 const auto& queue=world.session().cutscene_requests;put(memory,0x3b26d0,queue.records());put(memory,0x3b27d0,std::int16_t(queue.write_index()));put(memory,0x3b27d8,std::int16_t(queue.read_index()));put(memory,0x4baa50,flags.snapshot().scenario_owners);
 for(unsigned i=0;i<8;++i){const auto actor=world.primary(i);put(memory,0x4a5c30+0x10e0*i+0xb98,actor->character);put(memory,0x4a5c30+0x10e0*i+0xb99,actor->motion_style);}
 for(unsigned i=0;i<3;++i){const auto& value=channels.snapshot().channels[i];const unsigned at=0x2b8d70+24*i;put(memory,at,value.paused);put(memory,at+1,value.type);put(memory,at+2,value.start_wait);put(memory,at+3,value.started);put(memory,at+4,value.current);put(memory,at+8,value.maximum);put(memory,at+12,value.step);put(memory,at+16,value.level);put(memory,at+20,value.target);put(memory,0x2b8dc8+4*i,0x10000+8*i);put(memory,0x10000+8*i+0x70,std::uint8_t(0));put(memory,0x10000+8*i+0x71,std::int8_t(inputs.ready));}
}
void compare(std::uint8_t* memory,const s::CutscenePlaybackState& state,const w::World& world,const s::StreamChannels& channels){
 check(state.phase==transform_read<std::int8_t>(memory,controller));check(state.subphase==transform_read<std::int8_t>(memory,controller+1));check(state.detail==transform_read<std::int8_t>(memory,controller+2));check(state.entry_detail==transform_read<std::int8_t>(memory,controller+3));check(state.completion_word==transform_read<unsigned>(memory,controller+4));check(state.frame==transform_read<unsigned>(memory,controller+8));check(state.end_frame==transform_read<unsigned>(memory,controller+0x10));check(state.camera_selection==memory[controller+0x24]&&state.camera_ended==memory[controller+0x25]);check(state.request.mode==memory[controller+0x2f]);check(state.request.current.area==memory[controller+0x30]&&state.request.current.scene==memory[controller+0x31]&&state.request.current.variant==memory[controller+0x32]);check(state.request.selector==transform_read<unsigned>(memory,controller+0x34));check(state.request.actor_selection==transform_read<unsigned>(memory,controller+0x40));check(state.selected_actor==transform_read<unsigned>(memory,controller+0x3c));check(state.acknowledgement_mask==memory[0x4bae0e]&&state.cinematic_enabled==memory[0x4bae9a]&&state.voice_requested==memory[0x4bae09]);check(state.request.audio_count==memory[0x4bae0b]);check(world.paused==transform_read<std::int8_t>(memory,0x4badf8));check(world.session().clock_mode==memory[0x3243cc]);check(world.session().cutscene_requests.read_index()==transform_read<std::int16_t>(memory,0x3b27d8));
 for(unsigned i=0;i<3;++i){const auto& channel=channels.snapshot().channels[i];const unsigned at=0x2b8d70+24*i;check(channel.paused==transform_read<std::int8_t>(memory,at));check(channel.current==transform_read<std::int32_t>(memory,at+4)&&channel.maximum==transform_read<std::int32_t>(memory,at+8));check(std::bit_cast<unsigned>(channel.step)==transform_read<unsigned>(memory,at+12)&&std::bit_cast<unsigned>(channel.level)==transform_read<unsigned>(memory,at+16));check(channel.target==transform_read<std::int32_t>(memory,at+20));}
 if(native_events!=source_events){std::cerr<<"event sizes "<<native_events.size()<<','<<source_events.size()<<'\n';for(unsigned i=0;i<std::max(native_events.size(),source_events.size());++i){if(i<native_events.size())std::cerr<<" native "<<std::hex<<native_events[i].id<<std::dec<<' '<<native_events[i].first<<','<<native_events[i].second;if(i<source_events.size())std::cerr<<" source "<<std::hex<<source_events[i].id<<std::dec<<' '<<source_events[i].first<<','<<source_events[i].second;std::cerr<<'\n';}}
 check(native_events==source_events);
}
int main()try{
 const auto previous=_mm_getcsr();struct Reset{unsigned previous;~Reset(){_mm_setcsr(previous);}}reset{previous};_mm_setcsr(0x1f80);std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());w::Profile profile;profile.layouts.push_back({});auto session=std::make_shared<w::Session>();w::World world(profile,session);for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();actor->character=std::uint8_t(i+1);actor->motion_style=std::uint8_t(i%2);check(world.spawn_primary(i,std::move(actor)).status==w::actors::EntityStatus::completed);}s::FlagState flags;for(unsigned i=0;i<512;++i)check(flags.scenario_owner(i,std::uint8_t(i%9)));s::CutsceneActorTracks actor_tracks(world);s::CutsceneObjectTracks object_tracks(world);check(actor_tracks.install({})==s::CutsceneTrackStatus::completed);check(object_tracks.install({})==s::CutsceneTrackStatus::completed);s::StreamChannels channels(s::file1_stream_gain_curve());Backend backend;Services services(world);std::optional<std::uint32_t> tick=123;s::CutscenePlayback playback(world,flags,tick,channels,backend,services);services.state=&playback.state();services.try_close=true;bool duplicate_refused=false;try{s::CutscenePlayback duplicate(world,flags,tick,channels,backend,services);}catch(const std::invalid_argument&){duplicate_refused=true;}check(duplicate_refused);
 for(unsigned mode:{0u,1u,255u})for(unsigned participants:{0u,1u,2u,3u,4u,7u,8u,9u,31u,32u,33u,128u,255u})for(unsigned mask=0;mask<256;++mask){case_id=unsigned(ack_cases);put(memory.data(),0x3243f2,std::uint8_t(mode));put(memory.data(),0x4bae32,std::uint8_t(participants));put(memory.data(),0x4bae0e,std::uint8_t(mask));check(bool(invoke(memory.data(),0x5f1970))==s::cutscene_acknowledgements_complete(std::uint8_t(mode),std::uint8_t(mask),std::uint8_t(participants)));++ack_cases;}
 for(unsigned i=0;i<65536;++i){case_id=i;auto& state=playback.state();state={};state.phase=std::bit_cast<std::int8_t>(std::uint8_t(i<32768?std::array<unsigned,8>{0,1,1,1,2,3,254,4}[i%8]:1));state.subphase=std::bit_cast<std::int8_t>(std::uint8_t(i<32768?(i/8)%256:(i/8)%4));state.detail=21;state.entry_detail=-5;state.completion_word=i%11==0?17:0;state.frame=std::array<unsigned,8>{0,1,0x7ffffffe,0xffffffffu,100,999,1233,0x80000000u}[(i/11)%8];state.end_frame=std::array<unsigned,4>{0,1000,0x7fffffff,0x80000000u}[(i/23)%4];state.request.mode=std::array<std::uint8_t,4>{0,1,2,255}[(i/29)%4];state.request.audio_count=std::array<unsigned,4>{0,1,2,16}[(i/31)%4];state.request.selector=0;state.request.actor_selection=std::uint16_t(i%512);state.request.current={7,9,0};state.selected_actor=99;state.light_groups=std::int16_t(int(i%5)-1);state.camera_selection=7;state.camera_ended=9;state.cinematic_enabled=5;state.voice_requested=std::uint8_t(i%2);state.acknowledgement_mask=std::uint8_t(i%7==0?255:0);for(unsigned j=0;j<state.request.audio_count;++j)state.request.audio_cues[j]={std::uint8_t(j),std::uint8_t(j+1),std::uint8_t(j+2)};
  world.mode=std::uint8_t(i%3==0?0:1);world.paused=std::int8_t(i%2);world.selected_actor=std::uint8_t(i%8);session->single_roster_setup=std::uint8_t(i%6);session->clock_mode=std::uint8_t((i/7)%3);session->message_phase=std::int8_t(i%4);session->cutscene_requests={};for(unsigned j=0;j<i%4;++j)session->cutscene_requests.append({std::uint16_t((i+j)%4),std::uint16_t(i%60),std::uint16_t(j+1),0,std::uint16_t(i%512),0,0,0});
  s::StreamChannelSnapshot stream_state;for(unsigned j=0;j<3;++j){auto& channel=stream_state.channels[j];channel.paused=std::int8_t((i+j)%3-1);channel.started=std::uint8_t((i+j)%3);channel.start_wait=std::uint8_t(i+j);channel.current=std::int32_t((i+j)%128);channel.maximum=127;channel.target=77;channel.level=float(channel.current);channel.step=.25f;}check(channels.restore(stream_state)==s::StreamStatus::completed);inputs={int(i%3!=0),int((i/3)%4),int(i%2),int((i/5)%2),int((i/13)%2),i%19==0,i%17==0,0};project(memory.data(),state,world,flags,channels);native_events.clear();source_events.clear();const bool direct=i%7==0;const auto source_return=invoke(memory.data(),direct?0x5ee260:0x5ee680);const auto result=direct?playback.advance():playback.tick();check(result.status==s::CutscenePlaybackStatus::completed||result.status==s::CutscenePlaybackStatus::waiting);if(!direct)check(result.finished==bool(source_return));compare(memory.data(),state,world,channels);if(direct)++advance_cases;else++controller_cases;
 }
 check(world.cinematic_objects().initialize()==w::CinematicObjectStatus::completed);const auto object=world.cinematic_objects().reserve_inactive();check(object.status==w::CinematicObjectStatus::completed&&object.id);const auto model_object=world.cinematic_objects().resolve(object.id);const auto actor=world.primary(0);actor->scripted.emplace();
 for(unsigned clock=0;clock<256;++clock){
  case_id=70000+clock;auto& state=playback.state();state={};state.phase=1;state.subphase=3;state.frame=9;state.end_frame=1000;world.mode=0;session->clock_mode=std::uint8_t(clock);session->single_roster_setup=1;inputs={1,2,1,1,0,false,false,0};
  std::array<std::byte,72> actor_bytes{},object_bytes{};const auto write=[](auto& bytes,unsigned at,auto value){std::memcpy(bytes.data()+at,&value,sizeof value);};actor_bytes[1]=std::byte{4};write(actor_bytes,2,std::uint16_t(9));write(actor_bytes,20,0xabc00000u+clock);write(actor_bytes,38,std::uint16_t(65535));object_bytes[1]=std::byte{1};write(object_bytes,2,std::uint16_t(9));write(object_bytes,4,clock+1u);write(object_bytes,38,std::uint16_t(65535));
  s::CutsceneActorTrackGroup actor_group;actor_group.actor=world.identity_of(*actor);actor_group.kind=0;actor_group.streams[0]=s::CutsceneActorStream::import(actor_bytes);check(actor_tracks.install(std::span(&actor_group,1))==s::CutsceneTrackStatus::completed);
  s::CutsceneObjectTrackGroup object_group;object_group.object=object.id;object_group.streams[0]=s::CutsceneActorStream::import(object_bytes);check(object_tracks.install(std::span(&object_group,1))==s::CutsceneTrackStatus::completed);
  actor->active=false;actor->primary=3;actor->movement_enabled=239;actor->scripted->cue_phase=7;actor->scripted->request_flags=0x89abcdef;model_object->visible=false;project(memory.data(),state,world,flags,channels);put(memory.data(),0x38ecb6,std::int16_t(1));put(memory.data(),0x38ecb8,std::int16_t(1));std::fill_n(memory.data()+0x38fb60,32,0);std::fill_n(memory.data()+0x38f7b0,28,0);put(memory.data(),0x38fb60,0xc00000u);put(memory.data(),0x38f7b0,0xc00100u);put(memory.data(),0x38edd4,0xd00000u);std::memcpy(memory.data()+0xc00000,actor_bytes.data(),actor_bytes.size());std::memcpy(memory.data()+0xc00100,object_bytes.data(),object_bytes.size());put(memory.data(),0x38edd8,std::int8_t(0));put(memory.data(),0x38eddc,0xb00000u);std::fill_n(memory.data()+0xb00000,0x1000,0);put(memory.data(),0xb00000, std::uint8_t(actor->active));put(memory.data(),0xb00008,actor->primary);put(memory.data(),0xb00553,actor->movement_enabled);put(memory.data(),0xb00b38,actor->scripted->cue_phase);put(memory.data(),0xb00b3c,actor->scripted->request_flags);put(memory.data(),0xd00001,std::uint8_t(0));native_events.clear();source_events.clear();invoke(memory.data(),0x5ee680);check(playback.tick().status==s::CutscenePlaybackStatus::completed);compare(memory.data(),state,world,channels);check(actor->active==bool(memory[0xb00000])&&actor->primary==memory[0xb00008]&&actor->movement_enabled==memory[0xb00553]&&actor->scripted->cue_phase==transform_read<std::int8_t>(memory.data(),0xb00b38)&&actor->scripted->request_flags==transform_read<unsigned>(memory.data(),0xb00b3c));check(model_object->visible==bool(memory[0xd00001]));check(!actor_tracks.cursor(0,0)&&!object_tracks.cursor(0,0));
 }
 for(unsigned failure=1;failure<=13;++failure){auto& state=playback.state();state={};state.phase=1;state.subphase=3;state.request.mode=0;state.end_frame=1000;session->single_roster_setup=1;world.mode=0;inputs={1,2,1,1,0,false,false,failure};native_events.clear();const auto failed=playback.tick();check(failed.status==s::CutscenePlaybackStatus::unavailable&&!playback.busy()&&state.frame==0);check(native_events.size()==failure);++refusals;}
 {w::World missing(profile,std::make_shared<w::Session>());Services required(missing);inputs={1,2,1,1,0,false,false,0};{
  s::CutscenePlayback guarded(missing,flags,tick,channels,backend,required);guarded.state().phase=1;guarded.state().subphase=3;guarded.state().end_frame=1000;const auto result=guarded.tick();check(result.status==s::CutscenePlaybackStatus::unavailable&&!guarded.busy()&&guarded.state().frame==0);++refusals;
 }s::CutscenePlayback rebound(missing,flags,tick,channels,backend,required);check(missing.close()==w::Status::completed);check(rebound.tick().status==s::CutscenePlaybackStatus::closed);}

 check(services.close_refusals>64000);
 std::cout<<"{\"close_refusals\":"<<services.close_refusals<<",\"checks\":"<<checks<<",\"controller_cases\":"<<controller_cases<<",\"advance_cases\":"<<advance_cases<<",\"acknowledgements\":"<<ack_cases<<",\"native_worker_calls\":"<<worker_calls<<",\"refusals\":"<<refusals<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<"Case "<<case_id<<": "<<error.what()<<'\n';return 1;}
