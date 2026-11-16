#include "texture.hpp"
#include <algorithm>
#include <cstring>
#include <stdexcept>

namespace reo::native::gameplay_presentation {
namespace {
using Bytes=std::span<const std::byte>;
template<class T>T read(Bytes bytes,std::size_t at){
    if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Truncated texture data");
    T result;std::memcpy(&result,bytes.data()+at,sizeof result);return result;
}
constexpr std::size_t limit=16*1024*1024;
}
std::vector<std::byte> decompress_texture(Bytes source){
    if(source.size()<4||source.size()>limit||(source.size()&1))throw std::invalid_argument("Invalid compressed texture extent");
    std::vector<std::byte> output;output.reserve(std::min(source.size()*2,limit));std::size_t pos=0;
    while(pos<source.size()){
        const auto control=read<std::uint16_t>(source,pos);pos+=2;
        if(pos==source.size())throw std::invalid_argument("Missing compressed texture token");
        for(int bit=15;bit>=0&&pos<source.size();--bit){
            const auto word=read<std::uint16_t>(source,pos);pos+=2;
            if(!(control&(1u<<bit))){if(output.size()>limit-2)throw std::invalid_argument("Texture output too large");output.push_back(std::byte(word&255));output.push_back(std::byte(word>>8));continue;}
            std::size_t count=word>>11,offset=std::size_t(word&0x7ff)*2;
            if(!count&&!offset)return output;
            if(!count){count=read<std::uint16_t>(source,pos);pos+=2;}
            const auto length=count*2;
            if(offset>output.size()||length>limit-output.size())throw std::invalid_argument("Invalid texture back reference");
            if(!offset)output.insert(output.end(),length,std::byte{});
            else for(std::size_t i=0;i<length;++i)output.push_back(output[output.size()-offset]);
        }
    }
    return output;
}
Texture decode_texture(Bytes bytes){
    if(bytes.size()<64||std::memcmp(bytes.data(),"TIM2",4))throw std::invalid_argument("Invalid TIM2 texture");
    const std::size_t at=read<std::uint8_t>(bytes,5)?128:16;
    const auto total=read<std::uint32_t>(bytes,at),clut_bytes=read<std::uint32_t>(bytes,at+4),image_bytes=read<std::uint32_t>(bytes,at+8);
    const auto header=read<std::uint16_t>(bytes,at+12),colors=read<std::uint16_t>(bytes,at+14);
    const auto clut=read<std::uint8_t>(bytes,at+18),type=read<std::uint8_t>(bytes,at+19);
    const auto width=read<std::uint16_t>(bytes,at+20),height=read<std::uint16_t>(bytes,at+22);
    if(!width||!height||width>1024||height>1024||header<48||total<header||at>bytes.size()||total>bytes.size()-at||
       std::uint64_t(header)+image_bytes+clut_bytes>total||(type!=4&&type!=5)||(clut&63)!=3||colors!=(type==4?16:256))
        throw std::invalid_argument("Unsupported TIM2 texture profile");
    const std::size_t pixels=std::size_t(width)*height;
    if(clut_bytes<std::size_t(colors)*4||image_bytes<(pixels+(type==4?1:0))/(type==4?2:1))throw std::invalid_argument("Incomplete TIM2 texture");
    const auto image=at+header,palette=image+image_bytes;
    Texture texture{width,height,std::vector<std::uint8_t>(pixels*4)};
    for(std::size_t i=0;i<pixels;++i){
        unsigned index=read<std::uint8_t>(bytes,image+(type==4?i/2:i));
        if(type==4)index=(index>>((i&1)*4))&15;
        else if(!(clut&128))index=(index&~24u)|((index&8u)<<1)|((index&16u)>>1);
        const auto source=palette+4*index,dest=4*i;
        for(unsigned channel=0;channel<3;++channel)texture.rgba[dest+channel]=read<std::uint8_t>(bytes,source+channel);
        texture.rgba[dest+3]=std::uint8_t(std::min(255u,unsigned(read<std::uint8_t>(bytes,source+3))*2));
    }
    return texture;
}
}
