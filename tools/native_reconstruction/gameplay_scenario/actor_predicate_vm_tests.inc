#include "game/native/gameplay_scenario/actor_script_predicates.hpp"
namespace {
std::size_t actor_condition_dispatches{},actor_ai_counter_dispatches{},actor_predicate_refusals{};
void actor_predicate_vm_tests(){
    ActorFixture fixture;std::vector<std::uint8_t> ram(0x900000);install_original_tables(ram);
    std::memcpy(ram.data()+0x7408f0,original_actor_query_table.data(),sizeof(original_actor_query_table));
    vm::FlagState flags;vm::Providers providers;providers.world=&fixture.world;providers.flags=providers.canonical_flags=&flags;
    constexpr std::array<std::uint32_t,10> parameters{0,1,2,7,31,32,255,0x123,0xabcd0123,0x800000ff};
    constexpr std::array<std::uint32_t,9> statuses{0,8,0x20,0x40,0x80,0x100,0x400,0x5e0,0xfffffa1f};
    for(unsigned id=0;id<512;++id){check(flags.scenario_owner(id,std::uint8_t(id*13u)));ram[0x4baa50+id]=std::uint8_t(id*13u);}
    for(const auto pair:std::array<std::array<unsigned,2>,3>{{{0,1},{1,32},{511,33}}}){
        check(flags.scenario_owner(pair[0],std::uint8_t(pair[1])));ram[0x4baa50+pair[0]]=std::uint8_t(pair[1]);
    }
    for(bool offline:{false,true})for(unsigned mode:{0u,1u,2u,0xffffffffu})for(unsigned selector:{0u,1u,4u,7u,8u,255u})
    for(unsigned query=0;query<9;++query)for(unsigned pi=0;pi<(query==5?3u:10u);++pi)for(unsigned trial=0;trial<16;++trial){
        if(!mode&&selector>=8)continue;
        const auto parameter=query==5?std::array{0u,1u,511u}[pi]:parameters[pi];
        const auto expected=std::array{0u,1u,2u,0xffffffffu}[trial%4];
        assertion_context="156 offline="+std::to_string(offline)+" mode="+std::to_string(mode)+" selector="+std::to_string(selector)+" query="+std::to_string(query)+" parameter="+std::to_string(parameter)+" trial="+std::to_string(trial);
        fixture.world.selected_actor=ram[0x4baded]=std::uint8_t(trial%8);
        fixture.world.mode=ram[0x3243f2]=std::uint8_t(trial%4);
        fixture.session->primary_population=std::array{0u,1u,3u,8u}[(trial/4)%4];fixture_write(ram.data(),0x4baea0,*fixture.session->primary_population);
        for(unsigned i=0;i<8;++i){auto actor=fixture.world.primary(i);const auto at=0x4a5c30+0x10e0*i;
            actor->active=(trial+i)%3!=0;actor->ai_control=std::uint8_t((trial+i)%4);actor->character=std::uint8_t((trial+i)%3);
            actor->slot=std::array<std::uint8_t,5>{0,1,31,32,255}[(trial+i)%5];actor->motion_style=std::uint8_t((trial+i)%8);
            actor->status=statuses[(trial+i)%statuses.size()];actor->room=std::uint16_t(0x123+i);
            ram[at]=actor->active?0x80:0;ram[at+3]=actor->slot;ram[at+0xff0]=actor->ai_control;ram[at+0xb98]=actor->character;ram[at+0xb99]=actor->motion_style;
            fixture_write(ram.data(),at+0xba0,actor->status);fixture_write(ram.data(),at+0x1e2,actor->room);
        }
        const unsigned category=trial%5,relation=(trial/5)%4;fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);
        std::vector<std::byte> bytes;emit(bytes,0x156,{mode,selector,query,parameter,expected});
        emit(bytes,0x110,{0,11});emit(bytes,0xe4);emit(bytes,0x110,{0,17});emit(bytes,0xe5);emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        const vm::TickContext context{true,false,fixture.world.selected_actor};
        const auto result=offline?native.tick_offline_channel(0,context,{category,relation,0},providers):native.tick(0,context,providers);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);++actor_condition_dispatches;
    }
    // Fixed8 traversal deliberately ignores population and tests full-word1.
    fixture.session->primary_population.reset();fixture_write(ram.data(),0x4baea0,0xffffffffu);
    for(bool offline:{false,true})for(unsigned value:{0u,1u,2u,255u,256u,257u,65537u,0xffffffffu})
    for(unsigned category=0;category<5;++category)for(unsigned relation=0;relation<4;++relation)for(unsigned trial=0;trial<8;++trial){
        assertion_context="1A5 offline="+std::to_string(offline)+" value="+std::to_string(value)+" category="+std::to_string(category)+" relation="+std::to_string(relation)+" trial="+std::to_string(trial);
        fixture.world.selected_actor=ram[0x4baded]=std::uint8_t(trial);
        std::array<reo::native::gameplay_ai::ExecutionState,8> before;
        for(unsigned i=0;i<8;++i){auto actor=fixture.world.primary(i);const auto at=0x4a5c30+0x10e0*i;
            actor->active=(trial+i)%3!=0;actor->ai_control=std::uint8_t((trial+i)%4);actor->ai_execution.emplace();
            auto& state=*actor->ai_execution;state.goal=std::uint16_t(trial*3+i);state.action_counter=0xdead0000u+trial+i;state.reaction_countdown=std::uint16_t(99+i);
            before[i]=state;ram[at]=actor->active?0x80:0;ram[at+0xff0]=actor->ai_control;fixture_write(ram.data(),at+0x1034,state.action_counter);
        }
        fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);
        std::vector<std::byte> bytes;emit(bytes,0x1a5,{value});emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        const vm::TickContext context{true,false,fixture.world.selected_actor};
        const auto result=offline?native.tick_offline_channel(0,context,{category,relation,0},providers):native.tick(0,context,{});
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);
        for(unsigned i=0;i<8;++i){auto expected=before[i];expected.action_counter=fixture_read<std::uint32_t>(ram.data(),0x4a5c30+0x10e0*i+0x1034);check(*fixture.world.primary(i)->ai_execution==expected);}
        ++actor_ai_counter_dispatches;
    }
    const auto refusal=[&](unsigned opcode,std::initializer_list<std::uint32_t> payload,vm::Providers supplied){
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,opcode,payload);emit(bytes,0xa);
        vm::Interpreter native;check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},vm::DispatchProfile::offline_actor))==vm::Status::completed);
        check(native.tick_offline_channel(0,{true,false,fixture.world.selected_actor},{},supplied).status==vm::Status::provider_unavailable&&native.counters()[0]==0);++actor_predicate_refusals;
    };
    auto actor=fixture.world.primary(7);actor->active=true;actor->ai_control=1;actor->ai_execution.reset();refusal(0x1a5,{1},providers);
    check(!vm::set_actor_ai_counter(fixture.world,1));actor->active=false;check(vm::actor_ai_counter_ready(fixture.world));
    refusal(0x156,{0,0,0,0,0},providers);fixture.session->primary_population=9;refusal(0x156,{0,0,0,0,0},providers);
    fixture.session->primary_population=8;auto missing_flags=providers;missing_flags.flags=missing_flags.canonical_flags=nullptr;refusal(0x156,{0,0,5,1,0},missing_flags);
    check(fixture.world.retire_primary(0)==reo::native::gameplay_actors::EntityStatus::completed);refusal(0x156,{0,0,0,0,0},providers);refusal(0x156,{1,255,0,0,0},providers);
    for(const auto values:std::array<std::array<unsigned,5>,2>{{{0,8,0,0,0},{0,0,5,512,0}}}){
        std::vector<std::byte> bytes;emit(bytes,0x156,{values[0],values[1],values[2],values[3],values[4]});bool failed=false;
        try{vm::Program program({bytes});}catch(const std::invalid_argument&){failed=true;}check(failed);++actor_predicate_refusals;
    }
    assertion_context.clear();
}
}
