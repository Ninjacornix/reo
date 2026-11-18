#pragma once
#include "../transform_math/transform_math.hpp"
#include <cstddef>
#include <cstdint>
#include <array>
#include <optional>
#include <span>
#include <vector>

namespace reo::native::gameplay_presentation {
struct Uv {float u{},v{};};
struct Influence {std::uint32_t joint{};float weight{};};
struct MeshVertex {
    transform_math::Vector position{},normal{};
    Uv uv{};
    // Authored colors after source packing/normalization, before lighting.
    std::array<float,4> color{};
    std::vector<Influence> influences;
};
struct MeshTriangle {std::uint32_t a{},b{},c{},material{};};
// Admitted fields of the source F0000/1D29F0 object properties. Missing
// properties deliberately remain absent: the original retains prior state.
struct MeshRenderProfile {
    std::uint32_t format{},color_mode{};
    bool option_12{};
};
struct MeshPart {
    std::vector<MeshVertex> vertices;
    std::vector<MeshTriangle> triangles;
    std::optional<MeshRenderProfile> render_profile;
};
// Bounded NBD AMO data, with source physical-part ordinals preserved for the
// canonical SceneModels visibility/pose bank. No model or texture is invented.
struct ModelMesh {
    std::vector<MeshPart> parts;
    // Each material selects this authored model-local texture ordinal. Room
    // TID and embedded character TEX resolve that ordinal in different banks.
    std::vector<std::uint32_t> material_textures;
    static ModelMesh import(std::span<const std::byte>);
};
}
