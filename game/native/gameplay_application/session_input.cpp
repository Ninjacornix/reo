#include "session_input.hpp"
#include "../gameplay_actors/host_input.hpp"
#include "../../../runtime/input/input.h"

namespace reo::native::gameplay_application {
SessionInput::SessionInput(gameplay_world::World& world, reo::Input& input, void* window) noexcept:
    world_(world),input_(input),window_(window){}

bool SessionInput::poll() noexcept {
    if(world_.closed() || world_.busy() || world_.mode!=0 || world_.controllers().empty()) return false;
    const auto sample=input_.poll_native_window(window_);
    if(!sample){sampled_=false;return false;}
    const auto& port=sample->ports[0];
    const auto& pad=port.pad;
    try {
        world_.controllers()[0]=gameplay_actors::input::normalize_analog_pad(
            {pad.buttons,pad.right_x,pad.right_y,pad.left_x,pad.left_y});
    } catch(...) {sampled_=false;return false;}
    present_=port.keyboard_available||port.physical_connected;
    sampled_=true;
    return true;
}

bool SessionInput::initialize_roster_routes() noexcept {
    if(world_.closed() || !world_.busy() || world_.mode!=0 || !sampled_)return false;
    // The cold File1 controller count is one. 1B0AC0 examines controller 0
    // and primary record 0 once; an inactive actor does not advance that slot.
    if(!present_)return true;
    const auto actor=world_.primary(0);
    if(!actor || !actor->active)return true;
    if(actor->slot>=world_.controller_bindings.size())return false;
    world_.controller_bindings[actor->slot]=0;
    return true;
}
}
