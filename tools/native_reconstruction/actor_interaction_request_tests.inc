unsigned actor_request_cases{},actor_request_messages{},actor_request_lookups{},actor_request_refusals{};
namespace actor_request_fixture {
namespace g=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;namespace ats=actor_status_fixture;
constexpr unsigned raw=0x4a5c30;
std::vector<u::ActorInteractionRequestMessage> messages;std::vector<ats::Lookup> lookups;unsigned callback{};
void write(std::uint8_t* m,unsigned at,const g::Actor& a){
    check(bool(a.interaction_request));const auto& r=*a.interaction_request;m[at+0xab8]=a.transient_action;m[at+0xab9]=r.kind;m[at+0xaba]=r.parameter;m[at+0xabb]=std::uint8_t(a.scene_model.encoded());put(m,at+0xabc,r.anchor);put(m,at+0xac8,r.orientation);put(m,at+0xacc,r.travel_distance);m[at+0xad0]=r.endpoint;
}
void same(std::uint8_t* m,unsigned at,const g::Actor& a){
    check(bool(a.interaction_request));const auto& r=*a.interaction_request;check(a.transient_action==m[at+0xab8]&&r.kind==m[at+0xab9]&&r.parameter==m[at+0xaba]&&a.scene_model.encoded()==m[at+0xabb]);check(std::memcmp(&r.anchor,m+at+0xabc,12)==0&&r.orientation==get<unsigned>(m,at+0xac8)&&std::bit_cast<unsigned>(r.travel_distance)==get<unsigned>(m,at+0xacc)&&r.endpoint==m[at+0xad0]);
}
bool equal(const u::ActorInteractionRequestMessage& a,const u::ActorInteractionRequestMessage& b){return a.route==b.route&&a.channel==b.channel&&a.pending==b.pending&&a.scene_model==b.scene_model&&a.request.kind==b.request.kind&&a.request.parameter==b.request.parameter&&std::memcmp(&a.request.anchor,&b.request.anchor,12)==0&&a.request.orientation==b.request.orientation&&std::bit_cast<unsigned>(a.request.travel_distance)==std::bit_cast<unsigned>(b.request.travel_distance)&&a.request.endpoint==b.request.endpoint;}
void mutate(g::Actor& a){a.transient_action=11;a.scene_model=12;a.interaction_request=g::InteractionRequest{13,14,{-15,16,-17},18,-19,20};}
struct RequestSink:ats::Sink {
    using ats::Sink::send;std::vector<u::ActorInteractionRequestMessage> requests;
    explicit RequestSink(g::World& w):ats::Sink(w){}
    bool send(const u::ActorInteractionRequestMessage& value)noexcept override{requests.push_back(value);return available;}
    std::optional<unsigned> room_owner(u::MessageRoute route,std::uint16_t room)noexcept override{lookups.push_back({route,room});if(callback){world.mode=std::uint8_t(callback-1);mutate(*world.primary(0));}return lookup_available?std::optional<unsigned>{ats::mapped}:std::nullopt;}
};
}
void actor_request_message_port(std::uint8_t* m,R5900Context* c){
    using namespace actor_request_fixture;const auto p=GPR_U32(c,5);check(m[p]==3&&m[p+1]==32&&!m[p+2]&&!m[p+3]&&!GPR_U32(c,6)&&GPR_U32(c,7)==4);
    messages.push_back({c->pc==0x811190?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,GPR_U32(c,4),m[p+4],m[p+7],{m[p+5],m[p+6],get<g::Position>(m,p+8),get<unsigned>(m,p+20),get<float>(m,p+24),m[p+28]}});
}
void actor_request_room_port(std::uint8_t* m,R5900Context* c){using namespace actor_request_fixture;lookups.push_back({c->pc==0x811d40?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,std::uint16_t(GPR_U32(c,4))});SET_GPR_U32(c,2,ats::mapped);if(callback){m[0x3243f2]=std::uint8_t(callback-1);g::Actor a;mutate(a);write(m,raw,a);}}
void compare_actor_interaction_requests(std::uint8_t* memory){
    using namespace actor_request_fixture;actor_request_capture=true;
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(id));const auto a=world.primary(0);reo::native::gameplay_scenario::FlagState flags;RequestSink sink(world);u::StatePublication publisher(world,flags,&sink);
    const auto run=[&](unsigned n,unsigned category,unsigned mode,unsigned phase,unsigned selected,unsigned status,unsigned suppression,unsigned paused,unsigned cb){
        a->transient_action=std::uint8_t(n*17);a->scene_model=n%128;a->interaction_request=g::InteractionRequest{std::uint8_t(n),std::uint8_t(n>>8),{std::bit_cast<float>(n*1664525u),std::bit_cast<float>(n*1013904223u),std::bit_cast<float>(n*65521u)},n*1664525u,std::bit_cast<float>(n*22695477u),std::uint8_t(n*31)};write(memory,raw,*a);for(unsigned i=1;i<4;++i)memory[raw+0xad0+i]=std::uint8_t(n*13+i);
        a->category=std::uint8_t(category);a->slot=std::uint8_t(category?n:0);a->status=status;a->gauge_value.reset();world.selected_actor=std::uint8_t(selected);world.mode=std::uint8_t(mode);world.paused=std::bit_cast<std::int8_t>(std::uint8_t(paused));world.room=std::uint16_t(n*17);world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));world.session().actor_message_suppression=std::uint16_t(suppression);
        memory[raw+2]=a->category;memory[raw+3]=a->slot;put(memory,raw+0xba0,status);memory[0x4baded]=world.selected_actor;memory[0x3243f2]=world.mode;memory[0x3243fb]=std::uint8_t(phase);memory[0x4badf8]=std::uint8_t(paused);put(memory,0x3243dc,world.room);put(memory,0x744638,std::uint16_t(suppression));ats::mapped=n%7?n*65521u:UINT32_MAX;callback=cb;messages.clear();lookups.clear();sink.requests.clear();sink.lookups.clear();
        call(memory,0x67e230,{raw,0xabcd0003u});check(publisher.actor_message(id,u::ActorMessageSelector::interaction_request)==u::PublicationStatus::completed);check(messages.size()==sink.requests.size()&&lookups==sink.lookups);for(unsigned i=0;i<messages.size();++i)check(equal(messages[i],sink.requests[i]));same(memory,raw,*a);check(a->status==get<unsigned>(memory,raw+0xba0)&&world.mode==memory[0x3243f2]&&world.session().actor_message_suppression==get<std::uint16_t>(memory,0x744638)&&!a->gauge_value);for(unsigned i=1;i<4;++i)check(memory[raw+0xad0+i]==std::uint8_t(n*13+i));actor_request_messages+=unsigned(messages.size());actor_request_lookups+=unsigned(lookups.size());++actor_request_cases;
    };
    for(unsigned category:{0u,1u})for(unsigned mode=0;mode<4;++mode)for(unsigned n=0;n<65536;++n)run(n,category,mode,1+n%2,category?1:0,category?0x10000000u:0u,65535,0,n%17?0:1+n%4);
    for(unsigned n=0;n<65536;++n)run(n,n%4,n>>8,n,n%8,n%7?0x10000000u:4u,n,n%7?0:n,0);
    callback=0;a->category=0;a->slot=0;a->status=0;world.selected_actor=0;world.mode=1;world.paused=0;world.session().message_phase=1;world.session().actor_message_suppression=0;a->interaction_request.reset();check(publisher.actor_message(id,u::ActorMessageSelector::interaction_request)==u::PublicationStatus::unavailable);++actor_request_refusals;
    mutate(*a);for(unsigned model:{128u,254u,255u,256u}){a->scene_model=model;check(publisher.actor_message(id,u::ActorMessageSelector::interaction_request)==u::PublicationStatus::unavailable);}++actor_request_refusals;a->scene_model=127;sink.available=false;check(publisher.actor_message(id,u::ActorMessageSelector::interaction_request)==u::PublicationStatus::message_unavailable);++actor_request_refusals;sink.available=true;
    u::StatePublication absent(world,flags);check(absent.actor_message(id,u::ActorMessageSelector::interaction_request)==u::PublicationStatus::message_unavailable);++actor_request_refusals;ats::Sink old_sink(world);u::StatePublication old(world,flags,&old_sink);check(old.actor_message(id,u::ActorMessageSelector::interaction_request)==u::PublicationStatus::message_unavailable);++actor_request_refusals;a->category=1;a->status=0x10000000u;sink.lookup_available=false;check(publisher.actor_message(id,u::ActorMessageSelector::interaction_request)==u::PublicationStatus::unavailable);++actor_request_refusals;
    actor_action_fixture::Notifications notifications;u::Owner owner(world,notifications,e::RuleBook::file1(),&sink);a->category=0;a->status=0;check(owner.record_actor_message(id,u::ActorMessageSelector::interaction_request)==u::PublicationStatus::completed);++actor_request_cases;check(owner.record_actor_message({},u::ActorMessageSelector::interaction_request)==u::PublicationStatus::unavailable);++actor_request_refusals;
    check(owner.close()==u::Status::completed&&owner.record_actor_message(id,u::ActorMessageSelector::interaction_request)==u::PublicationStatus::unavailable);++actor_request_refusals;check(world.close()==g::Status::completed&&publisher.actor_message(id,u::ActorMessageSelector::interaction_request)==u::PublicationStatus::unavailable);++actor_request_refusals;actor_request_capture=false;
}
