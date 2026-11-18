#pragma once
#include "../adx_window/v2/playback_r2/stream_window.hpp"
#include "../adxt_output_session/session.hpp"
#include <array>
#include <memory>

namespace reo::native::adxt_shared_player {
namespace window=adx_window::v2;
namespace output=adxt_output_session;
enum class Status { completed, waiting_header, pending, ended, busy, closed, unsupported_profile, fault };
struct Config {
    window::Config decoder;
    Config(){decoder.pans={-128,-128};}
};
struct Snapshot {
    window::Snapshot decoder;adxt_playback::State playback;output::StreamSnapshot output;
    std::array<std::uint64_t,2> first_payload_digest{1469598103934665603ull,1469598103934665603ull};
    std::uint64_t copied_samples{},first_payload_samples{};
    bool configured{},stop_requested{},output_retired{},retired{},fault{};
};
// A decoder/source plus one exclusive producer in a shared output session.
// Callback rendering never references this object. All methods on this player
// and shared key contexts require one serialized control owner.
class Player final {
public:
    Player(Config,std::unique_ptr<output::Producer>,std::shared_ptr<const resources::ByteView>,
           std::unique_ptr<adxt_shared_source::Backend>,std::shared_ptr<adx_header::KeyContext>);
    ~Player();
    Player(const Player&)=delete;Player& operator=(const Player&)=delete;
    [[nodiscard]] Status service(std::uint32_t original_tick) noexcept;
    [[nodiscard]] Snapshot snapshot()const noexcept;
    [[nodiscard]] Status gain(float)noexcept;
    // Read-only identity for the session's explicit summation-order coordinator.
    [[nodiscard]] const output::Producer& output_identity()const noexcept;
    void request_stop()noexcept;
    // Per-stream output fence, then actual source join. No shared provider join
    // or bank/peer reset occurs; the caller separately owns session shutdown.
    [[nodiscard]] Status retire_on_control_thread()noexcept;
private:
    class State;std::unique_ptr<State> state_;
};
} // namespace reo::native::adxt_shared_player
