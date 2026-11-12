#include "game/native/gameplay_application/native_session.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include <iostream>
#include <vector>
#include "functions.h"
namespace a=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},prefixes{},ports{};
void check(bool value,const char* message){++checks;if(!value)throw std::runtime_error(message);}
void original_transform_port(std::uint8_t*,R5900Context* context,PS2Runtime*){
    check(context->pc==0x107ab0&&GPR_U32(context,31)==0x37f3a0,"exact first copy boundary after difficulty launch prefix");
    check(GPR_U32(context,4)==0x4b9d20&&GPR_U32(context,5)==0x318d85&&GPR_U32(context,6)==128,"actual remaining launch copy arguments");
    ++ports;context->pc=0x1ffffff0; // Explicit prefix stop; do not simulate later launch side effects.
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
struct Notifications:s::FlagNotifications{
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
struct ImportDuringRetirement:w::Actor{
    a::NativeSession& session;a::SessionStatus& observed;
    ImportDuringRetirement(a::NativeSession& s,a::SessionStatus& o):session(s),observed(o){}
    ~ImportDuringRetirement()override{observed=session.import_launch_difficulty(77);}
};
int main(int argc,char** argv)try{
    check(argc==2,"owned archive required");auto source=std::make_shared<const reo::assets::Source>(std::filesystem::path(argv[1]));
    Notifications notifications;w::Profile profile;profile.layouts.push_back({});a::NativeSession session(source,profile,notifications);
    check(!session.world().session().difficulty,"generic native session retains unknown difficulty");
    std::vector<std::uint8_t> memory(0x2000000);memory[0x318b64]=41;transform_write(memory.data(),0x318b66,std::uint16_t(123));transform_write(memory.data(),0x318b68,std::uint16_t(456));transform_write(memory.data(),0x31a2d8,std::uint16_t(73));
    for(unsigned value=0;value<256;++value){
        memory[0x318b65]=std::uint8_t(value);memory[0x4bae8a]=std::uint8_t(~value);R5900Context context;PS2Runtime runtime;
        SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x123456);o0_0037F330_0x37f330(memory.data(),&context,&runtime);
        check(context.pc==0x1ffffff0,"producer prefix stops before first unadopted launch copy");
        check(session.import_launch_difficulty(std::uint8_t(value))==a::SessionStatus::completed,"canonical application import");
        check(session.world().session().difficulty==memory[0x4bae8a]&&memory[0x4bae8a]==value,"actual37F330 byte producer agrees");
        check(!session.world().scenario&&session.world().room==0,"difficulty-only import does not impersonate full launch transfer");++prefixes;
    }
    a::SessionStatus refused=a::SessionStatus::completed;
    check(bool(session.world().spawn_primary(0,std::make_unique<ImportDuringRetirement>(session,refused)).id),"real actor retirement fixture");
    check(session.close()==a::SessionStatus::completed,"joined real owner close");
    check((refused==a::SessionStatus::busy||refused==a::SessionStatus::closed)&&session.world().session().difficulty==255,"reentrant import refuses without mutation");
    check(session.import_launch_difficulty(0)==a::SessionStatus::closed&&session.world().session().difficulty==255,"closed import refuses");
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"source_prefixes\":"<<prefixes<<",\"copy_boundaries\":"<<ports<<",\"game_launched\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
