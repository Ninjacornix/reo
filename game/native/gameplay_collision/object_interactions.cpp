#include "object_interactions.hpp"
#include <bit>
namespace reo::native::gameplay_collision::room_objects {
bool InteractionOwner::initialize_scene_slot(const ObjectId& id)noexcept{
    auto* object=edit(id);if(!object)return false;
    object->instance={};object->proxies={};object->control_flags&=~2u;
    object->requests=0;object->direction=0;object->secondary_direction=0;return true;
}
namespace {std::int8_t narrow(int n){return std::bit_cast<std::int8_t>(std::uint8_t(n));}}
std::optional<ObjectId> InteractionOwner::masked(std::uint8_t slot)const noexcept{if(!owner_.domain_)return{};const auto index=slot&31;return owner_.objects_[index].active?std::optional<ObjectId>(owner_.id(index)):std::nullopt;}
std::optional<std::uint8_t> InteractionOwner::source_ordinal(const ObjectId& id)const noexcept{return owner_.ordinal(id);}
void InteractionOwner::increment(const ObjectId& id)noexcept{if(auto* o=edit(id))if(o->count<owner_.types_[o->type].capacity)o->count=narrow(int(o->count)+1);}
void InteractionOwner::decrement(const ObjectId& id)noexcept{if(auto* o=edit(id))if(o->count>0)--o->count;}
bool InteractionOwner::below_capacity(const ObjectId& id)const noexcept{const auto* o=owner_.get(id);return o&&!(o->control_flags&2)&&o->count<owner_.types_[o->type].capacity;}
void InteractionOwner::transfer(std::int8_t old_source,std::int8_t next_source)noexcept{if(old_source==next_source)return;if(old_source>=0){const auto old=masked(std::uint8_t(old_source));if(!old)return;increment(*old);}if(next_source>=0)if(const auto next=masked(std::uint8_t(next_source)))decrement(*next);}
std::uint8_t InteractionOwner::direction(std::uint16_t heading)noexcept{return std::uint8_t(1u<<(((std::uint32_t(heading)+0x2000)>>14)&3));}
bool InteractionOwner::claim_secondary(const ObjectId& id,std::uint16_t heading,bool gate)noexcept{if(!gate)return false;auto* o=edit(id);if(!o||(o->control_flags&0x30))return false;const auto d=std::uint8_t(direction(heading)&o->allowed_directions);if(!d)return false;if(!o->secondary_direction)o->secondary_direction=d;return o->secondary_direction==d;}
void InteractionOwner::request_primary(const ObjectId& id,std::uint16_t heading)noexcept{auto* o=edit(id);if(!o)return;const auto d=std::uint8_t(direction(heading)&o->allowed_directions);if(!o->direction)o->direction=d;if(o->direction==d)o->requests=narrow(int(o->requests)+1);}
void InteractionOwner::clear_secondary(const ObjectId& id)noexcept{if(auto* o=edit(id))o->secondary_direction=0;}
void InteractionOwner::decay(const ObjectId& id)noexcept{auto* o=edit(id);if(!o)return;if(o->requests>0)--o->requests;if((o->control_flags&2)||!o->requests){o->control_flags&=~2u;o->direction=0;}}
Parameters InteractionOwner::parameters(std::uint8_t source_slot)const noexcept{const auto index=source_slot<32?source_slot:31;const auto& t=owner_.types_[owner_.objects_[index].type];return{t.request_threshold,std::bit_cast<std::int8_t>(t.parameter4),t.parameter5};}
}
