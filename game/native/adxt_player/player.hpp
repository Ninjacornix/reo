#pragma once
#include "../adx_window/v2/playback_r2/stream_window.hpp"
#include "../audio_output/audio_output_owner.h"
#include "../pcm/pcm.hpp"
#include <array>
#include <memory>

namespace reo::native::adxt_player {
namespace window=adx_window::v2;
enum class Status { completed, waiting_header, pending, ended, busy, closed, unsupported_profile, fault };
struct Config {
    window::Config decoder;
    // Source-compatible neutral routing is explicit. Other pitch/pan policies
    // must be reconstructed before admission; no implicit DSP approximation.
    Config() { decoder.pans={-128,-128}; }
};
struct Snapshot {
    window::Snapshot decoder;
    adxt_playback::State playback;
    std::array<pcm::ChannelInfo,2> output;
    pcm::Statistics output_statistics;
    pcm::VoiceInfo output_voice;
    std::array<std::uint64_t,2> first_payload_digest{1469598103934665603ull,1469598103934665603ull};
    std::uint64_t copied_samples{}, first_payload_samples{};
    bool configured{}, stop_requested{}, provider_joined{}, retired{}, fault{};
};

// Independent single-resource composition. Only render calls run concurrently;
// every other method requires one serialized control owner. A supplied provider
// owns its actual stream/device contract. All callbacks hold only the retained
// output renderer; they never touch decoder/source/control state.
// This cut does not implement LSC, full pause/clock APIs or production selection.
class Player final {
public:
    Player(Config,std::shared_ptr<const resources::ByteView>,
           std::unique_ptr<adxt_shared_source::Backend>,
           std::shared_ptr<adx_header::KeyContext>,
           std::shared_ptr<audio_output::Provider>);
    ~Player();
    Player(const Player&)=delete; Player& operator=(const Player&)=delete;
    [[nodiscard]] Status service(std::uint32_t original_tick) noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
    // Signal only. Reclamation still requires retire_on_control_thread().
    void request_stop() noexcept;
    // Joins the actual output provider BEFORE cutting queues, then drains and
    // joins the actual encoded source. Failed joins retain ownership for retry.
    [[nodiscard]] Status retire_on_control_thread() noexcept;
private:
    class State; std::unique_ptr<State> state_;
};
} // namespace reo::native::adxt_player
