#include "game/native/gameplay_world/dialogue_pool.hpp"
#include "game/native/gameplay_world/dialogue_responses.hpp"
#include "game/native/gameplay_world/primary_actor_records.hpp"
#include "game/native/gameplay_world/auxiliary_actors.hpp"
#include "game/native/gameplay_update/update.hpp"
#include "game/native/gameplay_update/actor_message_queue.hpp"
#include "game/native/gameplay_scenario/scene_resources.hpp"
#include "game/native/gameplay_scenario/resource_templates.hpp"
#include "game/native/gameplay_world/cached_dialogue_presentation.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
namespace w=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;namespace u=reo::native::gameplay_update;
namespace {
std::uint64_t external_timer_commands{},frames{},prefix_stops{},queued{},choose_calls{},reply_calls{},monitor_calls{},direct_calls{},history_calls{},preludes{},checks{},source_calls{},constructors{},updates{},clears{},lifetimes{},guards{},interruptions{},effect_writes{},capacity_refusals{},literal_records{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Dialogue pool "+std::to_string(at.line())+" constructors "+std::to_string(constructors)+" updates "+std::to_string(updates));}
struct Event {unsigned kind{};std::int32_t first{},second{};std::uint8_t alpha{};std::vector<std::byte> text;friend bool operator==(const Event&,const Event&)=default;};
std::vector<Event> events,original_events;
using SpeechMessage=std::array<std::int32_t,9>;std::vector<SpeechMessage> speech_messages,original_speech_messages;
const s::TextCache* live_cache{};const w::AuxiliaryActorPool* live_auxiliary{};
struct RefusalPrefix {};
std::vector<std::uint8_t> memory(0x2000000);bool hidden{},source_interrupt{},stop_input_read{},stop_target_read{};
constexpr unsigned actor_base=0x4a5c30,source_work=0x800000;
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
std::vector<std::byte> string(unsigned at){std::vector<std::byte> value;for(unsigned i=0;i<64;++i){const auto c=memory.at(at+i);if(!c)return value;value.push_back(std::byte(c));}throw std::runtime_error("Unbounded source dialogue string");}
struct Display final:w::DialoguePresentation {
    w::World& world;w::DialoguePool* pool{};bool reenter{};s::TextCache cache;w::DialogueVisibilityInputs visibility{std::uint8_t(1),std::uint8_t(0)};w::CachedDialoguePresentation actual;explicit Display(w::World& value):world(value),actual(value,cache,visibility){cache.reset();live_cache=&cache;}
    bool bound_to(const w::World& value)const noexcept override{return &value==&world;}
    bool erase(std::span<const std::byte> value)noexcept override{events.push_back({0,0,0,0,{value.begin(),value.end()}});if(reenter){check(pool&&pool->clear_records()==w::DialogueStatus::busy&&pool->advance_flag_durations()==w::DialogueStatus::busy&&pool->advance_responses(w::DialogueResponseFrame{}).status==w::DialogueStatus::busy&&world.close()==w::Status::busy);++guards;}return actual.erase(value);}
    std::optional<bool> suppressed()noexcept override{visibility.mode=hidden?1:0;const auto result=actual.suppressed();events.push_back({1,result.value_or(false)?1:0,0,0,{}});return result;}
    bool draw(std::int16_t center,std::uint16_t y,std::span<const std::byte> value,std::uint8_t alpha)noexcept override{events.push_back({2,center,y,alpha,{value.begin(),value.end()}});return actual.draw(center,y,value,alpha);}
};
struct Backend final:s::StreamBackend {
    s::StreamValue phase(std::uint8_t)noexcept override{return{s::StreamStatus::unbound,0};}
    s::StreamStatus start(std::uint8_t,s::StreamRequest,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus stop(std::uint8_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus pause(std::uint8_t,bool,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus attenuation(std::uint8_t,std::int32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus service(std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamValue actor_archive_marker(std::uint8_t slot)noexcept override{events.push_back({3,slot,0,0,{}});return{s::StreamStatus::completed,0};}
};
R5900Context call(unsigned at,unsigned a0=0,unsigned a1=0,unsigned a2=0){R5900Context state;PS2Runtime runtime;state.pc=at;SET_GPR_U32(&state,4,a0);SET_GPR_U32(&state,5,a1);SET_GPR_U32(&state,6,a2);SET_GPR_U32(&state,29,0x1f00000);SET_GPR_U32(&state,31,0xabcdef);original_transform_port(memory.data(),&state,&runtime);check(state.pc==(source_interrupt?0xdead0001u:0xabcdefu));if(!source_interrupt)check(GPR_U32(&state,29)==0x1f00000);return state;}
unsigned actor_address(const w::World& world,const w::actors::EntityId& id){for(unsigned i=0;i<8;++i)if(id==world.identity(i))return actor_base+i*0x10e0;if(live_auxiliary)if(const auto physical=live_auxiliary->physical_slot(id))return 0x160000+0x10e0*unsigned(*physical);return 0;}
void export_speech(const w::Actor& actor,unsigned at){const auto& x=actor.speech;check(x.selection&&x.variant&&x.gauge_notice&&x.partner_characters&&x.request&&x.notice&&x.repeat_delay&&x.response_delay&&x.target_lock&&x.timing_active&&x.previous_elapsed&&x.elapsed&&x.remote_request);put(at+0xda8,*x.request);put(at+0xda9,*x.variant);put(at+0xdaa,*x.notice);std::memcpy(memory.data()+at+0xdac,x.partner_characters->data(),4);put(at+0xdb0,*x.repeat_delay);put(at+0xdb4,x.selection->sequence);put(at+0xdb8,*x.gauge_notice);put(at+0xdbc,x.dialogue_delay.value_or(0));put(at+0xdbe,*x.response_delay);put(at+0xdc0,x.selection->pending);put(at+0xdc1,x.selection->response_state);put(at+0xdc2,x.selection->target_identifier);put(at+0xdc5,*x.target_lock);put(at+0xdc7,x.selection->target_context);put(at+0xdc8,*x.timing_active);put(at+0xdcc,*x.previous_elapsed);put(at+0xdd0,*x.elapsed);put(at+0x1075,x.display_style.value_or(0));put(at+0x1098,*x.remote_request);}
void export_actor(const w::World& world,unsigned index){const auto actor=world.primary(index);const unsigned at=actor_base+index*0x10e0;memory[at]=actor->active?1:0;memory[at+1]=actor->visible?1:0;memory[at+2]=actor->category;memory[at+3]=actor->slot;put(at+0x38,actor->position);put(at+0x58,actor->collision.basis.x.z);put(at+0x92,actor->orientation[1]);put(at+0x1e2,actor->room);memory[at+0xb98]=actor->character;memory[at+0xb99]=actor->motion_style;memory[at+0xb9b]=actor->class_marker;put(at+0x544,actor->current);put(at+0x546,actor->maximum);put(at+0xba0,actor->status);put(at+0xbac,actor->gauge_value.value_or(0));put(at+0xd28,actor->control_elapsed);put(at+0xd2c,actor->action_elapsed);put(at+0x54f,actor->motion_class);put(at+0xd32,actor->related_target_state.value_or(0));std::memcpy(memory.data()+at+0xc84,actor->inventory.carried.data(),4);std::memcpy(memory.data()+at+0xc88,actor->inventory.storage.data(),32);export_speech(*actor,at);}
void compare_speech(const w::Actor& actor,unsigned at){const auto& x=actor.speech;check(x.request==get<std::int8_t>(at+0xda8)&&x.variant==get<std::int8_t>(at+0xda9)&&x.notice==get<std::int16_t>(at+0xdaa));check(x.partner_characters&&std::memcmp(x.partner_characters->data(),memory.data()+at+0xdac,4)==0);check(x.repeat_delay==get<std::int32_t>(at+0xdb0)&&x.gauge_notice==get<std::int32_t>(at+0xdb8)&&x.dialogue_delay==get<std::int16_t>(at+0xdbc)&&x.response_delay==get<std::int16_t>(at+0xdbe));check(x.selection&&x.selection->sequence==get<unsigned>(at+0xdb4)&&x.selection->pending==get<std::int8_t>(at+0xdc0)&&x.selection->response_state==get<std::int8_t>(at+0xdc1)&&x.selection->target_identifier==get<std::int16_t>(at+0xdc2)&&x.selection->target_context==get<std::int8_t>(at+0xdc7));check(x.target_lock==get<std::int8_t>(at+0xdc5)&&x.timing_active==get<std::int32_t>(at+0xdc8)&&x.previous_elapsed==get<std::int32_t>(at+0xdcc)&&x.elapsed==get<std::int32_t>(at+0xdd0)&&x.display_style==get<std::int8_t>(at+0x1075)&&x.remote_request==get<std::uint8_t>(at+0x1098));}

void export_inputs(const w::World& world,const w::DialogueGates& gates){memory[0x4baded]=world.selected_actor;put(0x4badf8,world.paused);memory[0x4bae8d]=gates.blocked.value_or(0);memory[0x4bae89]=gates.flags.value_or(0);put(0x4baea0,*world.session().primary_population);put(0x324438,source_work);for(unsigned i=0;i<8;++i)export_actor(world,i);const auto random=world.session().random.state();put(0x3244b0,random.primary);put(0x3244b8,random.secondary);put(0x2b8de8,random.observed);}
void source_banks(const w::DialogueBanks& banks){
    for(unsigned index:{0u,1u,8u}){const auto& bank=banks[index];const unsigned physical=index==8?4:index,base=source_work+0x6000+0x12800*physical,text_base=source_work+0x5c000+0x5c00*physical;check(bank.cues&&bank.texts);const auto cues=bank.cues->backing(),text=bank.texts->backing();std::memcpy(memory.data()+base,cues->data(),cues->size());std::memcpy(memory.data()+text_base,text->data(),text->size());call(0x6b7350,base,0,physical);call(0x6b7350,text_base,1,physical);}
}
void compare(const w::DialoguePool& pool,const w::World& world){
    for(unsigned i=0;i<512;++i){check(pool.flag_duration(std::uint16_t(i))==get<std::int32_t>(0x74e868+4*i));check(world.session().auxiliary_scene.timer(i)==get<std::uint32_t>(0x74e868+4*i));}
    for(unsigned index=0;index<16;++index){const auto value=pool.record(index);check(bool(value));const auto& r=*value;std::array<std::uint8_t,0x98> expected{};const auto write=[&]<class T>(unsigned at,T v){std::memcpy(expected.data()+at,&v,sizeof v);};
        write(0,std::uint16_t(r.active));write(2,r.phase);write(4,r.delay);write(6,r.initial_delay);write(8,r.age);write(0xa,r.fade_ticks);write(0xb,r.character_ticks);write(0xc,r.alpha);write(0xd,r.channel);write(0xe,r.revealed);write(0x10,r.line_bytes);unsigned text_at{};
        if(r.text_owner){const auto actor=world.resolve(r.actor);check(bool(actor));const auto physical=actor->category?4u:unsigned(memory[0x74f0f4+actor->character]);const auto text_base=source_work+0x5c000+0x5c00*physical;const auto reference=get<unsigned>(text_base+4+8*r.text_index);text_at=text_base+get<unsigned>(text_base+reference)+8;}
        write(0x14,text_at);std::memcpy(expected.data()+0x18,r.buffer.data(),64);write(0x58,r.voice);write(0x5a,r.center);write(0x5c,actor_address(world,r.actor));write(0x60,r.sequence);write(0x62,r.glyphs);write(0x65,r.corruption_count);write(0x66,r.reveal_index);write(0x67,r.literal);write(0x68,r.page);write(0x69,r.newlines);std::memcpy(expected.data()+0x6a,r.prefix.data(),4);std::memcpy(expected.data()+0x72,r.corrupted.data(),32);write(0x92,r.display_style);
        const unsigned at=0x74dd40+0x98*index;if(std::memcmp(expected.data(),memory.data()+at,expected.size())){for(unsigned byte=0;byte<expected.size();++byte)if(expected[byte]!=memory[at+byte])std::cerr<<"Record mismatch index="<<index<<" offset="<<byte<<" native="<<unsigned(expected[byte])<<" source="<<unsigned(memory[at+byte])<<'\n';}check(std::memcmp(expected.data(),memory.data()+at,expected.size())==0);
    }
    if(const auto counts=pool.selected_counts())for(unsigned i=0;i<2;++i)check((*counts)[i]==get<std::int16_t>(0x74dd30+2*i));
    for(unsigned bit=0;bit<512;++bit)check(pool.flag(std::uint16_t(bit))==bool(get<unsigned>(0x74e828+4*(bit/32))&(1u<<(bit%32))));
    for(unsigned i=0;i<2;++i){const auto actor=world.primary(i);check(actor->speech.dialogue_delay==get<std::int16_t>(actor_base+0x10e0*i+0xdbc)&&actor->speech.display_style==get<std::int8_t>(actor_base+0x10e0*i+0x1075));}
    check(live_cache&&live_cache->snapshot());const auto cache=*live_cache->snapshot();for(unsigned i=0;i<cache.size();++i){const auto& record=cache[i];const auto at=0x3151d0+0x8c*i;check(get<std::uint16_t>(at)==unsigned(record.active)&&get<std::int16_t>(at+2)==record.x&&get<std::int16_t>(at+4)==record.y&&get<std::int16_t>(at+6)==record.duration);check(memory[at+8]==record.height&&memory[at+9]==record.fade&&memory[at+10]==record.alpha&&memory[at+11]==record.priority&&std::memcmp(memory.data()+at+12,record.text.data(),128)==0);}
    const auto random=world.session().random.state();check(random.primary==get<std::uint16_t>(0x3244b0)&&random.secondary==get<std::uint16_t>(0x3244b8)&&random.observed==get<std::uint8_t>(0x2b8de8));
}
}
std::uint8_t observed_response_byte(const std::uint8_t* ram,const R5900Context* context,std::uint32_t at){
    if(stop_input_read&&(context->pc==0x6b7de0||context->pc==0x6b7df4))throw RefusalPrefix{};
    return ram[at];
}
std::uint32_t observed_response_word(const std::uint8_t* ram,const R5900Context* context,std::uint32_t at){
    if(stop_target_read&&context->pc==0x6b875c)throw RefusalPrefix{};
    std::uint32_t value;std::memcpy(&value,ram+at,4);return value;
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++source_calls;choose_calls+=context->pc==0x6b8650;reply_calls+=context->pc==0x6b8cc0;monitor_calls+=context->pc==0x6b90a0;direct_calls+=context->pc==0x6b8f60;history_calls+=context->pc==0x6b92e0;
if(context->pc==0x1ba250&&GPR_S32(context,6)>=0){check(!memory[GPR_U32(context,4)+2]);original_events.push_back({3,memory[GPR_U32(context,4)+3],0,0,{}});}
if(context->pc==0x1b49b0)original_events.push_back({0,0,0,0,string(GPR_U32(context,4))});
if(context->pc==0x1b48e0){check(GPR_U32(context,6)==1&&GPR_U32(context,7)==20);original_events.push_back({2,GPR_S32(context,4),GPR_S32(context,5),std::uint8_t(GPR_U32(context,9)),string(GPR_U32(context,8))});}
if(context->pc==0x6dee20){memory[0x4bae33]=1;memory[0x755ec4]=hidden?1:0;memory[0x4badee]=0;original_events.push_back({1,hidden?1:0,0,0,{}});}
switch(context->pc){
#include "original_dispatch.hpp"
case 0x10a830:{const auto format=GPR_U32(context,5),destination=GPR_U32(context,4);unsigned i{};for(;i<32&&memory[format+i];++i)memory[destination+i]=memory[format+i];check(i<32);memory[destination+i]=0;SET_GPR_U32(context,2,i);break;}
case 0x1afdd0:{const auto at=GPR_U32(context,5);check(GPR_U32(context,6)==0&&GPR_U32(context,7)==4&&memory[at]==11&&memory[at+1]==20);original_speech_messages.push_back({memory[0x3243f2]==0?0:1,std::int32_t(GPR_U32(context,4)),std::bit_cast<std::int32_t>(get<unsigned>(at+4)),get<std::int16_t>(at+8),get<std::int16_t>(at+10),get<std::int32_t>(at+16),get<std::int8_t>(at+12),get<std::int8_t>(at+13),get<std::int8_t>(at+14)});SET_GPR_U32(context,2,0);break;}

default:throw std::runtime_error("Undeclared pool source helper "+std::to_string(context->pc));}context->pc=GPR_U32(context,31);}

namespace {
template<class T>void encode(std::vector<std::byte>& b,std::size_t at,T value){std::memcpy(b.data()+at,&value,sizeof value);}
std::uint32_t word(const std::vector<std::byte>& b,std::size_t at){std::uint32_t result{};std::memcpy(&result,b.data()+at,4);return result;}
std::vector<unsigned> safe_cues(const s::DialogueBank& bank){std::vector<unsigned> result;for(unsigned i=1;i<5000;++i){const auto cue=bank.cues->cue(i);if(!cue)continue;const auto text=bank.texts->text(cue->text);if(!text)continue;unsigned line{},lines{},maximum{};for(const auto c:text->body){if(c==std::byte{10}||c==std::byte{13}){maximum=std::max(maximum,line);line=0;lines+=c==std::byte{10};}else ++line;}maximum=std::max(maximum,line);if(maximum<=28&&lines<=8)result.push_back(i);}return result;}
void controlled_response(s::DialogueBank& bank,std::span<const unsigned> cue_ids,std::int8_t group,std::int8_t mode,std::uint32_t mask){
    auto b=std::make_shared<std::vector<std::byte>>(*bank.cues->backing());const auto first=word(*b,16),second=word(*b,20);check(std::size_t(second)+24000+48*cue_ids.size()<=b->size());for(unsigned i=0;i<6000;++i)encode(*b,second+4*i,0u);
    for(unsigned i=0;i<cue_ids.size();++i){const auto cue=cue_ids[i],at=second+24000+48*i,metadata=word(*b,first+4*cue);encode(*b,second+4*cue,at);std::fill_n(b->begin()+at,48,std::byte{});encode(*b,at,std::int16_t(cue));encode(*b,at+2,group);encode(*b,at+3,mode);for(unsigned c=0;c<4;++c)(*b)[at+4+8*c]=std::byte{255};encode(*b,at+44,mask);encode(*b,metadata+4,std::int16_t(2));encode(*b,metadata+8,std::int16_t(0));encode(*b,metadata+10,std::int16_t(0));}
    bank.cues=std::make_shared<const s::DialogueCues>(b);
}
void controlled_reply(s::DialogueBank& bank,unsigned cue,unsigned reply){auto b=std::make_shared<std::vector<std::byte>>(*bank.cues->backing());const auto first=word(*b,16),at=word(*b,first+4*cue);encode(*b,at+4,std::int16_t(2));encode(*b,at+8,std::int16_t(0));encode(*b,at+10,std::int16_t(0));for(unsigned i=0;i<4;++i)encode(*b,at+12+2*i,std::uint16_t(i?0:reply));bank.cues=std::make_shared<const s::DialogueCues>(b);}
struct Notifications final:s::FlagNotifications {bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}};
struct Messages final:u::GameplayMessageSink {
    u::ActorMessageQueue& queue;explicit Messages(u::ActorMessageQueue& value):queue(value){}
    bool send(const u::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const u::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const u::ResourcePositionMessage&)noexcept override{return false;}
    bool send(const u::ActorStatusMessage&)noexcept override{return false;}
    bool send(const u::ActorSpeechMessage& x)noexcept override{speech_messages.push_back({x.route==u::MessageRoute::mode_zero?0:1,std::int32_t(x.channel),std::bit_cast<std::int32_t>(x.sequence),x.target_identifier,x.target_context,x.response_state,x.pending,x.gauge_notice,x.variant});++queued;return queue.send(x);}
};
}
int main(int argc,char** argv)try{
    check(argc==2);auto source=std::make_shared<const reo::assets::Source>(argv[1]);s::content::ScenarioArchive archive(source);
    for(unsigned cohort=0;cohort<31;++cohort){
        std::fill(memory.begin(),memory.end(),0);owned_constants(memory.data());call(0x66a730);auto banks=std::make_shared<w::DialogueBanks>();for(unsigned i:{0u,1u,8u})(*banks)[i]=s::prepare_dialogue_bank(archive,1,0,std::uint8_t(i));
        const bool controlled=cohort>=8;const unsigned control=cohort>=28?0:controlled?(cohort-8)/2:999;const bool replying=controlled&&control>=6&&control<=8;
        const auto safe0=safe_cues((*banks)[0]),safe1=safe_cues((*banks)[1]);check(safe0.size()>=4&&safe1.size()>=4);
        if(controlled){const std::int8_t group=control<=1?0:control==2?1:control<=4?2:control==5?3:control<=8?4:6;const std::int8_t mode=control==1||control==2||control==7?1:control==3||control==4||control==5||control==8?2:0;controlled_response((*banks)[0],std::span<const unsigned>(safe0).first(control==5?2:1),group,mode,control==4||control==8?2u:0u);if(replying)controlled_reply((*banks)[1],safe1[0],safe0[0]);}
        w::World world(profile(),std::make_shared<w::Session>());check(w::initialize_primary_records(world).status==w::PrimaryRecordsStatus::completed);world.mode=std::uint8_t(cohort%2);world.room=1;world.session().primary_population=2;world.selected_actor=0;world.session().clock_mode=std::uint8_t((cohort/2)%2);world.session().message_phase=std::int8_t(cohort>=4?1:0);
        for(unsigned i=0;i<2;++i){const auto actor=world.primary(i);actor->active=actor->visible=true;actor->slot=actor->character=std::uint8_t(i);actor->room=1;actor->position={float(10*i),0,0};actor->current=actor->maximum=100;actor->motion_style=std::uint8_t(i);actor->class_marker=std::uint8_t(!i);actor->gauge_value=cohort&2?345600u:0u;}
        auto& auxiliary=world.auxiliary_actors();live_auxiliary=&auxiliary;const auto auxiliary_created=auxiliary.allocate();check(auxiliary_created.status==w::AuxiliaryStatus::completed);const auto aux=world.resolve(auxiliary_created.id);if(cohort==30)world.primary(1)->active=false;aux->active=cohort%3==0;aux->visible=false;aux->model_variant=1;aux->room=1;const auto aux_at=actor_address(world,auxiliary_created.id);put(aux_at,std::uint8_t(aux->active));put(aux_at+1,std::uint8_t(aux->visible));put(aux_at+2,aux->category);put(aux_at+3,aux->slot);put(aux_at+0x1e2,aux->room);put(aux_at+0xbb4,aux->model_variant);put(aux_at+0x1c,0u);export_speech(*aux,aux_at);put(0x3b59f0,aux_at);
        Notifications notifications;u::ActorReception reception(world);u::ActorMessageQueue queue(reception,1024);Messages messages(queue);u::Owner owner(world,notifications,reo::native::gameplay_events::RuleBook::file1(),&messages);s::SceneResources resources;s::ResourceTemplates templates;
        Backend backend;s::StreamChannels channels(s::file1_stream_gain_curve());reo::native::gameplay_audio::SpatialContext spatial;std::optional<std::uint32_t> tick=1;w::ActorVoiceRequests voice(world,channels,backend,spatial,tick);Display display(world);w::DialoguePool pool(world,&voice,&display);display.pool=&pool;
        w::DialogueGates gates{0,0};export_inputs(world,gates);put(0x3243f2,world.mode);put(0x3243fb,world.session().message_phase);put(0x3243cc,world.session().clock_mode);put(0x4bae77,std::uint8_t(world.session().cutscene_requests.limit_override));put(0x744638,world.session().actor_message_suppression);call(0x1b4a60);check(pool.initialize_owned_state()==w::DialogueStatus::completed);call(0x6b7610);check(pool.banks(banks)==w::DialogueStatus::completed);source_banks(*banks);compare(pool,world);
        w::input::Frame menu;w::input::ControllerFrame controller;const w::input::Remap remap{0x100,0x10,0x20};w::DialogueResponseFrame frame{&menu,0,gates,{&owner.flags(),&resources,&templates},&owner};
        const auto prelude=[&]{auto actor=world.primary(1);actor->speech.selection=w::SpeechSelection{safe1[0]+1,0,-1,0,0};export_speech(*actor,actor_base+0x10e0);events.clear();original_events.clear();const auto made=pool.construct(world.identity(1),gates);const auto original=call(0x6b7930,actor_base+0x10e0);check(made.status==w::DialogueStatus::completed&&made.original_return==GPR_S32(&original,2));check(pool.update(gates).status==w::DialogueStatus::completed);call(0x6b9590);compare(pool,world);check(events==original_events);++preludes;};
        for(unsigned step=0;step<(cohort>=29?1u:controlled?160u:96u);++step){
            if(step%32==0){const bool active=step%64==0;check(world.session().auxiliary_scene.set_timer(91,active));call(0x6ba230,91,active?1u:0u);check(pool.flag(91)==active);++external_timer_commands;}
            if(replying&&step%64==0)prelude();
            controller.held=controlled?(step%8==0?0x100u:0u):(step%8==0?0x100000u:step%8==2?0x2000u:0u);controller.held|=(!controlled&&step%16==0)?0x80u:0;controller.analog[5]=std::bit_cast<std::int16_t>(std::uint16_t(step*6000));frame.menu_actions=w::input::menu(menu,controller,remap);
            if(cohort>=28){world.primary(0)->speech.request=1;put(actor_base+0xda8,std::int8_t(1));menu.pressed=0;menu.held=0;frame.menu_actions=cohort==30?0x100u:0u;}
            world.primary(1)->speech.remote_request=std::uint8_t(!controlled&&step%17==0?1+cohort%8:0);put(actor_base+0x10e0+0x1098,*world.primary(1)->speech.remote_request);
            world.paused=std::int8_t(step%31==30);gates={std::uint8_t(step%37==36),std::uint8_t(step%41==40?4:0)};frame.gates=gates;hidden=step%43==42;display.reenter=step%19==18;
            put(0x324210,menu.pressed);put(0x324218,menu.held);put(0x32423a,menu.analog[5]);put(0x4bae90,*frame.menu_actions);put(0x4badf8,world.paused);put(0x4bae8d,*gates.blocked);put(0x4bae89,*gates.flags);
            events.clear();original_events.clear();speech_messages.clear();original_speech_messages.clear();stop_input_read=cohort==29;stop_target_read=cohort==30;const auto native=pool.advance_responses(frame);bool prefix_stopped{};try{call(0x6b7e40);}catch(const RefusalPrefix&){prefix_stopped=true;++prefix_stops;}
            if(cohort>=29){if(!prefix_stopped||native.status!=w::DialogueStatus::unsupported_profile)std::cerr<<"Prefix cohort="<<cohort<<" stopped="<<prefix_stopped<<" native="<<unsigned(native.status)<<" stage="<<unsigned(native.stage)<<" target="<<world.primary(0)->speech.selection->target_identifier<<" context="<<int(world.primary(0)->speech.selection->target_context)<<"\n";check(prefix_stopped&&native.status==w::DialogueStatus::unsupported_profile);for(unsigned i=0;i<8;++i)compare_speech(*world.primary(i),actor_base+0x10e0*i);compare_speech(*aux,aux_at);compare(pool,world);check(events==original_events&&speech_messages==original_speech_messages);stop_input_read=stop_target_read=false;continue;}
            check(!prefix_stopped);
            if(native.status!=w::DialogueStatus::completed)std::cerr<<"Full response status="<<unsigned(native.status)<<" stage="<<unsigned(native.stage)<<" cohort="<<cohort<<" frame="<<step<<" selection="<<native.selection.value_or(99999)<<'\n';
            check(native.status==w::DialogueStatus::completed);for(unsigned i=0;i<8;++i)compare_speech(*world.primary(i),actor_base+0x10e0*i);compare_speech(*aux,aux_at);compare(pool,world);check(events==original_events&&speech_messages==original_speech_messages);++frames;
            if(step%64==47){const auto retained=pool.record(0);check(pool.clear_records()==w::DialogueStatus::completed);call(0x6b7810);compare(pool,world);if(retained&&retained->text_owner){check(retained->text_owner->text(retained->text_index).has_value());++lifetimes;}}
        }
        check(queue.pending()<=queue.capacity());check(pool.advance_responses(w::DialogueResponseFrame{}).status==w::DialogueStatus::unavailable);check(world.close()==w::Status::completed&&pool.advance_responses(frame).status==w::DialogueStatus::closed);++guards;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"complete_original_frames\":"<<frames<<",\"external_shared_timer_commands\":"<<external_timer_commands<<",\"exact_unsupported_read_prefixes\":"<<prefix_stops<<",\"source_calls\":"<<source_calls<<",\"queued_speech_messages\":"<<queued<<",\"source_choice_calls\":"<<choose_calls<<",\"source_reply_calls\":"<<reply_calls<<",\"source_monitor_calls\":"<<monitor_calls<<",\"source_direct_calls\":"<<direct_calls<<",\"source_history_increments\":"<<history_calls<<",\"record_preludes\":"<<preludes<<",\"native_guards\":"<<guards<<",\"retained_text_lifetimes\":"<<lifetimes<<",\"game_run\":false,\"audio_device_opened\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
