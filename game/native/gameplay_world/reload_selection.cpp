#include "reload_selection.hpp"
#include <bit>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
using namespace gameplay_scenario;
SceneDescriptor descriptor(const SceneResources& resources,std::uint8_t slot){
    const auto id=resources.slot(slot);const auto value=id?resources.get(*id):std::nullopt;
    if(!value)throw std::runtime_error("Native reload descriptor unavailable");return *value;
}
const ResourceTemplate& metadata(const SceneDescriptor& item,const ResourceTemplates& templates){
    const unsigned index=item.active&&item.template_index!=255?item.template_index:128;
    if(index>=templates.state().templates.size())throw std::runtime_error("Native reload template unavailable");
    return templates.state().templates[index];
}
std::int16_t half(const ResourceTemplate& row,unsigned at){std::int16_t result;std::memcpy(&result,row.encoded.data()+at,sizeof result);return result;}
//5B41E0 selects by compatibility kind and returns content; the caller does
// not consume its extra halfword. Keep first-match order, including content0.
std::int16_t compatible_content(const SceneDescriptor& item,const ResourceTemplates& templates,std::int16_t kind){
    const auto& row=metadata(item,templates);const auto offset=half(row,4),count=half(row,6);
    if(offset<0||count<=0)return 0;
    const auto& table=templates.state().compatibility;
    for(unsigned i=0;i<unsigned(count);++i){
        const auto at=unsigned(offset)+3*i;
        if(at>=table.size()||3>table.size()-at)throw std::runtime_error("Native reload compatibility extent unavailable");
        if(std::bit_cast<std::int16_t>(table[at+2])==kind)return std::bit_cast<std::int16_t>(table[at]);
    }
    return 0;
}
}
std::uint8_t select_inventory_quantity(const Actor& actor,const gameplay_scenario::SceneResources& resources,std::uint8_t mode,std::uint16_t content){
    std::uint16_t best=mode==1?0:65535;
    std::uint8_t result=255;
    for(unsigned i=0;i<actor.inventory.carried.size();++i){
        const auto slot=actor.inventory.carried[i];if(!slot)continue;
        const auto item=descriptor(resources,slot);if(item.attachment_id!=content)continue;
        const auto quantity=std::uint16_t(item.parameter);
        if(mode==0){if(!quantity||quantity>best)continue;}
        else if(mode==1){if(!quantity||quantity<best)continue;}
        else continue;
        best=quantity;result=std::uint8_t(i);
    }
    return result;
}
std::uint8_t select_reload_source(const Actor& actor,const gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates,std::uint8_t resource,std::int16_t mode){
    const auto item=descriptor(resources,resource);
    const auto content=compatible_content(item,templates,mode);if(!content)return 255;
    if(mode!=1&&mode!=12)throw std::runtime_error("Native reload selection mode has undefined original scratch");
    const auto selected=select_inventory_quantity(actor,resources,mode==12?1:0,std::uint16_t(content));
    if(selected==255)return 255;
    if(mode==12&&descriptor(resources,actor.inventory.carried[selected]).parameter<=item.parameter)return 255;
    return selected;
}
bool reload_available(const Actor& actor,const gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates,const animation_events::Metadata& actions,std::uint8_t resource){
    const auto action=std::uint16_t(resources.action_kind(resource,templates)); //5F1F40 runs before status/zero gates.
    if((actor.status&8u)||resource==0)return false;
    const auto item=descriptor(resources,resource);
    if(item.parameter>=half(metadata(item,templates),8))return false;
    switch(actions.action_flags(action)&0x1e0u){
    case 0x20:case 0x40:
        if(select_reload_source(actor,resources,templates,resource,12)!=255)return true;
        [[fallthrough]];
    case 0x80:case 0x100:return select_reload_source(actor,resources,templates,resource,1)!=255;
    default:return false;
    }
}
}
