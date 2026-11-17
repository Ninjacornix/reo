#pragma once
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>

namespace reo::performance {
inline bool enabled() {
    static const bool value = [] {
        const char* option = std::getenv("REO_PERFORMANCE_OVERLAY");
        return option && std::strcmp(option, "1") == 0;
    }();
    return value;
}
inline std::atomic<uint64_t> updates{0};
// Modern camera crosshair, drawn by the present shader (bit 30 of the fps push word).
// Steady-clock milliseconds of the last camera frame that wanted it; the presenter
// draws it only while that is recent, so menus and cutscenes never keep it.
inline std::atomic<int64_t> crosshair_ms{0};
inline int64_t steady_ms() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count();
}
inline void request_crosshair(bool wanted) { crosshair_ms.store(wanted ? steady_ms() : 0); }
inline bool crosshair_visible() {
    const auto at = crosshair_ms.load(std::memory_order_relaxed);
    return at != 0 && steady_ms() - at < 100;
}

// Presentation warp (60 fps camera motion while the game updates at 30 Hz).
// The modern camera publishes its view direction and vertical lens once per game
// update. The presenter shows each game frame twice; the repeated scanout is
// rotated by half of the latest per-update camera rotation (pure rotation, so no
// depth is needed). Validated against real frames: vertical FOV = lens, 4:3
// picture, screen x = -(up x forward), screen y = up (tools/hybrid/warp_validate.py).
namespace warp {
struct View { float forward[3]{}; float lens{}; int64_t ms{}; uint64_t serial{}; };
inline std::atomic<uint32_t> sequence{0};  // seqlock: odd while writing
inline View latest_view, previous_view;
inline std::atomic<uint32_t> scanout_fbp{0xffffffffu};
inline bool enabled() {
    static const bool value = [] {
        const char* v = std::getenv("REO_CAMERA_WARP");
        return !v || std::strcmp(v, "0") != 0;
    }();
    return value;
}
// REO_CAMERA_WARP=0 disables the warp; =all also warps orbiting (third-person) views.
inline bool all_views() {
    static const bool value = [] {
        const char* v = std::getenv("REO_CAMERA_WARP");
        return v && std::strcmp(v, "all") == 0;
    }();
    return value;
}
inline void publish(const float forward[3], float lens) {
    const auto s = sequence.load(std::memory_order_relaxed);
    sequence.store(s + 1, std::memory_order_release);
    std::atomic_thread_fence(std::memory_order_release);
    previous_view = latest_view;
    latest_view = View{{forward[0], forward[1], forward[2]}, lens, steady_ms(), latest_view.serial + 1};
    sequence.store(s + 2, std::memory_order_release);
}
inline void clear() {
    const auto s = sequence.load(std::memory_order_relaxed);
    sequence.store(s + 1, std::memory_order_release);
    std::atomic_thread_fence(std::memory_order_release);
    previous_view = latest_view = View{};
    sequence.store(s + 2, std::memory_order_release);
}
inline bool read(View& latest, View& previous) {
    for (int attempt = 0; attempt < 8; ++attempt) {
        const auto a = sequence.load(std::memory_order_acquire);
        if (a & 1u) continue;
        latest = latest_view; previous = previous_view;
        std::atomic_thread_fence(std::memory_order_acquire);
        if (sequence.load(std::memory_order_relaxed) == a) return true;
    }
    return false;
}
struct Result { float rows[12]{}; float yaw_degrees{}; float pitch_degrees{}; bool repeat{}; };
inline void build(float yaw_d, float pitch_d, float yaw_t, float pitch_t, float lens, Result& out) {
    const float ty = std::tan(lens * 0.5f * 0.0174532925f), tx = ty * (4.f / 3.f);
    struct Basis { float f[3], r[3], u[3]; };
    const auto basis = [](float yaw, float pitch) {
        Basis b{};
        pitch = std::fmax(-1.55f, std::fmin(1.55f, pitch));
        const float cp = std::cos(pitch);
        b.f[0] = std::sin(yaw) * cp; b.f[1] = std::sin(pitch); b.f[2] = std::cos(yaw) * cp;
        b.r[0] = std::cos(yaw); b.r[1] = 0.f; b.r[2] = -std::sin(yaw);  // up x forward
        b.u[0] = b.f[1] * b.r[2] - b.f[2] * b.r[1];                      // forward x right
        b.u[1] = b.f[2] * b.r[0] - b.f[0] * b.r[2];
        b.u[2] = b.f[0] * b.r[1] - b.f[1] * b.r[0];
        return b;
    };
    const Basis D = basis(yaw_d, pitch_d), T = basis(yaw_t, pitch_t);
    const auto dot = [](const float* a, const float* b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; };
    // Shown ray: d = (-tx nx) r_T + (ty ny) u_T + f_T. Source NDC: x = -(d.r_D)/tx / (d.f_D), y = (d.u_D)/ty / (d.f_D).
    float* m = out.rows;
    m[0] = dot(T.r, D.r);              m[1] = -ty * dot(T.u, D.r) / tx;  m[2] = -dot(T.f, D.r) / tx;
    m[4] = -tx * dot(T.r, D.u) / ty;   m[5] = dot(T.u, D.u);             m[6] = dot(T.f, D.u) / ty;
    m[8] = -tx * dot(T.r, D.f);        m[9] = ty * dot(T.u, D.f);        m[10] = dot(T.f, D.f);
    m[3] = 1.f;  // enabled
}
// Diagnostic: REO_CAMERA_WARP_TEST=<yaw degrees>[,<pitch degrees>] warps every present by
// that fixed rotation (lens 40 unless a camera view is published), for validation.
inline bool test(Result& out) {
    struct Option { bool on; float yaw, pitch; };
    static const Option option = [] {
        const char* v = std::getenv("REO_CAMERA_WARP_TEST");
        Option o{false, 0.f, 0.f};
        if (v && *v) { o.on = true; o.yaw = float(std::atof(v)); if (const char* c = std::strchr(v, ',')) o.pitch = float(std::atof(c + 1)); }
        return o;
    }();
    if (!option.on) return false;
    View cur, prev;
    const float lens = read(cur, prev) && cur.lens > 1.f ? cur.lens : 40.f;
    out = Result{};
    build(0.f, 0.f, option.yaw * 0.0174532925f, option.pitch * 0.0174532925f, lens, out);
    out.yaw_degrees = option.yaw; out.pitch_degrees = option.pitch;
    return true;
}
// Fills rows r0..r2 (xyz) mapping picture NDC (nx, ny, 1) of the shown frame to the
// source frame: v = M q; source NDC = v.xy / v.z. Returns false for no warp.
inline bool compute(bool repeat_scanout, Result& out) {
    out = Result{}; out.repeat = repeat_scanout;
    if (!enabled() || !repeat_scanout) return false;
    View cur, prev;
    if (!read(cur, prev) || !cur.serial || prev.serial + 1 != cur.serial) return false;
    if (steady_ms() - cur.ms > 100 || cur.lens <= 1.f || cur.lens >= 170.f) return false;
    const auto yaw_of = [](const View& v) { return std::atan2(v.forward[0], v.forward[2]); };
    const auto pitch_of = [](const View& v) { return std::asin(std::fmax(-1.f, std::fmin(1.f, v.forward[1]))); };
    float dyaw = yaw_of(cur) - yaw_of(prev);
    if (dyaw > 3.14159265f) dyaw -= 6.28318531f;
    if (dyaw < -3.14159265f) dyaw += 6.28318531f;
    const float dpitch = pitch_of(cur) - pitch_of(prev);
    // Cuts, recentres and view switches are not motion.
    if (std::fabs(dyaw) > 0.35f || std::fabs(dpitch) > 0.35f) return false;
    if (std::fabs(dyaw) < 1e-5f && std::fabs(dpitch) < 1e-5f) return false;
    build(yaw_of(cur), pitch_of(cur), yaw_of(cur) + 0.5f * dyaw, pitch_of(cur) + 0.5f * dpitch, cur.lens, out);
    out.yaw_degrees = 0.5f * dyaw * 57.2957795f; out.pitch_degrees = 0.5f * dpitch * 57.2957795f;
    return true;
}
}  // namespace warp

