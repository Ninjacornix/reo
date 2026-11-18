#include "reference.hpp"
#include "functions.h"
#include "game/native/gameplay_application/session_scenario_resources.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
namespace a=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario::content;
static s::Bytes epp_data,door_data;
static bool epp_missing{};
static unsigned source_reads{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime*){
    const auto done=[&]{context->pc=GPR_U32(context,31);};
    switch(context->pc){
    case 0x107c68:{const auto at=GPR_U32(context,4),n=GPR_U32(context,6);
        if(at>0x2000000||n>0x2000000-at)throw std::runtime_error("source clear extent");
        std::memset(memory+at,int(GPR_U32(context,5)&255),n);SET_GPR_U32(context,2,at);done();return;}
    case 0x10a830:{const auto out=GPR_U32(context,4),fmt=GPR_U32(context,5);int written{};
        if(fmt==0x256a38)written=std::snprintf(reinterpret_cast<char*>(memory+out),256,reinterpret_cast<const char*>(memory+fmt),reinterpret_cast<const char*>(memory+GPR_U32(context,6)),int(GPR_U32(context,7)));
        else if(fmt==0x7428d8)written=std::snprintf(reinterpret_cast<char*>(memory+out),256,reinterpret_cast<const char*>(memory+fmt),int(GPR_U32(context,6)));
        else throw std::runtime_error("unexpected source path template");
        if(written<0||written>=256)throw std::runtime_error("source path extent");SET_GPR_U32(context,2,unsigned(written));done();return;}
    case 0x1cc8f0: case 0x1aa3e0:{const auto path=reinterpret_cast<const char*>(memory+GPR_U32(context,4));
        const bool placement=context->pc==0x1cc8f0;
        if(placement&&GPR_U32(context,6)!=0x10001)throw std::runtime_error("source placement mode");
        const std::string name(path);const auto data=placement?epp_data:door_data;
        if((placement&&name!="data/rom/scene/em_set/r41.epp")||(!placement&&name!="door041.dat"))throw std::runtime_error("source resource name");
        ++source_reads;
        if(placement&&epp_missing){SET_GPR_U32(context,2,0);done();return;}
        if(!data||GPR_U32(context,5)>0x2000000||data->size()>0x2000000-GPR_U32(context,5))throw std::runtime_error("source read extent");
        std::memcpy(memory+GPR_U32(context,5),data->data(),data->size());SET_GPR_U32(context,2,std::uint32_t(data->size()));done();return;}
    default:throw std::runtime_error("unexpected source buffer callee");
    }
}
static R5900Context call(std::vector<std::uint8_t>& memory,std::uint32_t pc,std::uint32_t x=0,std::uint32_t y=0,std::uint32_t z=0){
    R5900Context c;PS2Runtime runtime;c.pc=pc;SET_GPR_U32(&c,29,0x1fff000);SET_GPR_U32(&c,31,0x1000);SET_GPR_U32(&c,4,x);SET_GPR_U32(&c,5,y);SET_GPR_U32(&c,6,z);
    if(pc==0x1d49e0)sub_001D49E0_0x1d49e0(memory.data(),&c,&runtime);
    else if(pc==0x6dd9a0)o2_006DD9A0_0x6dd9a0(memory.data(),&c,&runtime);
    else if(pc==0x6344c0)o2_006344C0_0x6344c0(memory.data(),&c,&runtime);
    else throw std::runtime_error("unexpected source call");
    if(c.pc!=0x1000)throw std::runtime_error("source did not return");return c;
}
int main(int argc,char** argv)try{
    if(argc!=4)throw std::runtime_error("ELF image, overlay and owned NETBIO00 required");
    std::vector<std::uint8_t> memory(0x2000000);std::ifstream elf(argv[1],std::ios::binary);elf.read(reinterpret_cast<char*>(memory.data()),std::streamsize(memory.size()));if(!elf)throw std::runtime_error("ELF image read");
    std::ifstream overlay(argv[2],std::ios::binary);const std::vector<char> data{std::istreambuf_iterator<char>(overlay),{}};
    if(data.size()>memory.size()-0x570000)throw std::runtime_error("overlay extent");std::memcpy(memory.data()+0x570000,data.data(),data.size());
    auto source=std::make_shared<const reo::assets::Source>(argv[3]);s::ScenarioArchive archive(source);epp_data=archive.read_resource_sectors(41,"r41.epp");door_data=archive.read_resource_sectors(41,"door041.dat");
    const auto logical_door=archive.read_resource(41,"door041.dat");if(!epp_data||!door_data||!logical_door||door_data->size()!=2048||logical_door->size()!=1104)throw std::runtime_error("owned sector extent");
    auto session=std::make_shared<w::Session>();session->scenario=41;session->asset_loading_mode=1;w::Profile profile;profile.layouts.push_back({});w::World world(profile,session);
    a::SessionScenarioResources owner(world,archive);if(owner.initialize()!=a::ScenarioDataStatus::completed||owner.load_placements()!=a::ScenarioDataStatus::completed||owner.load_doors()!=a::ScenarioDataStatus::completed)throw std::runtime_error("native scenario buffers unavailable");
    constexpr std::uint32_t epp=0x100000,door=0x120000;transform_write(memory.data(),0x32446c,epp);transform_write(memory.data(),0x324458,door);
    transform_write(memory.data(),0x3243da,std::uint16_t(41));transform_write(memory.data(),0x3243d7,std::uint8_t(1));
    std::memset(memory.data()+epp,0xa5,0x10000);std::memset(memory.data()+door,0xa5,0x4000);call(memory,0x1d49e0);call(memory,0x6dd9a0);
    std::size_t checks{};const auto expect=[&](bool yes){++checks;if(!yes)throw std::runtime_error("source scenario-buffer mismatch check "+std::to_string(checks));};
    expect(source_reads==2);expect(transform_read<std::uint32_t>(memory.data(),0x755c84)==door_data->size());
    expect(transform_read<std::uint32_t>(memory.data(),0x755c88)==door+door_data->size());
    const auto native_doors=owner.doors();expect(bool(native_doors));const auto group_end=transform_read<std::uint32_t>(memory.data(),0x755c74);
    expect(native_doors->groups.size()==group_end-(door+16));expect(native_doors->metadata==transform_read<std::uint32_t>(memory.data(),0x755c7c));
    expect(std::memcmp(native_doors->groups.data(),memory.data()+door+16,native_doors->groups.size())==0);
    expect(std::memcmp(native_doors->admissions.data(),memory.data()+door+door_data->size(),128)==0);
    unsigned groups{};for(unsigned cursor=0;cursor+8<=epp_data->size();cursor+=8){const auto room=memory[epp+cursor],variant=memory[epp+cursor+1];if(room==255)break;
        for(unsigned index=0;index<2;++index){const auto original=call(memory,0x6344c0,room,variant,index);const auto at=GPR_U32(&original,2);const auto native=owner.placement(room,variant,index);
            expect(at>=epp&&at+20<=epp+epp_data->size()&&native.status==a::ScenarioDataStatus::completed&&native.placement.has_value());
            expect(native.placement->field0==transform_read<std::uint16_t>(memory.data(),at));expect(native.placement->yaw==transform_read<std::uint16_t>(memory.data(),at+2));
            for(unsigned lane=0;lane<3;++lane)expect(native.placement->position[lane]==transform_read<std::int32_t>(memory.data(),at+4+4*lane));
            expect(native.placement->field16==transform_read<std::uint32_t>(memory.data(),at+16));}
        ++groups;
    }
    expect(groups>0);const auto missing=call(memory,0x6344c0,254,0,0);
    expect(!owner.placement(254,0,0).placement&&GPR_U32(&missing,2)==0);
    epp_missing=true;call(memory,0x1d49e0);expect(memory[epp]==255&&memory[epp+1]==std::to_integer<std::uint8_t>((*epp_data)[1]));
    expect(owner.close()==a::ScenarioDataStatus::completed);
    std::cout<<"{\"checks\":"<<checks<<",\"groups\":"<<groups<<",\"door_logical_bytes\":1104,\"door_sector_bytes\":2048,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
