#include "game/native/gameplay_scenario/offline.hpp"
namespace {
struct NoticeSink final:vm::FlagNotifications {
    std::vector<std::tuple<std::uint32_t,std::uint8_t,std::uint8_t>> scenario_events;
    std::vector<std::tuple<std::uint32_t,std::uint32_t,bool,std::uint8_t>> room_events;
    void changed(const vm::ScenarioFlagChange& c)noexcept override{scenario_events.emplace_back(c.id,c.value,c.actor_owner);}
    void changed(const vm::StridedFlagChange& c)noexcept override{room_events.emplace_back(c.record,c.bit,c.set,c.slot);}
};
void export_bank(std::vector<std::uint8_t>& ram,std::uint32_t at,const vm::FlagWords& values){std::memcpy(ram.data()+at,values.data(),64);}
void export_flags(std::vector<std::uint8_t>& ram,const vm::FlagStateSnapshot& s){
    export_bank(ram,0x4b9c00,s.shared.scenario);export_bank(ram,0x4b9c40,s.shared.secondary);
    for(unsigned i=0;i<3;++i){export_bank(ram,0x4b9a80+64*i,s.primary[i]);export_bank(ram,0x4b9b40+64*i,s.auxiliary[i]);}
    std::memcpy(ram.data()+0x4b9c80,s.bounded_bytes.data(),16);fixture_write(ram.data(),0x4bac50,s.bounded_halfword);
    std::memcpy(ram.data()+0x4b9e20,s.strided.data(),256*12);
}
void compare_flags(const std::vector<std::uint8_t>& ram,const vm::FlagStateSnapshot& s){
    check(std::memcmp(ram.data()+0x4b9c00,s.shared.scenario.data(),64)==0);check(std::memcmp(ram.data()+0x4b9c40,s.shared.secondary.data(),64)==0);
    for(unsigned i=0;i<3;++i){check(std::memcmp(ram.data()+0x4b9a80+64*i,s.primary[i].data(),64)==0);check(std::memcmp(ram.data()+0x4b9b40+64*i,s.auxiliary[i].data(),64)==0);}
    check(std::memcmp(ram.data()+0x4b9c80,s.bounded_bytes.data(),16)==0);check(fixture_read<std::uint16_t>(ram.data(),0x4bac50)==s.bounded_halfword);
    check(std::memcmp(ram.data()+0x4b9e20,s.strided.data(),256*12)==0);
}
vm::FlagStateSnapshot initial_flags(){
    vm::FlagStateSnapshot s;
    for(unsigned j=0;j<16;++j){s.shared.scenario[j]=0x12345678u*j;s.shared.secondary[j]=0x87654321u*(j+1);
        for(unsigned i=0;i<3;++i){s.primary[i][j]=0x1020304u*(i+3)*(j+1);s.auxiliary[i][j]=0xfedcba98u*(i+1)*(j+2);}}
    return s;
}
std::vector<std::byte> offline_script(unsigned id){
    std::vector<std::byte> b;emit(b,5);emit(b,6); // Offline no-op bindings require no actor-event payload.
    emit(b,0xb,{1,id,0xff});emit(b,0xc,{1,id+1,1});emit(b,0xb,{0,id+2,0x81});emit(b,0xc,{0,id+3,0});
    emit(b,0x47,{37,1});emit(b,0x110,{0,1});emit(b,0xe4);emit(b,0x110,{0,2});emit(b,0xe5);emit(b,0xa);
    // Insert the remaining local/shared predicates before the final yield.
    b.resize(b.size()-4);
    for(const auto opcode:{0xe3u,0xe6u,0xecu,0xedu,0xefu}){
        emit(b,opcode,{opcode==0xef?257u:id,0x100});emit(b,0x110,{1,3});emit(b,0xe4);emit(b,0x110,{1,4});emit(b,0xe5);
    }
    emit(b,0xf4,{2,15});emit(b,0xf5,{2,31});
    for(const auto opcode:{0xb7u,0xb8u}){emit(b,opcode,{2,15,0});emit(b,0x110,{2,5});emit(b,0xe4);emit(b,0x110,{2,6});emit(b,0xe5);}
    emit(b,0xa);
    return b;
}
std::uint32_t last_record(const std::vector<std::byte>& bytes){
    std::uint32_t at=0,last=0;while(at<bytes.size()){last=at;at+=vm::Program::record_bytes(fixture_read<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(bytes.data()),at));}return last;
}
void install_original_tables(std::vector<std::uint8_t>& ram){
    std::memcpy(ram.data()+0x717830,original_opcode_table.data(),original_opcode_table.size()*4);
    std::memcpy(ram.data()+0x717600,original_opener_table.data(),original_opener_table.size()*4);
    std::memcpy(ram.data()+0x73cbe0,original_offline_table.data(),original_offline_table.size()*4);
    std::memcpy(ram.data()+0x73cbd0,original_party_channels.data(),original_party_channels.size()*4);
    std::memcpy(ram.data()+0x7408d0,original_counter_comparisons.data(),original_counter_comparisons.size()*4);
}
void install_offline_program(vm::Interpreter& vm,std::vector<std::uint8_t>& ram,std::size_t channel,std::vector<std::byte> bytes,std::uint32_t countdown=0){
    const auto address=0x10000u+std::uint32_t(channel)*0x10000,tail=last_record(bytes);
    std::memcpy(ram.data()+address,bytes.data(),bytes.size());fixture_write<std::uint32_t>(ram.data(),0x90000+4*channel,address);
    fixture_write<std::uint32_t>(ram.data(),0x4bace0+4*channel,address);fixture_write<std::uint32_t>(ram.data(),0x4bad28+4*channel,address+tail);
    fixture_write<std::uint32_t>(ram.data(),0x4bad40+4*channel,0x90000+4*channel);fixture_write<std::uint32_t>(ram.data(),0x4bacf8+4*channel,countdown);
    fixture_write<std::uint32_t>(ram.data(),0x4bad58+4*channel,0x80+std::uint32_t(channel));
    auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{std::move(bytes)},vm::DispatchProfile::offline_actor);
    check(vm.restore_channel(channel,vm::Channel{program,{0,0},{0,tail},countdown,0,0x80+std::uint32_t(channel)})==vm::Status::completed);
}
void compare_offline_channels(vm::Interpreter& vm,const std::vector<std::uint8_t>& ram){
    for(std::size_t i=0;i<6;++i){const auto& c=vm.channels()[i];if(!c.program)continue;const auto address=0x10000+std::uint32_t(i)*0x10000;
        check(fixture_read<std::uint32_t>(ram.data(),0x4bace0+4*i)==address+c.current.offset);
        check(fixture_read<std::uint32_t>(ram.data(),0x4bad28+4*i)==address+c.saved.offset);
        check(fixture_read<std::uint32_t>(ram.data(),0x4bacf8+4*i)==c.countdown);
        check(fixture_read<std::uint32_t>(ram.data(),0x4bad58+4*i)==c.condition);
    }
    check(ram[0x4badc1]==vm.selected_channel());
    for(std::size_t i=0;i<4;++i)check(fixture_read<std::uint32_t>(ram.data(),0x4bada8+4*i)==vm.counters()[i]);
}
void original_offline_call(std::vector<std::uint8_t>& ram,unsigned channel,bool wrapper){
    R5900Context ctx;PS2Runtime runtime;SET_GPR_U32(&ctx,4,channel);SET_GPR_U32(&ctx,29,0x7f0000);SET_GPR_U32(&ctx,31,0xdeadbeef);
    if(wrapper)o2_007003E0_0x7003e0(ram.data(),&ctx,&runtime);else o2_007006D0_0x7006d0(ram.data(),&ctx,&runtime);
    check(ctx.pc==0xdeadbeef);++invocations;
}
void offline_tests(){
    // Every dispatch context, including the category4 cross-family alias, is
    // compared with the actual offline dispatcher and its original bank helpers.
    for(unsigned category=0;category<=4;++category)for(unsigned relation=0;relation<4;++relation)for(auto predicate:{-1,0,1,2}){
        predicate_value=predicate;std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);
        ram[0x3243e8]=1;ram[0x4baded]=2;fixture_write<std::uint32_t>(ram.data(),0x75a4b0,category);fixture_write<std::uint32_t>(ram.data(),0x75a4c0,relation);
        NoticeSink sink;sink.scenario_events.reserve(100);sink.room_events.reserve(100);vm::FlagState flags(&sink);flags.restore(initial_flags());export_flags(ram,flags.snapshot());
        vm::Interpreter native;install_offline_program(native,ram,0,offline_script(17));Signals signals;signals.sent.reserve(100);signals.asked.reserve(100);tasks::FlagTimers timers;
        notifications.clear();queries.clear();messages.clear();strided_notifications.clear();original_offline_call(ram,0,false);
        const auto r=native.tick_offline_channel(0,{true,false,2},{category,relation,0},{&flags,&timers,&signals,&flags});check(r.status==vm::Status::yielded);
        compare_flags(ram,flags.snapshot());compare_offline_channels(native,ram);check(sink.scenario_events==notifications);check(signals.asked==queries);
    }
    // Whole mode-zero wrapper: mixed classes, rooms, active memberships,
    // disabled execution and retained deltas for inactive entries.
    constexpr std::array<std::array<std::uint8_t,3>,4> classes{{{0,1,2},{2,1,0},{3,0,1},{0,0,0}}};
    for(const auto kinds:classes)for(unsigned mask=0;mask<8;++mask)for(bool enabled:{false,true}){
        std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=enabled;fixture_write<std::uint16_t>(ram.data(),0x3243dc,9);ram[0x4baded]=2;
        NoticeSink sink;sink.scenario_events.reserve(100);vm::FlagState flags(&sink);flags.restore(initial_flags());export_flags(ram,flags.snapshot());
        vm::Interpreter native;for(unsigned channel=0;channel<6;++channel)install_offline_program(native,ram,channel,offline_script(10+channel*4));
        vm::OfflineState old;
        for(unsigned actor=0;actor<3;++actor){old.actors[actor].added.scenario[0]=1u<<(actor+24);old.actors[actor].removed.secondary[0]=1u<<(actor+20);
            std::memcpy(ram.data()+0x75a2b0+actor*128,old.actors[actor].added.scenario.data(),64);std::memcpy(ram.data()+0x75a2f0+actor*128,old.actors[actor].added.secondary.data(),64);
            std::memcpy(ram.data()+0x75a130+actor*128,old.actors[actor].removed.scenario.data(),64);std::memcpy(ram.data()+0x75a170+actor*128,old.actors[actor].removed.secondary.data(),64);
        }
        vm::OfflineCoordinator coordinator;check(coordinator.restore(old)==vm::Status::completed);std::array<vm::OfflinePartyActor,3> party;
        for(unsigned actor=0;actor<3;++actor){const bool active=(mask&(1u<<actor))!=0;party[actor]={active,active?kinds[actor]:std::uint8_t(255),std::uint16_t(actor%2?10:9)};
            ram[0x4a5c30+0x10e0*actor]=active?0x80:0;ram[0x4a5c33+0x10e0*actor]=party[actor].script_class;fixture_write<std::uint16_t>(ram.data(),0x4a5c30+0x10e0*actor+0x1e2,party[actor].room);
        }
        notifications.clear();queries.clear();messages.clear();strided_notifications.clear();predicate_value=0;original_offline_call(ram,1,true);
        Signals signals;signals.asked.reserve(100);tasks::FlagTimers timers;std::uint8_t selected=2;
        const auto r=coordinator.tick(native,1,enabled,party,9,selected,flags,{&flags,&timers,&signals,&flags});check(r.status==vm::Status::completed);check(selected==ram[0x4baded]);
        compare_flags(ram,flags.snapshot());compare_offline_channels(native,ram);check(sink.scenario_events==notifications);check(signals.asked==queries);
        for(unsigned actor=0;actor<3;++actor){const auto& d=coordinator.snapshot().actors[actor];
            check(std::memcmp(ram.data()+0x75a2b0+actor*128,d.added.scenario.data(),64)==0);check(std::memcmp(ram.data()+0x75a2f0+actor*128,d.added.secondary.data(),64)==0);
            check(std::memcmp(ram.data()+0x75a130+actor*128,d.removed.scenario.data(),64)==0);check(std::memcmp(ram.data()+0x75a170+actor*128,d.removed.secondary.data(),64)==0);
        }
    }
    // Non-party channels execute once with zero dispatch context and retain the
    // incoming selected actor, even when execution is disabled.
    for(unsigned channel:{0u,2u,3u,4u,5u})for(bool enabled:{false,true})for(unsigned actor=0;actor<4;++actor){
        std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=enabled;ram[0x4baded]=std::uint8_t(actor);
        NoticeSink sink;sink.scenario_events.reserve(100);vm::FlagState flags(&sink);flags.restore(initial_flags());export_flags(ram,flags.snapshot());
        vm::Interpreter native;install_offline_program(native,ram,channel,offline_script(23),2);
        notifications.clear();queries.clear();messages.clear();strided_notifications.clear();predicate_value=0;original_offline_call(ram,channel,true);
        Signals signals;signals.asked.reserve(100);tasks::FlagTimers timers;std::uint8_t selected=std::uint8_t(actor);vm::OfflineCoordinator coordinator;
        const std::array<vm::OfflinePartyActor,3> party{};
        const auto r=coordinator.tick(native,channel,enabled,party,9,selected,flags,{&flags,&timers,&signals,&flags});
        check(r.status==(enabled?vm::Status::yielded:vm::Status::disabled));check(r.invocations==1);check(selected==ram[0x4baded]);
        compare_flags(ram,flags.snapshot());compare_offline_channels(native,ram);check(sink.scenario_events==notifications);check(signals.asked==queries);
    }
    // Normal default slots with real offline handlers must never be admitted as
    // offline no-ops just because the ordinary profile permits them.
    for(const auto opcode:{0x175u,0x176u,0x1a0u,0x1adu}){
        std::vector<std::byte> b;emit(b,opcode);emit(b,0xa);vm::Interpreter n;
        const auto p=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b},vm::DispatchProfile::offline_actor);
        check(n.install(0,p)==vm::Status::unsupported_opcode);
    }
}
}
void sub_00107AB0_0x107ab0(std::uint8_t* r,R5900Context* c,PS2Runtime*){std::memmove(r+GPR_U32(c,4),r+GPR_U32(c,5),GPR_U32(c,6));SET_GPR_U32(c,2,GPR_U32(c,4));done(c);}
