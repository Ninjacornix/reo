#include "session_startup.hpp"
#include "runtime/assets/virtual_afs.h"
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace app=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
namespace u=reo::native::gameplay_update;
namespace {
unsigned checks{},startups{},models{},guards{},refusals{},lifetimes{},script_steps{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Session startup check "+std::to_string(at.line()));}
struct Notifications final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
struct Memory final:reo::assets::PositionedSource {
    std::vector<std::uint8_t> bytes;
    std::uint64_t size()const noexcept override{return bytes.size();}
    std::size_t read(std::uint64_t at,std::size_t count,void* out)const override{
        if(at>bytes.size()||count>bytes.size()-at)throw std::runtime_error("Startup fixture source range");
        std::memcpy(out,bytes.data()+at,count);return count;
    }
};
std::shared_ptr<const reo::assets::Source> fixture_source(){
    auto source=std::make_shared<Memory>();auto& bytes=source->bytes;bytes.resize(6*4096+3*1024*1024);
    std::memcpy(bytes.data(),"AFS\0",4);reo::assets::put32(bytes.data()+4,6);
    const std::array names{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs","romdata_usa.afs"};
    for(unsigned i=0;i<6;++i){const unsigned base=(i+1)*4096,size=i==5?3*1024*1024:4096;reo::assets::put32(bytes.data()+8+8*i,base);reo::assets::put32(bytes.data()+12+8*i,size);std::memcpy(bytes.data()+512+48*i,names[i],std::strlen(names[i]));std::memcpy(bytes.data()+base,"AFS\0",4);const unsigned count=i==5?1342:1;reo::assets::put32(bytes.data()+base+4,count);for(unsigned member=0;member<count;++member){reo::assets::put32(bytes.data()+base+8+8*member,i==5?16384+2048*member:2048);reo::assets::put32(bytes.data()+base+12+8*member,1);}}
    reo::assets::put32(bytes.data()+56,512);reo::assets::put32(bytes.data()+60,6*48);
    return std::make_shared<const reo::assets::Source>("explicit startup fixture",source);
}
void fixtures(){
    const auto source=fixture_source();Notifications notices;app::NativeSession session(source,profile(),notices);
    const auto records=session.scene_records();bool refused{};
    try{app::SessionStartup invalid(session,source,{});}catch(const std::invalid_argument&){refused=true;}
    check(refused&&!session.world().humanoid_motion_source()&&!session.world().humanoid_motion_source_closed());++refusals;
    app::SessionStartup startup(session,source,w::HumanoidMotionAssets::initial_banks(false));
    check(startup.bound_to(session)&&startup.open()&&session.world().humanoid_motion_source()==&startup.motion_owner());
    check(startup.initialize_records().status==w::PrimaryRecordsStatus::completed);
    check(startup.initialize_records().status==w::PrimaryRecordsStatus::not_empty);++refusals;
    for(unsigned i=0;i<8;++i)check(session.world().primary(i)&&session.world().primary(i)->slot==0);
    refused=false;try{app::SessionStartup duplicate(session,source,w::HumanoidMotionAssets::initial_banks(false));}catch(const std::invalid_argument&){refused=true;}
    check(refused&&session.world().humanoid_motion_source()==&startup.motion_owner());++refusals;
    session.world().session().primary_population=0;
    const auto unavailable=startup.start(nullptr);check(unavailable.status==w::PrimaryStartupStatus::unavailable&&unavailable.stage==w::PrimaryStartupStage::background&&session.world().session().setup_gate==2&&startup.last_result());++refusals;
    check(session.scene_records()==records&&session.world().session().timing==&session.update());
    check(startup.close()==w::PrimaryStartupStatus::completed&&!startup.last_result()&&!startup.open());
    check(startup.start(nullptr).status==w::PrimaryStartupStatus::closed&&startup.initialize_records().status==w::PrimaryRecordsStatus::closed);++refusals;
    check(session.close()==app::SessionStatus::completed&&startup.close()==w::PrimaryStartupStatus::completed);
    app::NativeSession second(source,profile(),notices);app::SessionStartup later(second,source,w::HumanoidMotionAssets::initial_banks(false));
    check(later.initialize_records().status==w::PrimaryRecordsStatus::completed);const auto retained=second.world().primary(0);const auto id=second.world().identity(0);
    check(second.close()==app::SessionStatus::completed&&later.close()==w::PrimaryStartupStatus::completed&&!second.world().resolve(id)&&retained->slot==0);++lifetimes;
}
struct Effects final:w::PrimaryStartupEffects {
    app::NativeSession& session;app::SessionStartup& startup;std::shared_ptr<reo::native::gameplay_scene::Records> records;
    std::vector<w::PrimaryStartupWork> work;unsigned voices{},backgrounds{},stream_initializations{};bool failed_once{};
    Effects(app::NativeSession& value,app::SessionStartup& capabilities):session(value),startup(capabilities),records(session.scene_records()){}
    bool bound_to(const w::World& value)const noexcept override{return &value==&session.world();}
    w::PrimaryStartupStatus guard(){
        check(session.world().busy()&&session.close()==app::SessionStatus::busy&&startup.close()==w::PrimaryStartupStatus::busy);
        check(session.install_room({41,73,0})==app::SessionStatus::busy&&session.step_room_script().status==app::SessionStatus::busy&&session.advance(nullptr,nullptr).status==app::SessionStatus::busy);
        check(startup.start(this).status==w::PrimaryStartupStatus::busy&&startup.initialize_records().status==w::PrimaryRecordsStatus::busy&&session.update().close()==u::Status::busy);
        check(session.scene_records()==records&&records==session.scene_controls().records()&&records==session.scene_proxies().records());++guards;
        return w::PrimaryStartupStatus::completed;
    }
    w::PrimaryStartupStatus voice_archive(std::uint8_t slot,std::uint8_t character)override{check(slot<5&&character<8);++voices;return guard();}
    w::PrimaryStartupStatus background(std::uint8_t value)override{check(value==0);++backgrounds;return guard();}
    w::PrimaryStartupStatus initialize_stream_stage()override{++stream_initializations;return guard();}
    w::PrimaryStartupStatus run(w::PrimaryStartupWork value)override{work.push_back(value);const auto result=guard();if(value==w::PrimaryStartupWork::scenario_sound&&!failed_once){failed_once=true;return w::PrimaryStartupStatus::unavailable;}return result;}
    w::PrimaryStartupStatus actor_resources(w::PrimaryStartupWork value,const w::actors::EntityId& id)override{check((value==w::PrimaryStartupWork::actor_equipment||value==w::PrimaryStartupWork::actor_secondary_resources)&&session.world().resolve(id));return guard();}
    std::optional<std::int8_t> roster_kind(std::uint8_t row)const noexcept override{return row<4?std::optional<std::int8_t>(0):std::nullopt;}
    std::optional<float> reference_height(std::uint8_t character)const noexcept override{return character<8?std::optional(float(character)+2.f):std::nullopt;}
};
void owned(const char* path){
    const auto source=std::make_shared<const reo::assets::Source>(path);Notifications notices;
    for(unsigned mode:{0u,1u})for(unsigned population:{1u,4u,8u}){
        app::NativeSession session(source,profile(),notices,std::uint8_t(mode));
        check(session.install_room({41,73,0})==app::SessionStatus::completed);const auto records=session.scene_records();
        check(session.scene_controls().size()==7&&session.scene_proxies().size()==7&&session.room_scene());
        app::SessionStartup startup(session,source,w::HumanoidMotionAssets::initial_banks(false));
        check(startup.initialize_records().status==w::PrimaryRecordsStatus::completed);
        auto& state=session.world().session();state.primary_population=population;state.asset_loading_mode=1;state.scene_stream_stage=0;
        for(unsigned i=0;i<8;++i){const auto actor=session.world().primary(i);check(actor->slot==0);actor->character=std::uint8_t(i);actor->ai_control=std::uint8_t(i&1);}
        Effects effects(session,startup);const auto interrupted=startup.start(&effects);
        check(interrupted.status==w::PrimaryStartupStatus::unavailable&&interrupted.stage==w::PrimaryStartupStage::scenario_sound&&state.setup_gate==2&&!session.world().busy());++refusals;
        std::array<std::shared_ptr<w::Actor>,8> retained;std::array<std::shared_ptr<reo::native::animation::Instance>,8> models_before;
        std::array<w::actors::EntityId,8> identities;
        for(unsigned i=0;i<8;++i){retained[i]=session.world().primary(i);models_before[i]=retained[i]->model;identities[i]=session.world().identity(i);}
        const auto completed=startup.start(&effects);check(completed.status==w::PrimaryStartupStatus::completed&&completed.models_applied==population&&completed.gauges_initialized==population&&state.setup_gate==0&&state.scene_stream_stage==0);++startups;
        check(effects.stream_initializations==1&&effects.backgrounds==3&&effects.voices==2*std::min(population,5u)&&startup.motion_owner().snapshot()->base_loaded());
        check(session.scene_records()==records&&records==session.scene_controls().records()&&records==session.scene_proxies().records()&&session.world().session().timing==&session.update());
        for(unsigned i=0;i<8;++i){check(retained[i]==session.world().primary(i)&&retained[i]->model==models_before[i]&&retained[i]->slot==(i<population?i:0));if(i<population){check(retained[i]->active&&retained[i]->model&&retained[i]->animation&&retained[i]->animation->model()==retained[i]->model);++models;}}
        check(session.update().clock().update_counter()==0);const auto script=session.step_room_script();check(script.status==app::SessionStatus::completed&&script.update.script_operations>0&&!script.update.clock_committed);++script_steps;
        check(startup.close()==w::PrimaryStartupStatus::completed&&session.close()==app::SessionStatus::completed);
        for(unsigned i=0;i<population;++i){check(retained[i]->model==models_before[i]&&!session.world().resolve(identities[i]));++lifetimes;}
    }
}
}
int main(int argc,char** argv)try{check(argc==1||argc==2);fixtures();if(argc==2)owned(argv[1]);std::cout<<"{\"checks\":"<<checks<<",\"canonical_startups\":"<<startups<<",\"models\":"<<models<<",\"busy_guards\":"<<guards<<",\"refusals\":"<<refusals<<",\"lifetimes\":"<<lifetimes<<",\"owned_room_script_steps\":"<<script_steps<<",\"game_run\":false}\n";}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
