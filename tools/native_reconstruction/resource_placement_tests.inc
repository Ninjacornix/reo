unsigned placement_cases{},placement_owned{},placement_refusals{},placement_full{};
std::shared_ptr<const reo::native::gameplay_collision::response::Grid> placement_grid(){
    using namespace reo::native::gameplay_collision;
    std::vector<std::byte> bytes(120);const auto write=[&]<class T>(unsigned at,T value){std::memcpy(bytes.data()+at,&value,sizeof value);};
    write(8,4096u);write(12,4096u);write(16,1u);write(20,1u);write(32,32u);write(36,56u);write(40,36u);write(44,0u);write(48,UINT32_MAX);
    write(64,0x3307u);write(68,Vec3{0,0,0});write(80,Vec3{0,0,4096});write(92,Vec3{4096,0,0});write(104,Vec3{0,1,0});write(116,0.f);
    return std::make_shared<const response::Grid>(response::Grid::import(bytes));
}
void compare_resource_placement(const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    namespace g=reo::native::gameplay_world;
    const auto assets=factory_load(static_path,16);auto banks=factory_load(template_path,5);auto* memory=ram.data();const auto floors=placement_grid();placement_floors=floors.get();
    std::vector<std::byte> controlled(124);const auto write=[&]<class T>(unsigned at,T value){std::memcpy(controlled.data()+at,&value,sizeof value);};
    write(0,3u);write(4,3u);write(12,2u);write(16,32u);write(20,104u);write(24,116u);
    for(unsigned i=0;i<3;++i){write(32+24*i+18,std::uint16_t(42+i));controlled[32+24*i+12]=std::byte(2-i);controlled[32+24*i+13]=std::byte(1);controlled[32+24*i+20]=std::byte(i==1?1:i==2?3:0);write(104+4*i,1.5f-float(i)*2.25f);}write(116,0.f);write(120,12.5f);banks.push_back(controlled);
    for(const auto& asset:assets){
        const auto cache=g::ResourceStaticAssets::import_nbd(asset);std::fill(ram.begin(),ram.end(),0);owned_constants(memory);put(memory,0x294e00,m::identity());unsigned offset{},length{};std::memcpy(&offset,asset.data()+0x24,4);std::memcpy(&length,asset.data()+0x28,4);std::memcpy(memory+0x100000,asset.data()+offset,length);put(memory,0x32440c,0x400000u);call(memory,0x1d3100,{0x70000,0x100000});
        for(const auto& encoded:banks){
            s::ResourceTemplates templates;check(templates.load(encoded));std::fill_n(memory+0x74bb50,129*24,0);std::fill_n(memory+0x74b940,129*4,0);std::fill_n(memory+0x74c770,128*4,0);std::fill_n(memory+0x74c970,384*2,0);std::fill_n(memory+0x74b6e0,600,255);put(memory,0x74ccf0,std::uint16_t(0));std::memcpy(memory+0x100000,encoded.data(),encoded.size());call(memory,0x5921d0,{0x100000});call(memory,0x590be0);call(memory,0x5c1120);std::fill_n(memory+0x3c5630,256*60,0);
            auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);world.room=1;s::SceneResources resources;auto records=std::make_shared<reo::native::gameplay_scene::Records>();s::ResourceCollisions collisions(resources,records);g::ResourceModels models;g::ResourceFrames frames(world,resources,models,nullptr,records,&templates);g::ResourceFactory factory(models,frames,templates,cache);const auto id=*resources.slot(3);const unsigned descriptor=0x3c5630+3*60;
            check(factory.place(id).status==g::ResourceModelStatus::unavailable&&models.available()==64);++placement_refusals;
            check(!factory.bind_scene(collisions,{},1)&&!factory.bind_scene(collisions,floors,2)&&factory.bind_scene(collisions,floors,1));
            const auto sync=[&](const s::SceneDescriptor& d){memory[descriptor]=d.active;memory[descriptor+1]=d.room;memory[descriptor+2]=d.instance_index;memory[descriptor+3]=d.kind;put(memory,descriptor+6,d.attachment_id);put(memory,descriptor+8,d.position);put(memory,descriptor+0x14,d.tilt);put(memory,descriptor+0x16,d.yaw);put(memory,descriptor+0x18,d.flags);put(memory,descriptor+0x28,d.ownership_tag);memory[descriptor+0x2b]=d.template_index;memory[descriptor+0x2c]=std::bit_cast<std::uint8_t>(d.shape_profile);memory[descriptor+0x2d]=std::bit_cast<std::uint8_t>(d.orientation_variant);const auto rng=session->random.state();put(memory,0x3244b0,rng.primary);put(memory,0x3244b8,rng.secondary);memory[0x2b8de8]=rng.observed;};
            const auto compare=[&](const g::ResourceModelCreated& result){
                const auto raw=get<unsigned>(memory,descriptor+28);check(result.status==g::ResourceModelStatus::completed&&raw&&result.model&&resources.get(id)->primary==result.model);const auto& model=*result.model;
                check(model.active==bool(memory[raw])&&model.visible==bool(memory[raw+1])&&model.content_id==get<std::uint16_t>(memory,raw+0x36)&&model.resource_slot==memory[raw+0x240]);
                check(model.flags==get<unsigned>(memory,raw+0x23c)&&model.draw_layer==memory[raw+0x241]);check(std::memcmp(&model.position,memory+raw+0x200,12)==0&&std::memcmp(model.angles.data(),memory+raw+0x21c,6)==0&&std::memcmp(&model.pose,memory+raw+0x1c0,64)==0);check(std::bit_cast<unsigned>(model.pulse_distance)==get<unsigned>(memory,raw+0x218)&&model.pulse_timer==get<std::int16_t>(memory,raw+0xe)&&model.pulse_packed==get<std::int16_t>(memory,raw+0x12));
                check(resources.get(id)->flags==get<unsigned>(memory,descriptor+24));const auto secondary=std::dynamic_pointer_cast<s::SceneRecordAttachment>(resources.get(id)->secondary);const auto original_secondary=get<unsigned>(memory,descriptor+32);check(bool(secondary)==bool(original_secondary));
                if(secondary){const auto node=records->acquire(secondary->identity());check(bool(node));const auto proxy=reo::native::gameplay_scene::collision_view(node->value);check(std::memcmp(proxy.bounds.data(),memory+original_secondary,32)==0&&proxy.lower==get<std::int32_t>(memory,original_secondary+32)&&proxy.upper==get<std::int32_t>(memory,original_secondary+36));}
                check(records->size()==128u-get<std::uint16_t>(memory,0x3b5150));const auto rng=session->random.state();check(rng.primary==get<std::uint16_t>(memory,0x3244b0)&&rng.secondary==get<std::uint16_t>(memory,0x3244b8)&&rng.observed==memory[0x2b8de8]);
            };
            unsigned selected{};
            for(unsigned row=0;row<templates.state().count;++row){
                const auto& metadata=templates.state().templates[row].encoded;const auto callback=std::to_integer<unsigned>(metadata[20]);if(callback!=0&&callback!=1&&callback!=3)continue;
                std::uint16_t content{};std::memcpy(&content,metadata.data()+18,2);if(content==0x75||content==0x135||content==0x1d||content==0x1c||content==0x3200||content==0x72)continue;const auto geometry=cache->find(std::bit_cast<std::int16_t>(content));if(geometry>=0&&!cache->roots()[unsigned(geometry)].admitted_parts)continue;
                const auto angle=std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(metadata[12]));const auto distance=std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(metadata[13]));if(angle<0||angle>=3||distance<0)continue;
                for(unsigned serial=0;serial<64;++serial){
                    auto d=*resources.get(id);d.active=1;d.room=1;d.instance_index=3;d.kind=std::uint8_t(serial&1);d.attachment_id=content;d.position={serial&2?100.25f:-100.75f,float(int(serial)-32)+.5f,100.5f};d.tilt=std::uint16_t(serial*1043);d.yaw=std::uint16_t(serial*2311);d.flags=std::array<unsigned,4>{0,0x200000,0x800,0x200800}[(serial/2)%4];d.ownership_tag=std::uint16_t(serial&4?1:0);d.template_index=std::uint8_t(row);d.shape_profile=std::int8_t(serial%20);d.orientation_variant=std::int8_t(serial/8);check(resources.replace(id,d)==s::SceneStatus::completed);sync(d);
                    const auto old=d.primary?std::dynamic_pointer_cast<g::ResourceModel>(d.primary):nullptr;const auto expected=call(memory,0x591620,{descriptor});const auto result=factory.place(id);check(GPR_U32(&expected,2)==get<unsigned>(memory,descriptor+28));compare(result);if(old)check(!old->current());++placement_cases;if(d.ownership_tag)++placement_owned;
                }
                ++selected;
            }
            check(selected>0);
            // Shared scene exhaustion leaves a valid primary and a known absent
            // secondary. These are actual allocations, not a full-result stub.
            auto d=*resources.get(id);records->clear();call(memory,0x5c1120);d.secondary.reset();d.ownership_tag=0;d.kind=1;d.flags=0x800;d.shape_profile=0;check(resources.replace(id,d)==s::SceneStatus::completed);put(memory,descriptor+32,0u);sync(d);
            for(unsigned i=0;i<128;++i){check(bool(records->create({})));const auto created=call(memory,0x5c11b0);check(GPR_U32(&created,2));}
            call(memory,0x591620,{descriptor});const auto scene_full=factory.place(id);compare(scene_full);check(!resources.get(id)->secondary&&records->size()==128);++placement_cases;++placement_full;
            // A genuinely full primary pool with no old primary returns failure
            // before collision construction, preserving the existing secondary.
            const auto identity=models.identity_of(*scene_full.model);check(models.retire(identity)==g::ResourceModelStatus::completed);call(memory,0x590d80,{get<unsigned>(memory,descriptor+28)});d=*resources.get(id);d.primary.reset();check(resources.replace(id,d)==s::SceneStatus::completed);put(memory,descriptor+28,0u);sync(d);
            for(unsigned i=0;i<64;++i){const auto expected=call(memory,0x591230,{d.attachment_id});const auto created=factory.create(d.attachment_id);check(GPR_U32(&expected,2)&&created.status==g::ResourceModelStatus::completed);}
            const auto expected_full=call(memory,0x591620,{descriptor});check(GPR_U32(&expected_full,2)==0&&factory.place(id).status==g::ResourceModelStatus::full&&!resources.get(id)->primary&&models.available()==0);++placement_full;
            world.room=2;const auto before=models.available();check(factory.place(id).status==g::ResourceModelStatus::unavailable);check(models.available()==before);++placement_refusals;
            s::SceneResources foreign;check(factory.place(*foreign.slot(3)).status==g::ResourceModelStatus::foreign_or_stale);++placement_refusals;
            check(models.close()==g::ResourceModelStatus::completed);records->clear();
        }
    }
    placement_floors=nullptr;
}
