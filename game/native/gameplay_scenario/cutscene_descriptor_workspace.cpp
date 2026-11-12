#include "cutscene_descriptor_workspace.hpp"
#include <algorithm>
#include <cstring>
#include <limits>
namespace reo::native::gameplay_scenario {
DescriptorWorkspaceStatus CutsceneDescriptorWorkspace::load(std::span<const std::byte> asset)noexcept{
    if(asset.size()<40||asset.size()>capacity-4)return DescriptorWorkspaceStatus::invalid_asset;
    if(generation_==std::numeric_limits<std::uint64_t>::max())return DescriptorWorkspaceStatus::exhausted;
    if(!asset.empty())std::memmove(bytes_.data(),asset.data(),asset.size());
    std::fill_n(bytes_.data()+asset.size(),4,std::byte{255});loaded_bytes_=asset.size();++generation_;
    return DescriptorWorkspaceStatus::completed;
}
DescriptorWorkspaceStatus CutsceneDescriptorWorkspace::clear_movie_prefix()noexcept{
    if(generation_==std::numeric_limits<std::uint64_t>::max())return DescriptorWorkspaceStatus::exhausted;
    std::fill_n(bytes_.data(),movie_clear_bytes,std::byte{});loaded_bytes_=0;++generation_;
    return DescriptorWorkspaceStatus::completed;
}
bool CutsceneDescriptorWorkspace::consume_frame(std::size_t offset,std::uint16_t stride)noexcept{
    if((stride!=24&&stride!=36&&stride!=40&&stride!=48)||offset%4||offset>loaded_bytes_||stride>loaded_bytes_-offset)return false;
    bytes_[offset+2]=bytes_[offset+3]=std::byte{255};return true;
}
std::optional<std::span<const std::byte,40>> CutsceneDescriptorWorkspace::record40(std::size_t offset)const noexcept{
    if(offset>capacity||40>capacity-offset)return{};
    return std::span<const std::byte,40>(bytes_.data()+offset,40);
}
} // namespace reo::native::gameplay_scenario
