#include "facial_curves.hpp"
#include <bit>
#include <cmath>
#include <cstring>
#include <stdexcept>
namespace reo::native::animation {
namespace {
template<class T>T field(std::span<const std::byte> bytes,std::size_t offset){
    if(offset>bytes.size()||sizeof(T)>bytes.size()-offset)throw std::invalid_argument("Native facial curve extent unavailable");
    T value;std::memcpy(&value,bytes.data()+offset,sizeof value);return value;
}
float finite(float value){
    if(!std::isfinite(value))throw std::domain_error("Native facial curve finite numeric profile required");
    return value;
}
std::int32_t signed_word(std::uint32_t value){return std::bit_cast<std::int32_t>(value);}
}
std::shared_ptr<const FacialCurves> FacialCurves::import(std::span<const std::byte> bytes){
    if(bytes.size()<20)throw std::invalid_argument("Native facial curve header unavailable");
    auto result=std::shared_ptr<FacialCurves>(new FacialCurves);
    for(unsigned channel=0;channel<5;++channel){
        auto offset=std::size_t(field<std::uint32_t>(bytes,channel*4));
        if(offset<20||offset%4)throw std::invalid_argument("Native facial curve offset unadmitted");
        auto& keys=result->channels_[channel];
        for(;;){
            const FacialKey key{field<std::int32_t>(bytes,offset),finite(field<float>(bytes,offset+4))};
            if(key.frame<0){keys.push_back(key);break;}
            if(!keys.empty()&&key.frame<=keys.back().frame)throw std::invalid_argument("Native facial curve increasing-time profile required");
            keys.push_back(key);offset+=8;
        }
        if(keys.size()<2)throw std::invalid_argument("Native facial curve initial segment unavailable");
    }
    return result;
}
FacialCurveStep advance_facial_curves(FacialCursor& state,const FacialCurves& curves){
    if(!state.active)return{};
    transform_math::require_profile();FacialWeights weights{};
    for(unsigned channel=0;channel<5;++channel){
        const auto keys=curves.channel(channel);const auto index=state.positions[channel];
        if(index>=keys.size()||keys.size()-index<2||keys[index].frame<0)
            throw std::out_of_range("Native facial curve current segment unavailable");
        const auto& first=keys[index];const auto& second=keys[index+1];
        const auto span=signed_word(std::uint32_t(second.frame)-std::uint32_t(first.frame));
        if(!span)throw std::domain_error("Native facial curve nonzero-duration profile required");
        const auto elapsed=signed_word(state.frame-(std::uint32_t(first.frame)-1u));
        const auto delta=finite(second.value-first.value);
        auto value=finite(first.value+finite(delta*float(elapsed))/float(span));
        if(value<0)value=0;
        weights[channel]=value;
    }
    auto residual=100.f;
    for(unsigned channel=0;channel<5;++channel)residual=finite(residual-weights[channel]);
    weights[5]=residual<0?0:residual;
    state.frame+=2;
    for(unsigned channel=0;channel<5;++channel){
        const auto keys=curves.channel(channel);auto& index=state.positions[channel];
        while(keys[index].frame<signed_word(state.frame)){
            ++index;
            if(index>=keys.size())throw std::out_of_range("Native facial curve continuation unavailable");
            if(keys[index].frame<0){state.active=false;return{{},true};}
        }
    }
    for(auto& weight:weights)weight=finite(weight/100.f);
    return{weights,false};
}
} // namespace reo::native::animation
