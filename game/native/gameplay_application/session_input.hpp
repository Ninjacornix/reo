#pragma once
#include "../gameplay_world/world.hpp"

namespace reo { class Input; }
namespace reo::native::gameplay_application {
class SessionStartupEffects;

// One File1 offline input source. Input and the actual host window must remain
// alive until this owner is destroyed; all calls are on the simulation thread.
class SessionInput final {
public:
    SessionInput(gameplay_world::World&, reo::Input&, void* window) noexcept;
    bool poll() noexcept;
    bool bound_to(const gameplay_world::World& world) const noexcept { return &world==&world_; }
    bool bound_to_window(const void* window) const noexcept { return window_==window; }
private:
    friend class SessionStartupEffects;
    // Called only at 5EB520's synchronous 1B0AC0 site, with World busy.
    bool initialize_roster_routes() noexcept;
    gameplay_world::World& world_;
    reo::Input& input_;
    void* window_;
    bool present_{},sampled_{};
};
}
