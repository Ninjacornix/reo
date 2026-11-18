#include "game/native/gameplay_world/packed_actor_audio.hpp"
#include "reference.hpp"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
namespace g=reo::native::gameplay_world;namespace a=reo::native::gameplay_audio;namespace b=reo::native::audio_banks::v2;
unsigned checks{},cases{},calls{},requests{},signal_samples{},mixed_frames{},refusals{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Packed actor audio "+std::to_string(at.line()));}
template<class T>T get(const std::uint8_t* m,unsigned at){return transform_read<T>(m,at);}
template<class T>void put(std::uint8_t* m,unsigned at,T v){transform_write(m,at,v);}
template<class T>void put(std::vector<std::uint8_t>& m,unsigned at,T v){put(m.data(),at,v);}
a::Owner* reference_audio{};reo::native::gameplay_session::Random* reference_random{};const a::SpatialContext* spatial{};std::optional<a::Result> reference_result;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
    if(context->pc==0x1b93d0){
        check(reference_audio&&reference_random&&spatial&&GPR_U32(context,8)==1&&GPR_U32(context,9)==0);
        reference_random->restore({get<std::uint16_t>(memory,0x3244b0),get<std::uint16_t>(memory,0x3244b8),memory[0x2b8de8]});
        reference_result=reference_audio->positional({GPR_U32(context,4),GPR_U32(context,5),UINT32_MAX,UINT32_MAX,std::uint8_t(GPR_U32(context,10))},get<a::Vector>(memory,GPR_U32(context,7)),*spatial,1);
        put(memory,0x3244b0,reference_random->state().primary);put(memory,0x3244b8,reference_random->state().secondary);memory[0x2b8de8]=reference_random->state().observed;++requests;context->pc=GPR_U32(context,31);return;
    }
    switch(context->pc){
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted packed sound helper "+std::to_string(context->pc));
    }
}
struct Gains final:b::GainProvider {float gain(unsigned,unsigned,std::uint64_t)noexcept override{return 1;}};
struct Offsets final:g::ActorSoundOffsets {
    g::World& world;bool missing{};std::uint8_t value{};
    explicit Offsets(g::World& w):world(w){}
    bool bound_to(const g::World& w)const noexcept override{return &w==&world;}
    std::optional<std::uint8_t> find(const g::actors::EntityId&)override{return missing?std::nullopt:std::optional(value);}
};
int main(int argc,char** argv)try{
    check(argc==2);std::ifstream input(argv[1],std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(input),{}};check(!raw.empty());const std::span<const std::uint8_t> asset{reinterpret_cast<const std::uint8_t*>(raw.data()),raw.size()};
    auto session=std::make_shared<g::Session>();g::Profile profile;profile.layouts.push_back({});profile.entities.capacity=16;g::World world(profile,session);
    const auto source=world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto parent=world.spawn_primary(1,std::make_unique<g::Actor>()).id;check(source&&parent);const auto source_actor=world.resolve(source),parent_actor=world.resolve(parent);
    auto engine=std::make_shared<b::Session>(),reference_engine=std::make_shared<b::Session>();a::Owner audio(engine,session->random);reo::native::gameplay_session::Random original_random;a::Owner original_audio(reference_engine,original_random);a::SpatialContext context;context.world_to_screen=reo::native::transform_math::identity();spatial=&context;reference_audio=&original_audio;reference_random=&original_random;Offsets offsets(world);g::PackedActorAudio frontend(world,audio,context,&offsets);
    for(unsigned bank=4;bank<=12;++bank){check(audio.install(audio.begin_bank(bank),asset).status==a::Status::completed);check(original_audio.install(original_audio.begin_bank(bank),asset).status==a::Status::completed);}
    std::vector<std::uint8_t> memory(0x2000000);Gains gains;
    for(unsigned category:{0u,1u,2u,3u,9u})for(unsigned related=0;related<(category==9?5u:1u);++related)for(unsigned slot=0;slot<4;++slot)for(unsigned packed=0;packed<512;++packed){
        const auto event=packed|(packed&256?0xabcd0000u:0u);source_actor->category=std::uint8_t(category);source_actor->slot=std::uint8_t(slot);source_actor->position={float(slot*7),float(int(packed%7)-3),float(packed%11)};parent_actor->category=std::uint8_t(related?related-1:0);parent_actor->slot=std::uint8_t(slot);parent_actor->position={float(int(packed%13)-6),2,float(slot*3)};source_actor->contact.related=related?parent:g::actors::EntityId{};offsets.value=std::uint8_t(packed%3);offsets.missing=false;
        memory[0x20002]=source_actor->category;memory[0x20003]=source_actor->slot;put(memory,0x20038,source_actor->position);put(memory,0x20028,related?0x22000u:0u);memory[0x20033]=offsets.value;memory[0x20554]=23;
        memory[0x22002]=parent_actor->category;memory[0x22003]=parent_actor->slot;put(memory,0x22038,parent_actor->position);memory[0x22033]=offsets.value;memory[0x22554]=27;
        const auto seed=reo::native::gameplay_session::RandomState{std::uint16_t(packed*257+category),std::uint16_t(related*997+slot),std::uint8_t(packed)};session->random.restore(seed);put(memory,0x3244b0,seed.primary);put(memory,0x3244b8,seed.secondary);memory[0x2b8de8]=seed.observed;
        const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok&&reference_engine->apply({&stop,1}).status==b::Status::ok);reference_result.reset();
        R5900Context original;PS2Runtime runtime;original.pc=0x1ba5e0;SET_GPR_U32(&original,4,0x20000);SET_GPR_U32(&original,5,event);SET_GPR_U32(&original,29,0x1f00000);SET_GPR_U32(&original,31,0x1234);original_transform_port(memory.data(),&original,&runtime);check(original.pc==0x1234&&GPR_U32(&original,29)==0x1f00000);
        check(frontend.sound(source,event));check(bool(frontend.last_result())==bool(reference_result));if(reference_result)check(frontend.last_result()->status==reference_result->status&&frontend.last_result()->commands==reference_result->commands&&frontend.last_result()->source_return==reference_result->source_return);
        check(session->random.state()==reo::native::gameplay_session::RandomState{get<std::uint16_t>(memory.data(),0x3244b0),get<std::uint16_t>(memory.data(),0x3244b8),memory[0x2b8de8]});
        std::array<float,128> actual{},expected{};check(engine->mix_add(actual.data(),64,gains)==b::Status::ok&&reference_engine->mix_add(expected.data(),64,gains)==b::Status::ok&&actual==expected);for(float value:actual)if(value!=0)++signal_samples;mixed_frames+=64;++cases;
    }
    check(signal_samples>0);check(frontend.sound({},7)&&!frontend.last_result());source_actor->category=2;offsets.missing=true;check(!frontend.sound(source,7)&&!frontend.last_result());check(frontend.sound(source,0));source_actor->category=5;check(!frontend.sound(source,7));check(frontend.sound(source,0));source_actor->category=9;source_actor->contact.related=parent;check(world.retire_primary(1)==g::actors::EntityStatus::completed&&!frontend.sound(source,7));refusals=3;
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"requests\":"<<requests<<",\"mixed_frames\":"<<mixed_frames<<",\"signal_samples\":"<<signal_samples<<",\"refusals\":"<<refusals<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
