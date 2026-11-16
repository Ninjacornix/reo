#include "font_face.hpp"
#include <array>
#include <stdexcept>

namespace reo::native::gameplay_presentation {
namespace {
constexpr std::uint32_t glyph_count=7808,glyph_bytes=100;
constexpr std::array<std::uint32_t,8> palette{0,0x80,0x8000,0x800000,0x8080,0x808000,0x8080,0x808080};
bool wide(std::uint8_t value)noexcept{return (value>=0x80&&value<0xa0)||value>=0xe0;}
struct Tag {char kind{},value{};};
std::optional<Tag> tag(std::span<const std::byte> bytes,std::size_t at)noexcept{
    if(bytes.size()-at<4||bytes[at]!=std::byte{'<'}||bytes[at+3]!=std::byte{'>'})return{};
    const auto kind=char(bytes[at+1]);if(kind!='c'&&kind!='p')return{};
    return Tag{kind,char(bytes[at+2])};
}
std::size_t first_line_units(std::span<const std::byte> bytes,std::size_t at)noexcept{
    std::size_t units=0;
    while(at<bytes.size()){
        const auto c=std::to_integer<std::uint8_t>(bytes[at]);if(!c||c=='\n')break;
        if(wide(c)){++units;++at;if(at==bytes.size()||bytes[at]==std::byte{})break;++units;++at;continue;}
        if(tag(bytes,at)){at+=4;continue;}
        ++units;++at;
    }return units;
}
}
FontFace::FontFace(std::vector<std::byte> bytes):bytes_(std::move(bytes)){
    if(bytes_.size()!=glyph_count*glyph_bytes)throw std::invalid_argument("File1 font extent unavailable");
}
std::uint32_t FontFace::single_code(std::uint8_t c)noexcept{
    if(c<0x60)return 0x851fu+c;
    if(c<0x80)return 0x8520u+c;
    if(c==0xa5)return 0x85a3u;
    return 0x84feu+c;
}
std::uint32_t FontFace::index(std::uint16_t pair)noexcept{
    const auto hi=std::uint32_t(pair>>8);auto lo=std::uint32_t(pair&255);
    auto row=(std::uint32_t(std::uint16_t(hi-(hi<0xa0?0x71:0xb1)))*2u+1u)&65535u;
    if(lo>=0x80)--lo;
    if(lo>=0x9e){lo=(lo-0x7d)&65535u;row=(row+1u)&65535u;}else lo=(lo-0x1f)&65535u;
    const auto translated=(row<<8)|lo;
    return (((translated>>8)&255u)-0x21u)*94u+((translated&255u)-0x21u);
}
std::span<const std::byte> FontFace::bitmap(std::uint32_t value)const noexcept{
    return value<glyph_count?std::span(bytes_).subspan(std::size_t(value)*glyph_bytes,glyph_bytes):std::span<const std::byte>{};
}
std::optional<std::vector<FontGlyph>> FontFace::layout(const gameplay_scenario::CachedText& record)const{
    std::vector<FontGlyph> result;if(!record.active)return result;
    const auto bytes=std::span(record.text);std::size_t at=0;std::int32_t x=record.x,y=record.y;bool positioned=false;
    std::uint32_t color_index=7;int centering=0;const auto size=std::int32_t(record.height);
    while(at<bytes.size()){
        auto c=std::to_integer<std::uint8_t>(bytes[at]);if(!c||c=='\r')break;
        if(!positioned&&centering){const auto units=first_line_units(bytes,at);if(!units)break;
            x=(640-std::int32_t(units)*(size/2))/2;positioned=true;}
        if(c=='\n'){++at;x=record.x;y+=size;positioned=false;continue;}
        if(const auto parsed=tag(bytes,at)){
            if(parsed->kind=='c'){if(parsed->value<'0'||parsed->value>'7')return{};color_index=unsigned(parsed->value-'0');}
            else centering=int(parsed->value)-'0';at+=4;continue;
        }
        ++at;const bool full=wide(c);std::uint32_t pair;
        if(full){if(at==bytes.size()||bytes[at]==std::byte{})break;pair=(std::uint32_t(c)<<8)|std::to_integer<std::uint8_t>(bytes[at++]);}
        else pair=single_code(c);
        const auto glyph=index(std::uint16_t(pair));
        if(c!=' '&&glyph<glyph_count)result.push_back({x,y,std::uint32_t(size),palette[color_index],glyph,record.alpha,!full});
        x+=full?size:size/2;
    }
    return result;
}
}
