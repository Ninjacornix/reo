#include "game/native/gameplay_scenario/cutscene_cues.hpp"

namespace {
std::size_t cutscene_batches{},placement_packets{},room_placement_finishes{};
std::vector<std::uint32_t> original_scene_effects;

void cutscene_batch_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    vm::FlagState flags;
    for(unsigned trial=0;trial<4096;++trial) {
        assertion_context="cutscene batch trial="+std::to_string(trial);
        ActorFixture actors(trial,std::uint8_t(trial%8));
        actors.export_original(ram);
        for(unsigned index=0;index<8;++index) {
            const auto actor=actors.world.primary(index);
            actor->motion_style=std::uint8_t((trial+index)%3);
            ram[0x4a5c30+0x10e0u*index+0xb99]=actor->motion_style;
        }
        for(unsigned index=0;index<512;++index) {
            const auto owner=std::uint8_t((trial+index)%9);
            check(flags.scenario_owner(index,owner));
            ram[0x4baa50+index]=owner;
        }
        auto& requests=actors.session->cutscene_requests;
        for(unsigned padding=0;padding<trial%16;++padding) {
            requests.append({});
            check(requests.take().has_value());
        }
        constexpr std::array<std::uint16_t,8> kinds{0,1,2,3,4,5,256,257};
        const auto count=1+(trial/3)%15;
        for(unsigned index=0;index<count;++index) {
            vm::CutsceneRequests::Record request{
                kinds[(trial+index)%kinds.size()],std::uint16_t(trial*17+index),
                std::uint16_t(trial*71+index*3),std::uint16_t((trial+index)%8+((trial&64)?256:0)),
                std::uint16_t((trial+index)%512),1,2,3};
            requests.append(request);
        }
        std::memcpy(ram.data()+0x3b26d0,requests.records().data(),256);
        fixture_write<std::uint16_t>(ram.data(),0x3b27d0,requests.write_index());
        fixture_write<std::uint16_t>(ram.data(),0x3b27d8,requests.read_index());
        ram[0x4bae09]=99;
        original_scene_effects.clear();
        R5900Context original;
        PS2Runtime runtime;
        SET_GPR_U32(&original,29,0x7f0000);
        SET_GPR_U32(&original,31,0xdeadbeef);
        o2_005F0380_0x5f0380(ram.data(),&original,&runtime);
        check(original.pc==0xdeadbeef);
        const auto batch=vm::collect_cutscene_cues(actors.world,flags);
        check(batch.has_value());
        check(batch->mode==ram[0x38eccf]&&batch->current.area==ram[0x38ecd0]&&
              batch->current.scene==ram[0x38ecd1]&&batch->current.variant==ram[0x38ecd2]);
        check(batch->selector==fixture_read<std::uint32_t>(ram.data(),0x38ecd4));
        check(batch->actor_selection==fixture_read<std::uint32_t>(ram.data(),0x38ece0));
        check(batch->audio_count==ram[0x4bae0b]);
        for(std::size_t index=0;index<batch->audio_count;++index) {
            const auto& cue=batch->audio_cues[index];
            const auto at=0x4bae36+3*index;
            check(cue.area==ram[at]&&cue.scene==ram[at+1]&&cue.variant==ram[at+2]);
        }
        check(requests.read_index()==fixture_read<std::uint16_t>(ram.data(),0x3b27d8));
        check(requests.write_index()==fixture_read<std::uint16_t>(ram.data(),0x3b27d0));
        const std::vector<std::uint32_t> effects=batch->mode==1?
            std::vector<std::uint32_t>{0x371b70,0x6de480}:
            std::vector<std::uint32_t>{0x371ad0,0x6de590,batch->current.area,batch->current.scene,0,0};
        check(effects==original_scene_effects);
        check(ram[0x4bae09]==(batch->audio_count?1:99));
        ++cutscene_batches;
    }
    assertion_context.clear();
}

