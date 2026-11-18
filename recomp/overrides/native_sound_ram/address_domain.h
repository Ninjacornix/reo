#pragma once
#include <cstddef>
#include <cstdint>

namespace reo::native::sound_ram {
// Pure address validation. This object owns no memory, lock, Runtime, or read
// capability. Successful validation MUST NOT be used as permission to copy.
enum class Space { ee, iop };
enum class AddressStatus {
    ok, invalid_geometry, invalid_space, unsupported_address, invalid_extent,
    excluded_aperture, invalid_host, host_alias
};
struct Region { Space space{}; std::size_t offset{}, bytes{}; };
struct AddressResult { AddressStatus status; Region region{}; };
struct HostExtent { std::uintptr_t begin{}, end{}; };
bool overlaps(HostExtent, HostExtent) noexcept;
bool checked_host_extent(const void*, std::size_t, HostExtent&) noexcept;

class AddressDomain final {
public:
    static constexpr std::size_t ee_bytes=32u*1024u*1024u;
    static constexpr std::size_t iop_bytes=2u*1024u*1024u;
    AddressDomain(const void* ee, const void* iop) noexcept;
    bool valid() const noexcept { return valid_; }
    AddressResult resolve(Space, std::uint32_t address, std::size_t bytes) const noexcept;
    // Host buffers must be valid for their entire synchronous operation by a
    // separate caller lifetime contract. This only checks arithmetic and rules
    // out aliases of either complete guest backing, even forbidden apertures.
    AddressStatus validate_host(const void*, std::size_t) const noexcept;
private:
    HostExtent ee_{},iop_{};
    bool valid_{};
};
} // namespace reo::native::sound_ram
