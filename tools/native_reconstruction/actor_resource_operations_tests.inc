#include "game/native/gameplay_world/actor_resource_operations.hpp"
#include "game/native/gameplay_world/animation_primitives.hpp"
unsigned actor_operation_cases{},actor_operation_live{},actor_operation_gates{},actor_operation_refusals{},actor_operation_transfer_mask{};
unsigned actor_operation_publications{};
namespace actor_operation_fixture {
using namespace ownership_fixture;
void export_notice(Fixture& q,const g::Actor& actor,unsigned slot){const auto at=0x4a5c30+0x10e0*slot;put(q.memory,at+0xd92,actor.pending_notice);q.memory[at+0xda2]=actor.equipment_notice_slot;q.memory[at+0xda3]=actor.equipment_notice_peer;q.memory[at+0xda4]=actor.equipment_notice_parameter;}
void compare_actor(Fixture& q,const g::Actor& actor,unsigned slot){inventory_fixture::compare_actor(q.memory,actor,slot);const auto at=0x4a5c30+0x10e0*slot;check(actor.pending_notice==get<std::uint16_t>(q.memory,at+0xd92)&&actor.equipment_notice_slot==q.memory[at+0xda2]&&actor.equipment_notice_peer==q.memory[at+0xda3]&&actor.equipment_notice_parameter==q.memory[at+0xda4]);}
std::int8_t compare(Consuming& f,g::ActorResourceOperations& owner,unsigned method,unsigned actor,unsigned mode,unsigned first,unsigned second,unsigned amount){
    const auto source=call(f.q.memory,method==0?0x5f4fe0:method==1?0x5f5c50:0x5f6a80,{0x4a5c30+0x10e0*actor,mode,first,second,amount});const auto id=f.q.world.identity(actor);const auto actual=method==0?owner.transfer_quantity(id,mode,first,second,amount):method==1?owner.release_instances(id,mode,first):owner.remap_content(id,mode,first);
    if(actual!=std::int8_t(GPR_U32(&source,2))){throw std::runtime_error("Actor resource operation method="+std::to_string(method)+" native="+std::to_string(actual)+" source="+std::to_string(std::int8_t(GPR_U32(&source,2))));}
    if(method==0){check(actual==-1||(actual>=0&&actual<=3));actor_operation_transfer_mask|=1u<<(actual==-1?4:unsigned(actual));}
    return actual;
}
struct NoticeServices final:g::Services {
    g::ActorResourceOperations& operations;g::actors::EntityId identity;unsigned writers;bool fail;
    std::uint16_t published{};unsigned calls{};
    NoticeServices(g::ActorResourceOperations& value,g::actors::EntityId id,unsigned selected,bool failure):operations(value),identity(id),writers(selected),fail(failure){}
    void begin_offline_frame(g::World&)override{}
    void run(g::Stage stage,g::World& world,g::Actor& actor)override{
        if(stage==g::Stage::update_behavior){check(actor.pending_notice==0);if(writers&1)g::animation_events::notify_equipment_selection(actor,world.selected_actor);if(writers&2)check(operations.release_instances(identity,2,3)==1);}
        if(stage==g::Stage::publish_notice){published=actor.pending_notice;++calls;++actor_operation_publications;if(fail)throw std::runtime_error("Declared notice delivery unavailable");}
    }
    bool remote_motion(g::World&,g::Actor&)override{return false;}
    bool find_grid(g::World&,g::Actor&,std::int8_t&)override{return false;}
    void switch_grid(g::World&,std::int32_t,std::int32_t)override{}
    float grid_response(g::World&,std::uint8_t)override{throw std::runtime_error("Unreached notice test grid response");}
};
}
void compare_actor_resource_operations(const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    using namespace actor_operation_fixture;const auto assets=factory_load(static_path,16);auto banks=factory_load(template_path,5);std::vector<std::byte> controlled(32+4*24+24);const auto write=[&]<class T>(unsigned at,T value){std::memcpy(controlled.data()+at,&value,sizeof value);};write(0,3u);write(4,4u);write(8,12u);write(16,32u);write(28,128u);
    for(unsigned row=0;row<4;++row){write(32+24*row,0x100001u);write(32+24*row+4,std::int16_t(3*row));write(32+24*row+6,std::int16_t(1));write(32+24*row+8,std::int16_t(20));write(32+24*row+18,std::uint16_t(42+row));write(128+6*row,std::int16_t(10));write(128+6*row+2,std::int16_t(99));write(128+6*row+4,std::array<std::int16_t,4>{1,0xb,0xc,0xd}[row]);}banks.push_back(controlled);
    for(const auto& bank:banks){Consuming f(ram,assets[0],bank);g::ActorResourceOperations owner(f.recipes);
        for(unsigned method=0;method<3;++method)for(unsigned n=0;n<65536;++n){
            s::SceneDescriptor a,b,c;a.active=std::uint8_t(n%5?1+n%255:0);b.active=std::uint8_t(n%7?128:0);c.active=1;a.instance_index=std::uint8_t(n%11?3:6);b.instance_index=std::uint8_t(n%13?4:6);c.instance_index=6;a.ownership_tag=std::uint16_t(n%5);b.ownership_tag=std::uint16_t((n/5)%5);c.ownership_tag=1;a.template_index=n%17?std::uint8_t(n%f.q.templates.state().count):255;b.template_index=std::uint8_t((n/7)%f.q.templates.state().count);c.template_index=0;a.parameter=std::bit_cast<std::int16_t>(std::uint16_t(n*65521u));b.parameter=std::bit_cast<std::int16_t>(std::uint16_t(n));c.parameter=17;a.attachment_id=method==2?std::array<std::uint16_t,4>{0,1,0xb,0xc}[n%4]:42;b.attachment_id=10;c.attachment_id=0x199;a.flags=n*1664525u;b.flags=n*1013904223u;c.flags=0x12300;sync_full(f.q,3,a);sync_full(f.q,4,b);sync_full(f.q,6,c);
            const auto index=n%4;for(unsigned slot=0;slot<4;++slot){const auto actor=f.q.world.primary(slot);actor->inventory={};actor->inventory.carried={3,4,3,0};actor->inventory.storage[(n/4)%32]=6;actor->selected_resource=std::uint8_t(n&1?3:4);actor->secondary_equipped_resource=std::uint8_t(n&2?4:3);actor->resource_action=123;actor->pending_notice=std::uint16_t(n*257u);actor->equipment_notice_slot=71;actor->equipment_notice_peer=83;actor->equipment_notice_parameter=97;f.actor(slot,std::uint8_t(n%3),std::uint8_t(n%8));actor->slot=std::uint8_t(n*17u);f.q.memory[0x4a5c30+0x10e0*slot+3]=actor->slot;export_notice(f.q,*actor,slot);}f.q.world.selected_actor=std::uint8_t(n/16);f.q.memory[0x4baded]=f.q.world.selected_actor;put(f.q.memory,0x743128,unsigned(f.q.resources.active_count()));
            (void)compare(f,owner,method,index,0xabcd0000u|std::uint8_t(n>>8),0x12340003,0x98760000u|std::uint32_t(n%29?4:3),0x24680000u|std::uint16_t(n*8191u));compare_full(f.q,3);compare_full(f.q,4);compare_full(f.q,6);for(unsigned slot=0;slot<4;++slot)compare_actor(f.q,*f.q.world.primary(slot),slot);check(f.q.resources.active_count()==get<unsigned>(f.q.memory,0x743128));++actor_operation_cases;
        }
    }
    // The full locality-mode/category cross product is independent of resource
    // policy. Inactive inputs distinguish gate rejection, handled0 and release1.
    {
        Consuming f(ram,assets[0],controlled);g::ActorResourceOperations owner(f.recipes);s::SceneDescriptor inactive;inactive.instance_index=3;sync_full(f.q,3,inactive);
        for(unsigned method=0;method<3;++method)for(unsigned mode=0;mode<256;++mode)for(unsigned category=0;category<256;++category)for(bool local:{false,true}){
            const auto actor=f.q.world.primary(0);actor->selected_resource=0;actor->pending_notice=0x2345;actor->equipment_notice_slot=71;actor->equipment_notice_peer=83;actor->equipment_notice_parameter=97;f.actor(0,std::uint8_t(category),0);actor->slot=std::uint8_t(category*17u);f.q.memory[0x4a5c30+3]=actor->slot;f.q.world.selected_actor=std::uint8_t(actor->slot+unsigned(!local));f.q.memory[0x4baded]=f.q.world.selected_actor;export_notice(f.q,*actor,0);(void)compare(f,owner,method,0,0xabcd0000u|mode,3,4,1);compare_actor(f.q,*actor,0);compare_full(f.q,3);++actor_operation_gates;
        }
    }
    for(unsigned asset:{0u,4u,8u,12u})for(unsigned method=0;method<3;++method)for(unsigned mask=0;mask<16;++mask)for(unsigned selected:{0u,3u,4u})for(unsigned mode:{0u,1u,2u}){
        Consuming f(ram,assets[asset],controlled);g::ActorResourceOperations owner(f.recipes);s::SceneDescriptor a,b;a.active=b.active=1;a.instance_index=3;b.instance_index=4;a.template_index=0;b.template_index=1;a.ownership_tag=1;b.ownership_tag=2;a.attachment_id=method==2?std::array<std::uint16_t,3>{0,1,0xb}[asset/4%3]:42;b.attachment_id=10;a.parameter=0;b.parameter=1;a.flags=b.flags=0x20040;a.position={100,-7,200};b.position={300,-5,400};a.shape_profile=b.shape_profile=2;
        if(method==2){const auto content=a.attachment_id==0?0x1c5:a.attachment_id==1?0x1c8:0x1c6;const auto root=f.q.assets->find(std::int16_t(content));if(root>=0&&!f.q.assets->roots()[unsigned(root)].admitted_parts)continue;}
        if(mask&1){auto [made,raw]=f.q.create(a.attachment_id,7);a.primary=made.model;made.model->resource_slot=3;f.q.memory[raw+0x240]=3;}if(mask&2){auto [made,raw]=f.q.create(b.attachment_id,7);b.primary=made.model;made.model->resource_slot=4;f.q.memory[raw+0x240]=4;}sync_full(f.q,3,a);sync_full(f.q,4,b);if(mask&4)secondary(f.q,3);if(mask&8)secondary(f.q,4);
        const auto actor=f.q.world.primary(0);actor->inventory.carried={3,4,3,0};actor->inventory.storage[31]=4;actor->selected_resource=std::uint8_t(selected);actor->secondary_equipped_resource=4;actor->resource_action=123;actor->pending_notice=0x2345;actor->equipment_notice_slot=71;actor->equipment_notice_peer=83;actor->equipment_notice_parameter=97;f.actor(0,mode==2?1:0,0);f.q.world.selected_actor=std::uint8_t(mode==1?1:0);f.q.memory[0x4baded]=f.q.world.selected_actor;export_notice(f.q,*actor,0);put(f.q.memory,0x743128,unsigned(f.q.resources.active_count()));(void)compare(f,owner,method,0,0xabcd0000u|mode,0x12340003,0x98760004,10);compare_full(f.q,3);compare_full(f.q,4);f.q.compare_world();compare_actor(f.q,*actor,0);check(f.q.resources.active_count()==get<unsigned>(f.q.memory,0x743128));++actor_operation_live;
    }
    // Actual equipment/inventory producers feed the same World frame notice.
    // Other frame services and the final notice observer are declared seams.
    for(unsigned writers=0;writers<4;++writers)for(unsigned prior:{0u,65535u})for(bool fail:{false,true}){
        Consuming f(ram,assets[0],controlled);g::ActorResourceOperations owner(f.recipes);auto actor=f.q.world.primary(0);actor->active=true;actor->room=f.q.world.room;actor->category=0;actor->slot=0;actor->selected_resource=3;actor->pending_notice=std::uint16_t(prior);actor->equipment_notice_slot=71;actor->equipment_notice_peer=83;actor->equipment_notice_parameter=97;s::SceneDescriptor d;d.active=1;d.instance_index=3;d.ownership_tag=1;const auto model=f.q.factory.create_delayed(42,7);check(model.status==g::ResourceModelStatus::completed);d.primary=model.model;check(f.q.resources.replace(*f.q.resources.slot(3),d)==s::SceneStatus::completed);f.q.world.mode=1;f.q.world.selected_actor=0;NoticeServices services(owner,f.q.world.identity(0),writers,fail);
        const auto expected=std::uint16_t((writers&1?0x20u:0u)|(writers&2?0x800u:0u));bool caught{};try{const auto result=f.q.world.update_primary(services);check(result.status==g::Status::completed&&result.updated==1);}catch(const std::runtime_error& error){if(std::string_view(error.what())!="Declared notice delivery unavailable")throw;caught=true;}
        check(caught==(fail&&expected!=0)&&services.calls==unsigned(expected!=0)&&services.published==expected&&actor->pending_notice==(caught?expected:0)&&model.model->current()==!(writers&2));check(actor->equipment_notice_slot==unsigned(writers&2?3:writers&1?0:71)&&actor->equipment_notice_peer==83&&actor->equipment_notice_parameter==97);if(writers&1)check(actor->equipment_slot==3);
    }
    {
        Consuming f(ram,assets[0],controlled);g::ActorResourceOperations owner(f.recipes);s::SceneDescriptor a,b;a.active=b.active=1;a.instance_index=3;b.instance_index=4;a.template_index=200;a.ownership_tag=1;b.ownership_tag=2;a.parameter=b.parameter=1;sync_full(f.q,3,a);sync_full(f.q,4,b);const auto actor=f.q.world.primary(0);actor->pending_notice=0x2345;actor->equipment_notice_slot=71;f.actor(0,0,0);f.q.world.selected_actor=0;
        const auto refused=[&](auto action){bool caught{};try{action();}catch(const std::exception&){caught=true;}check(caught);++actor_operation_refusals;};refused([&]{(void)owner.transfer_quantity(f.q.world.identity(0),0,3,4,10);});check(actor->pending_notice==0x2345&&actor->equipment_notice_slot==71);
        const auto id=f.q.world.identity(0);check(f.q.world.retire_primary(0)==g::actors::EntityStatus::completed);refused([&]{(void)owner.release_instances(id,0,3);});refused([&]{(void)owner.remap_content({},0,3);});check(f.q.world.close()==g::Status::completed);refused([&]{(void)owner.transfer_quantity({},0,3,4,10);});refused([&]{g::ActorResourceOperations closed(f.recipes);});
    }
    placement_floors=nullptr;
}
