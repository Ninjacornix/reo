#include "primary_start.hpp"
#include <bit>
namespace reo::native::gameplay_save {
std::optional<gameplay_world::PrimarySavedActors> decode_primary_start_snapshot(std::span<const std::byte> second)noexcept{
    if(second.size()!=0x7000)return{};
    gameplay_world::PrimarySavedActors result;
    const auto byte=[&](std::size_t at){return std::to_integer<std::uint8_t>(second[at]);};
    // Legacy section2 begins at original318B60. The first primary record is
    // section-relative1778, followed by the source10C-byte record stride.
    for(unsigned slot=0;slot<result.size();++slot){
        const auto at=0x1778+0x10cu*slot;auto& row=result[slot];
        row.health=std::bit_cast<std::int16_t>(std::uint16_t(byte(at+2)|(std::uint16_t(byte(at+3))<<8)));
        row.class_marker=byte(at+5);row.selected_resource=byte(at+0x26);
    }
    return result;
}
}
