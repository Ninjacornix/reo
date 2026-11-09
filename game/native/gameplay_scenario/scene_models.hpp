#pragma once
#include "content.hpp"
#include "model_reference.hpp"
#include "../transform_math/transform_math.hpp"
#include <array>
#include <cstdint>
#include <optional>
#include <span>

namespace reo::native::gameplay_scenario {
using ModelMatrix=transform_math::Matrix;
using RoomModelRemap=std::array<std::uint8_t,32>;
RoomModelRemap import_room_model_remap(const content::ScriptBank&);
struct ModelTransformPreset {transform_math::Vector radians,offset;};
std::span<const ModelTransformPreset,8> stock_model_transform_presets()noexcept;
struct SceneModelState {
    std::array<std::uint8_t,128> visibility{};
    std::array<std::uint32_t,128> styles{};
    std::array<ModelMatrix,128> poses{};
    // Room importer5C1390 owns this model-indexed sound resource map once.
    // Missing means not imported; a zero byte remains a valid authored value.
    std::array<std::optional<std::uint8_t>,128> sound_resources;
    std::optional<std::uint8_t> absent_sound_resource;
};
enum class ModelStatus {completed,invalid_authored_id,invalid_pose_slot,invalid_preset,unsupported_numeric};
// Canonical scene data, simulation-owner thread only. Renderer submission and
// external-pose binding ownership remain separate consumers of these values.
class SceneModels final {
public:
    SceneModels(const SceneModelState& state,const RoomModelRemap& remap):state_(state),remap_(remap){}
    const SceneModelState& state()const noexcept{return state_;}
    const RoomModelRemap& remap()const noexcept{return remap_;}
    bool admits(const ModelReference&)const noexcept;
    bool admits_channel(const ModelReference&,std::size_t)const noexcept;
    ModelReference reference(std::uint32_t authored)const noexcept;
    bool admits_adjustment(std::uint32_t authored)const noexcept{return admits(reference(authored));}
    bool admits_visibility(std::uint32_t authored)const noexcept;
    std::optional<ModelMatrix> pose(const ModelReference&)const noexcept;
    ModelStatus pose(const ModelReference&,const ModelMatrix&)noexcept;
    std::optional<std::uint8_t> sound_resource(const ModelReference&)const noexcept;
    ModelStatus sound_resource(const ModelReference&,std::uint8_t)noexcept;
    void room_remap(const RoomModelRemap&)noexcept;
    std::uint8_t resolve(std::uint32_t authored)const noexcept;
    ModelStatus visibility(std::uint32_t authored,bool set)noexcept;
    void mark_slot_byte(std::uint8_t resolved,std::uint8_t value)noexcept;
    ModelStatus sound_resource(std::uint32_t model,std::uint8_t value)noexcept;
    ModelStatus style(std::uint32_t authored,std::uint32_t word)noexcept;
    void reset_styles()noexcept;
    std::optional<ModelMatrix> pose(std::uint32_t slot)const noexcept;
    ModelStatus pose(std::uint32_t slot,const ModelMatrix&)noexcept;
    ModelStatus adjust(std::uint32_t authored,std::size_t preset,std::span<const ModelTransformPreset>)noexcept;
    ModelStatus adjust(std::uint32_t authored,std::size_t preset)noexcept{return adjust(authored,preset,stock_model_transform_presets());}
private:
    SceneModelState state_;
    RoomModelRemap remap_;
    std::weak_ptr<const AuthoredModelLease> absent_lease_;
    // Immutable installation provenance survives lease expiry to prevent an
    // expired typed absence reverting to legacy unchecked visibility aliasing.
    // This marker never grants admission; only the live weak lease can do so.
    std::shared_ptr<const AuthoredModelDomain> absent_origin_;
    std::uint32_t absent_authored_{};
    void authored_absence(std::shared_ptr<const AuthoredModelLease>)noexcept;
    friend class RoomSceneOwner;
};
} // namespace reo::native::gameplay_scenario
