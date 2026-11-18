#include "game/native/gameplay_scenario/room_actor_assets.hpp"

namespace {
std::size_t room_actor_asset_dispatches{},room_actor_asset_queries{};

void room_actor_asset_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    install_original_tables(ram);
    vm::FlagState flags;
    for(unsigned trial=0;trial<2048;++trial) {
        assertion_context="room actor assets trial="+std::to_string(trial);
        const bool offline=(trial&1)!=0;
        const auto category=(trial>>4)%5;
        const auto relation=(trial>>6)%3;
        ActorFixture actors(trial,0,offline);
        auto& assets=actors.session->room_actor_assets;
        for(unsigned room=0;room<128;++room) {
            for(unsigned slot=0;slot<4;++slot) {
                const auto select=(trial+room*3+slot)%7;
                const vm::RoomActorAsset asset{
                    select<2?std::uint16_t(65535):std::uint16_t((trial+slot+room)%17),
                    select==0||select==2?std::uint16_t(65535):std::uint16_t(room*31+slot)};
                check(assets.append(room,asset));
            }
            const auto row=assets.row(room);
            for(unsigned slot=0;slot<4;++slot) {
                const auto at=0x4b8e80+room*16+slot*4;
                fixture_write(ram.data(),at,(*row)[slot].id);
                fixture_write(ram.data(),at+2,(*row)[slot].parameter);
            }
        }
        actors.export_original(ram);
        fixture_write(ram.data(),0x75a4b0,category);
        fixture_write(ram.data(),0x75a4c0,relation);
        ram[0x3243e8]=1;
        const auto room=trial%128;
        const auto id=trial%19;
        std::vector<std::byte> script;
        emit(script,1);
        emit(script,0x85,{room,0xabcd0000u|id,0x12340000u|trial});
        emit(script,0x85,{room,0xffff,trial});
        emit(script,0x87,{room,0xf1230000u|((id+1)%19)});
        emit(script,0x86,{0xffee0000u|((id+2)%19)});
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
        check(native.channels()[0].current.offset+0x10000u==fixture_read<std::uint32_t>(ram.data(),0x4bace0));
        for(unsigned room=0;room<128;++room) {
            const auto row=assets.row(room);
            for(unsigned slot=0;slot<4;++slot) {
                const auto at=0x4b8e80+room*16+slot*4;
                check((*row)[slot].id==fixture_read<std::uint16_t>(ram.data(),at));
                check((*row)[slot].parameter==fixture_read<std::uint16_t>(ram.data(),at+2));
            }
        }
        for(unsigned query=0;query<8;++query) {
            const auto selected_room=(room+query*17)%128;
            const auto descriptor=(trial+query)%64;
            const auto content=std::uint16_t(query==7?65535:(trial+query)%19);
            fixture_write(ram.data(),0x390210+descriptor*120+4,content);
            R5900Context original;
            PS2Runtime runtime;
            SET_GPR_U32(&original,4,descriptor);
            SET_GPR_U32(&original,5,selected_room);
            SET_GPR_U32(&original,31,0xdeadbeefu);
            o2_00684770_0x684770(ram.data(),&original,&runtime);
            check(original.pc==0xdeadbeef);
            check(assets.allowed(selected_room,content)==(GPR_S32(&original,2)==1));
            ++room_actor_asset_queries;
        }
        const auto previous=*assets.row(room);
        check(!assets.append(128,{1,2})&&!assets.remove(1,128)&&!assets.row(128)&&!assets.allowed(128,1));
        check(previous==*assets.row(room));
        assets.reset();
        for(unsigned room=0;room<128;++room)
            for(const auto& asset:*assets.row(room))check(asset==vm::RoomActorAsset{});
        ++room_actor_asset_dispatches;
    }
    assertion_context.clear();
}
}
