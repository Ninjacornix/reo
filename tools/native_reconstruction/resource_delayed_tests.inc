unsigned delayed_constructors{},delayed_frames{},delayed_rebuilds{},delayed_refusals{},delayed_full_cases{};
namespace delayed_fixture {
namespace g=reo::native::gameplay_world;
constexpr unsigned descriptor=0x3c5630+3*60,pool=0x3f4010,stride=0x250;
struct Fixture {
    std::uint8_t* memory;
    std::shared_ptr<const g::ResourceStaticAssets> assets;
    std::shared_ptr<g::Session> session=std::make_shared<g::Session>();
    g::World world{{{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session};
    s::ResourceTemplates templates;
    s::SceneResources resources;
    std::shared_ptr<reo::native::gameplay_scene::Records> records=std::make_shared<reo::native::gameplay_scene::Records>();
    g::ResourceModels models;
    g::ResourceFrames frames{world,resources,models,nullptr,records,&templates};
    s::ResourceCollisions collisions{resources,records};
    g::ResourceFactory factory;
    std::shared_ptr<const reo::native::gameplay_collision::response::Grid> floors=placement_grid();
    Fixture(std::vector<std::uint8_t>& ram,const std::vector<std::byte>& nbd,const std::vector<std::byte>& encoded):memory(ram.data()),assets(g::ResourceStaticAssets::import_nbd(nbd)),factory(models,frames,templates,assets){
        check(templates.load(encoded));std::fill(ram.begin(),ram.end(),0);call(memory,0x5919f0);owned_constants(memory);put(memory,0x294e00,m::identity());unsigned offset{},length{};std::memcpy(&offset,nbd.data()+0x24,4);std::memcpy(&length,nbd.data()+0x28,4);std::memcpy(memory+0x100000,nbd.data()+offset,length);put(memory,0x32440c,0x400000u);call(memory,0x1d3100,{0x70000,0x100000});std::memcpy(memory+0x100000,encoded.data(),encoded.size());call(memory,0x5921d0,{0x100000});call(memory,0x590be0);call(memory,0x5c1120);world.room=1;put(memory,0x3243dc,std::uint16_t(1));check(factory.bind_scene(collisions,floors,1));placement_floors=floors.get();
    }
    unsigned address(const g::ResourceModelId& id)const{const auto slot=models.physical_slot(id);return slot?pool+stride**slot:0;}
    std::pair<g::ResourceModelCreated,unsigned> create(std::uint16_t content,std::int16_t ticks){const auto expected=call(memory,0x591400,{std::uint32_t(content)|0xabcd0000u,std::uint32_t(std::bit_cast<std::uint16_t>(ticks))|0x12340000u});auto result=factory.create_delayed(content,ticks);const auto raw=GPR_U32(&expected,2);check(result.status==g::ResourceModelStatus::completed&&raw==address(result.id));compare_model(*result.model,raw);++delayed_constructors;return{std::move(result),raw};}
    void compare_model(const g::ResourceModel& model,unsigned raw){
        check(model.active==bool(memory[raw])&&model.visible==bool(memory[raw+1])&&model.category==memory[raw+2]&&model.physical_slot==memory[raw+6]);check(model.content_id==get<std::uint16_t>(memory,raw+0x36)&&model.draw_tag==get<std::uint16_t>(memory,raw+0x238)&&model.asset_index==get<std::int16_t>(memory,raw+0x242));
        check(model.flags==get<unsigned>(memory,raw+0x23c)&&model.resource_slot==memory[raw+0x240]&&model.draw_layer==memory[raw+0x241]);check(model.program.elapsed==get<std::int16_t>(memory,raw+0x10));check(std::memcmp(&model.position,memory+raw+0x200,12)==0&&std::memcmp(&model.axis_scale,memory+raw+0x22c,12)==0&&std::memcmp(model.angles.data(),memory+raw+0x21c,6)==0&&std::memcmp(&model.pose,memory+raw+0x1c0,64)==0);check(std::memcmp(model.parts.data(),memory+raw+0x40,6*64)==0&&std::memcmp(model.part_enabled.data(),memory+raw+0x30,6)==0&&(&model.correction==&model.parts[5]));
    }
    void sync(const s::SceneDescriptor& d){
        check(resources.replace(*resources.slot(3),d)==s::SceneStatus::completed);memory[descriptor]=d.active;memory[descriptor+1]=d.room;memory[descriptor+2]=d.instance_index;memory[descriptor+3]=d.kind;put(memory,descriptor+6,d.attachment_id);put(memory,descriptor+8,d.position);put(memory,descriptor+0x14,d.tilt);put(memory,descriptor+0x16,d.yaw);put(memory,descriptor+24,d.flags);const auto primary=std::dynamic_pointer_cast<g::ResourceModel>(d.primary);put(memory,descriptor+28,primary?address(models.identity_of(*primary)):0u);put(memory,descriptor+40,d.ownership_tag);memory[descriptor+43]=d.template_index;memory[descriptor+44]=std::bit_cast<std::uint8_t>(d.shape_profile);memory[descriptor+45]=std::bit_cast<std::uint8_t>(d.orientation_variant);
    }
    void compare_world(){
        check(models.available()==get<std::uint16_t>(memory,0x3b5700));
        check(address(models.head())==get<unsigned>(memory,0x3b5708)&&address(models.tail())==get<unsigned>(memory,0x3b5710));
        for(auto id=models.head();id;id=models.next(id)){const auto raw=address(id);compare_model(*models.retain(id),raw);check(address(models.previous(id))==get<unsigned>(memory,raw+0x1c)&&address(models.next(id))==get<unsigned>(memory,raw+0x20));}
        const auto d=*resources.get(*resources.slot(3));check(d.flags==get<unsigned>(memory,descriptor+24));const auto primary=std::dynamic_pointer_cast<g::ResourceModel>(d.primary);check((primary?address(models.identity_of(*primary)):0u)==get<unsigned>(memory,descriptor+28));const auto secondary=std::dynamic_pointer_cast<s::SceneRecordAttachment>(d.secondary);const auto raw=get<unsigned>(memory,descriptor+32);check(bool(secondary)==bool(raw));
        if(secondary){const auto value=records->acquire(secondary->identity());check(bool(value));const auto proxy=reo::native::gameplay_scene::collision_view(value->value);check(std::memcmp(proxy.bounds.data(),memory+raw,32)==0&&proxy.lower==get<std::int32_t>(memory,raw+32)&&proxy.upper==get<std::int32_t>(memory,raw+36));}check(records->size()==128u-get<std::uint16_t>(memory,0x3b5150));
    }
};
}
void compare_resource_delayed(const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    using namespace delayed_fixture;
    const auto assets=factory_load(static_path,16),banks=factory_load(template_path,5);
    {
        Fixture q(ram,assets[0],banks[0]);
        for(unsigned mode:{0u,1u,2u,255u}){q.session->clock_mode=std::uint8_t(mode);q.memory[0x3243cc]=std::uint8_t(mode);
            for(unsigned bits=0;bits<65536;++bits){const auto content=std::array<std::uint16_t,4>{0,205,0x75,65535}[bits%4];const auto [created,raw]=q.create(content,std::bit_cast<std::int16_t>(std::uint16_t(bits)));call(q.memory,0x590d80,{raw});check(q.models.retire(created.id)==g::ResourceModelStatus::completed&&!created.model->current());}
        }
        q.session->clock_mode=0;q.memory[0x3243cc]=0;const auto [current,raw]=q.create(0,0);current.model->resource_slot=3;q.memory[raw+0x240]=3;
        for(unsigned bits=0;bits<65536;++bits){current.model->program.elapsed=std::bit_cast<std::int16_t>(std::uint16_t(bits));put(q.memory,raw+0x10,current.model->program.elapsed);current.model->active=bool(bits&1);q.memory[raw]=std::uint8_t(bits&1);current.model->visible=true;q.memory[raw+1]=1;call(q.memory,0x593550,{raw});current.model->work->update(q.models,current.id,*current.model);q.compare_model(*current.model,raw);++delayed_frames;}
    }
    // Full callbacks execute inside the actual mutation-sensitive model pass.
    // Primary may be this node, a different node, or known absent.
    for(bool active:{false,true})for(bool room:{false,true})for(unsigned owner:{0u,1u,5u})for(bool flag:{false,true})for(bool kind:{false,true})for(bool secondary:{false,true})for(unsigned primary=0;primary<3;++primary){
        Fixture q(ram,assets[0],banks[0]);std::uint16_t content{};std::uint8_t index{};bool found{};
        for(unsigned row=0;row<q.templates.state().count;++row){const auto& data=q.templates.state().templates[row].encoded;std::uint16_t candidate{};std::memcpy(&candidate,data.data()+18,2);const auto callback=std::to_integer<unsigned>(data[20]);if((callback==0||callback==1)&&candidate!=0x75&&candidate!=0x135&&candidate!=0x1d&&candidate!=0x1c&&candidate!=0x3200&&candidate!=0x72){content=candidate;index=std::uint8_t(row);found=true;break;}}check(found);
        g::ResourceModelCreated other;
        if(primary==1){const auto original=call(q.memory,0x591230,{content});other=q.factory.create(content);check(other.status==g::ResourceModelStatus::completed&&GPR_U32(&original,2)==q.address(other.id));}
        const auto [current,raw]=q.create(content,1);current.model->resource_slot=3;current.model->visible=true;q.memory[raw+0x240]=3;q.memory[raw+1]=1;
        s::SceneDescriptor d;d.active=std::uint8_t(active);d.room=room?1:2;d.instance_index=3;d.kind=std::uint8_t(kind);d.attachment_id=content;d.position={100.25f,-4,200.5f};d.yaw=12345;d.tilt=4321;d.flags=flag?0x200000u:0;d.ownership_tag=std::uint16_t(owner);d.template_index=index;d.shape_profile=1;d.orientation_variant=0;d.primary=primary==0?current.model:primary==1?other.model:nullptr;q.sync(d);
        std::shared_ptr<s::SceneRecordAttachment> held_secondary;
        if(secondary){call(q.memory,0x591860,{descriptor});const auto created=q.collisions.replace(*q.resources.slot(3));check(created.status==s::ResourceCollisionStatus::completed);held_secondary=created.attachment;}
        call(q.memory,0x590ea0);const auto pass=q.models.update(false);check(pass.status==g::ResourceModelStatus::completed);q.compare_world();++delayed_frames;
        const bool rebuilt=active&&room&&!owner;if(rebuilt)++delayed_rebuilds;check(current.model->current()==!(rebuilt&&primary==0));if(held_secondary)check(held_secondary->current()!=rebuilt);
    }
    {
        Fixture q(ram,assets[0],banks[0]);const auto [current,raw]=q.create(0,1);current.model->resource_slot=3;q.memory[raw+0x240]=3;s::SceneDescriptor d;d.active=1;d.room=1;d.instance_index=3;d.kind=1;d.template_index=0;d.flags=0x200000;d.position={10,0,20};q.sync(d);
        for(unsigned i=0;i<63;++i){const auto expected=call(q.memory,0x591230,{0});const auto created=q.factory.create(0);check(created.status==g::ResourceModelStatus::completed&&GPR_U32(&expected,2)==q.address(created.id));}
        const auto full=call(q.memory,0x591400,{0,1});check(GPR_U32(&full,2)==0&&q.factory.create_delayed(0,1).status==g::ResourceModelStatus::full);++delayed_full_cases;
        call(q.memory,0x590ea0);const auto pass=q.models.update(false);check(pass.status==g::ResourceModelStatus::completed&&pass.called==64);q.compare_world();check(!q.resources.get(*q.resources.slot(3))->primary&&q.resources.get(*q.resources.slot(3))->secondary);++delayed_frames;++delayed_full_cases;
    }
    {
        Fixture q(ram,assets[0],banks[0]);const auto [current,raw]=q.create(0,1);current.model->resource_slot=3;q.memory[raw+0x240]=3;s::SceneDescriptor d;d.active=1;d.room=1;d.instance_index=3;d.kind=1;d.template_index=0;d.flags=0x200000;d.position={10,0,20};d.primary=current.model;q.sync(d);
        for(unsigned i=0;i<128;++i){check(bool(q.records->create({})));const auto created=call(q.memory,0x5c11b0);check(GPR_U32(&created,2));}
        call(q.memory,0x590ea0);const auto pass=q.models.update(false);check(pass.status==g::ResourceModelStatus::completed);q.compare_world();check(!current.model->current()&&q.resources.get(*q.resources.slot(3))->primary&&!q.resources.get(*q.resources.slot(3))->secondary);++delayed_frames;++delayed_full_cases;
    }
    {
        Fixture q(ram,assets[0],banks[0]);auto other_factory=std::make_unique<g::ResourceFactory>(q.models,q.frames,q.templates,q.assets);const auto created=other_factory->create_delayed(0,3);check(created.status==g::ResourceModelStatus::completed);const auto work=created.model->work;other_factory.reset();bool refused{};try{work->update(q.models,created.id,*created.model);}catch(const std::runtime_error&){refused=true;}check(refused&&created.model->program.elapsed==3);++delayed_refusals;
        g::ResourceModels foreign;const auto good=q.factory.create_delayed(0,5);refused=false;try{good.model->work->update(foreign,good.id,*good.model);}catch(const std::runtime_error&){refused=true;}check(refused&&good.model->program.elapsed==5);++delayed_refusals;
        check(q.world.close()==g::Status::completed);check(q.factory.create_delayed(0,1).status==g::ResourceModelStatus::closed);++delayed_refusals;
    }
    placement_floors=nullptr;
}
