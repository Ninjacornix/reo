#include "game/native/gameplay_scenario/interpreter.hpp"
#include "game/native/gameplay_scenario/scene_resources.hpp"
#include "game/native/gameplay_scenario/session_counters.hpp"
#include "game/native/gameplay_scenario/sequence_control.hpp"
#include "game/native/gameplay_scenario/lighting.hpp"
#include "game/native/gameplay_scenario/scene_channels.hpp"
#include "game/native/gameplay_scenario/scene_controls.hpp"
#include "game/native/gameplay_scenario/stream_channels.hpp"
#include "game/native/gameplay_scenario/saved_controls.hpp"
#include "game/native/gameplay_scenario/action_choices.hpp"
#include "game/native/gameplay_world/world.hpp"
#include "game/native/gameplay_scenario/scene_models.hpp"
#include <bit>
#include "original_fixture.hpp"
#include "original_declarations.inc"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <source_location>
namespace vm=reo::native::gameplay_scenario;
namespace tasks=reo::native::gameplay_tasks;
namespace {
std::size_t checks{},invocations{};
std::string assertion_context;
std::vector<std::tuple<std::uint32_t,std::uint8_t,std::uint8_t>> notifications;
void check(bool ok,const std::source_location at=std::source_location::current()){++checks;if(!ok)throw std::runtime_error("Scenario differential assertion "+std::to_string(checks)+" "+assertion_context+" "+at.file_name()+":"+std::to_string(at.line()));}
void put(std::vector<std::byte>& bytes,std::uint32_t value){for(unsigned i=0;i<4;++i)bytes.push_back(std::byte((value>>(8*i))&255));}
std::uint32_t emit(std::vector<std::byte>& bytes,std::uint32_t opcode,std::initializer_list<std::uint32_t> payload={},unsigned minimum_exponent=0){
    unsigned exponent=minimum_exponent;while((4u<<exponent)<4+payload.size()*4)++exponent;
    const auto begin=static_cast<std::uint32_t>(bytes.size());put(bytes,(exponent<<24)|opcode);for(auto v:payload)put(bytes,v);
    bytes.resize(begin+(4u<<exponent));return begin;
}
constexpr std::uint32_t addresses[]={0x4b9c00,0x4b9a80,0x4b9b40,0x4b9c40,0x4b9c80,0x4bac50};
std::vector<std::tuple<std::uint32_t,std::uint32_t,bool,std::uint8_t>> strided_notifications;
std::vector<std::tuple<std::uint32_t,std::uint8_t,std::uint32_t>> messages;
std::vector<std::uint32_t> queries;
std::int32_t predicate_value{};
struct Flags final:vm::Flags {
    std::array<std::array<std::uint32_t,4>,6> banks{};
    std::vector<std::tuple<std::uint32_t,std::uint8_t,std::uint8_t>> notices;
    std::array<std::array<std::uint16_t,6>,4> strided_flags{};
    std::vector<std::tuple<std::uint32_t,std::uint32_t,bool,std::uint8_t>> strided_notices;
    std::optional<bool> get(vm::FlagBank bank,std::uint32_t id)const noexcept override{
        if(id>=128)return{};
        return bool(banks[static_cast<unsigned>(bank)][id/32]&(1u<<(id&31)));
    }
    bool write(vm::FlagBank bank,std::uint32_t id,bool enabled)noexcept override{
        if(id>=128)return false;
        auto& word=banks[static_cast<unsigned>(bank)][id/32];const auto mask=1u<<(id&31);
        if(enabled)word|=mask;else word&=~mask;return true;
    }
    bool scenario(std::uint32_t id,std::uint8_t raw,vm::NotifyOwner,std::uint8_t actor_owner)noexcept override{
        if(!write(vm::FlagBank::scenario,id,raw!=0))return false;
        notices.emplace_back(id,raw,actor_owner);return true;
    }
    bool strided(std::uint32_t record,std::uint32_t bit,std::uint8_t slot,bool set,bool notify)noexcept override{
        if(record>=4||slot>=6)return false;
        auto& flags=strided_flags[record][slot];const auto mask=std::uint16_t(1u<<(bit&31));
        flags=set?std::uint16_t(flags|mask):std::uint16_t(flags&~mask);
        if(notify)strided_notices.emplace_back(record,bit,set,slot);
        return true;
    }
    std::optional<bool> test_strided(std::uint32_t record,std::uint32_t bit,std::uint8_t slot)const noexcept override{
        if(record>=4||slot>=6)return{};
        return bool(strided_flags[record][slot]&std::uint16_t(1u<<(bit&31)));
    }
};
struct Signals final:vm::Signals {
    std::vector<std::tuple<std::uint32_t,std::uint8_t,std::uint32_t>> sent;
    std::vector<std::uint32_t> asked;
    bool send(const vm::SignalMessage& m)noexcept override{sent.emplace_back(m.id,m.value,m.parameter);return true;}
    std::optional<std::int32_t> query(std::uint32_t id)noexcept override{asked.push_back(id);return predicate_value;}
};
void done(R5900Context* c){c->pc=GPR_U32(c,31);}
void flag(std::uint8_t* ram,std::uint32_t id,bool value){auto bits=fixture_read<std::uint32_t>(ram,addresses[0]+(id/32)*4);if(value)bits|=1u<<(id&31);else bits&=~(1u<<(id&31));fixture_write(ram,addresses[0]+(id/32)*4,bits);}
void fixture_scenario(std::uint8_t* ram,R5900Context* c,bool selected){
    const auto id=GPR_U32(c,4);const auto value=std::uint8_t(GPR_U32(c,5));flag(ram,id,value!=0);
    notifications.emplace_back(id,value,selected?std::uint8_t(ram[0x4baded]+1):0);SET_GPR_U32(c,2,0);done(c);
}
void compare(vm::Interpreter& native,std::vector<std::uint8_t>& ram,std::size_t channel,const Flags& flags,const tasks::FlagTimers& timers,const Signals& signals){
    const auto& c=native.channels()[channel];const auto original_position=[&](vm::Position p){return p.block==UINT32_MAX?0u:0x10000u+p.block*0x10000u+p.offset;};
    check(fixture_read<std::uint32_t>(ram.data(),0x4bace0+4*channel)==original_position(c.current));
    check(fixture_read<std::uint32_t>(ram.data(),0x4bacf8+4*channel)==c.countdown);
    check(fixture_read<std::uint32_t>(ram.data(),0x4bad10+4*channel)==c.block_index);
    check(fixture_read<std::uint32_t>(ram.data(),0x4bad28+4*channel)==original_position(c.saved));
    check(fixture_read<std::uint32_t>(ram.data(),0x4bad58+4*channel)==c.condition);
    check(ram[0x4badc1]==native.selected_channel());
    for(std::size_t bank=0;bank<6;++bank)for(std::size_t i=0;i<4;++i)check(fixture_read<std::uint32_t>(ram.data(),addresses[bank]+4*i)==flags.banks[bank][i]);
    check(notifications==flags.notices);
    check(strided_notifications==flags.strided_notices);check(messages==signals.sent);check(queries==signals.asked);
    for(std::size_t i=0;i<4;++i){check(native.counters()[i]==fixture_read<std::uint32_t>(ram.data(),0x4bada8+4*i));
        for(std::size_t slot=0;slot<6;++slot)check(flags.strided_flags[i][slot]==fixture_read<std::uint16_t>(ram.data(),0x4b9e20+12*i+2*slot));
    }
    for(std::size_t actor=0;actor<4;++actor)for(std::size_t slot=0;slot<4;++slot){const auto& e=native.actor_events()[actor][slot];
        check(ram[0x4bac94+16*actor+slot]==e.active);check(ram[0x4bac98+16*actor+slot]==e.kind);
        check(fixture_read<std::uint16_t>(ram.data(),0x4bac9c+16*actor+2*slot)==e.value);
    }
    for(std::size_t i=0;i<8;++i){const auto& t=timers.snapshot()[i];check(fixture_read<std::int16_t>(ram.data(),0x4bad88+2*i)==t.remaining);
        const auto expected=std::uint16_t(t.target.id|(t.target.scope==tasks::FlagScope::session_owner_zero?0x8000:0));
        check(fixture_read<std::uint16_t>(ram.data(),0x4bad98+2*i)==expected);
    }
}
#include "scene_vm_fixture.inc"
#include "sequence_vm_fixture.inc"
#include "lighting_vm_fixture.inc"
#include "control_vm_fixture.inc"
#include "stream_vm_fixture.inc"
#include "actor_vm_fixture.inc"
#include "model_vm_fixture.inc"
void run(std::vector<std::vector<std::byte>> blocks,vm::Position saved,unsigned ticks,std::size_t channel=0,std::uint8_t actor=0,bool condition=false,unsigned scene_profile=0,unsigned sequence_profile=0,unsigned control_profile=0,unsigned stream_profile=0,std::uint32_t stream_tick=1234,unsigned actor_profile=0,unsigned model_profile=0){
    assertion_context="run first="+std::to_string(fixture_read<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(blocks[0].data()),0)&0xffffff)+" channel="+std::to_string(channel)+" actor="+std::to_string(actor)+" control="+std::to_string(control_profile)+" actorprofile="+std::to_string(actor_profile);
    std::vector<std::uint8_t> ram(0x800000);for(std::size_t i=0;i<blocks.size();++i){std::memcpy(ram.data()+0x10000+i*0x10000,blocks[i].data(),blocks[i].size());fixture_write<std::uint32_t>(ram.data(),0x90000+4*i,0x10000+std::uint32_t(i)*0x10000);}
    std::memcpy(ram.data()+0x717830,original_opcode_table.data(),original_opcode_table.size()*4);
    std::memcpy(ram.data()+0x717600,original_opener_table.data(),original_opener_table.size()*4);
    std::memcpy(ram.data()+0x7408d0,original_counter_comparisons.data(),original_counter_comparisons.size()*4);
    std::memcpy(ram.data()+0x740890,original_signed_comparisons.data(),original_signed_comparisons.size()*4);
    SceneFixture scene(scene_profile);scene.export_original(ram);fixture_write<std::uint16_t>(ram.data(),0x3243dc,9);
    SequenceFixture sequence(sequence_profile);sequence.export_original(ram);
    LightingFixture lighting;lighting.export_original(ram);
    vm::SceneChannels scene_channels;scene_channels.restore(0xa5a58000u);fixture_write(ram.data(),0x4b9d0c,scene_channels.mask());
    ControlFixture controls(control_profile);controls.export_original(ram);
    StreamFixture streams(stream_profile,stream_tick);streams.export_original(ram);
    ActorFixture actors(actor_profile,actor);actors.export_original(ram);
    ModelFixture models(model_profile);models.export_original(ram);
    ram[0x3243e8]=1;ram[0x4baded]=actor;fixture_write<std::uint32_t>(ram.data(),0x4bace0+4*channel,0x10000);
    fixture_write<std::uint32_t>(ram.data(),0x4bad28+4*channel,0x10000+saved.block*0x10000+saved.offset);
    fixture_write<std::uint32_t>(ram.data(),0x4bad40+4*channel,0x90000);
    Flags flags;flags.notices.reserve(100);flags.strided_notices.reserve(100);if(condition){flags.banks[0][0]=1;fixture_write<std::uint32_t>(ram.data(),0x4b9c00,1);}
    flags.strided_flags[2][2]=0x8001;fixture_write<std::uint16_t>(ram.data(),0x4b9e20+24+4,0x8001);
    Signals signals;signals.sent.reserve(100);signals.asked.reserve(100);
    notifications.clear();notifications.reserve(100);strided_notifications.clear();strided_notifications.reserve(100);messages.clear();messages.reserve(100);queries.clear();queries.reserve(100);
    tasks::FlagTimers timers;vm::SessionCounters session_counters;vm::Interpreter native;
    auto program=std::make_shared<const vm::Program>(std::move(blocks));vm::Channel state{program,{0,0},saved,0,0,0};check(native.restore_channel(channel,state)==vm::Status::completed);
    for(unsigned i=0;i<ticks;++i){R5900Context ctx;PS2Runtime runtime;SET_GPR_U32(&ctx,4,channel);SET_GPR_U32(&ctx,29,0x7f0000);SET_GPR_U32(&ctx,31,0xdeadbeef);
        o2_0068C660_0x68c660(ram.data(),&ctx,&runtime);check(ctx.pc==0xdeadbeef);
        vm::Providers providers{&flags,&timers,&signals,nullptr,&scene.resources,&scene,&scene,&session_counters,&sequence.owner,&lighting.owner,&scene_channels,&controls.owner,&controls,&streams.owner,&streams};providers.world=&actors.world;providers.action_choices=&actors.choices;providers.models=&models.owner;
        const auto result=native.tick(channel,{true,false,actor,9,stream_tick},providers);check(result.status==vm::Status::yielded);
        compare(native,ram,channel,flags,timers,signals);scene.compare_original(ram);++invocations;
        sequence.compare_original(ram);
        lighting.compare_original(ram);
        check(scene_channels.mask()==fixture_read<std::uint32_t>(ram.data(),0x4b9d0c));
        controls.compare_original(ram);
        streams.compare_original(ram);
        actors.compare_original(ram);
        models.compare_original(ram);
        check(std::memcmp(session_counters.snapshot().data(),ram.data()+0x4bad70,24)==0);
    }
}
}
void o2_005703E0_0x5703e0(std::uint8_t* r,R5900Context* c,PS2Runtime*){fixture_scenario(r,c,true);}
void o2_00570450_0x570450(std::uint8_t* r,R5900Context* c,PS2Runtime*){fixture_scenario(r,c,false);}
void o2_00570970_0x570970(std::uint8_t* r,R5900Context* c,PS2Runtime*){const auto id=GPR_U32(c,4);if(id<128)r[0x4b9c80+id/8]|=std::uint8_t(1u<<(id&7));SET_GPR_U32(c,2,0);done(c);}
void strided_fixture(std::uint8_t* r,R5900Context* c,bool set,bool notify){
    const auto record=GPR_U32(c,4),bit=GPR_U32(c,5);const auto slot=std::uint8_t(GPR_U32(c,6));
    const auto mask=std::uint16_t(1u<<(bit&31));auto flags=fixture_read<std::uint16_t>(r,0x4b9e20+12*record+2*slot);
    flags=set?std::uint16_t(flags|mask):std::uint16_t(flags&~mask);fixture_write(r,0x4b9e20+12*record+2*slot,flags);
    if(notify)strided_notifications.emplace_back(record,bit,set,slot);
    SET_GPR_U32(c,2,0);done(c);
}
void o2_00570670_0x570670(std::uint8_t* r,R5900Context* c,PS2Runtime*){strided_fixture(r,c,true,false);}
void o2_00570620_0x570620(std::uint8_t* r,R5900Context* c,PS2Runtime*){strided_fixture(r,c,false,false);}
void o2_005706B0_0x5706b0(std::uint8_t* r,R5900Context* c,PS2Runtime*){strided_fixture(r,c,true,true);}
void o2_00570700_0x570700(std::uint8_t* r,R5900Context* c,PS2Runtime*){strided_fixture(r,c,false,true);}
void o2_005709E0_0x5709e0(std::uint8_t* r,R5900Context* c,PS2Runtime*){const auto id=GPR_U32(c,4);if(id<16){auto f=fixture_read<std::uint16_t>(r,0x4bac50);fixture_write(r,0x4bac50,std::uint16_t(f|(1u<<id)));}SET_GPR_U32(c,2,0);done(c);}
void o2_00680220_0x680220(std::uint8_t*,R5900Context* c,PS2Runtime*){messages.emplace_back(GPR_U32(c,4),std::uint8_t(GPR_U32(c,5)),GPR_U32(c,6));SET_GPR_U32(c,2,0);done(c);}
void o2_00680850_0x680850(std::uint8_t*,R5900Context* c,PS2Runtime*){queries.push_back(GPR_U32(c,4));SET_GPR_S32(c,2,predicate_value);done(c);}
void o2_006B5E10_0x6b5e10(std::uint8_t*,R5900Context* c,PS2Runtime*){original_control_refreshes.push_back(std::uint8_t(GPR_U32(c,4)));done(c);}
void sub_00131E38_0x131e38(std::uint8_t* r,R5900Context* c,PS2Runtime*){stream_original_event(r,2,stream_original_channel(c));done(c);}
void sub_00131EF8_0x131ef8(std::uint8_t* r,R5900Context* c,PS2Runtime*){const auto index=stream_original_channel(c);stream_original_event(r,0,index);SET_GPR_S32(c,2,original_stream_fixture->phases[index]);done(c);}
void sub_001327B8_0x1327b8(std::uint8_t* r,R5900Context* c,PS2Runtime*){stream_original_event(r,4,stream_original_channel(c),GPR_S32(c,5));done(c);}
void sub_00132E50_0x132e50(std::uint8_t* r,R5900Context* c,PS2Runtime*){stream_original_event(r,3,stream_original_channel(c),GPR_S32(c,5));done(c);}
void sub_00133490_0x133490(std::uint8_t* r,R5900Context* c,PS2Runtime*){stream_original_event(r,1,stream_original_channel(c),GPR_S32(c,5),GPR_S32(c,6));done(c);}
void sub_001B82A0_0x1b82a0(std::uint8_t*,R5900Context* c,PS2Runtime*){SET_GPR_U32(c,2,0);done(c);}
void sub_0012BEF8_0x12bef8(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unexpected VM stream service");}
PS2Runtime::Function PS2Runtime::lookupFunction(std::uint32_t at)const{
    if(at==0x107ab0)return +[](std::uint8_t* r,R5900Context* c,PS2Runtime*){const auto d=GPR_U32(c,4),s=GPR_U32(c,5),n=GPR_U32(c,6);check(d<=0x800000&&n<=0x800000-d&&s<=0x800000&&n<=0x800000-s);std::memmove(r+d,r+s,n);done(c);};
    if(at==0x107c68)return +[](std::uint8_t* r,R5900Context* c,PS2Runtime*){const auto d=GPR_U32(c,4),n=GPR_U32(c,6);check(d<=0x800000&&n<=0x800000-d);std::memset(r+d,int(GPR_U32(c,5)&255),n);done(c);};
    switch(at){
#include "original_lookup.inc"
    default:throw std::runtime_error("Unqualified original VM dispatch "+std::to_string(at));
    }
}
#include "offline_tests.inc"
#include "room_rule_tests.inc"
#include "room_object_vm_tests.inc"
#include "actor_request_vm_tests.inc"
int main()try{
    {std::vector<std::byte> b;emit(b,1);const auto a=emit(b,0xa);run({b},{0,a},4);}
    for(unsigned delay:{0u,1u,2u,7u}){std::vector<std::byte> a,b;emit(a,4,{delay});emit(a,0xd);emit(b,0xa);run({a,b},{1,0},delay+3,delay%6);}
    {std::vector<std::byte> b;emit(b,3,{2});emit(b,0xe5);const auto end=emit(b,0xa);run({b},{0,end},2);}
    for(bool wanted:{false,true}){std::vector<std::byte> b;emit(b,8,{0,1});emit(b,0xb,{1,5,0xff});emit(b,0xe4);emit(b,0xb,{1,6,1});emit(b,0xe5);const auto end=emit(b,0xa);run({b},{0,end},3,2,1,wanted);}
    for(unsigned selector:{0u,1u,2u,3u})for(unsigned actor=0;actor<4;++actor){
        std::vector<std::byte> b;emit(b,0xb,{selector,3,0xff});emit(b,0xb,{selector,3,0});emit(b,0xc,{0,5,1});emit(b,0xc,{1,7,1});
        emit(b,5,{3,0x12345678,0xff});emit(b,5,{3,9,4});emit(b,6,{3});emit(b,5,{3,0xfffe,0x81});
        emit(b,0x44,{127});emit(b,0x44,{128});emit(b,0x45,{selector,0x8123,7,0x1ffff});emit(b,0x45,{0,1,8,4});const auto end=emit(b,0xa);
        run({b},{0,end},2,(selector+actor)%6,std::uint8_t(actor));
    }
    {std::vector<std::byte> b;for(std::size_t i=0;i<original_opcode_table.size();++i)if(original_opcode_table[i]==0x68cd80||i==0x192)emit(b,std::uint32_t(i),{},unsigned(i%6));const auto end=emit(b,0xa);run({b},{0,end},1);}
    for(auto p:{-1,0,1,2})for(auto op:{0x47u,0x48u})for(auto wanted:{0u,1u,0xffffffffu}){
        predicate_value=p;std::vector<std::byte> b;emit(b,0x46,{17,0x1234ff81,0x76543210});emit(b,op,{99,wanted});
        emit(b,0xb,{1,11,1});emit(b,0xe4);emit(b,0xb,{1,12,1});emit(b,0xe5);const auto end=emit(b,0xa);run({b},{0,end},2);
    }
    for(auto bit:{0u,15u,16u,31u,32u,0xffffffffu}){
        std::vector<std::byte> b;for(auto op:{0x40u,0x41u,0x42u,0x43u})emit(b,op,{2,bit});
        emit(b,0x44,{127});emit(b,0x49,{127,1});emit(b,0xe5);emit(b,0x4c,{bit});emit(b,0x4d,{bit,1});emit(b,0xe5);const auto end=emit(b,0xa);run({b},{0,end},2);
    }
    for(auto operation:{0u,1u,2u,3u,4u,5u,6u})for(auto actual:{0u,1u,0x80000000u,0xffffffffu})for(auto expected:{0u,1u,0x80000000u,0xffffffffu}){
        std::vector<std::byte> b;emit(b,0x110,{0,actual});emit(b,0x111,{1,0xffffffff});emit(b,0x111,{1,2});emit(b,0x112,{2,1});
        emit(b,0x113,{0,expected,operation});emit(b,0xb,{1,9,1});emit(b,0xe4);emit(b,0xb,{1,10,1});emit(b,0xe5);const auto end=emit(b,0xa);run({b},{0,end},1);
    }
    {std::vector<std::byte> b;emit(b,0x110,{3,0xffffffff});emit(b,0x110,{4,123});emit(b,0x114);emit(b,0x113,{4,0,0});const auto end=emit(b,0xa);run({b},{0,end},2);}
    for(unsigned exponent=0;exponent<256;++exponent)check(vm::Program::record_bytes(exponent<<24)==std::uint32_t((1u<<(exponent&31))*4u));
    // Admission cannot execute a few native handlers then silently fall back.
    {std::vector<std::byte> b;emit(b,1);emit(b,0x131,{},2);emit(b,0xa);vm::Interpreter n;const auto p=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b});check(n.install(0,p)==vm::Status::unsupported_opcode);}
    {std::vector<std::byte> b;emit(b,3,{0});vm::Interpreter n;check(n.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b}))==vm::Status::completed);check(n.tick(0,{}, {},8).status==vm::Status::budget_exhausted);}
    offline_tests();
    room_rules_tests();
    room_objects_vm_tests();
    actor_requests_vm_tests();
    for(unsigned profile=0;profile<16;++profile)for(const auto operation:{0u,1u,2u,3u,4u,5u,6u,0xffffffffu}){
        std::vector<std::byte> b;for(const auto opcode:{0x30u,0x31u,0x32u,0x33u})emit(b,opcode,{42});
        emit(b,0x37,{42,0xffffff81});emit(b,0x37,{42,0});
        emit(b,0x34,{42});emit(b,0x110,{0,1});emit(b,0xe4);emit(b,0x110,{0,2});emit(b,0xe5);
        emit(b,0x36,{19,0xfffffff9,operation});emit(b,0x110,{1,3});emit(b,0xe4);emit(b,0x110,{1,4});emit(b,0xe5);
        emit(b,0x35,{19});const auto end=emit(b,0xa);run({b},{0,end},2,profile%6,std::uint8_t(profile%4),false,profile);
    }
    for(const auto opcode:{0xe3u,0xe6u,0xecu,0xedu,0xefu})for(unsigned state=0;state<4;++state)for(const auto wanted:{0u,1u,0x100u}){
        std::vector<std::byte> b;emit(b,0xb,{0,127,state&1});emit(b,0xb,{1,127,state&1});emit(b,0xc,{0,127,state&2});emit(b,0xc,{1,127,state&2});
        emit(b,opcode,{opcode==0xef?0x1234007fu:127u,wanted});emit(b,0x110,{0,1});emit(b,0xe4);emit(b,0x110,{0,2});emit(b,0xe5);
        const auto end=emit(b,0xa);run({b},{0,end},2);
    }
    for(const auto bit:{0u,15u,16u,31u,32u,0xffffffffu})for(const auto wanted:{0u,1u}){
        std::vector<std::byte> b;emit(b,0x40,{2,bit});emit(b,0xf4,{2,bit});
        for(const auto opcode:{0xb7u,0xb8u}){emit(b,opcode,{2,bit,wanted});emit(b,0x110,{0,1});emit(b,0xe4);emit(b,0x110,{0,2});emit(b,0xe5);}
        emit(b,0xf5,{2,bit});const auto end=emit(b,0xa);run({b},{0,end},2);
    }
    for(const auto value:{0u,1u,2u,0x80000000u,0xffffffffu})for(const auto wanted:{0u,1u,0xffffffffu})for(unsigned actor=0;actor<4;++actor){
        std::vector<std::byte> b;
        for(unsigned index=0;index<2;++index){emit(b,0xe8,{index,value});emit(b,0xe9,{index,wanted});emit(b,0x110,{index,3});emit(b,0xe4);emit(b,0x110,{index,4});emit(b,0xe5);}
        const auto end=emit(b,0xa);run({b},{0,end},2,actor%6,std::uint8_t(actor));
    }
    {std::vector<std::byte> b;emit(b,0xe8,{2,123});bool rejected=false;try{const vm::Program p({b});}catch(const std::invalid_argument&){rejected=true;}check(rejected);}
    for(unsigned profile=0;profile<24;++profile)for(const auto desired:{0u,1u,2u,0xffffffffu}){
        std::vector<std::byte> b;emit(b,0x12);emit(b,0x14,{desired});emit(b,0x110,{0,1});emit(b,0xe4);emit(b,0x110,{0,2});emit(b,0xe5);
        emit(b,0x10,{31});emit(b,0x11,{0});emit(b,0x13,{0x1234001f,0xffff1234});emit(b,0x15,{30});emit(b,0x15,{31});
        emit(b,0x16,{0x12340081,0xffff8001,0x12347fff,0xffffffff});emit(b,0x17,{profile%2?profile+1:profile,desired});emit(b,0x110,{1,3});emit(b,0xe4);emit(b,0x110,{1,4});emit(b,0xe5);
        const auto end=emit(b,0xa);run({b},{0,end},2,profile%6,std::uint8_t(profile%4),false,0,profile);
    }
    for(const auto op:{0x10u,0x11u,0x13u,0x15u})for(const auto index:{32u,127u,255u}){
        std::vector<std::byte> b;emit(b,op,{index,123});bool rejected=false;try{const vm::Program p({b});}catch(const std::invalid_argument&){rejected=true;}check(rejected);}
    {vm::SequenceControl owner;vm::SequenceControlState invalid;invalid.count=33;check(!owner.restore(invalid));
        check(owner.snapshot().count==0);check(!owner.active(32,true));check(!owner.select(255,7));check(!owner.cancel_if_selected(255));}
    for(unsigned bank=0;bank<8;++bank){std::vector<std::byte> b;emit(b,0x20,{bank});if(bank>=4)emit(b,0x20,{0});
        for(unsigned i=0;i<32;++i)emit(b,0x23,{0x12340000u|i});
        emit(b,0x25);
        for(unsigned i=0;i<32;++i)emit(b,0x24,{i});
        emit(b,0x23,{7});const auto end=emit(b,0xa);run({b},{0,end},2,bank%6);}
    for(const auto op:{0x23u,0x24u})for(const auto index:{32u,255u}){std::vector<std::byte> b;emit(b,op,{index});bool refused=false;try{const vm::Program p({b});}catch(const std::invalid_argument&){refused=true;}check(refused);}
    for(const auto index:{0u,1u,31u,32u,63u,0x80000000u,0xffffffffu})for(unsigned channel=0;channel<6;++channel){std::vector<std::byte> b;
        emit(b,0xa0,{index});emit(b,4,{1});emit(b,0xa1,{index});emit(b,4,{1});emit(b,0xa2);emit(b,4,{1});emit(b,0xa3);const auto end=emit(b,0xa);run({b},{0,end},5,channel);}
    {std::vector<std::byte> b;emit(b,0x110,{0,88});emit(b,0xa2);emit(b,0xa);vm::Interpreter interpreter;
        check(interpreter.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b}))==vm::Status::completed);
        check(interpreter.tick(0,{}).status==vm::Status::provider_unavailable);check(interpreter.counters()[0]==0);}
    for(const auto parameter:{0u,1u,0x8000u,0x12345678u,0xffffffffu})for(const auto selector:{0u,7u,0xffffffffu})for(unsigned disabled=0;disabled<2;++disabled){
        std::vector<std::byte> b;for(const auto op:{0x50u,0x51u,0x52u,0x53u,0x54u,0x55u,0x56u,0x57u,0x58u,0x59u,0x5bu,0x5cu,0x5du,0x5eu,0x5fu,0x72u,0xb5u,0xf6u}){
            emit(b,op,{42,parameter,selector,0xffff87fe});emit(b,4,{1});}
        emit(b,0x190,{0x12345678});const auto end=emit(b,0xa);run({b},{0,end},20,parameter%6,std::uint8_t(selector&3),false,0,0,disabled);
    }
    for(const auto op:{0x104u,0x105u})for(const auto type:{0u,1u,2u,3u,4u,5u,6u,7u,9u,11u,13u,255u,UINT32_MAX})for(const auto id:{0u,42u,43u,UINT32_MAX})for(const auto selector:{0u,1u,7u,UINT32_MAX})for(unsigned disabled=0;disabled<2;++disabled){
        std::vector<std::byte> b;emit(b,op,{type,id,selector});const auto end=emit(b,0xa);run({b},{0,end},1,selector%6,0,false,0,0,disabled);
    }
    for(unsigned profile=0;profile<32;++profile)for(const auto tick:{0u,1234u}){std::vector<std::byte> b;emit(b,0x70,{69});emit(b,4,{1});emit(b,0x70,{69});emit(b,4,{1});emit(b,0x71);emit(b,4,{1});emit(b,0x70,{42});const auto end=emit(b,0xa);run({b},{0,end},5,profile%6,std::uint8_t(profile%4),false,0,0,0,profile,tick);}
    {std::vector<std::byte> b;emit(b,0x110,{0,88});emit(b,0x70,{69});emit(b,0xa);vm::Interpreter interpreter;StreamFixture streams;
        check(interpreter.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b}))==vm::Status::completed);vm::Providers providers;providers.streams=&streams.owner;providers.stream_backend=&streams;
        check(interpreter.tick(0,{},providers).status==vm::Status::provider_unavailable);check(interpreter.counters()[0]==0);check(streams.events.empty());}
    {std::vector<std::byte> b;emit(b,0x70,{0xffffffffu});bool refused=false;try{const vm::Program p({b});}catch(const std::invalid_argument&){refused=true;}check(refused);}
    for(unsigned profile=0;profile<192;++profile)for(unsigned owner=0;owner<4;++owner)for(unsigned variant=0;variant<4;++variant){
        const auto high=variant==0||variant==3?8u:variant==1?0u:255u;
        std::vector<std::byte> b;emit(b,0x135,{42,(high<<16)|(variant==3?0x8001u:42u),(high<<16)|(variant==3?0xffffu:2u),variant==3?0x80000u:UINT32_MAX,(high<<16)|(variant==3?0x4002u:400u)});
        emit(b,0x155,{profile%10,profile%3});emit(b,0x110,{0,1});emit(b,0xe4);emit(b,0x110,{0,2});emit(b,0xe5);
        emit(b,0x180,{profile%4});emit(b,0x110,{1,3});emit(b,0xe4);emit(b,0x110,{1,4});emit(b,0xe5);
        const auto end=emit(b,0xa);run({b},{0,end},1,profile%6,std::uint8_t(owner),false,0,0,profile,0,1234,profile);
    }
    {ActorFixture actor;vm::ActionChoiceState bad;bad.table_row=4;check(!actor.choices.restore(bad));check(actor.choices.state().table_row==0);
        for(const auto op:{0x135u,0x155u,0x180u}){std::vector<std::byte> b;emit(b,0x110,{0,88});emit(b,op,{42,8u<<16,8u<<16,8u<<16,8u<<16});emit(b,0xa);vm::Interpreter vm;
            check(vm.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b}))==vm::Status::completed);vm::SceneControls controls;vm::Providers p;p.scene_controls=&controls;p.action_choices=&actor.choices;
            check(vm.tick(0,{},p).status==vm::Status::provider_unavailable);check(vm.counters()[0]==0);p.world=&actor.world;
            check(vm.tick(0,{true,false,1},p).status==vm::Status::provider_unavailable);check(vm.counters()[0]==0);
            if(op!=0x180){actor.world.retire_primary(0);check(vm.tick(0,{},p).status==vm::Status::provider_unavailable);check(vm.counters()[0]==0);}
        }
    }
    for(unsigned profile=0;profile<8;++profile)for(const auto authored:{0u,3u,31u,32u,255u,0xffff0103u}){
        std::vector<std::byte> b;emit(b,0xb0,{authored});emit(b,4,{1});emit(b,0xb1,{authored});const auto end=emit(b,0xa);run({b},{0,end},2,profile%6,0,false,0,0,0,0,1234,0,profile==7?255u:profile);
    }
    for(unsigned profile=0;profile<16;++profile)for(unsigned preset=0;preset<8;++preset)for(const auto authored:{0u,7u,31u,32u,255u}){
        std::vector<std::byte> b;emit(b,0xb4,{authored,preset});const auto end=emit(b,0xa);run({b},{0,end},1,profile%6,0,false,0,0,0,0,1234,0,profile);
    }
    {std::vector<std::byte> b;emit(b,0x110,{0,88});emit(b,0xb4,{3,0});emit(b,0xa);vm::Interpreter interpreter;check(interpreter.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b}))==vm::Status::completed);
        check(interpreter.tick(0,{}).status==vm::Status::provider_unavailable);check(interpreter.counters()[0]==0);ModelFixture models(255);vm::Providers p;p.models=&models.owner;
        check(interpreter.tick(0,{},p).status==vm::Status::provider_unavailable);check(interpreter.counters()[0]==0);
        b.clear();emit(b,0xb4,{0,8});bool refused=false;try{const vm::Program program({b});}catch(const std::invalid_argument&){refused=true;}check(refused);
    }
    // Complete main1B3C30 is return-only in the pinned File1 ELF. Observe all
    // registers/context plus the whole bounded memory before/after the cohort.
    {std::vector<std::uint8_t> ram(0x800000,0xa5),before=ram;std::uint32_t seed=0x1234abcd;for(unsigned i=0;i<4096;++i){R5900Context context;PS2Runtime runtime;
            for(auto& reg:context.r)for(auto& w:reg.lane){seed=seed*1664525u+1013904223u;w=(std::uint64_t(seed)<<32)|~seed;}
            context.pc=0x1b3c30;auto expected=context;expected.pc=GPR_U32(&context,31);sub_001B3C30_0x1b3c30(ram.data(),&context,&runtime);
            check(std::memcmp(&context,&expected,sizeof(context))==0);}
        check(ram==before);}
    // Independent complete opcode16/helper execution, including precision edges
    // around the signed boundary, odd values and all exponent-scale regions.
    {std::vector<std::uint8_t> ram(0x800000);vm::SequenceControl native;std::uint32_t seed=0x4f31a9b2;
        for(unsigned i=0;i<65536;++i){seed=seed*1664525u+1013904223u;const auto amount=i<1024?0x80000000u-512u+i:i<2048?0xffffffffu-(i-1024):seed;
            fixture_write<std::uint32_t>(ram.data(),0x10000,0xffffff81u);fixture_write<std::uint32_t>(ram.data(),0x10004,0x12348001);fixture_write<std::uint32_t>(ram.data(),0x10008,0xffff7fff);fixture_write(ram.data(),0x1000c,amount);
            R5900Context ctx;PS2Runtime runtime;SET_GPR_U32(&ctx,4,0x10000);SET_GPR_U32(&ctx,29,0x7f0000);SET_GPR_U32(&ctx,31,0xdeadbeef);o2_0068D4E0_0x68d4e0(ram.data(),&ctx,&runtime);
            check(ctx.pc==0xdeadbeef);native.percentage(0x81,std::int16_t(-32767),32767,amount);check(std::bit_cast<std::uint32_t>(native.snapshot().fraction)==fixture_read<std::uint32_t>(ram.data(),0x3ddde0));
        }
    }
    {std::vector<std::byte> b;emit(b,0x110,{0,123});emit(b,0x30,{42});emit(b,0xa);vm::Interpreter n;
        check(n.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b}))==vm::Status::completed);
        check(n.tick(0,{}).status==vm::Status::provider_unavailable);check(n.counters()[0]==0);}
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_dispatch_invocations\":"<<invocations<<",\"room_rule_original_invocations\":"<<room_rule_invocations<<",\"room_rule_dispatches\":"<<room_rule_dispatches<<",\"room_object_dispatches\":"<<room_object_dispatches<<",\"actor_request_consumers\":"<<actor_request_consumers<<",\"actor_request_dispatches\":"<<actor_request_dispatches<<",\"actor_request_profile_refusals\":"<<actor_request_profile_refusals<<",\"coverage\":{";
    bool first_profile=true;
    for(const auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){
        if(!first_profile)std::cout<<',';
        first_profile=false;
        std::cout<<'"'<<(profile==vm::DispatchProfile::ordinary?"ordinary":"offline_actor")<<"\":{\"native_algorithm\":[";
        const auto coverage=vm::Interpreter::coverage(profile);unsigned count=0;
        for(std::size_t i=0;i<coverage.size();++i){if(i)std::cout<<',';std::cout<<(coverage[i].native_algorithm?"true":"false");count+=coverage[i].native_algorithm?1u:0u;}
        std::cout<<"],\"count\":"<<count<<",\"total\":432}";
    }
    std::cout<<"},\"original_numeric_handler_invocations\":65536,\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
