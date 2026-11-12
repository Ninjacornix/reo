#include "game/native/gameplay_scenario/cutscene_camera.hpp"
#include "game/native/gameplay_scenario/cutscene_descriptor.hpp"
#include "game/native/gameplay_scenario/cutscene_playback.hpp"
#include "runtime/assets/virtual_afs.h"
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <source_location>
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},descriptors{},streams{},keys{},ticks{},samples{},retained{};
void check(bool value,std::source_location where=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Camera asset check line"+std::to_string(where.line()));
}
template<class T>T field(std::span<const std::byte> bytes,std::size_t at){T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;}
int main(int argc,char** argv)try{
    check(argc==3);auto source=std::make_shared<reo::assets::Source>(argv[1]);std::ifstream manifest(argv[2]);check(bool(manifest));
    std::uint64_t offset{};std::uint32_t length{};
    while(manifest>>offset>>length){
        std::vector<std::byte> bytes(length);source->read(offset,length,bytes.data());auto descriptor=s::CutsceneDescriptor::import(bytes);
        auto prepared=s::prepare_camera_tracks(*descriptor);check(prepared->streams().size()==descriptor->camera_streams().size());
        const auto selection=descriptor->section(descriptor->camera_selection());check(selection.size()==prepared->selection().size()*16);
        for(std::size_t index=0;index<prepared->selection().size();++index){const auto& value=prepared->selection()[index];check(value.frame==field<std::uint16_t>(selection,index*16+2)&&value.camera==field<std::int16_t>(selection,index*16+4)&&value.fog==field<std::uint8_t>(selection,index*16+12));}
        for(std::size_t group=0;group<prepared->streams().size();++group)for(unsigned stream=0;stream<2;++stream){
            const auto raw=descriptor->section(descriptor->camera_streams()[group][stream]);const auto& track=prepared->streams()[group][stream];check(raw.size()==track.size()*56);++streams;
            for(std::size_t index=0;index<track.size();++index){const auto row=raw.subspan(index*56,56);const auto& value=track[index];
                check(value.type==field<std::uint8_t>(row,1)&&value.frame==field<std::uint16_t>(row,2));
                check(std::memcmp(&value.point,row.data()+4,12)==0&&std::memcmp(&value.control,row.data()+28,12)==0);
                check(std::memcmp(&value.lens,row.data()+20,4)==0&&std::memcmp(&value.roll_control,row.data()+48,4)==0&&std::memcmp(&value.lens_control,row.data()+52,4)==0&&value.roll==field<std::uint32_t>(row,24));++keys;
            }
        }
        const auto duration=descriptor->duration();check(duration<65535);descriptor.reset();bytes.clear();bytes.shrink_to_fit();++retained;
        for(std::uint8_t clock:{0,1}){
            s::CutscenePlaybackState state;s::Fog fog({});std::array<std::byte,4> ignored{};check(fog.import_fog(ignored)==s::FogStatus::unsupported_version);
            const s::CameraParameters initial{{{0,0,500},{0,0,0},{0,1,0},0},50000,1,27};s::CutsceneCamera camera(state,fog,initial);check(camera.install(prepared)==s::CutsceneCameraStatus::completed);
            for(;state.frame<duration;state.frame+=clock?2u:1u){
                check(camera.select(clock)==s::CutsceneCameraStatus::completed);++ticks;
                if(camera.sample()){
                    const auto view=s::camera_view(camera.parameters().pose);for(const auto& axis:view)for(float value:axis)check(std::isfinite(value));
                    check(std::isfinite(camera.parameters().lens)&&camera.parameters().near_plane==initial.near_plane&&camera.parameters().far_plane==initial.far_plane);++samples;
                }
            }
            camera.clear_bindings();check(!camera.sample());check(camera.install(nullptr)==s::CutsceneCameraStatus::completed&&camera.select(clock)==s::CutsceneCameraStatus::unavailable);
        }
        ++descriptors;
    }
    check(manifest.eof()&&descriptors==548&&streams==1092&&keys==2833&&retained==548&&ticks>100000);
    std::cout<<"{\"checks\":"<<checks<<",\"descriptors\":"<<descriptors<<",\"streams\":"<<streams<<",\"keys\":"<<keys<<",\"ticks\":"<<ticks<<",\"samples\":"<<samples<<",\"retained_assets\":"<<retained<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
