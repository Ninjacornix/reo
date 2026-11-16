// Hybrid swap: ordinary room camera o2 0x5BED30 and record import o2 0x5BE3E0.
//
// Phase 1 of the hybrid plan: guest memory stays the source of truth. Every
// call projects the guest camera header, parameters, display state, actor
// position, model visibility, hide flags and fog selection into the native
// Stage 4 objects, runs gameplay_scenario::RoomCamera, then either compares
// (shadow) or writes the same outputs back and replays the renderer commands
// through the original 0x1AF780 (native).
//
// The guest layout below is the one exercised by
// tools/native_reconstruction/room_camera_tests.cpp (166 rooms / 1,001 records)
// and docs/SYMBOLS_SCRIPT_VM.md / SYMBOLS_CALLBACK_*.md (header byte roles).
#include "room_camera_adapter.hpp"
#include "game/native/gameplay_scenario/room_camera.hpp"
#include "game/native/gameplay_scenario/room_camera_records.hpp"
#include "game/native/gameplay_scenario/sequence_control.hpp"
#include "game/native/gameplay_scenario/scene_models.hpp"
#include "game/native/gameplay_scenario/fog.hpp"
#include "game/native/gameplay_world/world.hpp"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "source_instruction_access.hpp"
#include "../reo_pad_tap.h"
#include "runtime/gs/performance.h"
#include <algorithm>
#include <array>
#include <atomic>
#include <bit>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <memory>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <type_traits>
#include <vector>

void o2_005BE3E0_0x5be3e0(std::uint8_t*, R5900Context*, PS2Runtime*);
void o2_005BED30_0x5bed30(std::uint8_t*, R5900Context*, PS2Runtime*);
void sub_001AF780_0x1af780(std::uint8_t*, R5900Context*, PS2Runtime*);
void o2_005795E0_0x5795e0(std::uint8_t*, R5900Context*, PS2Runtime*);
// SDK patch 0132 (Win32ModalRender): mouse look capture on the game window.
void ps2HostSetMouseLook(bool enabled);
bool ps2HostTakeMouseDelta(int* dx, int* dy, int* wheel);
unsigned ps2HostMouseButtons();

