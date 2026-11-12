#include "game/native/gameplay_world/dialogue_records.hpp"
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
namespace w=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;
namespace {
std::uint64_t checks{},source_calls{},source_cases{},frames{},refusals{},continuation_frames{},lifetimes{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Dialogue source comparison "+std::to_string(at.line())+" case "+std::to_string(source_cases));}
void word(std::vector<std::byte>& bytes,unsigned at,unsigned value){for(unsigned i=0;i<4;++i)bytes.at(at+i)=std::byte((value>>(8*i))&255);}
std::shared_ptr<const s::DialogueTexts> text(std::span<const std::uint8_t> body){auto bytes=std::make_shared<std::vector<std::byte>>(24+body.size()+1+16);const auto effects=unsigned(24+body.size()+1);word(*bytes,0,effects);word(*bytes,4,12);word(*bytes,8,1);word(*bytes,12,16);for(unsigned i=0;i<body.size();++i)(*bytes)[24+i]=std::byte(body[i]);for(unsigned i=effects;i<bytes->size();++i)(*bytes)[i]=std::byte{255};return std::make_shared<const s::DialogueTexts>(bytes);}
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
struct Event {unsigned kind{};std::int32_t first{},second{};std::uint8_t alpha{};std::vector<std::byte> text;friend bool operator==(const Event&,const Event&)=default;};
std::vector<Event> events;
struct Display final:w::DialoguePresentation {
    w::World& world;bool hidden{};explicit Display(w::World& value):world(value){}
    bool bound_to(const w::World& value)const noexcept override{return &world==&value;}
    bool erase(std::span<const std::byte> value)noexcept override{events.push_back({0,0,0,0,{value.begin(),value.end()}});return true;}
    std::optional<bool> suppressed()noexcept override{events.push_back({1,hidden?1:0,0,0,{}});return hidden;}
    bool draw(std::int16_t center,std::uint16_t y,std::span<const std::byte> value,std::uint8_t alpha)noexcept override{events.push_back({2,center,y,alpha,{value.begin(),value.end()}});return true;}
};
struct Backend final:s::StreamBackend {
    s::StreamValue phase(std::uint8_t)noexcept override{return{s::StreamStatus::unbound,0};}
    s::StreamStatus start(std::uint8_t,s::StreamRequest,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus stop(std::uint8_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus pause(std::uint8_t,bool,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus attenuation(std::uint8_t,std::int32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus service(std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamValue actor_archive_marker(std::uint8_t slot)noexcept override{events.push_back({3,slot,7,0,{}});return{s::StreamStatus::completed,0};}
};
}
#ifdef REO_DIALOGUE_RECORDS_ORIGINAL
#include "dialogue_records_reference.inc"
#else
void export_original(const w::DialogueRecord&,const w::DialogueContext&,unsigned,bool){}
void compare_original(const w::DialogueRecord&,const w::DialogueContext&){}
#endif
int main()try{
    w::World world(profile(),std::make_shared<w::Session>());for(unsigned i=0;i<2;++i){auto actor=std::make_unique<w::Actor>();actor->slot=std::uint8_t(i);actor->speech.gauge_notice=0;actor->speech.display_style=0;check(world.spawn_primary(i,std::move(actor)).status==w::actors::EntityStatus::completed);}
    const std::array<std::vector<std::uint8_t>,5> bodies{{{'G','o','.',13,10},{'a','b','c','d','e','f','g','h','i','j',13,10,'S','e','c','o','n','d','.',13,10},{0x82,0xa0,0x82,0xa1,0x82,0xa2,0x82,0xa3,13,10},{'A',0x82,0xa0,'B',0x82,0xa1,13,10},{0x81,0x69,'L','i','t','e','r','a','l',13,10}}};
    std::array<std::shared_ptr<const s::DialogueTexts>,5> texts;for(unsigned i=0;i<texts.size();++i)texts[i]=text(bodies[i]);
    Backend backend;s::StreamChannels channels(s::file1_stream_gain_curve());reo::native::gameplay_audio::SpatialContext spatial;std::optional<std::uint32_t> tick=5;w::ActorVoiceRequests voice(world,channels,backend,spatial,tick);Display display(world);w::DialogueContext context{world,&voice,&display,{},{},{}};
    for(unsigned seed=0;seed<4096;++seed){w::DialogueRecord record;record.active=true;record.actor=world.identity(seed%2);record.phase=std::int16_t(seed%6);record.delay=std::int16_t(seed%35-2);record.initial_delay=std::int16_t(seed%5);record.fade_ticks=std::bit_cast<std::int8_t>(std::uint8_t(seed%10-1));record.character_ticks=std::int8_t(seed%3);record.channel=std::int8_t(seed%2);record.alpha=std::uint8_t((seed%9)*16);record.line_bytes=3;record.revealed=std::int16_t(seed%4);record.text_owner=texts[seed%5];record.prefix={std::byte{'<'},std::byte{'c'},std::byte{'7'},std::byte{'>'}};record.voice=seed%7?-1:7;record.center=305;record.sequence=std::uint16_t(seed);record.newlines=1;record.display_style=std::int8_t(seed%17);record.literal=seed%5==4?1:0;record.buffer[0]=std::byte{'X'};record.buffer[1]=std::byte{'Y'};record.corruption_count=3;record.glyphs=3;record.reveal_index=0;record.corrupted[1]=1;
        if(seed%5==2){record.revealed=std::int16_t(2*(seed%3));record.line_bytes=8;}
        if(seed%5==3){record.revealed=0;record.line_bytes=6;}
        if(seed%5==4){record.revealed=0;record.line_bytes=9;}
        world.session().random.restore({std::uint16_t(seed*37+1),std::uint16_t(seed*11+1),std::uint8_t(seed)});world.primary(0)->speech.gauge_notice=seed&1;world.primary(1)->speech.gauge_notice=seed&1;
        world.primary(0)->speech.display_style=2;world.primary(1)->speech.display_style=3;world.primary(1)->collision.basis.x.z=std::bit_cast<float>(seed&2?0x3f80ffffu:0x3f800001u);
        context.previous_secondary_actor=seed&4?std::optional(world.identity(1)):std::nullopt;context.selected_counts={std::int16_t(seed%4),std::int16_t((seed/3)%4)};context.second_selected_active={bool(seed&8),bool(seed&16)};display.hidden=bool(seed&32);events.clear();
        export_original(record,context,seed%2,display.hidden);const auto result=w::advance_dialogue_record(record,std::uint8_t(seed%2),context);check(result.status==w::DialogueStatus::completed);compare_original(record,context);++frames;
    }
    for(unsigned channel=0;channel<2;++channel){w::DialogueRecord continuation;continuation.active=true;continuation.actor=world.identity(channel);continuation.text_owner=texts[1];continuation.initial_delay=2;continuation.voice=-1;continuation.display_style=4;continuation.prefix={std::byte{'<'},std::byte{'c'},std::byte{'7'},std::byte{'>'}};
        context.previous_secondary_actor.reset();context.selected_counts={1,1};context.second_selected_active={false,false};display.hidden=false;world.primary(channel)->speech.gauge_notice=0;
        const auto retained=continuation.text_owner;for(unsigned frame=0;frame<160&&continuation.active;++frame){events.clear();export_original(continuation,context,channel,false);check(w::advance_dialogue_record(continuation,std::uint8_t(channel),context).status==w::DialogueStatus::completed);compare_original(continuation,context);++continuation_frames;}
        check(!continuation.active&&world.primary(channel)->speech.display_style==0&&retained->text(0)->body.size()==bodies[1].size());++lifetimes;
    }
    w::DialogueRecord record;record.active=true;record.actor=world.identity(0);record.phase=1;record.text_owner=texts[0];record.voice=-1;record.prefix={std::byte{'<'},std::byte{'c'},std::byte{'7'},std::byte{'>'}};
    world.primary(0)->speech.gauge_notice.reset();const auto refusal=w::advance_dialogue_record(record,0,context);check(refusal.status==w::DialogueStatus::unavailable&&refusal.stage==w::DialogueStage::corruption&&record.phase==2&&record.line_bytes==3);++refusals;
    std::cout<<"{\"checks\":"<<checks<<",\"native_frames\":"<<frames<<",\"continuation_frames\":"<<continuation_frames<<",\"complete_original_frames\":"<<source_cases<<",\"source_calls\":"<<source_calls<<",\"prefix_refusals\":"<<refusals<<",\"retained_text_lifetimes\":"<<lifetimes<<",\"game_run\":false,\"audio_device_opened\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
