#include "game/native/gameplay_scenario/character_remap.hpp"

namespace {
std::size_t character_remap_dispatches{},character_remap_refusals{};

void export_character_assets(const vm::RoomActorAssets& assets,std::vector<std::uint8_t>& ram) {
    for(unsigned room=0;room<128;++room)for(unsigned slot=0;slot<4;++slot) {
        const auto& entry=(*assets.row(room))[slot];
        fixture_write(ram.data(),0x4b8e80+16*room+4*slot,entry.id);
        fixture_write(ram.data(),0x4b8e82+16*room+4*slot,entry.parameter);
    }
}
void compare_character_assets(const vm::RoomActorAssets& assets,const std::vector<std::uint8_t>& ram) {
    for(unsigned room=0;room<128;++room)for(unsigned slot=0;slot<4;++slot) {
        const auto& entry=(*assets.row(room))[slot];
        check(entry.id==fixture_read<std::uint16_t>(ram.data(),0x4b8e80+16*room+4*slot));
        check(entry.parameter==fixture_read<std::uint16_t>(ram.data(),0x4b8e82+16*room+4*slot));
    }
}

void character_remap_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    install_original_tables(ram);
    vm::FlagState flags;
    constexpr std::array<std::uint16_t,14> ids{0,1,64,199,200,201,202,203,204,205,206,207,208,209};
    constexpr std::array<std::uint8_t,14> variants{0,59,60,61,62,63,64,65,66,67,68,69,70,255};
    for(unsigned trial=0;trial<4096;++trial) {
        assertion_context="Character remap trial="+std::to_string(trial);
        const bool offline=(trial&1)!=0;
        const auto channel=std::uint8_t((trial/2)%6);
        const auto category=(trial/12)%5,relation=(trial/60)%3;
        ActorFixture actors(trial,0,offline);
        auto& session=*actors.session;
        session.primary_population=std::array<std::uint32_t,11>{0,1,2,3,4,5,6,7,8,0x80000008u,0xffffffffu}[trial%11];
        for(unsigned index=0;index<8;++index) {
            const auto actor=actors.world.primary(index);
            actor->active=(trial+index)%3!=0;
            actor->character=std::uint8_t(trial%3 ? (3*index+trial)%12 : index);
            session.missing_characters.values[index]=std::uint8_t(trial*17u+index*31u);
        }
        session.actor_placements.selected_request=std::uint8_t(trial*19u);
        seed_npcs(session.npc_descriptors,trial);
        for(unsigned index=0;index<64;++index) {
            auto& descriptor=*session.npc_descriptors.record(index);
            descriptor.template_id=descriptor.active ? ids[(index+trial)%ids.size()] : std::uint16_t(0xffffu-index);
        }
        for(unsigned room=0;room<128;++room)for(unsigned slot=0;slot<4;++slot) {
            auto& entry=(*session.room_actor_assets.row(room))[slot];
            entry.id=(room+slot+trial)%7 ? ids[(room+slot+trial)%ids.size()] : 65535;
            entry.parameter=std::uint16_t(trial*71u+room*17u+slot);
        }
        for(unsigned index=0;index<256;++index) {
            auto& descriptor=*session.enemy_descriptors.record(index);
            descriptor.family=std::uint8_t((index+trial)%3);
            descriptor.variant=variants[(index+trial)%variants.size()];
            descriptor.health=std::int16_t(index+trial);
        }
        actors.export_original(ram);
        fixture_write(ram.data(),0x4baea0,*session.primary_population);
        std::memcpy(ram.data()+0x4badb8,session.missing_characters.values.data(),8);
        ram[0x4badc0]=session.actor_placements.selected_request;
        export_npcs(session.npc_descriptors,ram);
        export_character_assets(session.room_actor_assets,ram);
        export_enemies(session.enemy_descriptors,ram);
        fixture_write(ram.data(),0x75a4b0,category);
        fixture_write(ram.data(),0x75a4c0,relation);
        ram[0x3243e8]=1;
        std::vector<std::byte> script;
        emit(script,1);emit(script,0x84);emit(script,0xa);
        std::memcpy(ram.data()+0x10000,script.data(),script.size());
        fixture_write(ram.data(),0x4bace0+4*channel,0x10000u);
        fixture_write(ram.data(),0x4bacf8+4*channel,0u);
        fixture_write(ram.data(),0x4bad28+4*channel,0u);
        vm::Interpreter native;
        const auto profile=offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary;
        check(native.install(channel,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{script},profile))==vm::Status::completed);
        vm::Providers providers;
        providers.world=&actors.world;providers.flags=&flags;providers.canonical_flags=&flags;
        if(offline) {
            original_offline_call(ram,channel,false);
            check(native.tick_offline_channel(channel,{true,false,0},{category,relation,0},providers).status==vm::Status::yielded);
        } else {
            invoke_npc_original(ram,o2_0068C660_0x68c660,{channel,0,0,0});
            ++invocations;
            check(native.tick(channel,{true,false,0},providers).status==vm::Status::yielded);
        }
        check(native.selected_channel()==ram[0x4badc1]);
        check(std::memcmp(ram.data()+0x4badb8,session.missing_characters.values.data(),8)==0);
        check(session.actor_placements.selected_request==ram[0x4badc0]);
        compare_npcs(session.npc_descriptors,ram);
        compare_character_assets(session.room_actor_assets,ram);
        compare_enemies(session.enemy_descriptors,ram);
        actors.compare_original(ram);
        ++character_remap_dispatches;
    }
    for(unsigned refusal=0;refusal<6;++refusal) {
        ActorFixture actors;
        auto& session=*actors.session;
        session.primary_population=0;
        session.missing_characters.values.fill(0xab);
        if(refusal==0)session.primary_population.reset();
        if(refusal==1)session.primary_population=9;
        if(refusal==2) {
            auto& descriptor=*session.npc_descriptors.record(0);
            descriptor.active=1;descriptor.template_id=210;
        }
        if(refusal==3)(*session.room_actor_assets.row(0))[0].id=210;
        if(refusal==4)check(actors.world.close()==reo::native::gameplay_world::Status::completed);
        vm::Interpreter native;
        std::vector<std::byte> script;
        emit(script,0x110,{0,123});emit(script,0x84);emit(script,0xa);
        check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{script}))==vm::Status::completed);
        vm::Providers providers;
        providers.world=refusal==5?nullptr:&actors.world;
        check(native.tick(0,{true,false,0},providers).status==vm::Status::provider_unavailable);
        check(native.counters()[0]==0);
        check(session.missing_characters.values==std::array<std::uint8_t,8>{0xab,0xab,0xab,0xab,0xab,0xab,0xab,0xab});
        ++character_remap_refusals;
    }
    {
        auto session=std::make_shared<reo::native::gameplay_world::Session>();
        reo::native::gameplay_world::World world(ActorFixture::profile(),session);
        session->primary_population=1;
        check(!vm::character_remap_ready(world));
        check(!vm::remap_missing_characters(world,0));
        ++character_remap_refusals;
    }
    assertion_context.clear();
}
}
