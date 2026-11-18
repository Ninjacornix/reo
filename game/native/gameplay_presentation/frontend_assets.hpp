#pragma once
#include "font_face.hpp"
#include "texture.hpp"
#include <memory>
#include <span>
#include <vector>
namespace reo::assets {struct Source;}
namespace reo::native::gameplay_presentation {
// Shared result of the real 1D1FC0 resource-0 producer. The decoded texture
// and its original expanded byte storage remain alive for all borrowers.
class CommonFrontendTextures final {
public:
    explicit CommonFrontendTextures(std::vector<std::byte>);
    std::span<const std::byte> expanded()const noexcept{return bytes_;}
    const std::shared_ptr<const Texture>& loading_texture()const noexcept{return loading_texture_;}
private:
    std::vector<std::byte> bytes_;
    std::shared_ptr<const Texture> loading_texture_;
};
// Exact File1 default archive members used by 1B3D90 and 1D1FC0. A real
// archive source is required; malformed or unavailable assets throw.
class FrontendAssets final {
public:
    explicit FrontendAssets(std::shared_ptr<const reo::assets::Source>);
    FontFace load_font()const;
    std::shared_ptr<const CommonFrontendTextures> load_common_textures()const;
private:
    std::vector<std::byte> read(std::size_t ordinal,const char* name)const;
    std::shared_ptr<const reo::assets::Source> source_;
    std::uint64_t base_{},bytes_{};
};
}