// Actor callbacks run more than once per game frame. Count the original room
// frame once, including wrap/reset, rather than counting every player and AI.
class UpdateTracker {
    uint32_t previous_ = 0;
    bool initialized_ = false;
public:
    bool observe(uint32_t frame) {
        if (initialized_ && frame == previous_) return false;
        previous_ = frame; initialized_ = true;
        return true;
    }
};
struct Reading {
    uint32_t fps = 0, frameMs = 0, ups = 0; // Tenths; zero is a real measured rate.
};
class Meter {
    bool initialized_ = false;
    uint64_t startNs_ = 0, startFrames_ = 0, startUpdates_ = 0;
    Reading reading_{};
    static uint32_t tenths(double value) {
        return uint32_t(std::lround(value > 9999.9 ? 99999.0 : value * 10.0));
    }
public:
    Reading sample(uint64_t nowNs, uint64_t frames, uint64_t gameUpdates) {
        if (!initialized_) {
            initialized_ = true; startNs_ = nowNs;
            startFrames_ = frames; startUpdates_ = gameUpdates;
        } else if (nowNs - startNs_ >= 1000000000ull) {
            const double seconds = double(nowNs - startNs_) * 1e-9;
            const auto count = frames - startFrames_;
            reading_.fps = tenths(double(count) / seconds);
            reading_.frameMs = count ? tenths(seconds * 1000.0 / double(count)) : 0;
            reading_.ups = tenths(double(gameUpdates - startUpdates_) / seconds);
            startNs_ = nowNs; startFrames_ = frames; startUpdates_ = gameUpdates;
        }
        return reading_;
    }
};
}
