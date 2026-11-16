#include "game/native/gameplay_world/dialogue_pool.hpp"
#include "game/native/gameplay_world/dialogue_responses.hpp"
#include "game/native/gameplay_world/primary_actor_records.hpp"
#include "game/native/gameplay_world/auxiliary_actors.hpp"
#include "game/native/gameplay_update/update.hpp"
#include "game/native/gameplay_update/actor_message_queue.hpp"
#include "game/native/gameplay_scenario/scene_resources.hpp"
#include "game/native/gameplay_world/dialogue_room_banks.hpp"
#include "game/native/gameplay_scenario/auxiliary_room_rows.hpp"
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
std::vector<std::uint8_t> memory(0x2000000);bool hidden{},source_interrupt{},stop_input_read{},stop_target_read{},stop_section{};std::size_t evb_bytes{};
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

void export_inputs(const w::World& world,const w::DialogueGates& gates){memory[0x4baded]=world.selected_actor;put(0x3243dc,world.room);put(0x4badf8,world.paused);memory[0x4bae8d]=gates.blocked.value_or(0);memory[0x4bae89]=gates.flags.value_or(0);put(0x4baea0,*world.session().primary_population);put(0x324438,source_work);for(unsigned i=0;i<8;++i)export_actor(world,i);const auto random=world.session().random.state();put(0x3244b0,random.primary);put(0x3244b8,random.secondary);put(0x2b8de8,random.observed);}
[[maybe_unused]] void source_banks(const w::DialogueBanks& banks){
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
    if(stop_section&&context->pc>=0x6b73f0&&context->pc<0x6b7480&&(at<0x1100000||at>=0x1100000+evb_bytes))throw RefusalPrefix{};
    if(stop_input_read&&(context->pc==0x6b7de0||context->pc==0x6b7df4))throw RefusalPrefix{};
    return ram[at];
}
std::uint32_t observed_response_word(const std::uint8_t* ram,const R5900Context* context,std::uint32_t at){
    if(stop_target_read&&context->pc==0x6b875c)throw RefusalPrefix{};
    std::uint32_t value;std::memcpy(&value,ram+at,4);return value;
}
namespace {
struct IoMember {std::uint64_t at{};std::uint32_t logical{},storage{};};
struct IoCatalogue {std::uint16_t scenario{};std::uint32_t first{},count{};std::vector<std::uint8_t> keys;std::vector<IoMember> members;};
std::shared_ptr<const reo::assets::Source> actual_source;std::vector<IoCatalogue> catalogues;const IoCatalogue* selected_catalogue{};const IoMember* selected_member{};
std::uint64_t load_calls{},resets{},cache_hits{},sdk_reads{},retained_banks{};bool bank_read_scope{};
struct Transfer {std::uint64_t offset{};std::size_t bytes{};};std::vector<Transfer> original_transfers;
struct TraceSource final:reo::assets::PositionedSource {
    std::shared_ptr<const reo::assets::Source> actual;mutable std::vector<Transfer> reads;
    explicit TraceSource(std::shared_ptr<const reo::assets::Source> value):actual(std::move(value)){}
    std::uint64_t size()const noexcept override{return actual->size;}
    std::size_t read(std::uint64_t at,std::size_t n,void* output)const override{actual->read(at,n,output);reads.push_back({at,n});return n;}
};
std::string lower(std::string value){for(char& c:value)if(c>='A'&&c<='Z')c+='a'-'A';return value;}
void import_catalogues(){
    const auto root=reo::assets::table(*actual_source,0,actual_source->size);
    for(unsigned id:{1u,2u,28u,35u,41u}){char afs[16],header[16];std::snprintf(afs,sizeof afs,"r%03u.afs",id);std::snprintf(header,sizeof header,"r%03u_h.bin",id);
        const auto archive=std::find_if(root.entries.begin(),root.entries.end(),[&](const auto& e){return lower(e.name)==afs;});const auto names=std::find_if(root.entries.begin(),root.entries.end(),[&](const auto& e){return lower(e.name)==header;});check(archive!=root.entries.end()&&names!=root.entries.end());
        std::vector<std::uint8_t> raw(names->size);actual_source->read(names->offset,raw.size(),raw.data());IoCatalogue table;table.scenario=std::uint16_t(id);table.first=reo::assets::u32(raw.data());table.count=reo::assets::u32(raw.data()+4);check(raw.size()==8+16ull*table.count);table.keys.assign(raw.begin()+8,raw.end());const auto members=reo::assets::table(*actual_source,archive->offset,archive->size);check(table.first+table.count<=members.entries.size());
        for(const auto& e:members.entries){const auto storage=(std::uint64_t(e.size)+2047u)&~std::uint64_t(2047);check(std::uint64_t(e.offset)+storage<=archive->size);table.members.push_back({std::uint64_t(archive->offset)+e.offset,e.size,std::uint32_t(storage)});}catalogues.push_back(std::move(table));
    }
}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++source_calls;load_calls+=context->pc==0x1d41f0;resets+=context->pc==0x6b7720;choose_calls+=context->pc==0x6b8650;reply_calls+=context->pc==0x6b8cc0;monitor_calls+=context->pc==0x6b90a0;direct_calls+=context->pc==0x6b8f60;history_calls+=context->pc==0x6b92e0;
if(context->pc==0x1ba250&&GPR_S32(context,6)>=0){check(!memory[GPR_U32(context,4)+2]);original_events.push_back({3,memory[GPR_U32(context,4)+3],0,0,{}});}
if(context->pc==0x1b49b0)original_events.push_back({0,0,0,0,string(GPR_U32(context,4))});
if(context->pc==0x1b48e0){check(GPR_U32(context,6)==1&&GPR_U32(context,7)==20);original_events.push_back({2,GPR_S32(context,4),GPR_S32(context,5),std::uint8_t(GPR_U32(context,9)),string(GPR_U32(context,8))});}
if(context->pc==0x6dee20){memory[0x4bae33]=1;memory[0x755ec4]=hidden?1:0;memory[0x4badee]=0;original_events.push_back({1,hidden?1:0,0,0,{}});}
switch(context->pc){
#include "original_dispatch.hpp"
case 0x10a830:{const auto format=string(GPR_U32(context,5));std::string pattern(reinterpret_cast<const char*>(format.data()),format.size());auto destination=reinterpret_cast<char*>(memory+GPR_U32(context,4));int size{};
    if(pattern.starts_with("data/rom/scene/spk/")&&pattern.ends_with("08.bin"))size=std::snprintf(destination,96,pattern.c_str(),GPR_U32(context,6),GPR_U32(context,7),GPR_U32(context,8));
    else if(pattern.starts_with("data/rom/scene/spk/"))size=std::snprintf(destination,96,pattern.c_str(),GPR_U32(context,6),GPR_U32(context,7),GPR_U32(context,8),GPR_U32(context,9));
    else if(pattern.ends_with("08.bin"))size=std::snprintf(destination,96,pattern.c_str(),GPR_U32(context,6),GPR_U32(context,7));
    else size=std::snprintf(destination,96,pattern.c_str(),GPR_U32(context,6),GPR_U32(context,7),GPR_U32(context,8));
    check(size>=0&&size<96);SET_GPR_U32(context,2,unsigned(size));break;}
case 0x1aa1e0:{const auto id=GPR_U32(context,4);const auto found=std::find_if(catalogues.begin(),catalogues.end(),[&](const auto& value){return value.scenario==id;});check(found!=catalogues.end());selected_catalogue=&*found;put(0x2b16a0,0x123450u);put(0x123450,1u);put(0x12345c,0x140000u);put(0x123464,found->count);put(0x123468,found->first);put(0x123470,7u);std::memcpy(memory+0x140000,found->keys.data(),found->keys.size());SET_GPR_U32(context,2,0);break;}
case 0x10cda8:{auto p=memory+GPR_U32(context,4);for(;*p;++p)if(*p>='a'&&*p<='z')*p+='A'-'a';SET_GPR_U32(context,2,GPR_U32(context,4));break;}
case 0x10b158:SET_GPR_U32(context,2,unsigned(std::strlen(reinterpret_cast<const char*>(memory+GPR_U32(context,4)))));break;
case 0x10b7b8:{const auto at=std::strrchr(reinterpret_cast<const char*>(memory+GPR_U32(context,4)),int(GPR_U32(context,5)));SET_GPR_U32(context,2,at?unsigned(reinterpret_cast<const std::uint8_t*>(at)-memory):0u);break;}
case 0x129240:{check(selected_catalogue&&GPR_U32(context,4)==7);const auto ordinal=GPR_U32(context,5);check(ordinal<selected_catalogue->members.size());selected_member=&selected_catalogue->members[ordinal];check(selected_member->storage>0);put(0x17000c,0u);put(0x170004,0x180000u);put(0x180010,selected_member->storage);SET_GPR_U32(context,2,0x170000);break;}
case 0x1297a0:{check(selected_member&&GPR_U32(context,4)==0x170000&&GPR_U32(context,5)==selected_member->storage/2048);actual_source->read(selected_member->at,selected_member->storage,memory+GPR_U32(context,6));original_transfers.push_back({selected_member->at,selected_member->storage});++sdk_reads;SET_GPR_U32(context,2,0);break;}
case 0x129d48:check(GPR_U32(context,4)==0x170000);SET_GPR_U32(context,2,3);break;
case 0x129350:check(GPR_U32(context,4)==0x170000);SET_GPR_U32(context,2,0);break;

case 0x1afdd0:{const auto at=GPR_U32(context,5);check(GPR_U32(context,6)==0&&GPR_U32(context,7)==4&&memory[at]==11&&memory[at+1]==20);original_speech_messages.push_back({memory[0x3243f2]==0?0:1,std::int32_t(GPR_U32(context,4)),std::bit_cast<std::int32_t>(get<unsigned>(at+4)),get<std::int16_t>(at+8),get<std::int16_t>(at+10),get<std::int32_t>(at+16),get<std::int8_t>(at+12),get<std::int8_t>(at+13),get<std::int8_t>(at+14)});SET_GPR_U32(context,2,0);break;}

default:throw std::runtime_error("Undeclared pool source helper "+std::to_string(context->pc));}context->pc=GPR_U32(context,31);}

