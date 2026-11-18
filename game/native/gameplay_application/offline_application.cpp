#include "offline_application.hpp"
#include "../gameplay_navigation/bank.hpp"
#include "../gameplay_scenario/actor_voice_archive_assets.hpp"
#include "../gameplay_scenario/actor_voice_selections.hpp"
#include "../gameplay_scenario/stream_instances.hpp"
#include <new>
#include <utility>

namespace reo::native::gameplay_application {
OfflineApplication::OfflineApplication(OfflineLaunchInput input,std::shared_ptr<NativeSession> session,
                                       std::unique_ptr<SessionStartup> startup):
    input_(std::move(input)),session_(std::move(session)),startup_(std::move(startup)){}
OfflineApplicationCreated OfflineApplication::create_fresh(OfflineLaunchInput input,
    gameplay_scenario::FlagNotifications& notifications,gameplay_update::GameplayMessageSink* messages)noexcept{
    const auto roster=gameplay_session::parse_launch_roster(input.launch_record);
    if(!input.source||!input.motion_banks||!input.effects||!input.contacts||input.static_model_key.empty()||
       !roster||roster->scenario!=input.room.scenario)
        return{OfflineApplicationStatus::invalid_input,{}};
    try{
        auto session=std::make_shared<NativeSession>(input.source,input.profile,notifications,0,messages);
        // Both values are established once at this explicit fresh-process
        // boundary. Neither a warm retry nor generic NativeSession performs it.
        if(!session->world().navigation().initialize_cold_empty())return{};
        session->world().session().room_variants.restore(std::array<std::uint8_t,128>{});
        // 3243FE is in the pinned File1 ELF's zero-filled PT_LOAD BSS. This
        // fresh-process boundary establishes it once; retries never reset it.
        session->world().session().scene_stream_stage=0;
        //5EADD0 clears4BADD0..4BAE9F, including the channel5 suppression byte.
        session->update().state.transition_gate=0; //4BAE76, shared with channel5 receipt
        // Source1BAC20 publishes3243FD=1 for this stock File1US startup.
        //3151C0..316350 lie in the pinned ELF's zero-filled BSS. Establish the
        // canonical empty cache once here; warm loads never clear it.
        if(session->select_scene_message_catalog(gameplay_scenario::SceneTextVariant::alternate)!=SessionStatus::completed||
           !session->application_lifecycle().begin_preparation())return{};
        session->text_cache().reset();
        auto startup=std::make_unique<SessionStartup>(*session,input.source,input.motion_banks);
        if(startup->adopt_cold_roster_kinds()!=gameplay_world::PrimaryStartupStatus::completed)return{};
        if(startup->adopt_cold_reference_heights()!=gameplay_world::PrimaryStartupStatus::completed)return{};
        auto background=std::make_unique<gameplay_presentation::BackgroundState>();startup->bind_background(background.get());
        std::shared_ptr<gameplay_scenario::ActorVoiceSelections> voices;
        std::shared_ptr<const afs_source_range::Archive> sound_archive;
        if(input.voice_source){
            const gameplay_scenario::ActorVoiceArchiveAssets assets(input.voice_source);
            sound_archive=assets.sound_archive();
            auto catalog=std::make_shared<gameplay_scenario::StreamAssetCatalog>();
            if(!catalog->add_actor_voice_archives(assets))return{};
            catalog->seal();voices=std::make_shared<gameplay_scenario::ActorVoiceSelections>(std::move(catalog));
            startup->bind_voices(voices);
        }
        auto result=std::unique_ptr<OfflineApplication>(new OfflineApplication(std::move(input),std::move(session),std::move(startup)));
        result->voices_=std::move(voices);
        result->sound_archive_=std::move(sound_archive);
        result->background_=std::move(background);
        result->graphics_=std::make_unique<gameplay_presentation::GraphicsState>();
        result->frontend_=std::unique_ptr<SessionFrontend>(new SessionFrontend(result->session_->world(),*result->background_,*result->graphics_,
            result->session_->text_cache(),result->input_.source));
        if(!messages){
            result->room_transport_=std::make_unique<SessionRoomTransport>(*result->session_);
            if(result->room_transport_->initialize()!=RoomTransportStatus::completed||
               result->session_->update().bind_message_sink(result->room_transport_.get())!=gameplay_update::Status::completed)return{};
        }
        return{OfflineApplicationStatus::completed,std::move(result)};
    }catch(...){return{};}
}
FrontendResult OfflineApplication::begin_frontend()noexcept{
    if(closed_||!session_->open())return{FrontendStatus::closed};
    if(running_||startup_->busy()||session_->busy())return{FrontendStatus::busy};
    if(stage_!=OfflinePrepareStage::records||started_||!frontend_)return{FrontendStatus::unavailable};
    if(!display_clock_||display_clock_->counter().status!=gameplay_presentation::VBlankStatus::completed)
        return{FrontendStatus::unavailable,frontend_->stage()};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    //1BAA00's1BAEC0 allocation precedes the1BCCB0 frontend task. Retries
    // preserve the same initialized data owners and any retained publications.
    auto& scenario_data=startup_->scenario_resources();
    if(!scenario_data.ready()&&scenario_data.initialize()!=ScenarioDataStatus::completed)
        return{FrontendStatus::unavailable,frontend_->stage()};
    const auto result=frontend_->begin();
    // Publish this capability only after the actual frontend initialized its
    // selectors. Merely allocating an unknown GraphicsState is insufficient.
    if(frontend_->stage()>=FrontendStage::callbacks&&!startup_->bind_graphics(graphics_.get()))
        return{FrontendStatus::unavailable,result.stage};
    if(startup_->bind_frontend(frontend_->common_textures(),frontend_display_.get())!=StartupTextureStatus::completed)
        return{FrontendStatus::unavailable,result.stage};
    return result;
}
OfflineApplicationStatus OfflineApplication::bind_display_clock(void* window)noexcept{
    if(closed_||!session_->open())return OfflineApplicationStatus::closed;
    if(running_||startup_->busy()||session_->busy())return OfflineApplicationStatus::busy;
    if(started_||display_clock_||!input_source_||!input_source_->bound_to_window(window)||
       (frontend_&&frontend_->pool()))return OfflineApplicationStatus::unavailable;
    auto opened=gameplay_presentation::WindowsVBlank::open(window);
    if(opened.status!=gameplay_presentation::VBlankStatus::completed||!opened.owner)return OfflineApplicationStatus::unavailable;
    try{
        auto display=std::make_unique<gameplay_presentation::FrontendDisplay>(session_->world(),window,*opened.owner,*background_);
        if(startup_->bind_frontend(frontend_->common_textures(),display.get())!=StartupTextureStatus::completed)
            return OfflineApplicationStatus::unavailable;
        display_clock_=std::move(opened.owner);frontend_display_=std::move(display);return OfflineApplicationStatus::completed;
    }catch(...){return OfflineApplicationStatus::unavailable;}
}
OfflineApplicationStatus OfflineApplication::bind_audio(std::shared_ptr<audio_mix_tail::Mixer> mixer,
    std::shared_ptr<adxt_output_session::Session> output)noexcept{
    if(closed_||!session_->open())return OfflineApplicationStatus::closed;
    if(running_||startup_->busy()||session_->busy())return OfflineApplicationStatus::busy;
    if(audio_||!sound_archive_)return OfflineApplicationStatus::unavailable;
    try{
        auto audio=std::make_unique<SessionAudio>(session_->world(),std::move(mixer),std::move(output),sound_archive_);
        if(!startup_->bind_audio(audio.get()))return OfflineApplicationStatus::unavailable;
        audio_=std::move(audio);frontend_->bind_audio(audio_.get());return OfflineApplicationStatus::completed;
    }
    catch(...){return OfflineApplicationStatus::unavailable;}
}
OfflineApplication::~OfflineApplication(){const auto status=close();if(status==OfflineApplicationStatus::busy||status==OfflineApplicationStatus::pending_collision)std::terminate();}
OfflineApplicationStatus OfflineApplication::bind_input(reo::Input& input,void* window)noexcept{
    if(closed_||!session_->open())return OfflineApplicationStatus::closed;
    if(running_||startup_->busy()||session_->update().busy()||session_->world().busy())return OfflineApplicationStatus::busy;
    if(started_||input_source_)return OfflineApplicationStatus::unavailable;
    try{
        auto owner=std::make_unique<SessionInput>(session_->world(),input,window);
        if(!owner->poll())return OfflineApplicationStatus::unavailable;
        startup_->bind_input(owner.get());input_source_=std::move(owner);
        return OfflineApplicationStatus::completed;
    }catch(...){return OfflineApplicationStatus::unavailable;}
}
OfflinePrepareResult OfflineApplication::prepare()noexcept{
    if(closed_||!session_->open())return{OfflineApplicationStatus::closed,stage_};
    if(running_||startup_->busy()||session_->update().busy()||session_->world().busy())return{OfflineApplicationStatus::busy,stage_};
    if(frontend_&&frontend_->pool()&&frontend_->stage()!=FrontendStage::complete)return{OfflineApplicationStatus::unavailable,stage_};
    if(stage_==OfflinePrepareStage::ready)return{OfflineApplicationStatus::completed,stage_};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    try{
        if(stage_==OfflinePrepareStage::records){
            if(startup_->initialize_records().status!=gameplay_world::PrimaryRecordsStatus::completed)return{OfflineApplicationStatus::unavailable,stage_};
            stage_=OfflinePrepareStage::roster;
        }
        if(stage_==OfflinePrepareStage::roster){
            if(session_->update().initialize_launch_roster(input_.launch_record)!=gameplay_update::Status::completed)return{OfflineApplicationStatus::unavailable,stage_};
            stage_=OfflinePrepareStage::difficulty;
        }
        if(stage_==OfflinePrepareStage::difficulty){
            if(session_->import_launch_difficulty(input_.difficulty)!=SessionStatus::completed)return{OfflineApplicationStatus::unavailable,stage_};
            stage_=OfflinePrepareStage::room;
        }
        if(stage_==OfflinePrepareStage::room){
            if(session_->install_room(input_.room)!=SessionStatus::completed)return{OfflineApplicationStatus::unavailable,stage_};
            stage_=OfflinePrepareStage::assets;
        }
        if(stage_==OfflinePrepareStage::assets){
            if(!rooms_)rooms_=std::make_shared<SessionRooms>(session_);
            const auto assets=SessionResourceAssets::load(session_->archive(),input_.room.scenario,input_.static_model_key,input_.effects,input_.contacts);
            if(session_->bind_resource_assets(assets,rooms_)!=SessionStatus::completed)return{OfflineApplicationStatus::unavailable,stage_};
            // Adopt5D7D60's priority gate reset before the first EVB startup.
            // The later actual1D4020 startup callback supplies message bytes.
            session_->scene_text_bank().priority().reset_active();
            stage_=OfflinePrepareStage::ready;
        }
        return{OfflineApplicationStatus::completed,stage_};
    }catch(...){return{OfflineApplicationStatus::unavailable,stage_};}
}
gameplay_world::PrimaryStartupReport OfflineApplication::start(gameplay_world::PrimaryStartupEffects* effects,
    const gameplay_world::PrimaryEquipmentContext* equipment)noexcept{
    using S=gameplay_world::PrimaryStartupStatus;
    if(closed_||!session_->open())return{S::closed};
    if(running_||startup_->busy()||session_->update().busy()||session_->world().busy())return{S::busy};
    if(stage_!=OfflinePrepareStage::ready||started_)return{S::unavailable};
    if(input_source_&&!input_source_->poll())return{S::unavailable};
    if(room_transport_&&display_clock_&&!room_transport_->active()){
        const auto tick=display_clock_->counter();
        if(tick.status!=gameplay_presentation::VBlankStatus::completed||
           room_transport_->activate(tick.count)!=RoomTransportStatus::completed)return{S::unavailable};
    }
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    auto& lifecycle=session_->application_lifecycle();
    if(lifecycle.phase()!=gameplay_session::ApplicationLifecycle::Phase::gameplay&&!lifecycle.enter_gameplay())return{S::unavailable};
    auto result=startup_->start(effects,equipment);started_=result.status==S::completed;return result;
}
OfflineApplicationStatus OfflineApplication::bind_frame(gameplay_update::PhaseServices& phases,SessionCollisionInputs& inputs,
    gameplay_world::SecondaryCollisionWalls& walls)noexcept{
    if(closed_||!session_->open())return OfflineApplicationStatus::closed;
    if(running_||startup_->busy()||session_->update().busy()||session_->world().busy())return OfflineApplicationStatus::busy;
    if(!started_)return OfflineApplicationStatus::not_started;
    if(frame_)return OfflineApplicationStatus::frame_already_bound;
    auto* resources=session_->resources();
    if(!resources||!resources->initialized()||!rooms_)return OfflineApplicationStatus::not_prepared;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    try{
        auto actors=std::make_unique<SessionActorServices>(session_->update(),resources->actor_operations(),rooms_);
        auto frame=std::make_unique<SessionCollisionFrame>(session_,rooms_,phases,*actors,inputs,walls);
        actors_=std::move(actors);frame_=std::move(frame);return OfflineApplicationStatus::completed;
    }catch(...){return OfflineApplicationStatus::unavailable;}
}
OfflineApplicationStatus OfflineApplication::bind_presentation(void* window,gameplay_scenario::CameraProjectionContext context,
    std::int8_t mode,std::uint32_t width,std::uint32_t height)noexcept{
    if(closed_||!session_->open())return OfflineApplicationStatus::closed;
    if(running_||startup_->busy()||session_->update().busy()||session_->world().busy())return OfflineApplicationStatus::busy;
    if(!started_)return OfflineApplicationStatus::not_started;
    if(presentation_)return OfflineApplicationStatus::presentation_already_bound;
    if(!input_source_||!input_source_->bound_to_window(window)||!rooms_)return OfflineApplicationStatus::unavailable;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    try{
        const auto font=frontend_?frontend_->font():nullptr;
        presentation_=std::make_unique<gameplay_presentation::SessionPresentation>(*session_,*rooms_,window,*background_,context,mode,width,height,graphics_.get(),
            font,font?&frontend_->text_gate():nullptr,frontend_?&frontend_->display_fade():nullptr,
            frontend_?&frontend_->letterbox():nullptr);return OfflineApplicationStatus::completed;
    }
    catch(...){return OfflineApplicationStatus::unavailable;}
}
FrameStep OfflineApplication::advance(std::span<const std::int16_t> amounts,std::size_t scripts,std::size_t tasks){
    if(closed_||!session_->open())return{SessionStatus::closed,{}};
    if(running_||startup_->busy()||session_->update().busy()||session_->world().busy())return{SessionStatus::busy,{}};
    if(!started_)return{SessionStatus::missing_providers,{}};
    if(!frame_)return{SessionStatus::missing_frame_services,{}};
    if(input_source_&&!input_source_->poll())return{SessionStatus::missing_providers,{}};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    if(room_transport_&&room_transport_->active()&&room_transport_->pump().status!=RoomTransportStatus::completed)
        return{SessionStatus::frame_failure,{}};
    auto result=frame_->advance_native_behavior(amounts,scripts,tasks);
    if(result.status==SessionStatus::completed&&presentation_){
        try{if(!presentation_->present())result.status=SessionStatus::frame_failure;}
        catch(...){result.status=SessionStatus::frame_failure;}
    }
    if(result.status==SessionStatus::completed&&frontend_&&frontend_->stage()>=FrontendStage::common_sound&&
       frontend_->advance_display_callbacks()!=FrontendStatus::completed)result.status=SessionStatus::frame_failure;
    return result;
}
OfflineApplicationStatus OfflineApplication::close()noexcept{
    if(closed_)return OfflineApplicationStatus::completed;
    if(running_||startup_->busy()||session_->busy())return OfflineApplicationStatus::busy;
    if(frame_&&frame_->bodies().pending())return OfflineApplicationStatus::pending_collision;
    if(audio_&&audio_->busy())return OfflineApplicationStatus::busy;
    if(!startup_->bind_audio(nullptr))return OfflineApplicationStatus::busy;
    const auto frontend_release=startup_->bind_frontend({},nullptr);
    if(frontend_release==StartupTextureStatus::busy)return OfflineApplicationStatus::busy;
    if(frontend_release!=StartupTextureStatus::completed)return OfflineApplicationStatus::unavailable;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    if(voices_){const auto status=voices_->close();if(status==gameplay_scenario::StreamStatus::busy)return OfflineApplicationStatus::busy;if(status!=gameplay_scenario::StreamStatus::completed)return OfflineApplicationStatus::unavailable;}
    if(frontend_)frontend_->bind_audio(nullptr);
    if(audio_&&!audio_->close())return OfflineApplicationStatus::busy;
    audio_.reset();sound_archive_.reset();
    frontend_display_.reset();
    const auto clock=display_clock_?display_clock_->close():gameplay_presentation::VBlankStatus::completed;
    display_clock_.reset();
    const auto presentation=presentation_?presentation_->close():SessionStatus::completed;
    if(presentation==SessionStatus::busy)return OfflineApplicationStatus::busy;
    presentation_.reset();
    if(room_transport_){
        if(room_transport_->close()==RoomTransportStatus::busy)return OfflineApplicationStatus::busy;
        if(session_->open()&&session_->update().bind_message_sink(nullptr,room_transport_.get())!=gameplay_update::Status::completed)
            return OfflineApplicationStatus::unavailable;
        room_transport_.reset();
    }
    const auto result=session_->close();
    if(result==SessionStatus::busy)return OfflineApplicationStatus::busy;
    frame_.reset();actors_.reset();
    const auto startup=startup_->close();
    if(startup==gameplay_world::PrimaryStartupStatus::busy)return OfflineApplicationStatus::busy;
    if(frontend_&&frontend_->close()==FrontendStatus::busy)return OfflineApplicationStatus::busy;
    frontend_.reset();
    startup_->bind_input(nullptr);input_source_.reset();graphics_.reset();background_.reset();closed_=true;started_=false;
    return result==SessionStatus::completed&&presentation==SessionStatus::completed&&startup==gameplay_world::PrimaryStartupStatus::completed&&
        clock==gameplay_presentation::VBlankStatus::completed?
        OfflineApplicationStatus::completed:OfflineApplicationStatus::unavailable;
}
}
