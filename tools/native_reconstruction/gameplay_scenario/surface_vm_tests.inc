std::size_t surface_vm_cases{};
#ifndef REO_VM_PINNED_EFFECTS
#include "game/native/gameplay_contact_world/contacts.hpp"
struct UnqueriedSurfaceRooms final:reo::native::gameplay_contact_world::RoomResources {
    unsigned reads{};
    std::shared_ptr<reo::native::gameplay_contact_world::RoomInvocation> retain(std::uint16_t)override{++reads;return{};}
};
#endif
void surface_vm_tests(const char* corpus_path){
    // Selector!=1 is a true no-op, even in a short bounded record. It needs no
    // World/effect provider and must not read absent color/intensity words.
    for(const auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor})for(const auto selector:{0u,2u,255u,UINT32_MAX}){
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,17});emit(bytes,0xa8,{selector});emit(bytes,0xa);vm::Interpreter native;
        check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},profile))==vm::Status::completed);
        vm::FlagState flags;vm::Providers p;p.flags=&flags;p.canonical_flags=&flags;
        const auto result=profile==vm::DispatchProfile::ordinary?native.tick(0,{},p):native.tick_offline_channel(0,{},{0,0,0},p);
        check(result.status==vm::Status::yielded&&native.counters()[0]==17);++surface_vm_cases;
    }
    {bool refused{};try{std::vector<std::byte> bytes;emit(bytes,0xa8,{1});vm::Program program({bytes});}catch(const std::invalid_argument&){refused=true;}check(refused);}
