#include "game/native/gameplay_application/session_actor_services.hpp"
#include "game/native/gameplay_application/session_resources.hpp"
#include "game/native/gameplay_application/session_rooms.hpp"
#include "game/native/gameplay_world/primary_actor_records.hpp"
#include "game/native/gameplay_world/launch_roster.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>

namespace app=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
namespace c=reo::native::gameplay_collision;
namespace e=reo::native::gameplay_effects;
namespace {
constexpr unsigned base=0x4a5c30,stride=0x10e0,stack=0x1f00000;
std::vector<std::uint8_t> memory(0x2000000);
unsigned checks{},cases{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Offline frame case "+std::to_string(cases)+" line "+std::to_string(at.line()));
}
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof(value));}
std::uint32_t next(std::uint32_t& x){x^=x<<13;x^=x>>17;x^=x<<5;return x;}
std::vector<std::byte> read(const char* path){
    std::ifstream in(path,std::ios::binary);const std::vector<char> bytes{std::istreambuf_iterator<char>(in),{}};
    if(bytes.empty())throw std::runtime_error("Owned oracle input unavailable");
    std::vector<std::byte> result(bytes.size());std::memcpy(result.data(),bytes.data(),bytes.size());return result;
}
std::shared_ptr<const e::EffectBank> effects(const char* path){
    std::ifstream in(path,std::ios::binary);unsigned count{};in.read(reinterpret_cast<char*>(&count),4);
    if(count!=12)throw std::runtime_error("Owned effect bank profile unavailable");
    std::array<std::vector<std::byte>,2> bytes;
    for(auto& item:bytes){unsigned size{};in.read(reinterpret_cast<char*>(&size),4);if(!size||size>10000000)throw std::runtime_error("Owned effect bank extent");item.resize(size);in.read(reinterpret_cast<char*>(item.data()),size);if(!in)throw std::runtime_error("Owned effect bank read");}
    return e::EffectBank::import(bytes[0],bytes[1]);
}
struct Notices final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
}
void original_transform_port(std::uint8_t* m,R5900Context* ctx,PS2Runtime* runtime){
    switch(ctx->pc){
    case 0x5f6ee0:o2_005F6EE0_0x5f6ee0(m,ctx,runtime);return;
    case 0x5f6fb0:o2_005F6FB0_0x5f6fb0(m,ctx,runtime);return;
    default:throw std::runtime_error("Unexpected original offline-frame callback");
    }
}
#include "original.cpp"

