#include "game/native/gameplay_world/resource_effects.hpp"
unsigned effect_cases{},effect_depletions{},effect_deployments{},effect_mutations{},effect_refusals{};
bool effect_capture{};
namespace effect_fixture {
using namespace consumption_fixture;
bool zero_quantity{};
struct Sink:health_fixture::Sink {
    Consuming* f{};std::vector<deployment_fixture::Packet> positions;
    bool send(const u::ResourcePositionMessage& value)noexcept override{
        positions.push_back({value.route==u::MessageRoute::mode_zero?0x811190u:0x810870u,value.resource,value.actor,value.operation,std::bit_cast<unsigned>(value.position.x),std::bit_cast<unsigned>(value.position.y),std::bit_cast<unsigned>(value.position.z),0,0});
        if(zero_quantity){auto item=*f->q.resources.get(*f->q.resources.slot(3));item.parameter=0;check(f->q.resources.replace(*f->q.resources.slot(3),item)==s::SceneStatus::completed);}
        return available;
    }
};
}
void effect_position_message_port(std::uint8_t* memory,R5900Context* context){
    deployment_message_port(memory,context);
    if(effect_fixture::zero_quantity)put(memory,pair_fixture::address(3)+0x24,std::int16_t(0));
}
void compare_resource_effects(const std::vector<std::vector<std::byte>>& corpus,const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    using namespace effect_fixture;namespace a=reo::native::gameplay_audio;namespace b=reo::native::audio_banks::v2;namespace l=reo::native::gameplay_lighting;
    const auto assets=factory_load(static_path,16);auto banks=factory_load(template_path,5);
    std::vector<std::byte> controlled(32+128*24);const auto write=[&]<class T>(unsigned at,T value){std::memcpy(controlled.data()+at,&value,sizeof value);};write(0,3u);write(4,128u);write(16,32u);
    for(unsigned n=0;n<128;++n){write(32+24*n,std::uint32_t(n|(n&1?0x40000u:0u)));write(32+24*n+10,std::uint16_t(n*13u));write(32+24*n+18,std::uint16_t(300+n%19));}banks.push_back(controlled);
    for(unsigned bank=0;bank<banks.size();++bank){
        Sink sink;Consuming f(ram,assets[0],banks[bank],&sink);sink.f=&f;health_fixture::Ui ui(f,sink.events);g::ResourceEffects effects(f.recipes,f.update,&ui);
        prepare(f.q.memory,corpus[0],corpus[1],0x1800000);unsigned offset{},length{};std::memcpy(&offset,assets[0].data()+0x24,4);std::memcpy(&length,assets[0].data()+0x28,4);std::memcpy(f.q.memory+0x1000000,assets[0].data()+offset,length);call(f.q.memory,0x1d3100,{0x70000,0x1000000});
        auto effect_bank=e::EffectBank::import(corpus[0],corpus[1]);auto engine=std::make_shared<b::Session>();a::Owner audio(engine,f.q.session->random);a::SpatialContext spatial;spatial.world_to_screen=m::identity();g::animation_events::BasicAudio frontend(f.q.world,audio,spatial,f.q.resources,f.q.templates);s::Lighting lighting;l::Pool lights(lighting);l::TimedLights timed(f.q.world,f.update.linked(),lights);e::NativeResourceCompanionActions actions(f.q.world,f.q.resources,f.q.models,f.q.templates,frontend,timed);e::PeriodicVisuals visuals(effect_bank,f.q.session->random);check(visuals.bind_resource_companions(f.q.world,f.q.resources,f.q.models,f.q.templates,actions)&&f.q.factory.bind_companions(visuals));
        const auto cleanup=[&](){check(visuals.update({}).status==e::VisualStatus::completed);const auto frame=visuals.retain();check(bool(frame));for(const auto& visual:frame->visuals)check(visuals.retire(visual.id));while(const auto id=f.q.models.head()){call(f.q.memory,0x590d80,{f.q.address(id)});check(f.q.models.retire(id)==g::ResourceModelStatus::completed);}call(f.q.memory,0x651850);check(!visuals.size());};
        bool full_events{};
        const auto run=[&](unsigned n,bool forced,unsigned kind,bool full,bool mutate_quantity){
            cleanup();f.reset_statistics(n*65521u);f.mode(n>>8,(n/4096)%4);f.q.session->message_phase=std::int8_t(n%3);f.q.memory[0x3243fb]=std::uint8_t(n%3);f.q.world.paused=0;f.q.memory[0x4badf8]=0;f.q.session->actor_message_suppression=0;put(f.q.memory,0x744638,std::uint16_t(0));f.q.session->inventory_owner=std::uint8_t(n);f.q.memory[0x4badee]=std::uint8_t(n);health_fixture::actors(f,n);health_fixture::mapped=n*65521u;
            unsigned selector=bank==5?n%128:std::uint8_t(f.q.templates.selector(std::int16_t(300+n%19)));if(forced){selector=0;while(selector<f.q.templates.state().count&&(read<unsigned>(f.q.templates.state().templates[selector],0)&0x4cu)!=kind)++selector;if(selector==f.q.templates.state().count)return;}
            const auto flags=read<unsigned>(f.q.templates.state().templates[selector],0);s::SceneDescriptor item;item.active=std::uint8_t(forced?1:n%5);item.instance_index=std::uint8_t(n%17?3:6);item.room=33;item.ownership_tag=std::uint16_t(forced?1:n%5);item.parameter=forced?std::int16_t(1+n%2):std::bit_cast<std::int16_t>(std::uint16_t(n*65521u));item.template_index=std::uint8_t(selector);item.attachment_id=std::uint16_t((flags&0x4cu)==8?0x3201:300+n%19);item.flags=n*1664525u;deployment_fixture::sync_record(f,3,item);auto other=item;other.instance_index=6;other.ownership_tag=1;deployment_fixture::sync_record(f,6,other);
            const auto slot=n%4;for(unsigned i=0;i<4;++i){const auto actor=f.q.world.primary(i);actor->inventory.carried={3,3,0,0};actor->selected_resource=actor->secondary_equipped_resource=3;actor->room=std::uint16_t(n%3==0?1:n%3==1?0x101:2);actor->position={float(n%41),-3,37};inventory_fixture::export_actor(f.q.memory,*actor,i);put(f.q.memory,0x4a5c30+0x10e0*i+0x1e2,actor->room);put(f.q.memory,0x4a5c30+0x10e0*i+0x38,actor->position);}
            if(full)for(unsigned i=0;i<64;++i){const auto source=call(f.q.memory,0x590c70);const auto made=f.q.models.create();check(made.status==g::ResourceModelStatus::completed&&f.q.address(made.id)==GPR_U32(&source,2));}
            put(f.q.memory,0x743128,unsigned(f.q.resources.active_count()));deployment_fixture::source_packets.clear();deployment_fixture::mutate=false;sink.positions.clear();health_fixture::observed.clear();sink.events.clear();zero_quantity=mutate_quantity;const bool null_actor=!forced&&n%29==0&&(flags&0x4cu)!=8;const auto id=null_actor?g::actors::EntityId{}:f.q.world.identity(slot);
            if(full_events)for(unsigned i=0;i<128;++i){call(f.q.memory,0x37bfb0,{i});check(f.update.record_simple_event(i).status==reo::native::gameplay_events::Status::completed);}
            effect_capture=true;R5900Context source;try{source=call(f.q.memory,0x5b2080,{0xabcd0003,null_actor?0u:0x4a5c30+0x10e0*slot});}catch(...){effect_capture=false;throw;}effect_capture=false;const auto native=effects.apply(0xabcd0003,id);
            if(native.status!=g::ResourceEffectStatus::completed||native.value!=std::int8_t(GPR_U32(&source,2)))throw std::runtime_error("Item effect result bank="+std::to_string(bank)+" n="+std::to_string(n)+" selector="+std::to_string(selector)+" flags="+std::to_string(flags));
            deployment_fixture::compare_record(f,3);deployment_fixture::compare_record(f,6);health_fixture::compare_actors(f);for(unsigned i=0;i<4;++i)inventory_fixture::compare_actor(f.q.memory,*f.q.world.primary(i));f.compare_statistics();check(f.q.resources.active_count()==get<unsigned>(f.q.memory,0x743128)&&health_fixture::observed==sink.events&&deployment_fixture::source_packets==sink.positions&&f.q.models.available()==get<std::uint16_t>(f.q.memory,0x3b5700));if(!full)f.q.compare_world();
            if(!f.q.resources.get(*f.q.resources.slot(3))->active&&item.active)++effect_depletions;
            if(effects.last_deployment()&&effects.last_deployment()->value==4)++effect_deployments;
            if(zero_quantity&&!sink.positions.empty())++effect_mutations;
            if(full_events&&native.value)check(effects.last_record()&&effects.last_record()->status==reo::native::gameplay_events::StatisticsStatus::completed);
            ++effect_cases;
        };
        for(unsigned n=0;n<(bank==5?65536u:4096u);++n)run(n,false,0,false,false);
        for(unsigned kind:{4u,8u,0x40u})for(unsigned n=0;n<512;++n)run(n,true,kind,n%31==0,n%7==0);
        full_events=true;run(0,true,4,false,false);full_events=false;
        cleanup();visuals.close();
        // Capability failures are native-only domains. Verify that the outer
        // caller preserves the reached helper prefix and does not consume or
        // retire the item after a failed required consumer.
        std::array<std::byte,56> required{};const auto set=[&]<class T>(unsigned at,T value){std::memcpy(required.data()+at,&value,sizeof value);};set(0,3u);set(4,1u);set(16,32u);set(32,4u);set(32+18,std::uint16_t(312));check(f.q.templates.load(required));s::SceneDescriptor pending;pending.active=1;pending.instance_index=3;pending.ownership_tag=1;pending.parameter=2;pending.template_index=0;pending.attachment_id=312;check(f.q.resources.replace(*f.q.resources.slot(3),pending)==s::SceneStatus::completed);const auto actor=f.q.world.primary(0);actor->category=0;actor->slot=0;actor->status=actor->auxiliary_status=0;actor->current=0;actor->maximum=100;f.mode(0,0);f.q.world.paused=0;f.q.session->message_phase=0;f.q.session->inventory_owner=3;g::ResourceEffects missing_ui(f.recipes,f.update);const auto failed_ui=missing_ui.apply(3,f.q.world.identity(0));check(failed_ui.status==g::ResourceEffectStatus::health_unavailable&&missing_ui.last_health()->status==g::ResourceHealthStatus::ui_unavailable&&f.q.resources.get(*f.q.resources.slot(3))->parameter==2&&actor->auxiliary_status==0x1000&&f.q.session->inventory_owner==0&&!missing_ui.last_record());++effect_refusals;
        set(32+10,std::uint16_t(0x10));check(f.q.templates.load(required));actor->status=1;f.q.session->message_phase=1;sink.available=false;const auto failed_message=effects.apply(3,f.q.world.identity(0));check(failed_message.status==g::ResourceEffectStatus::health_unavailable&&effects.last_health()->status==g::ResourceHealthStatus::message_unavailable&&actor->status==0&&f.q.resources.get(*f.q.resources.slot(3))->parameter==2&&!effects.last_record());++effect_refusals;
        set(32,8u);check(f.q.templates.load(required));pending.attachment_id=0x3201;check(f.q.resources.replace(*f.q.resources.slot(3),pending)==s::SceneStatus::completed);const auto failed_deployment=effects.apply(3,f.q.world.identity(0));check(failed_deployment.status==g::ResourceEffectStatus::deployment_unavailable&&effects.last_deployment()->status==g::ResourceModelStatus::unavailable&&f.q.resources.get(*f.q.resources.slot(3))->attachment_id==0x3201&&f.q.resources.get(*f.q.resources.slot(3))->parameter==2);++effect_refusals;sink.available=true;f.q.session->message_phase=0;
        set(32,0x40004u);set(32+10,std::uint16_t(1));check(f.q.templates.load(required));pending.attachment_id=300;pending.parameter=1;check(f.q.resources.replace(*f.q.resources.slot(3),pending)==s::SceneStatus::completed);actor->status=0;actor->current=0;actor->maximum=100;f.q.session->scenario.reset();const auto failed_statistics=effects.apply(3,f.q.world.identity(0));check(failed_statistics.status==g::ResourceEffectStatus::statistics_unavailable&&effects.last_record()->status==reo::native::gameplay_events::StatisticsStatus::unavailable&&actor->current==100&&f.q.resources.get(*f.q.resources.slot(3))->parameter==0&&f.q.resources.get(*f.q.resources.slot(3))->active);++effect_refusals;
        s::SceneDescriptor inactive;inactive.parameter=1;inactive.ownership_tag=1;sync(f.q,3,inactive);check(effects.apply(UINT32_MAX,{}).status==g::ResourceEffectStatus::completed&&!effects.last_health()&&!effects.last_deployment()&&!effects.last_record());++effect_refusals;
        check(f.update.close()==u::Status::completed&&effects.apply(3,{}).status==g::ResourceEffectStatus::unavailable);++effect_refusals;
    }
}
