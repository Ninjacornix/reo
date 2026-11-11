#include "material_animation.hpp"
#include "../gameplay_world/linked_models.hpp"
#include <algorithm>
#include <new>
#include <vector>

namespace reo::native::gameplay_update {
namespace tasks=gameplay_tasks;
namespace world=gameplay_world;
struct MaterialAnimations::Shared {
    world::World& world;tasks::Scheduler& tasks;
    struct Entry {tasks::Handle handle;std::shared_ptr<world::MaterialAnimationState> state;};
    std::vector<Entry> entries;
    bool closed{};
    Shared(world::World& w,tasks::Scheduler& t):world(w),tasks(t){entries.reserve(tasks::Scheduler::capacity);}
};
class MaterialAnimations::Work final:public tasks::Task {
    std::shared_ptr<Shared> owner_;
    world::actors::EntityId actor_;
    std::shared_ptr<world::MaterialAnimationState> state_;
public:
    Work(std::shared_ptr<Shared> owner,world::actors::EntityId actor,std::shared_ptr<world::MaterialAnimationState> state):
        owner_(std::move(owner)),actor_(std::move(actor)),state_(std::move(state)){}
    void update(tasks::Scheduler& tasks,const tasks::Handle& handle)noexcept override {
        if(owner_->closed||owner_->world.closed()){(void)tasks.erase(handle);return;}
        const auto actor=owner_->world.linked_models().physical_slot(actor_)?owner_->world.resolve(actor_):nullptr;
        if(!actor||!actor->material_uv){(void)tasks.erase(handle);return;}
        const bool initializing=state_->phase==0;
        world::advance_material_uv(*state_,*actor->material_uv);
        if(initializing){
            if(auto policy=tasks.policy(handle)){
                policy->presentation_mask=state_->presentation_mask;
                (void)tasks.policy(handle,*policy);
            }
        }
    }
};
MaterialAnimations::MaterialAnimations(world::World& world,tasks::Scheduler& tasks):shared_(std::make_shared<Shared>(world,tasks)){}
MaterialAnimations::~MaterialAnimations(){close();}
bool MaterialAnimations::bound_to(const world::World& world)const noexcept {
    return &shared_->world==&world&&!shared_->closed&&!world.closed()&&!shared_->tasks.closed();
}
tasks::Created MaterialAnimations::create(const world::actors::EntityId& id)noexcept {
    auto& owner=*shared_;
    if(owner.closed||owner.world.closed()||owner.tasks.closed())return{tasks::Status::closed,{}};
    try {
        const auto actor=owner.world.linked_models().physical_slot(id)?owner.world.resolve(id):nullptr;
        if(!actor||!actor->material_uv)return{tasks::Status::invalid,{}};
        std::erase_if(owner.entries,[&](const auto& entry){return !owner.tasks.contains(entry.handle);});
        auto state=std::make_shared<world::MaterialAnimationState>();
        const auto created=owner.tasks.create(std::make_shared<Work>(shared_,id,state));
        // Capacity was reserved before publication, so recording a successful
        // task cannot allocate or leave an untracked work item on failure.
        if(created.status==tasks::Status::completed)owner.entries.push_back({created.handle,std::move(state)});
        return created;
    }catch(const std::bad_alloc&){return{tasks::Status::no_memory,{}};}
}
std::optional<world::MaterialAnimationState> MaterialAnimations::snapshot(const tasks::Handle& handle)const noexcept {
    if(!shared_->tasks.contains(handle))return{};
    for(const auto& entry:shared_->entries)if(entry.handle==handle)return *entry.state;
    return{};
}
void MaterialAnimations::close()noexcept {
    auto& owner=*shared_;if(owner.closed)return;owner.closed=true;
    for(const auto& entry:owner.entries)(void)owner.tasks.erase(entry.handle);
    owner.entries.clear();
}
}
