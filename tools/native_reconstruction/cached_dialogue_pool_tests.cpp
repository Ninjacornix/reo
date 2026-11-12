#include "game/native/gameplay_world/dialogue_pool.hpp"
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
namespace w=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;
namespace {
std::uint64_t checks{},source_calls{},constructors{},updates{},clears{},lifetimes{},guards{},interruptions{},effect_writes{},capacity_refusals{},literal_records{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Dialogue pool "+std::to_string(at.line())+" constructors "+std::to_string(constructors)+" updates "+std::to_string(updates));}
struct Event {unsigned kind{};std::int32_t first{},second{};std::uint8_t alpha{};std::vector<std::byte> text;friend bool operator==(const Event&,const Event&)=default;};
std::vector<Event> events,original_events;
const s::TextCache* live_cache{};
std::vector<std::uint8_t> memory(0x2000000);bool hidden{},source_interrupt{};
constexpr unsigned actor_base=0x4a5c30,source_work=0x800000;
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
std::vector<std::byte> string(unsigned at){std::vector<std::byte> value;for(unsigned i=0;i<64;++i){const auto c=memory.at(at+i);if(!c)return value;value.push_back(std::byte(c));}throw std::runtime_error("Unbounded source dialogue string");}
struct Display final:w::DialoguePresentation {
    w::World& world;w::DialoguePool* pool{};bool reenter{};s::TextCache cache;w::DialogueVisibilityInputs visibility{std::uint8_t(1),std::uint8_t(0)};w::CachedDialoguePresentation actual;explicit Display(w::World& value):world(value),actual(value,cache,visibility){cache.reset();live_cache=&cache;}
    bool bound_to(const w::World& value)const noexcept override{return &value==&world;}
    bool erase(std::span<const std::byte> value)noexcept override{events.push_back({0,0,0,0,{value.begin(),value.end()}});if(reenter){check(pool&&pool->clear_records()==w::DialogueStatus::busy&&world.close()==w::Status::busy);++guards;}return actual.erase(value);}
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
unsigned actor_address(const w::World& world,const w::actors::EntityId& id){for(unsigned i=0;i<2;++i)if(id==world.identity(i))return actor_base+i*0x10e0;return 0;}
void export_actor(const w::World& world,unsigned index){const auto actor=world.primary(index);const unsigned at=actor_base+index*0x10e0;memory[at]=actor->active?1:0;memory[at+2]=actor->category;memory[at+3]=actor->slot;put(at+0x38,actor->position);put(at+0x58,actor->collision.basis.x.z);put(at+0x1e2,actor->room);memory[at+0xb98]=actor->character;memory[at+0xb99]=actor->class_marker;put(at+0xdb4,actor->speech.selection?actor->speech.selection->sequence:0);put(at+0xdb8,actor->speech.gauge_notice.value_or(0));put(at+0xdbc,actor->speech.dialogue_delay.value_or(0));put(at+0xda9,actor->speech.variant.value_or(0));put(at+0x1075,actor->speech.display_style.value_or(0));}
void export_inputs(const w::World& world,const w::DialogueGates& gates){memory[0x4baded]=world.selected_actor;put(0x4badf8,world.paused);memory[0x4bae8d]=gates.blocked.value_or(0);memory[0x4bae89]=gates.flags.value_or(0);put(0x4baea0,*world.session().primary_population);put(0x324438,source_work);for(unsigned i=0;i<2;++i)export_actor(world,i);const auto random=world.session().random.state();put(0x3244b0,random.primary);put(0x3244b8,random.secondary);put(0x2b8de8,random.observed);}
void source_banks(const w::DialogueBanks& banks){
    for(unsigned index:{0u,1u,8u}){const auto& bank=banks[index];const unsigned physical=index==8?4:index,base=source_work+0x6000+0x12800*physical,text_base=source_work+0x5c000+0x5c00*physical;check(bank.cues&&bank.texts);const auto cues=bank.cues->backing(),text=bank.texts->backing();std::memcpy(memory.data()+base,cues->data(),cues->size());std::memcpy(memory.data()+text_base,text->data(),text->size());call(0x6b7350,base,0,physical);call(0x6b7350,text_base,1,physical);}
}
void compare(const w::DialoguePool& pool,const w::World& world){
    for(unsigned index=0;index<16;++index){const auto value=pool.record(index);check(bool(value));const auto& r=*value;std::array<std::uint8_t,0x98> expected{};const auto write=[&]<class T>(unsigned at,T v){std::memcpy(expected.data()+at,&v,sizeof v);};
        write(0,std::uint16_t(r.active));write(2,r.phase);write(4,r.delay);write(6,r.initial_delay);write(8,r.age);write(0xa,r.fade_ticks);write(0xb,r.character_ticks);write(0xc,r.alpha);write(0xd,r.channel);write(0xe,r.revealed);write(0x10,r.line_bytes);unsigned text_at{};
        if(r.text_owner){const auto actor=world.resolve(r.actor);check(bool(actor));const auto text_base=source_work+0x5c000+0x5c00*actor->slot;const auto reference=get<unsigned>(text_base+4+8*r.text_index);text_at=text_base+get<unsigned>(text_base+reference)+8;}
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
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++source_calls;
if(context->pc==0x1b49b0)original_events.push_back({0,0,0,0,string(GPR_U32(context,4))});
if(context->pc==0x1b48e0){check(GPR_U32(context,6)==1&&GPR_U32(context,7)==20);original_events.push_back({2,GPR_S32(context,4),GPR_S32(context,5),std::uint8_t(GPR_U32(context,9)),string(GPR_U32(context,8))});}
if(context->pc==0x6dee20){memory[0x4bae33]=1;memory[0x755ec4]=hidden?1:0;memory[0x4badee]=0;original_events.push_back({1,hidden?1:0,0,0,{}});}
switch(context->pc){
#include "original_dispatch.hpp"
case 0x10a830:{const auto format=GPR_U32(context,5),destination=GPR_U32(context,4);unsigned i{};for(;i<32&&memory[format+i];++i)memory[destination+i]=memory[format+i];check(i<32);memory[destination+i]=0;SET_GPR_U32(context,2,i);break;}
case 0x1ba250:if(GPR_S32(context,6)>=0){if(memory[GPR_U32(context,4)+2]){source_interrupt=true;context->pc=0xdead0001;return;}original_events.push_back({3,memory[GPR_U32(context,4)+3],0,0,{}});}SET_GPR_S32(context,2,-1);break;
default:throw std::runtime_error("Undeclared pool source helper "+std::to_string(context->pc));}context->pc=GPR_U32(context,31);}
int main(int argc,char** argv)try{
    check(argc==2);auto source=std::make_shared<const reo::assets::Source>(argv[1]);s::content::ScenarioArchive archive(source);auto banks=std::make_shared<w::DialogueBanks>();for(unsigned i:{0u,1u,8u})(*banks)[i]=s::prepare_dialogue_bank(archive,1,0,std::uint8_t(i));
    std::array<std::vector<unsigned>,2> choices;
    for(unsigned bank=0;bank<2;++bank)for(unsigned index=0;index<s::DialogueCues::selections;++index){const auto cue=(*banks)[bank].cues->cue(index);if(!cue)continue;const auto text=(*banks)[bank].texts->text(cue->text);if(!text)continue;unsigned line{},lines{},maximum{};for(const auto c:text->body){if(c==std::byte{10}||c==std::byte{13}){maximum=std::max(maximum,line);line=0;lines+=c==std::byte{10};}else ++line;}maximum=std::max(maximum,line);if(maximum<=28&&lines<=8)choices[bank].push_back(index);}
    check(!choices[0].empty()&&!choices[1].empty());
    for(unsigned bank=0;bank<2;++bank)std::stable_sort(choices[bank].begin(),choices[bank].end(),[&](unsigned a,unsigned b){const auto left=(*banks)[bank].texts->text((*banks)[bank].cues->cue(a)->text),right=(*banks)[bank].texts->text((*banks)[bank].cues->cue(b)->text);return (left->effects[0]!=0xffff)>(right->effects[0]!=0xffff);});
    w::World world(profile(),std::make_shared<w::Session>());world.session().primary_population=2;for(unsigned i=0;i<2;++i){auto actor=std::make_unique<w::Actor>();actor->active=true;actor->slot=std::uint8_t(i);actor->character=std::uint8_t(i);actor->room=1;actor->speech.variant=0;actor->speech.dialogue_delay=0;actor->speech.display_style=0;check(world.spawn_primary(i,std::move(actor)).status==w::actors::EntityStatus::completed);}
    Backend backend;s::StreamChannels channels(s::file1_stream_gain_curve());reo::native::gameplay_audio::SpatialContext spatial;std::optional<std::uint32_t> tick=1;w::ActorVoiceRequests voice(world,channels,backend,spatial,tick);Display display(world);w::DialoguePool pool(world,&voice,&display);display.pool=&pool;
    bool duplicate{};try{w::DialoguePool other(world);}catch(const std::invalid_argument&){duplicate=true;}check(duplicate);++guards;
    w::DialogueGates gates{0,0};owned_constants(memory.data());export_inputs(world,gates);put(0x74dd32,std::int16_t(43));call(0x1b4a60);check(pool.initialize_owned_state()==w::DialogueStatus::completed);call(0x6b7610);check(!pool.selected_counts());compare(pool,world);check(pool.banks(banks)==w::DialogueStatus::completed);source_banks(*banks);
    for(unsigned seed=0;seed<48;++seed){check(pool.clear_records()==w::DialogueStatus::completed);call(0x6b7810);compare(pool,world);++clears;
        world.selected_actor=std::uint8_t(seed%2);world.paused=std::int8_t(seed%13==0);gates={std::uint8_t(seed%17==0),std::uint8_t(seed%19==0?4:0)};
        for(unsigned index=0;index<16;++index){const unsigned actor_index=index%2;auto actor=world.primary(actor_index);actor->active=index%11!=0;actor->speech.selection=w::SpeechSelection{choices[actor_index][(seed+index)%choices[actor_index].size()]+1,0,0,0,0};actor->speech.variant=std::bit_cast<std::int8_t>(std::uint8_t((seed+index)%5==0?0x81:(seed+index)%3));actor->class_marker=std::uint8_t(index%2);actor->position={float(index%3)*100,0,0};actor->speech.gauge_notice=std::int32_t(seed%2);actor->collision.basis.x.z=std::bit_cast<float>(seed&1?0x3f80ffffu:0x3f800001u);export_inputs(world,gates);
            const auto native=pool.construct(world.identity(actor_index),gates);const auto original=call(0x6b7930,actor_base+0x10e0*actor_index);check(native.status==w::DialogueStatus::completed&&native.original_return==GPR_S32(&original,2));effect_writes+=native.effects;if(native.record)literal_records+=pool.record(*native.record)->literal!=0;compare(pool,world);++constructors;}
        world.paused=0;gates={0,0};export_inputs(world,gates);hidden=bool(seed&4);display.reenter=seed%7==0;
        for(unsigned frame=0;frame<24;++frame){events.clear();original_events.clear();const auto native=pool.update(gates);call(0x6b9590);check(native.status==w::DialogueStatus::completed);compare(pool,world);check(events==original_events);++updates;}
    }
    check(pool.clear_records()==w::DialogueStatus::completed);call(0x6b7810);world.selected_actor=0;world.paused=0;gates={0,0};auto actor=world.primary(0);actor->active=true;actor->position={};world.primary(1)->position={};actor->speech.variant=0;actor->speech.selection=w::SpeechSelection{1,0,0,0,0};export_inputs(world,gates);
    // Owned USA texts never begin with8169. A retained controlled copy tests
    // that source branch and its successful-but-zero constructor return.
    auto literal_banks=std::make_shared<w::DialogueBanks>(*banks);auto literal_bytes=std::make_shared<std::vector<std::byte>>(*(*banks)[0].texts->backing());unsigned reference{},literal_at{};std::memcpy(&reference,literal_bytes->data()+4,4);std::memcpy(&literal_at,literal_bytes->data()+reference,4);literal_at+=8;(*literal_bytes)[literal_at]=std::byte{0x81};(*literal_bytes)[literal_at+1]=std::byte{0x69};(*literal_banks)[0].texts=std::make_shared<const s::DialogueTexts>(literal_bytes);check(pool.banks(literal_banks)==w::DialogueStatus::completed);source_banks(*literal_banks);
    const auto literal=pool.construct(world.identity(0),gates);const auto literal_original=call(0x6b7930,actor_base);check(literal.record&&literal.original_return==0&&GPR_S32(&literal_original,2)==0&&pool.record(*literal.record)->literal==1);++literal_records;++constructors;compare(pool,world);const auto literal_snapshot=pool.record(*literal.record);
    check(pool.clear_records()==w::DialogueStatus::completed);call(0x6b7810);check(pool.banks(banks)==w::DialogueStatus::completed);source_banks(*banks);check(literal_snapshot->text_owner->text(0)->body[0]==std::byte{0x81});++lifetimes;
    for(unsigned index=0;index<17;++index){const auto native=pool.construct(world.identity(0),gates);const auto original=call(0x6b7930,actor_base);check(native.original_return==GPR_S32(&original,2));check(native.status==(index<16?w::DialogueStatus::completed:w::DialogueStatus::capacity));if(index==16)++capacity_refusals;compare(pool,world);++constructors;}
    for(unsigned frame=0;frame<24;++frame){events.clear();original_events.clear();check(pool.update(gates).status==w::DialogueStatus::completed);call(0x6b9590);compare(pool,world);check(events==original_events);++updates;}
    const auto reused=pool.construct(world.identity(0),gates);const auto reused_original=call(0x6b7930,actor_base);check(reused.status==w::DialogueStatus::completed&&reused.record&&reused.original_return==GPR_S32(&reused_original,2));compare(pool,world);++constructors;
    const auto snapshot=pool.record(0);check(snapshot.has_value());check(pool.clear_records()==w::DialogueStatus::completed);call(0x6b7810);compare(pool,world);if(snapshot->text_owner){check(snapshot->text_owner->text(snapshot->text_index).has_value());++lifetimes;}
    std::cout<<"{\"checks\":"<<checks<<",\"complete_constructors\":"<<constructors<<",\"complete_pool_updates\":"<<updates<<",\"source_calls\":"<<source_calls<<",\"record_clears\":"<<clears<<",\"native_guards\":"<<guards<<",\"retained_text_lifetimes\":"<<lifetimes<<",\"controlled_interruptions\":"<<interruptions<<",\"authored_effect_writes\":"<<effect_writes<<",\"literal_records\":"<<literal_records<<",\"capacity_refusals\":"<<capacity_refusals<<",\"game_run\":false,\"audio_device_opened\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
