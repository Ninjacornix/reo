#pragma once
#include "scene_models.hpp"
#include "workspace_fullscreen_color.hpp"
namespace reo::native::gameplay_scenario {
struct CutscenePlaybackState;
struct RoomViewMasks {
    std::optional<std::uint32_t> first,second;
    // Actual5ECCA0 writes these before5ECF90 starts loading the scene.
    void begin_scene()noexcept{first=0;second=UINT32_MAX;}
    // Complete58FE80 visibility decision. The second source word's eventual
    // consumer remains numeric; it is never silently merged with this mask.
    std::optional<bool> visible(std::uint8_t channel)const noexcept{
        if(!first)return{};
        return (*first&(1u<<(channel&31u)))!=0;
    }
};
enum class CutsceneViewStatus {completed,unavailable,no_memory,invalid_asset};
struct CutsceneViewUpdated {
    CutsceneViewStatus status{CutsceneViewStatus::completed};
    std::size_t visited{},matched{},visibility_writes{},color_bindings{},consumed{};
};
// Complete5EF740 event owner. SceneModels is the existing canonical physical
// visibility bank; the caller retains that owner for this scene's lifetime.
class CutsceneViewControls final {
public:
    CutsceneViewControls(CutscenePlaybackState&,const std::uint8_t& clock_mode,
                         SceneModels&,RoomViewMasks&,FullscreenColor&)noexcept;
    CutsceneViewControls(const CutsceneViewControls&)=delete;
    CutsceneViewControls& operator=(const CutsceneViewControls&)=delete;
    CutsceneViewStatus install(std::shared_ptr<CutsceneDescriptorWorkspace>,std::size_t offset,std::size_t count)noexcept;
    CutsceneViewUpdated tick()noexcept;
    bool bound_to(const CutscenePlaybackState& state,const std::uint8_t& clock)const noexcept{
        return &state_==&state&&&clock_mode_==&clock;
    }
    void reset_color(std::uint32_t value)noexcept{color_.reset(value);}
    CutsceneViewStatus sample_color()noexcept{
        return color_.sample(frame())==FullscreenColorStatus::completed?CutsceneViewStatus::completed:CutsceneViewStatus::unavailable;
    }
private:
    std::uint32_t frame()const noexcept;
    CutscenePlaybackState& state_;const std::uint8_t& clock_mode_;
    SceneModels& models_;RoomViewMasks& masks_;FullscreenColor& color_;
    std::shared_ptr<CutsceneDescriptorWorkspace> workspace_;
    std::shared_ptr<const WorkspaceFullscreenColor> source_;
    std::size_t offset_{},count_{};std::uint64_t generation_{};bool installed_{};
};
} // namespace reo::native::gameplay_scenario
