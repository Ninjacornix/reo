#include "reference.hpp"
#include "functions.h"
#include "game/native/gameplay_presentation/model_mesh.hpp"
#include <algorithm>
#include <array>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

struct Selector {std::uint32_t id{},value{};};
static std::vector<Selector> selectors;
void original_transform_port(std::uint8_t*,R5900Context* context,PS2Runtime*){
    if(context->pc!=0x1af780)throw std::runtime_error("Unexpected mesh-properties callee");
    selectors.push_back({GPR_U32(context,4),GPR_U32(context,5)});
    context->pc=GPR_U32(context,31);
}
static std::uint32_t word(std::span<const std::byte> data,std::size_t at){
    if(at>data.size()||data.size()-at<4)throw std::runtime_error("fixture extent");
    std::uint32_t result{};std::memcpy(&result,data.data()+at,4);return result;
}
struct Chunk {std::uint32_t type{};std::size_t at{},size{};};
static std::vector<Chunk> children(std::span<const std::byte> data,std::size_t at){
    const auto size=word(data,at+8);if(at>data.size()||size>data.size()-at||size<12)throw std::runtime_error("fixture parent");
    const auto end=at+size;at+=12;std::vector<Chunk> result;
    while(at<end){const auto type=word(data,at),length=word(data,at+8);if(length<12||length>end-at)throw std::runtime_error("fixture child");result.push_back({type,at,length});at+=length;}
    return result;
}
int main(int argc,char** argv)try{
    if(argc!=5)throw std::runtime_error("ELF image and three model assets required");
    std::vector<std::uint8_t> initial(0x2000000);std::ifstream image(argv[1],std::ios::binary);
    image.read(reinterpret_cast<char*>(initial.data()),std::streamsize(initial.size()));if(!image)throw std::runtime_error("ELF image read");
    std::size_t original_calls{},checks{},absent{};
    for(int i=2;i<argc;++i){
        std::ifstream file(argv[i],std::ios::binary);std::vector<char> raw{std::istreambuf_iterator<char>(file),{}};
        const auto data=std::as_bytes(std::span(raw));const auto mesh=reo::native::gameplay_presentation::ModelMesh::import(data);
        const auto root=word(data,20);const auto top=children(data,root);
        const auto objects=std::find_if(top.begin(),top.end(),[](const auto& c){return c.type==2;});
        if(objects==top.end())throw std::runtime_error("objects absent");const auto parts=children(data,objects->at);
        if(parts.size()!=mesh.parts.size())throw std::runtime_error("part identity");
        for(std::size_t n=0;n<parts.size();++n){
            const auto entries=children(data,parts[n].at);const auto found=std::find_if(entries.begin(),entries.end(),[](const auto& c){return c.type==0xf0000;});
            if(found==entries.end()||(word(data,found->at+12)>>16)!=1){if(mesh.parts[n].render_profile)throw std::runtime_error("unexpected profile");++absent;continue;}
            if(found->size<84||!mesh.parts[n].render_profile)throw std::runtime_error("profile absent");
            auto memory=initial;std::memcpy(memory.data()+0x10000,data.data()+found->at+12,72);
            R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x1fff000);SET_GPR_U32(&context,31,0x1000);
            SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,5,0x11000);context.pc=0x1d29f0;selectors.clear();
            sub_001D29F0_0x1d29f0(memory.data(),&context,&runtime);if(context.pc!=0x1000)throw std::runtime_error("original did not return");
            const auto find=[](std::uint32_t id){const auto it=std::find_if(selectors.begin(),selectors.end(),[id](const auto& s){return s.id==id;});
                if(it==selectors.end())throw std::runtime_error("selector absent");return it->value;};
            const auto& profile=*mesh.parts[n].render_profile;
            if(profile.format!=find(0x15)||profile.option_12!=(find(0x12)==0x8000)||profile.color_mode!=find(1))
                throw std::runtime_error("native profile differs from original caller");
            ++original_calls;checks+=3;
        }
    }
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<original_calls<<",\"absent\":"<<absent<<",\"selector_callee\":\"capture only\",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
