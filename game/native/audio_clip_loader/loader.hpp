#pragma once
#include "../adx_sequence/clip.hpp"
#include <cstdint>
#include <memory>

namespace reo::native::audio_clip_loader {
struct Identity;
class Loader;
class Key final {
public:
    Key() = default;
private:
    friend class Loader;
    std::weak_ptr<const Identity> owner_;
    std::uint32_t slot_{};
    std::uint64_t generation_{};
};
enum class Status { accepted, pending, ready, failed, completed, invalid_input,
    invalid_key, capacity, queue_full, closed, no_memory, fault };
struct Config { std::uint32_t records{16}, pending_tasks{16}; };
struct Request { Status status{Status::fault}; Key key; };
struct Result {
    Status status{Status::invalid_key};
    adx_sequence::Status detail{adx_sequence::Status::invalid_input};
    std::shared_ptr<const adx_sequence::Clip> clip;
};
struct Snapshot {
    std::uint32_t records{};
    std::uint64_t accepted{}, finished{}, preparations{}, published{}, discarded{}, worker_failures{};
    bool closing{}, joined{};
    // Once joined, accepted - finished counts canceled pending tasks. Before
    // join, that difference also includes queued and active work.
};
// One externally serialized controller, plus a private bounded preparation
// worker. Submit/poll/release/stop never wait for source reads. Join/destruction
// must run off the game/output callback and wait for any active read to return.
// Never destroy the loader from its own source read/destruction callback.
// Accepted jobs retain immutable source ownership. Keys are generation-scoped;
// releasing a pending key cannot publish an old result into its reused slot.
class Loader final {
public:
    explicit Loader(Config = {});
    ~Loader();
    Loader(const Loader&) = delete;
    Loader& operator=(const Loader&) = delete;
    [[nodiscard]] Request prepare(std::shared_ptr<const resources::ByteView>) noexcept;
    [[nodiscard]] Result poll(const Key&) const noexcept;
    [[nodiscard]] Status release(const Key&) noexcept;
    void request_stop() noexcept;
    [[nodiscard]] bool join() noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
private:
    struct State;
    std::unique_ptr<State> state_;
};
}
