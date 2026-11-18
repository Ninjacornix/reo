#include "tasks.hpp"
#include "events.hpp"
#include <bit>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <limits>
#include <vector>

namespace g = reo::native::gameplay_tasks;
namespace {
unsigned checks{};
void check(bool value, const char* label) { ++checks; if (!value) { std::fprintf(stderr,"FAILED: %s\n",label); std::abort(); } }
struct Action final : g::Task {
    int id; std::vector<int>& log;
    std::function<void(g::Scheduler&, const g::Handle&)> action;
    Action(int value, std::vector<int>& events) : id(value), log(events) {}
    void update(g::Scheduler& owner, const g::Handle& self) noexcept override {
        log.push_back(id); const auto work=action; if (work) work(owner,self);
    }
    void present(g::Scheduler&, const g::Handle&) noexcept override { log.push_back(1000+id); }
};
struct Sink final : g::FlagSink {
    std::vector<g::FlagExpiry> events;
    std::function<void(const g::FlagExpiry&)> action;
    void expired(const g::FlagExpiry& event) noexcept override { events.push_back(event); if(action)action(event); }
};
struct DestructorProbe final:g::Task {
    g::Scheduler& owner;g::Status& observed;std::vector<int>& log;
    DestructorProbe(g::Scheduler& s,g::Status& result,std::vector<int>& events):owner(s),observed(result),log(events){}
    ~DestructorProbe()override{observed=owner.create(std::make_shared<Action>(99,log)).status;}
    void update(g::Scheduler&,const g::Handle&)noexcept override{}
};
void ordering() {
    std::vector<int> log; g::Scheduler scheduler;
    auto one=std::make_shared<Action>(1,log), two=std::make_shared<Action>(2,log);
    const auto first=scheduler.create(one,{0,255,true});
    const auto second=scheduler.create(two,{128,128,true});
    check(first.status==g::Status::completed && second.status==g::Status::completed,"native creation");
    one->action=[&](auto& owner,const auto&){one->action={};check(owner.create(std::make_shared<Action>(3,log)).status==g::Status::completed,"head child created");};
    check(scheduler.run(g::Pass::update).called==3 && log==std::vector<int>({1,2,3}),"head child joins same oldest-first pass; primary ignores active mask");
    log.clear();check(scheduler.run(g::Pass::presentation).called==1 && log==std::vector<int>({1002}),"secondary requires intersection and actual callback");
    check(scheduler.policy(second.handle,{255,128,false})==g::Status::completed,"secondary policy change");
    log.clear();check(scheduler.run(g::Pass::presentation).called==0 && log.empty(),"null-equivalent secondary callback suppressed");
    check(scheduler.erase(first.handle)==g::Status::completed && !scheduler.contains(first.handle),"native retirement");
    check(scheduler.erase(first.handle)==g::Status::foreign_or_stale,"double retirement refused");
    g::Scheduler other;check(!other.contains(second.handle) && other.erase(second.handle)==g::Status::foreign_or_stale,"foreign domain refused");
}
void mutation_and_lifetime() {
    std::vector<int> log;g::Scheduler owner;
    auto a=std::make_shared<Action>(1,log),b=std::make_shared<Action>(2,log),c=std::make_shared<Action>(3,log);
    auto ha=owner.create(a).handle,hb=owner.create(b).handle;owner.create(c);
    a->action=[&](auto& s,const auto&){a->action={};check(s.erase(hb)==g::Status::completed,"remove upcoming task");};
    check(owner.run(g::Pass::update).status==g::Status::completed && log==std::vector<int>({1,3}),"live predecessor read skips removed upcoming task");
    log.clear();a->action=[&](auto& s,const auto& self){a->action={};check(s.erase(self)==g::Status::completed,"self retire");check(s.create(std::make_shared<Action>(4,log)).status==g::Status::completed,"capacity restored immediately");check(!s.contains(self),"retired handle never aliases replacement");};
    check(owner.run(g::Pass::update).status==g::Status::completed && log==std::vector<int>({1,3,4}),"retired cursor survives and new head remains reachable");
    check(!owner.contains(ha),"old cursor handle stale after pass");
    check(owner.clear()==g::Status::completed && owner.size()==0,"clear releases native ownership");
    auto retained=std::make_shared<Action>(5,log);std::weak_ptr<Action> weak=retained;
    retained->action=[&](auto& s,const auto& self){check(s.run(g::Pass::update).status==g::Status::busy,"nested pass refused");check(s.clear()==g::Status::busy,"reset cannot tear down executing pass");check(s.erase(self)==g::Status::completed && !weak.expired(),"task stays alive through its callback");};
    owner.create(retained);retained.reset();owner.run(g::Pass::update);check(weak.expired(),"retired task releases after callback");
    g::Status destructor_creation=g::Status::invalid;
    owner.create(std::make_shared<DestructorProbe>(owner,destructor_creation,log));
    check(owner.clear()==g::Status::completed && owner.size()==0 && destructor_creation==g::Status::busy,"bulk retirement refuses destructor reentry mutation and finishes empty");
}
void oldest_and_bounds() {
    std::vector<int> log;g::Scheduler owner;auto a=std::make_shared<Action>(1,log);
    owner.create(a);owner.create(std::make_shared<Action>(2,log));
    a->action=[&](auto& s,const auto&){a->action={};s.create(std::make_shared<Action>(3,log),{},g::Placement::oldest);};
    owner.run(g::Pass::update);check(log==std::vector<int>({1,2}),"new tail waits for next pass");
    log.clear();owner.run(g::Pass::update);check(log==std::vector<int>({3,1,2}),"oldest insertion changes next pass order");
    log.clear();auto bounded=owner.run(g::Pass::update,2);check(bounded.status==g::Status::budget_exhausted && bounded.called==2 && log==std::vector<int>({3,1}),"bounded work reports incomplete pass");
    check(owner.run(g::Pass::update,0).status==g::Status::invalid,"zero work bound refused");
    check(owner.run(static_cast<g::Pass>(99)).status==g::Status::invalid,"invalid phase refused");
    check(owner.create({}).status==g::Status::invalid,"unowned callback refused");
    owner.clear();for(unsigned i=0;i<32;++i)check(owner.create(std::make_shared<Action>(int(i),log)).status==g::Status::completed,"stock capacity admitted");
    check(owner.create(std::make_shared<Action>(99,log)).status==g::Status::full && owner.size()==32,"bounded exhaustion does not mutate tasks");
}
void timer_edges_and_events() {
    g::FlagTimers timers;Sink sink;
    for(unsigned bits=0;bits<65536;++bits){
        const auto input=std::bit_cast<std::int16_t>(static_cast<std::uint16_t>(bits));
        check(timers.arm(0,input,{g::FlagScope::scenario,17})==g::Status::completed,"all signed countdown states stored");
        sink.events.clear();timers.tick(sink);
        check(timers.snapshot()[0].remaining==(input>0?input-1:input),"only signed-positive values decrement");
        check(sink.events.size()==std::size_t(input==1),"only positive-to-zero expires");
    }
    timers.arm(0,1,{g::FlagScope::scenario,3});timers.arm(1,0,{g::FlagScope::session_owner_zero,4});
    sink.events.clear();sink.action=[&](const auto& event){
        check(timers.snapshot()[event.slot].remaining==0,"expiration publishes zero before consumer");
        check(timers.tick(sink)==g::Status::busy,"recursive timer pass refused");
        if(event.slot==0){timers.arm(0,2,{g::FlagScope::scenario,5});timers.arm(1,1,{g::FlagScope::session_owner_zero,6});}
    };
    timers.tick(sink);check(sink.events.size()==2 && sink.events[0].slot==0 && sink.events[1].slot==1 && sink.events[1].target.id==6,"synchronous expiry mutation affects later timer in same pass");
    check(timers.snapshot()[0].remaining==2,"rearmed earlier slot waits for next invocation");
    const auto before=timers.snapshot();check(timers.arm(8,1,{})==g::Status::invalid && timers.arm(0,1,{g::FlagScope::scenario,0x8000})==g::Status::invalid,"typed invalid timer targets refused");
    check(timers.snapshot()[0].remaining==before[0].remaining && timers.snapshot()[0].target==before[0].target,"invalid arm keeps existing timer");
}
void clocks() {
    g::SimulationClock clock;check(clock.restore({99,59,59,59},std::numeric_limits<std::uint32_t>::max())==g::Status::completed,"valid clock restore");
    check(clock.commit_update(g::ClockStep::two)==g::Status::completed && clock.play_time()==g::PlayTime({0,0,0,1}) && clock.update_counter()==0,"play carry and update wrap preserve distinct units");
    check(clock.restore({0,0,0,0},0)==g::Status::completed,"clock reset");
    for(unsigned i=0;i<30;++i)clock.commit_update(g::ClockStep::two);
    check(clock.play_time()==g::PlayTime({0,0,1,0}) && clock.update_counter()==30,"thirty admitted double-unit updates yield sixty clock units");
    auto before=clock.play_time();check(clock.restore({100,0,0,0},123)==g::Status::invalid && clock.play_time()==before && clock.update_counter()==30,"invalid restore atomic");
    check(clock.commit_update(static_cast<g::ClockStep>(0))==g::Status::invalid && clock.update_counter()==30,"invalid clock step refused");
    clock.adjust_update_counter(150);check(clock.update_counter()==180 && clock.play_time()==before,"explicit request adjustment does not advance play time");
    // Repeated task/presentation work alone cannot accelerate the game clock.
    std::vector<int> log;g::Scheduler scheduler;scheduler.create(std::make_shared<Action>(1,log));
    for(unsigned i=0;i<100;++i){scheduler.run(g::Pass::update);scheduler.run(g::Pass::presentation);}
    check(clock.update_counter()==180 && clock.play_time()==before,"render/task invocation count is not gameplay clock authority");
}
struct EventWork final:g::EventTask {
    int id;std::vector<int>& log;std::function<void(g::EventTasks&,const g::Handle&,g::EventContext)> action;
    EventWork(int value,std::vector<int>& events):id(value),log(events){}
    void update(g::EventTasks& owner,const g::Handle& self,g::EventContext context)noexcept override{
        log.insert(log.end(),{id,context.bank,context.slot,context.owner.actor});const auto work=action;if(work)work(owner,self,context);
    }
};
void event_slots(){
    g::EventTasks owner,foreign;g::OwnerSelection selected{7};std::vector<int> log;
    auto a=std::make_shared<EventWork>(1,log),b=std::make_shared<EventWork>(2,log),c=std::make_shared<EventWork>(3,log);
    auto first=owner.install(0,5,a),second=owner.install(1,0,b),third=owner.install(2,9,c);
    check(first.status==g::Status::completed&&second.status==g::Status::completed&&third.status==g::Status::completed,"native event slots installed");
    check(owner.run(g::EventMode::shared_bank,selected).called==1&&selected.actor==7&&log==std::vector<int>({1,0,5,7}),"shared bank preserves caller selection");
    log.clear();selected.actor=6;owner.run(g::EventMode::owner_banks,selected);
    check(log==std::vector<int>({1,0,5,6,2,1,0,1,3,2,9,2})&&selected.actor==0,"bank and slot order with explicit owner changes and final restorezero");
    check(foreign.erase(first.handle)==g::Status::foreign_or_stale,"event owner identity isolated");
    check(owner.install(0,5,b).status==g::Status::full&&owner.install(3,0,b).status==g::Status::invalid,"event slot collision and bounds refused");
    check(owner.enabled(second.handle,false)==g::Status::completed,"event activity gate distinct from linked primary");
    a->action=[&](auto& s,const auto& self,auto context){a->action={};
        check(s.run(g::EventMode::owner_banks,selected).status==g::Status::busy&&s.clear()==g::Status::busy,"event pass reentry and reset refused");
        check(s.erase(self)==g::Status::completed&&!s.contains(self),"current event handle retired");
        check(s.install(0,6,std::make_shared<EventWork>(4,log)).status==g::Status::completed,"later event slot installed during callback");context.owner.actor=4;
    };
    log.clear();selected.actor=2;auto pass=owner.run(g::EventMode::shared_bank,selected);
    check(pass.visited==10&&pass.called==2&&log==std::vector<int>({1,0,5,2,4,0,6,4}),"live later event slot executes same pass with callback-modified owner selection");
    check(!owner.contains(first.handle)&&owner.contains(third.handle),"event lifecycle invalidates only retired task");
    check(owner.clear()==g::Status::completed&&owner.size()==0&&!owner.contains(third.handle),"event ownership clears without stale aliases");
    std::uint8_t canonical=9;auto borrowed=g::OwnerSelection::borrow(canonical);
    auto observe=std::make_shared<EventWork>(5,log);
    observe->action=[&](auto&,const auto&,auto context){
        check(&context.owner.actor==&canonical,"event owner is canonical session storage");
        context.owner.actor=21;check(canonical==21,"callback selection publication is synchronous");
    };
    check(owner.install(0,0,observe).status==g::Status::completed,"borrowed event owner install");
    check(owner.run(g::EventMode::shared_bank,borrowed).called==1&&canonical==21,"shared borrowed selection retained");
    check(owner.run(g::EventMode::owner_banks,borrowed).called==1&&canonical==0,"borrowed owner banks normalize canonical selection");
    check(owner.seal()==g::Status::completed && owner.size()==1,"sealing retains payloads until the composite owner releases them");
    check(owner.install(0,1,observe).status==g::Status::closed && owner.run(g::EventMode::shared_bank,borrowed).status==g::Status::closed,"sealed event pass/admission stay closed");
    check(owner.clear()==g::Status::completed && owner.size()==0,"sealed event payloads can retire after composite sealing");
}
}
int main(){ordering();mutation_and_lifetime();oldest_and_bounds();timer_edges_and_events();clocks();event_slots();std::printf("Native gameplay ownership/order/timer/clock checks passed: %u assertions\n",checks);}
