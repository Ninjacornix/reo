#include "dialogue_response_choice.hpp"
#include <bit>
namespace reo::native::gameplay_world {
namespace {
std::uint32_t word(const std::vector<std::byte>& bytes,std::size_t at)noexcept{
    std::uint32_t value{};for(unsigned i=0;i<4;++i)value|=std::uint32_t(std::to_integer<unsigned>(bytes[at+i]))<<(8*i);return value;
}
std::uint16_t half(const std::vector<std::byte>& bytes,std::size_t at)noexcept{return std::uint16_t(std::to_integer<unsigned>(bytes[at])|(std::to_integer<unsigned>(bytes[at+1])<<8));}
}
std::optional<DialogueResponseCueMetadata> dialogue_response_cue_metadata(const gameplay_scenario::DialogueCues& cues,std::size_t selection)noexcept{
    if(selection>=gameplay_scenario::DialogueCues::selections)return{};
    const auto& bytes=*cues.backing();const auto at=word(bytes,word(bytes,16)+4*selection);if(!at)return{};
    DialogueResponseCueMetadata result;result.blocked=std::bit_cast<std::int16_t>(half(bytes,at+8));result.priority=std::bit_cast<std::int16_t>(half(bytes,at+10));
    for(unsigned i=0;i<4;++i)result.replies[i]=half(bytes,at+12+2*i);
    return result;
}
DialogueResponsePriority dialogue_response_priority(const Actor& actor,std::uint8_t selected_slot,std::optional<std::uint16_t> sequence,const gameplay_scenario::DialogueCues* cues)noexcept{
    if(actor.category||actor.slot!=selected_slot)return{};
    if(!sequence)return{DialogueStatus::unavailable,99};
    if(!*sequence||!cues)return{};
    if(*sequence>gameplay_scenario::DialogueCues::selections)return{DialogueStatus::unsupported_profile,99};
    const auto metadata=dialogue_response_cue_metadata(*cues,*sequence-1);
    return{DialogueStatus::completed,metadata?metadata->priority:std::int16_t(99)};
}
DialogueResponseEvaluated evaluate_dialogue_response_choice(World& world,const DialoguePool* pool,const actors::EntityId& id,
    const gameplay_scenario::DialogueResponseDefinition& definition,DialogueResponseMutable& row,
    const gameplay_scenario::DialogueCues* actor_cues,std::optional<std::uint16_t> selected_sequence,
    const gameplay_scenario::DialogueCues* selected_cues,std::span<std::int32_t,8> choices,const DialogueConditionBindings& bindings)noexcept{
    DialogueResponseEvaluated report;
    if(world.closed()){report.status=DialogueStatus::closed;return report;}
    const auto actor=world.resolve(id);if(!actor){report.status=DialogueStatus::unavailable;return report;}
    for(std::size_t i=0;i<4;++i){
        const auto value=evaluate_dialogue_condition(world,pool,definition.conditions[i],id,bindings);
        if(value.status!=DialogueStatus::completed){report.status=value.status;return report;}
        row.condition_results[i]=std::bit_cast<std::int8_t>(std::uint8_t(value.value));++report.evaluated;
    }
    std::int32_t accepted=row.condition_results[0];
    for(std::size_t i=0;i<3;++i){if(definition.combiners[i]==0)accepted&=row.condition_results[i+1];else if(definition.combiners[i]>0)accepted|=row.condition_results[i+1];}
    if(actor_cues){
        if(row.cue<0||std::uint16_t(row.cue)>=gameplay_scenario::DialogueCues::selections){report.status=DialogueStatus::unsupported_profile;return report;}
        if(const auto metadata=dialogue_response_cue_metadata(*actor_cues,std::uint16_t(row.cue))){
            if(metadata->blocked)accepted=0;
            const auto priority=dialogue_response_priority(*actor,world.selected_actor,selected_sequence,selected_cues);
            if(priority.status!=DialogueStatus::completed){report.status=priority.status;return report;}
            if(metadata->priority>=priority.value)accepted=0;
        }
    }
    if(definition.mode==2){
        if(!actor->speech.selection){report.status=DialogueStatus::unavailable;return report;}
        const auto& target=*actor->speech.selection;
        if(target.target_context<0&&target.target_identifier>=0&&(row.replied_to&(1u<<(std::uint16_t(target.target_identifier)&31u))))accepted=0;
    }
    if(definition.group<0||std::uint8_t(definition.group)>=choices.size()){report.status=DialogueStatus::unsupported_profile;return report;}
    choices[std::uint8_t(definition.group)]=accepted?std::int32_t(row.cue)+1:0;report.chosen=bool(accepted);return report;
}
}
