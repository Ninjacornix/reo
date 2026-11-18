#pragma once
#include "camera_projection.hpp"
#include "display_fade.hpp"
namespace reo::native::gameplay_scenario {
struct CutscenePlaybackState;
// A controller adapter borrows the actual display domain's state and sink.
// Ownership of these records is never duplicated inside the scene controller.
class CutsceneDisplay final {
public:
    CutsceneDisplay(CutscenePlaybackState& state,const std::uint8_t& clock_mode,
        const std::int8_t& display_mode,CameraProjectionContext& projection,
        CameraDisplayState& camera,DisplayFadeState& fade,std::uint8_t& callback_initialized,
        CameraDisplaySink& sink)noexcept:
        state_(state),clock_mode_(clock_mode),display_mode_(display_mode),projection_(projection),
        camera_(camera),fade_(fade),callback_initialized_(callback_initialized),sink_(sink){}
    CutsceneDisplay(const CutsceneDisplay&)=delete;
    CutsceneDisplay& operator=(const CutsceneDisplay&)=delete;
    bool bound_to(const CutscenePlaybackState& state,const std::uint8_t& clock)const noexcept{
        return &state_==&state&&&clock_mode_==&clock;
    }
    void publish(CameraParameters& parameters){publish_camera_display(parameters,display_mode_,projection_,camera_,sink_);}
    void fade(bool rising,std::int16_t duration,std::uint32_t color)noexcept{start_display_fade(fade_,rising,duration,clock_mode_,color);}
    bool fade_finished()const noexcept{return display_fade_finished(fade_);}
    // Called by the real scheduled1BB480 worker. Controller/presentation visits
    // do not advance it automatically or fabricate completion while unbound.
    void advance_fade()noexcept{advance_display_fade(fade_,callback_initialized_);}
private:
    CutscenePlaybackState& state_;const std::uint8_t& clock_mode_;const std::int8_t& display_mode_;
    CameraProjectionContext& projection_;CameraDisplayState& camera_;DisplayFadeState& fade_;
    std::uint8_t& callback_initialized_;CameraDisplaySink& sink_;
};
} // namespace reo::native::gameplay_scenario
