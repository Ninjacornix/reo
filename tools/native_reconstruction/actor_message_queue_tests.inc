#include "game/native/gameplay_update/actor_message_queue.hpp"
unsigned reception_queue_cases{};
void compare_actor_message_queue(){
    using namespace actor_reception_fixture;
    struct Notifications:reo::native::gameplay_scenario::FlagNotifications {
        bool changed(const reo::native::gameplay_scenario::ScenarioFlagChange&)noexcept override{return true;}
        bool changed(const reo::native::gameplay_scenario::StridedFlagChange&)noexcept override{return true;}
    } notifications;
    g::World source({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>()),target({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());
    for(auto* w:{&source,&target})for(unsigned i=0;i<2;++i){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(i);check(bool(w->spawn_primary(i,std::move(actor)).id));}
    source.selected_actor=0;target.selected_actor=1;source.session().message_phase=target.session().message_phase=1;source.mode=target.mode=1;
    auto source_objects=objects(),target_objects=objects();u::ActorReception receiver(target,&target_objects);u::ActorMessageQueue queue(receiver,7);u::Owner owner(source,notifications,reo::native::gameplay_events::RuleBook::file1(),&queue,&source_objects);const auto id=source.identity(0);const auto a=source.primary(0),remote=target.primary(0);remote->current=10;remote->position={100,200,300};remote->orientation={1,2,3,4};remote->root_motion_delta={11,22,33};remote->pending_notice=65535;
    const auto publish=[&](u::ActorMessageSelector selector){check(owner.record_actor_message(id,selector)==u::PublicationStatus::completed);++reception_queue_cases;};
    a->status=0x80;a->current=42;publish(u::ActorMessageSelector::status);a->status=0;a->current=99;
    a->alignment_target=g::AlignmentTarget{{1,2,3},123};publish(u::ActorMessageSelector::alignment);a->alignment_target=g::AlignmentTarget{{7,8,9},456};
    a->interaction_kind=11;a->interaction_mode=12;a->interaction_slot=13;a->interaction_detail=14;publish(u::ActorMessageSelector::interaction);a->interaction_kind=99;
    a->inventory.carried={1,2,3,4};publish(u::ActorMessageSelector::carried);a->inventory.carried={5,6,7,8};
    for(unsigned i=0;i<4;++i){a->inventory.storage[i+1]=std::uint8_t(21+i);}
    publish(u::ActorMessageSelector::extra);
    for(unsigned i=0;i<4;++i){a->inventory.storage[i+1]=99;}
    a->explicit_resource_pair={31,32};a->inventory.carried={41,42,43,44};publish(u::ActorMessageSelector::resource_pair);a->inventory.carried={51,52,53,54};
    a->grid=1;check(source_objects.apply_source_coordinates(1,{-127,126}));publish(u::ActorMessageSelector::room_object);check(source_objects.apply_source_coordinates(1,{-1,-1}));a->grid=2;
    check(queue.pending()==7&&queue.capacity()==7&&remote->current==10&&owner.record_actor_status(id)==u::PublicationStatus::message_unavailable);++reception_queue_cases;
    auto drained=queue.drain(0);check(drained.status==u::ActorQueueStatus::completed&&!drained.consumed&&drained.pending==7&&remote->current==10);++reception_queue_cases;
    drained=queue.drain(2);check(drained.status==u::ActorQueueStatus::completed&&drained.consumed==2&&drained.pending==5&&remote->current==42&&remote->status==0x80&&remote->alignment_target&&remote->alignment_target->yaw==123&&remote->alignment_target->position.x==1&&!remote->pending_notice&&remote->root_motion_delta.x==0&&remote->previous_position.x==100&&remote->previous_orientation==remote->orientation);++reception_queue_cases;
    drained=queue.drain(2);check(drained.status==u::ActorQueueStatus::completed&&drained.consumed==2&&drained.pending==3&&remote->interaction_kind==11&&remote->interaction_mode==12&&remote->interaction_slot==13&&remote->interaction_detail==14&&remote->inventory.carried==std::array<std::uint8_t,4>{1,2,3,4});++reception_queue_cases;
    drained=queue.drain(10);check(drained.status==u::ActorQueueStatus::completed&&drained.consumed==3&&!drained.pending&&remote->inventory.carried==std::array<std::uint8_t,4>{41,42,43,44}&&remote->explicit_resource_pair==std::array<std::uint8_t,2>{31,32}&&remote->grid==1&&target_objects.source_coordinates(1)==std::optional(std::array<std::int8_t,2>{-127,126}));
    for(unsigned i=0;i<4;++i){check(remote->inventory.storage[i+1]==std::uint8_t(21+i));}++reception_queue_cases;
    for(unsigned n=0;n<64;++n){a->current=std::int16_t(n);publish(u::ActorMessageSelector::status);drained=queue.drain(1);check(drained.status==u::ActorQueueStatus::completed&&drained.consumed==1&&!drained.pending&&remote->current==std::int16_t(n));++reception_queue_cases;}
    check(!queue.send(u::ScenarioOwnerMessage{})&&!queue.send(u::ResourceOperationMessage{})&&!queue.send(u::ResourcePositionMessage{})&&!queue.send(u::ActorSnapshotMessage{})&&!queue.send(u::ActorStateMessage{})&&!queue.send(u::ActorActionMessage{}));++reception_queue_cases;
    a->category=1;a->status=0x10000000u;check(owner.record_actor_status(id)==u::PublicationStatus::unavailable&&!queue.pending());a->category=0;a->status=0;++reception_queue_cases;
    remote->root_motion_delta={7,8,9};check(queue.send(u::ActorRoomObjectMessage{u::MessageRoute::mode_one,1,255,{1,2}})&&queue.send(u::ActorStatusMessage{u::MessageRoute::mode_one,1,8,77}));drained=queue.drain(7);check(drained.status==u::ActorQueueStatus::unavailable&&drained.consumed==1&&drained.pending==1&&remote->grid==255&&remote->root_motion_delta.x==7);++reception_queue_cases;
    drained=queue.drain(7);check(drained.status==u::ActorQueueStatus::completed&&drained.consumed==1&&!drained.pending&&remote->current==77&&remote->grid==255&&remote->root_motion_delta.x==0);++reception_queue_cases;
    bool refused=false;try{u::ActorMessageQueue invalid(receiver,0);}catch(const std::invalid_argument&){refused=true;}check(refused);++reception_queue_cases;
    check(queue.send(u::ActorStatusMessage{u::MessageRoute::mode_one,1,8,88}));check(target.close()==g::Status::completed);drained=queue.drain(1);check(drained.status==u::ActorQueueStatus::unavailable&&drained.consumed==1&&!drained.pending);++reception_queue_cases;
    check(queue.close()==u::ActorQueueStatus::completed&&queue.close()==u::ActorQueueStatus::completed&&!queue.send(u::ActorStatusMessage{})&&queue.drain(1).status==u::ActorQueueStatus::closed);++reception_queue_cases;
}
