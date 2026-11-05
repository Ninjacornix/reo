#pragma once
#include "game/native/resources/byte_view.hpp"
#include "game/native/resources_windows/types.hpp"
#include <algorithm>
#include <atomic>
#include <filesystem>
#include <functional>
#include <optional>
#include <string>
#include <vector>

namespace reo::native::resources::win32 {
enum class MountStatus { ok, source_failure };
enum class ReaderDisposition { not_covered, ok, failed };
struct MountedReadResult {
    ReaderDisposition disposition{ReaderDisposition::not_covered};
    Status resource_status{Status::invalid_range};
    std::size_t bytes{};
};
struct MountIdentity {
    std::uint32_t import_version{2};
    Digest manifest_sha256{};
    std::optional<Digest> overlay_plan_sha256;
    Digest route_sha256{};
    std::vector<unsigned> sources{1, 2, 3};
};
class MountedResources {};
class MountedReader;
struct MountedReaderOpenResult {
    MountStatus status{MountStatus::source_failure};
    std::shared_ptr<MountedReader> reader;
    std::string detail;
    std::uint32_t system_error{};
};
namespace mock {
inline std::atomic<unsigned> opens{}, reads{}, io_calls{}, deaths{};
inline bool factory_failure{}, null_factory{};
inline std::optional<std::filesystem::path> captured_overlay;
inline std::filesystem::path captured_root;
inline std::size_t captured_limit{};
inline std::function<MountedReadResult(std::uint32_t, std::uint32_t, std::span<std::byte>)> action;
inline std::weak_ptr<MountedReader> last_reader;
}
class MountedReader final {
    MountIdentity identity_;
    MountedResources mount_;
public:
    MountedReader() { identity_.route_sha256[0] = 0x12; identity_.manifest_sha256[0] = 0x34; }
    ~MountedReader() { ++mock::deaths; }
    static MountedReaderOpenResult open_file1_windows(const std::filesystem::path& root,
        const std::optional<std::filesystem::path>& overlay = {}, std::size_t limit = 8u * 1024u * 1024u) noexcept {
        ++mock::opens;
        mock::captured_root = root;
        mock::captured_overlay = overlay;
        mock::captured_limit = limit;
        if (mock::factory_failure) return {MountStatus::source_failure, {}, "synthetic mount rejection", 5};
        if (mock::null_factory) return {MountStatus::ok, {}, {}, 0};
        auto reader = std::make_shared<MountedReader>();
        mock::last_reader = reader;
        return {MountStatus::ok, std::move(reader), {}, 0};
    }
    MountedReadResult read_sectors(std::uint32_t lba, std::uint32_t count,
                                   std::span<std::byte> destination) noexcept {
        ++mock::reads;
        if (mock::action) return mock::action(lba, count, destination);
        ++mock::io_calls;
        std::fill(destination.begin(), destination.end(), std::byte{0x63});
        return {ReaderDisposition::ok, Status::ok, destination.size()};
    }
    const MountIdentity& identity() const noexcept { return identity_; }
    const MountedResources& mount() const noexcept { return mount_; }
};
} // namespace reo::native::resources::win32
