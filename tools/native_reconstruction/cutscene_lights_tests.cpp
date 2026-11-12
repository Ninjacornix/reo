#include "game/native/gameplay_scenario/cutscene_lights.hpp"
#include "game/native/gameplay_scenario/cutscene_playback.hpp"
#include "game/native/gameplay_application/session_rooms.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
namespace s=reo::native::gameplay_scenario;namespace a=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;namespace c=reo::native::gameplay_collision;
std::uint64_t checks{},calls{},floor_queries{},floor_hits{},assets{},frames{},bindings{},samples{},callback_guards{},refusals{};unsigned serial{};
const c::response::Grid* original_floor{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Cinematic light owner case "+std::to_string(serial)+" line "+std::to_string(at.line()));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    case 0x107c68:std::memset(memory+GPR_U32(context,4),int(GPR_U32(context,5)&255),GPR_U32(context,6));context->pc=GPR_U32(context,31);return;
    case 0x107ab0:std::memmove(memory+GPR_U32(context,4),memory+GPR_U32(context,5),GPR_U32(context,6));context->pc=GPR_U32(context,31);return;
    case 0x617000:{check(original_floor&&GPR_U32(context,8)==255&&GPR_U32(context,11)==0);const auto point=transform_read<c::Vec3>(memory,GPR_U32(context,4));const auto floor=original_floor->floor(point,255);
        transform_write(memory,GPR_U32(context,9),floor.material);context->f[0]=floor.height;context->pc=GPR_U32(context,31);++floor_queries;if(floor.triangle)++floor_hits;return;}
    default:throw std::runtime_error("Unadmitted cinematic light owner source call "+std::to_string(context->pc));
    }
}
void invoke(std::uint8_t* memory,unsigned address,unsigned a0=0){R5900Context context;PS2Runtime runtime;context.pc=address;SET_GPR_U32(&context,4,a0);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);}
struct Notifications final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
struct GuardRooms final:reo::native::gameplay_contact_world::RoomResources {
    a::SessionRooms& actual;s::CutsceneLights* owner{};s::Lighting* lights{};std::optional<s::LightHandle> release;
    std::optional<std::uint8_t> replacement;
    explicit GuardRooms(a::SessionRooms& value):actual(value){}
    std::shared_ptr<reo::native::gameplay_contact_world::RoomInvocation> retain(std::uint16_t room)override{
        if(owner){check(owner->tick().status==s::CutsceneLightsStatus::busy);check(owner->sample(0).status==s::CutsceneLightsStatus::busy);check(owner->initialize()==s::CutsceneLightsStatus::busy);check(owner->install({})==s::CutsceneLightsStatus::busy);check(owner->clear_bindings()==s::CutsceneLightsStatus::busy);++callback_guards;}
        if(release){check(lights&&lights->release(*release));release.reset();replacement=lights->allocate(nullptr,123,4);check(bool(replacement));}
        return actual.retain(room);
    }
};
int main(int argc,char** argv)try{
    check(argc==3);auto source=std::make_shared<const reo::assets::Source>(argv[1]);Notifications notices;w::Profile profile;profile.layouts.push_back({});auto host=std::make_shared<a::NativeSession>(source,profile,notices);
    check(host->install_room({41,73,0})==a::SessionStatus::completed);a::SessionRooms rooms(host);auto retained=rooms.retain(73);check(retained&&retained->current(retained->identity()));original_floor=&retained->geometry().floors;
    auto& lights=host->lighting();s::Fog fog({});std::array<std::byte,4> unsupported{};check(fog.import_fog(unsupported)==s::FogStatus::unsupported_version);s::CutscenePlaybackState state;GuardRooms guarded(rooms);auto registration=std::make_unique<s::CutsceneLights>(host->world(),state,lights,fog,guarded);auto& owner=*registration;guarded.owner=&owner;guarded.lights=&lights;
    bool duplicate=false;try{s::CutsceneLights other(host->world(),state,lights,fog,rooms);}catch(const std::invalid_argument&){duplicate=true;}check(duplicate);
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());
    const auto project=[&]{
        transform_write(memory.data(),0x3240be,lights.selected());transform_write(memory.data(),0x747538,lights.primary_count());transform_write(memory.data(),0x748340,lights.auxiliary_count());
        std::memcpy(memory.data()+0x747540,lights.primary().data(),64*56);std::memcpy(memory.data()+0x748350,lights.auxiliary().data(),64*56);
        for(unsigned bank=0;bank<4;++bank){const auto at=0x3dc1e0+bank*0x6f4;const auto& value=lights.banks()[bank];transform_write(memory.data(),at,value.kind);transform_write(memory.data(),at+2,value.count);transform_write(memory.data(),at+4,value.base);transform_write(memory.data(),at+56,value.environment_words);std::memcpy(memory.data()+at+112,value.entries.data(),32*52);transform_write(memory.data(),at+0x6f0,value.enabled_mask);}
        for(unsigned index=0;index<32;++index)transform_write(memory.data(),0x7474b0+4*index,lights.bindings()[index]==255?0u:0x747540u+56u*lights.bindings()[index]);
        transform_write(memory.data(),0x3240bd,fog.state().selected);std::fill_n(memory.data()+0x3dbbe0,16*96,0);
    };
    const auto compare=[&]{
        check(std::uint8_t(lights.selected())==memory[0x3240be]&&std::uint8_t(fog.state().selected)==memory[0x3240bd]);
        for(unsigned bank=0;bank<4;++bank)check(lights.banks()[bank].enabled_mask==transform_read<unsigned>(memory.data(),0x3dc1e0+bank*0x6f4+0x6f0));
        for(unsigned index=0;index<32;++index)check(transform_read<unsigned>(memory.data(),0x7474b0+4*index)==(lights.bindings()[index]==255?0u:0x747540u+56u*lights.bindings()[index]));
        check(lights.primary_count()==memory[0x747538]&&lights.auxiliary_count()==memory[0x748340]);
        check(std::memcmp(lights.primary().data(),memory.data()+0x747540,64*56)==0&&std::memcmp(lights.auxiliary().data(),memory.data()+0x748350,64*56)==0);
        for(unsigned group=0;group<32;++group){const auto pointer=transform_read<unsigned>(memory.data(),0x747430+4*group);const auto light=owner.light(group);check(bool(pointer)==bool(light));if(light)check(std::memcmp(&*light,memory.data()+pointer,sizeof *light)==0);}
        const auto pointer=transform_read<unsigned>(memory.data(),0x747420);const auto mirror=owner.mirror();check(bool(pointer)==bool(mirror));if(mirror)check(std::memcmp(&*mirror,memory.data()+pointer,sizeof *mirror)==0);
    };
    std::ifstream manifest(argv[2]);check(bool(manifest));unsigned scenario,area,scene,suffix;std::uint64_t offset;std::size_t length;
    while(manifest>>scenario>>area>>scene>>suffix>>offset>>length){
        ++serial;std::vector<std::byte> bytes(length);source->read(offset,length,bytes.data());const auto descriptor=s::CutsceneDescriptor::import(bytes);const auto tracks=s::prepare_light_tracks(*descriptor);
        const auto groups=descriptor->extension_groups()?descriptor->extension_groups()->size():0;state={};state.light_groups=std::int16_t(groups);host->world().session().clock_mode=std::uint8_t(serial%3==0?0:serial%3==1?1:255);
        lights.reset_work();project();invoke(memory.data(),0x6b3830);check(owner.initialize()==s::CutsceneLightsStatus::completed);compare();invoke(memory.data(),0x6b38d0);check(owner.clear_bindings()==s::CutsceneLightsStatus::completed);check(owner.install(tracks)==s::CutsceneLightsStatus::completed);
        transform_write(memory.data(),0x7434c8,0x38eca0u);transform_write(memory.data(),0x38ecbc,state.light_groups);transform_write(memory.data(),0x3243cc,host->world().session().clock_mode);
        constexpr unsigned base=0xd00000;std::memcpy(memory.data()+base,bytes.data(),bytes.size());std::fill_n(memory.data()+0x38ff90,32*8,0);
        if(descriptor->extension_groups())for(unsigned group=0;group<groups;++group)for(unsigned stream=0;stream<2;++stream){const auto section=(*descriptor->extension_groups())[group][stream];transform_write(memory.data(),0x38ff90+group*8+stream*4,section.count?base+section.offset:0u);}
        for(state.frame=0;state.frame<descriptor->duration();state.frame+=host->world().session().clock_mode?2u:1u){
            transform_write(memory.data(),0x38eca8,state.frame);invoke(memory.data(),0x5ef640);const auto stepped=owner.tick();check(stepped.status==s::CutsceneLightsStatus::completed);bindings+=stepped.bound;
            for(unsigned group=0;group<groups;++group){invoke(memory.data(),0x6b3bb0,group);const auto sampled=owner.sample(std::int8_t(group));check(sampled.status==s::CutsceneLightsStatus::completed);samples+=sampled.sampled;}
            compare();for(unsigned group=0;group<groups;++group)for(unsigned stream=0;stream<2;++stream){const auto pointer=transform_read<unsigned>(memory.data(),0x38ff90+group*8+4*stream);const auto cursor=owner.cursor(group,stream);check(bool(pointer)==bool(cursor));if(cursor)check(pointer==base+(*descriptor->extension_groups())[group][stream].offset+48*unsigned(*cursor));}
            ++frames;
        }
        ++assets;
    }
    check(manifest.eof()&&assets==548&&frames>350000);
    // A guaranteed positive query comes from the real retained floor, rather
    // than assuming every other scene's authored light lies inside this room.
    std::optional<c::Vec3> hit_point;
    for(const auto& triangle:original_floor->triangles()){
        c::Vec3 point;for(const auto& vertex:triangle.vertices){point.x+=vertex.x/3.f;point.y+=vertex.y/3.f;point.z+=vertex.z/3.f;}point.y+=10;
        if(original_floor->floor(point,255).triangle){hit_point=point;break;}
    }
    check(bool(hit_point));std::array<std::array<std::byte,96>,2> probe{};
    for(unsigned stream=0;stream<2;++stream){const auto write=[&](unsigned at,auto value){std::memcpy(probe[stream].data()+at,&value,sizeof value);};write(1,std::int8_t(1));write(6,std::int16_t(stream));write(8,*hit_point);write(32,100.f);write(44,1.f);write(50,std::uint16_t(65535));}
    std::array<std::array<std::span<const std::byte>,2>,1> probe_spans{{{probe[0],probe[1]}}};const auto prepared=s::PreparedLightTracks::import(probe_spans);
    lights.reset_work();project();invoke(memory.data(),0x6b3830);check(owner.initialize()==s::CutsceneLightsStatus::completed);compare();check(owner.install(prepared)==s::CutsceneLightsStatus::completed);invoke(memory.data(),0x6b38d0);
    state.frame=0;state.light_groups=1;transform_write(memory.data(),0x38eca8,state.frame);transform_write(memory.data(),0x38ecbc,state.light_groups);std::memcpy(memory.data()+0xd00000,probe[0].data(),96);std::memcpy(memory.data()+0xd00100,probe[1].data(),96);transform_write(memory.data(),0x38ff90,0xd00000u);transform_write(memory.data(),0x38ff94,0xd00100u);
    invoke(memory.data(),0x5ef640);check(owner.tick().status==s::CutsceneLightsStatus::completed);invoke(memory.data(),0x6b3bb0,0);check(owner.sample(0).status==s::CutsceneLightsStatus::completed);compare();check(floor_hits>0);
    check(owner.sample(-1).status==s::CutsceneLightsStatus::unavailable&&owner.sample(32).status==s::CutsceneLightsStatus::unavailable);
    // Retirement/reuse during the real floor provider cannot retarget a new
    // light generation or resurrect the old canonical pool record.
    const auto selected=std::find_if(lights.primary().begin(),lights.primary().end(),[](const auto& light){return light.active&&light.mode==2;});check(selected!=lights.primary().end());const auto slot=std::uint8_t(selected-lights.primary().begin());guarded.release=lights.handle(slot);check(bool(guarded.release));
    check(owner.sample(0).status==s::CutsceneLightsStatus::unavailable&&guarded.replacement==slot);const auto replacement=lights.handle(slot);check(replacement&&lights.light(*replacement)->tag==123&&lights.light(*replacement)->mode==4);++refusals;
    lights.reset_work();const auto reused=lights.allocate(nullptr,17,7);check(bool(reused));const auto kept=lights.primary()[*reused];check(owner.sample(0).status==s::CutsceneLightsStatus::completed&&std::memcmp(&kept,&lights.primary()[*reused],sizeof kept)==0);
    guarded.owner=nullptr;registration.reset();s::CutsceneLights rebound(host->world(),state,lights,fog,guarded);check(rebound.bound_to(host->world(),state));
    std::cout<<"{\"checks\":"<<checks<<",\"assets\":"<<assets<<",\"frames\":"<<frames<<",\"bindings\":"<<bindings<<",\"samples\":"<<samples<<",\"callback_guards\":"<<callback_guards<<",\"refusals\":"<<refusals<<",\"floor_queries\":"<<floor_queries<<",\"floor_hits\":"<<floor_hits<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
