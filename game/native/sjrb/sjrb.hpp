#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>

namespace reo::native::sjrb {

enum class Status {
    completed,
    invalid_geometry,
    invalid_selector,
    invalid_span,
    foreign_storage,
    stale_incarnation,
    unsafe_request,
    unsafe_state,
    reentrant_call,
    incarnation_exhausted,
    callback_contract_violation // Guard hook ran: never original-call fallback.
};

struct Storage;
class Ring;

// Storage is retained strongly. No guest address or unowned data pointer exists.
// Mutable byte access is bounded copying, checked at each call; no escaped span
// can write into a later incarnation. All accesses require external serialization.
class Chunk final {
public:
    Chunk() = default;
    [[nodiscard]] static Chunk null(std::int32_t bytes = 0) noexcept;
    [[nodiscard]] bool is_null() const noexcept;
    [[nodiscard]] std::int32_t offset() const noexcept;
    [[nodiscard]] std::int32_t bytes() const noexcept;
    [[nodiscard]] std::uint64_t incarnation() const noexcept;
    // Numeric descriptor edit, as in a returning original error callback. It
    // cannot grant byte access: read/write and Ring admission check the extent.
    void set_bytes(std::int32_t bytes) noexcept;
    void clear() noexcept;
    [[nodiscard]] Status read(std::span<std::uint8_t> output, std::size_t relative = 0) const noexcept;
    [[nodiscard]] Status write(std::span<const std::uint8_t> input, std::size_t relative = 0) noexcept;

    // Actual split contract in the nonnegative, disjoint-descriptor domain.
    // Prefix above length clamps; zero remainder is a null chunk. No copying of
    // payload, guards or callbacks. Descriptor aliases refuse before effects.
    [[nodiscard]] static Status split(const Chunk& input, std::int32_t prefix,
                                      Chunk& first, Chunk& remainder) noexcept;
private:
    std::shared_ptr<Storage> storage_;
    std::uint64_t incarnation_{};
    std::int32_t offset_{}, bytes_{};
    [[nodiscard]] Status check_extent() const noexcept;
    friend class Ring;
};

// Synchronous, nonthrowing hooks. Caller serializes the Ring AND all its chunks.
// Guard hooks observe only. Error hooks may observe and edit the supplied Chunk
// length; arbitrary reentry/reset/destroy is outside this original-parity domain.
// Mutating Ring reentry refuses; do not destroy a Ring during an enclosing call.
struct Hooks {
    void* context{};
    void (*enter)(void*) noexcept {};
    void (*leave)(void*) noexcept {};
    void (*error)(void*, std::int32_t) noexcept {};
};

struct Snapshot {
    std::int32_t capacity{}, extension{};
    std::int32_t data{}, free{}, write{}, read{};
    // free acquisition, free return, data acquisition, data publication.
    std::array<std::uint32_t, 4> totals{};
    std::uint64_t incarnation{};
    friend bool operator==(const Snapshot&, const Snapshot&) = default;
};

// One standalone ring owner. This is not the original global 256-object pool.
// Construction allocates once and may throw invalid_argument/bad_alloc; it emits
// no original guard/callback. All operation paths allocate no backing/metadata.
class Ring final {
public:
    // Positive capacity, 0<=extension<=capacity, capacity+extension<=INT32_MAX.
    // Complete physical backing is allocated and owned before any operation.
    explicit Ring(std::int32_t capacity, std::int32_t extension, Hooks hooks = {},
                  std::uint8_t initial_byte = 0);
    Ring(const Ring&) = delete;
    Ring& operator=(const Ring&) = delete;
    Ring(Ring&&) = delete;
    Ring& operator=(Ring&&) = delete;
    ~Ring(); // Outstanding Chunk objects keep their actual backing alive.

    [[nodiscard]] static bool admits_geometry(std::int32_t capacity, std::int32_t extension) noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
    [[nodiscard]] Status set_hooks(Hooks hooks) noexcept;
    [[nodiscard]] Status reset() noexcept; // Tag guard; invalidates prior chunks.
    [[nodiscard]] Status get(std::uint32_t pool, std::int32_t requested, Chunk& output) noexcept;
    [[nodiscard]] Status put(std::uint32_t pool, Chunk& span) noexcept;
    [[nodiscard]] Status unget(std::uint32_t pool, Chunk& span) noexcept;
    [[nodiscard]] Status peek(std::uint32_t pool, std::int32_t requested,
                              std::int32_t& granted, bool& fits) noexcept;
    [[nodiscard]] Status count(std::uint32_t pool, std::int32_t& output) noexcept; // No tag guard.
    [[nodiscard]] Status set_total(std::uint32_t pool, std::uint32_t which, std::uint32_t value) noexcept;
    [[nodiscard]] Status total(std::uint32_t pool, std::uint32_t which, std::uint32_t& output) const noexcept;

    // Explicit original permissive numeric-span admission, NOT a linear lease.
    // A matching current storage/incarnation and physical extent are required;
    // prior acquisition or one-time return is deliberately not invented.
    [[nodiscard]] Status make_span(std::int32_t offset, std::int32_t bytes, Chunk& output) const noexcept;
    [[nodiscard]] Status read_backing(std::span<std::uint8_t> output) const noexcept;
    [[nodiscard]] std::size_t backing_size() const noexcept;
private:
    class Scope;
    std::shared_ptr<Storage> storage_;
    Snapshot state_;
    Hooks hooks_;
    bool busy_{};
    [[nodiscard]] Status check_span(const Chunk& span) const noexcept;
    [[nodiscard]] Status check_position(std::uint32_t pool) const noexcept;
    [[nodiscard]] std::int32_t grant(std::uint32_t pool, std::int32_t requested) const noexcept;
};

} // namespace reo::native::sjrb
