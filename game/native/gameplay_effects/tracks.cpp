#include "tracks.hpp"
#include <algorithm>
#include <bit>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_effects {
namespace {
template<class T>T read(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Truncated native effect track asset");
    T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;
}
float& component(transform_math::Vector& vector,unsigned index){
    if(index==0)return vector.x;
    if(index==1)return vector.y;
    return vector.z;
}
std::int16_t angle(float sample){
    const float scaled=std::bit_cast<float>(0x3cb40000u)*sample;
    const float turns=65536.f*scaled;
    const float degrees=turns/360.f;
    const float rounded=.5f+degrees;
    // Signed16 linear source values bound this result well inside int32.
    return std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(rounded)));
}
}
Curve Curve::import(std::span<const std::byte> bytes,std::size_t offset,std::int16_t count){
    Curve curve;
    // Literal source count-zero predecessor and negative-count first-value
    // profiles are admitted only when that value belongs to this asset span.
    if(count<=0){
        if(count==0){if(offset<4)throw std::invalid_argument("Effect zero-key predecessor outside asset");offset-=4;}
        curve.keys_.push_back({read<std::int16_t>(bytes,offset),0});return curve;
    }
    if(offset>bytes.size()||std::size_t(count)>(bytes.size()-offset)/4)throw std::invalid_argument("Effect key count exceeds asset");
    curve.keys_.reserve(std::size_t(count));
    for(std::int32_t i=0;i<count;++i){const auto key=read<Key>(bytes,offset+4*std::size_t(i));
        curve.keys_.push_back(key);
    }
    return curve;
}
float Curve::sample(std::int16_t time)const{
    transform_math::require_profile();
    if(keys_.empty())throw std::logic_error("Uninitialized native effect curve");
    // The original scans in authored order, including descending/duplicate
    // timestamps. Every preceding key is <= query, so an interior denominator
    // is positive without imposing an extra sorted-data admission rule.
    const auto next=std::find_if(keys_.begin(),keys_.end(),[time](const Key& key){return time<key.time;});
    if(next==keys_.begin())return float(next->value);
    if(next==keys_.end())return float(keys_.back().value);
    const auto previous=next-1;
    const float elapsed=float(time)-float(previous->time),span=float(next->time)-float(previous->time);
    const float fraction=elapsed/span,delta=float(next->value)-float(previous->value);
    const float interpolated=fraction*delta;return float(previous->value)+interpolated;
}
std::shared_ptr<const Tracks> Tracks::import(std::span<const std::byte> bytes){
    constexpr std::size_t base=1024;
    if(bytes.size()<base+20)throw std::invalid_argument("Truncated native effect mapping/header");
    auto tracks=std::make_shared<Tracks>();std::size_t count{};
    for(std::size_t i=0;i<512;++i){
        tracks->mapping_[i]=read<std::uint8_t>(bytes,i);tracks->variants_[i]=read<std::int8_t>(bytes,512+i);
        if(tracks->mapping_[i]!=255)count=std::max(count,std::size_t(tracks->mapping_[i])+std::size_t(std::max(1,int(tracks->variants_[i]))));
    }
    if(!count||count>(bytes.size()-base)/20)throw std::invalid_argument("Invalid native effect group extent");
    const auto table_end=count*20;tracks->groups_.resize(count);
    for(std::size_t i=0;i<count;++i){
        const auto header=base+20*i;const auto group_offset=read<std::uint32_t>(bytes,header);
        const auto parts=read<std::uint16_t>(bytes,header+12);
        auto& group=tracks->groups_[i];group.lifetime=read<std::int16_t>(bytes,header+18);
        if(!parts)continue;
        if(group_offset<table_end||group_offset>bytes.size()-base||std::size_t(parts)>(bytes.size()-base-group_offset)/8)
            throw std::invalid_argument("Native effect part table exceeds asset");
        group.parts.reserve(parts);
        for(std::size_t j=0;j<parts;++j){
            const auto part_at=base+std::size_t(group_offset)+8*j;
            Part part;part.resource=read<std::uint8_t>(bytes,part_at+4);part.material=read<std::uint8_t>(bytes,part_at+5);part.selector=read<std::uint8_t>(bytes,part_at+6);
            const auto channels=read<std::uint8_t>(bytes,part_at+7);const auto channel_offset=read<std::uint32_t>(bytes,part_at);
            if(channel_offset>bytes.size()-base||std::size_t(channels)>(bytes.size()-base-channel_offset)/8)
                throw std::invalid_argument("Native effect channel table exceeds asset");
            part.channels.reserve(channels);
            for(std::size_t k=0;k<channels;++k){
                const auto at=base+std::size_t(channel_offset)+8*k;Channel channel;channel.kind=read<std::int16_t>(bytes,at+6);
                if(channel.kind>=0&&channel.kind<=11){
                    const auto key_offset=read<std::uint32_t>(bytes,at);
                    if(key_offset>bytes.size()-base)throw std::invalid_argument("Native effect keys exceed asset");
                    channel.curve=Curve::import(bytes,base+std::size_t(key_offset),read<std::int16_t>(bytes,at+4));
                }
                part.channels.push_back(std::move(channel));
            }
            group.parts.push_back(std::move(part));
        }
    }
    return tracks;
}
std::optional<std::size_t> Tracks::resolve(std::uint16_t logical,std::int16_t variant)const noexcept{
    if(logical>=mapping_.size()||mapping_[logical]==255)return{};
    const auto selected=std::int32_t(mapping_[logical])+variant;
    if(selected<0||std::size_t(selected)>=groups_.size())return{};
    return std::size_t(selected);
}
std::int8_t Tracks::variants(std::uint16_t logical)const{
    if(logical>=variants_.size())throw std::out_of_range("Native effect logical ID outside admitted mapping");
    return variants_[logical];
}
const Group* Tracks::group(std::size_t index)const noexcept{return index<groups_.size()?&groups_[index]:nullptr;}
void sample_transform(std::span<const Channel> channels,std::int16_t time,Parameters& output){
    transform_math::require_profile();
    for(const auto& channel:channels){
        if(channel.kind<0||channel.kind>8)continue;
        if(!channel.curve)throw std::invalid_argument("Native effect transform curve unavailable");
        const auto value=channel.curve->sample(time);
        if(channel.kind<3)component(output.translation,unsigned(channel.kind))=value/16.f;
        else if(channel.kind<6)output.rotation[unsigned(channel.kind-3)]=angle(value);
        else component(output.scale,unsigned(channel.kind-6))=value/16.f;
    }
}
}
