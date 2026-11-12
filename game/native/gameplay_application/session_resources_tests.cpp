#include "session_resources.hpp"
#include "session_resource_workers.hpp"
#include "session_rooms.hpp"
#include "../gameplay_world/primary_actor_records.hpp"
#include "../gameplay_world/launch_roster.hpp"
#include "../gameplay_scenario/cutscene_playback.hpp"
#include "runtime/assets/virtual_afs.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace a=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
namespace u=reo::native::gameplay_update;
namespace e=reo::native::gameplay_effects;
namespace c=reo::native::gameplay_collision;
namespace {
unsigned checks{},selected{},placed{},starting{},workers{},refusals{},guards{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("SessionResources check "+std::to_string(at.line()));
}
struct Notices final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
w::Profile profile(){w::Profile p;p.layouts.push_back({});p.entities.capacity=256;return p;}
std::vector<std::byte> bytes(const char* path){
    std::ifstream in(path,std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(in),{}};
    check(!raw.empty());std::vector<std::byte> result(raw.size());std::memcpy(result.data(),raw.data(),raw.size());return result;
}
std::shared_ptr<const e::EffectBank> effects(const char* path){
    std::ifstream in(path,std::ios::binary);unsigned count{};in.read(reinterpret_cast<char*>(&count),4);check(count==12);
    std::array<std::vector<std::byte>,2> inputs;
    for(auto& input:inputs){unsigned size{};in.read(reinterpret_cast<char*>(&size),4);check(size&&size<10000000);input.resize(size);in.read(reinterpret_cast<char*>(input.data()),size);check(bool(in));}
    return e::EffectBank::import(inputs[0],inputs[1]);
}
struct Remaining final:u::PhaseServices {
    void run(u::Worker,u::Owner&)override{throw std::runtime_error("Unimplemented terminal worker");}
    bool button(u::Button,u::Owner&)override{throw std::runtime_error("Unimplemented input owner");}
    bool transition_request(u::Owner&)override{throw std::runtime_error("Unimplemented transition owner");}
    void effect(u::PhaseEffect,u::Owner&,std::uint32_t)override{throw std::runtime_error("Unimplemented phase owner");}
};
struct Refresh final:w::ResourceModelWork {
    std::shared_ptr<w::ResourceModelWork> actual;
    a::NativeSession& host;
    Refresh(std::shared_ptr<w::ResourceModelWork> value,a::NativeSession& session):actual(std::move(value)),host(session){}
    void update(w::ResourceModels& models,const w::ResourceModelId& id,w::ResourceModel& model)override{
        check(host.world().busy()&&host.close()==a::SessionStatus::busy);
        check(host.initialize_resources().status==a::ResourceImportStatus::busy);
        check(host.install_room({41,73,0})==a::SessionStatus::busy);
        check(host.resources()->close()==a::SessionResourceStatus::busy);++guards;
        actual->update(models,id,model);models.request_refresh();
    }
};
// These capabilities explicitly refuse. The resource worker borrows only the
// real controller's state; this fixture does not qualify cinematic playback.
struct Streams final:s::StreamBackend {
    s::StreamValue phase(std::uint8_t)noexcept override{return{s::StreamStatus::unbound,0};}
    s::StreamStatus start(std::uint8_t,s::StreamRequest,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus stop(std::uint8_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus pause(std::uint8_t,bool,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus attenuation(std::uint8_t,std::int32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus service(std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
};
struct Cinematic final:s::CutscenePlaybackServices {
    s::CutscenePlaybackStatus start_movie(const s::CutsceneBatch&)override{return s::CutscenePlaybackStatus::unavailable;}
    s::CutscenePlaybackValue movie_state()override{return{};}
    s::CutscenePlaybackValue movie_busy()override{return{};}
#define REFUSE(name) s::CutscenePlaybackStatus name()override{return s::CutscenePlaybackStatus::unavailable;}
    REFUSE(stop_movie) REFUSE(retire_movie) REFUSE(stop_stream_tasks)
    REFUSE(transition_audio_reset) REFUSE(close_actor_notice)
    REFUSE(clear_actor_descriptors) REFUSE(retire_scene) REFUSE(reset_scene) REFUSE(publish_scene_notice)
#undef REFUSE
    s::CutscenePlaybackStatus fade(bool,std::int16_t,std::uint32_t)override{return s::CutscenePlaybackStatus::unavailable;}
    s::CutscenePlaybackValue fade_finished()override{return{};}
    s::CutscenePlaybackStatus fullscreen_color(std::uint32_t)override{return s::CutscenePlaybackStatus::unavailable;}
    s::CutscenePlaybackStatus select_scene(s::CutscenePlaybackState&)override{return s::CutscenePlaybackStatus::unavailable;}
    s::CutscenePlaybackValue load_scene(s::CutscenePlaybackState&)override{return{};}
    s::CutsceneSpeech* speech()noexcept override{return nullptr;}
    s::CutscenePlaybackStatus frame_work(s::CutsceneFrameWork,s::CutscenePlaybackState&,std::int8_t)override{return s::CutscenePlaybackStatus::unavailable;}
};
std::shared_ptr<a::NativeSession> install(const std::shared_ptr<const reo::assets::Source>& source,Notices& notices){
    auto host=std::make_shared<a::NativeSession>(source,profile(),notices);
    check(host->world().session().asset_loading_mode==1);
    check(host->install_room({41,73,0})==a::SessionStatus::completed);
    check(w::initialize_primary_records(host->world()).status==w::PrimaryRecordsStatus::completed);
    reo::native::gameplay_session::LaunchRoster roster;roster.scenario=41;roster.count=4;
    for(unsigned i=0;i<4;++i)roster.actors[i].model_variant=std::uint16_t(i+1);
    check(w::apply_launch_roster(host->world(),host->update().action_choices(),roster));
    check(host->import_launch_difficulty(1)==a::SessionStatus::completed);return host;
}
void record(std::vector<std::byte>& data,unsigned opcode,std::initializer_list<unsigned> payload){
    unsigned shift{},words=1;while(words<payload.size()+1){words*=2;++shift;}
    const auto header=opcode|(shift<<24);const auto begin=data.size();
    for(unsigned i=0;i<4;++i)data.push_back(std::byte(header>>(8*i)));
    for(const auto word:payload)for(unsigned i=0;i<4;++i)data.push_back(std::byte(word>>(8*i)));
    data.resize(begin+4*words);
}
void owned(const char* archive_path,const char* catalog_path,const char* effects_path){
    const auto source=std::make_shared<const reo::assets::Source>(archive_path);
    const auto bank=effects(effects_path);const auto catalog=std::make_shared<const c::delivery::Catalog>(c::delivery::Catalog::import(bytes(catalog_path)));
    Notices notices;auto host=install(source,notices);auto rooms=std::make_shared<a::SessionRooms>(host);
    host->world().session().collision_disabled_mask=0; // controlled collision profile, not a startup producer claim
    const auto input=a::SessionResourceAssets::load(host->archive(),41,"DEF41.NBD",bank,catalog);
    check(input&&input->templates.state().count&&input->item_file&&!host->resources());
    auto foreign=install(source,notices);auto foreign_rooms=std::make_shared<a::SessionRooms>(foreign);
    check(host->bind_resource_assets(input,foreign_rooms)==a::SessionStatus::missing_providers&&!host->resources());++refusals;
    check(host->bind_resource_assets(nullptr,rooms)==a::SessionStatus::missing_providers&&!host->resources());++refusals;
    bool refused{};const auto records=host->scene_records();const auto floor=rooms->retain_floor(73);check(bool(floor));
    check(host->bind_resource_assets(input,rooms)==a::SessionStatus::completed&&host->resources());
    auto& graph=*host->resources();check(graph.bound_to(*host)&&!graph.bound_to(*foreign)&&!graph.initialized());
    check(graph.pose_pool().bound_to(host->world())&&graph.models().available()==64&&graph.pose_pool().remaining()==64);
    check(graph.factory().room_floor(73).get()==floor.get()&&host->scene_records()==records);
    refused=false;try{w::PoseWorkPool duplicate(host->world());}catch(const std::invalid_argument&){refused=true;}
    check(refused&&graph.pose_pool().bound_to(host->world()));++refusals;
    check(host->bind_resource_assets(input,rooms)==a::SessionStatus::missing_providers);++refusals;
    check(host->advance(nullptr,nullptr).status==a::SessionStatus::missing_frame_services);
    Remaining remaining;
    try{a::SessionResourceWorkers early(*host,graph,remaining);}catch(const std::invalid_argument&){refused=true;}
    check(refused);++refusals;
    const auto initialized=host->initialize_resources();
    check(initialized.status==a::ResourceImportStatus::completed&&initialized.item_found&&initialized.selection_found&&initialized.selected&&initialized.placed&&initialized.starting);
    selected+=unsigned(initialized.selected);placed+=unsigned(initialized.placed);starting+=unsigned(initialized.starting);
    check(graph.initialized()&&graph.templates().state().count==input->templates.state().count&&graph.descriptors().active_count()>0);
    const auto active=graph.descriptors().active_count();check(host->initialize_resources().status==a::ResourceImportStatus::unavailable_profile&&graph.descriptors().active_count()==active);++refusals;
    check(graph.inventory().bound_to(host->world(),graph.descriptors(),graph.templates()));
    check(host->install_room({41,73,0})==a::SessionStatus::missing_providers&&host->scene_records()==records);++refusals;
    a::SessionResourceWorkers workers_owner(*host,graph,remaining);
    refused=false;try{workers_owner.run(u::Worker::resource_instances,host->update());}catch(const std::runtime_error&){refused=true;}
    check(refused&&!host->world().cinematic_controller());++refusals;
    const auto created=graph.factory().create(0x81);check(created.status==w::ResourceModelStatus::completed&&created.model&&created.model->work&&created.model->asset_index==0&&created.model->base_parts&&created.model->base_parts->count==4);
    Streams streams;Cinematic cinematic;s::StreamChannels channels(s::file1_stream_gain_curve());
    {
        s::CutscenePlayback controller(host->update(),channels,streams,cinematic);
        check(host->world().cinematic_controller()==&controller);
        workers_owner.run(u::Worker::resource_instances,host->update());++workers;
        controller.state().cinematic_enabled=1;created.model->visible=false;
        workers_owner.run(u::Worker::resource_instances,host->update());check(!created.model->visible);++workers;
        controller.state().cinematic_enabled=0;
        created.model->work=std::make_shared<Refresh>(created.model->work,*host);
        const auto* dynamic=&host->object_instances()->dynamic();
        workers_owner.run(u::Worker::resource_instances,host->update());++workers;
        check(graph.models().refresh_requested()&&dynamic->status==c::trace::SamplingStatus::complete);
        // A complete native kind19 vertical motion is traversed through the
        // application worker and canonical World actor storage.
        const auto pose=graph.pose_pool().allocate();check(pose.status==w::PoseWorkStatus::completed);
        auto actor=graph.pose_pool().resolve(pose.id);check(actor&&host->world().resolve(pose.id)==actor);
        actor->active=true;actor->pose_work->kind=19;actor->pose_work->update_bound=true;actor->pose_work->lifetime=10;actor->position.z=30;
        workers_owner.run(u::Worker::scene_pose_tasks,host->update());++workers;
        check(actor->primary==1&&actor->position.z==-370);
        check(graph.pose_pool().retire(pose.id)==w::PoseWorkStatus::completed&&!host->world().resolve(pose.id));
        // A controlled command fixture verifies the actual interpreter caller
        // receives this graph's resource provider; it is not an authored launch.
        const auto allocated=graph.descriptors().allocate(73,30000,0x81,graph.templates());check(allocated.id.has_value());
        auto descriptor=graph.descriptors().get(*allocated.id);check(bool(descriptor));descriptor->kind=1;descriptor->parameter=1;descriptor->instance_index=allocated.slot;
        check(graph.descriptors().replace(*allocated.id,*descriptor)==s::SceneStatus::completed);
        std::vector<std::byte> command;record(command,0x174,{30000,3});record(command,0xa,{ });
        const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{command});
        check(!program->unsupported()&&host->update().scripts().install(1,program)==s::Status::completed);
        const auto stepped=host->step_room_script();check(stepped.status==a::SessionStatus::completed&&stepped.update.script_operations>0);
        check(bool(graph.descriptors().get(*allocated.id)->primary));
    }
    check(!host->world().cinematic_controller());
    refused=false;try{workers_owner.run(u::Worker::sequences,host->update());}catch(const std::runtime_error&){refused=true;}
    check(refused);++refusals;
    check(host->advance(nullptr,nullptr).status==a::SessionStatus::missing_frame_services&&host->update().clock().update_counter()==0);
    const auto retained=created.model;std::weak_ptr<a::NativeSession> weak=host;
    check(host->close()==a::SessionStatus::completed&&!retained->current());host.reset();
    check(weak.expired()&&!floor->triangles().empty()&&!rooms->world());
    check(foreign->close()==a::SessionStatus::completed);
    // Destruction must also work without an explicit close breaking a cycle.
    auto automatic=install(source,notices);automatic->world().session().collision_disabled_mask=0;
    auto automatic_rooms=std::make_shared<a::SessionRooms>(automatic);
    const auto automatic_floor=automatic_rooms->retain_floor(73);check(bool(automatic_floor));
    check(automatic->bind_resource_assets(input,automatic_rooms)==a::SessionStatus::completed);
    check(automatic->initialize_resources().status==a::ResourceImportStatus::completed);
    std::weak_ptr<a::NativeSession> automatic_weak=automatic;automatic.reset();
    check(automatic_weak.expired()&&!automatic_rooms->world()&&!automatic_floor->triangles().empty());
}
}
int main(int argc,char** argv)try{
    check(argc==4);owned(argv[1],argv[2],argv[3]);
    std::cout<<"{\"checks\":"<<checks<<",\"selected\":"<<selected<<",\"placed\":"<<placed<<",\"starting\":"<<starting<<",\"workers\":"<<workers<<",\"refusals\":"<<refusals<<",\"guards\":"<<guards<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
