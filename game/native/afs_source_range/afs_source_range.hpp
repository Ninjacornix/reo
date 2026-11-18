#pragma once
#include "../resources/bounded_view.hpp"
#include <cstdint>
#include <memory>
#include <vector>

namespace reo::native::afs_source_range {
enum class Status { completed, invalid_source, invalid_range, bad_magic, malformed_index,
    unsupported_profile, invalid_member, source_failure, no_memory };
struct Entry {
    std::uint32_t start_sector{}, sectors{}, logical_bytes{};
    friend bool operator==(const Entry&, const Entry&) = default;
};
struct Member { Status status{Status::invalid_member}; Entry entry; std::shared_ptr<const resources::ByteView> view; };
struct OpenRange {
    Status status{Status::invalid_range}; std::uint32_t start_sector{}, byte_length{};
    bool inside_backend{}; // The original default sentinel can retain an out-of-range start.
};
// Pure reconstruction of the admitted130478/130B78 range arithmetic. It does
// not open/close/stop a backend or report a provider completion fence.
[[nodiscard]] OpenRange prepare_open(std::uint32_t start, std::uint32_t count,
                                     std::uint32_t backend_sectors) noexcept;
class Archive;
struct OpenResult { Status status{Status::invalid_source}; std::shared_ptr<const Archive> archive; };
class Archive final {
public:
    [[nodiscard]] static OpenResult open(std::shared_ptr<const resources::ByteView> parent,
        std::uint64_t offset, std::uint64_t bytes, std::uint32_t max_members = 65536) noexcept;
    [[nodiscard]] std::uint32_t count() const noexcept { return static_cast<std::uint32_t>(entries_.size()); }
    [[nodiscard]] const Entry* entry(std::uint32_t index) const noexcept;
    [[nodiscard]] Member member(std::uint32_t index) const noexcept;
private:
    Archive() = default;
    std::shared_ptr<const resources::ByteView> parent_;
    std::uint64_t offset_{};
    std::vector<Entry> entries_;
};
} // namespace reo::native::afs_source_range
