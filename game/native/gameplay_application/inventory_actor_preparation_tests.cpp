#include "native_session.hpp"
#include "runtime/assets/virtual_afs.h"
#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <memory>
#include <source_location>
#include <stdexcept>
#include <vector>

namespace a=reo::native::gameplay_application;
namespace s=reo::native::gameplay_scenario;
namespace w=reo::native::gameplay_world;
namespace {
unsigned checks{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Inventory actor preparation check at "+std::to_string(at.line()));
}
struct Notices final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return false;}
    bool changed(const s::StridedFlagChange&)noexcept override{return false;}
};
struct Memory final:reo::assets::PositionedSource {
    std::vector<std::uint8_t> bytes;
    std::uint64_t size()const noexcept override{return bytes.size();}
    std::size_t read(std::uint64_t offset,std::size_t count,void* destination)const override{
        if(offset>bytes.size()||count>bytes.size()-offset)throw std::runtime_error("Inventory fixture range");
        std::memcpy(destination,bytes.data()+offset,count);return count;
    }
};
std::shared_ptr<const reo::assets::Source> archive(){
    auto memory=std::make_shared<Memory>();memory->bytes.resize(6*4096);auto& bytes=memory->bytes;
    std::memcpy(bytes.data(),"AFS\0",4);reo::assets::put32(bytes.data()+4,5);
    const std::array names{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs"};
    for(unsigned i=0;i<5;++i){const auto base=4096*(i+1);
        reo::assets::put32(bytes.data()+8+8*i,base);reo::assets::put32(bytes.data()+12+8*i,4096);
        std::memcpy(bytes.data()+512+48*i,names[i],8);
        std::memcpy(bytes.data()+base,"AFS\0",4);reo::assets::put32(bytes.data()+base+4,1);
        reo::assets::put32(bytes.data()+base+8,2048);reo::assets::put32(bytes.data()+base+12,1);
    }
    reo::assets::put32(bytes.data()+48,512);reo::assets::put32(bytes.data()+52,5*48);
    return std::make_shared<const reo::assets::Source>("inventory-actor-preparation-fixture",memory);
}
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
}
int main()try{
    Notices notices;a::NativeSession session(archive(),profile(),notices);
    auto& world=session.world();auto& ui=session.inventory_ui();
    auto actor=std::make_unique<w::Actor>();actor->category=0;actor->slot=0;
    const auto id=world.spawn_primary(0,std::move(actor)).id;check(bool(id));
    const auto primary=world.resolve(id);check(bool(primary));

    check(ui.dialogue_suppressed()==false);
    world.session().inventory_owner=0;
    check(ui.prepare_actor(*primary)==w::InventoryUiStatus::completed&&world.session().inventory_owner==0);
    world.session().inventory_owner=2;
    check(ui.prepare_actor(*primary)==w::InventoryUiStatus::completed&&world.session().inventory_owner==2);
    world.session().inventory_owner=5;
    check(ui.prepare_actor(*primary)==w::InventoryUiStatus::completed&&world.session().inventory_owner==5);

    world.session().inventory_owner=1;
    check(ui.prepare_actor(*primary)==w::InventoryUiStatus::completed&&world.session().inventory_owner==0);
    check(ui.dialogue_suppressed()==false);

    // The original active session-state branch returns for a valid owner tag;
    // it must preserve the owner and must not pretend that 6E1430 ran.
    world.session().inventory_owner=1;world.session().session_state=1;
    primary->status=0x8000;
    check(ui.prepare_actor(*primary)==w::InventoryUiStatus::completed);
    check(world.session().inventory_owner==1&&primary->status==0x8000);

    // Non-primary actors return before owner matching or suppression.
    auto auxiliary=std::make_unique<w::Actor>();auxiliary->category=1;auxiliary->slot=0;
    const auto auxiliary_id=world.spawn_linked(std::move(auxiliary)).id;check(bool(auxiliary_id));
    const auto linked=world.resolve(auxiliary_id);check(bool(linked));
    world.session().session_state=0;world.session().inventory_owner=1;
    check(ui.prepare_actor(*linked)==w::InventoryUiStatus::completed&&world.session().inventory_owner==1);

    // Actor capabilities must resolve in the InventoryUi's canonical World.
    w::World foreign(profile(),std::make_shared<w::Session>());
    w::Actor detached;
    check(ui.prepare_actor(detached)==w::InventoryUiStatus::unavailable_actor);
    const auto foreign_id=foreign.spawn_primary(0,std::make_unique<w::Actor>()).id;
    check(bool(foreign_id)&&ui.prepare_actor(*foreign.resolve(foreign_id))==w::InventoryUiStatus::unavailable_actor);

    check(session.close()==a::SessionStatus::completed);
    check(ui.dialogue_suppressed()==std::nullopt);
    check(ui.prepare_actor(*primary)==w::InventoryUiStatus::closed);
    std::cout<<"Inventory actor preparation passed "<<checks<<" checks (no active-menu close claimed)\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
