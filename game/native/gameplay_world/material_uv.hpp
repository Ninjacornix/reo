#pragma once
#include <bit>
#include <cstdint>

namespace reo::native::gameplay_world {
// Linked visual actors' D24/D28. D28 in primary actors instead belongs to
// control_elapsed; these family-specific fields must never alias that state.
struct MaterialUv { float u{},v{}; };
struct MaterialAnimationState {
    std::uint8_t phase{},subphase{},presentation_mask{};
    std::int16_t first{},second{};
};
// Complete 5D0C90 callback. Initialization deliberately leaves the UVs alone.
inline void advance_material_uv(MaterialAnimationState& state,MaterialUv& uv)noexcept {
    if(state.phase==0){
        state.phase=1;state.subphase=0;state.first=450;state.second=90;
        state.presentation_mask=1;
    }else if(state.phase==1){
        const auto decrement=[](std::int16_t value,std::int16_t reset){
            const auto next=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(value)-1u));
            return next<0?reset:next;
        };
        state.first=decrement(state.first,449);state.second=decrement(state.second,89);
        uv.u=float(state.first)/450.f;uv.v=float(state.second)/90.f;
    }
}
}
