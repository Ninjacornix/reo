#include "model_mesh.hpp"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <stdexcept>

namespace reo::native::gameplay_presentation {
namespace {
using Bytes=std::span<const std::byte>;
struct Chunk {std::uint32_t type{},count{};std::size_t at{},size{};};
template<class T>T read(Bytes bytes,std::size_t at){
    if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Truncated model mesh");
    T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;
}
float scalar(Bytes bytes,std::size_t at){const float value=read<float>(bytes,at);if(!std::isfinite(value))throw std::invalid_argument("Nonfinite model mesh");return value;}
Chunk chunk(Bytes bytes,std::size_t at,std::size_t end){
    if(end>bytes.size()||at>end||end-at<12)throw std::invalid_argument("Truncated model chunk");
    const Chunk c{read<std::uint32_t>(bytes,at),read<std::uint32_t>(bytes,at+4),at,read<std::uint32_t>(bytes,at+8)};
    if(c.size<12||c.size>end-at||c.count>100000)throw std::invalid_argument("Invalid model chunk extent");return c;
}
std::vector<Chunk> children(Bytes bytes,Chunk parent){
    std::vector<Chunk> result;const auto end=parent.at+parent.size;auto at=parent.at+12;
    while(at<end){auto c=chunk(bytes,at,end);result.push_back(c);at+=c.size;}
    return result;
}
const Chunk* find(const std::vector<Chunk>& list,std::uint32_t type){
    const Chunk* found=nullptr;for(const auto& item:list)if(item.type==type){if(found)throw std::invalid_argument("Duplicate model chunk");found=&item;}return found;
}
const Chunk& required(const std::vector<Chunk>& list,std::uint32_t type){const auto* value=find(list,type);if(!value)throw std::invalid_argument("Missing model chunk");return *value;}
void exact(const Chunk& c,std::size_t stride){if(c.count>(c.size-12)/stride||c.size!=12+c.count*stride)throw std::invalid_argument("Model array extent mismatch");}
std::uint32_t color_word(float value)noexcept{
    // 1A3F70 converts each finite float toward zero using the EE's
    // saturating signed conversion and its unsigned-high-bit adjustment.
    constexpr float high_bit=2147483648.f;
    const bool high=value>=high_bit;const float adjusted=high?value-high_bit:value;
    std::int32_t converted;
    if(adjusted>=high_bit)converted=std::numeric_limits<std::int32_t>::max();
    else if(adjusted<=-high_bit)converted=std::numeric_limits<std::int32_t>::min();
    else converted=static_cast<std::int32_t>(adjusted);
    return std::uint32_t(converted)|(high?0x80000000u:0u);
}
std::array<float,4> converted_color(Bytes bytes,std::size_t at){
    const auto red=color_word(scalar(bytes,at)),green=color_word(scalar(bytes,at+4));
    const auto blue=color_word(scalar(bytes,at+8)),alpha=color_word(scalar(bytes,at+12));
    // The shifts and ORs intentionally precede byte extraction: source does
    // not independently clamp or mask the four incoming float values.
    const auto packed=(alpha<<24)|(red<<16)|(green<<8)|blue;
    const auto a=(packed>>24)&255u;
    const auto gs_alpha=a==255?128u:a?std::max(1u,a>>1):0u;
    return {float((packed>>16)&255u)/255.f,float((packed>>8)&255u)/255.f,
            float(packed&255u)/255.f,float(gs_alpha)/128.f};
}
}
ModelMesh ModelMesh::import(Bytes bytes){
    const auto offset=read<std::uint32_t>(bytes,20),size=read<std::uint32_t>(bytes,24);
    if(!offset||!size||offset>bytes.size()||size>bytes.size()-offset)throw std::invalid_argument("Missing model AMO");
    const auto root=chunk(bytes,offset,offset+size);if(root.size!=size)throw std::invalid_argument("Model AMO trailing data");
    const auto top=children(bytes,root);const auto objects=children(bytes,required(top,2));
    if(objects.size()>128)throw std::invalid_argument("Model part capacity exceeded");
    ModelMesh output;output.parts.reserve(objects.size());
    const auto materials=children(bytes,required(top,9));const auto textures=children(bytes,required(top,10));
    output.material_textures.reserve(materials.size());
    for(const auto& material:materials){
        if(material.size<16)throw std::invalid_argument("Invalid model material");
        const auto index=read<std::uint32_t>(bytes,material.at+material.size-4);
        if(index>=textures.size()||textures[index].size<16)throw std::invalid_argument("Invalid model material texture");
        output.material_textures.push_back(read<std::uint32_t>(bytes,textures[index].at+12));
    }
    for(const auto& object:objects){
        if(object.type!=4)throw std::invalid_argument("Unsupported model part");
        const auto entries=children(bytes,object);const auto& pos=required(entries,0x70000);const auto& norm=required(entries,0x80000);const auto& uv=required(entries,0xa0000);const auto& color=required(entries,0xb0000);
        exact(pos,12);exact(norm,12);exact(uv,8);exact(color,16);
        if(!pos.count||norm.count!=pos.count||uv.count!=pos.count||color.count!=pos.count||pos.count>20000)throw std::invalid_argument("Model vertex profile unavailable");
        MeshPart part;part.vertices.resize(pos.count);
        // 1A3090 admits version-one F0000 records, then 1D29F0 uses the
        // indexed File1 tables to publish selectors 15, 12 and 01. A missing
        // or non-version-one record leaves the prior source state unchanged.
        if(const auto* properties=find(entries,0xf0000)){
            if(properties->size<16)throw std::invalid_argument("Truncated model render properties");
            if((read<std::uint32_t>(bytes,properties->at+12)>>16)==1){
                if(properties->size<84)throw std::invalid_argument("Truncated model render properties");
                const auto format=read<std::uint32_t>(bytes,properties->at+16);
                const auto color=read<std::uint32_t>(bytes,properties->at+32);
                const auto option=read<std::uint32_t>(bytes,properties->at+44);
                if(format>=2||color>=9||option>=4)throw std::invalid_argument("Unsupported model render properties");
                part.render_profile=MeshRenderProfile{format?2u:0u,color*0x100u,option==0};
            }
        }
        for(std::size_t i=0;i<part.vertices.size();++i){auto& v=part.vertices[i];const auto p=pos.at+12+12*i,n=norm.at+12+12*i,t=uv.at+12+8*i;
            v.position={scalar(bytes,p),scalar(bytes,p+4),scalar(bytes,p+8)};v.normal={scalar(bytes,n),scalar(bytes,n+4),scalar(bytes,n+8)};v.uv={scalar(bytes,t),scalar(bytes,t+4)};
            v.color=converted_color(bytes,color.at+12+16*i);}
        const auto* weights=find(entries,0xc0000);const auto* palette=find(entries,0x100000);
        if(bool(weights)!=bool(palette))throw std::invalid_argument("Incomplete skin profile");
        if(weights){
            exact(*palette,4);auto at=weights->at+12;const auto end=weights->at+weights->size;
            for(auto& vertex:part.vertices){const auto count=read<std::uint32_t>(bytes,at);at+=4;if(!count||count>4||at>end||count>(end-at)/8)throw std::invalid_argument("Invalid skin influence");
                std::array<std::uint32_t,4> indices{},quantized{};float sum=0;unsigned last_positive=0,total=0;
                for(unsigned j=0;j<count;++j){const auto index=read<std::uint32_t>(bytes,at)&255u;const auto percent=scalar(bytes,at+4);at+=8;
                    if(index>=palette->count||percent<0||percent>100)throw std::invalid_argument("Invalid skin palette");
                    indices[j]=index;sum+=percent/100.f;
                    // 1A45A0 multiplies first, then divides and truncates.
                    quantized[j]=std::uint32_t((255.f*percent)/100.f)&255u;
                    total+=quantized[j];if(quantized[j])last_positive=j;}
                if(std::fabs(sum-1.f)>0.0001f)throw std::invalid_argument("Invalid skin weight sum");
                if(total>255||quantized[last_positive]+255-total>255)throw std::invalid_argument("Unsupported skin correction");
                quantized[last_positive]+=255-total;
                // The source makes one adjacent compaction pass, preserving
                // the physical count and its final zero entries.
                for(unsigned j=0;j+1<count;++j)if(!quantized[j]){
                    quantized[j]=quantized[j+1];indices[j]=indices[j+1];quantized[j+1]=0;
                }
                for(unsigned j=0;j<count;++j){
                    if(indices[j]>=palette->count)throw std::invalid_argument("Invalid compacted skin palette");
                    vertex.influences.push_back({read<std::uint32_t>(bytes,palette->at+12+4*indices[j]),float(quantized[j])/255.f});
                }
            }if(at!=end)throw std::invalid_argument("Trailing skin data");
        }
        const auto& refs=required(entries,0x50000);const auto& groups=required(entries,0x60000);exact(refs,4);exact(groups,4);
        std::size_t ordinal=0;for(const auto& list:children(bytes,required(entries,5))){
            if(list.type!=0x30000&&list.type!=0x40000)throw std::invalid_argument("Unsupported model primitive");
            auto at=list.at+12;const auto end=list.at+list.size;
            for(unsigned i=0;i<list.count;++i,++ordinal){
                if(at>end||end-at<4||ordinal>=groups.count)throw std::invalid_argument("Missing model strip");
                const auto header=read<std::uint32_t>(bytes,at);at+=4;const auto count=header&0x7fffffffu;
                if(count<3||count>20000||count>(end-at)/4)throw std::invalid_argument("Invalid model strip");
                const auto ref=read<std::uint32_t>(bytes,groups.at+12+4*ordinal);if(ref>=refs.count)throw std::invalid_argument("Invalid material reference");
                const auto material=read<std::uint32_t>(bytes,refs.at+12+4*ref);
                if(material>=output.material_textures.size())throw std::invalid_argument("Invalid model material ordinal");
                for(std::size_t j=2;j<count;++j){auto a=read<std::uint32_t>(bytes,at+4*(j-2)),b=read<std::uint32_t>(bytes,at+4*(j-1));const auto c=read<std::uint32_t>(bytes,at+4*j);
                    if(a>=pos.count||b>=pos.count||c>=pos.count)throw std::invalid_argument("Invalid model vertex index");
                    if(a==b||b==c||a==c)continue;if(bool(j&1)!=bool(header&0x80000000u))std::swap(a,b);part.triangles.push_back({a,b,c,material});}
                at+=4*count;
            }if(at!=end)throw std::invalid_argument("Trailing model strip data");
        }if(ordinal!=groups.count)throw std::invalid_argument("Incomplete model material groups");
        output.parts.push_back(std::move(part));
    }
    return output;
}
}
