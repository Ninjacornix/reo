unsigned actor_snapshot_cases{},actor_snapshot_messages{},actor_snapshot_lookups{},actor_snapshot_refusals{},actor_snapshot_frames{};
namespace actor_snapshot_fixture {
namespace ats=actor_status_fixture;namespace g=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;
std::vector<u::ActorSnapshotMessage> messages;
std::vector<ats::Lookup> lookups;
unsigned captured_category{},callback{};bool recurse{};
bool equal(const u::ActorSnapshotMessage& a,const u::ActorSnapshotMessage& b){
    return a.route==b.route&&a.channel==b.channel&&a.action==b.action&&a.yaw==b.yaw&&a.health==b.health&&a.status==b.status&&
        std::bit_cast<unsigned>(a.position.x)==std::bit_cast<unsigned>(b.position.x)&&std::bit_cast<unsigned>(a.position.y)==std::bit_cast<unsigned>(b.position.y)&&std::bit_cast<unsigned>(a.position.z)==std::bit_cast<unsigned>(b.position.z)&&
        a.selected_resource==b.selected_resource&&a.equipment==b.equipment&&a.interaction_resource==b.interaction_resource&&a.grid==b.grid&&a.aim_pitch_adjustment==b.aim_pitch_adjustment&&a.aim_target_pitch==b.aim_target_pitch&&a.room==b.room&&a.aim_target_index==b.aim_target_index&&a.gauge_band==b.gauge_band&&a.model_variant==b.model_variant&&a.resource_pair==b.resource_pair&&a.auxiliary_flag==b.auxiliary_flag;
}
void mutate(g::Actor& a){
    a.primary=7;a.secondary=8;a.phase=9;a.subphase=10;a.position={-123,234,-345};a.orientation[1]=-12345;a.current=-321;a.status=0x10000000;
    a.selected_resource=200;a.equipment_slot=201;a.interaction_resource=202;a.grid=203;a.aim_pitch_adjustment=-111;a.aim_target_pitch=-222;a.room=0x1234;a.aim_target_index=204;a.model_variant=0x8888;a.explicit_resource_pair={205,206};a.auxiliary_status^=0x20000000u;a.category=2;
}
struct Sink:ats::Sink {
    using ats::Sink::send;std::vector<u::ActorSnapshotMessage> snapshots;u::StatePublication* publisher{};
    explicit Sink(g::World& w):ats::Sink(w){}
    bool send(const u::ActorSnapshotMessage& m)noexcept override{snapshots.push_back(m);return available;}
    std::optional<unsigned> room_owner(u::MessageRoute route,std::uint16_t room)noexcept override{
        lookups.push_back({route,room});check(world.session().actor_message_suppression==1);
        if(recurse){check(publisher&&publisher->actor_message(world.identity(0),u::ActorMessageSelector::snapshot)==u::PublicationStatus::completed&&snapshots.empty());}
        if(callback){world.mode=std::uint8_t(callback-1);mutate(*world.primary(0));}
        return lookup_available?std::optional<unsigned>{ats::mapped}:std::nullopt;
    }
};
struct Frame:actor_activity_fixture::Frame {
    u::Owner& update;
    explicit Frame(u::Owner& value):update(value){}
    void run(g::Stage stage,g::World& world,g::Actor& actor)override{
        if(stage==g::Stage::update_behavior){
            check(world.session().actor_message_suppression==0);
            check(update.record_actor_message(world.identity_of(actor),u::ActorMessageSelector::snapshot)==u::PublicationStatus::completed);
            check(update.record_actor_message(world.identity_of(actor),u::ActorMessageSelector::snapshot)==u::PublicationStatus::completed);
        }
        actor_activity_fixture::Frame::run(stage,world,actor);
    }
};
}
void actor_snapshot_message_port(std::uint8_t* memory,R5900Context* c){
    using namespace actor_snapshot_fixture;const auto at=GPR_U32(c,5);
    check(memory[at]==1&&memory[at+1]==44&&!memory[at+2]&&!memory[at+3]&&!GPR_U32(c,6)&&GPR_U32(c,7)==4);
    u::ActorSnapshotMessage m;m.route=c->pc==0x811190?u::MessageRoute::mode_zero:u::MessageRoute::mode_one;m.channel=GPR_U32(c,4);
    for(unsigned i=0;i<4;++i)m.action[i]=memory[at+4+i];
    m.position={get<float>(memory,at+8),get<float>(memory,at+12),get<float>(memory,at+16)};m.yaw=get<std::int16_t>(memory,at+20);m.health=get<std::int16_t>(memory,at+22);m.status=get<unsigned>(memory,at+24);
    m.selected_resource=memory[at+28];m.equipment=memory[at+29];m.interaction_resource=memory[at+30];m.grid=memory[at+31];m.aim_pitch_adjustment=get<std::int16_t>(memory,at+32);m.aim_target_pitch=get<std::int16_t>(memory,at+34);m.room=memory[at+36];m.aim_target_index=memory[at+37];
    if(captured_category==1)m.model_variant=memory[at+38];
    m.gauge_band=memory[at+39];m.resource_pair={memory[at+40],memory[at+41]};m.auxiliary_flag=memory[at+42]!=0;
    check(get<std::uint16_t>(memory,0x744638)==1);messages.push_back(m);
}
void actor_snapshot_room_owner_port(std::uint8_t* memory,R5900Context* c){
    using namespace actor_snapshot_fixture;lookups.push_back({c->pc==0x811d40?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,std::uint16_t(GPR_U32(c,4))});check(get<std::uint16_t>(memory,0x744638)==1);
    if(recurse){const auto count=messages.size();call(memory,0x67e230,{0x4a5c30,1});check(messages.size()==count);}
    if(callback){memory[0x3243f2]=std::uint8_t(callback-1);const unsigned a=0x4a5c30;memory[a+2]=2;for(unsigned i=0;i<4;++i)memory[a+8+i]=std::uint8_t(7+i);put(memory,a+0x38,-123.f);put(memory,a+0x3c,234.f);put(memory,a+0x40,-345.f);put(memory,a+0x92,std::int16_t(-12345));put(memory,a+0x544,std::int16_t(-321));put(memory,a+0xba0,0x10000000u);memory[a+0xc7c]=200;memory[a+0xc7f]=201;memory[a+0xc80]=202;memory[a+0xcb0]=203;put(memory,a+0xbc8,std::int16_t(-111));put(memory,a+0xcd4,std::int16_t(-222));put(memory,a+0x1e2,std::uint16_t(0x1234));memory[a+0xcdc]=204;put(memory,a+0xbb4,std::uint16_t(0x8888));memory[a+0xcaa]=205;memory[a+0xcab]=206;put(memory,a+0xba4,get<unsigned>(memory,a+0xba4)^0x20000000u);}
    SET_GPR_U32(c,2,ats::mapped);
}
void compare_actor_snapshot_messages(std::uint8_t* memory){
    using namespace actor_snapshot_fixture;actor_snapshot_capture=true;ats::nested=0;
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());
    for(unsigned i=0;i<8;++i){auto a=std::make_unique<g::Actor>();a->slot=std::uint8_t(i);check(bool(world.spawn_primary(i,std::move(a)).id));}
    reo::native::gameplay_scenario::FlagState flags;Sink sink(world);u::StatePublication publisher(world,flags,&sink);sink.publisher=&publisher;const auto id=world.identity(0);const auto a=world.primary(0);const unsigned raw=0x4a5c30;
    const auto run=[&](unsigned n,unsigned mode,unsigned phase,unsigned category,unsigned slot,unsigned selected,unsigned status,unsigned suppression,unsigned pause,unsigned cb){
        a->category=std::uint8_t(category);captured_category=category;a->slot=std::uint8_t(slot);a->primary=std::uint8_t(n>>8);a->secondary=std::uint8_t(n);a->phase=std::uint8_t(n*17);a->subphase=std::uint8_t(n*31);a->status=status;a->auxiliary_status=n*1664525u;a->room=std::uint16_t(n*65521u);a->position={std::bit_cast<float>(n*1664525u),std::bit_cast<float>(n*1013904223u),std::bit_cast<float>(n*65521u)};a->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(n));a->current=std::bit_cast<std::int16_t>(std::uint16_t(n*65521u));a->selected_resource=std::uint8_t(n*17);a->equipment_slot=std::uint8_t(n*31);a->interaction_resource=std::uint8_t(n*127);a->grid=std::uint8_t(n*63);a->aim_pitch_adjustment=std::bit_cast<std::int16_t>(std::uint16_t(n*65521));a->aim_target_pitch=std::bit_cast<std::int16_t>(std::uint16_t(n*65497));a->aim_target_index=std::uint8_t(n*251);a->model_variant=std::uint16_t(n*17);a->explicit_resource_pair={std::uint8_t(n*29),std::uint8_t(n*67)};
        world.mode=std::uint8_t(mode);world.selected_actor=std::uint8_t(selected);world.paused=std::bit_cast<std::int8_t>(std::uint8_t(pause));world.room=std::uint16_t(n*17);world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));world.session().actor_message_suppression=std::uint16_t(suppression);
        for(unsigned i=0;i<8;++i){const auto gauge=world.primary(i);gauge->gauge_value=(n+i)*65521u;gauge->character=std::uint8_t((n+i)%8);put(memory,raw+0x10e0*i+0xbac,*gauge->gauge_value);memory[raw+0x10e0*i+0xb98]=gauge->character;}
        memory[raw+2]=a->category;memory[raw+3]=a->slot;memory[raw+8]=a->primary;memory[raw+9]=a->secondary;memory[raw+10]=a->phase;memory[raw+11]=a->subphase;put(memory,raw+0xba0,status);put(memory,raw+0xba4,a->auxiliary_status);put(memory,raw+0x1e2,a->room);put(memory,raw+0x38,a->position.x);put(memory,raw+0x3c,a->position.y);put(memory,raw+0x40,a->position.z);put(memory,raw+0x92,a->orientation[1]);put(memory,raw+0x544,a->current);memory[raw+0xc7c]=a->selected_resource;memory[raw+0xc7f]=a->equipment_slot;memory[raw+0xc80]=*a->interaction_resource;memory[raw+0xcb0]=a->grid;put(memory,raw+0xbc8,*a->aim_pitch_adjustment);put(memory,raw+0xcd4,*a->aim_target_pitch);memory[raw+0xcdc]=*a->aim_target_index;put(memory,raw+0xbb4,a->model_variant);memory[raw+0xcaa]=a->explicit_resource_pair[0];memory[raw+0xcab]=a->explicit_resource_pair[1];
        memory[0x3243f2]=world.mode;memory[0x3243fb]=std::uint8_t(phase);memory[0x4baded]=world.selected_actor;memory[0x4badf8]=std::uint8_t(pause);put(memory,0x3243dc,world.room);put(memory,0x744638,std::uint16_t(suppression));ats::mapped=n%7?n*65521u:UINT32_MAX;callback=cb;recurse=n%13==0;messages.clear();lookups.clear();sink.snapshots.clear();sink.lookups.clear();
        call(memory,0x67e230,{raw,0xabcd0001u});check(publisher.actor_message(id,u::ActorMessageSelector::snapshot)==u::PublicationStatus::completed);check(messages.size()==sink.snapshots.size()&&lookups==sink.lookups);for(unsigned i=0;i<messages.size();++i)check(equal(messages[i],sink.snapshots[i]));check(world.mode==memory[0x3243f2]&&world.session().actor_message_suppression==get<std::uint16_t>(memory,0x744638)&&a->status==get<unsigned>(memory,raw+0xba0)&&a->category==memory[raw+2]);
        actor_snapshot_messages+=unsigned(messages.size());actor_snapshot_lookups+=unsigned(lookups.size());++actor_snapshot_cases;
    };
    for(unsigned n=0;n<65536;++n)run(n,n>>8,n,n%4,n,n%8,n%5?0x10000000u:n*1664525u,n,n%7?0:n,0);
    for(unsigned category:{0u,1u})for(unsigned mode=0;mode<4;++mode)for(unsigned n=0;n<65536;++n)run(n,mode,1+n%2,category,0,category?n%8:0,(n%17?0x10000000u:0x10000004u)|(n%2?0x08000000u:0u),n%19?65535:1,0,n%23?0:1+n%4);
    callback=0;recurse=false;world.mode=0;world.selected_actor=0;world.paused=0;world.session().message_phase=1;a->category=0;a->slot=0;a->primary=1;a->secondary=0;a->gauge_value=0;a->character=0;a->status=0;
    const auto reset=[&](){world.session().actor_message_suppression=65535;a->status=0;a->interaction_resource=0;a->aim_pitch_adjustment=0;a->aim_target_pitch=0;a->aim_target_index=255;};
    for(unsigned missing=0;missing<5;++missing){reset();if(missing==0)a->interaction_resource.reset();if(missing==1)a->aim_pitch_adjustment.reset();if(missing==2)a->aim_target_pitch.reset();if(missing==3)a->aim_target_index.reset();if(missing==4)a->gauge_value.reset();check(publisher.actor_message(id,u::ActorMessageSelector::snapshot)==u::PublicationStatus::unavailable&&a->status==0x08000000u&&world.session().actor_message_suppression==65535);++actor_snapshot_refusals;a->gauge_value=0;}
    reset();u::StatePublication missing(world,flags);check(missing.actor_message(id,u::ActorMessageSelector::snapshot)==u::PublicationStatus::message_unavailable&&world.session().actor_message_suppression==1);++actor_snapshot_refusals;
    reset();sink.available=false;check(publisher.actor_message(id,u::ActorMessageSelector::snapshot)==u::PublicationStatus::message_unavailable&&world.session().actor_message_suppression==1);++actor_snapshot_refusals;sink.available=true;
    reset();a->category=1;a->status=0x10000000u;sink.lookup_available=false;check(publisher.actor_message(id,u::ActorMessageSelector::snapshot)==u::PublicationStatus::unavailable&&world.session().actor_message_suppression==1);++actor_snapshot_refusals;sink.lookup_available=true;
    reset();a->category=0;a->room=world.room=0;a->active=true;sink.snapshots.clear();actor_action_fixture::Notifications notifications;u::Owner update(world,notifications,e::RuleBook::file1(),&sink);Frame frame(update);
    for(unsigned n=0;n<2;++n){check(world.update_primary(frame).status==g::Status::completed&&sink.snapshots.size()==n+1&&world.frame_shared_counter==1);++actor_snapshot_frames;}
    check(update.close()==u::Status::completed&&update.record_actor_message(id,u::ActorMessageSelector::snapshot)==u::PublicationStatus::unavailable);++actor_snapshot_refusals;
    check(world.close()==g::Status::completed&&publisher.actor_message(id,u::ActorMessageSelector::snapshot)==u::PublicationStatus::unavailable);++actor_snapshot_refusals;actor_snapshot_capture=false;
}
