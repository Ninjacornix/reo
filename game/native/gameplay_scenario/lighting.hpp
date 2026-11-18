#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <memory>
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
LightDescriptor decode_light_descriptor(std::span<const std::byte>);
struct LightDomain;
class CutsceneLights;
class LightHandle final {
public:
    LightHandle()=default;
    explicit operator bool()const noexcept{return bool(domain_)&&generation_!=0;}
    friend bool operator==(const LightHandle&,const LightHandle&)=default;
private:
    std::shared_ptr<const LightDomain> domain_;
    std::uint64_t epoch_{},generation_{};
    std::uint8_t slot_{};
    friend class Lighting;
};
enum class LightingImport { completed,unsupported_version };
class AuxiliaryLightHandle final {
public:
    AuxiliaryLightHandle()=default;
    explicit operator bool()const noexcept{return bool(domain_)&&generation_!=0;}
    friend bool operator==(const AuxiliaryLightHandle&,const AuxiliaryLightHandle&)=default;
private:
    std::shared_ptr<const LightDomain> domain_;
    std::uint64_t epoch_{},generation_{};
    std::uint8_t slot_{};
    friend class Lighting;
};
// Canonical game-side state; rendering consumes its typed snapshots later.
// Internal bank bindings name physical native pool slots deliberately: original
// removal retains its binding, including subsequent reuse of that same slot.
class Lighting final {
public:
    Lighting();
    Lighting(const Lighting&)=delete;
    Lighting& operator=(const Lighting&)=delete;
    LightingImport import_lig(std::span<const std::byte>);
    void reset_work()noexcept;
    void select(std::uint8_t bank)noexcept;
    bool create(std::uint8_t index)noexcept;
    bool remove(std::uint8_t index)noexcept;
    bool create_all()noexcept;
    std::optional<std::uint8_t> allocate(const LightDescriptor*,std::uint8_t tag,std::uint8_t mode)noexcept;
    bool release(std::uint8_t slot)noexcept;
    // Timed consumers retain generations; room bindings keep their separately
    // qualified physical-slot reuse semantics.
    std::optional<LightHandle> handle(std::uint8_t slot)const noexcept;
    std::optional<std::uint8_t> slot(const LightHandle&)const noexcept;
    std::optional<NativeLight> light(const LightHandle&)const noexcept;
    bool release(const LightHandle&)noexcept;
    bool replace(const LightHandle&,const LightDescriptor&)noexcept;
    // The source6B2BD0/6B2CC0 auxiliary pool is already canonical here. Its
    // handles have a distinct type so primary consumers cannot retarget it.
    std::optional<AuxiliaryLightHandle> allocate_auxiliary(const LightDescriptor*,std::uint8_t tag)noexcept;
    std::optional<AuxiliaryLightHandle> auxiliary_handle(std::uint8_t)const noexcept;
    std::optional<std::uint8_t> auxiliary_slot(const AuxiliaryLightHandle&)const noexcept;
    std::optional<NativeLight> light(const AuxiliaryLightHandle&)const noexcept;
    bool release(const AuxiliaryLightHandle&)noexcept;
    bool replace(const AuxiliaryLightHandle&,const LightDescriptor&)noexcept;
    const std::array<LightingBank,4>& banks()const noexcept{return banks_;}
    const std::array<NativeLight,64>& primary()const noexcept{return primary_;}
    const std::array<NativeLight,64>& auxiliary()const noexcept{return auxiliary_;}
    const std::array<std::uint8_t,32>& bindings()const noexcept{return bindings_;}
    std::int8_t selected()const noexcept{return selected_;}
    std::uint8_t primary_count()const noexcept{return primary_count_;}
    std::uint8_t auxiliary_count()const noexcept{return auxiliary_count_;}
    std::uint64_t reset_epoch()const noexcept{return reset_epoch_;}
private:
    friend class CutsceneLights;
    bool register_cutscene(CutsceneLights*)noexcept;
    void unregister_cutscene(CutsceneLights*)noexcept;
    bool owns_cutscene(const CutsceneLights*)const noexcept;
    std::array<LightingBank,4> banks_{};
    std::array<NativeLight,64> primary_{},auxiliary_{};
    std::array<std::uint8_t,32> bindings_{};
    std::uint8_t primary_count_{};
    std::int8_t selected_{-1};
    std::uint64_t reset_epoch_{};
    std::shared_ptr<const LightDomain> domain_;
    std::array<std::uint64_t,64> generations_{};
    std::array<std::uint64_t,64> auxiliary_generations_{};
    std::uint8_t auxiliary_count_{};
    bool exhausted_{};
};
} // namespace reo::native::gameplay_scenario
