#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>

namespace reo::native::gameplay_scenario {
struct RoomActorAsset {
    std::uint16_t id{65535}, parameter{65535};
    friend bool operator==(const RoomActorAsset&,const RoomActorAsset&) = default;
};

// Shared requests for scenario commands, auxiliary descriptor admission and
// the four-entry room asset loading/release consumers.
class RoomActorAssets {
public:
    static constexpr std::size_t room_count=128,room_capacity=4;
    using Row=std::array<RoomActorAsset,room_capacity>;

    void reset() noexcept { rows_={}; }
    bool append(std::uint32_t room,RoomActorAsset asset) noexcept {
        if(room>=room_count)return false;
        for(auto& entry:rows_[room]) {
            if(entry.id==65535 && entry.parameter==65535) {
                entry=asset;
                break;
            }
        }
        return true;
    }
    bool remove(std::uint16_t id,std::optional<std::uint32_t> room={}) noexcept {
        if(room && *room>=room_count)return false;
        const auto begin=room?*room:0u;
        const auto end=room?*room+1:room_count;
        for(auto index=begin;index<end;++index)
            for(auto& entry:rows_[index])
                if(entry.id==id)entry={};
        return true;
    }
    const Row* row(std::uint32_t room) const noexcept {
        return room<room_count?&rows_[room]:nullptr;
    }
    std::optional<bool> allowed(std::uint32_t room,std::uint16_t id) const noexcept {
        const auto entries=row(room);
        if(!entries)return {};
        for(const auto& entry:*entries)
            if(entry.id==id)return true;
        return false;
    }

private:
    std::array<Row,room_count> rows_{};
};
}
