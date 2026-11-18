#include "game/native/gameplay_scenario/difficulty_predicate.hpp"
namespace {
std::size_t difficulty_dispatches{},difficulty_refusals{};
void difficulty_vm_tests(){
    namespace world=reo::native::gameplay_world;
    world::World native_world(event_profile(),std::make_shared<world::Session>());native_world.mode=1;
    vm::FlagState flags;
    std::vector<std::uint8_t> ram(0x900000);install_original_tables(ram);owned_difficulty_constants(ram.data());
    for(bool offline:{false,true})for(unsigned current=0;current<256;++current)for(unsigned value=0;value<256;++value){
        if(offline&&value!=0&&value!=1&&value!=2&&value!=127&&value!=128&&value!=254&&value!=255)continue;
        for(unsigned selector:{0u,1u,2u,3u,4u,5u,6u,7u,255u}){
            assertion_context="EE offline="+std::to_string(offline)+" difficulty="+std::to_string(current)+" value="+std::to_string(value)+" selector="+std::to_string(selector);
            native_world.session().difficulty=std::uint8_t(current);ram[0x4bae8a]=std::uint8_t(current);
            fixture_write(ram.data(),0x75a4b0,0u);fixture_write(ram.data(),0x75a4c0,0u);
            std::vector<std::byte> bytes;emit(bytes,0xee,{0xface0000u|value,0xbeef0000u|selector});emit(bytes,0x110,{0,11});
            emit(bytes,0xee,{value,0});emit(bytes,0x110,{1,19});emit(bytes,0xe4);emit(bytes,0x110,{1,23});emit(bytes,0xe5);
            emit(bytes,0xe4);emit(bytes,0x110,{0,17});emit(bytes,0xe5);emit(bytes,0xa);
            vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
            vm::Providers p;p.world=&native_world;p.flags=p.canonical_flags=&flags;
            const auto result=offline?native.tick_offline_channel(0,{},{},p):native.tick(0,{},p);
            check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);
            check(native_world.session().difficulty==current&&ram[0x4bae8a]==current);++difficulty_dispatches;
        }
    }
    for(bool offline:{false,true})for(unsigned selector:{0u,1u,2u,3u,4u,5u}){
        native_world.session().difficulty.reset();std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0xee,{2,selector});emit(bytes,0x110,{1,11});emit(bytes,0xe5);emit(bytes,0xa);
        vm::Interpreter native;check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary))==vm::Status::completed);
        vm::Providers p;p.world=&native_world;p.flags=p.canonical_flags=&flags;const auto result=offline?native.tick_offline_channel(0,{},{},p):native.tick(0,{},p);
        check(result.status==vm::Status::provider_unavailable&&native.counters()[0]==0);++difficulty_refusals;
    }
    // Invalid selectors scan without reading a difficulty byte or World.
    for(bool offline:{false,true})for(unsigned selector:{6u,7u,255u}){
        std::vector<std::byte> bytes;emit(bytes,0xee,{2,selector});emit(bytes,0x110,{0,11});emit(bytes,0xe4);emit(bytes,0x110,{0,17});emit(bytes,0xe5);emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        vm::Providers p;p.flags=p.canonical_flags=&flags;
        const auto result=offline?native.tick_offline_channel(0,{},{},p):native.tick(0,{},p);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);check(native.counters()[0]==17);++difficulty_dispatches;
    }
    {std::vector<std::byte> short_payload;emit(short_payload,0xee,{2});bool rejected=false;try{const vm::Program program({short_payload});}catch(const std::invalid_argument&){rejected=true;}check(rejected);++difficulty_refusals;}
    assertion_context.clear();
}
}
