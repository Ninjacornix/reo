#include "game/native/gameplay_application/native_session.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include <iostream>
#include <type_traits>
#include <vector>
#include "functions.h"
namespace a=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},constructors{},commands{},recovery_closes{},calls{};
void check(bool value,const char* message){++checks;if(!value)throw std::runtime_error(message);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x107c68:check(GPR_U32(context,4)==0x755ec0&&GPR_U32(context,5)==0&&GPR_U32(context,6)==0x3e84,"complete actual UI domain clear");std::memset(memory+GPR_U32(context,4),0,GPR_U32(context,6));break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted active inventory UI consumer "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
struct Notifications:s::FlagNotifications{
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
void call(std::vector<std::uint8_t>& memory,std::uint32_t at){R5900Context context;PS2Runtime runtime;context.pc=at;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x123456);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0x123456,"complete original UI function returns");}
int main(int argc,char** argv)try{
    static_assert(!std::is_constructible_v<w::InventoryUi,w::World&>);
    check(argc==2,"owned archive required");auto source=std::make_shared<const reo::assets::Source>(std::filesystem::path(argv[1]));
    Notifications notifications;w::Profile profile;profile.layouts.push_back({});a::NativeSession session(source,profile,notifications);auto& world=session.world();auto& ui=session.inventory_ui();w::RecoveryUi& recovery=ui;
    std::vector<std::uint8_t> memory(0x2000000);constexpr unsigned actors=0x4a5c30,stride=0x10e0;
    for(unsigned slot=0;slot<8;++slot){auto actor=std::make_unique<w::Actor>();actor->slot=std::uint8_t(slot);check(bool(world.spawn_primary(slot,std::move(actor)).id),"canonical primary slots");}
    for(unsigned trial=0;trial<256;++trial){
        std::memset(memory.data()+0x755ec0,int(trial),0x3e84);world.session().inventory_owner=memory[0x4badee]=std::uint8_t(trial);
        for(auto at:{0x755b70u,0x755bf0u,0x755a70u,0x4bae33u,0x4bae8cu})memory[at]=std::uint8_t(trial+17);
        transform_write(memory.data(),0x755770,0x123456u);transform_write(memory.data(),0x755768,0xabcdefu);
        call(memory,0x6dec80);check(ui.initialize()==w::InventoryUiStatus::completed,"real typed cold initialization");const auto& state=ui.snapshot();check(bool(state),"cold state established");
        check(state->phase==memory[0x755ec4]&&state->update_enabled==memory[0x4bae33]&&state->requests_enabled==memory[0x4bae8c],"actual cold phase/gates");
        check(state->panel_active==std::array<std::uint8_t,3>{memory[0x755b70],memory[0x755bf0],memory[0x755a70]},"actual additional panel clears");
        check(state->selected==w::InventoryUiState::Record::primary&&state->auxiliary==w::InventoryUiState::Record::secondary&&transform_read<std::uint32_t>(memory.data(),0x755770)==0x755ed0&&transform_read<std::uint32_t>(memory.data(),0x755768)==0x759a28,"native selection identities represent actual two record references");
        for(unsigned i=0;i<0x3e84;++i)check(memory[0x755ec0+i]==0,"original clear establishes zero even for unadopted UI payload roles");
        check(world.session().inventory_owner==trial&&memory[0x4badee]==trial,"constructor preserves independent inventory owner");++constructors;
    }
    std::uint32_t seed=0x9812fe73;
    for(unsigned mode:{0u,1u,2u,255u})for(unsigned selected=0;selected<8;++selected)for(unsigned trial=0;trial<1024;++trial){
        world.mode=std::uint8_t(mode);world.selected_actor=memory[0x4baded]=std::uint8_t(selected);
        memory[0x3243f2]=std::uint8_t(mode);
        world.selected_frame_marker=memory[0x4bae89]=std::uint8_t(trial);world.session().inventory_owner=memory[0x4badee]=std::uint8_t(trial/4);
        std::array<std::uint8_t,8*stride> expected{};
        for(unsigned slot=0;slot<8;++slot){const auto actor=world.primary(slot);seed=seed*1664525u+1013904223u;actor->status=seed;seed=seed*1664525u+1013904223u;actor->auxiliary_status=seed;actor->active=(trial+slot)%2!=0;
            std::memset(expected.data()+stride*slot,int((trial+slot)%256),stride);expected[stride*slot]=actor->active?1:0;expected[stride*slot+3]=std::uint8_t(slot);std::memcpy(expected.data()+stride*slot+0xba0,&actor->status,4);std::memcpy(expected.data()+stride*slot+0xba4,&actor->auxiliary_status,4);}
        std::memcpy(memory.data()+actors,expected.data(),expected.size());check(ui.close_ready(),"cold owned UI close admitted");
        if(trial&1){check(recovery.bound_to(world)&&recovery.close(),"actual shared RecoveryUi consumer");call(memory,0x6e1430);++recovery_closes;}
        else{check(ui.force_close()==w::InventoryUiStatus::completed,"actual108 canonical command");call(memory,0x6925c0);++commands;}
        for(unsigned slot=0;slot<8;++slot){const auto actor=world.primary(slot);std::memcpy(expected.data()+stride*slot+0xba0,&actor->status,4);std::memcpy(expected.data()+stride*slot+0xba4,&actor->auxiliary_status,4);}
        check(std::memcmp(expected.data(),memory.data()+actors,expected.size())==0,"all eight whole affected actor records preserve every other source byte");
        check(world.selected_frame_marker==memory[0x4bae89]&&world.session().inventory_owner==memory[0x4badee]&&world.selected_actor==memory[0x4baded],"canonical frame marker/owner/selection");
    }
    const auto selected=world.selected_actor;check(world.retire_primary(selected)==w::actors::EntityStatus::completed,"real actor retirement");const auto marker=world.selected_frame_marker,owner=world.session().inventory_owner;
    check(!ui.close_ready()&&!recovery.close()&&ui.force_close()==w::InventoryUiStatus::unavailable_actor,"missing owned actor capability refuses");check(marker==world.selected_frame_marker&&owner==world.session().inventory_owner,"unadmitted command leaves prefix unchanged");
    w::World foreign(profile,std::make_shared<w::Session>());check(!ui.bound_to(foreign),"foreign UI binding refuses");
    check(session.close()==a::SessionStatus::completed,"real joined application close");check(!ui.close_ready()&&!ui.bound_to(world)&&!recovery.close()&&ui.initialize()==w::InventoryUiStatus::closed&&ui.force_close()==w::InventoryUiStatus::closed,"closed UI capabilities refuse");
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"constructors\":"<<constructors<<",\"commands\":"<<commands<<",\"recovery_closes\":"<<recovery_closes<<",\"original_calls\":"<<calls<<",\"game_launched\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
