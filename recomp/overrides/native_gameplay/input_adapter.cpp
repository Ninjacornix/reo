// Hybrid swap: player/menu input core (File #1 EE 0x1B0980, 0x1B0B80, 0x1B0DB0) ->
// native reo::native::gameplay_actors::input (phase 1: native logic on guest state).
// docs/native-gameplay/HYBRID_INTEGRATION_PLAN.md, step 4.
//
// Guest layout (File #1; tools/native_reconstruction/gameplay_actor_oracle/input_tests.cpp
// and the original bodies):
//   input frame (48 bytes): pressed +0, released +4, held +8, history[3] +12, repeat +24,
//     repeat timer +28 (s32), analog[8] +32 (s16)
//   1B0980(a0 = frame)  repeat timing on that frame
//   1B0B80(a0 = actor)  route controller -> actor frame +0xF78; slot +3, AI control +0xFF0
//   1B0DB0()            menu frame 0x324210 from controller 0x324300; actions -> 0x4BAE90
//   globals: mode 0x3243F2 (read by 1B0300/1B02D0, pure), selected actor 0x4BADED,
//     layout 0x3243EC, actor ports 0x2B8E90[8] (s8), controllers 0x324240 + 48*i (held +8,
//     analog +32), button layouts 0x2343C0 + 12*i (6 rows)
//
// REO_NATIVE_INPUT=shadow  originals run; native runs on the same pre-state; outputs and
//                          any other byte the original changes in its window are compared.
// REO_NATIVE_INPUT=1       native runs; an input the native core refuses (port, slot or
//                          layout out of its range) runs the original and is counted.
#include "game/native/gameplay_actors/input.hpp"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "source_instruction_access.hpp"
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <vector>

void sub_001B0980_0x1b0980(std::uint8_t*, R5900Context*, PS2Runtime*);
void sub_001B0B80_0x1b0b80(std::uint8_t*, R5900Context*, PS2Runtime*);
void sub_001B0DB0_0x1b0db0(std::uint8_t*, R5900Context*, PS2Runtime*);

