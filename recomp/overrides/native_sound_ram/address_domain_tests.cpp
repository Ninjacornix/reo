#include "address_domain.h"
#include <array>
#include <cstdio>
#include <cstdlib>
#include <limits>
using namespace reo::native::sound_ram;
namespace {
unsigned checks{};
void require(bool ok) { ++checks; if(!ok) { std::fprintf(stderr,"address check %u failed\n",checks); std::exit(1); } }
const void* pointer(std::uintptr_t p) { return reinterpret_cast<const void*>(p); }
}
int main() {
    static_assert(sizeof(std::uintptr_t)>=8);
    // Synthetic numeric intervals are never dereferenced or treated as memory
    // ownership. No RAM is read/written by the validator or these checks.
    constexpr std::uintptr_t ee=0x100000000ull,iop=0x200000000ull;
    AddressDomain domain(pointer(ee),pointer(iop)); require(domain.valid());
    for(const auto base:std::array<std::uint32_t,4>{0,0x20000000u,0x80000000u,0xa0000000u}) {
        const auto first=domain.resolve(Space::ee,base,16);
        require(first.status==AddressStatus::ok && first.region.offset==0 && first.region.bytes==16);
        require(domain.resolve(Space::ee,base+AddressDomain::ee_bytes-1,1).status==AddressStatus::ok);
        require(domain.resolve(Space::ee,base+AddressDomain::ee_bytes-1,2).status==AddressStatus::invalid_extent);
        require(domain.resolve(Space::ee,base+AddressDomain::ee_bytes,0).status==AddressStatus::ok);
        require(domain.resolve(Space::ee,base+AddressDomain::ee_bytes,1).status==AddressStatus::invalid_extent);
        for(const auto aperture:std::array<HostExtent,3>{{{0x01000000,0x01001000},{0x01004000,0x01005000},{0x01008000,0x01010000}}}) {
            const auto start=base+std::uint32_t(aperture.begin),end=base+std::uint32_t(aperture.end);
            require(domain.resolve(Space::ee,start-1,1).status==AddressStatus::ok);
            require(domain.resolve(Space::ee,start-1,2).status==AddressStatus::excluded_aperture);
            require(domain.resolve(Space::ee,start,1).status==AddressStatus::excluded_aperture);
            require(domain.resolve(Space::ee,end-1,1).status==AddressStatus::excluded_aperture);
            require(domain.resolve(Space::ee,end,1).status==AddressStatus::ok);
            require(domain.resolve(Space::ee,start,0).status==AddressStatus::ok);
        }
    }
    for(auto address:std::array<std::uint32_t,8>{0x04000000,0x11000000,0x11008000,0x1f800000,0x70000000,0x40000000,0xc0000000,0xffffffff})
        require(domain.resolve(Space::ee,address,1).status==AddressStatus::unsupported_address);
    require(domain.resolve(Space::ee,16,std::numeric_limits<std::size_t>::max()).status==AddressStatus::invalid_extent);
    require(domain.resolve(Space::iop,0,AddressDomain::iop_bytes).status==AddressStatus::ok);
    require(domain.resolve(Space::iop,AddressDomain::iop_bytes,0).status==AddressStatus::ok);
    require(domain.resolve(Space::iop,AddressDomain::iop_bytes,1).status==AddressStatus::invalid_extent);
    require(domain.resolve(Space::iop,0x80000000,1).status==AddressStatus::unsupported_address);
    require(domain.resolve(static_cast<Space>(17),0,1).status==AddressStatus::invalid_space);
    require(domain.validate_host(nullptr,0)==AddressStatus::ok);
    require(domain.validate_host(nullptr,1)==AddressStatus::invalid_host);
    require(domain.validate_host(pointer(std::numeric_limits<std::uintptr_t>::max()),1)==AddressStatus::invalid_host);
    for(const auto backing:std::array<HostExtent,2>{{{ee,ee+AddressDomain::ee_bytes},{iop,iop+AddressDomain::iop_bytes}}}) {
        require(domain.validate_host(pointer(backing.begin),1)==AddressStatus::host_alias);
        require(domain.validate_host(pointer(backing.begin-1),2)==AddressStatus::host_alias);
        require(domain.validate_host(pointer(backing.end-1),2)==AddressStatus::host_alias);
        require(domain.validate_host(pointer(backing.begin-1),1)==AddressStatus::ok);
        require(domain.validate_host(pointer(backing.end),1)==AddressStatus::ok);
        require(domain.validate_host(pointer(backing.begin),0)==AddressStatus::ok);
    }
    require(domain.validate_host(pointer(ee+0x01000000),1)==AddressStatus::host_alias);
    require(!AddressDomain(nullptr,pointer(iop)).valid());
    require(!AddressDomain(pointer(ee),pointer(ee+32)).valid());
    require(!AddressDomain(pointer(std::numeric_limits<std::uintptr_t>::max()-8),pointer(iop)).valid());
    require(AddressDomain(nullptr,nullptr).resolve(Space::ee,0,1).status==AddressStatus::invalid_geometry);
    require(!overlaps({1,1},{0,2})); require(!overlaps({1,2},{2,3})); require(overlaps({1,3},{2,4}));
    std::printf("%u address-domain checks passed; no RAM read authority exercised\n",checks);
}
