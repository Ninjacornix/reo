#include "game/native/gameplay_scenario/actor_model_classes.hpp"
namespace {
std::size_t actor_model_class_dispatches{},actor_model_class_refusals{};
void actor_model_classes_vm_tests(){
    namespace world=reo::native::gameplay_world;
    world::World native_world(event_profile(),std::make_shared<world::Session>());vm::FlagState flags;
    for(unsigned slot=0;slot<8;++slot){auto actor=std::make_unique<world::Actor>();actor->slot=std::uint8_t(slot);check(bool(native_world.spawn_primary(slot,std::move(actor)).id));}
    std::vector<std::uint8_t> ram(0x900000);install_original_tables(ram);
    std::uint32_t random=0x9856cd34;for(unsigned i=0;i<8*0x10e0;++i){random=random*1664525u+1013904223u;ram[0x4a5c30+i]=std::uint8_t(random>>24);}
    const std::array counts{0u,1u,2u,3u,4u,5u,6u,7u,8u,0x80000000u,0x80000001u,0xffffffffu};
    for(bool offline:{false,true})for(unsigned mode:{0u,1u,2u,255u})for(auto count:counts)for(unsigned value=0;value<256;++value){
        assertion_context="64 offline="+std::to_string(offline)+" mode="+std::to_string(mode)+" count="+std::to_string(count)+" value="+std::to_string(value);
        native_world.mode=ram[0x3243f2]=std::uint8_t(mode);native_world.selected_actor=ram[0x4baded]=std::uint8_t(value%8);
        native_world.session().primary_population=count;fixture_write(ram.data(),0x4baea0,count);
        for(unsigned slot=0;slot<8;++slot){auto actor=native_world.primary(slot);ram[0x4a5c30+slot*0x10e0]=std::uint8_t((slot+value)%2);actor->active=ram[0x4a5c30+slot*0x10e0]!=0;actor->model_pose_class=ram[0x4a617d+slot*0x10e0]=std::uint8_t(value+slot+3);}
        std::vector<std::uint8_t> projected(ram.begin()+0x4a5c30,ram.begin()+0x4a5c30+8*0x10e0);
        fixture_write(ram.data(),0x75a4b0,0u);fixture_write(ram.data(),0x75a4c0,0u);
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0x64,{0xbeef0000u|value});emit(bytes,0x110,{1,19});emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        vm::Providers p;p.world=&native_world;p.flags=p.canonical_flags=&flags;
        const auto result=offline?native.tick_offline_channel(0,{true,false,native_world.selected_actor},{},p):native.tick(0,{true,false,native_world.selected_actor},p);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);
        for(unsigned slot=0;slot<8;++slot)projected[slot*0x10e0+0x54d]=native_world.primary(slot)->model_pose_class;
        check(std::memcmp(projected.data(),ram.data()+0x4a5c30,projected.size())==0);check(fixture_read<std::uint32_t>(ram.data(),0x4baea0)==*native_world.session().primary_population);++actor_model_class_dispatches;
    }
    check(native_world.retire_primary(3)==reo::native::gameplay_actors::EntityStatus::completed);
    for(bool offline:{false,true})for(unsigned profile:{0u,1u,2u,3u}){
        native_world.session().primary_population=profile==0?std::optional<std::uint32_t>{}:std::optional<std::uint32_t>{profile==1?9u:profile==2?0x7fffffffu:8u};
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0x64,{2});emit(bytes,0xa);vm::Interpreter native;
        check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary))==vm::Status::completed);
        vm::Providers p;p.world=&native_world;p.flags=p.canonical_flags=&flags;const auto before=native_world.primary(0)->model_pose_class;
        const auto result=offline?native.tick_offline_channel(0,{true,false,native_world.selected_actor},{},p):native.tick(0,{true,false,native_world.selected_actor},p);
        check(result.status==vm::Status::provider_unavailable&&native.counters()[0]==0&&native_world.primary(0)->model_pose_class==before);++actor_model_class_refusals;
    }
    // A missing physical slot is irrelevant when signed population is negative.
    native_world.session().primary_population=0xffffffffu;check(vm::set_actor_model_classes(native_world,2));
    std::vector<std::byte> truncated;emit(truncated,0x64);bool rejected=false;try{const vm::Program program({truncated});}catch(const std::invalid_argument&){rejected=true;}check(rejected);++actor_model_class_refusals;
    assertion_context.clear();
}
}