void placement_packet_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    for(unsigned trial=0;trial<4096;++trial) {
        assertion_context="placement packet trial="+std::to_string(trial);
        ActorFixture actors(trial,std::uint8_t(trial%4));
        auto& placements=actors.session->actor_placements;
        const auto count=1+trial%32;
        std::vector<std::byte> packet(4+32*count);
        fixture_write(reinterpret_cast<std::uint8_t*>(packet.data()),0,count);
        for(unsigned offset=4;offset<packet.size();offset+=4)
            fixture_write(reinterpret_cast<std::uint8_t*>(packet.data()),offset,trial*1664525u+offset*1013904223u);
        const auto population=trial%9;
        actors.session->primary_population=population;
        fixture_write(ram.data(),0x4baea0,population);
        for(unsigned index=0;index<8;++index) {
            const auto actor=actors.world.primary(index);
            actor->active=index<4&&(trial+index)%3;
            actor->status=(trial+index)%5?0:0x5e0;
            actor->auxiliary_status=trial*257u;
            actor->position={1,2,3};actor->previous_position={4,5,6};
            actor->orientation={7,8,9,10};actor->previous_orientation={11,12,13,14};
            const auto at=0x4a5c30+0x10e0u*index;
            ram[at]=actor->active?0x80:0;
            fixture_write(ram.data(),at+0xba0,actor->status);
            fixture_write(ram.data(),at+0xba4,actor->auxiliary_status);
            fixture_write(ram.data(),at+0x38,actor->position);
            fixture_write(ram.data(),at+0x44,actor->previous_position);
            fixture_write(ram.data(),at+0x90,actor->orientation);
            fixture_write(ram.data(),at+0xa0,actor->previous_orientation);
            if(index<4) {
                check(placements.queue(index,std::uint8_t(index+3),std::uint8_t((trial+index)%count)));
                const auto& request=placements.requests()[index];
                ram[0x4b9d00+3*index]=request.state;
                ram[0x4b9d01+3*index]=request.room;
                ram[0x4b9d02+3*index]=request.position;
            }
        }
        std::memcpy(ram.data()+0x10000,packet.data(),packet.size());
        R5900Context original;
        PS2Runtime runtime;
        SET_GPR_U32(&original,4,0x10000);
        SET_GPR_U32(&original,29,0x7f0000);
        SET_GPR_U32(&original,31,0xdeadbeef);
        o2_00662C90_0x662c90(ram.data(),&original,&runtime);
        check(original.pc==0xdeadbeef&&placements.apply_packet(actors.world,packet));
        check(fixture_read<std::uint32_t>(ram.data(),0x4b8e78)==count);
        for(unsigned index=0;index<8;++index) {
            const auto actor=actors.world.primary(index);
            const auto at=0x4a5c30+0x10e0u*index;
            check(std::memcmp(&actor->position,ram.data()+at+0x38,12)==0);
            check(std::memcmp(&actor->previous_position,ram.data()+at+0x44,12)==0);
            check(std::memcmp(actor->orientation.data(),ram.data()+at+0x90,8)==0);
            check(std::memcmp(actor->previous_orientation.data(),ram.data()+at+0xa0,8)==0);
            check(actor->auxiliary_status==fixture_read<std::uint32_t>(ram.data(),at+0xba4));
            if(index<4)check(placements.requests()[index].state==ram[0x4b9d00+3*index]);
        }
        ++placement_packets;
    }
    assertion_context.clear();
}

