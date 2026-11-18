#pragma once
#include <array>
#include <cstdint>
#include <memory>
#include <span>

namespace reo::native::adxt_attenuation {
inline constexpr std::size_t table_words=1000;
enum class Status {completed,invalid_table,no_memory};
struct Metadata {std::uint32_t presence{};std::uint8_t decoder_phase{};std::uint16_t offset{};};
struct Result {std::int16_t requested{};std::int32_t clamped{};std::uint32_t volume{};};
class Table;
struct Open {Status status{Status::invalid_table};std::shared_ptr<const Table> table;};
// Injected immutable table, not an edition identity attestation. The game
// adapter must qualify its actual 1000 owned words before constructing it.
class Table final {
public:
    [[nodiscard]] static Open from_words(std::span<const std::uint32_t>)noexcept;
    [[nodiscard]] Result apply(std::uint32_t requested_word,Metadata)const noexcept;
private:
    std::array<std::uint32_t,table_words> words_;
    explicit Table(std::span<const std::uint32_t> words)noexcept;
};
} // namespace reo::native::adxt_attenuation
