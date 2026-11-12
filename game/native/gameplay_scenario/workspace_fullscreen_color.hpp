#pragma once
#include "cutscene_descriptor_workspace.hpp"
#include "fullscreen_color.hpp"
namespace reo::native::gameplay_scenario {
// Live typed lookahead over the single descriptor workspace, including the
// retained file tail and later typed event-frame consumption writes.
class WorkspaceFullscreenColor final:public FullscreenColorSource {
public:
    WorkspaceFullscreenColor(std::shared_ptr<const CutsceneDescriptorWorkspace> workspace,
                             std::size_t origin)noexcept:
        workspace_(std::move(workspace)),origin_(origin),generation_(workspace_?workspace_->generation():0){}
    std::optional<FullscreenColorKey> key(std::size_t)const noexcept override;
    bool current()const noexcept{return workspace_&&workspace_->generation()==generation_;}
private:
    std::shared_ptr<const CutsceneDescriptorWorkspace> workspace_;
    std::size_t origin_{};std::uint64_t generation_{};
};
} // namespace reo::native::gameplay_scenario
