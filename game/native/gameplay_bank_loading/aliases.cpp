#include "aliases.hpp"
#include <span>
namespace reo::native::gameplay_bank_loading {
namespace {
#include "aliases_profile.inc"
}
std::span<const std::string_view,422> sound_aliases()noexcept{return aliases;}
std::optional<std::string> normalize_sound_name(std::string_view input){
    input=input.substr(0,input.find('\0'));
    if(input.size()>255)return{};
    std::string value(input);
    for(auto& c:value){const auto byte=static_cast<unsigned char>(c);if(byte>=128)return{};if(c>='a'&&c<='z')c=char(c-'a'+'A');}
    for(std::size_t i=0;i+3<value.size();++i){
        const auto tail=std::string_view(value).substr(i);
        const auto separator=[](char c){return c=='\\'||c=='/';};
        if(((tail.substr(0,3)=="ROM"||tail.substr(0,3)=="RDT")&&separator(tail[3]))){value.erase(0,i+4);break;}
        if(tail.size()>=5&&tail.substr(0,4)=="EDIT"&&separator(tail[4])){value.erase(0,i+5);break;}
    }
    for(auto& c:value)if(c=='\\'||c=='/'||c=='.'||c=='-')c='_';
    return value;
}
std::optional<unsigned> sound_member(std::string_view input){
    const auto value=normalize_sound_name(input);if(!value)return{};
    for(unsigned i=0;i<aliases.size();++i)if(aliases[i]==*value)return i;
    return{};
}
}
