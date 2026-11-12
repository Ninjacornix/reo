#include "game/native/gameplay_scenario/workspace_fullscreen_color.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <vector>
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},calls{},cases{},patches{},retained_tails{},stale_refusals{},owned_scenes{},owned_colors{},owned_samples{};unsigned current_case{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Descriptor workspace comparison case"+std::to_string(current_case));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    case 0x107c68:check(GPR_U32(context,4)==0x316600&&GPR_U32(context,5)==0&&GPR_U32(context,6)==24);std::fill_n(memory+0x316600,24,0);context->pc=GPR_U32(context,31);return;
    default:throw std::runtime_error("Unadmitted workspace fullscreen helper");}
}
std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
template<class T>void put(std::vector<std::byte>& bytes,std::size_t at,T value){std::memcpy(bytes.data()+at,&value,sizeof value);}
int main(int argc,char** argv){
    constexpr unsigned base=0x100000;s::FullscreenColorState state;s::FullscreenColor color(state);
    auto workspace=std::make_shared<s::CutsceneDescriptorWorkspace>();std::vector<std::uint8_t> memory(0x2000000);PS2Runtime runtime;std::uint32_t random=0x5ed900;
    const auto invoke=[&](unsigned address,unsigned a0=0){R5900Context context;context.pc=address;SET_GPR_U32(&context,4,a0);SET_GPR_U32(&context,29,0x700000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x700000);};
    for(std::size_t offset=0;offset+40<=s::CutsceneDescriptorWorkspace::capacity;offset+=40){const auto record=workspace->record40(offset);check(bool(record));for(auto value:*record)check(value==std::byte{});}
    std::shared_ptr<const s::WorkspaceFullscreenColor> previous;
    for(unsigned index=0;index<8192;++index){
        current_case=index;std::vector<std::byte> asset((index%3?3:64)*40);
        for(unsigned at=0;at<asset.size();++at)asset[at]=std::byte(random_word(random));
        for(unsigned record=0;record<asset.size()/40;++record){put(asset,record*40+2,std::uint16_t(random_word(random)));put(asset,record*40+4,record%5==0?2u:0u);}
        put(asset,2,std::uint16_t(10));put(asset,4,2u);
        if(index%37==0){check(workspace->clear_movie_prefix()==s::DescriptorWorkspaceStatus::completed);std::fill_n(memory.data()+base,s::CutsceneDescriptorWorkspace::movie_clear_bytes,0);}
        std::memcpy(memory.data()+base,asset.data(),asset.size());std::fill_n(memory.data()+base+asset.size(),4,255);
        check(workspace->load(asset)==s::DescriptorWorkspaceStatus::completed);check(workspace->loaded().size()==asset.size());
        if(previous){check(!previous->current()&&!previous->key(0));++stale_refusals;}
        auto reader=std::make_shared<s::WorkspaceFullscreenColor>(workspace,0);check(reader->current());
        for(unsigned record=0;record<32;++record){const auto source=workspace->record40(record*40);check(source&&std::memcmp(source->data(),memory.data()+base+record*40,40)==0);if(record*40>=asset.size())++retained_tails;}
        if(index%7==0){check(workspace->consume_frame(40,40));transform_write(memory.data(),base+42,std::uint16_t(65535));++patches;}
        invoke(0x1bbb10,0xff123456);color.reset(0xff123456);invoke(0x1bbb80,base);check(color.bind(reader,0)==s::FullscreenColorStatus::completed);
        const auto frame=random_word(random);transform_write(memory.data(),0x38eca8,frame);invoke(0x1bbba0);check(color.sample(frame)==s::FullscreenColorStatus::completed);check(std::memcmp(&state,memory.data()+0x316600,sizeof state)==0);
        previous=reader;++cases;
    }
    const auto generation=workspace->generation();const auto retained=workspace->record40(0);std::array<std::byte,40> saved;std::copy(retained->begin(),retained->end(),saved.begin());
    check(workspace->load({})==s::DescriptorWorkspaceStatus::invalid_asset&&workspace->generation()==generation);
    check(!workspace->consume_frame(1,40)&&!workspace->consume_frame(0,56)&&!workspace->consume_frame(workspace->loaded().size(),40));
    check(std::memcmp(workspace->record40(0)->data(),saved.data(),40)==0);check(!workspace->record40(s::CutsceneDescriptorWorkspace::capacity-39));
    auto invalid=std::make_shared<s::WorkspaceFullscreenColor>(workspace,s::CutsceneDescriptorWorkspace::capacity);check(!invalid->key(0));
    if(argc==3){
        struct Row{std::uint64_t offset;std::uint32_t length,secondary,count;};std::vector<Row> rows;std::ifstream manifest(argv[2]);check(bool(manifest));Row row;
        while(manifest>>row.offset>>row.length>>row.secondary>>row.count)rows.push_back(row);
        check(manifest.eof()&&rows.size()==1097);
        reo::assets::Source source(argv[1]);workspace=std::make_shared<s::CutsceneDescriptorWorkspace>();std::fill_n(memory.data()+base,s::CutsceneDescriptorWorkspace::capacity,0);
        for(const auto& entry:rows){
            current_case=100000+unsigned(owned_scenes);std::vector<std::byte> asset(entry.length);source.read(entry.offset,entry.length,asset.data());
            check(workspace->load(asset)==s::DescriptorWorkspaceStatus::completed);std::memcpy(memory.data()+base,asset.data(),asset.size());std::fill_n(memory.data()+base+asset.size(),4,255);
            auto reader=std::make_shared<s::WorkspaceFullscreenColor>(workspace,entry.secondary);
            for(unsigned index=0;index<entry.count;++index){
                const auto key=reader->key(index);check(bool(key));if(key->kind!=2||key->frame==65535)continue;
                ++owned_colors;
                for(unsigned frame:{unsigned(key->frame),unsigned(key->frame)+1u,unsigned(key->frame)+17u}){
                    invoke(0x1bbb10,0xff123456);color.reset(0xff123456);invoke(0x1bbb80,base+entry.secondary+index*40);check(color.bind(reader,index)==s::FullscreenColorStatus::completed);
                    transform_write(memory.data(),0x38eca8,frame);invoke(0x1bbba0);check(color.sample(frame)==s::FullscreenColorStatus::completed);check(std::memcmp(&state,memory.data()+0x316600,sizeof state)==0);++owned_samples;
                }
            }
            ++owned_scenes;
        }
        check(owned_scenes==1097&&owned_colors>4056&&owned_samples==owned_colors*3);
    }else check(argc==1);
    std::cout<<"{\"owned_scenes\":"<<owned_scenes<<",\"owned_color_keys\":"<<owned_colors<<",\"owned_samples\":"<<owned_samples<<",\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"consumed_frames\":"<<patches<<",\"retained_tail_records\":"<<retained_tails<<",\"stale_refusals\":"<<stale_refusals<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}
