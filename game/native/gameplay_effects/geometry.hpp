#pragma once
#include "../animation/model.hpp"
#include "tracks.hpp"
namespace reo::native::gameplay_effects {
struct MeshChannels {std::vector<std::uint32_t> indices;};
struct GeometryRoot {std::int16_t id{};std::vector<std::size_t> meshes;bool palette_admitted{};};
// Gameplay-facing resource metadata. Native render resources are a Stage5
// consumer; these are owned mesh ordinals and authored material-track indices.
class Geometry {
public:
    static std::shared_ptr<const Geometry> import_nbd(std::span<const std::byte>);
    std::span<const MeshChannels> meshes()const noexcept{return meshes_;}
    std::span<const GeometryRoot> roots()const noexcept{return roots_;}
    std::optional<std::size_t> resolve(std::int16_t id)const noexcept;
    const MeshChannels* material(std::size_t root,std::uint8_t slot)const noexcept;
private:
    std::vector<MeshChannels> meshes_;
    std::vector<GeometryRoot> roots_;
};
class MaterialTracks {
public:
    static std::shared_ptr<const MaterialTracks> import(std::span<const std::byte> efdata,const Geometry&);
    // The source only writes kind11 channels. Other slots retain prior values.
    void sample(const MeshChannels&,std::int16_t time,std::span<float> values)const;
    bool complete(const MeshChannels&)const noexcept;
private:
    struct Entry {std::uint32_t index{};std::optional<Curve> curve;};
    std::vector<Entry> entries_;
};
}
