#include "reference.hpp"
#include "functions.h"
#include "game/native/gameplay_scenario/room_return_points.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>
namespace s=reo::native::gameplay_scenario;
namespace g=reo::native::gameplay_session;
using V=reo::native::transform_math::Vector;
static unsigned calls{},checks{},points{},nearest_queries{},bounded_refusals{};
static void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("RTP original check "+std::to_string(at.line())+" calls="+std::to_string(calls));
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
#include "original_dispatch.inc"
    default:throw std::runtime_error("Unexpected RTP original port "+std::to_string(context->pc));
    }
}
static std::vector<std::byte> read_file(const std::filesystem::path& path){
    std::ifstream input(path,std::ios::binary);check(bool(input));std::vector<char> raw{std::istreambuf_iterator<char>(input),{}};
    std::vector<std::byte> bytes(raw.size());std::memcpy(bytes.data(),raw.data(),raw.size());return bytes;
}
template<class T>T field(const std::vector<std::byte>& data,std::size_t at){T value;check(at+sizeof value<=data.size());std::memcpy(&value,data.data()+at,sizeof value);return value;}
int main(int argc,char** argv)try{
    check(argc==4);std::vector<std::uint8_t> memory(0x2000000);const auto elf=read_file(argv[1]);
    const auto ph=field<std::uint32_t>(elf,28);const auto step=field<std::uint16_t>(elf,42),count=field<std::uint16_t>(elf,44);
    for(unsigned i=0;i<count;++i){const auto at=ph+step*i;if(field<std::uint32_t>(elf,at)!=1)continue;
        const auto offset=field<std::uint32_t>(elf,at+4),address=field<std::uint32_t>(elf,at+8),size=field<std::uint32_t>(elf,at+16);
        check(std::size_t(offset)+size<=elf.size()&&std::size_t(address)+size<=memory.size());std::memcpy(memory.data()+address,elf.data()+offset,size);
    }
    const auto o0=read_file(argv[2]);check(o0.size()+0x370000<memory.size());std::memcpy(memory.data()+0x370000,o0.data(),o0.size());
    constexpr unsigned data=0x10000,position=0x20000;PS2Runtime runtime;
    g::RoomVariants variants;variants.restore({});
    const auto invoke=[&](unsigned address,unsigned room,unsigned mode,unsigned kind,unsigned index,V initial){
        transform_write(memory.data(),position,initial);R5900Context c;c.pc=address;
        SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0x1ffff00);
        SET_GPR_U32(&c,4,position);SET_GPR_U32(&c,5,room);SET_GPR_U32(&c,6,mode);SET_GPR_U32(&c,7,kind);SET_GPR_U32(&c,8,index);
        original_transform_port(memory.data(),&c,&runtime);check(c.pc==0x1ffff00);++calls;
        return std::bit_cast<std::int8_t>(std::uint8_t(GPR_U32(&c,2)));
    };
    for(unsigned scenario:{1u,2u,35u,41u}){
        char name[20];std::snprintf(name,sizeof name,"r%02u.rtp",scenario);const auto bytes=read_file(std::filesystem::path(argv[3])/name);
        const auto bank=s::RoomReturnPoints::import(bytes);check(bank&&!bank->rooms().empty());
        std::memcpy(memory.data()+data,bytes.data(),bytes.size());transform_write(memory.data(),0x324464,std::uint32_t(data));
        for(const auto& row:bank->rooms()){
            const unsigned room=row.key>>8;check(variants.store(room,row.key&255));transform_write(memory.data(),0x4b9d20+room,std::uint8_t(row.key));
            for(const auto& group:row.groups){
                for(unsigned ordinal=0;ordinal<group.indices.size();++ordinal){
                    for(unsigned wildcard:{0u,1u}){
                        const auto mode=wildcard?0xffffffffu:std::uint32_t(std::uint8_t(group.mode));
                        const auto kind=std::uint32_t(std::uint8_t(group.kind));const std::uint16_t seed=std::uint16_t(calls*1193u);
                        g::Random random({seed,0x1234,17});transform_write(memory.data(),0x3244b0,seed);
                        const auto actual=bank->point(room,mode,kind,ordinal,variants,random);
                        if(!actual){
                            const auto first_room=std::find_if(bank->rooms().begin(),bank->rooms().end(),[&](const auto& x){return x.key==row.key;});
                            const auto first_group=std::find_if(first_room->groups.begin(),first_room->groups.end(),[&](const auto& x){return x.kind==group.kind&&(wildcard||x.mode==group.mode);});
                            check(first_group!=first_room->groups.end()&&ordinal>=first_group->indices.size()&&random.state().primary==seed);
                            ++bounded_refusals;continue;
                        }
                        const V untouched{123,456,789};const auto expected=invoke(0x5fdf10,room,mode,kind,ordinal,untouched);
                        check(actual->status==expected);check(random.state().primary==transform_read<std::uint16_t>(memory.data(),0x3244b0));
                        if(actual->position)check(std::memcmp(&*actual->position,memory.data()+position,sizeof(V))==0);
                        else check(std::memcmp(&untouched,memory.data()+position,sizeof(V))==0);
                        ++points;
                    }
                    const auto v=row.points[std::size_t(group.indices[ordinal])];
                    for(unsigned wildcard:{0u,1u}){
                        const unsigned kind=wildcard?room:std::uint32_t(std::uint8_t(group.kind));const unsigned mode=std::uint32_t(std::uint8_t(group.mode));
                        const auto actual=bank->nearest(v,room,mode,kind,variants);check(bool(actual));
                        const auto expected=invoke(0x5fe160,room,mode,kind,0,v);check(*actual==expected);++nearest_queries;
                    }
                }
                g::Random random({71,0,0});transform_write(memory.data(),0x3244b0,std::uint16_t(71));
                const auto missing=bank->point(room,255,127,0,variants,random);check(missing&&missing->status==-1&&!missing->position);
                check(invoke(0x5fdf10,room,255,127,0,{1,2,3})==-1&&random.state().primary==71&&transform_read<std::uint16_t>(memory.data(),0x3244b0)==71);
            }
        }
    }
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_calls\":"<<calls<<",\"point_queries\":"<<points<<",\"nearest_queries\":"<<nearest_queries<<",\"bounded_refusals\":"<<bounded_refusals<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
