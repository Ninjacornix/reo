#pragma once
#include "player.hpp"
#include "../movie_assets/catalogue.hpp"
#include <string>
#include <vector>

namespace reo::native::host_movie {
struct CpuFrame {
    Generation generation{};std::uint64_t serial{},ordinal{};
    std::int64_t pts_100ns{};
    std::uint32_t width{},height{},pitch{};
    std::vector<std::uint8_t> bgra;
};
struct SessionSnapshot {
    Generation generation{};State state{State::closed};
    bool device_ready{},paused{},loop{},joined{};
    std::uint64_t frames{},backpressure{},clip_index{},queued_clips{};
    double position_seconds{},duration_seconds{};
    std::string error;
};
// Native owner thread. The game supplies prepared assets/controls and receives
// immutable standard BGRA frames. No guest memory or callback crosses this API.
// The worker owns Media Engine/D3D11; a temporary renderer can copy these frames
// while a native compositor can use Player's texture interface directly.
class Session final {
public:
    Session();~Session();
    Session(const Session&)=delete;Session& operator=(const Session&)=delete;
    [[nodiscard]] Generation start(std::vector<std::shared_ptr<const movie_assets::Asset>>,bool loop=false,std::uint32_t output_width=512);
    [[nodiscard]] bool append(Generation,std::shared_ptr<const movie_assets::Asset>);
    [[nodiscard]] bool pause(Generation,bool);
    [[nodiscard]] bool loop(Generation,bool);
    [[nodiscard]] bool stop(Generation);
    [[nodiscard]] SessionSnapshot snapshot()const;
    [[nodiscard]] std::shared_ptr<const CpuFrame> frame(Generation)const;
    void request_stop()noexcept;
    void join()noexcept;
private:struct Impl;std::unique_ptr<Impl> impl_;
};
}
