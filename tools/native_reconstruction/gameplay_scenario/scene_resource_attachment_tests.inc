namespace {
std::vector<std::tuple<unsigned,std::uint32_t,std::uint32_t>> attachment_events;
unsigned skipped_groups{};
struct EntityFixture final:reo::native::gameplay_actors::Entity {};
struct OwnerEffects final:vm::SceneOwners{
    reo::native::gameplay_actors::EntityId entity;
    std::uint32_t selected{};
    vm::SceneResourceId resource;
    std::vector<std::tuple<unsigned,std::uint32_t,std::uint32_t>> events;
    std::optional<reo::native::gameplay_actors::EntityId> resolve(vm::SceneOwnerReference owner)noexcept override{
        selected=owner.family==vm::SceneOwnerFamily::primary?owner.index:owner.index+4u;
        if(owner.family==vm::SceneOwnerFamily::extended)events.emplace_back(0,owner.index,0);
        return entity;
    }
    void detach(vm::SceneResources& resources,const reo::native::gameplay_actors::EntityId& id,std::uint8_t index)noexcept override{
        if(id!=entity)std::terminate();
        events.emplace_back(2,selected,index);
        if(mutate_instance_indices){auto d=*resources.get(resource);d.instance_index=23;resources.replace(resource,d);}
    }
    void refresh(vm::SceneResources& resources,const reo::native::gameplay_actors::EntityId& id)noexcept override{
        if(id!=entity)std::terminate();
        events.emplace_back(3,selected,0);
        if(mutate_instance_indices){auto d=*resources.get(resource);d.instance_index=29;resources.replace(resource,d);}
    }
};
unsigned original_owner(std::uint32_t address){return address>=0x600000?(address-0x600000)/0x100+4:(address-0x4a5c30)/0x10e0;}
void attachment_tests(){
    std::vector<std::uint8_t> ram(0x800000);vm::SceneResources resources;vm::SceneDescriptor d;d.authored_id=42;d.attachment_id=19;d.instance_index=251;
    const auto id=*resources.load(100,d);
    // Attached lookup uses a DIFFERENT authored halfword and eligibility from
    // plain descriptor lookup. Negative signed IDs cannot equal unsigned IDs.
    for(const auto active:{0u,255u})for(const auto flags:{0u,1u,0xffffffffu})for(const auto tag:{0u,1u,4u,5u,65535u})for(const auto authored:{-1,0,19,42,32767}){
        d.active=std::uint8_t(active);d.flags=flags;d.ownership_tag=std::uint16_t(tag);resources.replace(id,d);export_descriptor(ram,d);
        R5900Context c;PS2Runtime runtime;SET_GPR_S32(&c,4,authored);SET_GPR_U32(&c,5,0x10000);SET_GPR_U32(&c,31,0xdeadbeef);fixture_write<std::uint16_t>(ram.data(),0x10000,0xabcdu);
        o2_005B4A50_0x5b4a50(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++invocations;const auto attached=resources.lookup_attached(std::int16_t(authored));
        check(bool(attached)==(GPR_U32(&c,2)!=0));
        if(attached){check(attached->id==id);const auto owner=fixture_read<std::uint16_t>(ram.data(),0x10000);check((attached->owner.family==vm::SceneOwnerFamily::primary?attached->owner.index:attached->owner.index+4)==owner);}
        else check(fixture_read<std::uint16_t>(ram.data(),0x10000)==0xabcd);
    }
    reo::native::gameplay_actors::EntityStore actors;
    const auto entity=actors.create(std::make_unique<EntityFixture>());check(entity.status==reo::native::gameplay_actors::EntityStatus::completed);
    for(const auto tag:{1u,4u,5u,7u,65535u})for(bool primary:{false,true}){
        d.active=255;d.flags=1;d.ownership_tag=std::uint16_t(tag);d.primary=primary?std::make_shared<Attachment>():nullptr;resources.replace(id,d);export_descriptor(ram,d);
        original_effects.clear();attachment_events.clear();call(o2_00592CA0_0x592ca0,ram,19);
        Effects effects;effects.events.reserve(4);OwnerEffects owners;owners.entity=entity.id;owners.events.reserve(5);
        check(resources.detach(*resources.lookup_attached(19),&effects,&owners)==vm::SceneStatus::completed);
        // Actor resolution is a native provider, so compare the original
        // selection/effect transcript rather than casting an address to ID.
        check(owners.events==attachment_events);check(effects.events==original_effects);
        check(resources.get(id)->flags==fixture_read<std::uint32_t>(ram.data(),descriptor+24));
    }
    // Preserve rereads across external effects: release changes the instance
    // byte before detach; detach/refresh change it before final retirement.
    mutate_instance_indices=true;d.active=1;d.flags=1;d.ownership_tag=1;d.primary=std::make_shared<Attachment>();d.instance_index=251;resources.replace(id,d);export_descriptor(ram,d);
    original_effects.clear();attachment_events.clear();call(o2_00592CA0_0x592ca0,ram,19);
    Effects mutating_effects;mutating_effects.events.reserve(4);OwnerEffects mutating_owners;mutating_owners.entity=entity.id;mutating_owners.resource=id;mutating_owners.events.reserve(5);
    check(resources.detach(*resources.lookup_attached(19),&mutating_effects,&mutating_owners)==vm::SceneStatus::completed);
    check(mutating_effects.events==original_effects);check(mutating_owners.events==attachment_events);check(resources.get(id)->instance_index==ram[descriptor+2]);check(ram[descriptor+2]==29);
    mutate_instance_indices=false;
    std::memcpy(ram.data()+0x740890,original_signed_comparisons.data(),24);
    for(const auto actual:{-32768,-1,0,1,32767})for(const auto expected:{-32768,-1,0,1,32767})for(const auto operation:{-32768,-1,0,1,2,3,4,5,6,32767})for(bool eligible:{false,true}){
        d.active=255;d.flags=eligible?1:0;d.ownership_tag=1;d.parameter=std::int16_t(actual);resources.replace(id,d);export_descriptor(ram,d);
        fixture_write<std::int16_t>(ram.data(),0x10000,19);fixture_write<std::int16_t>(ram.data(),0x10004,std::int16_t(expected));fixture_write<std::int16_t>(ram.data(),0x10008,std::int16_t(operation));
        fixture_write<std::uint32_t>(ram.data(),0x4bad58,0xabcdu);skipped_groups=0;
        const auto result=call(o2_0068D780_0x68d780,ram,0x10000);const auto native=resources.compare_attached(19,std::int16_t(expected),std::int16_t(operation));
        check((result==0)==native);check(skipped_groups==(native?0u:1u));check(fixture_read<std::uint32_t>(ram.data(),0x4bad58)==0xabcd);
    }
}
}
void o2_00682F80_0x682f80(std::uint8_t*,R5900Context* c,PS2Runtime*){
    const auto extended=GPR_U32(c,4);attachment_events.emplace_back(0,extended,0);SET_GPR_U32(c,2,0x600000+extended*0x100);done(c);
}
void o2_005F2180_0x5f2180(std::uint8_t* r,R5900Context* c,PS2Runtime*){attachment_events.emplace_back(2,original_owner(GPR_U32(c,4)),GPR_U32(c,5));if(mutate_instance_indices)r[descriptor+2]=23;done(c);}
void o2_005F2330_0x5f2330(std::uint8_t* r,R5900Context* c,PS2Runtime*){attachment_events.emplace_back(3,original_owner(GPR_U32(c,4)),0);if(mutate_instance_indices)r[descriptor+2]=29;done(c);}
void o2_00591BE0_0x591be0(std::uint8_t* r,R5900Context* c,PS2Runtime*){effect(r,c,vm::SceneEffect::retire_instance);}
void o2_0068C9E0_0x68c9e0(std::uint8_t*,R5900Context* c,PS2Runtime*){++skipped_groups;done(c);}
