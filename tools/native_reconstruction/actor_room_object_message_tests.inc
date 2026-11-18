unsigned room_object_message_cases{},room_object_messages{},room_object_message_lookups{},room_object_message_refusals{};
namespace room_object_message_fixture {
namespace g=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;namespace ro=reo::native::gameplay_collision::room_objects;namespace ats=actor_status_fixture;
constexpr unsigned raw=0x4a5c30;
std::vector<u::ActorRoomObjectMessage> messages;std::vector<ats::Lookup> lookups;unsigned callback{},seed{},placement_count{};
std::array<std::int8_t,2> coordinates(unsigned n,unsigned slot,unsigned count){return slot&&slot<=count?std::array<std::int8_t,2>{std::bit_cast<std::int8_t>(std::uint8_t(n+17*(slot-1))),std::bit_cast<std::int8_t>(std::uint8_t((n>>8)+29*(slot-1)))}:std::array<std::int8_t,2>{};}
ro::Owner make(unsigned n,unsigned count){
    std::vector<std::byte> types(24),placements(8+count*16);
    const auto word=[](auto& bytes,unsigned at,unsigned value){for(unsigned i=0;i<4;++i)bytes[at+i]=std::byte(std::uint8_t(value>>(8*i)));};
    word(types,4,1);word(types,8,16);types[17]=std::byte{1};word(placements,0,2);word(placements,4,count);
    for(unsigned slot=1;slot<=count;++slot){const auto at=8+16*(slot-1);const auto cell=coordinates(n,slot,count);placements[at]=std::byte{1};placements[at+1]=std::byte(slot);placements[at+3]=std::byte(std::uint8_t(cell[0]));placements[at+4]=std::byte(std::uint8_t(cell[1]));placements[at+6]=std::byte{15};}
    return ro::Owner::import(types,placements);
}
void source_coordinates(std::uint8_t* memory,unsigned n,unsigned count){for(unsigned slot=0;slot<32;++slot){const auto cell=coordinates(n,slot,count);memory[0x3c4598+60*slot]=std::uint8_t(cell[0]);memory[0x3c4599+60*slot]=std::uint8_t(cell[1]);}}
bool equal(const u::ActorRoomObjectMessage& a,const u::ActorRoomObjectMessage& b){return a.route==b.route&&a.channel==b.channel&&a.grid==b.grid&&a.coordinates==b.coordinates;}
struct RoomObjectSink:ats::Sink {
    using ats::Sink::send;ro::Owner& objects;std::vector<u::ActorRoomObjectMessage> object_messages;
    RoomObjectSink(g::World& w,ro::Owner& o):ats::Sink(w),objects(o){}
    bool send(const u::ActorRoomObjectMessage& message)noexcept override{object_messages.push_back(message);return available;}
    std::optional<unsigned> room_owner(u::MessageRoute route,std::uint16_t room)noexcept override{
        lookups.push_back({route,room});if(callback){world.mode=std::uint8_t(callback-1);world.primary(0)->grid=std::uint8_t((world.primary(0)->grid+1)%32);objects=make(seed^0xa5a5u,placement_count);}return lookup_available?std::optional<unsigned>{ats::mapped}:std::nullopt;
    }
};
}
void actor_room_object_message_port(std::uint8_t* memory,R5900Context* c){
    using namespace room_object_message_fixture;const auto at=GPR_U32(c,5);check(memory[at]==9&&memory[at+1]==8&&!memory[at+2]&&!memory[at+3]&&!GPR_U32(c,6)&&GPR_U32(c,7)==4);
    messages.push_back({c->pc==0x811190?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,GPR_U32(c,4),memory[at+4],{std::bit_cast<std::int8_t>(memory[at+5]),std::bit_cast<std::int8_t>(memory[at+6])}});
}
void actor_room_object_room_port(std::uint8_t* memory,R5900Context* c){
    using namespace room_object_message_fixture;lookups.push_back({c->pc==0x811d40?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,std::uint16_t(GPR_U32(c,4))});
    if(callback){memory[0x3243f2]=std::uint8_t(callback-1);memory[raw+0xcb0]=std::uint8_t((memory[raw+0xcb0]+1)%32);source_coordinates(memory,seed^0xa5a5u,placement_count);}SET_GPR_U32(c,2,ats::mapped);
}
void compare_actor_room_object_messages(std::uint8_t* memory){
    using namespace room_object_message_fixture;actor_room_object_capture=true;ats::nested=0;
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto a=world.primary(0);auto objects=make(0,31);RoomObjectSink sink(world,objects);reo::native::gameplay_scenario::FlagState flags;u::StatePublication publisher(world,flags,&sink,&objects);
    const auto run=[&](unsigned n,unsigned grid,unsigned mode,unsigned phase,unsigned category,unsigned selected,unsigned status,unsigned suppression,unsigned paused,unsigned cb,unsigned count){
        seed=n;placement_count=count;objects=make(n,count);source_coordinates(memory,n,count);a->grid=std::uint8_t(grid);a->category=std::uint8_t(category);a->slot=std::uint8_t(category?n:0);a->status=status;a->gauge_value.reset();world.selected_actor=std::uint8_t(selected);world.mode=std::uint8_t(mode);world.paused=std::bit_cast<std::int8_t>(std::uint8_t(paused));world.room=std::uint16_t(n*17);world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));world.session().actor_message_suppression=std::uint16_t(suppression);
        memory[raw+0xcb0]=a->grid;memory[raw+2]=a->category;memory[raw+3]=a->slot;put(memory,raw+0xba0,status);memory[0x4baded]=world.selected_actor;memory[0x3243f2]=world.mode;memory[0x3243fb]=std::uint8_t(phase);memory[0x4badf8]=std::uint8_t(paused);put(memory,0x3243dc,world.room);put(memory,0x744638,std::uint16_t(suppression));ats::mapped=n%7?n*65521u:UINT32_MAX;callback=cb;messages.clear();lookups.clear();sink.object_messages.clear();sink.lookups.clear();
        call(memory,0x67e230,{raw,0xabcd0009u});check(publisher.actor_message(id,u::ActorMessageSelector::room_object)==u::PublicationStatus::completed);check(messages.size()==sink.object_messages.size()&&lookups==sink.lookups);for(unsigned i=0;i<messages.size();++i)check(equal(messages[i],sink.object_messages[i]));check(a->grid==memory[raw+0xcb0]&&a->status==get<unsigned>(memory,raw+0xba0)&&world.mode==memory[0x3243f2]&&world.session().actor_message_suppression==get<std::uint16_t>(memory,0x744638)&&!a->gauge_value);room_object_messages+=unsigned(messages.size());room_object_message_lookups+=unsigned(lookups.size());++room_object_message_cases;
    };
    for(unsigned category:{0u,1u})for(unsigned mode=0;mode<4;++mode)for(unsigned n=0;n<65536;++n)run(n,n%32,mode,1+n%2,category,0,category?0x10000000u:0u,65535,0,n%17?0:1+n%4,n%3?31:8);
    for(unsigned n=0;n<65536;++n)run(n,1,1,1,0,0,0,65535,0,0,31);
    for(unsigned n=0;n<65536;++n)run(n,n%32,n>>8,n,n%4,n%2,n%7?0x10000000u:4u,n,n%7?0:n,0,31);
    callback=0;a->category=0;a->slot=0;a->grid=1;a->status=0;world.selected_actor=0;world.mode=1;world.paused=0;world.session().message_phase=1;world.session().actor_message_suppression=0;
    u::StatePublication absent(world,flags,&sink);check(absent.actor_message(id,u::ActorMessageSelector::room_object)==u::PublicationStatus::unavailable);++room_object_message_refusals;
    ro::Owner uninitialized;u::StatePublication unknown(world,flags,&sink,&uninitialized);check(unknown.actor_message(id,u::ActorMessageSelector::room_object)==u::PublicationStatus::unavailable);++room_object_message_refusals;
    for(unsigned slot=32;slot<256;++slot){a->grid=std::uint8_t(slot);check(publisher.actor_message(id,u::ActorMessageSelector::room_object)==u::PublicationStatus::unavailable);}++room_object_message_refusals;a->grid=1;
    u::StatePublication no_sink(world,flags,nullptr,&objects);check(no_sink.actor_message(id,u::ActorMessageSelector::room_object)==u::PublicationStatus::message_unavailable);++room_object_message_refusals;
    ats::Sink unsupported(world);u::StatePublication old(world,flags,&unsupported,&objects);check(old.actor_message(id,u::ActorMessageSelector::room_object)==u::PublicationStatus::message_unavailable);++room_object_message_refusals;
    sink.available=false;check(publisher.actor_message(id,u::ActorMessageSelector::room_object)==u::PublicationStatus::message_unavailable);++room_object_message_refusals;sink.available=true;
    a->category=1;a->status=0x10000000u;sink.lookup_available=false;check(publisher.actor_message(id,u::ActorMessageSelector::room_object)==u::PublicationStatus::unavailable);++room_object_message_refusals;sink.lookup_available=true;a->category=0;a->status=0;
    world.session().message_phase=0;check(absent.actor_message({},u::ActorMessageSelector::room_object)==u::PublicationStatus::completed);++room_object_message_refusals;world.session().message_phase=1;
    actor_action_fixture::Notifications notifications;u::Owner owner(world,notifications,e::RuleBook::file1(),&sink,&objects);check(owner.record_actor_message(id,u::ActorMessageSelector::room_object)==u::PublicationStatus::completed&&!a->gauge_value);++room_object_message_cases;
    check(publisher.actor_message({},u::ActorMessageSelector::room_object)==u::PublicationStatus::unavailable);++room_object_message_refusals;
    check(world.retire_primary(0)==g::actors::EntityStatus::completed&&publisher.actor_message(id,u::ActorMessageSelector::room_object)==u::PublicationStatus::unavailable);++room_object_message_refusals;
    check(owner.close()==u::Status::completed&&owner.record_actor_message(id,u::ActorMessageSelector::room_object)==u::PublicationStatus::unavailable);++room_object_message_refusals;actor_room_object_capture=false;
}
