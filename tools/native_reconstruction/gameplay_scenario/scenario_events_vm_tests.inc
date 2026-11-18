#include "game/native/gameplay_update/update.hpp"
namespace {
std::size_t scenario_event_dispatches{},scenario_event_refusals{};
struct EventNotifications final:vm::FlagNotifications {
    bool changed(const vm::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const vm::StridedFlagChange&)noexcept override{std::terminate();}
};
reo::native::gameplay_world::Profile event_profile(){reo::native::gameplay_world::Profile p;p.layouts.push_back({});return p;}
void compare_event_constructor(reo::native::gameplay_update::Owner& owner,const std::vector<std::uint8_t>& ram){
    for(unsigned bank=0;bank<3;++bank)for(unsigned slot=0;slot<10;++slot){
        std::array<std::uint8_t,272> expected{};const auto state=owner.scenario_events().inspect(bank,slot);
        if(state){
            expected[0]=1;expected[1]=state->slot;expected[2]=state->kind;expected[0x100]=state->owner_selector;
            const auto write=[&](unsigned at,auto value){std::memcpy(expected.data()+at,&value,sizeof value);};
            write(0x1c,bank?0x5baed0u:0x5ba470u);for(unsigned i=0;i<5;++i)write(0x60+4*i,state->arguments[i]);
        }
        check(std::memcmp(expected.data(),ram.data()+0x3b64d0+272*(bank*10+slot),expected.size())==0);
    }
}
void scenario_events_vm_tests(){
    namespace world=reo::native::gameplay_world;namespace update=reo::native::gameplay_update;
    std::vector<std::uint8_t> ram(0x900000);install_original_tables(ram);owned_scenario_event_constants(ram.data());
    // All actual owned D1 forms plus physical banks, byte narrowing and the
    // occupied-slot return. The separate complete task oracle checks lifetime.
    constexpr std::array<std::array<unsigned,7>,3> authored{{{{6,7,5,255,39,38,38}},{{6,4,7,255,51,52,53}},{{6,7,0,255,2,108,101}}}};
    for(bool offline:{false,true})for(unsigned mode:{0u,1u,2u,255u})for(unsigned selected:{0u,1u,2u,3u,7u,255u})for(const auto& record:authored){
        assertion_context="D1 offline="+std::to_string(offline)+" mode="+std::to_string(mode)+" selected="+std::to_string(selected);
        EventNotifications notices;world::World native_world(event_profile(),std::make_shared<world::Session>());native_world.mode=mode;native_world.selected_actor=selected;update::Owner owner(native_world,notices);
        std::memset(ram.data()+0x3b64d0,0,30*272);std::memset(ram.data()+0x3b64b0,0,24);ram[0x3243f2]=mode;ram[0x4baded]=selected;
        fixture_write(ram.data(),0x75a4b0,0u);fixture_write(ram.data(),0x75a4c0,0u);
        std::vector<std::byte> bytes;emit(bytes,0xd1,{0xabcd0000u|record[0],0xffee0000u|record[1],record[2],record[3],record[4],record[5],record[6]});
        emit(bytes,0xd1,{6,record[1],7,6,511,510,509});emit(bytes,0x110,{0,77});emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        vm::Providers p;p.world=&native_world;p.flags=p.canonical_flags=&owner.flags();p.scenario_events=&owner.scenario_events();
        const auto result=offline?native.tick_offline_channel(0,{true,false,std::uint8_t(selected)},{},p):native.tick(0,{true,false,std::uint8_t(selected)},p);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);compare_event_constructor(owner,ram);++scenario_event_dispatches;
    }
    for(bool offline:{false,true}){
        EventNotifications notices,foreign_notices;world::World native_world(event_profile(),std::make_shared<world::Session>()),foreign_world(event_profile(),std::make_shared<world::Session>());
        update::Owner owner(native_world,notices),foreign(foreign_world,foreign_notices);vm::Providers p;p.world=&native_world;
        const auto refuse=[&](vm::Providers supplied){std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0xd1,{6,7,0,255,2,108,101});emit(bytes,0xa);vm::Interpreter native;
            check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary))==vm::Status::completed);
            const auto result=offline?native.tick_offline_channel(0,{},{},supplied):native.tick(0,{},supplied);
            check(result.status==vm::Status::provider_unavailable&&native.counters()[0]==0&&owner.events().size()==0);++scenario_event_refusals;};
        refuse(p);p.scenario_events=&foreign.scenario_events();refuse(p);p.scenario_events=&owner.scenario_events();check(owner.scenario_events().close()==vm::ScenarioEventStatus::completed);refuse(p);
    }
    for(const auto payload:std::array<std::array<unsigned,7>,5>{{{{5,7,0,255,2,108,101}},{{6,10,0,255,2,108,101}},{{6,7,0xffffffffu,255,2,108,101}},{{6,7,0,255,512,108,101}},{{6,7,0,255,2,108,512}}}}){
        std::vector<std::byte> bytes;emit(bytes,0xd1,{payload[0],payload[1],payload[2],payload[3],payload[4],payload[5],payload[6]});bool rejected=false;try{const vm::Program program({bytes});}catch(const std::invalid_argument&){rejected=true;}check(rejected);++scenario_event_refusals;
    }
    {EventNotifications notices;world::World native_world(event_profile(),std::make_shared<world::Session>());native_world.mode=1;update::Owner owner(native_world,notices);
        std::vector<std::byte> bytes;emit(bytes,0xd1,{6,7,0,255,2,108,101});emit(bytes,0xa);check(owner.scripts().install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes}))==vm::Status::completed);
        check(owner.step_script(0).status==update::Status::completed&&owner.events().size()==1);
        const vm::ChannelReplacement clear{0,{},{}};check(owner.scripts().replace_channels(std::span(&clear,1))==vm::Status::completed);check(owner.events().size()==1);
        auto selection=tasks::OwnerSelection::borrow(native_world.selected_actor);check(owner.events().run(tasks::EventMode::shared_bank,selection).status==tasks::Status::completed);check(owner.events().size()==0);
    }
    assertion_context.clear();
}
}
