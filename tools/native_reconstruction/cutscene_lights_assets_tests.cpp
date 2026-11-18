#include "game/native/gameplay_scenario/cutscene_lights.hpp"
#include "game/native/gameplay_scenario/cutscene_playback.hpp"
#include "game/native/gameplay_application/session_rooms.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <source_location>
namespace s=reo::native::gameplay_scenario;namespace a=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace {
std::uint64_t checks{},assets{},frames{},bindings{},samples{},guards{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Owned cinematic light check "+std::to_string(at.line()));
}
struct Notices final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
struct Rooms final:reo::native::gameplay_contact_world::RoomResources {
    a::SessionRooms& actual;s::CutsceneLights* worker{};
    explicit Rooms(a::SessionRooms& value):actual(value){}
    std::shared_ptr<reo::native::gameplay_contact_world::RoomInvocation> retain(std::uint16_t room)override{
        if(worker){check(worker->busy()&&worker->tick().status==s::CutsceneLightsStatus::busy&&worker->sample(0).status==s::CutsceneLightsStatus::busy);check(worker->initialize()==s::CutsceneLightsStatus::busy&&worker->clear_bindings()==s::CutsceneLightsStatus::busy);++guards;}
        return actual.retain(room);
    }
};
}
int main(int argc,char** argv)try{
    check(argc==3);auto source=std::make_shared<const reo::assets::Source>(argv[1]);Notices notices;w::Profile profile;profile.layouts.push_back({});auto host=std::make_shared<a::NativeSession>(source,profile,notices);
    check(host->install_room({41,73,0})==a::SessionStatus::completed);a::SessionRooms actual(host);Rooms rooms(actual);auto retained=actual.retain(73);check(retained&&retained->current(retained->identity()));
    s::Fog fog({});std::array<std::byte,4> unsupported{};check(fog.import_fog(unsupported)==s::FogStatus::unsupported_version);s::CutscenePlaybackState state;s::CutsceneLights owner(host->world(),state,host->lighting(),fog,rooms);rooms.worker=&owner;
    bool duplicate=false;try{s::CutsceneLights other(host->world(),state,host->lighting(),fog,rooms);}catch(const std::invalid_argument&){duplicate=true;}check(duplicate&&owner.bound_to(host->world(),state));
    std::ifstream manifest(argv[2]);check(bool(manifest));unsigned scenario,area,scene,suffix;std::uint64_t offset;std::size_t length;
    while(manifest>>scenario>>area>>scene>>suffix>>offset>>length){
        std::vector<std::byte> bytes(length);source->read(offset,length,bytes.data());const auto descriptor=s::CutsceneDescriptor::import(bytes);const auto tracks=s::prepare_light_tracks(*descriptor);
        auto& lights=host->lighting();lights.reset_work();check(owner.initialize()==s::CutsceneLightsStatus::completed&&owner.install(tracks)==s::CutsceneLightsStatus::completed);
        state={};state.light_groups=std::int16_t(descriptor->extension_groups()?descriptor->extension_groups()->size():0);host->world().session().clock_mode=std::uint8_t(assets%3==0?0:assets%3==1?1:255);
        const auto primary=lights.primary_count(),auxiliary=lights.auxiliary_count();check(primary>=32&&auxiliary==1);
        for(unsigned group=0;group<32;++group){const auto light=owner.light(group);check(light&&light->active&&light->mode==3);}
        for(state.frame=0;state.frame<descriptor->duration();state.frame+=host->world().session().clock_mode?2u:1u){
            const auto tick=owner.tick();check(tick.status==s::CutsceneLightsStatus::completed&&!owner.busy());bindings+=tick.bound;
            for(unsigned group=0;group<unsigned(state.light_groups);++group){const auto sampled=owner.sample(std::int8_t(group));check(sampled.status==s::CutsceneLightsStatus::completed&&!owner.busy());samples+=sampled.sampled;}
            check(lights.primary_count()==primary&&lights.auxiliary_count()==auxiliary);++frames;
        }
        ++assets;
    }
    check(manifest.eof()&&assets==548&&frames>350000&&bindings>3000&&samples>500000&&guards>500000);
    check(owner.sample(-1).status==s::CutsceneLightsStatus::unavailable&&owner.sample(32).status==s::CutsceneLightsStatus::unavailable);
    rooms.worker=nullptr;
    std::cout<<"{\"checks\":"<<checks<<",\"assets\":"<<assets<<",\"frames\":"<<frames<<",\"bindings\":"<<bindings<<",\"samples\":"<<samples<<",\"callback_guards\":"<<guards<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
