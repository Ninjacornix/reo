#include "game/native/gameplay_scenario/periodic_effects.hpp"
#include "runtime.hpp"
#include "functions.h"
#include <bit>
#include <iostream>
#include <source_location>
namespace s=reo::native::gameplay_scenario;
namespace t=reo::native::gameplay_tasks;
namespace r=reo::native::gameplay_session;
unsigned checks{},cases{},emissions{},retirements{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Periodic check "+std::to_string(checks)+" line "+std::to_string(at.line()));
}
constexpr std::uint32_t task_at=0x10000,parent_at=0x20000,visual_at=0x30000;
template<class T>T get(const std::uint8_t* data,std::uint32_t at){return oracle_read<T>(data,at);}
template<class T>void put(std::uint8_t* data,std::uint32_t at,T value){oracle_write(data,at,value);}
using Event=std::array<std::uint32_t,8>;
std::vector<Event> original_events;
bool pool_full{},original_retired{};std::int16_t lifetime{};
void done(R5900Context* c){c->pc=GPR_U32(c,31);}
void original_port(std::uint8_t* data,R5900Context* c,PS2Runtime* runtime){
    switch(c->pc){
    case 0x5709b0:o2_005709B0_0x5709b0(data,c,runtime);return;
    case 0x570a10:o2_00570A10_0x570a10(data,c,runtime);return;
    case 0x5ddc70:o2_005DDC70_0x5ddc70(data,c,runtime);return;
    case 0x573890:o2_00573890_0x573890(data,c,runtime);return;
    case 0x1aec80:sub_001AEC80_0x1aec80(data,c,runtime);return;
    case 0x573740:check(GPR_U32(c,4)==task_at);original_retired=true;done(c);return;
    case 0x573630:check(GPR_U32(c,4)==1);if(!pool_full)std::fill(data+task_at,data+task_at+0x100,0);
        SET_GPR_U32(c,2,pool_full?0:task_at);done(c);return;
    case 0x6525d0:{
        check(GPR_U32(c,4)==0 && GPR_U32(c,6)==0 && GPR_U32(c,8)==0 && GPR_U32(c,10)==0x6535c0);
        const auto position=GPR_U32(c,5);
        original_events.push_back({GPR_U32(c,7),get<std::uint32_t>(data,position),get<std::uint32_t>(data,position+4),
            get<std::uint32_t>(data,position+8),GPR_U32(c,9),get<std::uint16_t>(data,0x3244b0),get<std::uint16_t>(data,0x3244b8),data[0x2b8de8]});
        if(!pool_full){put(data,visual_at+0x38,s::EffectPosition{91,92,93});put(data,visual_at+0x44,get<s::EffectPosition>(data,position));
            put(data,visual_at+0xc,std::int16_t(17));put(data,visual_at+0xe,lifetime);put(data,visual_at+0xf0,112.f);}
        SET_GPR_U32(c,2,pool_full?0:visual_at);done(c);return;
    }
    default:throw std::runtime_error("Undeclared periodic source call "+std::to_string(c->pc));
    }
}
struct Emitter:s::PeriodicEmitter {
    r::Random* random{};bool ready{true},full{},fault{};std::int16_t duration{};
    std::vector<Event> events;std::shared_ptr<s::PeriodicVisual> last;
    bool admitted()const noexcept override{return ready;}
    s::EmissionResult emit(const s::PeriodicEmission& e)noexcept override{
        const auto rng=random->state();events.push_back({e.descriptor,std::bit_cast<std::uint32_t>(e.position.x),
            std::bit_cast<std::uint32_t>(e.position.y),std::bit_cast<std::uint32_t>(e.position.z),e.flags,rng.primary,rng.secondary,rng.observed});
        if(fault)return{s::EmissionStatus::unavailable,{}};
        if(full)return{s::EmissionStatus::pool_full,{}};
        last=std::make_shared<s::PeriodicVisual>();last->position={91,92,93};last->initial_position=e.position;
        last->delay=17;last->remaining=duration;last->scale=112;return{s::EmissionStatus::completed,last};
    }
};
struct Idle:t::Task {void update(t::Scheduler&,const t::Handle&)noexcept override{}};
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "original_periodic.cpp"
#pragma GCC diagnostic pop
int main()try{
    std::vector<std::uint8_t> memory(0x2000000,0xa5);
    for(unsigned profile=0;profile<2;++profile)for(std::uint32_t seed=0;seed<65536;++seed){
        s::FlagState flags;s::FlagStateSnapshot bits;
        bits.bounded_bytes[0]=std::uint8_t(seed&1);bits.bounded_halfword=std::uint16_t(seed^0xa581);flags.restore(bits);
        s::PeriodicState state;state.phase=std::uint8_t(seed);state.timer=std::bit_cast<std::int16_t>(std::uint16_t(seed*257));
        state.packed=std::bit_cast<std::int16_t>(std::uint16_t(seed));state.position={float(seed%101),-17.5f,float(seed%31)};
        if(seed%4==0)state.phase=1;
        if(seed%7==0)state.phase=2;
        if(profile){state.phase=1;state.timer=0;bits.bounded_bytes[0]=0;flags.restore(bits);}
        const auto stop=std::uint16_t(profile||seed%3==0?0:0x8000u|(seed&15));
        memory[parent_at+0x30]=5;put(memory.data(),parent_at+0x52,stop);put(memory.data(),task_at+0x28,parent_at);
        memory[task_at+8]=state.phase;put(memory.data(),task_at+0xc,state.timer);put(memory.data(),task_at+0xe,state.packed);put(memory.data(),task_at+0x70,state.position);
        std::copy(bits.bounded_bytes.begin(),bits.bounded_bytes.end(),memory.begin()+0x4b9c80);put(memory.data(),0x4bac50,bits.bounded_halfword);
        r::Random rng;rng.restore({std::uint16_t(seed),std::uint16_t(seed^0x3917),std::uint8_t(seed)});
        put(memory.data(),0x3244b0,rng.state().primary);put(memory.data(),0x3244b8,rng.state().secondary);memory[0x2b8de8]=rng.state().observed;
        const std::int16_t durations[]{-32768,-1,0,1,8,31,100,32767};lifetime=durations[(seed/3)%8];pool_full=!profile&&seed%11==0;
        Emitter emitter;emitter.random=&rng;emitter.duration=lifetime;emitter.full=pool_full;emitter.events.reserve(2);
        original_events.clear();original_retired=false;
        R5900Context context;context.pc=0x5d9680;SET_GPR_U32(&context,4,task_at);SET_GPR_U32(&context,29,0x1ff0000);SET_GPR_U32(&context,31,0x123456);PS2Runtime runtime;runtime.port=original_port;
        o2_005D9680_0x5d9680(memory.data(),&context,&runtime);
        const auto result=s::update_periodic(state,stop,flags,rng,emitter);
        check(result.status==s::PeriodicStatus::completed && result.retire==original_retired && context.pc==0x123456);
        check(memory[task_at+8]==state.phase && get<std::int16_t>(memory.data(),task_at+0xc)==state.timer && get<std::int16_t>(memory.data(),task_at+0xe)==state.packed);
        if(emitter.events!=original_events){
            std::cerr<<"event seed "<<seed<<" profile "<<profile<<'\n';
            for(const auto& event:emitter.events){for(auto word:event)std::cerr<<word<<' ';std::cerr<<'\n';}
            for(const auto& event:original_events){for(auto word:event)std::cerr<<word<<' ';std::cerr<<'\n';}
        }
        check(emitter.events==original_events);const auto after=rng.state();
        check(after.primary==get<std::uint16_t>(memory.data(),0x3244b0) && after.secondary==get<std::uint16_t>(memory.data(),0x3244b8) && after.observed==memory[0x2b8de8]);
        if(emitter.last){check(get<std::int16_t>(memory.data(),visual_at+0xc)==emitter.last->delay && get<std::int16_t>(memory.data(),visual_at+0xe)==emitter.last->remaining);
            check(get<float>(memory.data(),visual_at+0xf0)==emitter.last->scale);
            const auto position=get<s::EffectPosition>(memory.data(),visual_at+0x38);check(position.x==emitter.last->position.x && position.y==emitter.last->position.y && position.z==emitter.last->position.z);}
        emissions+=unsigned(emitter.events.size());retirements+=result.retire;++cases;
    }
    for(unsigned seed=0;seed<64;++seed){
        t::Scheduler tasks;s::SceneControls controls;s::FlagState flags;r::Random random;
        Emitter emitter;emitter.random=&random;s::PeriodicEffects owner(tasks,controls,flags,random,emitter);
        s::ControlTypeFive body;body.position={float(seed),-2.25f,17};const auto parent=*controls.append({17,1,body});
        pool_full=seed%2;
        if(pool_full)for(unsigned i=0;i<t::Scheduler::capacity;++i)
            check(tasks.create(std::make_shared<Idle>()).status==t::Status::completed);
        put(memory.data(),parent_at+0x44,s::EffectPosition{body.position[0],body.position[1],body.position[2]});
        R5900Context context;context.pc=0x5d9630;SET_GPR_U32(&context,4,parent_at);SET_GPR_U32(&context,29,0x1ff0000);SET_GPR_U32(&context,31,0x123456);
        PS2Runtime runtime;runtime.port=original_port;o2_005D9630_0x5d9630(memory.data(),&context,&runtime);
        const auto created=owner.create(parent);check(created.status==s::PeriodicStatus::completed && context.pc==0x123456);
        check((GPR_U32(&context,2)==0)==pool_full);
        if(pool_full)check(created.task_status==t::Status::full && !created.task);
        else{
            check(created.task_status==t::Status::completed && bool(created.task));const auto state=owner.snapshot(created.task);check(bool(state));
            check(memory[task_at]==1 && memory[task_at+2]==5 && get<std::uint32_t>(memory.data(),task_at+0x14)==0x5d9680 && get<std::uint32_t>(memory.data(),task_at+0x18)==0 && get<std::uint32_t>(memory.data(),task_at+0x28)==parent_at);
            const auto captured=get<s::EffectPosition>(memory.data(),task_at+0x70);check(captured.x==state->position.x && captured.y==state->position.y && captured.z==state->position.z);
            check(state->phase==memory[task_at+8] && state->timer==get<std::int16_t>(memory.data(),task_at+0xc) && state->packed==get<std::int16_t>(memory.data(),task_at+0xe));
        }
    }
    // Unbounded original byte-bit aliases outside the admitted native bank
    // remain explicit refusals before task state, RNG or emission effects.
    for(std::uint32_t stop=128;stop<0x8000;++stop){
        s::FlagState flags;r::Random random;Emitter emitter;emitter.random=&random;s::PeriodicState state;
        const auto before=random.state();const auto result=s::update_periodic(state,std::uint16_t(stop),flags,random,emitter);
        check(result.status==s::PeriodicStatus::flag_unavailable && !result.retire && state.phase==0 && state.timer==0 && state.packed==0);
        check(random.state().primary==before.primary && random.state().secondary==before.secondary && emitter.events.empty());
    }
    // Owner/lifetime path uses the real native linked scheduler and controls.
    t::Scheduler tasks;s::SceneControls controls;s::FlagState flags;r::Random random;Emitter emitter;emitter.random=&random;emitter.events.reserve(128);emitter.duration=16;
    s::PeriodicEffects owner(tasks,controls,flags,random,emitter);s::ControlTypeFive body;body.position={1,2,3};body.reset_sentinel=0x8000;
    const auto parent=*controls.append({42,1,body});const auto made=owner.create(parent);
    check(made.status==s::PeriodicStatus::completed && made.task_status==t::Status::completed && owner.admitted());
    body.position={7,8,9};check(controls.replace(parent,{42,1,body})==s::ControlStatus::completed);
    check(tasks.run(t::Pass::update).status==t::Status::completed && emitter.last && emitter.last->position.x==1);
    check(owner.snapshot(made.task)->phase==2 && owner.healthy());
    check(flags.write(s::FlagBank::bounded_halfword,0,true));tasks.run(t::Pass::update);
    check(!tasks.contains(made.task) && !owner.snapshot(made.task));
    flags.write(s::FlagBank::bounded_halfword,0,false);const auto retired=owner.create(parent);controls.erase(parent);tasks.run(t::Pass::update);
    check(!tasks.contains(retired.task));const auto replacement=*controls.append({42,1,body});check(replacement!=parent);
    emitter.fault=true;const auto fault=owner.create(replacement);tasks.run(t::Pass::update);
    check(owner.failure()==s::PeriodicStatus::emitter_unavailable && !owner.healthy() && tasks.contains(fault.task));owner.close();check(tasks.size()==0 && !owner.admitted());
    check(owner.create(replacement).status==s::PeriodicStatus::closed);
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"emissions\":"<<emissions<<",\"retirements\":"<<retirements<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
