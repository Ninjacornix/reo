unsigned resource_actions{},resource_action_retirements{},resource_action_failures{};
void compare_resource_actions(const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    using namespace delayed_fixture;
    const auto assets=factory_load(static_path,16),banks=factory_load(template_path,5);
    for(bool active:{false,true})for(bool kind:{false,true})for(bool room:{false,true})for(unsigned owner:{0u,1u,5u})for(bool primary:{false,true})for(bool secondary:{false,true}){
        Fixture q(ram,assets[0],banks[0]);s::SceneDescriptor d;d.active=std::uint8_t(active);d.kind=std::uint8_t(kind);d.room=room?1:2;d.instance_index=3;d.authored_id=42;d.attachment_id=0;d.template_index=std::bit_cast<std::uint8_t>(q.templates.selector(0));d.flags=0x20000000u;d.ownership_tag=std::uint16_t(owner);d.position={100.5f,-7.25f,200.75f};d.yaw=1234;d.shape_profile=2;
        if(primary){const auto expected=call(q.memory,0x591230,{0});const auto created=q.factory.create(0);check(created.status==g::ResourceModelStatus::completed&&GPR_U32(&expected,2)==q.address(created.id));d.primary=created.model;}q.sync(d);put(q.memory,descriptor+4,std::uint16_t(42));
        if(secondary){call(q.memory,0x591860,{descriptor});check(q.collisions.replace(*q.resources.slot(3)).status==s::ResourceCollisionStatus::completed);}
        const std::array<unsigned,4> entries{0x592960,0x592b00,0x592b90,0x592a10};const std::array<s::SceneCommand,4> commands{s::SceneCommand::enable,s::SceneCommand::force_enable,s::SceneCommand::alternate_enable,s::SceneCommand::disable};
        for(unsigned i=0;i<4;++i){call(q.memory,entries[i],{42});check(q.resources.command(*q.resources.slot(3),commands[i],q.world.room,&q.factory)==s::SceneStatus::completed);q.compare_world();++resource_actions;}
        put(q.memory,0x743128,unsigned(q.resources.active_count()));call(q.memory,0x591be0,{3});check(q.factory.apply(q.resources,*q.resources.slot(3),s::SceneEffect::retire_instance,3)==s::SceneStatus::completed);q.compare_world();check(q.resources.active_count()==get<unsigned>(q.memory,0x743128));++resource_action_retirements;
    }
    {
        Fixture q(ram,assets[0],banks[0]);const auto id=*q.resources.slot(3);s::SceneDescriptor d;d.active=d.kind=d.room=1;d.instance_index=3;d.template_index=std::bit_cast<std::uint8_t>(q.templates.selector(0));q.sync(d);g::ResourceFactory unbound(q.models,q.frames,q.templates,q.assets);
        check(q.resources.command(id,s::SceneCommand::enable,1,&unbound)==s::SceneStatus::provider_unavailable);check((q.resources.get(id)->flags&1)&&!q.resources.get(id)->primary&&q.models.available()==64);++resource_action_failures;
        d=*q.resources.get(id);d.attachment_id=0x75;check(q.resources.replace(id,d)==s::SceneStatus::completed);check(q.resources.command(id,s::SceneCommand::force_enable,1,&q.factory)==s::SceneStatus::provider_unavailable&&!q.resources.get(id)->primary&&q.models.available()==64);++resource_action_failures;
        d.attachment_id=0;const auto created=q.factory.create(0);check(created.status==g::ResourceModelStatus::completed);d.primary=created.model;d.secondary=std::make_shared<s::SceneAttachment>();d.flags=0x200001;check(q.resources.replace(id,d)==s::SceneStatus::completed);check(q.resources.command(id,s::SceneCommand::disable,1,&q.factory)==s::SceneStatus::provider_unavailable);check(created.model->current()&&!(q.resources.get(id)->flags&0x200001u));++resource_action_failures;
        s::SceneResources foreign;check(q.factory.apply(foreign,*foreign.slot(3),s::SceneEffect::construct_primary,3)==s::SceneStatus::invalid_identity);++resource_action_failures;
    }
    placement_floors=nullptr;
}
