#pragma once
#include "raster.hpp"
#include "background.hpp"
#include "graphics_state.hpp"
#include "model_mesh.hpp"
#include "model_textures.hpp"
#include "font_face.hpp"
#include "../gameplay_application/session_rooms.hpp"
#include "../gameplay_world/actor_assets.hpp"
#include "../gameplay_world/resource_static_assets.hpp"
#include <map>

namespace reo::native::gameplay_application {struct FrontendLetterbox;}
namespace reo::native::gameplay_scenario {struct DisplayFadeState;}
namespace reo::native::gameplay_presentation {
// The first matrix published by 3724F0 for an admitted rigid resource model.
// The model must retain its canonical, nonempty static pose bank.
transform_math::Matrix resource_model_matrix(const gameplay_world::ResourceModel&);
// One room-scoped native display. Session, rooms and the real process window
// outlive this owner; close unbinds the camera before those borrowed owners.
class SessionPresentation final {
public:
    SessionPresentation(gameplay_application::NativeSession&,gameplay_application::SessionRooms&,void* window,
        const BackgroundState&,gameplay_scenario::CameraProjectionContext,std::int8_t display_mode,std::uint32_t width,std::uint32_t height,
        const GraphicsState* = nullptr,const FontFace* = nullptr,const FrontendTextGate* = nullptr,
        const gameplay_scenario::DisplayFadeState* = nullptr,const gameplay_application::FrontendLetterbox* = nullptr);
    ~SessionPresentation();
    SessionPresentation(const SessionPresentation&)=delete;
    SessionPresentation& operator=(const SessionPresentation&)=delete;
    bool present();
    gameplay_application::SessionStatus close()noexcept;
    // Most recently presented CPU image, available for host diagnostics.
    std::span<const std::uint32_t> pixels()const noexcept{return raster_.pixels();}
    std::size_t actor_parts_submitted()const noexcept{return actor_parts_submitted_;}
    std::size_t resource_models_submitted()const noexcept{return resource_models_submitted_;}
private:
    struct ActorResources {
        std::shared_ptr<const gameplay_world::ActorModelAsset> asset;
        ModelMesh mesh;
        std::vector<Texture> textures;
        std::vector<transform_math::Matrix> inverse_bind;
    };
    ActorResources& actor_resources(const std::shared_ptr<const gameplay_world::ActorModelAsset>&);
    struct ResourceGeometry {
        std::shared_ptr<const gameplay_world::ResourceStaticAssets> asset;
        ModelMesh mesh;
        std::vector<Texture> textures;
    };
    ResourceGeometry& resource_geometry(const std::shared_ptr<const gameplay_world::ResourceStaticAssets>&);
    gameplay_application::NativeSession& session_;
    const BackgroundState& background_;
    const GraphicsState* graphics_{};
    const FontFace* font_{};
    const FrontendTextGate* text_gate_{};
    const gameplay_scenario::DisplayFadeState* display_fade_{};
    const gameplay_application::FrontendLetterbox* letterbox_{};
    void* window_{};
    Raster raster_;
    std::int8_t mode_{};
    gameplay_scenario::CameraProjectionContext context_;
    gameplay_scenario::CameraDisplayState display_state_;
    gameplay_scenario::CameraDisplayBinding binding_;
    std::shared_ptr<const gameplay_scenario::RoomSceneInput> room_input_;
    std::shared_ptr<const gameplay_scenario::RoomModelAsset> room_asset_;
    ModelMesh room_mesh_;
    std::vector<Texture> room_textures_;
    std::map<const gameplay_world::ActorModelAsset*,ActorResources> actor_cache_;
    std::map<const gameplay_world::ResourceStaticAssets*,ResourceGeometry> resource_cache_;
    std::size_t actor_parts_submitted_{};
    std::size_t resource_models_submitted_{};
    bool closed_{};
};
}
