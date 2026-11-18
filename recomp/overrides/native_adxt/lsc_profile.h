#pragma once
#include "handle_profile.h"
#include "game/native/adxt_shared_source/shared_source.hpp"
#include <utility>

namespace reo::native::adxt_binding {
// Owned File1 words:13CB50,13CBB0,13CD08,13CCB8 and SJRB13F8A8.
// Pure bounds/type/link observations only. The caller must separately establish
// the actual runtime/image, current canonical parent key, serialized guest
// control, child lifetime and real retirement before reuse. No provider access
// or source capability is minted from these bytes.
inline constexpr Pool lsc_children{0x21e110,0x238,16},source_rings{0x224c60,0x40,256};
enum class LscStatus {ready,parent,child,inactive,links,ring,geometry,queue,callback};
struct LscProfile {
    Handle parent;
    std::uint32_t address{},slot{},capacity{},minimum{},tail{},head{},count{};
    std::uint8_t state{},transferring{},repeat{},paused{};
    bool empty_history{};
};
struct LscResult {LscStatus status{LscStatus::parent};LscProfile value;};
[[nodiscard]] inline LscResult inspect_lsc(std::span<const std::uint8_t> ram,std::uint32_t at)noexcept{
    const auto parent=inspect_handle(ram,at);if(parent.status!=HandleStatus::ready)return{};
    LscProfile p;p.parent=parent.value;p.address=detail::load<std::uint32_t>(ram,at+0x94);
    if(!detail::slot(lsc_children,p.address,p.slot))return{LscStatus::child,{}};
    const auto child=p.address;if(ram[child]!=1)return{LscStatus::inactive,{}};
    if(detail::load<std::uint32_t>(ram,child+8)!=p.parent.input || detail::load<std::uint32_t>(ram,child+0x28)!=p.parent.file)return{LscStatus::links,{}};
    std::uint32_t ring_slot{};const auto input=p.parent.input;
    if(!detail::slot(source_rings,input,ring_slot) || detail::load<std::uint32_t>(ram,input)!=0x224c28 ||
        detail::load<std::uint32_t>(ram,0x224c4c)!=0x13fa38 || detail::load<std::uint32_t>(ram,input+4)!=1)return{LscStatus::ring,{}};
    p.capacity=detail::load<std::uint32_t>(ram,child+0x18);p.minimum=detail::load<std::uint32_t>(ram,child+0x14);
    if(p.capacity>static_cast<std::uint32_t>(adxt_shared_source::maximum_encoded_capacity) ||
        !adxt_shared_source::admits_capacity(static_cast<std::int32_t>(p.capacity),adxt_shared_source::CapacityProfile::bounded_sectors) ||
        p.minimum>p.capacity || detail::load<std::uint32_t>(ram,input+0x20)!=p.capacity || detail::load<std::uint32_t>(ram,input+0x24)!=36)return{LscStatus::geometry,{}};
    const auto data=detail::load<std::uint32_t>(ram,input+0xc),free=detail::load<std::uint32_t>(ram,input+0x10);
    const auto backing=detail::load<std::uint32_t>(ram,input+0x1c);
    if(data>p.capacity || free>p.capacity || std::uint64_t(data)+free>p.capacity || !detail::pointer(backing) || backing>ram_bytes-p.capacity-36)return{LscStatus::ring,{}};
    p.state=ram[child+1];p.transferring=ram[child+2];p.repeat=ram[child+3];p.paused=ram[child+4];
    p.tail=detail::load<std::uint32_t>(ram,child+0x1c);p.head=detail::load<std::uint32_t>(ram,child+0x20);p.count=detail::load<std::uint32_t>(ram,child+0x24);
    if(p.state>2 || p.transferring>1 || p.paused>1 || p.tail>=16 || p.head>=16 || p.count>16)return{LscStatus::queue,{}};
    if(detail::load<std::uint32_t>(ram,0x21dfd8))return{LscStatus::callback,{}};
    p.empty_history=p.state==0 && !p.transferring && !p.tail && !p.head && !p.count &&
        !detail::load<std::uint32_t>(ram,child+0x2c) && !detail::load<std::uint32_t>(ram,child+0x30) && !detail::load<std::uint32_t>(ram,child+0x34);
    for(unsigned i=0;i<16*8;++i)p.empty_history&=detail::load<std::uint32_t>(ram,child+0x38+i*4)==0;
    return{LscStatus::ready,std::move(p)};
}
}
