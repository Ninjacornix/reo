#include "game/native/gameplay_world/motion_transforms.hpp"
#include "game/native/gameplay_world/motion.hpp"
#include "reference.hpp"
#include <iostream>
#include <vector>
namespace g=reo::native::gameplay_world;
namespace t=reo::native::transform_math;
#include "owned_constants.hpp"
#include "functions.h"
constexpr std::uint32_t base=0x10000;
std::uint64_t checks{},local_cases{},pose_cases{},surface_calls{},failure_cases{},frame_cases{},helper_calls{};
void check(bool yes,const char* why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T v){transform_write(p,at,v);}
std::uint32_t random_word(std::uint32_t& x){x^=x<<13;x^=x>>17;x^=x<<5;return x;}
g::Profile profile(){return{{g::input::Remap{0x100,0x20,0x10}},4,{16,UINT64_MAX}};}
t::Matrix matrix(const reo::native::gameplay_collision::actors::Basis& b){return{{{b.x.x,b.x.y,b.x.z,0},{b.y.x,b.y.y,b.y.z,0},{b.z.x,b.z.y,b.z.z,0},{b.translation.x,b.translation.y,b.translation.z,1}}};}
auto basis(const t::Matrix& m){return reo::native::gameplay_collision::actors::Basis{{m[0][0],m[0][1],m[0][2]},{m[1][0],m[1][1],m[1][2]},{m[2][0],m[2][1],m[2][2]},{m[3][0],m[3][1],m[3][2]}};}
g::Actor import_actor(const std::uint8_t* p){
    g::Actor a;a.position=get<g::Position>(p,base+0x38);a.orientation=get<std::array<std::int16_t,4>>(p,base+0x90);a.collision.basis=basis(get<t::Matrix>(p,base+0x50));
    a.candidate_direction=get<g::Position>(p,base+0xa8);a.model_scale=get<g::Position>(p,base+0xb4);a.motion_multiplier=get<float>(p,base+0xf0);a.local_impulse=get<g::Position>(p,base+0xd8);a.world_impulse=get<g::Position>(p,base+0xe4);a.root_motion_delta=get<g::Position>(p,base+0x4e4);a.contact_flags=get<std::uint16_t>(p,base+0x54a);a.collision.pose_ready=true;return a;
}
void export_actor(std::uint8_t* p,const g::Actor& a){
    put(p,base+0x38,a.position);put(p,base+0x90,a.orientation);put(p,base+0x50,matrix(a.collision.basis));put(p,base+0xa8,a.candidate_direction);put(p,base+0xb4,a.model_scale);put(p,base+0xf0,a.motion_multiplier);put(p,base+0xd8,a.local_impulse);put(p,base+0xe4,a.world_impulse);put(p,base+0x4e4,a.root_motion_delta);put(p,base+0x54a,a.contact_flags);
}
using Observation=std::array<std::uint32_t,31>;
Observation observed(const std::uint8_t* memory){
    Observation result{};std::size_t at{};for(auto [offset,count]:{std::pair{0x38u,3u},{0xa8u,3u},{0x50u,16u},{0xd8u,3u},{0xe4u,3u},{0x4e4u,3u}})for(unsigned i=0;i<count;++i)result[at++]=get<std::uint32_t>(memory,base+offset+4*i);return result;
}
Observation observed(const g::Actor& a){
    std::array<float,31> values{};std::size_t i{};const auto vector=[&](const auto& v){values[i++]=v.x;values[i++]=v.y;values[i++]=v.z;};vector(a.position);vector(a.candidate_direction);for(const auto& col:matrix(a.collision.basis))for(auto value:col)values[i++]=value;vector(a.local_impulse);vector(a.world_impulse);vector(a.root_motion_delta);return std::bit_cast<Observation>(values);
}
unsigned provider_seed{};bool provider_throws{};std::vector<Observation> original_observations;
struct Pose final:g::MotionTransformServices {
    g::Actor* expected{};std::vector<Observation> observations;
    void orient_surface(g::World&,g::Actor& a)override{
        check(&a==expected,"surface provider receives canonical actor identity");check(!a.collision.pose_ready,"incomplete pose is not advertised ready");observations.push_back(observed(a));++surface_calls;
        if(provider_seed&1){a.position.x=97.5f;a.position.z=-31.25f;}
        if(provider_seed&2){a.collision.basis.x.y=.375f;a.collision.basis.translation={199,198,197};}
        if(provider_seed&4){a.local_impulse.x=1.25f;a.world_impulse.z=-2.5f;a.root_motion_delta.y=7.75f;}
        if(provider_seed&8){a.orientation[1]=0x1234;a.candidate_direction.y=.625f;}
        if(provider_throws){a.position.y=111.25f;throw std::runtime_error("required native surface/pose owner unavailable");}
    }
};
std::vector<std::uint32_t> call_trace;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++helper_calls;call_trace.push_back(context->pc);
    switch(context->pc){
    case 0x18f570:sub_0018F570_0x18f570(memory,context,runtime);return;
    case 0x18fdf0:sub_0018FDF0_0x18fdf0(memory,context,runtime);return;
    case 0x18fe20:sub_0018FE20_0x18fe20(memory,context,runtime);return;
    case 0x18fe60:sub_0018FE60_0x18fe60(memory,context,runtime);return;
    case 0x1902d0:sub_001902D0_0x1902d0(memory,context,runtime);return;
    case 0x190a10:sub_00190A10_0x190a10(memory,context,runtime);return;
    case 0x191300:sub_00191300_0x191300(memory,context,runtime);return;
    case 0x1919d0:sub_001919D0_0x1919d0(memory,context,runtime);return;
    case 0x191f80:sub_00191F80_0x191f80(memory,context,runtime);return;
    case 0x370220:o0_00370220_0x370220(memory,context,runtime);return;
    case 0x370320:o0_00370320_0x370320(memory,context,runtime);return;
    case 0x6657b0:
        check(GPR_U32(context,4)==base,"source surface provider actor argument");original_observations.push_back(observed(memory));
        if(provider_seed&1){put(memory,base+0x38,97.5f);put(memory,base+0x40,-31.25f);}
        if(provider_seed&2){put(memory,base+0x54,.375f);put(memory,base+0x80,g::Position{199,198,197});}
        if(provider_seed&4){put(memory,base+0xd8,1.25f);put(memory,base+0xec,-2.5f);put(memory,base+0x4e8,7.75f);}
        if(provider_seed&8){put(memory,base+0x92,std::int16_t(0x1234));put(memory,base+0xac,.625f);}
        if(provider_throws){put(memory,base+0x3c,111.25f);throw std::runtime_error("required reference surface owner unavailable");}
        return;
    default:throw std::runtime_error("undeclared original motion-transform entry");
    }
}
#include "original_transforms.cpp"
#include "original_motion_transforms.cpp"
void execute(std::uint8_t* ram,bool pose){
    R5900Context context;context.pc=pose?0x65e4a0:0x65e3a0;SET_GPR_U32(&context,4,base);SET_GPR_U32(&context,29,0x30000);SET_GPR_U32(&context,31,0xabcdef);PS2Runtime runtime;
    if(pose)o2_0065E4A0_0x65e4a0(ram,&context,&runtime);else o2_0065E3A0_0x65e3a0(ram,&context,&runtime);
    check(context.pc==0xabcdef && GPR_U32(&context,29)==0x30000,"complete source motion body returns synchronously");
}
struct Frame final:g::Services,g::MotionServices {
    unsigned local_delegations{},pose_delegations{},queues{},later{};g::Actor* expected{};bool remote{};
    void begin_offline_frame(g::World&)override{}
    void run(g::Stage stage,g::World&,g::Actor& a)override{check(&a==expected,"frame keeps canonical invocation actor");local_delegations+=stage==g::Stage::update_local_motion;pose_delegations+=stage==g::Stage::update_pose;}
    bool remote_motion(g::World&,g::Actor&)override{return remote;}
    bool find_grid(g::World&,g::Actor&,std::int8_t&)override{++later;return false;}
    void switch_grid(g::World&,std::int32_t,std::int32_t)override{}
    float grid_response(g::World&,std::uint8_t)override{return 0;}
    void enqueue(g::World&,g::Actor& a,std::uint16_t,std::uint16_t)override{check(&a==expected && a.collision.pose_ready,"native finish sees completed canonical pose");++queues;}
};
int main()try{
    const auto old_mxcsr=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}} reset{old_mxcsr};_mm_setcsr(0x1f80);
    std::vector<std::uint8_t> actual(0x2000000,0xa5),expected(actual);owned_constants(expected.data());put(expected.data(),0x294e00,t::identity());std::uint32_t random=0x65e4a0;g::World world(profile(),std::make_shared<g::Session>());
    const auto number=[&]{return float(std::int32_t(random_word(random)%2049)-1024)*.125f;};
    for(unsigned seed=0;seed<4096;++seed){
        for(unsigned i=0;i<0x10e0;i+=4)put(actual.data(),base+i,random_word(random));
        put(actual.data(),base+0x38,g::Position{number(),number(),number()});put(actual.data(),base+0x90,std::array<std::int16_t,4>{std::int16_t(random_word(random)),std::int16_t(random_word(random)),std::int16_t(random_word(random)),std::int16_t(random_word(random))});
        auto initial=t::identity();for(auto& col:initial)for(unsigned lane=0;lane<3;++lane)col[lane]=number();put(actual.data(),base+0x50,initial);
        put(actual.data(),base+0xa8,g::Position{number(),number(),number()});put(actual.data(),base+0xb4,g::Position{float(int(seed%7)-3)*.5f,std::bit_cast<float>(0x7f800001u+seed),float(int(seed%9)-4)*.5f});put(actual.data(),base+0xf0,float(int(seed%17)-8)*.25f);
        put(actual.data(),base+0xd8,g::Position{number(),number(),number()});put(actual.data(),base+0xe4,g::Position{number(),number(),number()});put(actual.data(),base+0x4e4,g::Position{number(),number(),number()});put(actual.data(),base+0x54a,std::uint16_t(random_word(random)));
        for(bool pose:{false,true}){
            std::array<std::uint8_t,0x10e0> before;std::copy_n(actual.data()+base,before.size(),before.data());std::copy_n(before.data(),before.size(),expected.data()+base);auto actor=import_actor(actual.data());Pose services;services.expected=&actor;provider_seed=seed;provider_throws=false;original_observations.clear();call_trace.clear();
            if(pose)g::rebuild_actor_pose(world,actor,services);else g::integrate_local_motion(actor);export_actor(actual.data(),actor);execute(expected.data(),pose);
            check(std::memcmp(actual.data()+base,expected.data()+base,0x10e0)==0,"full actor result differs from actual original motion/math chain");check(services.observations==original_observations,"source-ordered provider state differs");
            if(pose){check(actor.collision.pose_ready,"successful affine pose becomes ready");check(services.observations.size()==1 && call_trace.back()==0x6657b0,"required surface provider follows original math calls");++pose_cases;}
            else{check(!actor.collision.pose_ready,"moved position invalidates old pose capability");check(services.observations.empty(),"local root motion does not invent a surface callback");++local_cases;}
            std::copy_n(before.data(),before.size(),actual.data()+base);
        }
    }
    for(unsigned seed=0;seed<16;++seed){
        put(actual.data(),base+0x50,t::identity());put(actual.data(),base+0x38,g::Position{1,2,3});put(actual.data(),base+0x90,std::array<std::int16_t,4>{0,16384,0,123});put(actual.data(),base+0xd8,g::Position{1,2,3});put(actual.data(),base+0xe4,g::Position{4,5,6});put(actual.data(),base+0x4e4,g::Position{7,8,9});
        std::copy_n(actual.data()+base,0x10e0,expected.data()+base);auto actor=import_actor(actual.data());Pose services;services.expected=&actor;provider_seed=seed;provider_throws=true;original_observations.clear();bool native_failed{},reference_failed{};
        try{g::rebuild_actor_pose(world,actor,services);}catch(const std::runtime_error&){native_failed=true;}export_actor(actual.data(),actor);
        try{execute(expected.data(),true);}catch(const std::runtime_error&){reference_failed=true;}
        check(native_failed && reference_failed && !actor.collision.pose_ready,"required surface failure remains visible and pose unavailable");check(std::memcmp(actual.data()+base,expected.data()+base,0x10e0)==0,"partial impulse/provider effects differ after failure");check(services.observations==original_observations,"failed provider observes exact preceding state");++failure_cases;
    }
    // Scale is not consumed when source mask0x8 skips that operation. Refusing
    // these unused values would narrow the actual branch contract incorrectly.
    put(actual.data(),base+0x38,g::Position{1,2,3});put(actual.data(),base+0x50,t::identity());put(actual.data(),base+0x90,std::array<std::int16_t,4>{0,0,0,0});put(actual.data(),base+0xb4,g::Position{NAN,NAN,INFINITY});put(actual.data(),base+0xf0,1.f);put(actual.data(),base+0x4e4,g::Position{2,3,4});put(actual.data(),base+0x54a,std::uint16_t(8));
    std::copy_n(actual.data()+base,0x10e0,expected.data()+base);auto no_scale=import_actor(actual.data());g::integrate_local_motion(no_scale);export_actor(actual.data(),no_scale);execute(expected.data(),false);check(std::memcmp(actual.data()+base,expected.data()+base,0x10e0)==0,"unused model-scale values do not become mandatory admission");++local_cases;
    provider_throws=false;provider_seed=0;
    for(bool remote:{false,true}){
        g::World owned(profile(),std::make_shared<g::Session>());owned.room=1;auto actor=std::make_unique<g::Actor>();actor->active=true;actor->room=1;actor->slot=0;actor->root_motion_delta={2,0,0};actor->local_impulse={3,0,0};actor->world_impulse={4,0,0};
        check(owned.spawn_primary(0,std::move(actor)).status==g::actors::EntityStatus::completed,"canonical frame actor admitted");auto lease=owned.primary(0);Frame frame;frame.expected=lease.get();frame.remote=remote;Pose pose;pose.expected=lease.get();g::MotionFrameServices auxiliary(frame,frame);g::MotionTransformFrameServices transforms(auxiliary,pose);
        const auto result=owned.update_primary(transforms);check(result.status==g::Status::completed && result.updated==1 && frame.later==1 && frame.local_delegations==0 && frame.pose_delegations==0,"actual World selects native transform consumers");check(lease->collision.pose_ready && lease->position.x==(remote?7.f:9.f),"remote branch skips local root but still consumes impulse pose");++frame_cases;
    }
    {
        g::World owned(profile(),std::make_shared<g::Session>());owned.room=1;auto actor=std::make_unique<g::Actor>();actor->active=true;actor->room=1;actor->slot=0;actor->root_motion_delta={2,0,0};actor->local_impulse={3,0,0};actor->world_impulse={4,0,0};check(owned.spawn_primary(0,std::move(actor)).status==g::actors::EntityStatus::completed,"failure frame actor admitted");auto lease=owned.primary(0);Frame frame;frame.expected=lease.get();Pose pose;pose.expected=lease.get();g::MotionFrameServices auxiliary(frame,frame);g::MotionTransformFrameServices transforms(auxiliary,pose);provider_throws=true;bool rejected{};try{(void)owned.update_primary(transforms);}catch(const std::runtime_error&){rejected=true;}check(rejected && !lease->collision.pose_ready && frame.queues==0 && frame.later==0 && lease->position.x==9 && lease->position.y==111.25f,"required pose failure stops later real World stages and retains partial effects");check(owned.close()==g::Status::completed,"World invocation lease/guard retires after transform failure");++frame_cases;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"local_cases\":"<<local_cases<<",\"pose_cases\":"<<pose_cases<<",\"surface_calls\":"<<surface_calls<<",\"failure_cases\":"<<failure_cases<<",\"frame_cases\":"<<frame_cases<<",\"original_helper_calls\":"<<helper_calls<<",\"original_body_executed\":true,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
