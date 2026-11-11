#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <span>

namespace reo::native::gameplay_world { struct Session; }
namespace reo::native::gameplay_scenario {
// Numeric parameter names retain their authored source positions until their
// individual consumers establish a more specific role.
struct EnemyDescriptor {
    std::uint8_t ordinal{},actor_slot{},family{},variant{},condition{},parameter4{},spawned{};
    std::array<std::uint32_t,2> orientation{};
    std::array<std::int32_t,3> position{};
    std::int16_t health{},maximum{};
    std::uint8_t room{},owner_mode{},parameter1f{},parameter20{},parameter5{},parameter23{};
    std::array<std::uint8_t,10> auxiliary_ids{};
    std::int8_t parameter21{},route_position{};
    std::uint16_t route_wait{};
    std::uint8_t parameter24{},route_seed{},parameter25{},parameter26{},runtime_flags{},parameter31{},parameter32{};
    std::array<std::uint8_t,13> parameters34_to40{};
    std::array<std::uint8_t,2> parameters42_to43{};
    std::array<std::uint8_t,3> linked_ids{};
    std::uint8_t parameter48{},choice_mask{},mapped_parameter{},route_selector{};
};

struct EnemyRoomAssignments {
    std::array<std::uint16_t,2> counts{};
    std::array<std::uint8_t,4> flags{};
    std::array<std::uint8_t,1024> slots{};
    void reset() noexcept { counts={};flags={};slots.fill(255); } //1B2D80
};
enum class EnemyImportStatus { completed,malformed,full,unavailable };
struct EnemyImported {
    EnemyImportStatus status{EnemyImportStatus::malformed};
    std::size_t count{},source_offset{};
};

class EnemyDescriptors final {
public:
    static constexpr std::size_t capacity=256;
    // Count publication preserves the original byte-sized consumer contract.
    std::uint8_t count() const noexcept { return count_; }
    std::span<const EnemyDescriptor,capacity> records() const noexcept { return records_; }
    EnemyDescriptor* record(std::size_t index) noexcept {
        return index<capacity ? &records_[index] : nullptr;
    }
    std::span<const std::uint8_t,capacity> expiry() const noexcept { return expiry_; }
    EnemyRoomAssignments& assignments() noexcept { return assignments_; }
    const EnemyRoomAssignments& assignments() const noexcept { return assignments_; }
    const std::array<std::uint8_t,128>& room_counts() const noexcept { return room_counts_; }
    const std::array<std::uint8_t,128>& room_starts() const noexcept { return room_starts_; }
    // Complete bounded successful-load6BAA40 expansion. Native values, shared
    // RNG and registrations commit together after all selected records resolve.
    EnemyImported import(std::span<const std::byte>,gameplay_world::Session&,
                         bool offline,std::uint8_t choice_row) noexcept;
private:
    std::array<EnemyDescriptor,capacity> records_{};
    std::array<std::uint8_t,capacity> expiry_{};
    std::array<std::uint8_t,128> room_counts_{},room_starts_{};
    EnemyRoomAssignments assignments_;
    std::uint8_t count_{};
};
}
