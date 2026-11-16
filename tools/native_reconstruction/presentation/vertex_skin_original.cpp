#include "reference.hpp"
#include "functions.h"
#include "game/native/gameplay_presentation/model_mesh.hpp"
#include <algorithm>
#include <bit>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
        case 0x1a3d00:sub_001A3D00_0x1a3d00(memory,context,runtime);return;
        case 0x1a35f0:sub_001A35F0_0x1a35f0(memory,context,runtime);return;
        default:throw std::runtime_error("Unexpected skin conversion callee");
    }
}
static std::uint32_t word(const std::vector<char>& bytes,std::size_t at){
    if(at>bytes.size()||bytes.size()-at<4)throw std::runtime_error("fixture extent");
    std::uint32_t value{};std::memcpy(&value,bytes.data()+at,4);return value;
}
struct Chunk {std::uint32_t type{},count{};std::size_t at{},size{};};
static std::vector<Chunk> children(const std::vector<char>& bytes,std::size_t at){
    const auto size=word(bytes,at+8);if(at>bytes.size()||size>bytes.size()-at||size<12)throw std::runtime_error("fixture parent");
    const auto end=at+size;at+=12;std::vector<Chunk> result;
    while(at<end){const auto type=word(bytes,at),count=word(bytes,at+4),length=word(bytes,at+8);
        if(length<12||length>end-at)throw std::runtime_error("fixture child");result.push_back({type,count,at,length});at+=length;}
    return result;
}
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("owned actor model required");
    std::ifstream file(argv[1],std::ios::binary);std::vector<char> raw{std::istreambuf_iterator<char>(file),{}};
    const auto mesh=reo::native::gameplay_presentation::ModelMesh::import(std::as_bytes(std::span(raw)));
    const auto top=children(raw,word(raw,20));const auto objects=std::find_if(top.begin(),top.end(),[](const auto& c){return c.type==2;});
    if(objects==top.end())throw std::runtime_error("objects missing");const auto parts=children(raw,objects->at);
    if(parts.size()!=mesh.parts.size())throw std::runtime_error("part identity");
    std::vector<std::uint8_t> memory(0x2000000);std::size_t checks{},vertices{},adjusted{};
    for(std::size_t part_index=0;part_index<parts.size();++part_index){
        const auto& part=parts[part_index];const auto entries=children(raw,part.at);
        const auto weights=std::find_if(entries.begin(),entries.end(),[](const auto& c){return c.type==0xc0000;});
        const auto palette=std::find_if(entries.begin(),entries.end(),[](const auto& c){return c.type==0x100000;});
        if(weights==entries.end()||palette==entries.end()||part.size>0xf0000)throw std::runtime_error("skin sections missing");
        std::memcpy(memory.data()+0x10000,raw.data()+part.at,part.size);auto cursor=weights->at+12;
        if(weights->count!=mesh.parts[part_index].vertices.size())throw std::runtime_error("vertex count mismatch");
        for(std::size_t i=0;i<weights->count;++i){
            const auto count=word(raw,cursor);cursor+=4;if(!count||count>4)throw std::runtime_error("invalid source weight count");
            cursor+=8*count;if(cursor>weights->at+weights->size)throw std::runtime_error("source weight extent");
            constexpr std::uint32_t sp=0x1fff000;R5900Context context;PS2Runtime runtime;
            SET_GPR_U32(&context,29,sp);SET_GPR_U32(&context,2,count);SET_GPR_U32(&context,16,0x10000);
            SET_GPR_U32(&context,19,sp+0x94);SET_GPR_U32(&context,18,sp+0x98);SET_GPR_U32(&context,25,sp+0x9c);
            SET_GPR_U32(&context,24,sp+0x84);SET_GPR_U32(&context,15,sp+0x88);SET_GPR_U32(&context,22,sp+0x8c);
            SET_GPR_U32(&context,13,0x110024);SET_GPR_U32(&context,14,0x110028);SET_GPR_U32(&context,10,0x110000);
            SET_GPR_U32(&context,12,std::uint32_t(i));context.pc=0x1a4aa4;
            try{sub_001A45A0_0x1a45a0(memory.data(),&context,&runtime);throw std::runtime_error("skin stop not reached");}
            catch(const SkinStop&){}
            if(context.pc!=0x1a4c28)throw std::runtime_error("wrong skin stop");
            const auto packed_weights=transform_read<std::uint32_t>(memory.data(),0x110028);
            const auto packed_indices=transform_read<std::uint32_t>(memory.data(),0x110024);
            const auto& native=mesh.parts[part_index].vertices[i].influences;if(native.size()!=count)throw std::runtime_error("native influence count");
            for(std::size_t j=0;j<count;++j){const auto shift=unsigned(24-8*j),index=(packed_indices>>shift)&255u,weight=(packed_weights>>shift)&255u;
                if(index>=palette->count||native[j].joint!=word(raw,palette->at+12+4*index)||
                   std::bit_cast<std::uint32_t>(native[j].weight)!=std::bit_cast<std::uint32_t>(float(weight)/255.f)){
                    std::cerr<<"part="<<part_index<<" vertex="<<i<<" slot="<<j<<" source_index="<<index<<" source_weight="<<weight
                             <<" native_joint="<<native[j].joint<<" native_weight="<<native[j].weight<<'\n';
                    throw std::runtime_error("native skin influence differs from original");
                }
                checks+=2;
            }
            if(count>1){const auto first=(packed_weights>>24)&255u;if(first==127&&((packed_weights>>16)&255u)==128)++adjusted;}
            ++vertices;
        }
    }
    if(vertices!=3556||!adjusted)throw std::runtime_error("owned skin corpus coverage");
    std::cout<<"{\"checks\":"<<checks<<",\"original_packing_slices\":"<<vertices<<",\"adjusted_50_50\":"<<adjusted<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
