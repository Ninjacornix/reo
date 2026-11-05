#pragma once

#include "mounted_resources.hpp"

namespace reo::native::resources::win32 {

enum class ReaderDisposition { not_covered, ok, failed };
struct MountedReadResult {
    ReaderDisposition disposition{ReaderDisposition::not_covered};
    Status resource_status{Status::invalid_range};
    std::size_t bytes{};
};
struct MountedReaderOpenResult;

// Synchronous, exact in-file sector reads only. No guest/runtime state, worker,
// environment lookup or fallback I/O. Owner and writable destination must remain
// alive through every call; concurrent destinations must be disjoint/synchronized.
class MountedReader final {
  public:
    [[nodiscard]] static MountedReaderOpenResult
    open_file1_windows(const std::filesystem::path& imported_data,
                       const std::optional<std::filesystem::path>& overlay_plan = {},
                       std::size_t max_read_bytes = 8u * 1024u * 1024u) noexcept;
    ~MountedReader();
    MountedReader(const MountedReader&) = delete;
    MountedReader& operator=(const MountedReader&) = delete;
    MountedReader(MountedReader&&) = delete;
    MountedReader& operator=(MountedReader&&) = delete;

    // not_covered is decided before provider I/O or destination mutation. Only
    // that disposition permits a caller's legacy fallback. Native failures are
    // failed with zero bytes and untouched output; they must not restart I/O.
    [[nodiscard]] MountedReadResult read_sectors(std::uint32_t lba, std::uint32_t count,
                                                 std::span<std::byte> destination) noexcept;
    [[nodiscard]] const MountIdentity& identity() const noexcept;
    [[nodiscard]] const MountedResources& mount() const noexcept;

  private:
    struct Impl;
    explicit MountedReader(std::unique_ptr<Impl>) noexcept;
    std::unique_ptr<Impl> impl_;
};
struct MountedReaderOpenResult {
    MountStatus status{MountStatus::source_failure};
    std::shared_ptr<MountedReader> reader;
    std::string detail;
    std::uint32_t system_error{};
};
} // namespace reo::native::resources::win32
