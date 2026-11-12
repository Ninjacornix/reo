#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
// Apply only to a fresh, value-initialized Actor. Original cleared records
// have zero for these fields whose ordinary native defaults are nonzero.
// Resolved geometry/alignment/model capabilities remain absent until supplied.
inline void initialize_cleared_actor_defaults(Actor& actor)noexcept{
    actor.motion_rate=0;actor.model_scale={};actor.motion_multiplier=0;
    actor.surface_kind=actor.surface_material=0;actor.surface_normal={};
    actor.collision.basis.x={};actor.collision.basis.y={};actor.collision.basis.z={};actor.collision.basis.translation={};
    actor.contact.recipient={0,0};actor.contact.related_recipient={0,0};actor.contact.source_related={0,0};actor.contact.damage_scale=0;
    actor.gauge_value=0;actor.interaction_resource=0;actor.aim_pitch_adjustment=0;actor.aim_target_pitch=0;actor.aim_target_index=0;
    // Actual66A730/5F1290/682D10 clears cover61AAA0 history, FAC and CE2.
    // Generic Actor construction does not establish either source capability.
    actor.secondary_pose_history=SecondaryPoseHistory{};actor.secondary_pose_category_override=0;
    actor.surface_transition_flags=0;
    actor.contact_style_discriminator=0;
    actor.speech.dialogue_delay=0;actor.speech.display_style=0;
    actor.speech.partner_characters=std::array<std::int8_t,4>{};
}
}
