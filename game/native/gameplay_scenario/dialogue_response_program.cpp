#include "dialogue_response_program.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
std::uint32_t word(const std::vector<std::byte>& b,std::size_t at)noexcept{
    std::uint32_t value{};for(unsigned i=0;i<4;++i)value|=std::uint32_t(std::to_integer<unsigned>(b[at+i]))<<(8*i);return value;
}
std::uint16_t half(const std::vector<std::byte>& b,std::size_t at)noexcept{return std::uint16_t(std::to_integer<unsigned>(b[at])|(std::to_integer<unsigned>(b[at+1])<<8));}
std::int8_t byte(const std::vector<std::byte>& b,std::size_t at)noexcept{return std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(b[at]));}
}
DialogueResponseProgram::DialogueResponseProgram(std::shared_ptr<const DialogueCues> cues):cues_(std::move(cues)){
    if(!cues_)throw std::invalid_argument("Dialogue response cues unavailable");
    const auto& b=*cues_->backing();const auto table=word(b,20);const auto begin=std::size_t(table)+4*DialogueCues::selections;
    if(begin>b.size()||(b.size()-begin)%48)throw std::invalid_argument("Dialogue response row extent unavailable");
    rows_.resize((b.size()-begin)/48);
    for(std::size_t i=0;i<selections_.size();++i){const auto at=word(b,table+4*i);if(!at)continue;
        if(at<begin||at>b.size()||48>b.size()-at||(at-begin)%48)throw std::invalid_argument("Dialogue response outside second table region");
        const auto physical=(at-begin)/48;selections_[i]=physical;if(rows_[physical])continue;
        DialogueResponseEntry entry;entry.physical_row=physical;entry.definition.cue=std::bit_cast<std::int16_t>(half(b,at));entry.definition.group=byte(b,at+2);entry.definition.mode=byte(b,at+3);
        for(unsigned c=0;c<4;++c){const auto offset=at+4+8*c;entry.definition.conditions[c]={std::to_integer<std::uint8_t>(b[offset]),std::to_integer<std::uint8_t>(b[offset+1]),half(b,offset+2),std::bit_cast<std::int32_t>(word(b,offset+4))};entry.initial.condition_results[c]=byte(b,at+40+c);}
        for(unsigned c=0;c<3;++c)entry.definition.combiners[c]=byte(b,at+36+c);
        entry.initial.replied_to=word(b,at+44);rows_[physical]=entry;
    }
}
std::optional<DialogueResponseEntry> DialogueResponseProgram::response(std::size_t selection)const noexcept{
    if(selection>=selections_.size()||!selections_[selection])return{};
    return rows_[*selections_[selection]];
}
} // namespace reo::native::gameplay_scenario
