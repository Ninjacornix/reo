#include "actor_resource_operations.hpp"
#include <algorithm>
#include <bit>
#include <span>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
namespace s=gameplay_scenario;
struct DiscardPriority {std::uint16_t content;std::uint8_t minimum,maximum,priority;};
#include "offline_resource_priorities.inc"
s::SceneDescriptor descriptor(const s::SceneResources& resources,std::uint8_t slot){
    const auto id=resources.slot(slot);const auto value=id?resources.get(*id):std::nullopt;
    if(!value)throw std::runtime_error("Offline resource descriptor unavailable");return *value;
}
const s::ResourceTemplate& metadata(const s::SceneDescriptor& item,const s::ResourceTemplates& templates){
    //5B4380 returns canonical fallback record128 for inactive/tableFF.
    const auto index=item.active&&item.template_index!=255?item.template_index:128;
    if(std::size_t(index)>=templates.state().templates.size())throw std::runtime_error("Offline resource template unavailable");
    return templates.state().templates[index];
}
std::uint8_t kind(const s::SceneDescriptor& item,const s::ResourceTemplates& templates){return std::to_integer<std::uint8_t>(metadata(item,templates).encoded[21]);}
std::uint32_t flags(const s::SceneDescriptor& item,const s::ResourceTemplates& templates){return item.active&&item.template_index!=255?templates.flags(item.template_index):0;}
std::uint8_t discard_priority(const Actor& actor,std::uint8_t slot,const s::SceneDescriptor& item,const s::ResourceTemplates& templates,const s::SceneResources& resources){
    if(!item.active)return 255;
    if(item.attachment_id<10000&&kind(item,templates)>0){
        if(item.ownership_tag)return 255;
        return std::uint8_t(3u-kind(item,templates));
    }
    std::span<const DiscardPriority> table;
    const auto action=resources.action_kind(slot,templates);
    if(action!=0&&item.attachment_id!=0x135){
        switch(flags(item,templates)&0xf000u){
        case 0x1000:table=discard_829fe0;break;case 0x2000:table=discard_82a080;break;
        case 0x4000:table=discard_82a160;break;case 0x8000:table=discard_82a260;break;
        default:return 255;
        }
    }else{
        if(actor.character==0&&item.attachment_id==0x106)return 0x6b;
        const auto mask=flags(item,templates);
        table=(mask&4u)?std::span<const DiscardPriority>(discard_82a2b0):
            (mask&0xc02u)?std::span<const DiscardPriority>(discard_82a330):std::span<const DiscardPriority>(discard_82a410);
    }
    for(const auto& row:table)if(item.attachment_id==row.content&&item.parameter>=row.minimum&&item.parameter<=row.maximum)return row.priority;
    return 255;
}
}
std::optional<bool> offline_actor_resource_required(const World& world,std::int16_t index,std::int16_t content)noexcept{
    if(world.closed())return{};
    if(content<0||index<0)return false;
    const auto count=world.session().primary_population;if(!count)return{};
    if(index>=std::bit_cast<std::int8_t>(std::uint8_t(*count)))return false;
    if(std::uint16_t(index)>=World::primary_capacity)return{};
    const auto actor=world.primary(std::uint16_t(index));return actor&&actor->active&&actor->ai_control;
}
bool ActorResourceOperations::bound_to(const World& world,const s::SceneResources& resources,const s::ResourceTemplates& templates)const noexcept{
    return &world_==&world&&!world_.closed()&&&resources_.pairs_.resources_==&resources&&&resources_.pairs_.templates_==&templates;
}
bool ActorResourceOperations::grant_offline_resource(std::int16_t index,std::int16_t content,std::int16_t quantity,std::int16_t cleanup)noexcept{
    const auto required=offline_actor_resource_required(world_,index,content);if(!required)return false;if(!*required)return true;
    try{
        auto& table=resources_.pairs_.resources_;const auto& templates=resources_.pairs_.templates_;
        const auto actor=world_.primary(std::uint16_t(index));const auto id=world_.identity_of(*actor);if(!id)return false;
        //703194 allocates before826CB0 reads capacity or a reclaim candidate.
        const auto allocated=table.allocate_owned(std::uint16_t(index),std::uint16_t(content),quantity,templates);
        if(allocated.status==s::SceneStatus::full)return true;
        if(allocated.status!=s::SceneStatus::completed||!allocated.id)return false;
        const auto item=descriptor(table,allocated.slot);
        std::int32_t occupied{};
        for(const auto slot:actor->inventory.carried)if(slot)occupied+=(flags(descriptor(table,slot),templates)&0x20000u)?2:1;
        const auto carried_space=4-occupied;
        std::int32_t storage_space{};
        if(actor->character==6)for(unsigned i=1;i<=4;++i)storage_space+=actor->inventory.storage[i]==0;
        unsigned destination{};
        if(carried_space+storage_space>0)destination=carried_space>0?1u:storage_space>0?2u:0u;
        else{
            std::uint8_t discard{};unsigned found{};
            const auto candidate=[&](std::uint8_t slot,unsigned location){
                if(!slot)return;const auto value=descriptor(table,slot);
                if(kind(value,templates)>0)return;
                //826CB0 masks the byte before comparing >0: FF remains255.
                if(discard_priority(*actor,slot,value,templates,table)>0){discard=slot;found=location;}
            };
            for(const auto slot:actor->inventory.carried)candidate(slot,1);
            if(actor->character==6)for(unsigned i=1;i<=4;++i)candidate(actor->inventory.storage[i],2);
            if(found&&resources_.inventory_.detach_item(id,discard)){
                resources_.pairs_.destroy_owned(discard);destination=found;
            }
        }
        if(!destination)return true; //Source826CB0 return0 keeps the allocation.
        if(destination==1)resources_.inventory_.insert(id,item.instance_index);
        else{
            //Only character6 can select826CB0 destination2. Its5F2810 path
            //writes the first empty C89..C8C and then the shared5F2330 owner.
            if(actor->character!=6)return false;
            for(unsigned i=1;i<=4;++i)if(!actor->inventory.storage[i]){actor->inventory.storage[i]=item.instance_index;break;}
            resources_.inventory_.compact(id);
        }
        if(cleanup>0){
            //592A10 acts on the first authored-ID match, not the new slot.
            const auto target=table.lookup(cleanup);auto value=target?table.get(*target):std::nullopt;
            if(value&&value->active&&value->kind){
                value->flags&=0xffdffffeu;
                if(table.replace(*target,*value)!=s::SceneStatus::completed)return false;
                if(value->primary||value->secondary)resources_.pairs_.frames_.release(value->instance_index);
            }
        }
        return true;
    }catch(...){return false;}
}
}
