namespace gw=reo::native::gameplay_world;
namespace gs=reo::native::gameplay_scenario;
namespace gn=reo::native::gameplay_navigation;
std::uint64_t goal_resource_cases{},target_busy_cases{},goal_reevaluation_cases{},goal_reevaluation_writes{},goal_reevaluation_refusals{},goal_alias_cases{};
#ifdef REO_AI_ORIGINAL
void project_goal_actor(std::vector<std::uint8_t>& target,unsigned at,const gw::Actor& actor){
    put(target,at+0x544,actor.current);put(target,at+0x546,actor.maximum);put(target,at+0xba0,actor.status);put(target,at+0xba4,actor.auxiliary_status);put(target,at+0x1e2,actor.room);
    target[at+3]=actor.slot;target[at+0xb98]=actor.character;target[at+0xb9b]=actor.class_marker;target[at+0x54f]=actor.motion_class;target[at+0xc7f]=actor.equipment_slot;target[at+0xff0]=actor.ai_control;
    std::memcpy(target.data()+at+0xc84,actor.inventory.carried.data(),4);std::memcpy(target.data()+at+0xc88,actor.inventory.storage.data(),32);
    if(actor.ai_execution)project(target,*actor.ai_execution,at);
}
void project_goal_descriptor(const gs::SceneResources& resources,unsigned slot){
    const auto id=resources.slot(slot);check(bool(id));const auto descriptor=resources.get(*id);check(bool(descriptor));
    const auto at=0x3c5630+60*slot;memory[at]=descriptor->active;put(memory,at+6,descriptor->authored_id);
}
void project_goal_resources(const gs::SceneResources& resources){for(unsigned i=0;i<256;++i)project_goal_descriptor(resources,i);}
void project_goal_bank(const gn::Bank& bank){for(unsigned i=0;i<128;++i){const auto graph=bank.room(i);put(memory,0x83e558+164*i,std::uint32_t(graph?graph->nodes().size():0));}}
#endif
void load_goal_descriptor(gs::SceneResources& resources,unsigned slot,unsigned active,unsigned content){
    gs::SceneDescriptor descriptor;descriptor.active=std::uint8_t(active);descriptor.authored_id=std::uint16_t(content);check(bool(resources.load(slot,descriptor)));
#ifdef REO_AI_ORIGINAL
    project_goal_descriptor(resources,slot);
#endif
}
void compare_goal_resource(const gw::Actor& actor,const gw::Actor& other,const gs::SceneResources& resources){
    const auto result=ai::select_character_seven_resource(actor,other,resources);check(result.status==ai::Status::completed);
#ifdef REO_AI_ORIGINAL
    constexpr unsigned self=0x10000,reference=0x4a5c30,out=0x1e00000;
    project_goal_actor(memory,self,actor);project_goal_actor(memory,reference,other);memory[out]=197;
    const auto before=std::vector<std::uint8_t>(memory.begin()+self,memory.begin()+self+0x1100);
    const auto before_other=std::vector<std::uint8_t>(memory.begin()+reference,memory.begin()+reference+0x1100);
    R5900Context context;PS2Runtime runtime;context.pc=0x825cc0;SET_GPR_U32(&context,4,self);SET_GPR_U32(&context,5,reference);SET_GPR_U32(&context,6,out);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000&&bool(result.selected)==(GPR_U32(&context,2)!=0)&&memory[out]==result.selected.value_or(197));
    check(std::memcmp(before.data(),memory.data()+self,0x1100)==0&&std::memcmp(before_other.data(),memory.data()+reference,0x1100)==0);
#endif
    ++goal_resource_cases;
}
void compare_target_busy(const gw::Actor& actor){
    [[maybe_unused]] const auto result=ai::actor_target_busy(actor);
#ifdef REO_AI_ORIGINAL
    project_goal_actor(memory,0x10000,actor);R5900Context context;PS2Runtime runtime;context.pc=0x823190;SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,31,0x100);original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&result==(GPR_U32(&context,2)!=0));