namespace {
template<class T>void encode(std::vector<std::byte>& b,std::size_t at,T value){std::memcpy(b.data()+at,&value,sizeof value);}
[[maybe_unused]] std::uint32_t word(const std::vector<std::byte>& b,std::size_t at){std::uint32_t result{};std::memcpy(&result,b.data()+at,4);return result;}
std::vector<unsigned> safe_cues(const s::DialogueBank& bank){std::vector<unsigned> result;for(unsigned i=1;i<5000;++i){const auto cue=bank.cues->cue(i);if(!cue)continue;const auto text=bank.texts->text(cue->text);if(!text)continue;unsigned line{},lines{},maximum{};for(const auto c:text->body){if(c==std::byte{10}||c==std::byte{13}){maximum=std::max(maximum,line);line=0;lines+=c==std::byte{10};}else ++line;}maximum=std::max(maximum,line);if(maximum<=28&&lines<=8)result.push_back(i);}return result;}
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
namespace {
unsigned bank_word(const s::content::Bytes& bytes,std::size_t at){unsigned value;std::memcpy(&value,bytes->data()+at,4);return value;}
void compare_banks(const w::DialoguePool& pool){
    const auto banks=pool.bank_snapshot();
    for(unsigned character=0;character<9;++character){const auto physical=character==8?4u:unsigned(memory[0x74f0f4+character]);check(physical<5);const auto first=get<unsigned>(0x74f0cc+4*physical),second=get<unsigned>(0x74f0b8+4*physical),text=get<unsigned>(0x74f0e0+4*physical);const auto cues=banks?(*banks)[character].cues:nullptr;const auto texts=banks?(*banks)[character].texts:nullptr;check(bool(cues)==bool(first)&&bool(cues)==bool(second)&&bool(texts)==bool(text));
        if(cues){const auto data=cues->backing();const auto root=first-bank_word(data,16);check(second==root+bank_word(data,20));check(std::memcmp(data->data(),memory.data()+root,bank_word(data,20))==0);}
        if(texts){const auto data=texts->backing();check(std::memcmp(data->data(),memory.data()+text,data->size())==0);}
    }
}
void source_scenario(const s::content::ScriptBank& bank){const auto data=bank.backing();evb_bytes=data->size();check(evb_bytes<0x200000);std::memcpy(memory.data()+0x1100000,data->data(),data->size());const auto table=get<unsigned>(0x1100060);if(table)put(0x1100060,0x1100000+table);put(0x324424,0x1100000u);}
s::content::ScriptBank section_bank(const s::content::ScriptBank& original,std::uint8_t value){auto bytes=std::make_shared<std::vector<std::byte>>(*original.backing());const auto table=bank_word(bytes,0x60);check(table);const auto row=bank_word(bytes,table);(*bytes)[row]=std::byte(value);return s::content::ScriptBank(bytes,s::content::BankFormat::scenario_evb);}
}
int main(int argc,char** argv)try{
    check(argc==2);actual_source=std::make_shared<const reo::assets::Source>(argv[1]);import_catalogues();auto traced=std::make_shared<TraceSource>(actual_source);auto source=std::make_shared<const reo::assets::Source>("dialogue-bank-owned-source",traced);s::content::ScenarioArchive archive(source);
    for(unsigned scenario:{1u,2u,28u,35u,41u})for(unsigned mode:{0u,1u,255u}){
        std::fill(memory.begin(),memory.end(),0);owned_constants(memory.data());call(0x66a730);const auto original_bank=archive.scenario_scripts(std::uint16_t(scenario));check(bool(original_bank));const auto rows=s::AuxiliaryRoomRows::import(*original_bank);check(rows&&rows->row_count()>0);const auto selected_bank=section_bank(*original_bank,0);
        w::World world(profile(),std::make_shared<w::Session>());check(w::initialize_primary_records(world).status==w::PrimaryRecordsStatus::completed);world.mode=1;world.room=0;world.selected_actor=0;world.session().scenario=std::uint16_t(scenario);world.session().room_variant=65535;world.session().asset_loading_mode=std::uint8_t(mode);world.session().primary_population=2;world.session().clock_mode=0;world.session().message_phase=1;world.session().auxiliary_scene.bind(s::AuxiliaryRoomRows::import(selected_bank));
        for(unsigned i=0;i<2;++i){const auto actor=world.primary(i);actor->slot=actor->character=std::uint8_t(i);actor->room=world.room;actor->current=actor->maximum=100;actor->motion_style=std::uint8_t(i);actor->class_marker=std::uint8_t(!i);actor->gauge_value=0;actor->position={float(10*i),0,0};}
        live_auxiliary=&world.auxiliary_actors();Notifications notifications;u::ActorReception reception(world);u::ActorMessageQueue queue(reception,1024);Messages messages(queue);u::Owner owner(world,notifications,reo::native::gameplay_events::RuleBook::file1(),&messages);s::SceneResources resources;s::ResourceTemplates templates;Backend backend;s::StreamChannels channels(s::file1_stream_gain_curve());reo::native::gameplay_audio::SpatialContext spatial;std::optional<std::uint32_t> tick=1;w::ActorVoiceRequests voice(world,channels,backend,spatial,tick);Display display(world);w::DialoguePool pool(world,&voice,&display);display.pool=&pool;w::DialogueGates gates{0,0};
        export_inputs(world,gates);put(0x4b9d14,world.session().auxiliary_scene.loaded_index());put(0x4b9d15,world.session().auxiliary_scene.row());put(0x3243f2,world.mode);put(0x3243fb,world.session().message_phase);put(0x3243cc,world.session().clock_mode);put(0x3243f8,std::uint8_t(255));put(0x3243f9,std::uint8_t(255));put(0x4bae77,std::uint8_t(0));put(0x744638,std::uint16_t(0));call(0x1b4a60);check(pool.initialize_owned_state()==w::DialogueStatus::completed);call(0x6b7610);compare(pool,world);compare_banks(pool);
        const auto select=[&](std::uint32_t word){world.session().auxiliary_scene.select(word);put(0x10000,word);call(0x692a00,0x10000);check(world.session().auxiliary_scene.row()==memory[0x4b9d15]&&world.session().auxiliary_scene.loaded_index()==memory[0x4b9d14]);};
        const auto refresh=[&](const s::content::ScriptBank& bank){source_scenario(bank);put(0x3243da,world.session().scenario.value_or(0));put(0x3243d7,world.session().asset_loading_mode.value_or(0));put(0x3243dc,world.room);put(0x3243de,world.session().room_variant.value_or(0));put(0x4baea0,*world.session().primary_population);for(unsigned i=0;i<8;++i)export_actor(world,i);traced->reads.clear();original_transfers.clear();const auto resets_before=resets;const auto result=pool.refresh_room_banks(archive,bank);call(0x1d41f0);check(result.status==w::DialogueStatus::completed&&result.reset==(resets!=resets_before));cache_hits+=result.cache_hit;check(world.session().auxiliary_scene.loaded_index()==memory[0x4b9d14]);check(traced->reads.size()==original_transfers.size()&&result.loaded==traced->reads.size());for(unsigned i=0;i<traced->reads.size();++i){check(traced->reads[i].offset==original_transfers[i].offset);check(((traced->reads[i].bytes+2047u)&~std::size_t(2047))==original_transfers[i].bytes);}for(unsigned i=0;i<8;++i)compare_speech(*world.primary(i),actor_base+0x10e0*i);compare(pool,world);compare_banks(pool);return result;};
        check(refresh(selected_bank).loaded==6);check(refresh(selected_bank).cache_hit);
        auto banks=pool.bank_snapshot();check(banks&&(*banks)[0].cues&&(*banks)[0].texts);const auto safe=safe_cues((*banks)[0]);check(!safe.empty());const auto actor=world.primary(0);actor->active=actor->visible=true;actor->speech.selection=w::SpeechSelection{safe.front()+1,1,1,0,-1};export_actor(world,0);events.clear();original_events.clear();const auto made=pool.construct(world.identity(0),gates);const auto made_original=call(0x6b7930,actor_base);check(made.status==w::DialogueStatus::completed&&made.original_return==GPR_S32(&made_original,2));check(pool.update(gates).status==w::DialogueStatus::completed);call(0x6b9590);check(events==original_events);compare(pool,world);const auto retained=pool.record(0);actor->active=actor->visible=false;export_actor(world,0);
        check(world.session().auxiliary_scene.set_timer(91,true));call(0x6ba230,91,1);for(unsigned i=0;i<3;++i){check(pool.advance_flag_durations()==w::DialogueStatus::completed);call(0x6b80a0);}check(pool.flag_duration(91)==3);const auto duration=pool.flag_duration(91);
        select(0x100);check(refresh(selected_bank).loaded==6&&pool.flag_duration(91)==duration);if(retained&&retained->text_owner){check(retained->text_owner->text(retained->text_index).has_value());++retained_banks;}
        world.primary(1)->character=0;select(0x100);check(refresh(selected_bank).loaded==6);banks=pool.bank_snapshot();check((*banks)[0].cues==(*banks)[1].cues&&(*banks)[0].texts==(*banks)[1].texts);
        const auto failed=section_bank(*original_bank,254);select(0x100);const auto before=pool.bank_snapshot();const auto miss=refresh(failed);check(miss.missing==6&&miss.loaded==0&&pool.bank_snapshot()==before&&world.session().auxiliary_scene.loaded_index()==254);check(refresh(failed).cache_hit);
        select(std::uint32_t(rows->row_count()+1));world.room=65535;world.session().room_variant.reset();world.session().scenario.reset();world.session().asset_loading_mode.reset();const auto past=refresh(selected_bank);check(past.section==-1&&past.reset&&past.requested==0);check(refresh(selected_bank).reset);
        // Equal count reaches an undefined sentinel-relative byte read.
        select(std::uint32_t(rows->row_count()));world.room=0;world.session().room_variant=0;source_scenario(selected_bank);put(0x3243dc,world.room);stop_section=true;const auto native=pool.refresh_room_banks(archive,selected_bank);bool stopped{};try{call(0x1d41f0);}catch(const RefusalPrefix&){stopped=true;}stop_section=false;check(stopped&&native.status==w::DialogueStatus::unsupported_profile&&!native.reset);++prefix_stops;compare(pool,world);compare_banks(pool);
        check(world.close()==w::Status::completed&&pool.refresh_room_banks(archive,selected_bank).status==w::DialogueStatus::closed);++guards;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"complete_original_bank_refreshes\":"<<load_calls-prefix_stops<<",\"complete_original_resets\":"<<resets<<",\"source_sector_reads\":"<<sdk_reads<<",\"cache_hits\":"<<cache_hits<<",\"equal_count_read_prefixes\":"<<prefix_stops<<",\"retained_text_leases\":"<<retained_banks<<",\"source_calls\":"<<source_calls<<",\"game_run\":false,\"audio_device_opened\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
