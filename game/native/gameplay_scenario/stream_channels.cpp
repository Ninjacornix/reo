#include "stream_channels.hpp"
#include <bit>
#include <cmath>

namespace reo::native::gameplay_scenario {
namespace {
std::int32_t truncate_word(float value)noexcept{
    const auto bits=std::bit_cast<std::uint32_t>(value);const auto exponent=(bits>>23)&255u;
    if(exponent>157)return std::bit_cast<std::int32_t>((bits&0x80000000u)?0x80000000u:0x7fffffffu);
    if(exponent<127)return 0;
    const auto power=exponent-127,significand=(bits&0x7fffffu)|0x800000u;
    const auto magnitude=power>=23?significand<<(power-23):significand>>(23-power);
    return std::bit_cast<std::int32_t>((bits&0x80000000u)?0u-magnitude:magnitude);
}
StreamStatus combine(StreamStatus first,StreamStatus next)noexcept{
    if(!stream_accepted(first))return first;
    if(!stream_accepted(next))return next;
    return first==StreamStatus::pending||next==StreamStatus::pending?StreamStatus::pending:StreamStatus::completed;
}
float ramp_ratio(float numerator,std::int32_t calls)noexcept{
    if(calls)return numerator/float(calls);
    // The owned division's zero-denominator result is signed maximum finite,
    // including0/0. Preserve the game state result without CPU status flags.
    return std::bit_cast<float>(0x7f7fffffu|(std::bit_cast<std::uint32_t>(numerator)&0x80000000u));
}
}
StreamStatus StreamChannels::restore(const StreamChannelSnapshot& value)noexcept{
    for(const auto& c:value.channels)if(c.maximum<0||c.maximum>323||c.current<0||c.current>323||
        !std::isfinite(c.level)||c.level<0.0f||!std::isfinite(c.step))return StreamStatus::unsupported_profile;
    state_=value;return StreamStatus::completed;
}
StreamStatus StreamChannels::level(std::uint8_t index,std::int32_t requested,StreamBackend& backend)noexcept{
    if(index>=state_.channels.size())return StreamStatus::invalid_channel;
    auto& channel=state_.channels[index];const float ratio=float(requested)/127.0f;
    const auto quantized=std::uint32_t(truncate_word(ratio*float(channel.maximum)))&127u;
    const auto result=backend.attenuation(index,curve_[quantized]/10);
    channel.current=std::int32_t(quantized);channel.level=float(quantized);channel.step=0;return result;
}
StreamStatus StreamChannels::maximum(std::uint8_t index,std::int32_t requested,StreamBackend& backend)noexcept{
    if(index>=state_.channels.size())return StreamStatus::invalid_channel;
    auto& channel=state_.channels[index];const auto maximum=std::int32_t(std::uint32_t(requested)&127u);
    const auto result=backend.attenuation(index,curve_[std::size_t(maximum)]/10);channel.maximum=maximum;
    if(channel.current>maximum)channel.current=maximum;
    if(!(channel.level<=float(maximum)))channel.level=float(maximum);
    return result;
}
StreamStatus StreamChannels::ramp(std::uint8_t index,std::int32_t target,std::int32_t calls)noexcept{
    if(index>=state_.channels.size())return StreamStatus::invalid_channel;
    auto& channel=state_.channels[index];if(target>channel.maximum)target=channel.maximum;
    const float delta=float(target)-channel.level;channel.step=ramp_ratio(delta,calls);channel.target=target;return StreamStatus::completed;
}
StreamResult StreamChannels::start(std::uint8_t index,std::int32_t member,std::int32_t archive,std::uint32_t tick,StreamBackend& backend)noexcept{
    if(index>=state_.channels.size())return{StreamStatus::invalid_channel,0};
    if(features_.suppress_all||(features_.suppress_channel_zero&&index==0))return{};
    auto& channel=state_.channels[index];auto result=level(index,channel.maximum,backend);
    result=combine(result,backend.start(index,{archive<0?0u:std::uint32_t(archive),member},tick));
    result=combine(result,backend.pause(index,false,tick));channel.paused=0;return{result,0};
}
StreamStatus StreamChannels::stop(std::uint8_t index,StreamBackend& backend)noexcept{
    if(index>=state_.channels.size())return StreamStatus::invalid_channel;
    state_.channels[index].paused=0;return backend.stop(index);
}
StreamValue StreamChannels::prepared_ready(std::uint8_t index,StreamBackend& backend)noexcept{
    if(index>=state_.channels.size())return{StreamStatus::invalid_channel,0};
    if(features_.suppress_all)return{StreamStatus::completed,1};
    const auto available=backend.instance_available(index);if(!stream_accepted(available.status))return available;
    if(!available.value||!state_.channels[index].started)return{available.status,1};
    return backend.start_ready(index);
}
StreamStatus StreamChannels::release_start(std::uint8_t index,StreamBackend& backend)noexcept{
    if(index>=state_.channels.size())return StreamStatus::invalid_channel;
    if(features_.suppress_all)return StreamStatus::completed;
    const auto available=backend.instance_available(index);if(!stream_accepted(available.status))return available.status;
    if(!available.value)return available.status;
    auto& channel=state_.channels[index];channel.start_wait=0;
    const auto released=backend.start_inhibit(index,false);if(!stream_accepted(released))return released;
    const auto restored=level(index,channel.maximum,backend);if(!stream_accepted(restored))return restored;
    channel.started=0;return combine(released,restored);
}
StreamStatus StreamChannels::stop_preserving_state(std::uint8_t index,StreamBackend& backend)noexcept{
    if(index>=state_.channels.size())return StreamStatus::invalid_channel;
    if(features_.suppress_all)return StreamStatus::completed;
    const auto available=backend.instance_available(index);if(!stream_accepted(available.status))return available.status;
    return available.value?backend.stop(index):available.status;
}
StreamStatus StreamChannels::pause(std::uint8_t index,std::uint32_t tick,StreamBackend& backend)noexcept{
    if(index>=state_.channels.size())return StreamStatus::invalid_channel;
    state_.channels[index].paused=1;return backend.pause(index,true,tick);
}
StreamStatus StreamChannels::resume_current(std::uint8_t index,std::uint32_t tick,StreamBackend& backend)noexcept{
    if(index>=state_.channels.size())return StreamStatus::invalid_channel;
    auto& channel=state_.channels[index];auto result=level(index,channel.current,backend);channel.paused=0;
    return combine(result,backend.pause(index,false,tick));
}
StreamResult StreamChannels::request(std::uint8_t index,std::int32_t member,std::int32_t archive,std::uint32_t tick,StreamBackend& backend)noexcept{
    if(index>=state_.channels.size())return{StreamStatus::invalid_channel,0};
    auto& cached=state_.requested_ids[index];if(cached!=member){cached=member;return start(index,member,archive,tick,backend);}
    if(!state_.channels[index].paused)return start(index,member,archive,tick,backend);
    const auto phase=backend.phase(index);if(!stream_accepted(phase.status))return{phase.status,0};
    if(phase.value==0||phase.value==5)return start(index,member,archive,tick,backend);
    const auto result=resume_current(index,tick,backend);ramp(index,127,60);return{result,1};
}
StreamStatus StreamChannels::service(std::uint32_t tick,StreamBackend& backend)noexcept{
    std::array<float,3> next_levels{};std::array<std::int32_t,3> next_quantized{};
    // Reject numeric states outside the admitted engine profile before any
    // output call/state publication; suspect code-generator edge behavior is
    // not promoted into native game policy.
    for(std::size_t i=0;i<3;++i){const auto& channel=state_.channels[i];if(channel.paused||channel.step==0.0f)continue;
        float next=channel.level+channel.step;if(next<0.0f)next=0.0f;
        const float scaled=(next/127.0f)*float(channel.maximum);if(!std::isfinite(scaled))return StreamStatus::unsupported_profile;
        auto quantized=truncate_word(scaled);if(quantized>channel.maximum){quantized=channel.maximum;next=float(channel.maximum);}
        next_levels[i]=next;next_quantized[i]=quantized;
    }
    auto result=StreamStatus::completed;state_.loading=false;
    if(!features_.suppress_all)for(std::uint8_t i=0;i<3;++i){const auto phase=backend.phase(i);result=combine(result,phase.status);
        if(stream_accepted(phase.status)&&(phase.value==1||phase.value==2)){state_.loading=true;break;}}
    for(std::uint8_t i=0;i<3;++i){auto& channel=state_.channels[i];if(channel.paused||channel.step==0.0f)continue;
        const auto next=next_levels[i];const auto quantized=next_quantized[i];
        if(quantized!=channel.current)result=combine(result,backend.attenuation(i,curve_[std::uint32_t(quantized)&127u]/10));
        channel.current=quantized;channel.level=next;
        if((channel.current>=channel.target&&!(channel.step<=0.0f))||(channel.current<=channel.target&&channel.step<0.0f))channel.step=0;
    }
    return combine(result,backend.service(tick));
}
std::array<std::int32_t,128> file1_stream_gain_curve()noexcept{
    return {
#include "stream_gain_curve.inc"
    };
}
} // namespace reo::native::gameplay_scenario
