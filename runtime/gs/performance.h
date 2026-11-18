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

// Start at the main menu (REO_SKIP_INTRO=1). The boot logo screens are skipped in the
// boot scene handler (reo_bootstrap.cpp) and the CAPCOM opening and title prompt are
// answered with Start (reo_hw_bridge.cpp). Nothing runs hidden: intro_hidden() stays
// false; intro_finished records that the main menu was reached.
inline bool skip_intro() {
    static const bool value = [] {
        const char* v = std::getenv("REO_SKIP_INTRO");
        return v && std::strcmp(v, "1") == 0;
    }();
    return value;
}
inline std::atomic<bool> intro_finished{false};
inline bool intro_hidden() { return false; }
// Network Game straight to SERVER SELECT: from choosing Network in the main menu until the
// original server list appears, the connection prompts and sign-in run automatically
// (automatic account provider) behind a black screen with a "connecting" spinner, audio
// muted. Set by reo_hw_bridge.cpp (pad2NetworkVeil), which also applies a time limit.
inline std::atomic<bool> network_veil{false};
// What the connecting screen says under the spinner (present_performance.glsl statusText):
// 0 connecting, 1 loading network settings, 2 connecting to the network, 3 preparing your
// account, 4 signing in, 5 joining the lobby.
inline std::atomic<int> network_stage{0};
inline bool screen_hidden() { return intro_hidden() || network_veil.load(std::memory_order_relaxed); }

