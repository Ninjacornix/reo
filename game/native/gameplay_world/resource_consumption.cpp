#include "resource_consumption.hpp"
#include "../gameplay_update/update.hpp"
#include <bit>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
template<class T>T read(const gameplay_scenario::ResourceTemplate& row,unsigned at){T value;std::memcpy(&value,row.encoded.data()+at,sizeof value);return value;}
}
ResourceConsumption::ResourceConsumption(ResourceRecipes& lifecycle,gameplay_update::Owner& update):lifecycle_(lifecycle),update_(update),use_(lifecycle.pairs_.world_,lifecycle.pairs_.resources_,lifecycle.pairs_.templates_,lifecycle.pairs_.frames_){
    if(&lifecycle_.pairs_.world_!=&update_.world()||!update_.open())throw std::invalid_argument("Native consumption update owner unavailable or foreign");
}
std::shared_ptr<Actor> ResourceConsumption::actor(const actors::EntityId& id)const{
    if(!update_.open())throw std::runtime_error("Native resource consumption owner closed");
    if(!id)return{};
    const auto value=update_.world().resolve(id);if(!value)throw std::runtime_error("Native resource consumption actor foreign or retired");
    return value;
}
std::uint8_t ResourceConsumption::addressed(std::uint32_t resource)const{
    const auto low=std::uint16_t(resource);if(low>=256)throw std::runtime_error("Native consumption low16 descriptor extent unavailable");
    return std::uint8_t(low);
}
void ResourceConsumption::record(const Actor& actor,std::uint16_t content){
    if(!update_.world().locally_controlled(actor))return;
    const auto result=update_.record_scenario_event(content);last_record_=result;
    if(result.status!=gameplay_events::StatisticsStatus::completed)throw std::runtime_error("Native item completion-event consumer unavailable");
}
void ResourceConsumption::cleanup(const actors::EntityId& id,std::uint8_t resource){
    (void)lifecycle_.inventory_.detach_item(id,resource);lifecycle_.inventory_.compact(id);lifecycle_.pairs_.destroy_owned(resource);
}
void ResourceConsumption::decrement(const actors::EntityId& id,std::uint32_t full_resource){
    last_record_.reset();if(!actor(id))return;auto& pairs=lifecycle_.pairs_;const auto resource=addressed(full_resource);const auto value=pairs.descriptor(resource);if(!value.active)return;
    pairs.quantity(resource,std::int32_t(value.parameter)-1);if(pairs.descriptor(resource).parameter<=0)cleanup(id,std::uint8_t(full_resource));
}
std::uint8_t ResourceConsumption::consume_or_transform(const actors::EntityId& id,std::uint32_t full_resource){
    last_record_.reset();const auto selected=actor(id);if(!selected)return 0;auto& pairs=lifecycle_.pairs_;const auto resource=addressed(full_resource);auto value=pairs.descriptor(resource);if(!value.active)return 0;
    record(*selected,value.attachment_id);const auto flags=read<std::uint32_t>(pairs.metadata(resource),0);
    if(flags&0x40000u){pairs.quantity(resource,std::int32_t(pairs.descriptor(resource).parameter)-1);if(pairs.descriptor(resource).parameter<=0)cleanup(id,std::uint8_t(full_resource));return 1;}
    if(!(flags&0x80000u))return 0;
    const auto next=read<std::int16_t>(pairs.metadata(resource),10);lifecycle_.contents_.replace_direct(resource,std::uint16_t(next));value=pairs.descriptor(resource);
    if(value.attachment_id==0x3717)pairs.quantity(resource,use_.initial_quantity(std::uint8_t(full_resource)));
    return 1;
}
void ResourceConsumption::destroy(const actors::EntityId& id,std::uint32_t full_resource){
    last_record_.reset();const auto selected=actor(id);if(!selected)return;
    // Only the local-event branch dereferences low16. The nonlocal branch
    // legitimately uses low8 cleanup even if the unused low16 exceeds255.
    if(update_.world().locally_controlled(*selected))record(*selected,lifecycle_.pairs_.descriptor(addressed(full_resource)).attachment_id);
    cleanup(id,std::uint8_t(full_resource));
}
std::uint8_t ResourceConsumption::transform(const actors::EntityId& id,std::uint32_t full_resource){
    last_record_.reset();const auto selected=actor(id);if(!selected)return 0;auto& pairs=lifecycle_.pairs_;const auto resource=addressed(full_resource);const auto value=pairs.descriptor(resource);if(!value.active)return 0;
    record(*selected,value.attachment_id);if(!(read<std::uint32_t>(pairs.metadata(resource),0)&0x80000u))return 0;
    lifecycle_.contents_.replace_direct(resource,std::uint16_t(read<std::int16_t>(pairs.metadata(resource),10)));return 1;
}
}
