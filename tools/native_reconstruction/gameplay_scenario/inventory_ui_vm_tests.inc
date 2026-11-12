#include "game/native/gameplay_application/native_session.hpp"
#include "runtime/assets/virtual_afs.h"
// These calls belong exclusively to unadmitted active UI phases. A source
// fixture that accidentally reaches one must fail, never receive success.
void o2_006EC9D0_0x6ec9d0(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unadmitted active UI teardown6EC9D0");}
void o2_006DF230_0x6df230(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unadmitted active UI refresh6DF230");}
void o2_0067FF80_0x67ff80(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unadmitted active UI equipment67FF80");}
void o2_006EC6D0_0x6ec6d0(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unadmitted active UI cleanup6EC6D0");}
void o2_006D8100_0x6d8100(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unadmitted active UI close6D8100");}
namespace {
namespace ui_app=reo::native::gameplay_application;
std::size_t inventory_ui_dispatches{},inventory_ui_refusals{};
struct UiMemorySource final:reo::assets::PositionedSource {
    std::vector<std::uint8_t> bytes;
    std::uint64_t size()const noexcept override{return bytes.size();}
    std::size_t read(std::uint64_t at,std::size_t count,void* output)const override{
        if(at>bytes.size()||count>bytes.size()-at)throw std::runtime_error("UI fixture source range");
        std::memcpy(output,bytes.data()+at,count);return count;
    }
};
std::shared_ptr<const reo::assets::Source> ui_fixture_archive(){
    auto memory=std::make_shared<UiMemorySource>();auto& b=memory->bytes;b.resize(6*4096);std::memcpy(b.data(),"AFS\0",4);reo::assets::put32(b.data()+4,5);
    const std::array names{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs"};
    for(unsigned i=0;i<5;++i){const unsigned base=4096*(i+1);reo::assets::put32(b.data()+8+8*i,base);reo::assets::put32(b.data()+12+8*i,4096);std::memcpy(b.data()+512+48*i,names[i],8);std::memcpy(b.data()+base,"AFS\0",4);reo::assets::put32(b.data()+base+4,1);reo::assets::put32(b.data()+base+8,2048);reo::assets::put32(b.data()+base+12,1);}
    reo::assets::put32(b.data()+48,512);reo::assets::put32(b.data()+52,240);return std::make_shared<const reo::assets::Source>("UI-concrete-native-archive",memory);
}
void inventory_ui_vm_tests(){
    namespace world=reo::native::gameplay_world;namespace update=reo::native::gameplay_update;
    EventNotifications notices,foreign_notices;const auto source=ui_fixture_archive();ui_app::NativeSession session(source,event_profile(),notices),foreign(source,event_profile(),foreign_notices);
    auto& native_world=session.world();auto& ui=session.inventory_ui();
    for(unsigned slot=0;slot<8;++slot){auto actor=std::make_unique<world::Actor>();actor->slot=std::uint8_t(slot);check(bool(native_world.spawn_primary(slot,std::move(actor)).id));}
    std::vector<std::uint8_t> ram(0x900000);install_original_tables(ram);
    {R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x7f0000);SET_GPR_U32(&context,31,0xdeadbeef);o2_006DEC80_0x6dec80(ram.data(),&context,&runtime);check(context.pc==0xdeadbeef);}
    vm::Providers p;p.world=&native_world;p.flags=p.canonical_flags=&session.update().flags();p.inventory_ui=&ui;
    std::uint32_t random=0x19a8be7c;
    for(bool offline:{false,true})for(unsigned mode:{0u,1u,2u,255u})for(unsigned selected=0;selected<8;++selected)for(unsigned trial=0;trial<1024;++trial){
        assertion_context="108 offline="+std::to_string(offline)+" mode="+std::to_string(mode)+" selected="+std::to_string(selected)+" trial="+std::to_string(trial);
        native_world.mode=ram[0x3243f2]=std::uint8_t(mode);native_world.selected_actor=ram[0x4baded]=std::uint8_t(selected);
        native_world.selected_frame_marker=ram[0x4bae89]=std::uint8_t(trial);native_world.session().inventory_owner=ram[0x4badee]=std::uint8_t(trial/4);
        for(unsigned slot=0;slot<8;++slot){auto actor=native_world.primary(slot);random=random*1664525u+1013904223u;actor->status=random;random=random*1664525u+1013904223u;actor->auxiliary_status=random;actor->active=(slot+trial)%2!=0;
            const unsigned at=0x4a5c30+slot*0x10e0;ram[at]=actor->active?1:0;fixture_write(ram.data(),at+0xba0,actor->status);fixture_write(ram.data(),at+0xba4,actor->auxiliary_status);}
        fixture_write(ram.data(),0x75a4b0,0u);fixture_write(ram.data(),0x75a4c0,0u);
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0x108);emit(bytes,0x110,{1,19});emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        const auto result=offline?native.tick_offline_channel(0,{true,false,std::uint8_t(selected)},{},p):native.tick(0,{true,false,std::uint8_t(selected)},p);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);
        for(unsigned slot=0;slot<8;++slot){const auto actor=native_world.primary(slot);check(actor->status==fixture_read<std::uint32_t>(ram.data(),0x4a67d0+slot*0x10e0));check(actor->auxiliary_status==fixture_read<std::uint32_t>(ram.data(),0x4a67d4+slot*0x10e0));}
        check(native_world.selected_frame_marker==ram[0x4bae89]&&native_world.session().inventory_owner==ram[0x4badee]);++inventory_ui_dispatches;
    }
    for(bool offline:{false,true}){
        const auto refuse=[&](vm::Providers supplied){std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0x108);emit(bytes,0xa);vm::Interpreter native;
            check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary))==vm::Status::completed);
            const auto before=native_world.primary(native_world.selected_actor)->auxiliary_status;const auto marker=native_world.selected_frame_marker,owner=native_world.session().inventory_owner;
            const auto result=offline?native.tick_offline_channel(0,{},{},supplied):native.tick(0,{},supplied);
            check(result.status==vm::Status::provider_unavailable&&native.counters()[0]==0&&before==native_world.primary(native_world.selected_actor)->auxiliary_status&&marker==native_world.selected_frame_marker&&owner==native_world.session().inventory_owner);++inventory_ui_refusals;};
        auto missing=p;missing.inventory_ui=nullptr;refuse(missing);auto foreign_ui=p;foreign_ui.inventory_ui=&foreign.inventory_ui();refuse(foreign_ui);
    }
    {std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0x108);emit(bytes,0xa);check(session.update().scripts().install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes}))==vm::Status::completed);
        auto supplied=p;supplied.inventory_ui=&foreign.inventory_ui();check(session.update().step_script(0,supplied).status==update::Status::script_failure&&session.update().scripts().counters()[0]==0);
        check(session.update().step_script(0,p).status==update::Status::completed&&session.update().scripts().counters()[0]==77);}
    check(session.close()==ui_app::SessionStatus::completed&&!ui.close_ready());assertion_context.clear();
}
}
