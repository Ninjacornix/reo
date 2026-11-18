#pragma once
#include "../transform_math/transform_math.hpp"
#include "../gameplay_session/room_variants.hpp"
#include "../gameplay_session/session.hpp"
#include <cstddef>
#include <memory>
#include <span>
#include <vector>
namespace reo::native::gameplay_scenario {
struct ReturnPointGroup {
    std::int8_t kind{},mode{};
    std::vector<std::int8_t> indices;
};
struct ReturnPointRoom {
    std::uint16_t key{};
    std::vector<transform_math::Vector> points;
    std::vector<ReturnPointGroup> groups;
};
struct ReturnPointResult {
    std::int8_t status{-1}; // source -1 absent,0 more points,1 last point
    std::optional<transform_math::Vector> position;
};
// Immutable typed RTP content. Room order and duplicate keys/groups matter:
// the source selects the first matching record. No runtime pointers survive.
class RoomReturnPoints final {
public:
    static std::shared_ptr<const RoomReturnPoints> import(std::span<const std::byte>);
    std::span<const ReturnPointRoom> rooms()const noexcept{return rooms_;}
    //5FDF10: arguments truncate to signed bytes before their source queries.
    // Unknown room variant or an out-of-bounds source read refuses (nullopt).
    // A known source no-match is status-1 and consumes no random values.
    std::optional<ReturnPointResult> point(std::uint32_t room,std::uint32_t mode,
        std::uint32_t kind,std::uint32_t index,const gameplay_session::RoomVariants&,
        gameplay_session::Random&)const;
    //5FE160 returns a group-relative index. Its wildcard compares kind to
    // the signed room argument, unlike5FDF10's mode==-1 wildcard.
    std::optional<std::int8_t> nearest(transform_math::Vector,std::uint32_t room,
        std::uint32_t mode,std::uint32_t kind,const gameplay_session::RoomVariants&)const;
private:
    std::vector<ReturnPointRoom> rooms_;
    const ReturnPointRoom* find(std::uint16_t)const noexcept;
};
}
