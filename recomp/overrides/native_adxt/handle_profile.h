#pragma once
#include <array>
#include <cstdint>
#include <cstring>
#include <span>

namespace reo::native::adxt_binding {
// File #1 US only. The caller must first qualify the original code/table image,
// runtime incarnation and serialized guest read ownership. Matching these bytes
// alone is neither a runtime capability nor proof of original construction.
inline constexpr std::uint32_t ram_bytes=32u*1024u*1024u;
struct Pool {std::uint32_t base,stride,count;};
inline constexpr Pool handles{0x20f3c8,0xc4,16},decoders{0x217d88,0x9c,16},
    files{0x21a8c0,0x5c,40},rnas{0x223880,0x60,16},transfers{0x21bc08,0x40,32},
    paired{0x221480,0x18,32};
enum class HandleStatus {ready,wrong_ram,invalid_handle,inactive,unsupported_channels,invalid_child,channel_mismatch,invalid_route,unsupported_transfers};
struct Handle {
    // slot is the 16-entry ADXT service table index. file_slot is a separate
    // 40-entry source descriptor index; never use it as native Indices.stream.
    std::uint32_t address{},slot{},channels{},decoder{},file{},rna{},route{};
    std::uint32_t decoder_slot{},file_slot{},rna_slot{};
    std::array<std::uint32_t,2> transfer{},transfer_slot{},paired_record{},output{};
    std::uint32_t input{};
};
struct HandleResult {HandleStatus status{HandleStatus::invalid_handle};Handle value;};
namespace detail {
inline bool slot(Pool pool,std::uint32_t address,std::uint32_t& result)noexcept{
    if(address<pool.base || (address-pool.base)%pool.stride)return false;
    result=(address-pool.base)/pool.stride;return result<pool.count;
}
inline bool pointer(std::uint32_t address)noexcept{return address && address%4==0 && address<=ram_bytes-4;}
template<class T>T load(std::span<const std::uint8_t> ram,std::uint32_t address)noexcept{T value;std::memcpy(&value,ram.data()+address,sizeof(value));return value;}
}
[[nodiscard]] inline HandleResult inspect_handle(std::span<const std::uint8_t> ram,std::uint32_t address)noexcept{
    if(ram.size()!=ram_bytes || !ram.data())return{HandleStatus::wrong_ram,{}};
    Handle h;h.address=address;
    if(!detail::slot(handles,address,h.slot))return{HandleStatus::invalid_handle,{}};
    if(ram[address]!=1)return{HandleStatus::inactive,{}};
    h.channels=ram[address+3];if(h.channels<1 || h.channels>2)return{HandleStatus::unsupported_channels,{}};
    h.decoder=detail::load<std::uint32_t>(ram,address+4);h.file=detail::load<std::uint32_t>(ram,address+8);h.rna=detail::load<std::uint32_t>(ram,address+12);
    if(!detail::slot(decoders,h.decoder,h.decoder_slot) || !detail::slot(files,h.file,h.file_slot) || !detail::slot(rnas,h.rna,h.rna_slot))return{HandleStatus::invalid_child,{}};
    if(ram[h.decoder]!=1 || ram[h.rna]!=1 || ram[h.file]!=1)return{HandleStatus::inactive,{}};
    if(ram[h.decoder+2]!=h.channels || detail::load<std::uint32_t>(ram,h.rna+4)!=h.channels)return{HandleStatus::channel_mismatch,{}};
    h.input=detail::load<std::uint32_t>(ram,address+0x10);
    if(!detail::pointer(h.input) || detail::load<std::uint32_t>(ram,h.decoder+8)!=h.input || detail::load<std::uint32_t>(ram,h.file+4)!=h.input)return{HandleStatus::invalid_child,{}};
    h.route=detail::load<std::uint32_t>(ram,h.rna+0x20);
    if(h.route<0x1e0000 || h.route>=0x1eff00 || (h.route-0x1e0000)%0x20)return{HandleStatus::invalid_route,{}};
    const auto paired_count=detail::load<std::uint32_t>(ram,0x221438);
    if(paired_count<1 || paired_count>paired.count)return{HandleStatus::invalid_child,{}};
    for(unsigned channel=0;channel<h.channels;++channel){
        h.output[channel]=detail::load<std::uint32_t>(ram,address+0x18+4*channel);
        if(!detail::pointer(h.output[channel]) || detail::load<std::uint32_t>(ram,h.decoder+0xc+4*channel)!=h.output[channel] || detail::load<std::uint32_t>(ram,h.rna+0x18+4*channel)!=h.output[channel])return{HandleStatus::channel_mismatch,{}};
        h.transfer[channel]=detail::load<std::uint32_t>(ram,h.rna+0x10+4*channel);
        h.paired_record[channel]=detail::load<std::uint32_t>(ram,h.rna+8+4*channel);std::uint32_t pair_slot{};
        if(!detail::slot(transfers,h.transfer[channel],h.transfer_slot[channel]) || !detail::slot(paired,h.paired_record[channel],pair_slot) || pair_slot>=paired_count)return{HandleStatus::invalid_child,{}};
        if(ram[h.transfer[channel]]!=1 || ram[h.paired_record[channel]]!=1)return{HandleStatus::inactive,{}};
        const auto destination=detail::load<std::uint32_t>(ram,h.paired_record[channel]+8);
        if(!detail::pointer(destination) || detail::load<std::uint32_t>(ram,h.transfer[channel]+4)!=h.output[channel] || detail::load<std::uint32_t>(ram,h.transfer[channel]+8)!=destination)return{HandleStatus::channel_mismatch,{}};
    }
    // First game admission profile only: the paired native copy occupies the
    // first service position, while the game binding reserves BOTH DTR slots.
    // Arbitrary separated/interleaved original DTR schedules are not admitted.
    if(h.channels==2 && (h.transfer_slot[1]!=h.transfer_slot[0]+1 || h.output[0]==h.output[1] || h.paired_record[0]==h.paired_record[1]))return{HandleStatus::unsupported_transfers,{}};
    return{HandleStatus::ready,h};
}
} // namespace reo::native::adxt_binding