namespace reo::native::room_camera_adapter {
namespace {
namespace s = reo::native::gameplay_scenario;
namespace w = reo::native::gameplay_world;
namespace t = reo::native::transform_math;

// Room camera header (5BE3E0 clears 0x34 bytes + 32 records of 0x198).
constexpr std::uint32_t header_at = 0x3dddb0, records_at = header_at + 0x34, stride = 0x198, record_count = 32;
constexpr std::uint32_t header_bytes = 0x34 + record_count * stride;
// Camera parameters / display state.
constexpr std::uint32_t viewport_at = 0x324120, params_at = 0x324138, params_end = 0x324190, view_at = 0x3240e0;
constexpr std::uint32_t perspective_at = 0x70003f00, scaled_at = 0x294d00, first_composite_at = 0x294d40,
                        second_composite_at = 0x294d80;
// Projection context borrowed from the display owner.
constexpr std::uint32_t horizontal_at = 0x2941a8, vertical_at = 0x2941b0, width_at = 0x2941c8, height_at = 0x2941d0,
                        first_transform_at = 0x70003f80, second_transform_at = 0x294dc0;
constexpr std::uint32_t mode_at = 0x3243cf, visibility_at = 0x49eef0 + 0x8a0, model_count_at = 0x49f762,
                        hide_at = 0x4b9d10, fog_selected_at = 0x3240bd;
constexpr std::uint32_t actors_at = 0x4a5c30, actor_stride = 0x10e0, actor_position = 0x38, primary_actors = 8;
// o2 overlay slot (see recomp/config/output_ovl/o2/register_o2.cpp).
constexpr std::uint32_t overlay_base = 0x570000, overlay_magic = 0x336F574D, overlay_id_offset = 4, overlay_o2 = 3;
constexpr std::uint32_t camera_entry = 0x5bed30, import_entry = 0x5be3e0, renderer_command = 0x1af780;
constexpr unsigned op_viewport = 24, op_view = 22;
constexpr std::uint32_t actor_yaw = 0x92;  // signed halfword (save_actor_position_and_yaw, o2 0x667370)

// Third-person camera mod on the native room camera (native mode only).
//
// REO_CAMERA_MOD=tps enables it. The camera orbits a pivot above the primary
// actor; the right stick turns it (the game then sees a centred right stick),
// R3 recentres behind the actor, R1 (aim) switches to the aim rig and turns the
// actor to the camera yaw. The game's own analog movement (6621F0) is relative
// to the published camera eye/aim, so the left stick walks relative to this
// camera. The view is pulled in front of room walls with the game's segment test
// (o2 0x5795E0). Scripted camera selections (doors, events) are left to the game.
//
// Tuning: REO_CAMERA_TPS="key=value,..." with keys distance, pivot, pitch, side,
// yaw_speed, pitch_speed, invert_y, turn_sign, aim_distance, aim_side, aim_pivot,
// smoothing, pitch_min, pitch_max, mouse_sens (degrees per mouse count),
// zoom_step. REO_CAMERA_MOUSE=0 disables mouse look (on by default with tps):
// the cursor is hidden and kept in the window while the game has focus, C frees
// it, a click captures it again; right button aims (R1), left button is cross,
// the wheel zooms. REO_CAMERA_TPS_LOG=1 prints samples.
//
// Measured (2026-11-16): +Y is up; actor yaw (signed halfword +0x92) is 0x10000
// per turn and forward = (sin, 0, cos) of it.
struct ThirdPerson {
    bool enabled{}, log{}, mouse{true}, first_person{};
    float mouse_sens{0.12f}, zoom_step{25.f};
    // First person: eye height above the actor's feet and how far ahead of the face.
    float eye_height{160.f}, eye_ahead{30.f};
    // Aim height from camera pitch: above +down degrees aims low, below -up aims high.
    float aim_up{-12.f}, aim_down{16.f};
    // Moving while aiming (the original game stands still): units per second,
    // body radius kept from walls; strafe=0 turns it off.
    float strafe{1.f}, strafe_speed{75.f}, body_radius{28.f};
    float distance{300.f}, pivot{150.f}, pitch{10.f}, side{35.f};
    float yaw_speed{4.f}, pitch_speed{3.f}, invert_y{0.f}, turn_sign{1.f};
    float aim_distance{150.f}, aim_side{45.f}, aim_pivot{155.f};
    float smoothing{0.45f}, pitch_min{-35.f}, pitch_max{55.f};
    static ThirdPerson from_environment() {
        ThirdPerson t;
        if (const char* mod = std::getenv("REO_CAMERA_MOD")) t.enabled = !std::strcmp(mod, "tps");
        if (const char* log = std::getenv("REO_CAMERA_TPS_LOG")) t.log = !std::strcmp(log, "1");
        if (const char* mouse = std::getenv("REO_CAMERA_MOUSE")) t.mouse = std::strcmp(mouse, "0") != 0;
        if (const char* view = std::getenv("REO_CAMERA_VIEW")) t.first_person = !std::strcmp(view, "first");
        if (const char* tune = std::getenv("REO_CAMERA_TPS")) {
            const struct { const char* key; float* value; } keys[] = {
                {"distance", &t.distance}, {"pivot", &t.pivot}, {"pitch", &t.pitch}, {"side", &t.side},
                {"yaw_speed", &t.yaw_speed}, {"pitch_speed", &t.pitch_speed}, {"invert_y", &t.invert_y},
                {"turn_sign", &t.turn_sign}, {"aim_distance", &t.aim_distance}, {"aim_side", &t.aim_side},
                {"aim_pivot", &t.aim_pivot}, {"smoothing", &t.smoothing}, {"pitch_min", &t.pitch_min},
                {"pitch_max", &t.pitch_max}, {"mouse_sens", &t.mouse_sens}, {"zoom_step", &t.zoom_step},
                {"eye_height", &t.eye_height}, {"eye_ahead", &t.eye_ahead}, {"aim_up", &t.aim_up},
                {"aim_down", &t.aim_down}, {"strafe", &t.strafe}, {"strafe_speed", &t.strafe_speed},
                {"body_radius", &t.body_radius}};
            const char* at = tune;
            while (*at) {
                const char* end = std::strchr(at, ',');
                const std::size_t length = end ? std::size_t(end - at) : std::strlen(at);
                for (const auto& k : keys) {
                    const auto n = std::strlen(k.key);
                    if (length > n && !std::strncmp(at, k.key, n) && at[n] == '=') *k.value = float(std::atof(at + n + 1));
                }
                at += length; if (*at == ',') ++at;
            }
        }
        return t;
    }
};
struct ThirdPersonState {
    bool active{}, smoothed{};
    float yaw{}, pitch{};  // radians
    t::Vector eye{}, aim{};
    std::uint64_t imports_seen{};
    std::uint16_t previous_pressed{};
    float zoom{};  // added to the rig distance by the mouse wheel
    bool first_person{}, view_initialised{};
    std::uint64_t view_switches{}, first_person_frames{}, strafe_frames{}, strafe_blocked{};
    std::uint64_t frames{}, yielded{}, collisions{}, recentres{}, aim_frames{}, mouse_frames{};
};
constexpr float yaw_turn = 6.28318530718f / 65536.f;  // actor yaw units (measured)
constexpr float degrees = 0.01745329252f;

struct Event {
    unsigned op{};
    s::CameraViewport viewport{};
    s::CameraProjectionMatrices projection{};
    t::Matrix view{};
    s::CameraParameters parameters{};  // native: parameters at publication time
};
struct Mismatch { const char* field; unsigned index; std::uint32_t native, original; };
struct Counts {
    std::uint64_t calls{}, compared{}, mismatched{}, refused{}, native_completed{}, fallback{}, imports{},
        import_refused{}, no_records{}, unexpected_write_calls{};
    std::uint64_t refused_projection{}, refused_unavailable{}, refused_numeric{};
    bool first_refusal_logged{};
};
struct WriteRange { std::uint32_t at{}; std::uint32_t mask{}; std::uint64_t hits{}; };  // 32-byte block, byte mask

class Guest {
public:
    Guest(std::uint8_t* ram) : ram_(ram) {}
    void read(std::uint32_t at, void* data, std::size_t bytes) const { access(at, data, bytes, false); }
    void write(std::uint32_t at, const void* data, std::size_t bytes) const {
        access(at, const_cast<void*>(data), bytes, true);
    }
    template <class T> T get(std::uint32_t at) const { T value{}; read(at, &value, sizeof value); return value; }
    template <class T> void put(std::uint32_t at, const T& value) const { write(at, &value, sizeof value); }
private:
    void access(std::uint32_t at, void* data, std::size_t bytes, bool writing) const {
        if (at >= PS2_SCRATCHPAD_BASE && at - PS2_SCRATCHPAD_BASE <= PS2_SCRATCHPAD_SIZE - bytes) {
            auto* pad = ps2GetScratchpadHostPtr();
            if (!pad) throw std::runtime_error("Room camera adapter: scratchpad unavailable");
            auto* p = pad + (at - PS2_SCRATCHPAD_BASE);
            if (writing) std::memcpy(p, data, bytes); else std::memcpy(data, p, bytes);
            return;
        }
        const auto physical = at & 0x1fffffffu;
        if (physical >= 0x02000000u || bytes > 0x02000000u - physical)
            throw std::runtime_error("Room camera adapter: guest range refused");
        if (writing) reo_source_instrumentation::copyBytesForBank(ram_, ram_ + physical, data, bytes);
        else reo_source_instrumentation::copyBytesForBank(ram_, data, ram_ + physical, bytes);
    }
    std::uint8_t* ram_;
};

class Binding;
Binding* binding = nullptr;           // one runtime per process
thread_local std::vector<Event>* recording = nullptr;  // original 0x1AF780 observations (shadow)

class Binding final : public PS2Runtime::ExternalWorker {
public:
    class Sink final : public s::CameraDisplaySink {
    public:
        explicit Sink(Binding& owner) : owner_(owner) {}
        void viewport(const s::CameraViewport& value, const s::CameraProjectionMatrices& matrices) override {
            Event e; e.op = op_viewport; e.viewport = value; e.projection = matrices; e.parameters = owner_.parameters;
            owner_.events.push_back(e);
        }
        void view(const t::Matrix& matrix) override {
            Event e; e.op = op_view; e.view = matrix; e.parameters = owner_.parameters;
            owner_.events.push_back(e);
        }
    private:
        Binding& owner_;
    };

    Binding(PS2Runtime& runtime, Mode mode) : mode(mode), runtime(&runtime), ram(runtime.memory().getRDRAM()) {
        w::Profile profile; profile.layouts.push_back({});
        world = std::make_unique<w::World>(profile, std::make_shared<w::Session>());
        for (unsigned i = 0; i < primary_actors; ++i) {
            auto actor = std::make_unique<w::Actor>(); actor->active = true; actor->slot = std::uint8_t(i);
            if (!world->spawn_primary(i, std::move(actor)).id) throw std::runtime_error("Room camera adapter: actor setup");
        }
        if (mode == Mode::shadow_writes) { before.resize(0x02000000u); renderer_before.resize(0x02000000u); }
    }

