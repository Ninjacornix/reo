#include "game/native/gameplay_scenario/scenario_enemy_relocation.hpp"
#include "game/native/gameplay_world/actor_initial_state.hpp"
#include "original_fixture.hpp"
#include "original_declarations.inc"
#include <iostream>
#include <source_location>
#include <vector>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;
namespace {
unsigned checks{},calls{},dispatches{},refusals{},authored{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Enemy relocation check at "+std::to_string(at.line()));
}
template<class T>void put(std::span<std::byte> bytes,unsigned at,T value){std::memcpy(bytes.data()+at,&value,sizeof value);}
using Bytes=std::vector<std::uint8_t>;
std::shared_ptr<const s::Program> program(std::uint32_t condition,bool offline=false,bool prefix=false){
    std::vector<std::byte> bytes(prefix?32:16);put(std::span(bytes),0,1u);unsigned at=4;
    if(prefix){put(std::span(bytes),at,0x02000110u);put(std::span(bytes),at+4,0u);put(std::span(bytes),at+8,77u);at+=16;}
    put(std::span(bytes),at,0x01000169u);put(std::span(bytes),at+4,condition);put(std::span(bytes),at+8,0xau);
    return std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{bytes},offline?s::DispatchProfile::offline_actor:s::DispatchProfile::ordinary);
}
struct Fixture {
    std::shared_ptr<w::Session> session=std::make_shared<w::Session>();
    w::World world{{{w::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session};s::FlagState flags;
    Bytes memory=Bytes(0x900000);
    Fixture(){session->scenario=28;session->primary_population=3;
        for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();w::initialize_cleared_actor_defaults(*actor);
            actor->active=true;actor->room=7;actor->status=i?0x20u:0u;actor->character=0;
            check(world.spawn_primary(i,std::move(actor)).status==reo::native::gameplay_actors::EntityStatus::completed);}
        session->enemy_routes.classes={27,27};session->enemy_routes.room_banks[0][7]=1;session->enemy_routes.room_banks[1][7]=2;
        std::memset(memory.data()+0x4a5c30,0xa5,8*0x10e0);std::memset(memory.data()+0x74f250,0x63,256*96);
    }
    void enemies(unsigned count){
        std::vector<std::byte> bytes(4+96*count+3);put(std::span(bytes),0,4u);
        for(unsigned i=0;i<count;++i){const auto at=4+96*i;bytes[at+2]=std::byte{27};bytes[at+0x1c]=std::byte{7};bytes[at+0x20]=std::byte{9};
            bytes[at+0x22]=std::byte{16};bytes[at+0x33]=std::byte{255};bytes[at+0x49]=std::byte{1};}
        bytes[4+96*count+2]=std::byte{255};const auto imported=session->enemy_descriptors.import(bytes,*session,true,0);
        check(imported.status==s::EnemyImportStatus::completed&&imported.count==count&&session->enemy_descriptors.count()==std::uint8_t(count));
    }
    s::TickResult run(std::uint32_t condition,bool offline=false){
        s::Interpreter interpreter;check(interpreter.install(0,program(condition,offline))==s::Status::completed);
        s::Providers providers;providers.world=&world;providers.flags=providers.canonical_flags=&flags;++dispatches;
        const s::TickContext context{true,false,world.selected_actor};
        return offline?interpreter.tick_offline_channel(0,context,{0,0,0},providers):interpreter.tick(0,context,providers);
    }
    void state(Bytes& bytes)const{
        for(unsigned i=0;i<8;++i){const auto actor=world.primary(i);const auto at=0x4a5c30+i*0x10e0;
            bytes[at]=actor->active?0x80:0;bytes[at+2]=actor->category;bytes[at+3]=actor->slot;
            transform_write(bytes.data(),at+0x1e2,actor->room);transform_write(bytes.data(),at+0xba0,actor->status);bytes[at+0xb98]=actor->character;bytes[at+0xff0]=actor->ai_control;}
        for(unsigned i=0;i<256;++i){const auto& descriptor=session->enemy_descriptors.records()[i];const auto at=0x74f250+96*i;
            bytes[at+2]=descriptor.family;bytes[at+4]=descriptor.condition;bytes[at+0x22]=descriptor.room;bytes[at+0x2a]=descriptor.parameter20;}
        bytes[0x4bae8e]=session->enemy_descriptors.count();transform_write(bytes.data(),0x4baea0,*session->primary_population);
        transform_write(bytes.data(),0x3243da,*session->scenario);bytes[0x4baded]=world.selected_actor;
        std::memcpy(bytes.data()+0x4baa30,flags.snapshot().scene_record_eligibility.snapshot().data(),32);
        for(unsigned group=0;group<2;++group){transform_write(bytes.data(),0x4ba820+2*group,session->enemy_routes.classes[group]);
            std::memcpy(bytes.data()+0x4ba620+256*group,session->enemy_routes.room_banks[group].data(),256);}
    }
    void compare(std::uint32_t condition,bool offline=false){
        state(memory);auto expected=memory;transform_write(memory.data(),0x10000,condition);
        const auto random=session->random.state();R5900Context context;PS2Runtime runtime;
        context.pc=0x6946b0;SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,29,0x8f0000);SET_GPR_U32(&context,31,0x100);
        o2_006946B0_0x6946b0(memory.data(),&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,2)==0);++calls;
        const auto result=run(condition,offline);if(result.status!=s::Status::yielded)throw std::runtime_error("169 dispatch refused "+std::to_string(int(result.status)));
        state(expected);check(session->random.state()==random);
        for(unsigned i=0;i<8;++i)check(std::equal(expected.begin()+0x4a5c30+i*0x10e0,expected.begin()+0x4a5c30+(i+1)*0x10e0,memory.begin()+0x4a5c30+i*0x10e0));
        check(std::equal(expected.begin()+0x74f250,expected.begin()+0x74f250+256*96,memory.begin()+0x74f250));
        check(std::equal(expected.begin()+0x4baa10,expected.begin()+0x4baa50,memory.begin()+0x4baa10));
        check(std::equal(expected.begin()+0x4ba620,expected.begin()+0x4ba824,memory.begin()+0x4ba620));
        check(std::equal(expected.begin()+0x4baea0,expected.begin()+0x4baea4,memory.begin()+0x4baea0));
    }
};
void matrix(){
    constexpr std::uint32_t conditions[]{0,15,16,17,23,255,256,0x12345610u,0xffffffffu};
    constexpr std::uint32_t populations[]{0,1,2,3,8,128,255,256,257,0x12340003u,0xffffffffu};
    constexpr unsigned counts[]{0,1,2,3,4,7,16,128,255,256};
    for(bool offline:{false,true})for(const auto condition:conditions)for(unsigned trial=0;trial<48;++trial){
        Fixture fixture;fixture.enemies(counts[trial%std::size(counts)]);fixture.world.selected_actor=std::uint8_t(trial%8);
        fixture.session->scenario=trial%8==0?35:28;fixture.session->primary_population=populations[trial%std::size(populations)];
        auto& routes=fixture.session->enemy_routes;routes.classes={std::uint16_t(trial%4==1?0:27),std::uint16_t(trial%4==2?0:27)};
        for(unsigned room=0;room<128;++room){routes.room_banks[0][room]=std::uint16_t((room+trial)%3==0);routes.room_banks[1][room]=std::uint16_t((room+trial)%2==0);}
        for(unsigned i=0;i<8;++i){const auto actor=fixture.world.primary(i);actor->active=(i+trial)%4!=0;
            actor->status=std::array<std::uint32_t,5>{0,0x20,0x100,0x4000,0x5e0}[(i+trial)%5];
            actor->room=std::array<std::uint16_t,4>{0,7,8,35}[(i+trial)%4];actor->character=std::uint8_t(condition-16u);actor->ai_control=std::uint8_t(i+trial);}
        for(unsigned i=0;i<fixture.session->enemy_descriptors.count();++i){auto* descriptor=fixture.session->enemy_descriptors.record(i);
            descriptor->family=std::uint8_t(i%5?27:26);descriptor->condition=std::uint8_t(condition+i);descriptor->room=std::uint8_t(i%5?(trial+i)%36:127);}
        for(unsigned id=0;id<256;++id)check(fixture.flags.write(s::FlagBank::scene_record_eligibility,id,(id+trial)%3==0));
        fixture.compare(condition,offline);
    }
}
void wrap_and_precedence(){
    for(const auto count:{0u,1u,2u,3u,126u,127u,128u,129u,254u}){
        Fixture fixture;fixture.enemies(count+1);auto& descriptors=fixture.session->enemy_descriptors;
        descriptors.record(0)->room=2;for(unsigned i=1;i<=count;++i)descriptors.record(i)->condition=17;
        check(fixture.flags.write(s::FlagBank::scene_record_eligibility,17,true));fixture.compare(0x12340010u);
        const auto allowed=std::bit_cast<std::int8_t>(std::uint8_t(count))<2;
        check(descriptors.records()[0].room==(allowed?7:2));check(descriptors.records()[0].parameter20==(allowed?5:9));
        check((fixture.world.primary(1)->status&0x1000u)==(allowed?0x1000u:0));check(!(fixture.world.primary(2)->status&0x1000u));
    }
    {Fixture fixture;fixture.enemies(1);fixture.session->enemy_routes.room_banks[0][7]=0;
        fixture.compare(16);check(fixture.session->enemy_descriptors.records()[0].parameter20==9);}
    {Fixture fixture;fixture.enemies(1);fixture.session->enemy_routes.classes[0]=0;
        fixture.compare(16);check(fixture.session->enemy_descriptors.records()[0].parameter20==5);}
    {Fixture fixture;fixture.enemies(1);fixture.world.primary(0)->room=0;fixture.world.primary(1)->status=0;
        fixture.session->enemy_routes.room_banks[0][0]=1;fixture.compare(16);check(fixture.session->enemy_descriptors.records()[0].parameter20==9);}
    {Fixture fixture;fixture.enemies(1);fixture.world.primary(0)->active=false;fixture.world.primary(1)->status=0;
        fixture.compare(16);check(fixture.session->enemy_descriptors.records()[0].parameter20==5);}
    {Fixture fixture;fixture.enemies(0);fixture.compare(16);check(fixture.world.primary(1)->status==0x1020);}
}
void boundaries(){
    Fixture fixture;fixture.enemies(1);s::Interpreter interpreter;s::Providers providers;providers.world=&fixture.world;
    const auto attempt=[&](){check(interpreter.install(0,program(16,false,true))==s::Status::completed);return interpreter.tick(0,{},providers);};
    check(attempt().status==s::Status::provider_unavailable&&interpreter.counters()[0]==0);++refusals;
    fixture.session->scenario=35;fixture.session->primary_population.reset();check(attempt().status==s::Status::yielded&&interpreter.counters()[0]==77);
    fixture.session->scenario.reset();check(attempt().status==s::Status::provider_unavailable);++refusals;
    fixture.session->scenario=28;check(attempt().status==s::Status::provider_unavailable);++refusals;
    fixture.session->primary_population=0x80;check(attempt().status==s::Status::yielded);fixture.session->primary_population=9;
    check(attempt().status==s::Status::provider_unavailable);++refusals;
    fixture.session->primary_population=3;fixture.world.primary(0)->room=128;
    check(attempt().status==s::Status::provider_unavailable);++refusals;
    fixture.world.primary(0)->room=36;fixture.session->enemy_routes.room_banks[0][36]=1;check(attempt().status==s::Status::provider_unavailable);++refusals;
    fixture.world.primary(0)->room=7;s::FlagState foreign;providers.flags=&foreign;providers.canonical_flags=&fixture.flags;
    check(attempt().status==s::Status::provider_unavailable);++refusals;
    providers.flags=&fixture.flags;check(attempt().status==s::Status::yielded);
    check(fixture.world.retire_primary(2)==reo::native::gameplay_actors::EntityStatus::completed);check(attempt().status==s::Status::provider_unavailable);++refusals;
    check(fixture.world.close()==w::Status::completed);check(attempt().status==s::Status::provider_unavailable);++refusals;
    bool rejected{};try{std::vector<std::byte> bytes(4);put(std::span(bytes),0,0x169u);const s::Program truncated({bytes});}catch(const std::invalid_argument&){rejected=true;}check(rejected);++refusals;
}
void authored_records(){
    constexpr unsigned conditions[]{
#include "authored_commands.inc"
    };
    for(const auto condition:conditions){Fixture fixture;fixture.enemies(3);auto& descriptors=fixture.session->enemy_descriptors;
        descriptors.record(0)->condition=std::uint8_t(condition);descriptors.record(0)->room=2;
        descriptors.record(1)->condition=std::uint8_t(condition+1);descriptors.record(2)->condition=std::uint8_t(condition);
        check(fixture.flags.write(s::FlagBank::scene_record_eligibility,std::uint8_t(condition+1),true));
        fixture.world.primary(1)->character=fixture.world.primary(2)->character=std::uint8_t(condition-16);
        fixture.compare(condition);check(descriptors.records()[0].room==7&&descriptors.records()[0].parameter20==5);
        check(descriptors.records()[2].parameter20==9&&fixture.world.primary(1)->status==0x1020&&fixture.world.primary(2)->status==0x20);++authored;
    }
}
}
void original_transform_port(std::uint8_t* m,R5900Context* c,PS2Runtime* r){
    switch(c->pc){
#include "original_lookup.inc"
    case 0x107c68:std::memset(m+GPR_U32(c,4),int(GPR_U32(c,5)),GPR_U32(c,6));SET_GPR_U32(c,2,GPR_U32(c,4));c->pc=GPR_U32(c,31);return;
    default:throw std::runtime_error("Unexpected relocation original boundary "+std::to_string(c->pc));
    }
}
int main()try{
    matrix();wrap_and_precedence();boundaries();authored_records();
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<calls<<",\"dispatches\":"<<dispatches<<",\"refusals\":"<<refusals<<",\"authored_records\":"<<authored<<"}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
