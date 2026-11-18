#pragma once
#include <array>
#include <cstdint>
#include <optional>
#include <span>

namespace reo::native::gameplay_session {
using RoomMembers = std::array<std::uint8_t,4>;
using RoomMembershipTable = std::array<RoomMembers,128>;
struct RoomMembershipRow {
    std::uint8_t room{};
    RoomMembers members{};
    friend bool operator==(const RoomMembershipRow&,const RoomMembershipRow&)=default;
};
struct RoomMembershipUpdate {
    std::uint8_t sender{},count{};
    std::array<RoomMembershipRow,8> rows{};
};
enum class RoomMembershipStatus {completed,unavailable,too_many_changes};
struct RoomMembershipChanges {
    RoomMembershipStatus status{RoomMembershipStatus::completed};
    std::optional<RoomMembershipUpdate> update;
};
// Canonical room membership has three distinct producers: received claims,
// publication comparison, and received snapshots. A claim never grants local
// authority before the snapshot receiver runs. Generic construction is unknown.
class RoomMembership final {
public:
    bool initialize(std::uint8_t mode)noexcept;
    bool ready(std::uint8_t mode)const noexcept{return mode_&&*mode_==mode;}
    void clear()noexcept{mode_.reset();}
    // The overlay frame restores its authority workspace before draining
    // requests. This is separate from accepting a remote room snapshot.
    bool begin_update()noexcept;
    RoomMembershipStatus claim(std::uint8_t actor,std::uint16_t room,
        std::optional<std::int8_t> authority)noexcept;
    RoomMembershipStatus release(std::uint8_t actor,std::uint16_t room,
        std::optional<std::int8_t> authority)noexcept;
    RoomMembershipChanges collect(std::optional<std::int8_t> authority,
        std::uint8_t sender)noexcept;
    RoomMembershipStatus receive(std::span<const RoomMembershipRow>)noexcept;
    std::optional<bool> first(std::uint16_t room,std::uint8_t actor)const noexcept;
    std::optional<bool> contains(std::uint16_t room,std::uint8_t actor)const noexcept;
    std::optional<std::int32_t> owner(std::uint16_t room)const noexcept;
    const RoomMembershipTable& authority_rows()const noexcept{return authority_;}
    const RoomMembershipTable& published_rows()const noexcept{return published_;}
    const RoomMembershipTable& received_rows()const noexcept{return received_;}
private:
    std::optional<std::uint8_t> mode_;
    RoomMembershipTable authority_{},published_{},received_{};
};
}
