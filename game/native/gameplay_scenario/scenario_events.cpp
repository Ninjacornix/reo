#include "scenario_events.hpp"
#include "flags.hpp"
#include "../gameplay_tasks/events.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_collision/impact_populations.hpp"
#include <bit>
namespace reo::native::gameplay_scenario {
namespace tasks=gameplay_tasks;
namespace {
#include "scenario_event_profiles.inc"
}
struct ScenarioEvents::Shared {
    gameplay_world::World& world;FlagState& flags;tasks::FlagTimers& timers;tasks::EventTasks& events;
    struct Registration {std::weak_ptr<Task> task;bool requested{};};
    std::array<Registration,2> presentation;
    gameplay_effects::WorkBackend* effect_work{};
    ScenarioEventStatus failure{ScenarioEventStatus::completed};bool closed{};
    Shared(gameplay_world::World& w,FlagState& f,tasks::FlagTimers& t,tasks::EventTasks& e):world(w),flags(f),timers(t),events(e){}
    void unregister(const Task* task)noexcept;
};
struct ScenarioEvents::Task final:tasks::EventTask,std::enable_shared_from_this<Task> {
    std::shared_ptr<Shared> shared;
    ScenarioEventState state;
    Task(std::shared_ptr<Shared> owner,ScenarioEventState value):shared(std::move(owner)),state(value){}
    ~Task()override{shared->unregister(this);}
    bool update_scenario()noexcept{
        auto& world=shared->world;auto& flags=shared->flags;auto& args=state.arguments;
        const auto fail=[&](){shared->failure=ScenarioEventStatus::unavailable_owner;return false;};
        const auto scenario_flag=[&](std::uint32_t id,std::uint8_t value){
            return flags.scenario(id,value,NotifyOwner::selected_actor_plus_one,std::uint8_t(world.selected_actor+1));
        };
        const auto primary_flag=[&](std::uint32_t id,bool value,std::uint8_t bank=0){
            return flags.actor_flag(ActorFlagFamily::primary,{false,world.mode==0?bank:std::uint8_t(0)},id,value);
        };
        if(*state.scenario==41&&state.kind==9){ // Complete6FD060.
            const auto choice=(world.session().random.request(0)>>6)&3u;
            if(!primary_flag(38+choice,true,state.owner_selector)||!primary_flag(89,true,state.owner_selector))return fail();
            return true;
        }
        if(*state.scenario==2&&state.kind==15){ // Complete5A30F0.
            const auto choice=world.session().random.request(0)%22;
            for(unsigned i=0;i<8;++i){args[0]=498+i;if(!scenario_flag(args[0],puzzle_patterns[choice][i]))return fail();}
            args[0]=94;if(!primary_flag(94,true,state.owner_selector))return fail();
            const auto alternate=(world.session().random.request(0)>>6)&3u;
            if(!primary_flag(32+alternate,true,state.owner_selector))return fail();
            return true;
        }
        if(*state.scenario==35&&state.kind==11){ // Complete5B8880.
            auto* works=shared->effect_work;
            if(!works||!works->bound_to(world.session().random)||!works->admitted())return fail();
            transform_math::Matrix matrix{};matrix[1][1]=matrix[2][2]=matrix[3][3]=1;
            gameplay_collision::Vec3 point{4400,-3600,8730};
            try{
                if(gameplay_collision::delivery::oriented_contact_impact(*works,world.session().random,matrix,point,1)!=gameplay_collision::delivery::Status::completed)return fail();
            }catch(...){return fail();}
            return true;
        }
        if(*state.scenario==35&&state.kind==19){ // Complete5B8C90.
            if(flags.get(FlagBank::scenario,79).value_or(false))return true;
            std::uint8_t chosen{};
            if(args[0]==24){
                if((world.session().random.request(1)&3u)!=0){
                    if(!scenario_flag(args[3],true)||!primary_flag(args[4],true)||!primary_flag(133,true)||
                       !flags.write(FlagBank::local_auxiliary,args[2],true))return fail();
                    chosen=1;
                }
            }else{
                constexpr std::array<std::uint8_t,5> rooms{23,24,27,28,30};
                for(std::uint8_t i=1;i<3;++i){const auto actor=world.primary(i);
                    if(!actor||!actor->active||(actor->status&0x5e8u))continue;
                    for(const auto room:rooms)if(actor->room==room){
                        if(!scenario_flag(args[3],true)||!flags.scenario_owner(args[3],std::uint8_t(i+1))||
                           !primary_flag(args[4],true,i)||!primary_flag(133+i,true))return fail();
                        chosen=std::uint8_t(i+1);break;
                    }
                    if(chosen)break;
                }
            }
            if(!chosen)return true; //5B8E58 branches directly to5B8F28 retirement.
            for(std::uint8_t i=0;i<3;++i){const auto actor=world.primary(i);
                if(!actor||!actor->active||(actor->status&0x5e0u)||actor->room!=20||i==chosen-1)continue;
                if((chosen!=1&&!primary_flag(84,true))||!primary_flag(139,true)||
                   !primary_flag(std::uint32_t(actor->motion_style)+136,true)||!primary_flag(args[4],false,std::uint8_t(chosen-1)))return fail();
                break;
            }
            return true;
        }
        return fail();
    }
    void update(tasks::EventTasks& events,const tasks::Handle& handle,tasks::EventContext context)noexcept override{
        if(shared->closed||&events!=&shared->events||&context.owner.actor!=&shared->world.selected_actor||
            context.bank!=state.bank||context.slot!=state.slot){shared->failure=ScenarioEventStatus::unavailable_owner;return;}
        if(state.scenario){
            if(shared->failure!=ScenarioEventStatus::completed)return;
            const bool alternate=shared->world.mode==0&&state.owner_selector!=0;
            const auto retire=alternate||update_scenario();
            if(retire&&shared->failure==ScenarioEventStatus::completed){shared->unregister(this);(void)events.erase(handle);}
            return;
        }
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
bool ScenarioEvents::admits_scenario(std::uint32_t kind,std::uint32_t slot,const std::array<std::uint32_t,5>& args)noexcept{
    if(std::uint8_t(slot)>=10)return false;
    switch(std::uint8_t(kind)){
    case 9:case 11:case 15:return true;
    case 19:return args[2]<512&&args[3]<512&&args[4]<512;
    default:return false;
    }
}
bool ScenarioEvents::bound_to(const gameplay_world::World& world)const noexcept{return &state_->world==&world;}
bool ScenarioEvents::ready()const noexcept{return !state_->closed&&!state_->world.closed()&&state_->events.open();}
ScenarioEventStatus ScenarioEvents::failure()const noexcept{return state_->failure;}
bool ScenarioEvents::scenario_ready(std::uint32_t kind,std::uint32_t slot,const std::array<std::uint32_t,5>& args)const noexcept{
    if(!ready()||state_->failure!=ScenarioEventStatus::completed||!admits_scenario(kind,slot,args))return false;
    const auto& world=state_->world;
    if(world.mode==0&&world.selected_actor>=3)return true; //690EF0 returns before scenario/payload reads.
    if(!world.scenario)return false;
    switch(*world.scenario){
    case 2:return std::uint8_t(kind)==15&&state_->flags.notification_ready();
    case 35:
        if(std::uint8_t(kind)==19)return state_->flags.notification_ready();
        return std::uint8_t(kind)==11&&((world.mode==0&&world.selected_actor!=0)||
            (state_->effect_work&&state_->effect_work->bound_to(world.session().random)&&state_->effect_work->admitted()));
    case 41:return std::uint8_t(kind)==9;
    default:return false;
    }
}
ScenarioEventStatus ScenarioEvents::bind_effect_work(gameplay_effects::WorkBackend* works)noexcept{
    if(state_->closed&&!works)return ScenarioEventStatus::completed; //close already retired every borrower.
    if(!ready())return ScenarioEventStatus::closed;
    if(!state_->events.idle())return ScenarioEventStatus::busy;
    if(works==state_->effect_work)return ScenarioEventStatus::completed;
    for(unsigned bank=0;bank<3;++bank)for(unsigned slot=0;slot<10;++slot){
        const auto current=state_->events.slot(bank,slot);if(!current)continue;
        const auto task=std::dynamic_pointer_cast<Task>(current->task);
        if(task&&task->shared==state_)return ScenarioEventStatus::busy;
    }
    if(works&&(!works->admitted()||!works->bound_to(state_->world.session().random)))return ScenarioEventStatus::unavailable_owner;
    state_->effect_work=works;return ScenarioEventStatus::completed;
}
ScenarioEventStatus ScenarioEvents::scenario_command(std::uint32_t kind,std::uint32_t slot,const std::array<std::uint32_t,5>& args){
    if(!ready())return ScenarioEventStatus::closed;
    const auto selected=state_->world.selected_actor;
    const auto bank=state_->world.mode==0?selected:std::uint8_t(0);
    if(bank>=3)return ScenarioEventStatus::completed;
    const auto index=std::uint8_t(slot);if(index>=10)return ScenarioEventStatus::invalid_payload;
    if(const auto current=state_->events.slot(bank,index))return current->enabled?ScenarioEventStatus::completed:ScenarioEventStatus::unavailable_owner;
    if(!admits_scenario(kind,slot,args))return ScenarioEventStatus::invalid_payload;
    if(!scenario_ready(kind,slot,args))return ScenarioEventStatus::unavailable_owner;
    ScenarioEventState data;data.bank=bank;data.slot=index;data.kind=std::uint8_t(kind);data.owner_selector=selected;data.arguments=args;data.scenario=state_->world.scenario;
    try{
        const auto task=std::make_shared<Task>(state_,data);const auto created=state_->events.install(bank,index,task);
        return created.status==tasks::Status::completed?ScenarioEventStatus::completed:
            created.status==tasks::Status::no_memory?ScenarioEventStatus::no_memory:ScenarioEventStatus::unavailable_owner;
    }catch(const std::bad_alloc&){return ScenarioEventStatus::no_memory;}
}
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
    state_->closed=true;state_->presentation={};state_->effect_work=nullptr;
    for(unsigned bank=0;bank<3;++bank)for(unsigned slot=0;slot<10;++slot){
        const auto current=state_->events.slot(bank,slot);if(!current)continue;
        const auto task=std::dynamic_pointer_cast<Task>(current->task);
        if(task&&task->shared==state_)(void)state_->events.erase(current->handle);
    }
    return state_->failure;
}
}