#endif
    ++target_busy_cases;
}
std::shared_ptr<const gn::Asset> reevaluation_asset(bool nodes=true){
    const unsigned count=nodes?1:0,tail=44+64*count+4*count*count,directory=tail+8;
    std::vector<std::uint8_t> bytes(directory+64);const auto write=[&](unsigned at,unsigned value){for(unsigned i=0;i<4;++i)bytes[at+i]=std::uint8_t(value>>(8*i));};
    write(0,0x20030724);write(4,12);write(8,16);write(16,1);bytes[20]=7;write(24,32);write(32,tail-32);write(36,directory-32);write(40,count);
    if(nodes){bytes[44]=1;write(60,0xffffffff);for(unsigned i=0;i<4;++i){bytes[64+i]=255;bytes[108+i]=255;}}
    gn::ImportFailure failure;auto result=gn::Asset::read(bytes,failure);check(bool(result));return std::make_shared<const gn::Asset>(std::move(*result));
}
void goal_actor(gw::Actor& actor,unsigned seed=7){
    actor.room=7;actor.slot=1;actor.character=0;actor.motion_class=0;actor.status=actor.auxiliary_status=0;
    actor.ai_execution=state(seed);auto& s=*actor.ai_execution;s.goal_refresh=1;s.peer_priority=0;s.reference_request=0;s.owned_request=0;s.goal_resource=0xdeadbeef;
    s.combined_weights.fill(0);s.combined_weights[0]=10;
}
ai::GoalReevaluated compare_goal_reevaluation(gw::Actor& actor,gw::Actor& reference,gw::Actor& companion,const gn::Bank& bank,const gs::SceneResources& resources,unsigned alias=0){
    auto* ref=alias==1?&actor:&reference;auto* peer=alias==2?&actor:&companion;
#ifdef REO_AI_ORIGINAL
    const unsigned ref_at=0x4a5c30,peer_at=actor.slot==1?0x4a7df0:0x4a6d10,self_at=alias==1?ref_at:alias==2?peer_at:0x10000;
    project_goal_actor(memory,self_at,actor);project_goal_actor(memory,ref_at,*ref);project_goal_actor(memory,peer_at,*peer);
    auto expected=std::vector<std::uint8_t>(memory.begin()+self_at,memory.begin()+self_at+0x1100);
    auto expected_ref=std::vector<std::uint8_t>(memory.begin()+ref_at,memory.begin()+ref_at+0x1100);
    auto expected_peer=std::vector<std::uint8_t>(memory.begin()+peer_at,memory.begin()+peer_at+0x1100);
#endif
    const auto result=ai::reevaluate_goal(actor,ref,peer,bank,resources);
    if(result.status!=ai::Status::completed){++goal_reevaluation_refusals;return result;}
#ifdef REO_AI_ORIGINAL
    project_goal_actor(expected,0,actor);project_goal_actor(expected_ref,0,*ref);project_goal_actor(expected_peer,0,*peer);
    const auto before=reference_goal_sets;R5900Context context;PS2Runtime runtime;context.pc=0x8133d0;SET_GPR_U32(&context,4,self_at);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000&&reference_goal_sets-before==unsigned(result.goal_written));
    check(std::memcmp(expected.data(),memory.data()+self_at,0x1100)==0&&std::memcmp(expected_ref.data(),memory.data()+ref_at,0x1100)==0&&std::memcmp(expected_peer.data(),memory.data()+peer_at,0x1100)==0);
