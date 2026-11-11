#include "enemy_initialization.hpp"
#include "linked_models.hpp"
#include <bit>
#include <new>
#include <stdexcept>

namespace reo::native::gameplay_world {
namespace {
#include "enemy_priority_profiles.inc"
#include "enemy_binding_profiles.inc"
}

bool initialize_enemy_priorities(World& world, const actors::EntityId& id) noexcept {
    const auto actor = world.resolve(id);
    if (!actor) return false;
    const auto mode = std::uint8_t(actor->auxiliary_status);
    if (mode > 2) return true;
    const auto priority = world.session().enemy_descriptors.records()[actor->character].route_seed;
    if (priority >= 8) return false;
    const auto& row = enemy_priorities[8u*mode+priority];
    const bool skip_marker = mode == 1 && row[0] == 4;
    const unsigned first = skip_marker ? 1 : 0;
    if (skip_marker) actor->auxiliary_status = (actor->auxiliary_status&0xffffff00u)|2u;
    actor->gauge_modifier_one = std::uint16_t(row[first]|std::uint16_t(row[first+1])<<8);
    actor->gauge_modifier_two = std::uint16_t(row[first+2]|std::uint16_t(row[first+3])<<8);
    return true;
}

std::optional<std::uint8_t> actor_body_priority(const World& world, const Actor& actor) noexcept {
    if (world.closed()) return {};
    switch (actor.category) {
    case 0:
        if (!actor.ai_control) return 10;
        if (actor.character >= controlled_body_priorities.size()) return {};
        return controlled_body_priorities[actor.character];
    case 1:
        return 30;
    case 2:
        if (actor.slot >= enemy_body_priorities.size()) return {};
        return world.mode == 0 ? offline_enemy_body_priorities[actor.slot] : enemy_body_priorities[actor.slot];
    default:
        return 0;
    }
}

bool bind_enemy_record(World& world, const actors::EntityId& id,
                       const gameplay_scenario::EnemyDescriptor& record) noexcept {
    const auto actor = world.resolve(id);
    if (!actor || actor->category != 2) return false;
    try {
        if (!world.linked_models().physical_slot(id)) return false;
        const auto& parameters = record.parameters34_to40;
        if (parameters[2] >= 8 || parameters[3] >= 8 || parameters[4] >= 8 ||
            parameters[5] >= 8 || record.timing_profile >= 8) return false;
        const auto priority = actor_body_priority(world,*actor);
        if (!priority) return false;
        const auto& definition = File1LinkedModelProfiles{}.definition(actor->slot,record.variant);

        // All admission and throwing operations precede canonical mutation.
        actor->enemy.emplace();
        auto& enemy = *actor->enemy;
        actor->character = record.ordinal;
        actor->current = record.health;
        actor->maximum = record.maximum;
        actor->status = (actor->status&0x00ff00ffu) |
            (std::uint32_t(parameters[6])<<24) | (std::uint32_t(parameters[12])<<8);
        actor->interaction_marker = std::bit_cast<std::uint8_t>(record.actor_marker);
        actor->position = {float(record.position[0]),float(record.position[1]),float(record.position[2])};
        actor->orientation[0] = std::bit_cast<std::int16_t>(std::uint16_t(record.orientation[0]));
        actor->orientation[1] = std::bit_cast<std::int16_t>(std::uint16_t(record.orientation[1]));
        actor->orientation[2] = 0;
        actor->movement_enabled = 1;
        actor->model_height_correction = 0;
        actor->linked_model_variant = record.variant;
        actor->model_pose_class = 0;
        actor->auxiliary_status = (actor->auxiliary_status&0x0000ff00u) |
            (std::uint32_t(record.parameter1f)<<24) | record.parameter48;
        actor->previous_motion_class = record.parameter5;
        enemy.condition = record.condition;
        enemy.parameter_c2b = record.parameter20;
        enemy.parameter_b9d = std::bit_cast<std::uint8_t>(record.parameter21);
        enemy.owner_mode = record.owner_mode;
        enemy.parameter_baa = record.parameter23;
        const auto& ids = record.auxiliary_ids;
        actor->gauge_value = std::uint32_t(ids[0]) | (std::uint32_t(ids[1])<<8) |
            (std::uint32_t(ids[2])<<16) | (std::uint32_t(ids[3])<<24);
        actor->contact.probability_bonus = std::bit_cast<float>(std::uint32_t(ids[4]) |
            (std::uint32_t(ids[5])<<8) | (std::uint32_t(ids[6])<<16) | (std::uint32_t(ids[7])<<24));
        actor->model_variant = std::uint16_t(ids[8] | (std::uint16_t(ids[9])<<8));
        enemy.target_pool = (record.target_selector&0x80u) ? 1 : 0;
        enemy.target_slot = record.target_selector&15u;
        enemy.timer_c2e = 0;
        actor->collision.body_priority = *priority;
        actor->model_scale = {definition.scale,definition.scale,definition.scale};
        if (record.linked_ids[0]) actor->model_scale.x = float(record.linked_ids[0])/100.f;
        if (record.linked_ids[1]) actor->model_scale.y = float(record.linked_ids[1])/100.f;
        if (record.linked_ids[2]) actor->model_scale.z = float(record.linked_ids[2])/100.f;
        actor->motion_subtype = record.parameter31;
        enemy.header_parameter = record.parameter32;
        enemy.phase = 0;
        enemy.behavior_parameters = {parameters[8],parameters[9],parameters[10],parameters[11]};
        enemy.score_masks = {enemy_score_masks_one[parameters[4]],enemy_score_masks_two[parameters[5]]};
        enemy.distance_parameters = {std::bit_cast<float>(enemy_distance_bits[parameters[2]]),
                                     std::bit_cast<float>(enemy_distance_bits[parameters[3]])};
        enemy.score_parameters = {parameters[0],parameters[1]};
        const auto first = world.session().random.request(0)&7u;
        enemy.initial_timer = enemy_initial_timers[8u*record.timing_profile+first];
        const auto second = world.session().random.request(0)&7u;
        actor->frame_value_a = std::bit_cast<std::uint16_t>(enemy_frame_timers[8u*record.timing_profile+second]);
        enemy.control_state = {1,0,0,0};
        enemy.class_flags = enemy_class_flags[actor->slot];
        enemy.parameters_c27_c28 = record.parameters42_to43;
        enemy.parameter_c2a = parameters[7];
        enemy.behavior_mode = 3;
        enemy.target = {actors::ActorReference::Kind::primary,world.selected_actor};
        return true;
    } catch (const std::out_of_range&) {
        return false;
    } catch (const std::bad_alloc&) {
        return false;
    }
}
}
