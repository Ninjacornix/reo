#include "game/native/gameplay_update/update.hpp"
#include "game/native/gameplay_scenario/scene_resources.hpp"
#include "game/native/gameplay_world/linked_models.hpp"
#include "game/native/gameplay_world/target_metrics.hpp"
#include "game/native/animation/model.hpp"
#include "game/native/transform_math/heading.hpp"
#include "reference.hpp"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>

namespace g = reo::native::gameplay_world;
namespace u = reo::native::gameplay_update;
namespace c = reo::native::gameplay_collision;
namespace n = reo::native::gameplay_navigation;
namespace a = reo::native::gameplay_ai;
namespace m = reo::native::transform_math;
namespace s = reo::native::gameplay_scenario;

namespace {
constexpr unsigned primary_base = 0x4a5c30, primary_stride = 0x10e0;
constexpr unsigned linked_base = 0x42eb00, linked_stride = 0xd90;
constexpr unsigned stack = 0x1f00000;
unsigned case_number{}, checks{}, draw_calls{}, scene_calls{}, wall_calls{}, event_calls{};
unsigned wall_hits{}, wall_resets{};
unsigned refused_frames{};
unsigned ai_frames{}, gated_frames{}, refused_actions{};
unsigned off_room_frames{};
unsigned active_waypoint_frames{}, waypoint_contacts{}, waypoint_flags{};
std::array<unsigned, 4> threat_bands{};
std::optional<unsigned> original_event;
bool original_wall_hit{};
bool original_dispatched_goal{}, original_dispatched_action{}, original_off_room_action{};
bool original_active_waypoint{};
const n::VisibilityRoom* active_room{};
std::vector<std::uint8_t> memory(0x2000000);

void check(bool condition, std::source_location location = std::source_location::current()) {
    ++checks;
    if (!condition)
        throw std::runtime_error("Observation case " + std::to_string(case_number) + " line " +
                                 std::to_string(location.line()));
}
template <class Buffer, class Value> void put(Buffer& bytes, unsigned offset, Value value) {
    std::memcpy(bytes.data() + offset, &value, sizeof(value));
}

std::shared_ptr<const reo::native::animation::Skeleton> model_skeleton() {
    std::array<std::byte, 28 + 12 * 84> raw{};
    put(raw, 4, 13u);
    put(raw, 8, std::uint32_t(raw.size()));
    put(raw, 16, 1u);
    put(raw, 20, 16u);
    for (unsigned i = 0; i < 12; ++i) {
        const unsigned record = 28 + 84 * i, node = record + 12;
        put(raw, record, 1u);
        put(raw, record + 4, 1u);
        put(raw, record + 8, 84u);
        put(raw, node, i);
        put(raw, node + 8, i == 0 ? 1u : UINT32_MAX);
        put(raw, node + 12, i > 0 && i < 11 ? i + 1 : UINT32_MAX);
        for (unsigned lane = 0; lane < 3; ++lane)
            put(raw, node + 0x10 + 4 * lane, 1.f);
    }
    return reo::native::animation::Skeleton::import_raw(raw);
}

c::response::Grid clear_grid() {
    std::array<std::byte, 48> raw{};
    put(raw, 8, 4000u);
    put(raw, 12, 4000u);
    put(raw, 16, 1u);
    put(raw, 20, 1u);
    put(raw, 32, 32u);
    put(raw, 36, 40u);
    put(raw, 40, 36u);
    put(raw, 44, UINT32_MAX);
    return c::response::Grid::import(raw);
}

void bind_navigation(g::World& world) {
    std::array<std::uint8_t, 184> raw{};
    put(raw, 0, 0x20030724u);
    put(raw, 4, 12u);
    put(raw, 8, 16u);
    put(raw, 16, 1u);
    raw[20] = 7;
    put(raw, 24, 32u);
    put(raw, 32, 80u);
    put(raw, 36, 88u);
    put(raw, 40, 1u);
    raw[44] = 1;
    put(raw, 60, UINT32_MAX);
    put(raw, 64, UINT32_MAX);
    put(raw, 108, UINT32_MAX);
    n::ImportFailure failure;
    auto asset = n::Asset::read(raw, failure);
    check(bool(asset));
    check(world.session().room_variants.store(7, 0));
    check(world.navigation().bind(std::make_shared<const n::Asset>(std::move(*asset))));
}

struct Notifications final : s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&) noexcept override {
        std::terminate();
    }
    bool changed(const s::StridedFlagChange&) noexcept override {
        std::terminate();
    }
};

