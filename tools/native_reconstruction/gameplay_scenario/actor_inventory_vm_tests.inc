#include "game/native/gameplay_scenario/resource_templates.hpp"

namespace {
std::size_t actor_inventory_dispatches{};

void actor_inventory_vm_tests() {
    constexpr std::uint32_t records = 0x3c5630, stride = 60, actor_base = 0x4a5c30;
    std::vector<std::uint8_t> ram(0x900000);
    install_original_tables(ram);
    vm::FlagState flags;
    constexpr std::array<std::uint16_t,15> content_ids{0xffff,0,17,300,301,302,399,400,401,413,420,421,599,10003,32767};
    vm::ResourceTemplates templates;
    std::vector<std::byte> item(32 + 24 * content_ids.size());
    const auto store = [&]<class T>(std::size_t at, T value) { std::memcpy(item.data() + at, &value, sizeof(value)); };
    store(0,3u);
    store(4,std::uint32_t(content_ids.size()));
    store(16,32u);
    for (std::size_t i = 0; i < content_ids.size(); ++i) store(32 + i * 24 + 18, content_ids[i]);
    check(templates.load(item));
    std::memcpy(ram.data() + 0x74b6e0, templates.state().selectors.data(), templates.state().selectors.size());
    for (unsigned trial = 0; trial < 2048; ++trial) {
        const auto offline = (trial & 1) != 0;
        const auto opcode = std::array{0x38u,0x39u,0x173u}[(trial>>1)%3];
        const bool special = opcode == 0x173;
        const auto selected = std::uint8_t((trial >> 2) & 7);
        const auto category = (trial >> 5) % 5;
        const auto relation = (trial >> 7) % 3;
        const auto content = content_ids[(trial >> 3) % content_ids.size()];
        const auto target = opcode == 0x38 ? trial % 11 : (trial >> 2) % 4;
        const auto selector = trial & 0x200 ? target | 0x8080u : target;
        assertion_context = "actor inventory trial=" + std::to_string(trial);
        ActorFixture actors(trial, selected, offline);
        auto& session = *actors.session;
        session.primary_population = special ? (trial & 0x80 ? 0x80000008u : 4u + trial % 5) :
            0xcdef4500u | (trial & 0x80 ? 0xf8u : 4u + trial % 5);
        actors.export_original(ram);
        fixture_write(ram.data(),0x4baea0,*session.primary_population);
        fixture_write(ram.data(),0x75a4b0,category);
        fixture_write(ram.data(),0x75a4c0,relation);
        ram[0x3243e8] = 1;
        for (unsigned i = 0; i < 8; ++i) {
            auto actor = actors.world.primary(i);
            const auto at = actor_base + 0x10e0u * i;
            actor->active = (trial+i)%7 != 0;
            actor->character = std::uint8_t((i+trial/4)%4);
            actor->inventory.carried.fill(201);
            actor->inventory.storage.fill(202);
            if ((trial+i)%3 != 0) actor->inventory.carried[(trial+i)%4]=0;
            if ((trial+i)%5 != 0) actor->inventory.storage[(trial+i)%32]=0;
            if (special) {
                actor->inventory.storage.fill(0);
                if (i == 1 || i == 2) {
                    actor->character = 7;
                    if (i == 2 || trial % 4 != 0) actor->inventory.storage[1] = 199;
                    for (unsigned j=0;j<(trial>>2)%5;++j) actor->inventory.storage[2+j] = 198;
                    actor->inventory.storage[14] = 197;
                }
            }
            ram[at] = actor->active ? 0x80 : 0;
            ram[at+0xb98] = actor->character;
            std::memcpy(ram.data()+at+0xc84,actor->inventory.carried.data(),4);
            std::memcpy(ram.data()+at+0xc88,actor->inventory.storage.data(),32);
        }
        vm::SceneResources resources;
        std::memset(ram.data()+records,0,256*stride);
        for (unsigned i=0;i<256;++i) {
            if (trial%13!=0 && (i+trial)%11!=0 && !(special&&i>=197&&i<=199)) continue;
            vm::SceneDescriptor descriptor;
            descriptor.active=1;
            descriptor.flags=0x43210000u+i;
            descriptor.instance_index=std::uint8_t(i);
            if(special&&i>=197&&i<=199)
                descriptor.attachment_id=i==199?413:i==198?content:301;
            check(resources.load(i,descriptor).has_value());
            const auto at=records+stride*i;
            ram[at]=descriptor.active;
            ram[at+2]=descriptor.instance_index;
            ram[at+0x2b]=descriptor.template_index;
            fixture_write(ram.data(),at+6,descriptor.attachment_id);
            fixture_write(ram.data(),at+0x18,descriptor.flags);
        }
        fixture_write<std::uint32_t>(ram.data(),0x743128,resources.active_count());
        std::vector<std::byte> script;
        emit(script,1);
        if(special)emit(script,opcode,{0xa1020000u|content,
            std::array{0xffffffffu,0u,1u,2u,3u,4u,0x7fffffffu}[(trial>>1)%7]});
        else emit(script,opcode,{0xf1230000u|selector,0xa1020000u|content,0xbcdf0000u|((trial*509)&65535u)});
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
        providers.scene_resources=&resources;
        providers.resource_templates=&templates;
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
        check(result.status==vm::Status::yielded&&result.position.offset==4);
        const auto original_count=fixture_read<std::uint32_t>(ram.data(),0x743128);
        if(resources.active_count()!=original_count)
            assertion_context+=" native resources="+std::to_string(resources.active_count())+
                " original resources="+std::to_string(original_count);
        check(resources.active_count()==original_count);
        for (unsigned i=0;i<8;++i) {
            const auto actor=actors.world.primary(i);
            const auto at=actor_base+0x10e0u*i;
            check(std::memcmp(ram.data()+at+0xc84,actor->inventory.carried.data(),4)==0);
            check(std::memcmp(ram.data()+at+0xc88,actor->inventory.storage.data(),32)==0);
        }
        for (unsigned i=0;i<256;++i) {
            const auto at=records+stride*i;
            const auto d=resources.get(*resources.slot(i));
            check(d->active==ram[at]);
            if (!d->active) continue;
            check(d->room==ram[at+1]&&d->instance_index==ram[at+2]&&d->kind==ram[at+3]);
            check(d->authored_id==fixture_read<std::uint16_t>(ram.data(),at+4));
            check(d->attachment_id==fixture_read<std::uint16_t>(ram.data(),at+6));
            check(d->flags==fixture_read<std::uint32_t>(ram.data(),at+0x18));
            check(d->parameter==fixture_read<std::int16_t>(ram.data(),at+0x24));
            check(d->ownership_tag==fixture_read<std::uint16_t>(ram.data(),at+0x28));
            check(d->template_index==ram[at+0x2b]);
        }
        ++actor_inventory_dispatches;
    }
    assertion_context.clear();
}
}
