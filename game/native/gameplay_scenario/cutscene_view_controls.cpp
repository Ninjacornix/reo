#include "cutscene_view_controls.hpp"
#include "cutscene_playback.hpp"
#include <cstring>
namespace reo::native::gameplay_scenario {
namespace {
template<class T>T field(std::span<const std::byte,40> bytes,std::size_t at)noexcept{T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;}
}
CutsceneViewControls::CutsceneViewControls(CutscenePlaybackState& state,const std::uint8_t& mode,
    SceneModels& models,RoomViewMasks& masks,FullscreenColor& color)noexcept:
    state_(state),clock_mode_(mode),models_(models),masks_(masks),color_(color){}
std::uint32_t CutsceneViewControls::frame()const noexcept{return state_.frame;}
CutsceneViewStatus CutsceneViewControls::install(std::shared_ptr<CutsceneDescriptorWorkspace> workspace,
                                               std::size_t offset,std::size_t count)noexcept{
    if(!workspace){
        if(offset||count)return CutsceneViewStatus::invalid_asset;
        workspace_.reset();source_.reset();offset_=count_=0;generation_=0;installed_=true;return CutsceneViewStatus::completed;
    }
    if(offset%4||offset>workspace->loaded().size()||count>32767||count>(workspace->loaded().size()-offset)/40)return CutsceneViewStatus::invalid_asset;
    try{
        auto source=std::make_shared<WorkspaceFullscreenColor>(workspace,offset);generation_=workspace->generation();
        source_=std::move(source);workspace_=std::move(workspace);offset_=offset;count_=count;installed_=true;return CutsceneViewStatus::completed;
    }catch(const std::bad_alloc&){return CutsceneViewStatus::no_memory;}
}
CutsceneViewUpdated CutsceneViewControls::tick()noexcept{
    CutsceneViewUpdated result;if(!installed_){result.status=CutsceneViewStatus::unavailable;return result;}
    if(!workspace_)return result;
    if(workspace_->generation()!=generation_){result.status=CutsceneViewStatus::unavailable;return result;}
    for(std::size_t index=0;index<count_;++index){
        ++result.visited;const auto record=workspace_->record40(offset_+index*40);
        if(!record){result.status=CutsceneViewStatus::unavailable;return result;}
        const auto frame=field<std::uint16_t>(*record,2),current=std::uint16_t(state_.frame);
        if(clock_mode_?(frame>>1)!=(current>>1):frame!=current)continue;
        ++result.matched;const auto kind=field<std::uint32_t>(*record,4);
        if(kind==1){
            for(unsigned row=0;row<8;++row){const auto mask=field<std::uint16_t>(*record,8+2*row);
                for(unsigned column=0;column<16;++column){models_.mark_slot_byte(std::uint8_t(row*16+column),std::uint8_t((mask>>column)&1u));++result.visibility_writes;}}
            masks_.first=field<std::uint32_t>(*record,24);masks_.second=field<std::uint32_t>(*record,28);
        }
        if(kind==0||kind==1){
            if(!workspace_->consume_frame(offset_+index*40,40)){result.status=CutsceneViewStatus::unavailable;return result;}
            ++result.consumed;
        }else if(kind==2){
            if(color_.bind(source_,index)!=FullscreenColorStatus::completed){result.status=CutsceneViewStatus::unavailable;return result;}
            ++result.color_bindings;
        }
    }
    return result;
}
} // namespace reo::native::gameplay_scenario
