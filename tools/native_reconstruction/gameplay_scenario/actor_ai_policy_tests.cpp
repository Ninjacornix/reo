#include "game/native/gameplay_scenario/actor_ai_policy.hpp"
#include "game/native/gameplay_scenario/interpreter.hpp"
#include "game/native/gameplay_update/update.hpp"
#include "original_fixture.hpp"
#include <iostream>
#include <source_location>
#include <vector>

namespace s=reo::native::gameplay_scenario;
namespace w=reo::native::gameplay_world;
namespace u=reo::native::gameplay_update;
void o2_00702C50_0x702c50(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_007029E0_0x7029e0(std::uint8_t*,R5900Context*,PS2Runtime*);
namespace {
std::size_t checks{},original_calls{},dispatches{},refusals{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("AI policy check at "+std::to_string(at.line()));
}
void word(std::vector<std::byte>& bytes,std::uint32_t value){
    for(unsigned i=0;i<4;++i)bytes.push_back(std::byte((value>>(8*i))&255));
}
std::shared_ptr<const s::Program> program(std::uint32_t value,s::DispatchProfile profile,bool prefix=false){
    std::vector<std::byte> bytes;word(bytes,1);
    if(prefix){word(bytes,0x02000110);word(bytes,0);word(bytes,77);word(bytes,0);}
    word(bytes,0x010001a8);word(bytes,value);word(bytes,0xa);
    return std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{bytes},profile);
}
std::shared_ptr<const s::Program> inhibition_program(std::uint32_t selector,std::uint32_t value,s::DispatchProfile profile,bool prefix=false){
    std::vector<std::byte> bytes;word(bytes,1);
    if(prefix){word(bytes,0x02000110);word(bytes,0);word(bytes,77);word(bytes,0);}
    word(bytes,0x020001a4);word(bytes,selector);word(bytes,value);word(bytes,0);word(bytes,0xa);
    return std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{bytes},profile);
}
struct Notices:s::FlagNotifications{
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
}
int main()try{
    w::Profile profile;profile.layouts.push_back({});
    auto session=std::make_shared<w::Session>();w::World world(profile,session);s::FlagState flags;
    for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();actor->ai_execution.emplace();
        check(world.spawn_primary(i,std::move(actor)).status==reo::native::gameplay_actors::EntityStatus::completed);}
    std::vector<std::uint8_t> memory(0x900000);
    constexpr std::uint32_t values[]{0,1,2,3,255,256,257,258,65537,65538,0xffffffff};
    for(bool offline:{false,true})for(auto value:values)for(unsigned trial=0;trial<32;++trial){
        world.mode=std::uint8_t(trial%4);world.selected_actor=std::uint8_t(trial%8);
        if(trial%3==0)session->primary_population.reset();else session->primary_population=trial%3==1?0:0xffffffffu;
        std::array<reo::native::gameplay_ai::ExecutionState,8> before;
        for(unsigned i=0;i<8;++i){auto actor=world.primary(i);const auto at=0x4a5c30+i*0x10e0u;
            actor->active=(trial+i)%3!=0;actor->ai_control=std::uint8_t((trial+i)%4);
            actor->status=(trial%2)?0x5e0:0;actor->ai_execution.emplace();
            auto& state=*actor->ai_execution;state.action_damage_policy=std::uint8_t(31+trial+i);
            state.goal=std::uint16_t(trial*13+i);state.action_counter=0xdead0000u+i;state.goal_resource=0x12340000u+trial;
            before[i]=state;std::memset(memory.data()+at,std::uint8_t(trial+i),0x10e0);
            memory[at]=actor->active?0x80:0;memory[at+0xff0]=actor->ai_control;memory[at+0x10a8]=state.action_damage_policy;
        }
        auto expected_memory=memory;
        if(offline){
            transform_write(memory.data(),0x10000,value);transform_write(expected_memory.data(),0x10000,value);
            R5900Context context;PS2Runtime runtime;context.pc=0x702c50;SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,31,0x100);
            o2_00702C50_0x702c50(memory.data(),&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,2)==0);++original_calls;
        }
        s::Interpreter interpreter;check(interpreter.install(0,program(value,offline?s::DispatchProfile::offline_actor:s::DispatchProfile::ordinary))==s::Status::completed);
        s::Providers providers;providers.world=&world;providers.flags=providers.canonical_flags=&flags;
        const auto result=offline?interpreter.tick_offline_channel(0,{true,false,world.selected_actor},{trial%5,trial%4,0},providers):interpreter.tick(0,{});
        if(result.status!=s::Status::yielded)throw std::runtime_error("1A8 status "+std::to_string(int(result.status))+" offline="+std::to_string(offline)+" value="+std::to_string(value)+" trial="+std::to_string(trial));
        check(result.status==s::Status::yielded);++dispatches;
        for(unsigned i=0;i<8;++i){auto expected=before[i];const auto at=0x4a5c30+i*0x10e0u;
            expected.action_damage_policy=memory[at+0x10a8];check(*world.primary(i)->ai_execution==expected);
            expected_memory[at+0x10a8]=expected.action_damage_policy;
        }
        check(expected_memory==memory); // Actual original stores only the policy byte.
    }
    for(bool offline:{false,true})for(auto value:values)for(unsigned selector=0;selector<8;++selector)for(unsigned trial=0;trial<32;++trial){
        world.selected_actor=std::uint8_t((selector+3)%8);
        std::array<reo::native::gameplay_ai::ExecutionState,8> before;
        for(unsigned i=0;i<8;++i){auto actor=world.primary(i);const auto at=0x4a5c30+i*0x10e0u;
            actor->active=(trial+i)%3!=0;actor->ai_control=std::uint8_t((trial+i)%4);actor->status=0x5e0;
            actor->ai_execution.emplace();actor->ai_execution->inhibited=std::uint8_t(197+i);
            actor->ai_execution->action_damage_policy=std::uint8_t(trial+i);before[i]=*actor->ai_execution;
            std::memset(memory.data()+at,0x17,0x10e0);memory[at]=actor->active?0x80:0;memory[at+0xff0]=actor->ai_control;memory[at+0xff1]=before[i].inhibited;
        }
        auto expected_memory=memory;
        const bool skipped=trial%5>=2||trial%4==1||trial%4==2;
        if(offline&&!skipped){
            transform_write(memory.data(),0x10000,selector);transform_write(memory.data(),0x10004,value);
            R5900Context context;PS2Runtime runtime;context.pc=0x7029e0;SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,31,0x100);
            o2_007029E0_0x7029e0(memory.data(),&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,2)==0);++original_calls;
        }
        s::Interpreter interpreter;check(interpreter.install(0,inhibition_program(selector,value,offline?s::DispatchProfile::offline_actor:s::DispatchProfile::ordinary))==s::Status::completed);
        s::Providers providers;providers.world=&world;providers.flags=providers.canonical_flags=&flags;
        const auto result=offline?interpreter.tick_offline_channel(0,{true,false,world.selected_actor},{trial%5,trial%4,0},providers):interpreter.tick(0,{});
        check(result.status==s::Status::yielded);++dispatches;
        for(unsigned i=0;i<8;++i){auto expected=before[i];const auto at=0x4a5c30+i*0x10e0u;
            expected.inhibited=memory[at+0xff1];check(*world.primary(i)->ai_execution==expected);expected_memory[at+0xff1]=expected.inhibited;
        }
        check(std::memcmp(expected_memory.data()+0x4a5c30,memory.data()+0x4a5c30,8*0x10e0)==0);
    }
    for(unsigned i=0;i<8;++i){auto actor=world.primary(i);actor->active=true;actor->ai_control=1;actor->ai_execution.emplace();actor->ai_execution->action_damage_policy=197;}
    world.primary(7)->ai_execution.reset();s::Providers providers;providers.world=&world;providers.flags=providers.canonical_flags=&flags;
    const auto refuse=[&](s::Providers supplied){s::Interpreter interpreter;
        check(interpreter.install(0,program(2,s::DispatchProfile::offline_actor,true))==s::Status::completed);
        check(interpreter.tick_offline_channel(0,{true,false,world.selected_actor},{},supplied).status==s::Status::provider_unavailable);
        check(interpreter.counters()[0]==0);for(unsigned i=0;i<7;++i)check(world.primary(i)->ai_execution->action_damage_policy==197);++refusals;
    };
    refuse(providers);refuse({});check(!s::set_actor_ai_damage_policy(world,2));
    {
        s::Interpreter interpreter;check(interpreter.install(0,inhibition_program(7,1,s::DispatchProfile::offline_actor,true))==s::Status::completed);
        check(interpreter.tick_offline_channel(0,{true,false,world.selected_actor},{},providers).status==s::Status::provider_unavailable&&interpreter.counters()[0]==0);++refusals;
        check(!s::set_actor_ai_inhibition(world,7,1));
        check(s::set_actor_ai_inhibition(world,7,257)); // Full-word unknown value does not access absent FF1.
        bool rejected=false;try{inhibition_program(8,1,s::DispatchProfile::offline_actor);}catch(const std::invalid_argument&){rejected=true;}
        check(rejected);++refusals;
        std::vector<std::byte> truncated;word(truncated,0x010001a4);word(truncated,0);rejected=false;
        try{s::Program invalid({truncated},s::DispatchProfile::offline_actor);}catch(const std::invalid_argument&){rejected=true;}
        check(rejected);++refusals;
    }
    world.primary(7)->active=false;check(s::set_actor_ai_damage_policy(world,2));
    world.primary(7)->active=true;world.primary(7)->ai_control=0;check(s::set_actor_ai_damage_policy(world,1));
    // Actual Update installs its canonical World automatically for1A8.
    world.mode=0;Notices notices;u::Owner owner(world,notices);
    check(owner.scripts().install(0,program(2,s::DispatchProfile::offline_actor))==s::Status::completed);
    check(owner.step_script(0).status==u::Status::completed);
    for(unsigned i=0;i<7;++i)check(world.primary(i)->ai_execution->action_damage_policy==2);
    check(world.retire_primary(7)==reo::native::gameplay_actors::EntityStatus::completed);
    check(s::set_actor_ai_damage_policy(world,0));
    check(world.close()==w::Status::completed);check(!s::actor_ai_damage_policy_ready(world));check(!s::set_actor_ai_damage_policy(world,1));
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<original_calls<<",\"dispatches\":"<<dispatches<<",\"refusals\":"<<refusals<<",\"game_launched\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