    Mode mode;
    PS2Runtime* runtime;
    std::uint8_t* ram;
    std::recursive_mutex operation;
    std::atomic<bool> stopped{};bool emitted{};
    void requestStop() noexcept override { stopped.store(true); }
    bool join() noexcept override { requestStop(); std::lock_guard lock(operation); if (!emitted) { emitted = true; dump(); } return true; }
    Counts counts;
    std::array<Mismatch, 24> mismatches{};
    std::uint64_t mismatch_rows{};
    std::vector<WriteRange> unexpected;
    std::vector<std::uint8_t> before, renderer_before;
    std::vector<std::uint32_t> renderer_blocks;
    static constexpr std::uint32_t watch_at = 0x2b0800, watch_bytes = 0x100;
    std::array<std::uint8_t, watch_bytes> watch_after{};bool watch_valid{};
    std::uint64_t watch_changed_between_calls{}, watch_checks{};  // 32-byte blocks written inside 0x1AF780 this call

    std::shared_ptr<const s::RoomCameraRecords> records;
    bool records_installed{};
    std::unique_ptr<w::World> world;
    s::SequenceControl sequences;
    s::CameraParameters parameters;
    s::CameraDisplayState display;
    s::SceneModels models{s::SceneModelState{}, s::RoomModelRemap{}};
    s::CameraProjectionContext projection{};
    ThirdPerson third_person = ThirdPerson::from_environment();
    ThirdPersonState tps;
    std::uint64_t tps_samples{};
    std::int8_t display_mode{};
    std::size_t model_count{};
    std::vector<Event> events;
    Sink sink{*this};

    void mismatch(const char* field, unsigned index, std::uint32_t native, std::uint32_t original) {
        if (mismatch_rows < mismatches.size()) mismatches[mismatch_rows] = {field, index, native, original};
        ++mismatch_rows;
    }

    // Guest -> native. False when the guest state is outside what native owns.
    bool project(const Guest& g) {
        if (!records) return false;
        if (!records_installed) { sequences.install_camera_records(records, 0); records_installed = true; }
        std::array<std::uint8_t, 0x34> h{};
        g.read(header_at, h.data(), h.size());
        auto state = sequences.snapshot();
        const auto u16 = [&](unsigned o) { std::uint16_t v; std::memcpy(&v, h.data() + o, 2); return v; };
        const auto u32 = [&](unsigned o) { std::uint32_t v; std::memcpy(&v, h.data() + o, 4); return v; };
        const auto f32 = [&](unsigned o) { float v; std::memcpy(&v, h.data() + o, 4); return v; };
        state.initialized = h[0]; state.count = std::bit_cast<std::int8_t>(h[1]); state.restart_byte = h[2];
        state.condition_id = h[3]; state.selection_changed = h[4]; state.selected_id = h[5]; state.selection = u16(6);
        state.camera_progress = {f32(8), f32(12)}; state.camera_target = {f32(16), f32(20)};
        const auto previous = u32(0x18);
        if (!previous) state.previous_camera.reset();
        else {
            if (previous < records_at || (previous - records_at) % stride || (previous - records_at) / stride >= record_count)
                return false;
            state.previous_camera = std::uint8_t((previous - records_at) / stride);
        }
        state.view_masks.first = u32(0x1c); state.view_masks.second = u32(0x20);
        state.actor = h[0x24]; state.phase = h[0x25]; state.progress = h[0x26];
        if (state.count > std::int8_t(record_count)) return false;
        for (unsigned i = 0; i < record_count; ++i) {
            state.active[i] = g.get<std::uint8_t>(records_at + stride * i);
            state.camera_anchors[i] = g.get<t::Vector>(records_at + stride * i + 0x1c);
        }
        if (!sequences.restore(state)) return false;

        parameters.pose.eye = g.get<t::Vector>(params_at);
        parameters.pose.aim = g.get<t::Vector>(params_at + 0x0c);
        parameters.offset = g.get<t::Vector>(params_at + 0x18);
        parameters.pose.up = g.get<t::Vector>(params_at + 0x24);
        parameters.secondary_up = g.get<t::Vector>(params_at + 0x30);
        parameters.distance = g.get<float>(params_at + 0x3c);
        parameters.far_plane = g.get<float>(params_at + 0x40);
        parameters.near_plane = g.get<float>(params_at + 0x44);
        parameters.lens = g.get<float>(params_at + 0x48);
        parameters.pitch = g.get<std::uint32_t>(params_at + 0x4c);
        parameters.yaw = g.get<std::uint32_t>(params_at + 0x50);
        parameters.pose.roll = g.get<std::uint32_t>(params_at + 0x54);

        display.viewport = g.get<s::CameraViewport>(viewport_at);
        display.projection = {g.get<t::Matrix>(perspective_at), g.get<t::Matrix>(scaled_at),
                              g.get<t::Matrix>(first_composite_at), g.get<t::Matrix>(second_composite_at)};
        display.view = g.get<t::Matrix>(view_at);
        projection.horizontal_extent = g.get<float>(horizontal_at);
        projection.vertical_extent = g.get<float>(vertical_at);
        projection.width = g.get<float>(width_at);
        projection.height = g.get<float>(height_at);
        projection.first_transform = g.get<t::Matrix>(first_transform_at);
        projection.second_transform = g.get<t::Matrix>(second_transform_at);
        display_mode = g.get<std::int8_t>(mode_at);

        for (unsigned i = 0; i < 128; ++i) models.mark_slot_byte(std::uint8_t(i), g.get<std::uint8_t>(visibility_at + i));
        model_count = g.get<std::uint16_t>(model_count_at);

        if (state.actor < primary_actors) {
            const auto p = g.get<t::Vector>(actors_at + actor_stride * state.actor + actor_position);
            world->primary(state.actor)->position = {p.x, p.y, p.z};
        }
        auto& session = world->session();
        session.resource_hide_selected = g.get<std::uint8_t>(hide_at);
        session.resource_hide_others = g.get<std::uint8_t>(hide_at + 1);
        session.resource_hide_remaining = {g.get<std::uint8_t>(hide_at + 2), g.get<std::uint8_t>(hide_at + 3)};
        return true;
    }

    s::RoomCameraStatus run_native(std::int8_t fog_selected, s::Fog& fog) {
        (void)fog_selected;
        events.clear();
        s::CameraDisplayBinding bound{display_mode, projection, display, sink};
        s::RoomCamera camera(sequences, parameters);
        return camera.update(*world, models, model_count, fog, bound);
    }

