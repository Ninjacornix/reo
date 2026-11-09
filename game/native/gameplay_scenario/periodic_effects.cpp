#include "periodic_effects.hpp"
#include <algorithm>
#include <bit>
#include <new>
namespace reo::native::gameplay_scenario {
namespace {
std::int16_t half(std::int32_t value)noexcept{return std::bit_cast<std::int16_t>(std::uint16_t(std::uint32_t(value)));}
PeriodicStatus emit_periodic(PeriodicState& state,gameplay_session::Random& random,PeriodicEmitter& emitter)noexcept{
    const auto descriptor=std::uint16_t(random.request(1)%3+0x24);
    const auto result=emitter.emit({descriptor,state.position,0x1a193});
    if(result.status==EmissionStatus::pool_full)return PeriodicStatus::completed;
    if(result.status!=EmissionStatus::completed || !result.visual)return PeriodicStatus::emitter_unavailable;
    auto& visual=*result.visual;visual.position=state.position;visual.delay=0;visual.scale=30;
    const auto old_phase=std::int32_t(state.packed)>>12;
    const auto next=half(old_phase==2?0:old_phase+1);
    auto packed=std::uint16_t(std::uint32_t(std::int32_t(next)*4096));
    const auto duration=std::int32_t(visual.remaining)/2;
    auto delay=half(duration+30*(next==0?std::int32_t(next):std::int32_t(next)+1)-4);
    if(delay<0)delay=0;
    packed=std::uint16_t(packed|std::bit_cast<std::uint16_t>(delay));state.packed=std::bit_cast<std::int16_t>(packed);
    return PeriodicStatus::completed;
}
}
PeriodicStep update_periodic(PeriodicState& state,std::uint16_t stop,FlagState& flags,
    gameplay_session::Random& random,PeriodicEmitter& emitter)noexcept{
    const auto cancelled=flags.get(stop&0x8000?FlagBank::bounded_halfword:FlagBank::bounded_byte,
        stop&0x8000?stop&15:stop);
    if(!cancelled)return{PeriodicStatus::flag_unavailable,false};
    if(*cancelled)state.phase=3;
    if(state.phase==0){state.phase=1;state.timer=0;state.packed=0;}
    if(state.phase==1){
        state.timer=half(std::int32_t(state.timer)-1);
        if(state.timer<0){
            const auto status=emit_periodic(state,random,emitter);
            if(status!=PeriodicStatus::completed)return{status,false};
            ++state.phase;state.timer=0;
        }
    }else if(state.phase==2){
        state.timer=half(std::int32_t(state.timer)+1);
        if(state.timer>=4){state.timer=std::int16_t(std::uint16_t(state.packed)&0xfff);state.phase=1;}
    }else return{PeriodicStatus::completed,true};
    return{};
}
struct PeriodicEffects::Shared {
    gameplay_tasks::Scheduler& tasks;SceneControls& controls;FlagState& flags;
    gameplay_session::Random& random;PeriodicEmitter& emitter;
    struct Entry {gameplay_tasks::Handle handle;std::shared_ptr<PeriodicState> state;};
    std::vector<Entry> entries;
    PeriodicStatus fault{PeriodicStatus::completed};bool closed{};
    Shared(gameplay_tasks::Scheduler& t,SceneControls& c,FlagState& f,gameplay_session::Random& r,PeriodicEmitter& e):
        tasks(t),controls(c),flags(f),random(r),emitter(e){entries.reserve(gameplay_tasks::Scheduler::capacity);}
};
class PeriodicEffects::Work final:public gameplay_tasks::Task {
    std::shared_ptr<Shared> owner_;SceneControlId parent_;std::shared_ptr<PeriodicState> state_;
public:
    Work(std::shared_ptr<Shared> owner,SceneControlId parent,std::shared_ptr<PeriodicState> state):
        owner_(std::move(owner)),parent_(std::move(parent)),state_(std::move(state)){}
    void update(gameplay_tasks::Scheduler& tasks,const gameplay_tasks::Handle& handle)noexcept override{
        if(owner_->closed){(void)tasks.erase(handle);return;}
        if(owner_->fault!=PeriodicStatus::completed)return;
        const auto parent=owner_->controls.get(parent_);
        if(!parent){(void)tasks.erase(handle);return;}
        const auto five=std::get_if<ControlTypeFive>(&parent->body);
        if(!five){owner_->fault=PeriodicStatus::invalid_control;return;}
        const auto step=update_periodic(*state_,five->reset_sentinel,owner_->flags,owner_->random,owner_->emitter);
        if(step.status!=PeriodicStatus::completed)owner_->fault=step.status;
        if(step.retire)(void)tasks.erase(handle);
    }
};
PeriodicEffects::PeriodicEffects(gameplay_tasks::Scheduler& tasks,SceneControls& controls,FlagState& flags,
    gameplay_session::Random& random,PeriodicEmitter& emitter):shared_(std::make_shared<Shared>(tasks,controls,flags,random,emitter)){}
PeriodicEffects::~PeriodicEffects(){close();}
bool PeriodicEffects::admitted()const noexcept{
    const auto& owner=*shared_;
    if(owner.closed||owner.fault!=PeriodicStatus::completed)return false;
    const bool admitted=owner.emitter.admitted();
    return admitted&&!owner.closed&&owner.fault==PeriodicStatus::completed;
}
bool PeriodicEffects::healthy()const noexcept{return !shared_->closed&&shared_->fault==PeriodicStatus::completed;}
PeriodicStatus PeriodicEffects::failure()const noexcept{return shared_->fault;}
PeriodicCreated PeriodicEffects::create(const SceneControlId& id)noexcept{
    auto& owner=*shared_;
    if(owner.closed)return{PeriodicStatus::closed};
    if(!admitted())return{PeriodicStatus::emitter_unavailable};
    const auto parent=owner.controls.get(id);if(!parent)return{PeriodicStatus::invalid_control};
    const auto five=std::get_if<ControlTypeFive>(&parent->body);if(!five)return{PeriodicStatus::invalid_control};
    try{
        std::erase_if(owner.entries,[&](const auto& entry){return !owner.tasks.contains(entry.handle);});
        auto state=std::make_shared<PeriodicState>();state->position={five->position[0],five->position[1],five->position[2]};
        auto work=std::make_shared<Work>(shared_,id,state);
        const auto created=owner.tasks.create(work);
        if(created.status==gameplay_tasks::Status::closed){owner.fault=PeriodicStatus::closed;return{PeriodicStatus::closed,created.status,{}};}
        if(created.status==gameplay_tasks::Status::no_memory){owner.fault=PeriodicStatus::no_memory;return{PeriodicStatus::no_memory,created.status,{}};}
        if(created.status!=gameplay_tasks::Status::completed && created.status!=gameplay_tasks::Status::full){
            owner.fault=PeriodicStatus::task_unavailable;return{PeriodicStatus::task_unavailable,created.status,{}};
        }
        if(created.status==gameplay_tasks::Status::completed)owner.entries.push_back({created.handle,std::move(state)});
        return{PeriodicStatus::completed,created.status,created.handle};
    }catch(const std::bad_alloc&){owner.fault=PeriodicStatus::no_memory;return{PeriodicStatus::no_memory,gameplay_tasks::Status::no_memory,{}};}
}
std::optional<PeriodicState> PeriodicEffects::snapshot(const gameplay_tasks::Handle& handle)const noexcept{
    if(!shared_->tasks.contains(handle))return{};
    for(const auto& entry:shared_->entries)if(entry.handle==handle)return *entry.state;
    return{};
}
void PeriodicEffects::close()noexcept{
    auto& owner=*shared_;if(owner.closed)return;owner.closed=true;
    for(const auto& entry:owner.entries)(void)owner.tasks.erase(entry.handle);
    owner.entries.clear();
}
}
