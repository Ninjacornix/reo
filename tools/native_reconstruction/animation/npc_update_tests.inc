#include "game/native/gameplay_world/npc_updates.hpp"
std::uint64_t npc_distance_cases{},npc_pool_cases{},npc_pool_actors{},npc_attachment_cases{},npc_update_refusals{};
std::vector<std::pair<unsigned,unsigned>> npc_original_attachments;
bool npc_pool_capture{};
void npc_update_original_port(std::uint8_t* memory,R5900Context* context,PS2Runtime*){
    check(npc_pool_capture&&context->pc==0x373f40,"declared native NPC rendering boundary observation");
    const auto slot=(GPR_U32(context,4)-0x3e82f0)/2084,model=(GPR_U32(context,5)-0x3863d0)/20;
    check(slot<4&&GPR_U32(context,4)==0x3e82f0+2084*slot&&GPR_U32(context,5)==0x3863d0+20*model,"original NPC attachment record/model request");
    check(get<std::uint16_t>(memory,GPR_U32(context,6)+0xbb4)==model,"original attachment actual NPC model identity");
    npc_original_attachments.emplace_back(slot,model);context->pc=GPR_U32(context,31);
}
void npc_update_tests(std::vector<std::uint8_t>& ram){
    CommonBehaviorFixture behavior;const reo::native::gameplay_collision::response::Grid floors{};g::GridSurfaceOrientation pose(floors);
    g::World distance_world(world_profile(),std::make_shared<g::Session>());
    for(unsigned seed=0;seed<8192;++seed){
        distance_world.paused=seed%8==0?std::bit_cast<std::int8_t>(std::uint8_t(seed/8)):0;
        const std::array<float,7> edges{0,79.f,std::nextafter(80.f,0.f),80.f,std::nextafter(80.f,100.f),81.f,-80.f};
        const g::Position camera{float(int(seed%7)-3),float(int(seed%11)-5),float(int(seed%13)-6)};
        const g::Position position{camera.x+edges[seed%7],camera.y-100.f+float(int((seed/7)%5)-2),camera.z+float(int((seed/35)%9)-4)};
        put(ram.data(),0x4badf8,distance_world.paused);put(ram.data(),0x324138,camera);put(ram.data(),0x70000,position);
        const auto original=call(ram.data(),0x5c0870,0x70000,1);
        check(g::npc_camera_suppressed(distance_world,position,camera)==bool(std::uint8_t(GPR_U32(&original,2))),"complete original NPC camera distance and pause gate");++npc_distance_cases;
    }
    struct Attachments final:g::NpcAttachmentFrames {
        unsigned mask{};g::NpcActorUpdates* updates{};std::vector<std::pair<unsigned,unsigned>> calls;
        bool active(g::World& world,std::uint8_t slot)override{check(world.busy(),"NPC attachment getter has protected world");return (mask>>slot)&1;}
        bool update(g::World& world,g::actors::EntityId id,std::uint8_t slot,std::uint16_t model)override{
            check(world.resolve(id)&&world.resolve(id)->collision.pose_ready&&world.busy(),"NPC rendering request follows completed callback/pose");
            check(updates->run().status==g::NpcUpdateStatus::busy&&updates->close()==g::NpcUpdateStatus::busy&&world.auxiliary_actors().reset()==g::AuxiliaryStatus::busy,"NPC pool pass refuses recursive run/reset/closure");
            calls.emplace_back(slot,model);return true;
        }
    }attachments;
    for(unsigned seed=0;seed<256;++seed){
        location="NPC pool pass="+std::to_string(seed);g::World world(world_profile(),std::make_shared<g::Session>());
        world.paused=std::bit_cast<std::int8_t>(std::array<std::uint8_t,4>{0,1,127,255}[(seed/16)%4]);world.selected_actor=0;world.filter_nonselected_input=false;
        g::Position camera{};std::uint8_t inhibition=seed%11==0?255:0;attachments.mask=seed%16;attachments.calls.clear();npc_original_attachments.clear();
        put(ram.data(),0x4badf8,world.paused);put(ram.data(),0x324138,camera);ram[0x4b9d13]=inhibition;
        for(unsigned slot=0;slot<4;++slot)ram[0x3e82f0+2084*slot]=std::uint8_t((attachments.mask>>slot)&1);
        std::vector<std::pair<g::actors::EntityId,unsigned>> values;
        for(unsigned index=0;index<10;++index){
            const auto id=world.auxiliary_actors().allocate(1).id;const auto value=world.resolve(id);const unsigned at=actor+0x2000*index;
            value->active=(seed+index)%5!=0;value->visible=(seed+index)%7!=0;value->category=1;value->model_variant=std::uint16_t(100+index);value->room_marker=0xa5;
            value->npc=g::NpcActorState{0,index%5==4?std::nullopt:std::optional<std::uint8_t>(std::uint8_t(index%5)),1};
            value->position={std::array<float,5>{0,79,80,81,1000}[(seed+index)%5],-100,0};value->collision.pose_ready=true;
            value->model_scale={1.25f,1,1.5f};value->motion_multiplier=1.25f;value->movement_enabled=99;
            value->response_mask=value->response_value=0xffffffff;value->normalized_marker=value->motion_override=value->interaction_marker=255;value->pending_notice=value->contact_flags=value->frame_value_a=value->frame_value_b=65535;
            std::memset(ram.data()+at,0,0x1170);ram[at]=std::uint8_t(value->active);ram[at+1]=std::uint8_t(value->visible);ram[at+2]=value->category;ram[at+3]=value->slot;ram[at+0x32]=value->normalized_marker;ram[at+0xc53]=value->room_marker;
            put(ram.data(),at+0x18,0x66a2e0u);put(ram.data(),at+0x1c,index==9?0u:at+0x2000);put(ram.data(),at+0x38,value->position);put(ram.data(),at+0xb4,value->model_scale);put(ram.data(),at+0xf0,value->motion_multiplier);
            put(ram.data(),at+0x190,value->response_mask);put(ram.data(),at+0x194,value->response_value);ram[at+0x198]=1;ram[at+0x553]=value->movement_enabled;put(ram.data(),at+0xbb4,value->model_variant);ram[at+0xfb4]=value->npc->attachment.value_or(255);
            ram[at+0xc82]=value->motion_override;ram[at+0xb9e]=value->interaction_marker;put(ram.data(),at+0xd92,value->pending_notice);put(ram.data(),at+0x54a,value->contact_flags);put(ram.data(),at+0xbdc,value->frame_value_a);put(ram.data(),at+0xbde,value->frame_value_b);
            values.emplace_back(id,at);
        }
        put(ram.data(),0x3b59f0,actor);
        g::NpcActorUpdates updates(world,behavior,pose,camera,inhibition,&attachments);attachments.updates=&updates;
        bool duplicate=false;try{g::NpcActorUpdates invalid(world,behavior,pose,camera,inhibition,&attachments);}catch(const std::invalid_argument&){duplicate=true;}check(duplicate,"single NPC update owner per World");
        common_actor_mutate_inhibition=seed%17==0;behavior.inhibition=common_actor_mutate_inhibition?&inhibition:nullptr;
        common_actor_pool_capture=true;const auto result=updates.run();common_actor_capture=npc_pool_capture=true;call(ram.data(),0x6833c0,0);common_actor_capture=npc_pool_capture=common_actor_pool_capture=false;common_actor_mutate_inhibition=false;behavior.inhibition=nullptr;
        check(result.status==g::NpcUpdateStatus::completed&&result.visited==10&&result.called+result.suppressed==10&&!world.busy(),"canonical ten-actor NPC pass result and guard release");
        unsigned called{};
        for(const auto& [id,at]:values){const auto value=world.resolve(id);check(value->collision.pose_ready==bool(ram[at+0x198]),"NPC update admission and explicit pose validity");
            if(!value->collision.pose_ready)continue;
            check(value->normalized_marker==ram[at+0x32]&&value->room_marker==ram[at+0xc53]&&value->movement_enabled==ram[at+0x553]&&value->response_value==get<std::uint32_t>(ram.data(),at+0x194),"NPC actual common callback state");
            check(std::memcmp(&value->position,ram.data()+at+0x38,12)==0&&std::memcmp(&value->root_motion_delta,ram.data()+at+0x4e4,12)==0,"NPC actual root/pose position");
            for(const auto pair:{std::pair{value->collision.basis.x,0x50u},std::pair{value->collision.basis.y,0x60u},std::pair{value->collision.basis.z,0x70u},std::pair{value->collision.basis.translation,0x80u}})check(std::memcmp(&pair.first,ram.data()+at+pair.second,12)==0,"NPC final native pose basis");
            ++called;
        }
        check(called==result.called&&attachments.calls==npc_original_attachments&&result.attachments==attachments.calls.size()&&inhibition==ram[0x4b9d13],"NPC attachment requests use actual post-callback identity and order");
        npc_pool_actors+=result.called;npc_attachment_cases+=result.attachments;
        check(updates.close()==g::NpcUpdateStatus::completed&&updates.run().status==g::NpcUpdateStatus::closed&&world.close()==g::Status::completed,"NPC pass joined closure");++npc_pool_cases;
    }
}
void npc_update_failure_tests(){
    CommonBehaviorFixture behavior;const reo::native::gameplay_collision::response::Grid floors{};g::GridSurfaceOrientation pose(floors);
    g::World world(world_profile(),std::make_shared<g::Session>());g::Position camera{};std::uint8_t inhibition{};
    const auto id=world.auxiliary_actors().allocate(1).id;const auto actor=world.resolve(id);actor->active=actor->visible=true;actor->category=1;actor->npc=g::NpcActorState{0,0,1};actor->room_marker=0xa5;
    actor->position={1000,0,0};actor->model_scale={1,1,1};actor->motion_multiplier=1;
    {
        g::NpcActorUpdates updates(world,behavior,pose,camera,inhibition);const auto result=updates.run();
        check(result.status==g::NpcUpdateStatus::unavailable&&result.called==1&&actor->collision.pose_ready&&!world.busy(),"missing attachment owner retains completed callback and reports unavailable");++npc_update_refusals;
    }
    struct Failed final:g::NpcAttachmentFrames {
        bool active(g::World&,std::uint8_t slot)override{check(slot==0,"actual failed attachment slot");return true;}
        bool update(g::World&,g::actors::EntityId,std::uint8_t,std::uint16_t)override{return false;}
    }failed;
    const auto previous=actor->position;
    {
        g::NpcActorUpdates updates(world,behavior,pose,camera,inhibition,&failed);const auto result=updates.run();
        check(result.status==g::NpcUpdateStatus::unavailable&&result.called==1&&result.attachments==0&&actor->position.z>previous.z&&!world.busy(),"failed attachment completion keeps preceding motion without legacy retry");++npc_update_refusals;
    }
    check(world.close()==g::Status::completed,"failed NPC update still closes");
}
