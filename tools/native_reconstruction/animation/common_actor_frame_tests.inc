#include "game/native/gameplay_world/common_actor_frame.hpp"
std::uint64_t common_actor_cases{},common_actor_refusals{};
unsigned common_actor_seed{};
bool common_actor_capture{},common_actor_pool_capture{},common_actor_mutate_inhibition{};
void common_actor_original_port(std::uint8_t* memory,R5900Context* context,PS2Runtime*){
    const auto at=context->pc==0x107c68?GPR_U32(context,4)-0xf78:GPR_U32(context,4);
    check(common_actor_capture,"common actor behavior observation requires active fixture");
    if(context->pc==0x107c68){
        check(GPR_U32(context,4)==at+0xf78&&GPR_U32(context,5)==0&&GPR_U32(context,6)==48,"exact original common input clear");
        std::memset(memory+GPR_U32(context,4),0,48);
    }else{
        if(common_actor_pool_capture)common_actor_seed=memory[at+3];
        check(context->pc==0x66b500&&GPR_U32(context,4)==at,"only declared common behavior port");
        check(get<std::uint16_t>(memory,0x744638)==0&&get<std::uint32_t>(memory,at+0x190)==0x1ffff&&get<std::uint32_t>(memory,at+0x194)==0,"original frame prelude precedes behavior");
        check(memory[at+0xc82]==0&&get<std::uint16_t>(memory,at+0xd92)==0&&memory[at+0xb9e]==0&&get<std::uint16_t>(memory,at+0x54a)==0&&get<std::uint16_t>(memory,at+0xbdc)==0&&get<std::uint16_t>(memory,at+0xbde)==0&&memory[at+0x32]==0,"original transient reset before behavior");
        put(memory,at+0x194,0x12340000u|common_actor_seed);put(memory,0x744638,std::uint16_t(common_actor_seed));
        auto position=get<g::Position>(memory,at+0x38);position.x+=float(common_actor_seed%7)*.25f;put(memory,at+0x38,position);
        put(memory,at+0x4e4,g::Position{float(common_actor_seed%9)*.125f,-.25f,.5f});
        put(memory,at+0x54a,std::uint16_t(common_actor_seed%2?8:0));
        if(common_actor_mutate_inhibition)memory[0x4b9d13]=1;
        cinematic_behavior_original_extra(memory,context);
    }
    context->pc=GPR_U32(context,31);
}
struct CommonBehaviorFixture final:g::Services {
        std::uint8_t* inhibition{};
        bool throwing{},retire{};g::CommonActorFrame* callback{};g::actors::EntityId id;
        void begin_offline_frame(g::World&)override{throw std::runtime_error("unexpected common begin");}
        void run(g::Stage stage,g::World& world,g::Actor& value)override{
            if(common_actor_pool_capture)common_actor_seed=value.slot;
            check(stage==g::Stage::update_behavior&&world.busy()&&world.close()==g::Status::busy,"common callback actual behavior stage and lifetime guard");
            check(world.frame_shared_counter==0&&value.response_mask==0x1ffff&&value.response_value==0&&value.motion_override==0&&value.pending_notice==0&&value.interaction_marker==0&&value.contact_flags==0&&value.frame_value_a==0&&value.frame_value_b==0&&value.normalized_marker==0&&value.room_marker==0xa5,"native common prelude before behavior");
            if(callback){bool refused=false;try{callback->tick(id);}catch(const std::runtime_error&){refused=true;}check(refused&&world.busy(),"common callback refuses recursive invocation");}
            value.response_value=0x12340000u|common_actor_seed;world.frame_shared_counter=std::uint16_t(common_actor_seed);
            value.position.x+=float(common_actor_seed%7)*.25f;
            value.root_motion_delta={float(common_actor_seed%9)*.125f,-.25f,.5f};value.contact_flags=std::uint16_t(common_actor_seed%2?8:0);
            if(inhibition)*inhibition=1;
            if(retire)check(world.retire_linked(id)==g::actors::EntityStatus::completed,"retire fixture actor during common behavior");
            if(throwing)throw 17;
        }
        bool remote_motion(g::World&,g::Actor&)override{throw std::runtime_error("unexpected common remote");}
        bool find_grid(g::World&,g::Actor&,std::int8_t&)override{throw std::runtime_error("unexpected common grid");}
        void switch_grid(g::World&,std::int32_t,std::int32_t)override{throw std::runtime_error("unexpected common switch");}
        float grid_response(g::World&,std::uint8_t)override{throw std::runtime_error("unexpected common grid response");}
};
void common_actor_frame_tests(std::vector<std::uint8_t>& ram){
    CommonBehaviorFixture behavior;
    const reo::native::gameplay_collision::response::Grid floors{};g::GridSurfaceOrientation pose(floors);
    for(unsigned seed=0;seed<4096;++seed){
        common_actor_seed=seed;location="common actor frame="+std::to_string(seed);
        g::World world(world_profile(),std::make_shared<g::Session>());const auto id=world.spawn_linked(std::make_unique<g::Actor>()).id;const auto value=world.resolve(id);
        world.paused=std::bit_cast<std::int8_t>(std::array<std::uint8_t,4>{0,1,127,255}[(seed/4)%4]);world.filter_nonselected_input=(seed/16)%2;world.selected_actor=std::uint8_t((seed/32)%8);world.frame_shared_counter=0xbeef;
        value->category=std::array<std::uint8_t,4>{0,1,2,255}[seed%4];value->slot=std::uint8_t((seed/256)%8);value->movement_enabled=std::uint8_t(seed);
        value->response_mask=value->response_value=0xffffffff;value->motion_override=value->interaction_marker=value->normalized_marker=255;value->room_marker=0xa5;value->pending_notice=value->contact_flags=value->frame_value_a=value->frame_value_b=65535;
        static_assert(sizeof(g::input::Frame)==48);value->input={0x5a5a5a5au,0x5a5a5a5au,0x5a5a5a5au,{0x5a5a5a5au,0x5a5a5a5au,0x5a5a5a5au},0x5a5a5a5au,0x5a5a5a5a,{}};value->input.analog.fill(0x5a5a);value->position={10,20,30};value->model_scale={1.25f,.75f,1.5f};value->motion_multiplier=1.25f;
        value->orientation={std::int16_t(seed*7),std::int16_t(seed*113),std::int16_t(seed*19),0};value->local_impulse={.5f,.25f,-.125f};value->world_impulse={-.25f,.125f,.5f};
        std::memset(ram.data()+actor,0,0x1170);put(ram.data(),0x4badf8,world.paused);ram[0x3243fb]=world.filter_nonselected_input?1:0;ram[0x4baded]=world.selected_actor;put(ram.data(),0x744638,world.frame_shared_counter);
        ram[actor+2]=value->category;ram[actor+3]=value->slot;ram[actor+0x553]=value->movement_enabled;
        put(ram.data(),actor+0x190,value->response_mask);put(ram.data(),actor+0x194,value->response_value);ram[actor+0xc82]=value->motion_override;ram[actor+0xb9e]=value->interaction_marker;ram[actor+0x32]=value->normalized_marker;ram[actor+0xc53]=value->room_marker;
        put(ram.data(),actor+0xd92,value->pending_notice);put(ram.data(),actor+0x54a,value->contact_flags);put(ram.data(),actor+0xbdc,value->frame_value_a);put(ram.data(),actor+0xbde,value->frame_value_b);
        std::memcpy(ram.data()+actor+0xf78,&value->input,48);put(ram.data(),actor+0x38,value->position);put(ram.data(),actor+0x90,value->orientation);put(ram.data(),actor+0xb4,value->model_scale);put(ram.data(),actor+0xf0,value->motion_multiplier);
        put(ram.data(),actor+0xd8,value->local_impulse);put(ram.data(),actor+0xe4,value->world_impulse);
        g::CommonActorFrame frame(world,behavior,pose);behavior.callback=&frame;behavior.id=id;frame.tick(id);behavior.callback=nullptr;
        common_actor_capture=true;call(ram.data(),0x66a2e0,actor);common_actor_capture=false;
        check(!world.busy()&&value->response_mask==get<std::uint32_t>(ram.data(),actor+0x190)&&value->response_value==get<std::uint32_t>(ram.data(),actor+0x194)&&world.frame_shared_counter==get<std::uint16_t>(ram.data(),0x744638),"common callback response and shared counter");
        check(value->movement_enabled==ram[actor+0x553]&&std::memcmp(&value->input,ram.data()+actor+0xf78,48)==0,"common callback exact pause and primary input clear gates");
        check(value->normalized_marker==ram[actor+0x32]&&value->room_marker==ram[actor+0xc53]&&value->motion_override==ram[actor+0xc82]&&value->pending_notice==get<std::uint16_t>(ram.data(),actor+0xd92)&&value->interaction_marker==ram[actor+0xb9e]&&value->frame_value_a==get<std::uint16_t>(ram.data(),actor+0xbdc)&&value->frame_value_b==get<std::uint16_t>(ram.data(),actor+0xbde),"common callback transient fields");
        check(value->contact_flags==get<std::uint16_t>(ram.data(),actor+0x54a)&&std::memcmp(&value->position,ram.data()+actor+0x38,12)==0&&std::memcmp(&value->root_motion_delta,ram.data()+actor+0x4e4,12)==0,"actual common root integration");
        for(const auto pair:{std::pair{value->collision.basis.x,0x50u},std::pair{value->collision.basis.y,0x60u},std::pair{value->collision.basis.z,0x70u},std::pair{value->collision.basis.translation,0x80u}})check(std::memcmp(&pair.first,ram.data()+actor+pair.second,12)==0,"actual common pose basis");
        check(value->collision.pose_ready&&std::memcmp(&value->candidate_direction,ram.data()+actor+0xa8,12)==0&&std::memcmp(&value->local_impulse,ram.data()+actor+0xd8,12)==0&&std::memcmp(&value->world_impulse,ram.data()+actor+0xe4,12)==0,"actual common pose publication and cleared impulses");++common_actor_cases;
    }
    for(unsigned mode=0;mode<2;++mode){
        g::World world(world_profile(),std::make_shared<g::Session>());const auto id=world.spawn_linked(std::make_unique<g::Actor>()).id;const auto value=world.resolve(id);value->room_marker=0xa5;
        g::CommonActorFrame frame(world,behavior,pose);behavior.id=id;behavior.throwing=mode==0;behavior.retire=mode==1;
        bool refused=false;try{frame.tick(id);}catch(...){refused=true;}
        check(refused&&!world.busy()&&value->response_value==(0x12340000u|common_actor_seed)&&value->position.x==float(common_actor_seed%7)*.25f,"partial common frame effects survive failure and release lifetime guard");++common_actor_refusals;behavior.throwing=behavior.retire=false;
        check(world.close()==g::Status::completed,"common failure remains closable");
    }
    g::World world(world_profile(),std::make_shared<g::Session>()),foreign(world_profile(),std::make_shared<g::Session>());const auto id=foreign.spawn_linked(std::make_unique<g::Actor>()).id;g::CommonActorFrame frame(world,behavior,pose);
    bool refused=false;try{frame.tick(id);}catch(const std::runtime_error&){refused=true;}check(refused,"common frame foreign ID refused");++common_actor_refusals;
    check(world.close()==g::Status::completed,"common closure");refused=false;try{frame.tick({});}catch(const std::runtime_error&){refused=true;}check(refused,"closed common callback refused");++common_actor_refusals;
}
