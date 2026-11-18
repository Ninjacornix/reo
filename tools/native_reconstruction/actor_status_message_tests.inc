unsigned actor_status_cases{},actor_status_messages{},actor_status_lookups{},actor_status_refusals{};
namespace actor_status_fixture {
namespace u=reo::native::gameplay_update;
namespace g=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
std::vector<u::ActorStatusMessage> source_messages;
struct Lookup {u::MessageRoute route;std::uint16_t room;friend bool operator==(const Lookup&,const Lookup&)=default;};
std::vector<Lookup> source_lookups;unsigned mapped{},nested{};
bool equal(const u::ActorStatusMessage& a,const u::ActorStatusMessage& b){return a.route==b.route&&a.channel==b.channel&&a.status==b.status&&a.health==b.health;}
struct Sink:u::GameplayMessageSink {
    g::World& world;std::vector<u::ActorStatusMessage> messages;std::vector<Lookup> lookups;bool available{true},lookup_available{true};
    explicit Sink(g::World& w):world(w){}
    bool send(const u::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const u::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const u::ResourcePositionMessage&)noexcept override{return false;}
    bool send(const u::ActorStatusMessage& value)noexcept override{messages.push_back(value);return available;}
    std::optional<unsigned> room_owner(u::MessageRoute route,std::uint16_t room)noexcept override{
        lookups.push_back({route,room});if(nested){world.mode=std::uint8_t(nested-1);world.primary(0)->current=-123;world.primary(0)->status=0x12345678;}
        if(!lookup_available)return{};
        return mapped;
    }
};
}
void actor_status_message_port(std::uint8_t* memory,R5900Context* context){
    using namespace actor_status_fixture;const auto at=GPR_U32(context,5);check(memory[at]==14&&memory[at+1]==12&&memory[at+2]==0&&memory[at+3]==0&&GPR_U32(context,6)==0&&GPR_U32(context,7)==4);
    source_messages.push_back({context->pc==0x811190?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,GPR_U32(context,4),get<unsigned>(memory,at+4),get<std::int16_t>(memory,at+8)});
}
void actor_room_owner_port(std::uint8_t* memory,R5900Context* context){
    using namespace actor_status_fixture;source_lookups.push_back({context->pc==0x811d40?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,std::uint16_t(GPR_U32(context,4))});
    if(nested){memory[0x3243f2]=std::uint8_t(nested-1);put(memory,0x4a5c30+0x544,std::int16_t(-123));put(memory,0x4a5c30+0xba0,0x12345678u);}SET_GPR_U32(context,2,mapped);
}
void compare_actor_status_messages(std::uint8_t* memory,const char* tables){
    using namespace actor_status_fixture;std::ifstream input(tables,std::ios::binary);input.read(reinterpret_cast<char*>(memory+0x740710),64);input.read(reinterpret_cast<char*>(memory+0x740340),40);check(bool(input));
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(id));s::FlagState flags;Sink sink(world);u::StatePublication publisher(world,flags,&sink);
    const auto run=[&](bool clear,unsigned n,unsigned mode,unsigned phase,unsigned category,unsigned slot,unsigned selected,unsigned status,unsigned selector,unsigned suppression,unsigned pause,unsigned callback){
        auto actor=world.primary(0);actor->current=std::bit_cast<std::int16_t>(std::uint16_t(n*65521));actor->maximum=std::bit_cast<std::int16_t>(std::uint16_t(n*16645));actor->status=status;actor->category=std::uint8_t(category);actor->slot=std::uint8_t(slot);world.mode=std::uint8_t(mode);world.selected_actor=std::uint8_t(selected);world.paused=std::bit_cast<std::int8_t>(std::uint8_t(pause));world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));world.session().actor_message_suppression=std::uint16_t(suppression);world.room=std::uint16_t(n*17);
        put(memory,0x4a5c30+0x544,actor->current);put(memory,0x4a5c30+0x546,actor->maximum);put(memory,0x4a5c30+0xba0,status);memory[0x4a5c30+2]=actor->category;memory[0x4a5c30+3]=actor->slot;memory[0x3243f2]=world.mode;memory[0x3243fb]=std::uint8_t(phase);memory[0x4badf8]=std::uint8_t(pause);memory[0x4baded]=world.selected_actor;put(memory,0x744638,std::uint16_t(suppression));put(memory,0x3243dc,world.room);mapped=n*65521u;nested=callback;source_messages.clear();source_lookups.clear();sink.messages.clear();sink.lookups.clear();
        call(memory,clear?0x6605b0:0x67e230,{0x4a5c30,clear?selector:0xabcd000eu});if(clear)g::actors::clear_status_fields(*actor,selector);check(publisher.actor_status(id)==u::PublicationStatus::completed);
        check(actor->current==get<std::int16_t>(memory,0x4a5c30+0x544)&&actor->maximum==get<std::int16_t>(memory,0x4a5c30+0x546)&&actor->status==get<unsigned>(memory,0x4a5c30+0xba0)&&world.mode==memory[0x3243f2]);check(world.session().actor_message_suppression==get<std::uint16_t>(memory,0x744638));check(source_lookups==sink.lookups&&source_messages.size()==sink.messages.size());
        for(unsigned i=0;i<sink.messages.size();++i)check(equal(source_messages[i],sink.messages[i]));
        actor_status_messages+=unsigned(sink.messages.size());actor_status_lookups+=unsigned(sink.lookups.size());++actor_status_cases;
    };
    // All phase/mode pairs, arbitrary pause bytes, all clear selector bytes and
    // complete signed health/maximum domains without emulating a native arena.
    for(bool clear:{false,true})for(unsigned n=0;n<65536;++n)run(clear,n,n>>8,n,n%3,n>>8,n>>8,n%5?0x10000000u:(n*1664525u),n*65521u,n,n%7?0:n,0);
    // Ensure message-eligible combinations are dense, including status4 gate,
    // primary/nonlocal authority, room mapping, suppression14 and callback mode.
    for(bool clear:{false,true})for(unsigned category=0;category<4;++category)for(unsigned mode=0;mode<4;++mode)for(unsigned n=0;n<4096;++n)run(clear,n,mode,1+n%2,category,n%7?0:n%256,n%11?0:1,(n%5?0x10000000u:0)|(n%17?0:4u)|(n%13?3u:0u),n*65521u,n%19?0:14,0,n%23?0:1+n%4);
    // Primary slot and selected identities are bytes; slot255 publishes to
    // integer channel256 rather than wrapping it to zero.
    for(unsigned n=0;n<65536;++n)run(false,n,n%2,1,0,n%256,n>>8,0,0,0,0,0);
    nested=0;auto actor=world.primary(0);world.mode=0;world.paused=0;world.session().message_phase=1;world.session().actor_message_suppression=0;world.selected_actor=0;actor->slot=0;actor->category=0;actor->status=0;
    u::StatePublication missing(world,flags);check(missing.actor_status(id)==u::PublicationStatus::message_unavailable);++actor_status_refusals;
    sink.available=false;check(publisher.actor_status(id)==u::PublicationStatus::message_unavailable);++actor_status_refusals;sink.available=true;
    actor->category=1;actor->status=0x10000000;sink.lookup_available=false;check(publisher.actor_status(id)==u::PublicationStatus::unavailable);++actor_status_refusals;sink.lookup_available=true;
    check(publisher.actor_status({})==u::PublicationStatus::unavailable);++actor_status_refusals;
    world.session().message_phase=0;check(missing.actor_status({})==u::PublicationStatus::completed);++actor_status_refusals;
    world.session().message_phase=1;check(world.retire_primary(0)==g::actors::EntityStatus::completed&&publisher.actor_status(id)==u::PublicationStatus::unavailable);++actor_status_refusals;
    check(world.close()==g::Status::completed&&publisher.actor_status(id)==u::PublicationStatus::unavailable);++actor_status_refusals;
}
