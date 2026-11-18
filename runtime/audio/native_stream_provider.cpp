#include "native_stream_provider.h"
#include <atomic>

namespace reo::audio_output {
namespace {
std::atomic<bool> reserved{false};

void stream_callback(void* stereo, unsigned int frames) noexcept {
    // Slot initialization and owner publication precede callback registration.
    // No allocation, logging, provider calls or guest work on this route.
    native_stream_callback_slot().dispatch(static_cast<float*>(stereo), frames);
}
}

CallbackSlot& native_stream_callback_slot() {
    static CallbackSlot slot;
    return slot;
}

std::shared_ptr<NativeStreamProvider> NativeStreamProvider::create() {
    // Allocate before taking the permanent reservation so allocation failure
    // cannot consume the sole installation opportunity.
    auto result = std::shared_ptr<NativeStreamProvider>(new NativeStreamProvider);
    bool expected = false;
    if (!reserved.compare_exchange_strong(expected, true, std::memory_order_acq_rel))
        return {};
    (void)native_stream_callback_slot();
    return result;
}

std::string_view NativeStreamProvider::source_sha256() const noexcept {
    return provider_source_sha256;
}

bool NativeStreamProvider::attach(CallbackSlot& slot) noexcept {
    std::lock_guard lock(control_);
    if (&slot != &native_stream_callback_slot() || !slot.occupied()) return false;
    if (status_ == NativeStreamStatus::active) return true;
    if (status_ == NativeStreamStatus::detached || status_ == NativeStreamStatus::stopped ||
        status_ == NativeStreamStatus::unloaded) return false;
    if (!IsAudioDeviceReady()) {
        status_ = NativeStreamStatus::unavailable;
        return false; // no stream/callback; caller retains native headless mode
    }
    SetAudioStreamBufferSizeDefault(512);
    stream_ = LoadAudioStream(48000, 32, 2);
    if (!IsAudioStreamValid(stream_)) {
        // Fixed positive arguments + pinned Load/IsValid imply buffer == null.
        // No callback was published, and there is no returned buffer to unload.
        // Do not invent success/failure results for void cleanup APIs.
        stream_ = {};
        status_ = NativeStreamStatus::load_failed;
        return false;
    }
    SetAudioStreamCallback(stream_, stream_callback);
    PlayAudioStream(stream_);
    status_ = NativeStreamStatus::active;
    return true;
}

bool NativeStreamProvider::detach() noexcept {
    std::lock_guard lock(control_);
    if (status_ == NativeStreamStatus::detached || status_ == NativeStreamStatus::stopped ||
        status_ == NativeStreamStatus::unloaded) return true;
    if (status_ != NativeStreamStatus::active) return false;
    // Exact pinned implementation takes AUDIO.System.lock, also held over the
    // complete registered callback. Returning from this void call is the fence.
    SetAudioStreamCallback(stream_, nullptr);
    status_ = NativeStreamStatus::detached;
    return true;
}

bool NativeStreamProvider::stop() noexcept {
    std::lock_guard lock(control_);
    if (status_ == NativeStreamStatus::stopped || status_ == NativeStreamStatus::unloaded)
        return true;
    if (status_ != NativeStreamStatus::detached) return false;
    StopAudioStream(stream_);
    status_ = NativeStreamStatus::stopped;
    return true;
}

bool NativeStreamProvider::unload() noexcept {
    std::lock_guard lock(control_);
    if (status_ == NativeStreamStatus::unloaded) return true;
    if (status_ != NativeStreamStatus::stopped) return false;
    UnloadAudioStream(stream_);
    stream_ = {};
    status_ = NativeStreamStatus::unloaded;
    return true;
}

NativeStreamStatus NativeStreamProvider::status() const {
    std::lock_guard lock(control_);
    return status_;
}

} // namespace reo::audio_output
