#include "model_textures.hpp"
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_presentation {
namespace {
using Bytes=std::span<const std::byte>;
template<class T>T read(Bytes bytes,std::size_t at){if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Truncated model texture directory");T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;}
struct Section {std::size_t at{},size{};std::uint32_t count{};};
Section section(Bytes nbd,std::uint32_t expected){
    if(read<std::uint32_t>(nbd,0)!=expected)throw std::invalid_argument("Model texture bank type unavailable");
    const Section value{read<std::uint32_t>(nbd,4),read<std::uint32_t>(nbd,8),read<std::uint32_t>(nbd,12)};
    if(!value.at||value.at>nbd.size()||value.size>nbd.size()-value.at)throw std::invalid_argument("Model texture bank extent unavailable");
    return value;
}
Texture import(Bytes compressed){const auto expanded=decompress_texture(compressed);return decode_texture(expanded);}
}
std::vector<Texture> room_textures(const gameplay_scenario::content::ScenarioArchive& archive,std::uint16_t scenario,Bytes nbd){
    const auto tid=section(nbd,0x00444954u);if(tid.size<4)throw std::invalid_argument("Missing room texture list");
    const auto count=read<std::uint32_t>(nbd,tid.at);if(count>128||tid.size!=4ull+4ull*count)throw std::invalid_argument("Room texture list extent unavailable");
    std::vector<Texture> result;result.reserve(count);
    for(unsigned i=0;i<count;++i){const auto ordinal=read<std::uint32_t>(nbd,tid.at+4+4*i);const auto bytes=archive.read_member_ordinal(scenario,ordinal);
        if(!bytes)throw std::invalid_argument("Room texture archive member unavailable");result.push_back(import(*bytes));}
    return result;
}
std::vector<Texture> character_textures(Bytes nbd){
    const auto tex=section(nbd,0x00584554u);if(!tex.count||tex.count>128)throw std::invalid_argument("Character texture count unavailable");
    std::vector<Texture> result;result.reserve(tex.count);auto at=tex.at;const auto end=tex.at+tex.size;
    for(unsigned i=0;i<tex.count;++i){const auto size=read<std::uint32_t>(nbd,at);at+=4;if(!size||at>end||size>end-at)throw std::invalid_argument("Character texture extent unavailable");
        result.push_back(import(nbd.subspan(at,size)));at+=size;}
    if(at!=end)throw std::invalid_argument("Trailing character texture data");return result;
}
}
