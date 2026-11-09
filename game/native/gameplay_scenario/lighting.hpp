#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>

namespace reo::native::gameplay_scenario {
// Immutable LIG content values, decoded from the version4 asset format. The
// first two vectors' eventual lighting meanings remain a renderer contract.
struct LightDescriptor {
    std::array<float,4> vector0{},vector1{};
    std::array<float,3> position{};
    float attenuation{},parameter{};
};
struct LightingBank {
    std::uint16_t kind{},count{};
    LightDescriptor base;
    std::array<std::uint32_t,14> environment_words{};
    std::array<LightDescriptor,32> entries{};
    std::uint32_t enabled_mask{};
};
struct NativeLight {
    std::uint8_t active{},tag{},mode{},reserved{};
    LightDescriptor descriptor;
};
enum class LightingImport { completed,unsupported_version };
// Canonical game-side state; rendering consumes its typed snapshots later.
// Internal bank bindings name physical native pool slots deliberately: original
// removal retains its binding, including subsequent reuse of that same slot.
class Lighting final {
public:
    Lighting();
    LightingImport import_lig(std::span<const std::byte>);
    void reset_work()noexcept;
    void select(std::uint8_t bank)noexcept;
    bool create(std::uint8_t index)noexcept;
    bool remove(std::uint8_t index)noexcept;
    bool create_all()noexcept;
    std::optional<std::uint8_t> allocate(const LightDescriptor*,std::uint8_t tag,std::uint8_t mode)noexcept;
    bool release(std::uint8_t slot)noexcept;
    const std::array<LightingBank,4>& banks()const noexcept{return banks_;}
    const std::array<NativeLight,64>& primary()const noexcept{return primary_;}
    const std::array<NativeLight,64>& auxiliary()const noexcept{return auxiliary_;}
    const std::array<std::uint8_t,32>& bindings()const noexcept{return bindings_;}
    std::int8_t selected()const noexcept{return selected_;}
    std::uint8_t primary_count()const noexcept{return primary_count_;}
    std::uint64_t reset_epoch()const noexcept{return reset_epoch_;}
private:
    std::array<LightingBank,4> banks_{};
    std::array<NativeLight,64> primary_{},auxiliary_{};
    std::array<std::uint8_t,32> bindings_{};
    std::uint8_t primary_count_{};
    std::int8_t selected_{-1};
    std::uint64_t reset_epoch_{};
};
} // namespace reo::native::gameplay_scenario