void project_actor(std::span<std::uint8_t> bytes, const g::Actor& actor) {
    const auto& state = *actor.ai_execution;
    bytes[3] = actor.slot;
    bytes[0x0a] = actor.phase;
    put(bytes, 0x38, actor.position);
    put(bytes, 0x92, actor.orientation[1]);
    put(bytes, 0x1e2, actor.room);
    put(bytes, 0x534, actor.projectile_contact.normal);
    bytes[0x54f] = actor.motion_class;
    bytes[0xb98] = actor.character;
    put(bytes, 0xba0, actor.status);
    put(bytes, 0xba4, actor.auxiliary_status);
    bytes[0xbd0] = actor.response_lock;
    put(bytes, 0xc84, actor.inventory.carried);
    put(bytes, 0xc88, actor.inventory.storage);
    put(bytes, 0xf78, actor.input.pressed);
    put(bytes, 0xf7c, actor.input.released);
    put(bytes, 0xf80, actor.input.held);
    put(bytes, 0xf84, actor.input.history);
    put(bytes, 0xf90, actor.input.repeat);
    put(bytes, 0xf94, actor.input.repeat_timer);
    put(bytes, 0xf98, actor.input.analog);
    bytes[0xff1] = state.inhibited;
    bytes[0xff2] = state.steering_button_10;
    bytes[0xff3] = state.steering_button_20;
    put(bytes, 0xff4, state.goal);
    put(bytes, 0xff6, state.previous_goal);
    put(bytes, 0xff8, state.action);
    put(bytes, 0xffa, state.previous_action);
    put(bytes, 0xffc, state.goal_phases);
    put(bytes, 0x1000, state.goal_parameters);
    put(bytes, 0x1008, state.action_phases);
    bytes[0x100c] = std::uint8_t(actor.navigation_route->current_node);
    put(bytes, 0x101c, actor.navigation_route->output.route.first_position);
    put(bytes, 0x1038, state.steering_value);
    bytes[0x103a] = state.action_marker;
    put(bytes, 0x1054, actor.navigation_route->action);
    put(bytes, 0x1056, actor.navigation_route->previous_action);
    bytes[0x105a] = actor.navigation_route->completed;
    bytes[0x105b] = actor.navigation_route->selection_mode;
    put(bytes, 0x105c, actor.navigation_route->travel_ticks);
    put(bytes, 0x1060, state.observation_timeout);
    bytes[0x106c] = state.threat_band;
    bytes[0x106d] = state.previous_threat_band;
    bytes[0x106e] = state.threat_slot;
    put(bytes, 0x1070, state.observation_cooldown);
    put(bytes, 0x1072, state.periodic_counter);
    bytes[0x1074] = state.goal_refresh;
    bytes[0x1075] = static_cast<std::uint8_t>(actor.speech.display_style.value_or(0));
    bytes[0x1077] = state.weight_mode;
    put(bytes, 0x107c, state.room_memo);
    bytes[0x107e] = state.room_reaction_gate;
    bytes[0x107f] = state.previous_room_reaction_gate;
    bytes[0x1080] = state.reference_request;
    bytes[0x1081] = state.peer_priority;
    bytes[0x1082] = state.reference_signal;
    bytes[0x1083] = state.observation_flags;
    put(bytes, 0x1084, state.reactive_hold);
    put(bytes, 0x1086, state.reference_cooldown);
    put(bytes, 0x1088, state.companion_hold);
    put(bytes, 0x108a, state.owned_request);
    bytes[0x1098] = actor.speech.remote_request.value_or(0);
    bytes[0x1099] = state.pending_reaction;
    put(bytes, 0x109a, state.reaction_countdown);
    put(bytes, 0x109c, state.forced_priority);
    put(bytes, 0x10a0, state.forced_content);
    put(bytes, 0x10a4, state.forward_wall_ticks);
    bytes[0x10a9] = actor.transient_marker;
    put(bytes, 0x10ac, state.weight_profile ? 0x828a60u + 56u * *state.weight_profile : 0u);
    put(bytes, 0x10b0, state.base_weights);
    put(bytes, 0x10b8, state.reactive_weights);
    put(bytes, 0x10c0, state.status_weights);
    put(bytes, 0x10c8, state.combined_weights);
}