namespace reo::native::input_adapter {
enum class Mode { shadow, native };
namespace {
namespace in = reo::native::gameplay_actors::input;
using Frame = in::Frame;

#if defined(REO_GAME_FILE2)
constexpr bool supported = false;  // File #2 addresses not mapped yet
#else
constexpr bool supported = true;
#endif
constexpr std::uint32_t repeat_entry = 0x1b0980, route_entry = 0x1b0b80, menu_entry = 0x1b0db0;
constexpr std::uint32_t actor_frame = 0xf78, actor_slot = 3, actor_ai = 0xff0, actor_stride = 0x10e0;
constexpr std::uint32_t mode_at = 0x3243f2, selected_at = 0x4baded, layout_at = 0x3243ec, ports_at = 0x2b8e90;
constexpr std::uint32_t controllers_at = 0x324240, controller_stride = 48, layouts_at = 0x2343c0;
constexpr std::uint32_t menu_frame = 0x324210, menu_source = 0x324300, actions_at = 0x4bae90;
constexpr std::size_t controller_count = 4, layout_count = 6, frame_bytes = 48;
// Bytes watched for writes the native port does not reproduce.
constexpr std::uint32_t menu_window = 0x324200, menu_window_bytes = 0x200;

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
    void bytes(std::uint32_t at, std::vector<std::uint8_t>& out, std::size_t n) const {
        check(at, n); out.resize(n);
        reo_source_instrumentation::copyBytesForBank(ram, out.data(), ram + (at & 0x1fffffffu), n);
    }
    static void check(std::uint32_t at, std::size_t n) {
        const auto p = at & 0x1fffffffu;
        if (p >= 0x02000000u || n > 0x02000000u - p) throw std::runtime_error("input adapter: guest range refused");
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
in::ControllerFrame read_controller(const Guest& g, std::uint32_t at) {
    in::ControllerFrame c; c.held = g.get<std::uint32_t>(at + 8);
    for (unsigned i = 0; i < 8; ++i) c.analog[i] = g.get<std::int16_t>(at + 32 + 2 * i);
    return c;
}
std::array<in::Remap, layout_count> read_layouts(const Guest& g) {
    std::array<in::Remap, layout_count> r;
    for (std::uint32_t i = 0; i < layout_count; ++i) {
        const auto at = layouts_at + 12 * i;
        r[i] = {g.get<std::uint32_t>(at), g.get<std::uint32_t>(at + 4), g.get<std::uint32_t>(at + 8)};
    }
    return r;
}

enum Entry { repeat_e, route_e, menu_e, entry_count };
constexpr const char* entry_names[entry_count] = {"repeat", "route", "menu"};
struct Counts {
    std::uint64_t calls{}, native{}, skipped{}, refused{}, compared{}, mismatched{}, unexpected_writes{};
};

struct Binding {
    Mode mode;
    std::array<Counts, entry_count> counts{};
    std::uint64_t total{};
    unsigned logged{}, unexpected_logged{};
    std::mutex lock;
    std::vector<std::uint8_t> before, after;

    void periodic() {
        if (++total % 6000) return;
        for (int e = 0; e < entry_count; ++e) {
            const auto& c = counts[e];
            std::fprintf(stderr,
                "[NATIVE-INPUT] mode=%s entry=%s calls=%llu native=%llu skipped=%llu refused=%llu compared=%llu "
                "mismatched=%llu unexpected_writes=%llu\n",
                mode == Mode::native ? "native" : "shadow", entry_names[e], (unsigned long long)c.calls,
                (unsigned long long)c.native, (unsigned long long)c.skipped, (unsigned long long)c.refused,
                (unsigned long long)c.compared, (unsigned long long)c.mismatched,
                (unsigned long long)c.unexpected_writes);
        }
    }
    void mismatch(Entry e, std::uint32_t at, const Frame& want, const Frame& got, std::uint32_t want_actions = 0,
                  std::uint32_t got_actions = 0) {
        ++counts[e].mismatched;
        if (logged >= 24) return;
        ++logged;
        std::fprintf(stderr,
            "[NATIVE-INPUT-MISMATCH] entry=%s at=%08x original: pressed=%08x released=%08x held=%08x repeat=%08x "
            "timer=%d actions=%08x | native: pressed=%08x released=%08x held=%08x repeat=%08x timer=%d actions=%08x\n",
            entry_names[e], at, want.pressed, want.released, want.held, want.repeat, want.repeat_timer, want_actions,
            got.pressed, got.released, got.held, got.repeat, got.repeat_timer, got_actions);
    }
};
std::unique_ptr<Binding> binding;

void call_original(Entry e, std::uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    const auto back = GPR_U32(ctx, 31);
    if (e == repeat_e) sub_001B0980_0x1b0980(ram, ctx, rt);
    else if (e == route_e) sub_001B0B80_0x1b0b80(ram, ctx, rt);
    else sub_001B0DB0_0x1b0db0(ram, ctx, rt);
    if (ctx->pc != back || ctx->in_delay_slot) throw std::runtime_error("input adapter: original did not return");
}
void native_return(R5900Context* ctx) { ctx->pc = GPR_U32(ctx, 31); ctx->in_delay_slot = false; }

// Native result for one entry on the current guest pre-state. Guest memory is not changed.
struct Result { in::Routed routed{in::Routed::updated}; Frame frame; std::uint32_t actions{}; std::uint32_t frame_at{}; };
Result compute(Entry e, const Guest& g, std::uint32_t a0) {
    Result r;
    if (e == repeat_e) {
        r.frame_at = a0; r.frame = read_frame(g, a0); in::repeat(r.frame);
    } else if (e == route_e) {
        r.frame_at = a0 + actor_frame; r.frame = read_frame(g, r.frame_at);
        in::Routing routing;
        routing.mode = g.get<std::uint8_t>(mode_at); routing.selected_actor = g.get<std::uint8_t>(selected_at);
        routing.layout = g.get<std::uint8_t>(layout_at);
        for (std::uint32_t i = 0; i < routing.actor_ports.size(); ++i) routing.actor_ports[i] = g.get<std::int8_t>(ports_at + i);
        std::array<in::ControllerFrame, controller_count> sources;
        for (std::uint32_t i = 0; i < controller_count; ++i) sources[i] = read_controller(g, controllers_at + controller_stride * i);
        const auto layouts = read_layouts(g);
        r.routed = in::route(r.frame, {g.get<std::uint8_t>(a0 + actor_slot), g.get<std::uint8_t>(a0 + actor_ai)},
                             routing, sources, layouts);
    } else {
        r.frame_at = menu_frame; r.frame = read_frame(g, menu_frame);
        const auto layout = g.get<std::uint8_t>(layout_at);
        if (layout >= layout_count) { r.routed = in::Routed::invalid_layout; return r; }
        r.actions = in::menu(r.frame, read_controller(g, menu_source), read_layouts(g)[layout]);
    }
    return r;
}
bool refused(in::Routed r) { return r != in::Routed::updated && r != in::Routed::skipped; }

void hook(Entry e, std::uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    auto* b = binding.get();
    if (!b) { call_original(e, ram, ctx, rt); return; }
    const auto a0 = GPR_U32(ctx, 4) & 0x1fffffffu;
    const Guest g{ram};
    std::unique_lock guard(b->lock);
    auto& c = b->counts[e];
    ++c.calls;
    reo_source_instrumentation::EntryScope scope(rt, ctx);
    Result r;
    bool ok = true;
    try { r = compute(e, g, a0); } catch (...) { ok = false; }
    if (!ok || refused(r.routed)) {
        ++c.refused; b->periodic(); guard.unlock();
        call_original(e, ram, ctx, rt);
        return;
    }
    if (b->mode == Mode::native) {
        if (r.routed == in::Routed::skipped) ++c.skipped;
        else {
            write_frame(g, r.frame_at, r.frame);
            if (e == menu_e) g.put(actions_at, r.actions);
        }
        ++c.native; b->periodic();
        native_return(ctx);
        return;
    }
    // Shadow: run the original, compare its frame (and menu actions) with native, and look for
    // any other byte it changed in its window (the actor record, or the menu input globals).
    const std::uint32_t window = e == route_e ? a0 : e == menu_e ? menu_window : a0;
    const std::size_t window_bytes = e == route_e ? actor_stride : e == menu_e ? menu_window_bytes : frame_bytes;
    g.bytes(window, b->before, window_bytes);
    const auto actions_before = g.get<std::uint32_t>(actions_at);
    guard.unlock();
    call_original(e, ram, ctx, rt);
    guard.lock();
    g.bytes(window, b->after, window_bytes);
    for (std::size_t i = 0; i < window_bytes; ++i) {
        const auto addr = window + std::uint32_t(i);
        if (addr >= r.frame_at && addr < r.frame_at + frame_bytes) continue;
        if (b->before[i] != b->after[i]) {
            ++c.unexpected_writes;
            if (b->unexpected_logged < 16) {
                ++b->unexpected_logged;
                std::fprintf(stderr, "[NATIVE-INPUT-UNEXPECTED] entry=%s addr=%08x before=%02x after=%02x\n",
                             entry_names[e], addr, b->before[i], b->after[i]);
            }
            break;
        }
    }
    if (e != menu_e && g.get<std::uint32_t>(actions_at) != actions_before) ++c.unexpected_writes;
    if (r.routed == in::Routed::skipped) ++c.skipped;
    ++c.compared;
    const auto want = read_frame(g, r.frame_at);
    const auto want_actions = e == menu_e ? g.get<std::uint32_t>(actions_at) : 0u;
    if (!(want == r.frame) || want_actions != (e == menu_e ? r.actions : 0u))
        b->mismatch(e, r.frame_at, want, r.frame, want_actions, r.actions);
    b->periodic();
}
void repeat_hook(std::uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) { hook(repeat_e, ram, ctx, rt); }
void route_hook(std::uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) { hook(route_e, ram, ctx, rt); }
void menu_hook(std::uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) { hook(menu_e, ram, ctx, rt); }
}  // namespace

// Called from reo_bootstrap.cpp before the game runs. Declared there (no header) so that adding
// this swap does not change any header in the build kit.
bool install_before_run(PS2Runtime& rt, bool native) noexcept {
    if constexpr (!supported) return false;
    try {
        if (binding) return false;
        binding = std::make_unique<Binding>();
        binding->mode = native ? Mode::native : Mode::shadow;
        rt.registerFunction(repeat_entry, repeat_hook);
        rt.registerFunction(route_entry, route_hook);
        rt.registerFunction(menu_entry, menu_hook);
        std::fprintf(stderr, "[NATIVE-INPUT] installed mode=%s entries=1B0980,1B0B80,1B0DB0\n", native ? "native" : "shadow");
        return true;
    } catch (const std::exception& e) {
        std::fprintf(stderr, "[NATIVE-INPUT] install failed: %s\n", e.what());
        binding.reset();
        return false;
    }
}
}  // namespace reo::native::input_adapter
