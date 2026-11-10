#include "game/native/gameplay_lighting/timed_lights.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <vector>
namespace l=reo::native::gameplay_lighting;
namespace w=reo::native::gameplay_world;
namespace t=reo::native::gameplay_tasks;
constexpr unsigned light_at=0x747540,task_at=0x120000,actor_at=0x10000,position_at=0x11000;
unsigned checks{},calls{},policy_cases{},lifecycles{},frames{},refusals{},admissions{},retirements{},guard_cases{};
bool original_task{},deny_task{};
void check(bool ok,std::source_location at=std::source_location::current()){
    ++checks;if(!ok)throw std::runtime_error("Timed light check "+std::to_string(checks)+" at line "+std::to_string(at.line()));
}
template<class T>T get(const std::uint8_t* m,unsigned at){return transform_read<T>(m,at);}
template<class T>void put(std::uint8_t* m,unsigned at,T value){transform_write(m,at,value);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;const auto done=[&](){context->pc=GPR_U32(context,31);};
    switch(context->pc){
    case 0x107c68:{const auto dst=GPR_U32(context,4),n=GPR_U32(context,6);check(dst>=light_at&&dst<light_at+64*56&&n==56&&(dst-light_at)%56==0&&GPR_U32(context,5)==0);std::memset(memory+dst,0,n);SET_GPR_U32(context,2,dst);done();return;}
    case 0x107ab0:{const auto dst=GPR_U32(context,4),src=GPR_U32(context,5),n=GPR_U32(context,6);check(dst>=light_at+4&&dst<light_at+64*56&&(dst-light_at-4)%56==0&&src==0x1efffc0&&n==52);std::memcpy(memory+dst,memory+src,n);SET_GPR_U32(context,2,dst);done();return;}
    case 0x573890:check(GPR_U32(context,4)==0&&GPR_U32(context,5)==0x5d85e0);if(deny_task){SET_GPR_U32(context,2,0);}else{check(!original_task);original_task=true;std::memset(memory+task_at,0,256);SET_GPR_U32(context,2,task_at);++admissions;}done();return;
    case 0x573740:check(GPR_U32(context,4)==task_at&&original_task);original_task=false;++retirements;done();return;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unexpected timed-light original port "+std::to_string(context->pc));
    }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
void call(std::uint8_t* memory,unsigned pc,std::array<unsigned,2> args={}){
    R5900Context context;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);
    SET_GPR_U32(&context,4,args[0]);SET_GPR_U32(&context,5,args[1]);PS2Runtime runtime;original_transform_port(memory,&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);
}
void write_state(std::uint8_t* m,const l::TimedState& s){
    put(m,task_at+8,s.phase);put(m,task_at+12,s.remaining);put(m,task_at+14,s.wobble);
    put(m,task_at+16,s.fade_remaining);put(m,task_at+18,s.fade_duration);put(m,task_at+128,s.saved[0]);put(m,task_at+132,s.saved[1]);
}
void compare_state(const std::uint8_t* m,const l::TimedState& s){
    check(get<std::uint8_t>(m,task_at+8)==s.phase);check(get<std::int16_t>(m,task_at+12)==s.remaining);
    check(get<std::int16_t>(m,task_at+14)==s.wobble);check(get<std::int16_t>(m,task_at+16)==s.fade_remaining);
    check(get<std::int16_t>(m,task_at+18)==s.fade_duration);
    for(unsigned i=0;i<2;++i){check(get<std::uint32_t>(m,task_at+128+4*i)==std::bit_cast<std::uint32_t>(s.saved[i]));}
}
std::array<float,13> words(const l::Definition& d){return{d.vector0[0],d.vector0[1],d.vector0[2],d.vector0[3],d.vector1[0],d.vector1[1],d.vector1[2],d.vector1[3],d.position[0],d.position[1],d.position[2],d.attenuation,d.parameter};}
void compare_light(const std::uint8_t* m,unsigned slot,const l::Light& light){
    const auto at=light_at+56*slot;check(m[at]==light.active&&m[at+1]==light.tag&&m[at+2]==light.mode);
    const auto payload=words(light.descriptor);for(unsigned i=0;i<13;++i){check(get<std::uint32_t>(m,at+4+4*i)==std::bit_cast<std::uint32_t>(payload[i]));}
}
void reset_original(std::uint8_t* m){std::memset(m+light_at,0,64*56);m[0x747538]=0;std::memset(m+task_at,0,256);original_task=false;deny_task=false;}
std::unique_ptr<w::Actor> actor(std::optional<std::uint8_t> tag){auto a=std::make_unique<w::Actor>();a->active=true;a->primary=2;a->secondary=11;a->lighting_tag=tag;return a;}
struct Noop: t::Task{void update(t::Scheduler&,const t::Handle&)noexcept override{}};
struct Spawn: t::Task{
    l::TimedLights* owner{};w::actors::EntityId actor_id;l::TimedCreated made;
    void update(t::Scheduler& tasks,const t::Handle& self)noexcept override{made=owner->create(actor_id,{0,0,0});(void)tasks.erase(self);}
};
int main()try{
    std::vector<std::uint8_t> memory(0x2000000);auto* m=memory.data();owned_constants(m);
    const auto definition=l::timed_definition({0,0,0});const auto payload=words(definition);
    for(unsigned i=0;i<13;++i){check(get<std::uint32_t>(m,0x7202c0+4*i)==std::bit_cast<std::uint32_t>(payload[i]));}
    // Controlled task states exercise every clock byte, signed halfword wrap,
    // phase fallthrough, wobble reset, fading and unknown return phases.
    std::uint32_t seed=0x10203040;
    for(unsigned n=0;n<131072;++n){
        reset_original(m);seed=seed*1664525u+1013904223u;l::TimedState state;
        state.phase=std::uint8_t(n%6);state.remaining=std::bit_cast<std::int16_t>(std::uint16_t(seed));
        state.wobble=std::bit_cast<std::int16_t>(std::uint16_t(seed>>16));state.fade_remaining=std::bit_cast<std::int16_t>(std::uint16_t(seed*7));state.fade_duration=std::int16_t(1+n%32767);
        state.saved={float(std::int16_t(seed))/32,float(std::int16_t(seed>>16))/16};auto d=definition;d.vector0[0]=float(n%101)/13;d.vector0[1]=-float(n%127)/17;
        const auto bits=words(d);for(unsigned i=0;i<13;++i){put(m,light_at+4+4*i,bits[i]);}
        m[light_at]=m[0x747538]=1;original_task=true;put(m,task_at+40,light_at);write_state(m,state);m[0x3243cc]=std::uint8_t(n);
        call(m,0x5d85e0,{task_at,0});const bool retired=l::advance_timed_light(state,d,std::uint8_t(n));check(retired==!original_task);compare_state(m,state);
        if(!retired){compare_light(m,0,{1,0,0,0,d});}else check(m[0x747538]==0);
        ++policy_cases;
    }
    // Real world, scheduler and shared pool through complete task lifecycles.
    for(unsigned n=0;n<1024;++n){
        reset_original(m);auto session=std::make_shared<w::Session>();session->clock_mode=std::uint8_t(n/4);w::World world({{{0x100,0x10,0x20}},1,{16,100}},session);
        const auto id=world.spawn_primary(0,actor(std::uint8_t(n))).id;check(bool(id));reo::native::gameplay_scenario::Lighting canonical;l::Pool pool(canonical);t::Scheduler tasks;l::TimedLights timed(world,tasks,pool);
        check(timed.bound_to(world,tasks,pool));const std::array<float,3> pos{float(n),-2.5f,41.125f};m[actor_at+8]=2;m[actor_at+9]=11;m[actor_at+0x175]=std::uint8_t(n);std::memcpy(m+position_at,pos.data(),12);m[0x3243cc]=session->clock_mode;
        call(m,0x6b2680,{actor_at,position_at});const auto made=timed.create(id,pos);check(made.status==l::TimedStatus::completed&&original_task&&tasks.contains(made.task)&&pool.size()==1);compare_light(m,0,*pool.retain(made.light));
        for(unsigned frame=0;original_task&&frame<80;++frame){
            if(n%4==1&&frame==1){world.resolve(id)->primary=1;m[actor_at+8]=1;}
            if(n%4==2&&frame==25){world.resolve(id)->secondary=0;m[actor_at+9]=0;}
            if(n%4==3&&frame==5){session->clock_mode^=1;m[0x3243cc]=session->clock_mode;}
            call(m,0x5d85e0,{task_at,0});const auto pass=tasks.run(t::Pass::update);check(pass.status==t::Status::completed&&pass.called==1);check(tasks.contains(made.task)==original_task);
            const auto snap=timed.snapshot(made.task);check(bool(snap)==original_task);check(pool.size()==m[0x747538]);
            if(snap){compare_state(m,snap->state);compare_light(m,0,*pool.retain(made.light));}else check(!pool.retain(made.light));
            ++frames;
        }
        check(!original_task&&tasks.size()==0&&pool.size()==0&&timed.failure()==l::TimedStatus::completed);++lifecycles;
    }
    auto session=std::make_shared<w::Session>();w::World world({{{0x100,0x10,0x20}},1,{16,100}},session);auto id=world.spawn_primary(0,actor({})).id;
    reo::native::gameplay_scenario::Lighting canonical;l::Pool pool(canonical);t::Scheduler tasks;l::TimedLights timed(world,tasks,pool);
    check(timed.create(id,{0,0,0}).status==l::TimedStatus::tag_unavailable&&tasks.size()==0&&pool.size()==0);++refusals;
    world.resolve(id)->primary=0;check(timed.create(id,{0,0,0}).status==l::TimedStatus::skipped);world.resolve(id)->primary=2;world.resolve(id)->lighting_tag=0;
    for(unsigned pair=0;pair<65536;++pair){
        reset_original(m);m[actor_at+8]=std::uint8_t(pair>>8);m[actor_at+9]=std::uint8_t(pair);m[actor_at+0x175]=0;world.resolve(id)->primary=m[actor_at+8];world.resolve(id)->secondary=m[actor_at+9];
        call(m,0x6b2680,{actor_at,position_at});const auto guarded=timed.create(id,{});const bool eligible=pair==0x020b;check(original_task==eligible);check(guarded.status==(eligible?l::TimedStatus::completed:l::TimedStatus::skipped));
        check(pool.size()==std::size_t(eligible)&&tasks.size()==std::size_t(eligible));if(eligible){check(tasks.clear()==t::Status::completed&&pool.size()==0);}
        ++guard_cases;
    }
    world.resolve(id)->primary=2;world.resolve(id)->secondary=11;
    check(timed.create({},{}).status==l::TimedStatus::actor_unavailable);++refusals;
    w::World other({{{0x100,0x10,0x20}},1,{16,100}},std::make_shared<w::Session>());const auto foreign=other.spawn_primary(0,actor(0)).id;check(timed.create(foreign,{}).status==l::TimedStatus::actor_unavailable);++refusals;
    for(unsigned i=0;i<32;++i){check(tasks.create(std::make_shared<Noop>()).status==t::Status::completed);}
    reset_original(m);m[actor_at+8]=2;m[actor_at+9]=11;deny_task=true;call(m,0x6b2680,{actor_at,position_at});check(!original_task&&m[0x747538]==0);
    check(timed.create(id,{}).status==l::TimedStatus::task_full&&pool.size()==0);check(tasks.clear()==t::Status::completed);++refusals;
    for(unsigned i=0;i<64;++i){check(canonical.allocate(nullptr,0,1).has_value());}
    reset_original(m);for(unsigned i=0;i<64;++i){m[light_at+56*i]=1;}m[0x747538]=64;call(m,0x6b2680,{actor_at,position_at});check(original_task&&get<unsigned>(m,task_at+40)==0&&m[0x747538]==64);
    check(timed.create(id,{}).status==l::TimedStatus::light_full&&tasks.size()==0&&pool.size()==64);++refusals;canonical.reset_work();
    reset_original(m);std::memset(m+position_at,0,12);m[0x3243cc]=0;call(m,0x6b2680,{actor_at,position_at});call(m,0x5d85e0,{task_at,0});
    auto spawn=std::make_shared<Spawn>();spawn->owner=&timed;spawn->actor_id=id;check(tasks.create(spawn).status==t::Status::completed);
    const auto same_pass=tasks.run(t::Pass::update);check(same_pass.called==2&&same_pass.status==t::Status::completed&&spawn->made.status==l::TimedStatus::completed);compare_state(m,timed.snapshot(spawn->made.task)->state);compare_light(m,0,*pool.retain(spawn->made.light));
    check(tasks.run(t::Pass::presentation).called==0);check(tasks.clear()==t::Status::completed&&pool.size()==0);
    const auto stale=timed.create(id,{});check(stale.status==l::TimedStatus::completed);canonical.reset_work();const auto unrelated=pool.allocate();check(unrelated.status==l::Status::completed);check(tasks.run(t::Pass::update).called==1&&pool.size()==1&&pool.retain(unrelated.id)&&!tasks.contains(stale.task)&&timed.failure()==l::TimedStatus::light_unavailable);++refusals;
    const auto retired=timed.create(id,{});check(retired.status==l::TimedStatus::completed);check(world.retire_primary(0)==w::actors::EntityStatus::completed);const auto replacement=world.spawn_primary(0,actor(255)).id;check(replacement!=id);check(tasks.run(t::Pass::update).called==1&&!pool.retain(retired.light)&&pool.retain(unrelated.id));++refusals;
    const auto final=timed.create(replacement,{});check(final.status==l::TimedStatus::completed);check(tasks.erase(final.task)==t::Status::completed&&!pool.retain(final.light)&&pool.retain(unrelated.id));
    const auto closing=timed.create(replacement,{});check(closing.status==l::TimedStatus::completed);const auto unrelated_task=tasks.create(std::make_shared<Noop>());check(unrelated_task.status==t::Status::completed);timed.close();check(tasks.size()==1&&tasks.contains(unrelated_task.handle)&&!pool.retain(closing.light)&&pool.retain(unrelated.id)&&timed.create(replacement,{}).status==l::TimedStatus::closed);++refusals;
    std::cout<<"{\"checks\":"<<checks<<",\"policy_cases\":"<<policy_cases<<",\"guard_cases\":"<<guard_cases<<",\"lifecycles\":"<<lifecycles<<",\"frames\":"<<frames<<",\"refusals\":"<<refusals<<",\"original_calls\":"<<calls<<",\"original_admissions\":"<<admissions<<",\"original_retirements\":"<<retirements<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
