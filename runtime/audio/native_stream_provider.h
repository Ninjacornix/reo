#pragma once
#include "game/native/audio_output/audio_output_owner.h"
#include "raylib.h"
#include <memory>
#include <mutex>

namespace reo::audio_output {

// Stable process-local target for raylib's callback API, which has no userdata.
// Initialize/reserve the provider before game publication. There is one native
// candidate per process; this change does not admit runtime/provider replacement.
CallbackSlot& native_stream_callback_slot();

enum class NativeStreamStatus {
    idle, unavailable, load_failed, active, detached, stopped, unloaded
};

class NativeStreamProvider final : public Provider {
public:
    // Reserves once per process, even after unload/destruction. Returns null if
    // already reserved. Headless/load failure retries use the same instance.
    static std::shared_ptr<NativeStreamProvider> create();
    std::string_view source_sha256() const noexcept override;
    bool attach(CallbackSlot& slot) noexcept override;
    bool detach() noexcept override;
    bool stop() noexcept override;
    bool unload() noexcept override;
    NativeStreamStatus status() const;
private:
    NativeStreamProvider() = default;
    // No destructor provider calls: the enclosing Owner must successfully join.
    mutable std::mutex control_;
    AudioStream stream_{};
    NativeStreamStatus status_ = NativeStreamStatus::idle;
};

} // namespace reo::audio_output
