#pragma once

#include "../resources/byte_view.hpp"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <vector>

namespace reo::native::resource_io {

struct ReadOwnerIdentity;
struct ReadOwnerState;

class Ticket final {
public:
    Ticket() = default;
private:
    friend struct ReadOwnerState;
    std::weak_ptr<const ReadOwnerIdentity> owner_;
    std::uint64_t id_{};
};

struct Config {
    // One slot remains charged through preparing, queued, active AND ready.
    std::uint32_t max_requests{16};
    std::size_t max_read_bytes{8 * 1024 * 1024};
    // Each outstanding request reserves twice its byte count: owned output plus
    // ResourceSession's exact-read staging. Metadata is bounded by max_requests.
    std::size_t byte_budget{32 * 1024 * 1024};
    std::uint64_t max_ticket_id{std::numeric_limits<std::uint64_t>::max()};
};

enum class SubmitStatus {
    accepted, owner_closed, invalid_view, invalid_range, read_limit,
    request_capacity, byte_budget, ticket_exhausted, no_memory,
    worker_unavailable, session_error
};
struct SubmitResult {
    SubmitStatus status{SubmitStatus::invalid_view};
    Ticket ticket;
    resources::Status resource_status{resources::Status::ok};
};

struct ReadOutcome {
    resources::Status status{resources::Status::source_failure};
    // Exactly the requested bytes on success; empty on every failure.
    std::vector<std::byte> bytes;
};
enum class PollStatus { pending, ready, invalid_ticket, owner_closed };
struct PollResult {
    PollStatus status{PollStatus::invalid_ticket};
    ReadOutcome outcome;
};
enum class CancelStatus { cancelled, invalid_ticket, owner_closed };

class AsyncReadOwner final {
public:
    // Positive limits are required. Constructor allocation/thread failures throw.
    explicit AsyncReadOwner(Config config = {});
    ~AsyncReadOwner() noexcept;
    AsyncReadOwner(const AsyncReadOwner&) = delete;
    AsyncReadOwner& operator=(const AsyncReadOwner&) = delete;
    AsyncReadOwner(AsyncReadOwner&&) = delete;
    AsyncReadOwner& operator=(AsyncReadOwner&&) = delete;

    [[nodiscard]] SubmitResult submit(std::shared_ptr<const resources::ByteView> view,
                                      std::uint64_t offset, std::size_t byte_count) noexcept;
    // A ready result transfers its owned bytes once. Cancelled/consumed tickets
    // are invalid; tickets never become valid in a different owner or later run.
    [[nodiscard]] PollResult poll(const Ticket& ticket) noexcept;
    [[nodiscard]] CancelStatus cancel(const Ticket& ticket) noexcept;

    // Signal only: reject new submissions, suppress all outstanding publication,
    // discard ready buffers and let queued tasks release their views without I/O.
    // Active provider reads cannot be interrupted and keep their lease until done.
    void shutdown() noexcept;
    // Requires prior shutdown; returns false otherwise and on worker self-join.
    // True means accepted tasks, concurrent submissions and owner-held providers
    // have finished/released. Caller-owned views/results are outside this owner.
    [[nodiscard]] bool join() noexcept;
    [[nodiscard]] bool shutdown_and_join() noexcept;
private:
    std::unique_ptr<ReadOwnerState> state_;
};

} // namespace reo::native::resource_io
