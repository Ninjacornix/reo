#include "game/native/gameplay_world/linked_resource_flight.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>
namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;namespace d=reo::native::gameplay_collision::delivery;
unsigned checks{},calls{},cases{},constructors{},requests{},failures{};
void check(bool v,std::source_location at=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Linked flight "+std::to_string(at.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,unsigned at,T v){transform_write(p,at,v);}
struct Event {unsigned kind{},selector{};m::Vector point;friend bool operator==(const Event& a,const Event& b){return a.kind==b.kind&&a.selector==b.selector&&std::memcmp(&a.point,&b.point,12)==0;}};
struct Effects final:g::LinkedFlightEffects {
    std::vector<Event> events;reo::native::gameplay_collision::response::Floor sampled;unsigned reject{};
    bool bound_to(const g::World&)const noexcept override{return true;}
    std::optional<reo::native::gameplay_collision::response::Floor> floor(m::Vector p)override{events.push_back({1,255,p});if(reject==1)return{};return sampled;}
    bool burst(const g::actors::EntityId&,m::Vector p)override{events.push_back({2,0x6a,p});return reject!=2;}
    bool light(const g::actors::EntityId&,m::Vector p)override{events.push_back({3,0,p});return reject!=3;}
    bool sound(const g::actors::EntityId&,std::uint8_t s)override{events.push_back({4,s,{}});return reject!=4;}
    bool packet(const g::actors::EntityId&,std::uint8_t s)override{events.push_back({5,s,{}});return reject!=5;}
} effects;
std::vector<Event> original_events;unsigned packet_descriptor{},packet_bank{},packet_calls{};
constexpr unsigned base=0x3ec410,stride=0x1f0,work_at=0x20000,model_at=0x22000,parent_at=0x24000;
#ifdef REO_LINKED_FLIGHT_OWNER
bool linked_owner_port(std::uint8_t*,R5900Context*);
#endif
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
#ifdef REO_LINKED_FLIGHT_OWNER
    if(linked_owner_port(memory,context)){context->pc=GPR_U32(context,31);return;}
#endif
    switch(context->pc){
    case 0x107c68:{auto at=GPR_U32(context,4),size=GPR_U32(context,6);check(at>=base&&size<=base+64*stride-at&&GPR_U32(context,5)==0);std::memset(memory+at,0,size);SET_GPR_U32(context,2,at);break;}
    case 0x616f20:check(GPR_U32(context,6)==255);original_events.push_back({1,255,get<m::Vector>(memory,GPR_U32(context,4))});memory[GPR_U32(context,5)]=effects.sampled.type;context->f[0]=effects.sampled.height;break;
    case 0x5822a0:check(GPR_U32(context,4)==parent_at&&GPR_U32(context,5)==0&&GPR_U32(context,6)==20&&GPR_U32(context,7)==0x6a&&GPR_U32(context,8)==0&&GPR_U32(context,10)==2);original_events.push_back({2,0x6a,get<m::Vector>(memory,GPR_U32(context,9))});SET_GPR_U32(context,2,0);break;
    case 0x6b2760:check(GPR_U32(context,4)==parent_at);original_events.push_back({3,0,get<m::Vector>(memory,GPR_U32(context,5))});break;
    case 0x1ba5e0:check(GPR_U32(context,4)==work_at);original_events.push_back({4,GPR_U32(context,5),{}});break;
    case 0x5da2c0:packet_descriptor=GPR_U32(context,5);packet_bank=GPR_U32(context,6);++packet_calls;if(GPR_U32(context,4)==work_at)original_events.push_back({5,packet_descriptor,{}});SET_GPR_U32(context,2,0);break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted linked flight helper "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
void invoke(std::uint8_t* memory,unsigned pc,std::array<unsigned,7> args={}){
    R5900Context c;PS2Runtime r;c.pc=pc;SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0x1234);for(unsigned i=0;i<7;++i)SET_GPR_U32(&c,4+i,args[i]);
    if(pc==0x5822a0)o2_005822A0_0x5822a0(memory,&c,&r);else original_transform_port(memory,&c,&r);
    check(c.pc==0x1234&&GPR_U32(&c,29)==0x1f00000);
}
void compare_flight(std::uint8_t* memory,g::Actor& actor,g::ResourceModel* model){
    const auto& state=*actor.pose_work;
    check(actor.primary==memory[work_at+8]&&actor.visible==bool(memory[work_at+1])&&actor.auxiliary_status==memory[work_at+0x115]&&actor.contact.serial==memory[work_at+0x116]);
    check(state.timer==get<std::int16_t>(memory,work_at+12)&&state.lifetime==get<std::int16_t>(memory,work_at+18));
    check(std::memcmp(&actor.position,memory+work_at+0x38,12)==0&&std::memcmp(&state.velocity,memory+work_at+0xc0,12)==0&&std::memcmp(actor.previous_orientation.data(),memory+work_at+0x98,8)==0);
    if(model)check(model->flags==get<unsigned>(memory,model_at+0x23c)&&std::memcmp(&model->position,memory+model_at+0x200,12)==0&&std::memcmp(model->angles.data(),memory+model_at+0x21c,6)==0);
    check(effects.events==original_events);requests+=unsigned(effects.events.size());++cases;
}
#ifdef REO_LINKED_FLIGHT_OWNER
#include "tools/native_reconstruction/linked_flight_owner_tests.inc"
#endif
int main(int argc,char** argv)try{
    check(argc==
#ifdef REO_LINKED_FLIGHT_OWNER
        3
#else
        2
#endif
    );std::vector<std::uint8_t> raw(0x2000000);auto* memory=raw.data();owned_constants(memory);
    auto session=std::make_shared<g::Session>();g::Profile profile;profile.layouts.push_back({});profile.entities.capacity=256;g::World world(profile,session);g::PoseWorkPool pool(world);
    const auto parent=world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(parent));
    g::Actor actor;actor.pose_work.emplace();g::ResourceModel model({}, {}, {},0);
    const unsigned contents[]{0,0x71,0x72,0x9b,0x9c,0x9d,0x9e,0x9f,0x100,0xffff};
    const std::int16_t timers[]{INT16_MIN,-1,0,1,2,15,16,60,61,INT16_MAX};
    for(unsigned n=0;n<262144;++n){
        actor.primary=std::uint8_t((n%8)<5?n%2:(n%8)==5?2:(n%8)==6?3:255);actor.visible=n&8;actor.auxiliary_status=std::uint8_t(n>>4);actor.slot=3;actor.contact.related=parent;
        auto& st=*actor.pose_work;st.timer=timers[(n/8)%10];st.lifetime=std::int16_t(n);st.velocity={float(int(n%39)-19)*.125f,float(int(n%17)-8)*.25f,float(int(n%53)-26)*.0625f};
        actor.position={float(int(n%97)-48)*.5f,float(int(n%101)-50)*.25f,float(int(n%71)-35)};actor.orientation={1,std::bit_cast<std::int16_t>(std::uint16_t(n*13)),3,4};actor.previous_orientation={17,-19,23,-29};actor.projectile_contact.normal={float(int(n%7)-3)*.25f,float(int(n%11)-5)*.5f,float(int(n%13)-6)*.125f};
        actor.contact.serial=std::uint8_t((n/80)%5);actor.contact.recipient={255,255};actor.contact.related_recipient={255,255};const unsigned claim=(n/400)%5;if(claim==1)actor.contact.recipient.category=2;if(claim==2)actor.contact.recipient.token=3;if(claim==3)actor.contact.related_recipient.category=1;if(claim==4)actor.contact.related_recipient.token=0;
        model.content_id=std::uint16_t(contents[(n/2000)%10]);model.flags=n%127==0?0x20000:0x1040;model.position={101,103,107};model.use_vector={.25f,6,-.75f};model.use_parameters={-32768,32767,-73,97};model.angles={65535,1,32768};
        const auto clock=std::uint8_t(n/1024);const bool absent=n%257==0;effects.events.clear();original_events.clear();effects.sampled.height=float(int(n%37)-18)*.25f;effects.sampled.type=n&64?255:std::uint8_t(n%8);
        memory[work_at+1]=actor.visible;memory[work_at+8]=actor.primary;memory[work_at+3]=3;memory[work_at+0x115]=std::uint8_t(actor.auxiliary_status);memory[work_at+0x116]=actor.contact.serial;memory[work_at+0x117]=actor.contact.recipient.category;memory[work_at+0x118]=actor.contact.recipient.token;memory[work_at+0x119]=actor.contact.related_recipient.category;memory[work_at+0x11a]=actor.contact.related_recipient.token;
        put(memory,work_at+0x28,parent_at);put(memory,work_at+12,st.timer);put(memory,work_at+18,st.lifetime);put(memory,work_at+0x38,actor.position);put(memory,work_at+0x90,actor.orientation);put(memory,work_at+0x98,actor.previous_orientation);put(memory,work_at+0xc0,st.velocity);put(memory,work_at+0x160,actor.projectile_contact.normal);put(memory,0x3c564c+3*60,absent?0u:model_at);memory[0x3243cc]=clock;
        put(memory,model_at+0x36,model.content_id);put(memory,model_at+0x23c,model.flags);put(memory,model_at+0x200,model.position);put(memory,model_at+0x20c,model.use_vector);put(memory,model_at+0x224,model.use_parameters);put(memory,model_at+0x21c,model.angles);
        invoke(memory,0x583c50,{work_at});check(g::advance_linked_resource_flight(actor,absent?nullptr:&model,clock,{},effects));compare_flight(memory,actor,absent?nullptr:&model);
    }
    // Actual nullable constructor, 64-slot exhaustion, byte narrowing and owned
    // Catalog/Packets allocation. Source packet calls are observations only.
    std::ifstream in(argv[1],std::ios::binary);const std::vector<char> content{std::istreambuf_iterator<char>(in),{}};const auto catalog=d::Catalog::import({reinterpret_cast<const std::byte*>(content.data()),content.size()});d::Packets packets;reo::native::gameplay_scenario::SceneResources resources;reo::native::gameplay_scenario::ResourceTemplates templates;g::ResourcePoseWork factory(world,pool,resources,templates,packets,catalog);
    const m::Matrix matrix{{{{1,2,3,4}},{{5,6,7,8}},{{9,10,11,12}},{{13,14,15,16}}}};const m::Vector point{7,-9,11};put(memory,0x26000,matrix);put(memory,0x27000,point);
    for(unsigned n=0;n<8192;++n){
        invoke(memory,0x581f50);check(pool.reset()==g::PoseWorkStatus::completed);const bool full=n%17==0;if(full)for(unsigned i=0;i<64;++i){invoke(memory,0x581fe0,{1});check(pool.allocate().status==g::PoseWorkStatus::completed);}
        const unsigned descriptor=n|0xabcd0000u,kind=n*31;const std::int32_t life=std::bit_cast<std::int32_t>(n*100003u);const auto before=packet_calls;
        invoke(memory,0x5822a0,{parent_at,0,kind,descriptor,n&1?0x26000u:0u,n&2?0x27000u:0u,std::uint32_t(life)});const auto made=factory.attach(parent,descriptor,kind,0,n&1?&matrix:nullptr,n&2?&point:nullptr,life);
        check(pool.remaining()==get<std::uint16_t>(memory,0x3b55e0));if(full){check(made.status==g::PoseWorkStatus::full&&packet_calls==before);}else{
            const auto native=pool.resolve(made.work);const auto at=get<unsigned>(memory,0x3b55e8);check(native&&native->pose_work&&made.status==g::PoseWorkStatus::completed);const auto& state=*native->pose_work;
            check(native->active==bool(memory[at])&&native->category==memory[at+2]&&native->slot==memory[at+3]&&state.kind==memory[at+4]&&state.selector==memory[at+0x30]&&state.ordinal==memory[at+0x31]&&state.update_bound&&state.lifetime==get<std::int16_t>(memory,at+0x12));
            check(std::memcmp(&native->position,memory+at+0x38,12)==0&&std::memcmp(&state.basis,memory+at+0x50,64)==0&&native->contact.related==parent&&packet_calls==before+1&&packet_bank==0&&packet_descriptor==std::uint8_t(descriptor));
            const auto lease=packets.acquire(made.packet);check(lease&&lease.state().definition==catalog.find(0,std::uint8_t(descriptor)));check(packets.release(made.packet));
        }++constructors;
    }
    // A missing reached provider preserves the original prefix and refuses.
    for(unsigned rejection=1;rejection<=5;++rejection){actor.primary=1;actor.pose_work->timer=60;actor.pose_work->lifetime=-1;actor.contact.serial=1;actor.contact.recipient={255,255};actor.contact.related_recipient={255,255};actor.auxiliary_status=1;model.content_id=0x72;model.flags=0;effects.sampled.type=0;effects.reject=rejection;effects.events.clear();check(!g::advance_linked_resource_flight(actor,&model,0,{},effects)&&actor.primary==1&&actor.pose_work->timer==59&&actor.contact.serial==1);if(rejection==5)check(!(actor.auxiliary_status&1));++failures;}effects.reject=0;
#ifdef REO_LINKED_FLIGHT_OWNER
    linked_owner_checks(memory,catalog,argv[2]);
#endif
    std::cout<<"{\"checks\":"<<checks<<",\"flight_cases\":"<<cases<<",\"constructors\":"<<constructors<<",\"effect_requests\":"<<requests<<",\"original_calls\":"<<calls<<",\"reached_provider_refusals\":"<<failures
#ifdef REO_LINKED_FLIGHT_OWNER
    <<",\"owner_cases\":"<<owner_cases<<",\"owner_frames\":"<<owner_frames<<",\"owner_light_frames\":"<<owner_light_frames<<",\"owner_pcm_frames\":"<<owner_pcm_frames<<",\"owner_pcm_signal\":"<<owner_pcm_signal<<",\"owner_refusals\":"<<owner_refusals
#endif
    <<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
