#include "game/native/gameplay_world/resource_health_effects.hpp"
unsigned health_cases{},health_event_cases{},health_ui_cases{},health_refusals{};
namespace health_fixture {
using namespace consumption_fixture;
using Observation=std::array<unsigned,8>;
std::vector<Observation> observed;unsigned mapped{};
struct Sink:u::GameplayMessageSink {
    std::vector<Observation> events;bool available{true};
    bool send(const u::ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const u::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const u::ActorStatusMessage& value)noexcept override{
        events.push_back({value.route==u::MessageRoute::mode_zero?0x811190u:0x810870u,value.channel,14,12,value.status,std::uint16_t(value.health),0,0});return available;
    }
    std::optional<unsigned> room_owner(u::MessageRoute route,std::uint16_t room)noexcept override{events.push_back({route==u::MessageRoute::mode_zero?0x811d40u:0x8115f0u,room,0,0,0,0,0,0});return mapped;}
};
struct Ui:g::ResourceHealthUi {
    Consuming& f;std::vector<Observation>& events;unsigned failure{};
    Ui(Consuming& owner,std::vector<Observation>& output):f(owner),events(output){}
    bool bound_to(const g::World& world)const noexcept override{return &world==&f.q.world&&!world.closed();}
    bool close()noexcept override{events.push_back({0x6e1430,f.q.session->inventory_owner,0,0,0,0,0,0});return failure!=1;}
    bool feedback(const g::actors::EntityId& id,std::uint8_t selector)noexcept override{unsigned slot=4;for(unsigned i=0;i<4;++i)if(f.q.world.identity(i)==id)slot=i;events.push_back({0x665ca0,slot,selector,0,0,0,0,0});return failure!=2;}
    bool message(const g::ResourceHealthNotice& value)noexcept override{events.push_back({0x1c1ce0,value.text,0,0,0,0,0,0});events.push_back({0x1b4820,value.kind,value.x,value.y,value.width,value.height,value.text,0});return failure!=value.text-29;}
};
void actors(Consuming& f,unsigned n){
    for(unsigned i=0;i<4;++i){const auto actor=f.q.world.primary(i);actor->status=n%7?(n&3u)|(n%5?0u:8u)|(n%11?0u:0x10000000u):n*1664525u;actor->auxiliary_status=n*1013904223u;actor->current=std::bit_cast<std::int16_t>(std::uint16_t(n*65521u));actor->maximum=std::bit_cast<std::int16_t>(std::uint16_t(n*16645u));f.actor(i,std::uint8_t(n%17?0:n%3),std::uint8_t(n>>8));const auto at=0x4a5c30+0x10e0*i;put(f.q.memory,at+0x544,actor->current);put(f.q.memory,at+0x546,actor->maximum);put(f.q.memory,at+0xba0,actor->status);put(f.q.memory,at+0xba4,actor->auxiliary_status);}
}
void compare_actors(Consuming& f){for(unsigned i=0;i<4;++i){const auto actor=f.q.world.primary(i);const auto at=0x4a5c30+0x10e0*i;check(actor->current==get<std::int16_t>(f.q.memory,at+0x544)&&actor->maximum==get<std::int16_t>(f.q.memory,at+0x546)&&actor->status==get<unsigned>(f.q.memory,at+0xba0)&&actor->auxiliary_status==get<unsigned>(f.q.memory,at+0xba4));}check(f.q.session->inventory_owner==f.q.memory[0x4badee]);}
}
void health_message_port(std::uint8_t* memory,R5900Context* context){
    using namespace health_fixture;const auto at=GPR_U32(context,5);check(memory[at]==14&&memory[at+1]==12&&GPR_U32(context,6)==0&&GPR_U32(context,7)==4);
    observed.push_back({context->pc,GPR_U32(context,4),14,12,get<unsigned>(memory,at+4),get<std::uint16_t>(memory,at+8),0,0});
}
void health_ui_port(std::uint8_t* memory,R5900Context* context){
    using namespace health_fixture;switch(context->pc){
    case 0x6e1430:observed.push_back({0x6e1430,memory[0x4badee],0,0,0,0,0,0});return;
    case 0x665ca0:check(GPR_U32(context,4)>=0x4a5c30&&(GPR_U32(context,4)-0x4a5c30)%0x10e0==0);observed.push_back({0x665ca0,(GPR_U32(context,4)-0x4a5c30)/0x10e0,GPR_U32(context,5),0,0,0,0,0});return;
    case 0x1c1ce0:{const auto text=GPR_U32(context,4);check(text==32||text==33);observed.push_back({0x1c1ce0,text,0,0,0,0,0,0});SET_GPR_U32(context,2,0x180000+16*text);return;}
    case 0x1b4820:check(GPR_U32(context,9)>=0x180000&&(GPR_U32(context,9)-0x180000)%16==0);observed.push_back({0x1b4820,GPR_U32(context,4),GPR_U32(context,5),GPR_U32(context,6),GPR_U32(context,7),GPR_U32(context,8),(GPR_U32(context,9)-0x180000)/16,0});return;
    case 0x811d40:case 0x8115f0:observed.push_back({context->pc,GPR_U32(context,4),0,0,0,0,0,0});SET_GPR_U32(context,2,mapped);return;
    default:throw std::runtime_error("Unknown item-health UI/message oracle port");
    }
}
void compare_resource_health(const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    using namespace health_fixture;const auto assets=factory_load(static_path,16);auto banks=factory_load(template_path,5);
    for(unsigned high=0;high<2;++high){std::vector<std::byte> data(32+128*24);const auto write=[&]<class T>(unsigned at,T v){std::memcpy(data.data()+at,&v,sizeof v);};write(0,3u);write(4,128u);write(16,32u);for(unsigned i=0;i<128;++i){write(32+i*24,0x40004u);write(32+i*24+10,std::uint16_t(i+128*high));write(32+i*24+18,std::uint16_t(300+i%19));}banks.push_back(data);}
    for(unsigned bank=0;bank<banks.size();++bank){Sink sink;Consuming f(ram,assets[0],banks[bank],&sink);Ui ui(f,sink.events);g::ResourceHealthEffects health(f.recipes,f.update,&ui);
        const auto run=[&](unsigned n,unsigned content,unsigned selector,unsigned mode,unsigned phase,bool null_actor){
            f.mode(mode,(n/4096)%4);f.q.session->message_phase=std::bit_cast<std::int8_t>(std::uint8_t(phase));f.q.memory[0x3243fb]=std::uint8_t(phase);f.q.session->actor_message_suppression=std::uint16_t(n%19?0:14);put(f.q.memory,0x744638,f.q.session->actor_message_suppression);f.q.world.paused=std::bit_cast<std::int8_t>(std::uint8_t(n%23?0:n));f.q.memory[0x4badf8]=std::uint8_t(f.q.world.paused);f.q.session->inventory_owner=std::uint8_t(n);f.q.memory[0x4badee]=std::uint8_t(n);f.reset_statistics(n*65521u);health_fixture::actors(f,n);mapped=n*65521u;observed.clear();sink.events.clear();
            s::SceneDescriptor item;item.active=std::uint8_t(n%5?1:0);item.instance_index=3;item.ownership_tag=std::uint16_t(1+n%4);item.attachment_id=std::uint16_t(content);item.parameter=17;item.template_index=std::uint8_t(selector);sync(f.q,3,item);const auto slot=n%4;const auto id=null_actor?g::actors::EntityId{}:f.q.world.identity(slot);const auto expected=call(f.q.memory,0x5b2230,{address(3),null_actor?0u:0x4a5c30+0x10e0*slot});const auto result=health.apply(0xabcd0003,id);
            if(result.status!=g::ResourceHealthStatus::completed||result.value!=std::uint8_t(GPR_U32(&expected,2)))throw std::runtime_error("Item health result bank="+std::to_string(bank)+" n="+std::to_string(n)+" content="+std::to_string(content));
            compare_actors(f);compare_all(f.q,3);f.compare_statistics();check(observed==sink.events);if(!sink.events.empty())++health_ui_cases;++health_cases;
        };
        for(unsigned n=0;n<65536;++n){const auto content=300+n%19;const auto selector=bank<5?std::uint8_t(f.q.templates.selector(std::int16_t(content))):std::uint8_t(n%128);run(n,content,selector,n>>8,n,n%29==0);}
        for(unsigned n=1;n<4096;++n){const auto content=300+n%19;const auto selector=bank<5?std::uint8_t(f.q.templates.selector(std::int16_t(content))):std::uint8_t(n%128);run(n,content,selector,n%4,1+n%2,false);}
        if(bank==0){
            for(unsigned n=0;n<65536;++n){f.reset(0);health_fixture::actors(f,n);f.mode(n>>8,(n/4096)%4);s::SceneDescriptor item;item.ownership_tag=std::uint16_t(1+n%4);item.attachment_id=std::uint16_t(n%3?300+n%19:10100);sync(f.q,3,item);const auto slot=(n/4)%4;call(f.q.memory,0x5b6610,{address(3),n*65521u,0x4a5c30+0x10e0*slot});const auto result=health.publish(3,n*65521u,f.q.world.identity(slot));check(result.status==g::ResourceHealthStatus::completed);f.compare_events();++health_event_cases;}
            const auto target=f.q.world.primary(0);const auto id=f.q.world.identity(0);f.mode(0,0);f.q.world.paused=0;f.q.memory[0x4badf8]=0;f.q.session->message_phase=0;f.q.memory[0x3243fb]=0;f.q.session->inventory_owner=0;f.q.memory[0x4badee]=0;f.reset_statistics(0);
            s::SceneDescriptor item;item.active=1;item.instance_index=3;item.ownership_tag=1;item.attachment_id=300;item.template_index=std::uint8_t(f.q.templates.selector(300));sync(f.q,3,item);
            const auto target_state=[&](unsigned status){target->status=status;target->category=0;target->slot=0;target->current=0;target->maximum=100;target->auxiliary_status=0;f.actor(0,0,0);put(f.q.memory,0x4a5c30+0x544,target->current);put(f.q.memory,0x4a5c30+0x546,target->maximum);put(f.q.memory,0x4a5c30+0xba0,status);put(f.q.memory,0x4a5c30+0xba4,0u);};
            target_state(0);for(unsigned i=0;i<128;++i){call(f.q.memory,0x37bfb0,{i});check(f.update.record_simple_event(i).status==reo::native::gameplay_events::Status::completed);}call(f.q.memory,0x5b2230,{address(3),0x4a5c30});auto result=health.apply(3,id);check(result.status==g::ResourceHealthStatus::completed&&result.value==1&&f.update.cooperative_events().available()==0&&health.last_event()&&(health.last_event()==reo::native::gameplay_events::Status::full||health.last_event()==reo::native::gameplay_events::Status::priority_rejected));compare_actors(f);f.compare_statistics();++health_cases;
            // A missing amount is required only if the original actually reads
            // it; status8 uses fixed300 and admits the same unknown content.
            item.attachment_id=50000;sync(f.q,3,item);target_state(0);result=health.apply(3,id);check(result.status==g::ResourceHealthStatus::healing_unavailable&&target->current==0&&target->auxiliary_status==0);++health_refusals;
            target_state(8);call(f.q.memory,0x5b2230,{address(3),0x4a5c30});result=health.apply(3,id);check(result.status==g::ResourceHealthStatus::completed&&result.value==1);compare_actors(f);f.compare_statistics();++health_cases;
            item.attachment_id=300;item.ownership_tag=0;sync(f.q,3,item);target_state(0);result=health.apply(3,id);check(result.status==g::ResourceHealthStatus::unavailable&&target->current==100&&target->auxiliary_status==0x20);++health_refusals;
            item.ownership_tag=2;sync(f.q,3,item);f.actor(1,0,0);call(f.q.memory,0x5b6610,{address(3),1,0});check(health.publish(3,1,{}).status==g::ResourceHealthStatus::completed);f.compare_events();++health_event_cases;
            item.ownership_tag=1;item.attachment_id=0x138;item.template_index=255;sync(f.q,3,item);for(unsigned fail=1;fail<=4;++fail){target_state(0);f.q.session->inventory_owner=3;ui.failure=fail;sink.events.clear();result=health.apply(3,id);check(result.status==g::ResourceHealthStatus::ui_unavailable&&target->auxiliary_status==0x1000&&f.q.session->inventory_owner==0&&sink.events.size()==std::array<unsigned,4>{1,2,4,6}[fail-1]&&!health.last_event());++health_refusals;}ui.failure=0;
            item.attachment_id=301;item.template_index=std::uint8_t(f.q.templates.selector(306));sync(f.q,3,item);target_state(1);f.q.session->message_phase=1;f.q.session->actor_message_suppression=0;sink.available=false;result=health.apply(3,id);check(result.status==g::ResourceHealthStatus::message_unavailable&&target->status==0&&target->current==0&&target->auxiliary_status==0x20&&!health.last_event());++health_refusals;sink.available=true;
            check(health.apply(UINT32_MAX,{}).status==g::ResourceHealthStatus::completed);++health_refusals;
        }
        // Unavailable UI is observed after the known flag/gate prefix.
        f.mode(0,0);const auto actor=f.q.world.primary(0);actor->category=0;actor->slot=0;actor->status=0;actor->auxiliary_status=0;f.q.session->inventory_owner=3;s::SceneDescriptor special;special.active=1;special.instance_index=3;special.ownership_tag=1;special.attachment_id=0x138;special.template_index=255;sync(f.q,3,special);g::ResourceHealthEffects absent(f.recipes,f.update);const auto result=absent.apply(3,f.q.world.identity(0));check(result.status==g::ResourceHealthStatus::ui_unavailable&&(actor->auxiliary_status&0x1000u)&&f.q.session->inventory_owner==0);++health_refusals;
    }
}
