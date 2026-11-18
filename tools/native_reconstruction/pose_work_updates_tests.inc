#include "game/native/gameplay_world/resource_pose_updates.hpp"
unsigned update_cases{},update_retirements{},update_packets{};
void resource_updates(std::uint8_t* memory,const d::Catalog& catalog){
    auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{256,UINT64_MAX}},session);auto input=std::make_unique<g::Actor>();const auto owner=world.spawn_primary(0,std::move(input)).id;check(bool(owner));const auto parent_actor=world.resolve(owner);parent_actor->position={-13,17,21};put(memory,parent+0x38,parent_actor->position);
    g::PoseWorkPool pool(world);g::ResourceModels models;const auto model=models.create();check(model.status==g::ResourceModelStatus::completed);model.model->pose=m::Matrix{{{{.5f,.25f,-.1f,7}},{{.2f,2,.4f,8}},{{.3f,-.2f,.7f,9}},{{31,-12,7,1}}}};model.model->position={37,41,43};put(memory,0x231c0,model.model->pose);put(memory,0x23200,model.model->position);
    s::SceneResources resources;s::ResourceTemplates templates;d::Packets packets;g::ResourcePoseUpdates updates(world,pool,resources,templates,packets,catalog);
    std::vector<std::byte> encoded(56);const auto write=[&]<class T>(unsigned at,T value){std::memcpy(encoded.data()+at,&value,sizeof value);};write(0,3u);write(4,1u);write(16,32u);
    for(unsigned kind:{1u,2u,10u,14u})for(unsigned phase=0;phase<256;++phase)for(unsigned pattern=0;pattern<32;++pattern){
        invoke(memory,0x581f50);check(pool.reset()==g::PoseWorkStatus::completed);const auto original=invoke(memory,0x581fe0,{1});const auto at=GPR_U32(&original,2);const auto made=pool.allocate();check(made.status==g::PoseWorkStatus::completed);const auto actor=pool.resolve(made.id);check(bool(actor));
        actor->active=true;actor->visible=pattern&1;actor->category=9;actor->slot=3;actor->primary=std::uint8_t(phase);actor->response_class=std::uint8_t(pattern&2);actor->auxiliary_status=0xa0;actor->contact.related=owner;actor->contact.serial=std::uint8_t(pattern&4);
        actor->contact.recipient={std::uint8_t(pattern&8?255:0),std::uint8_t(pattern&16?255:0)};actor->contact.related_recipient={255,255};
        actor->pose_work->update_bound=true;actor->pose_work->kind=std::uint8_t(kind);actor->pose_work->lifetime=-2;actor->pose_work->timer=std::int16_t(pattern==0?INT16_MIN:pattern==1?INT16_MAX:int(pattern)-16);actor->position={1,2,3};actor->previous_position={4,5,6};
        parent_actor->auxiliary_status=std::uint32_t(pattern&8?1:0);memory[parent+0x115]=std::uint8_t(parent_actor->auxiliary_status);source_action=std::int8_t((phase+pattern)%64);expected_resource=3;lookups=packet_calls=0;encoded[47]=std::byte(std::uint8_t(source_action));check(templates.load(encoded));
        s::SceneDescriptor descriptor;descriptor.active=1;descriptor.template_index=0;if(!(pattern&16))descriptor.primary=model.model;check(bool(resources.load(3,descriptor)));put(memory,0x3c564c+3*60,pattern&16?0u:0x23000u);
        memory[at]=1;memory[at+1]=std::uint8_t(actor->visible);memory[at+2]=9;memory[at+3]=3;memory[at+4]=std::uint8_t(kind);memory[at+8]=std::uint8_t(phase);memory[at+0x13f]=actor->response_class;memory[at+0x115]=std::uint8_t(actor->auxiliary_status);memory[at+0x116]=actor->contact.serial;memory[at+0x117]=actor->contact.recipient.category;memory[at+0x118]=actor->contact.recipient.token;memory[at+0x119]=memory[at+0x11a]=255;
        put(memory,at+0x28,parent);put(memory,at+0xc,actor->pose_work->timer);put(memory,at+0x12,actor->pose_work->lifetime);put(memory,at+0x38,actor->position);put(memory,at+0x44,actor->previous_position);
        const auto function=kind==1?0x582e30u:kind==2?0x582f30u:kind==10?0x5840f0u:0x583550u;invoke(memory,function,{at});check(updates.update(pool,made.id,std::uint8_t(kind)));
        check(actor->active==bool(memory[at])&&actor->visible==bool(memory[at+1])&&actor->primary==memory[at+8]&&actor->auxiliary_status==memory[at+0x115]&&actor->response_class==memory[at+0x13f]);
        check(actor->contact.serial==memory[at+0x116]&&parent_actor->auxiliary_status==memory[parent+0x115]);check(actor->pose_work->timer==get<std::int16_t>(memory,at+0xc)&&actor->pose_work->lifetime==get<std::int16_t>(memory,at+0x12));
        check(std::memcmp(&actor->position,memory+at+0x38,12)==0&&std::memcmp(&actor->previous_position,memory+at+0x44,12)==0&&std::memcmp(&actor->pose_work->basis,memory+at+0x50,64)==0);
        check(lookups==(kind==1?1u:0u));check(packets.size()==packet_calls);
        if(packet_calls){const auto packet=packets.acquire(packets.head());check(packet&&packet.state().definition==catalog.find(0,std::int32_t(packet_descriptor)));check(packets.release(packets.head()));++update_packets;}
        if(!actor->active){check(!pool.resolve(made.id));++update_retirements;}
        ++update_cases;
    }
}
