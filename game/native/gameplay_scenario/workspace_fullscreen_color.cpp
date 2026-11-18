#include "workspace_fullscreen_color.hpp"
#include <cstring>
namespace reo::native::gameplay_scenario {
std::optional<FullscreenColorKey> WorkspaceFullscreenColor::key(std::size_t index)const noexcept{
    if(!current()||origin_>CutsceneDescriptorWorkspace::capacity||index>(CutsceneDescriptorWorkspace::capacity-origin_)/40)return{};
    const auto record=workspace_->record40(origin_+index*40);if(!record)return{};
    FullscreenColorKey result;std::memcpy(&result.frame,record->data()+2,2);std::memcpy(&result.kind,record->data()+4,4);
    std::memcpy(result.channels.data(),record->data()+8,8);return result;
}
} // namespace reo::native::gameplay_scenario
