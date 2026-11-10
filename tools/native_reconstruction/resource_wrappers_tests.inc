unsigned wrapper_cases{},wrapper_messages{},wrapper_frontends{},wrapper_refusals{};
namespace wrapper_fixture {
using namespace consumption_fixture;
struct Capture {
    u::MessageRoute route;std::uint16_t resource;std::uint8_t actor,operation;
    std::array<std::int16_t,3> quantities;std::array<std::uint8_t,4> carried;
    unsigned points,available;
    friend bool operator==(const Capture&,const Capture&)=default;
};
std::vector<Capture> source_messages;unsigned actor_slot{};bool mutate_self{};
struct Sink:u::GameplayMessageSink {
    Consuming* owner{};std::vector<Capture> messages;bool available{true};
    bool send(const u::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const u::ActorStatusMessage&)noexcept override{return false;}
    bool send(const u::ResourceOperationMessage& message)noexcept override{
        auto& f=*owner;Capture value{message.route,message.resource,message.actor,message.operation,{},{},f.update.completion_statistics().state().points,unsigned(f.update.cooperative_events().available())};
        for(unsigned i=0;i<3;++i)value.quantities[i]=f.q.resources.get(*f.q.resources.slot(std::array<unsigned,3>{3,4,6}[i]))->parameter;
        value.carried=f.q.world.primary(actor_slot)->inventory.carried;messages.push_back(value);
        if(mutate_self){auto d=*f.q.resources.get(*f.q.resources.slot(3));d.instance_index=6;check(f.q.resources.replace(*f.q.resources.slot(3),d)==s::SceneStatus::completed);}
        return available;
    }
};
void invoke(Consuming& f,unsigned operation,const g::actors::EntityId& id,unsigned content){switch(operation){case 0:f.consumer.use_carried_content(id,content);break;case 1:f.consumer.consume_carried_content(id,content);break;case 2:f.consumer.destroy_content(id,content);break;default:throw std::runtime_error("Unknown inventory consumption wrapper");}}
}
void wrapper_message_port(std::uint8_t* memory,R5900Context* context){
    using namespace wrapper_fixture;const auto at=GPR_U32(context,5);check(GPR_U32(context,4)==5&&GPR_U32(context,6)==0&&GPR_U32(context,7)==4&&memory[at]==9&&memory[at+1]==8);
    Capture value{context->pc==0x811190?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,get<std::uint16_t>(memory,at+4),memory[at+6],memory[at+7],{},{},get<unsigned>(memory,0x3b8500),get<std::uint16_t>(memory,0x56c810)};
    for(unsigned i=0;i<3;++i)value.quantities[i]=get<std::int16_t>(memory,pair_fixture::address(std::array<unsigned,3>{3,4,6}[i])+0x24);
    std::memcpy(value.carried.data(),memory+0x4a5c30+0x10e0*actor_slot+0xc84,4);source_messages.push_back(value);
    if(mutate_self)memory[pair_fixture::address(3)+2]=6;
}
void compare_resource_wrappers(const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    using namespace wrapper_fixture;const auto assets=factory_load(static_path,16);auto banks=factory_load(template_path,5);std::vector<std::byte> controlled(32+6*24);const auto write=[&]<class T>(unsigned at,T value){std::memcpy(controlled.data()+at,&value,sizeof value);};write(0,3u);write(4,6u);write(16,32u);
    for(unsigned i=0;i<6;++i){write(32+24*i,std::array<unsigned,6>{0,0x200,0x40200,0x80000,0xc0200,0x40000}[i]);write(32+24*i+8,std::int16_t(20));write(32+24*i+10,std::int16_t(42));write(32+24*i+18,std::uint16_t(42+i));}banks.push_back(controlled);
    constexpr std::array<unsigned,3> entries{0x5b4460,0x5b45e0,0x5b47f0};
    bool frontends_checked{};
    for(const auto& bank:banks){Sink sink;Consuming f(ram,assets[0],bank,&sink);sink.owner=&f;
        if(!frontends_checked){
            frontends_checked=true;actor_slot=0;mutate_self=false;for(unsigned i=0;i<4;++i)f.actor(i,0,0);
            const auto frontend=[&](unsigned mode,unsigned phase,unsigned n){
                f.mode(mode,0);f.q.session->message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));f.q.memory[0x3243fb]=std::uint8_t(phase);source_messages.clear();sink.messages.clear();
                const auto resource=0xabcd0000u|n,actor=n*1664525u,operation=n*1013904223u;call(f.q.memory,0x5b58c0,{resource,actor,operation});check(f.update.record_resource_operation(resource,actor,operation)==u::PublicationStatus::completed&&source_messages==sink.messages);wrapper_messages+=unsigned(sink.messages.size());++wrapper_frontends;
            };
            for(unsigned n=0;n<65536;++n)frontend(n>>8,n,n);
            for(unsigned mode=0;mode<2;++mode)for(unsigned n=0;n<65536;++n)frontend(mode,1,n);
        }
        const auto run=[&](unsigned operation,unsigned n,unsigned mode,unsigned phase,bool null_actor,bool nested){
            actor_slot=n%4;mutate_self=nested;f.mode(mode,(n/4096)%4);f.q.session->message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));f.q.memory[0x3243fb]=std::uint8_t(phase);f.reset_statistics(n*65521u);source_messages.clear();sink.messages.clear();
            for(unsigned slot:{3u,4u,6u}){s::SceneDescriptor d;d.active=std::uint8_t(n%5?1+n%255:0);d.instance_index=std::uint8_t(slot==3?(n%7?3:6):slot);d.ownership_tag=std::uint16_t(n%6?1:0);d.attachment_id=std::uint16_t(slot==4&&n%2?10102:10100);d.parameter=std::bit_cast<std::int16_t>(std::uint16_t(n*65521+slot-3));d.template_index=n%13?std::uint8_t((n/17+slot)%f.q.templates.state().count):255;d.flags=n*1664525u;sync(f.q,slot,d);}
            for(unsigned i=0;i<4;++i){const auto actor=f.q.world.primary(i);actor->inventory={};actor->inventory.carried={std::uint8_t(n%7?3:0),4,std::uint8_t(n%3?3:6),0};if(n%8==0)actor->inventory.carried={};actor->inventory.storage[n%32]=3;actor->inventory.storage[31]=6;actor->selected_resource=std::uint8_t(n&2?3:0);actor->secondary_equipped_resource=std::uint8_t(n&4?3:0);actor->resource_action=123;f.actor(i,std::uint8_t(n%17?0:127),std::uint8_t(n%8));}
            put(f.q.memory,0x743128,unsigned(f.q.resources.active_count()));const auto content=0xabcd0000u|(n%3?10100u:10102u);call(f.q.memory,entries[operation],{null_actor?0u:0x4a5c30+0x10e0*actor_slot,content});wrapper_fixture::invoke(f,operation,null_actor?g::actors::EntityId{}:f.q.world.identity(actor_slot),content);
            for(unsigned slot:{3u,4u,6u})compare_all(f.q,slot);
            for(unsigned i=0;i<4;++i)inventory_fixture::compare_actor(f.q.memory,*f.q.world.primary(i),i);
            check(f.q.resources.active_count()==get<unsigned>(f.q.memory,0x743128));f.compare_statistics();check(source_messages==sink.messages);wrapper_messages+=unsigned(sink.messages.size());++wrapper_cases;
        };
        for(unsigned operation=0;operation<3;++operation)for(unsigned n=0;n<65536;++n)run(operation,n,n%256,n>>8,n%11==0,false);
        for(unsigned operation=0;operation<3;++operation)for(unsigned phase:{1u,2u})for(unsigned mode=0;mode<4;++mode)for(unsigned n=1;n<257;++n)run(operation,n,mode,phase,false,n%3==0);
        sink.available=false;f.q.session->message_phase=1;f.q.world.mode=0;check(f.update.record_resource_operation(3,0,1)==u::PublicationStatus::message_unavailable);++wrapper_refusals;
    }
    mutate_self=false;
}
