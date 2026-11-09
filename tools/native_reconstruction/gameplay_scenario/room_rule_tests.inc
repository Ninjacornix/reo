#include "game/native/gameplay_scenario/room_rules.hpp"
namespace {
std::size_t room_rule_invocations{},room_rule_dispatches{};
vm::FlagStateSnapshot rule_flags(unsigned bits){
    auto s=initial_flags();const auto set=[&](std::uint32_t& word,unsigned bit,bool value){const auto mask=std::uint32_t(1)<<bit;word=value?word|mask:word&~mask;};
    for(unsigned i=0;i<4;++i)set(s.primary[0][3],15+i,(bits&(1u<<i))!=0);
    set(s.shared.scenario[9],10,(bits&16)!=0);set(s.shared.secondary[15],16,(bits&32)!=0);return s;
}
void add_minimal_three(ControlFixture& controls){controls.ids.push_back(*controls.owner.append({0xffffffffu,0x81,vm::ControlOther{3}}));}
void export_rule_context(std::vector<std::uint8_t>& ram,reo::native::gameplay_world::World& world,std::uint16_t scenario,std::uint16_t room,unsigned mode){
    world.scenario=scenario;world.room=room;world.mode=std::uint8_t(mode);world.selected_actor=2;
    fixture_write(ram.data(),0x3243da,scenario);fixture_write(ram.data(),0x3243dc,room);ram[0x3243f2]=std::uint8_t(mode);ram[0x4baded]=2;
}
void room_rules_tests(){
    auto session=std::make_shared<reo::native::gameplay_world::Session>();reo::native::gameplay_world::World world(ActorFixture::profile(),session);
    std::vector<std::uint8_t> ram(0x900000);vm::FlagState flags;
    for(const auto scenario:{0u,1u,2u,0x0102u,0xffffu})for(const auto room:{0u,0x1fu,0x23u,0x0123u})for(unsigned bits=0;bits<64;++bits)for(unsigned disabled=0;disabled<2;++disabled)for(const auto mode:{0u,1u,2u,255u}){
        assertion_context="complete room rules scenario="+std::to_string(scenario)+" room="+std::to_string(room)+" bits="+std::to_string(bits)+" mode="+std::to_string(mode)+" disabled="+std::to_string(disabled);
        export_rule_context(ram,world,std::uint16_t(scenario),std::uint16_t(room),mode);const auto initial=rule_flags(bits);flags.restore(initial);export_flags(ram,initial);ControlFixture controls(disabled);add_minimal_three(controls);controls.export_original(ram);
        R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);sub_001B3C40_0x1b3c40(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++room_rule_invocations;
        check(vm::apply_scenario_room_rules(world,flags,controls.owner)==vm::RoomRuleStatus::completed);compare_flags(ram,flags.snapshot());controls.compare_original(ram);
    }
    for(bool offline:{false,true})for(const auto scenario:{0u,2u,0x0102u})for(const auto room:{0x1fu,0x23u})for(unsigned bits=0;bits<64;++bits)for(unsigned category=0;category<(offline?5u:1u);++category)for(unsigned relation=0;relation<(offline?3u:1u);++relation){
        assertion_context="room rules dispatcher offline="+std::to_string(offline)+" scenario="+std::to_string(scenario)+" room="+std::to_string(room)+" bits="+std::to_string(bits)+" category="+std::to_string(category)+" relation="+std::to_string(relation);
        install_original_tables(ram);ram[0x3243e8]=1;export_rule_context(ram,world,std::uint16_t(scenario),std::uint16_t(room),offline?0:1);fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);
        const auto initial=rule_flags(bits);flags.restore(initial);export_flags(ram,initial);ControlFixture controls(bits&1u);add_minimal_three(controls);controls.export_original(ram);
        std::vector<std::byte> b;emit(b,0x110,{0,88});emit(b,0x191);emit(b,0x110,{1,99});const auto end=emit(b,0xa);vm::Interpreter native;
        for(unsigned i=0;i<4;++i)fixture_write<std::uint32_t>(ram.data(),0x4bada8+4*i,0);
        if(offline)install_offline_program(native,ram,0,b);
        else{std::memcpy(ram.data()+0x10000,b.data(),b.size());fixture_write<std::uint32_t>(ram.data(),0x4bace0,0x10000);fixture_write<std::uint32_t>(ram.data(),0x4bad28,0x10000+end);fixture_write<std::uint32_t>(ram.data(),0x4bad40,0x90000);fixture_write<std::uint32_t>(ram.data(),0x90000,0x10000);fixture_write<std::uint32_t>(ram.data(),0x4bacf8,0);fixture_write<std::uint32_t>(ram.data(),0x4bad10,0);
            const auto p=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b});check(native.restore_channel(0,{p,{0,0},{0,end},0,0,0})==vm::Status::completed);
        }
        if(offline)original_offline_call(ram,0,false);else{R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);o2_0068C660_0x68c660(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++invocations;}
        vm::Providers p;p.flags=&flags;p.canonical_flags=&flags;p.world=&world;p.scene_controls=&controls.owner;
        const auto result=offline?native.tick_offline_channel(0,{true,false,2,std::uint16_t(room)},{category,relation,0},p):native.tick(0,{true,false,2,std::uint16_t(room)},p);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);compare_flags(ram,flags.snapshot());controls.compare_original(ram);++room_rule_dispatches;
    }
    for(const auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){
        std::vector<std::byte> b;emit(b,0x110,{0,88});emit(b,0x191);emit(b,0xa);vm::Interpreter native;check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b},profile))==vm::Status::completed);
        ControlFixture controls;vm::Providers p;p.flags=&flags;p.canonical_flags=&flags;p.world=&world;p.scene_controls=&controls.owner;world.selected_actor=2;world.scenario.reset();
        const auto tick=[&]{return profile==vm::DispatchProfile::ordinary?native.tick(0,{true,false,2},p):native.tick_offline_channel(0,{true,false,2},{0,0,0},p);};
        check(tick().status==vm::Status::provider_unavailable);check(native.counters()[0]==0);world.scenario=0;p.canonical_flags=nullptr;check(tick().status==vm::Status::provider_unavailable);check(native.counters()[0]==0);
        p.canonical_flags=&flags;Flags shadow;p.flags=&shadow;check(tick().status==vm::Status::provider_unavailable);check(native.counters()[0]==0);
    }
    {std::vector<std::byte> b;emit(b,1);emit(b,0x191);emit(b,0xa);vm::Interpreter native;vm::OfflineCoordinator coordinator;std::array<vm::OfflinePartyActor,3> party;
        install_original_tables(ram);ram[0x3243e8]=1;export_rule_context(ram,world,2,0x23,0);const auto initial=rule_flags(16|2);flags.restore(initial);export_flags(ram,initial);
        for(unsigned i=0;i<3;++i){party[i]={true,0,0x23};ram[0x4a5c30+i*0x10e0]=0x80;ram[0x4a5c33+i*0x10e0]=0;fixture_write<std::uint16_t>(ram.data(),0x4a5c30+i*0x10e0+0x1e2,0x23);}
        install_offline_program(native,ram,1,b);ControlFixture controls;controls.export_original(ram);vm::Providers p;p.world=&world;p.scene_controls=&controls.owner;
        original_offline_call(ram,1,true);const auto result=coordinator.tick(native,1,true,party,0x23,world.selected_actor,flags,p);check(result.status==vm::Status::completed);check(result.invocations==3);compare_offline_channels(native,ram);compare_flags(ram,flags.snapshot());
        const auto before=flags.snapshot();const auto pc=native.channels()[1].current;world.selected_actor=2;world.scenario.reset();check(coordinator.tick(native,1,true,party,0x23,world.selected_actor,flags,p).status==vm::Status::provider_unavailable);check(world.selected_actor==2);check(native.channels()[1].current==pc);check(flags.snapshot().primary==before.primary);check(flags.snapshot().shared.scenario==before.shared.scenario);
    }
}
}