    // Header/output bytes native writes, in guest form.
    void write_outputs(const Guest& g, const s::Fog& fog) {
        const auto& state = sequences.snapshot();
        g.put<std::uint8_t>(header_at + 3, state.condition_id);
        g.put<std::uint8_t>(header_at + 4, state.selection_changed);
        g.put<std::uint8_t>(header_at + 0x26, state.progress);
        g.put(header_at + 8, state.camera_progress);
        g.put(header_at + 16, state.camera_target);
        g.put<std::uint32_t>(header_at + 0x18, state.previous_camera ? records_at + stride * *state.previous_camera : 0u);
        if (state.view_masks.first) g.put<std::uint32_t>(header_at + 0x1c, *state.view_masks.first);
        if (state.view_masks.second) g.put<std::uint32_t>(header_at + 0x20, *state.view_masks.second);
        for (unsigned i = 0; i < record_count; ++i) g.put(records_at + stride * i + 0x1c, state.camera_anchors[i]);
        const auto& visibility = models.state().visibility;
        g.write(visibility_at, visibility.data(), visibility.size());
        const auto& session = world->session();
        g.put<std::uint8_t>(hide_at, session.resource_hide_selected);
        g.put<std::uint8_t>(hide_at + 1, session.resource_hide_others);
        g.put<std::uint8_t>(hide_at + 2, session.resource_hide_remaining[0]);
        g.put<std::uint8_t>(hide_at + 3, session.resource_hide_remaining[1]);
        g.put<std::int8_t>(fog_selected_at, fog.state().selected);
        write_parameters(g, parameters);
    }
    static void write_parameters(const Guest& g, const s::CameraParameters& p) {
        g.put(params_at, p.pose.eye); g.put(params_at + 0x0c, p.pose.aim); g.put(params_at + 0x18, p.offset);
        g.put(params_at + 0x24, p.pose.up); g.put(params_at + 0x30, p.secondary_up);
        g.put(params_at + 0x3c, p.distance); g.put(params_at + 0x40, p.far_plane); g.put(params_at + 0x44, p.near_plane);
        g.put(params_at + 0x48, p.lens); g.put(params_at + 0x4c, p.pitch); g.put(params_at + 0x50, p.yaw);
        g.put(params_at + 0x54, p.pose.roll);
    }

    template <class T> void same(const char* field, unsigned index, const T& native, const T& original, bool& ok) {
        static_assert(std::is_trivially_copyable_v<T>);
        if (std::memcmp(&native, &original, sizeof(T)) == 0) return;
        ok = false;
        // First differing 32-bit word, for the report.
        std::array<std::uint32_t, (sizeof(T) + 3) / 4> a{}, b{};
        std::memcpy(a.data(), &native, sizeof(T)); std::memcpy(b.data(), &original, sizeof(T));
        unsigned word = 0; while (word < a.size() && a[word] == b[word]) ++word;
        mismatch(field, index * 100 + word, a[word], b[word]);
    }

    bool compare(const Guest& g, const s::Fog& fog, const std::vector<Event>& original_events) {
        bool ok = true;
        const auto& state = sequences.snapshot();
        same("condition_id", 0, state.condition_id, g.get<std::uint8_t>(header_at + 3), ok);
        same("selection_changed", 0, state.selection_changed, g.get<std::uint8_t>(header_at + 4), ok);
        same("progress", 0, state.progress, g.get<std::uint8_t>(header_at + 0x26), ok);
        same("camera_progress", 0, state.camera_progress, g.get<std::array<float, 2>>(header_at + 8), ok);
        same("camera_target", 0, state.camera_target, g.get<std::array<float, 2>>(header_at + 16), ok);
        same("previous_camera", 0, state.previous_camera ? records_at + stride * *state.previous_camera : 0u,
             g.get<std::uint32_t>(header_at + 0x18), ok);
        // Projected from guest every call, so both always hold a value here.
        same("view_mask_first", 0, state.view_masks.first.value_or(0xdeadbeefu), g.get<std::uint32_t>(header_at + 0x1c), ok);
        same("view_mask_second", 0, state.view_masks.second.value_or(0xdeadbeefu), g.get<std::uint32_t>(header_at + 0x20), ok);
        for (unsigned i = 0; i < record_count; ++i)
            same("anchor", i, state.camera_anchors[i], g.get<t::Vector>(records_at + stride * i + 0x1c), ok);
        for (unsigned i = 0; i < 128; ++i)
            same("visibility", i, models.state().visibility[i], g.get<std::uint8_t>(visibility_at + i), ok);
        const auto& session = world->session();
        same("hide_selected", 0, session.resource_hide_selected, g.get<std::uint8_t>(hide_at), ok);
        same("hide_others", 0, session.resource_hide_others, g.get<std::uint8_t>(hide_at + 1), ok);
        same("hide_remaining", 0, session.resource_hide_remaining[0], g.get<std::uint8_t>(hide_at + 2), ok);
        same("hide_remaining", 1, session.resource_hide_remaining[1], g.get<std::uint8_t>(hide_at + 3), ok);
        same("fog_selected", 0, fog.state().selected, g.get<std::int8_t>(fog_selected_at), ok);
        same("eye", 0, parameters.pose.eye, g.get<t::Vector>(params_at), ok);
        same("aim", 0, parameters.pose.aim, g.get<t::Vector>(params_at + 0x0c), ok);
        same("offset", 0, parameters.offset, g.get<t::Vector>(params_at + 0x18), ok);
        same("up", 0, parameters.pose.up, g.get<t::Vector>(params_at + 0x24), ok);
        same("secondary_up", 0, parameters.secondary_up, g.get<t::Vector>(params_at + 0x30), ok);
        same("distance", 0, parameters.distance, g.get<float>(params_at + 0x3c), ok);
        same("far_plane", 0, parameters.far_plane, g.get<float>(params_at + 0x40), ok);
        same("near_plane", 0, parameters.near_plane, g.get<float>(params_at + 0x44), ok);
        same("lens", 0, parameters.lens, g.get<float>(params_at + 0x48), ok);
        same("pitch", 0, parameters.pitch, g.get<std::uint32_t>(params_at + 0x4c), ok);
        same("yaw", 0, parameters.yaw, g.get<std::uint32_t>(params_at + 0x50), ok);
        same("roll", 0, parameters.pose.roll, g.get<std::uint32_t>(params_at + 0x54), ok);
        if (events.size() != original_events.size()) {
            ok = false; mismatch("event_count", 0, std::uint32_t(events.size()), std::uint32_t(original_events.size()));
        } else {
            for (unsigned i = 0; i < events.size(); ++i) {
                const auto& a = events[i]; const auto& b = original_events[i];
                same("event_op", i, a.op, b.op, ok);
                if (a.op != b.op) continue;
                if (a.op == op_viewport) {
                    same("event_viewport", i, a.viewport, b.viewport, ok);
                    same("event_perspective", i, a.projection.perspective, b.projection.perspective, ok);
                    same("event_scaled", i, a.projection.scaled, b.projection.scaled, ok);
                    same("event_first_composite", i, a.projection.first_composite, b.projection.first_composite, ok);
                    same("event_second_composite", i, a.projection.second_composite, b.projection.second_composite, ok);
                } else {
                    same("event_view", i, a.view, b.view, ok);
                }
            }
        }
        return ok;
    }

