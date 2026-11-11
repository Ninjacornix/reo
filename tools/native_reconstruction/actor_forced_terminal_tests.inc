#include "game/native/gameplay_world/actor_forced_terminal.hpp"

unsigned forced_terminal_cases{},forced_terminal_messages{},forced_terminal_refusals{},local_player_message_cases{};
namespace forced_terminal_fixture {
using namespace recovery_fixture;

Message action_message(const u::ActorActionMessage& message) {
    return {7,unsigned(message.route),message.channel,message.flags,message.values[0],message.values[1],
            message.values[2],message.values[3],message.equipment};
}
struct Sink final:recovery_fixture::Sink {
    using recovery_fixture::Sink::send;
    bool send(const u::ActorActionMessage& message) noexcept override {
        messages.push_back(action_message(message));
        return messages.size()!=reject;
    }
};

void prepare(Consuming& fixture,Ui& ui,unsigned trial) {
    seed(fixture,trial);
    fixture.reset(trial*65521u);
    fixture.mode(trial%4,(trial/4)%4);
    fixture.q.world.room=std::uint16_t(trial%128);
    put(fixture.q.memory,0x3243dc,fixture.q.world.room);
    fixture.q.world.paused=std::int8_t((trial>>4)%3);
    fixture.q.memory[0x4badf8]=std::uint8_t(fixture.q.world.paused);
    fixture.q.session->message_phase=trial%3?1:0;
    fixture.q.memory[0x3243fb]=std::uint8_t(fixture.q.session->message_phase);
    fixture.q.session->inventory_owner=99;
    fixture.q.memory[0x4badee]=99;
    fixture.q.session->cutscene_requests.limit_override=(trial&1)!=0;
    fixture.q.memory[0x4bae77]=fixture.q.session->cutscene_requests.limit_override;
    fixture.q.session->actor_message_suppression=std::uint16_t(trial%8);
    put(fixture.q.memory,0x744638,fixture.q.session->actor_message_suppression);
    recovery_fixture::source_calls.clear();
    recovery_fixture::source_messages.clear();
    ui.calls.clear();
    ui.index=fixture.q.world.mode==0?0:fixture.q.world.selected_actor;
    recovery_fixture::source_index=ui.index;
    recovery_fixture::mutation=trial%29?0:trial%3;
    for(unsigned index=0;index<4;++index) {
        const auto actor=fixture.q.world.primary(index);
        actor->inventory={};
        actor->inventory.carried={3,4,0,0};
        actor->inventory.storage={5,6,0};
        actor->selected_resource=0;
        actor->secondary_equipped_resource=0;
        actor->resource_action=0;
        actor->status=trial*65521u;
        actor->auxiliary_status=trial%7?0:0x02000000u;
        actor->primary=std::uint8_t(trial%6);
        actor->secondary=std::uint8_t(trial);
        actor->phase=std::uint8_t(trial>>8);
        actor->subphase=17;
        actor->motion_class=9;
        actor->previous_motion_class=11;
        actor->current=std::bit_cast<std::int16_t>(std::uint16_t(trial*257u));
        actor->maximum=1000;
        actor->recovery_timer=23;
        actor->terminal_countdown=17;
        actor->gauge_value=0;
        actor->class_marker=0;
        actor->action_flags=std::uint16_t(trial);
        actor->pending_notice=std::uint16_t(trial);
        actor->equipment_notice_slot=17;
        actor->equipment_notice_peer=19;
        actor->equipment_notice_parameter=23;
        actor->equipment_notice_detail=29;
        actor->position={float(trial),-float(trial),float(trial*7)};
        actor->orientation={1,std::bit_cast<std::int16_t>(std::uint16_t(trial)),3,4};
        actor->saved_action_position={-1,-2,-3};
        actor->saved_action_yaw=-7;
        actor->room=fixture.q.world.room;
        actor->interaction_resource=17;
        actor->aim_pitch_adjustment=-21;
        actor->aim_target_pitch=37;
        actor->aim_target_index=255;
        actor->explicit_resource_pair={11,12};
        actor->equipment_slot=3;
        actor->grid=5;
        fixture.actor(index,std::uint8_t((trial>>6)%3),std::uint8_t(trial%8));
        recovery_fixture::export_actor(fixture,index);
        const auto raw=0x4a5c30+0x10e0u*index;
        put(fixture.q.memory,raw+0x1e2,actor->room);
        fixture.q.memory[raw+0xc80]=17;
        put(fixture.q.memory,raw+0xbc8,std::int16_t(-21));
        put(fixture.q.memory,raw+0xcd4,std::int16_t(37));
        fixture.q.memory[raw+0xcdc]=255;
        fixture.q.memory[raw+0xcaa]=11;
        fixture.q.memory[raw+0xcab]=12;
        fixture.q.memory[raw+0xc7c]=actor->selected_resource;
        fixture.q.memory[raw+0xc7f]=actor->equipment_slot;
        fixture.q.memory[raw+0xcb0]=actor->grid;
        fixture.q.memory[raw+0xda5]=actor->equipment_notice_detail;
    }
}

void compare(Consuming& fixture,const Ui& ui,const Sink& sink) {
    check(recovery_fixture::source_calls==ui.calls);
    check(recovery_fixture::source_messages==sink.messages);
    compare_items(fixture.q);
    fixture.compare_events();
    for(unsigned index=0;index<4;++index) {
        const auto actor=fixture.q.world.primary(index);
        terminal_fixture::compare_terminal_actor(fixture.q,*actor,index);
        check(recovery_fixture::observe(fixture,index)==recovery_fixture::observe(fixture.q.memory,index));
    }
    fixture.q.compare_world();
    check(fixture.q.session->cutscene_requests.limit_override==bool(fixture.q.memory[0x4bae77]));
    check(fixture.q.session->actor_message_suppression==get<std::uint16_t>(fixture.q.memory,0x744638));
}
}

