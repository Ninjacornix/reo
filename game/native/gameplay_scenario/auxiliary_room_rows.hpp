#pragma once
#include "content.hpp"
#include <bitset>

namespace reo::native::gameplay_scenario {
// Scenario EVB object 24 supplies relative row offsets for 6B73F0.
class AuxiliaryRoomRows {
public:
    static std::optional<AuxiliaryRoomRows> import(const content::ScriptBank&);
    std::optional<std::uint8_t> index(std::uint8_t row,std::uint16_t room) const noexcept;
    std::size_t row_count() const noexcept { return offsets_.size(); }
    std::size_t room_count() const noexcept { return width_; }

private:
    content::Bytes bytes_;
    std::vector<std::uint32_t> offsets_;
    std::size_t width_{};
};

class AuxiliaryScene {
public:
    static constexpr std::size_t timer_count = 512;
    void bind(std::optional<AuxiliaryRoomRows> rows) noexcept;
    void select(std::uint32_t original_value) noexcept;
    std::optional<std::uint8_t> index(std::uint16_t room) const noexcept;
    std::uint8_t row() const noexcept { return row_; }
    std::uint8_t loaded_index() const noexcept { return loaded_; }
    void publish_loaded_index(std::uint8_t index) noexcept { loaded_ = index; }
    bool set_timer(std::int32_t index,bool active) noexcept;
    std::optional<std::uint32_t> timer(std::uint32_t index) const noexcept;
    std::optional<bool> timer_active(std::uint32_t index) const noexcept;
    void advance_timers() noexcept;
    void clear_timers() noexcept; // actual6B7610 clears74E828/74E868 together

private:
    std::optional<AuxiliaryRoomRows> rows_;
    std::uint8_t row_{},loaded_{255};
    std::bitset<timer_count> active_;
    std::array<std::uint32_t,timer_count> timers_{};
};
}