    // Renderer command through the original, as 375650/375920 call it.
    void provider(R5900Context* ctx, unsigned op) {
        [[maybe_unused]] auto* rdram = ram;  // SDK context-write bank macros
        const auto saved = *ctx;
        const auto sp = GPR_U32(ctx, 29);
        if (sp < 0x100 || (sp & 15)) throw std::runtime_error("Room camera adapter: provider stack refused");
        SET_GPR_U32(ctx, 29, sp - 0x40); SET_GPR_U32(ctx, 31, camera_entry);
        SET_GPR_U32(ctx, 4, op); ctx->pc = renderer_command; ctx->in_delay_slot = false;
        try {
            sub_001AF780_0x1af780(ram, ctx, runtime);
            if (ctx->pc != camera_entry || ctx->in_delay_slot)
                throw std::runtime_error("Room camera adapter: renderer command did not return");
        } catch (...) { *ctx = saved; throw; }
        *ctx = saved;
    }

    // Game segment test against room geometry (o2 0x5795E0): a0 start, a1 end,
    // a2 out point, a3 out normal, t0/t1 filters, t2 out type; v0 = any hit.
    // Filters -1/0 as the actor surface probe at o2 0x623884 passes them.
    bool segment(R5900Context* ctx, const Guest& g, t::Vector start, t::Vector end, t::Vector& hit) {
        [[maybe_unused]] auto* rdram = ram;  // SDK context-write bank macros
        const auto saved = *ctx;
        const auto sp = GPR_U32(ctx, 29);
        if (sp < 0x400 || (sp & 15)) return false;
        const std::uint32_t frame = (sp - 0x200) & ~15u;
        const std::uint32_t a = frame + 0x40, b = frame + 0x50, out = frame + 0x60, normal = frame + 0x70, type = frame + 0x80;
        g.put(a, start); g.put(b, end);
        SET_GPR_U32(ctx, 29, frame); SET_GPR_U32(ctx, 31, camera_entry);
        SET_GPR_U32(ctx, 4, a); SET_GPR_U32(ctx, 5, b); SET_GPR_U32(ctx, 6, out); SET_GPR_U32(ctx, 7, normal);
        SET_GPR_U32(ctx, 8, 0xffffffffu); SET_GPR_U32(ctx, 9, 0); SET_GPR_U32(ctx, 10, type);
        ctx->pc = 0x5795e0; ctx->in_delay_slot = false;
        bool any = false;
        try {
            o2_005795E0_0x5795e0(ram, ctx, runtime);
            if (ctx->pc != camera_entry || ctx->in_delay_slot) throw std::runtime_error("segment test did not return");
            any = GPR_U32(ctx, 2) != 0;
            if (any) hit = g.get<t::Vector>(out);
        } catch (...) { *ctx = saved; throw; }
        *ctx = saved;
        return any;
    }

