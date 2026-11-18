#pragma once

#include "byte_view.hpp"

#include <limits>

namespace reo::native::resources {

struct SessionIdentity;
class ResourceSession;

// Not a wire token. Weak owner identity prevents another session (including a
// later object at a reused address) from accepting an old session's handle.
class Handle final {
public:
    Handle() = default;
private:
    friend class ResourceSession;
    std::weak_ptr<const SessionIdentity> owner_;
    std::uint32_t slot_{std::numeric_limits<std::uint32_t>::max()};
    std::uint64_t generation_{};
};

struct OpenResult {
    Status status{Status::invalid_view};
    Handle handle;
};

struct SizeResult {
    Status status{Status::invalid_handle};
    std::uint64_t bytes{};
};

struct SessionConfig {
    std::size_t max_read_bytes{8 * 1024 * 1024};
    std::uint32_t max_handles{1024};
    // Slots retire on their final generation. A smaller configured domain can be
    // useful for bounded owners/tests; generation zero is never emitted.
    std::uint64_t max_generation{std::numeric_limits<std::uint64_t>::max()};
};

class ResourceSession final {
public:
    // Invalid zero limits throw invalid_argument; creating session state may
    // throw bad_alloc. Operational allocation failures use typed statuses.
    explicit ResourceSession(SessionConfig config = {});
    ~ResourceSession();
    ResourceSession(const ResourceSession&) = delete;
    ResourceSession& operator=(const ResourceSession&) = delete;
    ResourceSession(ResourceSession&&) = delete;
    ResourceSession& operator=(ResourceSession&&) = delete;

    [[nodiscard]] OpenResult open(std::shared_ptr<const ByteView> view) noexcept;
    [[nodiscard]] SizeResult size(const Handle& handle) const noexcept;
    // Success copies exactly destination.size() bytes. Every failure returns
    // zero bytes and leaves caller output unchanged, even after provider writes.
    [[nodiscard]] ReadResult read_exact(const Handle& handle, std::uint64_t offset,
                                        std::span<std::byte> destination) noexcept;
    [[nodiscard]] Status close(const Handle& handle) noexcept;

    // No automatic threads. shutdown refuses new work and invalidates all
    // handles. Existing reads retain their provider until completion.
    void shutdown() noexcept;
    // Stable drain requires prior shutdown or externally stopped submissions.
    // Never call drain from an active provider read (it would wait on itself).
    void drain() noexcept;
    void shutdown_and_drain() noexcept;
private:
    struct State;
    std::shared_ptr<State> state_;
};

} // namespace reo::native::resources
