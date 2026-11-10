unsigned room_release_cases{},room_release_messages{},room_hold_cases{},room_transition_cases{},room_control_refusals{},room_response_aliases{};
namespace actor_room_control_fixture {
namespace g=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;namespace ats=actor_status_fixture;
constexpr unsigned raw=0x4a5c30;
std::vector<u::RoomClaimReleaseMessage> messages;
struct RoomSink:ats::Sink {
    using ats::Sink::send;std::vector<u::RoomClaimReleaseMessage> releases;
    explicit RoomSink(g::World& w):ats::Sink(w){}
    bool send(const u::RoomClaimReleaseMessage& value)noexcept override{releases.push_back(value);return available;}
};
void same_messages(const RoomSink& sink){check(messages.size()==sink.releases.size());for(unsigned i=0;i<messages.size();++i){const auto& a=messages[i];const auto& b=sink.releases[i];check(a.route==b.route&&a.sender==b.sender&&a.room==b.room);}room_release_messages+=unsigned(messages.size());}
void seed(std::uint8_t* m,g::World& w,unsigned mode,unsigned selected,unsigned n){
    w.mode=std::uint8_t(mode);w.selected_actor=std::uint8_t(selected);w.paused=std::bit_cast<std::int8_t>(std::uint8_t(n));w.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(n>>8));w.session().actor_message_suppression=std::uint16_t(n);w.session().exit_requested=std::uint8_t(n*13);
    m[0x3243f2]=w.mode;m[0x4baded]=w.selected_actor;m[0x4badf8]=std::uint8_t(w.paused);m[0x3243fb]=std::uint8_t(w.session().message_phase);put(m,0x744638,w.session().actor_message_suppression);m[0x3243d8]=w.session().exit_requested;
}
}
void actor_room_control_port(std::uint8_t* m,R5900Context* c){
    using namespace actor_room_control_fixture;const auto p=GPR_U32(c,5);check(GPR_U32(c,4)==7&&!GPR_U32(c,6)&&m[p]==4&&m[p+1]==8&&m[p+3]==4&&m[p+4]==1&&m[p+2]==m[p+5]&&!m[p+7]);messages.push_back({c->pc==0x810960?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,m[p+5],m[p+6]});
}
void compare_actor_room_control(std::uint8_t* m){
    using namespace actor_room_control_fixture;room_control_capture=true;
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());for(unsigned i=0;i<8;++i){auto a=std::make_unique<g::Actor>();a->slot=std::uint8_t(i);check(bool(world.spawn_primary(i,std::move(a)).id));}const auto id=world.identity(0);const auto a=world.primary(0);reo::native::gameplay_scenario::FlagState flags;RoomSink sink(world);u::StatePublication publisher(world,flags,&sink);
    const auto release=[&](unsigned slot,unsigned room,unsigned mode,unsigned selected,unsigned n){
        seed(m,world,mode,selected,n);for(unsigned i=0;i<8;++i){world.primary(i)->room=std::uint16_t(room);put(m,raw+0x10e0*i+0x1e2,std::uint16_t(room));}messages.clear();sink.releases.clear();call(m,0x1b0010,{slot});check(publisher.release_actor_room(slot)==u::PublicationStatus::completed);same_messages(sink);check(world.session().exit_requested==m[0x3243d8]&&world.session().actor_message_suppression==get<std::uint16_t>(m,0x744638));++room_release_cases;
    };
    for(unsigned room=0;room<65536;++room)for(unsigned mode:{0u,1u})release(0,room,mode,0,room);
    for(unsigned n=0;n<65536;++n)release(n&255u,n*17u,n>>8,n>>10,n);
    for(unsigned n=0;n<65536;++n){
        seed(m,world,n>>8,n&255u,n);a->category=std::uint8_t(n%4);a->slot=std::uint8_t(n>>2);a->status=n*1664525u;a->response_lock=std::uint8_t(n*17);m[raw+2]=a->category;m[raw+3]=a->slot;put(m,raw+0xba0,a->status);m[raw+0xbd0]=a->response_lock;call(m,0x6696c0,{raw});check(g::begin_interaction_hold(world,id)&&a->status==get<unsigned>(m,raw+0xba0)&&a->response_lock==m[raw+0xbd0]&&world.session().exit_requested==m[0x3243d8]);++room_hold_cases;
    }
    for(unsigned n=0;n<65536;++n){
        seed(m,world,n>>8,(n>>4)%8,n);a->category=0;a->slot=std::uint8_t(n%8);a->primary=std::uint8_t(2+n%253);a->secondary=17;a->phase=18;a->subphase=19;a->status=n%2?0x80u:0u;a->response_lock=22;a->transient_action=std::uint8_t((n&255u)|1u);a->interaction_request=g::InteractionRequest{std::uint8_t(n%51),std::uint8_t(n),{1,2,3},4,5,6};a->saved_action_position={-1,-2,-3};a->saved_action_yaw=-4;
        for(unsigned i=0;i<8;++i){world.primary(i)->room=std::uint16_t((n>>3)+i);put(m,raw+0x10e0*i+0x1e2,world.primary(i)->room);}m[raw+2]=0;m[raw+3]=a->slot;m[raw+8]=a->primary;m[raw+9]=17;m[raw+10]=18;m[raw+11]=19;put(m,raw+0xba0,a->status);m[raw+0xbd0]=22;m[raw+0xab8]=a->transient_action;m[raw+0xab9]=a->interaction_request->kind;m[raw+0xaba]=std::uint8_t(n);put(m,raw+0xd94,a->saved_action_position);put(m,raw+0xda0,a->saved_action_yaw);messages.clear();sink.releases.clear();
        a->position={float(n),-float(n),float(n*2)};a->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(n));put(m,raw+0x38,a->position);put(m,raw+0x92,a->orientation[1]);
        const auto result=publisher.consume_interaction_request(id,0);if(result.status==g::InteractionTransitionStatus::unavailable){check(world.mode==0&&a->slot!=0&&!a->transient_action&&a->response_lock==0);++room_control_refusals;continue;}
        const auto original=call(m,0x64ef10,{raw,0});if(!(result.original_result==bool(original)&&a->transient_action==m[raw+0xab8]&&a->response_lock==m[raw+0xbd0]&&a->status==get<unsigned>(m,raw+0xba0)&&world.session().exit_requested==m[0x3243d8]))throw std::runtime_error("Room transition n="+std::to_string(n)+" return="+std::to_string(result.original_result)+"/"+std::to_string(original)+" pending="+std::to_string(a->response_lock)+"/"+std::to_string(m[raw+0xbd0])+" status="+std::to_string(a->status)+"/"+std::to_string(get<unsigned>(m,raw+0xba0))+" notice="+std::to_string(world.session().exit_requested)+"/"+std::to_string(m[0x3243d8]));check(result.original_result==bool(original)&&a->transient_action==m[raw+0xab8]&&a->response_lock==m[raw+0xbd0]&&a->status==get<unsigned>(m,raw+0xba0)&&world.session().exit_requested==m[0x3243d8]);check(a->primary==m[raw+8]&&a->secondary==m[raw+9]&&a->phase==m[raw+10]&&a->subphase==m[raw+11]&&std::memcmp(&a->saved_action_position,m+raw+0xd94,12)==0&&a->saved_action_yaw==get<std::int16_t>(m,raw+0xda0));same_messages(sink);++room_transition_cases;
    }
    // The script/control producer and hit consumer share the actual BD0 byte.
    for(unsigned n=0;n<256;++n){
        seed(m,world,1,0,n);world.paused=0;world.session().suppress_hits=false;m[0x4badf8]=0;m[0x4bae8d]=0;a->category=0;a->slot=0;a->status=0;a->special_kind=0;a->source_kind=0;a->pending_hit=1;a->notice_flags=std::uint8_t(n);a->transient_action=31;
        check(reo::native::gameplay_scenario::queue_actor_request(world,5,n)==reo::native::gameplay_scenario::ActorRequestStatus::completed&&reo::native::gameplay_scenario::consume_actor_request(*a,world.session())==reo::native::gameplay_scenario::ActorRequestStatus::completed&&a->response_lock==1&&!a->transient_equipment);
        m[raw+2]=0;put(m,raw+0xba0,0u);m[raw+0x150]=0;m[raw+0x148]=0;m[raw+0x13f]=1;m[raw+0x115]=std::uint8_t(n);m[raw+0xbd0]=1;m[raw+0xab8]=31;call(m,0x660af0,{raw});hit_gauge_fixture::Behavior behavior(world,*a);g::actors::consume_pending_hit(*a,world.session(),behavior,{});check(!a->pending_hit&&a->pending_hit==m[raw+0x13f]&&a->notice_flags==m[raw+0x115]&&a->response_lock==m[raw+0xbd0]&&a->transient_action==m[raw+0xab8]&&behavior.calls.empty());++room_response_aliases;
    }
    seed(m,world,0,0,0);a->room=0;sink.available=false;check(publisher.release_actor_room(0)==u::PublicationStatus::message_unavailable);++room_control_refusals;sink.available=true;u::StatePublication absent(world,flags);check(absent.release_actor_room(0)==u::PublicationStatus::message_unavailable);++room_control_refusals;
    a->category=0;a->slot=0;a->primary=2;a->status=0;a->response_lock=22;a->transient_action=1;a->interaction_request=g::InteractionRequest{1,0,{1,2,3},4,5,6};check(absent.consume_interaction_request(id,0).status==g::InteractionTransitionStatus::unavailable&&!a->transient_action&&!a->response_lock&&(a->status&0x10000u)&&world.session().exit_requested==1);++room_control_refusals;
    world.mode=1;a->category=1;world.session().exit_requested=177;check(g::begin_interaction_hold(world,id)&&world.session().exit_requested==177);++room_hold_cases;
    check(!g::begin_interaction_hold(world,{}));++room_control_refusals;check(world.retire_primary(0)==g::actors::EntityStatus::completed&&publisher.release_actor_room(0)==u::PublicationStatus::unavailable);++room_control_refusals;
    check(world.close()==g::Status::completed&&!g::begin_interaction_hold(world,id)&&publisher.release_actor_room(0)==u::PublicationStatus::unavailable);++room_control_refusals;room_control_capture=false;
}
