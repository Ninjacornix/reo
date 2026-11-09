#pragma once
#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <vector>
namespace reo::native::animation {
struct WeaponKey {float value;std::int32_t time;};
struct WeaponSample {float value;bool finished;};
class WeaponCurve final {
public:
    WeaponSample sample(std::int32_t time)const;
    std::span<const WeaponKey> keys()const noexcept{return keys_;}
private:
    std::vector<WeaponKey> keys_;
    friend class WeaponProgramBank;
};
struct WeaponPart {std::array<std::optional<WeaponCurve>,6> curves;};
struct WeaponProgram {std::array<std::optional<WeaponPart>,6> parts;};
enum class WeaponSelectionKind {empty,program,unavailable};
struct WeaponSelection {WeaponSelectionKind kind{WeaponSelectionKind::empty};std::shared_ptr<const WeaponProgram> program;};
// Original WMD files are copied into a cleared2KiB asset buffer. They do not
// all contain ten header offsets: some later selector words overlap key data.
// Import only admits bounded valid selection trees; unavailable cells are not
// silently converted into the meaningful zero-offset/empty selection.
class WeaponProgramBank final {
public:
    static std::shared_ptr<const WeaponProgramBank> import(std::span<const std::byte>);
    const WeaponSelection& selection(unsigned index)const;
private:
    std::array<WeaponSelection,10> selections_;
};
struct WeaponProgramState {
    std::uint8_t phase{};
    std::int16_t elapsed{};
    std::array<std::uint8_t,7> completed{};
    std::shared_ptr<const WeaponProgramBank> source;
    std::shared_ptr<const WeaponProgram> selected;
    std::optional<unsigned> selection_index;
};
}
