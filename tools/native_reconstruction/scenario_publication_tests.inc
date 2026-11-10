unsigned publication_cases{},publication_messages{},publication_refusals{};
namespace publication_fixture {
namespace u=reo::native::gameplay_update;
std::vector<u::ScenarioOwnerMessage> messages;
unsigned reentrant{},index{};
struct Sink:u::GameplayMessageSink {
    reo::native::gameplay_scenario::FlagState& flags;std::vector<u::ScenarioOwnerMessage> values;bool available{true};
    explicit Sink(reo::native::gameplay_scenario::FlagState& f):flags(f){}
    bool send(const u::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const u::ActorStatusMessage&)noexcept override{return false;}
    bool send(const u::ScenarioOwnerMessage& value)noexcept override{
        values.push_back(value);if(reentrant)check(flags.scenario_owner(index,reentrant==1?255:0));return available;
    }
};
}
void publication_message_port(std::uint8_t* memory,R5900Context* context){
    using namespace publication_fixture;const auto at=GPR_U32(context,5);check(GPR_U32(context,4)==5&&GPR_U32(context,6)==0&&GPR_U32(context,7)==4&&memory[at]==0&&memory[at+1]==8);
    messages.push_back({context->pc==0x811190?u::MessageRoute::mode_zero:u::MessageRoute::mode_one,get<std::uint16_t>(memory,at+4),memory[at+6]});
    if(reentrant)memory[0x4baa50+index]=reentrant==1?255:0;
}
void compare_scenario_publication(std::uint8_t* memory){
    using namespace publication_fixture;automatic_fixture::Native native;Sink sink(native.flags);u::StatePublication publication(native.world,native.flags,&sink);
    const auto run=[&](unsigned mode,unsigned phase,unsigned selected,unsigned status,unsigned id,unsigned value,unsigned replacement,unsigned previous,unsigned nested){
        native.world.mode=std::uint8_t(mode);native.world.selected_actor=std::uint8_t(selected);native.world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));native.world.primary(selected)->status=status;
        memory[0x3243f2]=std::uint8_t(mode);memory[0x3243fb]=std::uint8_t(phase);memory[0x4baded]=std::uint8_t(selected);put(memory,0x4a5c30+4320*selected+0xba0,status);index=id;reentrant=nested;
        check(native.flags.scenario_owner(id,std::uint8_t(previous)));memory[0x4baa50+id]=std::uint8_t(previous);messages.clear();sink.values.clear();
        call(memory,0x67dbd0,{id,value,replacement});check(publication.publish(id,value,replacement)==u::PublicationStatus::completed);check(native.flags.scenario_owner(id)==memory[0x4baa50+id]);check(messages.size()==sink.values.size());
        for(unsigned i=0;i<messages.size();++i){const auto& a=messages[i];const auto& b=sink.values[i];check(a.route==b.route&&a.flag==b.flag&&a.value==b.value);++publication_messages;}
        ++publication_cases;
    };
    for(unsigned n=0;n<65536;++n)run(n>>8,n,n%4,n%3?0:n*65521u,n%512,n*1664525u,n*1013904223u,n,n%3);
    for(unsigned mode=0;mode<4;++mode)for(unsigned phase:{1u,2u})for(unsigned previous=0;previous<256;++previous)for(unsigned nested=0;nested<3;++nested)run(mode,phase,previous%4,0,(previous*37)%512,previous*65521u,previous*1013904223u,previous,nested);
    reentrant=0;native.world.selected_actor=0;native.world.primary(0)->status=0;native.world.mode=0;native.world.session().message_phase=1;
    u::StatePublication missing(native.world,native.flags);check(missing.publish(0,1,2)==u::PublicationStatus::message_unavailable);++publication_refusals;
    sink.available=false;check(publication.publish(0,1,2)==u::PublicationStatus::message_unavailable);++publication_refusals;sink.available=true;
    native.world.primary(0)->status=0x400;check(missing.publish(UINT32_MAX,1,2)==u::PublicationStatus::completed);++publication_refusals;
    native.world.primary(0)->status=0;native.world.session().message_phase=0;check(publication.publish(512,1,2)==u::PublicationStatus::unavailable);++publication_refusals;
    native.world.session().message_phase=1;sink.values.clear();check(publication.publish(0x12340200,1,2)==u::PublicationStatus::unavailable&&sink.values.size()==1&&sink.values[0].flag==512);++publication_refusals;
    native.world.selected_actor=255;check(publication.publish(0,1,2)==u::PublicationStatus::unavailable);++publication_refusals;
    native.world.selected_actor=0;check(native.world.retire_primary(0)==u::world::actors::EntityStatus::completed&&publication.publish(0,1,2)==u::PublicationStatus::unavailable);++publication_refusals;
    check(native.world.close()==u::world::Status::completed&&publication.publish(0,1,2)==u::PublicationStatus::unavailable);++publication_refusals;
}
