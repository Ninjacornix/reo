#include "cutscene_playback.hpp"
#include "cutscene_actor_tracks.hpp"
#include "cutscene_object_tracks.hpp"
#include "cutscene_camera.hpp"
#include "cutscene_display.hpp"
#include "cutscene_view_controls.hpp"
#include "cutscene_lights.hpp"
#include "../gameplay_update/update.hpp"
#include <bit>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
struct Unavailable {CutscenePlaybackStatus status;};
void require(CutscenePlaybackStatus status){if(status!=CutscenePlaybackStatus::completed&&status!=CutscenePlaybackStatus::waiting)throw Unavailable{status};}
std::int8_t increment(std::int8_t value){return std::bit_cast<std::int8_t>(std::uint8_t(unsigned(std::bit_cast<std::uint8_t>(value))+1));}
CutscenePlaybackStatus stream_status(StreamStatus status){
    switch(status){case StreamStatus::completed:return CutscenePlaybackStatus::completed;case StreamStatus::pending:return CutscenePlaybackStatus::waiting;case StreamStatus::closed:return CutscenePlaybackStatus::closed;case StreamStatus::busy:return CutscenePlaybackStatus::busy;default:return CutscenePlaybackStatus::unavailable;}
}
}
bool cutscene_acknowledgements_complete(std::uint8_t mode,std::uint8_t mask,std::uint8_t participants)noexcept{
    if(!mode)return mask!=0;
    unsigned acknowledged{};for(unsigned i=0;i<participants;++i)acknowledged+=(std::uint32_t(mask)&(1u<<(i&31u)))!=0;
    return acknowledged==participants;
}
CutscenePlayback::CutscenePlayback(gameplay_update::Owner& owner,StreamChannels& channels,StreamBackend& streams,CutscenePlaybackServices& services)
    :CutscenePlayback(owner.world(),owner.flags(),owner.state.audio_tick,channels,streams,services){}
