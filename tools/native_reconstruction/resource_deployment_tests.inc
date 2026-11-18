#include "game/native/gameplay_world/resource_deployment.hpp"
unsigned deployment_counts{},deployment_admissions{},deployment_cases{},deployment_effects{},deployment_messages{},deployment_frontends{},deployment_lifecycle{},deployment_capacity{},deployment_refusals{};
namespace deployment_fixture {
using namespace consumption_fixture;
using Packet=std::array<unsigned,9>;
std::vector<Packet> source_packets;bool mutate{};
struct Sink:u::GameplayMessageSink {
    Consuming* f{};std::vector<Packet> packets;bool available{true};
    bool send(const u::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const u::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const u::ActorStatusMessage&)noexcept override{return false;}
    bool send(const u::ResourcePositionMessage& value)noexcept override{
        packets.push_back({value.route==u::MessageRoute::mode_zero?0x811190u:0x810870u,value.resource,value.actor,value.operation,std::bit_cast<unsigned>(value.position.x),std::bit_cast<unsigned>(value.position.y),std::bit_cast<unsigned>(value.position.z),0,0});
        if(mutate){auto item=*f->q.resources.get(*f->q.resources.slot(3));item.instance_index=6;check(f->q.resources.replace(*f->q.resources.slot(3),item)==s::SceneStatus::completed);f->q.world.primary(0)->position={17,18,19};}
        return available;
    }
};
void sync_record(Consuming& f,unsigned index,const s::SceneDescriptor& item){sync(f.q,index,item);const auto raw=address(index);f.q.memory[raw+1]=item.room;put(f.q.memory,raw+4,item.authored_id);put(f.q.memory,raw+8,item.position);put(f.q.memory,raw+0x14,item.tilt);put(f.q.memory,raw+0x16,item.yaw);const auto model=std::dynamic_pointer_cast<g::ResourceModel>(item.primary);put(f.q.memory,raw+0x1c,model?f.q.address(f.q.models.identity_of(*model)):0u);}
void compare_record(Consuming& f,unsigned index){compare_all(f.q,index);const auto item=*f.q.resources.get(*f.q.resources.slot(index));const auto raw=address(index);check(item.room==f.q.memory[raw+1]&&item.authored_id==get<std::uint16_t>(f.q.memory,raw+4)&&item.tilt==get<std::uint16_t>(f.q.memory,raw+0x14)&&item.yaw==get<std::uint16_t>(f.q.memory,raw+0x16)&&std::memcmp(&item.position,f.q.memory+raw+8,12)==0);const auto model=std::dynamic_pointer_cast<g::ResourceModel>(item.primary);check((model?f.q.address(f.q.models.identity_of(*model)):0u)==get<unsigned>(f.q.memory,raw+0x1c));}
}
void deployment_message_port(std::uint8_t* memory,R5900Context* context){
    using namespace deployment_fixture;const auto raw=GPR_U32(context,5);check(GPR_U32(context,4)==5&&GPR_U32(context,6)==0&&GPR_U32(context,7)==4&&memory[raw]==9&&memory[raw+1]==20);
    source_packets.push_back({context->pc,get<std::uint16_t>(memory,raw+4),memory[raw+6],memory[raw+7],get<unsigned>(memory,raw+8),get<unsigned>(memory,raw+12),get<unsigned>(memory,raw+16),0,0});
    if(mutate){memory[pair_fixture::address(3)+2]=6;put(memory,0x4a5c30+0x38,m::Vector{17,18,19});}
}
void compare_resource_deployment(const std::vector<std::vector<std::byte>>& corpus,const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    using namespace deployment_fixture;namespace a=reo::native::gameplay_audio;namespace b=reo::native::audio_banks::v2;namespace l=reo::native::gameplay_lighting;
    const auto assets=factory_load(static_path,16),banks=factory_load(template_path,5);
    for(unsigned asset=0;asset<corpus.size();asset+=2)for(unsigned primary=0;primary<4;++primary)for(unsigned bank_index=0;bank_index<banks.size();++bank_index){
        std::cerr<<"deployment bank "<<asset<<","<<primary<<","<<bank_index<<"\n";
        Sink sink;Consuming f(ram,assets[primary],banks[bank_index],&sink);sink.f=&f;prepare(f.q.memory,corpus[asset],corpus[asset+1],0x1800000);put(f.q.memory,0x294e00,m::identity());unsigned offset{},length{};std::memcpy(&offset,assets[primary].data()+0x24,4);std::memcpy(&length,assets[primary].data()+0x28,4);std::memcpy(f.q.memory+0x1000000,assets[primary].data()+offset,length);call(f.q.memory,0x1d3100,{0x70000,0x1000000});
        auto effects=e::EffectBank::import(corpus[asset],corpus[asset+1]);auto engine=std::make_shared<b::Session>();a::Owner audio(engine,f.q.session->random);a::SpatialContext spatial;spatial.world_to_screen=m::identity();g::animation_events::BasicAudio frontend(f.q.world,audio,spatial,f.q.resources,f.q.templates);s::Lighting lighting;l::Pool lights(lighting);l::TimedLights timed(f.q.world,f.update.linked(),lights);e::NativeResourceCompanionActions actions(f.q.world,f.q.resources,f.q.models,f.q.templates,frontend,timed);e::PeriodicVisuals visuals(effects,f.q.session->random);check(visuals.bind_resource_companions(f.q.world,f.q.resources,f.q.models,f.q.templates,actions)&&f.q.factory.bind_companions(visuals));g::ResourceDeployment deployment(f.recipes,f.update);
        // Publish the previous case only for cleanup: retain() is absent before
        // the first update and intentionally does not enumerate newly created work.
        const auto reset=[&](){check(visuals.update({}).status==e::VisualStatus::completed);const auto frame=visuals.retain();check(bool(frame));for(const auto& value:frame->visuals)check(visuals.retire(value.id));check(!visuals.size());call(f.q.memory,0x651850);while(const auto id=f.q.models.head()){const auto raw=f.q.address(id);call(f.q.memory,0x590d80,{raw});check(f.q.models.retire(id)==g::ResourceModelStatus::completed);}f.q.session->random.restore({});put(f.q.memory,0x3244b0,std::uint16_t(0));put(f.q.memory,0x3244b8,std::uint16_t(0));f.q.memory[0x2b8de8]=0;for(unsigned index=0;index<256;++index){s::SceneDescriptor item;item.instance_index=std::uint8_t(index);sync_record(f,index,item);}sink.packets.clear();source_packets.clear();mutate=false;};
        reset();
        for(unsigned n=0;n<256;++n){
            reset();const auto count=n%65;for(unsigned i=0;i<count;++i){const auto expected=call(f.q.memory,0x590c70);const auto created=f.q.models.create();check(created.status==g::ResourceModelStatus::completed&&GPR_U32(&expected,2)==f.q.address(created.id));auto& model=*created.model;const auto raw=f.q.address(created.id);model.active=bool((n+i)%7);model.visible=bool((n+i)%5);model.content_id=std::uint16_t((n+i)%11?0x3200:42);model.resource_slot=std::uint8_t((i+n)%256);f.q.memory[raw]=std::uint8_t(model.active);f.q.memory[raw+1]=std::uint8_t(model.visible);put(f.q.memory,raw+0x36,model.content_id);f.q.memory[raw+0x240]=model.resource_slot;s::SceneDescriptor item;item.active=std::uint8_t((n+i)%3);sync_record(f,model.resource_slot,item);}
            const auto expected=call(f.q.memory,0x5b5af0);const auto native=deployment.count();check(native.status==g::ResourceModelStatus::completed&&native.value==std::bit_cast<std::int8_t>(std::uint8_t(GPR_U32(&expected,2))));++deployment_counts;
        }
        reset();
        for(unsigned n=0;n<(asset?4096u:65536u);++n){s::SceneDescriptor item;item.active=std::uint8_t(n%5);item.instance_index=3;item.ownership_tag=std::uint16_t(n%7);item.parameter=std::bit_cast<std::int16_t>(std::uint16_t(n*65521u));item.attachment_id=std::uint16_t(n%3?0x3201:42);item.template_index=n%13?std::uint8_t(n%f.q.templates.state().count):255;sync_record(f,3,item);const auto expected=call(f.q.memory,0x5b2770,{0xabcd0003});const auto result=deployment.admission(0xabcd0003);check(result.status==g::ResourceModelStatus::completed&&result.value==std::bit_cast<std::int8_t>(std::uint8_t(GPR_U32(&expected,2))));++deployment_admissions;}
        for(unsigned method=0;method<2;++method)for(unsigned n=0;n<64;++n){
            reset();const auto actor=f.q.world.primary(0);actor->room=std::uint16_t(n%3==0?1:n%3==1?0x101:2);actor->position={float(int(n)-30),float(int(n%17)-8),float(n%11)};put(f.q.memory,0x4a5c30+0x1e2,actor->room);put(f.q.memory,0x4a5c30+0x38,m::Vector{actor->position.x,actor->position.y,actor->position.z});f.mode(n%4,0);f.q.session->message_phase=std::bit_cast<std::int8_t>(std::uint8_t(n%3));f.q.memory[0x3243fb]=std::uint8_t(n%3);mutate=n%7==0;
            for(unsigned index:{3u,6u}){s::SceneDescriptor item;item.active=std::uint8_t(n%5);item.room=33;item.instance_index=std::uint8_t(index);item.attachment_id=std::uint16_t(n%13?0x3201:42);item.template_index=std::bit_cast<std::uint8_t>(f.q.templates.selector(std::int16_t(item.attachment_id)));item.ownership_tag=1;item.parameter=17;item.flags=n*1664525u;item.authored_id=99;item.tilt=11;item.yaw=22;item.position={-1,-2,-3};sync_record(f,index,item);}
            const auto id=f.q.world.identity(0);if(method==0){call(f.q.memory,0x5b5cb0,{0x4a5c30,0xabcd0003,0x4a5c30+0x38});const auto result=deployment.place(id,0xabcd0003,actor->position);check(result.status==g::ResourceModelStatus::completed);++deployment_cases;}
            else{const auto expected=call(f.q.memory,0x5b26d0,{address(3),0x4a5c30});const auto result=deployment.effect(3,id);check(result.status==g::ResourceModelStatus::completed&&result.value==std::bit_cast<std::int8_t>(std::uint8_t(GPR_U32(&expected,2))));++deployment_effects;}
            compare_record(f,3);compare_record(f,6);f.q.compare_world();check(source_packets==sink.packets&&visuals.size()==168u-get<std::uint16_t>(f.q.memory,0x3b5828)&&visuals.piece_count()==256u-get<std::uint16_t>(f.q.memory,0x3b5820));deployment_messages+=unsigned(sink.packets.size());check(f.q.session->random.state()==reo::native::gameplay_session::RandomState{get<std::uint16_t>(f.q.memory,0x3244b0),get<std::uint16_t>(f.q.memory,0x3244b8),f.q.memory[0x2b8de8]});
        }
        // Full narrowing domain for the position-message frontend, including
        // raw float payloads and every mode byte. No numerical conversion occurs.
        reset();
        for(unsigned n=0;n<(asset?4096u:65536u);++n){
            f.mode(n/256,0);const auto phase=std::array<std::uint8_t,6>{0,1,2,3,128,255}[n%6];f.q.session->message_phase=std::bit_cast<std::int8_t>(phase);f.q.memory[0x3243fb]=phase;
            const g::Position position{std::bit_cast<float>(n*65537u),std::bit_cast<float>(0x80000000u|(n<<16)),std::bit_cast<float>(n%2?0x7f800000u:0xffc01234u)};put(f.q.memory,0x120000,position);sink.packets.clear();source_packets.clear();
            call(f.q.memory,0x5b5940,{0xabcd0000u|n,0x12340000u|n,0x56780000u|(n*257u),0x120000});
            check(f.update.record_resource_position(0xabcd0000u|n,0x12340000u|n,0x56780000u|(n*257u),position)==u::PublicationStatus::completed&&source_packets==sink.packets);++deployment_frontends;
        }
        // Real repeated conversion retains the former primary and the shared
        // secondary. Counting is per model, so duplicate descriptor references
        // remain separate deployed instances and affect the eleven-item limit.
        reset();f.mode(0,0);f.q.session->message_phase=0;f.q.memory[0x3243fb]=0;const auto actor=f.q.world.primary(0);actor->room=1;actor->position={12,-3,37};put(f.q.memory,0x4a5c30+0x1e2,actor->room);put(f.q.memory,0x4a5c30+0x38,actor->position);
        s::SceneDescriptor deployed;deployed.active=1;deployed.instance_index=3;deployed.room=1;deployed.attachment_id=0x3201;deployed.template_index=std::bit_cast<std::uint8_t>(f.q.templates.selector(0x3201));deployed.ownership_tag=1;deployed.parameter=17;deployed.shape_profile=1;deployed.position={100,-7,200};
        auto [old,old_raw]=f.q.create(42,7);old.model->resource_slot=3;f.q.memory[old_raw+0x240]=3;deployed.primary=old.model;f.q.sync(deployed);sync_record(f,3,deployed);call(f.q.memory,0x591860,{address(3)});const auto collision=f.q.collisions.replace(*f.q.resources.slot(3));check(collision.status==s::ResourceCollisionStatus::completed);
        const auto secondary=f.q.resources.get(*f.q.resources.slot(3))->secondary;
        for(unsigned n=0;n<3;++n){auto item=*f.q.resources.get(*f.q.resources.slot(3));item.attachment_id=0x3201;item.template_index=std::bit_cast<std::uint8_t>(f.q.templates.selector(0x3201));check(f.q.resources.replace(*f.q.resources.slot(3),item)==s::SceneStatus::completed);put(f.q.memory,address(3)+6,item.attachment_id);f.q.memory[address(3)+0x2b]=item.template_index;
            call(f.q.memory,0x5b5cb0,{0x4a5c30,3,0x4a5c30+0x38});check(deployment.place(f.q.world.identity(0),3,actor->position).status==g::ResourceModelStatus::completed);compare_record(f,3);f.q.compare_world();check(old.model->current()&&f.q.resources.get(*f.q.resources.slot(3))->secondary==secondary&&f.q.models.available()==62-n);const auto expected=call(f.q.memory,0x5b5af0);check(deployment.count().value==std::int8_t(GPR_U32(&expected,2)));++deployment_lifecycle;
        }
        deployed.primary.reset();
        reset();
        for(unsigned n=0;n<64;++n){const auto expected=call(f.q.memory,0x590c70);const auto made=f.q.models.create();check(made.status==g::ResourceModelStatus::completed&&f.q.address(made.id)==GPR_U32(&expected,2));const auto raw=f.q.address(made.id);made.model->active=made.model->visible=true;made.model->content_id=0x3200;made.model->resource_slot=6;f.q.memory[raw]=f.q.memory[raw+1]=1;put(f.q.memory,raw+0x36,std::uint16_t(0x3200));f.q.memory[raw+0x240]=6;s::SceneDescriptor item;item.active=255;item.instance_index=6;sync_record(f,6,item);const auto counted=call(f.q.memory,0x5b5af0);check(deployment.count().value==std::int8_t(GPR_U32(&counted,2))&&unsigned(std::uint8_t(deployment.count().value))==n+1);
            if(n>=10){sync_record(f,3,deployed);const auto effect=call(f.q.memory,0x5b26d0,{address(3),0});const auto actual=deployment.effect(3,{});check(!GPR_U32(&effect,2)&&actual.status==g::ResourceModelStatus::completed&&!actual.value&&source_packets.empty()&&sink.packets.empty());}++deployment_capacity;
        }
        // Capacity failure still converts the descriptor and retains its prior
        // primary, then the effect reports4 exactly as the source does.
        auto item=deployed;item.primary.reset();item.secondary.reset();sync_record(f,3,item);call(f.q.memory,0x5b5cb0,{0x4a5c30,3,0x4a5c30+0x38});check(deployment.place(f.q.world.identity(0),3,actor->position).status==g::ResourceModelStatus::full);compare_record(f,3);++deployment_capacity;
        for(auto id=f.q.models.head();id;id=f.q.models.next(id)){f.q.models.retain(id)->content_id=42;put(f.q.memory,f.q.address(id)+0x36,std::uint16_t(42));}
        sync_record(f,3,item);const auto source_full=call(f.q.memory,0x5b26d0,{address(3),0x4a5c30});const auto native_full=deployment.effect(3,f.q.world.identity(0));check(native_full.status==g::ResourceModelStatus::completed&&native_full.value==4&&native_full.value==std::int8_t(GPR_U32(&source_full,2)));compare_record(f,3);++deployment_capacity;
        reset();
        check(f.update.record_resource_position(1,2,3,{})==u::PublicationStatus::completed);f.q.session->message_phase=1;
        check(f.update.record_resource_position(1,2,3,{})==u::PublicationStatus::unavailable);sink.available=false;f.mode(0,0);check(f.update.record_resource_position(1,2,3,g::Position{})==u::PublicationStatus::message_unavailable);sink.available=true;deployment_refusals+=2;
        sync_record(f,3,deployed);check(deployment.place({},0x10000u|3u,actor->position).status==g::ResourceModelStatus::unavailable);const auto prefix=*f.q.resources.get(*f.q.resources.slot(3));check(prefix.attachment_id==0x3200&&prefix.ownership_tag==0&&prefix.room==1&&prefix.position.x==100);++deployment_refusals;
        sync_record(f,3,deployed);check(deployment.place(f.q.world.identity(0),3,{std::numeric_limits<float>::quiet_NaN(),0,0}).status==g::ResourceModelStatus::unavailable);check(f.q.resources.get(*f.q.resources.slot(3))->attachment_id==0x3200&&f.q.resources.get(*f.q.resources.slot(3))->position.x==100);++deployment_refusals;
        check(deployment.place({},0x100u,{}).status==g::ResourceModelStatus::unavailable);++deployment_refusals;
        reset();visuals.close();check(f.update.close()==u::Status::completed);check(deployment.count().status==g::ResourceModelStatus::closed&&deployment.admission(3).status==g::ResourceModelStatus::closed&&deployment.place({},3,{}).status==g::ResourceModelStatus::closed&&deployment.effect(3,{}).status==g::ResourceModelStatus::closed);++deployment_refusals;
    }
}
