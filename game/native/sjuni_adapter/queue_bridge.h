#pragma once

#include "guest_image.h"
#include "../sjuni/sjuni.hpp"
#include <span>

namespace reo::sjuni::bridge {

// Registered borrowed-storage regions. The adapter translates numeric tokens;
// the native core sees only resource identity and offsets, never guest memory.
struct Region {
    std::uint64_t id{};
    std::uint32_t base{};
    std::uint64_t size{};
};

enum class Operation { get, put, unget, queued_bytes, availability, queued_nodes, free_nodes };
struct Call {
    Operation operation{};
    std::uint32_t queue{};
    std::int32_t request{};
    std::uint32_t descriptor{}; // Span input/output or availability int32 output.
};

enum class Event { enter, leave, error };
struct Callbacks {
    void* context{};
    // Synchronous; may inspect/mutate the wire image. Error is delivered only
    // when its guest callback token is nonzero. No live guest dispatch here.
    void (*invoke)(void*, Event, std::int32_t code, Memory){};
};

enum class Disposition {
    completed,
    fallback_before_effects,
    callback_contract_violation // Never restart the original operation.
};
struct Outcome {
    Disposition disposition{Disposition::fallback_before_effects};
    std::uint32_t value{}; // Only query results have a defined value.
};

// Portable temporary adapter. Existing guest layouts remain the interchange
// state between operations; a native Pool owns the working state during each
// call and mirrors it before callbacks and before returning. This supports
// isolated comparison; runtime entry-point installation is a separate step.
//
// Unsupported preflight leaves memory/callbacks untouched. Once a callback has
// run, a contract violation is explicit and MUST NOT trigger whole-call fallback.
// Regions must coherently cover numeric adjacency for admitted spans; wrapped
// pointers/lengths, overlapping descriptors/storage and unregistered spans are
// excluded before any effect. Callback mutation must preserve those admissions.
Outcome execute(Memory memory, const Profile& profile, std::uint32_t object,
                std::span<const Region> regions, const Call& call,
                Callbacks callbacks = {});

} // namespace reo::sjuni::bridge
