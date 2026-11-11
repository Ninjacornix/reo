#include "game/native/gameplay_scenario/auxiliary_room_rows.hpp"
#include "game/native/gameplay_scenario/cutscene_requests.hpp"

namespace {
std::size_t cutscene_command_calls{}, scene_auxiliary_cells{}, auxiliary_timer_checks{}, roster_dispatches{}, scene_boot_dispatches{};
unsigned original_terminal_calls{};

struct TerminalFixture final : vm::ForcedActorTerminal {
    unsigned calls{};
    bool apply(reo::native::gameplay_world::World& world,std::uint32_t mode) noexcept override {
        if (mode || world.paused != 1 || !world.session().cutscene_requests.limit_override) std::terminate();
        ++calls;
        return true;
    }
};

void cutscene_commands() {
    std::vector<std::uint8_t> ram(0x900000);
    std::memcpy(ram.data()+0x7174d0,original_cutscene_fallback.data(),original_cutscene_fallback.size());
    constexpr std::array<std::int8_t,5> pauses{0,1,2,-1,-128};
    for (unsigned trial=0;trial<2048;++trial) {
        assertion_context="cutscene request trial="+std::to_string(trial);
        ActorFixture actors(trial,std::uint8_t(trial&7));
        auto& state=actors.session->cutscene_requests;
        const auto actor=actors.world.primary(actors.world.selected_actor);
        actor->status=((trial>>3)&7)*0x20u;
        actors.world.paused=pauses[(trial>>5)%pauses.size()];
        state.limit_override=(trial&0x100)!=0;
        actors.session->actor_placements.selected_request=(trial&0x200)!=0;
        for(unsigned i=0;i<(trial>>2)%16;++i) {
            vm::CutsceneRequests::Record record;
            for(unsigned j=0;j<record.size();++j)record[j]=std::uint16_t(trial+257*i+j);
            state.append(record);
        }
        for(unsigned i=0;i<(trial>>7)%6;++i)(void)state.take();
        const auto at=0x4a5c30+0x10e0u*actors.world.selected_actor;
        fixture_write(ram.data(),at+0xba0,actor->status);
        ram[0x4baded]=actors.world.selected_actor;
        ram[0x4badf8]=std::uint8_t(actors.world.paused);
        ram[0x4bae77]=state.limit_override;
        ram[0x4badc0]=actors.session->actor_placements.selected_request;
        std::memcpy(ram.data()+0x3b26d0,state.records().data(),256);
        fixture_write<std::uint16_t>(ram.data(),0x3b27d0,state.write_index());
        fixture_write<std::uint16_t>(ram.data(),0x3b27d8,state.read_index());
        std::array<std::uint16_t,5> args;
        for (unsigned i=0;i<args.size();++i) {
            const auto word=trial*0x51431u+i*0x7123u;
            fixture_write(ram.data(),0x10000+4*i,word);
            args[i]=std::uint16_t(word);
        }
        R5900Context original;
        PS2Runtime runtime;
        SET_GPR_U32(&original,4,0x10000u);
        SET_GPR_U32(&original,29,0x7f0000u);
        SET_GPR_U32(&original,31,0xdeadbeefu);
        original_terminal_calls=0;
        o2_0068F010_0x68f010(ram.data(),&original,&runtime);
        check(original.pc==0xdeadbeef);
        TerminalFixture terminal;
        check(vm::queue_cutscene(actors.world,args,&terminal));
        check(terminal.calls==original_terminal_calls);
        check(state.limit_override==bool(ram[0x4bae77]));
        check(std::uint8_t(actors.world.paused)==ram[0x4badf8]);
        check(actors.session->actor_placements.selected_request==bool(ram[0x4badc0]));
        check(fixture_read<std::uint16_t>(ram.data(),0x3b27d0)==state.write_index());
        check(fixture_read<std::uint16_t>(ram.data(),0x3b27d8)==state.read_index());
        check(std::memcmp(ram.data()+0x3b26d0,state.records().data(),256)==0);
        ++cutscene_command_calls;
    }
    assertion_context.clear();
}

void scene_auxiliary_rows(const char* path) {
    using namespace vm::content;
    std::ifstream input(path,std::ios::binary);
    check(bool(input));
    constexpr std::array<std::size_t,5> widths{26,52,36,33,100},counts{3,3,4,5,5};
    constexpr std::uint32_t base=0x690000;
    std::vector<std::uint8_t> ram(0x900000);
    fixture_write(ram.data(),0x324424,base);
    for (std::size_t scenario=0;scenario<widths.size();++scenario) {
        std::array<std::uint8_t,4> extent{};
        check(bool(input.read(reinterpret_cast<char*>(extent.data()),extent.size())));
        auto bytes=std::make_shared<std::vector<std::byte>>(fixture_read<std::uint32_t>(extent.data(),0));
        check(bool(input.read(reinterpret_cast<char*>(bytes->data()),bytes->size())));
        std::memcpy(ram.data()+base,bytes->data(),bytes->size());
        const auto table=fixture_read<std::uint32_t>(ram.data(),base+0x60);
        fixture_write(ram.data(),base+0x60,base+table);
        vm::AuxiliaryScene selection;
        auto rows=vm::AuxiliaryRoomRows::import(ScriptBank(bytes,BankFormat::scenario_evb));
        check(rows&&rows->room_count()==widths[scenario]&&rows->row_count()==counts[scenario]);
        selection.bind(std::move(rows));
        for(std::uint8_t row=0;row<counts[scenario];++row) {
            selection.select(row);
            ram[0x4b9d15]=row;
            for(std::uint16_t room=0;room<widths[scenario];++room) {
                fixture_write(ram.data(),0x3243dc,room);
                R5900Context original;
                PS2Runtime runtime;
                SET_GPR_U32(&original,31,0xdeadbeef);
                o2_006B73F0_0x6b73f0(ram.data(),&original,&runtime);
                check(original.pc==0xdeadbeef && selection.index(room)==GPR_U32(&original,2));
                ++scene_auxiliary_cells;
            }
            check(!selection.index(std::uint16_t(widths[scenario])));
        }
        selection.select(std::uint32_t(counts[scenario]));
        check(!selection.index(0));
    }
    for(unsigned trial=0;trial<1024;++trial) {
        vm::AuxiliaryScene selection;
        const auto row=std::uint8_t(trial);
        selection.select(row);
        selection.publish_loaded_index(42);
        ram[0x4b9d14]=42;
        ram[0x4b9d15]=row;
        const auto word=trial&0x100?std::uint32_t(row):trial&0x200?std::uint32_t(row)|0xfabc0000u:255u-row;
        fixture_write(ram.data(),0x10000,word);
        R5900Context original;
        PS2Runtime runtime;
        SET_GPR_U32(&original,4,0x10000);
        SET_GPR_U32(&original,31,0xdeadbeef);
        o2_00692A00_0x692a00(ram.data(),&original,&runtime);
        selection.select(word);
        check(original.pc==0xdeadbeef && selection.row()==ram[0x4b9d15] &&
              selection.loaded_index()==ram[0x4b9d14]);
    }
}

void auxiliary_timers() {
    vm::AuxiliaryScene auxiliary;
    std::vector<std::uint8_t> ram(0x900000);
    constexpr std::uint32_t bits=0x74e828,counters=0x74e868;
    for(unsigned frame=0;frame<8;++frame) {
        for(std::int32_t index=-31;index<512;++index) {
            const bool active=(std::uint32_t(index+31)*17+frame)%5!=0;
            R5900Context original;
            PS2Runtime runtime;
            SET_GPR_U32(&original,4,std::uint32_t(index));
            SET_GPR_U32(&original,5,active?0x100:0);
            SET_GPR_U32(&original,29,0x7f0000u);
            SET_GPR_U32(&original,31,0xdeadbeefu);
            o2_006BA230_0x6ba230(ram.data(),&original,&runtime);
            check(original.pc==0xdeadbeef && auxiliary.set_timer(index,active));
            if (index < 0) {
                const auto alias=std::uint32_t(index)&31u;
                check(auxiliary.timer_active(alias)==bool(fixture_read<std::uint32_t>(ram.data(),bits)&(1u<<alias)));
            }
        }
        R5900Context original;
        PS2Runtime runtime;
        SET_GPR_U32(&original,31,0xdeadbeefu);
        o2_006B80A0_0x6b80a0(ram.data(),&original,&runtime);
        auxiliary.advance_timers();
        check(original.pc==0xdeadbeef);
        for(unsigned index=0;index<512;++index) {
            const auto word=fixture_read<std::uint32_t>(ram.data(),bits+4*(index/32));
            check(auxiliary.timer_active(index)==bool(word&(1u<<(index&31))));
            check(auxiliary.timer(index)==fixture_read<std::uint32_t>(ram.data(),counters+4*index));
            ++auxiliary_timer_checks;
        }
    }
    check(!auxiliary.set_timer(-32,true)&&!auxiliary.set_timer(512,true));
}

void roster_conditions() {
    std::vector<std::uint8_t> ram(0x900000);
    install_original_tables(ram);
    vm::FlagState flags;
    for(unsigned trial=0;trial<512;++trial) {
        assertion_context="actor roster trial="+std::to_string(trial);
        const bool offline=(trial&1)!=0;
        const auto category=(trial>>4)%5;
        const auto relation=(trial>>6)%3;
        const auto character=(trial>>1)%9;
        const auto desired=(trial>>3)%5;
        ActorFixture actors(trial,0,offline);
        actors.session->primary_population=trial%9;
        actors.export_original(ram);
        fixture_write(ram.data(),0x4baea0,*actors.session->primary_population);
        fixture_write(ram.data(),0x75a4b0,category);
        fixture_write(ram.data(),0x75a4c0,relation);
        for(unsigned i=0;i<8;++i) {
            actors.world.primary(i)->active=(i+trial)%7==0;
            ram[0x4a5c30+0x10e0u*i]=actors.world.primary(i)->active?0x80:0;
        }
        fixture_write(ram.data(),0x4bada8,0u);
        ram[0x3243e8]=1;
        std::vector<std::byte> script;
        emit(script,1);
        emit(script,0xea,{0xf1230000u|character,0xabcd0000u|desired});
        emit(script,0x110,{0,3});
        emit(script,0xe4);
        emit(script,0x110,{0,4});
        emit(script,0xe5);
        emit(script,0xa);
        std::memcpy(ram.data()+0x10000,script.data(),script.size());
        fixture_write(ram.data(),0x4bace0,0x10000u);
        fixture_write(ram.data(),0x4bacf8,0u);
        fixture_write(ram.data(),0x4bad28,0u);
        vm::Interpreter native;
        const auto profile=offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary;
        check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{script},profile))==vm::Status::completed);
        vm::Providers providers;
        providers.world=&actors.world;
        providers.flags=&flags;
        providers.canonical_flags=&flags;
        vm::TickResult result;
        if(offline) {
            original_offline_call(ram,0,false);
            result=native.tick_offline_channel(0,{},{category,relation,0},providers);
        } else {
            R5900Context original;
            PS2Runtime runtime;
            SET_GPR_U32(&original,29,0x7f0000u);
            SET_GPR_U32(&original,31,0xdeadbeefu);
            o2_0068C660_0x68c660(ram.data(),&original,&runtime);
            check(original.pc==0xdeadbeef);
            ++invocations;
            result=native.tick(0,{},providers);
        }
        check(result.status==vm::Status::yielded);
        check(native.counters()[0]==fixture_read<std::uint32_t>(ram.data(),0x4bada8));
        check(native.channels()[0].condition==fixture_read<std::uint32_t>(ram.data(),0x4bad58));
        check(native.channels()[0].current.offset+0x10000u==fixture_read<std::uint32_t>(ram.data(),0x4bace0));
        ++roster_dispatches;
    }
    assertion_context.clear();
}

