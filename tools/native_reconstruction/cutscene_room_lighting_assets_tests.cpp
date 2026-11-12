#include "game/native/gameplay_application/session_rooms.hpp"
#include "game/native/gameplay_scenario/cutscene_lights.hpp"
#include "game/native/gameplay_scenario/cutscene_playback.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <source_location>
namespace a=reo::native::gameplay_application;namespace s=reo::native::gameplay_scenario;
namespace w=reo::native::gameplay_world;
std::uint64_t checks{},visits{},lig_reads{},fog_reads{},default_misses{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Current room lighting line "+std::to_string(at.line()));
}
struct Notifications final:s::FlagNotifications{
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
int main(int argc,char** argv)try{
    check(argc==3);auto source=std::make_shared<const reo::assets::Source>(argv[1]);
    std::ifstream manifest(argv[2]);check(bool(manifest));std::map<unsigned,std::set<std::string>> keys;
    unsigned scenario,ordinal,logical,storage;std::uint64_t offset;std::string key;
    while(manifest>>scenario>>ordinal>>key>>offset>>logical>>storage){check(logical<=storage&&storage%2048==0);keys[scenario].insert(key);}
    check(manifest.eof()&&keys.size()==6);std::set<std::array<unsigned,3>> rooms;
    for(const auto& [id,table]:keys)for(const auto& name:table){
        if(name.size()!=12||name[0]!='R'||name[8]!='_'||(name.substr(9)!="LIG"&&name.substr(9)!="FOG"))continue;
        if(unsigned(std::stoul(name.substr(1,3)))==id)rooms.insert({id,unsigned(std::stoul(name.substr(4,2))),unsigned(std::stoul(name.substr(6,2)))});
    }
    rooms.insert({65535,0,0});rooms.insert({41,65535,65535});check(rooms.size()==227);
    Notifications notifications;w::Profile profile;profile.layouts.push_back({});
    auto host=std::make_shared<a::NativeSession>(source,profile,notifications);check(host->install_room({41,73,0})==a::SessionStatus::completed);a::SessionRooms actual_rooms(host);
    auto& lights=host->lighting();s::Fog fog({});s::CutscenePlaybackState state;state.frame=0xabcdef01;s::CutsceneLights owner(host->world(),state,lights,fog,actual_rooms);
    for(const auto& row:rooms)for(unsigned selected:{0u,1u,255u})for(unsigned occupied:{0u,63u})for(unsigned mode:{1u,0u,255u}){
        auto& session=host->world().session();session.scenario=std::uint16_t(row[0]);host->world().room=std::uint16_t(row[1]);session.room_variant=std::uint16_t(row[2]);session.asset_loading_mode=std::uint8_t(mode);session.clock_mode=std::uint8_t(visits%3==0?0:visits%3==1?1:255);
        lights.reset_work();for(unsigned index=0;index<occupied;++index){check(bool(lights.allocate(nullptr,std::uint8_t(index),7)));check(bool(lights.allocate_auxiliary(nullptr,std::uint8_t(index))));}
        fog.state().selected=std::bit_cast<std::int8_t>(std::uint8_t(selected));fog.state().near_distance=91;fog.state().far_distance=231;std::array<std::byte,4> unsupported{};check(fog.import_fog(unsupported)==s::FogStatus::unsupported_version);
        const auto result=owner.load_room(host->archive());check(result.status==s::CutsceneLightsStatus::completed&&result.initialized);char name[128];std::snprintf(name,sizeof name,"R%03u%02u%02u_LIG",row[0],row[1],row[2]);const auto expected_lig=mode&&keys[row[0]].contains(name);std::snprintf(name,sizeof name,"R%03u%02u%02u_FOG",row[0],row[1],row[2]);const auto expected_fog=mode&&keys[row[0]].contains(name);
        check(result.lighting_read==expected_lig&&result.fog_read==expected_fog);check(bool(result.lighting_import)==expected_lig&&bool(result.fog_import)==expected_fog);check(fog.state().selected==0&&state.frame==0xabcdef01);check(lights.primary_count()<=64&&lights.auxiliary_count()<=64);
        lig_reads+=result.lighting_read;fog_reads+=result.fog_read;if(!mode)++default_misses;++visits;
    }
    check(visits==4086&&lig_reads==1752&&fog_reads==2676&&default_misses==1362);
    const auto epoch=lights.reset_epoch();auto& session=host->world().session();session.asset_loading_mode.reset();check(owner.load_room(host->archive()).status==s::CutsceneLightsStatus::unavailable&&lights.reset_epoch()==epoch);
    session.asset_loading_mode=1;session.scenario=0;check(owner.load_room(host->archive()).status==s::CutsceneLightsStatus::unavailable&&lights.reset_epoch()==epoch);
    host->world().close();check(owner.load_room(host->archive()).status==s::CutsceneLightsStatus::closed&&lights.reset_epoch()==epoch);
    std::cout<<"{\"checks\":"<<checks<<",\"room_keys\":"<<rooms.size()<<",\"visits\":"<<visits<<",\"lighting_reads\":"<<lig_reads<<",\"fog_reads\":"<<fog_reads<<",\"default_misses\":"<<default_misses<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
