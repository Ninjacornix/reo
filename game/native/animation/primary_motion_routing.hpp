#pragma once
#include "model.hpp"
#include <stdexcept>
namespace reo::native::animation {
namespace detail {
#include "primary_track_layouts.inc"
}
// Complete5D1C70's count/category decision after a bounded token lookup. An
// absent token returns true in that query; it grants no clear/configure input.
inline bool primary_motion_compatible(std::uint8_t category,std::uint8_t kind,
                                      std::optional<std::size_t> count)noexcept{
    if(!count)return true;
    return category<=1&&(*count==22||*count==(kind==1?73u:36u));
}
inline std::span<const std::uint16_t> primary_restore_tracks(std::uint8_t kind){
    if(kind==0)return detail::ordinary_primary_tracks;
    if(kind==1)return detail::high_primary_tracks;
    throw std::out_of_range("Native primary restore layout unavailable");
}
inline void clear_primary_motion_tracks(Instance& model,std::uint8_t kind,std::size_t count){
    const auto layout=primary_restore_tracks(kind);
    if(count>layout.size()||model.nodes().size()<layout.size())
        throw std::out_of_range("Native primary motion node prefix unavailable");
    model.relabel_prefix(count,0);
}
inline void restore_primary_motion_tracks(Instance& model,std::uint8_t kind){
    model.relabel_prefix(primary_restore_tracks(kind));
}
}
