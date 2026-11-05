#pragma once
namespace reo::native::resources::win32 { class MountedResources; }
class ReoHwBridge {
public:
    inline static ReoHwBridge* current{};
    ReoHwBridge() { current = this; }
    ~ReoHwBridge() { current = nullptr; }
    static ReoHwBridge* instance() noexcept { return current; }
    bool nativeResourceLayoutMatches(const reo::native::resources::win32::MountedResources&) const noexcept {
        return matches;
    }
    bool matches = true;
};