    void third_person_override(const Guest& g, R5900Context* ctx) {
        auto& tp = third_person;
        if (!tp.enabled && !tp.log) return;
        const auto& state = sequences.snapshot();
        const auto actor = state.actor;
        if (actor >= primary_actors) return;
        const auto base = actors_at + actor_stride * actor;
        const auto position = g.get<t::Vector>(base + actor_position);
        const auto actor_angle = float(g.get<std::int16_t>(base + actor_yaw)) * yaw_turn;
        if (tp.log && (tps_samples++ % 15) == 0)
            std::fprintf(stderr, "[NATIVE-ROOM-CAMERA-TPS] actor=%u pos=%.1f,%.1f,%.1f actor_yaw=%.1f cam_yaw=%.1f cam_pitch=%.1f active=%d eye=%.1f,%.1f,%.1f aim=%.1f,%.1f,%.1f\n",
                         unsigned(actor), position.x, position.y, position.z, actor_angle / degrees, tps.yaw / degrees,
                         tps.pitch / degrees, int(tps.active), parameters.pose.eye.x, parameters.pose.eye.y,
                         parameters.pose.eye.z, parameters.pose.aim.x, parameters.pose.aim.y, parameters.pose.aim.z);
        if (!tp.enabled) return;

        int mouse_dx = 0, mouse_dy = 0, wheel = 0;
        const bool mouse_captured = tp.mouse && ps2HostTakeMouseDelta(&mouse_dx, &mouse_dy, &wheel);
        // Scripted selections (doors, events, notifications) keep the game's camera.
        if (state.selection != 0) {
            tps.active = false; tps.smoothed = false; ++tps.yielded;
            reo::performance::request_crosshair(false); reo_pad_tap::set_aim_left(-1);
            return;
        }
        if (!tps.view_initialised) { tps.first_person = tp.first_person; tps.view_initialised = true; }
        const auto pad = reo_pad_tap::latest();
        const auto pressed_now = std::uint16_t(pad.pressed & ~tps.previous_pressed);
        tps.previous_pressed = pad.pressed;
        if (!tps.active || tps.imports_seen != counts.imports) {
            tps.active = true; tps.smoothed = false; tps.imports_seen = counts.imports;
            tps.yaw = actor_angle; tps.pitch = tp.pitch * degrees;
        }
        if (pressed_now & reo_pad_tap::R3) { tps.yaw = actor_angle; tps.pitch = tp.pitch * degrees; ++tps.recentres; }
        // L3 switches between third and first person.
        if (pressed_now & reo_pad_tap::L3) { tps.first_person = !tps.first_person; tps.smoothed = false; ++tps.view_switches; }
        const auto axis = [](std::uint8_t v) {
            const float x = (float(v) - 128.f) / 127.f;
            const float dead = 0.18f;
            if (std::fabs(x) < dead) return 0.f;
            return std::copysign((std::fabs(x) - dead) / (1.f - dead), x);
        };
        tps.yaw += tp.turn_sign * axis(pad.right_x) * tp.yaw_speed * degrees;
        tps.pitch += (tp.invert_y != 0.f ? -1.f : 1.f) * axis(pad.right_y) * tp.pitch_speed * degrees;
        if (mouse_captured) {
            tps.yaw += tp.turn_sign * float(mouse_dx) * tp.mouse_sens * degrees;
            tps.pitch += (tp.invert_y != 0.f ? -1.f : 1.f) * float(mouse_dy) * tp.mouse_sens * degrees;
            tps.zoom = std::clamp(tps.zoom - float(wheel) / 120.f * tp.zoom_step, -150.f, 250.f);
            if (mouse_dx || mouse_dy) ++tps.mouse_frames;
        }
        tps.pitch = std::clamp(tps.pitch, tp.pitch_min * degrees, tp.pitch_max * degrees);
        if (tps.yaw > 3.14159265f) tps.yaw -= 6.28318531f;
        if (tps.yaw < -3.14159265f) tps.yaw += 6.28318531f;

        const bool aiming = (pad.pressed & reo_pad_tap::R1) != 0;
        reo::performance::request_crosshair(aiming || tps.first_person);
        if (aiming) {
            const float pitch_degrees = tps.pitch / degrees;
            reo_pad_tap::set_aim_left(pitch_degrees < tp.aim_up ? 0x00 : pitch_degrees > tp.aim_down ? 0xff : 0x80);
        } else reo_pad_tap::set_aim_left(-1);
        if (aiming) {
            // Modern aim: the actor faces where the camera looks.
            const auto units = std::int16_t(std::lround(tps.yaw / yaw_turn));
            g.put<std::int16_t>(base + actor_yaw, units);
            ++tps.aim_frames;
            // Move while aiming: the host left stick (not the aim override) moves
            // the actor relative to the camera; a knee-height segment test keeps
            // the body radius away from room walls. Height is unchanged.
            const float sx = axis(pad.left_x), sy = -axis(pad.left_y);
            if (tp.strafe != 0.f && (sx != 0.f || sy != 0.f)) {
                const float step = tp.strafe_speed / 30.f;
                const t::Vector flat{std::sin(tps.yaw), 0.f, std::cos(tps.yaw)};
                const t::Vector side{std::cos(tps.yaw), 0.f, -std::sin(tps.yaw)};
                t::Vector move{flat.x * sy + side.x * sx, 0.f, flat.z * sy + side.z * sx};
                const float length = std::sqrt(move.x * move.x + move.z * move.z);
                if (length > 1.f) { move.x /= length; move.z /= length; }
                const t::Vector knee{position.x, position.y + 50.f, position.z};
                const float reach = step + tp.body_radius;
                const t::Vector probe{knee.x + move.x * reach, knee.y, knee.z + move.z * reach};
                t::Vector wall{};
                bool blocked = true;
                try { blocked = segment(ctx, g, knee, probe, wall); } catch (...) {}
                if (!blocked) {
                    const t::Vector next{position.x + move.x * step, position.y, position.z + move.z * step};
                    g.put(base + actor_position, next);
                    ++tps.strafe_frames;
                } else ++tps.strafe_blocked;
            }
        }
        const float distance = std::max(60.f, (aiming ? tp.aim_distance : tp.distance) + (aiming ? 0.f : tps.zoom));
        const float side = aiming ? tp.aim_side : tp.side;
        const float lift = aiming ? tp.aim_pivot : tp.pivot;
        const float cp = std::cos(tps.pitch), sp = std::sin(tps.pitch);
        const t::Vector forward{std::sin(tps.yaw) * cp, -sp, std::cos(tps.yaw) * cp};
        if (tps.first_person) {
            const t::Vector flat{std::sin(tps.yaw), 0.f, std::cos(tps.yaw)};
            const t::Vector eye{position.x + flat.x * tp.eye_ahead, position.y + tp.eye_height,
                                position.z + flat.z * tp.eye_ahead};
            parameters.pose.eye = eye;
            parameters.pose.aim = {eye.x + forward.x * 400.f, eye.y + forward.y * 400.f, eye.z + forward.z * 400.f};
            parameters.pose.roll = 0;
            tps.eye = parameters.pose.eye; tps.aim = parameters.pose.aim; tps.smoothed = true;
            ++tps.frames; ++tps.first_person_frames;
            auto relatched = sequences.snapshot(); relatched.selection_changed = 0; sequences.restore(relatched);
            events.clear();
            s::publish_camera_display(parameters, display_mode, projection, display, sink);
            return;
        }
        const t::Vector right{std::cos(tps.yaw), 0.f, -std::sin(tps.yaw)};
        const t::Vector pivot{position.x + right.x * side, position.y + lift, position.z + right.z * side};
        t::Vector eye{pivot.x - forward.x * distance, pivot.y - forward.y * distance, pivot.z - forward.z * distance};
        const t::Vector aim{pivot.x + forward.x * 400.f, pivot.y + forward.y * 400.f, pivot.z + forward.z * 400.f};
        // Walls: test from the actor's head line to the eye; stop short of a hit.
        const t::Vector head{position.x, position.y + lift, position.z};
        bool pulled = false;
        t::Vector hit{};
        try {
            if (segment(ctx, g, head, eye, hit)) {
                const t::Vector back{head.x - hit.x, head.y - hit.y, head.z - hit.z};
                const float length = std::sqrt(back.x * back.x + back.y * back.y + back.z * back.z);
                const float pull = length > 1.f ? std::min(25.f, length * 0.5f) / length : 0.f;
                eye = {hit.x + back.x * pull, hit.y + back.y * pull, hit.z + back.z * pull};
                pulled = true; ++tps.collisions;
            }
        } catch (...) {}
        if (!tps.smoothed) { tps.eye = eye; tps.aim = aim; tps.smoothed = true; }
        else {
            const float k = std::clamp(tp.smoothing, 0.f, 1.f);
            const auto lerp = [k](t::Vector a, t::Vector b) {
                return t::Vector{a.x + (b.x - a.x) * k, a.y + (b.y - a.y) * k, a.z + (b.z - a.z) * k};
            };
            const auto d2 = [&](t::Vector v) {
                return (v.x - head.x) * (v.x - head.x) + (v.y - head.y) * (v.y - head.y) + (v.z - head.z) * (v.z - head.z);
            };
            // Never ease through a wall: when pulled in closer than the smoothed eye, snap.
            tps.eye = pulled && d2(eye) < d2(tps.eye) ? eye : lerp(tps.eye, eye);
            tps.aim = lerp(tps.aim, aim);
        }
        parameters.pose.eye = tps.eye;
        parameters.pose.aim = tps.aim;
        parameters.pose.roll = 0;
        ++tps.frames;
        // Free camera: no zone hand-off latch for the analog direction (6621F0).
        auto relatched = sequences.snapshot(); relatched.selection_changed = 0; sequences.restore(relatched);
        // Republish viewport/view from the overridden pose; replaces the native events.
        events.clear();
        s::publish_camera_display(parameters, display_mode, projection, display, sink);
    }

