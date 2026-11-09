#include "game/native/gameplay_world/inventory.hpp"
unsigned inventory_lookups{},inventory_removals{},inventory_compactions{},inventory_insertions{},inventory_detachments{},inventory_refusals{};
namespace inventory_fixture {
constexpr unsigned actor_base=0x4a5c30;
void export_actor(std::uint8_t* memory,const reo::native::gameplay_world::Actor& actor,unsigned slot=0){const auto raw=actor_base+0x10e0*slot;memory[raw+0xb98]=actor.character;memory[raw+0xc7c]=actor.selected_resource;memory[raw+0xc7d]=actor.secondary_equipped_resource;put(memory,raw+0xca8,actor.resource_action);std::memcpy(memory+raw+0xc84,actor.inventory.carried.data(),4);std::memcpy(memory+raw+0xc88,actor.inventory.storage.data(),32);}
void compare_actor(const std::uint8_t* memory,const reo::native::gameplay_world::Actor& actor,unsigned slot=0){const auto raw=actor_base+0x10e0*slot;check(std::memcmp(actor.inventory.carried.data(),memory+raw+0xc84,4)==0&&std::memcmp(actor.inventory.storage.data(),memory+raw+0xc88,32)==0);check(actor.selected_resource==memory[raw+0xc7c]&&actor.secondary_equipped_resource==memory[raw+0xc7d]&&actor.resource_action==get<std::uint16_t>(memory,raw+0xca8));}
}
void compare_resource_inventory(const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    using namespace delayed_fixture;using namespace inventory_fixture;
    const auto assets=factory_load(static_path,16);auto banks=factory_load(template_path,5);std::vector<std::byte> controlled(32+3*24);const auto write=[&]<class T>(unsigned at,T value){std::memcpy(controlled.data()+at,&value,sizeof value);};write(0,3u);write(4,3u);write(16,32u);for(unsigned i=0;i<3;++i){write(32+24*i,i==1?0u:0x20000u);write(32+24*i+18,std::uint16_t(i+1));}banks.push_back(controlled);
    for(const auto& encoded:banks){
        Fixture q(ram,assets[0],encoded);g::WorldInventory inventory(q.world,q.resources,q.templates,q.frames);const auto id=q.world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(id));const auto actor=q.world.resolve(id);
        for(unsigned i=0;i<256;++i){s::SceneDescriptor d;d.active=std::uint8_t(i%3?1:0);d.instance_index=std::uint8_t(i);d.template_index=std::uint8_t(i%q.templates.state().count);d.attachment_id=std::uint16_t(i%4==1?0x12c:i%4==2?0x12d:i%4==3?0x12e:42);check(bool(q.resources.load(i,d)));const auto raw=0x3c5630+60*i;q.memory[raw]=d.active;q.memory[raw+2]=d.instance_index;q.memory[raw+43]=d.template_index;put(q.memory,raw+6,d.attachment_id);}
        for(unsigned serial=0;serial<4096;++serial){
            actor->character=std::uint8_t(serial%7);actor->selected_resource=17;actor->secondary_equipped_resource=23;actor->resource_action=1234;
            for(unsigned i=0;i<4;++i)actor->inventory.carried[i]=std::uint8_t((serial>>(3*i))&7u);
            for(unsigned i=0;i<32;++i){actor->inventory.storage[i]=std::uint8_t(i%5?(serial*17+i*19)%256:0);}
            actor->inventory.storage[0]=165;export_actor(q.memory,*actor);
            call(q.memory,0x5f2330,{actor_base});inventory.compact(id);compare_actor(q.memory,*actor);++inventory_compactions;
            if(serial<256)for(unsigned requested=0;requested<256;++requested){const auto expected=call(q.memory,0x5f22c0,{actor_base,requested|0xabcd0000u});check(inventory.find(id,std::uint8_t(requested))==std::uint8_t(GPR_U32(&expected,2)));++inventory_lookups;}
            const auto removed=call(q.memory,0x5f2120,{actor_base,serial|0x12340000u});check(inventory.remove(id,std::uint8_t(serial))==(GPR_U32(&removed,2)==0));compare_actor(q.memory,*actor);++inventory_removals;
            const auto item=std::uint8_t(serial*197+31);call(q.memory,0x5f27b0,{actor_base,item});inventory.insert(id,item);compare_actor(q.memory,*actor);++inventory_insertions;
        }
        actor->character=7;
        for(unsigned a=0;a<10;++a)for(unsigned b=0;b<10;++b)for(unsigned c=0;c<10;++c){
            actor->inventory.carried={1,2,1,4};actor->inventory.storage.fill(0);actor->inventory.storage[0]=170;actor->inventory.storage[29]=201;actor->inventory.storage[30]=202;actor->inventory.storage[31]=203;unsigned index=1;for(unsigned i=0;i<a;++i)actor->inventory.storage[index++]=1;for(unsigned i=0;i<b;++i)actor->inventory.storage[index++]=2;for(unsigned i=0;i<c;++i)actor->inventory.storage[index++]=3;while(index<29){actor->inventory.storage[index]=std::uint8_t(index%2?4:8);++index;}export_actor(q.memory,*actor);
            call(q.memory,0x5f2330,{actor_base});inventory.compact(id);compare_actor(q.memory,*actor);++inventory_compactions;
        }
        actor->inventory.carried={1,2,1,0};actor->inventory.storage.fill(1);actor->character=7;const auto old=actor->inventory.storage;check(inventory.refresh(q.resources,id)==s::SceneStatus::provider_unavailable&&actor->inventory.storage==old);++inventory_refusals;
    }
    // Actual opcode35 helper: release, resolve the canonical primary actor,
    // remove its item, refresh its inventory, and deactivate the same descriptor.
    for(unsigned slot=0;slot<4;++slot)for(unsigned location=0;location<3;++location)for(bool selected:{false,true})for(bool second:{false,true})for(bool primary:{false,true})for(bool secondary:{false,true}){
        Fixture q(ram,assets[0],banks[0]);g::WorldInventory inventory(q.world,q.resources,q.templates,q.frames);const auto entity=q.world.spawn_primary(slot,std::make_unique<g::Actor>()).id;check(bool(entity));const auto actor=q.world.resolve(entity);actor->character=0;actor->selected_resource=selected?3:9;actor->secondary_equipped_resource=second?3:8;actor->resource_action=1234;actor->inventory.carried={4,0,4,2};actor->inventory.storage[0]=7;actor->inventory.storage[4]=6;if(location==0)actor->inventory.carried[1]=3;else if(location==1)actor->inventory.storage[27]=3;export_actor(q.memory,*actor,slot);
        s::SceneDescriptor d;d.active=d.kind=d.room=1;d.instance_index=3;d.attachment_id=42;d.template_index=std::bit_cast<std::uint8_t>(q.templates.selector(0));d.flags=0x20001;d.ownership_tag=std::uint16_t(slot+1);d.position={10,0,20};
        if(primary){const auto original=call(q.memory,0x591230,{0});const auto created=q.factory.create(0);check(created.status==g::ResourceModelStatus::completed&&GPR_U32(&original,2)==q.address(created.id));d.primary=created.model;}q.sync(d);
        if(secondary){call(q.memory,0x591860,{descriptor});check(q.collisions.replace(*q.resources.slot(3)).status==s::ResourceCollisionStatus::completed);}
        put(q.memory,0x743128,unsigned(q.resources.active_count()));const auto attached=q.resources.lookup_attached(42);check(bool(attached));call(q.memory,0x592ca0,{42});check(q.resources.detach(*attached,&q.factory,&inventory)==s::SceneStatus::completed);compare_actor(q.memory,*actor,slot);q.compare_world();check(q.resources.active_count()==get<unsigned>(q.memory,0x743128));++inventory_detachments;
    }
    {
        Fixture q(ram,assets[0],banks[0]);g::WorldInventory inventory(q.world,q.resources,q.templates,q.frames);const auto entity=q.world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto actor=q.world.resolve(entity);actor->character=7;actor->inventory.carried={3,4,0,0};actor->inventory.storage.fill(1);s::SceneDescriptor herb;herb.active=1;herb.attachment_id=0x12c;check(bool(q.resources.load(1,herb)));s::SceneDescriptor target;target.active=target.kind=target.room=1;target.instance_index=3;target.attachment_id=42;target.flags=1;target.ownership_tag=1;check(q.resources.replace(*q.resources.slot(3),target)==s::SceneStatus::completed);const auto attached=q.resources.lookup_attached(42);check(bool(attached));check(q.resources.detach(*attached,&q.factory,&inventory)==s::SceneStatus::provider_unavailable);check(q.resources.get(attached->id)->active==1&&std::find(actor->inventory.carried.begin(),actor->inventory.carried.end(),3)==actor->inventory.carried.end());++inventory_refusals;
    }
    {
        Fixture q(ram,assets[0],banks[0]);g::WorldInventory inventory(q.world,q.resources,q.templates,q.frames);check(!inventory.resolve({s::SceneOwnerFamily::extended,0})&&!inventory.resolve({s::SceneOwnerFamily::primary,4}));++inventory_refusals;
        const auto id=q.world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto held=q.world.resolve(id);check(inventory.resolve({s::SceneOwnerFamily::primary,0})==id);check(q.world.retire_primary(0)==g::actors::EntityStatus::completed&&inventory.refresh(q.resources,id)==s::SceneStatus::provider_unavailable);++inventory_refusals;
        s::SceneResources foreign;check(inventory.detach(foreign,id,3)==s::SceneStatus::invalid_identity);++inventory_refusals;check(bool(held));
        bool rejected{};try{g::WorldInventory invalid(q.world,foreign,q.templates,q.frames);}catch(const std::invalid_argument&){rejected=true;}check(rejected);++inventory_refusals;
        check(q.world.close()==g::Status::completed&&!inventory.resolve({s::SceneOwnerFamily::primary,0}));++inventory_refusals;
    }
    placement_floors=nullptr;
}
