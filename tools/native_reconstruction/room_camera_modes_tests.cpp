#define main room_camera_lower_fixture_main
#include "room_camera_tests.cpp"
#undef main
#include "game/native/gameplay_scenario/room_camera_modes.hpp"
#include "game/native/gameplay_scenario/room_scene_input.hpp"
#include "game/native/gameplay_scenario/room_scene_owner.hpp"
#include "game/native/gameplay_scenario/scene_controls.hpp"
#include "game/native/gameplay_scenario/scene_model_bindings.hpp"
#include "game/native/gameplay_scenario/lighting.hpp"
#include "game/native/gameplay_collision/response.hpp"
#include "game/native/gameplay_world/actor_assets.hpp"
#include "game/native/animation/model.hpp"
#include "runtime/assets/virtual_afs.h"

namespace {
struct SourceTask {std::uint32_t address{},callback{};bool alive{};};
struct BusyProbe final:reo::native::gameplay_tasks::Task {
    s::RoomCameraModes& owner;Fixture& fixture;bool observed{};
    BusyProbe(s::RoomCameraModes& value,Fixture& f):owner(value),fixture(f){}
    void update(reo::native::gameplay_tasks::Scheduler& scheduler,const reo::native::gameplay_tasks::Handle& handle)noexcept override{
        observed=owner.close()==s::CameraModeStatus::busy&&owner.update(128,fixture.fog,fixture.binding)==s::CameraModeStatus::busy;
        (void)scheduler.erase(handle);
    }
};
struct IdleTask final:reo::native::gameplay_tasks::Task {
    void update(reo::native::gameplay_tasks::Scheduler&,const reo::native::gameplay_tasks::Handle&)noexcept override{}
};
struct DebugSink final:s::CameraDisplaySink {
    Sink& sink;explicit DebugSink(Sink& s):sink(s){}
    void viewport(const s::CameraViewport& v,const s::CameraProjectionMatrices& p)override{
        const auto& e=events.at(sink.cursor);const std::array<t::Matrix,4> a{p.perspective,p.scaled,p.first_composite,p.second_composite};
        const std::array<t::Matrix,4> b{e.projection.perspective,e.projection.scaled,e.projection.first_composite,e.projection.second_composite};
        for(unsigned i=0;i<4;++i)for(unsigned c=0;c<4;++c)for(unsigned r=0;r<4;++r)if(std::bit_cast<unsigned>(a[i][c][r])!=std::bit_cast<unsigned>(b[i][c][r])){
            current+=" matrix="+std::to_string(i)+" col="+std::to_string(c)+" row="+std::to_string(r);same(a[i][c][r],b[i][c][r]);}
        sink.viewport(v,p);
    }
    void view(const t::Matrix& m)override{const auto label=current;current+=" view";sink.view(m);current=label;}
};
std::vector<SourceTask> source_tasks;unsigned allocation_limit=32;
void reset_source_tasks(){source_tasks.clear();allocation_limit=32;}
std::shared_ptr<const s::RoomSceneInput> room_input(){
    auto bank=std::make_shared<std::vector<std::byte>>(128);put(*bank,0,64u);put(*bank,4,96u);
    for(unsigned i=0;i<32;++i){(*bank)[64+i]=std::byte(i+20);(*bank)[96+i]=std::byte(i);}
    s::content::ScriptBank scripts(bank,s::content::BankFormat::room_section);
    std::vector<std::byte> records(8);return std::make_shared<const s::RoomSceneInput>(records,scripts);
}
std::shared_ptr<const reo::native::gameplay_collision::response::Grid> empty_floor(){
    std::vector<std::byte> b(48);put(b,8,1000u);put(b,12,1000u);put(b,16,1u);put(b,20,1u);put(b,32,32u);put(b,36,40u);put(b,40,36u);put(b,44,0xffffffffu);
    return std::make_shared<const reo::native::gameplay_collision::response::Grid>(reo::native::gameplay_collision::response::Grid::import(b));
}
void run_source_tasks(Fixture& f){
    for(std::size_t i=0;i<source_tasks.size();++i)if(source_tasks[i].alive){const auto task=source_tasks[i];
        invoke(f.memory,task.callback,task.address);
    }
}
void source_actor(Fixture& f,const t::Matrix& joint){
    constexpr unsigned actor=0x4a5c30,model=0x1500000,node=0x1501000;
    transform_write(f.memory.data(),actor+0x34,model);transform_write(f.memory.data(),model+0x82c,node);transform_write(f.memory.data(),node,joint);
}
void install_source_proxy(Fixture& f,const t::Matrix& model){
    constexpr unsigned baseptr=0x1700000,map=0x1709000,record=0x1710000;
    transform_write(f.memory.data(),0x324424,baseptr);transform_write(f.memory.data(),baseptr+0x8000,map);
    for(unsigned i=0;i<16;++i)f.memory[map+i]=std::uint8_t(i+20);
    transform_write(f.memory.data(),0x3b5150,std::uint16_t(127));transform_write(f.memory.data(),0x3b5160,record);
    f.memory[record+0x30]=0;transform_write(f.memory.data(),record+0x40,5u);transform_write(f.memory.data(),record+0x4c,6u);transform_write(f.memory.data(),record+0x54,2u);
    transform_write(f.memory.data(),0x49eef0+0xb20+64*6,model);transform_write(f.memory.data(),0x49eef0+0xb20+64*25,model);
}
void seed_common(Fixture& f,unsigned mode,unsigned restart){
    auto state=f.sequences.snapshot();state.phase=std::uint8_t(mode);state.restart_byte=std::uint8_t(restart);state.actor=0;state.condition_id=7;check(f.sequences.restore(state));
    f.memory[base+0x25]=std::uint8_t(mode);f.memory[base+2]=std::uint8_t(restart);f.memory[base+3]=7;f.memory[base+0x24]=0;
    f.world.primary(0)->motion_class=10;f.memory[0x4a5c30+0x54f]=10;
}
void step_modes(Fixture& f,s::RoomCameraModes& camera){
    events.clear();f.sink.cursor=0;invoke(f.memory,0x5be9a0);
    DebugSink sink(f.sink);s::CameraDisplayBinding binding(f.mode,f.projection,f.display,sink);
    const auto result=camera.update(128,f.fog,binding);
    if(result!=s::CameraModeStatus::completed){f.sink.cursor=0;binding.publish(f.parameters);}
    check(result==s::CameraModeStatus::completed);
    check(f.sink.cursor==events.size());
    const auto state=f.sequences.snapshot();check(state.phase==f.memory[base+0x25]&&state.restart_byte==f.memory[base+2]&&state.condition_id==f.memory[base+3]);
    check(state.selected_id==f.memory[base+5]&&state.selection==read<std::uint16_t>(f.memory,base+6));
    for(unsigned i=0;i<32;++i)check(state.active[i]==f.memory[base+0x34+0x198u*i]);
}
void mode_cases(const std::filesystem::path& archive){
    auto bytes=synthetic();Fixture f(bytes);f.reset(0,128);f.position({0,0,0});f.select(1);f.tick(128);
    reo::native::gameplay_tasks::Scheduler scheduler;s::Lighting lighting;
    reo::native::gameplay_actors::EntityStore entities({64});s::SceneModelBindings bindings(f.models,entities);s::SceneControls controls;
    auto input=room_input();auto floor=empty_floor();
    reo::native::gameplay_collision::ownership::Proxies proxies(controls.records());
    s::FlagState flags;std::uint16_t room=0;s::SceneMatrixPrograms programs(controls,f.models,bindings,flags,room);
    s::RoomSceneGlobals globals;auto installed=s::RoomSceneOwner::install(input,controls,proxies,f.models,programs,globals);
    check(installed.status==s::RoomSceneStatus::completed&&installed.owner&&installed.owner->bound_to(*input,controls));
    auto state=f.models.state();(void)state;
    t::Matrix matrix=t::identity();matrix[3][0]=23;matrix[3][1]=41;matrix[3][2]=-17;
    check(f.models.pose(6,matrix)==s::ModelStatus::completed&&f.models.pose(25,matrix)==s::ModelStatus::completed);
    s::ControlTypeZero zero;zero.matrix_program=s::ControlMatrixProgramResource{s::ModelReference(6),2,0};zero.destination=s::ControlRouteDestination{6,2};
    s::SceneControl control;control.authored_id=5;control.body=zero;const auto control_id=controls.append(control);check(bool(control_id));
    install_source_proxy(f,matrix);auto actor=f.world.primary(0);actor->scene_model=s::ModelReference(25);actor->interaction_subselector=255;actor->model_scale.y=1.5f;
    f.memory[0x4a5c30+0xabb]=25;f.memory[0x4a5c30+0xad1]=255;transform_write(f.memory.data(),0x4a5c30+0xb8,1.5f);
    s::RoomCameraModes owner(f.world,scheduler,f.sequences,f.parameters,lighting,*installed.owner,controls,f.models,bindings,input,floor);
    w::World foreign_world(profile(),std::make_shared<w::Session>());check(owner.bound_to(f.world)&&!owner.bound_to(foreign_world));
    // Mode2 immediately spawns real linked tracking and light callbacks.
    reset_source_tasks();seed_common(f,2,1);step_modes(f,owner);check(source_tasks.size()==2&&scheduler.size()==2);
    run_source_tasks(f);check(scheduler.run(reo::native::gameplay_tasks::Pass::update).status==reo::native::gameplay_tasks::Status::completed);
    check(owner.status()==s::CameraModeStatus::completed);same(f.parameters.pose.eye,read<t::Vector>(f.memory,0x324138));same(f.parameters.pose.aim,read<t::Vector>(f.memory,0x324144));
    same(f.parameters.lens,read<float>(f.memory,0x324180));check(f.parameters.pose.roll==read<unsigned>(f.memory,0x32418c));
    check(lighting.primary_count()==1);const auto light=lighting.primary()[0];check(light.active&&light.tag==255&&light.mode==4);
    const auto source_light=read<unsigned>(f.memory,source_tasks[1].address+0x28);check(source_light);same(t::Vector{light.descriptor.position[0],light.descriptor.position[1],light.descriptor.position[2]},read<t::Vector>(f.memory,source_light+0x24));
    check(f.world.session().resource_hide_selected==f.memory[0x4b9d10]&&f.world.session().resource_hide_others==f.memory[0x4b9d11]&&f.world.session().resource_hide_remaining[0]==f.memory[0x4b9d12]&&f.world.session().resource_hide_remaining[1]==f.memory[0x4b9d13]);
    auto reset=f.sequences.snapshot();reset.phase=0;check(f.sequences.restore(reset));f.memory[base+0x25]=0;run_source_tasks(f);scheduler.run(reo::native::gameplay_tasks::Pass::update);check(scheduler.size()==0&&lighting.primary_count()==0);
    // Type2's +4C/+54 and +44/+48 are independent authored fields.
    for(const auto selector:std::array<std::uint8_t,2>{255,7})for(unsigned index=0;index<4;++index){
        current="mode2 type2 selector="+std::to_string(selector)+" offset="+std::to_string(index);
        s::ControlTypeTwo two;two.selector=7;two.camera_anchor=6;two.camera_offset=std::uint8_t(index);
        two.model_reference=s::ControlModelReference{s::ModelReference(6),std::uint32_t(3-index)};
        control.body=two;check(controls.replace(*control_id,control)==s::ControlStatus::completed);
        constexpr unsigned record=0x1710000;f.memory[record+0x30]=2;transform_write(f.memory.data(),record+0x50,7u);
        transform_write(f.memory.data(),record+0x44,6u);transform_write(f.memory.data(),record+0x48,std::uint32_t(3-index));
        f.memory[record+0x54]=std::uint8_t(index);actor->interaction_subselector=selector;f.memory[0x4a5c30+0xad1]=selector;
        reset_source_tasks();seed_common(f,2,1);step_modes(f,owner);run_source_tasks(f);scheduler.run(reo::native::gameplay_tasks::Pass::update);
        check(owner.status()==s::CameraModeStatus::completed&&lighting.primary_count()==1);
        same(f.parameters.pose.eye,read<t::Vector>(f.memory,0x324138));same(f.parameters.pose.aim,read<t::Vector>(f.memory,0x324144));
        const auto actual=lighting.primary()[0];const auto original=read<unsigned>(f.memory,source_tasks[1].address+0x28);check(original);
        same(t::Vector{actual.descriptor.position[0],actual.descriptor.position[1],actual.descriptor.position[2]},read<t::Vector>(f.memory,original+0x24));
        reset=f.sequences.snapshot();reset.phase=0;check(f.sequences.restore(reset));f.memory[base+0x25]=0;run_source_tasks(f);scheduler.run(reo::native::gameplay_tasks::Pass::update);
        check(scheduler.size()==0&&lighting.primary_count()==0);
    }
    control.body=zero;check(controls.replace(*control_id,control)==s::ControlStatus::completed);f.memory[0x1710030]=0;f.memory[0x1710054]=2;
    actor->interaction_subselector=255;f.memory[0x4a5c30+0xad1]=255;
    // Mode1 tracks the owned model joint and preserves the source yaw basis.
    auto source=std::make_shared<const reo::assets::Source>(archive);w::ActorAssets assets(source);auto model=assets.read_primary(0,0,0)->make_instance();check(model&&model->nodes().size()>3);model->rebuild(t::identity());actor->model=model;
    t::Matrix joint=t::identity();joint[3][0]=70;joint[3][1]=80;joint[3][2]=90;const reo::native::animation::JointPosePatch patch{3,joint};model->patch_world_poses(std::span(&patch,1));source_actor(f,joint);
    reset_source_tasks();seed_common(f,1,1);actor->orientation[1]=0x1000;transform_write(f.memory.data(),0x4a5c30+0x92,std::int16_t(0x1000));step_modes(f,owner);run_source_tasks(f);scheduler.run(reo::native::gameplay_tasks::Pass::update);
    check(owner.status()==s::CameraModeStatus::completed);same(f.parameters.pose.eye,read<t::Vector>(f.memory,0x324138));same(f.parameters.pose.aim,read<t::Vector>(f.memory,0x324144));
    joint[3][2]+=20;
    const reo::native::animation::JointPosePatch moved{3,joint};model->patch_world_poses(std::span(&moved,1));source_actor(f,joint);
    actor->orientation[1]=0x2000;transform_write(f.memory.data(),0x4a5c30+0x92,std::int16_t(0x2000));run_source_tasks(f);scheduler.run(reo::native::gameplay_tasks::Pass::update);
    same(f.parameters.pose.eye,read<t::Vector>(f.memory,0x324138));same(f.parameters.pose.aim,read<t::Vector>(f.memory,0x324144));
    reset=f.sequences.snapshot();reset.phase=0;check(f.sequences.restore(reset));f.memory[base+0x25]=0;run_source_tasks(f);scheduler.run(reo::native::gameplay_tasks::Pass::update);
    for(const auto angle:std::array<std::uint16_t,10>{0,1,0x123,0x1000,0x2345,0x4000,0x5555,0x8000,0xbad0,0xffff}){
        current="mode1 yaw="+std::to_string(angle);reset_source_tasks();seed_common(f,1,1);
        actor->orientation[1]=angle;actor->class_marker=angle&1?2:0;f.memory[0x4a5c30+0xb9b]=actor->class_marker;
        transform_write(f.memory.data(),0x4a5c30+0x92,std::int16_t(angle));step_modes(f,owner);
        run_source_tasks(f);scheduler.run(reo::native::gameplay_tasks::Pass::update);
        check(owner.status()==s::CameraModeStatus::completed);same(f.parameters.pose.eye,read<t::Vector>(f.memory,0x324138));same(f.parameters.pose.aim,read<t::Vector>(f.memory,0x324144));
        joint[3][0]+=3;joint[3][2]-=7;const reo::native::animation::JointPosePatch moved_joint{3,joint};model->patch_world_poses(std::span(&moved_joint,1));source_actor(f,joint);
        actor->orientation[1]=std::uint16_t(angle+0x2222);transform_write(f.memory.data(),0x4a5c30+0x92,std::int16_t(angle+0x2222));
        run_source_tasks(f);scheduler.run(reo::native::gameplay_tasks::Pass::update);same(f.parameters.pose.eye,read<t::Vector>(f.memory,0x324138));same(f.parameters.pose.aim,read<t::Vector>(f.memory,0x324144));
        reset=f.sequences.snapshot();reset.phase=0;check(f.sequences.restore(reset));f.memory[base+0x25]=0;run_source_tasks(f);scheduler.run(reo::native::gameplay_tasks::Pass::update);
        check(scheduler.size()==0&&lighting.primary_count()==0);
    }
    // Mode5 curve delay/duration and repeated additive camera publication.
    reset_source_tasks();auto seq=f.sequences.snapshot();seq.phase=5;seq.restart_byte=0;seq.mode=0;seq.parameter_a=1;seq.parameter_b=8;seq.fraction=.75f;check(f.sequences.restore(seq));
    f.memory[base+0x25]=5;f.memory[base+2]=0;f.memory[base+0x27]=0;transform_write(f.memory.data(),base+0x2c,std::uint16_t(1));transform_write(f.memory.data(),base+0x2e,std::uint16_t(8));transform_write(f.memory.data(),base+0x30,.75f);
    step_modes(f,owner);check(source_tasks.size()==1&&scheduler.size()==1);
    for(unsigned i=0;i<12&&scheduler.size();++i){run_source_tasks(f);scheduler.run(reo::native::gameplay_tasks::Pass::update);same(f.parameters.pose.eye,read<t::Vector>(f.memory,0x324138));same(f.parameters.pose.aim,read<t::Vector>(f.memory,0x324144));}
    // Controlled authored state: source sentinel and countdown transitions.
    for(const auto [mode,selection,actor_status]:std::array<std::array<unsigned,3>,9>{{
        {{3,0,0}},{{3,7,0}},{{4,0,0}},{{4,1,0}},{{4,2,0}},
        {{4,0xfffe,0}},{{4,0xffff,0}},{{4,0xffff,0x20000}},{{4,0xfffe,0x20000}}
    }}){
        current="transition mode="+std::to_string(mode)+" selection="+std::to_string(selection)+" status="+std::to_string(actor_status);
        auto value=f.sequences.snapshot();value.phase=std::uint8_t(mode);value.selected_id=1;value.selection=std::uint16_t(selection);value.condition_id=7;value.active[1]=1;
        check(f.sequences.restore(value));f.memory[base+0x25]=std::uint8_t(mode);f.memory[base+5]=1;f.memory[base+3]=7;
        transform_write(f.memory.data(),base+6,std::uint16_t(selection));f.memory[base+0x34+0x198]=1;
        actor->status=actor_status;transform_write(f.memory.data(),0x4a5c30+0xba0,actor_status);
        f.world.selected_frame_marker=0;f.memory[0x4bae89]=0;step_modes(f,owner);
        check(f.world.selected_frame_marker==f.memory[0x4bae89]);
    }
    auto foreign=room_input();bool rejected=false;
    try{s::RoomCameraModes wrong(f.world,scheduler,f.sequences,f.parameters,lighting,*installed.owner,controls,f.models,bindings,foreign,floor);}
    catch(const std::invalid_argument&){rejected=true;}
    check(rejected);
    auto probe=std::make_shared<BusyProbe>(owner,f);check(scheduler.create(probe).status==reo::native::gameplay_tasks::Status::completed);
    check(scheduler.run(reo::native::gameplay_tasks::Pass::update).status==reo::native::gameplay_tasks::Status::completed&&probe->observed);
    std::vector<reo::native::gameplay_tasks::Handle> occupied;
    for(unsigned i=0;i<reo::native::gameplay_tasks::Scheduler::capacity;++i){const auto made=scheduler.create(std::make_shared<IdleTask>());check(made.status==reo::native::gameplay_tasks::Status::completed);occupied.push_back(made.handle);}
    current="mode2 pre-pool eye";same(f.parameters.pose.eye,read<t::Vector>(f.memory,0x324138));
    current="mode2 pre-pool aim";same(f.parameters.pose.aim,read<t::Vector>(f.memory,0x324144));
    current="mode2 pre-pool up";same(f.parameters.pose.up,read<t::Vector>(f.memory,0x32415c));
    current="mode2 pre-pool lens";same(f.parameters.lens,read<float>(f.memory,0x324180));same(f.parameters.far_plane,read<float>(f.memory,0x324178));same(f.parameters.near_plane,read<float>(f.memory,0x32417c));check(f.parameters.pose.roll==read<unsigned>(f.memory,0x32418c));
    current="mode2 pre-pool transform1";same(f.projection.first_transform,read<t::Matrix>(f.memory,0x70003f80));
    current="mode2 pre-pool transform2";same(f.projection.second_transform,read<t::Matrix>(f.memory,0x294dc0));
    current="mode2 pre-pool source identity";same(t::identity(),read<t::Matrix>(f.memory,0x294e00));
    current="mode2 task pool full";
    reset_source_tasks();allocation_limit=0;seed_common(f,2,1);step_modes(f,owner);
    check(scheduler.size()==occupied.size()&&f.sequences.snapshot().phase==0);
    for(const auto& handle:occupied)check(scheduler.erase(handle)==reo::native::gameplay_tasks::Status::completed);
    // With no canonical AD1 producer, light initialization refuses while the
    // already-created tracking task and its effects are retained.
    {s::RoomCameraModes partial(f.world,scheduler,f.sequences,f.parameters,lighting,*installed.owner,controls,f.models,bindings,input,floor);
        current="mode2 partial refusal";reset_source_tasks();seed_common(f,2,1);actor->interaction_subselector.reset();step_modes(f,partial);run_source_tasks(f);
        check(scheduler.run(reo::native::gameplay_tasks::Pass::update).status==reo::native::gameplay_tasks::Status::completed);
        check(partial.status()==s::CameraModeStatus::unavailable&&scheduler.size()==1);
        check(partial.close()==s::CameraModeStatus::completed&&scheduler.size()==0);f.memory[base+0x25]=0;run_source_tasks(f);
        actor->interaction_subselector=255;
    }
    // A task retaining an explicitly retired room must surface a sticky
    // failure, rather than following a stale proxy or publishing success.
    current="mode2 retired scene";reset_source_tasks();seed_common(f,2,1);step_modes(f,owner);check(scheduler.size()==2);
    installed.owner->close();check(!installed.owner->bound_to(*input,controls));
    check(scheduler.run(reo::native::gameplay_tasks::Pass::update).status==reo::native::gameplay_tasks::Status::completed);
    check(owner.status()==s::CameraModeStatus::unavailable&&scheduler.size()==0);
    check(owner.update(128,f.fog,f.binding)==s::CameraModeStatus::unavailable);
    check(owner.close()==s::CameraModeStatus::completed&&owner.status()==s::CameraModeStatus::closed&&!owner.bound_to(f.world));
}
}
void mode_port_allocate(std::uint8_t* m,R5900Context* c,PS2Runtime*){
    if(source_tasks.size()>=allocation_limit)SET_GPR_U32(c,2,0);
    else{const auto address=std::uint32_t(0x1b00000+source_tasks.size()*0x200);std::memset(m+address,0,0x100);source_tasks.push_back({address,GPR_U32(c,5),true});SET_GPR_U32(c,2,address);}c->pc=GPR_U32(c,31);
}
void mode_port_retire(std::uint8_t*,R5900Context* c,PS2Runtime*){for(auto& task:source_tasks)if(task.address==GPR_U32(c,4))task.alive=false;c->pc=GPR_U32(c,31);}
void mode_port_floor(std::uint8_t* m,R5900Context* c,PS2Runtime*){m[GPR_U32(c,5)]=255;c->pc=GPR_U32(c,31);}
int main(int argc,char**argv)try{check(argc==2);mode_cases(std::filesystem::path(argv[1]));std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";return 0;}catch(const std::exception&e){std::cerr<<e.what()<<'\n';return 1;}