    void replay(const Guest& g, R5900Context* ctx) {
        for (const auto& e : events) {
            write_parameters(g, e.parameters);
            if (e.op == op_viewport) {
                g.put(viewport_at, e.viewport);
                g.put(perspective_at, e.projection.perspective); g.put(scaled_at, e.projection.scaled);
                g.put(first_composite_at, e.projection.first_composite);
                g.put(second_composite_at, e.projection.second_composite);
            } else {
                g.put(view_at, e.view);
            }
            provider(ctx, e.op);
        }
    }

    // Guest ranges the original may legitimately write during 5BED30.
    static bool expected_write(std::uint32_t at, std::uint32_t sp) {
        const auto in = [&](std::uint32_t lo, std::uint32_t hi) { return at >= lo && at < hi; };
        return in(header_at, header_at + header_bytes) || in(view_at, params_end) ||
               in(scaled_at, second_transform_at) || in(visibility_at, visibility_at + 128) ||
               in(hide_at, hide_at + 4) || in(fog_selected_at, fog_selected_at + 1) ||
               in((sp & 0x1fffffffu) - 0x4000, (sp & 0x1fffffffu) + 0x100);
    }
    void record_unexpected_writes(std::uint32_t sp) {
        bool any = false;
        std::sort(renderer_blocks.begin(), renderer_blocks.end());
        for (std::uint32_t at = 0; at < 0x02000000u; at += 32) {
            if (!std::memcmp(before.data() + at, ram + at, 32)) continue;
            if (std::binary_search(renderer_blocks.begin(), renderer_blocks.end(), at)) continue;
            std::uint32_t mask = 0;
            for (unsigned i = 0; i < 32; ++i)
                if (before[at + i] != ram[at + i] && !expected_write(at + i, sp)) mask |= 1u << i;
            if (!mask) continue;
            any = true;
            auto it = std::find_if(unexpected.begin(), unexpected.end(), [&](const WriteRange& r) { return r.at == at; });
            if (it != unexpected.end()) { ++it->hits; it->mask |= mask; }
            else if (unexpected.size() < 64) unexpected.push_back({at, mask, 1});
        }
        renderer_blocks.clear();
        if (any) ++counts.unexpected_write_calls;
    }
    // Called around each original 0x1AF780 while the original camera runs.
    void renderer_snapshot() { std::memcpy(renderer_before.data(), ram, renderer_before.size()); }
    void renderer_attribute() {
        for (std::uint32_t at = 0; at < 0x02000000u; at += 32)
            if (std::memcmp(renderer_before.data() + at, ram + at, 32)) renderer_blocks.push_back(at);
    }

