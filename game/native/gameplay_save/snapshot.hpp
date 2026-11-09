#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <span>

namespace reo::native::gameplay_save {
inline constexpr std::size_t container_bytes=0x3fcc0;
inline constexpr std::size_t payload_bytes=container_bytes-8;
inline constexpr std::size_t header_bytes=0x100;
inline constexpr std::size_t data_bytes=container_bytes-0x108;
using Container=std::array<std::byte,container_bytes>;
using ContainerView=std::span<std::byte,container_bytes>;
using HeaderView=std::span<std::byte,header_bytes>;
using ConstHeaderView=std::span<const std::byte,header_bytes>;
using DataView=std::span<std::byte,data_bytes>;
using ConstDataView=std::span<const std::byte,data_bytes>;

// Native-owned section bytes: their individual gameplay fields are not guessed.
// These objects and container storage must not alias. Calls are externally serialized.
struct LiveState {
    std::array<std::byte,16> settings{};
    std::array<std::byte,0x4234> first{};
    std::array<std::byte,0x7000> second{};
    std::array<std::byte,0x8000> third{};
    std::array<std::byte,0x40> tail{};
    std::array<std::byte,8> conditional_tail{};
    std::byte profile_flag{},second_flag{},resume_selector{};
};
enum class DecodeResult:int { ok=0,bad_magic=-1,bad_checksum=-2,dependency_unavailable=-3 };
struct RestoreResult { int original_return{};DecodeResult decode{}; };
struct Services {
    void* context{};
    void (*timestamp)(void*,HeaderView) noexcept{};
    std::uint32_t (*random)(void*,std::uint32_t) noexcept{};
    void (*settings_changed)(void*,LiveState&) noexcept{};
};

// Exact legacy format. Decode mutates the entire payload before checksum failure.
// No encryption/authentication or field-semantic validation is claimed.
void encode(ContainerView,std::uint32_t seed) noexcept;
DecodeResult decode(ContainerView) noexcept;
void capture_header(HeaderView,const LiveState&) noexcept;
void capture_first(DataView,const LiveState&) noexcept;
void capture_second(HeaderView,DataView,const LiveState&) noexcept;
void capture_tail(DataView,const LiveState&) noexcept;
bool restore_header(ConstHeaderView,LiveState&,const Services&) noexcept;
void restore_first(ConstDataView,LiveState&) noexcept;
void restore_second(ConstDataView,LiveState&) noexcept;
void restore_tail(ConstDataView,LiveState&) noexcept;
void clear_second_for_root_mode(LiveState&,std::uint32_t root_mode) noexcept;
// Dependencies must all be supplied. These return false without mutation when
// required services are absent; no synthetic RNG/time/notification is substituted.
bool capture(ContainerView,const LiveState&,const Services&) noexcept;
RestoreResult restore(ContainerView,LiveState&,const Services&) noexcept;
} // namespace reo::native::gameplay_save
