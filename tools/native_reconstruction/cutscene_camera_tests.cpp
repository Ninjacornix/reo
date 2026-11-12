#include "game/native/gameplay_scenario/cutscene_camera.hpp"
#include "game/native/gameplay_scenario/cutscene_playback.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <vector>
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},calls{},ticks{},fog_calls{},selections{},bindings{};
unsigned current_case{},current_tick{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Camera selector comparison case"+std::to_string(current_case)+" tick"+std::to_string(current_tick));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;if(context->pc==0x6b2200)++fog_calls;
    switch(context->pc){
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted camera selector helper");}
}
std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
template<class T>void put(std::vector<std::byte>& bytes,std::size_t at,T value){std::memcpy(bytes.data()+at,&value,sizeof value);}
std::uint32_t address(std::size_t group,std::size_t stream,std::size_t record){return 0x12000u+std::uint32_t(group)*0x1000u+std::uint32_t(stream)*0x400u+std::uint32_t(record)*56u;}
int main(){
    std::vector<std::uint8_t> memory(0x2000000);PS2Runtime runtime;std::uint32_t random=0x5ee950;
    for(unsigned serial=0;serial<2048;++serial){
        current_case=serial;current_tick=0;s::CutscenePlaybackState state;state.camera_selection=std::uint8_t(serial%4);state.camera_ended=std::uint8_t(serial%5==0?3:serial%7==0?255:0);
        s::Fog fog({});std::array<std::byte,4> invalid_version{};check(fog.import_fog(invalid_version)==s::FogStatus::unsupported_version);
        s::CutsceneCamera camera(state,fog,{});check(camera.bound_to(state));s::CutscenePlaybackState foreign;check(!camera.bound_to(foreign));
        std::vector<std::byte> selection(5*16);std::array<std::array<std::vector<std::byte>,2>,4> records;
        std::array<std::array<std::span<const std::byte>,2>,4> spans;
        for(unsigned index=0;index<5;++index){
            put(selection,index*16+2,std::uint16_t(index==4?65535:index*30));
            put(selection,index*16+4,std::uint16_t((random_word(random)&0xff00u)|(random_word(random)%4)));
            put(selection,index*16+12,std::uint8_t(random_word(random)));
        }
        for(unsigned group=0;group<4;++group)for(unsigned stream=0;stream<2;++stream){
            auto& bytes=records[group][stream];bytes.resize(6*56);
            for(unsigned record=0;record<6;++record){
                put(bytes,record*56+1,std::uint8_t(serial%3==0?stream:random_word(random)%3));
                put(bytes,record*56+2,std::uint16_t(record==5?65535:record*10+group*2));
                for(unsigned at=4;at<56;at+=4)put(bytes,record*56+at,random_word(random));
            }
            spans[group][stream]=bytes;std::memcpy(memory.data()+address(group,stream,0),bytes.data(),bytes.size());
            transform_write(memory.data(),0x3900a0+group*8+stream*4,address(group,stream,0));
        }
        auto prepared=s::PreparedCameraTracks::import(selection,spans);check(camera.install(prepared)==s::CutsceneCameraStatus::completed);
        std::memcpy(memory.data()+0x10000,selection.data(),selection.size());
        transform_write(memory.data(),0x7434c8,0x38eca0u);transform_write(memory.data(),0x3901a8,0x10000u);
        transform_write(memory.data(),0x38ecc4,state.camera_selection);transform_write(memory.data(),0x38ecc5,state.camera_ended);
        transform_write(memory.data(),0x3240bd,std::uint8_t(255));transform_write(memory.data(),0x38ec90,0u);transform_write(memory.data(),0x38ec94,0u);
        const auto mode=std::uint8_t(serial%5==0?0:serial%5==1?1:serial%5==2?2:serial%5==3?31:255);transform_write(memory.data(),0x3243cc,mode);
        for(unsigned tick=0;tick<128;++tick){
            current_tick=tick;state.frame=std::uint32_t(tick)+(serial%2?0x12340000u:0u);transform_write(memory.data(),0x38eca8,state.frame);
            R5900Context context;context.pc=0x5ee950;SET_GPR_U32(&context,29,0x700000);SET_GPR_U32(&context,31,0xabcdef);
            original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x700000);
            check(camera.select(mode)==s::CutsceneCameraStatus::completed);
            check(state.camera_selection==memory[0x38ecc4]&&state.camera_ended==memory[0x38ecc5]);
            check(std::uint8_t(fog.state().selected)==memory[0x3240bd]);
            const auto position=camera.selection_cursor();check(transform_read<std::uint32_t>(memory.data(),0x3901a8)==(position?0x10000u+std::uint32_t(*position)*16u:0u));
            for(unsigned group=0;group<4;++group)for(unsigned stream=0;stream<2;++stream){const auto cursor=camera.cursor(group,stream);check(transform_read<std::uint32_t>(memory.data(),0x3900a0+group*8+stream*4)==(cursor?address(group,stream,*cursor):0u));}
            for(unsigned index=0;index<2;++index){const auto bound=camera.bindings()[index];check(transform_read<std::uint32_t>(memory.data(),0x38ec90+index*4)==(bound?address(bound->group,bound->stream,bound->record):0u));if(bound)++bindings;}
            ++ticks;
        }
        ++selections;
        check(camera.install(nullptr)==s::CutsceneCameraStatus::completed);check(camera.select(mode)==s::CutsceneCameraStatus::unavailable);check(!camera.sample());
    }
    {
        s::CutscenePlaybackState state;s::Fog fog({});s::CutsceneCamera camera(state,fog,{});
        check(camera.install(s::PreparedCameraTracks::import({},{}))==s::CutsceneCameraStatus::completed);
        std::fill_n(memory.data()+0x3900a0,32*8,0);transform_write(memory.data(),0x3901a8,0u);
        for(unsigned selected:{0u,1u,31u}){
            state.camera_selection=std::uint8_t(selected);transform_write(memory.data(),0x38ecc4,state.camera_selection);
            R5900Context context;context.pc=0x5ee950;SET_GPR_U32(&context,29,0x700000);SET_GPR_U32(&context,31,0xabcdef);
            original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef);
            check(camera.select(0)==s::CutsceneCameraStatus::completed&&!camera.sample());
        }
        state.camera_selection=255;check(camera.select(0)==s::CutsceneCameraStatus::unavailable);
        std::array<std::byte,16> truncated_selection{};bool refused{};
        try{(void)s::PreparedCameraTracks::import(truncated_selection,{});}catch(const std::invalid_argument&){refused=true;}check(refused);
        check(camera.selection_cursor()==std::nullopt);
    }
    std::cout<<"{\"checks\":"<<checks<<",\"fixtures\":"<<selections<<",\"ticks\":"<<ticks<<",\"bound_visits\":"<<bindings<<",\"fog_calls\":"<<fog_calls<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}
