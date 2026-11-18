#include "session_behavior_services.hpp"
#include "native_session.hpp"
#include "session_room_transport.hpp"
#include "../gameplay_update/actor_message_queue.hpp"
#include "runtime/assets/virtual_afs.h"
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace app=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
namespace {
unsigned checks{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Behavior services check at "+std::to_string(at.line()));
}
template<class F>void refuses(F call){bool refused{};try{call();}catch(const std::runtime_error&){refused=true;}check(refused);}
struct Notices final:s::FlagNotifications{
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
void room_transport(const std::shared_ptr<const reo::assets::Source>& source,w::Profile profile,Notices& notices){
    namespace u=reo::native::gameplay_update;
    using T=app::RoomTransportStatus;
    app::NativeSession host(source,std::move(profile),notices,0);
    app::SessionRoomTransport transport(host);
    check(!host.room_membership().ready(0)&&!transport.active()&&!transport.scene_record_parameters_ready());
    check(transport.initialize()==T::completed&&host.world().session().activity.single==0);
    check(transport.scene_record_parameters_ready());
    check(transport.initialize()==T::unavailable);
    check(transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,1})&&transport.pending_scene_messages()==0);
    check(transport.send(u::SceneRecordParameterMessage{u::MessageRoute::mode_zero,255,77})&&transport.pending_scene_messages()==0);
    check(host.update().bind_message_sink(&transport)==u::Status::completed);
    check(host.update().message_sink()==&transport&&host.update().bind_message_sink(nullptr)==u::Status::actor_failure);
    auto primary=std::make_unique<w::Actor>();primary->active=true;primary->room=73;
    check(bool(host.world().spawn_primary(0,std::move(primary)).id));
    check(transport.pump().status==T::unavailable);
    host.world().selected_actor=3;
    check(transport.activate(17)==T::completed&&host.world().selected_actor==0&&
          host.world().session().message_phase==2&&host.world().session().activity.single==1);
    check(transport.activate(99)==T::completed&&transport.activation_tick()==17);
    check(transport.frame_counter()==0&&transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,1})&&transport.pending_scene_messages()==0);
    check(transport.send(u::SceneRecordParameterMessage{u::MessageRoute::mode_zero,255,77})&&transport.pending_scene_messages()==0);
    check(u::publish_actor_room_claim(host.world(),0,host.update().message_sink())==u::PublicationStatus::completed);
    check(transport.pump().status==T::unavailable&&transport.pending_requests()==1);
    host.world().session().setup_gate=2;
    check(transport.pump().status==T::completed&&transport.pending_requests()==1);
    check(transport.frame_counter()==0);
    host.world().session().setup_gate=0;
    const auto first=transport.pump();
    check(first.status==T::completed&&first.requests==1&&first.snapshots==0&&first.published==1);
    check(transport.room_owner(u::MessageRoute::mode_zero,73)==UINT32_MAX&&transport.pending_snapshots()==1);
    check(u::publish_actor_room_release(host.world(),0,host.update().message_sink())==u::PublicationStatus::completed);
    const auto second=transport.pump();
    check(second.status==T::completed&&second.requests==1&&second.snapshots==1&&second.published==1);
    check(transport.room_owner(u::MessageRoute::mode_zero,73)==0&&transport.pending_snapshots()==1);
    const auto third=transport.pump();
    check(third.status==T::completed&&third.requests==0&&third.snapshots==1&&third.published==0);
    check(transport.room_owner(u::MessageRoute::mode_zero,73)==UINT32_MAX);
    check(transport.frame_counter()==3&&host.update().state.transition_gate==0);
    auto& flags=host.update().flags();
    check(transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,255})&&transport.pending_scene_messages()==1);
    check(transport.pump().status==T::completed&&flags.get(s::FlagBank::scenario,123)==false&&flags.scenario_owner(123)==0); //self echo
    host.update().state.transition_gate=0;host.world().selected_actor=0;
    check(transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,255}));
    host.world().selected_actor=1;
    check(transport.pump().status==T::completed&&flags.get(s::FlagBank::scenario,123)==true&&flags.scenario_owner(123)==1);
    check(transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,0}));
    host.world().selected_actor=0;
    check(transport.pump().status==T::completed&&flags.get(s::FlagBank::scenario,123)==false&&flags.scenario_owner(123)==1);
    host.update().state.transition_gate=255;
    check(transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,1}));host.world().selected_actor=1;
    check(transport.pump().status==T::completed&&flags.get(s::FlagBank::scenario,123)==false);
    host.update().state.transition_gate=0;host.world().session().message_phase=0;
    check(transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,1}));host.world().selected_actor=0;
    check(transport.pump().status==T::completed&&flags.get(s::FlagBank::scenario,123)==false);
    host.world().session().message_phase=2;
    auto& parameter=host.world().session().enemy_descriptors.record(255)->parameter2e;
    parameter=19;
    check(!transport.send(u::SceneRecordParameterMessage{u::MessageRoute::mode_one,255,77}));
    check(transport.send(u::SceneRecordParameterMessage{u::MessageRoute::mode_zero,255,77}));
    check(transport.pump().status==T::completed&&parameter==19); //self-echo is filtered before case6
    check(transport.send(u::SceneRecordParameterMessage{u::MessageRoute::mode_zero,255,77}));
    host.world().selected_actor=1;
    check(transport.pump().status==T::completed&&parameter==77);
    check(transport.send(u::SceneRecordParameterMessage{u::MessageRoute::mode_zero,255,0}));
    check(transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,1}));
    check(transport.send(u::SceneRecordParameterMessage{u::MessageRoute::mode_zero,255,255}));
    host.world().selected_actor=0;
    const auto mixed=transport.pump();
    check(mixed.status==T::completed&&mixed.scene_messages==3&&parameter==255&&flags.scenario_owner(123)==2);
    host.update().state.transition_gate=1;
    check(transport.send(u::SceneRecordParameterMessage{u::MessageRoute::mode_zero,255,3}));
    host.world().selected_actor=1;
    check(transport.pump().status==T::completed&&parameter==255);
    host.update().state.transition_gate=0;host.world().session().message_phase=0;
    check(transport.send(u::SceneRecordParameterMessage{u::MessageRoute::mode_zero,255,4}));
    host.world().selected_actor=0;
    check(transport.pump().status==T::completed&&parameter==255);
    host.world().session().message_phase=2;
    for(unsigned i=0;i<16;++i)check(transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,1}));
    check(!transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,1})&&transport.pending_scene_messages()==16);
    check(transport.pump().status==T::completed&&transport.pending_scene_messages()==0);
    check(!transport.begin_room_claim({u::MessageRoute::mode_one,0,73}));
    for(unsigned i=0;i<16;++i)check(transport.begin_room_claim({u::MessageRoute::mode_zero,0,73}));
    check(!transport.begin_room_claim({u::MessageRoute::mode_zero,0,73})&&transport.pending_requests()==16);
    for(unsigned i=0;i<7;++i)check(transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,1}));
    check(transport.pending_scene_messages()==6); //last queued packet crosses512; next is source-dropped
    check(transport.pump().status==T::completed&&transport.pending_requests()==0&&transport.pending_snapshots()==1);
    check(transport.close()==T::completed&&transport.pending_snapshots()==0);
    check(!transport.scene_record_parameters_ready()&&!transport.send(u::SceneRecordParameterMessage{u::MessageRoute::mode_zero,255,77}));
    check(!transport.send(u::ScenarioOwnerMessage{u::MessageRoute::mode_zero,123,1})&&transport.pending_scene_messages()==0);
    check(!transport.begin_room_claim({u::MessageRoute::mode_zero,0,73})&&transport.pump().status==T::closed);
    check(host.update().bind_message_sink(nullptr,&transport)==u::Status::completed);
    check(host.close()==app::SessionStatus::completed);
}
}
int main(int argc,char** argv)try{
    if(argc!=2)throw std::invalid_argument("Owned scenario archive path required");
    auto source=std::make_shared<const reo::assets::Source>(argv[1]);Notices notices;
    w::Profile profile;profile.layouts.push_back({});
    room_transport(source,profile,notices);
    app::NativeSession session(source,profile,notices,1);
    check(session.install_room({41,73,0})==app::SessionStatus::completed);
    auto actor=std::make_unique<w::Actor>();actor->active=true;actor->slot=0;actor->room=73;
    const auto id=session.world().spawn_primary(0,std::move(actor)).id;check(bool(id));
    auto current=session.world().resolve(id);
    app::SessionBehaviorServices services(session);
    check(services.locally_controlled(*current,session.world().session()));
    auto other=std::make_unique<w::Actor>();other->active=true;other->slot=1;
    const auto other_id=session.world().spawn_primary(1,std::move(other)).id;check(bool(other_id));
    check(!services.locally_controlled(*session.world().resolve(other_id),session.world().session()));
    w::actors::HitActor foreign;refuses([&]{(void)services.locally_controlled(foreign,session.world().session());});
    auto& state=session.world().session();
    for(int phase:{-128,0,1,2,3,127})for(bool filter:{false,true}){
        state.message_phase=std::int8_t(phase);state.authority_filter=filter;
        check(services.authority_filter(state)==(phase==1||phase==2));
    }
    state.message_phase=0;state.authority_filter=false;
    w::actors::HealthSession foreign_session;
    refuses([&]{(void)services.authority_filter(foreign_session);});
    refuses([&]{(void)services.selected_authority(foreign_session,0);});
    refuses([&]{(void)services.selected_authority(state,0);});
    check(services.selected_authority(state,4)==0);
    state.mode=3;check(services.selected_authority(state,0)==1);
    state.mode=1;check(session.room_membership().initialize(1));
    using Members=reo::native::gameplay_session::RoomMembershipRow;
    const std::array<Members,1> membership{{{73,{1,0,0xff,0xff}}}};
    check(session.room_membership().receive(membership)==reo::native::gameplay_session::RoomMembershipStatus::completed);
    check(services.selected_authority(state,0)==0&&services.selected_authority(state,1)==1);
    namespace u=reo::native::gameplay_update;
    u::ActorMessageQueue messages(session.reception(),8);
    state.mode=0;state.activity.single=1;check(session.room_membership().initialize(0));
    check(messages.begin_room_update());
    check(u::publish_actor_room_claim(session.world(),0,&messages)==u::PublicationStatus::completed);
    check(services.selected_authority(state,0)==0&&messages.pending()==1);
    check(messages.drain(8).status==u::ActorQueueStatus::completed&&services.selected_authority(state,0)==0);
    check(messages.publish_room_membership(u::MessageRoute::mode_zero)==u::ActorQueueStatus::completed);
    check(services.selected_authority(state,0)==0&&messages.pending()==1);
    check(messages.drain(8).status==u::ActorQueueStatus::completed&&services.selected_authority(state,0)==1);
    check(messages.room_owner(u::MessageRoute::mode_zero,73)==0);
    check(messages.begin_room_update());
    check(u::publish_actor_room_release(session.world(),0,&messages)==u::PublicationStatus::completed);
    check(messages.drain(8).status==u::ActorQueueStatus::completed);
    check(messages.publish_room_membership(u::MessageRoute::mode_zero)==u::ActorQueueStatus::completed);
    check(messages.drain(8).status==u::ActorQueueStatus::completed&&services.selected_authority(state,0)==0);
    check(messages.room_owner(u::MessageRoute::mode_zero,73)==UINT32_MAX);
    check(messages.close()==u::ActorQueueStatus::completed);
    state.mode=1;state.activity.single.reset();
    current->maximum=100;current->current=50;
    services.refresh_class(*current,state);check(current->class_marker==0);
    current->current=49;services.refresh_class(*current,state);check(current->class_marker==1);
    current->current=24;services.refresh_class(*current,state);check(current->class_marker==2);
    current->status=8;services.refresh_class(*current,state);check(current->class_marker==3);
    current->status=0;current->current=current->maximum;
    refuses([&]{services.refresh_class(foreign,state);});
    current->position={3,4,5};current->orientation[1]=-8192;
    services.snapshot(*current,state);
    check(current->saved_action_position.x==3&&current->saved_action_position.y==4&&
          current->saved_action_position.z==5&&current->saved_action_yaw==-8192);
    w::actors::StatusSession foreign_status;
    refuses([&]{services.snapshot(*current,foreign_status);});
    current->primary=1;current->secondary=3;
    check(services.suppress_action_notice(session.world(),*current,1,0));
    current->secondary=0;check(!services.suppress_action_notice(session.world(),*current,1,3));
    current->secondary=0xa3;check(services.suppress_action_notice(session.world(),*current,1,0));
    current->secondary=0x24;check(!services.suppress_action_notice(session.world(),*current,1,0));
    current->primary=2;current->secondary=9;
    check(services.suppress_action_notice(session.world(),*current,2,5));
    check(!services.suppress_action_notice(session.world(),*current,1,5));
    current->secondary=2;
    refuses([&]{(void)services.suppress_action_notice(session.world(),*current,2,1);});
    current->primary=1;current->secondary=0;
    session.world().paused=1;
    services.publish(*current,state,14); //actual publication pause gate; no transport required
    session.world().paused=0;
    current->status=0x81;current->character=3;
    check(services.partner_flags(0)==0x81&&services.partner_character(0)==3);
    refuses([&]{(void)services.partner_flags(8);});
    refuses([&]{(void)services.scene_owner(0);});
    current->status=0;current->character=0;
    current->character=1;current->motion_class=0x41;
    current->source_kind=0;current->source_slot=1;current->damage_word=211;
    current->candidate_direction={0,0,1};current->position={0,0,0};
    session.world().resolve(other_id)->position={0,0,20};state.gameplay_flags=2;
    services.finish_contact_state(*current,state);
    check(current->damage_word==105&&(current->response_flags&1u));
    current->damage_word=211;state.gameplay_flags=0;
    services.finish_contact_state(*current,state);check(current->damage_word==0);
    refuses([&]{services.finish_contact_state(foreign,state);});
    current->interaction_registration=w::InteractionRegistrationState{0xffffffff,7,9};
    services.detach_scene(*current,state,1,5);
    check(current->interaction_registration->selection_word==1);
    services.detach_scene(*current,state,2,5);
    check(current->interaction_registration->selection_word==0);
    current->character=0;current->motion_class=0;state.gameplay_flags=0;
    services.cleanup(*session.world().resolve(other_id),state); //real mode0 nonselected return
    services.release_equipment(*session.world().resolve(other_id),state,0);
    session.world().session().inventory_owner=1;
    session.world().session().session_state=0;
    services.run(w::BehaviorStage::prepare_inventory,session.world(),*current);
    check(session.world().session().inventory_owner==0);
    current->transient_equipment=1;current->control_request={5,0};
    services.run(w::BehaviorStage::prepare_control,session.world(),*current);
    check(!current->transient_equipment&&current->response_lock==1);
    // Explicit state fixtures exercise the source gates before resource aging.
    // This does not stand in for production launch/scenario selection.
    current->motion_class=0x15;
    services.run(w::BehaviorStage::interaction,session.world(),*current);
    current->motion_class=0;session.world().scenario=1;
    services.run(w::BehaviorStage::interaction,session.world(),*current);
    session.world().scenario=41;
    refuses([&]{services.run(w::BehaviorStage::interaction,session.world(),*current);});
    services.run(w::BehaviorStage::terminal_timer,session.world(),*current);
    current->auxiliary_status|=0x1000u;current->primary=4;
    services.run(w::BehaviorStage::terminal_timer,session.world(),*current);
    current->primary=1;
    refuses([&]{services.run(w::BehaviorStage::terminal_timer,session.world(),*current);});
    session.world().paused=1;
    services.run(w::BehaviorStage::progression,session.world(),*current);
    session.world().paused=0;
    refuses([&]{services.run(w::BehaviorStage::progression,session.world(),*current);});
    refuses([&]{services.run(w::BehaviorStage::analog_control,session.world(),*current);});
    refuses([&]{services.dispatch(w::ActionPass::primary,1,session.world(),*current);});
    //66B8E0 commits its initialization before a required room publication.
    current->primary=0;current->secondary=12;current->response_lock=9;
    current->visible=false;current->room=73;current->auxiliary_status=0;
    session.world().mode=0;
    refuses([&]{services.dispatch(w::ActionPass::secondary,0,session.world(),*current);});
    check(current->primary==1&&current->visible&&current->response_lock==0&&
          current->secondary_pose_history&&(current->auxiliary_status&0x08000000u));
    // Mode3 skips the room-claim publication, then executes the real empty
    // secondary12 entry. It is an entry contract, not a playable-frame claim.
    current->primary=0;current->status|=0x200u;session.world().mode=3;
    services.dispatch(w::ActionPass::secondary,0,session.world(),*current);
    check(current->primary==1&&!(current->status&0x200u));
    check(session.world().retire_primary(0)==w::actors::EntityStatus::completed);
    refuses([&]{services.run(w::BehaviorStage::prepare_control,session.world(),*current);});
    refuses([&]{(void)services.locally_controlled(*current,session.world().session());});
    refuses([&]{services.refresh_class(*current,state);});
    refuses([&]{services.snapshot(*current,state);});
    check(session.close()==app::SessionStatus::completed);
    check(!session.room_membership().ready(0)&&!session.room_membership().ready(1));
    refuses([&]{services.run(w::BehaviorStage::prepare_inventory,session.world(),*current);});
    std::cout<<"Native session behavior services passed "<<checks<<" checks (ordinary action providers remain incomplete)\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
