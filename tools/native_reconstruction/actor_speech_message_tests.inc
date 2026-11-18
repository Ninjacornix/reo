unsigned actor_speech_cases{},actor_speech_messages{},actor_speech_lookups{},actor_speech_refusals{};
namespace actor_speech_fixture {
namespace g=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;namespace ats=actor_status_fixture;
constexpr unsigned raw=0x4a5c30;
std::vector<u::ActorSpeechMessage> messages;std::vector<ats::Lookup> lookups;unsigned callback{};
void write(std::uint8_t* m,unsigned at,const g::SpeechState& state){
    check(state.selection&&state.variant&&state.gauge_notice);const auto& s=*state.selection;
    put(m,at+0xdb4,s.sequence);put(m,at+0xdb8,*state.gauge_notice);put(m,at+0xdc2,s.target_identifier);
    m[at+0xdc7]=std::uint8_t(s.target_context);m[at+0xdc1]=std::uint8_t(s.response_state);m[at+0xdc0]=std::uint8_t(s.pending);m[at+0xda9]=std::uint8_t(*state.variant);
}
void same(std::uint8_t* m,unsigned at,const g::SpeechState& state){
    check(state.selection&&state.variant&&state.gauge_notice);const auto& s=*state.selection;
    check(s.sequence==get<unsigned>(m,at+0xdb4)&&*state.gauge_notice==get<std::int32_t>(m,at+0xdb8)&&s.target_identifier==get<std::int16_t>(m,at+0xdc2));
    check(std::uint8_t(s.target_context)==m[at+0xdc7]&&std::uint8_t(s.response_state)==m[at+0xdc1]&&std::uint8_t(s.pending)==m[at+0xdc0]&&std::uint8_t(*state.variant)==m[at+0xda9]);
}
void mutate(g::SpeechState& state){state={g::SpeechSelection{123,-456,-7,8,-9},-101,std::int8_t(11)};}
bool equal(const u::ActorSpeechMessage& a,const u::ActorSpeechMessage& b){return a.route==b.route&&a.channel==b.channel&&a.sequence==b.sequence&&a.target_identifier==b.target_identifier&&a.target_context==b.target_context&&a.response_state==b.response_state&&a.pending==b.pending&&a.gauge_notice==b.gauge_notice&&a.variant==b.variant;}
struct SpeechSink:ats::Sink {
    using ats::Sink::send;std::vector<u::ActorSpeechMessage> speeches;
    explicit SpeechSink(g::World& world):ats::Sink(world){}
    bool send(const u::ActorSpeechMessage& value)noexcept override{speeches.push_back(value);return available;}
    std::optional<unsigned> room_owner(u::MessageRoute route,std::uint16_t room)noexcept override{lookups.push_back({route,room});if(callback){world.mode=std::uint8_t(callback-1);mutate(world.primary(0)->speech);}return lookup_available?std::optional<unsigned>{ats::mapped}:std::nullopt;}
};
}
void actor_speech_message_port(std::uint8_t* m,R5900Context* c){
    using namespace actor_speech_fixture;const auto p=GPR_U32(c,5);check(m[p]==11&&m[p+1]==20&&!m[p+2]&&!m[p+3]&&!GPR_U32(c,6)&&GPR_U32(c,7)==4);
    messages.push_back({c->pc==0x811190?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,GPR_U32(c,4),get<unsigned>(m,p+4),get<std::int16_t>(m,p+8),get<std::int16_t>(m,p+10),get<std::int32_t>(m,p+16),get<std::int8_t>(m,p+12),get<std::int8_t>(m,p+13),get<std::int8_t>(m,p+14)});
}
void actor_speech_room_port(std::uint8_t* m,R5900Context* c){using namespace actor_speech_fixture;const auto route=c->pc==0x811d40?u::MessageRoute::mode_zero:u::MessageRoute::mode_one;lookups.push_back({route,std::uint16_t(GPR_U32(c,4))});SET_GPR_U32(c,2,ats::mapped);if(callback){m[0x3243f2]=std::uint8_t(callback-1);g::SpeechState state;mutate(state);write(m,raw,state);}}
void compare_actor_speech_messages(std::uint8_t* memory){
    using namespace actor_speech_fixture;actor_speech_capture=true;
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());for(unsigned i=0;i<8;++i){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(i);check(bool(world.spawn_primary(i,std::move(actor)).id));}
    reo::native::gameplay_scenario::FlagState flags;SpeechSink sink(world);u::StatePublication publisher(world,flags,&sink);const auto id=world.identity(0);const auto a=world.primary(0);
    const auto run=[&](unsigned n,unsigned category,unsigned mode,unsigned phase,unsigned selected,unsigned status,unsigned suppression,unsigned paused,unsigned cb){
        a->speech={g::SpeechSelection{n*1664525u,std::bit_cast<std::int16_t>(std::uint16_t(n*65521)),std::bit_cast<std::int8_t>(std::uint8_t(n)),std::bit_cast<std::int8_t>(std::uint8_t(n>>8)),std::bit_cast<std::int8_t>(std::uint8_t(n*31))},-12345,std::bit_cast<std::int8_t>(std::uint8_t(n*17))};write(memory,raw,a->speech);
        for(unsigned i=0;i<8;++i){const auto actor=world.primary(i);actor->character=std::uint8_t((n+i)%8);actor->gauge_value=n%2?(n+i)*65521u:g::actor_gauge_limits[actor->character]*(n%101)/100;memory[raw+0x10e0*i+0xb98]=actor->character;put(memory,raw+0x10e0*i+0xbac,*actor->gauge_value);}
        a->category=std::uint8_t(category);a->slot=std::uint8_t(category?n:0);a->status=status;world.selected_actor=std::uint8_t(selected);world.mode=std::uint8_t(mode);world.paused=std::bit_cast<std::int8_t>(std::uint8_t(paused));world.room=std::uint16_t(n*17);world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));world.session().actor_message_suppression=std::uint16_t(suppression);
        memory[raw+2]=a->category;memory[raw+3]=a->slot;put(memory,raw+0xba0,status);memory[0x4baded]=world.selected_actor;memory[0x3243f2]=world.mode;memory[0x3243fb]=std::uint8_t(phase);memory[0x4badf8]=std::uint8_t(paused);put(memory,0x3243dc,world.room);put(memory,0x744638,std::uint16_t(suppression));ats::mapped=n%7?n*65521u:UINT32_MAX;callback=cb;messages.clear();lookups.clear();sink.speeches.clear();sink.lookups.clear();
        call(memory,0x67e230,{raw,0xabcd000bu});check(publisher.actor_message(id,u::ActorMessageSelector::speech)==u::PublicationStatus::completed);check(messages.size()==sink.speeches.size()&&lookups==sink.lookups);for(unsigned i=0;i<messages.size();++i)check(equal(messages[i],sink.speeches[i]));same(memory,raw,a->speech);check(a->status==get<unsigned>(memory,raw+0xba0)&&world.mode==memory[0x3243f2]&&world.session().actor_message_suppression==get<std::uint16_t>(memory,0x744638));actor_speech_messages+=unsigned(messages.size());actor_speech_lookups+=unsigned(lookups.size());++actor_speech_cases;
    };
    for(unsigned category:{0u,1u})for(unsigned mode=0;mode<4;++mode)for(unsigned n=0;n<65536;++n)run(n,category,mode,1+n%2,category?n%8:0,category?0x10000000u:0u,65535,0,n%17?0:1+n%4);
    for(unsigned n=0;n<65536;++n)run(n,n%4,n>>8,n,n%8,n%7?0x10000000u:4u,n,n%7?0:n,0);
    callback=0;a->category=0;a->slot=0;a->status=0;world.selected_actor=0;world.mode=1;world.paused=0;world.session().message_phase=1;world.session().actor_message_suppression=0;
    a->speech={};check(publisher.actor_message(id,u::ActorMessageSelector::speech)==u::PublicationStatus::unavailable&&!a->speech.gauge_notice);++actor_speech_refusals;
    a->speech.selection=g::SpeechSelection{};check(publisher.actor_message(id,u::ActorMessageSelector::speech)==u::PublicationStatus::unavailable);++actor_speech_refusals;a->speech.variant=0;a->gauge_value.reset();check(publisher.actor_message(id,u::ActorMessageSelector::speech)==u::PublicationStatus::unavailable&&!a->speech.gauge_notice);++actor_speech_refusals;
    a->gauge_value=UINT32_MAX;a->character=0;sink.available=false;check(publisher.actor_message(id,u::ActorMessageSelector::speech)==u::PublicationStatus::message_unavailable&&a->speech.gauge_notice==1);++actor_speech_refusals;sink.available=true;u::StatePublication absent(world,flags);check(absent.actor_message(id,u::ActorMessageSelector::speech)==u::PublicationStatus::message_unavailable);++actor_speech_refusals;
    ats::Sink old_sink(world);u::StatePublication old(world,flags,&old_sink);check(old.actor_message(id,u::ActorMessageSelector::speech)==u::PublicationStatus::message_unavailable);++actor_speech_refusals;a->category=1;a->status=0x10000000u;sink.lookup_available=false;check(publisher.actor_message(id,u::ActorMessageSelector::speech)==u::PublicationStatus::unavailable&&a->speech.gauge_notice==1);++actor_speech_refusals;
    actor_action_fixture::Notifications notifications;u::Owner owner(world,notifications,e::RuleBook::file1(),&sink);a->category=0;a->status=0;check(owner.record_actor_message(id,u::ActorMessageSelector::speech)==u::PublicationStatus::completed);++actor_speech_cases;
    check(owner.record_actor_message({},u::ActorMessageSelector::speech)==u::PublicationStatus::unavailable);++actor_speech_refusals;check(owner.close()==u::Status::completed&&owner.record_actor_message(id,u::ActorMessageSelector::speech)==u::PublicationStatus::unavailable);++actor_speech_refusals;check(world.close()==g::Status::completed&&publisher.actor_message(id,u::ActorMessageSelector::speech)==u::PublicationStatus::unavailable);++actor_speech_refusals;actor_speech_capture=false;
}
