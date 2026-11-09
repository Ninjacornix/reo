#pragma once
#include "../transform_math/transform_math.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <vector>
namespace reo::native::gameplay_effects {
struct Key {std::int16_t value{},time{};};
class Curve {
public:
    static Curve import(std::span<const std::byte> bank,std::size_t offset,std::int16_t count);
    float sample(std::int16_t time)const;
    std::span<const Key> keys()const noexcept{return keys_;}
private:
    std::vector<Key> keys_;
};
struct Channel {std::int16_t kind{};std::optional<Curve> curve;};
struct Part {std::uint8_t resource{},material{},selector{};std::vector<Channel> channels;};
struct Group {std::int16_t lifetime{};std::vector<Part> parts;};
struct Parameters {
    transform_math::Vector translation,scale{1,1,1};
    std::array<std::int16_t,4> rotation{};
};
// Native owned File1 efdata tracks. The logical mapping and immutable curve
// values are asset data, independent of loaded geometry/resource identities.
class Tracks {
public:
    static std::shared_ptr<const Tracks> import(std::span<const std::byte>);
    std::optional<std::size_t> resolve(std::uint16_t logical,std::int16_t variant)const noexcept;
    std::int8_t variants(std::uint16_t logical)const;
    std::span<const Group> groups()const noexcept{return groups_;}
    const Group* group(std::size_t)const noexcept;
private:
    std::array<std::uint8_t,512> mapping_;
    std::array<std::int8_t,512> variants_;
    std::vector<Group> groups_;
    // Some owned banks have a bounded empty header at the literal byte255
    // index. The original constructor consumes it without an FF guard.
    std::optional<Group> maximum_byte_group_;
};
// Complete5903E0 channel policy; caller-owned channels not written by the
// authored group retain their values, including the fourth rotation halfword.
void sample_transform(std::span<const Channel>,std::int16_t time,Parameters&);
}
