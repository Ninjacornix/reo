#include "auxiliary_room_rows.hpp"
#include <stdexcept>
#include <utility>

namespace reo::native::gameplay_scenario {
namespace {
std::uint32_t word(std::span<const std::byte> data) noexcept {
    return std::to_integer<std::uint32_t>(data[0]) |
           std::to_integer<std::uint32_t>(data[1]) << 8 |
           std::to_integer<std::uint32_t>(data[2]) << 16 |
           std::to_integer<std::uint32_t>(data[3]) << 24;
}
}

std::optional<AuxiliaryRoomRows> AuxiliaryRoomRows::import(const content::ScriptBank& bank) {
    if (bank.format() != content::BankFormat::scenario_evb)
        throw std::invalid_argument("Auxiliary room rows require a scenario EVB");
    const auto object = bank.object(24);
    if (!object) return {};
    const auto table = bank.view(*object);
    AuxiliaryRoomRows result;
    result.bytes_ = bank.backing();
    bool terminated = false;
    for (std::size_t at = 0; at + 4 <= table.size(); at += 4) {
        const auto offset = word(table.subspan(at,4));
        if (offset == UINT32_MAX) {
            terminated = true;
            break;
        }
        if (offset < bank.table_size() * 4 || offset >= object->bound.offset ||
            (!result.offsets_.empty() && offset <= result.offsets_.back()) ||
            result.offsets_.size() == 256)
            throw std::invalid_argument("Auxiliary room row lies outside its EVB extent");
        result.offsets_.push_back(offset);
    }
    if (!terminated) throw std::invalid_argument("Auxiliary room rows lack a terminator");
    if (result.offsets_.empty()) return result;
    const auto last_width = object->bound.offset - result.offsets_.back();
    result.width_ = result.offsets_.size() == 1 ? last_width : result.offsets_[1] - result.offsets_[0];
    if (result.width_ == 0 || result.width_ > 128 || last_width < result.width_)
        throw std::invalid_argument("Invalid auxiliary room row extent");
    for (std::size_t i = 1; i < result.offsets_.size(); ++i)
        if (result.offsets_[i] - result.offsets_[i-1] != result.width_)
            throw std::invalid_argument("Inconsistent auxiliary room row widths");
    return result;
}

std::optional<std::uint8_t> AuxiliaryRoomRows::index(std::uint8_t row,std::uint16_t room) const noexcept {
    if (row >= offsets_.size() || room >= width_) return {};
    return std::to_integer<std::uint8_t>((*bytes_)[offsets_[row] + room]);
}

void AuxiliaryScene::bind(std::optional<AuxiliaryRoomRows> rows) noexcept {
    rows_ = std::move(rows);
    loaded_ = 255;
}

void AuxiliaryScene::select(std::uint32_t value) noexcept {
    if (value == row_) return;
    row_ = std::uint8_t(value);
    loaded_ = 255;
}

std::optional<std::uint8_t> AuxiliaryScene::index(std::uint16_t room) const noexcept {
    return rows_ ? rows_->index(row_,room) : std::nullopt;
}

bool AuxiliaryScene::set_timer(std::int32_t index,bool active) noexcept {
    if (index < -31 || index >= std::int32_t(timer_count)) return false;
    // Signed division rounds toward zero. -31..-1 use word zero.
    const auto slot = index < 0 ? std::uint32_t(index) & 31u : std::uint32_t(index);
    active_[slot] = active;
    return true;
}

std::optional<std::uint32_t> AuxiliaryScene::timer(std::uint32_t index) const noexcept {
    if (index >= timer_count) return {};
    return timers_[index];
}

std::optional<bool> AuxiliaryScene::timer_active(std::uint32_t index) const noexcept {
    if (index >= timer_count) return {};
    return active_[index];
}

void AuxiliaryScene::clear_timers() noexcept {
    active_.reset();
    timers_ = {};
}

void AuxiliaryScene::advance_timers() noexcept {
    for (std::size_t i = 0; i < timer_count; ++i)
        timers_[i] = active_[i] ? timers_[i] + 1u : 0u;
}
}
