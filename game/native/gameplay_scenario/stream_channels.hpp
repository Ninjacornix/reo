#pragma once
#include <array>
#include <cstddef>
#include <cstdint>

namespace reo::native::gameplay_scenario {
enum class StreamStatus { completed,pending,closed,busy,invalid_channel,unbound,missing_asset,unsupported_profile,fault };
constexpr bool stream_accepted(StreamStatus s)noexcept{return s==StreamStatus::completed||s==StreamStatus::pending;}
struct StreamValue {StreamStatus status{StreamStatus::fault};std::int32_t value{};};
struct StreamRequest {std::uint32_t archive{};std::int32_t member{};};
// Primitive native decoder/output operations, not opaque engine-call wrappers.
// Implementations must use native source identities; no guest RAM/callbacks.
class StreamBackend {
public:
    virtual ~StreamBackend()=default;
    virtual StreamValue phase(std::uint8_t channel)noexcept=0;
    virtual StreamStatus start(std::uint8_t,StreamRequest,std::uint32_t tick)noexcept=0;
    virtual StreamStatus stop(std::uint8_t)noexcept=0;
    virtual StreamStatus pause(std::uint8_t,bool,std::uint32_t tick)noexcept=0;
    virtual StreamStatus attenuation(std::uint8_t,std::int32_t)noexcept=0;
    virtual StreamStatus service(std::uint32_t tick)noexcept=0;
};
struct StreamChannel {
    std::int8_t paused{};std::uint8_t type{},start_wait{},started{};
    std::int32_t current{},maximum{},target{};
    float step{},level{};
};
struct StreamChannelSnapshot {
    std::array<StreamChannel,3> channels{};
    std::array<std::int32_t,3> requested_ids{};
    bool loading{};
};
struct StreamFeatureGates {bool suppress_all{},suppress_channel_zero{};};
struct StreamResult {StreamStatus status{StreamStatus::completed};std::int32_t original_return{};};
// Three authoritative engine channels, distinct from decoder source instances.
// One simulation controller; service advances call-based ramps exactly once per
// explicit engine service invocation, never from host time or audio callbacks.
class StreamChannels final {
public:
    explicit StreamChannels(std::array<std::int32_t,128> gain_curve)noexcept:curve_(gain_curve){}
    const StreamChannelSnapshot& snapshot()const noexcept{return state_;}
    StreamStatus restore(const StreamChannelSnapshot&)noexcept;
    void features(StreamFeatureGates value)noexcept{features_=value;}
    StreamResult request(std::uint8_t channel,std::int32_t member,std::int32_t archive,std::uint32_t tick,StreamBackend&)noexcept;
    StreamResult start(std::uint8_t channel,std::int32_t member,std::int32_t archive,std::uint32_t tick,StreamBackend&)noexcept;
    StreamStatus stop(std::uint8_t,StreamBackend&)noexcept;
    StreamStatus pause(std::uint8_t,std::uint32_t tick,StreamBackend&)noexcept;
    StreamStatus resume_current(std::uint8_t,std::uint32_t tick,StreamBackend&)noexcept;
    StreamStatus level(std::uint8_t,std::int32_t,StreamBackend&)noexcept;
    StreamStatus maximum(std::uint8_t,std::int32_t,StreamBackend&)noexcept;
    StreamStatus ramp(std::uint8_t,std::int32_t target,std::int32_t calls)noexcept;
    StreamStatus service(std::uint32_t tick,StreamBackend&)noexcept;
private:
    StreamChannelSnapshot state_;
    std::array<std::int32_t,128> curve_;
    StreamFeatureGates features_;
};
// Exact immutable File1 engine gain curve at234060, checked by offline tools.
std::array<std::int32_t,128> file1_stream_gain_curve()noexcept;
} // namespace reo::native::gameplay_scenario