void scene_boot_dispatch() {
    std::vector<std::uint8_t> ram(0x900000);
    install_original_tables(ram);
    std::memcpy(ram.data()+0x7174d0,original_cutscene_fallback.data(),original_cutscene_fallback.size());
    vm::FlagState flags;
    for(unsigned trial=0;trial<512;++trial) {
        assertion_context="scene boot dispatch trial="+std::to_string(trial);
        const bool offline=(trial&1)!=0;
        const auto category=(trial>>4)%5;
        const auto relation=(trial>>6)%3;
        ActorFixture actors(trial,0,offline);
        actors.export_original(ram);
        const auto actor=actors.world.primary(0);
        actor->status=((trial>>1)&7)*0x20u;
        fixture_write(ram.data(),0x4a67d0,actor->status);
        fixture_write(ram.data(),0x75a4b0,category);
        fixture_write(ram.data(),0x75a4c0,relation);
        ram[0x3243e8]=1;
        ram[0x4badf8]=std::uint8_t((trial>>3)&1);
        actors.world.paused=std::int8_t(ram[0x4badf8]);
        ram[0x4bae77]=0;
        ram[0x4badc0]=1;
        ram[0x4b9d15]=0;
        ram[0x4b9d14]=0xff;
        actors.session->actor_placements.selected_request=true;
        std::memset(ram.data()+0x3b26d0,0,0x110);
        std::memset(ram.data()+0x74e828,0,64);
        const auto slot=trial%512;
        std::vector<std::byte> script;
        emit(script,1);
        emit(script,0x120,{slot});
        emit(script,0x120,{(slot+1)%512});
        emit(script,0x121,{slot});
        emit(script,0x122,{trial*7});
        emit(script,0x62,{trial,2,3,4,5});
        emit(script,0xa);
        std::memcpy(ram.data()+0x10000,script.data(),script.size());
        fixture_write(ram.data(),0x4bace0,0x10000u);
        fixture_write(ram.data(),0x4bacf8,0u);
        fixture_write(ram.data(),0x4bad28,0u);
        vm::Interpreter native;
        const auto profile=offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary;
        check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{script},profile))==vm::Status::completed);
        TerminalFixture terminal;
        vm::Providers providers;
        providers.world=&actors.world;
        providers.flags=&flags;
        providers.canonical_flags=&flags;
        providers.forced_terminal=&terminal;
        original_terminal_calls=0;
        vm::TickResult result;
        if(offline) {
            original_offline_call(ram,0,false);
            result=native.tick_offline_channel(0,{},{category,relation,0},providers);
        } else {
            R5900Context original;
            PS2Runtime runtime;
            SET_GPR_U32(&original,29,0x7f0000u);
            SET_GPR_U32(&original,31,0xdeadbeefu);
            o2_0068C660_0x68c660(ram.data(),&original,&runtime);
            check(original.pc==0xdeadbeef);
            ++invocations;
            result=native.tick(0,{},providers);
        }
        check(result.status==vm::Status::yielded);
        check(native.channels()[0].current.offset+0x10000u==fixture_read<std::uint32_t>(ram.data(),0x4bace0));
        const auto& queue=actors.session->cutscene_requests;
        const auto& auxiliary=actors.session->auxiliary_scene;
        check(std::memcmp(ram.data()+0x3b26d0,queue.records().data(),256)==0);
        check(fixture_read<std::uint16_t>(ram.data(),0x3b27d0)==queue.write_index());
        check(std::uint8_t(actors.world.paused)==ram[0x4badf8]);
        check(queue.limit_override==bool(ram[0x4bae77]));
        check(actors.session->actor_placements.selected_request==bool(ram[0x4badc0]));
        check(terminal.calls==original_terminal_calls);
        check(auxiliary.row()==ram[0x4b9d15] && auxiliary.loaded_index()==ram[0x4b9d14]);
        for(const auto i:{slot,(slot+1)%512}) {
            const auto word=fixture_read<std::uint32_t>(ram.data(),0x74e828+4*(i/32));
            check(auxiliary.timer_active(i)==bool(word&(1u<<(i&31))));
        }
        ++scene_boot_dispatches;
    }
    assertion_context.clear();
}
}

void o2_006671D0_0x6671d0(std::uint8_t* ram,R5900Context* context,PS2Runtime*) {
    check(GPR_U32(context,4)==0 && ram[0x4badf8]==1 && ram[0x4bae77]);
    ++original_terminal_calls;
    done(context);
}
