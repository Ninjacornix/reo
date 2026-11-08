#pragma once
#include "game/native/resources_windows/mounted_resources.hpp"
#include <string_view>

namespace reo::native::adxt_binding {
enum class FileStatus {ready,missing_mount,unsupported_mount,unsupported_argument,invalid_name,
    missing_file,unsupported_range,empty_range,no_memory};
struct FileRequest {std::string_view filename;std::uint32_t backend_argument{},start_sector{},sector_count{0xfffff};};
struct FileSource {
    FileStatus status{FileStatus::missing_mount};
    std::string canonical_key{};
    std::shared_ptr<const resources::ByteView> view{};
    std::uint32_t start_sector{},bytes{};
};
// Metadata-only preparation from the SAME retained native mount. The caller
// qualifies its runtime/guest read scope and captures arguments before this
// operation, outside canonical Owner::run. No worker, callback or provider read
// occurs here. A ready ByteView retains the pinned files independently of mount.
// The original backend's second argument is opaque; only zero is admitted by
// this first profile. No source replacement/retirement is performed on refusal.
[[nodiscard]] FileSource prepare_file_source(
    const std::shared_ptr<const resources::win32::MountedResources>&,FileRequest)noexcept;
}
