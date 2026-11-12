#pragma once
#include "cutscene_descriptor.hpp"
#include "cutscene_descriptor_workspace.hpp"
#include "scenario_archive.hpp"
namespace reo::native::gameplay_world {struct Session;}
namespace reo::native::gameplay_scenario {
struct CutscenePlaybackState;
enum class CutsceneDescriptorLoadStatus {completed,busy,unavailable,invalid_asset,no_memory};
struct CutsceneDescriptorLoaded {
    CutsceneDescriptorLoadStatus status{CutsceneDescriptorLoadStatus::unavailable};
    // Complete5F15A0 returns1 for the early terminal and0 for the full tail.
    //5ED900 also returns1 on a missing read, without parsing or clearing tails.
    std::uint32_t value{};
    bool read{},parsed{};
};
// One retained descriptor workspace is borrowed by all scene-view consumers.
// The two loading modes use the same actual authored scenario namespace; the
// resident route resolves its basename through the current scenario _H index.
// Movie5EDA40 merging is a separate operation and is not inferred here.
class CutsceneDescriptorLoader final {
public:
    CutsceneDescriptorLoader(gameplay_world::Session&,const content::ScenarioArchive&,
                             std::shared_ptr<CutsceneDescriptorWorkspace>);
    CutsceneDescriptorLoader(const CutsceneDescriptorLoader&)=delete;
    CutsceneDescriptorLoader& operator=(const CutsceneDescriptorLoader&)=delete;
    CutsceneDescriptorLoaded load(CutscenePlaybackState&)noexcept;
    std::shared_ptr<const CutsceneDescriptor> descriptor()const noexcept{return descriptor_;}
    const std::shared_ptr<CutsceneDescriptorWorkspace>& workspace()const noexcept{return workspace_;}
    bool bound_to(const gameplay_world::Session& session)const noexcept{return &session_==&session;}
private:
    gameplay_world::Session& session_;const content::ScenarioArchive& archive_;
    std::shared_ptr<CutsceneDescriptorWorkspace> workspace_;
    std::shared_ptr<const CutsceneDescriptor> descriptor_;
    bool running_{};
};
} // namespace reo::native::gameplay_scenario
