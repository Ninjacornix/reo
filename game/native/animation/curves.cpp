#include "curves.hpp"
#include "../transform_math/transform_math.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <cstring>
#include <stdexcept>

namespace reo::native::animation {
namespace {
template<class T>T read(std::span<const std::byte> bytes,std::size_t at){if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Truncated native animation asset");T v;std::memcpy(&v,bytes.data()+at,sizeof v);return v;}
float finite(float v){if(!std::isfinite(v))throw std::domain_error("Native animation finite FP32 profile required");return v;}
float add(float a,float b){return finite(a+b);}
float sub(float a,float b){return finite(a-b);}
float mul(float a,float b){return finite(a*b);}
std::size_t stride(std::uint8_t format){switch(format){case 0x21:return 8;case 0x22:return 16;case 0x23:return 20;case 0x11:return 4;case 0x12:return 8;case 0x13:return 12;default:throw std::invalid_argument("Unsupported native animation curve format");}}
}
float interpolate_linear(float time,float a,float ta,float b,float tb){
    const float q=finite(1.f/sub(tb,ta));
    const float slope=mul(sub(b,a),q),intercept=mul(sub(mul(tb,a),mul(ta,b)),q);
    return add(mul(slope,time),intercept);
}
float interpolate_cubic(float time,float a,float ta,float outgoing,float b,float tb,float incoming){
    const float d=sub(time,ta),q=finite(1.f/sub(tb,ta));
    const float q2=mul(q,q),d2=mul(d,d),d2q=mul(d2,q),d3q2=mul(mul(d2,d),q2);
    const float x=mul(mul(2.f,d3q2),q),y=mul(mul(3.f,d2),q2);
    float result=mul(a,add(sub(x,y),1.f));result=add(result,mul(b,sub(y,x)));
    result=add(result,mul(outgoing,add(sub(sub(d3q2,d2q),d2q),d)));
    return add(result,mul(incoming,sub(d3q2,d2q)));
}
Curve Curve::import(std::uint8_t format,std::uint8_t channel,std::span<const std::byte> bytes,std::size_t count){
    if(channel>=10||count==0||count>32767)throw std::invalid_argument("Native curve channel/count outside admitted cache profile");
    const auto step=stride(format);if(count>bytes.size()/step)throw std::invalid_argument("Truncated native curve keys");
    Curve curve;curve.format_=format;curve.channel_=channel;curve.keys_.reserve(count);
    const bool compact=(format&0xf0)==0x10,mixed=(format&0xf)==3,cubic=(format&0xf)==2;
    for(std::size_t i=0;i<count;++i){
        const auto at=i*step+(mixed?4:0);const auto scalar=[&](unsigned j){return compact?float(read<std::int16_t>(bytes,at+2*j)):read<float>(bytes,at+4*j);};
        Key key;key.value=finite(scalar(0));key.time=finite(scalar(1));if(cubic||mixed){key.incoming=finite(scalar(2));key.outgoing=finite(scalar(3));}if(mixed)key.kind=read<std::uint32_t>(bytes,i*step);else key.kind=cubic?0x20000:0x10000;
        if(!curve.keys_.empty()&&curve.keys_.back().time>key.time)throw std::invalid_argument("Native curve keys require nondecreasing finite times");
        curve.keys_.push_back(key);
    }
    return curve;
}
float Curve::sample(float frame,std::int16_t& cache)const{
    transform_math::require_profile();finite(frame);
    const auto& first=keys_.front();if(frame<=first.time||keys_.size()==1){cache=0;return first.value;}
    const auto& last=keys_.back();if(!(frame<last.time)){cache=std::int16_t(keys_.size()-1);return last.value;}
    auto i=std::clamp<std::ptrdiff_t>(cache,0,std::ptrdiff_t(keys_.size()-1));
    while(true){const auto& key=keys_[std::size_t(i)];if(key.time==frame){cache=std::int16_t(i);return key.value;}if(key.time<frame&&frame<keys_[std::size_t(i+1)].time)break;i+=frame<key.time?-1:1;}
    cache=std::int16_t(i);const auto& a=keys_[std::size_t(i)];const auto& b=keys_[std::size_t(i+1)];
    if(a.kind==0x10000)return interpolate_linear(frame,a.value,a.time,b.value,b.time);
    if(a.kind==0x20000)return interpolate_cubic(frame,a.value,a.time,a.outgoing,b.value,b.time,b.incoming);
    return 0; // Original mixed-key unknown segment kind has this defined result.
}
std::shared_ptr<const Clip> Clip::import_raw(std::span<const std::byte> bytes){
    if(bytes.size()<20)throw std::invalid_argument("Truncated raw animation clip");
    const auto mode=read<std::uint32_t>(bytes,0)&255;
    if(mode!=1&&mode!=2)throw std::invalid_argument("Unsupported raw animation channel mode");
    const auto count=read<std::uint32_t>(bytes,4),length=read<std::uint32_t>(bytes,8);
    if(!count||count>32767||length<20||length>bytes.size())throw std::invalid_argument("Invalid native clip extent/count");
    bytes=bytes.first(length);
    auto clip=std::make_shared<Clip>();clip->looping_=read<std::uint32_t>(bytes,12)!=0;clip->loop_start_=clip->looping_?finite(read<float>(bytes,16)):0;clip->first_=1e10f;clip->last_=0;
    std::size_t at=20;for(std::size_t i=0;i<count;++i){
        const auto channels=read<std::uint32_t>(bytes,at+4),size=read<std::uint32_t>(bytes,at+8);if(size<12||at>bytes.size()||size>bytes.size()-at||channels>32767)throw std::invalid_argument("Invalid raw animation track extent");
        Track track;track.quantized=mode==2;std::size_t current=at+12;
        for(std::size_t j=0;j<channels;++j){
            const auto flags=read<std::uint32_t>(bytes,current),n=read<std::uint32_t>(bytes,current+4),span=read<std::uint32_t>(bytes,current+8);if(span<12||current>at+size||span>at+size-current)throw std::invalid_argument("Invalid raw animation channel extent");
            if(!(flags&0x80000000u))throw std::invalid_argument("Inactive raw channel has undefined original sampled result; unsupported");
            const unsigned selector=flags&0x1ffu;if(!selector||(selector&(selector-1)))throw std::invalid_argument("Non-one-hot animation channel selector outside admitted profile");
            const auto index=std::uint8_t(std::countr_zero(selector)),format=std::uint8_t(flags>>16);auto curve=Curve::import(format,index,bytes.subspan(current+12,span-12),n);
            clip->first_=std::min(clip->first_,curve.keys().front().time);clip->last_=std::max(clip->last_,curve.keys().back().time);track.curves.push_back(std::move(curve));current+=span;
        }
        if(current!=at+size)throw std::invalid_argument("Unconsumed animation channel bytes");
        clip->tracks_.push_back(std::move(track));at+=size;
    }
    if(at!=length)throw std::invalid_argument("Unconsumed raw clip records");
    return clip;
}
void sample_parameters(const Track& track,float frame,Parameters& values,Caches& caches){
    for(const auto& curve:track.curves){const auto index=curve.channel();float value=curve.sample(frame,caches[index]);values[index]=value;if(track.quantized){if(index>=3&&index<=5)value=mul(value,std::bit_cast<float>(0x39c90fdbu));else value=finite(value/16.f);values[index]=value;}}
}
} // namespace reo::native::animation
