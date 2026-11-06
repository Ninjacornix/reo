#pragma once
#include "../../sjrb/sjrb.hpp"
#include <array>
#include <cstdint>
#include <memory>
#include <span>

namespace reo::native::adx_pcm::v2 {
inline constexpr std::int32_t capacity = 16384, extension = 192;
enum class Status { completed, busy, closed, invalid_configuration, invalid_lease,
    invalid_count, physical_conflict, id_exhausted, ring_failure, invariant_fault };
enum class Phase { idle, reserved, staged };
enum class Transfer { none, reserve, read, publish, restore, finish_read };
struct Grant {
    std::int32_t offset{}, bytes{};
    friend bool operator==(const Grant&, const Grant&) = default;
};
struct Config { std::uint32_t channels{1}; std::int32_t cursor{}, queued_bytes{}; };
struct Snapshot {
    std::array<sjrb::Snapshot, 2> rings{};
    std::array<Grant, 2> producer{}, consumer{};
    std::uint64_t write_id{}, read_id{};
    Transfer transfer{Transfer::none}; std::uint32_t transfer_channel{};
    Phase phase{Phase::idle}; bool stopped{}, retired{}, fault{};
};
struct Domain;
class Store;
class WriteLease final {
public:
    WriteLease() = default;
    WriteLease(WriteLease&&) noexcept;
    WriteLease(const WriteLease&) = delete;
    WriteLease& operator=(const WriteLease&) = delete;
    WriteLease& operator=(WriteLease&&) = delete;
    [[nodiscard]] Grant grant(std::uint32_t channel) const noexcept;
private:
    friend class Store;
    std::shared_ptr<Domain> domain_; std::uint64_t id_{};
    std::array<sjrb::Chunk, 2> chunks_;
};
class ReadLease final {
public:
    ReadLease() = default;
    ReadLease(ReadLease&&) noexcept;
    ReadLease(const ReadLease&) = delete;
    ReadLease& operator=(const ReadLease&) = delete;
    ReadLease& operator=(ReadLease&&) = delete;
    [[nodiscard]] Grant grant(std::uint32_t channel) const noexcept;
    [[nodiscard]] Status read_into(std::uint32_t channel, std::span<std::uint8_t>,
                                   std::size_t relative = 0) const noexcept;
private:
    friend class Store;
    std::shared_ptr<Domain> domain_; std::uint64_t id_{};
    std::array<sjrb::Chunk, 2> chunks_;
};
class View final {
public:
    [[nodiscard]] std::int32_t bytes() const noexcept;
    [[nodiscard]] Status read_into(std::span<std::uint8_t>, std::size_t relative = 0) const noexcept;
private:
    friend class Store;
    std::shared_ptr<Domain> domain_; sjrb::Chunk chunk_;
};
struct Hooks {
    void* context{};
    void (*guard)(void*, std::uint32_t channel, bool entering) noexcept {};
    void (*publication)(void*, std::uint32_t channel, const View&) noexcept {};
};
struct WriteResult { Status status{Status::invalid_lease}; WriteLease lease; };
struct ReadResult { Status status{Status::invalid_lease}; ReadLease lease; };
struct Pcm { std::span<const std::int16_t> left, right; };

// A serialized storage/credit owner, not a decoder or device fence. All memory
// is allocated in construction. Tokens never return credit from a destructor.
class Store final {
public:
    explicit Store(Config, Hooks = {}, std::uint8_t initial_byte = 0);
    ~Store();
    Store(const Store&) = delete; Store& operator=(const Store&) = delete;
    [[nodiscard]] static bool admits(Config) noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
    [[nodiscard]] WriteResult reserve() noexcept;
    // Refusals retain the actual reservation. Never original-call fallback.
    // Stage stores/wraps only. Publication and all logical credit stay pending
    // so the caller can return encoded input and update decoder state between.
    // No PCM mutation/restore/stop may intervene after successful staging.
    // Pure sizing query for a retained reservation; no codec, bytes or credit effects.
    [[nodiscard]] Status admit_stage(const WriteLease&, std::size_t raw_samples,
        std::int32_t corrected_samples, std::int32_t published_samples) const noexcept;
    [[nodiscard]] Status stage(WriteLease&, Pcm,
        std::int32_t corrected_samples, std::int32_t published_samples) noexcept;
    [[nodiscard]] Status publish(WriteLease&) noexcept;
    [[nodiscard]] Status write_and_publish(WriteLease&, Pcm,
        std::int32_t corrected_samples, std::int32_t published_samples) noexcept;
    [[nodiscard]] Status restore(WriteLease&) noexcept;
    [[nodiscard]] ReadResult read(std::int32_t requested_bytes) noexcept;
    [[nodiscard]] Status finish(ReadLease&) noexcept;
    [[nodiscard]] Status stop() noexcept;
    [[nodiscard]] Status retire() noexcept;
    [[nodiscard]] Status read_backing(std::uint32_t, std::span<std::uint8_t>) const noexcept;
private:
    class Scope;
    struct RingContext { Store* owner{}; std::uint32_t channel{}; };
    Config config_; Hooks hooks_; std::shared_ptr<Domain> domain_;
    std::array<std::unique_ptr<sjrb::Ring>, 2> rings_;
    std::array<RingContext, 2> contexts_;
    std::array<sjrb::Chunk, 2> producer_, consumer_;
    std::array<std::uint8_t, capacity + extension> staging_{};
    std::array<std::uint8_t, extension> wrap_staging_{};
    std::uint64_t last_write_{}, last_read_{};
    Transfer transfer_{Transfer::none}; std::uint32_t transfer_channel_{};
    bool busy_{}, stopped_{}, retired_{}, fault_{};
    Phase phase_{Phase::idle}; std::int32_t staged_published_{};
    static void enter(void*) noexcept;
    static void leave(void*) noexcept;
    static void ring_error(void*, std::int32_t) noexcept;
    [[nodiscard]] bool sound() const noexcept;
    [[nodiscard]] bool same_grants() const noexcept;
    [[nodiscard]] bool valid(const WriteLease&) const noexcept;
    [[nodiscard]] bool valid(const ReadLease&) const noexcept;
    [[nodiscard]] bool safe_writes(std::uint32_t, std::int32_t raw_bytes,
        std::int32_t produced_bytes, std::int32_t published_bytes) const noexcept;
    [[nodiscard]] bool ok(sjrb::Status) noexcept;
    [[nodiscard]] Status fail() noexcept;
    [[nodiscard]] bool bootstrap(std::uint32_t) noexcept;
};
} // namespace reo::native::adx_pcm
