#include "scene_text_bank.hpp"
#include "../gameplay_world/world.hpp"
#include <algorithm>
#include <cstdio>
#include <new>
#include <bit>
namespace reo::native::gameplay_scenario {
SceneTextBank::SceneTextBank(gameplay_world::Session& session,const content::ScenarioArchive& archive)noexcept:session_(session),archive_(archive){}
SceneTextBankLoaded SceneTextBank::load()noexcept{
    if(running_)return{SceneTextBankStatus::busy};
    running_=true;struct Exit{bool& active;~Exit(){active=false;}}exit{running_};
    if(!session_.scenario||!session_.asset_loading_mode)return{};
    try{
        content::Bytes data;
        // Mode0 uses flags1 and the fixed1342-entry default catalogue. Its
        // names contain no EVE_DMnnn_BIN key. It is not selected-scenario IO.
        if(*session_.asset_loading_mode){
            const auto scenario=*session_.scenario;
            if(scenario!=1&&scenario!=2&&scenario!=28&&scenario!=35&&scenario!=41)return{};
            std::array<char,32> key{};std::snprintf(key.data(),key.size(),"dm%03u.bin",unsigned(scenario));
            data=archive_.read_resource_sectors(scenario,key.data());
        }
        if(!data||data->empty()){
            std::fill_n(bytes_.begin(),4,std::byte{});known_=std::max(known_,std::size_t(4));
            return{SceneTextBankStatus::completed,false,0};
        }
        // The admitted front bank ends where the first actor SP window starts.
        // Reject larger inputs instead of overwriting another owner's bank.
        if(data->size()>capacity)return{SceneTextBankStatus::invalid_asset};
        std::copy(data->begin(),data->end(),bytes_.begin());known_=std::max(known_,data->size());
        return{SceneTextBankStatus::completed,true,data->size()};
    }catch(const std::bad_alloc&){return{SceneTextBankStatus::no_memory};}
    catch(...){return{};}
}
SceneTextBankLoaded SceneTextBank::load_messages(SceneTextVariant variant)noexcept{
    if(running_)return{SceneTextBankStatus::busy};
    if(variant!=SceneTextVariant::standard&&variant!=SceneTextVariant::alternate)return{};
    running_=true;struct Exit{bool& active;~Exit(){active=false;}}exit{running_};
    if(!session_.scenario||!session_.asset_loading_mode||!*session_.asset_loading_mode)return{};
    try{
        content::Bytes data;
        if(*session_.asset_loading_mode){
            const auto scenario=*session_.scenario;
            if(scenario!=1&&scenario!=2&&scenario!=28&&scenario!=35&&scenario!=41)return{};
            std::array<char,32> key{};
            std::snprintf(key.data(),key.size(),variant==SceneTextVariant::standard?"r%03u.bin":"r%03uu.bin",unsigned(scenario));
            data=archive_.read_resource_sectors(scenario,key.data());
        }
        if(!data||data->empty()){
            std::fill_n(messages_.begin(),4,std::byte{});messages_known_=std::max(messages_known_,std::size_t(4));
            return{SceneTextBankStatus::completed,false,0};
        }
        if(data->size()>messages_.size())return{SceneTextBankStatus::invalid_asset};
        std::copy(data->begin(),data->end(),messages_.begin());messages_known_=std::max(messages_known_,data->size());
        return{SceneTextBankStatus::completed,true,data->size()};
    }catch(const std::bad_alloc&){return{SceneTextBankStatus::no_memory};}
    catch(...){return{};}
}
namespace {
#include "system_text_messages.inc"
std::uint16_t text_half(std::span<const std::byte> bytes,std::size_t at)noexcept{
    return std::to_integer<std::uint16_t>(bytes[at])|std::uint16_t(std::to_integer<std::uint16_t>(bytes[at+1])<<8);
}
std::uint32_t text_word(std::span<const std::byte> bytes,std::size_t at)noexcept{
    return text_half(bytes,at)|(std::uint32_t(text_half(bytes,at+2))<<16);
}
}
std::optional<SceneTextLines> SceneTextBank::message_lines(std::int16_t id,std::uint32_t kind)const noexcept{
    if(id<0)return{};
    if(kind==2){
        // The source table has63 backed strings followed by a NULL pointer.
        // A NULL/foreign string cannot be admitted to the real cache consumer.
        if(std::size_t(id)>=system_text_rows.size())return{};
        const auto [offset,size]=system_text_rows[std::size_t(id)];
        try{
            SceneTextLines result;
            result.lines.emplace_back(reinterpret_cast<const std::byte*>(system_text_bytes+offset),size);
            return result;
        }catch(...){return{};}
    }
    if(kind!=0)return{};
    const auto bytes=messages_known();const auto row=4+std::size_t(id)*8;
    if(row>bytes.size()||bytes.size()-row<8)return{};
    const auto offset=std::size_t(text_word(bytes,row));
    const auto count=std::bit_cast<std::int32_t>(text_word(bytes,row+4));
    SceneTextLines result;if(count<=0)return result;
    if(offset>bytes.size()||std::size_t(count)>(bytes.size()-offset)/4)return{};
    try{
        result.lines.reserve(std::size_t(count));
        for(std::int32_t i=0;i<count;++i){
            const auto line=std::size_t(text_word(bytes,offset+std::size_t(i)*4));
            if(line>=bytes.size())return{};
            const auto text=bytes.subspan(line);
            const auto end=std::find(text.begin(),text.end(),std::byte{});
            if(end==text.end())return{};
            result.lines.push_back(text.first(std::size_t(end-text.begin())+1));
        }
        return result;
    }catch(...){return{};}
}
std::optional<std::array<std::uint16_t,8>> SceneTextBank::message_cues(std::int16_t id,std::uint32_t kind)const noexcept{
    //6BA1A0 returns before reading an id, bank or timer for system messages.
    if(kind==2){std::array<std::uint16_t,8> result;result.fill(0xffffu);return result;}
    if(kind!=0)return{};
    const auto bytes=messages_known();if(id<0||bytes.size()<2)return{};
    const auto offset=std::size_t(text_half(bytes,0))+std::size_t(id)*16;
    if(offset>bytes.size()||bytes.size()-offset<16)return{};
    std::array<std::uint16_t,8> result;
    for(unsigned i=0;i<result.size();++i)result[i]=text_half(bytes,offset+i*2);
    return result;
}
SceneTextBankStatus SceneTextBank::initialize_choices()noexcept{
    if(running_)return SceneTextBankStatus::busy;
    // Actual709880 contains exactly IDs3..12.5A4F90 copies at most62 bytes,
    // then appends NUL; no scene-message allocation/load is consulted here.
    for(unsigned i=0;i<choices_.size();++i){
        const auto [offset,size]=system_text_rows[i+3];
        const auto count=std::min(size-1,std::size_t(62));
        for(std::size_t byte=0;byte<count;++byte)choices_[i][byte]=std::byte(system_text_bytes[offset+byte]);
        choices_[i][count]=std::byte{};
    }
    choices_known_=true;return SceneTextBankStatus::completed;
}
std::optional<std::span<const std::byte>> SceneTextBank::choice_text(std::uint32_t index)const noexcept{
    if(!choices_known_||index>=choices_.size())return{};
    const auto bytes=std::span<const std::byte>(choices_[index]);
    const auto end=std::find(bytes.begin(),bytes.end(),std::byte{});
    return bytes.first(std::size_t(end-bytes.begin())+1);
}
std::optional<SceneChoiceQuestion> SceneTextBank::choice_question(std::uint32_t id)const noexcept{
    const auto bytes=messages_known();if(bytes.size()<8)return{};
    SceneChoiceQuestion result;
    if(!text_word(bytes,4))return result; //5A50C0's empty-bank early return
    result.enabled=true;
    if(bytes.size()<12||std::size_t(id)>(bytes.size()-12)/8)return{};
    const auto row=4+std::size_t(id)*8;
    const auto offset=std::size_t(text_word(bytes,row));const auto count=text_word(bytes,row+4);
    if(!count)return result;
    // The original tests only zero/one; every other count draws two rows,
    // including a malformed signed-negative count. Never decode an unused tail.
    const auto rows=count==1?1u:2u;
    if(offset>bytes.size()||rows>(bytes.size()-offset)/4)return{};
    for(unsigned i=0;i<rows;++i){
        const auto line=std::size_t(text_word(bytes,offset+i*4));if(line>=bytes.size())return{};
        const auto text=bytes.subspan(line);const auto end=std::find(text.begin(),text.end(),std::byte{});
        if(end==text.end())return{};
        result.lines[i]=text.first(std::size_t(end-text.begin())+1);
    }
    return result;
}
} // namespace reo::native::gameplay_scenario