void compare(unsigned seed, const c::response::Grid& grid,
             const std::shared_ptr<const reo::native::animation::Skeleton>& skeleton,
             bool full_ai_frame = false) {
    g::World world({{{1, 2, 4}}, 1, {68, UINT64_MAX}}, std::make_shared<g::Session>());
    Notifications notifications;
    u::Owner owner(world, notifications);
    s::SceneResources resources;
    reo::native::gameplay_scene::Records records;
    const bool active_waypoint = full_ai_frame && seed % 7 != 0 && seed % 5 == 1 && seed < 1024;
    const bool waypoint_wall = active_waypoint && seed % 2 == 1;
    const std::array walls{c::response::Triangle{
        waypoint_wall && seed % 3 != 0 ? 0x10002u : 0x10000u,
        {c::Vec3{100, -100, 450}, c::Vec3{300, -100, 450}, c::Vec3{200, 200, 450}},
        {0, 0, -1},
        450,
    }};
    const bool wall_profile = (!full_ai_frame && seed % 5 == 1) || waypoint_wall;
    const n::VisibilityRoom room{grid,
                                 {},
                                 wall_profile ? std::span<const c::response::Triangle>(walls)
                                              : std::span<const c::response::Triangle>{}};
    world.room = seed % 11 ? 7 : 8;
    bind_navigation(world);
    const unsigned self_slot = 1 + seed % 2, peer_slot = 3 - self_slot;
    for (unsigned slot = 0; slot < 8; ++slot) {
        auto actor = std::make_unique<g::Actor>();
        actor->slot = std::uint8_t(slot);
        actor->room = 7;
        actor->position = {100.f + 50.f * float(slot), 20.f, 400.f};
        actor->ai_execution.emplace();
        actor->navigation_route.emplace();
        check(bool(world.spawn_primary(slot, std::move(actor)).id));
    }
    auto self = world.primary(self_slot), reference = world.primary(0),
         peer = world.primary(peer_slot);
    self->active = true;
    self->position.x = 200.f;
    peer->position.x = (seed / 2 % 3 == 0) ? 180.f : 240.f;
    if (seed / 8 % 7 == 0)
        reference->position.x = 1200.f;
    self->model = std::make_shared<reo::native::animation::Instance>(skeleton);
    auto basis = m::identity();
    basis[3] = {self->position.x, self->position.y, self->position.z, 1.f};
    self->model->rebuild(basis);
    self->motion_class = std::array<std::uint8_t, 6>{0, 8, 5, 0x1a, 0x3b, 0x21}[seed / 8 % 6];
    self->orientation[1] = wall_profile ? 0 : std::int16_t(seed * 131u);
    self->character = std::uint8_t(seed / 13 % 8);
    self->status = seed / 71 % 2 ? 8 : 0;
    self->auxiliary_status = (seed / 29 % 4) << 21;
    reference->status = seed / 37 % 2 ? 8 : 0;
    reference->motion_class = seed / 17 % 2 ? 0x15 : 0;
    reference->phase = seed / 19 % 2 ? 10 : 0;
    reference->speech.display_style = std::int8_t(seed / 2 % 13);
    reference->ai_execution->reference_signal = seed / 101 % 5 ? 1 : 0;
    reference->ai_execution->weight_mode = std::uint8_t(seed / 41 % 2);
    peer->ai_execution->companion_hold = seed / 7 % 5 == 0 ? 2 : 0;
    peer->ai_execution->goal = seed / 23 % 2 ? 11 : 3;

    auto& state = *self->ai_execution;
    a::select_weight_profile(state, seed % 20);
    state.goal = 15;
    state.action = 8;
    state.goal_phases.fill(19);
    state.action_phases.fill(9);
    state.goal_parameters.fill(333);
    state.action_marker = 11;
    state.weight_mode = std::uint8_t(seed / 59 % 2);
    state.room_memo = seed / 3 % 2 ? 7 : 9;
    state.room_reaction_gate = std::uint8_t(seed / 79 % 2);
    state.reference_request = std::uint8_t(seed / 53 % 3);
    state.periodic_counter = seed / 5 % 9 == 0 ? 0 : 60;
    state.reference_cooldown = seed / 43 % 5 == 0 ? 1 : 0;
    state.reactive_hold = std::uint16_t(seed / 31 % 3);
    state.reactive_weights.fill(231);
    state.combined_weights.fill(121);
    state.observation_flags = 7;
    state.threat_band = 2;
    state.threat_slot = 9;
    state.pending_reaction = 4;
    state.reaction_countdown = std::uint16_t(seed / 11 % 3);
    state.forward_wall_ticks = 148 + seed % 4;
    state.owned_request = std::uint16_t(seed % 3);
    state.observation_cooldown = 1;
    state.observation_timeout = 2;
    state.forced_priority = seed / 67 % 3 == 0 ? -1 : std::int32_t(seed % 8);
    state.forced_content = 0x131;
    const auto gate_bits = full_ai_frame && seed % 3 == 0 ? seed / 3 % 32 : 0u;
    const bool session_gate = (gate_bits & 1) != 0;
    if (full_ai_frame) {
        self->motion_class = seed % 4 == 0 ? 0x3b : 0;
        self->navigation_route->selection_mode = seed == 1024 || seed % 7 == 0 ? 1 : 0;
        self->transient_marker = self->navigation_route->selection_mode ? 0 : 1;
        self->status = gate_bits & 16 ? 0x20 : 0;
        self->response_lock = gate_bits & 4 ? 2 : 0;
        world.session().suppress_hits = (gate_bits & 8) != 0;
        self->input = {13, 17, 21, {25, 33, 42}, 53, -7, {1, 2, 3, 4, 5, 6, 7, 8}};
        state.inhibited = gate_bits & 2 ? 2 : 0;
        state.steering_value = 0x1234;
        state.steering_button_10 = 3;
        state.steering_button_20 = 2;
        self->speech.remote_request = 199;
        state.goal = std::array<std::uint16_t, 3>{0, 6, 14}[seed % 3];
        const bool waypoint = seed == 1024 || (self->navigation_route->selection_mode && seed % 3 == 1);
        state.action = waypoint ? 2 : std::uint16_t(seed / 7 % 2);
        self->navigation_route->action = seed == 1024 ? 12 : 13;
        self->navigation_route->travel_ticks = seed == 1024 ? 0 : 57;
        state.goal_refresh = self->motion_class == 0x3b && seed % 17 == 0 ? 1 : 0;
        state.goal_phases[0] = 1;
        state.goal_parameters[0] = std::uint16_t(seed % 3);
        state.goal_parameters[1] = 180;
        state.action_phases[0] = waypoint ? 1 : std::uint8_t(seed % 2);
        state.forward_wall_ticks = seed % 4;
        if (active_waypoint) {
            state.goal = seed % 3 ? 0 : 6;
            state.action = 2;
            state.action_marker = seed % 3 ? 0 : 11;
            self->navigation_route->action = seed % 3 ? 13 : 0x7700;
            self->navigation_route->previous_action = 0x4500;
            self->navigation_route->completed = seed % 13 == 1 ? 1 : 0;
            self->navigation_route->output.route.first_position = {200, 30, 500};
            self->projectile_contact.normal = {0, 0, seed % 11 == 1 ? 1.f : -1.f};
        }
    }
    self->inventory.storage[17] = 4;
    s::SceneDescriptor descriptor;
    descriptor.attachment_id = seed / 89 % 2 ? 0x131 : 0x132;
    descriptor.authored_id = 0x131;
    check(bool(resources.load(4, descriptor)));
    put(memory, 0x3c5630 + 4 * 60 + 6, descriptor.attachment_id);

    const unsigned target_count = seed == 4096 ? 50 : seed % 127 == 0 ? 49 : seed % 17 == 0 ? 0 : 4;
    const float gap = float(seed % 601);
    for (unsigned i = 0; i < target_count; ++i) {
        auto id = world.linked_models().allocate(false).id;
        auto target = world.resolve(id);
        check(bool(target));
        const auto slot = world.linked_models().physical_slot(id).value();
        target->active = true;
        target->room = 7;
        target->slot = std::uint8_t((i * 7 + seed) % 64);
        target->position = {self->position.x + float(i * 17) + gap, 20.f, 400.f};
        target->targeting = g::TargetingState{seed / (i + 5) % 3 == 0 ? 0x200u : 0u, false};
        const auto offset = linked_base + slot * linked_stride;
        memory[offset + 3] = target->slot;
        memory[offset + 6] = slot;
        put(memory, offset + 0xc94, target->targeting->flags);
    }
    check(world.target_metrics().rebuild({grid, grid, {}, {}}).status ==
          g::TargetMetricStatus::completed);
    const auto& cache = *world.target_metrics().state();
    for (unsigned i = 0; i < 8; ++i) {
        for (unsigned j = 0; j < 8; ++j)
            put(memory, 0x3b4e40 + 64 * i + 8 * j, cache.primary_pairs[i][j]->distance);
        put(memory, 0x3b2e10 + 50 * i, cache.primary_linked_order[i]);
        for (unsigned j = 0; j < 50; ++j)
            if (const auto& value = cache.primary_linked[i][j]) {
                const unsigned offset = 0x3b41c0 + 400 * i + 8 * j;
                put(memory, offset, value->pair.distance);
                memory[offset + 6] = value->wall;
                memory[offset + 7] = value->floor;
            }
        auto bytes = std::span(memory).subspan(primary_base + primary_stride * i, primary_stride);
        std::fill(bytes.begin(), bytes.end(), 0xa5);
        project_actor(bytes, *world.primary(i));
    }
    const auto source_before = std::vector<std::uint8_t>(
        memory.begin() + primary_base, memory.begin() + primary_base + 8 * primary_stride);
    const auto initial_random = std::uint16_t(seed * 67u);
    world.session().random.restore({initial_random, 4321, 89});
    put(memory, 0x3244b0, initial_random);
    put(memory, 0x3244b8, std::uint16_t(4321));
    put(memory, 0x3243dc, world.room);
    put(memory, 0x83e530, 23u);
    put(memory, 0x83e558 + 7 * 164, 1u);
    memory[0x3243d2] = session_gate ? 2 : 0;
    memory[0x4bae8d] = world.session().suppress_hits;
    const c::Vec3 camera_position{0, 80, 400}, camera_target{100, 0, 600};
    put(memory, 0x324138, camera_position);
    put(memory, 0x324144, camera_target);
    const auto camera_heading =
        m::direction_turn(camera_target.x - camera_position.x, camera_target.z - camera_position.z);
    if (seed == 4097)
        world.target_metrics().invalidate();
    a::ObservationUpdated result;
    if (full_ai_frame) {
        const auto frame = owner.run_ai_frame(world.identity(self_slot), session_gate, room,
                                              records, resources, camera_heading);
        if (seed == 1024) {
            check(frame.status == u::AiFrameStatus::action_unavailable &&
                  frame.observation.status == a::Status::completed &&
                  frame.goal.status == a::Status::completed && self->motion_class == 3);
            ++refused_actions;
            return;
        }
        check(frame.status == (gate_bits ? u::AiFrameStatus::gated : u::AiFrameStatus::completed));
        result = frame.observation;
        ++ai_frames;
        if (gate_bits)
            ++gated_frames;
        else if (self->navigation_route->selection_mode)
            ++off_room_frames;
        else if (active_waypoint) {
            ++active_waypoint_frames;
            if (state.steering_button_20 == 1)
                ++waypoint_flags;
        }
    } else {
        result = owner.update_ai_observations(world.identity(self_slot), room, records, resources);
    }
    if (seed >= 4096) {
        check(result.status == a::Status::unavailable);
        check(state.observation_timeout == 2 && result.targets_examined == 0);
        ++refused_frames;
        return;
    }
    if (!gate_bits) {
        check(result.status == a::Status::completed);
        check(result.targets_examined == target_count);
        if (!full_ai_frame)
            ++threat_bands.at(state.threat_band);
    }
    auto expected = source_before;
    for (unsigned i = 0; i < 8; ++i)
        project_actor(std::span(expected).subspan(i * primary_stride, primary_stride),
                      *world.primary(i));
    R5900Context context;
    PS2Runtime runtime;
    context.pc = full_ai_frame ? 0x812460 : 0x812540;
    SET_GPR_U32(&context, 4, primary_base + self_slot * primary_stride);
    SET_GPR_U32(&context, 29, stack);
    SET_GPR_U32(&context, 31, 0x100);
    original_event.reset();
    original_wall_hit = false;
    original_dispatched_goal = false;
    original_dispatched_action = false;
    original_off_room_action = false;
    original_active_waypoint = false;
    active_room = &room;
    const auto previous_walls = wall_calls;
    original_transform_port(memory.data(), &context, &runtime);
    active_room = nullptr;
    check(context.pc == 0x100 && GPR_U32(&context, 29) == stack);
    check(result.scheduled_event == original_event);
    check(result.wall_probe == (previous_walls != wall_calls));
    check(result.wall_hit == original_wall_hit);
    if (result.wall_hit) {
        ++wall_hits;
        if (result.goal_and_action_reset)
            ++wall_resets;
    }
    check((gate_bits ? 23u : result.scene_candidates.count) ==
          transform_read<std::uint32_t>(memory.data(), 0x83e530));
    check(original_dispatched_goal == (full_ai_frame && !gate_bits));
    check(original_dispatched_action == (full_ai_frame && !gate_bits));
    check(original_off_room_action == (full_ai_frame && !gate_bits && self->navigation_route->selection_mode));
    check(original_active_waypoint == (active_waypoint && !gate_bits));
    check(world.session().random.state().primary ==
          transform_read<std::uint16_t>(memory.data(), 0x3244b0));
    check(world.session().random.state().secondary ==
          transform_read<std::uint16_t>(memory.data(), 0x3244b8));
    const auto mismatch =
        std::mismatch(expected.begin(), expected.end(), memory.begin() + primary_base);
    if (mismatch.first != expected.end()) {
        const auto offset = std::distance(expected.begin(), mismatch.first);
        std::cerr << "Actor slot " << offset / primary_stride << " offset " << std::hex
                  << offset % primary_stride << std::dec << " native " << unsigned(*mismatch.first)
                  << " original " << unsigned(*mismatch.second) << '\n';
        check(false);
    }
}
} // namespace