#ifndef REO_VM_PINNED_EFFECTS
    namespace effects=reo::native::gameplay_effects;namespace w=reo::native::gameplay_world;
    std::ifstream source(corpus_path,std::ios::binary);std::uint32_t n{};source.read(reinterpret_cast<char*>(&n),4);check(n==12);std::vector<std::vector<std::byte>> assets;
    for(unsigned i=0;i<n;++i){std::uint32_t size{};source.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x200000);assets.emplace_back(size);source.read(reinterpret_cast<char*>(assets.back().data()),size);check(bool(source));}
    std::array<std::byte,264> joint_records{};const auto joint_profile=effects::SurfaceProfile::import(joint_records,255,254); // Factory does not read joint rows.
    for(unsigned bank_index=0;bank_index<6;++bank_index){
        const auto bank=effects::EffectBank::import(assets[2*bank_index],assets[2*bank_index+1]);
        for(const auto dispatch:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor})for(unsigned count=0;count<=8;++count)for(unsigned filled:{0u,160u,167u,168u}){
            assertion_context="surface VM bank="+std::to_string(bank_index)+" count="+std::to_string(count)+" filled="+std::to_string(filled);
            w::Profile profile;profile.layouts.push_back({0x100,0x10,0x20});profile.entities.capacity=16;
            auto session=std::make_shared<w::Session>();session->primary_population=count;
            auto world=std::make_shared<w::World>(profile,session);
            for(unsigned i=0;i<count;++i)check(world->spawn_primary(i,std::make_unique<w::Actor>()).status==w::actors::EntityStatus::completed);
            effects::PeriodicVisuals visuals(bank,session->random);effects::Modulation modulation({std::uint16_t(0x1280+count),{1,2,3},4});UnqueriedSurfaceRooms rooms;
            check(visuals.bind_surfaces(world,rooms,modulation,joint_profile));
            for(unsigned i=0;i<filled;++i)check(visuals.emit({36,{}}).status==vm::EmissionStatus::completed);
            std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=1;
            fixture_write(ram.data(),0x4b9d1a,modulation.state().flags);fixture_write(ram.data(),0x4bac84,modulation.state().color);fixture_write(ram.data(),0x4bac90,modulation.state().intensity);fixture_write(ram.data(),0x4baea0,count);
            const auto a=std::uint32_t(count%2?0x80000001u:200u),b=std::uint32_t(filled%2?0xffffffffu:400u);
            std::vector<std::byte> bytes;emit(bytes,0x110,{0,17});emit(bytes,0xa8,{1,a,b,600,750});emit(bytes,0x110,{1,19});const auto end=emit(bytes,0xa);
            vm::Interpreter native;
            if(dispatch==vm::DispatchProfile::offline_actor)install_offline_program(native,ram,0,bytes);
            else{std::memcpy(ram.data()+0x10000,bytes.data(),bytes.size());fixture_write<std::uint32_t>(ram.data(),0x4bace0,0x10000);fixture_write<std::uint32_t>(ram.data(),0x4bad28,0x10000+end);fixture_write<std::uint32_t>(ram.data(),0x4bad40,0x90000);fixture_write<std::uint32_t>(ram.data(),0x90000,0x10000);auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes});check(native.restore_channel(0,{program,{0,0},{0,end},0,0,0})==vm::Status::completed);}
            original_surface_used=filled;original_surface_attempts=0;original_surface_nodes.clear();
            if(dispatch==vm::DispatchProfile::offline_actor)original_offline_call(ram,0,false);
            else{R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);o2_0068C660_0x68c660(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++invocations;}
            vm::FlagState flags;vm::Providers p;p.world=world.get();p.flags=&flags;p.canonical_flags=&flags;p.surface_effects=&visuals;
            const auto result=dispatch==vm::DispatchProfile::ordinary?native.tick(0,{},p):native.tick_offline_channel(0,{},{0,0,0},p);
            check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);check(rooms.reads==0);
            check(modulation.state().flags==fixture_read<std::uint16_t>(ram.data(),0x4b9d1a)&&std::memcmp(&modulation.state().color,ram.data()+0x4bac84,12)==0&&std::bit_cast<std::uint32_t>(modulation.state().intensity)==fixture_read<std::uint32_t>(ram.data(),0x4bac90));
            check(original_surface_attempts==count&&original_surface_nodes.size()==std::min(count,168-filled)&&visuals.size()==original_surface_used);
            for(const auto at:original_surface_nodes){check(ram[at]==1&&ram[at+1]==0&&ram[at+3]==0x17);check(fixture_read<std::uint32_t>(ram.data(),at+0x24)==0x4a5c30+ram[at+4]*0x10e0u);}
            ++surface_vm_cases;
        }
    }
    // Whole-program and three-actor offline admission happens before prefix
    // mutations. A foreign RNG, stale World, unknown count or hole is refused.
    const auto bank=effects::EffectBank::import(assets[0],assets[1]);
    for(unsigned failure=0;failure<6;++failure){
        w::Profile profile;profile.layouts.push_back({0x100,0x10,0x20});auto session=std::make_shared<w::Session>();session->primary_population=1;auto world=std::make_shared<w::World>(profile,session);
        check(world->spawn_primary(0,std::make_unique<w::Actor>()).status==w::actors::EntityStatus::completed);effects::PeriodicVisuals visuals(bank,session->random);effects::Modulation modulation({});UnqueriedSurfaceRooms rooms;
        check(visuals.bind_surfaces(world,rooms,modulation,joint_profile));
        if(failure==1)session->primary_population.reset();
        if(failure==2)session->primary_population=9;
        if(failure==3)world->retire_primary(0);
        if(failure==4)world->close();
        if(failure==5)visuals.close();
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,88});emit(bytes,0xa8,{1,1,2,3,4});emit(bytes,0xa);
        for(const auto dispatch:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){
            vm::Interpreter native;auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},dispatch);check(native.install(dispatch==vm::DispatchProfile::ordinary?0:1,program)==vm::Status::completed);
            vm::FlagState flags;vm::Providers p;p.world=world.get();p.flags=&flags;p.canonical_flags=&flags;p.surface_effects=failure?&visuals:nullptr;
            if(dispatch==vm::DispatchProfile::ordinary)check(native.tick(0,{},p).status==vm::Status::provider_unavailable);
            else{vm::OfflineCoordinator coordinator;std::array<vm::OfflinePartyActor,3>party{{{true,0,0},{true,0,0},{true,0,0}}};const auto result=coordinator.tick(native,1,true,party,0,world->selected_actor,flags,p);check(result.status==vm::Status::provider_unavailable&&result.invocations==0);}
            check(native.counters()[0]==0&&modulation.state().flags==0&&rooms.reads==0);++surface_vm_cases;
        }
    }
#else
    (void)corpus_path;
#endif
}
