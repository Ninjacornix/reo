#include "dialogue_partner_characters.hpp"
#include <bit>
namespace reo::native::gameplay_world {
DialoguePartnersRebuilt rebuild_dialogue_partner_characters(World& world,const actors::EntityId& id)noexcept{
    if(world.closed())return{DialogueStatus::closed,0};
    const auto actor=world.resolve(id);
    if(!actor)return{DialogueStatus::unavailable,0};
    if(actor->category)return{};
    actor->speech.partner_characters=std::array<std::int8_t,4>{-1,-1,-1,-1};
    const auto population=world.session().primary_population;
    if(!population)return{DialogueStatus::unavailable,0};
    if(*population>World::primary_capacity)return{DialogueStatus::unsupported_profile,0};
    std::size_t written{};
    for(std::size_t i=0;i<*population;++i){
        const auto candidate=world.primary(i);
        if(!candidate)return{DialogueStatus::unavailable,written};
        if(candidate->character==actor->character)continue;
        if(written==actor->speech.partner_characters->size())return{DialogueStatus::unsupported_profile,written};
        (*actor->speech.partner_characters)[written++]=std::bit_cast<std::int8_t>(candidate->character);
    }
    return{DialogueStatus::completed,written};
}
}
