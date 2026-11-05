#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>

namespace reo::native::resources {

enum class Status {
    ok,
    invalid_handle,
    invalid_range,
    read_limit,
    source_failure,
    no_memory,
    session_closed,
    invalid_view,
    capacity_exhausted
};

struct ReadResult {
    Status status{Status::source_failure};
    std::size_t bytes{};
    friend bool operator==(const ReadResult&, const ReadResult&) = default;
};

// Immutable size; size() must be nonblocking and perform no I/O. read() may block
// and may modify its supplied buffer before failing. It may throw; the session
// translates allocation/source exceptions. Success must report the exact count.
class ByteView {
public:
    virtual ~ByteView() = default;
    [[nodiscard]] virtual std::uint64_t size() const noexcept = 0;
    [[nodiscard]] virtual ReadResult read(std::uint64_t offset,
                                        std::span<std::byte> destination) const = 0;
};

struct ViewResult {
    Status status{Status::invalid_view};
    std::shared_ptr<const ByteView> view;
};

} // namespace reo::native::resources
