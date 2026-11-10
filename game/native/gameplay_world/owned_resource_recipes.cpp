#include "owned_resource_recipes.hpp"
#include "../gameplay_update/update.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
OwnedResourceRecipes::OwnedResourceRecipes(ResourceRecipes& recipes,gameplay_update::Owner& update):recipes_(recipes),update_(update){
    if(&recipes_.pairs_.world_!=&update_.world()||!update_.open()||!update_.cooperative_events().open())throw std::invalid_argument("Native owned recipe update/event owner unavailable or foreign");
}
void OwnedResourceRecipes::admit()const{if(!update_.open()||!update_.cooperative_events().open())throw std::runtime_error("Native owned recipe update/event owner closed");}
bool OwnedResourceRecipes::publish(std::uint32_t recipe,std::uint32_t full_extra,std::uint32_t old_content,const actors::EntityId& id){
    admit();last_event_.reset();const auto actor=update_.world().resolve(id);if(!actor)throw std::runtime_error("Native recipe event actor foreign or retired");
    const auto& world=update_.world();if(actor->category||actor->slot!=(world.mode==0?0:world.selected_actor))return false;
    const auto extra=std::bit_cast<std::int16_t>(std::uint16_t(full_extra));std::optional<std::uint16_t> event;std::uint16_t first{};
    if(actor->character==3&&(recipe==0xf||recipe==0x10)){
        switch(extra){case 0x136:event=0x13;break;case 0x137:event=0x15;break;case 0x13a:event=0x14;break;case 0x13b:event=0x16;break;case 0x13c:event=0x17;break;case 0x13d:event=0x18;break;default:break;}
        if(event)first=std::uint16_t(old_content);
    }
    if(!event&&actor->character==4&&(recipe==0x11||recipe==0x12||recipe==0x13)){
        switch(extra){case 0x71:event=0x1a;break;case 0x1d:event=0x1b;break;case 0x73:event=0x1c;break;case 0:case 1:event=0x1d;break;case 0xb:event=0x1e;break;default:break;}
    }
    if(!event&&(recipe==9||recipe==0xa)&&extra==0x72)event=0x19;
    if(!event)return false;
    const auto result=update_.record_event(*event,first,0);last_event_=result.status;
    if(result.status!=gameplay_events::Status::completed&&result.status!=gameplay_events::Status::priority_rejected&&result.status!=gameplay_events::Status::full)throw std::runtime_error("Native recipe event recording capability unavailable");
    return true;
}
std::int8_t OwnedResourceRecipes::apply(std::uint32_t full_first,std::uint32_t full_second){
    admit();last_event_.reset();auto& pairs=recipes_.pairs_;const auto first=std::uint8_t(full_first),second=std::uint8_t(full_second);const auto a=pairs.descriptor(first),b=pairs.descriptor(second);
    if(!a.active||!b.active||!a.ownership_tag||!b.ownership_tag)return 0;
    const auto match=pairs.classify(first,second);const auto kind=std::uint8_t(std::uint16_t(match.kind));if(kind==0||kind==0x15||kind>=0x18)return 0;
    if(!match.extra)throw std::runtime_error("Native owned recipe matched payload unavailable");
    const auto extra=std::uint16_t(*match.extra);std::uint16_t old{};std::int8_t result{};
    const auto primitive=[&](RecipePrimitive operation,bool reverse=false){return recipes_.primitive(operation,reverse?second:first,reverse?first:second,extra);};
    const auto reverse_result=[](std::int8_t value){return value==3?std::int8_t(2):value;};
    switch(kind){
    case 1:case 0x16:result=primitive(RecipePrimitive::merge_positive);break;
    case 2:case 0x17:result=reverse_result(primitive(RecipePrimitive::merge_positive,true));break;
    case 3:result=primitive(RecipePrimitive::merge_matching);break;
    case 4:case 5:result=primitive(RecipePrimitive::replace_owned_and_consume);break;
    case 6:result=reverse_result(primitive(RecipePrimitive::replace_owned_and_consume,true));break;
    case 7:result=primitive(RecipePrimitive::redistribute);break;
    case 8:result=reverse_result(primitive(RecipePrimitive::redistribute,true));break;
    case 9:result=primitive(RecipePrimitive::replace_owned);break;
    case 0xa:result=primitive(RecipePrimitive::replace_owned,true);break;
    case 0xb:result=primitive(RecipePrimitive::swap_into_second);break;
    case 0xc:result=primitive(RecipePrimitive::swap_into_second,true);break;
    case 0xd:result=primitive(RecipePrimitive::fill_first);break;
    case 0xe:result=reverse_result(primitive(RecipePrimitive::fill_first,true));break;
    case 0xf:old=pairs.descriptor(second).attachment_id;result=primitive(RecipePrimitive::replace_from_195);break;
    case 0x10:old=pairs.descriptor(first).attachment_id;result=primitive(RecipePrimitive::replace_from_195,true);break;
    case 0x11:result=primitive(RecipePrimitive::consume_owner_199);break;
    case 0x12:result=primitive(RecipePrimitive::consume_19a);break;
    case 0x13:result=primitive(RecipePrimitive::consume_19a,true);if(result==2)result=3;break;
    case 0x14:result=primitive(RecipePrimitive::replace_with_reverse_followup);break;
    default:break;
    }
    if(!result)return 0;
    const auto after=pairs.descriptor(first);const auto owner=after.active?after.ownership_tag:pairs.descriptor(second).ownership_tag;
    if(owner<1||owner>4)throw std::runtime_error("Native owned recipe post-operation primary owner unavailable");
    const auto actor=update_.world().identity(owner-1u);if(!actor)throw std::runtime_error("Native owned recipe post-operation actor unavailable");
    (void)publish(std::uint32_t(std::int32_t(match.kind)),extra,old,actor);return result;
}
}
