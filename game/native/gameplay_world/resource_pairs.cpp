#include "resource_pairs.hpp"
#include <bit>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
template<class T>T read(const gameplay_scenario::ResourceTemplate& row,unsigned offset){T result;std::memcpy(&result,row.encoded.data()+offset,sizeof result);return result;}
std::int16_t half(std::int32_t value){return std::bit_cast<std::int16_t>(std::uint16_t(value));}
constexpr std::array<std::array<std::int16_t,2>,11> special_recipes{{
#include "resource_special_recipe_profile.inc"
}};
}
ResourcePairs::ResourcePairs(World& world,gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates,ResourceFrames& frames):world_(world),resources_(resources),templates_(templates),frames_(frames){
    if(!frames.open()||&frames.world_!=&world||&frames.resources_!=&resources||!frames.templates_bound_to(templates))throw std::invalid_argument("Native resource-pair owners unavailable or foreign");
}
gameplay_scenario::SceneDescriptor ResourcePairs::descriptor(std::uint8_t index)const{
    if(world_.closed())throw std::runtime_error("Native resource-pair world closed");
    const auto id=resources_.slot(index);const auto value=id?resources_.get(*id):std::nullopt;
    if(!value)throw std::runtime_error("Native resource-pair descriptor unavailable");
    return *value;
}
const gameplay_scenario::ResourceTemplate& ResourcePairs::metadata(std::uint8_t index)const{
    const auto value=descriptor(index);const unsigned selected=value.active&&value.template_index!=255?value.template_index:128;
    if(selected>=templates_.state().templates.size())throw std::runtime_error("Native resource-pair template unavailable");
    return templates_.state().templates[selected];
}
ResourcePairMatch ResourcePairs::special(const gameplay_scenario::SceneDescriptor& first,const gameplay_scenario::SceneDescriptor& second)const{
    if(!first.ownership_tag||first.ownership_tag>4)throw std::runtime_error("Native special resource recipe owner unavailable");
    const auto actor=world_.primary(first.ownership_tag-1u);if(!actor)throw std::runtime_error("Native special resource recipe actor unavailable");
    bool admitted{};
    for(const auto slot:actor->inventory.storage)if(slot){const auto item=descriptor(slot);if(item.attachment_id==0x199&&item.parameter>0){admitted=true;break;}}
    if(!admitted)return{};
    unsigned start{},count{};switch(first.attachment_id){
    case 0x1c:start=0;count=1;break;case 0x66:start=1;count=2;break;case 0x67:start=3;count=2;break;
    case 0x6a:start=5;count=1;break;case 0x6f:start=6;count=2;break;case 0x76:start=8;count=1;break;
    case 0x1c2:start=9;count=1;break;case 0x1c7:start=10;count=1;break;default:return{};
    }
    for(unsigned i=0;i<count;++i){const auto& row=special_recipes[start+i];if(std::int32_t(second.attachment_id)==std::int32_t(row[0]))return{0x11,row[1]};}
    return{};
}
ResourcePairMatch ResourcePairs::classify(std::optional<std::uint8_t> first_slot,std::optional<std::uint8_t> second_slot)const{
    if(world_.closed())throw std::runtime_error("Native resource-pair world closed");
    if(!first_slot||!second_slot||first_slot==second_slot)return{};
    const auto first=descriptor(*first_slot),second=descriptor(*second_slot);
    if(first.ownership_tag<5&&second.ownership_tag<5){
        if(!first.ownership_tag)throw std::runtime_error("Native resource recipe cannot read before the primary actor array");
        const auto actor=world_.primary(first.ownership_tag-1u);if(!actor)throw std::runtime_error("Native resource recipe primary actor unavailable");
        if(actor->character==4){
            if(!second.ownership_tag)throw std::runtime_error("Native resource recipe cannot read before the second primary actor array");
            const auto other=world_.primary(second.ownership_tag-1u);if(!other)throw std::runtime_error("Native resource recipe second primary actor unavailable");
            if(other->character==4){switch(first.attachment_id){case 0x1c:case 0x66:case 0x67:case 0x6a:case 0x6f:case 0x76:case 0x1c2:case 0x1c7:{const auto match=special(first,second);if(match.kind)return match;break;}default:break;}}
        }
    }
    const auto& row=metadata(*first_slot);const auto offset=read<std::int16_t>(row,4),count=read<std::int16_t>(row,6);if(offset<0||count<=0)return{};
    const auto& table=templates_.state().compatibility;
    for(unsigned i=0;i<unsigned(count);++i){const auto at=unsigned(offset)+3*i;if(at>=table.size())throw std::runtime_error("Native resource compatibility extent unavailable");
        if(std::int32_t(second.attachment_id)==std::int32_t(std::bit_cast<std::int16_t>(table[at]))){
            if(3>table.size()-at)throw std::runtime_error("Native matched resource compatibility payload unavailable");
            return{std::bit_cast<std::int16_t>(table[at+2]),std::bit_cast<std::int16_t>(table[at+1])};
        }
    }
    return{};
}
std::int16_t ResourcePairs::query_active(std::uint32_t first,std::uint32_t second)const{
    const auto a=std::uint8_t(first),b=std::uint8_t(second);if(!descriptor(a).active||!descriptor(b).active)return 0;return classify(a,b).kind;
}
void ResourcePairs::quantity(std::uint8_t index,std::int32_t value){
    auto item=descriptor(index);item.parameter=half(value);if(resources_.replace(*resources_.slot(index),item)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native resource quantity descriptor changed");
}
void ResourcePairs::destroy_owned(std::uint8_t index){
    const auto item=descriptor(index);if(!item.active||!item.ownership_tag)return;
    frames_.release(index);const auto after=descriptor(index);const auto target=resources_.slot(after.instance_index);
    if(!target||resources_.deactivate(*target)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native consumed resource deactivation unavailable");
}
std::int8_t ResourcePairs::move_quantity(std::uint8_t destination,std::optional<std::uint8_t> source,std::uint32_t full_amount){
    auto amount=half(std::uint16_t(full_amount));const auto capacity=read<std::int16_t>(metadata(destination),8);const auto initial=descriptor(destination).parameter;
    const auto space=std::int32_t(capacity)-initial;if(space<amount)amount=half(space);
    if(initial>=capacity||amount<=0||!source)return 0;
    const auto available=descriptor(*source).parameter;if(available<=0)return 0;
    if(available>=amount){quantity(destination,std::int32_t(descriptor(destination).parameter)+amount);quantity(*source,std::int32_t(descriptor(*source).parameter)-amount);}
    else{quantity(destination,std::int32_t(descriptor(destination).parameter)+available);quantity(*source,0);}
    const auto after=descriptor(*source);if(after.parameter>0)return 1;destroy_owned(after.instance_index);return 3;
}
std::int8_t ResourcePairs::swap_quantity(std::uint8_t first,std::uint8_t second){
    const auto before=descriptor(first).parameter;const auto capacity=read<std::int16_t>(metadata(first),8);if(before>=capacity)return 0;
    const auto other=descriptor(second).parameter;if(other<=0)return 0;quantity(first,other);quantity(second,before);return 1;
}
std::int8_t ResourcePairs::transfer_owned(std::uint32_t first,std::uint32_t second,std::uint32_t amount){
    if(half(std::uint16_t(amount))<=0)return 0;
    const auto a=std::uint8_t(first),b=std::uint8_t(second);const auto initial=descriptor(a);if(!initial.active||!initial.ownership_tag)return 0;
    const auto flags=read<std::uint32_t>(metadata(a),0);if(!(flags&0xc01u)||!(flags&0x100000u))return 0;
    const auto other=descriptor(b);if(!other.active||!other.ownership_tag)return 0;
    switch(classify(a,b).kind){case 0xd:case 1:return move_quantity(a,b,amount);case 0xb:return swap_quantity(b,a);case 0xc:return swap_quantity(a,b);default:return 0;}
}
}
