#pragma once
#include "session.hpp"
#include "../movie_timing_context/video_frames.hpp"
#include "../movie_audio_clock/session_source.hpp"
#include "../resource_io/async_read_owner.hpp"
#include <optional>
#include <span>
namespace reo::native::movie_lifecycle {
namespace timing=movie_timing_context;
class VideoBackend {
public:
    virtual ~VideoBackend()=default;
    // Pending feed/end must refuse before effects. Completed feed accepts all
    // bytes once. The backend owns demux, decoder, reference and frame storage.
    virtual Status feed(std::uint64_t,std::span<const std::byte>)noexcept=0;
    virtual Status end()noexcept=0;
    virtual Status service()noexcept=0;
    virtual void request_stop()noexcept=0;
    virtual Status poll_retired()noexcept=0;
    virtual void drain()noexcept=0;
};
class VideoFactory {
public:
    virtual ~VideoFactory()=default;
    virtual std::shared_ptr<VideoBackend> create(std::shared_ptr<timing::Context>,std::uint64_t)=0;
};
struct AudioRoute {
    std::shared_ptr<adxt_control_session::Session> session;
    std::shared_ptr<const resources::ByteView> input;
    adxt_control_session::player::Config player;
    adxt_control_session::Indices indices;
    std::shared_ptr<timing::audio::ServiceTick> tick;
};
struct GraphConfig {
    timing::Config clock;
    std::shared_ptr<VideoFactory> video;
    std::optional<AudioRoute> audio;
    std::size_t read_bytes{2048};
};
// Explicit prepared inputs: source is a positioned native ByteView; an optional
// audio input is an independently demuxed ADX view. This does not pretend that
// the existing video-only PES parser demuxes CRI audio/private streams.
class PreparedGraph final:public Graph {
public:
    PreparedGraph(GraphConfig,Recipe,std::uint64_t);
    ~PreparedGraph()override;
    [[nodiscard]] bool constructed()const noexcept{return constructed_;}
    Status service()noexcept override;
    void request_stop()noexcept override;
    Status poll_retired()noexcept override;
    void drain()noexcept override;
    const std::shared_ptr<timing::Context>& clock()const noexcept{return clock_;}
private:
    GraphConfig config_;Recipe recipe_;
    std::shared_ptr<resource_io::AsyncReadOwner> input_;
    struct Join;std::unique_ptr<Join> join_;
    std::shared_ptr<timing::Context> clock_;std::shared_ptr<VideoBackend> video_;
    std::optional<adxt_control_session::Key> audio_key_;
    resource_io::Ticket ticket_;std::vector<std::byte> bytes_;
    std::uint64_t offset_{};bool reading_{},ended_{},closing_{},audio_retired_{},detached_{},busy_{},constructed_{};
    bool begin_join()noexcept;
};
class PreparedFactory final:public Factory {
public:
    explicit PreparedFactory(GraphConfig config):config_(std::move(config)){}
    Build construct(const Recipe&,std::uint64_t)noexcept override;
private:GraphConfig config_;
};
}
