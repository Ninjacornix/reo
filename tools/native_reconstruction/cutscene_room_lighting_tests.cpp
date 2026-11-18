#include "game/native/gameplay_scenario/cutscene_lights.hpp"
#include "game/native/gameplay_scenario/cutscene_playback.hpp"
#include "game/native/gameplay_scenario/scenario_archive.hpp"
#include "game/native/gameplay_application/session_rooms.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <source_location>
namespace s=reo::native::gameplay_scenario;namespace a=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
std::uint64_t checks{},calls{},visits{},reads{},lighting_reads{},fog_reads{},default_misses{};unsigned serial{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Room lighting case "+std::to_string(serial)+" line "+std::to_string(at.line()));
}
struct Resource{unsigned ordinal{};std::string key;std::uint64_t offset{};unsigned logical{},storage{};};
std::map<unsigned,std::vector<Resource>> resources;std::shared_ptr<const reo::assets::Source> source;
std::vector<std::byte> payload;unsigned mode{},scenario{},room{},variant{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;const auto done=[&](unsigned value=0){SET_GPR_U32(context,2,value);context->pc=GPR_U32(context,31);};
    const auto name=[&](unsigned reg){return std::string(reinterpret_cast<const char*>(memory+GPR_U32(context,reg)));};
    switch(context->pc){
#include "original_dispatch.hpp"
    case 0x107c68:std::memset(memory+GPR_U32(context,4),int(GPR_U32(context,5)&255),GPR_U32(context,6));done();return;
    case 0x107ab0:std::memmove(memory+GPR_U32(context,4),memory+GPR_U32(context,5),GPR_U32(context,6));done(GPR_U32(context,4));return;
    case 0x10afc0:{const auto copy=name(5);check(copy.size()<512);std::memcpy(memory+GPR_U32(context,4),copy.c_str(),copy.size()+1);done(GPR_U32(context,4));return;}
    case 0x10cda8:{auto p=memory+GPR_U32(context,4);for(;*p;++p)if(*p>='a'&&*p<='z')*p+='A'-'a';done(GPR_U32(context,4));return;}
    case 0x10b158:done(unsigned(name(4).size()));return;
    case 0x10b7b8:{const auto p=std::strrchr(reinterpret_cast<const char*>(memory+GPR_U32(context,4)),int(GPR_U32(context,5)));done(p?unsigned(reinterpret_cast<const std::uint8_t*>(p)-memory):0u);return;}
    case 0x10ae78:done(std::uint32_t(std::strcmp(reinterpret_cast<const char*>(memory+GPR_U32(context,4)),reinterpret_cast<const char*>(memory+GPR_U32(context,5)))));return;
    case 0x10a830:{const auto format=name(5);char expected[128];const char* suffix=format.ends_with("lig")?"lig":"fog";
        std::snprintf(expected,sizeof expected,"r%03u%02u%02u.%s",scenario,room,variant,suffix);
        auto destination=reinterpret_cast<char*>(memory+GPR_U32(context,4));int length{};
        if(mode)length=std::snprintf(destination,128,format.c_str(),GPR_U32(context,6),GPR_U32(context,7),GPR_U32(context,8));
        else length=std::snprintf(destination,128,format.c_str(),reinterpret_cast<const char*>(memory+GPR_U32(context,6)),GPR_U32(context,7),GPR_U32(context,8),GPR_U32(context,9),GPR_U32(context,10));
        check(length>0&&length<128&&std::string(destination).ends_with(expected));done(unsigned(length));return;}
    case 0x1aa1e0:{check(GPR_U32(context,4)==scenario);const auto& table=resources[scenario];transform_write(memory,0x2b16a0,0x123450u);transform_write(memory,0x123450,1u);transform_write(memory,0x12345c,0x140000u);transform_write(memory,0x123464,unsigned(table.size()));transform_write(memory,0x123468,table.empty()?0u:table.front().ordinal);transform_write(memory,0x123470,7u);
        for(unsigned index=0;index<table.size();++index){check(table[index].ordinal==table.front().ordinal+index&&table[index].key.size()<=16);std::fill_n(memory+0x140000+16*index,16,0);std::memcpy(memory+0x140000+16*index,table[index].key.data(),table[index].key.size());}done();return;}
    case 0x129240:{check(mode&&GPR_U32(context,4)==7);const auto& table=resources[scenario];const auto item=std::find_if(table.begin(),table.end(),[&](const auto& value){return value.ordinal==GPR_U32(context,5);});check(item!=table.end());payload.resize(item->storage);source->read(item->offset,payload.size(),payload.data());check(payload.size()%2048==0&&item->logical<=payload.size());transform_write(memory,0x17000c,0u);transform_write(memory,0x170004,0x180000u);transform_write(memory,0x180010,unsigned(payload.size()));++reads;done(0x170000);return;}
    case 0x1297a0:check(GPR_U32(context,4)==0x170000&&GPR_U32(context,5)==payload.size()/2048);std::memcpy(memory+GPR_U32(context,6),payload.data(),payload.size());done();return;
    case 0x129d48:check(GPR_U32(context,4)==0x170000);done(3);return;
    case 0x129350:check(GPR_U32(context,4)==0x170000);done();return;
    default:throw std::runtime_error("Unadmitted room lighting source call "+std::to_string(context->pc));
    }
}
void invoke(std::uint8_t* memory){R5900Context context;PS2Runtime runtime;context.pc=0x1d4870;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);}
struct Notifications final:s::FlagNotifications{
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
void export_fog(std::uint8_t* memory,const s::FogState& state,unsigned bias=0){
    transform_write(memory,0x324010 - bias,state.near_distance);transform_write(memory,0x324014 - bias,state.far_distance);std::memcpy(memory+0x324018 - bias,state.color.data(),3);std::memcpy(memory+0x32407c - bias,state.tail_color.data(),3);
    std::memcpy(memory+0x32408c - bias,state.secondary_colors[0].data(),4);std::memcpy(memory+0x324098 - bias,state.secondary_colors[1].data(),4);transform_write(memory,0x3240cc - bias,state.parameters[0]);transform_write(memory,0x3240ce - bias,state.parameters[1]);transform_write(memory,0x3240c0 - bias,state.direction);
    std::memcpy(memory+0x323edc - bias,state.vectors[0].data(),16);std::memcpy(memory+0x323efc - bias,state.vectors[1].data(),16);std::memcpy(memory+0x323eec - bias,state.vectors[2].data(),16);transform_write(memory,0x32404c - bias,state.words[0]);transform_write(memory,0x324050 - bias,state.words[1]);memory[0x3240bf - bias]=state.option;memory[0x3240bd - bias]=std::bit_cast<std::uint8_t>(state.selected);std::memcpy(memory+0x3240d0 - bias,state.flash.data(),4);
}
int main(int argc,char** argv)try{
    check(argc==3);source=std::make_shared<const reo::assets::Source>(argv[1]);std::ifstream list(argv[2]);check(bool(list));unsigned id;Resource item;
    while(list>>id>>item.ordinal>>item.key>>item.offset>>item.logical>>item.storage){if(item.key=="-")item.key.clear();resources[id].push_back(item);}check(list.eof()&&resources.size()==6);
    std::set<std::array<unsigned,3>> rooms;
    for(const auto& [id,table]:resources)for(const auto& resource:table){const auto& key=resource.key;if(key.size()!=12||key[0]!='R'||key[8]!='_'||(key.substr(9)!="LIG"&&key.substr(9)!="FOG"))continue;
        const auto authored=unsigned(std::stoul(key.substr(1,3)));if(authored!=id)continue;rooms.insert({id,unsigned(std::stoul(key.substr(4,2))),unsigned(std::stoul(key.substr(6,2)))});}
    check(rooms.size()>100);rooms.insert({65535,0,0});rooms.insert({41,65535,65535});
    Notifications notices;w::Profile profile;profile.layouts.push_back({});auto host=std::make_shared<a::NativeSession>(source,profile,notices);check(host->install_room({41,73,0})==a::SessionStatus::completed);a::SessionRooms actual_rooms(host);
    auto& lights=host->lighting();s::Fog fog({});s::CutscenePlaybackState state;s::CutsceneLights owner(host->world(),state,lights,fog,actual_rooms);s::content::ScenarioArchive archive(source);
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());const auto identity=reo::native::transform_math::identity();std::memcpy(memory.data()+0x294e00,identity.data(),64);transform_write(memory.data(),0x32440c,0xd00000u);
    transform_write(memory.data(),0x2b1698,0x130000u);transform_write(memory.data(),0x13000c,0x2322c0u);transform_write(memory.data(),0x130014,1342u);transform_write(memory.data(),0x3243f8,std::uint8_t(255));transform_write(memory.data(),0x3243f9,std::uint8_t(255));
    const auto project=[&]{
        transform_write(memory.data(),0x3240be,lights.selected());transform_write(memory.data(),0x747538,lights.primary_count());transform_write(memory.data(),0x748340,lights.auxiliary_count());std::memcpy(memory.data()+0x747540,lights.primary().data(),64*56);std::memcpy(memory.data()+0x748350,lights.auxiliary().data(),64*56);
        for(unsigned bank=0;bank<4;++bank)std::memcpy(memory.data()+0x3dc1e0+bank*0x6f4,&lights.banks()[bank],0x6f4);
        for(unsigned index=0;index<32;++index)transform_write(memory.data(),0x7474b0+4*index,lights.bindings()[index]==255?0u:0x747540u+56u*lights.bindings()[index]);
        export_fog(memory.data(),fog.state());std::fill_n(memory.data()+0x3dbbe0,16*96,0);
    };
    const auto compare=[&]{
        check(std::uint8_t(lights.selected())==memory[0x3240be]&&lights.primary_count()==memory[0x747538]&&lights.auxiliary_count()==memory[0x748340]);
        for(unsigned bank=0;bank<4;++bank)check(std::memcmp(&lights.banks()[bank],memory.data()+0x3dc1e0+bank*0x6f4,0x6f4)==0);
        check(std::memcmp(lights.primary().data(),memory.data()+0x747540,64*56)==0&&std::memcmp(lights.auxiliary().data(),memory.data()+0x748350,64*56)==0);
        for(unsigned index=0;index<32;++index){check(transform_read<unsigned>(memory.data(),0x7474b0+4*index)==(lights.bindings()[index]==255?0u:0x747540u+56u*lights.bindings()[index]));const auto pointer=transform_read<unsigned>(memory.data(),0x747430+4*index);const auto light=owner.light(index);check(bool(pointer)==bool(light));if(light)check(std::memcmp(&*light,memory.data()+pointer,sizeof *light)==0);}
        const auto mirror=owner.mirror();const auto pointer=transform_read<unsigned>(memory.data(),0x747420);check(bool(mirror)==bool(pointer));if(mirror)check(std::memcmp(&*mirror,memory.data()+pointer,sizeof *mirror)==0);
        std::array<std::uint8_t,0x400> projected;std::memcpy(projected.data(),memory.data()+0x323e00,projected.size());export_fog(projected.data(),fog.state(),0x323e00);check(std::memcmp(projected.data(),memory.data()+0x323e00,projected.size())==0);
        for(unsigned index=0;index<16;++index){const auto at=0x3dbbe0+96*index;const auto& value=fog.records()[index];check(value.active==transform_read<unsigned>(memory.data(),at));check(value.near_distance==transform_read<float>(memory.data(),at+4)&&value.far_distance==transform_read<float>(memory.data(),at+8));for(unsigned c=0;c<3;++c)check(value.colors[c]==transform_read<unsigned>(memory.data(),at+12+4*c));check(value.parameters==transform_read<unsigned>(memory.data(),at+24));check(value.pitch==transform_read<std::uint16_t>(memory.data(),at+28)&&value.yaw==transform_read<std::uint16_t>(memory.data(),at+32));check(std::memcmp(value.vectors.data(),memory.data()+at+36,48)==0&&std::memcmp(value.words.data(),memory.data()+at+84,12)==0);}
    };
    for(const auto& row:rooms)for(unsigned selected:{0u,1u,255u})for(unsigned occupied:{0u,63u})for(unsigned loading:{1u,0u,255u}){
        ++serial;scenario=row[0];room=row[1];variant=row[2];mode=loading;auto& session=host->world().session();session.scenario=std::uint16_t(scenario);host->world().room=std::uint16_t(room);session.room_variant=std::uint16_t(variant);session.asset_loading_mode=std::uint8_t(mode);
        lights.reset_work();for(unsigned index=0;index<occupied;++index){check(bool(lights.allocate(nullptr,std::uint8_t(index),7)));check(bool(lights.allocate_auxiliary(nullptr,std::uint8_t(index))));}
        fog.state().selected=std::bit_cast<std::int8_t>(std::uint8_t(selected));fog.state().near_distance=91;fog.state().far_distance=231;fog.state().color={82,73,64};std::array<std::byte,4> unsupported{};check(fog.import_fog(unsupported)==s::FogStatus::unsupported_version);project();
        transform_write(memory.data(),0x3243da,std::uint16_t(scenario));transform_write(memory.data(),0x3243dc,std::uint16_t(room));transform_write(memory.data(),0x3243de,std::uint16_t(variant));transform_write(memory.data(),0x3243d7,std::uint8_t(mode));const auto before=reads;invoke(memory.data());const auto result=owner.load_room(archive);check(result.status==s::CutsceneLightsStatus::completed&&result.initialized);check(unsigned(result.lighting_read)+unsigned(result.fog_read)==reads-before);if(!mode){check(!result.lighting_read&&!result.fog_read);++default_misses;}lighting_reads+=result.lighting_read;fog_reads+=result.fog_read;compare();++visits;
    }
    host->world().session().asset_loading_mode.reset();check(owner.load_room(archive).status==s::CutsceneLightsStatus::unavailable);host->world().session().asset_loading_mode=1;host->world().session().scenario=0;check(owner.load_room(archive).status==s::CutsceneLightsStatus::unavailable);
    std::cout<<"{\"checks\":"<<checks<<",\"room_keys\":"<<rooms.size()<<",\"visits\":"<<visits<<",\"lighting_reads\":"<<lighting_reads<<",\"fog_reads\":"<<fog_reads<<",\"default_misses\":"<<default_misses<<",\"physical_reads\":"<<reads<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