#endif
    ++goal_reevaluation_cases;goal_reevaluation_writes+=result.goal_written;if(alias)++goal_alias_cases;return result;
}
void priority_goal_contracts(){
    gs::SceneResources resources;
#ifdef REO_AI_ORIGINAL
    project_goal_resources(resources);
#endif
    load_goal_descriptor(resources,1,128,0x131);load_goal_descriptor(resources,2,1,0x12d);load_goal_descriptor(resources,3,255,0x12d);
    gw::Actor self,other;self.character=7;self.inventory.storage[28]=1;self.inventory.storage[10]=2;self.inventory.storage[18]=3;
    other.class_marker=2;other.maximum=1000;
    for(unsigned raw=0;raw<65536;++raw)for(unsigned flags:{0u,1u,8u,9u}){other.current=std::bit_cast<std::int16_t>(std::uint16_t(raw));other.status=flags;compare_goal_resource(self,other,resources);}
    other.status=1;
    for(unsigned raw=0;raw<65536;++raw)for(std::int16_t health:{1,125,32767}){other.maximum=std::bit_cast<std::int16_t>(std::uint16_t(raw));other.current=health;compare_goal_resource(self,other,resources);}
    for(unsigned character=0;character<256;++character)for(unsigned marker:{0u,1u,2u,255u}){self.character=std::uint8_t(character);other.class_marker=std::uint8_t(marker);compare_goal_resource(self,other,resources);}
    // Exact special/extended slots and all descriptor-byte IDs/activity values.
    self.character=7;other.class_marker=2;other.current=1;other.maximum=100;
    for(unsigned id=0;id<256;++id)for(unsigned active:{0u,1u,128u,255u}){
        load_goal_descriptor(resources,id,active,0x131);self.inventory.storage.fill(0);self.inventory.storage[28]=std::uint8_t(id);other.status=0;compare_goal_resource(self,other,resources);
        load_goal_descriptor(resources,id,active,0x12d);other.status=1;
        for(unsigned position=10;position<19;++position){self.inventory.storage.fill(0);self.inventory.storage[position]=std::uint8_t(id);compare_goal_resource(self,other,resources);}
        load_goal_descriptor(resources,id,0,0);
    }
    load_goal_descriptor(resources,1,128,0x131);load_goal_descriptor(resources,2,1,0x12d);load_goal_descriptor(resources,3,255,0x12d);
    for(unsigned motion=0;motion<256;++motion)for(unsigned aux:{0u,0x10000u,0x20000u,0x30000u})for(unsigned status:{0u,0x200u}){self.motion_class=std::uint8_t(motion);self.auxiliary_status=aux;self.status=status;compare_target_busy(self);}
    reo::native::gameplay_session::RoomVariants variants;check(variants.store(7,0));gn::Bank bank(variants);check(bank.bind(reevaluation_asset()));
#ifdef REO_AI_ORIGINAL
    project_goal_bank(bank);
#endif
    gw::Actor reference,companion;reference.room=8;reference.maximum=1000;reference.current=10;reference.class_marker=2;reference.equipment_slot=201;companion.ai_execution=state(1);companion.ai_execution->goal=3;
    for(unsigned motion=0;motion<256;++motion)for(unsigned refresh:{0u,1u,128u})for(unsigned aux:{0u,0x10000u,0x04000000u,0x20000u,0x01000000u})for(unsigned status:{0u,1u,8u,0x200u,0x208u}){
        goal_actor(self);self.motion_class=std::uint8_t(motion);self.ai_execution->goal_refresh=std::uint8_t(refresh);self.auxiliary_status=aux;self.status=status;
        check(compare_goal_reevaluation(self,reference,companion,bank,resources).status==ai::Status::completed);
    }
    for(unsigned motion=0;motion<256;++motion)for(unsigned profile=0;profile<16;++profile)for(unsigned weights=0;weights<10;++weights){
        goal_actor(self);self.motion_class=std::uint8_t(motion);reference.room=8;reference.status=reference.auxiliary_status=0;reference.motion_class=0;reference.current=10;reference.maximum=1000;
        companion.ai_execution->goal=3;auto& s=*self.ai_execution;s.combined_weights.fill(0);if(weights<8)s.combined_weights[weights]=10;else if(weights==9)s.combined_weights[0]=s.combined_weights[1]=10;
        if(profile>=1&&profile<=5){reference.room=7;if(profile==1||profile==4||profile==5)reference.status=8;if(profile==2){reference.motion_class=0x30;reference.auxiliary_status=0x01000000;}if(profile==3)reference.motion_class=0x25;if(profile==4)companion.ai_execution->goal=10;if(profile==5)s.peer_priority=1;}
        if(profile==6)s.reference_request=1;
        if(profile==7){reference.room=7;s.owned_request=256;}
        if(profile==8)s.owned_request=65535;
        if(profile==9||profile==10||profile==11||profile==14){self.character=7;self.inventory.storage.fill(0);self.inventory.storage[28]=1;self.inventory.storage[10]=2;if(profile!=11)reference.room=7;if(profile==10){reference.current=500;reference.status=1;}if(profile==14)reference.status=8;}
        if(profile==12){reference.room=7;reference.motion_class=0x25;companion.ai_execution->goal=10;}
        if(profile==13)s.reference_request=255;
        check(compare_goal_reevaluation(self,reference,companion,bank,resources).status==ai::Status::completed);
    }
    for(unsigned alias:{1u,2u})for(unsigned motion=0;motion<256;++motion){
        goal_actor(self);self.motion_class=std::uint8_t(motion);reference.room=7;reference.status=0;reference.motion_class=0;companion.ai_execution->goal=3;
        check(compare_goal_reevaluation(self,reference,companion,bank,resources,alias).status==ai::Status::completed);
    }
    // First strict maximum, full byte weights and winners outside0..4.
    reference.room=8;
    for(unsigned winner=0;winner<8;++winner)for(unsigned value=0;value<256;++value){goal_actor(self);self.ai_execution->combined_weights.fill(0);self.ai_execution->combined_weights[winner]=std::uint8_t(value);check(compare_goal_reevaluation(self,reference,companion,bank,resources).status==ai::Status::completed);}
    goal_actor(self);self.room=8;check(compare_goal_reevaluation(self,reference,companion,bank,resources).status==ai::Status::completed); // bound absent graph count0
    check(bank.bind(reevaluation_asset(false)));
#ifdef REO_AI_ORIGINAL
    project_goal_bank(bank);
#endif
    goal_actor(self);check(compare_goal_reevaluation(self,reference,companion,bank,resources).status==ai::Status::completed);
    check(bank.bind(reevaluation_asset()));
    goal_actor(self);const auto old_goal=self.ai_execution->goal;check(ai::reevaluate_goal(self,nullptr,nullptr,bank,resources).status==ai::Status::unavailable&&self.ai_execution->goal==old_goal&&self.ai_execution->observation_flags==0);++goal_reevaluation_refusals;
    reference.room=7;check(ai::reevaluate_goal(self,&reference,nullptr,bank,resources).status==ai::Status::unavailable);++goal_reevaluation_refusals;
    self.room=200;check(ai::reevaluate_goal(self,&reference,&companion,bank,resources).status==ai::Status::unavailable);++goal_reevaluation_refusals;
    goal_actor(self);bank.clear_rooms();check(ai::reevaluate_goal(self,&reference,&companion,bank,resources).status==ai::Status::unavailable);++goal_reevaluation_refusals;
    self.ai_execution.reset();check(ai::reevaluate_goal(self,&reference,&companion,bank,resources).status==ai::Status::unavailable);++goal_reevaluation_refusals;
}
