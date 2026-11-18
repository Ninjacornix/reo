#include "resource_recipes.hpp"
#include <bit>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
std::int16_t half(std::int32_t v){return std::bit_cast<std::int16_t>(std::uint16_t(v));}
std::int16_t capacity(const gameplay_scenario::ResourceTemplate& row){std::int16_t result;std::memcpy(&result,row.encoded.data()+8,2);return result;}
}
ResourceRecipes::ResourceRecipes(ResourcePairs& pairs,ResourceContents& contents,WorldInventory& inventory):pairs_(pairs),contents_(contents),inventory_(inventory){
    if(pairs.world_.closed()||&pairs.world_!=&contents.world_||&pairs.resources_!=&contents.resources_||&pairs.templates_!=&contents.templates_||&pairs.world_!=&inventory.world_||&pairs.resources_!=&inventory.resources_||&pairs.templates_!=&inventory.templates_||&pairs.frames_!=&inventory.frames_||&pairs.frames_!=&contents.factory_.frames_)throw std::invalid_argument("Native recipe owners unavailable or foreign");
}
void ResourceRecipes::destroy_general(std::uint8_t index){
    const auto item=pairs_.descriptor(index);if(!item.active)return;
    if(item.ownership_tag){pairs_.destroy_owned(index);return;}
    pairs_.frames_.release(index);const auto after=pairs_.descriptor(index);const auto target=pairs_.resources_.slot(after.instance_index);
    if(!target||pairs_.resources_.deactivate(*target)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native general recipe destruction unavailable");
}
std::int8_t ResourceRecipes::merge(std::uint8_t first,std::uint8_t second,bool positive,bool reject_full,bool general){
    auto a=pairs_.descriptor(first),b=pairs_.descriptor(second);if(positive&&b.parameter<=0)return 0;if(!positive&&a.attachment_id!=b.attachment_id)return 0;
    const auto cap=capacity(pairs_.metadata(first));if(positive&&a.parameter>=cap)return 0;if(reject_full&&(a.parameter==cap||b.parameter==cap))return 0;
    const auto sum=half(std::int32_t(a.parameter)+b.parameter);
    if(sum>cap){pairs_.quantity(first,cap);pairs_.quantity(second,std::int32_t(sum)-cap);}
    else{pairs_.quantity(first,sum);pairs_.quantity(second,0);}
    b=pairs_.descriptor(second);if(b.parameter>0)return 1;if(general)destroy_general(b.instance_index);else pairs_.destroy_owned(b.instance_index);return general?2:3;
}
std::int8_t ResourceRecipes::redistribute(std::uint8_t first,std::uint8_t second,std::uint32_t content){
    const auto before=pairs_.descriptor(first);if(pairs_.descriptor(second).parameter<0||before.attachment_id<0x17||before.attachment_id>0x1b)return 0;
    const auto replacement=std::uint16_t(before.attachment_id-0x17+0x101),saved=std::bit_cast<std::uint16_t>(before.parameter);
    pairs_.quantity(first,0);contents_.replace_direct(first,content);auto excess=pairs_.descriptor(second).parameter;const auto cap=capacity(pairs_.metadata(first));
    if(excess>cap){pairs_.quantity(first,cap);excess=half(std::int32_t(excess)-cap);}else{pairs_.quantity(first,excess);excess=0;}
    if(std::bit_cast<std::int16_t>(saved)>0){contents_.replace_direct(second,replacement);pairs_.quantity(second,std::bit_cast<std::int16_t>(saved));return 1;}
    if(excess>0){pairs_.quantity(second,excess);return 1;}
    pairs_.destroy_owned(pairs_.descriptor(second).instance_index);return 3;
}
std::int8_t ResourceRecipes::fill(std::uint8_t first,std::uint8_t second){
    //5B30F0 enters5B4320 with its original a0: capacity belongs to FIRST.
    const auto cap=capacity(pairs_.metadata(first));const auto other=pairs_.descriptor(second).parameter;if(other<=0)return 0;
    const auto before=pairs_.descriptor(first).parameter;if(before>=cap)return 0;const auto delta=half(std::int32_t(cap)-before);
    if(delta<other){pairs_.quantity(first,cap);pairs_.quantity(second,std::int32_t(pairs_.descriptor(second).parameter)-delta);}
    else{pairs_.quantity(first,std::int32_t(before)+other);pairs_.quantity(second,0);}
    const auto after=pairs_.descriptor(second);if(after.parameter>0)return 1;pairs_.destroy_owned(after.instance_index);return 3;
}
std::int8_t ResourceRecipes::consume_owner(std::uint8_t first,std::uint8_t second,std::uint32_t content){
    const auto owner=pairs_.descriptor(first).ownership_tag;const auto next=half(std::uint16_t(content));if(owner>=5||next<0)return 0;
    if(!owner)throw std::runtime_error("Native owner199 recipe cannot read before the primary actor array");
    const auto actor=pairs_.world_.primary(owner-1u);const auto id=pairs_.world_.identity(owner-1u);if(!actor||!id)throw std::runtime_error("Native owner199 recipe actor unavailable");
    for(unsigned i=0;i<actor->inventory.storage.size();++i){const auto slot=actor->inventory.storage[i];if(!slot)continue;const auto item=pairs_.descriptor(slot);if(!item.active||item.attachment_id!=0x199||item.parameter<=0)continue;
        pairs_.quantity(slot,std::int32_t(item.parameter)-1);
        if(pairs_.descriptor(slot).parameter<=0){(void)inventory_.detach_item(id,slot);pairs_.destroy_owned(actor->inventory.storage[i]);}
        break;
    }
    std::int16_t saved=1;if(next==0x1d){const auto a=pairs_.descriptor(first);saved=a.attachment_id==0x1c?a.parameter:pairs_.descriptor(second).parameter;}
    (void)contents_.replace_owned(pairs_.descriptor(first).instance_index,content);if(next==0x1d)pairs_.quantity(first,saved);
    pairs_.destroy_owned(pairs_.descriptor(second).instance_index);return 3;
}
std::int8_t ResourceRecipes::primitive(RecipePrimitive operation,std::uint8_t first,std::uint8_t second,std::uint32_t content){
    const auto next=half(std::uint16_t(content));
    switch(operation){
    case RecipePrimitive::merge_positive:return merge(first,second,true,false,false);
    case RecipePrimitive::merge_matching:return merge(first,second,false,true,false);
    case RecipePrimitive::merge_general:return merge(first,second,false,false,true);
    case RecipePrimitive::replace_owned_and_consume:
        if(next<0)return 0;
        (void)contents_.replace_owned(pairs_.descriptor(first).instance_index,content);pairs_.destroy_owned(pairs_.descriptor(second).instance_index);return 3;
    case RecipePrimitive::replace_owned:
        if(next<0)return 0;
        (void)contents_.replace_owned(pairs_.descriptor(first).instance_index,content);return 1;
    case RecipePrimitive::redistribute:return redistribute(first,second,content);
    case RecipePrimitive::swap_into_second:{
        const auto before=pairs_.descriptor(second).parameter;const auto cap=capacity(pairs_.metadata(second));if(before<cap){const auto other=pairs_.descriptor(first).parameter;if(other>0){pairs_.quantity(second,other);pairs_.quantity(first,before);}}return 1;
    }
    case RecipePrimitive::fill_first:return fill(first,second);
    case RecipePrimitive::replace_from_195:
        if(pairs_.descriptor(first).attachment_id!=0x195||next<0)return 0;
        contents_.replace_direct(second,content);return 1;
    case RecipePrimitive::consume_owner_199:return consume_owner(first,second,content);
    case RecipePrimitive::consume_19a:{
        if(pairs_.descriptor(first).attachment_id!=0x19a||next<0)return 0;
        contents_.replace_direct(second,content);pairs_.quantity(first,std::int32_t(pairs_.descriptor(first).parameter)-1);const auto after=pairs_.descriptor(first);if(after.parameter>0)return 1;pairs_.destroy_owned(after.instance_index);return 2;
    }
    case RecipePrimitive::replace_with_reverse_followup:{
        if(next<0)return 0;
        contents_.replace_direct(first,content);const auto match=pairs_.classify(second,first);if(match.kind==0x14){if(!match.extra)throw std::runtime_error("Native reverse recipe matched payload unavailable");if(*match.extra>=0)contents_.replace_direct(second,std::uint16_t(*match.extra));}return 1;
    }
    case RecipePrimitive::replace_general_and_consume:
        if(next<0)return 0;
        contents_.replace_direct(first,content);destroy_general(pairs_.descriptor(second).instance_index);return 2;
    }
    throw std::invalid_argument("Native recipe primitive unavailable");
}
std::int8_t ResourceRecipes::combine_active(std::uint32_t full_first,std::uint32_t full_second){
    const auto first=std::uint8_t(full_first),second=std::uint8_t(full_second);if(!pairs_.descriptor(first).active||!pairs_.descriptor(second).active)return 0;
    for(auto slot:{first,second}){auto value=pairs_.descriptor(slot);value.flags|=1u;if(pairs_.resources_.replace(*pairs_.resources_.slot(slot),value)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Native active recipe flags changed");}
    const auto match=pairs_.classify(first,second);switch(std::uint8_t(std::uint16_t(match.kind))){
    case 3:return merge(first,second,false,false,true);
    case 4:if(!match.extra)throw std::runtime_error("Native active recipe payload unavailable");return primitive(RecipePrimitive::replace_general_and_consume,first,second,std::uint16_t(*match.extra));
    default:return 0;
    }
}
}
