#pragma once
#include <cstdint>
#include <filesystem>
#include <memory>

struct ID3D11Device;
struct ID3D11Texture2D;
namespace reo::native::host_movie {
using Generation=std::uint64_t;
enum class State {closed,loading,ready,playing,paused,ended,error};
struct Options {bool loop{},muted{};double volume{1.0};};
struct Snapshot {
    Generation generation{};
    State state{State::closed};
    // Media Engine reports display size after pixel-aspect correction, rather
    // than the encoded sample dimensions. aspect_x:y is the picture aspect.
    std::uint32_t display_width{},display_height{},aspect_x{},aspect_y{},error_code{};
    std::int32_t extended_error{},shutdown_error{};
    double position_seconds{},duration_seconds{};
    std::uint64_t events{},transferred_frames{};
    bool has_audio{},seeking{},loop{};
};
struct Frame {bool updated{};Generation generation{};std::int64_t pts_100ns{};};

// Windows-native MP4 playback, independent of any game ABI or PS2 services.
// All calls/destruction use one externally serialized graphics-owner thread.
// The device must support video and BGRA and must not be SINGLETHREADED.
// Media Foundation uses its own asynchronous decoder/timing pipeline. Callbacks
// only retain per-open event counters, never Player/game pointers or controls.
class Player final {
public:
    explicit Player(ID3D11Device*);
    ~Player();
    Player(const Player&)=delete;
    Player& operator=(const Player&)=delete;
    // Existing local MP4 only. Invalid input refuses before replacing playback.
    // A fresh engine/callback lifetime prevents late old-source events from
    // becoming current state. Opening does not block waiting for readiness.
    [[nodiscard]] Generation open(const std::filesystem::path&,Options={});
    void play(Generation);
    void pause(Generation);
    void seek(Generation,double seconds);
    void loop(Generation,bool);
    void volume(Generation,double);
    void muted(Generation,bool);
    [[nodiscard]] Snapshot snapshot()const;
    // The native engine schedules the frame. Destination is a same-device,
    // single-sample BGRA8 render-target texture. Media Engine scales and
    // letterboxes into it using the source picture aspect. Present that texture
    // with square pixels; do not apply pixel-aspect correction twice. No new frame means
    // retain the previous texture. GPU consumption/fences belong to the caller;
    // returning updated does not claim that asynchronous GPU writes finished.
    [[nodiscard]] Frame transfer(Generation,ID3D11Texture2D*);
    void close()noexcept;
private:
    struct Impl;std::unique_ptr<Impl> impl_;
};
}
