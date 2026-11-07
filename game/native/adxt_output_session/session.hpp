#pragma once
#include "../adxt_playback/playback.hpp"
#include "../audio_output/audio_output_owner.h"
#include "../pcm/pcm.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>

namespace reo::native::audio_mix_tail { class Mixer; }
namespace reo::native::adxt_output_session {
inline constexpr std::uint32_t maximum_streams=16, samples_per_channel=8192;
enum class Status { completed, closed, invalid_input, capacity, allocation_failure,
    stale_producer, copy_refused, order_required, pending, provider_refused, fault };
struct Config {
    std::uint32_t streams{16};std::uint64_t maximum_counter{UINT64_MAX};
    std::shared_ptr<audio_mix_tail::Mixer> bank_mix{};
};
struct StreamSnapshot {
    std::uint32_t slot{}, channels{}, frequency{48000}; std::uint64_t generation{};
    std::array<pcm::ChannelInfo,2> channel;
    pcm::VoiceInfo voice;
    bool active{}, transfer_open{}, through{}, retired{}, orphaned{}, fault{};
};
struct Snapshot {
    std::array<StreamSnapshot,maximum_streams> streams;
    pcm::Statistics statistics;
    std::uint32_t occupied{}, playing{};
    bool closing{}, provider_joined{}, closed{}, order_required{}, render_fault{},bank_mix_fault{};
    pcm::Status last_render_status{pcm::Status::ok};
};
struct State;
class Session;
class Producer final:public adxt_playback::Output {
public:
    ~Producer() override;
    Producer(const Producer&)=delete; Producer& operator=(const Producer&)=delete;
    [[nodiscard]] Status configure(std::uint32_t frequency) noexcept;
    [[nodiscard]] Status gain(float) noexcept;
    // Copies the complete planar batch atomically with respect to rendering.
    // Caller still owns and must explicitly finish its decoder read lease.
    [[nodiscard]] Status copy(std::span<const std::byte> left,
                              std::span<const std::byte> right={}) noexcept;
    [[nodiscard]] StreamSnapshot snapshot() const noexcept;
    // A synchronous per-voice render/copy fence. Other streams and the shared
    // provider remain active. No device join or source join is implied.
    [[nodiscard]] Status retire() noexcept;
    adxt_playback::Status queued_samples(std::uint32_t&) noexcept override;
    adxt_playback::Status free_samples(std::uint32_t&) noexcept override;
    adxt_playback::Status play(bool) noexcept override;
    adxt_playback::Status stop_transfer() noexcept override;
    adxt_playback::Status through() noexcept override;
private:
    friend class Session;
    struct Identity;
    Producer(std::shared_ptr<State>,std::shared_ptr<Identity>);
    std::shared_ptr<State> state_;std::shared_ptr<Identity> identity_;
    std::uint32_t slot_{};std::uint64_t generation_{};
    std::optional<StreamSnapshot> final_;
};
struct OpenResult { Status status{Status::fault}; std::unique_ptr<Producer> producer; };

// One session renderer/provider, many exclusive producers. All PCM handles are
// private. The supplied slot must be the provider's ACTUAL stable slot and remain
// alive through its fence; this is how the current process-wide provider binds.
// Rendering runs concurrently. Session lifecycle/order calls require one control
// owner. Each Producer separately requires one serialized control owner.
class Session final {
public:
    Session(Config,std::shared_ptr<audio_output::CallbackSlot>,
            std::shared_ptr<audio_output::Provider>);
    ~Session();
    Session(const Session&)=delete; Session& operator=(const Session&)=delete;
    [[nodiscard]] OpenResult open(std::uint32_t channels) noexcept;
    // Exact permutation of active producers in the required summation order.
    // More than two playing streams requires an order covering the new stream.
    [[nodiscard]] Status set_order(std::span<const Producer* const>) noexcept;
    [[nodiscard]] Status start() noexcept;
    void request_stop() noexcept;
    [[nodiscard]] Status join() noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
private:
    std::shared_ptr<State> state_;std::shared_ptr<audio_output::Owner> owner_;
};
} // namespace reo::native::adxt_output_session
