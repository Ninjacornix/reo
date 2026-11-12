#include "transient_lights.hpp"
#include "../gameplay_update/update.hpp"
#include <algorithm>
#include <cmath>
#include <exception>
#include <stdexcept>
namespace reo::native::gameplay_lighting {
struct TransientLights::Shared {
    gameplay_update::Owner& update;gameplay_scenario::Lighting& lights;
    struct Entry {gameplay_tasks::Handle handle;std::weak_ptr<Work> work;};
    std::vector<Entry> entries;bool closed{};TransientStatus fault{TransientStatus::completed};
    Shared(gameplay_update::Owner& owner,gameplay_scenario::Lighting& lighting):update(owner),lights(lighting){entries.reserve(gameplay_tasks::Scheduler::capacity);}
};
class TransientLights::Work final:public gameplay_tasks::Task {
    std::shared_ptr<Shared> owner_;
public:
    TransientState state;
    gameplay_scenario::LightHandle primary;
    gameplay_scenario::AuxiliaryLightHandle auxiliary;
    explicit Work(std::shared_ptr<Shared> owner):owner_(std::move(owner)){}
    ~Work()override{if(primary)(void)owner_->lights.release(primary);if(auxiliary)(void)owner_->lights.release(auxiliary);}
    void update(gameplay_tasks::Scheduler& tasks,const gameplay_tasks::Handle& handle)noexcept override{
        auto& owner=*owner_;
        if(owner.closed){(void)tasks.erase(handle);return;}
        try{
            auto first=primary?owner.lights.light(primary):std::nullopt;
            auto second=auxiliary?owner.lights.light(auxiliary):std::nullopt;
            if((primary&&!first)||(auxiliary&&!second)){
                owner.fault=TransientStatus::unavailable;(void)tasks.erase(handle);return;
            }
            const auto result=advance_transient_light(state,{bool(primary),bool(auxiliary)});
            if(result.retire){(void)tasks.erase(handle);return;}
            if(result.release[0]){if(!owner.lights.release(primary))owner.fault=TransientStatus::unavailable;primary={};}
            else if(result.attenuation[0]){first->descriptor.attenuation=*result.attenuation[0];if(!owner.lights.replace(primary,first->descriptor))owner.fault=TransientStatus::unavailable;}
            if(result.release[1]){if(!owner.lights.release(auxiliary))owner.fault=TransientStatus::unavailable;auxiliary={};}
            else if(result.attenuation[1]){second->descriptor.attenuation=*result.attenuation[1];if(!owner.lights.replace(auxiliary,second->descriptor))owner.fault=TransientStatus::unavailable;}
            if(owner.fault!=TransientStatus::completed)(void)tasks.erase(handle);
        }catch(...){owner.fault=TransientStatus::unavailable;(void)tasks.erase(handle);}
    }
    std::array<std::optional<Light>,2> snapshot()const noexcept{
        return{primary?owner_->lights.light(primary):std::nullopt,auxiliary?owner_->lights.light(auxiliary):std::nullopt};
    }
};
TransientLights::TransientLights(gameplay_update::Owner& owner,gameplay_scenario::Lighting& lights):shared_(std::make_shared<Shared>(owner,lights)){
    if(!owner.open())throw std::invalid_argument("Native transient lights require an open canonical Update owner");
}
TransientLights::~TransientLights(){if(close()==TransientStatus::busy)std::terminate();}
bool TransientLights::bound_to(const gameplay_update::Owner& owner,const gameplay_scenario::Lighting& lights)const noexcept{
    return !shared_->closed&&&shared_->update==&owner&&&shared_->lights==&lights&&shared_->update.open();
}
TransientCreated TransientLights::create(const gameplay_actors::EntityId& id,const std::array<float,3>& position)noexcept{
    auto& owner=*shared_;if(owner.closed||!owner.update.open())return{TransientStatus::closed,{},{}};
    if(owner.fault!=TransientStatus::completed)return{owner.fault,{},{}};
    const auto actor=owner.update.world().resolve(id);if(!actor)return{};
    if(!std::all_of(position.begin(),position.end(),[](float value){return std::isfinite(value);}))return{};
    try{
        auto& tasks=owner.update.linked();
        std::erase_if(owner.entries,[&](const auto& entry){return !tasks.contains(entry.handle);});
        const auto work=std::make_shared<Work>(shared_);const auto task=tasks.create(work);
        if(task.status!=gameplay_tasks::Status::completed)return{task.status==gameplay_tasks::Status::full?TransientStatus::task_full:task.status==gameplay_tasks::Status::no_memory?TransientStatus::no_memory:TransientStatus::unavailable,{},{}};
        const auto definition=transient_definition(position);
        const auto primary=owner.lights.allocate(&definition,actor->surface_material,0);
        if(primary){const auto handle=owner.lights.handle(*primary);if(!handle){(void)tasks.erase(task.handle);return{};}work->primary=*handle;}
        const auto auxiliary=owner.lights.allocate_auxiliary(&definition,actor->surface_material);
        if(auxiliary)work->auxiliary=*auxiliary;
        owner.entries.push_back({task.handle,work});
        return{TransientStatus::completed,task.handle,{bool(work->primary),bool(work->auxiliary)}};
    }catch(const std::bad_alloc&){return{TransientStatus::no_memory,{},{}};}
}
std::optional<TransientSnapshot> TransientLights::snapshot(const gameplay_tasks::Handle& handle)const noexcept{
    const auto& owner=*shared_;if(owner.closed||!owner.update.linked().contains(handle))return{};
    for(const auto& entry:owner.entries)if(entry.handle==handle){const auto work=entry.work.lock();if(work)return TransientSnapshot{work->state,work->snapshot()};}
    return{};
}
TransientStatus TransientLights::failure()const noexcept{return shared_->fault;}
TransientStatus TransientLights::close()noexcept{
    auto& owner=*shared_;if(owner.closed)return TransientStatus::completed;
    auto& tasks=owner.update.linked();if(!tasks.idle())return TransientStatus::busy;
    owner.closed=true;for(const auto& entry:owner.entries)(void)tasks.erase(entry.handle);
    owner.entries.clear();return TransientStatus::completed;
}
}
