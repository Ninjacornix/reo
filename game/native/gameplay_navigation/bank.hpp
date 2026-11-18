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
    // Fresh-process843780 BSS authority, supplied only by the concrete launch
    // owner. An absent imported SGL by itself does not establish empty data.
    bool initialize_cold_empty()noexcept;
    bool refresh_source_ready()const noexcept{return !closed_&&(bool(asset_)||cold_empty_);}
    // Complete815E70 mode2: runtime room/occupancy views are cleared before
    // reselection; retained SGL visits, graph flags and header are preserved.
    bool refresh_rooms_mode_two()noexcept;
    void clear_rooms()noexcept;
    void close()noexcept;
    bool bound()const noexcept{return bound_&&!closed_;}
    // Mutable first header byte of this loaded SGL session. The immutable
    // imported version remains provenance;8120C0 clears this runtime byte.
    std::uint8_t header_byte()const noexcept{return header_byte_;}
    bool clear_header_byte()noexcept{if(closed_)return false;header_byte_=0;return true;}
    // Cross-room table views83E540..4C publish only after the complete room
    // loop. A refused refresh may still expose earlier room graphs below.
    const Asset* asset()const noexcept{return bound()&&runtime_views_ready_?asset_.get():nullptr;}
    // Current canonical session byte, not the variant selected at last bind.
    std::optional<std::uint8_t> current_variant(std::uint32_t room)const noexcept{return bound()?variants_.get(room):std::nullopt;}
    const RoomGraph* room(std::uint32_t)const noexcept;
    std::optional<std::uint8_t> occupancy(std::uint32_t room,std::uint32_t node)const noexcept;
    bool occupancy(std::uint32_t room,std::uint32_t node,std::uint8_t)noexcept;
    std::span<const std::uint8_t> visits(std::uint32_t actor)const noexcept;
    bool visit(std::uint32_t actor,std::uint32_t link,std::uint8_t)noexcept;
    bool clear_actor_visits(std::uint32_t actor)noexcept; // complete8194F0, actor0..3
    std::optional<std::array<std::uint8_t,4>> edge_flags(std::uint32_t room)const noexcept;
    bool edge_flags(std::uint32_t room,std::array<std::uint8_t,4>)noexcept;
    //816170/816500: first matching signed room/variant descriptor, independent
    // of the selected room graph (whose duplicate-key rule is last-match).
    std::optional<std::uint32_t> descriptor_policy(std::int32_t room,std::int32_t variant)const noexcept;
    bool descriptor_policy(std::int32_t room,std::int32_t variant,std::uint32_t)noexcept;
    // Per-room source views become known-empty at actual815E30, independently
    // of retained SGL provenance and later cross-room table publication.
    std::optional<std::size_t> condition_count(std::uint32_t room)const noexcept;
    bool condition_active(std::uint32_t room,std::size_t index,std::uint8_t)noexcept;
private:
    const gameplay_session::RoomVariants& variants_;
    std::shared_ptr<const Asset> asset_;
    std::array<std::optional<std::size_t>,128> selected_{};
    std::array<std::array<std::uint8_t,128>,128> occupancy_{};
    std::vector<std::uint8_t> visits_;
    std::vector<std::array<std::uint8_t,4>> graph_edge_flags_;
    std::vector<std::uint32_t> descriptor_policies_;
    // One runtime graph per source graph preserves aliasing between room keys
    // while keeping separate Banks' mutable condition bytes independent.
    std::vector<RoomGraph> graph_runtime_;
    bool bound_{},closed_{};
    bool cold_empty_{};
    bool runtime_views_ready_{};
    bool room_views_known_{};
    std::uint8_t header_byte_{};
};
}
