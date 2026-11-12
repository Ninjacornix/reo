#pragma once
#include "cutscene_cues.hpp"
#include "cutscene_descriptor.hpp"
#include "stream_channels.hpp"
#include <memory>
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_scenario {
class CutsceneSpeech;
// One native controller for source38ECA0. The original7434C8 pointer aliases
// this record; +8 and global38ECA8 are the SAME simulation frame. Request.mode
// is both controller byte2F and38ECCF, including the movie/scene branch gate.
struct CutscenePlaybackState {
    std::int8_t phase{},subphase{},detail{},entry_detail{};
    std::uint32_t completion_word{},frame{},end_frame{};
    std::uint8_t camera_selection{},camera_ended{}; //24/25
    CutsceneBatch request;
    std::array<std::uint8_t,3> loaded_identity{},previous_identity{};
    std::uint32_t selected_actor{}; //38ECDC, resolved request actor_selection
    std::int16_t light_groups{}; //38ECBC
    std::uint8_t acknowledgement_mask{},cinematic_enabled{},voice_requested{}; //4BAE0E/4BAE9A/4BAE09
};
enum class CutscenePlaybackStatus {completed,waiting,busy,closed,unavailable,no_memory};
struct CutscenePlaybackValue {CutscenePlaybackStatus status{CutscenePlaybackStatus::unavailable};std::int32_t value{};};
struct CutscenePlaybackResult {CutscenePlaybackStatus status{CutscenePlaybackStatus::completed};bool finished{};std::size_t work_calls{};};
// The literal16-entry callback order. Empty slots10..14 are proved mechanical
// returns and have no provider. Remaining unbound consumers refuse explicitly.
enum class CutsceneFrameWork {
    camera_selection,actor_tracks,object_tracks,general_events,indexed_resources,
    light_tracks,scene_controls,word_controls,actor_camera_parameters,byte_controls,
    skip_input,paired_camera,light_interpolation,camera_curves,fullscreen_curve,
    indexed_resource_expiry
};
// Concrete scene/audio/movie owners implement these operations. Their results
// retain source order and may mutate the borrowed canonical state. There are
// no default successful callbacks, invented readiness or completion timeouts.
class CutscenePlaybackServices {
public:
    virtual ~CutscenePlaybackServices()=default;
    virtual CutscenePlaybackStatus prepare_voice(const CutsceneBatch&,bool playlist)=0;
    virtual CutscenePlaybackStatus start_movie(const CutsceneBatch&)=0;
    virtual CutscenePlaybackValue movie_state()=0;
    virtual CutscenePlaybackValue movie_busy()=0;
    virtual CutscenePlaybackStatus stop_movie()=0;
    virtual CutscenePlaybackStatus retire_movie()=0;
    virtual CutscenePlaybackStatus stop_stream_tasks()=0;
    virtual CutscenePlaybackStatus fade(bool rising,std::int16_t duration,std::uint32_t color)=0;
    virtual CutscenePlaybackValue fade_finished()=0;
    virtual CutscenePlaybackStatus fullscreen_color(std::uint32_t)=0;
    virtual CutscenePlaybackStatus transition_audio_reset()=0;
    //5F0380 follows cue collection with the actual371AD0/371B70 and room
    //6DE590/6DE480 route. Collection alone does not qualify those effects.
    virtual CutscenePlaybackStatus select_scene(CutscenePlaybackState&)=0;
    virtual CutscenePlaybackStatus close_actor_notice()=0;
    virtual CutscenePlaybackStatus clear_actor_descriptors()=0;
    virtual CutscenePlaybackStatus retire_scene()=0;
    virtual CutscenePlaybackStatus reset_scene()=0;
    // Preserves5ECF90's return word; nonzero does not imply a loaded scene.
    virtual CutscenePlaybackValue load_scene(CutscenePlaybackState&)=0;
    virtual CutscenePlaybackStatus publish_scene_notice()=0;
    virtual CutsceneSpeech* speech()noexcept=0;
    virtual CutscenePlaybackStatus frame_work(CutsceneFrameWork,CutscenePlaybackState&,std::int8_t light_group=-1)=0;
};
class CutscenePlayback final {
public:
    CutscenePlayback(gameplay_update::Owner&,StreamChannels&,StreamBackend&,CutscenePlaybackServices&);
    CutscenePlayback(gameplay_world::World&,FlagState&,const std::optional<std::uint32_t>& audio_tick,StreamChannels&,StreamBackend&,CutscenePlaybackServices&);
    ~CutscenePlayback();
    CutscenePlayback(const CutscenePlayback&)=delete;
    CutscenePlayback& operator=(const CutscenePlayback&)=delete;
    CutscenePlaybackState& state()noexcept{return state_;}
    const CutscenePlaybackState& state()const noexcept{return state_;}
    // The actual5EE680 outer visit and5EE260 substate. Neither starts a game,
    // device nor thread; required media/scene capability failures are returned.
    CutscenePlaybackResult tick()noexcept;
    CutscenePlaybackResult advance()noexcept;
    bool busy()const noexcept{return running_;}
private:
    gameplay_world::World& world_;FlagState& flags_;const std::optional<std::uint32_t>& audio_tick_;
    StreamChannels& channels_;StreamBackend& streams_;
    CutscenePlaybackServices& services_;CutscenePlaybackState state_;
    bool running_{};
    std::size_t work_calls_{};
    CutscenePlaybackResult advance_inner();
    CutscenePlaybackStatus frame_work(CutsceneFrameWork,std::int8_t group=-1);
};
bool cutscene_acknowledgements_complete(std::uint8_t mode,std::uint8_t mask,std::uint8_t participants)noexcept;
}
