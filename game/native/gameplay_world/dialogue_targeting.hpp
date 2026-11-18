#pragma once
#include "dialogue_pool.hpp"
namespace reo::native::gameplay_world {
// Complete6B88E0, preserving the original nearest-candidate order and lock
// semantics on the same canonical actor's DC2/DC5/DC7 speech fields.
DialogueStatus update_dialogue_target(World&,const actors::EntityId&)noexcept;
}
