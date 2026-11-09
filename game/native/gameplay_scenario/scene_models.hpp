#pragma once
#include "content.hpp"
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
};
enum class ModelStatus {completed,invalid_authored_id,invalid_pose_slot,invalid_preset,unsupported_numeric};
// Canonical scene data, simulation-owner thread only. Renderer submission and
// external-pose binding ownership remain separate consumers of these values.
class SceneModels final {
public:
    SceneModels(const SceneModelState& state,const RoomModelRemap& remap):state_(state),remap_(remap){}
    const SceneModelState& state()const noexcept{return state_;}
    const RoomModelRemap& remap()const noexcept{return remap_;}
    void room_remap(const RoomModelRemap& value)noexcept{remap_=value;}
    std::uint8_t resolve(std::uint32_t authored)const noexcept;
    void visibility(std::uint32_t authored,bool set)noexcept;
    void mark_slot_byte(std::uint8_t resolved,std::uint8_t value)noexcept;
    ModelStatus style(std::uint32_t authored,std::uint32_t word)noexcept;
    void reset_styles()noexcept;
    std::optional<ModelMatrix> pose(std::uint32_t slot)const noexcept;
    ModelStatus pose(std::uint32_t slot,const ModelMatrix&)noexcept;
    ModelStatus adjust(std::uint32_t authored,std::size_t preset,std::span<const ModelTransformPreset>)noexcept;
    ModelStatus adjust(std::uint32_t authored,std::size_t preset)noexcept{return adjust(authored,preset,stock_model_transform_presets());}
private:
    SceneModelState state_;
    RoomModelRemap remap_;
};
} // namespace reo::native::gameplay_scenario
