#include "resource_static_assets.hpp"
#include <bit>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
template<class T>T read(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Truncated native resource static asset");
    T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;
}
}
std::shared_ptr<const ResourceStaticAssets> ResourceStaticAssets::import_nbd(std::span<const std::byte> bytes){
    const auto offset=read<std::uint32_t>(bytes,0x24),length=read<std::uint32_t>(bytes,0x28);
    if(!offset||!length||offset>bytes.size()||length>bytes.size()-offset)throw std::invalid_argument("Native resource NBD forest extent unavailable");
    return import_forest(bytes.subspan(offset,length));
}
std::shared_ptr<const ResourceStaticAssets> ResourceStaticAssets::import_forest(std::span<const std::byte> bytes){
    const auto count=read<std::uint32_t>(bytes,4),length=read<std::uint32_t>(bytes,8);
    if(count>1153||length<12||length>bytes.size())throw std::invalid_argument("Native resource forest count/extent unavailable");
    bytes=bytes.first(length);std::optional<std::uint32_t> roots;std::size_t at=12;
    for(unsigned i=0;i<count;++i){
        const auto type=read<std::uint32_t>(bytes,at)&255,n=read<std::uint32_t>(bytes,at+4),size=read<std::uint32_t>(bytes,at+8);
        if(size<12||size>bytes.size()-at)throw std::invalid_argument("Native resource forest record extent unavailable");
        if(!type){if(roots||n>(size-12)/4||n>96)throw std::invalid_argument("Native resource root table exceeds admitted source profile");roots=n;}
        else if(size<84)throw std::invalid_argument("Native resource forest node extent unavailable");
        at+=size;
    }
    if(at!=length)throw std::invalid_argument("Native resource forest record count/extent mismatch");
    auto result=std::make_shared<ResourceStaticAssets>();
    for(unsigned ordinal=0;ordinal<roots.value_or(0);++ordinal){
        const auto skeleton=animation::Skeleton::import_raw(bytes,ordinal);animation::Instance model(skeleton);model.rebuild(transform_math::identity());
        const auto definitions=skeleton->nodes();const auto poses=model.nodes();
        ResourceStaticRoot root;root.content=std::bit_cast<std::int16_t>(definitions[0].track);root.part_count=poses.size()-1;
        if(root.part_count<=6){auto parts=std::make_shared<ResourcePartPoses>();parts->asset_index=std::int16_t(ordinal);parts->count=std::uint16_t(root.part_count);
            for(unsigned part=0;part<root.part_count;++part)parts->poses[part]=poses[part+1].world;
            root.admitted_parts=std::move(parts);
        }
        result->roots_.push_back(std::move(root));
    }
    return result;
}
std::int16_t ResourceStaticAssets::find(std::int16_t content)const noexcept{
    for(std::size_t i=0;i<roots_.size();++i)if(roots_[i].content==content)return std::int16_t(i);
    return -1;
}
std::shared_ptr<const ResourcePartPoses> ResourceStaticAssets::parts(std::int16_t index)const{
    if(index<0||std::size_t(index)>=roots_.size())throw std::out_of_range("Native resource static asset index unavailable");
    const auto& parts=roots_[unsigned(index)].admitted_parts;
    if(!parts)throw std::runtime_error("Native primary resource root exceeds six-part consumer profile");
    return parts;
}
}