    void dump() {
        counters();
        dump_details();
    }
    void counters() {
        std::fprintf(stderr,
            "[NATIVE-ROOM-CAMERA] mode=%s calls=%llu compared=%llu mismatched=%llu refused=%llu native_completed=%llu "
            "fallback=%llu imports=%llu import_refused=%llu no_records=%llu unexpected_write_calls=%llu "
            "refused_projection=%llu refused_unavailable=%llu refused_numeric=%llu\n",
            mode == Mode::native ? "native" : mode == Mode::shadow ? "shadow" : "shadow-writes",
            (unsigned long long)counts.calls, (unsigned long long)counts.compared, (unsigned long long)counts.mismatched,
            (unsigned long long)counts.refused, (unsigned long long)counts.native_completed,
            (unsigned long long)counts.fallback, (unsigned long long)counts.imports,
            (unsigned long long)counts.import_refused, (unsigned long long)counts.no_records,
            (unsigned long long)counts.unexpected_write_calls, (unsigned long long)counts.refused_projection,
            (unsigned long long)counts.refused_unavailable, (unsigned long long)counts.refused_numeric);
        std::fflush(stderr);
    }
    void dump_details() {
        if (third_person.enabled)
            std::fprintf(stderr, "[NATIVE-ROOM-CAMERA-TPS-SUMMARY] frames=%llu yielded=%llu collisions=%llu recentres=%llu aim_frames=%llu mouse_frames=%llu first_person_frames=%llu view_switches=%llu\n",
                         (unsigned long long)tps.frames, (unsigned long long)tps.yielded, (unsigned long long)tps.collisions,
                         (unsigned long long)tps.recentres, (unsigned long long)tps.aim_frames,
                         (unsigned long long)tps.mouse_frames, (unsigned long long)tps.first_person_frames,
                         (unsigned long long)tps.view_switches);
            std::fprintf(stderr, "[NATIVE-ROOM-CAMERA-STRAFE] frames=%llu blocked=%llu\n",
                         (unsigned long long)tps.strafe_frames, (unsigned long long)tps.strafe_blocked);
        if (mode == Mode::shadow_writes)
            std::fprintf(stderr, "[NATIVE-ROOM-CAMERA-WATCH] block=0x%06x checks=%llu changed_between_calls=%llu\n",
                         watch_at, (unsigned long long)watch_checks, (unsigned long long)watch_changed_between_calls);
        const auto shown = std::min<std::uint64_t>(mismatch_rows, mismatches.size());
        for (std::uint64_t i = 0; i < shown; ++i)
            std::fprintf(stderr, "[NATIVE-ROOM-CAMERA-MISMATCH] field=%s index=%u native=0x%08x original=0x%08x\n",
                         mismatches[i].field, mismatches[i].index, mismatches[i].native, mismatches[i].original);
        for (const auto& r : unexpected)
            std::fprintf(stderr, "[NATIVE-ROOM-CAMERA-UNEXPECTED-WRITE] block=0x%06x byte_mask=0x%08x calls=%llu\n", r.at,
                         r.mask, (unsigned long long)r.hits);
    }
};

std::mutex registry_mutex;
std::shared_ptr<Binding> owned;

// Original 0x1AF780 observed while the original camera runs (shadow only).
void renderer_recorder(std::uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    if (recording) {
        Guest g(ram);
        Event e; e.op = GPR_U32(ctx, 4);
        if (e.op == op_viewport) {
            e.viewport = g.get<s::CameraViewport>(viewport_at);
            e.projection = {g.get<t::Matrix>(perspective_at), g.get<t::Matrix>(scaled_at),
                            g.get<t::Matrix>(first_composite_at), g.get<t::Matrix>(second_composite_at)};
        } else if (e.op == op_view) {
            e.view = g.get<t::Matrix>(view_at);
        }
        recording->push_back(e);
        if (binding && binding->mode == Mode::shadow_writes) {
            binding->renderer_snapshot();
            sub_001AF780_0x1af780(ram, ctx, rt);
            binding->renderer_attribute();
            return;
        }
    }
    sub_001AF780_0x1af780(ram, ctx, rt);
}

void run_original_camera(std::uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    const auto back = GPR_U32(ctx, 31);
    o2_005BED30_0x5bed30(ram, ctx, rt);
    if (ctx->pc != back || ctx->in_delay_slot) throw std::runtime_error("Room camera adapter: original did not return");
}

void import_hook(std::uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    auto* b = binding;
    std::vector<std::byte> raw;
    const auto at = GPR_U32(ctx, 4), size = GPR_U32(ctx, 5);
    if (b) {
        try {
            reo_source_instrumentation::EntryScope scope(rt, ctx);
            if (size && size <= 0x100000u) { raw.resize(size); Guest(ram).read(at, raw.data(), size); }
        } catch (...) { raw.clear(); }
    }
    const auto back = GPR_U32(ctx, 31);
    o2_005BE3E0_0x5be3e0(ram, ctx, rt);
    if (ctx->pc != back) throw std::runtime_error("Room camera adapter: record import did not return");
    if (!b) return;
    std::lock_guard<std::recursive_mutex> lock(b->operation);
    ++b->counts.imports;
    b->records = raw.empty() ? nullptr : s::RoomCameraRecords::import(raw);
    b->records_installed = false;
    if (!b->records) ++b->counts.import_refused;
}

void camera_hook(std::uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    auto* b = binding;
    if (!b) { run_original_camera(ram, ctx, rt); return; }
    std::unique_lock<std::recursive_mutex> lock(b->operation);
    ++b->counts.calls;
    if (b->counts.calls % 1000 == 0) b->counters();  // survives a killed process
    if (!b->records) { ++b->counts.no_records; lock.unlock(); run_original_camera(ram, ctx, rt); return; }
    const auto saved = *ctx;
    const auto entry_sp = GPR_U32(ctx, 29);
    reo_source_instrumentation::EntryScope scope(rt, ctx);
    Guest g(ram);
    bool projected = false;
    s::RoomCameraStatus status = s::RoomCameraStatus::unavailable;
    std::optional<s::Fog> fog;
    try {
        projected = b->project(g);
        if (projected) {
            s::FogState fog_state; fog_state.selected = g.get<std::int8_t>(fog_selected_at);
            fog.emplace(fog_state);
            status = b->run_native(fog_state.selected, *fog);
        }
    } catch (...) { projected = false; }
    const bool native_ok = projected && status == s::RoomCameraStatus::completed;
    if (!native_ok) {
        if (!projected) ++b->counts.refused_projection;
        else if (status == s::RoomCameraStatus::unavailable) ++b->counts.refused_unavailable;
        else ++b->counts.refused_numeric;
        if (!b->counts.first_refusal_logged) {
            b->counts.first_refusal_logged = true;
            std::array<std::uint8_t, 0x28> h{};
            try { g.read(header_at, h.data(), h.size()); } catch (...) {}
            std::fprintf(stderr, "[NATIVE-ROOM-CAMERA-REFUSAL] call=%llu projected=%d status=%d initialized=%u count=%d "
                "condition=%u selected=%u selection=%u actor=%u records=%u\n",
                (unsigned long long)b->counts.calls, int(projected), int(status), h[0], int(std::int8_t(h[1])), h[3], h[5],
                unsigned(h[6] | (h[7] << 8)), h[0x24], b->records ? unsigned(b->records->count()) : 0u);
        }
    }

    if (b->mode == Mode::native) {
        if (!native_ok) { ++b->counts.refused; ++b->counts.fallback; run_original_camera(ram, ctx, rt); return; }
        b->third_person_override(g, ctx);
        b->replay(g, ctx);
        b->write_outputs(g, *fog);
        ++b->counts.native_completed;
        *ctx = saved; ctx->pc = GPR_U32(ctx, 31); ctx->in_delay_slot = false;
        return;
    }

    // Shadow: original authoritative.
    if (b->mode == Mode::shadow_writes) {
        if (b->watch_valid) { ++b->watch_checks;
            if (std::memcmp(b->watch_after.data(), ram + Binding::watch_at, Binding::watch_bytes)) ++b->watch_changed_between_calls; }
        std::memcpy(b->before.data(), ram, b->before.size());
    }
    std::vector<Event> original_events;
    recording = &original_events;
    try { run_original_camera(ram, ctx, rt); } catch (...) { recording = nullptr; throw; }
    recording = nullptr;
    if (b->mode == Mode::shadow_writes) {
        b->record_unexpected_writes(entry_sp);
        std::memcpy(b->watch_after.data(), ram + Binding::watch_at, Binding::watch_bytes); b->watch_valid = true;
    }
    if (!native_ok) { ++b->counts.refused; return; }
    ++b->counts.compared;
    if (!b->compare(g, *fog, original_events)) ++b->counts.mismatched;
}

}  // namespace

bool install_before_run(PS2Runtime& rt, Mode mode) noexcept {
    try {
        auto lease = rt.acquirePreRunSetup();
        if (!lease) return false;
        std::lock_guard lock(registry_mutex);
        if (owned) return false;
        owned = std::make_shared<Binding>(rt, mode);
        if (!rt.registerExternalWorker(owned)) { owned.reset(); return false; }
        binding = owned.get();
        rt.registerOverlayFunction(overlay_base, overlay_magic, overlay_id_offset, overlay_o2, import_entry, import_hook);
        rt.registerOverlayFunction(overlay_base, overlay_magic, overlay_id_offset, overlay_o2, camera_entry, camera_hook);
        if (mode != Mode::native) rt.registerFunction(renderer_command, renderer_recorder);
        if (mode == Mode::native && owned->third_person.enabled) {
            reo_pad_tap::consume_right_stick.store(true);
            if (owned->third_person.mouse) {
                ps2HostSetMouseLook(true);
                reo_pad_tap::mouse_buttons_source.store(&ps2HostMouseButtons);
            }
        }
        return true;
    } catch (...) {
        binding = nullptr; owned.reset();
        return false;
    }
}
}  // namespace reo::native::room_camera_adapter
