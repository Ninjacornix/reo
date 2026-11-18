#include "game/native/gameplay_world/linked_updates.hpp"
std::uint64_t linked_actor_cases{},linked_expiry_cases{},linked_update_refusals{},linked_full_pool_cases{};
bool linked_original_capture{};
std::vector<std::pair<std::uint8_t,std::uint8_t>> linked_original_notices;
bool linked_original_order_capture{};
std::vector<std::uint32_t> linked_original_order;
void linked_actor_original_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x107c68&&GPR_U32(context,6)==0x11a0){
        const auto at=GPR_U32(context,4);check(GPR_U32(context,5)==0&&at>=0x600000&&at<0x611a00&&(at-0x600000)%0x11a0==0,"bounded original sixteen-object clear");
        std::memset(memory+at,0,0x11a0);context->pc=GPR_U32(context,31);return;
    }
    if(context->pc==0x61a6a0||context->pc==0x61b1a0||context->pc==0x66a2e0){cinematic_frame_original_port(memory,context,runtime);return;}
    if(primary_scripted_reference&&context->pc==0x1a0d70){
        const auto token=GPR_U32(context,4);check(token>0&&token<resources.size(),"primary scripted packed-header identity seam");
        SET_GPR_U32(context,2,resources[token]);context->pc=GPR_U32(context,31);++primary_scripted_metadata;return;
    }
    if(context->pc==0x373f40){npc_update_original_port(memory,context,runtime);return;}
    if(context->pc==0x66b500||(context->pc==0x107c68&&GPR_U32(context,6)==48)){common_actor_original_port(memory,context,runtime);return;}
    if(context->pc==0x10a830||context->pc==0x1adb30||context->pc==0x67c590){cutscene_command_original_port(memory,context,runtime);return;}
    if(context->pc==0x1b0300){
        // Audited three-word getter only. The rest of its merged generated
        // source file is not an admitted callable entry in this fixture.
        SET_GPR_S32(context,1,0x320000);SET_GPR_U32(context,2,memory[0x3243f2]);
        context->branch_pc=0x1b0304;context->in_delay_slot=false;context->pc=GPR_U32(context,31);return;
    }
    if(context->pc==0x811190||context->pc==0x810870){
        check(linked_original_capture,"declared linked expiry delivery observation port");
        check(GPR_U32(context,4)==8&&GPR_U32(context,6)==0&&GPR_U32(context,7)==4,"original expiry route arguments");
        const auto packet=GPR_U32(context,5);
        check(memory[packet]==0x49&&memory[packet+1]==6&&memory[packet+4]==255,"only initialized original expiry payload fields");
        linked_original_notices.emplace_back(context->pc==0x811190?0:1,memory[packet+3]);
        context->pc=GPR_U32(context,31);return;
    }
    if(context->pc==0x6ba880&&linked_original_order_capture)linked_original_order.push_back(GPR_U32(context,4));
    original_transform_port(memory,context,runtime);
}
void linked_actor_composition(g::World& world,const g::actors::EntityId& id,g::ScriptedMotionBanks banks,
                              unsigned variant,std::vector<std::uint8_t>& ram){
    location="linked actor composition="+std::to_string(variant);
    const auto value=world.resolve(id);
    value->active=variant%4!=0;value->character=std::uint8_t(variant);
    value->linked_frame=g::LinkedActorFrameState{std::uint8_t(variant%3==0?0:17),99};
    value->targeting=g::TargetingState{0x89abcd00u|(variant%2?4u:0u),false,std::uint8_t(0)};
    value->collision.local_center={1.25f,2.5f,-3.75f};value->collision.previous_center_offset={-99,-98,-97};
    auto& record=*world.session().enemy_descriptors.record(value->character);record.runtime_flags=std::uint8_t(variant);
    auto& state=world.session().linked_updates;
    state.previous_seconds=std::uint8_t(variant*17);state.expiry_countdown=5;state.work_counters={1,2,3,4};
    world.session().feedback_phase=state.previous_seconds;
    put(ram.data(),actor,std::uint8_t(value->active));put(ram.data(),actor+0xb98,value->character);
    put(ram.data(),actor+0xc8b,value->linked_frame->center_cache_state);put(ram.data(),actor+0xc98,value->linked_frame->transient_marker);
    put(ram.data(),actor+0xc94,value->targeting->flags);
    put(ram.data(),actor+0x1ac,value->collision.local_center);put(ram.data(),actor+0x1cc,value->collision.previous_center_offset);
    put(ram.data(),actor+0x1c,0u);put(ram.data(),actor+0x14,0x6ba880u);put(ram.data(),0x3b5900,actor);
    put(ram.data(),0x4bae02,world.session().feedback_phase);put(ram.data(),0x3b5040,state.previous_seconds);
    put(ram.data(),0x37fd80,state.expiry_countdown);put(ram.data(),0x755350,state.work_counters);
    put(ram.data(),0x74f250+96*value->character+0x45,record.runtime_flags);
    put(ram.data(),0x3243cc,world.session().clock_mode);
    std::memcpy(ram.data()+0x3b5050,world.session().enemy_descriptors.expiry().data(),256);
    const auto floors=std::make_shared<const reo::native::gameplay_collision::response::Grid>();
    g::LinkedActorUpdates updates(world,std::move(banks),floors);
    const auto result=updates.run();call(ram.data(),0x6bbba0,0);
    check(result.status==g::LinkedUpdateStatus::completed&&result.visited==1&&result.called==unsigned(value->active),"actual native linked callback pass");
    check(result.poses==unsigned(value->active&&!(value->targeting->flags&4)),"actual linked post-callback pose gate");
    check(record.runtime_flags==ram[0x74f250+96*value->character+0x45]&&value->linked_frame->center_cache_state==ram[actor+0xc8b]&&value->linked_frame->transient_marker==ram[actor+0xc98],"linked canonical descriptor flag and actor cache fields");
    check(std::memcmp(&value->collision.previous_center_offset,ram.data()+actor+0x1cc,12)==0,"376DB0 transforms local center without translation");
    check(std::memcmp(&value->position,ram.data()+actor+0x38,12)==0&&std::memcmp(value->orientation.data(),ram.data()+actor+0x90,8)==0,"linked callback movement effects");
    for(const auto pair:{std::pair{value->collision.basis.x,0x50u},std::pair{value->collision.basis.y,0x60u},std::pair{value->collision.basis.z,0x70u},std::pair{value->collision.basis.translation,0x80u}})
        check(std::memcmp(&pair.first,ram.data()+actor+pair.second,12)==0,"linked final pose basis");
    records(*value->animation,ram,{value->root_motion_delta.x,value->root_motion_delta.y,value->root_motion_delta.z});
    check(state.previous_seconds==ram[0x3b5040]&&state.expiry_countdown==get<std::int8_t>(ram.data(),0x37fd80)&&state.clock_factor==ram[0x74f200]&&std::memcmp(state.work_counters.data(),ram.data()+0x755350,4)==0,"shared native linked frame clock/counters");
    check(updates.close()==g::LinkedUpdateStatus::completed,"linked update closure");++linked_actor_cases;
}
void linked_expiry_tests(std::vector<std::uint8_t>& ram){
    struct Notices final:g::LinkedExpirySink {
        std::vector<std::pair<std::uint8_t,std::uint8_t>> values;
        bool expired(const g::LinkedExpiryNotice& value)noexcept override{values.emplace_back(value.mode,value.ordinal);return true;}
    };
    const auto floors=std::make_shared<const reo::native::gameplay_collision::response::Grid>();
    for(unsigned counter=0;counter<256;++counter)for(bool changed:{false,true}){
        location="linked expiry counter="+std::to_string(counter)+" changed="+std::to_string(changed);
        g::World world(world_profile(),std::make_shared<g::Session>());Notices notices;notices.values.reserve(2);
        g::LinkedActorUpdates updates(world,{},floors,&notices);
        auto& session=world.session();auto& state=session.linked_updates;
        session.feedback_phase=std::uint8_t(counter*73);session.clock_mode=std::uint8_t(counter%2);
        state.previous_seconds=std::uint8_t(session.feedback_phase-unsigned(changed));state.expiry_countdown=std::bit_cast<std::int8_t>(std::uint8_t(counter));state.work_counters={0xab,0xcd,0xef,0x87};
        world.mode=std::array<std::uint8_t,5>{0,1,2,3,255}[counter%5];
        session.message_phase=std::array<std::int8_t,5>{-1,0,1,2,3}[(counter/5)%5];
        put(ram.data(),0x4bae02,session.feedback_phase);put(ram.data(),0x3243cc,session.clock_mode);
        put(ram.data(),0x3b5040,state.previous_seconds);put(ram.data(),0x37fd80,state.expiry_countdown);
        put(ram.data(),0x755350,state.work_counters);put(ram.data(),0x3b5900,0u);
        put(ram.data(),0x3243f2,world.mode);put(ram.data(),0x3243fb,session.message_phase);
        for(unsigned index=0;index<256;++index){
            auto& record=*session.enemy_descriptors.record(index);record.ordinal=std::uint8_t(255-index);record.owner_mode=std::uint8_t(index%3);
            check(session.enemy_descriptors.arm_expiry(index,std::uint8_t(index+counter)),"native expiry admission");
            ram[0x3b5050+index]=std::uint8_t(index+counter);
            put(ram.data(),0x74f250+96*index,record.ordinal);put(ram.data(),0x74f250+96*index+0x2b,record.owner_mode);
        }
        const auto result=updates.run();
        linked_original_notices.clear();linked_original_capture=true;
        call(ram.data(),0x6bbba0,0);linked_original_capture=false;
        check(result.status==g::LinkedUpdateStatus::completed&&result.visited==0&&result.publication_failures==0,"native expiry pass without actor callbacks");
        check(state.previous_seconds==ram[0x3b5040]&&state.expiry_countdown==get<std::int8_t>(ram.data(),0x37fd80)&&state.clock_factor==ram[0x74f200],"all signed countdown patterns and unchanged seconds");
        check(std::memcmp(state.work_counters.data(),ram.data()+0x755350,4)==0&&std::memcmp(session.enemy_descriptors.expiry().data(),ram.data()+0x3b5050,256)==0,"all expiry bytes and work counters");
        check(notices.values==linked_original_notices,"actual original message-phase/owner/mode dispatch gates");
        ++linked_expiry_cases;
    }
    g::World world(world_profile(),std::make_shared<g::Session>());
    bool refused{};try{g::LinkedActorUpdates invalid(world,{},{});}catch(const std::invalid_argument&){refused=true;}
    check(refused,"linked updater needs an owned floor context");++linked_update_refusals;
    g::LinkedActorUpdates first(world,{},floors);refused=false;
    try{g::LinkedActorUpdates duplicate(world,{},floors);}catch(const std::invalid_argument&){refused=true;}
    check(refused,"one native linked update owner per World");++linked_update_refusals;
    check(first.close()==g::LinkedUpdateStatus::completed&&first.run().status==g::LinkedUpdateStatus::closed,"closed linked updater cannot run");
    g::LinkedActorUpdates replacement(world,{},floors);
    check(replacement.run().status==g::LinkedUpdateStatus::completed,"closed registration admits replacement owner");
    const auto id=world.linked_models().allocate(true).id;const auto value=world.resolve(id);value->active=true;value->character=42;
    world.session().enemy_descriptors.record(42)->runtime_flags=255;
    check(replacement.run().status==g::LinkedUpdateStatus::unavailable&&world.session().enemy_descriptors.records()[42].runtime_flags==239,"unsupported required actor callback refuses after preceding record clear");++linked_update_refusals;
    check(world.close()==g::Status::completed&&replacement.run().status==g::LinkedUpdateStatus::closed,"joined linked World closure");
}
void linked_full_pool_tests(std::vector<std::uint8_t>& ram){
    const auto floors=std::make_shared<const reo::native::gameplay_collision::response::Grid>();
    for(unsigned variant=0;variant<8;++variant){
        location="linked full pool="+std::to_string(variant);
        auto profile=world_profile();profile.entities.capacity=64;
        g::World world(profile,std::make_shared<g::Session>());
        g::LinkedActorUpdates updates(world,{},floors);
        std::vector<g::actors::EntityId> ids;
        std::vector<std::uint32_t> addresses;
        world.paused=std::uint8_t(variant%2);
        world.session().feedback_phase=0;world.session().clock_mode=std::uint8_t(variant&1);
        world.session().linked_updates.previous_seconds=0;
        put(ram.data(),0x4bae02,std::uint8_t(0));put(ram.data(),0x3b5040,std::uint8_t(0));
        put(ram.data(),0x37fd80,std::int8_t(5));put(ram.data(),0x3243cc,world.session().clock_mode);
        // 6BA880 reads this actual pause byte before its primary-state gate.
        put(ram.data(),0x4badf8,world.paused);
        for(unsigned index=0;index<50;++index){
            const auto id=world.linked_models().allocate((index+variant)%3!=0).id;
            check(bool(id),"native actual shared fifty-node admission");ids.push_back(id);
            const auto value=world.resolve(id);value->category=2;value->character=std::uint8_t(index);
            value->active=(index+variant)%4!=0;value->primary=0;value->scripted.emplace();
            value->targeting=g::TargetingState{4,false,std::uint8_t(0)};
            value->linked_frame=g::LinkedActorFrameState{std::uint8_t(index%3?17:0),99};
            value->collision.local_center={1.25f,2.5f,-3.75f};
            value->collision.basis={{1,0,0},{0,1,0},{0,0,1},{4,5,6}};
            value->collision.previous_center_offset={-99,-98,-97};
            world.session().enemy_descriptors.record(index)->runtime_flags=std::uint8_t(index|16);
            const auto address=0xa00000u+0x1000u*index;addresses.push_back(address);
            std::memset(ram.data()+address,0,0x1000);
            put(ram.data(),address,std::uint8_t(value->active));put(ram.data(),address+8,value->primary);
            put(ram.data(),address+0x14,0x6ba880u);put(ram.data(),address+0xb98,value->character);
            put(ram.data(),address+0xc94,4u);put(ram.data(),address+0xc8b,value->linked_frame->center_cache_state);
            put(ram.data(),address+0xc98,std::uint8_t(99));
            put(ram.data(),address+0x1ac,value->collision.local_center);put(ram.data(),address+0x1cc,value->collision.previous_center_offset);
            for(const auto pair:{std::pair{value->collision.basis.x,0x50u},std::pair{value->collision.basis.y,0x60u},std::pair{value->collision.basis.z,0x70u}})
                put(ram.data(),address+pair.second,pair.first);
            put(ram.data(),0x74f250+96*index+0x45,std::uint8_t(index|16));
        }
        check(world.linked_models().allocate(true).status==g::LinkedStatus::full,"same fifty-node capacity");
        std::vector<std::uint32_t> expected;
        for(auto id=world.linked_models().tail();id;id=world.linked_models().previous(id)){
            const auto index=std::size_t(std::find(ids.begin(),ids.end(),id)-ids.begin());
            const auto prior=world.linked_models().previous(id);
            const auto prior_index=std::size_t(std::find(ids.begin(),ids.end(),prior)-ids.begin());
            put(ram.data(),addresses[index]+0x1c,prior?addresses[prior_index]:0u);
            if(world.resolve(id)->active)expected.push_back(addresses[index]);
        }
        const auto tail_index=std::size_t(std::find(ids.begin(),ids.end(),world.linked_models().tail())-ids.begin());
        put(ram.data(),0x3b5900,addresses[tail_index]);
        const auto result=updates.run();linked_original_order.clear();linked_original_order.reserve(50);
        linked_original_order_capture=true;call(ram.data(),0x6bbba0,0);linked_original_order_capture=false;
        check(result.status==g::LinkedUpdateStatus::completed&&result.visited==50&&result.called==expected.size()&&result.poses==0,"complete actual linked pool update");
        check(linked_original_order==expected,"original callback order matches actual canonical tail-to-head links");
        for(unsigned index=0;index<50;++index){
            const auto value=world.resolve(ids[index]);const auto address=addresses[index];
            check(value->linked_frame->center_cache_state==ram[address+0xc8b]&&value->linked_frame->transient_marker==ram[address+0xc98],"all active and inactive cache/marker branches");
            check(std::memcmp(&value->collision.previous_center_offset,ram.data()+address+0x1cc,12)==0,"complete linked center transform for pool");
            check(world.session().enemy_descriptors.records()[index].runtime_flags==ram[0x74f250+96*index+0x45],"all canonical descriptor flags after pool pass");
        }
        ++linked_full_pool_cases;
    }
}
