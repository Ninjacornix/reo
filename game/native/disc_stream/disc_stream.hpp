#pragma once

#include <array>
#include <cstdint>

namespace reo::native::disc_stream {

struct BufferId {
    std::uint64_t value{};
    explicit constexpr operator bool() const noexcept { return value != 0; }
    friend bool operator==(BufferId, BufferId) = default;
};

struct RequestId {
    std::uint64_t value{};
    explicit constexpr operator bool() const noexcept { return value != 0; }
    friend bool operator==(RequestId, RequestId) = default;
};

enum class FileStatus { idle, ready, pending, error };
enum class RequestStatus {
    stopped, queued, active, complete, stage4, stage5, stage6, stage7, stage8, error
};
enum class Diagnostic { null_file, negative_request, null_buffer };

struct FileState {
    FileStatus status{FileStatus::idle};
    std::int32_t sectors{};
    std::int32_t cursor{};
    std::int32_t accepted{};
    std::int32_t completed{};
    BufferId buffer;
    RequestId request;
    std::uint32_t base_sector{};
    // The fourth mode byte is retained; submitting a request updates only three.
    std::array<std::uint8_t, 4> read_mode{};
    friend bool operator==(const FileState&, const FileState&) = default;
};

struct Settings {
    std::array<std::uint8_t, 3> read_mode{};
    std::int32_t sync_mode{}; // Exactly 1 selects the synchronous path.
};

// Scripted/preserving, no-reentry domain: hooks return normally and may observe
// state, but do not mutate FileState/Settings or reenter operations on this file.
// This interface supplies no I/O, scheduler, stop/close or payload-lifetime policy.
class Hooks {
public:
    virtual ~Hooks() = default;
    virtual void diagnostic(Diagnostic) = 0;
    virtual void enter() = 0;
    virtual void leave() = 0;
    virtual RequestId create_request() = 0;
    // Describes the original wrapping inclusive range without interpreting an
    // opaque buffer ID as a pointer. A bridge constructs its own address range.
    virtual void cache_range(BufferId destination, std::uint32_t bytes) = 0;
    virtual bool prepare_disc(RequestId request, std::uint32_t start_sector,
                              std::int32_t sectors, BufferId destination,
                              const std::array<std::uint8_t, 4>& mode) = 0;
    virtual void cd_sync() = 0;
    virtual void server_gate() = 0;
    virtual void server_service() = 0;
    virtual void wait(RequestId request) = 0; // Original scalar caller ignores v0.
    virtual void destroy(RequestId request) = 0;
    virtual RequestStatus request_status(RequestId request) = 0;
};

// Arithmetic is explicitly wrapping 32-bit arithmetic; no host signed overflow.
// Nonnull FileState and returned RequestStatus values must use declared enums.
std::int32_t seek(FileState* file, std::int32_t offset, std::int32_t origin, Hooks& hooks);
std::int32_t tell(const FileState* file, Hooks& hooks);
std::int32_t status(const FileState* file, Hooks& hooks);
std::int32_t transferred(const FileState* file, Hooks& hooks);
std::int32_t request(FileState* file, std::int32_t sectors, BufferId destination,
                     const Settings& settings, Hooks& hooks);
void update(FileState& file, Hooks& hooks);

} // namespace reo::native::disc_stream
