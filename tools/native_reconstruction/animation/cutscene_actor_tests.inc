#include "game/native/gameplay_world/cutscene_actor.hpp"
std::uint64_t cutscene_actor_calls{},cutscene_actor_gate_calls{},cutscene_actor_refusals{};
std::uint64_t primary_action_calls{},primary_action_initializations{},primary_action_timer_calls{},primary_action_gate_calls{},primary_action_refusals{};
std::uint64_t primary_action_timer_sweeps{};
void primary_cutscene_timer_sweep(g::World& world,const g::actors::EntityId& id,
                                 g::PrimaryCutsceneAction& consumer,std::vector<std::uint8_t>& ram){
    const auto value=world.resolve(id);auto& state=*value->scripted;
    world.paused=1;value->model_pose_class=0;value->secondary=0;
    state.cue_phase=2;state.request_flags=0;state.movement_remaining=0;state.scale_lock=1;
    put(ram.data(),0x4badf8,world.paused);put(ram.data(),actor+0x54d,value->model_pose_class);put(ram.data(),actor+9,value->secondary);
    put(ram.data(),actor+0xb38,state.cue_phase);put(ram.data(),actor+0xb3c,state.request_flags);put(ram.data(),actor+0xb78,state.movement_remaining);put(ram.data(),actor+0xb41,state.scale_lock);
    for(unsigned style=0;style<2;++style)for(unsigned mode=0;mode<3;++mode)for(unsigned word=0;word<65536;++word){
        location="primary timer style="+std::to_string(style)+" mode="+std::to_string(mode)+" word="+std::to_string(word);
        value->motion_style=std::uint8_t(style);state.command_angles={};state.command_angles[mode]=std::bit_cast<std::int16_t>(std::uint16_t(word));
        value->model_offset_frame=std::bit_cast<std::int16_t>(std::uint16_t(1+word%65535));
        put(ram.data(),actor+0xb99,value->motion_style);put(ram.data(),actor+0xb64,state.command_angles);put(ram.data(),actor+0xc50,value->model_offset_frame.value_or(0));
        consumer.tick(id);call(ram.data(),0x67be90,actor);
        check(std::memcmp(state.command_angles.data(),ram.data()+actor+0xb64,6)==0&&value->model_offset_frame==get<std::int16_t>(ram.data(),actor+0xc50),"complete signed timer domain and unsigned total duration");
        for(unsigned node:{24u,26u})check(bits(value->model->local_translation(node).y)==get<std::uint32_t>(ram.data(),nodes+400*node+0x74),"actual paired local-node offsets with animation disabled");
        ++primary_action_timer_sweeps;
    }
    state.command_angles={1,1,1};value->model_offset_frame=1;put(ram.data(),actor+0xb64,state.command_angles);put(ram.data(),actor+0xc50,value->model_offset_frame.value_or(0));
    for(unsigned tick=0;tick<4;++tick){
        consumer.tick(id);call(ram.data(),0x67be90,actor);
        check(std::memcmp(state.command_angles.data(),ram.data()+actor+0xb64,6)==0&&value->model_offset_frame==get<std::int16_t>(ram.data(),actor+0xc50),"sequential three-timer handoff without same-tick fallthrough");
        for(unsigned node:{24u,26u})check(bits(value->model->local_translation(node).y)==get<std::uint32_t>(ram.data(),nodes+400*node+0x74),"sequential paired-node timer result");
        ++primary_action_timer_sweeps;
    }
}
void primary_cutscene_action_composition(g::World& world,const g::actors::EntityId& id,
                                       g::ScriptedActorMotion& motion,unsigned variant,
                                       std::vector<std::uint8_t>& ram){
    const auto value=world.resolve(id);auto& state=*value->scripted;
    g::PrimaryCutsceneAction consumer(world,motion);
    world.paused=std::bit_cast<std::int8_t>(std::array<std::uint8_t,3>{0,1,255}[variant%3]);
    value->motion_style=std::uint8_t(variant%2);value->primary=6;value->visible=false;
    value->secondary=19;value->phase=55;value->subphase=37;state.cue_phase=0;
    value->root_motion_delta={3,4,5};value->auxiliary_status=0x80000000u|(variant%2?2u:0u);
    value->position={10,20,30};value->orientation={0,std::int16_t(variant*113),0,0};
    state.request_flags=0x89abcdef;state.request_phase=77;state.scale_lock=std::int8_t(variant%2);
    state.movement_angles={std::bit_cast<std::int16_t>(std::uint16_t(variant*31337)),std::bit_cast<std::int16_t>(std::uint16_t(variant*7919))};
    state.forward_step=float(int(variant%9)-4)*.125f;state.yaw_step=0x81230000u|std::uint16_t(variant*617);
    state.movement_remaining=std::array{0u,1u,2u,0x80000000u,0xffffffffu}[variant%5];
    state.command_angles={};
    state.command_angles[variant%3]=std::array<std::int16_t,5>{1,2,3,-1,INT16_MIN}[variant%5];
    value->model_offset_frame=std::bit_cast<std::int16_t>(std::array<std::uint16_t,4>{1,3,32768,65535}[variant%4]);
    const auto write_state=[&]{
        put(ram.data(),0x4badf8,world.paused);put(ram.data(),actor+1,std::uint8_t(value->visible));
        put(ram.data(),actor+8,value->primary);put(ram.data(),actor+9,value->secondary);put(ram.data(),actor+10,value->phase);put(ram.data(),actor+11,value->subphase);
        put(ram.data(),actor+0x38,value->position);put(ram.data(),actor+0x90,value->orientation);put(ram.data(),actor+0x4e4,value->root_motion_delta);
        put(ram.data(),actor+0xb38,state.cue_phase);put(ram.data(),actor+0xb3c,state.request_flags);put(ram.data(),actor+0xb41,state.scale_lock);put(ram.data(),actor+0xb42,state.request_phase);
        put(ram.data(),actor+0xb64,state.command_angles);put(ram.data(),actor+0xc50,value->model_offset_frame.value_or(0));
        put(ram.data(),actor+0xb6c,state.movement_angles);put(ram.data(),actor+0xb70,state.forward_step);put(ram.data(),actor+0xb74,state.yaw_step);put(ram.data(),actor+0xb78,state.movement_remaining);
        put(ram.data(),actor+0xba4,value->auxiliary_status);put(ram.data(),actor+0xb99,value->motion_style);
    };
    write_state();
    for(unsigned tick=0;tick<6;++tick){
        location="primary action variant="+std::to_string(variant)+" tick="+std::to_string(tick);
        if(tick==1){state.cue_phase=1;put(ram.data(),actor+0xb38,state.cue_phase);}
        if(tick==5){state.cue_phase=-1;put(ram.data(),actor+0xb38,state.cue_phase);}
        consumer.tick(id);call(ram.data(),0x67be90,actor);
        check(value->visible==bool(ram[actor+1])&&value->primary==ram[actor+8]&&value->secondary==ram[actor+9]&&value->phase==ram[actor+10]&&value->subphase==ram[actor+11],"actual primary action cue and action transitions");
        check(state.cue_phase==get<std::int8_t>(ram.data(),actor+0xb38)&&state.request_flags==get<std::uint32_t>(ram.data(),actor+0xb3c)&&state.request_phase==ram[actor+0xb42],"actual primary request consumption");
        check(std::memcmp(state.command_angles.data(),ram.data()+actor+0xb64,6)==0&&value->model_offset_frame==get<std::int16_t>(ram.data(),actor+0xc50),"signed first-nonzero timer decrement and next-duration handoff");
        check(std::memcmp(&value->position,ram.data()+actor+0x38,12)==0&&std::memcmp(value->orientation.data(),ram.data()+actor+0x90,8)==0,"primary counted movement before animation");
        check(std::memcmp(state.movement_angles.data(),ram.data()+actor+0xb6c,4)==0&&bits(state.forward_step)==get<std::uint32_t>(ram.data(),actor+0xb70)&&state.yaw_step==get<std::uint32_t>(ram.data(),actor+0xb74)&&state.movement_remaining==get<std::uint32_t>(ram.data(),actor+0xb78),"primary movement exact-zero cleanup");
        check(value->contact_flags==get<std::uint16_t>(ram.data(),actor+0x54a)&&value->auxiliary_status==get<std::uint32_t>(ram.data(),actor+0xba4),"primary final auxiliary bit-two propagation");
        records(*value->animation,ram,{value->root_motion_delta.x,value->root_motion_delta.y,value->root_motion_delta.z});
        if(tick==0){
            for(unsigned i=0;i<12*32;++i)check(ram[actor+0x1e4+i]==0,"original twelve channel records clear completely");
            ++primary_action_initializations;
        }else if(tick<5)++primary_action_timer_calls;
        ++primary_action_calls;
    }
    if(value->category==0&&variant==0&&primary_action_timer_sweeps==0)primary_cutscene_timer_sweep(world,id,consumer,ram);
}
void primary_cutscene_action_gates(std::vector<std::uint8_t>& ram){
    for(unsigned cue=3;cue<256;++cue){
        g::World world(world_profile(),std::make_shared<g::Session>());
        const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto actor_value=world.resolve(id);
        actor_value->scripted.emplace();actor_value->scripted->cue_phase=std::bit_cast<std::int8_t>(std::uint8_t(cue));actor_value->category=std::uint8_t(cue%2);actor_value->auxiliary_status=cue%2?2:0;
        std::memset(ram.data()+actor,0,0x10e0);put(ram.data(),actor+0xb38,actor_value->scripted->cue_phase);put(ram.data(),actor+0xba4,actor_value->auxiliary_status);
        g::ScriptedActorMotion motion(world,{});g::PrimaryCutsceneAction consumer(world,motion);
        consumer.tick(id);call(ram.data(),0x67be90,actor);
        check(actor_value->contact_flags==get<std::uint16_t>(ram.data(),actor+0x54a),"inactive primary cue still propagates final status bit without model");++primary_action_gate_calls;
    }
    g::World world(world_profile(),std::make_shared<g::Session>());
    const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto value=world.resolve(id);
    value->scripted.emplace();value->primary=19;value->secondary=27;value->phase=37;value->subphase=47;value->root_motion_delta={3,4,5};
    g::ScriptedActorMotion motion(world,{});g::PrimaryCutsceneAction consumer(world,motion);bool refused{};
    try{consumer.tick(id);}catch(const std::runtime_error&){refused=true;}
    check(refused&&value->primary==6&&value->secondary==0&&value->phase==0&&value->subphase==0&&value->root_motion_delta.x==0,"missing owned primary channels refuses after initialization prefix");++primary_action_refusals;
    value->scripted->cue_phase=2;value->scripted->request_flags=2;value->scripted->command_angles[0]=1;value->model_offset_frame=1;
    world.paused=1;refused=false;try{consumer.tick(id);}catch(const std::runtime_error&){refused=true;}
    check(refused&&value->secondary==0x23&&value->scripted->request_flags==0&&value->scripted->command_angles[0]==1,"missing paired-node model refuses after request prefix and before decrement");++primary_action_refusals;
    value->secondary=0;value->model_pose_class=1;consumer.tick(id);
    check(value->scripted->command_angles[0]==0,"head model bypasses paired-node helper without invented model requirement");++primary_action_gate_calls;
    check(world.close()==g::Status::completed,"primary action close");refused=false;try{consumer.tick(id);}catch(const std::runtime_error&){refused=true;}
    check(refused,"closed primary action refuses stale identity");++primary_action_refusals;
}
void cutscene_actor_composition(g::World& world,const g::actors::EntityId& id,
                               g::ScriptedActorMotion& motion,unsigned variant,
                               std::vector<std::uint8_t>& ram){
    const auto value=world.resolve(id);auto& state=*value->scripted;
    const reo::native::gameplay_collision::response::Grid floors{};
    g::CutsceneActor consumer(world,motion,floors);
    world.paused=std::bit_cast<std::int8_t>(std::uint8_t(variant));
    value->primary=6;value->visible=false;value->phase=23;value->subphase=17;
    value->position={10,20,30};value->orientation={std::int16_t(variant*37),std::int16_t(variant*113),std::int16_t(variant*19),0};
    value->model_scale={1.25f,.75f,1.5f};value->motion_multiplier=1.25f;
    state.cue_phase=1;state.request_flags=0x89abcdef;state.scale_lock=std::int8_t(variant%2);
    state.request_phase=77;state.movement_angles={std::bit_cast<std::int16_t>(std::uint16_t(variant*31337)),std::bit_cast<std::int16_t>(std::uint16_t(variant*7919))};
    state.forward_step=float(int(variant%9)-4)*.125f;state.yaw_step=0x81230000u|std::uint16_t(variant*617);
    state.movement_remaining=std::array{0u,1u,2u,0x80000000u,0xffffffffu}[variant%5];
    put(ram.data(),0x4badf8,world.paused);put(ram.data(),actor+1,std::uint8_t(value->visible));
    put(ram.data(),actor+8,value->primary);put(ram.data(),actor+10,value->phase);put(ram.data(),actor+11,value->subphase);
    put(ram.data(),actor+0x38,value->position);put(ram.data(),actor+0x90,value->orientation);
    put(ram.data(),actor+0xb4,value->model_scale);put(ram.data(),actor+0xf0,value->motion_multiplier);
    put(ram.data(),actor+0xb38,state.cue_phase);put(ram.data(),actor+0xb3c,state.request_flags);
    put(ram.data(),actor+0xb41,state.scale_lock);put(ram.data(),actor+0xb42,state.request_phase);
    put(ram.data(),actor+0xb6c,state.movement_angles);put(ram.data(),actor+0xb70,state.forward_step);
    put(ram.data(),actor+0xb74,state.yaw_step);put(ram.data(),actor+0xb78,state.movement_remaining);
    for(unsigned tick=0;tick<3;++tick){
        location="cutscene actor variant="+std::to_string(variant)+" tick="+std::to_string(tick);
        consumer.tick(id);call(ram.data(),0x6ba880,actor);
        check(value->visible==bool(ram[actor+1])&&value->primary==ram[actor+8]&&value->secondary==ram[actor+9]&&value->phase==ram[actor+10]&&value->subphase==ram[actor+11],"cutscene activation/request/action states");
        check(state.cue_phase==get<std::int8_t>(ram.data(),actor+0xb38)&&state.request_flags==get<std::uint32_t>(ram.data(),actor+0xb3c)&&state.request_phase==ram[actor+0xb42],"cutscene cue and request ownership");
        check(std::memcmp(&value->position,ram.data()+actor+0x38,12)==0&&std::memcmp(value->orientation.data(),ram.data()+actor+0x90,8)==0,"cutscene displacement and wrapped yaw");
        check(std::memcmp(state.movement_angles.data(),ram.data()+actor+0xb6c,4)==0&&bits(state.forward_step)==get<std::uint32_t>(ram.data(),actor+0xb70)&&state.yaw_step==get<std::uint32_t>(ram.data(),actor+0xb74)&&state.movement_remaining==get<std::uint32_t>(ram.data(),actor+0xb78),"cutscene counted movement and exact-zero cleanup");
        check(value->contact_flags==get<std::uint16_t>(ram.data(),actor+0x54a)&&value->motion_class==ram[actor+0x54f],"cutscene local-motion scale mask consumption");
        records(*value->animation,ram,{value->root_motion_delta.x,value->root_motion_delta.y,value->root_motion_delta.z});
        if(world.paused){
            const auto& basis=value->collision.basis;
            for(const auto pair:{std::pair{basis.x,0x50u},std::pair{basis.y,0x60u},std::pair{basis.z,0x70u},std::pair{basis.translation,0x80u}})
                check(std::memcmp(&pair.first,ram.data()+actor+pair.second,12)==0,"cutscene canonical pose basis and translation");
            check(std::memcmp(&value->candidate_direction,ram.data()+actor+0xa8,12)==0&&value->collision.pose_ready,"cutscene forward direction and real pose publication");
        }
        ++cutscene_actor_calls;
    }
}
void cutscene_actor_gate_tests(std::vector<std::uint8_t>& ram){
    const reo::native::gameplay_collision::response::Grid floors{};
    for(unsigned pause:{0u,1u,255u})for(unsigned primary:{0u,5u,6u,255u})for(unsigned phase=0;phase<256;++phase){
        location="cutscene gates pause="+std::to_string(pause)+" primary="+std::to_string(primary)+" phase="+std::to_string(phase);
        g::World world(world_profile(),std::make_shared<g::Session>());
        const auto id=world.linked_models().allocate(true).id;const auto value=world.resolve(id);
        value->category=2;value->primary=std::uint8_t(primary);value->scripted.emplace();
        value->scripted->cue_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));
        world.paused=std::bit_cast<std::int8_t>(std::uint8_t(pause));
        std::memset(ram.data()+actor,0,0xd90);
        put(ram.data(),actor+2,value->category);put(ram.data(),actor+8,value->primary);
        put(ram.data(),actor+0xb38,value->scripted->cue_phase);put(ram.data(),0x4badf8,world.paused);
        g::ScriptedActorMotion motion(world,{});g::CutsceneActor consumer(world,motion,floors);
        consumer.tick(id);call(ram.data(),0x6ba880,actor);
        check(value->visible==bool(ram[actor+1])&&value->scripted->cue_phase==get<std::int8_t>(ram.data(),actor+0xb38)&&value->contact_flags==get<std::uint16_t>(ram.data(),actor+0x54a),"unused cutscene gates require no model or motion bank");
        ++cutscene_actor_gate_calls;
    }
    g::World world(world_profile(),std::make_shared<g::Session>()),foreign(world_profile(),std::make_shared<g::Session>());
    g::ScriptedActorMotion motion(world,{}),other(foreign,{});
    bool refused{};try{g::CutsceneActor invalid(world,other,floors);}catch(const std::invalid_argument&){refused=true;}
    check(refused,"cutscene motion owner must belong to same World");++cutscene_actor_refusals;
    g::CutsceneActor consumer(world,motion,floors);consumer.tick({});
    world.paused=1;refused=false;try{consumer.tick({});}catch(const std::runtime_error&){refused=true;}
    check(refused,"active cutscene refuses missing actor identity");++cutscene_actor_refusals;
    check(world.close()==g::Status::completed,"cutscene closure setup");refused=false;
    try{consumer.tick({});}catch(const std::runtime_error&){refused=true;}
    check(refused,"closed cutscene World refuses");++cutscene_actor_refusals;
    for(unsigned family:{0u,1u}){
        g::World primary_world(world_profile(),std::make_shared<g::Session>());
        const auto id=primary_world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto value=primary_world.resolve(id);
        primary_world.paused=1;value->category=std::uint8_t(family);value->primary=6;value->scripted.emplace();value->scripted->cue_phase=1;
        g::ScriptedActorMotion primary_motion(primary_world,{});g::CutsceneActor linked_consumer(primary_world,primary_motion,floors);refused=false;
        try{linked_consumer.tick(id);}catch(const std::runtime_error&){refused=true;}
        check(refused&&!value->visible&&value->scripted->cue_phase==1,"linked outer callback cannot replace actual primary action-six handler");++cutscene_actor_refusals;
    }
}
