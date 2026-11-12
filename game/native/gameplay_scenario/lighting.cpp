#include "lighting.hpp"
#include <bit>
#include <stdexcept>

namespace reo::native::gameplay_scenario {
struct LightDomain {};
namespace {
void extent(std::span<const std::byte> bytes,std::size_t offset,std::size_t size){
    if(offset>bytes.size()||size>bytes.size()-offset)throw std::invalid_argument("Bounded LIG extent");
}
std::uint32_t word(std::span<const std::byte> bytes,std::size_t at){
    extent(bytes,at,4);return std::to_integer<std::uint32_t>(bytes[at])|
        std::to_integer<std::uint32_t>(bytes[at+1])<<8|std::to_integer<std::uint32_t>(bytes[at+2])<<16|
        std::to_integer<std::uint32_t>(bytes[at+3])<<24;
}
LightDescriptor descriptor(std::span<const std::byte> bytes,std::size_t at){
    extent(bytes,at,52);LightDescriptor d;
    for(std::size_t i=0;i<4;++i){d.vector0[i]=std::bit_cast<float>(word(bytes,at+4*i));d.vector1[i]=std::bit_cast<float>(word(bytes,at+16+4*i));}
    for(std::size_t i=0;i<3;++i)d.position[i]=std::bit_cast<float>(word(bytes,at+32+4*i));
    d.attenuation=std::bit_cast<float>(word(bytes,at+44));d.parameter=std::bit_cast<float>(word(bytes,at+48));return d;
}
}
LightDescriptor decode_light_descriptor(std::span<const std::byte> bytes){if(bytes.size()!=52)throw std::invalid_argument("Native light definition requires52 authored bytes");return descriptor(bytes,0);}
Lighting::Lighting():domain_(std::make_shared<const LightDomain>()){bindings_.fill(0xff);}
LightingImport Lighting::import_lig(std::span<const std::byte> bytes){
    const auto version=word(bytes,0);const auto count=std::bit_cast<std::int32_t>(word(bytes,4));
    if(version!=4){banks_={};return LightingImport::unsupported_version;}
    if(count>4)throw std::invalid_argument("Native four-bank LIG profile");
    std::array<LightingBank,4> banks{};
    if(count>0)extent(bytes,8,std::size_t(count)*4);
    for(std::int32_t i=0;i<count;++i){
        const auto at=std::size_t(word(bytes,8+std::size_t(i)*4));extent(bytes,at,116);
        auto& bank=banks[std::size_t(i)];bank.kind=std::uint16_t(word(bytes,at));bank.count=std::uint16_t(word(bytes,at+4));
        if(bank.count>32)throw std::invalid_argument("Native 32-entry LIG profile");
        extent(bytes,at+116,std::size_t(bank.count)*52);bank.base=descriptor(bytes,at+8);
        for(std::size_t j=0;j<bank.environment_words.size();++j)bank.environment_words[j]=word(bytes,at+60+4*j);
        for(std::size_t j=0;j<bank.count;++j)bank.entries[j]=descriptor(bytes,at+116+52*j);
    }
    banks_=banks;reset_work();return LightingImport::completed;
}
void Lighting::reset_work()noexcept{
    selected_=-1;primary_={};auxiliary_={};primary_count_=auxiliary_count_=0;bindings_.fill(0xff);
    if(reset_epoch_==UINT64_MAX)exhausted_=true;else ++reset_epoch_;
    // Existing bank masks are deliberately not cleared by 6B1DC0.
}
void Lighting::select(std::uint8_t bank)noexcept{if(bank<banks_.size()&&banks_[bank].kind)selected_=std::int8_t(bank);}
std::optional<std::uint8_t> Lighting::allocate(const LightDescriptor* source,std::uint8_t tag,std::uint8_t mode)noexcept{
    if(exhausted_||primary_count_>=primary_.size())return{};
    for(std::size_t i=0;i<primary_.size();++i)if(!primary_[i].active){
        if(generations_[i]==UINT64_MAX)return{};
        auto& light=primary_[i];light.active=1;++primary_count_;++generations_[i];
        if(source)light.descriptor=*source;
        light.tag=tag;light.mode=mode;return std::uint8_t(i);
    }
    return{};
}
bool Lighting::release(std::uint8_t slot)noexcept{
    if(!primary_count_||slot>=primary_.size()||!primary_[slot].active)return false;
    primary_[slot]={};--primary_count_;return true;
}
std::optional<LightHandle> Lighting::handle(std::uint8_t index)const noexcept{
    if(exhausted_||index>=primary_.size()||!primary_[index].active)return{};
    LightHandle id;id.domain_=domain_;id.epoch_=reset_epoch_;id.generation_=generations_[index];id.slot_=index;return id;
}
std::optional<std::uint8_t> Lighting::slot(const LightHandle& id)const noexcept{
    if(exhausted_||id.domain_!=domain_||id.epoch_!=reset_epoch_||!id.generation_||id.slot_>=primary_.size()||generations_[id.slot_]!=id.generation_||!primary_[id.slot_].active)return{};
    return id.slot_;
}
std::optional<NativeLight> Lighting::light(const LightHandle& id)const noexcept{const auto index=slot(id);return index?std::optional(primary_[*index]):std::nullopt;}
bool Lighting::release(const LightHandle& id)noexcept{const auto index=slot(id);return index&&release(*index);}
bool Lighting::replace(const LightHandle& id,const LightDescriptor& value)noexcept{const auto index=slot(id);if(!index)return false;primary_[*index].descriptor=value;return true;}
std::optional<AuxiliaryLightHandle> Lighting::allocate_auxiliary(const LightDescriptor* source,std::uint8_t tag)noexcept{
    if(exhausted_||auxiliary_count_>=auxiliary_.size())return{};
    for(std::size_t i=0;i<auxiliary_.size();++i)if(!auxiliary_[i].active){
        if(auxiliary_generations_[i]==UINT64_MAX)return{};
        auto& value=auxiliary_[i];value.active=1;value.tag=tag;
        if(source)value.descriptor=*source;
        ++auxiliary_generations_[i];++auxiliary_count_;return auxiliary_handle(std::uint8_t(i));
    }
    return{};
}
std::optional<AuxiliaryLightHandle> Lighting::auxiliary_handle(std::uint8_t index)const noexcept{
    if(exhausted_||index>=auxiliary_.size()||!auxiliary_[index].active)return{};
    AuxiliaryLightHandle id;id.domain_=domain_;id.epoch_=reset_epoch_;id.generation_=auxiliary_generations_[index];id.slot_=index;return id;
}
std::optional<std::uint8_t> Lighting::auxiliary_slot(const AuxiliaryLightHandle& id)const noexcept{
    if(exhausted_||id.domain_!=domain_||id.epoch_!=reset_epoch_||!id.generation_||id.slot_>=auxiliary_.size()||auxiliary_generations_[id.slot_]!=id.generation_||!auxiliary_[id.slot_].active)return{};
    return id.slot_;
}
std::optional<NativeLight> Lighting::light(const AuxiliaryLightHandle& id)const noexcept{
    const auto index=auxiliary_slot(id);return index?std::optional(auxiliary_[*index]):std::nullopt;
}
bool Lighting::release(const AuxiliaryLightHandle& id)noexcept{
    const auto index=auxiliary_slot(id);if(!index)return false;
    auxiliary_[*index]={};--auxiliary_count_;return true;
}
bool Lighting::replace(const AuxiliaryLightHandle& id,const LightDescriptor& value)noexcept{
    const auto index=auxiliary_slot(id);if(!index)return false;
    auxiliary_[*index].descriptor=value;return true;
}
bool Lighting::remove(std::uint8_t index)noexcept{
    if(index>=bindings_.size()||selected_<0||std::size_t(selected_)>=banks_.size())return false;
    if(bindings_[index]!=0xff)release(bindings_[index]);
    banks_[std::size_t(selected_)].enabled_mask&=~(std::uint32_t(1)<<index);return true;
}
bool Lighting::create(std::uint8_t index)noexcept{
    if(index>=bindings_.size())return false;
    if(selected_<0)return true;
    auto& bank=banks_[std::size_t(selected_)];if(!bank.kind||bank.entries[index].attenuation<=0.0f)return true;
    remove(index);const auto slot=allocate(&bank.entries[index],0,1);bindings_[index]=slot?*slot:0xff;
    bank.enabled_mask|=std::uint32_t(1)<<index;return true;
}
bool Lighting::create_all()noexcept{for(std::uint8_t i=0;i<32;++i)if(!create(i))return false;return true;}
} // namespace reo::native::gameplay_scenario
