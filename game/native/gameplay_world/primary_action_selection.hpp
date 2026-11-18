#pragma once
#include "animation_events.hpp"
#include <span>

namespace reo::native::gameplay_world {
// 711810's authored action row. Callers select the row before the input policy;
// it is not a table of guest function pointers.
using LocomotionActionRow=std::array<std::uint16_t,16>;
const LocomotionActionRow& locomotion_action_row(std::uint8_t);
bool select_status_action(Actor&); //64E800
bool select_character_action(const World&,Actor&); //64FFA0
bool select_directional_action(Actor&); //64E860
bool select_forward_action(Actor&,const LocomotionActionRow&); //64DC00
bool select_fast_forward_action(Actor&,const LocomotionActionRow&); //64DC60
bool select_backward_action(Actor&,const LocomotionActionRow&); //64DD00
bool select_turn_action(Actor&,const LocomotionActionRow&); //64DDC0
bool select_resource_movement(Actor&,const animation_events::Metadata&); //64E6B0

class PrimaryActionSelectionServices {
public:
    virtual ~PrimaryActionSelectionServices()=default;
    virtual bool dialogue_suppressed()=0; //6DEE20
    virtual bool interaction(World&,Actor&)=0; //64E960
    virtual bool request(World&,Actor&)=0; //64F5F0
    virtual bool modal(World&,Actor&)=0; //64F110
    //65F060 and the following canonical target write; manual mode clears the
    //same target and CDC. A missing target owner must throw before that write.
    virtual void prepare_weapon_target(World&,Actor&,bool automatic)=0;
    virtual bool reload_available(World&,Actor&,std::uint8_t)=0; //586440
};
bool select_weapon_action(World&,Actor&,const animation_events::Metadata&,PrimaryActionSelectionServices&); //64E5C0
bool select_reload_action(World&,Actor&,PrimaryActionSelectionServices&); //64E770
// Complete64B060 ordering. The original empty64F680,64E950,64FB70,64FB80
// and64DCF0 entries return zero; no provider or fallback is required for them.
bool select_idle_action(World&,Actor&,const animation_events::Metadata&,PrimaryActionSelectionServices&);
}
