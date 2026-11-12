#pragma once
#include "dialogue_pool.hpp"
namespace reo::native::gameplay_world {
struct DialoguePartnersRebuilt {
    DialogueStatus status{DialogueStatus::completed};
    std::size_t written{};
};
// Source6B819C..8218, after6B8130 has admitted the primary list-build phase.
// The full request/cooldown/response worker retains its earlier guards.
DialoguePartnersRebuilt rebuild_dialogue_partner_characters(World&,const actors::EntityId&)noexcept;
}
