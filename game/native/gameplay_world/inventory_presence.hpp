#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
struct InventoryPeerPresence {std::uint8_t room{};Position position;std::uint32_t updates_left{};};
enum class PresenceStatus {completed,unavailable};
// A native inventory/map view owns this derived cache. It borrows the canonical
// simulation World, and is simulation-thread only; UI handoff copies values.
// Uninitialized peer samples remain unknown until an actual producer supplies
// them. Activating this cache does not create a UI or import its other content.
class InventoryPresence final {
public:
    explicit InventoryPresence(World& world)noexcept:world_(world){}
    bool bound_to(const World& world)const noexcept{return &world_==&world&&!world_.closed();}
    bool activate()noexcept;
    void close()noexcept;
    bool active()const noexcept{return active_&&!world_.closed();}
    PresenceStatus refresh(std::uint32_t actor_index)noexcept; //6DFEE0
    std::optional<InventoryPeerPresence> peer(std::uint32_t actor_index)const noexcept;
private:
    World& world_;
    bool active_{};
    std::array<std::optional<InventoryPeerPresence>,4> peers_;
};
}