// Presentation warp (60 fps camera motion while the game updates at 30 Hz).
// The modern camera publishes its eye, view direction and vertical lens once per game
// update. The presenter shows each game frame twice; the repeated scanout is drawn
// as seen from the camera half an update later:
//  - depth mode: the frame's GS Z buffer (snapshot at the flip) gives every pixel's
//    3D point, which is reprojected into the in-between camera (rotation and
//    translation, so the orbiting third-person camera works);
//  - rotation mode (no depth mapping configured): a pure rotation, exact only for a
//    camera turning in place (first person).
// Conventions measured on real frames: vertical FOV = lens, 4:3 picture, screen x =
// -(up x forward), screen y = up (tools/hybrid/warp_validate.py).
namespace warp {
struct View {
    float eye[3]{}, forward[3]{}; float lens{}; bool rotation_only{}; bool valid{};
    int64_t ms{}; uint64_t serial{};
};
constexpr unsigned ring_size = 8;
inline std::atomic<uint32_t> sequence{0};  // seqlock: odd while writing
inline View ring[ring_size];
inline uint64_t latest_serial = 0;
inline std::atomic<uint32_t> scanout_fbp{0xffffffffu};
inline const char* option() { return std::getenv("REO_CAMERA_WARP"); }
// REO_CAMERA_WARP=0 disables the warp; =all also allows rotation-only warps of
// orbiting (third-person) views when no depth mapping is configured.
inline bool enabled() {
    static const bool value = [] { const char* v = option(); return !v || std::strcmp(v, "0") != 0; }();
    return value;
}
inline bool all_views() {
    static const bool value = [] { const char* v = option(); return v && std::strcmp(v, "all") == 0; }();
    return value;
}
// Z = a + b / d (d = distance along the view direction). Measured for Outbreak (both
// editions use the same VU1 projection): Z = 2^24 / d (tools/hybrid/depth_calibrate.py).
// REO_CAMERA_WARP_DEPTH=a,b overrides it; =off uses rotation-only warps.
struct DepthMapping { bool on{}; float a{}, b{}; };
inline DepthMapping depth_mapping() {
    static const DepthMapping value = [] {
        DepthMapping m{true, 0.f, 16777216.f};
        const char* v = std::getenv("REO_CAMERA_WARP_DEPTH");
        if (v && !std::strcmp(v, "off")) return DepthMapping{};
        if (v && *v) {
            m = DepthMapping{};
            m.a = float(std::atof(v));
            if (const char* c = std::strchr(v, ',')) { m.b = float(std::atof(c + 1)); m.on = m.b != 0.f; }
        }
        return m;
    }();
    return value;
}
// Game updates between the camera evaluation and the frame it is shown in. Measured: 2
// (view switches reach the scanout two camera updates later; REO_CAMERA_WARP_PROBE).
inline unsigned lag() {
    static const unsigned value = [] {
        const char* v = std::getenv("REO_CAMERA_WARP_LAG");
        return v ? unsigned(std::atoi(v)) : 2u;
    }();
    return value;
}
inline void write_begin() {
    sequence.store(sequence.load(std::memory_order_relaxed) + 1, std::memory_order_release);
    std::atomic_thread_fence(std::memory_order_release);
}
inline void write_end() { sequence.store(sequence.load(std::memory_order_relaxed) + 1, std::memory_order_release); }
inline void publish(const float eye[3], const float forward[3], float lens, bool rotation_only) {
    write_begin();
    const auto serial = ++latest_serial;
    ring[serial % ring_size] = View{{eye[0], eye[1], eye[2]}, {forward[0], forward[1], forward[2]}, lens,
                                    rotation_only, true, steady_ms(), serial};
    write_end();
}
inline void clear() {
    write_begin();
    for (auto& v : ring) v.valid = false;
    ++latest_serial;
    write_end();
}
inline bool read(View (&out)[ring_size], uint64_t& serial) {
    for (int attempt = 0; attempt < 8; ++attempt) {
        const auto a = sequence.load(std::memory_order_acquire);
        if (a & 1u) continue;
        for (unsigned i = 0; i < ring_size; ++i) out[i] = ring[i];
        serial = latest_serial;
        std::atomic_thread_fence(std::memory_order_acquire);
        if (sequence.load(std::memory_order_relaxed) == a) return true;
    }
    return false;
}
inline uint64_t current_serial() {
    View views[ring_size]; uint64_t serial = 0;
    return read(views, serial) ? serial : 0;
}
// mode: 0 none, 1 rotation, 2 depth. Rotation mode: rows map shown NDC (nx, ny, 1)
// to the rendered frame (v = M q, ndc = v.xy / v.z). Depth mode: rows hold the
// rendered camera -> shown camera rotation with the translation in .w (camera axes
// r, u, f). params: tan half-angles (x, y) and the depth mapping a, b.
struct Result {
    float rows[12]{}; float params[4]{}; uint32_t mode{};
    float yaw_degrees{}, pitch_degrees{}, move{}; bool repeat{};
};
struct Basis { float f[3], r[3], u[3]; };
inline Basis basis(float yaw, float pitch) {
    Basis b{};
    pitch = std::fmax(-1.55f, std::fmin(1.55f, pitch));
    const float cp = std::cos(pitch);
    b.f[0] = std::sin(yaw) * cp; b.f[1] = std::sin(pitch); b.f[2] = std::cos(yaw) * cp;
    b.r[0] = std::cos(yaw); b.r[1] = 0.f; b.r[2] = -std::sin(yaw);  // up x forward
    b.u[0] = b.f[1] * b.r[2] - b.f[2] * b.r[1];                      // forward x right
    b.u[1] = b.f[2] * b.r[0] - b.f[0] * b.r[2];
    b.u[2] = b.f[0] * b.r[1] - b.f[1] * b.r[0];
    return b;
}
inline float dot3(const float* a, const float* b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
inline void build(float yaw_d, float pitch_d, float yaw_t, float pitch_t, float lens, Result& out) {
    const float ty = std::tan(lens * 0.5f * 0.0174532925f), tx = ty * (4.f / 3.f);
    const Basis D = basis(yaw_d, pitch_d), T = basis(yaw_t, pitch_t);
    // Shown ray: d = (-tx nx) r_T + (ty ny) u_T + f_T. Source NDC: x = -(d.r_D)/tx / (d.f_D), y = (d.u_D)/ty / (d.f_D).
    float* m = out.rows;
    m[0] = dot3(T.r, D.r);              m[1] = -ty * dot3(T.u, D.r) / tx;  m[2] = -dot3(T.f, D.r) / tx;
    m[4] = -tx * dot3(T.r, D.u) / ty;   m[5] = dot3(T.u, D.u);             m[6] = dot3(T.f, D.u) / ty;
    m[8] = -tx * dot3(T.r, D.f);        m[9] = ty * dot3(T.u, D.f);        m[10] = dot3(T.f, D.f);
    m[3] = 1.f;  // enabled
    out.params[0] = tx; out.params[1] = ty;
    out.mode = 1;
}
inline void build_depth(const float eye_d[3], float yaw_d, float pitch_d, const float eye_t[3], float yaw_t,
                        float pitch_t, float lens, DepthMapping mapping, Result& out) {
    const float ty = std::tan(lens * 0.5f * 0.0174532925f), tx = ty * (4.f / 3.f);
    const Basis D = basis(yaw_d, pitch_d), T = basis(yaw_t, pitch_t);
    const float* d_axes[3] = {D.r, D.u, D.f};
    const float* t_axes[3] = {T.r, T.u, T.f};
    const float delta[3] = {eye_d[0] - eye_t[0], eye_d[1] - eye_t[1], eye_d[2] - eye_t[2]};
    for (unsigned i = 0; i < 3; ++i) {
        for (unsigned j = 0; j < 3; ++j) out.rows[i * 4 + j] = dot3(t_axes[i], d_axes[j]);
        out.rows[i * 4 + 3] = dot3(t_axes[i], delta);
    }
    out.params[0] = tx; out.params[1] = ty; out.params[2] = mapping.a; out.params[3] = mapping.b;
    out.mode = 2;
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
    View views[ring_size]; uint64_t serial = 0;
    const bool have = read(views, serial) && views[serial % ring_size].valid;
    const float lens = have ? views[serial % ring_size].lens : 40.f;
    out = Result{};
    build(0.f, 0.f, option.yaw * 0.0174532925f, option.pitch * 0.0174532925f, lens, out);
    out.yaw_degrees = option.yaw; out.pitch_degrees = option.pitch;
    return true;
}
inline float yaw_of(const View& v) { return std::atan2(v.forward[0], v.forward[2]); }
inline float pitch_of(const View& v) { return std::asin(std::fmax(-1.f, std::fmin(1.f, v.forward[1]))); }
inline float wrap(float a) {
    while (a > 3.14159265f) a -= 6.28318531f;
    while (a < -3.14159265f) a += 6.28318531f;
    return a;
}
// flip_serial: the newest camera view when the shown frame first reached the display.
inline bool compute(bool repeat_scanout, uint64_t flip_serial, bool depth_available, Result& out) {
    out = Result{}; out.repeat = repeat_scanout;
    if (!enabled() || !repeat_scanout || !flip_serial) return false;
    View views[ring_size]; uint64_t serial = 0;
    if (!read(views, serial)) return false;
    const auto get = [&](uint64_t s, View& v) {
        if (!s || s > serial || serial - s >= ring_size) return false;
        v = views[s % ring_size];
        return v.valid && v.serial == s;
    };
    const unsigned behind = lag();
    if (flip_serial <= behind) return false;
    View shown, other;
    if (!get(flip_serial - behind, shown)) return false;
    if (steady_ms() - shown.ms > 200 || shown.lens <= 1.f || shown.lens >= 170.f) return false;
    // In-between camera: halfway to the next view when it exists (exact interpolation),
    // otherwise half a step further along the last motion (extrapolation).
    float k = 0.5f;
    if (!get(shown.serial + 1, other)) {
        if (!get(shown.serial - 1, other)) return false;
        k = -0.5f;
    }
    const float dyaw = wrap(yaw_of(other) - yaw_of(shown)), dpitch = pitch_of(other) - pitch_of(shown);
    const float dx = other.eye[0] - shown.eye[0], dy = other.eye[1] - shown.eye[1], dz = other.eye[2] - shown.eye[2];
    const float move = std::sqrt(dx * dx + dy * dy + dz * dz);
    // Cuts, recentres, view and shoulder snaps are not motion.
    if (std::fabs(dyaw) > 0.35f || std::fabs(dpitch) > 0.35f || move > 150.f) return false;
    if (std::fabs(dyaw) < 1e-5f && std::fabs(dpitch) < 1e-5f && move < 1e-3f) return false;
    const float yaw_t = yaw_of(shown) + k * dyaw, pitch_t = pitch_of(shown) + k * dpitch;
    const auto mapping = depth_mapping();
    if (mapping.on && depth_available) {
        const float eye_t[3] = {shown.eye[0] + k * dx, shown.eye[1] + k * dy, shown.eye[2] + k * dz};
        build_depth(shown.eye, yaw_of(shown), pitch_of(shown), eye_t, yaw_t, pitch_t, shown.lens, mapping, out);
    } else if (shown.rotation_only || all_views()) {
        build(yaw_of(shown), pitch_of(shown), yaw_t, pitch_t, shown.lens, out);
    } else {
        return false;
    }
    out.yaw_degrees = k * dyaw * 57.2957795f; out.pitch_degrees = k * dpitch * 57.2957795f; out.move = std::fabs(k) * move;
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