CutscenePlayback::CutscenePlayback(gameplay_world::World& world,FlagState& flags,const std::optional<std::uint32_t>& tick,StreamChannels& channels,StreamBackend& streams,CutscenePlaybackServices& services)
    :world_(world),flags_(flags),audio_tick_(tick),channels_(channels),streams_(streams),voice_(world,channels,streams,tick),services_(services){
    if(world_.closed()||world_.busy()||world_.cutscene_playback_owner_)throw std::invalid_argument("Native cutscene playback World unavailable or already bound");
    world_.cutscene_playback_owner_=this;
}
CutscenePlayback::~CutscenePlayback(){
    if(busy())std::terminate();
    if(world_.cutscene_playback_owner_==this)world_.cutscene_playback_owner_=nullptr;
}
CutscenePlaybackStatus CutscenePlayback::bind_camera(std::unique_ptr<CutsceneCamera>& camera)noexcept{
    if(busy()||world_.busy())return CutscenePlaybackStatus::busy;
    if(world_.closed())return CutscenePlaybackStatus::closed;
    if(!camera||camera_||!camera->bound_to(state_))return CutscenePlaybackStatus::unavailable;
    camera_=std::move(camera);return CutscenePlaybackStatus::completed;
}
CutscenePlaybackStatus CutscenePlayback::unbind_camera()noexcept{
    if(busy()||world_.busy())return CutscenePlaybackStatus::busy;
    if(world_.closed())return CutscenePlaybackStatus::closed;
    camera_.reset();return CutscenePlaybackStatus::completed;
}
CutscenePlaybackStatus CutscenePlayback::bind_display(std::unique_ptr<CutsceneDisplay>& display)noexcept{
    if(busy()||world_.busy())return CutscenePlaybackStatus::busy;
    if(world_.closed())return CutscenePlaybackStatus::closed;
    if(!display||display_||!display->bound_to(state_,world_.session().clock_mode))return CutscenePlaybackStatus::unavailable;
    display_=std::move(display);return CutscenePlaybackStatus::completed;
}
CutscenePlaybackStatus CutscenePlayback::unbind_display()noexcept{
    if(busy()||world_.busy())return CutscenePlaybackStatus::busy;
    if(world_.closed())return CutscenePlaybackStatus::closed;
    display_.reset();return CutscenePlaybackStatus::completed;
}
CutscenePlaybackStatus CutscenePlayback::bind_view_controls(std::unique_ptr<CutsceneViewControls>& controls)noexcept{
    if(busy()||world_.busy())return CutscenePlaybackStatus::busy;
    if(world_.closed())return CutscenePlaybackStatus::closed;
    if(!controls||view_controls_||!controls->bound_to(state_,world_.session().clock_mode))return CutscenePlaybackStatus::unavailable;
    view_controls_=std::move(controls);return CutscenePlaybackStatus::completed;
}
CutscenePlaybackStatus CutscenePlayback::unbind_view_controls()noexcept{
    if(busy()||world_.busy())return CutscenePlaybackStatus::busy;
    if(world_.closed())return CutscenePlaybackStatus::closed;
    view_controls_.reset();return CutscenePlaybackStatus::completed;
}
CutscenePlaybackStatus CutscenePlayback::fullscreen_color(std::uint32_t value){
    if(!view_controls_)return services_.fullscreen_color(value);
    view_controls_->reset_color(value);return CutscenePlaybackStatus::completed;
}
CutscenePlaybackStatus CutscenePlayback::bind_lights(std::unique_ptr<CutsceneLights>& lights)noexcept{
    if(busy()||world_.busy()||(lights&&lights->busy()))return CutscenePlaybackStatus::busy;
    if(world_.closed())return CutscenePlaybackStatus::closed;
    if(!lights||lights_||!lights->bound_to(world_,state_))return CutscenePlaybackStatus::unavailable;
    lights_=std::move(lights);light_running_=&lights_->running_;return CutscenePlaybackStatus::completed;
}
CutscenePlaybackStatus CutscenePlayback::unbind_lights()noexcept{
    if(busy()||world_.busy())return CutscenePlaybackStatus::busy;
    if(world_.closed())return CutscenePlaybackStatus::closed;
    light_running_=nullptr;lights_.reset();return CutscenePlaybackStatus::completed;
}
CutscenePlaybackStatus CutscenePlayback::fade(bool rising,std::int16_t duration,std::uint32_t color){
    if(!display_)return services_.fade(rising,duration,color);
    display_->fade(rising,duration,color);return CutscenePlaybackStatus::completed;
}
CutscenePlaybackValue CutscenePlayback::fade_finished(){
    return display_?CutscenePlaybackValue{CutscenePlaybackStatus::completed,display_->fade_finished()}:services_.fade_finished();
}
CutscenePlaybackStatus CutscenePlayback::frame_work(CutsceneFrameWork work,std::int8_t group){
    if(lights_&&(work==CutsceneFrameWork::light_tracks||work==CutsceneFrameWork::light_interpolation)){
        const auto status=work==CutsceneFrameWork::light_tracks?lights_->tick().status:lights_->sample(group).status;
        switch(status){case CutsceneLightsStatus::completed:return CutscenePlaybackStatus::completed;case CutsceneLightsStatus::busy:return CutscenePlaybackStatus::busy;case CutsceneLightsStatus::closed:return CutscenePlaybackStatus::closed;case CutsceneLightsStatus::no_memory:return CutscenePlaybackStatus::no_memory;default:return CutscenePlaybackStatus::unavailable;}
    }
    if(view_controls_&&(work==CutsceneFrameWork::scene_controls||work==CutsceneFrameWork::fullscreen_curve)){
        const auto status=work==CutsceneFrameWork::scene_controls?view_controls_->tick().status:view_controls_->sample_color();
        switch(status){case CutsceneViewStatus::completed:return CutscenePlaybackStatus::completed;case CutsceneViewStatus::no_memory:return CutscenePlaybackStatus::no_memory;default:return CutscenePlaybackStatus::unavailable;}
    }
    const auto map=[](CutsceneTrackStatus status){switch(status){case CutsceneTrackStatus::completed:return CutscenePlaybackStatus::completed;case CutsceneTrackStatus::busy:return CutscenePlaybackStatus::busy;case CutsceneTrackStatus::closed:return CutscenePlaybackStatus::closed;case CutsceneTrackStatus::no_memory:return CutscenePlaybackStatus::no_memory;default:return CutscenePlaybackStatus::unavailable;}};
    if(work==CutsceneFrameWork::actor_tracks){
        if(!world_.cutscene_tracks_owner_)return CutscenePlaybackStatus::unavailable;
        return map(world_.cutscene_tracks_owner_->tick(state_.frame,state_.request.current.scene,services_.speech()).status);
    }
    if(work==CutsceneFrameWork::object_tracks){
        if(!world_.cutscene_object_tracks_owner_)return CutscenePlaybackStatus::unavailable;
        return map(world_.cutscene_object_tracks_owner_->tick(state_.frame).status);
    }
    if(camera_&&work==CutsceneFrameWork::camera_selection){
        switch(camera_->select(world_.session().clock_mode)){
        case CutsceneCameraStatus::completed:return CutscenePlaybackStatus::completed;
        case CutsceneCameraStatus::no_memory:return CutscenePlaybackStatus::no_memory;
        default:return CutscenePlaybackStatus::unavailable;
        }
    }
    if(camera_&&work==CutsceneFrameWork::paired_camera){
        if(!camera_->sample())return CutscenePlaybackStatus::completed;
        if(!display_)return services_.publish_camera(camera_->parameters());
        display_->publish(camera_->parameters());return CutscenePlaybackStatus::completed;
    }
    return services_.frame_work(work,state_,group);
}
CutscenePlaybackResult CutscenePlayback::advance_inner(){
    auto& world=world_;
    const auto action=[&](CutscenePlaybackStatus status){++work_calls_;require(status);};
    const auto query=[&](CutscenePlaybackValue value){++work_calls_;require(value.status);return value.value;};
    const auto stop_stream=[&](std::uint8_t channel){action(stream_status(channels_.stop(channel,streams_)));};
    const auto leave=[&]{state_.phase=increment(state_.phase);state_.subphase=state_.detail=0;state_.acknowledgement_mask=0;};
    switch(state_.subphase){
    case 0:
        action(stream_status(voice_.prepare(state_.request,state_.request.mode==1&&state_.request.audio_count!=1)));
        state_.subphase=increment(state_.subphase);return{};
    case 1:
        if(!(state_.request.mode==1&&state_.request.audio_count!=1)&&![&]{const auto ready=channels_.prepared_ready(1,streams_);return query({stream_status(ready.status),ready.value});}())return{CutscenePlaybackStatus::waiting};
        if(!state_.request.mode){
            state_.subphase=3;action(stream_status(channels_.release_start(1,streams_)));action(fade(false,1,0xff000000u));action(fullscreen_color(0xff000000u));
        }else{action(services_.start_movie(state_.request));state_.subphase=increment(state_.subphase);}
        state_.completion_word=state_.frame=0;state_.camera_selection=state_.camera_ended=0;return{};
    case 2:
        if(query(services_.movie_state())!=2)return{CutscenePlaybackStatus::waiting};
        state_.subphase=increment(state_.subphase);
        if(state_.request.audio_count==1)action(stream_status(channels_.release_start(1,streams_)));
        if(state_.request.audio_count>=2){
            if(!audio_tick_)throw Unavailable{CutscenePlaybackStatus::unavailable};
            action(stream_status(channels_.resume_current(1,*audio_tick_,streams_)));
        }
        action(fullscreen_color(0xff000000u));action(fade(false,1,0xff000000u));return{};
    case 3:{
        std::uint32_t ended=state_.request.mode?std::uint32_t(query(services_.movie_busy())==0):state_.completion_word;
        if(cutscene_acknowledgements_complete(world.mode,state_.acknowledgement_mask,world.session().single_roster_setup)){
            leave();action(services_.close_actor_notice());stop_stream(1);stop_stream(2);action(services_.stop_stream_tasks());
            if(state_.request.mode){action(services_.stop_movie());action(services_.retire_movie());action(stream_status(channels_.stop_preserving_state(1,streams_)));}
            //5F1B30's conditional message-phase callback is a proved empty return.
            return{};
        }
        if(ended){
            if(state_.request.mode){action(services_.stop_movie());action(stream_status(channels_.stop_preserving_state(1,streams_)));}
            leave();stop_stream(1);stop_stream(2);action(services_.stop_stream_tasks());action(services_.close_actor_notice());return{};
        }
        // Slots10..14 are literal5EE940 mechanical returns. The remaining
        // callback order is the owned70C550 table, followed by its consumers.
        constexpr std::array<CutsceneFrameWork,11> callbacks{
            CutsceneFrameWork::camera_selection,CutsceneFrameWork::actor_tracks,CutsceneFrameWork::object_tracks,
            CutsceneFrameWork::general_events,CutsceneFrameWork::indexed_resources,CutsceneFrameWork::light_tracks,
            CutsceneFrameWork::scene_controls,CutsceneFrameWork::word_controls,CutsceneFrameWork::actor_camera_parameters,
            CutsceneFrameWork::byte_controls,CutsceneFrameWork::skip_input};
        for(auto callback:callbacks)action(frame_work(callback));
        action(frame_work(CutsceneFrameWork::paired_camera));
        for(int i=0;i<state_.light_groups;++i)action(frame_work(CutsceneFrameWork::light_interpolation,std::bit_cast<std::int8_t>(std::uint8_t(i))));
        action(frame_work(CutsceneFrameWork::camera_curves));action(frame_work(CutsceneFrameWork::fullscreen_curve));action(frame_work(CutsceneFrameWork::indexed_resource_expiry));
        state_.frame+=world.session().clock_mode?2u:1u;
        if(std::bit_cast<std::int32_t>(state_.frame)>=std::bit_cast<std::int32_t>(state_.end_frame))state_.completion_word=1;
        return{};
    }
    default:return{};
    }
}
CutscenePlaybackResult CutscenePlayback::advance()noexcept{
    if(busy()||world_.busy())return{CutscenePlaybackStatus::busy};
    if(world_.closed())return{CutscenePlaybackStatus::closed};
    running_=true;work_calls_=0;struct Reset{bool& running;~Reset(){running=false;}}reset{running_};
    try{auto result=advance_inner();result.work_calls=work_calls_;return result;}
    catch(const Unavailable& failure){return{failure.status,false,work_calls_};}
    catch(const std::bad_alloc&){return{CutscenePlaybackStatus::no_memory,false,work_calls_};}
    catch(...){return{CutscenePlaybackStatus::unavailable,false,work_calls_};}
}
CutscenePlaybackResult CutscenePlayback::tick()noexcept{
    if(busy()||world_.busy())return{CutscenePlaybackStatus::busy};
    if(world_.closed())return{CutscenePlaybackStatus::closed};
    running_=true;work_calls_=0;struct Reset{bool& running;~Reset(){running=false;}}reset{running_};
    const auto action=[&](CutscenePlaybackStatus status){++work_calls_;require(status);};
    const auto query=[&](CutscenePlaybackValue value){++work_calls_;require(value.status);return value.value;};
    try{
        auto& world=world_;
        switch(state_.phase){
        case 0:state_.phase=increment(state_.phase);break;
        case 1:{auto result=advance_inner();result.work_calls=work_calls_;return result;}
        case 2:
            if(world.session().cutscene_requests.read_index()==world.session().cutscene_requests.write_index()){
                state_.phase=0;return{CutscenePlaybackStatus::completed,true,work_calls_};
            }
            action(fade(true,1,0xff000000u));action(services_.transition_audio_reset());
            state_.phase=increment(state_.phase);state_.subphase=state_.detail=state_.entry_detail=0;break;
        case 3:{
            if(!query(fade_finished()))return{CutscenePlaybackStatus::waiting,false,work_calls_};
            action(stream_status(channels_.stop(1,streams_)));action(stream_status(channels_.stop(2,streams_)));
            const auto request=collect_cutscene_cues(world_,flags_);if(!request)throw Unavailable{CutscenePlaybackStatus::unavailable};state_.request=*request;
            if(state_.request.mode)state_.voice_requested=1;
            action(services_.select_scene(state_));
            state_.selected_actor=0;
            if(state_.request.actor_selection){const auto selected=flags_.scenario_owner(state_.request.actor_selection);if(!selected)throw Unavailable{CutscenePlaybackStatus::unavailable};state_.selected_actor=*selected;}
            action(services_.clear_actor_descriptors());action(services_.retire_scene());action(services_.reset_scene());
            if(query(services_.load_scene(state_))){world.paused=0;state_.cinematic_enabled=0;}else world.paused=1;
            state_.phase=1;state_.subphase=state_.detail=state_.entry_detail=0;action(services_.publish_scene_notice());break;
        }
        default:break;
        }
        return{CutscenePlaybackStatus::completed,false,work_calls_};
    }catch(const Unavailable& failure){return{failure.status,false,work_calls_};}
    catch(const std::bad_alloc&){return{CutscenePlaybackStatus::no_memory,false,work_calls_};}
    catch(...){return{CutscenePlaybackStatus::unavailable,false,work_calls_};}
}
}
