#pragma once
#include "navigation.hpp"
#include "../gameplay_session/room_variants.hpp"
#include <memory>
namespace reo::native::gameplay_navigation {
// Simulation-owner-thread state. Immutable graph leases may be shared; mutable
// occupancy and visits belong only to this bank. Borrowed views expire on bind.
class Bank final {
public:
    explicit Bank(const gameplay_session::RoomVariants& variants)noexcept:variants_(variants){}
    Bank(const Bank&)=delete;
    Bank& operator=(const Bank&)=delete;
    // Room selection/occupancy portion of815E70, without mode0/1 callbacks.
    // Rebinding the same loaded asset preserves its four mutable visit masks.
    bool bind(std::shared_ptr<const Asset>);
    void clear_rooms()noexcept;
    void close()noexcept;
    bool bound()const noexcept{return bound_&&!closed_;}
    const Asset* asset()const noexcept{return bound()?asset_.get():nullptr;}
    const RoomGraph* room(std::uint32_t)const noexcept;
    std::optional<std::uint8_t> occupancy(std::uint32_t room,std::uint32_t node)const noexcept;
    bool occupancy(std::uint32_t room,std::uint32_t node,std::uint8_t)noexcept;
    std::span<const std::uint8_t> visits(std::uint32_t actor)const noexcept;
    bool visit(std::uint32_t actor,std::uint32_t link,std::uint8_t)noexcept;
    bool clear_actor_visits(std::uint32_t actor)noexcept; // complete8194F0, actor0..3
    std::optional<std::array<std::uint8_t,4>> edge_flags(std::uint32_t room)const noexcept;
    bool edge_flags(std::uint32_t room,std::array<std::uint8_t,4>)noexcept;
private:
    const gameplay_session::RoomVariants& variants_;
    std::shared_ptr<const Asset> asset_;
    std::array<std::optional<std::size_t>,128> selected_{};
    std::array<std::array<std::uint8_t,128>,128> occupancy_{};
    std::vector<std::uint8_t> visits_;
    std::vector<std::array<std::uint8_t,4>> graph_edge_flags_;
    bool bound_{},closed_{};
};
}