void original_transform_port(std::uint8_t* memory, R5900Context* context, PS2Runtime* runtime) {
    const unsigned arg = GPR_U32(context, 4), other = GPR_U32(context, 5);
    if (context->pc == 0x1aec80)
        ++draw_calls;
    if (context->pc == 0x813330)
        original_dispatched_goal = true;
    if (context->pc == 0x81a720 || context->pc == 0x81beb0)
        original_dispatched_action = true;
    if (context->pc == 0x81beb0)
        original_off_room_action = true;
    if (context->pc == 0x81a880) {
        original_active_waypoint = true;
        const auto return_pc = GPR_U32(context, 31);
        o9_0081A880_0x81a880(memory, context, runtime);
        check(context->pc == 0x81a8f0 && GPR_U32(context, 31) == return_pc);
        original_transform_port(memory, context, runtime);
        return;
    }
    if (context->pc == 0x8130d0) {
        if (!original_dispatched_goal)
            original_event = other;
        ++event_calls;
    }
    switch (context->pc) {
#include "dispatch.inc"
        case 0x815bc0:
            check(other == arg + 0x38 && GPR_U32(context, 6) == 0);
            SET_GPR_U32(context, 2, 0); // Single admitted graph node.
            break;
        case 0x819bc0:
            check(other == 0x83e330);
            SET_GPR_U32(context, 2, 0); // The fixture has no scene records.
            ++scene_calls;
            break;
        case 0x191f80:
            context->f[0] = m::radians(std::uint16_t(arg));
            break;
        case 0x370140: {
            check(other == primary_base + 0x38 || other == arg + 0x101c - 0x38);
            const auto from = transform_read<g::Position>(memory, arg);
            const auto to = transform_read<g::Position>(memory, other);
            SET_GPR_U32(context, 2, m::position_direction_turn(to.x - from.x, to.z - from.z));
            break;
        }
        case 0x376e70: {
            check((arg == 0x324138 && other == 0x324144) ||
                  (other >= primary_base + 0x534 &&
                   (other - primary_base - 0x534) % primary_stride == 0));
            const auto from = transform_read<c::Vec3>(memory, arg);
            const auto to = transform_read<c::Vec3>(memory, other);
            SET_GPR_U32(context, 2, m::direction_turn(to.x - from.x, to.z - from.z));
            break;
        }
        case 0x191bc0: {
            const auto trig = m::sin_cos(context->f[12]);
            check(transform_read<float>(memory, arg) == 0.f &&
                  transform_read<float>(memory, arg + 8) == 100.f);
            transform_write(memory, arg, 100.f * trig.sine);
            transform_write(memory, arg + 8, 100.f * trig.cosine);
            break;
        }
        case 0x579980: {
            check(active_room && GPR_U32(context, 6) == 0x1ffff && GPR_U32(context, 7) == 0);
            auto filter = active_room->filter;
            filter.include = 0x1ffff;
            filter.exclude = 0;
            filter.dynamic_kind_gate = false;
            const auto hit =
                c::trace::any(active_room->walls, transform_read<c::Vec3>(memory, arg),
                              transform_read<c::Vec3>(memory, other), filter, active_room->dynamic);
            check(hit.status == c::trace::SamplingStatus::complete);
            original_wall_hit = bool(hit.hit);
            SET_GPR_U32(context, 2, original_wall_hit);
            ++wall_calls;
            break;
        }
        case 0x5795e0: {
            check(active_room && GPR_U32(context, 8) == UINT32_MAX && GPR_U32(context, 9) == 0);
            auto filter = active_room->filter;
            filter.include = UINT32_MAX;
            filter.exclude = 0;
            filter.dynamic_kind_gate = false;
            const auto hit = c::trace::shorten(
                active_room->walls, transform_read<c::Vec3>(memory, arg),
                transform_read<c::Vec3>(memory, other), filter, active_room->dynamic);
            check(hit.status == c::trace::SamplingStatus::complete);
            SET_GPR_U32(context, 2, bool(hit.hit));
            if (hit.hit) {
                transform_write(memory, GPR_U32(context, 6), hit.hit->point);
                transform_write(memory, GPR_U32(context, 7), hit.hit->normal);
                transform_write(memory, GPR_U32(context, 10), hit.hit->type);
                ++waypoint_contacts;
            }
            break;
        }
        case 0x107c68:
            check(other == 0 && GPR_U32(context, 6) == 8 && arg + 8 < 0x2000000);
            std::memset(memory + arg, 0, 8);
            SET_GPR_U32(context, 2, arg);
            break;
        default:
            throw std::runtime_error("Undeclared original observation dependency " +
                                     std::to_string(context->pc));
    }
    context->pc = GPR_U32(context, 31);
}

