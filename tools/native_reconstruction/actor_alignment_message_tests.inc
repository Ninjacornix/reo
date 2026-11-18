unsigned actor_alignment_cases{},actor_alignment_messages{},actor_alignment_lookups{},actor_alignment_refusals{};
namespace actor_alignment_fixture {
namespace ats=actor_status_fixture;namespace g=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;
std::vector<u::ActorAlignmentMessage> messages;std::vector<ats::Lookup> lookups;unsigned callback{};
bool equal(const u::ActorAlignmentMessage& a,const u::ActorAlignmentMessage& b){return a.route==b.route&&a.channel==b.channel&&a.target.yaw==b.target.yaw&&std::memcmp(&a.target.position,&b.target.position,12)==0;}
void mutate(g::Actor& a){a.alignment_target=g::AlignmentTarget{{11,22,33},-1234};}
struct AlignmentSink:ats::Sink {
    using ats::Sink::send;std::vector<u::ActorAlignmentMessage> alignments;
    explicit AlignmentSink(g::World& w):ats::Sink(w){}
    bool send(const u::ActorAlignmentMessage& m)noexcept override{alignments.push_back(m);return available;}
    std::optional<unsigned> room_owner(u::MessageRoute route,std::uint16_t room)noexcept override{
        lookups.push_back({route,room});if(callback){world.mode=std::uint8_t(callback-1);mutate(*world.primary(0));}
        return lookup_available?std::optional<unsigned>{ats::mapped}:std::nullopt;
    }
};
}
void actor_alignment_message_port(std::uint8_t* memory,R5900Context* c){
    using namespace actor_alignment_fixture;const auto at=GPR_U32(c,5);check(memory[at]==6&&memory[at+1]==20&&!memory[at+2]&&!memory[at+3]&&!GPR_U32(c,6)&&GPR_U32(c,7)==4);
    messages.push_back({c->pc==0x811190?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,GPR_U32(c,4),{{get<float>(memory,at+4),get<float>(memory,at+8),get<float>(memory,at+12)},get<std::int16_t>(memory,at+16)}});
}
void actor_alignment_room_owner_port(std::uint8_t* memory,R5900Context* c){
    using namespace actor_alignment_fixture;lookups.push_back({c->pc==0x811d40?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,std::uint16_t(GPR_U32(c,4))});
    if(callback){memory[0x3243f2]=std::uint8_t(callback-1);put(memory,0x4a5c30+0xc34,11.f);put(memory,0x4a5c30+0xc38,22.f);put(memory,0x4a5c30+0xc3c,33.f);put(memory,0x4a5c30+0xc4c,std::int16_t(-1234));}SET_GPR_U32(c,2,ats::mapped);
}
void compare_actor_alignment_messages(std::uint8_t* memory){
    using namespace actor_alignment_fixture;actor_alignment_capture=true;ats::nested=0;
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto a=world.primary(0);reo::native::gameplay_scenario::FlagState flags;AlignmentSink sink(world);u::StatePublication publisher(world,flags,&sink);
    const auto run=[&](unsigned n,unsigned mode,unsigned phase,unsigned category,unsigned slot,unsigned selected,unsigned status,unsigned suppression,unsigned paused,unsigned cb){
        a->category=std::uint8_t(category);a->slot=std::uint8_t(slot);a->status=status;a->position={100,200,300};a->orientation[1]=-9;a->alignment_target=g::AlignmentTarget{{std::bit_cast<float>(n*1664525u),std::bit_cast<float>(n*1013904223u),std::bit_cast<float>(n*65521u)},std::bit_cast<std::int16_t>(std::uint16_t(n*65521))};a->gauge_value.reset();world.mode=std::uint8_t(mode);world.selected_actor=std::uint8_t(selected);world.paused=std::bit_cast<std::int8_t>(std::uint8_t(paused));world.room=std::uint16_t(n*17);world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));world.session().actor_message_suppression=std::uint16_t(suppression);
        const unsigned raw=0x4a5c30;memory[raw+2]=a->category;memory[raw+3]=a->slot;put(memory,raw+0xba0,status);put(memory,raw+0x38,a->position);put(memory,raw+0x92,a->orientation[1]);put(memory,raw+0xc34,a->alignment_target->position);put(memory,raw+0xc4c,a->alignment_target->yaw);memory[0x3243f2]=world.mode;memory[0x3243fb]=std::uint8_t(phase);memory[0x4baded]=world.selected_actor;memory[0x4badf8]=std::uint8_t(paused);put(memory,0x3243dc,world.room);put(memory,0x744638,std::uint16_t(suppression));ats::mapped=n%7?n*65521u:UINT32_MAX;callback=cb;messages.clear();lookups.clear();sink.alignments.clear();sink.lookups.clear();
        call(memory,0x67e230,{raw,0xabcd0006u});check(publisher.actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::completed);check(messages.size()==sink.alignments.size()&&lookups==sink.lookups);for(unsigned i=0;i<messages.size();++i)check(equal(messages[i],sink.alignments[i]));check(world.mode==memory[0x3243f2]&&a->status==get<unsigned>(memory,raw+0xba0)&&world.session().actor_message_suppression==get<std::uint16_t>(memory,0x744638));check(std::memcmp(&a->alignment_target->position,memory+raw+0xc34,12)==0&&a->alignment_target->yaw==get<std::int16_t>(memory,raw+0xc4c)&&a->position.x==100&&a->orientation[1]==-9&&!a->gauge_value);actor_alignment_messages+=unsigned(messages.size());actor_alignment_lookups+=unsigned(lookups.size());++actor_alignment_cases;
    };
    for(unsigned n=0;n<65536;++n)run(n,n>>8,n,n%4,n,n>>8,n%5?0x10000000u:n*1664525u,n,n%7?0:n,0);
    for(unsigned category:{0u,1u})for(unsigned mode=0;mode<4;++mode)for(unsigned n=0;n<8192;++n)run(n,mode,1+n%2,category,0,0,n%17?0x10000000u:0x10000004u,n%19?65535:6,0,n%23?0:1+n%4);
    for(unsigned n=0;n<65536;++n)run(n,1,1,0,n,n>>8,0,65535,0,0);
    callback=0;world.mode=0;world.paused=0;world.selected_actor=0;world.session().message_phase=1;world.session().actor_message_suppression=0;a->category=0;a->slot=0;a->status=0;a->alignment_target.reset();
    check(publisher.actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::unavailable&&world.session().actor_message_suppression==0&&a->status==0);++actor_alignment_refusals;
    world.session().message_phase=0;check(publisher.actor_message({},u::ActorMessageSelector::alignment)==u::PublicationStatus::completed);++actor_alignment_refusals;world.session().message_phase=1;
    a->alignment_target=g::AlignmentTarget{{1,2,3},-7};u::StatePublication missing(world,flags);check(missing.actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::message_unavailable);++actor_alignment_refusals;
    ats::Sink old_sink(world);u::StatePublication legacy(world,flags,&old_sink);check(legacy.actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::message_unavailable);++actor_alignment_refusals;
    sink.available=false;check(publisher.actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::message_unavailable);++actor_alignment_refusals;sink.available=true;a->category=1;a->status=0x10000000u;sink.lookup_available=false;check(publisher.actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::unavailable);++actor_alignment_refusals;sink.lookup_available=true;
    a->category=0;a->status=0;actor_action_fixture::Notifications notifications;u::Owner update(world,notifications,e::RuleBook::file1(),&sink);sink.alignments.clear();check(update.record_actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::completed&&sink.alignments.size()==1&&!a->gauge_value);++actor_alignment_cases;
    check(update.record_actor_message({},u::ActorMessageSelector::alignment)==u::PublicationStatus::unavailable);++actor_alignment_refusals;
    check(update.close()==u::Status::completed&&update.record_actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::unavailable);++actor_alignment_refusals;
    check(world.retire_primary(0)==g::actors::EntityStatus::completed&&publisher.actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::unavailable);++actor_alignment_refusals;
    check(world.close()==g::Status::completed&&publisher.actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::unavailable);++actor_alignment_refusals;actor_alignment_capture=false;
}
