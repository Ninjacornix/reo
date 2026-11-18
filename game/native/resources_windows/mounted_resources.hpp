#pragma once

#include "pinned_file.hpp"
#include "../resources/byte_view.hpp"
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace reo::native::resources::win32 {

enum class MountStatus {
    ok,
    invalid_path,
    manifest_error,
    file_set_mismatch,
    unsupported_layout,
    source_failure,
    overlay_error,
    no_memory
};
enum class MountSourceKind { manifest, imported, overlay_plan, replacement };
struct MountSourceIdentity {
    MountSourceKind kind{};
    std::string key;
    FileIdentity file;
};
struct MountIdentity {
    std::uint32_t import_version{};
    Digest manifest_sha256{};
    std::optional<Digest> overlay_plan_sha256;
    // Computed from actual retained file IDs/hashes, plan/manifest bytes, and
    // ordered route/segment descriptions. Not a signed retail-disc identity.
    Digest route_sha256{};
    std::vector<MountSourceIdentity> sources;
};
struct MountedRoute {
    // Current PAK facade key: uppercase ASCII with backslash separators.
    std::string key;
    std::uint32_t lba{};
    std::uint64_t bytes{}, sector_capacity_bytes{};
    bool overlay{};
    Digest layout_sha256{};
    std::shared_ptr<const ByteView> view;
};
enum class RouteStatus { ok, not_found, invalid_range };
struct SectorRoute {
    RouteStatus status{RouteStatus::not_found};
    std::shared_ptr<const ByteView> view;
    std::uint64_t offset{}, prefix_bytes{}, total_bytes{};
    bool overlay{};
};
struct MountOpenResult;

// An admitted File1 extracted-data/PAK mount. No ISO-sector inference, automatic
// worker, ResourceSession singleton, mutable assets::active or environment state.
// Returned views retain their file providers independently of this facade.
class MountedResources final {
  public:
    [[nodiscard]] static MountOpenResult
    open_file1_windows(const std::filesystem::path& imported_data,
                       const std::optional<std::filesystem::path>& overlay_plan = {}) noexcept;
    ~MountedResources();
    [[nodiscard]] const MountIdentity& identity() const noexcept;
    [[nodiscard]] std::span<const MountedRoute> routes() const noexcept;
    // Input is an already-canonical facade key, not an arbitrary PS2 URI.
    // Overlay wins file lookup; original PAK-sector routes remain available.
    [[nodiscard]] std::optional<MountedRoute> find_file(std::string_view canonical_key) const;
    // Metadata only: caller zero-fills private staging for total_bytes, then reads a positive
    // prefix_bytes from the retained view at offset through ResourceSession.
    // Zero prefix means no provider read (offset may exceed EOF). Publish only
    // after successful staging. No I/O or destination publication occurs here.
    [[nodiscard]] SectorRoute resolve_sectors(std::uint32_t lba,
                                              std::uint32_t count) const noexcept;

  private:
    struct Impl;
    explicit MountedResources(std::unique_ptr<Impl>) noexcept;
    std::unique_ptr<Impl> impl_;
};
struct MountOpenResult {
    MountStatus status{MountStatus::source_failure};
    std::shared_ptr<const MountedResources> mount;
    std::string detail;
    std::uint32_t system_error{};
};
} // namespace reo::native::resources::win32
