#pragma once
#include <array>
#include <cstddef>
#include <cstdint>

namespace reo::native::gameplay_session {
struct RandomState {
    std::uint16_t primary{},secondary{};
    std::uint8_t observed{};
    friend bool operator==(const RandomState&,const RandomState&)=default;
};
class Random final {
public:
    explicit Random(RandomState state={}) noexcept:state_(state){}
    void seed(std::uint8_t value)noexcept;
    std::uint16_t request(std::uint32_t selector)noexcept;
    RandomState state()const noexcept{return state_;}
    void restore(RandomState state)noexcept{state_=state;}
private:
    RandomState state_;
};

struct Options {
    std::uint8_t audio_mode{},music_volume{},effects_volume{},controller_profile{},vibration{},brightness{};
    std::int8_t screen_x{},screen_y{};
    friend bool operator==(const Options&,const Options&)=default;
};
using SavedOptions=std::array<std::byte,16>;
class OptionServices {
public:
    virtual ~OptionServices()=default;
    virtual void defaults_changed(SavedOptions&)=0;
    virtual void screen_offset(Options&,std::int8_t x,std::int8_t y)=0;
    virtual void audio_mode(Options&,std::uint8_t)=0;
    virtual void effects_volume(Options&,std::uint8_t)=0;
    virtual void music_volume(Options&,std::uint8_t)=0;
};
// Preserve unknown saved bytes8..15 when capturing live values.
void capture_options(const Options&,SavedOptions&)noexcept;
void sanitize_options(Options&)noexcept;
void initialize_saved_options(SavedOptions&,OptionServices&);
// Copy all fields before callbacks, then reread each value at its service call.
void restore_options(const SavedOptions&,Options&,OptionServices&);
} // namespace reo::native::gameplay_session
