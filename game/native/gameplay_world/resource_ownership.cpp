#include "resource_ownership.hpp"
#include <bit>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
template<class T>T read(const gameplay_scenario::ResourceTemplate& row,unsigned at){T value;std::memcpy(&value,row.encoded.data()+at,sizeof value);return value;}
constexpr std::array<std::array<std::uint32_t,7>,8> orientations{{
#include "resource_orientation_profile.inc"
}};
}
ResourceOwnership::ResourceOwnership(WorldInventory& inventory,ResourceFactory& factory):inventory_(inventory),factory_(factory),world_(inventory.world_),resources_(inventory.resources_),templates_(inventory.templates_),frames_(inventory.frames_){
    if(world_.closed()||&factory_.frames_!=&frames_||&factory_.templates_!=&templates_)throw std::invalid_argument("Native resource ownership consumers unavailable or foreign");
}
gameplay_scenario::SceneDescriptor ResourceOwnership::descriptor(std::uint8_t slot)const{
    if(world_.closed())throw std::runtime_error("Native resource ownership world closed");
    const auto key=resources_.slot(slot);const auto value=key?resources_.get(*key):std::nullopt;
    if(!value)throw std::runtime_error("Native resource ownership descriptor unavailable");
    return *value;
}
void ResourceOwnership::publish(std::uint8_t slot,const gameplay_scenario::SceneDescriptor& value){
    const auto key=resources_.slot(slot);
    if(!key||resources_.replace(*key,value)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native resource ownership descriptor changed");
}
const gameplay_scenario::ResourceTemplate& ResourceOwnership::metadata(std::uint8_t slot)const{
    const auto value=descriptor(slot);const unsigned index=value.active&&value.template_index!=255?value.template_index:128;
    if(index>=templates_.state().templates.size())throw std::runtime_error("Native ownership template unavailable");
    return templates_.state().templates[index];
}
bool ResourceOwnership::admits(std::uint32_t full_actor,std::uint32_t full_resource)const{
    const auto resource=std::uint8_t(full_resource);const auto item=descriptor(resource);if(!item.active)return false;
    const auto index=std::uint16_t(full_actor);
    if(index>=4)throw std::runtime_error("Native extended ownership actor unavailable");
    const auto actor=world_.primary(index);if(!actor)throw std::runtime_error("Native ownership primary actor unavailable");
    const auto identity=world_.identity_of(*actor);
    if((read<std::uint32_t>(metadata(resource),0)&0x8000000u)&&inventory_.find_by_content(identity,item.attachment_id))return false;
    if(!world_.session().scenario)throw std::runtime_error("Native ownership scenario identity unavailable");
    if(*world_.session().scenario!=0x23)return true;
    if(item.attachment_id==0x34bc||item.attachment_id==0x34bd)return !inventory_.find_by_content(identity,0x34be);
    if(item.attachment_id==0x34be)return !inventory_.find_by_content(identity,0x34bc)&&!inventory_.find_by_content(identity,0x34bd);
    return true;
}
std::int8_t ResourceOwnership::assign(std::uint32_t full_resource,std::uint32_t actor){
    const auto resource=std::uint8_t(full_resource);auto item=descriptor(resource);if(!item.active)return 0;
    item.flags|=1;publish(resource,item);if(!admits(actor,full_resource))return 2;
    item=descriptor(resource);item.ownership_tag=std::uint16_t(actor+1u);item.kind=0;item.flags=(item.flags|0x800u)&~0x400u;publish(resource,item);
    item.shape_profile=std::bit_cast<std::int8_t>(std::uint8_t(int(read<std::int8_t>(metadata(resource),12))+2));publish(resource,item);
    frames_.release(resource);return 1;
}
std::int8_t ResourceOwnership::swap_owned(std::uint32_t full_first,std::uint32_t full_second){
    const auto first=std::uint8_t(full_first),second=std::uint8_t(full_second);auto a=descriptor(first),b=descriptor(second);
    if(!a.active||!b.active||!a.ownership_tag||!b.ownership_tag)return 0;
    if(!admits(std::uint16_t(b.ownership_tag-1u),full_first)||!admits(std::uint16_t(a.ownership_tag-1u),full_second))return 2;
    frames_.release(first);frames_.release(second);a=descriptor(first);b=descriptor(second);
    auto new_a=b,new_b=a;new_a.ownership_tag=a.ownership_tag;new_b.ownership_tag=b.ownership_tag;new_a.instance_index=a.instance_index;new_b.instance_index=b.instance_index;
    publish(first,new_a);publish(second,new_b);return 1;
}
std::int8_t ResourceOwnership::exchange_world(std::uint32_t full_first,std::uint32_t full_second){
    const auto first=std::uint8_t(full_first),second=std::uint8_t(full_second);auto a=descriptor(first),b=descriptor(second);
    if(!a.active||!b.active)return 0;
    a.flags|=1;publish(first,a);b=descriptor(second);b.flags|=1;publish(second,b);a=descriptor(first);
    if(a.ownership_tag||!b.ownership_tag)return 0;
    if(!admits(std::uint16_t(b.ownership_tag-1u),full_first))return 2;
    a.ownership_tag=b.ownership_tag;publish(first,a);
    a.shape_profile=std::bit_cast<std::int8_t>(std::uint8_t(int(read<std::int8_t>(metadata(first),12))+2));a.flags|=0x800u;publish(first,a);
    b.room=a.room;b.authored_id=a.authored_id;b.ownership_tag=0;b.orientation_variant=a.orientation_variant;b.flags|=a.flags&0xc00u;publish(second,b);
    const int variant=b.orientation_variant,shape=read<std::int8_t>(metadata(second),12);
    if(variant<0||unsigned(variant)>=orientations.size()||shape<0||shape>=4)throw std::runtime_error("Native exchange shape profile unavailable");
    b.shape_profile=std::bit_cast<std::int8_t>(std::uint8_t(orientations[unsigned(variant)][unsigned(shape)+3]));publish(second,b);
    a.flags&=~0x400u;publish(first,a);
    if(a.kind){b.position=a.saved_position;b.tilt=0;b.yaw=a.saved_yaw;a.kind=0;publish(first,a);}
    else{b.position=a.position;b.tilt=a.tilt;b.yaw=a.yaw;}
    publish(second,b);frames_.release(first);
    const auto made=factory_.place(*resources_.slot(second));
    if(made.status!=ResourceModelStatus::completed&&made.status!=ResourceModelStatus::full)throw std::runtime_error("Native exchanged world resource construction unavailable");
    return 1;
}
void ResourceOwnership::set_claim(std::uint32_t resource,std::uint32_t actor){
    const auto slot=std::uint8_t(resource);auto item=descriptor(slot);if(item.active){item.claim_tag=std::uint8_t(std::uint8_t(actor)+1u);publish(slot,item);}
}
void ResourceOwnership::clear_claim(std::uint32_t resource,std::uint32_t actor){
    const auto slot=std::uint8_t(resource);auto item=descriptor(slot);const auto index=std::uint8_t(actor);
    if(item.active&&(index==255||unsigned(item.claim_tag)==unsigned(index)+1)){item.claim_tag=0;publish(slot,item);}
}
bool ResourceOwnership::claimed_by_other(std::uint32_t resource,std::uint32_t actor)const{
    const auto item=descriptor(std::uint8_t(resource));return item.active&&item.claim_tag&&unsigned(item.claim_tag)!=unsigned(std::uint8_t(actor))+1;
}
void ResourceOwnership::clear_claims(){
    if(world_.closed()||!clear_resource_claims(resources_))throw std::runtime_error("Native resource claim owner unavailable");
}
bool clear_resource_claims(gameplay_scenario::SceneResources& resources)noexcept{
    for(unsigned slot=0;slot<256;++slot){const auto id=resources.slot(slot);const auto value=id?resources.get(*id):std::nullopt;
        if(!value)return false;
        if(value->active){auto changed=*value;changed.claim_tag=0;if(resources.replace(*id,changed)!=gameplay_scenario::SceneStatus::completed)return false;}}
    return true;
}
void ResourceOwnership::clear_actor_claims(std::uint32_t actor){
    const unsigned tag=unsigned(std::uint8_t(actor))+1;
    for(unsigned slot=0;slot<256;++slot){auto item=descriptor(std::uint8_t(slot));if(item.active&&unsigned(item.claim_tag)==tag){item.claim_tag=0;publish(std::uint8_t(slot),item);}}
}
}
