// Hybrid swap: player analog control (File #1 o2 0x6621F0) -> native
// gameplay_world::update_analog_control (phase 1: native logic on guest state).
//
// Guest layout (File #1, from tools/native_reconstruction/analog_control_tests.cpp and
// the original body): actor a0 with category +2, slot +3, yaw +0x92, motion class
// +0x54F, character +0xB98, status +0xBA0 (u32), heading target +0xBCE (s16),
// response lock +0xBD0, input frame +0xF78 (pressed, released, held, history[3],
// repeat, repeat timer, analog[8] s16), previous heading +0xFA8 (s16), heading
// active +0xFAA, AI control +0xFF0. Globals: request block 0x4BAE8D, mode 0x3243F2,
// selected actor 0x4BADED, inventory owner 0x4BADEE, dialogue bytes 0x4BAE33 and
// 0x755EC4, camera eye/aim 0x324138/0x324144, camera one-shot latch 0x3DDDB4.
//
// The original's two queries are pure reads and are evaluated natively:
//   1B0340(actor) = category==0 && slot==(mode==0 ? 0 : selected)  (World::locally_controlled)
//   6DEE20()      = b33 && ec4 && (ec4 != 2 || inventory owner)    (dialogue suppression)
#include "analog_control_adapter.hpp"
#include "game/native/gameplay_world/world.hpp"
#include "game/native/gameplay_world/analog_control.hpp"
#include "game/native/gameplay_world/actor_initial_state.hpp"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "source_instruction_access.hpp"
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <vector>

void o2_006621F0_0x6621f0(std::uint8_t*, R5900Context*, PS2Runtime*);

