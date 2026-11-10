#include <algorithm>
#include <string_view>
unsigned actor_action_cases{},actor_action_messages{},actor_action_lookups{},actor_action_requests{},actor_action_refusals{},actor_action_world_publications{};
namespace actor_action_fixture {
namespace ats=actor_status_fixture;
namespace u=reo::native::gameplay_update;namespace g=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;
using Requests=std::array<std::uint8_t,24>;
std::vector<u::ActorActionMessage> source_messages;std::vector<Requests> source_requests;bool nested_payload{};
Requests requests(const g::World& world){Requests result{};for(unsigned i=0;i<8;++i){const auto actor=world.primary(i);check(bool(actor));result[3*i]=actor->interaction_kind;result[3*i+1]=actor->interaction_mode;result[3*i+2]=actor->interaction_slot;}return result;}
Requests requests(const std::uint8_t* memory){Requests result{};for(unsigned i=0;i<8;++i)std::copy_n(memory+0x4a5c30+0x10e0*i+0xc78,3,result.begin()+3*i);return result;}
bool equal(const u::ActorActionMessage& a,const u::ActorActionMessage& b){return a.route==b.route&&a.channel==b.channel&&a.flags==b.flags&&a.values==b.values&&a.equipment==b.equipment;}
struct Sink:ats::Sink {
    using ats::Sink::send;
    std::vector<u::ActorActionMessage> actions;std::vector<Requests> before_lookup;
    explicit Sink(g::World& world):ats::Sink(world){}
    bool send(const u::ActorActionMessage& value)noexcept override{actions.push_back(value);return available;}
    std::optional<unsigned> room_owner(u::MessageRoute route,std::uint16_t room)noexcept override{
        before_lookup.push_back(requests(world));const auto result=ats::Sink::room_owner(route,room);
        if(nested_payload){const auto actor=world.primary(0);actor->pending_notice=0xabcd;actor->equipment_notice_slot=201;actor->equipment_notice_peer=202;actor->equipment_notice_parameter=203;actor->equipment_notice_detail=204;actor->equipment_slot=205;}
        return result;
    }
};
struct Notifications:s::FlagNotifications {bool changed(const s::ScenarioFlagChange&)noexcept override{return false;}bool changed(const s::StridedFlagChange&)noexcept override{return false;}};
struct Services:g::Services {
    u::Owner& owner;g::actors::EntityId identity;bool suppress{};unsigned published{};
    Services(u::Owner& value,g::actors::EntityId id):owner(value),identity(id){}
    void begin_offline_frame(g::World&)override{}
    void run(g::Stage stage,g::World& world,g::Actor& actor)override{
        if(stage==g::Stage::update_behavior){check(actor.pending_notice==0&&world.session().actor_message_suppression==0);actor.pending_notice=0x820;actor.equipment_notice_slot=3;actor.equipment_notice_peer=4;actor.equipment_notice_parameter=5;actor.equipment_notice_detail=6;actor.equipment_slot=7;if(suppress)world.frame_shared_counter=7;}
        if(stage==g::Stage::publish_notice){++published;++actor_action_world_publications;if(owner.record_actor_action(identity)!=u::PublicationStatus::completed)throw std::runtime_error("Declared action message delivery unavailable");}
    }
    bool remote_motion(g::World&,g::Actor&)override{return false;}
    bool find_grid(g::World&,g::Actor&,std::int8_t&)override{return false;}
    void switch_grid(g::World&,std::int32_t,std::int32_t)override{}
    float grid_response(g::World&,std::uint8_t)override{throw std::runtime_error("Unreached action notice grid response");}
};
}
void actor_action_message_port(std::uint8_t* memory,R5900Context* context){
    using namespace actor_action_fixture;const auto at=GPR_U32(context,5);check(actor_action_capture&&memory[at]==7&&memory[at+1]==12&&!memory[at+2]&&!memory[at+3]&&!GPR_U32(context,6)&&GPR_U32(context,7)==4);
    source_messages.push_back({context->pc==0x811190?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,GPR_U32(context,4),get<std::uint16_t>(memory,at+4),{memory[at+6],memory[at+7],memory[at+8],memory[at+9]},memory[at+10]});
}
void actor_action_room_owner_port(std::uint8_t* memory,R5900Context* context){
    using namespace actor_action_fixture;source_requests.push_back(requests(memory));actor_room_owner_port(memory,context);
    if(nested_payload){put(memory,0x4a5c30+0xd92,std::uint16_t(0xabcd));for(unsigned i=0;i<4;++i)memory[0x4a5c30+0xda2+i]=std::uint8_t(201+i);memory[0x4a5c30+0xc7f]=205;}
}
void compare_actor_action_messages(std::uint8_t* memory){
    using namespace actor_action_fixture;actor_action_capture=true;
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());for(unsigned i=0;i<8;++i){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(i);check(bool(world.spawn_primary(i,std::move(actor)).id));}s::FlagState flags;Sink sink(world);u::StatePublication publisher(world,flags,&sink);const auto id=world.identity(0);
    const auto run=[&](unsigned n,unsigned mode,unsigned phase,unsigned category,unsigned slot,unsigned selected,unsigned status,unsigned suppression,unsigned pause,unsigned callback){
        for(unsigned i=0;i<8;++i){const auto peer=world.primary(i);peer->interaction_kind=std::uint8_t(n+5*i);peer->interaction_mode=std::uint8_t(n*3+i);peer->interaction_slot=std::uint8_t(n*7+i);memory[0x4a5c30+0x10e0*i+0xc78]=peer->interaction_kind;memory[0x4a5c30+0x10e0*i+0xc79]=peer->interaction_mode;memory[0x4a5c30+0x10e0*i+0xc7a]=peer->interaction_slot;}
        const auto before=requests(world);const auto actor=world.primary(0);actor->current=std::bit_cast<std::int16_t>(std::uint16_t(n));actor->status=status;actor->category=std::uint8_t(category);actor->slot=std::uint8_t(slot);actor->pending_notice=std::uint16_t(n);actor->equipment_notice_slot=std::uint8_t(n);actor->equipment_notice_peer=std::uint8_t(n%9);actor->equipment_notice_parameter=std::uint8_t((n/7)%9);actor->equipment_notice_detail=std::uint8_t(n*13);actor->equipment_slot=std::uint8_t(n*17);world.mode=std::uint8_t(mode);world.selected_actor=std::uint8_t(selected);world.paused=std::bit_cast<std::int8_t>(std::uint8_t(pause));world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));world.session().actor_message_suppression=std::uint16_t(suppression);world.room=std::uint16_t(n*17);
        put(memory,0x4a5c30+0x544,actor->current);put(memory,0x4a5c30+0xba0,status);memory[0x4a5c30+2]=actor->category;memory[0x4a5c30+3]=actor->slot;put(memory,0x4a5c30+0xd92,actor->pending_notice);memory[0x4a5c30+0xda2]=actor->equipment_notice_slot;memory[0x4a5c30+0xda3]=actor->equipment_notice_peer;memory[0x4a5c30+0xda4]=actor->equipment_notice_parameter;memory[0x4a5c30+0xda5]=actor->equipment_notice_detail;memory[0x4a5c30+0xc7f]=actor->equipment_slot;memory[0x3243f2]=world.mode;memory[0x3243fb]=std::uint8_t(phase);memory[0x4badf8]=std::uint8_t(pause);memory[0x4baded]=world.selected_actor;put(memory,0x744638,std::uint16_t(suppression));put(memory,0x3243dc,world.room);
        ats::mapped=n%7?n*65521u:UINT32_MAX;ats::nested=callback;nested_payload=callback!=0;source_messages.clear();source_requests.clear();ats::source_lookups.clear();sink.actions.clear();sink.lookups.clear();sink.before_lookup.clear();call(memory,0x67e230,{0x4a5c30,0xabcd0007});check(publisher.actor_action(id)==u::PublicationStatus::completed);
        const auto after=requests(world);check(after==requests(memory)&&world.mode==memory[0x3243f2]&&world.frame_shared_counter==get<std::uint16_t>(memory,0x744638));for(unsigned i=0;i<8;++i)if(!std::equal(before.begin()+3*i,before.begin()+3*i+3,after.begin()+3*i))++actor_action_requests;
        check(actor->status==get<unsigned>(memory,0x4a5c30+0xba0)&&actor->current==get<std::int16_t>(memory,0x4a5c30+0x544)&&actor->pending_notice==get<std::uint16_t>(memory,0x4a5c30+0xd92)&&actor->equipment_slot==memory[0x4a5c30+0xc7f]);check(actor->equipment_notice_slot==memory[0x4a5c30+0xda2]&&actor->equipment_notice_peer==memory[0x4a5c30+0xda3]&&actor->equipment_notice_parameter==memory[0x4a5c30+0xda4]&&actor->equipment_notice_detail==memory[0x4a5c30+0xda5]);check(source_requests==sink.before_lookup&&ats::source_lookups==sink.lookups&&source_messages.size()==sink.actions.size());for(unsigned i=0;i<sink.actions.size();++i)check(equal(source_messages[i],sink.actions[i]));actor_action_messages+=unsigned(sink.actions.size());actor_action_lookups+=unsigned(sink.lookups.size());++actor_action_cases;
    };
    for(unsigned n=0;n<65536;++n)run(n,n>>8,n,n%4,n,n>>8,n%5?0x10000000u:n*1664525u,n,n%7?0:n,0);
    for(unsigned category:{0u,1u})for(unsigned mode:{0u,1u})for(unsigned n=0;n<65536;++n)run(n,mode,1+n%2,category,0,0,(n%17?0x10000000u:0x10000004u),n%19?0:7,0,n%23?0:1+n%4);
    for(unsigned n=0;n<65536;++n)run(n,1,1,0,n,n>>8,0,0,0,0);
    ats::nested=0;nested_payload=false;const auto actor=world.primary(0);world.mode=0;world.paused=0;world.session().message_phase=1;world.session().actor_message_suppression=0;world.selected_actor=0;actor->slot=0;actor->category=0;actor->status=0;actor->pending_notice=5;actor->equipment_notice_peer=2;actor->equipment_notice_parameter=9;actor->interaction_slot=71;sink.actions.clear();check(publisher.actor_action(id)==u::PublicationStatus::unavailable&&world.primary(1)->interaction_kind==2&&world.primary(1)->interaction_mode==0&&world.primary(1)->interaction_slot==71&&sink.actions.empty());++actor_action_refusals;
    actor->pending_notice=1;actor->equipment_notice_parameter=0;u::StatePublication missing(world,flags);check(missing.actor_action(id)==u::PublicationStatus::message_unavailable&&world.primary(1)->interaction_slot==71);++actor_action_refusals;sink.available=false;check(publisher.actor_action(id)==u::PublicationStatus::message_unavailable);++actor_action_refusals;sink.available=true;actor->category=1;actor->status=0x10000000;sink.lookup_available=false;check(publisher.actor_action(id)==u::PublicationStatus::unavailable);++actor_action_refusals;sink.lookup_available=true;check(publisher.actor_action({})==u::PublicationStatus::unavailable);++actor_action_refusals;world.session().message_phase=0;check(missing.actor_action({})==u::PublicationStatus::completed);++actor_action_refusals;world.session().message_phase=1;check(world.retire_primary(0)==g::actors::EntityStatus::completed&&publisher.actor_action(id)==u::PublicationStatus::unavailable);++actor_action_refusals;check(world.close()==g::Status::completed&&publisher.actor_action(id)==u::PublicationStatus::unavailable);++actor_action_refusals;
    for(bool available:{false,true})for(bool suppress:{false,true}){
        g::World framed({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());auto owned=std::make_unique<g::Actor>();owned->active=true;owned->slot=0;const auto active=framed.spawn_primary(0,std::move(owned)).id;Sink output(framed);output.available=available;Notifications notifications;u::Owner update(framed,notifications,e::RuleBook::file1(),&output);framed.mode=1;framed.session().message_phase=1;framed.session().actor_message_suppression=7;Services services(update,active);services.suppress=suppress;bool failed{};try{check(framed.update_primary(services).status==g::Status::completed);}catch(const std::runtime_error& error){if(std::string_view(error.what())!="Declared action message delivery unavailable")throw;failed=true;}check(failed==(!available&&!suppress)&&services.published==1&&output.actions.size()==unsigned(!suppress)&&framed.primary(0)->pending_notice==(failed?0x820:0));if(!output.actions.empty())check(output.actions[0].flags==0x820&&output.actions[0].values==std::array<std::uint8_t,4>{3,4,5,6}&&output.actions[0].equipment==7);check(&framed.frame_shared_counter==&framed.session().actor_message_suppression);
    }
    actor_action_capture=false;
}
