#include "game/native/gameplay_scenario/scene_record_commands.hpp"
namespace {
std::size_t scene_record_eligibility_handlers{},scene_record_eligibility_dispatches{};
std::size_t scene_record_retirement_handlers{},scene_record_retirement_dispatches{};
void scene_record_eligibility_tests(){
    std::vector<std::uint8_t> ram(0x800000);
    NoticeSink notices;vm::FlagState flags(&notices);
    std::uint32_t seed=0x693164u;
    for(unsigned sample=0;sample<64;++sample)for(std::uint32_t id=0;id<256;++id){
        vm::SceneRecordEligibility::Words words;
        for(auto& word:words){seed=seed*1664525u+1013904223u;word=seed;}
        auto state=initial_flags();state.scene_record_eligibility.restore(words);
        state.scenario_owners.fill(0xa5);flags.restore(state);
        std::memcpy(ram.data()+0x4baa30,words.data(),32);
        std::fill(ram.begin()+0x4baa50,ram.begin()+0x4bac50,0xa5);
        fixture_write(ram.data(),0x10000,id);
        R5900Context context;PS2Runtime runtime;
        SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,31,0xdeadbeef);
        o2_00694390_0x694390(ram.data(),&context,&runtime);
        check(context.pc==0xdeadbeef&&GPR_U32(&context,2)==0);
        check(flags.write(vm::FlagBank::scene_record_eligibility,id,true));
        check(std::memcmp(ram.data()+0x4baa30,flags.snapshot().scene_record_eligibility.snapshot().data(),32)==0);
        check(flags.get(vm::FlagBank::scene_record_eligibility,id)==true);
        check(flags.snapshot().scenario_owners==state.scenario_owners);
        check(flags.snapshot().shared.scenario==state.shared.scenario);
        check(flags.snapshot().shared.secondary==state.shared.secondary);
        for(unsigned i=0;i<512;++i)check(ram[0x4baa50+i]==0xa5);
        vm::FlagState restored;restored.restore(flags.snapshot());
        check(restored.snapshot().scene_record_eligibility==flags.snapshot().scene_record_eligibility);
        check(flags.write(vm::FlagBank::scene_record_eligibility,id,false));
        check(flags.get(vm::FlagBank::scene_record_eligibility,id)==false);
        ++scene_record_eligibility_handlers;
    }
    check(notices.scenario_events.empty()&&notices.room_events.empty());
    for(const auto id:{256u,257u,511u,0x80000000u,0xffffffffu}){
        const auto before=flags.snapshot().scene_record_eligibility;
        check(!flags.get(vm::FlagBank::scene_record_eligibility,id));
        check(!flags.write(vm::FlagBank::scene_record_eligibility,id,true));
        check(before==flags.snapshot().scene_record_eligibility);
        std::vector<std::byte> bytes;emit(bytes,0x164,{id});
        for(auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){
            bool refused=false;try{vm::Program p({bytes},profile);}catch(const std::invalid_argument&){refused=true;}check(refused);
        }
    }
    for(auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){
        std::vector<std::byte> short_record;emit(short_record,0x164);
        bool refused=false;try{vm::Program p({short_record},profile);}catch(const std::invalid_argument&){refused=true;}check(refused);
    }
    // Actual ordinary and offline dispatchers, including all distinct offline
    // category/relation filter outcomes. The canonical bank is never actor-
    // delta merged or redirected to shared scenario flags.
    install_original_tables(ram);
    for(bool offline:{false,true})for(unsigned category=0;category<(offline?5u:1u);++category)
    for(unsigned relation=0;relation<(offline?4u:1u);++relation)for(std::uint32_t id=0;id<256;++id){
        const auto profile=offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary;
        std::vector<std::byte> bytes;emit(bytes,0x164,{id});const auto tail=emit(bytes,0xa);
        auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},profile);
        check(program->needs_flags()&&!program->unsupported());
        vm::Interpreter native;check(native.restore_channel(0,{program,{0,0},{0,tail},0,0,0})==vm::Status::completed);
        std::memcpy(ram.data()+0x10000,bytes.data(),bytes.size());
        fixture_write<std::uint32_t>(ram.data(),0x90000,0x10000);
        fixture_write<std::uint32_t>(ram.data(),0x4bace0,0x10000);
        fixture_write<std::uint32_t>(ram.data(),0x4bad28,0x10000+tail);
        fixture_write<std::uint32_t>(ram.data(),0x4bad40,0x90000);
        fixture_write<std::uint32_t>(ram.data(),0x4bacf8,0);
        fixture_write<std::uint32_t>(ram.data(),0x4bad10,0);
        fixture_write<std::uint32_t>(ram.data(),0x4bad58,0);
        fixture_write<std::uint32_t>(ram.data(),0x75a4b0,category);
        fixture_write<std::uint32_t>(ram.data(),0x75a4c0,relation);
        ram[0x3243e8]=1;ram[0x4baded]=0;
        auto initial=initial_flags();vm::SceneRecordEligibility::Words words;
        words.fill(0x503164a5u);initial.scene_record_eligibility.restore(words);flags.restore(initial);
        std::memcpy(ram.data()+0x4baa30,words.data(),32);export_flags(ram,initial);
        R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,4,0);SET_GPR_U32(&context,29,0x7f0000);SET_GPR_U32(&context,31,0xdeadbeef);
        if(offline)o2_007006D0_0x7006d0(ram.data(),&context,&runtime);else o2_0068C660_0x68c660(ram.data(),&context,&runtime);
        check(context.pc==0xdeadbeef);
        vm::Providers providers;providers.flags=providers.canonical_flags=&flags;
        auto result=offline?native.tick_offline_channel(0,{}, {category,relation,0},providers):native.tick(0,{},providers);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);compare_flags(ram,flags.snapshot());
        check(std::memcmp(ram.data()+0x4baa30,flags.snapshot().scene_record_eligibility.snapshot().data(),32)==0);
        check(notices.scenario_events.empty()&&notices.room_events.empty());
        ++scene_record_eligibility_dispatches;
    }
    std::vector<std::byte> bytes;emit(bytes,0x110,{0,123});emit(bytes,0x164,{255});emit(bytes,0xa);
    vm::Interpreter missing;check(missing.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes}))==vm::Status::completed);
    check(missing.tick(0,{}).status==vm::Status::provider_unavailable&&missing.counters()[0]==0);
}
}

