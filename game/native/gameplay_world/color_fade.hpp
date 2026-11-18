#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
enum class FadeDirection {increase,decrease};
enum class FadeStatus {completed,unavailable};
FadeStatus start_color_fade(World&,const actors::EntityId&,FadeDirection,std::uint32_t start_alpha,std::uint32_t updates)noexcept;
FadeStatus advance_color_fade(World&,const actors::EntityId&,FadeDirection)noexcept;
FadeStatus finish_color_fade(World&,const actors::EntityId&)noexcept; // complete6655F0
// Actual669F30 finish_actor consumer. All remaining frame work keeps its
// independently required owners; this adapter owns only the color-fade stage.
class ColorFadeFrameServices final:public Services {
public:
    explicit ColorFadeFrameServices(Services& frame)noexcept:frame_(frame){}
    void begin_offline_frame(World&)override;
    void run(Stage,World&,Actor&)override;
    bool remote_motion(World&,Actor&)override;
    bool find_grid(World&,Actor&,std::int8_t&)override;
    void switch_grid(World&,std::int32_t,std::int32_t)override;
    float grid_response(World&,std::uint8_t)override;
private:
    Services& frame_;
};
}
