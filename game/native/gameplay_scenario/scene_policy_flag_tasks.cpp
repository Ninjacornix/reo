#include "scene_policy_flag_tasks.hpp"
#include "flags.hpp"
#include "../gameplay_world/world.hpp"
#include <array>
#include <new>
#include <vector>

namespace reo::native::gameplay_scenario {
struct ScenePolicyFlagTasks::Shared {
    gameplay_world::World& world;FlagState& flags;gameplay_tasks::EventTasks& events;
    struct Registration {gameplay_tasks::Handle handle;};
    std::vector<Registration> registrations;
    ScenePolicyTaskStatus fault{ScenePolicyTaskStatus::completed};bool closed{};
    Shared(gameplay_world::World& w,FlagState& f,gameplay_tasks::EventTasks& e):world(w),flags(f),events(e){}
    void unregister(const gameplay_tasks::Handle& handle)noexcept{
        for(auto it=registrations.begin();it!=registrations.end();++it)
            if(it->handle==handle){registrations.erase(it);return;}
    }
    struct Task final:gameplay_tasks::EventTask {
        std::shared_ptr<Shared> shared_;
        ScenePolicyTaskRegistration value_;
        Task(std::shared_ptr<Shared> shared,ScenePolicyTaskRegistration value):shared_(std::move(shared)),value_(value){}
        void update(gameplay_tasks::EventTasks& events,const gameplay_tasks::Handle& handle,
                gameplay_tasks::EventContext context)noexcept override{
            if(shared_->closed||&events!=&shared_->events||context.bank!=value_.bank||context.slot!=value_.slot){
                shared_->fault=shared_->closed?ScenePolicyTaskStatus::closed:ScenePolicyTaskStatus::unavailable_owner;
                if(shared_->closed){shared_->unregister(handle);(void)events.erase(handle);}return;
            }
            const bool set=value_.callback==ScenePolicyFlagCallback::set_primary;
            if(!shared_->flags.actor_flag(ActorFlagFamily::primary,
                ActorFlagSelection{false,value_.actor_owner},value_.flag,set)){
                shared_->fault=ScenePolicyTaskStatus::unavailable_owner;return;
            }
            shared_->unregister(handle);(void)events.erase(handle);
        }
    };
};
ScenePolicyFlagTasks::ScenePolicyFlagTasks(gameplay_world::World& world,FlagState& flags,
    gameplay_tasks::EventTasks& events):shared_(std::make_shared<Shared>(world,flags,events)){}
ScenePolicyFlagTasks::~ScenePolicyFlagTasks(){(void)close();}
ScenePolicyTaskStatus ScenePolicyFlagTasks::register_callback(ScenePolicyTaskRegistration value){
    auto& state=*shared_;
    if(state.closed||state.world.closed()||!state.events.open())return ScenePolicyTaskStatus::closed;
    if(state.fault!=ScenePolicyTaskStatus::completed)return state.fault;
    if(value.bank>=gameplay_tasks::EventTasks::banks||value.slot>=gameplay_tasks::EventTasks::slots_per_bank||
       value.actor_owner>=gameplay_tasks::EventTasks::banks||value.callback>ScenePolicyFlagCallback::set_primary)
        return ScenePolicyTaskStatus::invalid_payload;
    if(state.events.slot(value.bank,value.slot))return ScenePolicyTaskStatus::busy;
    try{
        state.registrations.push_back({});
        auto task=std::make_shared<Shared::Task>(shared_,value);const auto created=state.events.install(value.bank,value.slot,std::move(task));
        if(created.status==gameplay_tasks::Status::no_memory){state.registrations.pop_back();return ScenePolicyTaskStatus::no_memory;}
        if(created.status!=gameplay_tasks::Status::completed){state.registrations.pop_back();return ScenePolicyTaskStatus::unavailable_owner;}
        state.registrations.back()={created.handle};return ScenePolicyTaskStatus::completed;
    }catch(const std::bad_alloc&){if(!state.registrations.empty()&&!state.registrations.back().handle)state.registrations.pop_back();return ScenePolicyTaskStatus::no_memory;}
}
ScenePolicyTaskStatus ScenePolicyFlagTasks::failure()const noexcept{return shared_->fault;}
ScenePolicyTaskStatus ScenePolicyFlagTasks::close()noexcept{
    auto& state=*shared_;if(state.closed)return ScenePolicyTaskStatus::completed;
    state.closed=true;if(!state.events.idle())return ScenePolicyTaskStatus::busy;
    for(const auto& value:state.registrations)(void)state.events.erase(value.handle);
    state.registrations.clear();return ScenePolicyTaskStatus::completed;
}
}
