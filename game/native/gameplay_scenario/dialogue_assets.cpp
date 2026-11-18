#include "dialogue_assets.hpp"
#include <algorithm>
#include <bit>
#include <cstdio>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
std::uint32_t word(const content::Bytes& data,std::size_t at){
    if(!data||at>data->size()||4>data->size()-at)throw std::invalid_argument("Dialogue word outside owned resource");
    std::uint32_t value{};for(unsigned i=0;i<4;++i)value|=std::uint32_t(std::to_integer<unsigned>((*data)[at+i]))<<(8*i);return value;
}
std::uint16_t half(const content::Bytes& data,std::size_t at)noexcept{
    return std::uint16_t(std::to_integer<unsigned>((*data)[at])|(std::to_integer<unsigned>((*data)[at+1])<<8));
}
}
DialogueCues::DialogueCues(content::Bytes data):bytes_(std::move(data)){
    if(!bytes_||bytes_->size()<24||word(bytes_,0)!=0x4e475448||word(bytes_,4)!=0x10000||word(bytes_,8)||word(bytes_,12))
        throw std::invalid_argument("Owned dialogue cue header unavailable");
    first_=word(bytes_,16);second_=word(bytes_,20);constexpr auto table_bytes=4*selections;
    if(first_!=24||second_<first_+table_bytes||second_>bytes_->size()||table_bytes>bytes_->size()-second_)
        throw std::invalid_argument("Owned dialogue cue tables unavailable");
    const std::size_t begin=first_+table_bytes;
    for(std::size_t i=0;i<selections;++i){const auto at=word(bytes_,first_+4*i);if(!at)continue;
        if(at<begin||at>second_||20>second_-at||(at-begin)%20)
            throw std::invalid_argument("Owned dialogue cue record outside its first table region");}
}
std::optional<DialogueCue> DialogueCues::cue(std::size_t selection)const noexcept{
    if(selection>=selections)return{};
    const auto at=word(bytes_,first_+4*selection);if(!at)return{};
    return DialogueCue{half(bytes_,at+2),std::bit_cast<std::int16_t>(half(bytes_,at+4)),std::bit_cast<std::int16_t>(half(bytes_,at+6))};
}
DialogueTexts::DialogueTexts(content::Bytes data):bytes_(std::move(data)){
    if(!bytes_||bytes_->size()<12)throw std::invalid_argument("Owned dialogue text header unavailable");
    effects_=word(bytes_,0);const auto first=word(bytes_,4);
    if(first<12||(first-4)%8||first>effects_||effects_>bytes_->size())
        throw std::invalid_argument("Owned dialogue text index unavailable");
    count_=(first-4)/8;
    if(count_>(bytes_->size()-effects_)/16||effects_+16*count_!=bytes_->size()||4*count_>effects_-first)
        throw std::invalid_argument("Owned dialogue text effects extent unavailable");
    for(std::size_t i=0;i<count_;++i){const auto reference=word(bytes_,4+8*i);
        if(word(bytes_,8+8*i)!=1||reference<first||reference>effects_||4>effects_-reference)
            throw std::invalid_argument("Owned dialogue text reference unavailable");
        const auto at=word(bytes_,reference);
        if(at<first+4*count_||at>effects_||8>=effects_-at||std::find(bytes_->begin()+at+8,bytes_->begin()+effects_,std::byte{})==bytes_->begin()+effects_)
            throw std::invalid_argument("Owned dialogue text body unavailable");}
}
std::optional<DialogueText> DialogueTexts::text(std::size_t index)const noexcept{
    if(index>=count_)return{};
    const auto at=word(bytes_,word(bytes_,4+8*index))+8;
    const auto end=std::find(bytes_->begin()+at,bytes_->begin()+effects_,std::byte{});
    DialogueText value;value.body=std::span<const std::byte>(*bytes_).subspan(at,std::size_t(end-(bytes_->begin()+at)));
    for(unsigned i=0;i<8;++i)value.effects[i]=half(bytes_,effects_+16*index+2*i);
    return value;
}
DialogueBank prepare_dialogue_bank(const content::ScenarioArchive& archive,std::uint16_t scenario,std::uint8_t section,std::uint8_t character){
    std::array<char,32> cue_name{},text_name{};
    std::snprintf(cue_name.data(),cue_name.size(),"sp%02u%02u%02u.bin",unsigned(scenario),unsigned(section),unsigned(character));
    std::snprintf(text_name.data(),text_name.size(),"spm%02u%02u%02u.bin",unsigned(scenario),unsigned(section),unsigned(character));
    DialogueBank value;value.cue_identity=cue_name.data();value.text_identity=text_name.data();
    if(const auto data=archive.read_resource(scenario,value.cue_identity))value.cues=std::make_shared<const DialogueCues>(data);
    if(const auto data=archive.read_resource(scenario,value.text_identity))value.texts=std::make_shared<const DialogueTexts>(data);
    return value;
}
} // namespace reo::native::gameplay_scenario
