#pragma once
#include "gs_backend_route.h"
#include "resident_backend_factory.hpp"
#include <optional>
namespace reo_parallel_backend {
struct Config {
    reo_resident_live::OwnerConfig residentGeometry{};
    // Must stay false until root validates the clean pinned renderer change.
    bool validatedDrawing = false;
    std::function<bool(uint64_t)> diagnosticOutputRequested;
    std::function<void(uint64_t, const std::vector<uint8_t>&, uint32_t, uint32_t)> diagnosticOutput;
    std::function<void(unsigned, uint64_t)> residentStoppedDiagnostic;
    bool residentPresentation = false; // Generic default remains host reference.
    std::vector<uint32_t> presentationVertex, presentationFragment;
    std::function<reo_gpu_present::Target()> presentationTarget;
    std::function<bool(uint64_t)> presentationEpochCurrent;
    bool descriptorBuffer = false;
    // Host scanout policy only; preserves guest INT/FFMD and display registers.
    // Full-height FFMD0 output and anti-blur are selected per title by the host.
    bool forceProgressive = false;
    bool antiBlur = false;
    // Opt-in driver pipelines only, independent of guest state. Blank file
    // uses a stable per-device LOCALAPPDATA cache; explicit override is UTF-8.
    bool persistentPipelineCache = false;
    std::string pipelineCacheFile;
    // Ordered reset snapshot; consumer publishes backend-owned status only.
    // CPU display reset belongs at enqueue order so newer writes survive.
    // Invocation uses coherent state policy, never a guest handler call.
    std::function<void(const gs_backend_bridge::Privileged&)> publishPrivilegedReset;
    // Exact event W1C bits at worker retirement. Never publish an old full CSR
    // over current FIELD; atomically clear only this mask in guest status.
    std::function<void(uint64_t mask)> publishStatusAck;
    // Native single event-bank policy. If installed, queued ACK retirement
    // refreshes this bank rather than clearing it again. nullopt suppresses a
    // stale pre-RESET job; the root's callback owns its epoch/front-state lock.
    std::function<std::optional<gs_backend_bridge::Privileged>()> peekEventFrontState;
};
// Constructs a factory only; deliberately does not register/enable it.
gs_backend_bridge::Factory makeFactory(Config config = {});
struct ResidentDiagnostics {
    uint64_t presented = 0, normalDownloads = 0, outputReadbacks = 0, ownerSerial = 0,
             fenceWaits = 0;
    unsigned liveImages = 0;
};
ResidentDiagnostics residentDiagnostics(gs_backend_bridge::Backend&);
// Private concrete-backend inspection/publication helper. Invoke only under
// the same serialized owner policy as Backend, never reenter Route callbacks.
gs_backend_bridge::Privileged snapshotPrivileged(gs_backend_bridge::Backend&);
} // namespace reo_parallel_backend
