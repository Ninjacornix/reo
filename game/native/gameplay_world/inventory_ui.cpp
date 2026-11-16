#include "inventory_ui.hpp"
#include "world.hpp"
#include "inventory_visibility.hpp"
#include "../gameplay_scenario/inventory_ui_resources.hpp"
namespace reo::native::gameplay_world {
InventoryUi::InventoryUi(World& world)noexcept:world_(world){}
bool InventoryUi::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed();}
InventoryUiStatus InventoryUi::initialize()noexcept{
    if(world_.closed())return InventoryUiStatus::closed;
    if(world_.busy())return InventoryUiStatus::busy;
    state_=InventoryUiState{};state_->update_enabled=1;state_->requests_enabled=1;
    return InventoryUiStatus::completed;
}
std::optional<bool> InventoryUi::dialogue_suppressed()const noexcept{
    if(!bound_to(world_)||!state_)return{};
    return ::reo::native::gameplay_world::dialogue_suppressed(
        {state_->update_enabled,state_->phase},world_.session().inventory_owner);
}
InventoryUiStatus InventoryUi::prepare_actor(Actor& actor)noexcept{
    if(world_.closed())return InventoryUiStatus::closed;
    const auto id=world_.identity_of(actor);
    if(!id||world_.resolve(id).get()!=&actor)return InventoryUiStatus::unavailable_actor;

    // 5F4F00 returns for non-primary actors before reading inventory ownership.
    if(actor.category!=0)return InventoryUiStatus::completed;
    const auto owner=world_.session().inventory_owner;
    // The source computes slot+1 as a 32-bit addiu. Do not byte-wrap 255+1.
    const auto actor_owner=std::uint16_t(actor.slot)+1u;
    if(actor_owner!=owner)return InventoryUiStatus::completed;
    // 5F4F00 admits only tags 1..4 after the exact slot+1 comparison.
    switch(owner){case 1:case 2:case 3:case 4:break;default:return InventoryUiStatus::completed;}

    // Source324200==1 takes the active UI branch. For a matching owner the
    // original guard returns without mutation; it does not call 6E1430 here.
    // If a future source-qualified caller needs that close branch, close()
    // continues to refuse an unqualified active phase.
    if(world_.session().session_state==1)return InventoryUiStatus::completed;

    const auto suppressed=dialogue_suppressed();
    if(!suppressed)return InventoryUiStatus::unavailable_phase;
    if(!*suppressed)world_.session().inventory_owner=0;
    return InventoryUiStatus::completed;
}
bool InventoryUi::close_ready()const noexcept{
    return !world_.closed()&&state_&&state_->phase==0&&bool(world_.primary(world_.selected_actor));
}
bool InventoryUi::request_mode_ready(std::uint32_t mode)const noexcept{
    return !world_.closed()&&state_.has_value()&&(mode!=0||
        (resources_&&resources_->bound_to(world_)&&resources_->ready_zero()));
}
InventoryUiStatus InventoryUi::bind_resources(gameplay_scenario::InventoryUiResources* resources,
    const gameplay_scenario::InventoryUiResources* expected)noexcept{
    if(world_.closed())return InventoryUiStatus::closed;
    if(world_.busy()||(resources_&&resources_->busy())||(resources&&resources->busy()))return InventoryUiStatus::busy;
    if(resources&&resources==resources_)return InventoryUiStatus::completed;
    if(resources_!=expected||(resources&&!resources->bound_to(world_)))return InventoryUiStatus::unavailable_request_reset;
    resources_=resources;return InventoryUiStatus::completed;
}
InventoryUiStatus InventoryUi::reset_request_gate()noexcept{
    if(world_.closed())return InventoryUiStatus::closed;
    if(world_.busy())return InventoryUiStatus::busy;
    request_blocked_=0;return InventoryUiStatus::completed;
}
InventoryUiStatus InventoryUi::configure_requests(std::uint32_t mode)noexcept{
    if(world_.closed())return InventoryUiStatus::closed;
    if(!request_mode_ready(mode))return InventoryUiStatus::unavailable_request_reset;
    if(mode){request_blocked_=1;return InventoryUiStatus::completed;}
    request_blocked_=0; //604310 commits this before the cache/asset refresh.
    const auto result=resources_->refresh_zero();
    return result==gameplay_scenario::InventoryResourcesStatus::completed?
        InventoryUiStatus::completed:result==gameplay_scenario::InventoryResourcesStatus::busy?
        InventoryUiStatus::busy:InventoryUiStatus::unavailable_request_reset;
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
