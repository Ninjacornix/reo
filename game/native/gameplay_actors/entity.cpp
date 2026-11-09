#include "entity.hpp"
#include <stdexcept>
#include <utility>

namespace reo::native::gameplay_actors {
struct EntityDomain {};
EntityStore::EntityStore(EntityConfig config):domain_(std::make_shared<EntityDomain>()),
    slots_(config.capacity),maximum_generation_(config.max_generation){
    if(!config.capacity || !config.max_generation)throw std::invalid_argument("Invalid native entity capacity/generation domain");
}
EntityStore::~EntityStore(){shutdown();}
bool EntityStore::matches(const EntityId& id)const noexcept{
    return id.domain_==domain_ && id.slot_<slots_.size() && id.generation_!=0 &&
        slots_[id.slot_].generation==id.generation_ && bool(slots_[id.slot_].entity);
}
EntityCreated EntityStore::create(std::unique_ptr<Entity> entity)noexcept{
    if(closed_)return{EntityStatus::closed,{}};
    if(!entity)return{EntityStatus::invalid,{}};
    for(std::size_t i=0;i<slots_.size();++i){
        auto& slot=slots_[i];if(slot.entity || slot.generation==maximum_generation_)continue;
        try{
            std::shared_ptr<Entity> owned(std::move(entity));
            EntityId id;id.domain_=domain_;id.slot_=std::uint32_t(i);id.generation_=slot.generation+1;
            slot.entity=std::move(owned);slot.generation=id.generation_;++size_;
            return{EntityStatus::completed,std::move(id)};
        }catch(...){return{EntityStatus::no_memory,{}};}
    }
    return{EntityStatus::full,{}};
}
std::shared_ptr<Entity> EntityStore::acquire(const EntityId& id)const noexcept{
    if(closed_ || !matches(id))return{};
    return slots_[id.slot_].entity;
}
EntityStatus EntityStore::retire(const EntityId& id)noexcept{
    if(closed_)return EntityStatus::closed;
    if(!matches(id))return EntityStatus::foreign_or_stale;
    // Unpublish before destruction: a destructor can consult or mutate this
    // store without seeing itself still registered or a stale size counter.
    auto old=std::move(slots_[id.slot_].entity);--size_;old.reset();
    return EntityStatus::completed;
}
std::vector<EntityId> EntityStore::identities()const{
    std::vector<EntityId> result;if(closed_)return result;result.reserve(size_);
    for(std::size_t i=0;i<slots_.size();++i)if(slots_[i].entity){
        EntityId id;id.domain_=domain_;id.slot_=std::uint32_t(i);id.generation_=slots_[i].generation;result.push_back(std::move(id));
    }
    return result;
}
void EntityStore::shutdown()noexcept{
    if(closed_)return;
    closed_=true;size_=0;
    for(auto& slot:slots_)slot.entity.reset();
}
} // namespace reo::native::gameplay_actors
