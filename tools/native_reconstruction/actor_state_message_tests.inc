unsigned actor_state_cases{},actor_state_messages{},actor_state_lookups{},actor_state_refusals{},actor_gauge_cases{},actor_state_class_cases{},actor_periodic_cases{},actor_clock_cases{};
namespace actor_state_fixture {
namespace ats=actor_status_fixture;namespace act=actor_action_fixture;
namespace u=reo::native::gameplay_update;namespace g=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;
std::vector<u::ActorStateMessage> source_messages;bool nested_payload{};
bool equal(const u::ActorStateMessage& a,const u::ActorStateMessage& b){return a.route==b.route&&a.channel==b.channel&&a.status==b.status&&a.yaw==b.yaw&&a.gauge_band==b.gauge_band&&std::bit_cast<unsigned>(a.position.x)==std::bit_cast<unsigned>(b.position.x)&&std::bit_cast<unsigned>(a.position.y)==std::bit_cast<unsigned>(b.position.y)&&std::bit_cast<unsigned>(a.position.z)==std::bit_cast<unsigned>(b.position.z);}
void mutate(g::Actor& actor){actor.position={-11,22,-33};actor.orientation[1]=-456;actor.gauge_value=0;actor.character=7;}
struct Sink:ats::Sink {
    using ats::Sink::send;std::vector<u::ActorStateMessage> states;
    explicit Sink(g::World& world):ats::Sink(world){}
    bool send(const u::ActorStateMessage& value)noexcept override{states.push_back(value);return available;}
    std::optional<unsigned> room_owner(u::MessageRoute route,std::uint16_t room)noexcept override{const auto result=ats::Sink::room_owner(route,room);if(nested_payload)mutate(*world.primary(0));return result;}
};
float call_percentage(std::uint8_t* memory){R5900Context context;context.pc=0x667f90;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);PS2Runtime runtime;original_transform_port(memory,&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);return context.f[0];}
}
void actor_state_message_port(std::uint8_t* memory,R5900Context* context){
    using namespace actor_state_fixture;const auto at=GPR_U32(context,5);check(memory[at]==2&&memory[at+1]==24&&!memory[at+2]&&!memory[at+3]&&!GPR_U32(context,6)&&GPR_U32(context,7)==2);
    source_messages.push_back({context->pc==0x811190?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,GPR_U32(context,4),{get<float>(memory,at+4),get<float>(memory,at+8),get<float>(memory,at+12)},get<unsigned>(memory,at+16),get<std::int16_t>(memory,at+20),memory[at+22]});
}
void actor_state_room_owner_port(std::uint8_t* memory,R5900Context* context){
    using namespace actor_state_fixture;actor_room_owner_port(memory,context);if(nested_payload){put(memory,0x4a5c30+0x38,-11.f);put(memory,0x4a5c30+0x3c,22.f);put(memory,0x4a5c30+0x40,-33.f);put(memory,0x4a5c30+0x92,std::int16_t(-456));put(memory,0x4a5c30+0xbac,0u);memory[0x4a5c30+0xb98]=7;}
}
void compare_actor_state_messages(std::uint8_t* memory,const char* tables){
    using namespace actor_state_fixture;actor_state_capture=true;ats::nested=0;nested_payload=false;
    std::ifstream input(tables,std::ios::binary);input.seekg(104);input.read(reinterpret_cast<char*>(memory+0x71adb0),32);check(bool(input));check(std::memcmp(g::actor_gauge_limits.data(),memory+0x71adb0,32)==0);
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());for(unsigned i=0;i<8;++i){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(i);check(bool(world.spawn_primary(i,std::move(actor)).id));}s::FlagState flags;Sink sink(world);u::StatePublication publisher(world,flags,&sink);const auto id=world.identity(0);const auto actor=world.primary(0);
    for(unsigned primary=0;primary<256;++primary)for(unsigned secondary=0;secondary<256;++secondary){actor->primary=std::uint8_t(primary);actor->secondary=std::uint8_t(secondary);memory[0x4a5c30+8]=actor->primary;memory[0x4a5c30+9]=actor->secondary;check(call(memory,0x664d00,{0x4a5c30})==unsigned(g::state_message_classified(*actor)));++actor_state_class_cases;}
    const auto gauge=[&](unsigned selected,unsigned character,unsigned value){world.selected_actor=std::uint8_t(selected);memory[0x4baded]=std::uint8_t(selected);const auto target=world.primary(selected);target->character=std::uint8_t(character);target->gauge_value=value;memory[0x4a5c30+0x10e0*selected+0xb98]=std::uint8_t(character);put(memory,0x4a5c30+0x10e0*selected+0xbac,value);const auto native=g::selected_gauge_percentage(world);check(native&&std::bit_cast<unsigned>(*native)==std::bit_cast<unsigned>(call_percentage(memory)));check(g::selected_gauge_band(world)==call(memory,0x668c80));++actor_gauge_cases;};
    // Every low16-bit value, a dispersed full unsigned domain, rounding points
    // above2^31 and every stock percentage threshold, for all eight characters.
    for(unsigned character=0;character<8;++character){
        for(unsigned n=0;n<65536;++n){gauge((n+character)%8,character,n);gauge((n+character)%8,character,n*1664525u+1013904223u);}
        for(unsigned value:{0x7fffffffu,0x80000000u,0x80000001u,0x8000007fu,0x80000080u,0x80000081u,0xffffff7fu,0xffffff80u,0xffffffffu})gauge(character,character,value);
        for(unsigned threshold:{50u,80u,90u})for(int delta=-9;delta<=9;++delta)gauge(character,character,g::actor_gauge_limits[character]*threshold/100+unsigned(delta));
    }
    const auto run=[&](bool periodic,unsigned n,unsigned mode,unsigned phase,unsigned category,unsigned slot,unsigned selected,unsigned status,unsigned suppression,unsigned pause,unsigned primary,unsigned secondary,unsigned tick,unsigned callback){
        actor->category=std::uint8_t(category);actor->slot=std::uint8_t(slot);actor->status=status;actor->primary=std::uint8_t(primary);actor->secondary=std::uint8_t(secondary);actor->position={std::bit_cast<float>(n*1664525u),std::bit_cast<float>(n*1013904223u),std::bit_cast<float>(n*65521u)};actor->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(n));world.mode=std::uint8_t(mode);world.paused=std::bit_cast<std::int8_t>(std::uint8_t(pause));world.selected_actor=std::uint8_t(selected);world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));world.session().actor_message_suppression=std::uint16_t(suppression);world.session().feedback_suppressed=std::uint8_t(tick);world.room=std::uint16_t(n*17);
        // Message slot may differ from the selected gauge owner. Supply every
        // admitted primary; never silently read a default gauge of zero.
        for(unsigned i=0;i<8;++i){const auto target=world.primary(i);target->character=std::uint8_t((n+i)%8);target->gauge_value=(n+i)*65521u;memory[0x4a5c30+0x10e0*i+0xb98]=target->character;put(memory,0x4a5c30+0x10e0*i+0xbac,*target->gauge_value);}
        memory[0x4a5c30+2]=actor->category;memory[0x4a5c30+3]=actor->slot;memory[0x4a5c30+8]=actor->primary;memory[0x4a5c30+9]=actor->secondary;put(memory,0x4a5c30+0xba0,status);put(memory,0x4a5c30+0x38,actor->position.x);put(memory,0x4a5c30+0x3c,actor->position.y);put(memory,0x4a5c30+0x40,actor->position.z);put(memory,0x4a5c30+0x92,actor->orientation[1]);memory[0x3243f2]=world.mode;memory[0x3243fb]=std::uint8_t(phase);memory[0x4baded]=world.selected_actor;memory[0x4badf8]=std::uint8_t(pause);memory[0x4bae03]=std::uint8_t(tick);put(memory,0x744638,std::uint16_t(suppression));put(memory,0x3243dc,world.room);
        ats::mapped=n%7?n*65521u:UINT32_MAX;ats::nested=callback;nested_payload=callback!=0;source_messages.clear();ats::source_lookups.clear();sink.states.clear();sink.lookups.clear();call(memory,periodic?0x664f60:0x67e230,{0x4a5c30,0xabcd0002u});check((periodic?publisher.periodic_actor_state(id):publisher.actor_message(id,u::ActorMessageSelector::state))==u::PublicationStatus::completed);check(source_messages.size()==sink.states.size()&&ats::source_lookups==sink.lookups&&actor->status==get<unsigned>(memory,0x4a5c30+0xba0)&&world.mode==memory[0x3243f2]);for(unsigned i=0;i<sink.states.size();++i)check(equal(source_messages[i],sink.states[i]));check(std::bit_cast<unsigned>(actor->position.x)==get<unsigned>(memory,0x4a5c30+0x38)&&actor->orientation[1]==get<std::int16_t>(memory,0x4a5c30+0x92));actor_state_messages+=unsigned(sink.states.size());actor_state_lookups+=unsigned(sink.lookups.size());if(periodic)++actor_periodic_cases;else ++actor_state_cases;
    };
    for(unsigned n=0;n<65536;++n)run(false,n,n>>8,n,n%4,n,n%8,n%5?0x10000000u:n*1664525u,n,n%7?0:n,n>>8,n,n,0);
    for(unsigned category:{0u,1u})for(unsigned mode=0;mode<4;++mode)for(unsigned n=0;n<65536;++n)run(false,n,mode,1+n%2,category,0,category?n%8:0,(n%17?0x10000000u:0x10000004u)|(n%2?0x08000000u:0u),n%19?65535:2,0,n%11?1:2,n,n,n%23?0:1+n%4);
    // Exhaust both byte domains at valid gates; do not round the game clock
    // to a host timer or infer this from presented frame counts.
    for(unsigned tick=0;tick<256;++tick)for(unsigned state=0;state<256;++state)run(true,65536*tick+state,tick%2,1,0,0,0,0,65535,0,1,state,tick,0);
    for(unsigned n=0;n<65536;++n)run(true,n,n>>8,n,n%4,n,n%8,n%5?0x10000000u:n*1664525u,n,n%7?0:n,n>>8,n,30,0);
    ats::nested=0;nested_payload=false;world.mode=0;world.paused=0;world.session().message_phase=1;world.session().actor_message_suppression=65535;world.selected_actor=0;actor->slot=0;actor->category=0;actor->primary=1;actor->secondary=0;actor->status=0;actor->character=0;actor->gauge_value.reset();
    check(publisher.actor_message(id,u::ActorMessageSelector::state)==u::PublicationStatus::unavailable&&actor->status==0x08000000u);++actor_state_refusals;
    actor->gauge_value=0;actor->character=8;check(!g::selected_gauge_percentage(world)&&publisher.actor_message(id,u::ActorMessageSelector::state)==u::PublicationStatus::unavailable);++actor_state_refusals;
    actor->character=0;world.selected_actor=8;actor->category=1;actor->status=0x10000000;check(publisher.actor_message(id,u::ActorMessageSelector::state)==u::PublicationStatus::unavailable&&actor->status==0x18000000);++actor_state_refusals;
    world.selected_actor=0;actor->category=0;actor->primary=2;u::StatePublication missing(world,flags);check(missing.actor_message(id,u::ActorMessageSelector::state)==u::PublicationStatus::message_unavailable&&actor->status==0x10000000);++actor_state_refusals;
    sink.available=false;check(publisher.actor_message(id,u::ActorMessageSelector::state)==u::PublicationStatus::message_unavailable);++actor_state_refusals;sink.available=true;actor->category=1;sink.lookup_available=false;check(publisher.actor_message(id,u::ActorMessageSelector::state)==u::PublicationStatus::unavailable);++actor_state_refusals;sink.lookup_available=true;
    world.session().feedback_suppressed=1;check(publisher.periodic_actor_state({})==u::PublicationStatus::completed);world.session().feedback_suppressed=0;check(publisher.periodic_actor_state({})==u::PublicationStatus::unavailable);++actor_state_refusals;
    // Bind the real update clock, deliberately contradict its old standalone
    // byte, and run every valid subsecond through the actual Owner facade.
    act::Notifications notifications;u::Owner update(world,notifications,e::RuleBook::file1(),&sink);actor->category=0;actor->status=0;actor->primary=1;actor->secondary=0;
    for(unsigned tick=0;tick<60;++tick){check(update.clock().restore({0,0,0,std::uint8_t(tick)},0)==u::tasks::Status::completed);world.session().feedback_suppressed=std::uint8_t(tick%30?0:1);sink.states.clear();check(update.record_periodic_actor_state(id)==u::PublicationStatus::completed&&sink.states.size()==unsigned(tick%30==0));++actor_clock_cases;}
    check(update.close()==u::Status::completed&&update.record_periodic_actor_state(id)==u::PublicationStatus::unavailable);++actor_state_refusals;check(world.close()==g::Status::completed&&!g::selected_gauge_percentage(world)&&publisher.periodic_actor_state(id)==u::PublicationStatus::unavailable&&publisher.actor_message(id,u::ActorMessageSelector::state)==u::PublicationStatus::unavailable);++actor_state_refusals;actor_state_capture=false;
}
