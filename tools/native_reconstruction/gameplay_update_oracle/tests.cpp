#include "game/native/gameplay_update/update.hpp"
#include "runtime.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
namespace u=reo::native::gameplay_update;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
namespace t=reo::native::gameplay_tasks;
std::vector<std::uint32_t>* trace;
struct Notifications final:s::FlagNotifications {
    void changed(const s::ScenarioFlagChange& v)noexcept override{trace->insert(trace->end(),{0x5703e0,v.id,v.value,v.actor_owner});}
    void changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
constexpr std::uint32_t addresses[]{0x6816f0,0x371a90,0x6671d0,0x5d7ed0,0x581ee0,0x6d6240,0x682fd0,0x6bbba0,
    0x6ef150,0x5da680,0x3769f0,0x376ae0,0x376b80,0x66a3a0,0x6832f0,0x5dc430,0x5dc4b0,0x5dc500,
    0x5be9a0,0x5d8160,0x590ea0,0x5821f0,0x651ed0,0x573d30,0x6deea0,0x1b98e0,0x6b7e40,0x6ae9f0,
    0x633780,0x5da720,0x6814e0,0x681a40,0x6041b0,0x37baf0};
struct Workers final:u::Services {
    std::uint32_t seed{};
    std::function<void(u::Owner&)> on_reset;
    void run(u::Worker stage,u::Owner& owner)override{
        if(stage==u::Worker::reset_entity_queues && on_reset)on_reset(owner);
        trace->insert(trace->end(),{addresses[std::size_t(stage)],owner.world().selected_actor,owner.world().paused,owner.clock().update_counter()});
        if(stage==u::Worker::clear_interaction_activity && seed%3==0)owner.world().paused=!owner.world().paused;
        if(stage==u::Worker::target_caches && seed%5==0)owner.world().mode=std::uint8_t(seed%3);
        if(stage==u::Worker::sequences && seed%7==0)owner.state.session_work_gate=1;
        if(stage==u::Worker::reset_entity_queues && seed%11==0)owner.clock().adjust_update_counter(1);
    }
};
struct ActorPorts final:w::Services {
    void begin_offline_frame(w::World& world)override{trace->insert(trace->end(),{0x8122b0,world.selected_actor});}
    void run(w::Stage,w::World&,w::Actor&)override{std::terminate();}
    bool remote_motion(w::World&,w::Actor&)override{std::terminate();}
    bool find_grid(w::World&,w::Actor&,std::int8_t&)override{std::terminate();}
    void switch_grid(w::World&,std::int32_t,std::int32_t)override{std::terminate();}
    float grid_response(w::World&,std::uint8_t)override{std::terminate();}
};
struct Linked final:t::Task {
    std::uint32_t value{};
    explicit Linked(std::uint32_t v):value(v){}
    void update(t::Scheduler&,const t::Handle&)noexcept override{trace->insert(trace->end(),{0x573840,value});}
};
struct Destruction final:t::Task {
    std::function<void()> callback;
    explicit Destruction(std::function<void()> cb):callback(std::move(cb)){}
    ~Destruction(){callback();}
    void update(t::Scheduler&,const t::Handle&)noexcept override{}
};
struct Event final:t::EventTask {
    u::Owner& owner;
    explicit Event(u::Owner& o):owner(o){}
    void update(t::EventTasks&,const t::Handle&,t::EventContext ctx)noexcept override{
        if(&ctx.owner.actor!=&owner.world().selected_actor)std::terminate();
        trace->insert(trace->end(),{0x5b91b0,ctx.bank,ctx.slot,ctx.owner.actor});ctx.owner.actor=std::uint8_t(ctx.owner.actor+1);
    }
};
template<class T>T get(const std::uint8_t* r,std::uint32_t at){return oracle_read<T>(r,at);}
template<class T>void put(std::uint8_t* r,std::uint32_t at,T value){oracle_write<T>(r,at,value);}
void read(std::uint8_t* r,u::Owner& o){
    o.world().mode=r[0x3243f2];o.world().paused=r[0x4badf8]!=0;o.world().selected_actor=r[0x4baded];
    o.state.limit_override=r[0x4bae77]!=0;o.state.session_work_gate=get<std::int16_t>(r,0x3241f8);
    auto& state=o.state;state.control_armed=r[0x4bae94];state.control_state=r[0x4bae97];state.exit_requested=r[0x3243d8];state.short_exit_adjustment=r[0x324477];
    state.notification_pending=r[0x4badfb];state.transition_gate=r[0x4bae76];state.pause_latched=r[0x4badf9];state.request_flags=get<std::uint32_t>(r,0x324330);state.control_flags=get<std::uint32_t>(r,0x324300);
    o.world().session().session_state=get<std::int16_t>(r,0x324200);o.world().session().clock_mode=r[0x3243cc];
    if(o.clock().restore({r[0x4bae00],r[0x4bae01],r[0x4bae02],r[0x4bae03]},get<std::uint32_t>(r,0x4bade8))!=t::Status::completed)std::terminate();
}
void write(std::uint8_t* r,u::Owner& o){
    r[0x3243f2]=o.world().mode;r[0x4badf8]=o.world().paused?1:0;r[0x4baded]=o.world().selected_actor;
    r[0x4bae77]=o.state.limit_override?1:0;put(r,0x3241f8,o.state.session_work_gate);put(r,0x4bade8,o.clock().update_counter());
    const auto& state=o.state;r[0x4bae94]=state.control_armed;r[0x4bae97]=state.control_state;r[0x3243d8]=state.exit_requested;r[0x324477]=state.short_exit_adjustment;
    r[0x4badfb]=state.notification_pending;r[0x4bae76]=state.transition_gate;r[0x4badf9]=state.pause_latched;put(r,0x324330,state.request_flags);put(r,0x324300,state.control_flags);
    put(r,0x324200,o.world().session().session_state);r[0x3243cc]=o.world().session().clock_mode;
    const auto time=o.clock().play_time();r[0x4bae00]=time.hours;r[0x4bae01]=time.minutes;r[0x4bae02]=time.seconds;r[0x4bae03]=time.sixtieths;
}
struct Expiry final:t::FlagSink {
    u::Owner& owner;explicit Expiry(u::Owner& o):owner(o){}
    void expired(const t::FlagExpiry& e)noexcept override{
        bool okay;
        if(e.target.scope==t::FlagScope::scenario)okay=owner.flags().scenario(e.target.id,1,s::NotifyOwner::selected_actor_plus_one,std::uint8_t(owner.world().selected_actor+1));
        else okay=owner.flags().actor_flag(s::ActorFlagFamily::primary,{false,0},e.target.id,true);
        if(!okay)std::terminate();
    }
};
struct PhaseWorkers final:u::PhaseServices {
    Workers workers;std::uint32_t buttons{};
    void run(u::Worker stage,u::Owner& o)override{workers.run(stage,o);}
    bool button(u::Button key,u::Owner& o)override{
        trace->insert(trace->end(),{0x1b82a0,key==u::Button::primary?0x54u:0x52u,o.clock().update_counter(),o.world().selected_actor});
        return ((workers.seed>>(buttons++%11))&3)==1;
    }
    bool transition_request(u::Owner& o)override{trace->insert(trace->end(),{0x5fe9b0,o.state.control_armed});return workers.seed%3==0;}
    void effect(u::PhaseEffect effect,u::Owner& o,std::uint32_t argument=0)override{
        constexpr std::uint32_t calls[]{0x6e0ed0,0x6deea0,0x5fe970,0x1af9c0,0x1baaf0,0x6e1430,0x6df230,0x5ff5d0,0x681c70,0x1ae1e0,0x1acf70};
        trace->insert(trace->end(),{calls[std::size_t(effect)],argument,o.world().selected_actor,o.clock().update_counter(),o.state.notification_pending,o.state.transition_gate});
        if(effect==u::PhaseEffect::update_ui && workers.seed%5==0)o.state.control_state=2;
        if(effect==u::PhaseEffect::enter_phase && argument==3 && workers.seed%7==0)o.world().mode=0;
        if(effect==u::PhaseEffect::close_ui && workers.seed%11==0)o.state.control_armed^=2;
    }
};
u::Owner* original_owner;Workers* original_workers;ActorPorts actors;
PhaseWorkers* original_phase{};bool phase_workers{};
void o2_005FED00_0x5fed00(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_0068C8D0_0x68c8d0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_005FEE60_0x5fee60(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_005FEE70_0x5fee70(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_005FEE80_0x5fee80(std::uint8_t*,R5900Context*,PS2Runtime*);
void original_port(std::uint8_t* r,R5900Context* ctx,PS2Runtime* runtime){
    if(ctx->pc==0x5fed00){phase_workers=true;o2_005FED00_0x5fed00(r,ctx,runtime);phase_workers=false;return;}
    if(ctx->pc==0x68c8d0){o2_0068C8D0_0x68c8d0(r,ctx,runtime);return;}
    if(ctx->pc==0x5fee60){o2_005FEE60_0x5fee60(r,ctx,runtime);return;}
    if(ctx->pc==0x5fee70){o2_005FEE70_0x5fee70(r,ctx,runtime);return;}
    if(ctx->pc==0x5fee80){o2_005FEE80_0x5fee80(r,ctx,runtime);return;}
    auto& o=*original_owner;read(r,o);bool found=false;
    if(original_phase){
        if(ctx->pc==0x1b82a0){const auto key=GPR_U32(ctx,4);if(key!=0x54 && key!=0x52)throw std::runtime_error("Phase input ABI");SET_GPR_U32(ctx,2,original_phase->button(key==0x54?u::Button::primary:u::Button::secondary,o));found=true;}
        else if(ctx->pc==0x1b02d0){SET_GPR_U32(ctx,2,o.world().mode==0);found=true;}
        else if(ctx->pc==0x1b0300){SET_GPR_U32(ctx,2,o.world().mode);found=true;}
        else if(ctx->pc==0x5fe9b0){SET_GPR_U32(ctx,2,original_phase->transition_request(o));found=true;}
        else{
            constexpr std::uint32_t calls[]{0x6e0ed0,0x6deea0,0x5fe970,0x1af9c0,0x1baaf0,0x6e1430,0x6df230,0x5ff5d0,0x681c70,0x1ae1e0,0x1acf70};
            for(std::size_t i=0;i<std::size(calls);++i)if(ctx->pc==calls[i] && !(ctx->pc==0x6deea0 && phase_workers)){
                const auto arg=ctx->pc==0x6e0ed0?GPR_U32(ctx,5):ctx->pc==0x1baaf0||ctx->pc==0x5ff5d0?GPR_U32(ctx,4):0;
                if(ctx->pc==0x6e0ed0 && GPR_U32(ctx,4)!=4)throw std::runtime_error("Phase UI ABI");
                original_phase->effect(u::PhaseEffect(i),o,arg);found=true;break;
            }
        }
    }
    for(std::size_t i=0;!found && i<std::size(addresses);++i)if(ctx->pc==addresses[i]){
        if(ctx->pc==0x6671d0 && GPR_U32(ctx,4)!=1)throw std::runtime_error("Limit action ABI");
        original_workers->run(u::Worker(i),o);found=true;break;
    }
    if(!found)switch(ctx->pc){
    case 0x68c7b0:{Expiry sink(o);if(o.timers().tick(sink)!=t::Status::completed)throw std::runtime_error("Timer port");break;}
    case 0x68c660:{
        const auto channel=GPR_U32(ctx,4);s::Providers p;p.flags=&o.flags();p.canonical_flags=&o.flags();p.timers=&o.timers();
        if(o.world().mode==0){const std::array<s::OfflinePartyActor,3> party{};const auto step=o.offline().tick(o.scripts(),channel,o.state.scripts_enabled,party,o.world().room,o.world().selected_actor,o.flags(),p);if(step.status!=s::Status::completed&&step.status!=s::Status::yielded)throw std::runtime_error("Offline script port");}
        else if(o.scripts().tick(channel,{true,false,o.world().selected_actor,o.world().room},p).status!=s::Status::yielded)throw std::runtime_error("Script port");
        break;
    }
    case 0x669f30:if(o.world().update_primary(actors).status!=w::Status::completed)throw std::runtime_error("Actor port");break;
    case 0x5b91b0:{auto selection=t::OwnerSelection::borrow(o.world().selected_actor);if(o.events().run(o.world().mode==0?t::EventMode::owner_banks:t::EventMode::shared_bank,selection).status!=t::Status::completed)throw std::runtime_error("Event port");break;}
    case 0x573840:if(o.linked().run(t::Pass::update).status!=t::Status::completed)throw std::runtime_error("Linked task port");break;
    default:throw std::runtime_error("Undeclared worker port "+std::to_string(ctx->pc));
    }
    write(r,o);ctx->pc=GPR_U32(ctx,31);
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "original_update.cpp"
#pragma GCC diagnostic pop
void install(u::Owner& o,s::DispatchProfile profile){
    const auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{{std::byte{0xa},std::byte{},std::byte{},std::byte{}}},profile);
    for(std::size_t i=0;i<6;++i){s::Channel channel{program,{0,0},{0,0},0,0,0};if(o.scripts().restore_channel(i,channel)!=s::Status::completed)throw std::runtime_error("Fixture script admission");}
}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000,0xa5),expected(ram);std::uint64_t cases{},words{},paused{},limited{},phase_cases{},phase_words{},committed{};
    w::Profile profile;profile.layouts.resize(1);w::World native_world(profile,std::make_shared<w::Session>()),reference_world(profile,std::make_shared<w::Session>());
    Notifications native_notify,reference_notify;u::Owner native(native_world,native_notify),reference(reference_world,reference_notify);original_owner=&reference;
    for(std::uint32_t seed=0;seed<2048;++seed){
        native_world.mode=std::uint8_t(seed%3);native_world.paused=seed%2;native_world.selected_actor=std::uint8_t(seed%4);
        native.state.limit_override=seed%5==0;native.state.session_work_gate=std::int16_t(seed%2);
        const std::uint32_t counters[]{0,0x83d5f,0x83d60,0x83d61,UINT32_MAX,0x80000000};native.clock().restore({},counters[(seed/4)%6]);
        write(ram.data(),native);read(ram.data(),reference);reference.state=native.state;
        const auto dispatch=native_world.mode==0?s::DispatchProfile::offline_actor:s::DispatchProfile::ordinary;install(native,dispatch);install(reference,dispatch);
        native.flags().restore({});reference.flags().restore({});native.events().clear();reference.events().clear();native.linked().clear();reference.linked().clear();
        for(auto* o:{&native,&reference}){
            if(o->linked().create(std::make_shared<Linked>(seed)).status!=t::Status::completed)throw std::runtime_error("Linked fixture admission");
            for(std::size_t bank=0;bank<3;++bank)if(o->events().install(bank,bank,std::make_shared<Event>(*o)).status!=t::Status::completed)throw std::runtime_error("Event fixture admission");
            for(std::size_t i=0;i<8;++i)o->timers().arm(i,std::int16_t((seed+i)%5),{i%2?t::FlagScope::scenario:t::FlagScope::session_owner_zero,std::uint16_t(i)});
        }
        std::vector<std::uint32_t> native_trace,reference_trace;Workers n,r;n.seed=r.seed=seed;original_workers=&r;
        trace=&reference_trace;R5900Context ctx;ctx.pc=0x5fed00;SET_GPR_U32(&ctx,29,0x1ff0000);SET_GPR_U32(&ctx,31,0x123456);PS2Runtime runtime;runtime.port=original_port;
        o2_005FED00_0x5fed00(ram.data(),&ctx,&runtime);
        trace=&native_trace;const auto result=native.run_workers(n,actors);write(expected.data(),native);
        if(ctx.pc!=0x123456||result.status!=u::Status::completed||native_trace!=reference_trace){
            std::cerr<<"native status "<<unsigned(result.status)<<" sizes "<<native_trace.size()<<" "<<reference_trace.size()<<" pc "<<std::hex<<ctx.pc<<std::dec<<"\n";
            for(std::size_t i=0;i<std::max(native_trace.size(),reference_trace.size());++i)if(i>=native_trace.size()||i>=reference_trace.size()||native_trace[i]!=reference_trace[i]){
                std::cerr<<"first mismatch "<<i<<" native="<<(i<native_trace.size()?native_trace[i]:0)<<" original="<<(i<reference_trace.size()?reference_trace[i]:0)<<"\n";break;
            }
            throw std::runtime_error("Worker trace seed "+std::to_string(seed));
        }
        for(const auto at:{0x3243f2u,0x4badf8u,0x4badedu,0x4bae77u})if(ram[at]!=expected[at])throw std::runtime_error("Worker gate publication");
        if(get<std::int16_t>(ram.data(),0x3241f8)!=native.state.session_work_gate||get<std::uint32_t>(ram.data(),0x4bade8)!=native.clock().update_counter())throw std::runtime_error("Worker counter/gate");
        for(std::size_t i=0;i<8;++i)if(native.timers().snapshot()[i].remaining!=reference.timers().snapshot()[i].remaining)throw std::runtime_error("Timer ordering");
        if(native.flags().snapshot().shared.scenario!=reference.flags().snapshot().shared.scenario||native.flags().snapshot().primary!=reference.flags().snapshot().primary)throw std::runtime_error("Native flag publication");
        ++cases;words+=native_trace.size();paused+=native_world.paused;limited+=result.script_operations==0;
    }
    for(std::uint32_t seed=0;seed<4096;++seed){
        native_world.mode=std::uint8_t(seed%3);native_world.paused=(seed/3)%3==0;native_world.selected_actor=std::uint8_t(seed%4);
        native_world.session().clock_mode=std::uint8_t((seed/7)%3);native_world.session().session_state=std::int16_t((seed/13)%3);
        native.state={};auto& state=native.state;state.control_armed=std::uint8_t(seed%3);state.control_state=std::uint8_t((seed/7)%3);
        state.exit_requested=std::uint8_t((seed/11)%2);state.short_exit_adjustment=std::uint8_t(seed%2);state.transition_gate=std::uint8_t((seed/17)%2);
        state.pause_latched=std::uint8_t((seed/23)%2);state.request_flags=seed%3?0:0x100;state.control_flags=seed%5?0:0x4000;state.session_work_gate=std::int16_t(seed%2);
        native.clock().restore({std::uint8_t(seed%100),59,59,std::uint8_t(seed%3?59:0)},seed%2?UINT32_MAX:seed);
        write(ram.data(),native);read(ram.data(),reference);reference.state=state;
        const auto dispatch=native_world.mode==0?s::DispatchProfile::offline_actor:s::DispatchProfile::ordinary;install(native,dispatch);install(reference,dispatch);
        native.flags().restore({});reference.flags().restore({});native.events().clear();reference.events().clear();native.linked().clear();reference.linked().clear();
        for(auto* o:{&native,&reference})for(std::size_t i=0;i<8;++i)o->timers().arm(i,0,{t::FlagScope::scenario,0});
        std::vector<std::uint32_t> native_trace,reference_trace;PhaseWorkers n,r;n.workers.seed=r.workers.seed=seed;original_workers=&r.workers;original_phase=&r;
        trace=&reference_trace;R5900Context ctx;ctx.pc=0x5fea30;SET_GPR_U32(&ctx,29,0x1ff0000);SET_GPR_U32(&ctx,31,0x123456);PS2Runtime runtime;runtime.port=original_port;
        o2_005FEA30_0x5fea30(ram.data(),&ctx,&runtime);
        trace=&native_trace;const auto result=native.advance(n,actors);write(expected.data(),native);
        if(ctx.pc!=0x123456 || result.status!=u::Status::completed || native_trace!=reference_trace){
            std::cerr<<"Phase mismatch seed "<<seed<<" sizes "<<native_trace.size()<<" "<<reference_trace.size()<<" status "<<unsigned(result.status)<<"\n";
            for(std::size_t i=0;i<std::min(native_trace.size(),reference_trace.size());++i)if(native_trace[i]!=reference_trace[i]){std::cerr<<"first "<<i<<" native "<<native_trace[i]<<" original "<<reference_trace[i]<<"\n";break;}
            throw std::runtime_error("Native phase trace");
        }
        for(auto [begin,count]:{std::pair{0x3241f8u,0x300u},{0x4badd0u,0x100u}})
            for(std::uint32_t i=begin;i<begin+count;++i)if(ram[i]!=expected[i])throw std::runtime_error("Native phase state seed "+std::to_string(seed)+" at "+std::to_string(i));
        ++phase_cases;phase_words+=native_trace.size();committed+=result.clock_committed;
    }
    original_phase=nullptr;
    std::vector<std::uint32_t> lifecycle_trace;trace=&lifecycle_trace;Workers work;work.seed=23;
    w::World lifecycle_world(profile,std::make_shared<w::Session>());lifecycle_world.mode=1;Notifications notifications;
    u::Owner lifecycle(lifecycle_world,notifications);std::uint32_t checks{};
    const auto check=[&](bool okay){++checks;if(!okay)throw std::runtime_error("Native update owner lifetime/admission check "+std::to_string(checks));};
    check(lifecycle.clock().restore({0,0,8,0},0)==t::Status::completed);
    check(lifecycle_world.session().timer_seconds()==8 && lifecycle_world.session().timer_subseconds()==0);
    check(lifecycle.clock().commit_update(t::ClockStep::one)==t::Status::completed && lifecycle_world.session().timer_subseconds()==1);
    lifecycle.clock().restore({},0);bool duplicate_refused=false;
    try{u::Owner duplicate(lifecycle_world,notifications);}catch(const std::invalid_argument&){duplicate_refused=true;}
    check(duplicate_refused && lifecycle_world.session().timing==&lifecycle);
    check(lifecycle.run_workers(work,actors).status==u::Status::script_failure);
    install(lifecycle,s::DispatchProfile::ordinary);
    check(lifecycle.timers().arm(0,1,{t::FlagScope::scenario,600})==t::Status::completed);
    check(lifecycle.run_workers(work,actors).status==u::Status::flag_failure);
    work.on_reset=[&](u::Owner& owner){check(owner.run_workers(work,actors).status==u::Status::busy);check(owner.close()==u::Status::busy);};
    check(lifecycle.run_workers(work,actors).status==u::Status::completed);work.on_reset={};
    check(lifecycle.linked().create(std::make_shared<Linked>(29)).status==t::Status::completed);
    check(lifecycle.run_workers(work,actors,{},4096,0).status==u::Status::task_failure);
    check(lifecycle.clock().update_counter()==0 && lifecycle.clock().sixtieth_units()==0);
    work.on_reset=[](u::Owner&){throw std::runtime_error("Declared effect failure");};bool threw=false;
    try{(void)lifecycle.run_workers(work,actors);}catch(const std::runtime_error&){threw=true;}
    check(threw);work.on_reset={};check(lifecycle.run_workers(work,actors).status==u::Status::completed);
    check(lifecycle.close()==u::Status::completed);check(lifecycle.run_workers(work,actors).status==u::Status::closed);
    check(lifecycle_world.session().timing==nullptr);
    bool destructor_reentry=false;
    {
        u::Owner retiring(lifecycle_world,notifications);
        auto destructor=std::make_shared<Destruction>([&]{
            destructor_reentry=retiring.run_workers(work,actors).status==u::Status::closed;
            check(retiring.events().install(0,0,std::make_shared<Event>(retiring)).status==t::Status::closed);
            check(retiring.linked().create(std::make_shared<Linked>(9)).status==t::Status::closed);
        });
        check(retiring.linked().create(destructor).status==t::Status::completed);destructor.reset();
    }
    check(destructor_reentry);
    std::cout<<"{\"status\":\"passed\",\"cases\":"<<cases<<",\"trace_words\":"<<words<<",\"paused_after\":"<<paused<<",\"limit_paths\":"<<limited<<",\"native_owner_checks\":"<<checks<<",\"phase_cases\":"<<phase_cases<<",\"phase_trace_words\":"<<phase_words<<",\"committed_updates\":"<<committed<<"}\n";
    return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
