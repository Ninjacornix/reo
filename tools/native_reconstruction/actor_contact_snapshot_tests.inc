#include <limits>
unsigned contact_snapshot_cases{},contact_snapshot_messages{},contact_snapshot_lookups{},contact_snapshot_refusals{},contact_snapshot_recursions{};
namespace contact_snapshot_fixture {
namespace g=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;namespace ats=actor_status_fixture;
constexpr unsigned raw=0x4a5c30;
std::array<g::actors::EntityId,3> references;
constexpr std::array<unsigned,3> pointers{0,raw,raw+0x10e0};
std::vector<u::ActorContactSnapshotMessage> messages;std::vector<ats::Lookup> lookups;
unsigned callback{},source_recursions{};bool recursive{};
bool equal(const u::ActorContactSnapshotMessage& a,const u::ActorContactSnapshotMessage& b){
    return a.route==b.route&&a.channel==b.channel&&a.action==b.action&&a.position==b.position&&a.yaw==b.yaw&&a.health==b.health&&a.room==b.room&&a.status==b.status&&a.source_kind==b.source_kind&&a.source_slot==b.source_slot&&a.source_related==b.source_related&&a.response_class==b.response_class&&a.region==b.region&&a.auxiliary_a==b.auxiliary_a&&a.response_code==b.response_code&&a.response_flags==b.response_flags&&a.gauge_band==b.gauge_band&&std::memcmp(&a.direction,&b.direction,12)==0&&a.recorded_source==b.recorded_source&&a.model_variant==b.model_variant;
}
void mutate(g::World& w){w.mode=std::uint8_t(callback-1);const auto a=w.primary(0);a->position={11,22,33};a->status|=8;a->contact.direction={44,55,66};a->contact.recorded_source={};}
struct ContactSnapshotSink:ats::Sink {
    using ats::Sink::send;std::vector<u::ActorContactSnapshotMessage> contacts;u::StatePublication* publisher{};g::actors::EntityId actor;
    explicit ContactSnapshotSink(g::World& w):ats::Sink(w){}
    bool send(const u::ActorContactSnapshotMessage& m)noexcept override{
        contacts.push_back(m);if(recursive){check(publisher&&publisher->actor_message(actor,u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::completed);++contact_snapshot_recursions;}return available;
    }
    std::optional<unsigned> room_owner(u::MessageRoute route,std::uint16_t room)noexcept override{lookups.push_back({route,room});if(callback)mutate(world);return lookup_available?std::optional<unsigned>{ats::mapped}:std::nullopt;}
};
}
void actor_contact_snapshot_message_port(std::uint8_t* memory,R5900Context* c){
    using namespace contact_snapshot_fixture;const auto at=GPR_U32(c,5);check(memory[at]==5&&memory[at+1]==52&&!memory[at+2]&&!memory[at+3]&&!GPR_U32(c,6)&&GPR_U32(c,7)==4);
    u::ActorContactSnapshotMessage m;m.route=c->pc==0x811190?u::MessageRoute::mode_zero:u::MessageRoute::mode_one;m.channel=GPR_U32(c,4);
    for(unsigned i=0;i<4;++i)m.action[i]=memory[at+4+i];
    for(unsigned i=0;i<3;++i)m.position[i]=get<std::int16_t>(memory,at+8+2*i);
    m.yaw=get<std::int16_t>(memory,at+14);m.health=get<std::int16_t>(memory,at+16);m.room=memory[at+18];m.status=get<unsigned>(memory,at+20);
    m.source_kind=memory[at+24];m.source_slot=memory[at+25];m.source_related={memory[at+26],memory[at+27]};m.response_class=memory[at+28];m.region=memory[at+29];m.auxiliary_a=memory[at+30];m.response_code=memory[at+31];m.response_flags=memory[at+32];m.gauge_band=memory[at+33];m.direction=get<reo::native::gameplay_collision::Vec3>(memory,at+36);
    const auto pointer=get<unsigned>(memory,at+48);bool mapped=false;for(unsigned i=0;i<3;++i)if(pointer==pointers[i]){m.recorded_source=references[i];mapped=true;}check(mapped);if(memory[raw+2]==1)m.model_variant=memory[at+19];messages.push_back(m);
    if(recursive){call(memory,0x67e230,{raw,5});++source_recursions;}
}
void actor_contact_snapshot_room_port(std::uint8_t* memory,R5900Context* c){
    using namespace contact_snapshot_fixture;lookups.push_back({c->pc==0x811d40?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,std::uint16_t(GPR_U32(c,4))});
    if(callback){memory[0x3243f2]=std::uint8_t(callback-1);put(memory,raw+0x38,g::Position{11,22,33});put(memory,raw+0xba0,get<unsigned>(memory,raw+0xba0)|8u);put(memory,raw+0x12c,reo::native::gameplay_collision::Vec3{44,55,66});put(memory,raw+0x11c,0u);}SET_GPR_U32(c,2,ats::mapped);
}
void compare_actor_contact_snapshot(std::uint8_t* memory){
    using namespace contact_snapshot_fixture;actor_contact_snapshot_capture=true;ats::nested=0;
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto peer=world.spawn_primary(1,std::make_unique<g::Actor>()).id;references={g::actors::EntityId{},id,peer};const auto a=world.primary(0);world.primary(1)->character=1;world.primary(1)->gauge_value=g::actor_gauge_limits[1]/2;
    memory[raw+0x10e0+0xb98]=1;put(memory,raw+0x10e0+0xbac,*world.primary(1)->gauge_value);reo::native::gameplay_scenario::FlagState flags;ContactSnapshotSink sink(world);u::StatePublication publisher(world,flags,&sink);sink.publisher=&publisher;sink.actor=id;
    const auto run=[&](unsigned n,unsigned mode,unsigned phase,unsigned category,unsigned selected,unsigned status,unsigned suppression,unsigned paused,unsigned cb,const g::Position& position){
        a->category=std::uint8_t(category);a->slot=std::uint8_t(category?n:0);a->status=status;world.selected_actor=std::uint8_t(selected);world.mode=std::uint8_t(mode);world.paused=std::bit_cast<std::int8_t>(std::uint8_t(paused));world.room=std::uint16_t(n*17);world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));world.session().actor_message_suppression=std::uint16_t(suppression);
        a->primary=std::uint8_t(n);a->secondary=std::uint8_t(n>>8);a->phase=std::uint8_t(n*17);a->subphase=std::uint8_t(n*31);a->position=position;a->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(n));a->current=std::bit_cast<std::int16_t>(std::uint16_t(n*65521));a->room=std::uint16_t(n);a->model_variant=std::uint16_t(n*257);a->character=std::uint8_t(n%8);a->gauge_value=g::actor_gauge_limits[n%8]*std::uint64_t(n%10001)/10000;
        a->source_kind=std::uint8_t(n);a->source_slot=std::uint8_t(n>>8);a->contact.source_related={std::uint8_t(n*17),std::uint8_t(n*31)};a->response_class=std::uint8_t(n*37);a->contact.region=std::uint8_t(n*41);a->contact.auxiliary_a=std::uint8_t(n*43);a->contact.response_code=std::uint8_t(n*47);a->response_flags=std::uint8_t(n*53);a->contact.direction={std::bit_cast<float>(n*1664525u),std::bit_cast<float>(n*1013904223u),std::bit_cast<float>(n*65521u)};a->contact.recorded_source=references[n%3];
        memory[raw+2]=a->category;memory[raw+3]=a->slot;memory[raw+8]=a->primary;memory[raw+9]=a->secondary;memory[raw+10]=a->phase;memory[raw+11]=a->subphase;put(memory,raw+0x38,a->position);put(memory,raw+0x92,a->orientation[1]);put(memory,raw+0x544,a->current);put(memory,raw+0x1e2,a->room);put(memory,raw+0xba0,a->status);put(memory,raw+0xbb4,a->model_variant);memory[raw+0xb98]=a->character;put(memory,raw+0xbac,*a->gauge_value);
        memory[raw+0x148]=a->source_kind;memory[raw+0x149]=a->source_slot;memory[raw+0x14a]=a->contact.source_related.category;memory[raw+0x14b]=a->contact.source_related.token;memory[raw+0x140]=a->response_class;memory[raw+0x13e]=a->contact.region;memory[raw+0x14c]=a->contact.auxiliary_a;memory[raw+0x141]=a->contact.response_code;memory[raw+0x143]=a->response_flags;put(memory,raw+0x12c,a->contact.direction);put(memory,raw+0x11c,pointers[n%3]);memory[0x3243f2]=world.mode;memory[0x3243fb]=std::uint8_t(phase);memory[0x4baded]=world.selected_actor;memory[0x4badf8]=std::uint8_t(paused);put(memory,0x3243dc,world.room);put(memory,0x744638,std::uint16_t(suppression));
        ats::mapped=n%7?n*65521u:UINT32_MAX;callback=cb;recursive=n%19==0;source_recursions=0;const auto before_recursions=contact_snapshot_recursions;messages.clear();lookups.clear();sink.lookups.clear();sink.contacts.clear();
        try{
            call(memory,0x67e230,{raw,0xabcd0005u});const auto original_lookups=lookups;lookups.clear();
            check(publisher.actor_message(id,u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::completed);
            check(messages.size()==sink.contacts.size());
            check(original_lookups==sink.lookups);
            for(unsigned i=0;i<messages.size();++i)check(equal(messages[i],sink.contacts[i]));
            check(contact_snapshot_recursions-before_recursions==source_recursions);
            check(a->status==get<unsigned>(memory,raw+0xba0));
            check(world.session().actor_message_suppression==get<std::uint16_t>(memory,0x744638));
            check(world.mode==memory[0x3243f2]);
            check(std::memcmp(&a->position,memory+raw+0x38,12)==0);
            contact_snapshot_messages+=unsigned(messages.size());contact_snapshot_lookups+=unsigned(original_lookups.size());++contact_snapshot_cases;
        }catch(const std::exception& error){throw std::runtime_error(std::string(error.what())+" contact snapshot n="+std::to_string(n)+" mode="+std::to_string(mode)+" category="+std::to_string(category)+" callback="+std::to_string(cb));}
    };
    for(unsigned category:{0u,1u})for(unsigned mode=0;mode<4;++mode)for(unsigned n=0;n<65536;++n)run(n,mode,1+n%2,category,0,category?0x10000000u:0u,65535,0,n%17?0:1+n%4,{float(std::int32_t(n*65521u))*.25f,float(std::int16_t(n))+.875f,-float(n*65521u)*.25f});
    for(unsigned n=0;n<65536;++n)run(n,n>>8,n,n%4,n%2,n%7?0x10000000u:4u,n,n%7?0:n,0,{float(n),-float(n),-0.f});
    const std::array<float,15> boundaries{0.f,-0.f,.999f,-.999f,1.001f,-1.001f,32767.99f,32768.5f,-32768.5f,65536.5f,-65536.5f,2147483520.f,-2147483648.f,std::numeric_limits<float>::denorm_min(),-std::numeric_limits<float>::denorm_min()};
    for(unsigned i=0;i<boundaries.size();++i)run(i,1,1,0,0,0,65535,0,0,{boundaries[i],boundaries[(i+1)%boundaries.size()],boundaries[(i+2)%boundaries.size()]});
    callback=0;recursive=false;a->category=0;a->slot=0;a->status=0;world.selected_actor=0;world.mode=1;world.paused=0;world.session().message_phase=1;world.session().actor_message_suppression=0;
    for(float bad:{std::numeric_limits<float>::quiet_NaN(),std::numeric_limits<float>::infinity(),-std::numeric_limits<float>::infinity(),2147483648.f,-2147483904.f}){a->position={bad,0,0};check(publisher.actor_message(id,u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::unavailable&&world.session().actor_message_suppression==0);++contact_snapshot_refusals;}
    a->position={1,2,3};a->gauge_value.reset();check(publisher.actor_message(id,u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::unavailable&&world.session().actor_message_suppression==0);++contact_snapshot_refusals;a->gauge_value=0;
    u::StatePublication missing(world,flags);check(missing.actor_message(id,u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::message_unavailable&&world.session().actor_message_suppression==5);++contact_snapshot_refusals;world.session().actor_message_suppression=0;
    ats::Sink unsupported(world);u::StatePublication old(world,flags,&unsupported);check(old.actor_message(id,u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::message_unavailable&&world.session().actor_message_suppression==5);++contact_snapshot_refusals;world.session().actor_message_suppression=0;
    a->category=1;a->status=0x10000000u;sink.lookup_available=false;check(publisher.actor_message(id,u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::unavailable&&world.session().actor_message_suppression==5);++contact_snapshot_refusals;sink.lookup_available=true;world.session().actor_message_suppression=0;
    a->category=0;a->status=0;sink.available=false;check(publisher.actor_message(id,u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::message_unavailable&&world.session().actor_message_suppression==5);++contact_snapshot_refusals;sink.available=true;world.session().actor_message_suppression=0;
    actor_action_fixture::Notifications notifications;u::Owner owner(world,notifications,e::RuleBook::file1(),&sink);check(owner.record_actor_message(id,u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::completed);++contact_snapshot_cases;
    world.session().actor_message_suppression=0;
    check(publisher.actor_message({},u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::unavailable);++contact_snapshot_refusals;
    check(world.retire_primary(0)==g::actors::EntityStatus::completed&&publisher.actor_message(id,u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::unavailable);++contact_snapshot_refusals;
    check(owner.close()==u::Status::completed&&owner.record_actor_message(id,u::ActorMessageSelector::contact_snapshot)==u::PublicationStatus::unavailable);++contact_snapshot_refusals;actor_contact_snapshot_capture=false;
}
