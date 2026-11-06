#pragma once
#include "../adx_window/v2/playback_r2/stream_window.hpp"
#include "../adxt_output_session/session.hpp"
#include "../adxt_estimated_clock/estimated_clock.hpp"
#include "../adxt_service_group/service_group.hpp"
#include <array>
#include <memory>

namespace reo::native::adxt_control_session {class Session;}
namespace reo::native::adxt_serviced_clock {class Service;}
namespace reo::native::adxt_phased_player {
namespace window=adx_window::v2;
namespace output=adxt_output_session;
namespace clock=adxt_estimated_clock;
enum class Status { completed, waiting_header, pending, ended, busy, closed, unsupported_profile, fault };
struct Config {
    window::Config decoder;
    std::uint32_t initial_tick{},time_base{};
    Config(){decoder.pans={-128,-128};}
};
struct Snapshot {
    window::Snapshot decoder;adxt_playback::State playback;output::StreamSnapshot output;
    clock::Stream clock;clock::integer::Observation clock_observation;
    std::array<std::uint64_t,2> first_payload_digest{1469598103934665603ull,1469598103934665603ull};
    std::uint64_t copied_samples{},first_payload_samples{};
    bool transfer_primed{};
    std::array<std::uint64_t,5> service_visits{};
    bool configured{},stop_requested{},output_retired{},retired{},fault{},clock_observation_valid{};
};
// A decoder/source plus one exclusive producer in a shared output session.
// Callback rendering never references this object. All methods on this player
// and shared key contexts require one serialized control owner.
struct ClockResult { Status status{Status::completed}; clock::Result result; };
struct ClockControl { Status status{Status::completed}; clock::Status result{clock::Status::completed}; };
struct Ports {
    std::shared_ptr<adxt_service_group::ActiveWork> decoder,rna,transfer;
    std::shared_ptr<adxt_service_group::Stream> stream;
};
class Player final:public std::enable_shared_from_this<Player> {
public:
    Player(Config,std::unique_ptr<output::Producer>,std::shared_ptr<const resources::ByteView>,
           std::unique_ptr<adxt_shared_source::Backend>,std::shared_ptr<adx_header::KeyContext>,
           std::shared_ptr<clock::Shared>);
    ~Player();
    Player(const Player&)=delete;Player& operator=(const Player&)=delete;
    [[nodiscard]] Status service_source()noexcept;
    [[nodiscard]] Status service_decoder()noexcept;
    [[nodiscard]] Status service_control(adxt_service_group::Phase,std::uint32_t original_tick)noexcept;
    [[nodiscard]] Status service_rna()noexcept;
    [[nodiscard]] Status service_transfer()noexcept;
    [[nodiscard]] std::int8_t active()const noexcept;
    [[nodiscard]] std::int8_t phase()const noexcept;
    [[nodiscard]] Status set_tick(std::uint32_t)noexcept;
    [[nodiscard]] Ports make_ports();
    [[nodiscard]] Snapshot snapshot()const noexcept;
    [[nodiscard]] Status gain(float)noexcept;
    // Read-only identity for the session's explicit summation-order coordinator.
    [[nodiscard]] const output::Producer& output_identity()const noexcept;
    [[nodiscard]] ClockResult estimate(std::uint32_t original_tick)noexcept;
    [[nodiscard]] ClockResult centiseconds(std::uint32_t original_tick)noexcept;
    [[nodiscard]] ClockControl pause(std::int32_t argument,std::uint32_t original_tick)noexcept;
    [[nodiscard]] ClockControl discard_rebase(std::uint32_t original_tick)noexcept;
    [[nodiscard]] Status set_time_base(std::uint32_t)noexcept;
    void request_stop()noexcept;
    // Per-stream output fence, then actual source join. No shared provider join
    // or bank/peer reset occurs; the caller separately owns session shutdown.
    [[nodiscard]] Status retire_on_control_thread()noexcept;
private:
    friend class adxt_control_session::Session;
    [[nodiscard]] ClockControl discard_via(std::shared_ptr<adxt_serviced_clock::Service>,std::uint32_t)noexcept;
    class WorkPort;class StreamPort;
    class State;std::unique_ptr<State> state_;
};
} // namespace reo::native::adxt_phased_player
