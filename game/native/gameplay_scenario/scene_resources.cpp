#include "scene_resources.hpp"
#include <utility>

namespace reo::native::gameplay_scenario {
struct SceneResourceDomain {};
SceneResources::SceneResources():domain_(std::make_shared<SceneResourceDomain>()) {generations_.fill(1);}
bool SceneResources::valid(const SceneResourceId& id)const noexcept{
    return id.domain_==domain_&&id.slot_<capacity&&id.generation_==generations_[id.slot_];
}
SceneResourceId SceneResources::identity(std::size_t slot)const noexcept{
    SceneResourceId id;id.domain_=domain_;id.slot_=std::uint16_t(slot);id.generation_=generations_[slot];return id;
}
std::optional<SceneResourceId> SceneResources::load(std::size_t slot,SceneDescriptor descriptor){
    if(slot>=capacity||generations_[slot]==UINT64_MAX)return{};
    ++generations_[slot];descriptors_[slot]=std::move(descriptor);return identity(slot);
}
std::optional<SceneResourceId> SceneResources::slot(std::size_t index)const noexcept{
    if(index>=capacity)return{};
    return identity(index);
}
std::optional<SceneResourceId> SceneResources::lookup(std::int16_t authored)const noexcept{
    if(authored<=0)return{};
    for(std::size_t i=0;i<capacity;++i)if(descriptors_[i].authored_id==std::uint16_t(authored))return identity(i);
    return{};
}
std::optional<AttachedSceneResource> SceneResources::lookup_attached(std::int16_t authored)const noexcept{
    for(std::size_t i=0;i<capacity;++i){const auto& d=descriptors_[i];
        if(d.active&&(d.flags&1)&&std::int32_t(d.attachment_id)==std::int32_t(authored)&&d.ownership_tag){
            const auto owner=std::uint16_t(d.ownership_tag-1);
            return AttachedSceneResource{identity(i),{owner<4?SceneOwnerFamily::primary:SceneOwnerFamily::extended,std::uint16_t(owner<4?owner:owner-4)}};
        }
    }
    return{};
}
std::optional<SceneDescriptor> SceneResources::get(const SceneResourceId& id)const noexcept{
    if(!valid(id))return{};
    return descriptors_[id.slot_];
}
SceneStatus SceneResources::replace(const SceneResourceId& id,SceneDescriptor descriptor)noexcept{
    if(!valid(id))return SceneStatus::invalid_identity;
    descriptors_[id.slot_]=std::move(descriptor);return SceneStatus::completed;
}
SceneStatus SceneResources::command(const SceneResourceId& id,SceneCommand command,std::uint16_t room,SceneEffects* effects)noexcept{
    if(!valid(id))return SceneStatus::invalid_identity;
    auto& d=descriptors_[id.slot_];if(!d.active||!d.kind)return SceneStatus::completed;
    bool invoke=false;SceneEffect effect=SceneEffect::construct_primary;
    const bool room_eligible=d.room==room&&d.ownership_tag==0;
    switch(command){
    case SceneCommand::enable:invoke=!(d.primary&&d.secondary)&&room_eligible;break;
    case SceneCommand::disable:invoke=bool(d.primary)||bool(d.secondary);effect=SceneEffect::release;break;
    case SceneCommand::force_enable:invoke=room_eligible;break;
    case SceneCommand::alternate_enable:invoke=room_eligible;effect=SceneEffect::construct_alternate;break;
    }
    if(invoke&&!effects)return SceneStatus::provider_unavailable;
    if(command==SceneCommand::disable)d.flags&=~0x200001u;
    else if(command==SceneCommand::force_enable)d.flags|=0x200001u;
    else d.flags=(d.flags|1u)&~0x200000u;
    const auto index=d.instance_index;
    // No reference is used after the external effect; it may replace/retire the
    // descriptor through its native owner without invalidating a borrowed view.
    if(invoke)effects->apply(*this,id,effect,index);
    return SceneStatus::completed;
}
std::optional<bool> SceneResources::inactive_or_flag29(const SceneResourceId& id)const noexcept{
    if(!valid(id))return{};
    const auto& d=descriptors_[id.slot_];
    return d.active?d.kind==0:bool(d.flags&0x20000000u);
}
SceneStatus SceneResources::flag800(const SceneResourceId& id,std::int8_t value)noexcept{
    if(!valid(id))return SceneStatus::invalid_identity;
    auto& d=descriptors_[id.slot_];if(!d.active||!d.kind)return SceneStatus::completed;
    d.flags=value?d.flags|0x800u:d.flags&~0x800u;
    const auto primary=d.primary;
    if(primary){const auto flags=std::dynamic_pointer_cast<SceneFlagAttachment>(primary);if(!flags)return SceneStatus::provider_unavailable;flags->flag(0x800u,value!=0);}
    return SceneStatus::completed;
}
SceneStatus SceneResources::detach(const AttachedSceneResource& attached,SceneEffects* effects,SceneOwners* owners)noexcept{
    if(!valid(attached.id))return SceneStatus::invalid_identity;
    if(!effects||!owners)return SceneStatus::provider_unavailable;
    // The owner selection is the lookup's value captured before release. Byte
    // instance indices are reread after each effect, as in the original body.
    auto current=get(attached.id);
    if(current->primary)effects->apply(*this,attached.id,SceneEffect::release,current->instance_index);
    const auto entity=owners->resolve(attached.owner);
    if(!entity||!bool(*entity))return SceneStatus::provider_unavailable;
    current=get(attached.id);if(!current)return SceneStatus::invalid_identity;
    owners->detach(*this,*entity,current->instance_index);
    owners->refresh(*this,*entity);
    current=get(attached.id);if(!current)return SceneStatus::invalid_identity;
    effects->apply(*this,attached.id,SceneEffect::retire_instance,current->instance_index);
    return SceneStatus::completed;
}
bool SceneResources::compare_attached(std::int16_t id,std::int16_t expected,std::int16_t operation)const noexcept{
    const auto attached=lookup_attached(id);if(!attached)return false;
    const auto actual=descriptors_[attached->id.slot_].parameter;
    switch(operation){case 0:return actual==expected;case 1:return actual!=expected;case 2:return actual>=expected;
    case 3:return actual<=expected;case 4:return actual>expected;case 5:return actual<expected;default:return true;}
}
} // namespace reo::native::gameplay_scenario
