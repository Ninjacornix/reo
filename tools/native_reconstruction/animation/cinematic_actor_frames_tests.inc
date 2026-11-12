#include "game/native/gameplay_world/cinematic_actor_frames.hpp"
#include "game/native/gameplay_world/scene_primary_actors.hpp"
#include "game/native/gameplay_world/auxiliary_actors.hpp"
std::uint64_t cinematic_frame_cases{},cinematic_frame_calls{},cinematic_frame_restores{},cinematic_frame_mutations{},cinematic_frame_refusals{};
bool cinematic_capture{};
using CinematicCall=std::array<std::uint32_t,3>;
std::vector<CinematicCall> cinematic_original_calls;
std::function<void(std::uint8_t*,R5900Context*)> cinematic_original_mutation;
void cinematic_frame_original_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(cinematic_capture)cinematic_original_calls.push_back({context->pc,GPR_U32(context,4),context->pc==0x61b1a0?GPR_U32(context,5):0u});
    original_transform_port(memory,context,runtime);
}
void cinematic_behavior_original_extra(std::uint8_t* memory,R5900Context* context){
    if(cinematic_capture&&cinematic_original_mutation)cinematic_original_mutation(memory,context);
}
struct CinematicEntry {g::actors::EntityId id;unsigned at{},work{},node_base{};std::optional<std::uint8_t> profile;};
struct CinematicBehaviorFixture final:g::Services {
    CommonBehaviorFixture base;g::CinematicActorFrames* frames{};std::vector<CinematicEntry>* entries{};
    std::vector<CinematicCall> expected;std::function<void(g::World&,g::Actor&)> mutation;
    void begin_offline_frame(g::World& world)override{base.begin_offline_frame(world);}
    void run(g::Stage stage,g::World& world,g::Actor& value)override{
        const auto found=std::find_if(entries->begin(),entries->end(),[&](const auto& entry){return world.resolve(entry.id).get()==&value;});
        check(found!=entries->end(),"cinematic frame uses the actual temporary/auxiliary actor");
        check(frames->run().status==g::CinematicFrameStatus::busy&&frames->close()==g::CinematicFrameStatus::busy&&world.close()==g::Status::busy,"cinematic traversal reentry/closure guards");
        check(world.scene_primary_actors().initialize()==g::ScenePrimaryStatus::busy,"fixed cinematic generation reset is protected during callbacks");
        if(value.category==1)check(world.auxiliary_actors().reset()==g::AuxiliaryStatus::busy,"auxiliary reset is protected during its list pass");
        expected.push_back({0x61a6a0,found->at,0});
        if(found->profile){
            expected.push_back({0x61b1a0,found->work+0x820,std::array<unsigned,4>{0x70f628,0x70f630,0x70f638,0x70f640}[*found->profile]});
            const auto& links=value.model->links();
            if(*found->profile==0)check(links[21].child==22&&!links[36].sibling,"actual ordinary restore precedes behavior/prelude");
            else check(!links[*found->profile==2?64:62].sibling,"actual high restore precedes behavior/prelude");
        }
        expected.push_back({0x66a2e0,found->at,0});base.run(stage,world,value);if(mutation)mutation(world,value);
    }
    bool remote_motion(g::World& w,g::Actor& v)override{return base.remote_motion(w,v);}
    bool find_grid(g::World& w,g::Actor& v,std::int8_t& grid)override{return base.find_grid(w,v,grid);}
    void switch_grid(g::World& w,std::int32_t next,std::int32_t prev)override{base.switch_grid(w,next,prev);}
    float grid_response(g::World& w,std::uint8_t grid)override{return base.grid_response(w,grid);}
};
void cinematic_export_actor(const g::Actor& value,const CinematicEntry& entry,std::vector<std::uint8_t>& ram){
    const auto at=entry.at;std::fill_n(ram.data()+at,0x10e0,0);
    ram[at]=value.active;ram[at+1]=value.visible;ram[at+2]=value.category;ram[at+3]=value.slot;ram[at+0xc53]=value.room_marker;
    put(ram.data(),at+0x38,value.position);put(ram.data(),at+0x90,value.orientation);put(ram.data(),at+0xb4,value.model_scale);put(ram.data(),at+0xf0,value.motion_multiplier);
    put(ram.data(),at+0x190,value.response_mask);put(ram.data(),at+0x194,value.response_value);ram[at+0x553]=value.movement_enabled;
    put(ram.data(),at+0x54a,value.contact_flags);ram[at+0x54d]=value.model_pose_class;ram[at+0xb98]=value.character;put(ram.data(),at+0xbb4,value.model_variant);ram[at+0xbbc]=value.appearance_variant;
    ram[at+0xc82]=value.motion_override;ram[at+0xb9e]=value.interaction_marker;ram[at+0x32]=value.normalized_marker;
    put(ram.data(),at+0xd92,value.pending_notice);put(ram.data(),at+0xbdc,value.frame_value_a);put(ram.data(),at+0xbde,value.frame_value_b);std::memcpy(ram.data()+at+0xf78,&value.input,48);
    put(ram.data(),at+0xd8,value.local_impulse);put(ram.data(),at+0xe4,value.world_impulse);put(ram.data(),at+0x34,entry.work);
    if(value.model)for(unsigned i=0;i<value.model->links().size();++i){
        put(ram.data(),entry.work+0x820+4*i,entry.node_base+400*i);
        const auto& row=value.model->links()[i];for(auto [link,offset]:{std::pair{row.parent,0xc8u},std::pair{row.child,0xd0u},std::pair{row.sibling,0xccu}})put(ram.data(),entry.node_base+400*i+offset,link?entry.node_base+400*unsigned(*link):0u);
    }
}
void cinematic_actor_frame_tests(const std::vector<std::vector<std::byte>>& skeletons,std::vector<std::uint8_t>& ram){
    check(skeletons.size()==4,"qualified actual secondary-link model package");std::array<std::shared_ptr<const a::Skeleton>,4> definitions;
    for(unsigned i=0;i<4;++i)definitions[i]=a::Skeleton::import_raw(skeletons[i]);
    const reo::native::gameplay_collision::response::Grid floors{};g::GridSurfaceOrientation pose(floors);
    for(unsigned seed=0;seed<256;++seed){
        location="cinematic actor traversal="+std::to_string(seed);
        auto profile=world_profile();profile.entities.capacity=64;g::World world(profile,std::make_shared<g::Session>());
        auto& temporary=world.scene_primary_actors();check(temporary.initialize()==g::ScenePrimaryStatus::completed,"actual eight temporary actors initialized");
        const auto primary=world.spawn_primary(0,std::make_unique<g::Actor>()).id;world.resolve(primary)->active=true;world.resolve(primary)->position.x=42;
        const auto linked=world.linked_models().allocate(true).id;world.resolve(linked)->active=true;world.resolve(linked)->position.x=99;
        world.paused=std::bit_cast<std::int8_t>(std::array<std::uint8_t,4>{0,1,127,255}[(seed/4)%4]);world.filter_nonselected_input=bool(seed&16);world.selected_actor=std::uint8_t(seed%8);
        put(ram.data(),0x4badf8,world.paused);ram[0x3243fb]=world.filter_nonselected_input;ram[0x4baded]=world.selected_actor;
        std::vector<CinematicEntry> entries;CinematicBehaviorFixture behavior;behavior.entries=&entries;
        for(unsigned ordinal=0;ordinal<18;++ordinal){
            const auto id=ordinal<8?temporary.identity_at(ordinal):world.auxiliary_actors().allocate(1).id;const auto value=world.resolve(id);check(bool(value),"actual fixed/auxiliary construction capacity");
            value->active=ordinal<8?bool((seed>>ordinal)&1):(seed+ordinal)%5!=0;value->visible=(seed+ordinal)%7!=0;
            value->category=std::uint8_t(ordinal<8?0:1);value->character=std::uint8_t(ordinal<8?(ordinal%3?0:7):5);value->model_pose_class=std::uint8_t(ordinal<8?ordinal%2:(ordinal%4==0?1:0));value->model_variant=std::uint16_t(ordinal>=8&&ordinal%4==0?54:0);
            if(ordinal<8&&value->character==7)value->model=std::make_shared<a::Instance>(definitions[value->model_pose_class]);
            if(ordinal>=8&&value->model_variant==54)value->model=std::make_shared<a::Instance>(definitions[2]);
            value->room_marker=0xa5;value->position={10,20,30};value->model_scale={1.25f,.75f,1.5f};value->motion_multiplier=1.25f;
            value->orientation={std::int16_t(ordinal*7),std::int16_t(ordinal*113),std::int16_t(ordinal*19),0};value->response_mask=value->response_value=0xffffffff;
            value->contact_flags=std::uint16_t(seed&32?0x40:0);value->pending_notice=value->frame_value_a=value->frame_value_b=65535;value->normalized_marker=value->motion_override=value->interaction_marker=255;value->movement_enabled=99;
            const unsigned at=ordinal<8?0x600000+ordinal*0x10e0:0x800000+(ordinal-8)*0x2000;
            const CinematicEntry entry{id,at,0xa00000+0x2000*ordinal,0xc00000+0x10000*ordinal,g::select_secondary_pose_links(*value).profile};entries.push_back(entry);cinematic_export_actor(*value,entry,ram);
        }
        for(unsigned index=8;index<18;++index)put(ram.data(),entries[index].at+0x1c,index+1<18?entries[index+1].at:0u);
        put(ram.data(),0x38edd0,0x600000u);put(ram.data(),0x3b59f0,entries[8].at);
        g::CinematicActorFrames frames(world,behavior,pose);behavior.frames=&frames;
        bool duplicate{};try{g::CinematicActorFrames invalid(world,behavior,pose);}catch(const std::invalid_argument&){duplicate=true;}check(duplicate,"one cinematic frame owner per World");
        common_actor_pool_capture=true;cinematic_original_calls.clear();cinematic_original_mutation={};
        // Activate a later fixed record; the source reads its activity when reached.
        if(seed%17==0){
            const auto later=entries[7].id;world.resolve(entries[0].id)->active=true;ram[entries[0].at]=1;world.resolve(later)->active=false;ram[entries[7].at]=0;
            behavior.mutation=[&,later](g::World& w,g::Actor& v){if(&v==w.resolve(entries[0].id).get())w.resolve(later)->active=true;};
            cinematic_original_mutation=[&](std::uint8_t* memory,R5900Context* context){if(GPR_U32(context,4)==entries[0].at)memory[entries[7].at]=1;};
        }
        unsigned expected_auxiliary=10;
        // A fixed callback can clear the auxiliary list before its head is read.
        if(seed%31==1){
            world.resolve(entries[0].id)->active=true;ram[entries[0].at]=1;
            behavior.mutation=[&](g::World& w,g::Actor& v){if(&v==w.resolve(entries[0].id).get())check(w.auxiliary_actors().reset()==g::AuxiliaryStatus::completed,"fixed callback auxiliary reset before head load");};
            cinematic_original_mutation=[&](std::uint8_t* memory,R5900Context* context){if(GPR_U32(context,4)==entries[0].at)put(memory,0x3b59f0,0u);};expected_auxiliary=0;
        }else if(seed%29==2){
            world.resolve(entries[8].id)->active=true;ram[entries[8].at]=1;
            behavior.mutation=[&](g::World& w,g::Actor& v){if(&v==w.resolve(entries[8].id).get())check(w.auxiliary_actors().release(entries[9].id)==g::AuxiliaryStatus::completed,"auxiliary callback retires its next actor");};
            cinematic_original_mutation=[&](std::uint8_t* memory,R5900Context* context){if(GPR_U32(context,4)==entries[8].at)put(memory,entries[8].at+0x1c,entries[10].at);};expected_auxiliary=9;
        }
        for(auto& entry:entries)entry.profile=g::select_secondary_pose_links(*world.resolve(entry.id)).profile;
        const auto result=frames.run();if(behavior.mutation)++cinematic_frame_mutations;common_actor_capture=cinematic_capture=true;call(ram.data(),0x5ecae0,0);common_actor_capture=cinematic_capture=common_actor_pool_capture=false;cinematic_original_mutation={};
        check(result.status==g::CinematicFrameStatus::completed&&result.temporary_visits==8&&result.auxiliary_visits==expected_auxiliary&&!world.busy()&&behavior.expected==cinematic_original_calls,"complete actual temporary/auxiliary frame order, late head and post-callback next observation");
        const auto restores=std::count_if(cinematic_original_calls.begin(),cinematic_original_calls.end(),[](const auto& c){return c[0]==0x61b1a0;});
        check(result.called==(behavior.expected.size()-std::size_t(restores))/2&&result.links_restored==std::size_t(restores),"cinematic frame restoration and completed call counts");
        for(const auto& entry:entries){const auto value=world.resolve(entry.id);if(!value)continue;
            check(std::memcmp(&value->position,ram.data()+entry.at+0x38,12)==0&&value->response_value==get<std::uint32_t>(ram.data(),entry.at+0x194)&&value->contact_flags==get<std::uint16_t>(ram.data(),entry.at+0x54a),"cinematic actual common frame effects");
            if(value->collision.pose_ready)for(const auto pair:{std::pair{value->collision.basis.x,0x50u},std::pair{value->collision.basis.y,0x60u},std::pair{value->collision.basis.z,0x70u},std::pair{value->collision.basis.translation,0x80u}})check(std::memcmp(&pair.first,ram.data()+entry.at+pair.second,12)==0,"cinematic real root/basis publication");
        }
        check(world.resolve(primary)->position.x==42&&world.resolve(linked)->position.x==99,"canonical primary and linked-model populations are outside this traversal");
        cinematic_frame_calls+=result.called;cinematic_frame_restores+=result.links_restored;++cinematic_frame_cases;
        check(frames.close()==g::CinematicFrameStatus::completed&&frames.run().status==g::CinematicFrameStatus::closed&&world.close()==g::Status::completed,"cinematic owner closure");
    }
    CommonBehaviorFixture failure;g::World world(world_profile(),std::make_shared<g::Session>());
    g::CinematicActorFrames empty(world,failure,pose);check(empty.run().status==g::CinematicFrameStatus::completed&&empty.run().temporary_visits==0,"absent cinematic populations need no fabricated actors");
    check(empty.close()==g::CinematicFrameStatus::completed,"empty cinematic owner closes");g::CinematicActorFrames frames(world,failure,pose);
    check(empty.close()==g::CinematicFrameStatus::completed&&frames.run().status==g::CinematicFrameStatus::completed,"closed old owner cannot unbind its replacement");
    auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed,"failure scene initialized");const auto id=pool.identity_at(0);const auto value=world.resolve(id);
    value->active=value->visible=true;value->character=7;value->response_value=0xffffffff;
    const auto unavailable=frames.run();check(unavailable.status==g::CinematicFrameStatus::unavailable&&unavailable.failed==id&&unavailable.called==0&&value->response_value==0xffffffff&&!world.busy(),"required restoration failure stops before common prelude and releases guards");++cinematic_frame_refusals;
    value->character=0;value->room_marker=0xa5;failure.throwing=true;common_actor_seed=3;bool threw{};
    try{(void)frames.run();}catch(int){threw=true;}
    check(threw&&!world.busy()&&value->response_value==0x12340003u&&value->position.x==.75f,"provider failure preserves completed behavior prefix and releases outer/common guards");++cinematic_frame_refusals;
    check(frames.close()==g::CinematicFrameStatus::completed&&world.close()==g::Status::completed&&frames.run().status==g::CinematicFrameStatus::closed,"failed cinematic pass remains closable");
    g::World retiring_world(world_profile(),std::make_shared<g::Session>());const auto retiring_id=retiring_world.auxiliary_actors().allocate(1).id;const auto retiring=retiring_world.resolve(retiring_id);
    retiring->active=retiring->visible=true;retiring->category=1;retiring->room_marker=0xa5;
    std::vector<CinematicEntry> retiring_entries{{retiring_id,0,0,0,{}}};CinematicBehaviorFixture retiring_behavior;retiring_behavior.entries=&retiring_entries;
    g::CinematicActorFrames retiring_frames(retiring_world,retiring_behavior,pose);retiring_behavior.frames=&retiring_frames;
    retiring_behavior.mutation=[&](g::World& w,g::Actor&){check(w.auxiliary_actors().release(retiring_id)==g::AuxiliaryStatus::completed,"actual current auxiliary retirement");};
    bool retired_failure{};try{(void)retiring_frames.run();}catch(const std::runtime_error&){retired_failure=true;}
    check(retired_failure&&!retiring_world.busy()&&!retiring_world.resolve(retiring_id)&&retiring->response_value==0x12340003u&&retiring_world.auxiliary_actors().remaining()==10,"current callback retirement is explicit failure with retained prefix and released guards");++cinematic_frame_refusals;
    check(retiring_frames.close()==g::CinematicFrameStatus::completed&&retiring_world.close()==g::Status::completed,"current-retirement failure remains closable");
}
