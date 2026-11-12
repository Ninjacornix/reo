#include "game/native/gameplay_scenario/scene_voice_preparation.hpp"
#include "game/native/gameplay_world/world.hpp"
#include "reference.hpp"
#include "functions.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <source_location>
#include <string>
#include <vector>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;
struct Event {unsigned id{},channel{};std::int32_t first{},second{};friend bool operator==(const Event&,const Event&)=default;};
std::vector<Event> original_events,native_events;std::uint64_t checks{},cases{},calls{};unsigned seed{};
void check(bool value,std::source_location where=std::source_location::current()){++checks;if(!value)throw std::runtime_error("scene voice policy seed "+std::to_string(seed)+" line "+std::to_string(where.line()));}
std::string_view text_at(const std::uint8_t* memory,unsigned at){check(at<0x2000000);unsigned length{};while(length<256&&memory[at+length])++length;check(length<256);return{reinterpret_cast<const char*>(memory+at),length};}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;const auto done=[&](std::int32_t result=0){SET_GPR_S32(context,2,result);context->pc=GPR_U32(context,31);};switch(context->pc){
#include "original_dispatch.hpp"
case 0x10a830:{const auto format=text_at(memory,GPR_U32(context,5));const auto at=GPR_U32(context,4);int size{};if(format=="%02d_%02d_%d")size=std::snprintf(reinterpret_cast<char*>(memory+at),128,format.data(),GPR_S32(context,6),GPR_S32(context,7),GPR_S32(context,8));else if(format=="%s%s.adx")size=std::snprintf(reinterpret_cast<char*>(memory+at),128,format.data(),text_at(memory,GPR_U32(context,6)).data(),text_at(memory,GPR_U32(context,7)).data());else throw std::runtime_error("Unknown original scene voice format");check(size>0&&size<128);done(size);return;}
case 0x10afc0:{const auto value=text_at(memory,GPR_U32(context,5));std::memcpy(memory+GPR_U32(context,4),value.data(),value.size()+1);done(std::int32_t(GPR_U32(context,4)));return;}
case 0x10b158:done(std::int32_t(text_at(memory,GPR_U32(context,4)).size()));return;
case 0x10cda8:{auto at=GPR_U32(context,4);const auto length=text_at(memory,at).size();for(unsigned i=0;i<length;++i)if(memory[at+i]>='a'&&memory[at+i]<='z')memory[at+i]-=32;done(std::int32_t(at));return;}
case 0x10ae78:{const auto a=text_at(memory,GPR_U32(context,4)),b=text_at(memory,GPR_U32(context,5));const auto compared=a.compare(b);done(compared<0?-1:compared>0?1:0);return;}
case 0x133490:case 0x12a6b8:original_events.push_back({context->pc,(GPR_U32(context,4)-0x10000u)/256,GPR_S32(context,5),GPR_S32(context,6)});done();return;
case 0x132e50:case 0x1327b8:original_events.push_back({context->pc,(GPR_U32(context,4)-0x10000u)/256,GPR_S32(context,5),0});done();return;
case 0x12a8f0:case 0x12a830:case 0x12a780:original_events.push_back({context->pc,(GPR_U32(context,4)-0x10000u)/256});done();return;
default:throw std::runtime_error("Unknown original voice policy dependency "+std::to_string(context->pc));
}}
void invoke(std::uint8_t* memory,unsigned pc){R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);}
struct Backend final:s::StreamBackend {
 std::array<std::uint8_t,3> inhibit{};
 s::StreamValue instance_available(std::uint8_t)noexcept override{return{s::StreamStatus::completed,1};}
 s::StreamValue start_ready(std::uint8_t)noexcept override{return{s::StreamStatus::unbound,0};}
 s::StreamStatus start_inhibit(std::uint8_t index,bool value)noexcept override{inhibit[index]=value?1:0;return s::StreamStatus::completed;}
 s::StreamStatus prepare_cues(std::uint8_t index,std::span<const s::StreamCue> cues,std::uint32_t)noexcept override{for(const auto& cue:cues)native_events.push_back({0x12a6b8,index,3,cue.source.member});for(unsigned id:{0x12a8f0u,0x12a830u,0x12a780u})native_events.push_back({id,index});return s::StreamStatus::completed;}
 s::StreamValue phase(std::uint8_t)noexcept override{return{s::StreamStatus::unbound,0};}
 s::StreamStatus start(std::uint8_t index,s::StreamRequest source,std::uint32_t)noexcept override{native_events.push_back({0x133490,index,3,source.member});return s::StreamStatus::completed;}
 s::StreamStatus stop(std::uint8_t)noexcept override{return s::StreamStatus::unbound;}
 s::StreamStatus pause(std::uint8_t index,bool value,std::uint32_t)noexcept override{native_events.push_back({0x132e50,index,value?1:0});return s::StreamStatus::completed;}
 s::StreamStatus attenuation(std::uint8_t index,std::int32_t value)noexcept override{native_events.push_back({0x1327b8,index,value});return s::StreamStatus::completed;}
 s::StreamStatus service(std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
};
template<class T>void put(std::uint8_t* memory,unsigned at,T value){transform_write(memory,at,value);}
void project(std::uint8_t* memory,std::uint16_t scenario,const s::CutsceneBatch& batch,const s::StreamChannels& channels,const Backend& backend){put(memory,0x3243da,scenario);put(memory,0x38ecd0,batch.current.area);put(memory,0x38ecd1,batch.current.scene);put(memory,0x38ecd2,batch.current.variant);put(memory,0x4bae0b,std::uint8_t(batch.audio_count));for(unsigned i=0;i<batch.audio_count;++i){put(memory,0x4bae36+3*i,batch.audio_cues[i].area);put(memory,0x4bae37+3*i,batch.audio_cues[i].scene);put(memory,0x4bae38+3*i,batch.audio_cues[i].variant);}for(unsigned i=0;i<3;++i){const auto& c=channels.snapshot().channels[i];const unsigned at=0x2b8d70+24*i;put(memory,at,c.paused);put(memory,at+1,c.type);put(memory,at+2,c.start_wait);put(memory,at+3,c.started);put(memory,at+4,c.current);put(memory,at+8,c.maximum);put(memory,at+12,c.step);put(memory,at+16,c.level);put(memory,at+20,c.target);put(memory,0x2b8dc8+4*i,0x10000+256*i);put(memory,0x10000+256*i+0x70,backend.inhibit[i]);}}
void compare(std::uint8_t* memory,const s::StreamChannels& channels,const Backend& backend){for(unsigned i=0;i<3;++i){const auto& c=channels.snapshot().channels[i];const unsigned at=0x2b8d70+24*i;check(c.paused==transform_read<std::int8_t>(memory,at));check(c.type==memory[at+1]&&c.start_wait==memory[at+2]&&c.started==memory[at+3]);check(c.current==transform_read<std::int32_t>(memory,at+4)&&c.maximum==transform_read<std::int32_t>(memory,at+8)&&c.target==transform_read<std::int32_t>(memory,at+20));check(std::bit_cast<unsigned>(c.level)==transform_read<unsigned>(memory,at+16)&&std::bit_cast<unsigned>(c.step)==transform_read<unsigned>(memory,at+12));check(backend.inhibit[i]==memory[0x10000+256*i+0x70]);}if(native_events!=original_events){std::cerr<<"voice event lengths "<<native_events.size()<<","<<original_events.size()<<'\n';for(unsigned i=0;i<std::min(native_events.size(),original_events.size());++i)std::cerr<<std::hex<<native_events[i].id<<","<<original_events[i].id<<std::dec<<" args "<<native_events[i].first<<","<<original_events[i].first<<" second "<<native_events[i].second<<","<<original_events[i].second<<'\n';}check(native_events==original_events);}
int main(int argc,char** argv)try{check(argc==2);std::ifstream file(argv[1],std::ios::binary);check(bool(file));std::uint32_t segments;file.read(reinterpret_cast<char*>(&segments),4);std::vector<std::uint8_t> memory(0x2000000);for(unsigned i=0;i<segments;++i){std::uint32_t at,bytes;file.read(reinterpret_cast<char*>(&at),4);file.read(reinterpret_cast<char*>(&bytes),4);check(at<memory.size()&&bytes<=memory.size()-at);file.read(reinterpret_cast<char*>(memory.data()+at),bytes);check(file.gcount()==bytes);}w::Profile profile;profile.layouts.push_back({});w::World world(profile,std::make_shared<w::Session>());s::StreamChannels channels(s::file1_stream_gain_curve());Backend backend;std::optional<std::uint32_t> tick=1000;s::SceneVoicePreparation voices(world,channels,backend,tick);const auto assets=s::scene_voice_assets();
 for(seed=0;seed<8192;++seed)for(bool playlist:{false,true}){const auto& asset=assets[seed%assets.size()];world.scenario=seed%11==0?0:seed%13==0?65535:asset.scenario;s::CutsceneBatch batch;batch.current=seed%17==0?s::CutsceneCue{255,255,255}:asset.cue;batch.audio_count=seed%17;for(unsigned i=0;i<batch.audio_count;++i)batch.audio_cues[i]=assets[(seed+i)%assets.size()].cue;s::StreamChannelSnapshot state;for(unsigned i=0;i<3;++i){auto& c=state.channels[i];c.paused=std::bit_cast<std::int8_t>(std::uint8_t(seed+i));c.type=std::uint8_t(seed/3+i);c.start_wait=std::uint8_t(seed/7+i);c.started=std::uint8_t(seed/5+i);c.current=std::int32_t((seed*17+i)%324);c.maximum=std::int32_t((seed*23+i)%324);c.target=std::int32_t(seed*29+i);c.level=float(c.current);c.step=float(int(seed%17)-8)*.25f;backend.inhibit[i]=std::uint8_t(seed/11+i);}check(channels.restore(state)==s::StreamStatus::completed);project(memory.data(),*world.scenario,batch,channels,backend);original_events.clear();native_events.clear();invoke(memory.data(),playlist?0x6d7470:0x6d73f0);check(voices.prepare(batch,playlist)==s::StreamStatus::completed);compare(memory.data(),channels,backend);++cases;}
 s::CutsceneBatch batch;batch.current={3,0,0};world.scenario.reset();check(voices.prepare(batch,false)==s::StreamStatus::unbound);world.scenario=1;tick.reset();check(voices.prepare(batch,false)==s::StreamStatus::unbound);tick=1000;batch.audio_count=17;check(voices.prepare(batch,true)==s::StreamStatus::unsupported_profile);check(world.close()==w::Status::completed);check(voices.prepare(batch,false)==s::StreamStatus::closed);
 std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
