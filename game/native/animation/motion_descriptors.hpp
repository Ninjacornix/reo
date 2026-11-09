#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
namespace reo::native::animation {
struct PackedMotion {std::array<std::uint8_t,8> bytes{};friend bool operator==(const PackedMotion&,const PackedMotion&)=default;};
struct MotionIdentity {
    std::uint32_t status{};
    std::uint16_t resource_action{};
    std::uint8_t category{},subtype{},character{},class_marker{};
};
struct DecodedMotion {
    std::uint8_t family{},flags{},offset_selector{},shape_selector{},threshold{},alternate_threshold{};
    std::uint16_t channel_one{},channel_zero{};
};
// A bounded concrete immutable File1 content profile. Original pointer tables
// become native index arrays; consumed bytes are owned metadata, not guest RAM.
class File1MotionDescriptors final {
public:
    static constexpr std::size_t descriptor_count=1112;
    const PackedMotion& at(std::size_t)const;
    std::uint8_t resource_class(std::uint16_t)const;
    const PackedMotion& resolve(const MotionIdentity&,std::uint32_t encoded_key)const;
    DecodedMotion unpack(const MotionIdentity&,const PackedMotion&)const;
};
} // namespace reo::native::animation
