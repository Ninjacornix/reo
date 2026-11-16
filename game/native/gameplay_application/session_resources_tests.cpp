#include "session_resources.hpp"
#include "session_resource_workers.hpp"
#include "session_rooms.hpp"
#include "session_actor_services.hpp"
#include "session_frontend.hpp"
#include "../gameplay_presentation/session_presentation.hpp"
#include "../gameplay_presentation/frontend_assets.hpp"
#include "../gameplay_world/primary_actor_records.hpp"
#include "../gameplay_world/color_fade.hpp"
#include "../gameplay_collision/object_queries.hpp"
#include "../gameplay_world/launch_roster.hpp"
#include "../gameplay_scenario/cutscene_playback.hpp"
#include "runtime/assets/virtual_afs.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <source_location>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
#endif
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
struct TerminalCloseSink final:u::GameplayMessageSink {
    a::NativeSession* host{};unsigned room_calls{},snapshot_calls{};bool guarded{true};
    bool send(const u::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const u::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const u::ResourcePositionMessage&)noexcept override{return false;}
    bool send(const u::ActorStatusMessage&)noexcept override{return false;}
    void check_close()noexcept{
        if(!host||!host->resources()){guarded=false;return;}
        auto* graph=host->resources();
        guarded=guarded&&host->update().busy()&&host->close()==a::SessionStatus::busy&&
            graph->close()==a::SessionResourceStatus::busy&&host->open()&&
            host->resources()==graph&&graph->initialized();
    }
    bool send(const u::RoomClaimReleaseMessage&)noexcept override{++room_calls;check_close();return true;}
    bool send(const u::ActorSnapshotMessage&)noexcept override{++snapshot_calls;check_close();return true;}
};
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
struct DirectReentrantClose final:w::ResourceModelWork {
    a::NativeSession& host;unsigned calls{};
    explicit DirectReentrantClose(a::NativeSession& value):host(value){}
    void update(w::ResourceModels& models,const w::ResourceModelId&,w::ResourceModel&)override{
        ++calls;check(models.busy()&&!host.world().busy()&&host.resources()->busy());
        check(host.resources()->close()==a::SessionResourceStatus::busy);
        check(host.close()==a::SessionStatus::busy);
        check(host.open()&&host.resources()->initialized()&&host.update().scenario_events().ready());
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
void camera_frame(a::NativeSession& host,a::SessionRooms& rooms,std::shared_ptr<const reo::assets::Source> source){
    // Actual camera/resource/task owners in a controlled empty-actor frame.
    // Remaining workers are observations here, not completed game providers.
    struct Phases final:u::PhaseServices {
        std::vector<u::Worker> calls;
        void run(u::Worker worker,u::Owner&)override{calls.push_back(worker);}
        bool button(u::Button,u::Owner&)override{return true;}
        bool transition_request(u::Owner&)override{std::terminate();}
        void effect(u::PhaseEffect,u::Owner&,std::uint32_t)override{std::terminate();}
    } phases;
    struct Actors final:w::Services {
        void begin_offline_frame(w::World&)override{std::terminate();}
        void run(w::Stage,w::World&,w::Actor&)override{std::terminate();}
        bool remote_motion(w::World&,w::Actor&)override{std::terminate();}
        bool find_grid(w::World&,w::Actor&,std::int8_t&)override{std::terminate();}
        void switch_grid(w::World&,std::int32_t,std::int32_t)override{std::terminate();}
        float grid_response(w::World&,std::uint8_t)override{std::terminate();}
    } actors;
    struct Display final:s::CameraDisplaySink {
        a::NativeSession& host;unsigned views{};
        explicit Display(a::NativeSession& value):host(value){}
        void viewport(const s::CameraViewport&,const s::CameraProjectionMatrices&)override{
            check(host.close()==a::SessionStatus::busy&&host.unbind_room_camera()==a::SessionStatus::busy);
        }
        void view(const reo::native::transform_math::Matrix&)override{++views;}
    } display(host);
    for(unsigned i=0;i<w::World::primary_capacity;++i)if(const auto actor=host.world().primary(i))check(!actor->active);
    auto& update=host.update();const auto old_state=update.state;const auto old_channels=update.scripts().channels();
    const auto old_time=update.clock().play_time();const auto old_counter=update.clock().update_counter();
    const auto disabled=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{
        {std::byte{1},std::byte{},std::byte{},std::byte{},std::byte{0xa},std::byte{},std::byte{},std::byte{}}});
    for(unsigned i=0;i<2;++i)check(update.scripts().install(i,disabled)==s::Status::completed);
    update.state.scripts_enabled=false;update.state.session_work_gate=1;
    s::CameraProjectionContext projection{320,224,640,448,reo::native::transform_math::identity(),reo::native::transform_math::identity()};
    s::CameraDisplayState output;const std::int8_t mode=0;s::CameraDisplayBinding binding(mode,projection,output,display);
    check(host.bind_room_camera(rooms,binding)==a::SessionStatus::completed&&update.room_camera_modes());
    check(host.bind_room_camera(rooms,binding)==a::SessionStatus::missing_providers);
    check(host.sequences().select(0,123));auto state=host.sequences().snapshot();
    state.phase=5;state.restart_byte=0;state.mode=0;state.parameter_a=0;state.parameter_b=2;state.fraction=3;
    check(host.sequences().restore(state));
    const auto first=host.advance(&phases,&actors);
    check(first.status==a::SessionStatus::completed&&first.update.clock_committed&&first.update.linked.called==1&&display.views);
    check(std::find(phases.calls.begin(),phases.calls.end(),u::Worker::camera_modes)==phases.calls.end());
    check(host.advance(&phases,&actors).status==a::SessionStatus::completed&&update.linked().size()==0);
    // An invalid reached camera variant fails in the actual linked callback.
    state=host.sequences().snapshot();state.phase=5;state.restart_byte=0;state.mode=255;check(host.sequences().restore(state));
    phases.calls.clear();const auto before_failure=update.clock().update_counter();
    const auto failure=host.advance(&phases,&actors);
    check(failure.status==a::SessionStatus::frame_failure&&failure.update.status==u::Status::task_failure&&
          !failure.update.clock_committed&&update.clock().update_counter()==before_failure);
    check(std::find(phases.calls.begin(),phases.calls.end(),u::Worker::render_work_banks)==phases.calls.end());
    check(host.unbind_room_camera()==a::SessionStatus::frame_failure&&!update.room_camera_modes());
    check(host.unbind_room_camera()==a::SessionStatus::completed);
#ifdef _WIN32
    // Controlled no-actor frame with genuine room model, textures, camera,
    // and a real hidden process window. Other phase services above remain
    // test observations, so this does not claim a complete gameplay frame.
    const HWND window=CreateWindowExA(0,"STATIC","native presentation test",0,0,0,64,64,nullptr,nullptr,GetModuleHandleA(nullptr),nullptr);
    check(window!=nullptr);
    {
        const auto authored=reo::native::gameplay_presentation::ModelMesh::import(*host.room_models().asset()->bytes());
        check(authored.parts.size()==69);
        check(std::count_if(authored.parts.begin(),authored.parts.end(),[](const auto& part){
            return part.render_profile&&part.render_profile->format==0&&
                part.render_profile->color_mode==0x300&&part.render_profile->option_12;
        })==69);
        check(authored.parts[9].vertices[0].color==std::array<float,4>{20.f/255.f,20.f/255.f,20.f/255.f,102.f/128.f});
        reo::native::gameplay_presentation::BackgroundState background;check(background.select(0));
        reo::native::gameplay_presentation::GraphicsState graphics;
        graphics.initialize_frontend_prefix();
        reo::native::gameplay_presentation::FrontendAssets frontend_assets(source);
        const auto common=frontend_assets.load_common_textures();check(common&&common->loading_texture()&&common->loading_texture()->width==256&&common->loading_texture()->height==128);
        auto font=frontend_assets.load_font();reo::native::gameplay_presentation::FrontendTextGate text_gate;
        s::DisplayFadeState display_fade; a::FrontendLetterbox letterbox;
        host.text_cache().reset();
        // Isolate the authored resource model while preserving all live pool
        // identities and their prior visibility for the remainder of the test.
        auto& resource_models=host.resources()->models();
        std::vector<std::pair<std::shared_ptr<w::ResourceModel>,bool>> resource_visibility;
        for(auto id=resource_models.head();id;id=resource_models.next(id)){
            auto model=resource_models.retain(id);check(bool(model));resource_visibility.emplace_back(model,model->visible);model->visible=false;
        }
        reo::native::gameplay_presentation::SessionPresentation presentation(host,rooms,window,background,projection,mode,320,224,&graphics,&font,&text_gate,&display_fade,&letterbox);
        state=host.sequences().snapshot();state.phase=5;state.restart_byte=0;state.mode=0;state.parameter_a=0;state.parameter_b=2;state.fraction=3;
        check(host.sequences().restore(state));
        check(host.advance(&phases,&actors).status==a::SessionStatus::completed);
        // The real resource worker can republish visibility during that frame.
        // Hide the same retained models again for the controlled baseline.
        for(auto& [model,visible]:resource_visibility){(void)visible;model->visible=false;}
        check(presentation.present());
        check(std::any_of(presentation.pixels().begin(),presentation.pixels().end(),[](std::uint32_t pixel){return (pixel&0xffffffu)!=0;}));
        const std::vector<std::uint32_t> initialized_pixels(presentation.pixels().begin(),presentation.pixels().end());
        // Exercise the actual session fog owner through the actual room
        // presenter, with a controlled range and signed flash adjustments.
        check(host.fog().ready());const auto saved_fog=host.fog().state();
        auto& fog=host.fog().state();fog.near_distance=-1000000.f;fog.far_distance=-999999.f;
        fog.color={10,20,30};fog.flash={246,20,128,0};
        check(presentation.present());
        check(std::any_of(presentation.pixels().begin(),presentation.pixels().end(),[](std::uint32_t pixel){
            return (pixel&0x00ff00u)!=0&&(pixel&0xff00ffu)==0;
        }));
        host.fog().state()=saved_fog;check(presentation.present());
        check(std::equal(initialized_pixels.begin(),initialized_pixels.end(),presentation.pixels().begin(),presentation.pixels().end()));
        // Already imported geometry is independent of later global changes.
        graphics.select_format(0);check(presentation.present());
        check(std::equal(initialized_pixels.begin(),initialized_pixels.end(),presentation.pixels().begin(),presentation.pixels().end()));
        graphics.select_format(2);
        graphics.set_color(0xff000000u);check(presentation.present());
        check(std::equal(initialized_pixels.begin(),initialized_pixels.end(),presentation.pixels().begin(),presentation.pixels().end()));
        const std::array text{std::byte{'Y'},std::byte{'E'},std::byte{'S'},std::byte{}};
        check(host.text_cache().request(0,20,20,4,20,text,0).status==s::TextCacheStatus::completed);
        check(presentation.present());check(!std::equal(initialized_pixels.begin(),initialized_pixels.end(),presentation.pixels().begin(),presentation.pixels().end()));
        text_gate.set_suppressed(true);check(presentation.present());
        check(std::equal(initialized_pixels.begin(),initialized_pixels.end(),presentation.pixels().begin(),presentation.pixels().end()));
        text_gate.set_suppressed(false);check(presentation.present());
        check(!std::equal(initialized_pixels.begin(),initialized_pixels.end(),presentation.pixels().begin(),presentation.pixels().end()));
        check(host.text_cache().erase(text)==s::TextCacheStatus::completed);
        display_fade.status=1;display_fade.alpha=1.f;display_fade.color=0xff0000u;display_fade.rectangle={0,0,640,448,0};
        check(presentation.present()&&std::all_of(presentation.pixels().begin(),presentation.pixels().end(),[](std::uint32_t pixel){return pixel==0xffff0000u;}));
        display_fade.status=0;letterbox.phase=1;letterbox.top={0,0,640,64,0xff000000};letterbox.bottom={0,384,640,64,0xff000000};
        check(presentation.present()&&presentation.pixels()[10*320+160]==0xff000000u&&presentation.pixels()[210*320+160]==0xff000000u);
        letterbox.phase=0;
        // Exercise373630's actual F4 visibility bytes through the real actor
        // asset, pose and presentation owner. This controlled actor is not a
        // claim that the remaining simulation workers form a complete frame.
        auto actor=host.world().primary(0);check(bool(actor));
        const auto old_active=actor->active,old_visible=actor->visible;const auto old_room=actor->room;
        auto old_asset=actor->model_asset;auto old_model=actor->model;auto old_primary=std::move(actor->primary_state);
        w::ActorAssets actor_assets(source);actor->model_asset=actor_assets.read_primary(0,0,0);check(bool(actor->model_asset));
        actor->model=actor->model_asset->make_instance();check(bool(actor->model));actor->model->rebuild(reo::native::transform_math::identity());
        actor->primary_state.emplace();actor->primary_state->part_visibility.assign(actor->model_asset->part_count(),0);
        actor->active=true;actor->visible=true;actor->room=host.world().room;
        check(presentation.present()&&presentation.actor_parts_submitted()==0);
        actor->primary_state->part_visibility[1]=0x80;check(presentation.present()&&presentation.actor_parts_submitted()==1);
        std::fill(actor->primary_state->part_visibility.begin(),actor->primary_state->part_visibility.end(),1);
        check(presentation.present()&&presentation.actor_parts_submitted()==actor->model_asset->part_count());
        actor->primary_state->part_visibility.clear();bool missing_visibility=false;
        try{(void)presentation.present();}catch(const std::invalid_argument&){missing_visibility=true;}check(missing_visibility);
        actor->active=old_active;actor->visible=old_visible;actor->room=old_room;actor->model_asset=std::move(old_asset);actor->model=std::move(old_model);actor->primary_state=std::move(old_primary);
        check(!resource_visibility.empty());const auto resource=resource_visibility.front().first;
        check(resource->current()&&resource->active&&resource->category==8&&resource->asset_index==0&&resource->base_parts&&resource->base_parts->count==4);
        const bool resource_baseline= presentation.present();
        if(!resource_baseline||presentation.resource_models_submitted()!=0)
            throw std::runtime_error("Resource baseline present="+std::to_string(resource_baseline)+" submitted="+
                std::to_string(presentation.resource_models_submitted())+" busy="+std::to_string(host.resources()->busy()));
        check(resource_baseline&&presentation.resource_models_submitted()==0);
        const std::vector<std::uint32_t> without_resource(presentation.pixels().begin(),presentation.pixels().end());
        const auto old_position=resource->position;const auto old_pose=resource->pose;const auto old_pulse=resource->pulse_distance;
        const auto old_enabled=resource->part_enabled;resource->pulse_distance=0;resource->visible=true;
        const auto camera=host.camera_parameters().pose;bool resource_pixels=false;
        for(float fraction:{0.1f,0.25f,0.5f}){
            for(float scale:{1.f,10.f,100.f}){
                resource->position={camera.eye.x+(camera.aim.x-camera.eye.x)*fraction,
                                    camera.eye.y+(camera.aim.y-camera.eye.y)*fraction,
                                    camera.eye.z+(camera.aim.z-camera.eye.z)*fraction};
                resource->pose=reo::native::transform_math::scale({scale,scale,scale});
                check(presentation.present()&&presentation.resource_models_submitted()==1);
                if(!std::equal(without_resource.begin(),without_resource.end(),presentation.pixels().begin(),presentation.pixels().end())){resource_pixels=true;break;}
            }
            if(resource_pixels)break;
        }
        check(resource_pixels);const std::vector<std::uint32_t> resource_image(presentation.pixels().begin(),presentation.pixels().end());
        // 3724F0 publishes the matrix bank without testing byte30+i.
        resource->part_enabled[0]=0;check(presentation.present()&&presentation.resource_models_submitted()==1&&
            std::equal(resource_image.begin(),resource_image.end(),presentation.pixels().begin(),presentation.pixels().end()));
        const auto saved_index=resource->asset_index;resource->asset_index=-1;bool missing_resource=false;
        try{(void)presentation.present();}catch(const std::invalid_argument&){missing_resource=true;}
        check(missing_resource);resource->asset_index=saved_index;resource->position=old_position;resource->pose=old_pose;
        resource->pulse_distance=old_pulse;resource->part_enabled=old_enabled;
        for(auto& [model,visible]:resource_visibility)model->visible=visible;
        check(presentation.close()==a::SessionStatus::completed);
    }
    check(DestroyWindow(window)!=0);
#endif
    update.state=old_state;check(update.clock().restore(old_time,old_counter)==u::tasks::Status::completed);
    for(unsigned i=0;i<2;++i)check(update.scripts().restore_channel(i,old_channels[i])==s::Status::completed);
}
std::shared_ptr<a::NativeSession> install(const std::shared_ptr<const reo::assets::Source>& source,Notices& notices,
                                          u::GameplayMessageSink* messages=nullptr){
    auto host=std::make_shared<a::NativeSession>(source,profile(),notices,1,messages);
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
    const auto authored_model=host->archive().read_resource(41,"DEF41.NBD");
    check(authored_model&&input->models->nbd()&&*input->models->nbd()==*authored_model);
    auto foreign=install(source,notices);auto foreign_rooms=std::make_shared<a::SessionRooms>(foreign);
    check(host->bind_resource_assets(input,foreign_rooms)==a::SessionStatus::missing_providers&&!host->resources());++refusals;
    check(host->bind_resource_assets(nullptr,rooms)==a::SessionStatus::missing_providers&&!host->resources());++refusals;
    bool refused{};const auto records=host->scene_records();const auto floor=rooms->retain_floor(73);check(bool(floor));
    // This standalone resource fixture explicitly imports its room before
    // binding the graph; the roster-startup path imports it at 6AD5C0.
    check(bool(rooms->retain(73)));
    check(host->bind_resource_assets(input,rooms)==a::SessionStatus::completed&&host->resources());
    auto& graph=*host->resources();check(graph.bound_to(*host)&&!graph.bound_to(*foreign)&&!graph.initialized());
    host->world().scenario=35;
    check(!host->update().scenario_events().scenario_ready(11,8,{}));
    host->world().scenario=41;
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
    host->world().scenario=35;
    check(host->update().scenario_events().scenario_ready(11,8,{}));
    host->world().scenario=41;
    const auto active=graph.descriptors().active_count();check(host->initialize_resources().status==a::ResourceImportStatus::unavailable_profile&&graph.descriptors().active_count()==active);++refusals;
    check(graph.inventory().bound_to(host->world(),graph.descriptors(),graph.templates()));
    {
        // Actual669790 through the application terminal and canonical inventory.
        a::SessionActorServices service(host->update(),graph.actor_operations(),rooms);
        const auto actor=host->world().primary(0);check(bool(actor));
        const auto old_status=actor->status,old_aux=actor->auxiliary_status;
        const auto old_inventory=actor->inventory;const auto old_lists=host->world().session().auxiliary_resources;
        const auto old_selected=actor->selected_resource,old_primary=actor->primary,old_secondary=actor->secondary,old_character=actor->character;
        const auto old_phase=actor->phase,old_subphase=actor->subphase,old_motion=actor->motion_class;
        const auto old_visible=actor->visible;const auto old_notice=actor->pending_notice;
        const auto old_position=actor->position,old_saved=actor->saved_action_position;
        const auto old_orientation=actor->orientation;const auto old_yaw=actor->saved_action_yaw;
        const auto old_room=actor->room;const auto old_fade=actor->color_fade;
        const auto old_filter=host->world().filter_nonselected_input;
        const auto old_basis=actor->collision.basis;const auto old_center=actor->collision.previous_center_offset,old_local=actor->collision.local_center;
        const auto old_message_phase=host->world().session().message_phase;
        actor->slot=0;actor->category=0;actor->room=73;actor->status=0x40;actor->auxiliary_status=0;
        actor->selected_resource=0;actor->primary=1;actor->secondary=0;actor->phase=5;actor->subphase=6;
        actor->position={11,22,33};actor->orientation[1]=123;
        actor->inventory.carried.fill(0);actor->inventory.storage.fill(0);
        host->world().selected_actor=0;host->world().session().auxiliary_resources={};
        // Read-only terminal preflight follows 5F6800's actual short circuits.
        auto& operations=graph.actor_operations();const auto actor_id=host->world().identity(0);
        const auto descriptor_id=graph.descriptors().slot(255);check(bool(descriptor_id));
        const auto saved_descriptor=graph.descriptors().get(*descriptor_id);check(bool(saved_descriptor));
        auto invalid=*saved_descriptor;invalid.active=1;invalid.template_index=200;invalid.ownership_tag=1;
        invalid.secondary=std::make_shared<s::SceneAttachment>();
        check(graph.descriptors().replace(*descriptor_id,invalid)==s::SceneStatus::completed);
        actor->selected_resource=255;actor->auxiliary_status=0x02000000u;actor->category=1;
        check(operations.transfer_inventory_ready(actor_id,0));
        actor->category=0;check(!operations.transfer_inventory_ready(actor_id,0));
        actor->selected_resource=0;actor->slot=5;host->world().selected_actor=5;actor->auxiliary_status=0;
        check(operations.transfer_inventory_ready(actor_id,0));
        actor->inventory.storage[0]=255;check(!operations.transfer_inventory_ready(actor_id,0));
        actor->slot=0;host->world().selected_actor=0;actor->character=0;
        check(operations.transfer_inventory_ready(actor_id,0));
        actor->character=6;check(!operations.transfer_inventory_ready(actor_id,0));
        check(actor->inventory.storage[0]==255&&graph.descriptors().get(*descriptor_id)->secondary==invalid.secondary);
        check(graph.descriptors().replace(*descriptor_id,*saved_descriptor)==s::SceneStatus::completed);
        actor->selected_resource=0;actor->character=0;actor->inventory={};actor->auxiliary_status=0;
        service.run(w::Stage::prepare_authority,host->world(),*actor);
        check(actor->visible&&actor->motion_class==0xa0&&actor->primary==4&&actor->secondary==1&&actor->phase==0&&actor->subphase==0);
        check(actor->inventory.carried==std::array<std::uint8_t,4>{}&&(actor->auxiliary_status&0x02000000u));
        check(actor->saved_action_position.x==11&&actor->saved_action_position.y==22&&actor->saved_action_yaw==123);
        actor->status=0x60;actor->auxiliary_status=0x80;actor->visible=true;
        service.run(w::Stage::prepare_authority,host->world(),*actor);
        check((actor->status&0x1160)==0x1160&&!actor->visible);
        actor->visible=false;service.run(w::Stage::prepare_contacts,host->world(),*actor);
        actor->collision.basis={{1,0,0},{0,1,0},{0,0,1},{}};actor->collision.local_center={1,2,3};
        service.run(w::Stage::refresh_grid_position,host->world(),*actor);
        check(actor->collision.previous_center_offset.x==1&&actor->collision.previous_center_offset.y==2&&actor->collision.previous_center_offset.z==3);
        std::int8_t grid=42;check(!service.find_grid(host->world(),*actor,grid)&&grid==42);
        const auto objects=rooms->objects();check(bool(objects)&&!objects->grid());
        c::room_objects::InteractionOwner interactions(*objects);const auto ids=objects->objects();check(!ids.empty());
        const auto slot=interactions.source_ordinal(ids[0]);check(bool(slot));
        const auto before=objects->get(ids[0])->count;const auto capacity=objects->type(objects->get(ids[0])->type)->capacity;
        service.switch_grid(host->world(),*slot,-1);
        check(objects->get(ids[0])->count==(before<capacity?before+1:before));
        if(before<capacity){service.switch_grid(host->world(),-1,*slot);check(objects->get(ids[0])->count==before);}
        check(service.grid_response(host->world(),*slot)==c::object_queries::height_offset(*objects,ids[0]));
        actor->status=0;actor->pending_notice=0x2000;host->world().session().message_phase=1;
        bool failed_notice{};try{service.run(w::Stage::publish_notice,host->world(),*actor);}catch(const std::runtime_error&){failed_notice=true;}
        check(failed_notice&&actor->pending_notice==0x2000);
        host->world().session().message_phase=0;service.run(w::Stage::publish_notice,host->world(),*actor);check(actor->pending_notice==0x2000);
        check(!service.remote_motion(host->world(),*actor));
        host->world().filter_nonselected_input=true;check(!service.remote_motion(host->world(),*actor));
        host->world().filter_nonselected_input=old_filter;
        actor->auxiliary_status=0x4000;actor->color_fade=w::ColorFade{0,0x1000000u,2};
        service.run(w::Stage::finish_actor,host->world(),*actor);check(actor->color_fade->updates_left==1&&actor->color_fade->rgba==0x1000000u);
        bool unsupported{};try{service.run(w::Stage::update_behavior,host->world(),*actor);}catch(const std::runtime_error&){unsupported=true;}check(unsupported);
        actor->status=old_status;actor->auxiliary_status=old_aux;actor->inventory=old_inventory;host->world().session().auxiliary_resources=old_lists;
        actor->selected_resource=old_selected;actor->primary=old_primary;actor->secondary=old_secondary;actor->character=old_character;actor->phase=old_phase;actor->subphase=old_subphase;actor->motion_class=old_motion;
        actor->visible=old_visible;actor->pending_notice=old_notice;actor->position=old_position;actor->saved_action_position=old_saved;actor->orientation=old_orientation;actor->saved_action_yaw=old_yaw;actor->room=old_room;actor->color_fade=old_fade;
        actor->collision.basis=old_basis;actor->collision.previous_center_offset=old_center;actor->collision.local_center=old_local;host->world().session().message_phase=old_message_phase;
    }
    {
        // 8122B0 visits all eight physical records, including inactive ones.
        a::SessionActorServices service(host->update(),graph.actor_operations(),rooms);
        struct Saved {
            reo::native::gameplay_ai::ExecutionState execution;
            std::optional<std::int8_t> style;
            std::optional<std::uint32_t> gauge;
            std::int16_t current{},maximum{};
            std::uint32_t status{};
            std::uint8_t character{},ai{},motion{};
            bool active{};
        };
        std::array<Saved,8> saved;
        constexpr std::array<std::int16_t,8> health{100,75,74,50,49,25,24,0};
        constexpr std::array<std::uint32_t,8> gauge{0,74088,75600,119448,120960,134568,136080,151200};
        constexpr std::array<std::uint8_t,8> expected_health{0,0,1,1,2,2,3,3};
        constexpr std::array<std::uint8_t,8> expected_gauge{0,0,1,1,2,2,3,3};
        for(unsigned i=0;i<8;++i){
            const auto actor=host->world().primary(i);check(actor&&actor->ai_execution);
            saved[i]={*actor->ai_execution,actor->speech.display_style,actor->gauge_value,actor->current,actor->maximum,
                      actor->status,actor->character,actor->ai_control,actor->motion_class,actor->active};
            actor->active=bool(i&1);actor->character=0;actor->ai_control=0;actor->current=health[i];actor->maximum=100;
            actor->gauge_value=gauge[i];actor->status=0;actor->motion_class=std::uint8_t(20+i);
            actor->speech.display_style=std::int8_t(i);auto& state=*actor->ai_execution;
            state.previous_display_style_1076=9;state.health_band_1078=8;state.gauge_band_107a=7;state.weight_mode=9;
        }
        service.begin_offline_frame(host->world());
        for(unsigned i=0;i<8;++i){const auto actor=host->world().primary(i);const auto& state=*actor->ai_execution;
            check(actor->speech.display_style==std::int8_t(i)&&state.reference_signal==1&&state.previous_display_style_1076==i);
            check(state.previous_motion_class_106f==20+i&&state.previous_health_band_1079==8&&state.previous_gauge_band_107b==7);
            check(state.health_band_1078==expected_health[i]&&state.gauge_band_107a==expected_gauge[i]);
            check(state.weight_mode==std::uint8_t(i>=2));
        }
        const auto first=host->world().primary(0);first->maximum=0;first->current=-1;first->gauge_value=136079;
        service.begin_offline_frame(host->world());
        check(first->ai_execution->health_band_1078==0&&first->ai_execution->gauge_band_107a==2&&first->ai_execution->weight_mode==0);
        first->gauge_value=135702;service.begin_offline_frame(host->world());
        check(first->ai_execution->gauge_band_107a==2&&first->ai_execution->weight_mode==0);
        first->gauge_value=136080;service.begin_offline_frame(host->world());
        check(first->ai_execution->gauge_band_107a==3&&first->ai_execution->weight_mode==1);
        first->status=1;first->gauge_value=0;service.begin_offline_frame(host->world());check(first->ai_execution->weight_mode==1);
        first->status=0;first->ai_control=1;service.begin_offline_frame(host->world());check(first->ai_execution->weight_mode==0);
        first->maximum=100;first->current=24;service.begin_offline_frame(host->world());check(first->ai_execution->health_band_1078==3&&first->ai_execution->weight_mode==1);
        // The source has no control-byte row bound: ai=2/character=0 aliases
        // the pinned next character's first row while still inside the table.
        first->ai_control=2;first->current=74;service.begin_offline_frame(host->world());check(first->ai_execution->health_band_1078==1&&first->ai_execution->weight_mode==0);
        first->current=49;service.begin_offline_frame(host->world());check(first->ai_execution->health_band_1078==2&&first->ai_execution->weight_mode==1);
        first->character=7;first->ai_control=2;bool policy_refused{};
        try{service.begin_offline_frame(host->world());}catch(const std::runtime_error&){policy_refused=true;}
        check(policy_refused&&first->ai_execution->weight_mode==0);
        first->character=0;first->ai_control=0;
        for(unsigned i=0;i<8;++i)host->world().primary(i)->ai_execution->weight_mode=77;
        const auto fourth=host->world().primary(3);fourth->gauge_value.reset();bool refused{};
        try{service.begin_offline_frame(host->world());}catch(const std::runtime_error&){refused=true;}
        check(refused&&host->world().primary(2)->ai_execution->weight_mode!=77&&fourth->ai_execution->weight_mode==0&&host->world().primary(4)->ai_execution->weight_mode==77);
        for(unsigned i=0;i<8;++i){const auto actor=host->world().primary(i);const auto& old=saved[i];
            *actor->ai_execution=old.execution;actor->speech.display_style=old.style;actor->gauge_value=old.gauge;
            actor->current=old.current;actor->maximum=old.maximum;actor->status=old.status;actor->character=old.character;
            actor->ai_control=old.ai;actor->motion_class=old.motion;actor->active=old.active;
        }
    }
    {
        // Controlled descriptor slots exercise 5B6450 through the session's
        // actual resource graph; no authored item placement is claimed.
        auto& table=graph.descriptors();auto& world=host->world();const auto actor=world.primary(0);const auto id=world.identity(0);
        const auto old_inventory=actor->inventory;const auto old_character=actor->character,old_category=actor->category;
        const auto old_scenario=world.scenario;const auto old_phase=world.session().message_phase;
        std::array<std::uint8_t,6> slots{};std::array<s::SceneResourceId,6> identities{};std::array<s::SceneDescriptor,6> originals{};
        unsigned available{};
        for(unsigned i=1;i<256&&available<slots.size();++i){const auto candidate=table.slot(i);const auto descriptor=table.get(*candidate);
            if(!descriptor->active){slots[available]=std::uint8_t(i);identities[available]=*candidate;originals[available]=*descriptor;++available;}}
        check(available==slots.size());
        const auto replace=[&](unsigned index,std::int16_t quantity,bool active,std::uint8_t template_index){
            s::SceneDescriptor item;item.active=std::uint8_t(active);item.attachment_id=0x3717;item.parameter=quantity;
            item.instance_index=slots[index];item.template_index=template_index;
            check(table.replace(identities[index],item)==s::SceneStatus::completed);
        };
        const auto quantity=[&](unsigned index){return table.get(identities[index])->parameter;};
        actor->category=1;actor->character=0;actor->inventory={};world.scenario=41;world.session().message_phase=0;
        replace(0,-1,false,255);replace(1,0,false,255);replace(2,1,false,255);replace(3,2,false,255);
        actor->inventory.carried={slots[0],slots[1],slots[2],slots[3]};
        check(!graph.consumption().age_carried_expirations(id));
        check(quantity(0)==-1&&quantity(1)==-1&&quantity(2)==0&&quantity(3)==1);
        replace(3,2,false,255);actor->inventory.carried={slots[3],slots[3],0,0};
        check(!graph.consumption().age_carried_expirations(id)&&quantity(3)==0);
        replace(4,2,false,255);replace(5,2,false,255);actor->inventory={};
        actor->inventory.storage[0]=slots[4];actor->inventory.storage[31]=slots[5];
        check(!graph.consumption().age_carried_expirations(id)&&quantity(4)==2&&quantity(5)==2);
        actor->character=6;check(!graph.consumption().age_carried_expirations(id)&&quantity(4)==1&&quantity(5)==1);
        world.scenario=28;check(!graph.consumption().age_carried_expirations(id)&&quantity(4)==1&&quantity(5)==1);
        world.scenario.reset();bool missing_scenario{};try{(void)graph.consumption().age_carried_expirations(id);}catch(const std::runtime_error&){missing_scenario=true;}
        check(missing_scenario&&quantity(4)==1&&quantity(5)==1);world.scenario=41;
        unsigned transform_template=255;std::int16_t transform_content{};
        const auto authored=std::uint8_t(graph.templates().selector(0x3717));
        const auto consider=[&](unsigned index){
            if(index>=graph.templates().state().count||!(graph.templates().flags(std::uint8_t(index))&0x80000u))return false;
            std::int16_t next{};std::memcpy(&next,graph.templates().state().templates[index].encoded.data()+10,sizeof(next));
            if(std::uint16_t(next)==0x3717)return false;
            transform_template=index;transform_content=next;return true;
        };
        if(!consider(authored))for(unsigned i=0;i<graph.templates().state().count;++i)if(consider(i))break;
        check(transform_template!=255);actor->character=0;actor->inventory={};actor->inventory.carried[0]=slots[0];
        replace(0,1,true,std::uint8_t(transform_template));world.session().message_phase=1;
        bool missing_sink{};try{(void)graph.consumption().age_carried_expirations(id);}catch(const std::runtime_error&){missing_sink=true;}
        check(missing_sink&&table.get(identities[0])->attachment_id==std::uint16_t(transform_content));
        replace(0,1,true,std::uint8_t(transform_template));world.session().message_phase=0;
        check(graph.consumption().age_carried_expirations(id)&&table.get(identities[0])->attachment_id==std::uint16_t(transform_content));
        for(unsigned i=0;i<slots.size();++i)check(table.replace(identities[i],originals[i])==s::SceneStatus::completed);
        actor->inventory=old_inventory;actor->character=old_character;actor->category=old_category;world.scenario=old_scenario;world.session().message_phase=old_phase;
    }
    check(host->install_room({41,73,0})==a::SessionStatus::missing_providers&&host->scene_records()==records);++refusals;
    a::SessionResourceWorkers workers_owner(*host,graph,remaining);
    refused=false;try{workers_owner.run(u::Worker::resource_instances,host->update());}catch(const std::runtime_error&){refused=true;}
    check(refused&&!host->world().cinematic_controller());++refusals;
    const auto created=graph.factory().create(0x81);check(created.status==w::ResourceModelStatus::completed&&created.model&&created.model->work&&created.model->asset_index==0&&created.model->base_parts&&created.model->base_parts->count==4);
    {
        const auto actual=created.model->work;auto reentrant=std::make_shared<DirectReentrantClose>(*host);created.model->work=reentrant;
        const auto pass=graph.models().update(false);check(pass.status==w::ResourceModelStatus::completed&&reentrant->calls==1);
        check(!graph.busy()&&graph.initialized()&&host->update().scenario_events().ready());created.model->work=actual;
    }
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
        camera_frame(*host,*rooms,source);
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
    host->world().scenario=35;
    check(host->update().scenario_events().scenario_command(11,8,{})==s::ScenarioEventStatus::completed);
    check(host->update().events().slot(0,8)&&graph.close()==a::SessionResourceStatus::busy&&graph.initialized());
    check(host->update().events().slot(0,8).has_value());
    host->world().scenario=41;
    const auto retained=created.model;std::weak_ptr<a::NativeSession> weak=host;
    check(host->close()==a::SessionStatus::completed&&!retained->current()&&!host->update().events().slot(0,8));host.reset();
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
    // A sealed task scheduler does not mean ScenarioEvents was closed. The
    // standalone graph must retain its borrowed visual owner and live task.
    auto sealed=install(source,notices);auto sealed_rooms=std::make_shared<a::SessionRooms>(sealed);
    check(sealed->bind_resource_assets(input,sealed_rooms)==a::SessionStatus::completed);
    check(sealed->initialize_resources().status==a::ResourceImportStatus::completed);
    sealed->world().scenario=35;
    check(sealed->update().scenario_events().scenario_command(11,8,{})==s::ScenarioEventStatus::completed);
    check(sealed->update().events().seal()==reo::native::gameplay_tasks::Status::completed);
    check(!sealed->update().scenario_events().ready()&&sealed->resources()->close()==a::SessionResourceStatus::resource_failure);
    check(sealed->resources()->initialized()&&sealed->resources()->visuals().admitted()&&sealed->update().events().slot(0,8));
    check(sealed->close()==a::SessionStatus::completed&&!sealed->update().events().slot(0,8));
    // Actual direct 68EF50 publication must pin both the Update and the
    // retained resource graph through each synchronous transport callback.
    TerminalCloseSink sink;auto terminal_host=install(source,notices,&sink);sink.host=terminal_host.get();
    terminal_host->world().session().collision_disabled_mask=0;auto active_rooms=std::make_shared<a::SessionRooms>(terminal_host);
    check(terminal_host->bind_resource_assets(input,active_rooms)==a::SessionStatus::completed);
    check(terminal_host->initialize_resources().status==a::ResourceImportStatus::completed);
    auto actor=terminal_host->world().primary(0);actor->active=true;actor->slot=0;actor->category=0;
    actor->status=0;actor->auxiliary_status=0;actor->room=73;actor->character=0;
    actor->selected_resource=0;actor->inventory={};actor->gauge_value=0;
    terminal_host->world().selected_actor=0;terminal_host->world().session().message_phase=1;
    check(terminal_host->update().actor_script_terminal().command_ready());
    check(terminal_host->update().actor_script_terminal().command()==s::ActorScriptTerminalStatus::completed);
    check(sink.guarded&&sink.room_calls==1&&sink.snapshot_calls==1&&terminal_host->resources()->initialized());
    std::vector<std::byte> terminal_commands;record(terminal_commands,0x60,{});record(terminal_commands,0xa,{});
    const auto terminal_program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{terminal_commands});
    check(!terminal_program->unsupported()&&terminal_host->update().scripts().install(1,terminal_program)==s::Status::completed);
    const auto script=terminal_host->step_room_script();
    check(script.status==a::SessionStatus::completed&&script.update.script_operations>0&&sink.guarded&&sink.room_calls==2&&sink.snapshot_calls==2);
    // Source-qualified 172/6C/106 records through the same real app VM and graph.
    auto* terminal_graph=terminal_host->resources();const auto resource=terminal_graph->descriptors().slot(3);check(bool(resource));
    auto content=*terminal_graph->descriptors().get(*resource);content.active=0;content.attachment_id=10206;
    check(terminal_graph->descriptors().replace(*resource,content)==s::SceneStatus::completed);
    actor->active=true;actor->ai_control=0;actor->inventory.carried[0]=3;
    actor->transient_equipment=0;actor->control_request.parameter=0x2222;
    auto other=terminal_host->world().primary(1);other->transient_action=0;other->interaction_request.reset();
    std::vector<std::byte> interactions;record(interactions,1,{});
    record(interactions,0x172,{10206,73});record(interactions,0x172,{10207,74});
    record(interactions,0x6c,{0,20,1,12});record(interactions,0x106,{1,3822,4294966196u,909,32768});record(interactions,0xa,{});
    const auto interaction_program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{interactions});
    check(!interaction_program->unsupported()&&terminal_host->update().scripts().install(1,interaction_program)==s::Status::completed);
    const auto interaction_step=terminal_host->step_room_script();
    const auto& request=terminal_host->world().session().actor_placements.requests()[0];
    check(interaction_step.status==a::SessionStatus::completed&&interaction_step.update.script_operations>=5&&
          terminal_host->update().flags().get(s::FlagBank::local_primary,73)==true&&
          terminal_host->update().flags().get(s::FlagBank::local_primary,74)==false);
    check(actor->transient_equipment==1&&actor->control_request.kind==12&&actor->control_request.parameter==0x2222&&
          request.state==0&&request.room==20&&request.position==1&&terminal_host->world().session().actor_placements.selected_request==1);
    check(other->interaction_request&&other->interaction_request->anchor.x==3822.f&&
          other->interaction_request->anchor.y==4294966272.f&&other->interaction_request->anchor.z==909.f&&
          other->interaction_request->orientation==0xffff8000u&&other->transient_action==0);
    // Offline702CE0 through the real VM and the app's initialized resource graph.
    actor->active=true;actor->visible=true;actor->ai_control=1;actor->status=1;actor->auxiliary_status=0;
    actor->inventory={};actor->selected_resource=0;
    check(terminal_host->update().actor_script_terminal().retire_offline_actor_ready(0));
    std::vector<std::byte> retire;record(retire,1,{});record(retire,0x1a9,{0});record(retire,0xa,{});
    const auto retire_program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{retire},s::DispatchProfile::offline_actor);
    s::Interpreter offline_vm;check(offline_vm.install(0,retire_program)==s::Status::completed);
    s::Providers retirement;retirement.world=&terminal_host->world();retirement.flags=retirement.canonical_flags=&terminal_host->update().flags();
    retirement.actor_script_terminal=&terminal_host->update().actor_script_terminal();
    check(offline_vm.tick_offline_channel(0,{true,false,0,73},{0,0,73},retirement).status==s::Status::yielded);
    check(!actor->active&&!actor->visible&&actor->status==0x5e1&&(actor->auxiliary_status&0x02000000u));
    {
        // Actual7030F0 through NativeSession's offline party dispatcher and
        // the same initialized descriptor/template/inventory graph.
        auto& world=terminal_host->world();const auto mode=world.mode;world.mode=0;
        const auto recipient=world.primary(1);check(bool(recipient));
        actor->active=true;actor->ai_control=0;actor->room=world.room;
        recipient->active=true;recipient->ai_control=1;recipient->room=world.room;
        recipient->inventory.carried.fill(0);recipient->inventory.storage.fill(0);
        world.primary(2)->active=false;world.selected_actor=0;
        std::vector<std::byte> command;record(command,1,{});record(command,0x175,{1,10209,1,0});record(command,0xa,{});
        const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{command},s::DispatchProfile::offline_actor);
        check(!program->unsupported()&&terminal_host->update().scripts().install(1,program)==s::Status::completed);
        std::vector<std::byte> loop;record(loop,1,{});record(loop,0xa,{});
        const auto idle=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{loop},s::DispatchProfile::offline_actor);
        for(unsigned channel:{2u,3u})check(terminal_host->update().scripts().install(channel,idle)==s::Status::completed);
        const auto result=terminal_host->step_room_script();check(result.status==a::SessionStatus::completed);
        const auto granted=terminal_graph->descriptors().find_inventory_content(recipient->inventory,10209);check(granted!=0);
        const auto entry=terminal_graph->descriptors().slot(granted);const auto value=entry?terminal_graph->descriptors().get(*entry):std::nullopt;
        check(value&&value->active&&value->kind==0&&value->ownership_tag==2&&value->parameter==1);
        check(terminal_graph->initialized()&&!result.update.clock_committed);world.mode=mode;
    }
    check(terminal_host->close()==a::SessionStatus::completed);
}
}
int main(int argc,char** argv)try{
    check(argc==4);owned(argv[1],argv[2],argv[3]);
    std::cout<<"{\"checks\":"<<checks<<",\"selected\":"<<selected<<",\"placed\":"<<placed<<",\"starting\":"<<starting<<",\"workers\":"<<workers<<",\"refusals\":"<<refusals<<",\"guards\":"<<guards<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
