unsigned equipment_selections{},equipment_selection_full{},equipment_selection_refusals{};
void compare_equipment_selection(const char* iso_path,const char* static_path,std::vector<std::uint8_t>& ram){
    using namespace weapon_fixture;using delayed_fixture::Fixture;
    const auto pinned=r::win32::PinnedFile::open_verified(std::filesystem::path(iso_path),owned_iso_bytes,owned_iso_sha);check(pinned.status==r::win32::PinnedStatus::ok);
    const auto archive=[&](std::uint64_t offset,std::uint64_t bytes){reo::assets::VirtualFile file;file.size=bytes;file.segments.push_back({0,bytes,offset,std::make_shared<reo::assets::Source>(pinned.file->identity().final_path,pinned.file),{}});const auto view=r::VirtualFileView::create(file);check(view.status==r::Status::ok);const auto result=af::Archive::open(view.view,0,bytes);check(result.status==af::Status::completed);return result.archive;};
    const auto catalogue=w::Catalogue::prepare_file1_rom(archive(17065984,477052928));const auto snd=archive(924106752,1062582272);const auto assets=factory_load(static_path,16);
    const auto encoded=[](unsigned action,bool flag){std::vector<std::byte> data(80);const auto write=[&](unsigned offset,unsigned value){std::memcpy(data.data()+offset,&value,4);};write(0,3);write(4,2);write(16,32);write(32,1);data[46]=std::byte(1);data[47]=std::byte(action);write(56,flag?0x80000001u:0x80000000u);data[56+18]=std::byte(99);return data;};
    for(unsigned slot=0;slot<4;++slot){
        Fixture q(ram,assets[0],encoded(0,true));auto engine=std::make_shared<b::Session>();auto audio=std::make_shared<a::Owner>(engine,q.world.session().random);l::Loader loader(audio,snd);w::Owner weapons(q.world,q.resources,q.templates,catalogue,audio,loader);w::Equipment equipment(weapons,q.factory);
        for(unsigned i=0;i<4;++i){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(i);check(bool(q.world.spawn_primary(i,std::move(actor)).id));q.memory[0x4a5c30+0x10e0*i+3]=std::uint8_t(i);}
        q.world.session().primary_population=4;put(q.memory,0x4baea0,4u);
        const auto run=[&](unsigned action,bool active,bool meta_active,bool flag,bool missing,bool meta_missing,unsigned requested,bool queue_full=false,bool pool_full=false){
            call(q.memory,0x5b1850,{3});q.frames.release(3,false);
            const auto data=encoded(action,flag);check(q.templates.load(data));std::memcpy(q.memory+0x100000,data.data(),data.size());call(q.memory,0x5921d0,{0x100000});
            s::SceneDescriptor d;d.active=std::uint8_t(active);d.instance_index=8;d.template_index=missing?255:0;d.flags=0x1234;q.sync(d);
            s::SceneDescriptor metadata;metadata.active=std::uint8_t(meta_active);metadata.template_index=meta_missing?255:1;check(bool(q.resources.load(8,metadata)));q.memory[0x3c5630+8*60]=metadata.active;q.memory[0x3c5630+8*60+43]=metadata.template_index;
            const auto actor=q.world.primary(slot);actor->selected_resource=9;actor->resource_action=0x1234;actor->weapon_programs=catalogue->cleared();const unsigned raw=0x4a5c30+0x10e0*slot;q.memory[raw+0xc7c]=9;put(q.memory,raw+0xca8,std::uint16_t(0x1234));std::fill_n(q.memory+0x749180+2048*slot,2048,0);std::fill_n(q.memory+0x2b3840,0x100,0);
            std::array<l::LoadTicket,8> tickets;if(queue_full){for(auto& ticket:tickets){const auto submitted=loader.enqueue("weapon01",8);check(submitted.status==l::LoadStatus::accepted);ticket=submitted.ticket;}q.memory[0x2b3841]=8;}
            if(pool_full)for(unsigned n=0;n<64;++n){const auto original=call(q.memory,0x591230,{0});const auto native=q.factory.create(0);check(native.status==g::ResourceModelStatus::completed&&GPR_U32(&original,2)==q.address(native.id));}
            call(q.memory,0x666de0,{raw,requested});const auto actual=equipment.select(q.world.identity(slot),std::uint8_t(requested));
            const bool selected=requested&&meta_active&&flag&&!meta_missing;check(actual.status==s::SceneStatus::completed&&actual.changed==selected&&bool(actual.attachment)==selected);
            check(actor->selected_resource==q.memory[raw+0xc7c]&&actor->resource_action==get<std::uint16_t>(q.memory,raw+0xca8));check(q.resources.get(*q.resources.slot(3))->ownership_tag==get<std::uint16_t>(q.memory,delayed_fixture::descriptor+40));q.compare_world();
            const bool changed=selected&&active&&!missing;check(actor->weapon_programs==(changed?catalogue->find(1):catalogue->cleared()));std::array<std::uint8_t,2048> buffer{};if(changed)std::copy(owned_weapons[1].bytes.begin(),owned_weapons[1].bytes.end(),buffer.begin());check(std::memcmp(buffer.data(),q.memory+0x749180+2048*slot,buffer.size())==0);
            check(q.memory[0x2b3841]==(queue_full?8u:unsigned(changed)));if(changed){check(actual.attachment->weapons&&actual.attachment->weapons->audio);if(queue_full)check(actual.attachment->weapons->audio->status==l::LoadStatus::full);else check(loader.cancel(actual.attachment->weapons->audio->ticket));}
            if(queue_full){for(auto ticket:tickets)check(loader.cancel(ticket));++equipment_selection_full;}if(pool_full){check(actual.attachment->primary.status==g::ResourceModelStatus::full);while(const auto id=q.models.head()){call(q.memory,0x590d80,{q.address(id)});check(q.models.retire(id)==g::ResourceModelStatus::completed);}++equipment_selection_full;}
            ++equipment_selections;
        };
        for(unsigned action=0;action<256;++action)run(action,true,true,true,false,false,3);
        for(bool active:{false,true})for(bool meta_active:{false,true})for(bool flag:{false,true})for(bool missing:{false,true})for(bool meta_missing:{false,true})for(unsigned requested:{0u,3u})run((equipment_selections*37)&255u,active,meta_active,flag,missing,meta_missing,requested);
        run(255,true,true,true,false,false,3,true);run(128,true,true,true,false,false,3,false,true);
        // Missing population stops after real selection/model prefix; action
        // computation must not overwrite the prior CA8 value after refusal.
        call(q.memory,0x5b1850,{3});q.frames.release(3,false);s::SceneDescriptor d;d.active=1;d.instance_index=8;d.template_index=0;q.sync(d);s::SceneDescriptor meta;meta.active=1;meta.template_index=1;check(bool(q.resources.load(8,meta)));const auto data=encoded(127,true);check(q.templates.load(data));q.world.session().primary_population.reset();const auto actor=q.world.primary(slot);actor->resource_action=1234;const auto refused=equipment.select(q.world.identity(slot),3);check(refused.status==s::SceneStatus::provider_unavailable&&refused.changed&&refused.attachment&&refused.attachment->primary.model&&actor->selected_resource==3&&actor->resource_action==1234);++equipment_selection_refusals;
        check(equipment.select({},3).status==s::SceneStatus::invalid_identity);++equipment_selection_refusals;
        auto linked=std::make_unique<g::Actor>();linked->slot=std::uint8_t(slot);const auto linked_id=q.world.spawn_linked(std::move(linked)).id;const auto linked_refused=equipment.select(linked_id,3);check(linked_refused.status==s::SceneStatus::provider_unavailable&&!linked_refused.changed);++equipment_selection_refusals;
        check(q.world.close()==g::Status::completed&&equipment.select({},3).status==s::SceneStatus::provider_unavailable);check(equipment.select({},0).status==s::SceneStatus::completed);++equipment_selection_refusals;
    }
    placement_floors=nullptr;
}
