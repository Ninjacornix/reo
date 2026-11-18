#include "fog.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
std::uint32_t word(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||bytes.size()-at<4)throw std::invalid_argument("Native fog asset extent");
    std::uint32_t result{};for(unsigned i=0;i<4;++i)result|=std::uint32_t(std::to_integer<std::uint8_t>(bytes[at+i]))<<(8*i);return result;
}
float real(std::span<const std::byte> bytes,std::size_t at){return std::bit_cast<float>(word(bytes,at));}
std::array<std::uint8_t,3> rgb(std::uint32_t value){return{std::uint8_t(value>>16),std::uint8_t(value>>8),std::uint8_t(value)};}
std::int16_t decrement(std::int16_t value){return std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(value)-1u));}
std::int16_t increment(std::int16_t value){return std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(value)+1u));}
std::uint8_t byte(float value){if(!std::isfinite(value)||value<-2147483648.f||value>=2147483648.f)throw std::domain_error("Native fog byte conversion profile");return std::uint8_t(std::int32_t(value));}
}
FogStatus Fog::import_fog(std::span<const std::byte> bytes)noexcept{
    try{
        const auto version=word(bytes,0);
        if(version!=2){records_={};ready_=true;return FogStatus::unsupported_version;}
        const auto count=std::bit_cast<std::int32_t>(word(bytes,4));
        if(count<0||count>16)return FogStatus::invalid_asset;
        std::array<FogRecord,16> records{};
        for(std::int32_t i=0;i<count;++i){
            const auto at=std::size_t(word(bytes,8+4*std::size_t(i)));
            if(at>bytes.size()||bytes.size()-at<96)return FogStatus::invalid_asset;
            auto& record=records[std::size_t(i)];record.active=word(bytes,at);record.near_distance=real(bytes,at+4);record.far_distance=real(bytes,at+8);
            for(unsigned j=0;j<3;++j)record.colors[j]=word(bytes,at+12+4*j);
            record.parameters=word(bytes,at+24);record.pitch=std::uint16_t(word(bytes,at+28));record.yaw=std::uint16_t(word(bytes,at+32));
            for(unsigned j=0;j<3;++j)for(unsigned k=0;k<4;++k)record.vectors[j][k]=real(bytes,at+36+16*j+4*k);
            for(unsigned j=0;j<3;++j)record.words[j]=word(bytes,at+84+4*j);
        }
        std::array<std::uint8_t,3> tail{};
        if(count)tail=rgb(word(bytes,8+100*std::size_t(count)));
        records_=records;ready_=true;if(!count)return FogStatus::completed;
        state_.tail_color=tail;return select(0);
    }catch(const std::exception&){return FogStatus::invalid_asset;}
}
FogStatus Fog::select(std::uint8_t index)noexcept{
    if(std::int32_t(state_.selected)==index)return FogStatus::completed;
    if(index>=16){state_.selected=std::bit_cast<std::int8_t>(index);return FogStatus::completed;}
    if(!ready_)return FogStatus::unavailable;
    const auto& record=records_[index];
    if(record.active){
        try{
            auto matrix=transform_math::identity();transform_math::reset_euler_axes(matrix,{record.pitch,record.yaw,0});
            const auto direction=transform_math::direction(matrix,{0,0,-1});
            state_.near_distance=record.near_distance;state_.far_distance=record.far_distance;state_.color=rgb(record.colors[0]);
            for(unsigned j=0;j<2;++j){const auto color=rgb(record.colors[j+1]);std::copy(color.begin(),color.end(),state_.secondary_colors[j].begin());state_.secondary_colors[j][3]=255;}
            state_.parameters={std::uint8_t(record.parameters),std::uint16_t(record.parameters>>16)};state_.direction=direction;
            state_.vectors=record.vectors;state_.words={record.words[0],record.words[1]};state_.option=std::uint8_t(record.words[2]);
        }catch(const std::exception&){return FogStatus::unsupported_numeric;}
    }
    state_.selected=std::bit_cast<std::int8_t>(index);return FogStatus::completed;
}
FogPulseResult Fog::advance(FogPulse& work)noexcept{
    if(!ready_)return{FogStatus::unavailable};
    try{
        transform_math::require_profile();auto& near=state_.near_distance;auto& far=state_.far_distance;
        if(!std::isfinite(near)||!std::isfinite(far))return{FogStatus::unsupported_numeric};
        if(work.last_near!=near||work.last_far!=far||work.phase==0){work.saved_near=near;work.saved_far=far;}
        if(work.phase==0){
            work.phase=1;work.counter=0;work.duration=10;work.delay=5;work.velocity={6,6,4};work.accumulator={};state_.flash={};
        }else if(work.phase==1){work.delay=decrement(work.delay);if(work.delay<0)work.phase=2;
        }else if(work.phase==10||work.phase==2){
            if(work.phase==10){work.phase=2;work.counter=0;work.duration=10;work.velocity={6,6,4};}
            const auto before=work.counter;work.counter=increment(work.counter);
            if(before<10){
                work.accumulator.x=std::min(work.accumulator.x+work.velocity.x,60.f);
                work.accumulator.y=std::min(work.accumulator.y+work.velocity.y,60.f);
                work.accumulator.z=std::min(work.accumulator.z+work.velocity.z,40.f);
                state_.flash[0]=byte(work.accumulator.x);state_.flash[1]=byte(work.accumulator.y);state_.flash[2]=byte(work.accumulator.z);
                if(!work.duration)return{FogStatus::unsupported_numeric};
                work.near_step=(-10000.f-near)/float(work.duration);work.far_step=(10000.f-far)/float(work.duration);work.duration=decrement(work.duration);
                near=std::max(near+work.near_step,-10000.f);far=std::min(far+work.far_step,10000.f);
            }else{work.phase=3;work.counter=90;work.duration=0;work.velocity={std::bit_cast<float>(0x3f2aaaabu),std::bit_cast<float>(0x3f2aaaabu),std::bit_cast<float>(0x3ee38e39u)};}
        }else if(work.phase==3){
            work.counter=decrement(work.counter);
            if(work.counter<0){const auto selected=std::bit_cast<std::uint8_t>(state_.selected);reset_selection();const auto status=select(selected);if(status!=FogStatus::completed)return{status};state_.flash[0]=state_.flash[1]=state_.flash[2]=0;return{FogStatus::completed,true};}
            work.accumulator={float(work.counter)*work.velocity.x,float(work.counter)*work.velocity.y,float(work.counter)*work.velocity.z};
            for(unsigned i=0;i<3;++i){const float value=i==0?work.accumulator.x:i==1?work.accumulator.y:work.accumulator.z;const auto converted=byte(value);state_.flash[i]=(converted&0x80)?0:converted;}
            work.near_step=(work.saved_near-near)/(float(work.counter)+1.f);work.far_step=(work.saved_far-far)/(float(work.counter)+1.f);
            near=std::min(near+work.near_step,work.saved_near);far=std::max(far+work.far_step,work.saved_far);
        }
        work.last_near=near;work.last_far=far;return{};
    }catch(const std::exception&){return{FogStatus::unsupported_numeric};}
}
}
