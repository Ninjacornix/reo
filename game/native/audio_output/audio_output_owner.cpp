#include "audio_output_owner.h"
#include <algorithm>
#include <utility>

namespace reo::audio_output {
static_assert(std::atomic<std::uint64_t>::is_always_lock_free,
              "Audio admission requires a lock-free 64-bit atomic");
namespace {
thread_local unsigned callback_depth = 0;
struct CallbackScope {
    CallbackScope() { ++callback_depth; }
    ~CallbackScope() { --callback_depth; }
};
}

bool CallbackSlot::publish(const std::shared_ptr<Owner>& owner) {
    std::lock_guard lock(mutex_);
    if (owner_) return false;
    owner_ = owner;
    return true;
}

std::shared_ptr<Owner> CallbackSlot::remove(const Owner* owner) {
    std::lock_guard lock(mutex_);
    if (owner_.get() != owner) return {};
    return std::exchange(owner_, {}); // caller destroys lease outside slot lock
}

bool CallbackSlot::occupied() const {
    std::lock_guard lock(mutex_);
    return static_cast<bool>(owner_);
}

bool CallbackSlot::dispatch(float* stereo, std::uint32_t frames) noexcept {
    CallbackScope callback_scope;
    // The strong snapshot is retained through render and released outside lock.
    std::shared_ptr<Owner> owner;
    {
        std::lock_guard lock(mutex_);
        owner = owner_;
    }
    if (!stereo || frames > maximum_callback_frames) return false;
    if (owner && owner->render(stereo, frames)) return true;
    std::fill_n(stereo, static_cast<std::size_t>(frames) * 2, 0.0f);
    return false;
}

Owner::Owner(CallbackSlot& slot, std::shared_ptr<Provider> provider,
             std::shared_ptr<Renderer> renderer)
    : slot_(slot), provider_(std::move(provider)), renderer_(std::move(renderer)) {}

std::shared_ptr<Owner> Owner::create(CallbackSlot& slot,
                                     std::shared_ptr<Provider> provider,
                                     std::shared_ptr<Renderer> renderer) {
    if (!provider || !renderer || provider->source_sha256() != provider_source_sha256)
        return {};
    return std::shared_ptr<Owner>(new Owner(slot, std::move(provider), std::move(renderer)));
}

StartResult Owner::start() {
    if (callback_depth) return StartResult::callback_thread;
    auto keep_alive = shared_from_this();
    std::shared_ptr<Owner> removed;
    // Lifecycle lock is independent of the provider's audio-system lock.
    std::unique_lock control(lifecycle_);
    if (stop_requested()) return StartResult::stop_requested;
    if (attached_) return StartResult::already_started;
    if (!slot_.publish(keep_alive)) return StartResult::slot_busy;
    if (!provider_->attach(slot_)) {
        // Provider's failed-attach contract has already fenced this attempt.
        removed = slot_.remove(this);
        control.unlock();
        return StartResult::attach_failed;
    }
    attached_ = true;
    return StartResult::started;
}

void Owner::request_stop() noexcept {
    admission_.fetch_or(closed_bit, std::memory_order_acq_rel);
}

bool Owner::stop_requested() const noexcept {
    return (admission_.load(std::memory_order_acquire) & closed_bit) != 0;
}

bool Owner::render(float* stereo, std::uint32_t frames) noexcept {
    auto current = admission_.load(std::memory_order_acquire);
    for (;;) {
        if ((current & closed_bit) || current == closed_bit - 1) return false;
        if (admission_.compare_exchange_strong(current, current + 1,
                                             std::memory_order_acq_rel,
                                             std::memory_order_acquire)) break;
    }
    renderer_->render(stereo, frames);
    admission_.fetch_sub(1, std::memory_order_acq_rel);
    admission_.notify_all();
    return true;
}

JoinResult Owner::join() {
    request_stop();
    // Even joining another stream owner from this trampoline could invert the
    // process-wide raylib audio-system mutex, so refuse any callback depth.
    if (callback_depth) return JoinResult::callback_thread;
    auto keep_alive = shared_from_this();
    std::shared_ptr<Owner> removed;
    std::unique_lock control(lifecycle_);
    if (joined_) return JoinResult::joined;
    if (attached_) {
        if (!detached_) {
            if (!provider_->detach()) return JoinResult::detach_failed;
            detached_ = true;
        }
        // The registered callback fence should have drained these already.
        // Retain explicit admission proof before stop/unload or slot release.
        auto current = admission_.load(std::memory_order_acquire);
        while ((current & ~closed_bit) != 0) {
            admission_.wait(current, std::memory_order_acquire);
            current = admission_.load(std::memory_order_acquire);
        }
        if (!stopped_) {
            if (!provider_->stop()) return JoinResult::stop_failed;
            stopped_ = true;
        }
        if (!unloaded_) {
            if (!provider_->unload()) return JoinResult::unload_failed;
            unloaded_ = true;
        }
    }
    removed = slot_.remove(this);
    joined_ = true;
    control.unlock(); // no last lease destruction under lifecycle/slot lock
    return JoinResult::joined;
}

} // namespace reo::audio_output
