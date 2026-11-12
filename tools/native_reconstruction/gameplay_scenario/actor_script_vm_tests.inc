#include "game/native/gameplay_scenario/actor_script_commands.hpp"
namespace {
std::size_t actor_room_dispatches{},actor_profile_dispatches{},actor_script_refusals{};
void install_actor_script(vm::Interpreter& native,std::vector<std::uint8_t>& ram,
                         std::vector<std::byte> bytes,bool offline){
    std::fill(ram.begin()+0x4bace0,ram.begin()+0x4bade0,0);
    const auto tail=last_record(bytes);
    std::memcpy(ram.data()+0x10000,bytes.data(),bytes.size());
    fixture_write(ram.data(),0x90000,0x10000u);
    fixture_write(ram.data(),0x4bace0,0x10000u);fixture_write(ram.data(),0x4bad28,0x10000u+tail);
    fixture_write(ram.data(),0x4bad40,0x90000u);ram[0x3243e8]=1;
    auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{std::move(bytes)},offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary);
    check(native.restore_channel(0,{program,{0,0},{0,tail},0,0,0})==vm::Status::completed);
}
void call_actor_script(std::vector<std::uint8_t>& ram,bool offline){
    R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,4,0);SET_GPR_U32(&context,29,0x7f0000);SET_GPR_U32(&context,31,0xdeadbeef);
    if(offline)o2_007006D0_0x7006d0(ram.data(),&context,&runtime);else o2_0068C660_0x68c660(ram.data(),&context,&runtime);
    check(context.pc==0xdeadbeef);
}
void actor_script_vm_tests(){
    ActorFixture fixture;std::vector<std::uint8_t> ram(0x900000);install_original_tables(ram);owned_ai_profile_constants(ram.data());
    vm::FlagState flags;vm::Providers providers;providers.world=&fixture.world;providers.flags=providers.canonical_flags=&flags;
    constexpr std::array<std::uint32_t,8> statuses{0,0x20,0x40,0x80,0x100,0x400,0x5e0,0xfffffa1f};
    // Both actual dispatchers, both branches/else scans, nested predicates,
    // all physical slots and every selected-slot alias destination.
    for(bool offline:{false,true})for(unsigned selector=0;selector<8;++selector)for(unsigned selected=0;selected<8;++selected)
    for(unsigned trial=0;trial<32;++trial){
        assertion_context="150 offline="+std::to_string(offline)+" selector="+std::to_string(selector)+" selected="+std::to_string(selected)+" trial="+std::to_string(trial);
        fixture.world.selected_actor=std::uint8_t(selected);ram[0x4baded]=std::uint8_t(selected);
        for(unsigned i=0;i<8;++i){const auto actor=fixture.world.primary(i);const auto at=0x4a5c30+0x10e0*i;
            actor->active=((trial+i)&1)!=0;actor->status=statuses[(trial/2+i)%statuses.size()];actor->room=std::uint16_t(((trial&16)?0x8023:0x123)+i);
            ram[at]=actor->active?std::uint8_t((trial&2)?0x80:1):0;fixture_write(ram.data(),at+0xba0,actor->status);fixture_write(ram.data(),at+0x1e2,actor->room);
        }
        const unsigned category=trial%5,relation=(trial/5)%4;
        fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);
        std::vector<std::byte> bytes;emit(bytes,0x150,{selector,0xabcd0123u+(trial%8),(trial&2)?0x100u:0u});
        emit(bytes,0x110,{0,11});emit(bytes,0x150,{4,0x123,1});emit(bytes,0x110,{1,19});emit(bytes,0xe4);emit(bytes,0x110,{1,23});emit(bytes,0xe5);
        emit(bytes,0xe4);emit(bytes,0x110,{0,17});emit(bytes,0xe5);emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        const vm::TickContext context{true,false,std::uint8_t(selected)};
        const auto result=offline?native.tick_offline_channel(0,context,{category,relation,0},providers):native.tick(0,context,providers);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);++actor_room_dispatches;
    }
    constexpr std::array<std::int32_t,7> profiles{0,1,19,20,255,256,INT32_MAX};
    for(unsigned mode:{0u,1u,2u,0xffffffffu})for(unsigned selector=0;selector<9;++selector)for(auto profile:profiles)
    for(unsigned trial=0;trial<24;++trial){
        if(!mode&&selector>=8)continue;
        assertion_context="1A1 mode="+std::to_string(mode)+" selector="+std::to_string(selector)+" profile="+std::to_string(profile)+" trial="+std::to_string(trial);
        fixture.world.selected_actor=ram[0x4baded]=std::uint8_t(trial%8);
        fixture.session->primary_population=trial%9;fixture_write(ram.data(),0x4baea0,*fixture.session->primary_population);
        std::array<reo::native::gameplay_ai::ExecutionState,8> before;
        for(unsigned i=0;i<8;++i){auto actor=fixture.world.primary(i);actor->active=(trial+i)%3!=0;actor->ai_control=std::uint8_t((trial+i)%4);actor->character=std::uint8_t(i%3);
            actor->ai_execution.emplace();auto& state=*actor->ai_execution;state.goal=std::uint16_t(trial+i);state.action=std::uint16_t(trial*7+i);state.weight_profile=std::uint8_t((trial+i)%20);
            state.reaction_countdown=std::uint16_t(trial*11+i);
            for(unsigned j=0;j<8;++j){state.base_weights[j]=std::uint8_t(trial+i+j);state.reactive_weights[j]=std::uint8_t(trial*3+i+j);state.status_weights[j]=std::uint8_t(trial*7+i+j);state.combined_weights[j]=std::uint8_t(trial*11+i+j);}
            before[i]=state;const auto at=0x4a5c30+0x10e0*i;
            ram[at]=actor->active?0x80:0;ram[at+0xff0]=actor->ai_control;ram[at+0xb98]=actor->character;ram[at+0x1067]=*state.weight_profile;fixture_write(ram.data(),at+0x10ac,0x828a60u+56u*(*state.weight_profile));
            for(unsigned j=0;j<8;++j){ram[at+0x10b0+j]=state.base_weights[j];ram[at+0x10b8+j]=state.reactive_weights[j];ram[at+0x10c0+j]=state.status_weights[j];ram[at+0x10c8+j]=state.combined_weights[j];}
        }
        const unsigned category=trial%5,relation=(trial/5)%4;fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);
        std::vector<std::byte> bytes;emit(bytes,0x1a1,{mode,selector,std::bit_cast<std::uint32_t>(profile)});emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),true);call_actor_script(ram,true);
        check(native.tick_offline_channel(0,{true,false,fixture.world.selected_actor},{category,relation,0},providers).status==vm::Status::yielded);
        compare_offline_channels(native,ram);
        for(unsigned i=0;i<8;++i){const auto actor=fixture.world.primary(i);const auto at=0x4a5c30+0x10e0*i;auto expected=before[i];expected.weight_profile=ram[at+0x1067];
            for(unsigned j=0;j<8;++j){expected.base_weights[j]=ram[at+0x10b0+j];expected.reactive_weights[j]=ram[at+0x10b8+j];expected.status_weights[j]=ram[at+0x10c0+j];expected.combined_weights[j]=ram[at+0x10c8+j];}
            check(*actor->ai_execution==expected);check(fixture_read<std::uint32_t>(ram.data(),at+0x10ac)==0x828a60u+56u*(*expected.weight_profile));
        }
        ++actor_profile_dispatches;
    }
    // Whole-program preflight must protect an earlier counter. Unknown AI
    // capability is required only for actors which the command would update.
    const auto refusal=[&](std::uint32_t mode,std::uint32_t selector,std::int32_t profile){
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0x1a1,{mode,selector,std::bit_cast<std::uint32_t>(profile)});emit(bytes,0xa);
        vm::Interpreter native;check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},vm::DispatchProfile::offline_actor))==vm::Status::completed);
        check(native.tick_offline_channel(0,{true,false,fixture.world.selected_actor},{},providers).status==vm::Status::provider_unavailable&&native.counters()[0]==0);++actor_script_refusals;
    };
    auto actor=fixture.world.primary(0);actor->active=true;actor->ai_control=1;actor->character=0;actor->ai_execution.reset();
    refusal(0,0,1);fixture.session->primary_population=1;refusal(1,0,1);actor->ai_execution.emplace();refusal(0,0,-1);
    fixture.session->primary_population.reset();refusal(1,0,1);fixture.session->primary_population=9;refusal(1,0,1);
    check(vm::actor_weight_profile_ready(fixture.world,0,0,20));actor->active=false;check(vm::actor_weight_profile_ready(fixture.world,0,0,-1));
    check(fixture.world.retire_primary(0)==reo::native::gameplay_actors::EntityStatus::completed);
    check(vm::actor_room_matches(fixture.world,0,0,false)==true&&vm::actor_weight_profile_ready(fixture.world,0,0,1));
    for(auto opcode:{0x150u,0x1a1u}){std::vector<std::byte> bytes;emit(bytes,opcode,{8,0,0});if(opcode==0x1a1){bytes.clear();emit(bytes,opcode,{0,8,0});}
        bool failed=false;try{vm::Program program({bytes},vm::DispatchProfile::offline_actor);}catch(const std::invalid_argument&){failed=true;}check(failed);++actor_script_refusals;
    }
    assertion_context.clear();
}
}