namespace reo::native::analog_control_adapter {
namespace {
namespace w = reo::native::gameplay_world;
namespace t = reo::native::transform_math;
using Frame = reo::native::gameplay_actors::input::Frame;

#if defined(REO_GAME_FILE2)
constexpr bool supported = false;  // File #2 layout not mapped yet
constexpr std::uint32_t overlay_base = 0x58d000, analog_entry = 0;
#else
constexpr bool supported = true;
constexpr std::uint32_t overlay_base = 0x570000, analog_entry = 0x6621f0;
#endif
constexpr std::uint32_t overlay_magic = 0x336F574D, overlay_id_offset = 4, overlay_o2 = 3;
constexpr std::uint32_t actors_at = 0x4a5c30, actor_stride = 0x10e0;
constexpr std::uint32_t frame_at = 0xf78, status_at = 0xba0, target_at = 0xbce, previous_at = 0xfa8, active_at = 0xfaa;
constexpr std::uint32_t request_at = 0x4bae8d, mode_at = 0x3243f2, selected_at = 0x4baded, owner_at = 0x4badee;
constexpr std::uint32_t dialogue_a = 0x4bae33, dialogue_b = 0x755ec4, eye_at = 0x324138, aim_at = 0x324144, latch_at = 0x3dddb4;

struct Guest {
    std::uint8_t* ram;
    template <class T> T get(std::uint32_t at) const {
        T v{}; check(at, sizeof v);
        reo_source_instrumentation::copyBytesForBank(ram, &v, ram + (at & 0x1fffffffu), sizeof v); return v;
    }
    template <class T> void put(std::uint32_t at, const T& v) const {
        check(at, sizeof v);
        reo_source_instrumentation::copyBytesForBank(ram, ram + (at & 0x1fffffffu), &v, sizeof v);
    }
    static void check(std::uint32_t at, std::size_t n) {
        const auto p = at & 0x1fffffffu;
        if (p >= 0x02000000u || n > 0x02000000u - p) throw std::runtime_error("analog adapter: guest range refused");
    }
};

Frame read_frame(const Guest& g, std::uint32_t at) {
    Frame f;
    f.pressed = g.get<std::uint32_t>(at); f.released = g.get<std::uint32_t>(at + 4); f.held = g.get<std::uint32_t>(at + 8);
    for (unsigned i = 0; i < 3; ++i) f.history[i] = g.get<std::uint32_t>(at + 12 + 4 * i);
    f.repeat = g.get<std::uint32_t>(at + 24); f.repeat_timer = g.get<std::int32_t>(at + 28);
    for (unsigned i = 0; i < 8; ++i) f.analog[i] = g.get<std::int16_t>(at + 32 + 2 * i);
    return f;
}
void write_frame(const Guest& g, std::uint32_t at, const Frame& f) {
    g.put(at, f.pressed); g.put(at + 4, f.released); g.put(at + 8, f.held);
    for (unsigned i = 0; i < 3; ++i) g.put(at + 12 + 4 * i, f.history[i]);
    g.put(at + 24, f.repeat); g.put(at + 28, f.repeat_timer);
    for (unsigned i = 0; i < 8; ++i) g.put(at + 32 + 2 * i, f.analog[i]);
}

// Everything the original may change (outputs) plus the inputs it reads.
struct Snapshot {
    Frame frame; std::uint32_t status{}; std::int16_t target{}, previous{}; std::uint8_t active{}, latch{};
    bool operator==(const Snapshot& o) const {
        return frame == o.frame && status == o.status && target == o.target && previous == o.previous &&
               active == o.active && latch == o.latch;
    }
};
Snapshot snapshot(const Guest& g, std::uint32_t actor) {
    Snapshot s;
    s.frame = read_frame(g, actor + frame_at); s.status = g.get<std::uint32_t>(actor + status_at);
    s.target = g.get<std::int16_t>(actor + target_at); s.previous = g.get<std::int16_t>(actor + previous_at);
    s.active = g.get<std::uint8_t>(actor + active_at); s.latch = g.get<std::uint8_t>(latch_at);
    return s;
}
bool output_byte(std::uint32_t offset) {
    const auto in = [&](std::uint32_t lo, std::uint32_t n) { return offset >= lo && offset < lo + n; };
    return in(frame_at, 0x30) || in(status_at, 4) || in(target_at, 2) || in(previous_at, 2) || in(active_at, 1);
}

struct Counts {
    std::uint64_t calls{}, compared{}, mismatched{}, native_completed{}, unavailable{}, fallback{}, refused{},
        unexpected_writes{};
};

class Binding {
public:
    explicit Binding(Mode m) : mode(m), session(std::make_shared<w::Session>()) {
        w::Profile profile; profile.layouts.push_back({}); profile.controller_count = 1;
        world = std::make_unique<w::World>(profile, session);
        auto actor = std::make_unique<w::Actor>(); w::initialize_cleared_actor_defaults(*actor);
        actor->category = 0; actor->slot = 0;
        if (world->spawn_primary(0, std::move(actor)).status != reo::native::gameplay_actors::EntityStatus::completed)
            throw std::runtime_error("analog adapter: native actor");
    }
    // Projects the guest actor/globals and runs the native function. Leaves guest memory untouched.
    w::AnalogControlStatus run_native(const Guest& g, std::uint32_t at, Snapshot& out) {
        const auto actor = world->primary(0);
        if (!actor) return w::AnalogControlStatus::unavailable;
        actor->category = g.get<std::uint8_t>(at + 2); actor->slot = g.get<std::uint8_t>(at + 3);
        actor->orientation[1] = g.get<std::int16_t>(at + 0x92);
        actor->motion_class = g.get<std::uint8_t>(at + 0x54f); actor->character = g.get<std::uint8_t>(at + 0xb98);
        actor->status = g.get<std::uint32_t>(at + status_at); actor->response_lock = g.get<std::uint8_t>(at + 0xbd0);
        actor->ai_control = g.get<std::uint8_t>(at + 0xff0);
        actor->analog_control = w::AnalogControlState{std::int8_t(g.get<std::uint8_t>(at + active_at)),
                                                      g.get<std::int16_t>(at + previous_at), g.get<std::int16_t>(at + target_at)};
        actor->input = read_frame(g, at + frame_at);
        world->mode = g.get<std::uint8_t>(mode_at);
        world->selected_actor = g.get<std::uint8_t>(selected_at);
        const auto owner = g.get<std::uint8_t>(owner_at);
        session->inventory_owner = owner;
        const auto a = g.get<std::uint8_t>(dialogue_a), b = g.get<std::uint8_t>(dialogue_b);
        const bool suppressed = a && b && (b != 2 || owner);
        const bool local = world->locally_controlled(*actor);
        std::uint8_t latch = g.get<std::uint8_t>(latch_at);
        const t::Vector eye = g.get<t::Vector>(eye_at), aim = g.get<t::Vector>(aim_at);
        const auto status = w::update_analog_control(*world, *actor, eye, aim, latch,
            std::optional<std::uint8_t>(g.get<std::uint8_t>(request_at)),
            local && owner == 0 ? std::optional<bool>(suppressed) : std::nullopt);
        if (status != w::AnalogControlStatus::completed) return status;
        out.frame = actor->input; out.status = actor->status; out.latch = latch;
        out.active = std::uint8_t(actor->analog_control->heading_active);
        out.previous = actor->analog_control->previous_input_heading;
        out.target = actor->analog_control->control_target_heading;
        return status;
    }
    static void write(const Guest& g, std::uint32_t at, const Snapshot& s) {
        write_frame(g, at + frame_at, s.frame); g.put(at + status_at, s.status);
        g.put(at + target_at, s.target); g.put(at + previous_at, s.previous);
        g.put(at + active_at, s.active); g.put(latch_at, s.latch);
    }
    void report_mismatch(std::uint32_t at, const Snapshot& before, const Snapshot& want, const Snapshot& got) {
        if (logged >= 24) return;
        ++logged;
        std::fprintf(stderr,
            "[NATIVE-ANALOG-MISMATCH] actor=%08x in: held=%08x mag=%d ang=%d status=%08x act=%u prev=%d latch=%u | "
            "original: pressed=%08x released=%08x held=%08x status=%08x act=%u prev=%d target=%d latch=%u | "
            "native: pressed=%08x released=%08x held=%08x status=%08x act=%u prev=%d target=%d latch=%u\n",
            at, before.frame.held, before.frame.analog[0], before.frame.analog[1], before.status, before.active,
            before.previous, before.latch, want.frame.pressed, want.frame.released, want.frame.held, want.status,
            want.active, want.previous, want.target, want.latch, got.frame.pressed, got.frame.released, got.frame.held,
            got.status, got.active, got.previous, got.target, got.latch);
    }
    void periodic() {
        if (counts.calls % 2000) return;
        std::fprintf(stderr,
            "[NATIVE-ANALOG] mode=%s calls=%llu compared=%llu mismatched=%llu native_completed=%llu unavailable=%llu "
            "fallback=%llu refused=%llu unexpected_writes=%llu\n",
            mode == Mode::native ? "native" : "shadow", (unsigned long long)counts.calls,
            (unsigned long long)counts.compared, (unsigned long long)counts.mismatched,
            (unsigned long long)counts.native_completed, (unsigned long long)counts.unavailable,
            (unsigned long long)counts.fallback, (unsigned long long)counts.refused,
            (unsigned long long)counts.unexpected_writes);
    }
    Mode mode;
    std::shared_ptr<w::Session> session;
    std::unique_ptr<w::World> world;
    Counts counts;
    unsigned logged{};
    std::mutex lock;
    std::vector<std::uint8_t> before_record = std::vector<std::uint8_t>(actor_stride);
};

std::unique_ptr<Binding> binding;

void run_original(std::uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    const auto back = GPR_U32(ctx, 31);
    o2_006621F0_0x6621f0(ram, ctx, rt);
    if (ctx->pc != back || ctx->in_delay_slot) throw std::runtime_error("analog adapter: original did not return");
}

void analog_hook(std::uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    auto* b = binding.get();
    const auto at = GPR_U32(ctx, 4) & 0x1fffffffu;
    // Only the four primary actor records are projected.
    if (!b || at < actors_at || at >= actors_at + 4 * actor_stride || (at - actors_at) % actor_stride) {
        if (b) ++b->counts.refused;
        o2_006621F0_0x6621f0(ram, ctx, rt);
        return;
    }
    std::unique_lock guard(b->lock);
    ++b->counts.calls;
    const Guest g{ram};
    reo_source_instrumentation::EntryScope scope(rt, ctx);
    if (b->mode == Mode::native) {
        Snapshot result;
        w::AnalogControlStatus status{};
        try { status = b->run_native(g, at, result); } catch (...) { status = w::AnalogControlStatus::unavailable; }
        if (status == w::AnalogControlStatus::completed) {
            Binding::write(g, at, result);
            ++b->counts.native_completed;
            ctx->pc = GPR_U32(ctx, 31); ctx->in_delay_slot = false;  // return as the original would (void)
            b->periodic();
            return;
        }
        ++b->counts.unavailable; ++b->counts.fallback;
        b->periodic();
        guard.unlock();
        run_original(ram, ctx, rt);
        return;
    }
    // Shadow: native on the pre-state, then the original; compare.
    const auto before = snapshot(g, at);
    Snapshot native_result;
    w::AnalogControlStatus status{};
    try { status = b->run_native(g, at, native_result); } catch (...) { status = w::AnalogControlStatus::unavailable; }
    for (std::uint32_t i = 0; i < actor_stride; ++i) b->before_record[i] = g.get<std::uint8_t>(at + i);
    guard.unlock();
    run_original(ram, ctx, rt);
    guard.lock();
    const auto after = snapshot(g, at);
    for (std::uint32_t i = 0; i < actor_stride; ++i)
        if (!output_byte(i) && g.get<std::uint8_t>(at + i) != b->before_record[i]) { ++b->counts.unexpected_writes; break; }
    if (status == w::AnalogControlStatus::completed) {
        ++b->counts.compared;
        if (!(native_result == after)) { ++b->counts.mismatched; b->report_mismatch(at, before, after, native_result); }
    } else {
        ++b->counts.unavailable;
    }
    b->periodic();
}
}  // namespace

bool install_before_run(PS2Runtime& rt, Mode mode) noexcept {
    if constexpr (!supported) return false;
    try {
        if (binding) return false;
        binding = std::make_unique<Binding>(mode);
        rt.registerOverlayFunction(overlay_base, overlay_magic, overlay_id_offset, overlay_o2, analog_entry, analog_hook);
        std::fprintf(stderr, "[NATIVE-ANALOG] installed mode=%s\n", mode == Mode::native ? "native" : "shadow");
        return true;
    } catch (const std::exception& e) {
        std::fprintf(stderr, "[NATIVE-ANALOG] install failed: %s\n", e.what());
        binding.reset();
        return false;
    }
}
}  // namespace reo::native::analog_control_adapter
