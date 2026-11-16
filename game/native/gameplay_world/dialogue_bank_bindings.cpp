#include "dialogue_bank_bindings.hpp"
#include <utility>
namespace reo::native::gameplay_world {
DialogueBankPublished DialogueBankBindings::map(std::size_t physical,std::optional<std::uint8_t> character)noexcept{
    if(physical==4)return{DialogueBankBindingStatus::completed,true,false};
    // The original publishes the physical half before reading actor.B98.
    // A missing/invalid character preserves that completed physical write.
    if(!character)return{DialogueBankBindingStatus::unavailable,true,false};
    if(*character>=character_to_physical_.size())return{DialogueBankBindingStatus::unsupported_profile,true,false};
    character_to_physical_[*character]=std::uint8_t(physical);
    return{DialogueBankBindingStatus::completed,true,true};
}
DialogueBankPublished DialogueBankBindings::publish_cues(std::size_t physical,std::optional<std::uint8_t> character,
    std::shared_ptr<const gameplay_scenario::DialogueCues> cues,std::string identity){
    if(physical>=physical_.size())return{DialogueBankBindingStatus::unsupported_profile};
    if(!cues)return{DialogueBankBindingStatus::unavailable};
    physical_[physical].cues=std::move(cues);physical_[physical].cue_identity=std::move(identity);
    return map(physical,character);
}
DialogueBankPublished DialogueBankBindings::publish_texts(std::size_t physical,std::optional<std::uint8_t> character,
    std::shared_ptr<const gameplay_scenario::DialogueTexts> texts,std::string identity){
    if(physical>=physical_.size())return{DialogueBankBindingStatus::unsupported_profile};
    if(!texts)return{DialogueBankBindingStatus::unavailable};
    physical_[physical].texts=std::move(texts);physical_[physical].text_identity=std::move(identity);
    return map(physical,character);
}
std::array<gameplay_scenario::DialogueBank,9> DialogueBankBindings::logical()const{
    std::array<gameplay_scenario::DialogueBank,9> result;
    for(std::size_t i=0;i<character_to_physical_.size();++i)result[i]=physical_[character_to_physical_[i]];
    result[8]=physical_[4];return result;
}
const gameplay_scenario::DialogueBank* DialogueBankBindings::physical(std::size_t index)const noexcept{return index<physical_.size()?&physical_[index]:nullptr;}
std::optional<std::uint8_t> DialogueBankBindings::physical_for_character(std::size_t index)const noexcept{return index<character_to_physical_.size()?std::optional(character_to_physical_[index]):std::nullopt;}
}
