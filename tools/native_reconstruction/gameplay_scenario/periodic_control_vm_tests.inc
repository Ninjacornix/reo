#include "game/native/gameplay_effects/periodic_visuals.hpp"
#include "game/native/gameplay_scenario/periodic_effects.hpp"
#include <fstream>
namespace {
std::size_t periodic_dispatches{},periodic_factories{},periodic_live_frames{};
struct PeriodicIdle final:tasks::Task {void update(tasks::Scheduler&,const tasks::Handle&)noexcept override{}};
void periodic_control_vm_tests(const char* path){
    namespace effects=reo::native::gameplay_effects;
    std::ifstream source(path,std::ios::binary);std::uint32_t count{};source.read(reinterpret_cast<char*>(&count),4);check(count==12);
    const auto member=[&](){std::uint32_t size{};source.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x200000);std::vector<std::byte> bytes(size);source.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(source));return bytes;};
    const auto nbd=member(),efdata=member();const auto bank=effects::EffectBank::import(nbd,efdata);
    std::vector<std::uint8_t> ram(0x900000);
    for(bool offline:{false,true})for(unsigned profile=0;profile<8;++profile)for(unsigned existing:{0u,28u,31u,32u})for(unsigned id:{42u,43u,99u,0x100002au})for(unsigned category=0;category<(offline?5u:1u);++category)for(unsigned relation=0;relation<(offline?3u:1u);++relation){
        assertion_context="periodic131 profile="+std::to_string(profile)+" existing="+std::to_string(existing)+" id="+std::to_string(id)+" offline="+std::to_string(offline)+" category="+std::to_string(category)+" relation="+std::to_string(relation);
        ActorFixture actors(0,0,offline);vm::FlagState flags;flags.restore(initial_flags());ControlFixture controls(profile);tasks::Scheduler scheduler;
        for(unsigned i=0;i<existing;++i)check(scheduler.create(std::make_shared<PeriodicIdle>()).status==tasks::Status::completed);
        effects::PeriodicVisuals visuals(bank);vm::PeriodicEffects periodic(scheduler,controls.owner,flags,actors.session->random,visuals);
        const auto selector=0x98760000u|profile,stop=0x12348000u|(profile&15),parameter=0x76540000u|std::uint32_t(profile*123);
        actors.export_original(ram);controls.export_original(ram);export_flags(ram,flags.snapshot());install_original_tables(ram);ram[0x3243e8]=1;fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,17});emit(bytes,0x131,{id,selector,stop,parameter});emit(bytes,0x110,{1,19});const auto end=emit(bytes,0xa);vm::Interpreter native;
        if(offline)install_offline_program(native,ram,0,bytes);
        else{std::memcpy(ram.data()+0x10000,bytes.data(),bytes.size());fixture_write<std::uint32_t>(ram.data(),0x4bace0,0x10000);fixture_write<std::uint32_t>(ram.data(),0x4bad28,0x10000+end);fixture_write<std::uint32_t>(ram.data(),0x4bad40,0x90000);fixture_write<std::uint32_t>(ram.data(),0x90000,0x10000);fixture_write<std::uint32_t>(ram.data(),0x4bacf8,0);fixture_write<std::uint32_t>(ram.data(),0x4bad10,0);auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes});check(native.restore_channel(0,{program,{0,0},{0,end},0,0,0})==vm::Status::completed);}
        for(unsigned i=0;i<4;++i)fixture_write<std::uint32_t>(ram.data(),0x4bada8+4*i,0);
        original_periodic_used=existing;original_periodic_tasks.clear();
        if(offline)original_offline_call(ram,0,false);else{R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);o2_0068C660_0x68c660(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++invocations;}
        vm::Providers providers;providers.world=&actors.world;providers.flags=&flags;providers.canonical_flags=&flags;providers.scene_controls=&controls.owner;providers.periodic_effects=&periodic;
        const auto result=offline?native.tick_offline_channel(0,{true,false,0},{category,relation,0},providers):native.tick(0,{},providers);check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);controls.compare_original(ram);
        check(scheduler.size()==original_periodic_used);periodic_factories+=original_periodic_tasks.size();
        for(const auto task:original_periodic_tasks){check(ram[task]==1&&ram[task+2]==5);check(fixture_read<std::uint32_t>(ram.data(),task+0x14)==0x5d9680&&fixture_read<std::uint32_t>(ram.data(),task+0x18)==0);const auto parent=fixture_read<std::uint32_t>(ram.data(),task+0x28);check(parent>=control_node&&parent<control_node+controls.ids.size()*control_stride);check(std::memcmp(ram.data()+task+0x70,ram.data()+parent+0x44,12)==0);}
        flags.restore({});check(scheduler.run(tasks::Pass::update).status==tasks::Status::completed);check(periodic.healthy());check(visuals.update({10,20,30}).status==effects::VisualStatus::completed);const auto frame=visuals.retain();check(frame&&frame->visuals.size()==original_periodic_tasks.size());++periodic_live_frames;
        periodic.close();check(scheduler.size()==existing);++periodic_dispatches;
    }
    // Required owners are checked before even the first preceding script write.
    for(const auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor})for(unsigned failure=0;failure<10;++failure){
        ActorFixture actors;vm::FlagState flags,other_flags;ControlFixture controls;vm::SceneControls other_controls;tasks::Scheduler scheduler;effects::PeriodicVisuals visuals(bank);reo::native::gameplay_session::Random other_random;
        vm::PeriodicEffects periodic(scheduler,failure==3?other_controls:controls.owner,failure==4?other_flags:flags,failure==5?other_random:actors.session->random,visuals);
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,88});emit(bytes,0x131,{42,1,0x8000,2});emit(bytes,0xa);vm::Interpreter native;check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},profile))==vm::Status::completed);
        vm::Providers p;p.world=&actors.world;p.flags=&flags;p.canonical_flags=&flags;p.scene_controls=failure==1?nullptr:&controls.owner;p.periodic_effects=failure==0?nullptr:&periodic;
        if(failure==2)visuals.close();
        if(failure==6)check(scheduler.seal()==tasks::Status::completed);
        if(failure==7)p.world=nullptr;
        if(failure==8)p.flags=&other_flags;
        if(failure==9)p.canonical_flags=nullptr;
        const auto result=profile==vm::DispatchProfile::ordinary?native.tick(0,{},p):native.tick_offline_channel(0,{},{0,0,0},p);check(result.status==vm::Status::provider_unavailable&&result.operations==0&&native.counters()[0]==0&&scheduler.size()==0);
    }
    for(unsigned stop:{128u,255u,0x7fffu})for(const auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){bool refused{};try{std::vector<std::byte> bytes;emit(bytes,0x131,{42,0,stop,0});vm::Program program({bytes},profile);}catch(const std::invalid_argument&){refused=true;}check(refused);}
}
}
