#include "dialogue_response_uses.hpp"
#include <bit>
namespace reo::native::gameplay_world {
std::optional<std::size_t> find_dialogue_response_use(std::span<DialogueResponseUse,1000> uses,std::int32_t selection)noexcept{
    std::optional<std::size_t> vacant;
    for(std::size_t i=0;i<uses.size();++i){
        if(uses[i].selection==selection)return i;
        if(!vacant&&uses[i].selection<0)vacant=i;
    }
    if(vacant)uses[*vacant].selection=std::bit_cast<std::int16_t>(std::uint16_t(selection));
    return vacant;
}
void choose_dialogue_response_use(std::span<DialogueResponseUse,1000> uses,std::int32_t& selected,std::int32_t candidate)noexcept{
    if(selected<0){find_dialogue_response_use(uses,candidate);selected=candidate;return;}
    const auto previous=find_dialogue_response_use(uses,selected);
    const auto incoming=find_dialogue_response_use(uses,candidate);
    if(!previous||!incoming)return;
    const auto& old=uses[*previous];const auto& next=uses[*incoming];
    if(next.count<old.count||(next.count==old.count&&next.selection<old.selection))selected=candidate;
}
void increment_dialogue_response_use(std::span<DialogueResponseUse,1000> uses,std::int32_t choice)noexcept{
    if(const auto index=find_dialogue_response_use(uses,choice)){
        auto& count=uses[*index].count;count=std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(count)+1));
        if(count>=10000)count=9999;
    }
}
}
