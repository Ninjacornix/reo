#include "game/native/gameplay_scenario/cutscene_view_controls.hpp"
#include "game/native/gameplay_scenario/cutscene_playback.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <vector>
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},calls{},cases{},visibility_writes{},color_bindings{},consumed{},mask_gates{};unsigned current_case{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Cutscene view comparison case"+std::to_string(current_case));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    case 0x107c68:check(GPR_U32(context,4)==0x316600&&GPR_U32(context,5)==0&&GPR_U32(context,6)==24);std::fill_n(memory+0x316600,24,0);context->pc=GPR_U32(context,31);return;
    default:throw std::runtime_error("Unadmitted cutscene view helper");}
}
std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
template<class T>void put(std::vector<std::byte>& bytes,std::size_t at,T value){std::memcpy(bytes.data()+at,&value,sizeof value);}
int main(){
    std::vector<std::uint8_t> memory(0x2000000);PS2Runtime runtime;std::uint32_t random=0x5ef740;
    const auto invoke=[&](unsigned address,unsigned a0=0){R5900Context context;context.pc=address;SET_GPR_U32(&context,4,a0);SET_GPR_U32(&context,29,0x700000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x700000);};
    for(unsigned serial=0;serial<2048;++serial){
        current_case=serial;s::SceneModelState initial;for(unsigned slot=0;slot<128;++slot){initial.visibility[slot]=std::uint8_t(random_word(random));initial.styles[slot]=random_word(random);}
        s::RoomModelRemap remap{};s::SceneModels models(initial,remap);s::RoomViewMasks masks{random_word(random),random_word(random)};
        s::FullscreenColorState color_state;s::FullscreenColor color(color_state);s::CutscenePlaybackState state;auto mode=std::uint8_t(serial%3==0?0:serial%3==1?1:255);
        s::CutsceneViewControls controls(state,mode,models,masks,color);check(controls.tick().status==s::CutsceneViewStatus::unavailable);
        auto workspace=std::make_shared<s::CutsceneDescriptorWorkspace>();const auto count=std::array<unsigned,9>{0,1,2,4,17,127,255,256,257}[serial%9];std::vector<std::byte> asset(std::max(1u,count)*40);
        state.frame=(serial%2?0x12340000u:0u)+serial%128;
        for(unsigned index=0;index<count;++index){
            for(unsigned at=0;at<40;++at)asset[index*40+at]=std::byte(random_word(random));
            put(asset,index*40+2,std::uint16_t(index%3?std::uint16_t(state.frame)+(index%2):random_word(random)));
            put(asset,index*40+4,std::array<unsigned,5>{0,1,2,3,0xffffffffu}[(index+serial)%5]);
        }
        check(workspace->load(asset)==s::DescriptorWorkspaceStatus::completed&&controls.install(workspace,0,count)==s::CutsceneViewStatus::completed);
        constexpr unsigned base=0x100000;std::fill_n(memory.data()+base,s::CutsceneDescriptorWorkspace::capacity,0);std::memcpy(memory.data()+base,asset.data(),asset.size());std::fill_n(memory.data()+base+asset.size(),4,255);
        std::memcpy(memory.data()+0x49f790,initial.visibility.data(),128);std::memcpy(memory.data()+0x49f810,initial.styles.data(),512);
        transform_write(memory.data(),0x3dddcc,*masks.first);transform_write(memory.data(),0x3dddd0,*masks.second);
        transform_write(memory.data(),0x7434c8,0x38eca0u);transform_write(memory.data(),0x3901c0,base);transform_write(memory.data(),0x38ecba,std::uint16_t(count));transform_write(memory.data(),0x3243cc,mode);
        invoke(0x1bbb10,0xff123456);color.reset(0xff123456);
        for(unsigned tick=0;tick<4;++tick){
            transform_write(memory.data(),0x38eca8,state.frame);invoke(0x5ef740);const auto result=controls.tick();check(result.status==s::CutsceneViewStatus::completed&&result.visited==count);
            visibility_writes+=result.visibility_writes;color_bindings+=result.color_bindings;consumed+=result.consumed;
            check(std::memcmp(models.state().visibility.data(),memory.data()+0x49f790,128)==0&&std::memcmp(models.state().styles.data(),memory.data()+0x49f810,512)==0);
            check(*masks.first==transform_read<unsigned>(memory.data(),0x3dddcc)&&*masks.second==transform_read<unsigned>(memory.data(),0x3dddd0));
            check(bool(color.binding())==bool(transform_read<unsigned>(memory.data(),0x38eb10)));
            invoke(0x1bbba0);check(color.sample(state.frame)==s::FullscreenColorStatus::completed&&color_state.rectangle.color==transform_read<unsigned>(memory.data(),0x316614));
            check(std::memcmp(workspace->loaded().data(),memory.data()+base,asset.size())==0);++state.frame;
        }
        for(unsigned tag=0;tag<256;++tag){transform_write(memory.data(),0xc00030,std::uint8_t(tag));invoke(0x58fe80,0xc00000);check(masks.visible(std::uint8_t(tag))==bool(memory[0xc00001]));++mask_gates;}
        check(controls.install(workspace,1,0)==s::CutsceneViewStatus::invalid_asset);
        check(workspace->load(asset)==s::DescriptorWorkspaceStatus::completed&&controls.tick().status==s::CutsceneViewStatus::unavailable);
        check(controls.install({},0,0)==s::CutsceneViewStatus::completed&&controls.tick().status==s::CutsceneViewStatus::completed);
        ++cases;
    }
    s::RoomViewMasks unknown;check(!unknown.visible(0)&&!unknown.visible(255));
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"visibility_writes\":"<<visibility_writes<<",\"color_bindings\":"<<color_bindings<<",\"consumed_frames\":"<<consumed<<",\"mask_gates\":"<<mask_gates<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}
