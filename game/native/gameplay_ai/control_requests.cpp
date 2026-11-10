#include "control_requests.hpp"
#include <bit>
namespace reo::native::gameplay_ai {
namespace {
std::int16_t narrow_target(std::uint32_t target)noexcept{return std::bit_cast<std::int16_t>(std::uint16_t(target));}
}
bool ControlRequests::registered(std::uint32_t kind,std::uint32_t target)const noexcept{
    for(const auto& entry:registrations_)if(entry.active&&entry.kind==std::uint8_t(kind)&&entry.target==narrow_target(target))return true;
    return false;
}
RegistrationStatus ControlRequests::register_control(std::uint32_t kind,std::uint32_t target)noexcept{
    if(registered(kind,target))return RegistrationStatus::exists;
    for(auto& entry:registrations_)if(!entry.active){
        entry.active=1;entry.kind=std::uint8_t(kind);entry.target=narrow_target(target);entry.counters.fill(0);entry.owner_tag=255;return RegistrationStatus::created;
    }
    return RegistrationStatus::full;
}
bool ControlRequests::unregister_control(std::uint32_t kind,std::uint32_t target)noexcept{
    for(auto& entry:registrations_)if(entry.active&&entry.kind==std::uint8_t(kind)&&entry.target==narrow_target(target)){
        entry.active=entry.kind=0;entry.target=0;entry.counters.fill(0);return true;
    }
    return false;
}
std::optional<std::uint8_t> ControlRequests::find(std::int32_t kind,std::int32_t target,std::int32_t selector)const noexcept{
    const auto tag=selector==-1?std::uint8_t(255):std::uint8_t(std::uint8_t(selector)+1);
    for(std::size_t i=0;i<registrations_.size();++i){
        const auto& entry=registrations_[i];
        if(entry.active&&std::int32_t(entry.kind)==kind&&std::int32_t(entry.target)==target&&entry.owner_tag==tag)return std::uint8_t(i);
    }
    return {};
}
RequestResult ControlRequests::request(std::int32_t kind,std::int32_t target,std::array<std::uint8_t,4> payload,std::int32_t selector)noexcept{
    const auto index=find(kind,target,selector);if(!index)return {};
    if(count_==requests_.size())return {RequestStatus::full,index};
    requests_[count_++]={*index,payload};return {RequestStatus::queued,index};
}
RequestResult publish_actor_control(ControlRequests& controls,std::uint8_t actor_slot,std::uint32_t value)noexcept{
    return controls.request(0,actor_slot,{std::uint8_t(value),0,0,0});
}
ControlApplied ControlRequests::apply(std::uint8_t encoded_index,std::span<const std::uint8_t> payload,std::uint8_t mode,std::optional<std::int32_t> activity_mode)noexcept{
    auto& target=registrations_[encoded_index&63];
    if(mode==0){
        if(payload.size()<4)return {ControlApplyStatus::malformed};
        for(std::size_t i=0;i<4;++i)target.payload[i]=payload[i];
        return {ControlApplyStatus::completed,1,1};
    }
    if(mode==1){
        if(!activity_mode)return {};
        if(*activity_mode==0){
            if(payload.empty())return {ControlApplyStatus::malformed};
            target.owner_tag=payload[0];return {ControlApplyStatus::completed,1,1};
        }
    }
    return {ControlApplyStatus::completed,1,0};
}
ControlApplied ControlRequests::receive(std::span<const std::uint8_t> packet,std::optional<std::int32_t> activity_mode)noexcept{
    if(packet.size()<4)return {ControlApplyStatus::malformed};
    const auto mode=packet[0];
    if(mode==0){
        if(packet.size()<9)return {ControlApplyStatus::malformed};
        return apply(packet[4],packet.subspan(5,4),0,activity_mode);
    }
    if(packet[1]<4)return {ControlApplyStatus::malformed};
    const auto count=std::size_t((packet[1]-4)/2);
    if(count>(packet.size()-4)/2)return {ControlApplyStatus::malformed};
    if(count&&mode==1&&!activity_mode)return {};
    ControlApplied result{ControlApplyStatus::completed};
    for(std::size_t i=0;i<count;++i){
        const auto item=apply(packet[4+2*i],packet.subspan(5+2*i,1),mode,activity_mode);
        result.visited+=item.visited;result.written+=item.written;
    }
    return result;
}
}
