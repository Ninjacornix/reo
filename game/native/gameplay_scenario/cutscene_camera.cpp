#include "cutscene_camera.hpp"
#include "cutscene_playback.hpp"
#include <bit>
#include <cstring>
#include <stdexcept>

namespace reo::native::gameplay_scenario {
namespace {
template<class T>T field(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Native camera record outside retained asset");
    T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;
}
CameraKey key(std::span<const std::byte> bytes){
    CameraKey value;value.type=field<std::uint8_t>(bytes,1);value.frame=field<std::uint16_t>(bytes,2);
    value.point=field<transform_math::Vector>(bytes,4);value.lens=field<float>(bytes,20);
    value.roll=field<std::uint32_t>(bytes,24);value.control=field<transform_math::Vector>(bytes,28);
    value.roll_control=field<float>(bytes,48);value.lens_control=field<float>(bytes,52);return value;
}
bool due(std::uint16_t key_frame,std::uint32_t frame,std::uint8_t mode)noexcept{
    const auto current=std::uint16_t(frame);return mode?(key_frame>>1)==(current>>1):key_frame==current;
}
}
std::shared_ptr<const PreparedCameraTracks> PreparedCameraTracks::import(std::span<const std::byte> selection,
    std::span<const std::array<std::span<const std::byte>,2>> streams){
    if(streams.size()>32||selection.size()%16||selection.size()/16>65536)
        throw std::invalid_argument("Native camera track profile exceeded");
    auto result=std::shared_ptr<PreparedCameraTracks>(new PreparedCameraTracks);
    for(std::size_t at=0;at<selection.size();at+=16){
        CameraSelectionKey value{field<std::uint16_t>(selection,at+2),field<std::int16_t>(selection,at+4),field<std::uint8_t>(selection,at+12)};
        const auto narrowed=std::bit_cast<std::int8_t>(std::uint8_t(value.camera));
        if(value.frame!=65535&&(narrowed<0||std::size_t(narrowed)>=streams.size()))
            throw std::invalid_argument("Native camera selection outside authored groups");
        result->selection_.push_back(value);
    }
    if(!result->selection_.empty()&&result->selection_.back().frame!=65535)
        throw std::invalid_argument("Native camera selection lacks terminal");
    result->streams_.resize(streams.size());
    std::size_t total{};
    for(std::size_t group=0;group<streams.size();++group)for(unsigned stream=0;stream<2;++stream){
        const auto bytes=streams[group][stream];
        if(bytes.size()%56||bytes.size()/56>65536-total)throw std::invalid_argument("Native camera stream extent exceeded");
        total+=bytes.size()/56;auto& output=result->streams_[group][stream];
        for(std::size_t at=0;at<bytes.size();at+=56)output.push_back(key(bytes.subspan(at,56)));
        if(!output.empty()&&output.back().frame!=65535)throw std::invalid_argument("Native camera stream lacks terminal");
    }
    return result;
}
CutsceneCamera::CutsceneCamera(CutscenePlaybackState& state,Fog& fog,CameraParameters& initial) noexcept:
    state_(state),fog_(fog),parameters_(initial){}
CutsceneCameraStatus CutsceneCamera::install(std::shared_ptr<const PreparedCameraTracks> prepared) noexcept{
    try{
        std::vector<std::array<std::optional<std::size_t>,2>> positions(prepared?prepared->streams().size():0);
        if(prepared)for(std::size_t group=0;group<positions.size();++group)for(unsigned stream=0;stream<2;++stream)
            if(!prepared->streams()[group][stream].empty())positions[group][stream]=0;
        positions_=std::move(positions);tracks_=std::move(prepared);bindings_={};
        selection_=tracks_&&!tracks_->selection().empty()?std::optional<std::size_t>(0):std::nullopt;
        return CutsceneCameraStatus::completed;
    }catch(const std::bad_alloc&){return CutsceneCameraStatus::no_memory;}
}
std::optional<std::size_t> CutsceneCamera::cursor(std::size_t group,std::size_t stream)const noexcept{
    return group<positions_.size()&&stream<2?positions_[group][stream]:std::nullopt;
}
CutsceneCameraStatus CutsceneCamera::select(std::uint8_t mode) noexcept{
    if(!tracks_)return CutsceneCameraStatus::unavailable;
    if(selection_){
        const auto& selection=tracks_->selection()[*selection_];
        if(state_.camera_ended==3||due(selection.frame,state_.frame,mode)){
            state_.camera_ended=0;
            if(selection.frame==65535)selection_.reset();
            else{
                if(fog_.select(selection.fog)!=FogStatus::completed)return CutsceneCameraStatus::unavailable;
                state_.camera_selection=std::uint8_t(selection.camera);++*selection_;
            }
        }
    }
    // A null selection cursor still visits the currently selected streams.
    const auto signed_group=std::bit_cast<std::int8_t>(state_.camera_selection);
    if(signed_group<0||signed_group>=32)return CutsceneCameraStatus::unavailable;
    if(std::size_t(signed_group)>=positions_.size())return CutsceneCameraStatus::completed;
    const auto group=std::size_t(signed_group);
    for(unsigned stream=0;stream<2;++stream)if(auto& position=positions_[group][stream]){
        const auto& keys=tracks_->streams()[group][stream];const auto& current=keys[*position];
        if(due(current.frame,state_.frame,mode)){
            if(*position+1>=keys.size())return CutsceneCameraStatus::unavailable;
            bindings_[current.type==0?0:1]=CameraKeyLocation{group,stream,*position};++*position;
            if(keys[*position].frame==65535){position.reset();state_.camera_ended|=std::uint8_t(1u<<stream);}
        }
    }
    return CutsceneCameraStatus::completed;
}
bool CutsceneCamera::sample() noexcept{
    std::array<std::optional<CameraSegment>,2> segments;
    for(unsigned index=0;index<2;++index)if(const auto& binding=bindings_[index]){
        const auto& stream=tracks_->streams()[binding->group][binding->stream];
        segments[index]=CameraSegment{stream[binding->record],stream[binding->record+1]};
    }
    return sample_camera_parameters(parameters_,segments[0],segments[1],state_.frame);
}
} // namespace reo::native::gameplay_scenario
