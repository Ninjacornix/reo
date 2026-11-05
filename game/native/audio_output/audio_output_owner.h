#pragma once
#include <atomic>
#include <cstdint>
#include <memory>
#include <mutex>
#include <string_view>

namespace reo::audio_output {

inline constexpr std::string_view provider_source_sha256 =
    "2d6a2d5b9f86b44b879605f654659c542a317d97477ddfde54683019e8bfeacc";
inline constexpr std::uint32_t maximum_callback_frames = 512;

class Owner;

// Stable storage for the one no-userdata provider trampoline. Its owner must
// keep this slot alive until successful Owner::join(), and beyond every caller
// of dispatch(). This is not a global registry or an actual raylib binding.
class CallbackSlot final {
public:
    bool dispatch(float* stereo, std::uint32_t frames) noexcept;
    bool occupied() const;
private:
    friend class Owner;
    bool publish(const std::shared_ptr<Owner>& owner);
    std::shared_ptr<Owner> remove(const Owner* owner);
    mutable std::mutex mutex_;
    std::shared_ptr<Owner> owner_;
};

// This interface describes the pinned raylib stream contract, not device
// ownership. A production adapter must prove this identity and these rules:
// * attach publishes callback only after slot publication; false means no
//   publication and no active callback from that attempt remains.
// * detach(true) has replaced the registered callback with null and fenced all
//   its invocations, using the same audio-system lock as callback execution.
// * stop/unload are serialized after detach; false permits retry of that step.
//   A false result must not irreversibly consume its resource.
// * all methods run outside callbacks, with a valid live device/stream whose
//   lifecycle cannot race another owner or device close.
// Source hash equality is an admission check, not independent proof of an adapter.
class Provider {
public:
    virtual ~Provider() = default;
    virtual std::string_view source_sha256() const noexcept = 0;
    virtual bool attach(CallbackSlot& slot) noexcept = 0;
    virtual bool detach() noexcept = 0;
    virtual bool stop() noexcept = 0;
    virtual bool unload() noexcept = 0;
};

class Renderer {
public:
    virtual ~Renderer() = default;
    // float32 stereo, <=512 frames. Bounded/no allocation, no guest execution,
    // no provider calls. This class does not enforce renderer internals.
    virtual void render(float* stereo, std::uint32_t frames) noexcept = 0;
};

enum class StartResult { started, already_started, stop_requested,
                         callback_thread, slot_busy, attach_failed };
enum class JoinResult { joined, callback_thread, detach_failed,
                        stop_failed, unload_failed };

class Owner final : public std::enable_shared_from_this<Owner> {
public:
    static std::shared_ptr<Owner> create(CallbackSlot& slot,
                                         std::shared_ptr<Provider> provider,
                                         std::shared_ptr<Renderer> renderer);
    StartResult start();
    // Atomic-only: never fences provider, drops a lease, waits, or resets PCM.
    void request_stop() noexcept;
    // Caller must hold no registry/PCM/bank/guest locks. A failed result retains
    // the slot and provider/storage lifetime; retry outside callbacks.
    JoinResult join();
    bool stop_requested() const noexcept;
private:
    friend class CallbackSlot;
    Owner(CallbackSlot&, std::shared_ptr<Provider>, std::shared_ptr<Renderer>);
    bool render(float*, std::uint32_t) noexcept;
    static constexpr std::uint64_t closed_bit = std::uint64_t{1} << 63;
    CallbackSlot& slot_;
    std::shared_ptr<Provider> provider_;
    std::shared_ptr<Renderer> renderer_;
    std::atomic<std::uint64_t> admission_{0}; // closed bit + admitted callback count
    std::mutex lifecycle_; // callback never acquires this mutex
    bool attached_ = false, detached_ = false, stopped_ = false, unloaded_ = false;
    bool joined_ = false;
};

} // namespace reo::audio_output
