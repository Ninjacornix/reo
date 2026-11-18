#include "game/native/gameplay_world/weapon_actions.hpp"
unsigned weapon_action_cases{},weapon_action_refusals{};
void compare_weapon_actions(const std::vector<std::vector<std::byte>>& corpus,const char* static_path,
    const char*,const char* iso_path,const std::filesystem::path&,std::vector<std::uint8_t>& ram){
    using namespace depletion_fixture;
    const auto assets=factory_load(static_path,16);
    std::vector<std::byte> encoded(32+16*24);
    const auto write=[&]<class T>(unsigned at,T value){std::memcpy(encoded.data()+at,&value,sizeof value);};
    write(0,3u);write(4,16u);write(16,32u);
    for(unsigned n=0;n<16;++n){
        write(32+24*n,std::uint32_t(1u|(n&1?0x1000000u:0u)|(n&2?0x80000u:0u)|(n&4?0x40000u:0u)));
        write(32+24*n+8,std::int16_t(20));write(32+24*n+10,std::int16_t(-1));
        write(32+24*n+14,std::uint8_t(255));write(32+24*n+18,std::uint16_t(42));
    }
    Consuming f(ram,assets[0],encoded);
    for(unsigned i=4;i<8;++i)check(bool(f.q.world.spawn_primary(i,std::make_unique<g::Actor>()).id));
    const auto pinned=r::win32::PinnedFile::open_verified(std::filesystem::path(iso_path),owned_iso_bytes,owned_iso_sha);
    check(pinned.status==r::win32::PinnedStatus::ok);
    const auto archive=[&](std::uint64_t offset,std::uint64_t bytes){
        reo::assets::VirtualFile file;file.size=bytes;file.segments.push_back({0,bytes,offset,std::make_shared<reo::assets::Source>(pinned.file->identity().final_path,pinned.file),{}});
        const auto view=r::VirtualFileView::create(file);check(view.status==r::Status::ok);
        const auto opened=af::Archive::open(view.view,0,bytes);check(opened.status==af::Status::completed);return opened.archive;
    };
    auto engine=std::make_shared<b::Session>();auto audio=std::make_shared<a::Owner>(engine,f.q.session->random);
    l::Loader loader(audio,archive(924106752,1062582272));
    const auto catalogue=w::Catalogue::prepare_file1_rom(archive(17065984,477052928));
    w::Owner weapons(f.q.world,f.q.resources,f.q.templates,catalogue,audio,loader);
    a::SpatialContext spatial;spatial.world_to_screen=m::identity();
    g::animation_events::BasicAudio frontend(f.q.world,*audio,spatial,f.q.resources,f.q.templates);
    e::PeriodicVisuals visuals(e::EffectBank::import(corpus[0],corpus[1]),f.q.session->random);
    check(visuals.bind_resource_debris(f.q.world,f.q.models,f.q.factory));
    g::ResourceDepletion depletion(f.recipes,visuals,frontend,weapons);
    g::ResourceDeployment deployment(f.recipes,f.update);
    g::ResourceWeaponActions actions(f.update,f.q.resources,f.q.templates,f.inventory,depletion,deployment,frontend);
    // Complete original use/refresh bodies;65E880's real metadata/absent-model
    // return executes. This cohort makes no reached firing/effect claim.
    for(unsigned method=0;method<2;++method)for(unsigned n=0;n<32768;++n){
        const auto slot=n%8;const auto actor=f.q.world.primary(slot);
        f.mode((n/8)%4,(n/32)%8);f.q.session->gameplay_flags=std::uint8_t(n/256);
        f.q.memory[0x4bae96]=f.q.session->gameplay_flags;
        actor->category=std::uint8_t((n/64)%3);actor->slot=std::uint8_t(slot);
        actor->character=std::uint8_t(n%8);actor->selected_resource=std::uint8_t(n%17?3:0);
        actor->secondary_equipped_resource=std::uint8_t(n%7?0:3);actor->resource_action=std::uint16_t(n%64);
        actor->status=0x80000000u|n;actor->inventory={};actor->inventory.carried={3,0,6,3};
        inventory_fixture::export_actor(f.q.memory,*actor,slot);
        const auto raw_actor=0x4a5c30+0x10e0*slot;
        f.q.memory[raw_actor+2]=actor->category;f.q.memory[raw_actor+3]=actor->slot;
        put(f.q.memory,raw_actor+0xba0,actor->status);
        s::SceneDescriptor item;item.active=std::uint8_t(n%13?1:0);item.instance_index=3;
        item.ownership_tag=std::uint16_t(n%11?1:0);item.parameter=std::int16_t((n/128)%5-1);
        item.attachment_id=42;item.template_index=std::uint8_t((n/1024)%16);item.flags=std::uint32_t(n&0x40);
        sync(f.q,3,item);auto other=item;other.instance_index=6;other.template_index=0;sync(f.q,6,other);
        put(f.q.memory,0x743128,unsigned(f.q.resources.active_count()));
        f.reset_statistics(n);const auto count=n*65521u;
        auto statistics=f.update.completion_statistics().state();
        statistics.actors.resource_uses=count;statistics.actors.used_resource=std::uint8_t(n);
        f.update.completion_statistics().restore(statistics);
        put(f.q.memory,0x3b84bc,count);f.q.memory[0x3b84f5]=std::uint8_t(n);
        const auto resource=n%17?0xabcd0003u:0xabcd0000u;
        const auto expected=call(f.q.memory,method?0x65ec40:0x65e750,{raw_actor,resource});
        if(method)check(actions.refresh(f.q.world.identity(slot)));
        else{const auto actual=actions.use(f.q.world.identity(slot),resource);check(actual.available&&actual.value==std::int8_t(GPR_U32(&expected,2)));}
        compare_all(f.q,3);compare_all(f.q,6);inventory_fixture::compare_actor(f.q.memory,*actor,slot);
        check(actor->status==get<unsigned>(f.q.memory,raw_actor+0xba0));
        const auto& counters=f.update.completion_statistics().state().actors;
        if(counters.resource_uses!=get<unsigned>(f.q.memory,0x3b84bc)||counters.used_resource!=f.q.memory[0x3b84f5])
            throw std::runtime_error("Weapon counters method="+std::to_string(method)+" n="+std::to_string(n)+" count="+std::to_string(counters.resource_uses)+"/"+std::to_string(get<unsigned>(f.q.memory,0x3b84bc))+" used="+std::to_string(counters.used_resource)+"/"+std::to_string(f.q.memory[0x3b84f5]));
        check(true);
        ++weapon_action_cases;
    }
    check(!actions.use({},3).available&&!actions.refresh({}));++weapon_action_refusals;
    const auto stale=f.q.world.identity(7);check(f.q.world.retire_primary(7)==g::actors::EntityStatus::completed);
    check(!actions.use(stale,3).available&&!actions.refresh(stale));++weapon_action_refusals;
#ifdef REO_WEAPON_FIRE
    compare_weapon_fire(f,frontend,catalogue->cleared());
#endif
}
