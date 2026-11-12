#include "inventory_ui.hpp"
#include "world.hpp"
namespace reo::native::gameplay_world {
InventoryUi::InventoryUi(World& world)noexcept:world_(world){}
bool InventoryUi::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed();}
InventoryUiStatus InventoryUi::initialize()noexcept{
    if(world_.closed())return InventoryUiStatus::closed;
    if(world_.busy())return InventoryUiStatus::busy;
    state_=InventoryUiState{};state_->update_enabled=1;state_->requests_enabled=1;
    return InventoryUiStatus::completed;
}
bool InventoryUi::close_ready()const noexcept{
    return !world_.closed()&&state_&&state_->phase==0&&bool(world_.primary(world_.selected_actor));
}
bool InventoryUi::request_mode_ready(std::uint32_t mode)const noexcept{
    return !world_.closed()&&state_.has_value()&&mode!=0;
}
InventoryUiStatus InventoryUi::configure_requests(std::uint32_t mode)noexcept{
    if(world_.closed())return InventoryUiStatus::closed;
    //604310 also clears three asset caches then invokes6DDD70. Until the real
    // resource-reset owner is installed, refuse its complete command prefix.
    if(!request_mode_ready(mode))return InventoryUiStatus::unavailable_request_reset;
    request_blocked_=1;return InventoryUiStatus::completed;
}
bool InventoryUi::close()noexcept{
    //6E1430 clears the selected actor's status bit before its phase switch.
    // Whole-command admission excludes active phases with unowned consumers.
    if(!close_ready())return false;
    const auto actor=world_.primary(world_.selected_actor);if(!actor)return false;
    actor->status&=~0x8000u;return true;
}
InventoryUiStatus InventoryUi::force_close()noexcept{
    if(world_.closed())return InventoryUiStatus::closed;
    if(!state_||state_->phase!=0)return InventoryUiStatus::unavailable_phase;
    const auto actor=world_.primary(world_.selected_actor);if(!actor)return InventoryUiStatus::unavailable_actor;
    actor->auxiliary_status|=0x400u;world_.selected_frame_marker|=3;
    world_.session().inventory_owner=0;
    return close()?InventoryUiStatus::completed:InventoryUiStatus::unavailable_actor;
}
}
