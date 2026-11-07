#pragma once
#include "../movie_admission/admission.hpp"
#include "../movie_audio_clock/clock.hpp"
#include "../movie_clock_initialize/initialize.hpp"
#include "../movie_pause/controller.hpp"
#include "buffering.hpp"
#include "audio_commands.hpp"
#include <memory>
#include <optional>

namespace reo::native::movie_timing_context {
namespace selected=movie_selected_clock;
namespace pause=movie_pause;
namespace audio=movie_audio_clock;
namespace admission=movie_admission;
namespace initialize=movie_clock_initialize;
using Words=selected::Words;
struct Facts {
    std::uint32_t actual{4},requested{4},pause{},depth{},pending{},buffering{},episodes{},rate{4};
    std::uint32_t property_e{},selector{2},property_47{1},tolerance{10},admit_slack{},requested_slack{};
};
struct Updates {
    std::optional<std::uint32_t> actual,requested,pause,depth,pending,buffering,episodes,rate;
    std::optional<std::uint32_t> property_e,selector,property_47,tolerance,admit_slack,requested_slack;
};
struct View {
    Facts facts;initialize::State clock;audio::State audio;audio::Health audio_health;selected::GuardState guard;
    bool validated{},detached{};
    std::optional<AudioCommands> audio_commands;
};
struct Reply {
    pause::ProviderStatus provider{pause::ProviderStatus::completed};
    std::uint32_t status{};Updates updates;
};
class Ports {
public:
    virtual ~Ports()=default;
    // Prepared component/predicate/error boundary, not actual audio/video
    // dispatch. Only component callbacks may perform the qualified nested query.
    virtual Reply call(pause::Call,const View&)noexcept=0;
};
struct Config {
    Facts facts;std::uint32_t frequency{48000};
    std::shared_ptr<audio::AudioSource> audio;
    std::shared_ptr<audio::HelperClock> helper;
    std::shared_ptr<Ports> ports;
    std::shared_ptr<selected::GuardHooks> hooks;
    std::shared_ptr<selected::GuardState> guard;
    // When supplied, complete native buffering predicates replace predicate
    // ports. Commands/errors remain explicit component-owner boundaries.
    std::optional<Buffering> buffering;
    std::optional<AudioCommands> audio_commands;
    std::optional<std::uint32_t> audio_filter_mode;
};
enum class Operation {selected,cached,refresh,tick,pause,buffer,admit,requested_admit,picture_request,audio_requested,audio_temporary,audio_command};
enum class Status {completed,busy,detached,invalid_input,provider_failure,numeric_failure};
struct Input {Words prior,query;std::uint32_t value{};};
struct Result {
    Status status{Status::invalid_input};Words words{};
    bool words_written{},decision_written{},return_defined{};
    std::uint32_t decision{},returned{};
};
// Prepared timing context only. Property/state admission and actual movie
// start/stop, components and source/frame retirement remain with their owners.
class Context final:public std::enable_shared_from_this<Context> {
public:
    [[nodiscard]] static std::shared_ptr<Context> create(Config);
    Context(const Context&)=delete;Context& operator=(const Context&)=delete;
    [[nodiscard]] Status observe(const Updates&)noexcept;
    [[nodiscard]] Status observe_buffering(Buffering)noexcept;
    [[nodiscard]] Result execute(Operation,Input={})noexcept;
    [[nodiscard]] Status detach_queries()noexcept;
    [[nodiscard]] View snapshot()const noexcept;
private:
    class Bridge;
    explicit Context(Config);
    void finish(std::shared_ptr<Ports>);
    [[nodiscard]] Status validate(const Updates&)const noexcept;
    void properties(const Updates&)noexcept;
    [[nodiscard]] bool from_pause(const pause::State&)noexcept;
    [[nodiscard]] bool to_pause()noexcept;
    pause::Reply command(pause::Call,pause::View)noexcept;
    [[nodiscard]] Result query(Operation,Input)noexcept;
    [[nodiscard]] Result due(Words,bool)noexcept;
    [[nodiscard]] Result error(std::uint32_t,std::uint32_t)noexcept;
    [[nodiscard]] pause::Reply buffer_predicate(bool)noexcept;
    [[nodiscard]] bool buffer_end()const noexcept;
    [[nodiscard]] bool buffer_refill(bool,bool&)noexcept;
    [[nodiscard]] bool buffer_peek(std::uint32_t,std::uint32_t&)noexcept;
    [[nodiscard]] Result audio_control(Operation,std::uint32_t)noexcept;
    [[nodiscard]] Result audio_pause(std::uint32_t)noexcept;
    Facts facts_;std::uint32_t frequency_{};
    initialize::State initial_;
    admission::State admission_;
    std::shared_ptr<selected::GuardState> guard_;
    std::shared_ptr<selected::GuardHooks> hooks_;
    std::shared_ptr<audio::Clock> audio_;
    std::unique_ptr<selected::Clock> selected_;
    std::unique_ptr<pause::Controller> pause_;
    std::shared_ptr<Ports> ports_;
    std::optional<Buffering> buffering_;
    std::optional<AudioCommands> audio_commands_;
    std::shared_ptr<audio::ControlledSource> controlled_audio_;
    bool incidental_audio_return_{};
    bool busy_{},in_pause_{},in_component_{},nested_query_{},validated_{},detached_{};
};
}
