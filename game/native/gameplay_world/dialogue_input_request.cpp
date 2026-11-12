#include "dialogue_input_request.hpp"
#include <bit>
namespace reo::native::gameplay_world {
namespace {
DialogueInputRequested prepare(SpeechState& speech,const gameplay_actors::input::Frame* frame,std::optional<bool> suppression,std::optional<std::size_t> physical_index)noexcept{
    if(!suppression)return{DialogueStatus::unavailable,false};
    if(*suppression)return{};
    if(!frame)return{DialogueStatus::unavailable,false};
    std::optional<unsigned> direction;
    if(frame->pressed&0x2000u){speech.request=1;direction=4;}
    else if(frame->pressed&0xf00000u){speech.request=1;direction=(std::uint16_t(std::int32_t(frame->analog[5])+8192))>>14;}
    if(!speech.request)return{DialogueStatus::unavailable,false};
    if(!*speech.request)return{};
    // Without a fresh direction, the standalone entry has no direction
    // producer. The actual mode-zero caller can supply its physical loop
    // index, which is already live across this call in the original body.
    const bool fresh=bool(direction);
    if(!direction){if(!physical_index)return{DialogueStatus::unsupported_profile,false};if(*physical_index>=8)return{DialogueStatus::unsupported_profile,false};direction=unsigned(*physical_index);}
    constexpr std::array<std::uint8_t,8> ordinary{1,4,3,2,7,0,0,0},modified{129,128,5,130,6,0,0,0};
    speech.variant=std::bit_cast<std::int8_t>((frame->held&0x80u)?modified[*direction]:ordinary[*direction]);
    // The normal table's admitted values1..7 cannot equal the source's later
    // full-word comparison of signed DA9 with positive0x82 in mode zero.
    return{DialogueStatus::completed,fresh};
 }
}
DialogueInputRequested prepare_dialogue_input_request(SpeechState& speech,const gameplay_actors::input::Frame* frame,std::optional<bool> suppression)noexcept{return prepare(speech,frame,suppression,{});}
DialogueInputRequested prepare_loop_dialogue_input_request(SpeechState& speech,const gameplay_actors::input::Frame* frame,std::optional<bool> suppression,std::size_t physical_index)noexcept{return prepare(speech,frame,suppression,physical_index);}
}
