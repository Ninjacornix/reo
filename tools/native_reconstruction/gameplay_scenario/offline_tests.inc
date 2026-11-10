#include "game/native/gameplay_scenario/offline.hpp"
namespace {
struct NoticeSink final:vm::FlagNotifications {
    std::vector<std::tuple<std::uint32_t,std::uint8_t,std::uint8_t>> scenario_events;
    std::vector<std::tuple<std::uint32_t,std::uint32_t,bool,std::uint8_t>> room_events;
    bool changed(const vm::ScenarioFlagChange& c)noexcept override{scenario_events.emplace_back(c.id,c.value,c.actor_owner);return true;}
    bool changed(const vm::StridedFlagChange& c)noexcept override{room_events.emplace_back(c.record,c.bit,c.set,c.slot);return true;}
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
    // Mode-one helper calls select the actual authored owner counter bank.
    // Save the condition as the next invocation entry so consumption is checked
    // repeatedly across nonzero-to-zero and uint32 wrap boundaries.
    for(const auto value:{0u,1u,2u,0x80000000u,0xffffffffu})for(const auto wanted:{0u,1u,0xffffffffu})for(unsigned owner=0;owner<3;++owner){
        std::vector<std::byte> b;emit(b,0xe8,{1,value});emit(b,1);emit(b,0xe9,{1,wanted});emit(b,0x110,{0,3});emit(b,0xe4);emit(b,0x110,{0,4});emit(b,0xe5);emit(b,0xa);
        std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=1;ram[0x4baded]=std::uint8_t(owner);
        vm::Interpreter native;install_offline_program(native,ram,0,b);vm::FlagState flags;vm::SessionCounters counters;
        const vm::Providers providers{&flags,nullptr,nullptr,&flags,nullptr,nullptr,nullptr,&counters};
        for(unsigned iteration=0;iteration<4;++iteration){
            original_offline_call(ram,0,false);const auto r=native.tick_offline_channel(0,{true,false,std::uint8_t(owner)},{0,0,0},providers);
            check(r.status==vm::Status::yielded);compare_offline_channels(native,ram);check(std::memcmp(counters.snapshot().data(),ram.data()+0x4bad70,24)==0);
        }
        const auto before=counters.snapshot();check(native.tick_offline_channel(0,{true,false,3},{0,0,0},providers).status==vm::Status::invalid_program);check(before==counters.snapshot());
    }
    for(unsigned profile=0;profile<6;++profile)for(const auto desired:{0u,1u,2u,0xffffffffu})for(unsigned category=0;category<5;++category){
        std::vector<std::byte> b;emit(b,0x12);emit(b,0x14,{desired});emit(b,0x110,{0,1});emit(b,0xe4);emit(b,0x110,{0,2});emit(b,0xe5);
        emit(b,0x10,{31});emit(b,0x11,{0});emit(b,0x13,{31,0x1234});emit(b,0x15,{31});emit(b,0x16,{0x81,0x8001,0x7fff,0x80000001});
        emit(b,0x17,{profile+1,desired});emit(b,0x110,{1,3});emit(b,0xe4);emit(b,0x110,{1,4});emit(b,0xe5);emit(b,0xa);
        std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=1;ram[0x4baded]=2;
        fixture_write<std::uint32_t>(ram.data(),0x75a4b0,category);fixture_write<std::uint32_t>(ram.data(),0x75a4c0,0);
        vm::Interpreter native;install_offline_program(native,ram,0,b);SequenceFixture sequence(profile);sequence.export_original(ram);
        original_offline_call(ram,0,false);vm::FlagState flags;vm::Providers providers;providers.flags=&flags;providers.canonical_flags=&flags;providers.sequences=&sequence.owner;
        const auto r=native.tick_offline_channel(0,{true,false,2},{category,0,0},providers);check(r.status==vm::Status::yielded);
        compare_offline_channels(native,ram);sequence.compare_original(ram);
    }
    for(const auto op:{0xa0u,0xa1u,0xa2u,0xa3u})for(const auto index:{0u,31u,32u,0x80000000u,0xffffffffu})for(unsigned category=0;category<5;++category)for(unsigned relation=0;relation<3;++relation){
        assertion_context="scene channel offline op="+std::to_string(op)+" index="+std::to_string(index)+" category="+std::to_string(category)+" relation="+std::to_string(relation);
        std::vector<std::byte> b;emit(b,op,{index});emit(b,0xa);std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=1;ram[0x4baded]=2;
        fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);fixture_write<std::uint32_t>(ram.data(),0x4b9d0c,0xa5a58000u);
        vm::Interpreter native;install_offline_program(native,ram,0,b);vm::SceneChannels channels;channels.restore(0xa5a58000u);
        original_offline_call(ram,0,false);vm::FlagState flags;vm::Providers providers;providers.flags=&flags;providers.canonical_flags=&flags;providers.scene_channels=&channels;
        check(native.tick_offline_channel(0,{true,false,2},{category,relation,0},providers).status==vm::Status::yielded);compare_offline_channels(native,ram);
        check(channels.mask()==fixture_read<std::uint32_t>(ram.data(),0x4b9d0c));
    }
    for(const auto op:{0x51u,0x55u,0x56u,0x57u,0x5fu,0x72u,0xb5u,0x190u})for(unsigned category=0;category<5;++category)for(unsigned relation=0;relation<3;++relation){
        assertion_context="linked control offline op="+std::to_string(op)+" category="+std::to_string(category)+" relation="+std::to_string(relation);
        std::vector<std::byte> b;emit(b,op,{42,0xffff8172,7,0xffff87fe});emit(b,0xa);std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=1;ram[0x4baded]=2;
        fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);ControlFixture controls;controls.export_original(ram);
        vm::Interpreter native;install_offline_program(native,ram,0,b);original_offline_call(ram,0,false);vm::FlagState flags;vm::Providers providers;providers.flags=&flags;providers.canonical_flags=&flags;providers.scene_controls=&controls.owner;providers.control_effects=&controls;
        check(native.tick_offline_channel(0,{true,false,2},{category,relation,0},providers).status==vm::Status::yielded);compare_offline_channels(native,ram);controls.compare_original(ram);
    }
    for(const auto op:{0x104u,0x105u})for(unsigned owner=0;owner<3;++owner)for(unsigned category=0;category<5;++category)for(unsigned relation=0;relation<3;++relation)for(unsigned disabled=0;disabled<2;++disabled)
    for(const auto type:{0u,2u,3u,4u,6u,7u,11u,13u,15u}){
        assertion_context="typed controls offline op="+std::to_string(op)+" type="+std::to_string(type)+" owner="+std::to_string(owner)+" category="+std::to_string(category)+" relation="+std::to_string(relation)+" disabled="+std::to_string(disabled);
        std::vector<std::byte> b;emit(b,op,{type,42,1});emit(b,0xa);std::vector<std::uint8_t> ram(0x900000);install_original_tables(ram);ram[0x3243e8]=1;ram[0x4baded]=std::uint8_t(owner);
        fixture_write(ram.data(),0x75a4b8,owner);fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);ControlFixture controls(disabled);controls.export_original(ram);SavedControlFixture saved;saved.export_original(ram);
        vm::Interpreter native;install_offline_program(native,ram,0,b);original_offline_call(ram,0,false);vm::FlagState flags;vm::Providers providers;providers.flags=&flags;providers.canonical_flags=&flags;providers.scene_controls=&controls.owner;providers.saved_controls=&saved.owner;
        check(native.tick_offline_channel(0,{true,false,std::uint8_t(owner)},{category,relation,0},providers).status==vm::Status::yielded);compare_offline_channels(native,ram);controls.compare_original(ram);saved.compare_original(ram);
    }
    {std::vector<std::byte> b;emit(b,0x110,{0,88});emit(b,0x104,{0,42,0});emit(b,0xa);vm::Interpreter native;vm::SceneControls controls;vm::FlagState flags;vm::Providers providers;providers.flags=&flags;providers.canonical_flags=&flags;providers.scene_controls=&controls;
        check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b},vm::DispatchProfile::offline_actor))==vm::Status::completed);
        check(native.tick_offline_channel(0,{},{},providers).status==vm::Status::provider_unavailable);check(native.counters()[0]==0);
        vm::OfflineCoordinator coordinator;std::array<vm::OfflinePartyActor,3> party{};std::uint8_t selected=2;
        check(coordinator.tick(native,0,true,party,9,selected,flags,providers).status==vm::Status::provider_unavailable);check(selected==2);check(native.counters()[0]==0);
        vm::SavedControlRecords saved;providers.saved_controls=&saved;check(native.tick_offline_channel(0,{true,false,3},{},providers).status==vm::Status::provider_unavailable);check(native.counters()[0]==0);
    }
    for(const auto op:{0x50u,0x52u,0x53u,0x54u,0x58u,0x59u,0x5bu,0x5cu,0x5du,0x5eu,0xf6u}){
        std::vector<std::byte> b;emit(b,op,{42,1,7,3});emit(b,0xa);vm::Interpreter native;
        check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b},vm::DispatchProfile::offline_actor))==vm::Status::unsupported_opcode);
    }
    for(unsigned profile=0;profile<12;++profile)for(unsigned category=0;category<5;++category)for(unsigned relation=0;relation<3;++relation){
        assertion_context="stream offline profile="+std::to_string(profile)+" category="+std::to_string(category)+" relation="+std::to_string(relation);
        std::vector<std::byte> b;emit(b,0x70,{69});emit(b,0x71);emit(b,0xa);std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=1;ram[0x4baded]=2;
        fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);StreamFixture streams(profile,0);streams.export_original(ram);
        vm::Interpreter native;install_offline_program(native,ram,0,b);original_offline_call(ram,0,false);vm::FlagState flags;vm::Providers providers;providers.flags=&flags;providers.canonical_flags=&flags;providers.streams=&streams.owner;providers.stream_backend=&streams;
        check(native.tick_offline_channel(0,{true,false,2,9,0u},{category,relation,0},providers).status==vm::Status::yielded);compare_offline_channels(native,ram);streams.compare_original(ram);
    }
    for(unsigned profile=0;profile<72;++profile)for(unsigned owner=0;owner<3;++owner)for(unsigned category=0;category<5;++category)for(unsigned relation=0;relation<3;++relation){
        assertion_context="native actor choices offline profile="+std::to_string(profile)+" owner="+std::to_string(owner)+" category="+std::to_string(category)+" relation="+std::to_string(relation);
        std::vector<std::byte> b;emit(b,0x135,{42,0x8002a,0x80002,UINT32_MAX,0x80190});
        emit(b,0x155,{profile%10,profile%3});emit(b,0x110,{0,1});emit(b,0xe4);emit(b,0x110,{0,2});emit(b,0xe5);
        emit(b,0x180,{profile%4});emit(b,0x110,{1,3});emit(b,0xe4);emit(b,0x110,{1,4});emit(b,0xe5);emit(b,0xa);
        std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=1;fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);
        ActorFixture actors(profile,std::uint8_t(owner),true);actors.export_original(ram);ControlFixture controls(profile);controls.export_original(ram);
        vm::Interpreter native;install_offline_program(native,ram,0,b);original_offline_call(ram,0,false);vm::FlagState flags;vm::Providers p;p.flags=&flags;p.canonical_flags=&flags;p.world=&actors.world;p.action_choices=&actors.choices;p.scene_controls=&controls.owner;
        check(native.tick_offline_channel(0,{true,false,std::uint8_t(owner)},{category,relation,0},p).status==vm::Status::yielded);
        compare_offline_channels(native,ram);controls.compare_original(ram);actors.compare_original(ram);
    }
    for(unsigned profile=0;profile<8;++profile){
        std::vector<std::byte> b;emit(b,1);emit(b,0x135,{42,0x8002a,0x8002a,0x8002a,0x8002a});emit(b,0x155,{0,1});emit(b,0x110,{0,1});emit(b,0xe4);emit(b,0x110,{0,2});emit(b,0xe5);emit(b,0x180,{0});emit(b,0x110,{1,3});emit(b,0xe4);emit(b,0x110,{1,4});emit(b,0xe5);emit(b,0xa);
        std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=1;fixture_write<std::uint16_t>(ram.data(),0x3243dc,9);
        ActorFixture actors(profile,2,true);actors.export_original(ram);ControlFixture controls;controls.export_original(ram);vm::Interpreter native;std::array<vm::OfflinePartyActor,3> party;
        for(unsigned i=0;i<3;++i){party[i]={true,std::uint8_t(i),9};ram[0x4a5c30+i*0x10e0]=0x80;ram[0x4a5c33+i*0x10e0]=std::uint8_t(i);actors.world.primary(i)->slot=std::uint8_t(i);fixture_write<std::uint16_t>(ram.data(),0x4a5c30+i*0x10e0+0x1e2,9);install_offline_program(native,ram,i+1,b);}
        vm::FlagState flags;vm::OfflineCoordinator coordinator;vm::Providers p;p.world=&actors.world;p.action_choices=&actors.choices;p.scene_controls=&controls.owner;
        original_offline_call(ram,1,true);const auto r=coordinator.tick(native,1,true,party,9,actors.world.selected_actor,flags,p);check(r.status==vm::Status::completed);check(r.invocations==3);compare_offline_channels(native,ram);controls.compare_original(ram);actors.compare_original(ram);
        const auto first=native.channels()[1].current;const auto counter=native.counters();actors.world.selected_actor=2;actors.world.retire_primary(1);
        check(coordinator.tick(native,1,true,party,9,actors.world.selected_actor,flags,p).status==vm::Status::provider_unavailable);check(actors.world.selected_actor==2);check(native.channels()[1].current==first);check(native.counters()==counter);
    }
    // The wrapper must borrow the canonical selected-owner byte, not silently
    // update a detached copy before invoking actor-dependent programs.
    {std::vector<std::byte> b;emit(b,0x135,{42,0x8002a,0x8002a,0x8002a,0x8002a});emit(b,0xa);vm::Interpreter native;vm::FlagState flags;vm::OfflineCoordinator coordinator;ActorFixture actors(0,2,true);ControlFixture controls;
        std::vector<std::uint8_t> ram(0x800000);install_offline_program(native,ram,0,b);vm::Providers p;p.world=&actors.world;p.action_choices=&actors.choices;p.scene_controls=&controls.owner;
        std::array<vm::OfflinePartyActor,3> party{};std::uint8_t detached=2;const auto old=native.channels()[0].current;
        check(coordinator.tick(native,0,true,party,9,detached,flags,p).status==vm::Status::provider_unavailable);check(detached==2);check(native.channels()[0].current==old);
        actors.world.retire_primary(2);check(coordinator.tick(native,0,true,party,9,actors.world.selected_actor,flags,p).status==vm::Status::provider_unavailable);check(actors.world.selected_actor==2);check(native.channels()[0].current==old);
    }
    for(const auto op:{0xb0u,0xb1u,0xb4u})for(unsigned profile=0;profile<8;++profile)for(unsigned category=0;category<5;++category)for(unsigned relation=0;relation<3;++relation){
        assertion_context="scene model offline op="+std::to_string(op)+" profile="+std::to_string(profile)+" category="+std::to_string(category)+" relation="+std::to_string(relation);
        for(const auto authored:{3u,31u,32u,255u}){std::vector<std::byte> b;emit(b,op,{authored,profile});emit(b,0xa);std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=1;ram[0x4baded]=2;
            fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);ModelFixture models(profile==7&&op!=0xb4?255u:profile);models.export_original(ram);
            vm::Interpreter native;install_offline_program(native,ram,0,b);original_offline_call(ram,0,false);vm::FlagState flags;vm::Providers p;p.flags=&flags;p.canonical_flags=&flags;p.models=&models.owner;
            check(native.tick_offline_channel(0,{true,false,2},{category,relation,0},p).status==vm::Status::yielded);compare_offline_channels(native,ram);models.compare_original(ram);
        }
    }
    {std::vector<std::byte> b;emit(b,1);emit(b,0xb0,{7});emit(b,0xb1,{3});emit(b,0xb4,{7,4});emit(b,0xa);std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=1;fixture_write<std::uint16_t>(ram.data(),0x3243dc,9);ram[0x4baded]=2;
        std::array<vm::OfflinePartyActor,3> party;for(unsigned i=0;i<3;++i){party[i]={true,0,9};ram[0x4a5c30+i*0x10e0]=0x80;ram[0x4a5c33+i*0x10e0]=0;fixture_write<std::uint16_t>(ram.data(),0x4a5c30+i*0x10e0+0x1e2,9);}
        ModelFixture models;models.export_original(ram);vm::Interpreter native;install_offline_program(native,ram,1,b);vm::FlagState flags;vm::OfflineCoordinator coordinator;vm::Providers p;p.models=&models.owner;std::uint8_t selected=2;
        original_offline_call(ram,1,true);const auto r=coordinator.tick(native,1,true,party,9,selected,flags,p);check(r.status==vm::Status::completed);check(r.invocations==3);compare_offline_channels(native,ram);models.compare_original(ram);check(selected==ram[0x4baded]);
        const auto old=native.channels()[1].current;selected=2;p.models=nullptr;check(coordinator.tick(native,1,true,party,9,selected,flags,p).status==vm::Status::provider_unavailable);check(selected==2);check(native.channels()[1].current==old);
        ModelFixture invalid(255);p.models=&invalid.owner;auto remap=invalid.owner.remap();remap[7]=255;invalid.owner.room_remap(remap);check(coordinator.tick(native,1,true,party,9,selected,flags,p).status==vm::Status::provider_unavailable);check(selected==2);check(native.channels()[1].current==old);
    }
    // Actual optional audio tick reaches both wrapper routes, including every
    // active actor when a shared authored channel reenters its saved record.
    for(const auto tick:{0u,1234u})for(const auto requested:{0u,1u}){
        std::vector<std::byte> b;emit(b,1);emit(b,0x70,{69});emit(b,0xa);std::vector<std::uint8_t> ram(0x800000);install_original_tables(ram);ram[0x3243e8]=1;fixture_write<std::uint16_t>(ram.data(),0x3243dc,9);ram[0x4baded]=2;
        std::array<vm::OfflinePartyActor,3> party;for(unsigned i=0;i<3;++i){party[i]={true,0,9};ram[0x4a5c30+0x10e0*i]=0x80;ram[0x4a5c33+0x10e0*i]=0;fixture_write<std::uint16_t>(ram.data(),0x4a5c30+0x10e0*i+0x1e2,9);}
        StreamFixture streams(0,tick);streams.export_original(ram);vm::Interpreter native;install_offline_program(native,ram,requested,b);vm::FlagState flags;vm::OfflineCoordinator coordinator;vm::Providers providers;providers.streams=&streams.owner;providers.stream_backend=&streams;std::uint8_t selected=2;
        original_offline_call(ram,requested,true);const auto result=coordinator.tick(native,requested,true,party,9,selected,flags,providers,4096,tick);
        check(result.status==(requested==1?vm::Status::completed:vm::Status::yielded));check(result.invocations==(requested==1?3u:1u));compare_offline_channels(native,ram);streams.compare_original(ram);check(selected==ram[0x4baded]);
        streams.events.clear();selected=2;const auto old_pc=native.channels()[requested].current;
        check(coordinator.tick(native,requested,true,party,9,selected,flags,providers).status==vm::Status::provider_unavailable);check(selected==2);check(native.channels()[requested].current==old_pc);check(streams.events.empty());
    }
}
}
void sub_00107AB0_0x107ab0(std::uint8_t* r,R5900Context* c,PS2Runtime*){std::memmove(r+GPR_U32(c,4),r+GPR_U32(c,5),GPR_U32(c,6));SET_GPR_U32(c,2,GPR_U32(c,4));done(c);}
