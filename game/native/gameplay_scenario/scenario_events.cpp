#include "scenario_events.hpp"
#include "flags.hpp"
#include "../gameplay_tasks/events.hpp"
#include "../gameplay_world/world.hpp"
#include <bit>
namespace reo::native::gameplay_scenario {
namespace tasks=gameplay_tasks;
struct ScenarioEvents::Shared {
    gameplay_world::World& world;FlagState& flags;tasks::FlagTimers& timers;tasks::EventTasks& events;
    struct Registration {std::weak_ptr<Task> task;bool requested{};};
    std::array<Registration,2> presentation;
    ScenarioEventStatus failure{ScenarioEventStatus::completed};bool closed{};
    Shared(gameplay_world::World& w,FlagState& f,tasks::FlagTimers& t,tasks::EventTasks& e):world(w),flags(f),timers(t),events(e){}
    void unregister(const Task* task)noexcept;
};
struct ScenarioEvents::Task final:tasks::EventTask,std::enable_shared_from_this<Task> {
    std::shared_ptr<Shared> shared;
    ScenarioEventState state;
    Task(std::shared_ptr<Shared> owner,ScenarioEventState value):shared(std::move(owner)),state(value){}
    ~Task()override{shared->unregister(this);}
    void update(tasks::EventTasks& events,const tasks::Handle& handle,tasks::EventContext context)noexcept override{
        if(shared->closed||&events!=&shared->events||&context.owner.actor!=&shared->world.selected_actor||
            context.bank!=state.bank||context.slot!=state.slot){shared->failure=ScenarioEventStatus::unavailable_owner;return;}
        if(state.bank){ // Actual5BAED0 tail-calls5B93B0: retire this record.
            shared->unregister(this);(void)events.erase(handle);return;
        }
        const auto enabled=shared->flags.get(FlagBank::local_primary,state.arguments[2]);
        if(!enabled){shared->failure=ScenarioEventStatus::invalid_payload;return;}
        if(!*enabled){shared->unregister(this);(void)events.erase(handle);return;}
        if(state.phase==2){state.phase=1;return;}
        if(!state.phase){state.render_style=2;state.phase=1;}
        else if(state.phase!=1)return;
        if(!shared->world.session().inventory_owner){
            shared->presentation[1]={weak_from_this(),true};
            state.phase=1;
        }
    }
};
void ScenarioEvents::Shared::unregister(const Task* task)noexcept{
    // Control-block identity also works during final task destruction, when a
    // weak lock can no longer succeed. The first matching registration wins.
    const auto identity=task->weak_from_this();
    for(auto& registration:presentation)
        if(!registration.task.owner_before(identity)&&!identity.owner_before(registration.task)){registration={};return;}
}
ScenarioEvents::ScenarioEvents(gameplay_world::World& world,FlagState& flags,tasks::FlagTimers& timers,tasks::EventTasks& events):
    state_(std::make_shared<Shared>(world,flags,timers,events)){}
ScenarioEvents::~ScenarioEvents(){(void)close();}
bool ScenarioEvents::admits(std::uint32_t kind,std::uint32_t slot,const std::array<std::uint32_t,5>& args)noexcept{
    return std::uint8_t(kind)==6&&std::uint8_t(slot)<10&&std::bit_cast<std::int32_t>(args[0])>=0&&
        std::bit_cast<std::int32_t>(args[1])>=0&&args[2]<512&&args[3]<512&&args[4]<512;
}
bool ScenarioEvents::bound_to(const gameplay_world::World& world)const noexcept{return &state_->world==&world;}
bool ScenarioEvents::ready()const noexcept{return !state_->closed&&!state_->world.closed()&&state_->events.open();}
ScenarioEventStatus ScenarioEvents::failure()const noexcept{return state_->failure;}
ScenarioEventStatus ScenarioEvents::command(std::uint32_t kind,std::uint32_t slot,const std::array<std::uint32_t,5>& args){
    if(!ready())return ScenarioEventStatus::closed;
    const auto selected=state_->world.selected_actor;
    const auto bank=state_->world.mode==0?selected:std::uint8_t(0);
    if(bank>=3)return ScenarioEventStatus::completed; // Source returns before payload reads.
    const auto index=std::uint8_t(slot);
    if(index>=10)return ScenarioEventStatus::invalid_payload;
    if(const auto current=state_->events.slot(bank,index)){
        if(current->enabled)return ScenarioEventStatus::completed;
        // Arbitrary external disabling does not establish the stock clear/
        // presentation-retirement contract. Source-owned callbacks erase.
        return ScenarioEventStatus::unavailable_owner;
    }
    if(!admits(kind,slot,args))return ScenarioEventStatus::invalid_payload;
    ScenarioEventState data;data.bank=bank;data.slot=index;data.kind=std::uint8_t(kind);data.owner_selector=selected;data.arguments=args;
    try{
        const auto task=std::make_shared<Task>(state_,data);const auto created=state_->events.install(bank,index,task);
        return created.status==tasks::Status::completed?ScenarioEventStatus::completed:
            created.status==tasks::Status::no_memory?ScenarioEventStatus::no_memory:ScenarioEventStatus::unavailable_owner;
    }catch(const std::bad_alloc&){return ScenarioEventStatus::no_memory;}
}
std::optional<ScenarioEventState> ScenarioEvents::inspect(std::uint8_t bank,std::uint8_t slot)const noexcept{
    const auto current=state_->events.slot(bank,slot);if(!current)return{};
    const auto task=std::dynamic_pointer_cast<Task>(current->task);
    return task&&task->shared==state_?std::optional(task->state):std::nullopt;
}
ScenarioEventPresented ScenarioEvents::present_timer_hud()noexcept{
    if(!ready())return{ScenarioEventStatus::closed,{}};
    if(!state_->events.idle())return{ScenarioEventStatus::busy,{}};
    auto& registration=state_->presentation[1];const auto task=registration.task.lock();
    if(!task){registration={};return{};}
    if(!registration.requested)return{};
    const auto alternate=state_->flags.get(FlagBank::local_primary,task->state.arguments[3]);
    const auto pulse=state_->flags.get(FlagBank::local_primary,task->state.arguments[4]);
    if(!alternate||!pulse)return{ScenarioEventStatus::invalid_payload,{}};
    std::array<std::int16_t,8> countdowns;for(unsigned i=0;i<countdowns.size();++i)countdowns[i]=state_->timers.snapshot()[i].remaining;
    auto frame=timer_hud(task->state.pulse,countdowns,task->state.arguments[0],task->state.arguments[1],*alternate,*pulse);
    if(frame.status!=TimerHudStatus::complete)return{ScenarioEventStatus::invalid_payload,{}};
    if(frame.acknowledge)registration.requested=false;
    return{ScenarioEventStatus::completed,std::move(frame)};
}
ScenarioEventStatus ScenarioEvents::close()noexcept{
    if(state_->closed)return state_->failure;
    if(!state_->events.idle())return ScenarioEventStatus::busy;
    state_->closed=true;state_->presentation={};
    for(unsigned bank=0;bank<3;++bank)for(unsigned slot=0;slot<10;++slot){
        const auto current=state_->events.slot(bank,slot);if(!current)continue;
        const auto task=std::dynamic_pointer_cast<Task>(current->task);
        if(task&&task->shared==state_)(void)state_->events.erase(current->handle);
    }
    return state_->failure;
}
}
