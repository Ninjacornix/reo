#include "game/native/gameplay_world/actor_placements.hpp"

namespace {
std::size_t actor_placement_dispatches{};

void actor_placement_vm_tests() {
    using reo::native::gameplay_world::Actor;
    constexpr std::uint32_t records = 0x4b8a70, queue = 0x4b9d00, flag = 0x4badc0;
    constexpr std::uint32_t actor_base = 0x4a5c30, actor_stride = 0x10e0;
    std::vector<std::uint8_t> ram(0x900000);
    install_original_tables(ram);
    vm::FlagState flags;
    for (unsigned trial = 0; trial < 512; ++trial) {
        const auto selected = std::uint8_t(trial & 7);
        const auto category = (trial >> 3) % 5;
        const auto relation = (trial >> 5) % 3;
        const auto offline = (trial & 0x40) != 0;
        assertion_context = "actor placement trial=" + std::to_string(trial);
        ActorFixture actors(trial, selected, offline);
        auto& placements = actors.session->actor_placements;
        actors.session->script_room_parameter = 0xaa;
        placements.selected_request = std::uint8_t(trial*17u);
        ram[0x4b9d17] = 0xaa;
        ram[flag] = placements.selected_request;
        ram[queue + 12] = 0xa5;
        actors.export_original(ram);
        ram[0x3243e8] = 1;
        fixture_write(ram.data(), 0x75a4b0, category);
        fixture_write(ram.data(), 0x75a4c0, relation);
        std::vector<std::byte> packet;
        put(packet, 32);
        for (unsigned i = 0; i < 32; ++i) {
            put(packet, (i + trial) * 1711u - 0x800010u);
            put(packet, 0x80001004u + trial * 319u - i);
            put(packet, 0xa5a50000u | ((i + trial) * 2311u & 65535u));
            put(packet, 0);
            put(packet, 0);
            put(packet, i * 543178u + trial * 13u - 0x80001000u);
            put(packet, 0);
            put(packet, 0);
        }
        check(placements.load_positions(packet));
        check(!placements.load_positions(std::span<const std::byte>(packet).first(packet.size()-1)));
        check(placements.position(31).has_value());
        std::memcpy(ram.data() + records, packet.data() + 4, packet.size() - 4);
        const auto actor_at = [&](unsigned i) { return actor_base + actor_stride * i; };
        const auto compare_actor = [&](unsigned i, bool export_fields) {
            auto actor = actors.world.primary(i);
            const auto at = actor_at(i);
            const auto field = [&]<class T>(std::uint32_t offset, const T& value) {
                if (export_fields) fixture_write(ram.data(), at + offset, value);
                else if (std::memcmp(ram.data() + at + offset, &value, sizeof(T)) != 0) {
                    assertion_context += " actor=" + std::to_string(i) + " offset=" + std::to_string(offset) +
                        " guest=" + std::to_string(ram[at + offset]) +
                        " native=" + std::to_string(*reinterpret_cast<const std::uint8_t*>(&value));
                    check(false);
                } else check(true);
            };
            field(0x38, actor->position);
            field(0x44, actor->previous_position);
            field(0x90, actor->orientation);
            field(0xa0, actor->previous_orientation);
            field(0x548, actor->action_flags);
            field(0xb90, actor->surface_blend_weight);
            field(0x4e4, actor->root_motion_delta);
            field(0xabc, actor->interaction_request->anchor);
            field(0xac8, actor->interaction_request->orientation);
            if (!export_fields) check(actor->interaction_request->kind == 42 && actor->interaction_request->endpoint == 89);
        };
        for (unsigned i = 0; i < 8; ++i) {
            auto actor = actors.world.primary(i);
            actor->active = ((i + trial) % 3) == 0;
            actor->character = std::uint8_t((i + trial) % 3);
            actor->position = {1,2,3};
            actor->previous_position = {-4,5,6};
            actor->orientation = {1,2,3,-4567};
            actor->previous_orientation = {2,3,4,-5};
            actor->root_motion_delta = {8,9,-10};
            actor->surface_blend_weight = 0.75f;
            actor->action_flags = 0x8123;
            actor->interaction_request.emplace();
            actor->interaction_request->kind = 42;
            actor->interaction_request->endpoint = 89;
            actor->interaction_request->orientation = 0x7ac8a5f0;
            ram[actor_at(i) + 0xb98] = actor->character;
            ram[actor_at(i)] = actor->active ? 0x80 : 0;
            compare_actor(i, true);
        }
        for (unsigned i = 0; i < 4; ++i) {
            check(placements.queue(i, std::uint8_t(5+i), std::uint8_t(8+i)));
            ram[queue + 3*i] = 0;
            ram[queue + 3*i + 1] = std::uint8_t(5+i);
            ram[queue + 3*i + 2] = std::uint8_t(8+i);
        }
        std::vector<std::byte> script;
        emit(script,1);
        emit(script,0x65,{0x12345600u|trial});
        emit(script,0x68,{(trial + 1) % 3, 0x12345678, 0xabcdef42});
        if (trial & 8) emit(script,0x6a);
        emit(script,0x69,{trial % 4,trial % 240,trial & 255});
        emit(script,0x69,{4,0xf0,(trial / 2) & 31});
        emit(script,0x69,{(trial >> 2) % 8,0xf1,255});
        emit(script,0xa);
        std::memcpy(ram.data()+0x10000,script.data(),script.size());
        fixture_write(ram.data(),0x4bace0,0x10000u);
        fixture_write(ram.data(),0x4bacf8,0u);
        fixture_write(ram.data(),0x4bad28,0u);
        vm::Interpreter native;
        const auto mode=offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary;
        check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{script},mode))==vm::Status::completed);
        vm::Providers providers;
        providers.world=&actors.world;
        providers.flags=&flags;
        providers.canonical_flags=&flags;
        const vm::TickContext context{true,false,selected};
        vm::TickResult result;
        if (offline) {
            original_offline_call(ram,0,false);
            result=native.tick_offline_channel(0,context,{category,relation,0},providers);
        } else {
            R5900Context original;
            PS2Runtime runtime;
            SET_GPR_U32(&original,29,0x7f0000);
            SET_GPR_U32(&original,31,0xdeadbeef);
            o2_0068C660_0x68c660(ram.data(),&original,&runtime);
            check(original.pc==0xdeadbeef);
            ++invocations;
            result=native.tick(0,context,providers);
        }
        check(result.status==vm::Status::yielded && result.position.offset==4);
        check(fixture_read<std::uint32_t>(ram.data(),0x4bace0)==0x10004u);
        for (unsigned i=0;i<8;++i) compare_actor(i,false);
        for (unsigned i=0;i<4;++i) {
            const auto& entry=placements.requests()[i];
            check(entry.state==ram[queue+3*i]&&entry.room==ram[queue+3*i+1]&&entry.position==ram[queue+3*i+2]);
        }
        check(ram[queue+12]==0xa5);
        check(placements.selected_request==ram[flag]);
        check(actors.session->script_room_parameter==ram[0x4b9d17]);
        ++actor_placement_dispatches;
    }
    assertion_context.clear();
}
}
