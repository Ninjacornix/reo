#include "room_model_assets.hpp"
#include "../gameplay_world/model_parts.hpp"
#include <cmath>
#include <cstring>
#include <stdexcept>

namespace reo::native::gameplay_scenario {
namespace {
template<class T>T read(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Room model extent unavailable");
    T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;
}
std::uint8_t control(float value){
    if(!std::isfinite(value)||value<-2147483648.0f||double(value)>=4294967296.0)
        throw std::domain_error("Room model control conversion unavailable");
    return std::uint8_t(std::uint32_t(std::int64_t(value)));
}
}
std::shared_ptr<const RoomModelAsset> RoomModelAsset::import(std::string name,content::Bytes bytes){
    if(!bytes)throw std::invalid_argument("Room model bundle unavailable");
    const auto offset=read<std::uint32_t>(*bytes,0x24),size=read<std::uint32_t>(*bytes,0x28);
    if(!offset||!size||offset>bytes->size()||size>bytes->size()-offset)
        throw std::invalid_argument("Room model skeleton unavailable");
    const auto raw=std::span<const std::byte>(*bytes).subspan(offset,size);
    const auto records=read<std::uint32_t>(raw,4),length=read<std::uint32_t>(raw,8);
    if(!(read<std::uint32_t>(raw,0)&0x80000000u)||!records||records>1153||length!=raw.size())
        throw std::invalid_argument("Room model raw record profile unavailable");
    std::vector<std::uint32_t> roots;
    std::size_t at=12;unsigned nodes{};
    for(unsigned i=0;i<records;++i){
        const auto type=read<std::uint32_t>(raw,at)&255,count=read<std::uint32_t>(raw,at+4),extent=read<std::uint32_t>(raw,at+8);
        if(extent<12||at>raw.size()||extent>raw.size()-at)throw std::invalid_argument("Room model record unavailable");
        if(!type){
            if(!roots.empty()||!count||count>24||count>(extent-12)/4)throw std::invalid_argument("Room model root table unavailable");
            for(unsigned j=0;j<count;++j)roots.push_back(read<std::uint32_t>(raw,at+12+4*j));
        }else {if(count!=1)throw std::invalid_argument("Room model node record profile unavailable");++nodes;}
        at+=extent;
    }
    if(at!=raw.size()||roots.empty()||nodes!=records-1)throw std::invalid_argument("Room model node layout unavailable");
    auto result=std::shared_ptr<RoomModelAsset>(new RoomModelAsset);
    result->name_=std::move(name);result->bytes_=std::move(bytes);result->nodes_=std::uint16_t(nodes);
    const auto model_offset=read<std::uint32_t>(*result->bytes_,0x14),model_size=read<std::uint32_t>(*result->bytes_,0x18);
    if(model_offset){
        if(!model_size||model_offset>result->bytes_->size()||model_size>result->bytes_->size()-model_offset)
            throw std::invalid_argument("Room model part directory unavailable");
        const auto parts=gameplay_world::model_part_count(std::span<const std::byte>(*result->bytes_).subspan(model_offset,model_size));
        if(parts>128)throw std::out_of_range("Room model physical part capacity unavailable");
        result->parts_=std::uint16_t(parts);
    }
    for(std::size_t group=0;group<roots.size();++group){
        const auto first=roots[group],end=group+1<roots.size()?roots[group+1]:nodes;
        if(end<=first||end>nodes||first<2*group||first-2*group>255)
            throw std::invalid_argument("Room model contiguous root interval unavailable");
        const auto skeleton=animation::Skeleton::import_raw(raw,group);
        if(skeleton->nodes().size()!=end-first)throw std::invalid_argument("Room model root interval differs from packed forest");
        animation::Instance instance(skeleton);instance.rebuild(transform_math::identity());
        RoomModelGroup row{std::uint8_t(first-2*group),0,{},
            {instance.nodes()[0].world[3][0],instance.nodes()[0].world[3][1],instance.nodes()[0].world[3][2]}};
        for(std::size_t i=0;i<skeleton->nodes().size();++i){
            const auto& node=skeleton->nodes()[i];
            //1D2DDC begins this separate control search at local node1;
            // local root0 still participates in matrix publication below.
            if(node.static_index<0){if(i&&!row.control)row.control=control(node.defaults[0]);continue;}
            if(node.static_index>=128||row.models==255)throw std::out_of_range("Room model physical slot unavailable");
            result->poses_.push_back({std::uint8_t(node.static_index),instance.nodes()[i].world});++row.models;
        }
        result->groups_.push_back(row);
    }
    return result;
}
}
