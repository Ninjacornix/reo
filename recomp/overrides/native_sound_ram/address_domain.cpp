#include "address_domain.h"
#include <array>
#include <limits>

namespace reo::native::sound_ram {
bool overlaps(HostExtent a,HostExtent b) noexcept {
    return a.begin<a.end && b.begin<b.end && a.begin<b.end && b.begin<a.end;
}
bool checked_host_extent(const void* p,std::size_t bytes,HostExtent& out) noexcept {
    const auto begin=reinterpret_cast<std::uintptr_t>(p);
    if((!p && bytes) || bytes>std::numeric_limits<std::uintptr_t>::max()-begin) return false;
    out={begin,begin+bytes};
    return true;
}
AddressDomain::AddressDomain(const void* ee,const void* iop) noexcept {
    valid_=ee && iop && checked_host_extent(ee,ee_bytes,ee_) &&
        checked_host_extent(iop,iop_bytes,iop_) && !overlaps(ee_,iop_);
}
AddressResult AddressDomain::resolve(Space space,std::uint32_t address,std::size_t bytes) const noexcept {
    if(!valid_) return {AddressStatus::invalid_geometry};
    if(space==Space::iop) {
        if(address>iop_bytes) return {AddressStatus::unsupported_address};
        if(bytes>iop_bytes-address) return {AddressStatus::invalid_extent};
        return {AddressStatus::ok,{space,address,bytes}};
    }
    if(space!=Space::ee) return {AddressStatus::invalid_space};
    constexpr std::array<std::uint32_t,4> bases{0,0x20000000u,0x80000000u,0xa0000000u};
    for(const auto base:bases) {
        // An empty interval may be exactly at its own window end. It grants no
        // payload access. Never normalize a nonempty unsupported alias by mask.
        if(address<base || std::uint64_t(address)-base>ee_bytes) continue;
        const auto offset=std::size_t(address-base);
        if(bytes>ee_bytes-offset) return {AddressStatus::invalid_extent};
        constexpr std::array<HostExtent,3> excluded{{
            {0x01000000u,0x01001000u}, {0x01004000u,0x01005000u},
            {0x01008000u,0x01010000u}}};
        const HostExtent range{offset,offset+bytes};
        for(const auto aperture:excluded)
            if(overlaps(range,aperture)) return {AddressStatus::excluded_aperture};
        return {AddressStatus::ok,{space,offset,bytes}};
    }
    return {AddressStatus::unsupported_address};
}
AddressStatus AddressDomain::validate_host(const void* pointer,std::size_t bytes) const noexcept {
    if(!valid_) return AddressStatus::invalid_geometry;
    HostExtent extent;
    if(!checked_host_extent(pointer,bytes,extent)) return AddressStatus::invalid_host;
    if(overlaps(extent,ee_) || overlaps(extent,iop_)) return AddressStatus::host_alias;
    return AddressStatus::ok;
}
} // namespace reo::native::sound_ram
