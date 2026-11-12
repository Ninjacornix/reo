#include "native_session.hpp"
#include "runtime/assets/virtual_afs.h"
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace application=reo::native::gameplay_application;
namespace scenario=reo::native::gameplay_scenario;
namespace world=reo::native::gameplay_world;
namespace update=reo::native::gameplay_update;
namespace {
std::size_t checks{},owned_rooms{},script_steps{},frame_refusals{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("NativeSession check at "+std::to_string(at.line()));
}
struct Notifications final:scenario::FlagNotifications {
    bool changed(const scenario::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const scenario::StridedFlagChange&)noexcept override{std::terminate();}
};
struct Memory final:reo::assets::PositionedSource {
    std::vector<std::uint8_t> bytes;
    std::uint64_t size()const noexcept override{return bytes.size();}
    std::size_t read(std::uint64_t offset,std::size_t count,void* destination)const override{
        if(offset>bytes.size()||count>bytes.size()-offset)throw std::runtime_error("Fixture range");
        std::memcpy(destination,bytes.data()+offset,count);return count;
    }
};
world::Profile profile(){world::Profile value;value.layouts.push_back({});return value;}
std::shared_ptr<const reo::assets::Source> fixture_archive(){
    auto memory=std::make_shared<Memory>();memory->bytes.resize(6*4096);
    auto& bytes=memory->bytes;
    std::memcpy(bytes.data(),"AFS\0",4);reo::assets::put32(bytes.data()+4,5);
    const std::array names{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs"};
    for(unsigned i=0;i<5;++i){const auto base=4096*(i+1);
        reo::assets::put32(bytes.data()+8+8*i,base);reo::assets::put32(bytes.data()+12+8*i,4096);
        std::memcpy(bytes.data()+512+48*i,names[i],8);
        std::memcpy(bytes.data()+base,"AFS\0",4);reo::assets::put32(bytes.data()+base+4,1);
        reo::assets::put32(bytes.data()+base+8,2048);reo::assets::put32(bytes.data()+base+12,1);
    }
    reo::assets::put32(bytes.data()+48,512);reo::assets::put32(bytes.data()+52,5*48);
    return std::make_shared<const reo::assets::Source>("native-session-fixture",memory);
}
struct ClosingActor final:world::Actor {
    application::NativeSession* session{};application::SessionStatus* result{};
    ~ClosingActor()override{if(session&&result)*result=session->close();}
};
void fixtures(){
    Notifications notices;application::NativeSession session(fixture_archive(),profile(),notices);
    check(session.open());
    check(session.world().session().timing==&session.update());
    check(session.scene_records()==session.scene_controls().records());
    check(session.scene_records()==session.scene_proxies().records());
    check(session.step_room_script().status==application::SessionStatus::missing_room);
    check(session.install_room({41,73,0})==application::SessionStatus::missing_room);
    check(!session.room()&&!session.update().scripts().channels()[1].program);
    check(session.advance(nullptr,nullptr).status==application::SessionStatus::missing_room);
    application::SessionStatus callback_status=application::SessionStatus::completed;
    auto actor=std::make_unique<ClosingActor>();actor->session=&session;actor->result=&callback_status;
    check(bool(session.world().spawn_primary(0,std::move(actor)).id));
    check(session.close()==application::SessionStatus::completed&&callback_status==application::SessionStatus::busy);
    check(!session.open()&&session.world().session().timing==nullptr);
    check(session.step_room_script().status==application::SessionStatus::closed);
    check(session.install_room({41,73,0})==application::SessionStatus::closed);
    check(session.advance(nullptr,nullptr).status==application::SessionStatus::closed);
    check(session.close()==application::SessionStatus::completed);
}
void canonical_step(){
    Notifications notices;world::World native_world(profile(),std::make_shared<world::Session>());update::Owner owner(native_world,notices);
    native_world.mode=1;
    std::vector<std::byte> bytes(20);const std::array<std::uint32_t,5> words{0x02000110u,0u,77u,0u,0xau};std::memcpy(bytes.data(),words.data(),20);
    check(owner.scripts().install(0,std::make_shared<const scenario::Program>(std::vector<std::vector<std::byte>>{bytes}))==scenario::Status::completed);
    scenario::FlagState foreign_flags;scenario::Providers providers;providers.flags=&foreign_flags;
    check(owner.step_script(0,providers).status==update::Status::script_failure&&owner.scripts().counters()[0]==0);
    providers={};providers.canonical_flags=&foreign_flags;
    check(owner.step_script(0,providers).status==update::Status::script_failure&&owner.scripts().counters()[0]==0);
    world::World foreign_world(profile(),std::make_shared<world::Session>());providers={};providers.world=&foreign_world;
    check(owner.step_script(0,providers).status==update::Status::script_failure&&owner.scripts().counters()[0]==0);
    reo::native::gameplay_tasks::FlagTimers foreign_timers;providers={};providers.timers=&foreign_timers;
    check(owner.step_script(0,providers).status==update::Status::script_failure&&owner.scripts().counters()[0]==0);
    const auto stepped=owner.step_script(0);
    check(stepped.status==update::Status::completed&&owner.scripts().counters()[0]==77&&stepped.script_operations==2);
    check(!stepped.clock_committed&&owner.clock().update_counter()==0&&!owner.busy());
    check(owner.step_script(99).status==update::Status::script_failure);
}
void owned(const std::filesystem::path& path){
    auto source=std::make_shared<const reo::assets::Source>(path);Notifications notices;
    for(const auto mode:{std::uint8_t(1),std::uint8_t(0)})for(bool terminal:{false,true}){
        application::NativeSession session(source,profile(),notices,mode);
        check(session.install_room({41,73,0})==application::SessionStatus::completed);++owned_rooms;
        check(session.room()&&session.world().scenario==41&&session.world().room==73);
        check(session.room_scene()&&session.room_scene()->identities().size()==7);
        check(session.scene_controls().size()==7&&session.scene_proxies().size()==7);
        check(session.scene_records()==session.scene_controls().records()&&session.scene_records()==session.scene_proxies().records());
        check(session.scene_matrices().bound_to(session.scene_controls(),session.scene_models()));
        check(session.scene_matrices().bound_to_records(*session.scene_records(),session.update().flags(),session.world().room));
        check(session.lighting().banks()[0].kind==1&&session.lighting().banks()[0].count==20);
        const auto& channels=session.update().scripts().channels();check(channels[1].program&&channels[1].current==scenario::Position{8,0});
        check(channels[1].program->profile()==(mode?scenario::DispatchProfile::ordinary:scenario::DispatchProfile::offline_actor));
        if(!mode){
            check(channels[2].program==channels[1].program&&channels[3].program==channels[1].program);
            check(session.step_room_script().status==application::SessionStatus::missing_providers);
            for(unsigned i=0;i<3;++i){auto actor=std::make_unique<world::Actor>();actor->active=true;actor->slot=std::uint8_t(i);actor->room=73;
                check(bool(session.world().spawn_primary(i,std::move(actor)).id));}
        }
        if(terminal)for(unsigned bit=0;bit<2;++bit)check(session.update().flags().strided(73,bit,2,true,false));
        const auto flags=session.update().flags().snapshot();
        const auto before=channels[1].current;const auto records=session.scene_records();
        check(session.advance(nullptr,nullptr).status==application::SessionStatus::missing_frame_services);++frame_refusals;
        check(channels[1].current==before&&session.update().clock().update_counter()==0);
        for(unsigned pass=0;pass<3;++pass){const auto result=session.step_room_script();
            check(result.status==application::SessionStatus::completed&&result.update.script_operations>0&&!result.update.clock_committed);++script_steps;}
        check(session.update().clock().update_counter()==0&&session.world().selected_actor==0);
        check(session.scene_channels().mask()==0xffffffffu&&session.lighting().selected()==0);
        check(session.lighting().primary_count()>0);
        for(unsigned index=0;index<2;++index){const auto id=session.room_scene()->identities()[index*2];const auto control=session.scene_controls().get(id);
            check(control&&std::get<scenario::ControlTypeZero>(control->body).refresh_parameter==1);
            const auto matrix=session.scene_matrices().inspect(index);check(bool(matrix));
            if(terminal)check(matrix->progress==2&&matrix->playback==0&&matrix->cursor==1);else check(matrix->progress==0&&matrix->playback==0);}
        check(session.update().flags().snapshot().shared.scenario==flags.shared.scenario);
        check(session.install_room({41,99,0})==application::SessionStatus::missing_room&&session.scene_records()==records);
        check(session.update().scripts().channels()[1].program==channels[1].program);
        const auto stale=session.room_scene()->identities().front();
        check(session.install_room({41,73,0})==application::SessionStatus::completed);
        check(!records->acquire(stale)&&session.scene_records()!=records&&session.scene_controls().size()==7);
        check(session.close()==application::SessionStatus::completed&&session.scene_controls().size()==0);
    }
}
}
int main(int argc,char** argv)try{
    fixtures();canonical_step();check(argc==1||argc==2);
    if(argc==2){const std::string_view value(argv[1]);owned(std::filesystem::path(std::u8string(value.begin(),value.end())));}
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"owned_rooms\":"<<owned_rooms<<",\"script_steps\":"<<script_steps<<",\"frame_refusals\":"<<frame_refusals<<",\"game_launched\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
