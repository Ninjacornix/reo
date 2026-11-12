#include "fullscreen_color.hpp"
#include <bit>
#include <cmath>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
template<class T>T field(std::span<const std::byte> bytes,std::size_t at){T result;std::memcpy(&result,bytes.data()+at,sizeof result);return result;}
std::uint32_t truncate(float value)noexcept{
    if(!std::isfinite(value)||value>=2147483648.0f||value<-2147483648.0f)return std::signbit(value)?0x80000000u:0x7fffffffu;
    return std::bit_cast<std::uint32_t>(static_cast<std::int32_t>(value));
}
std::uint32_t pack(const std::array<std::uint32_t,4>& channels)noexcept{
    return (channels[0]<<16)|(channels[1]<<8)|channels[2]|(channels[3]<<24);
}
}
std::shared_ptr<const FullscreenColorStream> FullscreenColorStream::import(std::span<const std::byte> bytes){
    if(bytes.size()%40||bytes.size()/40>65536)throw std::invalid_argument("Native fullscreen curve extent unavailable");
    auto result=std::shared_ptr<FullscreenColorStream>(new FullscreenColorStream);result->keys_.reserve(bytes.size()/40);
    for(std::size_t at=0;at<bytes.size();at+=40)result->keys_.push_back({field<std::uint16_t>(bytes,at+2),field<std::uint32_t>(bytes,at+4),field<std::array<std::uint16_t,4>>(bytes,at+8)});
    return result;
}
void FullscreenColor::reset(std::uint32_t color)noexcept{
    state_={};state_.rectangle={0,0,640,480,color};stream_.reset();position_.reset();
}
FullscreenColorStatus FullscreenColor::bind(std::shared_ptr<const FullscreenColorSource> stream,std::size_t position)noexcept{
    const auto key=stream?stream->key(position):std::nullopt;
    if(!key)return FullscreenColorStatus::unavailable;
    if(key->kind==2){stream_=std::move(stream);position_=position;}
    return FullscreenColorStatus::completed;
}
FullscreenColorStatus FullscreenColor::sample(std::uint32_t frame)noexcept{
    if(!position_)return FullscreenColorStatus::completed;
    const auto current_key=stream_->key(*position_);if(!current_key)return FullscreenColorStatus::unavailable;
    const auto& current=*current_key;std::optional<FullscreenColorKey> next;
    for(std::size_t step=1;step<=32;++step){
        const auto key=stream_->key(*position_+step);if(!key)return FullscreenColorStatus::unavailable;
        if(key->kind==2){if(key->frame!=65535&&current.frame<key->frame)next=*key;break;}
        if(step==32)return FullscreenColorStatus::completed;
    }
    std::array<std::uint32_t,4> channels{};
    if(next){
        const auto denominator=std::int32_t(next->frame>>1)-std::int32_t(current.frame>>1);
        const auto t=denominator?float(std::bit_cast<std::int32_t>(frame)/2-std::int32_t(current.frame>>1))/float(denominator):1.0f;
        for(unsigned channel=0;channel<4;++channel){const auto first=float(current.channels[channel]);channels[channel]=truncate(first+t*(float(next->channels[channel])-first));}
    }else for(unsigned channel=0;channel<4;++channel)channels[channel]=current.channels[channel];
    state_.rectangle.color=pack(channels);return FullscreenColorStatus::completed;
}
} // namespace reo::native::gameplay_scenario