int main(int argc,char** argv)try{
    if(argc!=6)throw std::runtime_error("archive, contact catalog, effect bank, o9 and o2 inputs required");
    const auto o9=read(argv[4]),o2=read(argv[5]);
    if(o9.size()<0x18f60||o2.size()<0x1aade0)throw std::runtime_error("Owned overlay extent unavailable");
    std::memcpy(memory.data()+0x828ed0,o9.data()+(0x828ed0-0x810000),144);
    std::memcpy(memory.data()+0x71adb0,o2.data()+(0x71adb0-0x570000),32);
    auto source=std::make_shared<const reo::assets::Source>(argv[1]);Notices notices;
    w::Profile profile;profile.layouts.push_back({});profile.entities.capacity=256;
    auto host=std::make_shared<app::NativeSession>(source,profile,notices,1);
    check(host->install_room({41,73,0})==app::SessionStatus::completed);
    check(w::initialize_primary_records(host->world()).status==w::PrimaryRecordsStatus::completed);
    reo::native::gameplay_session::LaunchRoster roster;roster.scenario=41;roster.count=4;
    for(unsigned i=0;i<4;++i)roster.actors[i].model_variant=std::uint16_t(i+1);
    check(w::apply_launch_roster(host->world(),host->update().action_choices(),roster));
    check(host->import_launch_difficulty(1)==app::SessionStatus::completed);
    auto rooms=std::make_shared<app::SessionRooms>(host);
    auto bank=effects(argv[3]);auto catalog=std::make_shared<const c::delivery::Catalog>(c::delivery::Catalog::import(read(argv[2])));
    auto assets=app::SessionResourceAssets::load(host->archive(),41,"DEF41.NBD",bank,catalog);
    check(bool(assets)&&host->bind_resource_assets(assets,rooms)==app::SessionStatus::completed);
    check(host->initialize_resources().status==app::ResourceImportStatus::completed);
    host->world().mode=0; // Controlled offline caller after the admitted ordinary resource bootstrap.
    app::SessionActorServices service(host->update(),host->resources()->actor_operations(),rooms);
    constexpr std::array<std::uint32_t,8> limits{151200,273600,100800,345600,345600,201600,345600,100800};
    std::uint32_t random=0x7135ad9u;
    for(cases=0;cases<2048;++cases){
        for(unsigned i=0;i<8;++i){
            auto actor=host->world().primary(i);auto& state=*actor->ai_execution;const auto at=base+stride*i;
            actor->active=bool((cases+i)&1);actor->character=std::uint8_t((cases+i)&7);actor->ai_control=std::uint8_t((cases>>(3+i))&1);
            actor->maximum=(cases%11==0)?0:100;
            constexpr std::array<std::int16_t,13> health{-1,0,24,25,26,49,50,51,74,75,76,100,101};
            actor->current=health[(cases+3*i)%health.size()];
            const auto maximum=limits[actor->character];
            constexpr std::array<unsigned,11> numerator{0,49,50,79,80,89,90,91,99,100,101};
            auto value=std::uint32_t((std::uint64_t(maximum)*numerator[(cases+i)%numerator.size()])/100u);
            if(cases%17==0)value=0xffffffffu;
            if(cases%19==0)value=std::uint32_t(std::uint64_t(maximum)*9u/10u-1u);
            if(cases%23==0)value=next(random);
            if(cases%29==0)value=std::uint32_t(std::uint64_t(maximum)*8975u/10000u);
            actor->gauge_value=value;actor->status=next(random);actor->motion_class=std::uint8_t(next(random));
            actor->speech.display_style=std::bit_cast<std::int8_t>(std::uint8_t(next(random)));
            state.previous_motion_class_106f=std::uint8_t(next(random));state.previous_display_style_1076=std::uint8_t(next(random));
            state.health_band_1078=std::uint8_t(next(random));state.previous_health_band_1079=std::uint8_t(next(random));
            state.gauge_band_107a=std::uint8_t(next(random));state.previous_gauge_band_107b=std::uint8_t(next(random));
            state.reference_signal=std::uint8_t(next(random));state.weight_mode=std::uint8_t(next(random));
            memory[at]=actor->active;memory[at+0xb98]=actor->character;memory[at+0xff0]=actor->ai_control;
            memory[at+0x54f]=actor->motion_class;put(at+0x544,actor->current);put(at+0x546,actor->maximum);
            put(at+0xba0,actor->status);put(at+0xbac,*actor->gauge_value);
            memory[at+0x1075]=std::bit_cast<std::uint8_t>(*actor->speech.display_style);
            memory[at+0x106f]=state.previous_motion_class_106f;memory[at+0x1076]=state.previous_display_style_1076;
            memory[at+0x1077]=state.weight_mode;memory[at+0x1078]=state.health_band_1078;memory[at+0x1079]=state.previous_health_band_1079;
            memory[at+0x107a]=state.gauge_band_107a;memory[at+0x107b]=state.previous_gauge_band_107b;memory[at+0x1082]=state.reference_signal;
        }
        R5900Context ctx;ctx.pc=0x8122b0;SET_GPR_U32(&ctx,29,stack);SET_GPR_U32(&ctx,31,0x1234);PS2Runtime runtime;
        o9_008122B0_0x8122b0(memory.data(),&ctx,&runtime);check(ctx.pc==0x1234);
        service.begin_offline_frame(host->world());
        for(unsigned i=0;i<8;++i){const auto actor=host->world().primary(i);const auto& state=*actor->ai_execution;const auto at=base+stride*i;
            check(memory[at+0x106f]==state.previous_motion_class_106f&&memory[at+0x1076]==state.previous_display_style_1076);
            check(memory[at+0x1077]==state.weight_mode&&memory[at+0x1078]==state.health_band_1078&&memory[at+0x1079]==state.previous_health_band_1079);
            check(memory[at+0x107a]==state.gauge_band_107a&&memory[at+0x107b]==state.previous_gauge_band_107b&&memory[at+0x1082]==state.reference_signal);
            check(memory[at+0x1075]==std::bit_cast<std::uint8_t>(*actor->speech.display_style)&&memory[at]==actor->active);
        }
    }
    check(host->close()==app::SessionStatus::completed);
    std::cout<<"{\"status\":\"passed\",\"cases\":"<<cases<<",\"checks\":"<<checks<<",\"original_bodies\":[\"8122B0\",\"5F6EE0\",\"5F6FB0\"],\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
