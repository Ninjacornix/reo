#include "attenuation.hpp"
#include <algorithm>
#include <bit>

namespace reo::native::adxt_attenuation {
Table::Table(std::span<const std::uint32_t> words)noexcept{std::copy(words.begin(),words.end(),words_.begin());}
Open Table::from_words(std::span<const std::uint32_t> words)noexcept {
    if(words.size()!=table_words || words.front()!=256 || words.back()!=0)return {};
    for(std::size_t i=1;i<words.size();++i)if(words[i]>words[i-1])return {};
    try{return {Status::completed,std::shared_ptr<const Table>(new Table(words))};}
    catch(...){return {Status::no_memory,{}};}
}
Result Table::apply(std::uint32_t requested_word,Metadata metadata)const noexcept {
    const auto requested=std::bit_cast<std::int16_t>(static_cast<std::uint16_t>(requested_word));
    const bool ready=std::bit_cast<std::int32_t>(metadata.presence)>0 &&
        (metadata.decoder_phase==2 || metadata.decoder_phase==3);
    const auto offset=ready?std::bit_cast<std::int16_t>(metadata.offset):std::int16_t{};
    const auto clamped=std::clamp(std::int32_t(requested)+offset,-999,0);
    return {requested,clamped,words_[static_cast<std::size_t>(-clamped)]};
}
} // namespace reo::native::adxt_attenuation