int main(int argc, char** argv) try {
    check(argc == 2);
    std::ifstream image(argv[1], std::ios::binary);
    check(bool(image));
    image.read(reinterpret_cast<char*>(memory.data() + 0x810000), 113152);
    check(image.gcount() == 113152);
    const auto grid = clear_grid();
    const auto skeleton = model_skeleton();
    for (; case_number < 4096; ++case_number)
        compare(case_number, grid, skeleton);
    compare(4096, grid, skeleton);
    compare(4097, grid, skeleton);
    for (unsigned seed = 0; seed < 1025; ++seed, ++case_number)
        compare(seed, grid, skeleton, true);
    check(wall_hits > wall_resets && wall_resets > 0);
    check(std::ranges::all_of(threat_bands, [](unsigned count) { return count > 0; }));
    std::cout << "{\"cases\":4096,\"checks\":" << checks << ",\"draw_calls\":" << draw_calls
              << ",\"scene_calls\":" << scene_calls << ",\"wall_calls\":" << wall_calls
              << ",\"wall_hits\":" << wall_hits << ",\"wall_resets\":" << wall_resets
              << ",\"event_calls\":" << event_calls << ",\"refused_frames\":" << refused_frames
              << ",\"threat_bands\":[" << threat_bands[0] << ',' << threat_bands[1] << ','
              << threat_bands[2] << ',' << threat_bands[3] << "],\"ai_frames\":" << ai_frames
              << ",\"gated_frames\":" << gated_frames << ",\"refused_actions\":" << refused_actions
              << ",\"off_room_frames\":" << off_room_frames
              << ",\"active_waypoint_frames\":" << active_waypoint_frames
              << ",\"waypoint_contacts\":" << waypoint_contacts
              << ",\"waypoint_flags\":" << waypoint_flags << "}\n";
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
}
