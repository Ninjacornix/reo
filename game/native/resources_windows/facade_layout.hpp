#pragma once

#include "mounted_resources.hpp"
#include "runtime/cdvd/cdvd.h"
#include <algorithm>

namespace reo::native::resources::win32 {

// Temporary migration check against the facade that the game already opened.
// The caller supplies actual overlay activity, retains both objects, and calls
// before guest execution. This checks captured layout + current pinned objects;
// it does not infer original ISO extents or admit mutable overlay globals.
inline bool matches_plain_pak_layout(const reo::CDVD& facade, const MountedResources& mount,
                                     bool overlay_active) noexcept {
    try {
        if (!facade.is_game_pak() || overlay_active || mount.identity().overlay_plan_sha256)
            return false;
        const auto legacy = facade.pak_routes();
        const auto routes = mount.routes();
        if (legacy.size() != routes.size()) return false;
        for (std::size_t i = 0; i < routes.size(); ++i) {
            const auto& route = routes[i];
            const auto& original = legacy[i];
            if (route.overlay || route.key != original.key || route.lba != original.lba ||
                route.bytes != original.bytes || route.sector_capacity_bytes !=
                    ((original.bytes + 2047) / 2048 + 0x4000) * 2048) return false;
            const auto found = std::find_if(mount.identity().sources.begin(), mount.identity().sources.end(),
                [&](const auto& source) { return source.kind == MountSourceKind::imported && source.key == route.key; });
            if (found == mount.identity().sources.end() ||
                !std::filesystem::equivalent(original.path, found->file.final_path)) return false;
        }
        return true;
    } catch (...) { return false; }
}
} // namespace reo::native::resources::win32
