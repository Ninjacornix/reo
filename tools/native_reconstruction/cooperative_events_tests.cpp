#include "game/native/gameplay_events/events.hpp"
#include "reference.hpp"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>
namespace e=reo::native::gameplay_events;
unsigned checks{},calls{},appends{},retirements{},prunings{},resets{},refusals{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Cooperative event check "+std::to_string(checks)+" line "+std::to_string(at.line()));}
template<class T>T get(const std::uint8_t* m,unsigned at){return transform_read<T>(m,at);}
template<class T>void put(std::uint8_t* m,unsigned at,T v){transform_write(m,at,v);}
#ifdef REO_SCENARIO_PUBLICATION
void publication_message_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_STATUS_MESSAGE
void actor_status_message_port(std::uint8_t*,R5900Context*);
void actor_room_owner_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_ACTION_MESSAGE
bool actor_action_capture{};
void actor_action_message_port(std::uint8_t*,R5900Context*);
void actor_action_room_owner_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_INVENTORY_MESSAGE
bool actor_inventory_capture{};
void actor_inventory_message_port(std::uint8_t*,R5900Context*);
void actor_inventory_room_owner_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_STATE_MESSAGE
bool actor_state_capture{};
void actor_state_message_port(std::uint8_t*,R5900Context*);
void actor_state_room_owner_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_REQUEST_MESSAGE
bool actor_request_capture{};
void actor_request_message_port(std::uint8_t*,R5900Context*);
void actor_request_room_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_SPEECH_MESSAGE
bool actor_speech_capture{};
void actor_speech_message_port(std::uint8_t*,R5900Context*);
void actor_speech_room_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_PEER_MESSAGE
bool actor_peer_capture{};
void actor_peer_message_port(std::uint8_t*,R5900Context*);
void actor_peer_room_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_ROOM_OBJECT_MESSAGE
bool actor_room_object_capture{};
void actor_room_object_message_port(std::uint8_t*,R5900Context*);
void actor_room_object_room_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_CONTACT_SNAPSHOT
bool actor_contact_snapshot_capture{};
void actor_contact_snapshot_message_port(std::uint8_t*,R5900Context*);
void actor_contact_snapshot_room_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_ALIGNMENT_MESSAGE
bool actor_alignment_capture{};
void actor_alignment_message_port(std::uint8_t*,R5900Context*);
void actor_alignment_room_owner_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_SNAPSHOT_MESSAGE
bool actor_snapshot_capture{};
void actor_snapshot_message_port(std::uint8_t*,R5900Context*);
void actor_snapshot_room_owner_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_HIT_GAUGE
bool hit_gauge_capture{};
bool hit_gauge_port(std::uint8_t*,R5900Context*);
#endif
#ifdef REO_ACTOR_ROOM_CONTROL
bool room_control_capture{};
void actor_room_control_port(std::uint8_t*,R5900Context*);
#endif
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;const auto done=[&](){context->pc=GPR_U32(context,31);};
#ifdef REO_ACTOR_HIT_GAUGE
if(hit_gauge_capture&&hit_gauge_port(memory,context)){done();return;}
#endif
switch(context->pc){
#ifdef REO_ACTOR_ROOM_CONTROL
case 0x810960:case 0x8129c0:if(room_control_capture){actor_room_control_port(memory,context);done();return;}throw std::runtime_error("Unadmitted room-control send");
#endif
#ifdef REO_COMPLETION_STATISTICS
case 0x1b0300:SET_GPR_U32(context,2,memory[0x3243f2]);done();return;
#endif
#ifdef REO_SCENARIO_PUBLICATION
case 0x811190:case 0x810870:
#ifdef REO_ACTOR_REQUEST_MESSAGE
if(actor_request_capture){actor_request_message_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_SPEECH_MESSAGE
if(actor_speech_capture){actor_speech_message_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_PEER_MESSAGE
if(actor_peer_capture){actor_peer_message_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_ROOM_OBJECT_MESSAGE
if(actor_room_object_capture){actor_room_object_message_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_CONTACT_SNAPSHOT
if(actor_contact_snapshot_capture){actor_contact_snapshot_message_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_ALIGNMENT_MESSAGE
if(actor_alignment_capture){actor_alignment_message_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_SNAPSHOT_MESSAGE
if(actor_snapshot_capture){actor_snapshot_message_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_STATE_MESSAGE
if(actor_state_capture){actor_state_message_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_INVENTORY_MESSAGE
if(actor_inventory_capture){actor_inventory_message_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_ACTION_MESSAGE
if(memory[GPR_U32(context,5)]==7){actor_action_message_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_STATUS_MESSAGE
if(memory[GPR_U32(context,5)]==14){actor_status_message_port(memory,context);done();return;}
#endif
publication_message_port(memory,context);done();return;
#endif
#ifdef REO_ACTOR_STATUS_MESSAGE
case 0x811d40:case 0x8115f0:
#ifdef REO_ACTOR_REQUEST_MESSAGE
if(actor_request_capture){actor_request_room_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_SPEECH_MESSAGE
if(actor_speech_capture){actor_speech_room_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_PEER_MESSAGE
if(actor_peer_capture){actor_peer_room_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_ROOM_OBJECT_MESSAGE
if(actor_room_object_capture){actor_room_object_room_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_CONTACT_SNAPSHOT
if(actor_contact_snapshot_capture){actor_contact_snapshot_room_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_ALIGNMENT_MESSAGE
if(actor_alignment_capture){actor_alignment_room_owner_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_SNAPSHOT_MESSAGE
if(actor_snapshot_capture){actor_snapshot_room_owner_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_STATE_MESSAGE
if(actor_state_capture){actor_state_room_owner_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_INVENTORY_MESSAGE
if(actor_inventory_capture){actor_inventory_room_owner_port(memory,context);done();return;}
#endif
#ifdef REO_ACTOR_ACTION_MESSAGE
if(actor_action_capture){actor_action_room_owner_port(memory,context);done();return;}
#endif
actor_room_owner_port(memory,context);done();return;
#endif
#ifdef REO_ACTOR_INVENTORY_MESSAGE
case 0x18dbb0:{const auto dst=GPR_U32(context,4),src=GPR_U32(context,5),size=GPR_U32(context,6);check(size==4&&dst>=0x1e00000&&dst<=0x2000000-4&&(src==0x4a5c30+0xc84||src==0x4a5c30+0xc89));std::memcpy(memory+dst,memory+src,4);SET_GPR_U32(context,2,dst);done();return;}
#endif
case 0x107c68:{const auto at=GPR_U32(context,4),n=GPR_U32(context,6);check(at<=0x2000000&&n<=0x2000000-at&&GPR_U32(context,5)==0);std::memset(memory+at,0,n);SET_GPR_U32(context,2,at);done();return;}
#include "dispatch.inc"
default:throw std::runtime_error("Unadmitted cooperative event source helper "+std::to_string(context->pc));}}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
unsigned call(std::uint8_t* memory,unsigned pc,std::array<unsigned,3> args={}){R5900Context context;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);for(unsigned i=0;i<3;++i){SET_GPR_U32(&context,4+i,args[i]);}PS2Runtime runtime;original_transform_port(memory,&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);}
constexpr unsigned base=0x56bc10;
void compare(const e::Events& owner,const std::uint8_t* memory){check(owner.available()==get<std::uint16_t>(memory,0x56c810)&&owner.threshold()==std::bit_cast<std::int8_t>(memory[0x56bb88]));const auto live=owner.snapshot();unsigned raw=get<unsigned>(memory,0x56c820),previous{};for(const auto& record:live){check(raw&&owner.physical_slot(record.id)&&raw==base+24**owner.physical_slot(record.id));const auto& v=record.value;check(v.timestamp==get<unsigned>(memory,raw+8)&&v.id==get<std::uint16_t>(memory,raw+0xc)&&v.type==memory[raw+0xe]&&v.priority==memory[raw+0xf]&&v.room==get<std::uint16_t>(memory,raw+0x10)&&v.first==get<std::uint16_t>(memory,raw+0x12)&&v.second==get<std::uint16_t>(memory,raw+0x14));check(previous==get<unsigned>(memory,raw+4)&&get<std::uint16_t>(memory,raw+0x16)==0);check(owner.get(record.id)==v);previous=raw;raw=get<unsigned>(memory,raw);}check(!raw&&previous==get<unsigned>(memory,0x56c818)&&live.size()==128-owner.available());}
#ifdef REO_COMPLETION_STATISTICS
#include "tools/native_reconstruction/completion_statistics_tests.inc"
#endif
#ifdef REO_AUTOMATIC_COMPLETION
#include "tools/native_reconstruction/automatic_completion_tests.inc"
#endif
#ifdef REO_SCENARIO_PUBLICATION
#include "tools/native_reconstruction/scenario_publication_tests.inc"
#endif
#ifdef REO_ACTOR_STATUS_MESSAGE
#include "tools/native_reconstruction/actor_status_message_tests.inc"
#endif
#ifdef REO_ACTOR_ACTION_MESSAGE
#include "tools/native_reconstruction/actor_action_message_tests.inc"
#endif
#ifdef REO_ACTOR_INVENTORY_MESSAGE
#include "tools/native_reconstruction/actor_inventory_message_tests.inc"
#endif
#ifdef REO_ACTOR_STATE_MESSAGE
#include "tools/native_reconstruction/actor_state_message_tests.inc"
#endif
#ifdef REO_ACTOR_ACTIVITY_BINDING
#include "tools/native_reconstruction/actor_activity_binding_tests.inc"
#endif
#ifdef REO_ACTOR_GAUGE_EFFECTS
#include "tools/native_reconstruction/actor_gauge_effects_tests.inc"
#endif
#ifdef REO_ACTOR_HIT_GAUGE
#include "tools/native_reconstruction/actor_hit_gauge_tests.inc"
#endif
#ifdef REO_ACTOR_SNAPSHOT_MESSAGE
#include "tools/native_reconstruction/actor_snapshot_message_tests.inc"
#endif
#ifdef REO_ACTOR_ALIGNMENT_MESSAGE
#include "tools/native_reconstruction/actor_alignment_message_tests.inc"
#endif
#ifdef REO_ACTOR_CONTACT_ALIGNMENT
#include "tools/native_reconstruction/actor_contact_alignment_tests.inc"
#endif
#ifdef REO_ACTOR_CONTACT_SNAPSHOT
#include "tools/native_reconstruction/actor_contact_snapshot_tests.inc"
#endif
#ifdef REO_ACTOR_ROOM_OBJECT_MESSAGE
#include "tools/native_reconstruction/actor_room_object_message_tests.inc"
#endif
#ifdef REO_AUXILIARY_ACTOR_POOL
#include "tools/native_reconstruction/auxiliary_actor_pool_tests.inc"
#endif
#ifdef REO_ACTOR_PEER_MESSAGE
#include "tools/native_reconstruction/actor_peer_message_tests.inc"
#endif
#ifdef REO_ACTOR_SPEECH_MESSAGE
#include "tools/native_reconstruction/actor_speech_message_tests.inc"
#endif
#ifdef REO_ACTOR_REQUEST_MESSAGE
#include "tools/native_reconstruction/actor_interaction_request_tests.inc"
#endif
#ifdef REO_INTERACTION_TRANSITIONS
#include "tools/native_reconstruction/actor_interaction_transition_tests.inc"
#endif
#ifdef REO_ACTOR_ROOM_CONTROL
#include "tools/native_reconstruction/actor_room_control_tests.inc"
#endif
int main(int argc,char** argv)try{
    check(argc==
#ifdef REO_INTERACTION_TRANSITIONS
    1+
#endif
#ifdef REO_COMPLETION_STATISTICS
    3
#ifdef REO_AUTOMATIC_COMPLETION
    +1
#endif
#ifdef REO_ACTOR_STATUS_MESSAGE
    +1
#endif
#ifdef REO_ACTOR_CONTACT_ALIGNMENT
    +1
#endif
#else
    2
#endif
    );std::ifstream input(argv[1],std::ios::binary);std::array<std::uint8_t,39> priorities;input.read(reinterpret_cast<char*>(priorities.data()),priorities.size());check(bool(input));std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();std::memcpy(memory+0x389d30,priorities.data(),priorities.size());e::Events owner;
    const auto reset=[&](){call(memory,0x37c170);check(owner.reset()==e::Status::completed);compare(owner,memory);++resets;};
    const auto append=[&](bool simple,unsigned id,unsigned first,unsigned second,unsigned time,std::uint16_t room){put(memory,0x4bade8,time);put(memory,0x3243dc,room);const auto available=owner.available();call(memory,simple?0x37bfb0:0x37c060,{id,first,second});const auto result=simple?owner.simple(id,time):owner.typed(id,first,second,time,room);compare(owner,memory);check(bool(result.id)==(result.status==e::Status::completed));if(result.id)check(owner.get(result.id).has_value());else check(owner.available()>=available||result.status==e::Status::full);++appends;return result;};
    reset();
    for(unsigned n=0;n<65536;++n){if(n%257==0)reset();append(n%13==0,n%13?0xabcd0000u|(n%39):0xabcd0000u|n,n*1664525u,n*1013904223u,n*65521u,std::uint16_t(n*17));if(n%41==0){check(owner.prune()==bool(call(memory,0x37c3b0)));compare(owner,memory);++prunings;}}
    for(unsigned id=0;id<39;++id){reset();for(unsigned n=0;n<128;++n)append(false,id,n,n+1,0xa4c478u+n,std::uint16_t(n));for(unsigned n=0;n<10;++n){check(owner.prune()==bool(call(memory,0x37c3b0)));compare(owner,memory);++prunings;}append(false,id,1,2,UINT32_MAX,65535);}
    reset();for(unsigned n=0;n<129;++n)append(true,n,0,0,n,0);check(owner.available()==0&&owner.threshold()==9);
    for(unsigned n=0;n<512;++n){if(owner.available()<8)reset();std::vector<e::EventId> ids;for(unsigned i=0;i<7;++i)ids.push_back(append(false,(n+i)%39,n,i,n*1234567u,std::uint16_t(n)).id);
        for(unsigned i:{0u,6u,3u,1u,5u,2u,4u}){const auto raw=base+24**owner.physical_slot(ids[i]);check(call(memory,0x37c2c0,{raw})==1&&owner.retire(ids[i]));check(!owner.retire(ids[i])&&!owner.get(ids[i]));compare(owner,memory);++retirements;}
    }
    reset();const auto old=append(false,0,1,2,3,4).id;const auto snapshot=owner.snapshot();reset();const auto replacement=append(false,0,5,6,7,8).id;check(old!=replacement&&!owner.retire(old)&&!owner.get(old)&&snapshot.size()==1&&snapshot[0].value.first==1);++refusals;
    e::Events foreign;check(!foreign.get(replacement)&&!foreign.retire(replacement));++refusals;
    for(unsigned id=39;id<65536;++id){check(owner.typed(0xabcd0000u|id,0,0,0,0).status==e::Status::unavailable);}++refusals;
    e::Events limited(1);const auto first=limited.simple(1,0);check(first.status==e::Status::completed&&limited.simple(2,0).status==e::Status::serial_exhausted&&limited.available()==127);check(limited.retire(first.id)&&limited.reset()==e::Status::completed&&limited.simple(3,0).status==e::Status::serial_exhausted);++refusals;
    owner.close();check(owner.simple(1,0).status==e::Status::closed&&owner.typed(1,0,0,0,0).status==e::Status::closed&&owner.reset()==e::Status::closed&&!owner.get(replacement)&&!owner.retire(replacement)&&!owner.prune()&&owner.snapshot().empty());++refusals;
#ifdef REO_COMPLETION_STATISTICS
    compare_completion_statistics(memory,argv[2]);
#endif
#ifdef REO_AUTOMATIC_COMPLETION
    compare_automatic_completion(memory,argv[2],argv[3]);
#endif
#ifdef REO_SCENARIO_PUBLICATION
    compare_scenario_publication(memory);
#endif
#ifdef REO_ACTOR_STATUS_MESSAGE
    compare_actor_status_messages(memory,argv[4]);
#endif
#ifdef REO_ACTOR_ACTION_MESSAGE
    compare_actor_action_messages(memory);
#endif
#ifdef REO_ACTOR_INVENTORY_MESSAGE
    compare_actor_inventory_messages(memory);
#endif
#ifdef REO_ACTOR_STATE_MESSAGE
    compare_actor_state_messages(memory,argv[4]);
#endif
#ifdef REO_ACTOR_ACTIVITY_BINDING
    compare_actor_activity_binding();
#endif
#ifdef REO_ACTOR_GAUGE_EFFECTS
    compare_actor_gauge_effects(memory,argv[4]);
#endif
#ifdef REO_ACTOR_HIT_GAUGE
    compare_actor_hit_gauge(memory);
#endif
#ifdef REO_ACTOR_SNAPSHOT_MESSAGE
    compare_actor_snapshot_messages(memory);
#endif
#ifdef REO_ACTOR_ALIGNMENT_MESSAGE
    compare_actor_alignment_messages(memory);
#endif
#ifdef REO_ACTOR_CONTACT_ALIGNMENT
    compare_actor_contact_alignment(memory,argv[5]);
#endif
#ifdef REO_ACTOR_CONTACT_SNAPSHOT
    compare_actor_contact_snapshot(memory);
#endif
#ifdef REO_ACTOR_ROOM_OBJECT_MESSAGE
    compare_actor_room_object_messages(memory);
#endif
#ifdef REO_AUXILIARY_ACTOR_POOL
    compare_auxiliary_actor_pool(memory);
#endif
#ifdef REO_ACTOR_PEER_MESSAGE
    compare_actor_peer_messages(memory);
#endif
#ifdef REO_ACTOR_SPEECH_MESSAGE
    compare_actor_speech_messages(memory);
#endif
#ifdef REO_ACTOR_REQUEST_MESSAGE
    compare_actor_interaction_requests(memory);
#endif
#ifdef REO_INTERACTION_TRANSITIONS
    compare_actor_interaction_transitions(memory,argv[argc-1]);
#endif
#ifdef REO_ACTOR_ROOM_CONTROL
    compare_actor_room_control(memory);
#endif
    std::cout<<"{\"checks\":"<<checks<<",\"appends\":"<<appends<<",\"retirements\":"<<retirements<<",\"prunings\":"<<prunings<<",\"resets\":"<<resets<<",\"refusals\":"<<refusals<<",\"original_calls\":"<<calls
#ifdef REO_COMPLETION_STATISTICS
    <<",\"completion_cases\":"<<completion_cases<<",\"completion_initializations\":"<<completion_initializations<<",\"completion_refusals\":"<<completion_refusals
#endif
#ifdef REO_AUTOMATIC_COMPLETION
    <<",\"condition_cases\":"<<condition_cases<<",\"automatic_cases\":"<<automatic_cases<<",\"automatic_refusals\":"<<automatic_refusals
#endif
#ifdef REO_SCENARIO_PUBLICATION
    <<",\"publication_cases\":"<<publication_cases<<",\"publication_messages\":"<<publication_messages<<",\"publication_refusals\":"<<publication_refusals
#endif
#ifdef REO_ACTOR_STATUS_MESSAGE
    <<",\"actor_status_cases\":"<<actor_status_cases<<",\"actor_status_messages\":"<<actor_status_messages<<",\"actor_status_lookups\":"<<actor_status_lookups<<",\"actor_status_refusals\":"<<actor_status_refusals
#endif
#ifdef REO_ACTOR_ACTION_MESSAGE
    <<",\"actor_action_cases\":"<<actor_action_cases<<",\"actor_action_messages\":"<<actor_action_messages<<",\"actor_action_lookups\":"<<actor_action_lookups<<",\"actor_action_requests\":"<<actor_action_requests<<",\"actor_action_refusals\":"<<actor_action_refusals<<",\"actor_action_world_publications\":"<<actor_action_world_publications
#endif
#ifdef REO_ACTOR_INVENTORY_MESSAGE
    <<",\"actor_inventory_cases\":"<<actor_inventory_cases<<",\"actor_inventory_messages\":"<<actor_inventory_messages<<",\"actor_inventory_lookups\":"<<actor_inventory_lookups<<",\"actor_inventory_refusals\":"<<actor_inventory_refusals
#endif
#ifdef REO_ACTOR_STATE_MESSAGE
    <<",\"actor_state_cases\":"<<actor_state_cases<<",\"actor_state_messages\":"<<actor_state_messages<<",\"actor_state_lookups\":"<<actor_state_lookups<<",\"actor_state_refusals\":"<<actor_state_refusals<<",\"actor_gauge_cases\":"<<actor_gauge_cases<<",\"actor_state_class_cases\":"<<actor_state_class_cases<<",\"actor_periodic_cases\":"<<actor_periodic_cases<<",\"actor_clock_cases\":"<<actor_clock_cases
#endif
#ifdef REO_ACTOR_ACTIVITY_BINDING
    <<",\"actor_activity_cases\":"<<actor_activity_cases<<",\"actor_activity_deliveries\":"<<actor_activity_deliveries<<",\"actor_activity_failures\":"<<actor_activity_failures
#endif
#ifdef REO_ACTOR_GAUGE_EFFECTS
    <<",\"gauge_adjustment_cases\":"<<gauge_adjustment_cases<<",\"gauge_crossing_cases\":"<<gauge_crossing_cases<<",\"gauge_effect_events\":"<<gauge_effect_events<<",\"gauge_effect_refusals\":"<<gauge_effect_refusals<<",\"gauge_capacity_cases\":"<<gauge_capacity_cases
#endif
#ifdef REO_ACTOR_HIT_GAUGE
    <<",\"hit_gauge_cases\":"<<hit_gauge_cases<<",\"hit_gauge_events\":"<<hit_gauge_events<<",\"hit_gauge_failures\":"<<hit_gauge_failures
#endif
#ifdef REO_ACTOR_SNAPSHOT_MESSAGE
    <<",\"actor_snapshot_cases\":"<<actor_snapshot_cases<<",\"actor_snapshot_messages\":"<<actor_snapshot_messages<<",\"actor_snapshot_lookups\":"<<actor_snapshot_lookups<<",\"actor_snapshot_refusals\":"<<actor_snapshot_refusals<<",\"actor_snapshot_frames\":"<<actor_snapshot_frames
#endif
#ifdef REO_ACTOR_ALIGNMENT_MESSAGE
    <<",\"actor_alignment_cases\":"<<actor_alignment_cases<<",\"actor_alignment_messages\":"<<actor_alignment_messages<<",\"actor_alignment_lookups\":"<<actor_alignment_lookups<<",\"actor_alignment_refusals\":"<<actor_alignment_refusals
#endif
#ifdef REO_ACTOR_CONTACT_ALIGNMENT
    <<",\"contact_alignment_cases\":"<<contact_alignment_cases<<",\"heading_cases\":"<<heading_cases<<",\"contact_alignment_rejections\":"<<contact_alignment_rejections<<",\"contact_alignment_refusals\":"<<contact_alignment_refusals<<",\"contact_alignment_owner_cases\":"<<contact_alignment_owner_cases
#endif
#ifdef REO_ACTOR_CONTACT_SNAPSHOT
    <<",\"contact_snapshot_cases\":"<<contact_snapshot_cases<<",\"contact_snapshot_messages\":"<<contact_snapshot_messages<<",\"contact_snapshot_lookups\":"<<contact_snapshot_lookups<<",\"contact_snapshot_refusals\":"<<contact_snapshot_refusals<<",\"contact_snapshot_recursions\":"<<contact_snapshot_recursions
#endif
#ifdef REO_ACTOR_ROOM_OBJECT_MESSAGE
    <<",\"room_object_message_cases\":"<<room_object_message_cases<<",\"room_object_messages\":"<<room_object_messages<<",\"room_object_message_lookups\":"<<room_object_message_lookups<<",\"room_object_message_refusals\":"<<room_object_message_refusals
#endif
#ifdef REO_AUXILIARY_ACTOR_POOL
    <<",\"auxiliary_pool_cases\":"<<auxiliary_pool_cases<<",\"auxiliary_pool_lookups\":"<<auxiliary_pool_lookups<<",\"auxiliary_pool_reuses\":"<<auxiliary_pool_reuses<<",\"auxiliary_pool_refusals\":"<<auxiliary_pool_refusals<<",\"auxiliary_pool_lifetimes\":"<<auxiliary_pool_lifetimes
#endif
#ifdef REO_ACTOR_PEER_MESSAGE
    <<",\"actor_peer_cases\":"<<actor_peer_cases<<",\"actor_peer_messages\":"<<actor_peer_messages<<",\"actor_peer_lookups\":"<<actor_peer_lookups<<",\"actor_peer_mirrors\":"<<actor_peer_mirrors<<",\"actor_peer_refusals\":"<<actor_peer_refusals<<",\"actor_peer_hit_aliases\":"<<actor_peer_hit_aliases
#endif
#ifdef REO_ACTOR_SPEECH_MESSAGE
    <<",\"actor_speech_cases\":"<<actor_speech_cases<<",\"actor_speech_messages\":"<<actor_speech_messages<<",\"actor_speech_lookups\":"<<actor_speech_lookups<<",\"actor_speech_refusals\":"<<actor_speech_refusals
#endif
#ifdef REO_ACTOR_REQUEST_MESSAGE
    <<",\"actor_request_cases\":"<<actor_request_cases<<",\"actor_request_messages\":"<<actor_request_messages<<",\"actor_request_lookups\":"<<actor_request_lookups<<",\"actor_request_refusals\":"<<actor_request_refusals<<",\"actor_request_hit_aliases\":"<<actor_request_hit_aliases
#endif
#ifdef REO_INTERACTION_TRANSITIONS
    <<",\"interaction_transition_cases\":"<<interaction_transition_cases<<",\"interaction_transition_refusals\":"<<interaction_transition_refusals<<",\"interaction_transition_owner_cases\":"<<interaction_transition_owner_cases
#endif
#ifdef REO_ACTOR_ROOM_CONTROL
    <<",\"room_release_cases\":"<<room_release_cases<<",\"room_release_messages\":"<<room_release_messages<<",\"room_hold_cases\":"<<room_hold_cases<<",\"room_transition_cases\":"<<room_transition_cases<<",\"room_control_refusals\":"<<room_control_refusals<<",\"room_control_hit_aliases\":"<<room_control_hit_aliases<<",\"room_response_aliases\":"<<room_response_aliases
#endif
    <<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
