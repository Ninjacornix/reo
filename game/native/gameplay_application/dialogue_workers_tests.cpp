#include "native_session.hpp"
#include "../gameplay_world/inventory_dialogue_presentation.hpp"
#include "../gameplay_world/dialogue_pool.hpp"
#include "../gameplay_world/primary_actor_records.hpp"
#include "../gameplay_update/dialogue_workers.hpp"
#include "runtime/assets/virtual_afs.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
namespace app=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace u=reo::native::gameplay_update;
namespace s=reo::native::gameplay_scenario;
namespace {
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Canonical dialogue worker contract "+std::to_string(checks));}
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
struct CatalogBytes final:reo::assets::PositionedSource {
    std::vector<std::uint8_t> bytes;
    std::uint64_t size()const noexcept override{return bytes.size();}
    std::size_t read(std::uint64_t at,std::size_t count,void* destination)const override{if(at>bytes.size()||count>bytes.size()-at)throw std::runtime_error("Dialogue catalog fixture range");std::memcpy(destination,bytes.data()+at,count);return count;}
};
std::shared_ptr<const reo::assets::Source> catalog_fixture(){
    auto memory=std::make_shared<CatalogBytes>();memory->bytes.resize(6*4096);auto& b=memory->bytes;std::memcpy(b.data(),"AFS\0",4);reo::assets::put32(b.data()+4,5);
    const std::array names{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs"};
    for(unsigned i=0;i<5;++i){const auto at=4096*(i+1);reo::assets::put32(b.data()+8+8*i,at);reo::assets::put32(b.data()+12+8*i,4096);std::memcpy(b.data()+512+48*i,names[i],8);std::memcpy(b.data()+at,"AFS\0",4);reo::assets::put32(b.data()+at+4,1);reo::assets::put32(b.data()+at+8,2048);reo::assets::put32(b.data()+at+12,1);}
    reo::assets::put32(b.data()+48,512);reo::assets::put32(b.data()+52,5*48);return std::make_shared<const reo::assets::Source>("dialogue-contract-catalog",memory);
}
struct Notifications final:s::FlagNotifications{bool changed(const s::ScenarioFlagChange&)noexcept override{return false;}bool changed(const s::StridedFlagChange&)noexcept override{return false;}};
struct Remaining final:u::PhaseServices {
    unsigned calls{};u::Worker stage{};u::Owner* owner{};std::optional<std::uint32_t> at_occupancy;
    void run(u::Worker value,u::Owner& actor)override{++calls;stage=value;owner=&actor;if(value==u::Worker::room_occupancy)at_occupancy=actor.world().session().auxiliary_scene.timer(91);}
    bool button(u::Button,u::Owner&)override{return true;}
    bool transition_request(u::Owner&)override{return false;}
    void effect(u::PhaseEffect,u::Owner&,std::uint32_t)override{}
};
struct InactiveActors final:w::Services {
    void begin_offline_frame(w::World&)override{throw std::runtime_error("Unexpected offline actor stage");}
    void run(w::Stage,w::World&,w::Actor&)override{throw std::runtime_error("Unexpected active actor stage");}
    bool remote_motion(w::World&,w::Actor&)override{throw std::runtime_error("Unexpected remote actor stage");}
    bool find_grid(w::World&,w::Actor&,std::int8_t&)override{throw std::runtime_error("Unexpected grid actor stage");}
    void switch_grid(w::World&,std::int32_t,std::int32_t)override{throw std::runtime_error("Unexpected grid switch");}
    float grid_response(w::World&,std::uint8_t)override{throw std::runtime_error("Unexpected grid response");}
};
}
int main(int argc,char** argv)try{
    check(argc==1||argc==2);Notifications notifications;auto source=argc==2?std::make_shared<const reo::assets::Source>(argv[1]):catalog_fixture();app::NativeSession session(source,profile(),notifications),other(source,profile(),notifications);
    auto& world=session.world();check(w::initialize_primary_records(world).status==w::PrimaryRecordsStatus::completed);world.session().primary_population=2;world.primary(0)->slot=0;world.primary(1)->slot=1;world.primary(1)->character=1;
    s::TextCache cache;w::InventoryDialoguePresentation display(world,cache,session.inventory_ui());check(display.bound_to(world)&&!display.bound_to(other.world())&&display.suppressed()==false);
    bool foreign{};try{w::InventoryDialoguePresentation bad(other.world(),cache,session.inventory_ui());}catch(const std::invalid_argument&){foreign=true;}check(foreign);
    const std::array text{std::byte{'A'}};check(!display.draw(100,321,text,128));cache.reset();check(display.draw(101,321,text,91));const auto retained=cache.snapshot();check(retained&&(*retained)[0].active&&display.erase(text)&&!(*cache.snapshot())[0].active&&(*retained)[0].alpha==91);
    auto& shared=world.session().auxiliary_scene;shared.select(5);shared.publish_loaded_index(42);check(shared.set_timer(91,true));shared.advance_timers();check(shared.timer(91)==1);
    w::DialoguePool pool(world,nullptr,&display);check(pool.initialize_owned_state()==w::DialogueStatus::completed&&shared.timer(91)==0&&shared.timer_active(91)==false&&shared.row()==5&&shared.loaded_index()==42);
    Remaining remaining;w::input::Frame menu;std::optional<std::uint32_t> actions=0;u::DialogueWorkers worker(session.update(),remaining,pool,session.inventory_ui(),&menu,actions);
    worker.run(u::Worker::room_sound_callbacks,session.update());check(remaining.calls==1&&remaining.stage==u::Worker::room_sound_callbacks&&remaining.owner==&session.update());check(worker.button(u::Button::primary,session.update())&&!worker.transition_request(session.update()));
    check(!session.inventory_ui().request_blocked());world.paused=1;worker.run(u::Worker::sequences,session.update());check(worker.last_result()&&worker.last_result()->status==w::DialogueStatus::completed&&remaining.calls==1);
    world.paused=0;bool refused{};try{worker.run(u::Worker::sequences,session.update());}catch(const std::runtime_error&){refused=true;}check(refused&&worker.last_result()->status==w::DialogueStatus::unavailable&&worker.last_result()->stage==w::DialogueResponseStage::records);
    check(session.inventory_ui().configure_requests(1)==w::InventoryUiStatus::completed&&session.inventory_ui().request_blocked()==1);
    worker.run(u::Worker::sequences,session.update());check(worker.last_result()->status==w::DialogueStatus::completed&&worker.last_result()->actors==2);
    check(session.inventory_ui().initialize()==w::InventoryUiStatus::completed&&session.inventory_ui().request_blocked()==1&&display.suppressed()==false);
    check(session.inventory_ui().configure_requests(0)==w::InventoryUiStatus::unavailable_request_reset&&session.inventory_ui().request_blocked()==1);
    check(shared.set_timer(91,true)&&pool.flag(91)==true&&pool.flag_duration(91)==0);
    worker.run(u::Worker::sequences,session.update());check(shared.timer(91)==0&&pool.flag_duration(91)==0);
    world.mode=1;world.session().scenario=0;check(session.update().initialize_completion_statistics()==reo::native::gameplay_events::StatisticsStatus::completed);
    const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{{std::byte{1},{},{},{},std::byte{0xa},{},{},{}}});
    check(session.update().scripts().install(0,program)==s::Status::completed&&session.update().scripts().install(1,program)==s::Status::completed);
    InactiveActors actors;check(session.update().run_workers(worker,actors).status==u::Status::completed);check(shared.timer(91)==1&&pool.flag_duration(91)==1&&remaining.at_occupancy==1);
    world.paused=1;check(session.update().run_workers(worker,actors).status==u::Status::completed&&shared.timer(91)==1);world.paused=0;
    const auto forwarded=remaining.calls;
    foreign=false;try{worker.run(u::Worker::sequences,other.update());}catch(const std::invalid_argument&){foreign=true;}check(foreign&&remaining.calls==forwarded);
    check(worker.close()==u::Status::completed);refused=false;try{worker.run(u::Worker::sequences,session.update());}catch(const std::invalid_argument&){refused=true;}check(refused);
    check(session.close()==app::SessionStatus::completed&&!display.bound_to(world)&&!display.suppressed()&&!display.erase(text));check((*retained)[0].active&&(*retained)[0].alpha==91);
    std::cout<<"Canonical dialogue worker contract passed "<<checks<<" checks\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
