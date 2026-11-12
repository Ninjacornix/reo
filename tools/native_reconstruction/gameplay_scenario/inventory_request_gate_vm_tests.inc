//604310 belongs to the unadmitted asset-reset branch. Reaching it in this
// original-body fixture must fail; production has no successful replacement.
void o2_00604310_0x604310(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unadmitted63zero604310 asset reset");}
namespace {
std::size_t inventory_request_dispatches{},inventory_request_refusals{},inventory_request_initializers{};
void inventory_request_gate_vm_tests(){
    EventNotifications notices,other_notices;const auto source=ui_fixture_archive();ui_app::NativeSession session(source,event_profile(),notices),other(source,event_profile(),other_notices);
    auto& native_world=session.world();auto& ui=session.inventory_ui();check(!ui.request_blocked());
    std::vector<std::uint8_t> ram(0x900000);install_original_tables(ram);ram[0x4bae8d]=128;
    vm::Providers p;p.world=&native_world;p.inventory_ui=&ui;p.flags=p.canonical_flags=&session.update().flags();
    for(bool offline:{false,true})for(unsigned mode:{0u,1u,2u,255u})for(unsigned value=0;value<65536;++value){
        const std::uint32_t word=value?value:0x10000u;
        assertion_context="63 offline="+std::to_string(offline)+" mode="+std::to_string(mode)+" word="+std::to_string(word);
        native_world.mode=ram[0x3243f2]=std::uint8_t(mode);
        fixture_write(ram.data(),0x75a4b0,0u);fixture_write(ram.data(),0x75a4c0,0u);
        std::array<std::uint8_t,64> before;std::memcpy(before.data(),ram.data()+0x4bae60,before.size());
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0x63,{word});emit(bytes,0x110,{1,19});emit(bytes,0xa);
        vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        const auto result=offline?native.tick_offline_channel(0,{},{},p):native.tick(0,{},p);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);
        before[0x2d]=*ui.request_blocked();check(std::memcmp(before.data(),ram.data()+0x4bae60,before.size())==0);++inventory_request_dispatches;
        if(value%8192==0){
            R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x7f0000);SET_GPR_U32(&context,31,0xdeadbeef);o2_006DEC80_0x6dec80(ram.data(),&context,&runtime);
            check(context.pc==0xdeadbeef&&ui.initialize()==reo::native::gameplay_world::InventoryUiStatus::completed&&ui.request_blocked()==ram[0x4bae8d]);++inventory_request_initializers;
        }
    }
    for(bool offline:{false,true})for(auto word:{0x80000000u,0x01000000u,0xff000000u,0xffffffffu}){
        std::vector<std::byte> bytes;emit(bytes,0x63,{word});emit(bytes,0xa);vm::Interpreter native;install_actor_script(native,ram,std::move(bytes),offline);call_actor_script(ram,offline);
        const auto result=offline?native.tick_offline_channel(0,{},{},p):native.tick(0,{},p);check(result.status==vm::Status::yielded&&ui.request_blocked()==ram[0x4bae8d]);compare_offline_channels(native,ram);++inventory_request_dispatches;
    }
    for(bool offline:{false,true})for(unsigned profile:{0u,1u,2u}){
        std::vector<std::byte> bytes;emit(bytes,0x110,{0,77});emit(bytes,0x63,{profile==0?0u:1u});emit(bytes,0xa);vm::Interpreter native;
        check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary))==vm::Status::completed);
        auto supplied=p;if(profile==1)supplied.inventory_ui=nullptr;if(profile==2)supplied.inventory_ui=&other.inventory_ui();
        const auto before=ui.request_blocked();const auto result=offline?native.tick_offline_channel(0,{},{},supplied):native.tick(0,{},supplied);
        check(result.status==vm::Status::provider_unavailable&&native.counters()[0]==0&&ui.request_blocked()==before);++inventory_request_refusals;
    }
    assertion_context.clear();
}
}
