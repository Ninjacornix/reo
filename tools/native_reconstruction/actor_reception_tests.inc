#include "game/native/gameplay_update/reception.hpp"
#include <variant>
#include "game/native/gameplay_world/auxiliary_actors.hpp"
unsigned reception_cases{},reception_equipment{},reception_refusals{},reception_auxiliary_cases{};
namespace actor_reception_fixture {
namespace u=reo::native::gameplay_update;namespace g=reo::native::gameplay_world;namespace ro=reo::native::gameplay_collision::room_objects;
constexpr unsigned base=0x4a5c30,packet=0x70000;
using Message=std::variant<u::ActorStatusMessage,u::ActorAlignmentMessage,u::ActorInteractionMessage,u::ActorInventoryMessage,u::ActorResourcePairMessage,u::ActorRoomObjectMessage,u::ActorPeerMessage,u::ActorInteractionRequestMessage>;
ro::Owner objects(){std::array<std::byte,16> types{};std::array<std::byte,8> placements{};placements[0]=std::byte{2};return ro::Owner::import(types,placements);}
unsigned encode(std::uint8_t* memory,const Message& message){
    std::fill_n(memory+packet,64,0);return std::visit([&](const auto& value){using T=std::decay_t<decltype(value)>;unsigned type{};
        if constexpr(std::is_same_v<T,u::ActorStatusMessage>){type=14;put(memory,packet+4,value.status);put(memory,packet+8,value.health);}
        else if constexpr(std::is_same_v<T,u::ActorAlignmentMessage>){type=6;put(memory,packet+4,value.target.position);put(memory,packet+16,value.target.yaw);}
        else if constexpr(std::is_same_v<T,u::ActorInteractionMessage>){type=4;std::memcpy(memory+packet+4,value.values.data(),4);}
        else if constexpr(std::is_same_v<T,u::ActorInventoryMessage>){type=unsigned(value.kind);std::memcpy(memory+packet+4,value.resources.data(),4);}
        else if constexpr(std::is_same_v<T,u::ActorResourcePairMessage>){type=10;std::memcpy(memory+packet+4,value.pair.data(),2);std::memcpy(memory+packet+6,value.carried.data(),4);}
        else if constexpr(std::is_same_v<T,u::ActorPeerMessage>){type=8;put(memory,packet+4,value.state);put(memory,packet+6,std::uint16_t((value.peer.kind==g::actors::ActorReference::Kind::auxiliary?0x8000u:0u)|value.peer.identifier));put(memory,packet+8,value.parameters);}
        else if constexpr(std::is_same_v<T,u::ActorInteractionRequestMessage>){type=3;memory[packet+4]=value.pending;memory[packet+5]=value.request.kind;memory[packet+6]=value.request.parameter;memory[packet+7]=value.scene_model;put(memory,packet+8,value.request.anchor);put(memory,packet+20,value.request.orientation);put(memory,packet+24,value.request.travel_distance);memory[packet+28]=value.request.endpoint;}
        else{type=9;memory[packet+4]=value.grid;memory[packet+5]=std::uint8_t(value.coordinates[0]);memory[packet+6]=std::uint8_t(value.coordinates[1]);}
        memory[packet]=std::uint8_t(type);return type;
    },message);
}
Message message(unsigned kind,unsigned n,unsigned channel){
    const std::array<std::uint8_t,4> bytes{std::uint8_t(n),std::uint8_t(n>>8),std::uint8_t(n*17),std::uint8_t(n*31)};
    switch(kind){
    case 0:return u::ActorStatusMessage{u::MessageRoute::mode_one,channel,n*1664525u,std::bit_cast<std::int16_t>(std::uint16_t(n))};
    case 1:return u::ActorAlignmentMessage{u::MessageRoute::mode_one,channel,{{std::bit_cast<float>(n*1664525u),std::bit_cast<float>(n*1013904223u),std::bit_cast<float>(n*65521u)},std::bit_cast<std::int16_t>(std::uint16_t(n))}};
    case 2:return u::ActorInteractionMessage{u::MessageRoute::mode_one,channel,bytes};
    case 3:case 4:return u::ActorInventoryMessage{u::MessageRoute::mode_one,channel,kind==3?u::ActorInventoryMessage::Kind::carried:u::ActorInventoryMessage::Kind::extra,bytes};
    case 5:return u::ActorResourcePairMessage{u::MessageRoute::mode_one,channel,{bytes[0],bytes[1]},bytes};
    case 8:return u::ActorInteractionRequestMessage{u::MessageRoute::mode_one,channel,std::uint8_t(n),std::uint8_t(n>>8),{std::uint8_t(n*17),std::uint8_t(n*31),{std::bit_cast<float>(n*1664525u),std::bit_cast<float>(n*1013904223u),std::bit_cast<float>(n*65521u)},n*1664525u,std::bit_cast<float>(n*22695477u),std::uint8_t(n*13)}};
    case 7:return u::ActorPeerMessage{u::MessageRoute::mode_one,channel,std::uint16_t(n*65521u),{g::actors::ActorReference::Kind::primary,std::uint16_t((n>>4)%8)},{std::bit_cast<std::int16_t>(std::uint16_t(n)),std::bit_cast<std::int16_t>(std::uint16_t(n*17))}};
    default:return u::ActorRoomObjectMessage{u::MessageRoute::mode_one,channel,std::uint8_t(n%32),{std::bit_cast<std::int8_t>(bytes[0]),std::bit_cast<std::int8_t>(bytes[1])}};
    }
}
void seed_actor(std::uint8_t* memory,unsigned at,g::Actor& actor,unsigned n){
    actor.status=n*1013904223u;actor.current=123;actor.pending_notice=std::uint16_t(n);actor.selected_resource=0;actor.position={std::bit_cast<float>(n*65521u),std::bit_cast<float>(n*1664525u),std::bit_cast<float>(n*1013904223u)};actor.previous_position={-11,-22,-33};actor.root_motion_delta={11,22,33};
    for(unsigned i=0;i<4;++i){actor.orientation[i]=std::bit_cast<std::int16_t>(std::uint16_t(n*65521+i));actor.previous_orientation[i]=-123;actor.inventory.carried[i]=std::uint8_t(n+i);actor.inventory.storage[i+1]=std::uint8_t(n+17+i);}
    actor.transient_contact=7;actor.peer_request=g::PeerRequest{6,{g::actors::ActorReference::Kind::primary,3},{4,5}};put(memory,at+0xc64,std::uint16_t(0x0607));put(memory,at+0xc66,std::uint16_t(3));put(memory,at+0xc68,std::int16_t(4));put(memory,at+0xc6a,std::int16_t(5));
    actor.transient_action=21;actor.scene_model=22;actor.interaction_request=g::InteractionRequest{23,24,{25,26,27},28,29,30};actor.related_target_state=-31;
    memory[at+0xab8]=21;memory[at+0xab9]=23;memory[at+0xaba]=24;memory[at+0xabb]=22;put(memory,at+0xabc,actor.interaction_request->anchor);put(memory,at+0xac8,28u);put(memory,at+0xacc,29.f);memory[at+0xad0]=30;memory[at+0xd32]=std::uint8_t(-31);
    actor.alignment_target=g::AlignmentTarget{{1,2,3},-4};actor.interaction_kind=1;actor.interaction_mode=2;actor.interaction_slot=3;actor.interaction_detail=4;actor.explicit_resource_pair={5,6};actor.grid=7;
    put(memory,at+0xba0,actor.status);put(memory,at+0x544,actor.current);put(memory,at+0xd92,actor.pending_notice);memory[at+0xc7c]=0;put(memory,at+0x38,actor.position);put(memory,at+0x44,actor.previous_position);put(memory,at+0x4e4,actor.root_motion_delta);std::memcpy(memory+at+0x90,actor.orientation.data(),8);std::memcpy(memory+at+0xa0,actor.previous_orientation.data(),8);std::memcpy(memory+at+0xc84,actor.inventory.carried.data(),4);std::memcpy(memory+at+0xc89,actor.inventory.storage.data()+1,4);put(memory,at+0xc34,actor.alignment_target->position);put(memory,at+0xc4c,actor.alignment_target->yaw);memory[at+0xc78]=1;memory[at+0xc79]=2;memory[at+0xc7a]=3;memory[at+0xc7b]=4;memory[at+0xcaa]=5;memory[at+0xcab]=6;memory[at+0xcb0]=7;
}
void compare_peer_request(std::uint8_t* memory,unsigned at,const g::Actor& actor){
    check(actor.peer_request&&actor.transient_contact==memory[at+0xc64]&&actor.peer_request->state_high==memory[at+0xc65]);
    const auto reference=std::uint16_t((actor.peer_request->peer.kind==g::actors::ActorReference::Kind::auxiliary?0x8000u:0u)|actor.peer_request->peer.identifier);
    check(reference==get<std::uint16_t>(memory,at+0xc66)&&actor.peer_request->parameters[0]==get<std::int16_t>(memory,at+0xc68)&&actor.peer_request->parameters[1]==get<std::int16_t>(memory,at+0xc6a));
}
void compare_actor(std::uint8_t* memory,unsigned at,const g::Actor& actor){
    compare_peer_request(memory,at,actor);
    check(actor.interaction_request&&actor.related_target_state);const auto& request=*actor.interaction_request;
    check(actor.transient_action==memory[at+0xab8]&&request.kind==memory[at+0xab9]&&request.parameter==memory[at+0xaba]&&actor.scene_model.encoded()==memory[at+0xabb]&&std::uint8_t(*actor.related_target_state)==memory[at+0xd32]);
    check(std::memcmp(&request.anchor,memory+at+0xabc,12)==0&&request.orientation==get<unsigned>(memory,at+0xac8)&&std::bit_cast<unsigned>(request.travel_distance)==get<unsigned>(memory,at+0xacc)&&request.endpoint==memory[at+0xad0]);
    check(actor.status==get<unsigned>(memory,at+0xba0)&&actor.current==get<std::int16_t>(memory,at+0x544)&&actor.pending_notice==get<std::uint16_t>(memory,at+0xd92));
    check(std::memcmp(&actor.previous_position,memory+at+0x44,12)==0&&std::memcmp(actor.previous_orientation.data(),memory+at+0xa0,8)==0&&std::memcmp(&actor.root_motion_delta,memory+at+0x4e4,12)==0);
    check(std::memcmp(&actor.alignment_target->position,memory+at+0xc34,12)==0&&actor.alignment_target->yaw==get<std::int16_t>(memory,at+0xc4c));
    check(actor.interaction_kind==memory[at+0xc78]&&actor.interaction_mode==memory[at+0xc79]&&actor.interaction_slot==memory[at+0xc7a]&&actor.interaction_detail==memory[at+0xc7b]);
    check(std::memcmp(actor.inventory.carried.data(),memory+at+0xc84,4)==0&&std::memcmp(actor.inventory.storage.data()+1,memory+at+0xc89,4)==0&&std::memcmp(actor.explicit_resource_pair.data(),memory+at+0xcaa,2)==0&&actor.grid==memory[at+0xcb0]);
}
}
bool actor_reception_port(std::uint8_t* memory,R5900Context* c){
    using namespace actor_reception_fixture;if(c->pc!=0x18dbb0)return false;
    const auto dst=GPR_U32(c,4),src=GPR_U32(c,5),size=GPR_U32(c,6);if(src<packet+4||src>packet+12)return false;
    check(size==4&&dst>=base&&dst<base+8*0x10e0&&((dst-base)%0x10e0==0xc84||(dst-base)%0x10e0==0xc89));std::memcpy(memory+dst,memory+src,4);SET_GPR_U32(c,2,dst);return true;
}
void compare_peer_auxiliary_reception(std::vector<std::uint8_t>& ram){
    using namespace actor_reception_fixture;auto* memory=ram.data();std::fill(ram.begin(),ram.end(),0);owned_constants(memory);
    g::World world({{{1,2,4}},1,{32,UINT64_MAX}},std::make_shared<g::Session>());for(unsigned i=0;i<2;++i){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(i);check(bool(world.spawn_primary(i,std::move(actor)).id));memory[base+i*0x10e0+3]=std::uint8_t(i);}
    auto& pool=world.auxiliary_actors();call(memory,0x682c60);std::array<g::actors::EntityId,3> auxiliary;std::array<unsigned,3> addresses;
    for(unsigned i=0;i<3;++i){const auto source=call(memory,0x682d10,{i%2});const auto original=GPR_U32(&source,2);const auto made=pool.allocate(i%2);check(made.status==g::AuxiliaryStatus::completed&&original==0x417090u+0x1170u**pool.physical_slot(made.id));auxiliary[i]=made.id;addresses[i]=original;const auto actor=world.resolve(made.id);actor->model_variant=std::uint16_t(17+i);put(memory,original+0xbb4,actor->model_variant);}
    world.selected_actor=1;world.session().message_phase=1;world.mode=1;memory[0x4baded]=1;memory[0x3243fb]=1;memory[0x3243f2]=1;u::ActorReception receiver(world);const auto actor=world.primary(0);
    for(unsigned n=0;n<65536;++n){
        seed_actor(memory,base,*actor,n);const unsigned wanted=n%4==3?404:17+n%3;const u::ActorPeerMessage peer{u::MessageRoute::mode_one,1,std::uint16_t(n*65521u),{g::actors::ActorReference::Kind::auxiliary,std::uint16_t(wanted)},{std::bit_cast<std::int16_t>(std::uint16_t(n)),std::bit_cast<std::int16_t>(std::uint16_t(n*17))}};encode(memory,Message(peer));call(memory,0x67ed50,{1,packet,1});check(receiver.receive(peer,true).status==u::ReceptionStatus::completed);compare_actor(memory,base,*actor);
        if(wanted==404)check(actor->previous_position.x==-11&&actor->root_motion_delta.x==11);
        for(unsigned i=0;i<3;++i){if(world.resolve(auxiliary[i])->peer_request)compare_peer_request(memory,addresses[i],*world.resolve(auxiliary[i]));}
        ++reception_cases;++reception_auxiliary_cases;
    }
}
#include "tools/native_reconstruction/actor_reception_equipment_tests.inc"
#include "tools/native_reconstruction/actor_speech_reception_tests.inc"
void compare_actor_reception(const char* iso_path,const char* static_path,std::vector<std::uint8_t>& ram){
    using namespace actor_reception_fixture;auto* memory=ram.data();actor_reception_capture=true;
    g::World world({{{1,2,4}},1,{32,UINT64_MAX}},std::make_shared<g::Session>());for(unsigned i=0;i<8;++i){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(i);check(bool(world.spawn_primary(i,std::move(actor)).id));memory[base+i*0x10e0+2]=0;memory[base+i*0x10e0+3]=std::uint8_t(i);}
    auto room_objects=objects();u::ActorReception receiver(world,&room_objects);std::fill_n(memory+0x3c4580,32*60,0);
    const auto run=[&](unsigned kind,unsigned n,unsigned phase){
        const unsigned index=n%8,selected=(n>>3)%8,channel=index+1,echo=n%3;const auto actor=world.primary(index);const auto at=base+index*0x10e0;seed_actor(memory,at,*actor,n);world.selected_actor=std::uint8_t(selected);world.mode=std::uint8_t(n>>8);world.paused=std::bit_cast<std::int8_t>(std::uint8_t(n));world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));const auto selected_status=n%17?0u:4u;world.primary(selected)->status=selected_status;put(memory,base+selected*0x10e0+0xba0,selected_status);memory[0x4baded]=world.selected_actor;memory[0x3243fb]=std::uint8_t(phase);memory[0x3243f2]=world.mode;memory[0x4badf8]=std::uint8_t(world.paused);
        const auto value=message(kind,n,channel);encode(memory,value);call(memory,0x67ed50,{channel,packet,echo});const auto result=std::visit([&](const auto& m){return receiver.receive(m,echo!=0);},value);check(result.status==u::ReceptionStatus::completed&&!result.equipment);compare_actor(memory,at,*actor);for(unsigned peer=0;peer<8;++peer)if(world.primary(peer)->peer_request)compare_peer_request(memory,base+peer*0x10e0,*world.primary(peer));
        for(unsigned slot=0;slot<32;++slot){const auto cell=room_objects.source_coordinates(std::uint8_t(slot));check(cell&&std::uint8_t((*cell)[0])==memory[0x3c4598+60*slot]&&std::uint8_t((*cell)[1])==memory[0x3c4599+60*slot]);}++reception_cases;
    };
    for(unsigned kind=0;kind<9;++kind)for(unsigned n=0;n<65536;++n)run(kind,n,1+n%2);
    for(unsigned kind=0;kind<9;++kind)for(unsigned n=0;n<8192;++n)run(kind,n,n);
    compare_peer_auxiliary_reception(ram);
    compare_reception_equipment(iso_path,static_path,ram);
    compare_actor_speech_reception(ram);
    world.session().message_phase=1;world.selected_actor=1;world.primary(1)->status=0;auto live=world.primary(0);live->selected_resource=3;live->pending_notice=77;live->root_motion_delta={1,2,3};const u::ActorStatusMessage status{u::MessageRoute::mode_zero,1,8,9};
    check(receiver.receive(status,true).status==u::ReceptionStatus::unavailable&&live->status==8&&live->current==9&&!live->pending_notice&&live->root_motion_delta.x==0);++reception_refusals;live->selected_resource=0;
    u::ActorReception absent(world);const u::ActorRoomObjectMessage location{u::MessageRoute::mode_one,1,3,{4,5}};live->root_motion_delta={1,2,3};check(absent.receive(location,true).status==u::ReceptionStatus::unavailable&&live->grid==3&&live->root_motion_delta.x==1);++reception_refusals;
    for(unsigned ordinal=32;ordinal<256;++ordinal){auto invalid=location;invalid.grid=std::uint8_t(ordinal);check(receiver.receive(invalid,true).status==u::ReceptionStatus::unavailable&&live->grid==ordinal);}++reception_refusals;
    for(unsigned channel:{0u,9u,UINT32_MAX}){auto invalid=status;invalid.channel=channel;check(receiver.receive(invalid,true).status==u::ReceptionStatus::unavailable);}++reception_refusals;
    check(world.retire_primary(0)==g::actors::EntityStatus::completed&&receiver.receive(status,true).status==u::ReceptionStatus::unavailable);++reception_refusals;
    check(world.close()==g::Status::completed&&receiver.receive(status,true).status==u::ReceptionStatus::unavailable);++reception_refusals;actor_reception_capture=false;
}