namespace {
void seed_scene_record_retirement(ActorFixture& actors,vm::FlagState& flags,
                                 std::vector<std::uint8_t>& ram,unsigned trial,std::uint32_t id){
    auto initial=initial_flags();vm::SceneRecordEligibility::Words words;
    for(unsigned index=0;index<words.size();++index)words[index]=0xdeadbeefu^(trial*31337u+index*97u);
    initial.scene_record_eligibility.restore(words);flags.restore(initial);
    std::memcpy(ram.data()+0x4baa30,words.data(),32);export_flags(ram,initial);
    // No imported rows: the source nevertheless scans every physical row.
    check(actors.session->enemy_descriptors.count()==0);
    for(unsigned index=0;index<256;++index){
        auto& descriptor=*actors.session->enemy_descriptors.record(index);
        descriptor.ordinal=std::uint8_t(index);descriptor.family=std::uint8_t(index%62);
        descriptor.condition=(index+trial)%7?std::uint8_t(id):std::uint8_t(id+1u);
        descriptor.owner_mode=std::uint8_t((index+trial)%3?0:1u+((index+trial)&0x7fu));
    }
    auto& controls=actors.session->ai_control_requests;
    for(unsigned index=0;index<64;++index){
        auto& entry=*controls.registration(index);entry.active=std::uint8_t((index+trial)%5!=0);
        entry.kind=std::uint8_t((index+trial)%4?2:1);
        entry.target=std::int16_t((index/2u+trial*17u)%256u); // duplicate registrations deliberately retained
        entry.phase=std::uint8_t(index+trial);entry.owner_tag=std::uint8_t(trial*3u+index);
        for(unsigned lane=0;lane<4;++lane){entry.payload[lane]=std::uint8_t(index*5u+lane);entry.counters[lane]=std::uint16_t(0x8000u+index*17u+lane+trial);}
    }
    export_enemies(actors.session->enemy_descriptors,ram);export_npc_controls(controls,ram);
}
void compare_scene_record_retirement(ActorFixture& actors,const vm::FlagState& flags,
                                    const std::vector<std::uint8_t>& ram){
    compare_enemies(actors.session->enemy_descriptors,ram);
    compare_npc_controls(actors.session->ai_control_requests,ram);
    compare_flags(ram,flags.snapshot());
    check(std::memcmp(ram.data()+0x4baa30,flags.snapshot().scene_record_eligibility.snapshot().data(),32)==0);
}
void scene_record_retirement_tests(){
    std::vector<std::uint8_t> ram(0x800000);ActorFixture actors;NoticeSink notices;vm::FlagState flags(&notices);
    for(unsigned trial=0;trial<2048;++trial){
        const auto id=std::uint32_t(trial&255u);seed_scene_record_retirement(actors,flags,ram,trial,id);
        fixture_write(ram.data(),0x10000,id);R5900Context context;PS2Runtime runtime;
        SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,29,0x7f0000);SET_GPR_U32(&context,31,0xdeadbeef);
        o2_006943D0_0x6943d0(ram.data(),&context,&runtime);
        check(context.pc==0xdeadbeef&&GPR_U32(&context,2)==0);
        check(vm::clear_scene_record_eligibility(flags,actors.world,id));
        compare_scene_record_retirement(actors,flags,ram);
        check(notices.scenario_events.empty()&&notices.room_events.empty());++scene_record_retirement_handlers;
    }
    install_original_tables(ram);
    for(bool offline:{false,true})for(unsigned category=0;category<(offline?5u:1u);++category)
    for(unsigned relation=0;relation<(offline?4u:1u);++relation)for(std::uint32_t id=0;id<256;id+=4){
        const auto trial=id+category*257u+relation*1009u;seed_scene_record_retirement(actors,flags,ram,trial,id);
        const auto profile=offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary;
        std::vector<std::byte> bytes;emit(bytes,0x165,{id});const auto tail=emit(bytes,0xa);
        auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes},profile);
        check(program->needs_flags()&&program->needs_world()&&program->needs_canonical_flags()&&!program->unsupported());
        vm::Interpreter native;check(native.restore_channel(0,{program,{0,0},{0,tail},0,0,0})==vm::Status::completed);
        std::memcpy(ram.data()+0x10000,bytes.data(),bytes.size());
        fixture_write<std::uint32_t>(ram.data(),0x90000,0x10000);
        fixture_write<std::uint32_t>(ram.data(),0x4bace0,0x10000);
        fixture_write<std::uint32_t>(ram.data(),0x4bad28,0x10000+tail);
        fixture_write<std::uint32_t>(ram.data(),0x4bad40,0x90000);
        fixture_write<std::uint32_t>(ram.data(),0x4bacf8,0);
        fixture_write<std::uint32_t>(ram.data(),0x4bad10,0);
        fixture_write<std::uint32_t>(ram.data(),0x4bad58,0);
        fixture_write<std::uint32_t>(ram.data(),0x75a4b0,category);
        fixture_write<std::uint32_t>(ram.data(),0x75a4c0,relation);
        ram[0x3243e8]=1;ram[0x4baded]=actors.world.selected_actor=0;
        R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,4,0);SET_GPR_U32(&context,29,0x7f0000);SET_GPR_U32(&context,31,0xdeadbeef);
        if(offline)o2_007006D0_0x7006d0(ram.data(),&context,&runtime);else o2_0068C660_0x68c660(ram.data(),&context,&runtime);
        check(context.pc==0xdeadbeef);
        vm::Providers providers;providers.flags=providers.canonical_flags=&flags;providers.world=&actors.world;
        const auto result=offline?native.tick_offline_channel(0,{}, {category,relation,0},providers):native.tick(0,{},providers);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);compare_scene_record_retirement(actors,flags,ram);
        check(notices.scenario_events.empty()&&notices.room_events.empty());++scene_record_retirement_dispatches;
    }
    for(const auto id:{256u,257u,0x80000000u,0xffffffffu}){
        const auto before=flags.snapshot().scene_record_eligibility;
        std::array<reo::native::gameplay_ai::ControlRegistration,64> controls;
        std::copy(actors.session->ai_control_requests.registrations().begin(),actors.session->ai_control_requests.registrations().end(),controls.begin());
        check(!vm::clear_scene_record_eligibility(flags,actors.world,id));
        check(before==flags.snapshot().scene_record_eligibility);
        check(std::equal(controls.begin(),controls.end(),actors.session->ai_control_requests.registrations().begin()));
        std::vector<std::byte> bytes;emit(bytes,0x165,{id});
        for(auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){bool refused=false;try{vm::Program p({bytes},profile);}catch(const std::invalid_argument&){refused=true;}check(refused);}
    }
    {std::vector<std::byte> bytes;emit(bytes,0x110,{0,123});emit(bytes,0x165,{255});emit(bytes,0xa);
        vm::Interpreter missing;check(missing.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{bytes}))==vm::Status::completed);
        vm::Providers providers;providers.flags=providers.canonical_flags=&flags;
        check(missing.tick(0,{},providers).status==vm::Status::provider_unavailable&&missing.counters()[0]==0);
        providers.world=&actors.world;providers.canonical_flags=nullptr;
        check(missing.tick(0,{},providers).status==vm::Status::provider_unavailable&&missing.counters()[0]==0);
    }
    {ActorFixture closed;check(closed.world.close()==reo::native::gameplay_world::Status::completed);check(!vm::clear_scene_record_eligibility(flags,closed.world,0));}
}
}