void room_placement_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    for(unsigned trial=0;trial<2048;++trial) {
        assertion_context="room placement completion trial="+std::to_string(trial);
        ActorFixture actors(trial,std::uint8_t(trial%4));
        actors.export_original(ram);
        actors.world.room=std::uint16_t(trial%128);
        actors.session->session_state=std::int16_t(std::int32_t((trial>>2)%5)-2);
        fixture_write(ram.data(),0x3243dc,actors.world.room);
        fixture_write(ram.data(),0x324200,actors.session->session_state);
        for(unsigned index=0;index<8;++index) {
            const auto actor=actors.world.primary(index);
            actor->room=std::uint16_t(trial+index*7);
            fixture_write(ram.data(),0x4a5e12+0x10e0u*index,actor->room);
            if(index<4) {
                const auto room=std::uint8_t((trial+index)%128);
                check(actors.session->actor_placements.queue(index,room,0));
                ram[0x4b9d01+3*index]=room;
            }
        }
        original_scene_effects.clear();
        R5900Context original;
        PS2Runtime runtime;
        SET_GPR_U32(&original,29,0x7f0000);
        SET_GPR_U32(&original,31,0xdeadbeef);
        o2_006040A0_0x6040a0(ram.data(),&original,&runtime);
        check(original.pc==0xdeadbeef);
        check(original_scene_effects==std::vector<std::uint32_t>{0x5d7d60,0x651850,0x5eb520});
        check(actors.session->actor_placements.finish_room_transition(actors.world));
        check(actors.world.room==fixture_read<std::uint16_t>(ram.data(),0x3243dc));
        check(actors.session->room_variant==fixture_read<std::uint16_t>(ram.data(),0x3243de));
        for(unsigned index=0;index<8;++index)
            check(actors.world.primary(index)->room==fixture_read<std::uint16_t>(ram.data(),0x4a5e12+0x10e0u*index));
        ++room_placement_finishes;
    }
    assertion_context.clear();
}

void transition_input_refusals() {
    ActorFixture actors;
    vm::FlagState flags;
    auto& requests=actors.session->cutscene_requests;
    requests.append({1,2,3,1,65535,0,0,0});
    const auto read=requests.read_index();
    check(!vm::collect_cutscene_cues(actors.world,flags)&&requests.read_index()==read);
    auto& placements=actors.session->actor_placements;
    std::vector<std::byte> packet(36);
    fixture_write(reinterpret_cast<std::uint8_t*>(packet.data()),0,1u);
    check(placements.load_positions(packet));
    check(!placements.apply_packet(actors.world,packet));
    actors.session->primary_population=1;
    actors.world.primary(0)->active=true;
    check(placements.queue(0,1,31));
    check(!placements.apply_packet(actors.world,packet));
    check(placements.requests()[0].state==0&&placements.position(0)&&!placements.position(1));
    check(!placements.apply_packet(actors.world,std::span<const std::byte>(packet).first(3)));
    actors.world.room=7;
    actors.session->room_variants=reo::native::gameplay_session::RoomVariants{};
    check(!placements.finish_room_transition(actors.world)&&actors.world.room==7&&!actors.session->room_variant);
    check(actors.world.close()==reo::native::gameplay_world::Status::completed);
    check(!placements.apply_packet(actors.world,packet)&&!placements.finish_room_transition(actors.world));
}
}

void o2_006DE480_0x6de480(std::uint8_t*,R5900Context* context,PS2Runtime*) {
    original_scene_effects.push_back(0x6de480);done(context);
}
void o2_006DE590_0x6de590(std::uint8_t*,R5900Context* context,PS2Runtime*) {
    original_scene_effects.push_back(0x6de590);
    for(unsigned argument=4;argument<8;++argument)original_scene_effects.push_back(GPR_U32(context,argument));
    done(context);
}
void o2_005D7D60_0x5d7d60(std::uint8_t*,R5900Context* context,PS2Runtime*) {
    original_scene_effects.push_back(0x5d7d60);done(context);
}
void o2_00651850_0x651850(std::uint8_t*,R5900Context* context,PS2Runtime*) {
    original_scene_effects.push_back(0x651850);done(context);
}
void o2_005EB520_0x5eb520(std::uint8_t*,R5900Context* context,PS2Runtime*) {
    original_scene_effects.push_back(0x5eb520);done(context);
}
void original_scene_mode_port(std::uint8_t*,R5900Context* context,PS2Runtime*) {
    original_scene_effects.push_back(context->pc);done(context);
}
