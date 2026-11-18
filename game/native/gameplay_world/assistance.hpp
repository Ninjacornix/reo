#pragma once
#include "world.hpp"
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_world {
class InventoryUi;
class ActionAnimation;
// Complete666A10 with666680's assistance selector4, over the physical
// primary roster followed by the canonical auxiliary list.
actors::EntityId nearest_assistance_actor(World&,Actor&);
//6507F0 and6506C0 use native actor identities rather than guest pointers.
actors::EntityId select_assistance_actor(gameplay_update::Owner&,Actor&);
void begin_assistance(gameplay_update::Owner&,Actor&,Actor& related);
//64F7B0's complete side effects; the actor behavior caller ignores its return.
//Animation is required only at the original state2 animation callsite.
void update_cooperation_action(gameplay_update::Owner&,Actor&,InventoryUi&,ActionAnimation*);
}
