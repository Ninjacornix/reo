#include "reference.hpp"
#include "functions.h"
#include "game/native/gameplay_presentation/model_mesh.hpp"
#include <algorithm>
#include <array>
#include <bit>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <vector>

void original_transform_port(std::uint8_t*,R5900Context*,PS2Runtime*){
    throw std::runtime_error("Unexpected vertex packing callee");
}
static std::uint32_t word(const std::vector<char>& bytes,std::size_t at){
    if(at>bytes.size()||bytes.size()-at<4)throw std::runtime_error("fixture extent");
    std::uint32_t value{};std::memcpy(&value,bytes.data()+at,4);return value;
}
struct Chunk {std::uint32_t type{};std::size_t at{},size{};};
static std::vector<Chunk> children(const std::vector<char>& bytes,std::size_t at){
    const auto size=word(bytes,at+8);if(at>bytes.size()||size>bytes.size()-at||size<12)throw std::runtime_error("fixture parent");
    const auto end=at+size;at+=12;std::vector<Chunk> result;
    while(at<end){const auto type=word(bytes,at),length=word(bytes,at+8);if(length<12||length>end-at)throw std::runtime_error("fixture child");result.push_back({type,at,length});at+=length;}
    return result;
}
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("owned room model required");
    std::ifstream file(argv[1],std::ios::binary);std::vector<char> raw{std::istreambuf_iterator<char>(file),{}};
    const auto top=children(raw,word(raw,20));const auto objects=std::find_if(top.begin(),top.end(),[](const auto& c){return c.type==2;});
    if(objects==top.end())throw std::runtime_error("objects missing");const auto parts=children(raw,objects->at);
    if(parts.size()<10)throw std::runtime_error("part missing");const auto entries=children(raw,parts[9].at);
    const auto colors=std::find_if(entries.begin(),entries.end(),[](const auto& c){return c.type==0xb0000;});
    if(colors==entries.end()||colors->size<28)throw std::runtime_error("color missing");
    const std::array<std::array<float,4>,12> cases{{
        {0,0,0,0},{255,255,255,255},{20.611225f,20.611225f,20.611225f,204},
        {191.25f,19.38f,127.5f,165.75f},{1,2,3,1},{254,253,252,254},
        {256,0,0,0},{-1,0,0,0},{0,-1,0,0},{0,0,-1,0},
        {2147483648.f,1,2,3},{std::numeric_limits<float>::max(),0,0,0}
    }};
    std::vector<std::uint8_t> memory(0x2000000);std::size_t checks{};
    for(const auto& input:cases){
        std::memcpy(memory.data()+0x10000,input.data(),sizeof(input));
        R5900Context packing;PS2Runtime runtime;SET_GPR_U32(&packing,2,0x10000);SET_GPR_U32(&packing,9,0x11000);
        packing.pc=0x1a42c0;
        try{sub_001A3F70_0x1a3f70(memory.data(),&packing,&runtime);throw std::runtime_error("packing stop not reached");}
        catch(const PackingStop&){}
        if(packing.pc!=0x1a43e0)throw std::runtime_error("wrong packing stop");
        const auto packed=transform_read<std::uint32_t>(memory.data(),0x11018);
        R5900Context skinned;SET_GPR_U32(&skinned,2,0x10000);SET_GPR_U32(&skinned,10,0x12000);skinned.pc=0x1a4964;
        try{sub_001A45A0_0x1a45a0(memory.data(),&skinned,&runtime);throw std::runtime_error("skinned packing stop not reached");}
        catch(const PackingStop&){}
        if(skinned.pc!=0x1a4a88||transform_read<std::uint32_t>(memory.data(),0x12018)!=packed)
            throw std::runtime_error("skinned packing differs");
        std::array<float,4> expected{};
        for(unsigned i=0;i<4;++i){
            const unsigned shift=i==0?16:i==1?8:i==2?0:24;
            R5900Context component;SET_GPR_U32(&component,4,(packed>>shift)&255u);SET_GPR_U32(&component,5,i==3?0:1);
            SET_GPR_U32(&component,31,0x1000);component.pc=0x18b2c0;
            sub_0018B2C0_0x18b2c0(memory.data(),&component,&runtime);
            if(component.pc!=0x1000)throw std::runtime_error("component conversion did not return");
            expected[i]=i==3?component.f[0]/128.f:component.f[0];
        }
        std::memcpy(raw.data()+colors->at+12,input.data(),sizeof(input));
        const auto mesh=reo::native::gameplay_presentation::ModelMesh::import(std::as_bytes(std::span(raw)));
        const auto actual=mesh.parts[9].vertices[0].color;
        for(unsigned i=0;i<4;++i)if(std::bit_cast<std::uint32_t>(actual[i])!=std::bit_cast<std::uint32_t>(expected[i]))
            throw std::runtime_error("native converted vertex color differs");
        checks+=4;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"packing_slices\":"<<cases.size()*2<<",\"complete_component_calls\":"<<cases.size()*4
             <<",\"controlled_fixture\":true,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