bool actor_forced_terminal_port(std::uint8_t* memory,R5900Context* context) {
    if(context->pc!=0x811190&&context->pc!=0x810870)return false;
    const auto at=GPR_U32(context,5);
    if(memory[at]!=7)return false;
    check(memory[at+1]==12&&!GPR_U32(context,6)&&GPR_U32(context,7)==4);
    reo::native::gameplay_update::ActorActionMessage message;
    message.route=context->pc==0x811190?reo::native::gameplay_update::MessageRoute::mode_zero:
                                                    reo::native::gameplay_update::MessageRoute::mode_one;
    message.channel=GPR_U32(context,4);
    message.flags=get<std::uint16_t>(memory,at+4);
    for(unsigned index=0;index<4;++index)message.values[index]=memory[at+6+index];
    message.equipment=memory[at+10];
    recovery_fixture::source_messages.push_back(forced_terminal_fixture::action_message(message));
    return true;
}

void compare_actor_forced_terminal(const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram) {
    using namespace forced_terminal_fixture;
    actor_forced_terminal_capture=actor_recovery_capture=true;
    gauge_progression_capture=false;
    const auto assets=factory_load(static_path,16),tables=factory_load(template_path,5);
    for(const auto& table:tables) {
        forced_terminal_fixture::Sink sink;
        Consuming fixture(ram,assets[0],table,&sink);
        g::ActorResourceOperations operations(fixture.recipes);
        Ui ui(fixture);
        g::ActorForcedTerminal terminal(fixture.update,operations,ui);
        for(unsigned trial=0;trial<2048;++trial) {
            prepare(fixture,ui,trial);
            sink.messages.clear();
            const auto mode=trial%11==0?0xffffffffu:trial%3;
            call(fixture.q.memory,0x6671d0,{mode});
            terminal.force(mode);
            compare(fixture,ui,sink);
            forced_terminal_messages+=unsigned(sink.messages.size());
            ++forced_terminal_cases;
        }
        for(unsigned trial=0;trial<1024;++trial) {
            prepare(fixture,ui,trial);
            recovery_fixture::mutation=0;
            sink.messages.clear();
            const auto index=(trial>>2)%4;
            const auto selector=trial%3==0?u::ActorMessageSelector::none:
                                trial%3==1?u::ActorMessageSelector::snapshot:u::ActorMessageSelector::action;
            call(fixture.q.memory,0x67eb60,{0x4a5c30+0x10e0u*index,std::uint32_t(selector)});
            check(fixture.update.record_local_actor_message(fixture.q.world.identity(index),selector)==u::PublicationStatus::completed);
            compare(fixture,ui,sink);
            ++local_player_message_cases;
        }
        prepare(fixture,ui,1);
        ui.available=false;
        check(!terminal.apply(fixture.q.world,0)&&fixture.q.session->inventory_owner==0);
        ++forced_terminal_refusals;
        ui.available=true;
        g::World foreign({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());
        check(!terminal.apply(foreign,0));
        ++forced_terminal_refusals;
        check(fixture.update.close()==u::Status::completed&&!terminal.apply(fixture.q.world,0));
        ++forced_terminal_refusals;
    }
    actor_forced_terminal_capture=actor_recovery_capture=false;
}
