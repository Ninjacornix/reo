#pragma once

#include <array>
#include <cstdint>
#include <limits>
#include <span>
#include <vector>

namespace reo::native::sjuni {

using RegionId = std::uint64_t;
using NodeId = std::uint32_t;
inline constexpr NodeId no_node = std::numeric_limits<NodeId>::max();

// Region zero is the null payload token. Offsets are numeric, never host pointers.
// Region bounds/lifetime and coherent numeric adjacency belong to the adapter.
struct Span {
    RegionId region{};
    std::int64_t offset{};
    std::int32_t bytes{};
    friend bool operator==(const Span&, const Span&) = default;
};

struct Node {
    NodeId next{no_node};
    Span span{}; // Retained unchanged when a whole get returns this node to free.
    friend bool operator==(const Node&, const Node&) = default;
};

struct Snapshot {
    std::uint8_t mode{};
    NodeId free_head{no_node};
    std::array<NodeId, 4> heads{no_node, no_node, no_node, no_node};
    std::vector<Node> nodes;
    friend bool operator==(const Snapshot&, const Snapshot&) = default;
};

// Hooks are synchronous and may reenter this Pool or import a new valid snapshot.
// Keep the Pool alive until every enclosing call returns. No internal mutex exists.
// An enter hook must preserve the admitted arithmetic domain; violation is distinct
// from unsupported preflight and must NEVER cause fallback to an original object.
struct Hooks {
    void* context{};
    void (*enter)(void*){};
    void (*leave)(void*){};
    void (*error)(void*, std::int32_t){};
};

enum class Result {
    completed, // Describes core execution, not an original guest success register.
    unsupported_arithmetic,
    unsupported_state,
    unsupported_selector, // Only the originally unchecked node-count operation.
    capacity_mismatch,
    callback_contract_violation // Hooks ran: never safe for automatic fallback.
};

class Pool final {
public:
    // Positive capacity <= INT32_MAX; allocates metadata/validation scratch once.
    // Throws invalid_argument for an inadmissible capacity; allocation may throw.
    explicit Pool(std::uint32_t capacity, std::uint8_t mode = 1, Hooks hooks = {});
    Pool(const Pool&) = delete;
    Pool& operator=(const Pool&) = delete;
    Pool(Pool&&) = delete;
    Pool& operator=(Pool&&) = delete;

    [[nodiscard]] std::uint32_t capacity() const noexcept;
    [[nodiscard]] std::uint8_t mode() const noexcept;
    [[nodiscard]] NodeId free_head() const noexcept;
    [[nodiscard]] const std::array<NodeId, 4>& heads() const noexcept;
    [[nodiscard]] std::span<const Node> nodes() const noexcept;
    void set_hooks(Hooks hooks) noexcept;

    void reset() noexcept; // Unguarded, as in the original; preserves mode/hooks.
    // All-or-nothing, no hooks. Every node must belong exactly once to one of the
    // four acyclic queues or free list. Queued spans must be positive/non-null
    // and have representable end offsets. Stale free-node spans are unrestricted.
    [[nodiscard]] Result import_state(const Snapshot& state) noexcept;
    void export_state(Snapshot& state) const;
    [[nodiscard]] Snapshot snapshot() const;

    // Pure preflight: unsupported results have no output/state/hook side effects.
    [[nodiscard]] Result check_get(std::uint32_t queue, std::int32_t request) const noexcept;
    [[nodiscard]] Result check_put(std::uint32_t queue, const Span& span) const noexcept;
    [[nodiscard]] Result check_unget(std::uint32_t queue, const Span& span) const noexcept;

    // Invalid queue is an original -3 callback, not unsupported admission.
    // Positive/null admission is before enter; span is reread after enter.
    // Errors are synchronous; exhaustion does not retry after callback reentry.
    [[nodiscard]] Result get(std::uint32_t queue, std::int32_t request, Span& output);
    [[nodiscard]] Result put(std::uint32_t queue, const Span& span);
    [[nodiscard]] Result unget(std::uint32_t queue, const Span& span);
    [[nodiscard]] std::int32_t queued_bytes(std::uint32_t queue);
    [[nodiscard]] bool head_availability(std::uint32_t queue, std::int32_t request,
                                         std::int32_t& output_head_bytes);
    [[nodiscard]] Result queued_nodes(std::uint32_t queue, std::uint32_t& output) const noexcept;
    [[nodiscard]] std::uint32_t free_nodes() const noexcept;

private:
    std::uint8_t mode_{};
    NodeId free_head_{no_node};
    std::array<NodeId, 4> heads_{no_node, no_node, no_node, no_node};
    std::vector<Node> nodes_;
    std::vector<std::uint8_t> visited_; // Import scratch, allocated at creation.
    Hooks hooks_{};
    [[nodiscard]] NodeId tail(std::uint32_t queue) const noexcept;
    void enter();
    void leave();
    void error();
};

} // namespace reo::native::sjuni
