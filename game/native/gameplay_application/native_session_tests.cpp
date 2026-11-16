#include "native_session.hpp"
#include "session_rooms.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
#include "../gameplay_scenario/room_camera_records.hpp"
#include "runtime/assets/virtual_afs.h"
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace application=reo::native::gameplay_application;
namespace scenario=reo::native::gameplay_scenario;
namespace world=reo::native::gameplay_world;
namespace update=reo::native::gameplay_update;
namespace {
std::size_t checks{},owned_rooms{},script_steps{},frame_refusals{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("NativeSession check at "+std::to_string(at.line()));
}
struct Notifications final:scenario::FlagNotifications {
    bool changed(const scenario::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const scenario::StridedFlagChange&)noexcept override{std::terminate();}
};
struct Memory final:reo::assets::PositionedSource {
    std::vector<std::uint8_t> bytes;
    std::uint64_t size()const noexcept override{return bytes.size();}
    std::size_t read(std::uint64_t offset,std::size_t count,void* destination)const override{
        if(offset>bytes.size()||count>bytes.size()-offset)throw std::runtime_error("Fixture range");
        std::memcpy(destination,bytes.data()+offset,count);return count;
    }
};
world::Profile profile(){world::Profile value;value.layouts.push_back({});return value;}
std::shared_ptr<const reo::assets::Source> fixture_archive(){
    auto memory=std::make_shared<Memory>();memory->bytes.resize(6*4096);
    auto& bytes=memory->bytes;
    std::memcpy(bytes.data(),"AFS\0",4);reo::assets::put32(bytes.data()+4,5);
    const std::array names{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs"};
    for(unsigned i=0;i<5;++i){const auto base=4096*(i+1);
        reo::assets::put32(bytes.data()+8+8*i,base);reo::assets::put32(bytes.data()+12+8*i,4096);
        std::memcpy(bytes.data()+512+48*i,names[i],8);
        std::memcpy(bytes.data()+base,"AFS\0",4);reo::assets::put32(bytes.data()+base+4,1);
        reo::assets::put32(bytes.data()+base+8,2048);reo::assets::put32(bytes.data()+base+12,1);
    }
    reo::assets::put32(bytes.data()+48,512);reo::assets::put32(bytes.data()+52,5*48);
    return std::make_shared<const reo::assets::Source>("native-session-fixture",memory);
}
struct ClosingActor final:world::Actor {
    application::NativeSession* session{};application::SessionStatus* result{};
    ~ClosingActor()override{if(session&&result)*result=session->close();}
};
void fixtures(){
    Notifications notices;application::NativeSession session(fixture_archive(),profile(),notices);
    check(session.open());
    check(!session.world().session().difficulty);
    for(unsigned value=0;value<256;++value){
        check(session.import_launch_difficulty(std::uint8_t(value))==application::SessionStatus::completed);
        check(session.world().session().difficulty==value);
    }
    check(session.world().session().timing==&session.update());
    check(session.scene_records()==session.scene_controls().records());
    check(session.scene_records()==session.scene_proxies().records());
    check(session.step_room_script().status==application::SessionStatus::missing_room);
    check(session.install_room({41,73,0})==application::SessionStatus::missing_room);
    check(!session.room()&&!session.update().scripts().channels()[1].program);
    check(session.advance(nullptr,nullptr).status==application::SessionStatus::missing_room);
    application::SessionStatus callback_status=application::SessionStatus::completed;
    auto actor=std::make_unique<ClosingActor>();actor->session=&session;actor->result=&callback_status;
    check(bool(session.world().spawn_primary(0,std::move(actor)).id));
    check(session.close()==application::SessionStatus::completed&&callback_status==application::SessionStatus::busy);
    check(!session.open()&&session.world().session().timing==nullptr);
    check(session.step_room_script().status==application::SessionStatus::closed);
    check(session.install_room({41,73,0})==application::SessionStatus::closed);
    check(session.advance(nullptr,nullptr).status==application::SessionStatus::closed);
    check(session.close()==application::SessionStatus::completed);
    check(session.import_launch_difficulty(0)==application::SessionStatus::closed&&session.world().session().difficulty==255);
}
void canonical_step(){
    Notifications notices;world::World native_world(profile(),std::make_shared<world::Session>());update::Owner owner(native_world,notices);
    native_world.mode=1;
    std::vector<std::byte> bytes(20);const std::array<std::uint32_t,5> words{0x02000110u,0u,77u,0u,0xau};std::memcpy(bytes.data(),words.data(),20);
    check(owner.scripts().install(0,std::make_shared<const scenario::Program>(std::vector<std::vector<std::byte>>{bytes}))==scenario::Status::completed);
    scenario::FlagState foreign_flags;scenario::Providers providers;providers.flags=&foreign_flags;
    check(owner.step_script(0,providers).status==update::Status::script_failure&&owner.scripts().counters()[0]==0);
    providers={};providers.canonical_flags=&foreign_flags;
    check(owner.step_script(0,providers).status==update::Status::script_failure&&owner.scripts().counters()[0]==0);
    world::World foreign_world(profile(),std::make_shared<world::Session>());providers={};providers.world=&foreign_world;
    check(owner.step_script(0,providers).status==update::Status::script_failure&&owner.scripts().counters()[0]==0);
    reo::native::gameplay_tasks::FlagTimers foreign_timers;providers={};providers.timers=&foreign_timers;
    check(owner.step_script(0,providers).status==update::Status::script_failure&&owner.scripts().counters()[0]==0);
    const auto stepped=owner.step_script(0);
    check(stepped.status==update::Status::completed&&owner.scripts().counters()[0]==77&&stepped.script_operations==2);
    check(!stepped.clock_committed&&owner.clock().update_counter()==0&&!owner.busy());
    check(owner.step_script(99).status==update::Status::script_failure);
}
void timed_text_failure_boundary(){
    // Controlled empty-actor frame: only the actual timed callback and its
    // ordering are under test. These recording services are not game owners.
    struct Phases final:update::PhaseServices {
        std::vector<update::Worker> calls;unsigned effects{};
        void run(update::Worker worker,update::Owner&)override{calls.push_back(worker);}
        bool button(update::Button,update::Owner&)override{return false;}
        bool transition_request(update::Owner&)override{return false;}
        void effect(update::PhaseEffect,update::Owner&,std::uint32_t)override{++effects;}
    } phases;
    struct EmptyActors final:world::Services {
        void begin_offline_frame(world::World&)override{std::terminate();}
        void run(world::Stage,world::World&,world::Actor&)override{std::terminate();}
        bool remote_motion(world::World&,world::Actor&)override{std::terminate();}
        bool find_grid(world::World&,world::Actor&,std::int8_t&)override{std::terminate();}
        void switch_grid(world::World&,std::int32_t,std::int32_t)override{std::terminate();}
        float grid_response(world::World&,std::uint8_t)override{std::terminate();}
    } actors;
    Notifications notices;application::NativeSession session(fixture_archive(),profile(),notices,1);
    auto& owner=session.update();owner.state.scripts_enabled=false;owner.state.session_work_gate=1;
    const auto disabled_program=std::make_shared<const scenario::Program>(std::vector<std::vector<std::byte>>{
        {std::byte{1},std::byte{},std::byte{},std::byte{},std::byte{0xa},std::byte{},std::byte{},std::byte{}}});
    for(unsigned channel=0;channel<2;++channel)
        check(owner.scripts().install(channel,disabled_program)==scenario::Status::completed);
    check(owner.clock().restore({},123)==update::tasks::Status::completed);
    session.text_cache().reset();session.scene_text_bank().priority().reset_active();
    check(session.application_lifecycle().begin_preparation());
    check(session.timed_scene_text().request(181)==scenario::TimedTextStatus::completed);
    scenario::Providers providers;providers.world=&session.world();providers.timed_scene_text=&session.timed_scene_text();
    const auto result=owner.advance(phases,actors,providers);
    check(result.status==update::Status::task_failure&&!result.clock_committed&&!result.completion_checked);
    check(result.linked.called==1&&owner.clock().update_counter()==123&&phases.effects==0);
    check(!phases.calls.empty()&&phases.calls.back()==update::Worker::scene_pose_tasks);
    check(session.timed_scene_text().snapshot().callback_status==scenario::TimedTextStatus::unavailable);
    check(session.close()==application::SessionStatus::frame_failure);
    check(session.close()==application::SessionStatus::completed);
}
void cold_inventory_ui(){
    Notifications notices;application::NativeSession session(fixture_archive(),profile(),notices);
    auto& ui=session.inventory_ui();auto& world=session.world();
    check(ui.bound_to(world)&&ui.snapshot()&&ui.snapshot()->phase==0&&ui.snapshot()->update_enabled==1&&ui.snapshot()->requests_enabled==1);
    check(!ui.close_ready()&&ui.force_close()==world::InventoryUiStatus::unavailable_actor);
    check(!ui.request_blocked()&&ui.request_mode_ready(0x10000)&&!ui.request_mode_ready(0));
    check(ui.configure_requests(0)==world::InventoryUiStatus::unavailable_request_reset&&!ui.request_blocked());
    check(ui.configure_requests(0x10000)==world::InventoryUiStatus::completed&&ui.request_blocked()==1);
    check(ui.initialize()==world::InventoryUiStatus::completed&&ui.request_blocked()==1);
    auto actor=std::make_unique<world::Actor>();actor->status=0x80008001u;actor->auxiliary_status=0x80000001u;
    const auto spawned=world.spawn_primary(0,std::move(actor));check(bool(spawned.id));
    world.selected_frame_marker=0x80;world.session().inventory_owner=4;
    check(ui.close_ready()&&ui.force_close()==world::InventoryUiStatus::completed);
    check(world.primary(0)->status==0x80000001u&&world.primary(0)->auxiliary_status==0x80000401u&&world.selected_frame_marker==0x83&&world.session().inventory_owner==0);
    world.primary(0)->status=0x8001;world.session().inventory_owner=4;world::RecoveryUi& recovery=ui;
    check(recovery.close()&&world.primary(0)->status==1&&world.session().inventory_owner==4);
    check(session.close()==application::SessionStatus::completed&&!ui.close_ready()&&!recovery.close());
    check(!ui.request_mode_ready(1)&&ui.configure_requests(1)==world::InventoryUiStatus::closed&&ui.request_blocked()==1);
}
struct CameraSink final:scenario::CameraDisplaySink {
    application::NativeSession& session;std::vector<unsigned> calls;
    explicit CameraSink(application::NativeSession& value):session(value){}
    void viewport(const scenario::CameraViewport& viewport,const scenario::CameraProjectionMatrices&)override{
        check(session.close()==application::SessionStatus::busy);check(viewport.width==640&&viewport.height==448);calls.push_back(24);
    }
    void view(const reo::native::transform_math::Matrix&)override{
        check(session.close()==application::SessionStatus::busy);calls.push_back(22);
    }
};
void owned_camera(std::shared_ptr<const reo::assets::Source> source,Notifications& notices){
    auto host=std::make_shared<application::NativeSession>(std::move(source),profile(),notices);
    auto& session=*host;application::SessionRooms rooms(host);
    check(session.install_room({41,73,0})==application::SessionStatus::completed&&session.fog().ready());
    auto actor=std::make_unique<world::Actor>();actor->active=true;
    check(bool(session.world().spawn_primary(0,std::move(actor)).id));
    auto& sequences=session.sequences();check(sequences.select(0,123));
    const auto& record=sequences.camera_records()->records()[0];
    scenario::CameraProjectionContext projection{320,224,640,448,reo::native::transform_math::identity(),reo::native::transform_math::identity()};
    scenario::CameraDisplayState display;const std::int8_t mode=0;CameraSink sink(session);
    scenario::CameraDisplayBinding binding(mode,projection,display,sink);
    check(session.step_room_camera(binding)==application::SessionStatus::completed);
    check(sink.calls==std::vector<unsigned>{24,24,22,24,22});
    check(sequences.snapshot().selection_changed==0&&sequences.snapshot().condition_id==0&&sequences.snapshot().previous_camera==0);
    const auto& parameters=session.camera_parameters();
    check(parameters.pose.eye.x==float(record.endpoints[1][0][0])&&parameters.pose.aim.z==float(record.endpoints[2][0][2]));
    check(parameters.pitch==record.parameters[0]&&parameters.yaw==record.parameters[1]&&parameters.pose.roll==record.parameters[2]);
    check(parameters.lens==record.lens&&parameters.distance==500&&parameters.far_plane==50000&&parameters.near_plane==1);
    for(unsigned i=0;i<session.room_models().asset()->parts();++i)
        check((session.scene_models().state().visibility[i]&1u)==((std::to_integer<unsigned>(record.view_controls[i/8])>>(i%8))&1u));
    const auto selected_fog=session.fog().state().selected;
    check(session.install_room({41,127,0})==application::SessionStatus::missing_room&&session.fog().state().selected==selected_fog);
    sink.calls.clear();check(session.step_room_camera(binding)==application::SessionStatus::completed);
    check(sequences.snapshot().selection_changed==0&&sequences.snapshot().progress==1&&sink.calls.size()==5);
    check(session.bind_room_camera(rooms,binding)==application::SessionStatus::completed&&session.update().room_camera_modes());
    check(session.update().bind_room_camera_modes(nullptr)==update::Status::actor_failure&&session.update().room_camera_modes());
    check(session.install_room({41,73,0})==application::SessionStatus::completed&&!session.update().room_camera_modes());
    check(session.bind_room_camera(rooms,binding)==application::SessionStatus::completed);
    check(session.unbind_room_camera()==application::SessionStatus::completed&&!session.update().room_camera_modes());
    check(session.bind_room_camera(rooms,binding)==application::SessionStatus::completed);
    check(session.close()==application::SessionStatus::completed&&session.step_room_camera(binding)==application::SessionStatus::closed);
    check(!session.update().room_camera_modes());
}
void owned(const std::filesystem::path& path){
    auto source=std::make_shared<const reo::assets::Source>(path);Notifications notices;
    owned_camera(source,notices);
    for(const auto mode:{std::uint8_t(1),std::uint8_t(0)})for(bool terminal:{false,true}){
        application::NativeSession session(source,profile(),notices,mode);
        check(session.install_room({41,73,0})==application::SessionStatus::completed);++owned_rooms;
        check(session.room()&&session.world().scenario==41&&session.world().room==73);
        const auto camera=session.sequences().camera_records();
        check(camera&&camera->count()==16&&camera->records()[0].type==1);
        check(session.sequences().snapshot().count==16&&session.sequences().snapshot().initialized==1);
        check(session.sequences().snapshot().actor==session.world().selected_actor&&session.sequences().snapshot().distance==80);
        check(session.sequences().select(0,123));
        check(session.install_room({41,127,0})==application::SessionStatus::missing_room);
        check(session.sequences().camera_records()==camera&&session.sequences().snapshot().selection==123);
        session.sequences().reset_camera_override();
        const auto asset=session.room_models().asset();
        check(asset&&asset->name()=="r0417300.nbd"&&asset->parts()==69&&asset->nodes()==71&&asset->poses().size()==69);
        for(unsigned i=0;i<128;++i){
            check(session.scene_models().state().styles[i]==0xffffffffu);
            if(i<69){check(session.scene_models().state().visibility[i]==1);check(*session.scene_models().pose(i)==session.room_models().saved()[i]);}
        }
        check(session.room_models().groups()[0].models==69&&session.room_models().groups()[0].control==0);
        check(session.room_scene()&&session.room_scene()->identities().size()==7);
        check(session.scene_controls().size()==7&&session.scene_proxies().size()==7);
        check(session.scene_records()==session.scene_controls().records()&&session.scene_records()==session.scene_proxies().records());
        check(session.scene_matrices().bound_to(session.scene_controls(),session.scene_models()));
        check(session.scene_matrices().bound_to_records(*session.scene_records(),session.update().flags(),session.world().room));
        check(session.lighting().banks()[0].kind==1&&session.lighting().banks()[0].count==20);
        const auto& channels=session.update().scripts().channels();check(channels[1].program&&channels[1].current==scenario::Position{8,0});
        check(channels[1].program->profile()==(mode?scenario::DispatchProfile::ordinary:scenario::DispatchProfile::offline_actor));
        if(!mode){
            check(channels[2].program==channels[1].program&&channels[3].program==channels[1].program);
            check(session.step_room_script().status==application::SessionStatus::missing_providers);
            for(unsigned i=0;i<3;++i){auto actor=std::make_unique<world::Actor>();actor->active=true;actor->slot=std::uint8_t(i);actor->room=73;
                check(bool(session.world().spawn_primary(i,std::move(actor)).id));}
        }
        if(terminal)for(unsigned bit=0;bit<2;++bit)check(session.update().flags().strided(73,bit,2,true,false));
        const auto flags=session.update().flags().snapshot();
        const auto before=channels[1].current;const auto records=session.scene_records();
        check(session.advance(nullptr,nullptr).status==application::SessionStatus::missing_frame_services);++frame_refusals;
        check(channels[1].current==before&&session.update().clock().update_counter()==0);
        for(unsigned pass=0;pass<3;++pass){const auto result=session.step_room_script();
            check(result.status==application::SessionStatus::completed&&result.update.script_operations>0&&!result.update.clock_committed);++script_steps;}
        check(session.update().clock().update_counter()==0&&session.world().selected_actor==0);
        check(session.scene_channels().mask()==0xffffffffu&&session.lighting().selected()==0);
        check(session.lighting().primary_count()>0);
        for(unsigned index=0;index<2;++index){const auto id=session.room_scene()->identities()[index*2];const auto control=session.scene_controls().get(id);
            check(control&&std::get<scenario::ControlTypeZero>(control->body).refresh_parameter==1);
            const auto matrix=session.scene_matrices().inspect(index);check(bool(matrix));
            if(terminal)check(matrix->progress==2&&matrix->playback==0&&matrix->cursor==1);else check(matrix->progress==0&&matrix->playback==0);}
        check(session.update().flags().snapshot().shared.scenario==flags.shared.scenario);
        check(session.install_room({41,99,0})==application::SessionStatus::missing_room&&session.scene_records()==records);
        check(session.update().scripts().channels()[1].program==channels[1].program);
        const auto stale=session.room_scene()->identities().front();
        const auto saved=session.room_models().saved()[0];auto live=saved;live[3][0]+=17;
        check(session.scene_models().pose(0,live)==scenario::ModelStatus::completed);
        session.scene_models().mark_slot_byte(128,123);
        check(session.install_room({41,73,0})==application::SessionStatus::completed);
        check(session.room_models().asset()==asset&&*session.scene_models().pose(0)==live&&session.scene_models().state().styles[0]==0xffffff7bu);
        check(session.room_models().saved()[0]==saved);
        session.room_models().restore_poses_and_styles(session.scene_models());
        check(*session.scene_models().pose(0)==saved&&session.scene_models().state().styles[0]==0xffffffffu);
        check(!records->acquire(stale)&&session.scene_records()!=records&&session.scene_controls().size()==7);
        check(session.close()==application::SessionStatus::completed&&session.scene_controls().size()==0);
    }
}
// Controlled script roots avoid unrelated unimplemented r028 audio/effect
// providers. All scene, camera, lighting and model assets remain owned bytes.
struct RoomScriptOverlay final:reo::assets::PositionedSource {
    std::shared_ptr<const reo::assets::Source> source;
    std::array<std::uint64_t,2> offsets{};
    std::uint64_t size()const noexcept override{return source->size;}
    std::size_t read(std::uint64_t at,std::size_t length,void* destination)const override{
        source->read(at,length,destination);
        constexpr std::array<std::uint8_t,8> replacement{1,0,0,0,10,0,0,0};
        for(auto offset:offsets)if(offset){const auto first=std::max(at,offset),last=std::min(at+length,offset+replacement.size());
            if(first<last)std::memcpy(static_cast<std::uint8_t*>(destination)+(first-at),replacement.data()+(first-offset),std::size_t(last-first));}
        return length;
    }
};
std::shared_ptr<const reo::assets::Source> controlled_room_28(const std::filesystem::path& path){
    auto source=std::make_shared<const reo::assets::Source>(path);
    const auto lower=[](std::string value){for(auto& c:value)if(c>='A'&&c<='Z')c+=('a'-'A');return value;};
    const auto outer=reo::assets::table(*source,0,source->size);
    const auto parent=std::find_if(outer.entries.begin(),outer.entries.end(),[&](const auto& e){return lower(e.name)=="r028.afs";});
    check(parent!=outer.entries.end());const auto inner=reo::assets::table(*source,parent->offset,parent->size);
    const auto member=std::find_if(inner.entries.begin(),inner.entries.end(),[&](const auto& e){return lower(e.name)=="r0280300.rdt";});
    check(member!=inner.entries.end());const auto base=std::uint64_t(parent->offset)+member->offset;
    std::array<std::uint32_t,2> section{};source->read(base+8,sizeof(section),section.data());
    check(section[1]>=64&&section[0]<=member->size&&section[1]<=member->size-section[0]);
    std::array<std::uint32_t,16> table{};source->read(base+section[0],sizeof(table),table.data());
    auto overlay=std::make_shared<RoomScriptOverlay>();overlay->source=source;
    for(unsigned i=0;i<2;++i){const auto root=table[8+4*i];if(root){check(root>=64&&root+8<=section[1]);overlay->offsets[i]=base+section[0]+root;}}
    check(overlay->offsets[0]!=0);
    return std::make_shared<const reo::assets::Source>("controlled-r028-room-script",overlay);
}
// 169 dispatches through the real application VM and descriptor owners. The
// controlled descriptor bytes and the room-script overlay are test fixtures.
void enemy_relocation(const std::filesystem::path& path){
    auto source=controlled_room_28(path);Notifications notices;
    application::NativeSession session(source,profile(),notices,1);auto& world=session.world();
    auto& state=world.session();world.scenario=28;state.primary_population=3;
    for(unsigned i=0;i<3;++i){auto actor=std::make_unique<world::Actor>();actor->active=i<2;actor->slot=std::uint8_t(i);
        check(bool(world.spawn_primary(i,std::move(actor)).id));}
    world.selected_actor=0;world.primary(0)->room=7;world.primary(0)->status=0;
    world.primary(1)->status=0x20;world.primary(1)->character=0;
    auto& routes=state.enemy_routes;routes.classes={27,27};routes.room_banks[0][7]=1;
    std::vector<std::byte> data(295);reo::assets::put32(reinterpret_cast<std::uint8_t*>(data.data()),4);
    auto prediction=state.random;(void)prediction.request(0);const auto group=std::uint8_t(prediction.request(2)&3u);
    for(unsigned i=0;i<3;++i){const auto at=4+96*i;data[at+2]=std::byte{27};data[at+0x1c]=std::byte(i==0?2:i==1?7:3);
        data[at+0x1e]=std::byte(group);data[at+0x20]=std::byte{9};data[at+0x22]=std::byte(i==1?17:16);
        data[at+0x33]=std::byte{255};data[at+0x49]=std::byte{1};}
    data[4+288+2]=std::byte{255};
    check(state.enemy_descriptors.import(data,state,false,0).count==3);
    check(session.update().flags().write(scenario::FlagBank::scene_record_eligibility,17,true));
    check(session.install_room({28,3,0})==application::SessionStatus::completed);
    std::vector<std::byte> script(16);const std::array<std::uint32_t,4> words{1,0x01000169,16,0xa};
    std::memcpy(script.data(),words.data(),script.size());
    auto program=std::make_shared<const scenario::Program>(std::vector<std::vector<std::byte>>{script});
    check(!program->unsupported()&&session.update().scripts().install(1,program)==scenario::Status::completed);
    const auto result=session.step_room_script();auto* first=state.enemy_descriptors.record(0);
    check(result.status==application::SessionStatus::completed&&first&&first->room==7&&first->parameter20==5&&world.primary(1)->status==0x1020);
    routes.room_banks[0][7]=0;routes.room_banks[1][7]=1;first->room=2;first->parameter20=9;world.primary(1)->status=0x20;
    check(session.update().scripts().install(1,program)==scenario::Status::completed);
    check(session.step_room_script().status==application::SessionStatus::completed&&first->room==2&&
          first->parameter20==9&&world.primary(1)->status==0x20);
    check(session.close()==application::SessionStatus::completed);
}
#include "destination_policy_tests.inc"
#include "offline_actor_controls_tests.inc"
#include "offline_scene_entry_tests.inc"
}
int main(int argc,char** argv)try{
    fixtures();canonical_step();timed_text_failure_boundary();cold_inventory_ui();check(argc==1||argc==2);
    if(argc==2){const std::string_view value(argv[1]);const auto path=std::filesystem::path(std::u8string(value.begin(),value.end()));owned(path);enemy_relocation(path);destination_policy_application(path);offline_navigation_controls_application(path);offline_actor_controls_application(path);offline_scene_entry_application(path);}
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"owned_rooms\":"<<owned_rooms<<",\"script_steps\":"<<script_steps<<",\"frame_refusals\":"<<frame_refusals<<",\"game_launched\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
