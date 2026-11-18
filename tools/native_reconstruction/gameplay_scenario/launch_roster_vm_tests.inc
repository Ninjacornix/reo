#include "game/native/gameplay_world/launch_roster.hpp"

namespace {
std::size_t launch_roster_cases{},launch_roster_refusals{};

void launch_roster_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    for(unsigned trial=0;trial<4096;++trial) {
        assertion_context="launch roster trial="+std::to_string(trial);
        ActorFixture actors(trial,std::uint8_t(trial%8));
        actors.world.mode=std::uint8_t(trial);
        actors.session->single_roster_setup=std::uint8_t(trial*17u);
        actors.export_original(ram);
        ram[0x4bae32]=actors.session->single_roster_setup;
        std::array<std::byte,32> record;
        for(unsigned byte=0;byte<record.size();++byte)
            record[byte]=std::byte((trial*17u+byte*71u)&255u);
        record[2]=std::byte((trial/15)%4);
        record[4]=std::byte(trial%5);
        record[5]=std::byte((trial/5)%3);
        for(unsigned index=0;index<8;++index) {
            const auto actor=actors.world.primary(index);
            actor->active=(trial+index)%3!=0;
            actor->appearance_variant=std::uint8_t(trial+index);
            actor->model_variant=std::uint16_t(trial*65521u+index);
            actor->ai_control=std::uint8_t((trial+index)%4);
            const auto at=0x4a5c30+0x10e0u*index;
            ram[at]=actor->active?0x80:0;
            ram[at+0xbbc]=actor->appearance_variant;
            fixture_write(ram.data(),at+0xbb4,actor->model_variant);
            ram[at+0xff0]=actor->ai_control;
        }
        std::memcpy(ram.data()+0x316680,record.data(),record.size());
        R5900Context original;
        PS2Runtime runtime;
        SET_GPR_U32(&original,29,0x7f0000);
        SET_GPR_U32(&original,31,0xdeadbeef);
        o2_005EB0D0_0x5eb0d0(ram.data(),&original,&runtime);
        check(original.pc==0xdeadbeef);
        const auto launch=reo::native::gameplay_session::parse_launch_roster(record);
        check(launch.has_value());
        check(reo::native::gameplay_world::apply_launch_roster(actors.world,actors.choices,*launch));
        check(actors.session->primary_population==fixture_read<std::uint32_t>(ram.data(),0x4baea0));
        check(std::uint8_t(*actors.session->primary_population)==ram[0x4bae8f]);
        check(actors.session->gameplay_flags==ram[0x4bae96]);
        check(actors.session->scenario==fixture_read<std::uint16_t>(ram.data(),0x3243da));
        check(actors.session->single_roster_setup==ram[0x4bae32]);
        actors.compare_original(ram);
        for(unsigned index=0;index<8;++index) {
            const auto actor=actors.world.primary(index);
            const auto at=0x4a5c30+0x10e0u*index;
            check(actor->active==bool(ram[at]));
            check(actor->appearance_variant==ram[at+0xbbc]);
            check(actor->model_variant==fixture_read<std::uint16_t>(ram.data(),at+0xbb4));
            check(actor->ai_control==ram[at+0xff0]);
        }
        ++launch_roster_cases;
    }

    ActorFixture actors;
    std::array<std::byte,32> record{};
    check(!reo::native::gameplay_session::parse_launch_roster(std::span<const std::byte>(record).first(31)));
    ++launch_roster_refusals;
    record[4]=std::byte{5};
    check(!reo::native::gameplay_session::parse_launch_roster(record));
    ++launch_roster_refusals;
    record[4]=std::byte{0};record[5]=std::byte{3};
    check(!reo::native::gameplay_session::parse_launch_roster(record));
    ++launch_roster_refusals;
    record[5]=std::byte{0};record[2]=std::byte{4};
    check(!reo::native::gameplay_session::parse_launch_roster(record));
    ++launch_roster_refusals;
    record[2]=std::byte{0};record[4]=std::byte{1};
    const auto launch=reo::native::gameplay_session::parse_launch_roster(record);
    check(launch.has_value());
    const auto random=actors.session->random.state();
    const auto choice=actors.choices.state();
    check(actors.world.retire_primary(0)==reo::native::gameplay_actors::EntityStatus::completed);
    check(!reo::native::gameplay_world::apply_launch_roster(actors.world,actors.choices,*launch));
    check(actors.session->random.state()==random&&!actors.session->primary_population);
    check(actors.choices.state().table_row==choice.table_row&&actors.choices.state().used==choice.used);
    ++launch_roster_refusals;
    check(actors.world.close()==reo::native::gameplay_world::Status::completed);
    check(!reo::native::gameplay_world::apply_launch_roster(actors.world,actors.choices,*launch));
    ++launch_roster_refusals;
    assertion_context.clear();
}
}
