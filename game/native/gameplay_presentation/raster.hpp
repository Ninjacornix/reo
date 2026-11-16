#pragma once
#include "texture.hpp"
#include "../gameplay_scenario/camera_projection.hpp"
#include <span>
#include <optional>
#include <vector>

namespace reo::native::gameplay_scenario { struct FogState; }
namespace reo::native::gameplay_presentation {
class FontFace;
struct FontGlyph;
// Color is a normalized authored vertex value. The default is deliberately
// white for callers whose lighting comes from a different source owner.
struct SurfaceVertex {transform_math::Vector world;float u{},v{};std::array<float,4> color{1,1,1,1};};
struct RasterFog {float near_distance{},far_distance{};std::array<std::uint8_t,3> color{};};
// 6B1660's reached fog publication, without borrowing or mutating the owner.
std::optional<RasterFog> prepare_scene_fog(const gameplay_scenario::FogState&)noexcept;
// Bounded finite VU fog-factor profile, expressed in native positive clip W.
std::optional<std::uint8_t> fog_factor(float clip_w,const RasterFog&)noexcept;
// CPU presentation consumes the actual CameraDisplayBinding callbacks and
// actual model vertices/textures. It owns pixels only, never gameplay state.
class Raster final:public gameplay_scenario::CameraDisplaySink {
public:
    Raster(std::uint32_t width,std::uint32_t height);
    void viewport(const gameplay_scenario::CameraViewport&,const gameplay_scenario::CameraProjectionMatrices&)override;
    void view(const transform_math::Matrix&)override;
    bool ready()const noexcept{return has_view_&&has_projection_;}
    bool global_alpha(float)noexcept;
    // A bounded CPU fog profile. nullopt disables fog for the following draw.
    bool fog(std::optional<RasterFog>)noexcept;
    void clear(std::uint32_t argb=0xff000000u)noexcept;
    void triangle(const SurfaceVertex&,const SurfaceVertex&,const SurfaceVertex&,const Texture&);
    // The resident font's 20x20 indexed bitmap, including its offset shadow.
    // Native CPU sampling is nearest-neighbor; GS filtering is not emulated.
    bool text(const FontFace&,std::span<const FontGlyph>)noexcept;
    //1ABB60's logical 640x448 rectangle, composited into this CPU surface.
    void rectangle(std::int32_t x,std::int32_t y,std::int32_t width,std::int32_t height,std::uint32_t argb)noexcept;
    std::span<const std::uint32_t> pixels()const noexcept{return pixels_;} // BGRA, top-to-bottom
    std::uint32_t width()const noexcept{return width_;}
    std::uint32_t height()const noexcept{return height_;}
private:
    std::uint32_t width_,height_;
    std::vector<std::uint32_t> pixels_;
    std::vector<float> depth_;
    transform_math::Matrix projection_{},view_{};
    float global_alpha_{1};
    std::optional<RasterFog> fog_;
    std::uint32_t font_emitted_{};
    bool has_view_{},has_projection_{};
};
}
