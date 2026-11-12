#include "cutscene_descriptor_loader.hpp"
#include "cutscene_playback.hpp"
#include <cstdio>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
CutsceneDescriptorLoader::CutsceneDescriptorLoader(gameplay_world::Session& session,
    const content::ScenarioArchive& archive,std::shared_ptr<CutsceneDescriptorWorkspace> workspace):
    session_(session),archive_(archive),workspace_(std::move(workspace)){
    if(!workspace_)throw std::invalid_argument("Native scene loader requires its retained descriptor workspace");
}
CutsceneDescriptorLoaded CutsceneDescriptorLoader::load(CutscenePlaybackState& state)noexcept{
    if(running_)return{CutsceneDescriptorLoadStatus::busy};
    running_=true;struct Reset{bool& running;~Reset(){running=false;}}reset{running_};
    CutsceneDescriptorLoaded result;
    try{
        if(session_.session_state!=1){
            const auto mode=session_.asset_loading_mode;
            if(!mode||!session_.scenario)return result;
            // Flags1 selects1AA480's DEFAULT romdata name catalogue. Its
            // owned1342 compiled keys contain no scene-DM namespace. A file
            // in the scenario archive cannot satisfy that distinct lookup.
            if(!*mode){result.status=CutsceneDescriptorLoadStatus::completed;result.value=1;return result;}
            std::array<char,128> name{};const auto cue=state.request.current;
            std::snprintf(name.data(),name.size(),"dm%02u%02u%c.bin",
                unsigned(cue.area),unsigned(cue.scene),int(cue.variant)+97);
            const auto bytes=archive_.read_resource_sectors(*session_.scenario,name.data());
            if(!bytes){result.status=CutsceneDescriptorLoadStatus::completed;result.value=1;return result;}
            const auto loaded=workspace_->load(*bytes);
            if(loaded!=DescriptorWorkspaceStatus::completed){
                result.status=loaded==DescriptorWorkspaceStatus::invalid_asset?CutsceneDescriptorLoadStatus::invalid_asset:CutsceneDescriptorLoadStatus::unavailable;
                return result;
            }
            result.read=true;descriptor_.reset();
        }
        if(workspace_->loaded().empty())return result;
        auto descriptor=CutsceneDescriptor::import(workspace_->loaded());
        state.loaded_identity=descriptor->identity();state.end_frame=descriptor->duration();
        state.light_groups=descriptor->extension_groups()?std::int16_t(descriptor->extension_groups()->size()):0;
        result.value=descriptor->tail_kind()==CutsceneTail::complete?0:1;
        descriptor_=std::move(descriptor);result.parsed=true;result.status=CutsceneDescriptorLoadStatus::completed;return result;
    }catch(const std::bad_alloc&){result.status=CutsceneDescriptorLoadStatus::no_memory;return result;}
    catch(...){result.status=CutsceneDescriptorLoadStatus::invalid_asset;return result;}
}
} // namespace reo::native::gameplay_scenario
