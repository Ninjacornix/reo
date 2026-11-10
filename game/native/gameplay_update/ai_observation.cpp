#include "update.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
#include "../gameplay_world/linked_models.hpp"
#include "../gameplay_world/target_metrics.hpp"
#include "../transform_math/transform_math.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_update {
namespace ai = gameplay_ai;
namespace nav = gameplay_navigation;
namespace collision = gameplay_collision;
namespace {
struct ThreatPolicy {
    std::array<std::int8_t, 3> distance_hundreds;
    std::int8_t priority;
};
#include "ai_observation_frame_policy.inc"
template <class T> void decrement(T& value) {
    if (value)
        --value;
}
} // namespace
ai::ObservationUpdated Owner::update_ai_observations(const world::actors::EntityId& id,
                                                     const nav::VisibilityRoom& room,
                                                     const gameplay_scene::Records& records,
                                                     const scenario::SceneResources& resources) {
    ai::ObservationUpdated result;
    if (!open())
        return result;
    const auto actor = world_.resolve(id);
    if (!actor || world_.identity(actor->slot) != id || !actor->ai_execution ||
        !actor->navigation_route)
        return result;
    auto& state = *actor->ai_execution;
    const auto reference = world_.primary(0), companion = world_.primary(actor->slot == 1 ? 2 : 1);
    auto& random = world_.session().random;
    try {
        if (refresh_current_navigation_node(id, room).status != nav::QueryStatus::completed)
            return result;
        if (actor->room != world_.room) {
            result.scene_candidates.status = nav::QueryStatus::completed;
            state.forward_wall_ticks = 0;
        } else {
            result.scene_candidates = collect_actor_scene_candidates(id, records);
            if (result.scene_candidates.status != nav::QueryStatus::completed)
                return result;
            bool reset = actor->motion_class == 8;
            if (!ai::observation_blocked(*actor)) {
                const auto angle =
                    transform_math::radians(std::bit_cast<std::uint16_t>(actor->orientation[1]));
                const auto trig = transform_math::sin_cos(angle);
                const auto p = actor->position;
                const collision::Vec3 start{p.x, p.y, p.z},
                    end{p.x + 100.f * trig.sine, p.y + 10.f, p.z + 100.f * trig.cosine};
                auto filter = room.filter;
                filter.include = 0x1ffff;
                filter.exclude = 0;
                filter.dynamic_kind_gate = false;
                result.wall_probe = true;
                const auto wall =
                    collision::trace::any(room.walls, start, end, filter, room.dynamic);
                if (wall.status != collision::trace::SamplingStatus::complete)
                    return result;
                result.wall_hit = bool(wall.hit);
                if (result.wall_hit) {
                    ++state.forward_wall_ticks;
                    if (state.forward_wall_ticks >= 150) {
                        state.forward_wall_ticks = 0;
                        reset = true;
                    }
                } else
                    state.forward_wall_ticks = 0;
            } else
                state.forward_wall_ticks = 0;
            if (reset) {
                ai::set_action(state, 0);
                ai::set_goal(state, 0);
                result.goal_and_action_reset = true;
            }
        }
        state.peer_priority = 0;
        if (!companion)
            return result;
        const auto* metrics = world_.target_metrics().state();
        const auto cached_distance = [&](unsigned from, unsigned to) -> std::optional<float> {
            if (!metrics || from >= 8 || to >= 8 || !metrics->primary_identity[from] ||
                !metrics->primary_identity[to] ||
                metrics->primary_identity[from] != world_.identity(from) ||
                metrics->primary_identity[to] != world_.identity(to))
                return {};
            const auto& value = metrics->primary_pairs[from][to];
            if (!value)
                return {};
            return value->distance;
        };
        if (actor->room == companion->room && !state.companion_hold) {
            if (!companion->ai_execution)
                return result;
            if (companion->ai_execution->companion_hold)
                state.peer_priority = 2;
            else {
                if (!reference)
                    return result;
                const auto own = cached_distance(actor->slot, reference->slot),
                           peer = cached_distance(companion->slot, reference->slot);
                if (!own || !peer)
                    return result;
                state.peer_priority = *own <= *peer ? 0 : 1;
            }
        }
        if (!reference || !reference->ai_execution)
            return result;
        const auto& reference_state = *reference->ai_execution;
        const auto profile =
            state.weight_profile ? ai::weight_profile(*state.weight_profile) : nullptr;
        if ((reference_state.weight_mode || state.weight_mode) && !profile)
            return result;
        for (unsigned i = 0; i < 8; ++i) {
            const auto ref = reference_state.weight_mode ? profile->policy[32 + i] : std::uint8_t{};
            const auto own = state.weight_mode ? profile->policy[40 + i] : std::uint8_t{};
            state.status_weights[i] = std::max(ref, own);
        }
        if (reference->status & 8)
            state.status_weights[0] = 50;
        const auto own_distance = cached_distance(actor->slot, reference->slot);
        if (!own_distance)
            return result;
        if (*own_distance < 1000.f && !state.reference_cooldown &&
            reference_state.reference_signal) {
            const auto event = reference_state.reference_event;
            if (event == 1) {
                if (!(actor->status & 8))
                    result.scheduled_event = 10;
            } else if (event == 9 || event == 10) {
                if (actor->slot == event - 8) {
                    state.companion_hold = 300;
                    if (!companion->ai_execution)
                        return result;
                    companion->ai_execution->companion_hold = 0;
                }
            } else if ((event == 2 || event == 4 || event == 5 || event == 8) &&
                       state.peer_priority != 2) {
                if (event != 5 && state.peer_priority)
                    state.reference_cooldown = 90;
                else {
                    if (event == 4)
                        result.scheduled_event = 6;
                    if (!(actor->status & 8)) {
                        if (event == 2)
                            result.scheduled_event = 5;
                        if (event == 5)
                            result.scheduled_event = 7;
                        if (event == 8)
                            result.scheduled_event = 8;
                    }
                    bool reaction = true;
                    if (event != 5) {
                        const auto admission = ai::admit_reference_reaction(
                            *actor, reference.get(), event == 8 ? 1 : 0, random);
                        if (admission.status != ai::Status::completed)
                            return result;
                        reaction = admission.admitted;
                    }
                    if (reaction) {
                        if (actor->character >= reactive_holds.size())
                            return result;
                        state.reactive_hold = reactive_holds[actor->character];
                        state.observation_flags = 1;
                        if (!profile)
                            return result;
                        const unsigned offset = event == 2   ? 0
                                                : event == 5 ? 8
                                                : event == 4 ? 16
                                                             : 24;
                        std::copy_n(profile->policy.begin() + offset, 8,
                                    state.reactive_weights.begin());
                    }
                    state.reference_cooldown = 90;
                }
            }
        }
        if (!state.reactive_hold)
            state.reactive_weights.fill(0);
        const auto& candidates = metrics->primary_linked_order[actor->slot];
        const auto end = std::find(candidates.begin(), candidates.end(), std::uint8_t(255));
        // The original scans past a physically full list without a sentinel.
        // That can borrow adjacent rows; refuse instead of inventing a result.
        if (end == candidates.end())
            return result;
        state.previous_room_reaction_gate = state.room_reaction_gate;
        state.room_reaction_gate = std::uint8_t(std::distance(candidates.begin(), end));
        unsigned band = 3;
        int priority = 0;
        std::uint8_t selected = 255;
        for (auto candidate = candidates.begin(); candidate != end; ++candidate) {
            const auto slot = *candidate;
            ++result.targets_examined;
            if (slot >= metrics->linked_identity.size())
                return result;
            const auto target_id = world_.linked_models().identity_at(slot);
            if (!target_id || metrics->linked_identity[slot] != target_id)
                return result;
            const auto target = world_.resolve(target_id);
            const auto& metric = metrics->primary_linked[actor->slot][slot];
            if (!target || !target->targeting || !metric || target->slot >= threat_types.size())
                return result;
            if (metric->wall || metric->floor || (target->targeting->flags & 0x200u))
                continue;
            const auto distance = metric->pair.distance;
            if (!std::isfinite(distance) || distance < 0.f || double(distance) >= 2147483648.0)
                return result;
            const auto whole = std::int32_t(distance);
            const auto& policy = threat_policies[threat_types[target->slot]];
            for (unsigned i = 0; i < 3; ++i) {
                if (whole >= int(policy.distance_hundreds[i]) * 100)
                    continue;
                if (i < band || (i == band && policy.priority > priority)) {
                    band = i;
                    priority = policy.priority;
                    selected = slot;
                }
                break;
            }
        }
        state.previous_threat_band = state.threat_band;
        state.threat_slot = selected;
        state.threat_band = std::uint8_t(band);
        for (unsigned i = 0; i < 8; ++i)
            state.combined_weights[i] = std::uint8_t(
                state.base_weights[i] + state.reactive_weights[i] + state.status_weights[i]);
        state.combined_weights[3] = std::uint8_t(state.combined_weights[3] + threat_bonuses[band]);
        if (state.forced_priority != -1) {
            if (!resources.find_inventory_content(actor->inventory, state.forced_content))
                state.forced_priority = -1;
            else {
                if (state.forced_priority < 0 ||
                    std::size_t(state.forced_priority) >= state.combined_weights.size())
                    return result;
                state.combined_weights[std::size_t(state.forced_priority)] = 255;
            }
        }
        if (reference->motion_class != 0x15 || reference->phase != 0x0a ||
            reference->room != actor->room)
            state.reference_request = 0;
        else if (!state.peer_priority) {
            if (!companion->ai_execution)
                return result;
            if (companion->ai_execution->goal != 11 && !state.reference_request)
                state.reference_request = 1;
        }
        if (state.periodic_counter)
            --state.periodic_counter;
        else {
            state.periodic_counter = 60;
            result.scheduled_event = 9;
        }
        if (actor->auxiliary_status & 0x00200000u)
            result.scheduled_event = 0;
        if (actor->auxiliary_status & 0x00400000u)
            result.scheduled_event = 1;
        if (result.scheduled_event &&
            ai::schedule_reaction(state, actor->character, *result.scheduled_event, random)
                    .status != ai::Status::completed)
            return result;
        if (state.reaction_countdown && --state.reaction_countdown == 0) {
            state.reaction = state.pending_reaction;
            state.pending_reaction = 0;
        }
        if (state.reactive_hold)
            --state.reactive_hold;
        else
            state.observation_flags = 0;
        decrement(state.reference_cooldown);
        decrement(state.companion_hold);
        decrement(state.owned_request);
        decrement(state.observation_cooldown);
        if (state.room_memo != actor->room)
            state.room_memo = UINT16_MAX;
        decrement(state.observation_timeout);
        result.status = ai::Status::completed;
        return result;
    } catch (const std::exception&) {
        return result;
    }
}
} // namespace reo::native::gameplay_update
