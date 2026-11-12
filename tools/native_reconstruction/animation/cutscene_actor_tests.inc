#include "game/native/gameplay_world/cutscene_actor.hpp"
std::uint64_t cutscene_actor_calls{},cutscene_actor_gate_calls{},cutscene_actor_refusals{};
std::uint64_t primary_cutscene_actor_calls{};
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
        if(value->category<2)++primary_cutscene_actor_calls;else ++cutscene_actor_calls;
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
}
