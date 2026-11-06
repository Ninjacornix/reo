#pragma once

#include "../sjrb/sjrb.hpp"
#include "../resource_io/async_read_owner.hpp"

#include <cstdint>
#include <limits>
#include <memory>
#include <span>
#include <vector>

namespace reo::native::adxt_refill {

enum class Status { completed, busy, closed, invalid_configuration, invalid_source,
    invalid_lease, invalid_count, id_exhausted, provider_failure, provider_protocol,
    ring_failure, reentrant_call };
enum class BackendState { idle, pending, complete, error };
struct Acceptance {
    std::int32_t sectors{}; // Negative/zero is declined; positive means retained work.
    bool error{};          // Source retry applies only for an actual error status.
};
struct Completion {
    BackendState state{BackendState::idle};
    std::uint64_t request_id{};
    std::vector<std::byte> bytes; // Exact accepted bytes on complete; empty otherwise.
};

// One exclusive owner, externally serialized calls. A worker may fill PRIVATE
// output only; it must not touch the ring, owner or callbacks. Destruction joins
// retained provider work. No arbitrary callback or raw destination escapes.
class Backend {
public:
    virtual ~Backend() = default;
    virtual Acceptance submit(std::shared_ptr<const resources::ByteView> view,
        std::uint64_t offset, std::uint32_t sectors, std::uint64_t request_id) noexcept = 0;
    virtual Completion poll() noexcept = 0;
    // Called only once the owner has no accepted request. Must report self-join
    // failure rather than block on its own provider worker.
    virtual bool shutdown_and_join() noexcept = 0;
};

// Real implementation: one unchanged AsyncReadOwner/SerialWorker, one request,
// double-byte exact-read budget. Constructor allocation/thread failure throws.
[[nodiscard]] std::unique_ptr<Backend> make_async_backend(std::size_t maximum_read_bytes);

struct Config {
    std::int32_t capacity{4096};
    std::int32_t start_sector{};
    std::int32_t byte_length{4096}; // First profile: whole sectors, in actual view.
    std::int32_t threshold{4096}, maximum_request_bytes{4096}, maximum_sectors{2};
    std::int32_t target_sectors{-1}, finite_sector_limit{0xFFFFF}, retry_limit{2};
    std::uint64_t maximum_id{std::numeric_limits<std::uint64_t>::max()};
};
struct InitialBuffer {
    std::int32_t position{};
    std::span<const std::uint8_t> data{}; // Copied before hooks/admission, not retained.
};
struct Snapshot {
    sjrb::Snapshot ring;
    std::int32_t state{}, accepted_sectors{}, progress_sectors{}, cumulative_bytes{}, retries{};
    std::int32_t producer_offset{}, producer_bytes{}, consumer_offset{}, consumer_bytes{};
    std::uint8_t paused{};
    bool in_flight{}, service_requested{}, stop_requested{}, close_requested{}, source_open{};
    bool shutting_down{}, joined{};
    std::uint64_t epoch{}, request_id{}, consumer_id{};
    Status last_error{Status::completed};
};
struct Hooks {
    void* context{};
    void (*target)(void*, const Snapshot&) noexcept {};
    sjrb::Hooks ring{}; // Read-only/nonreentrant; no provider I/O under hooks.
};
struct LeaseIdentity;
class EncodedSource;
class DataLease final {
public:
    DataLease() = default;
    ~DataLease() = default; // No credit return, I/O, callback or owner mutation.
    DataLease(const DataLease&) = delete;
    DataLease& operator=(const DataLease&) = delete;
    DataLease(DataLease&&) noexcept;
    DataLease& operator=(DataLease&&) = delete; // Never overwrite a live credit token.
    [[nodiscard]] std::int32_t bytes() const noexcept;
    [[nodiscard]] std::int32_t offset() const noexcept;
    [[nodiscard]] Status read_into(std::span<std::uint8_t> output, std::size_t relative = 0) const noexcept;
private:
    std::shared_ptr<LeaseIdentity> identity_;
    sjrb::Chunk chunk_;
    std::uint64_t epoch_{}, id_{};
    friend class EncodedSource;
};
struct BorrowResult { Status status{Status::invalid_lease}; DataLease lease; };

// Exactly one owned encoded ring. All methods/lease reads require external
// serialization; workers access private Backend output only. No Ring escape.
class EncodedSource final {
public:
    EncodedSource(Config, std::shared_ptr<const resources::ByteView>,
                  std::unique_ptr<Backend>, Hooks = {}, InitialBuffer = {});
    ~EncodedSource(); // Terminal emergency teardown; not ordinary ADXT stop.
    EncodedSource(const EncodedSource&) = delete;
    EncodedSource& operator=(const EncodedSource&) = delete;
    EncodedSource(EncodedSource&&) = delete;
    EncodedSource& operator=(EncodedSource&&) = delete;

    [[nodiscard]] Snapshot snapshot() const noexcept;
    [[nodiscard]] Status service() noexcept;
    [[nodiscard]] BorrowResult borrow_data(std::int32_t maximum) noexcept;
    [[nodiscard]] Status finish_data(DataLease&, std::int32_t consumed) noexcept;
    [[nodiscard]] Status set_paused(std::uint8_t) noexcept;
    [[nodiscard]] Status request_stop() noexcept;
    [[nodiscard]] Status request_close() noexcept;
    [[nodiscard]] Status reset_quiescent() noexcept;
    [[nodiscard]] Status replace_source(std::shared_ptr<const resources::ByteView>) noexcept;
    [[nodiscard]] Status begin_shutdown() noexcept;
    [[nodiscard]] bool finalize_shutdown_and_join() noexcept;
private:
    class Scope;
    Config config_;
    Hooks hooks_;
    sjrb::Ring ring_;
    std::shared_ptr<const resources::ByteView> view_;
    std::unique_ptr<Backend> backend_;
    std::shared_ptr<LeaseIdentity> identity_;
    sjrb::Chunk producer_, consumer_;
    Snapshot state_;
    std::uint64_t last_request_{}, last_consumer_{};
    bool busy_{};
    [[nodiscard]] Status return_producer(bool error) noexcept;
    [[nodiscard]] Status publish(Completion&) noexcept;
    [[nodiscard]] bool valid_view(const std::shared_ptr<const resources::ByteView>&) const noexcept;
    [[nodiscard]] Status reset_inner() noexcept;
    [[nodiscard]] Status fail(Status, bool terminal = false) noexcept;
};

} // namespace reo::native::adxt_refill
