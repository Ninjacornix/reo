#include "scene_primary_actors.hpp"
#include "actor_initial_state.hpp"
#include "../animation/playback.hpp"
#include <exception>
#include <new>
namespace reo::native::gameplay_world {
ScenePrimaryActorPool::~ScenePrimaryActorPool(){if(mutating_)std::terminate();(void)close();}
actors::EntityId ScenePrimaryActorPool::identity_at(std::size_t slot)const noexcept{
    return initialized()&&slot<capacity?slots_[slot]:actors::EntityId{};
}
std::optional<std::uint8_t> ScenePrimaryActorPool::physical_slot(const actors::EntityId& id)const noexcept{
    if(!initialized()||!id||!world_.resolve(id))return{};
    for(unsigned slot=0;slot<capacity;++slot)if(slots_[slot]==id)return std::uint8_t(slot);
    return{};
}
ScenePrimaryStatus ScenePrimaryActorPool::initialize()noexcept{
    if(closed_||world_.closed())return ScenePrimaryStatus::closed;
    if(mutating_||world_.busy())return ScenePrimaryStatus::busy;
    std::array<std::shared_ptr<Actor>,capacity> old;
    for(unsigned slot=0;slot<capacity;++slot){
        if(!slots_[slot])continue;
        old[slot]=world_.resolve(slots_[slot]);
        if(!old[slot])return ScenePrimaryStatus::invalid_identity;
        if(old[slot]->model||(old[slot]->animation&&old[slot]->animation->model()))return ScenePrimaryStatus::model_in_use;
    }
    mutating_=world_.updating_=true;
    struct Reset{bool& busy;bool& world;~Reset(){world=false;busy=false;}}reset{mutating_,world_.updating_};
    // Keep old Actor destructors under the guard and after complete publication.
    const auto previous=std::move(old);(void)previous;
    std::array<actors::EntityId,capacity> next{};
    const auto rollback=[&](){for(const auto& id:next)if(id)(void)world_.entities_.retire(id);};
    try{
        for(unsigned slot=0;slot<capacity;++slot){
            auto actor=std::make_unique<Actor>();initialize_cleared_actor_defaults(*actor);actor->slot=std::uint8_t(slot);
            const auto created=world_.entities_.create(std::move(actor));
            if(created.status!=actors::EntityStatus::completed){rollback();return created.status==actors::EntityStatus::no_memory?ScenePrimaryStatus::no_memory:ScenePrimaryStatus::entity_capacity;}
            next[slot]=created.id;
        }
        slots_.swap(next);initialized_=true;
        for(const auto& id:next)if(id)(void)world_.entities_.retire(id);
        return ScenePrimaryStatus::completed;
    }catch(const std::bad_alloc&){rollback();return ScenePrimaryStatus::no_memory;}catch(...){rollback();return ScenePrimaryStatus::invalid_identity;}
}
ScenePrimaryFound ScenePrimaryActorPool::find_inactive()noexcept{
    if(closed_||world_.closed())return{ScenePrimaryStatus::closed};
    if(mutating_||world_.busy())return{ScenePrimaryStatus::busy};
    if(!initialized_)return{};
    mutating_=world_.updating_=true;
    struct Reset{bool& busy;bool& world;~Reset(){world=false;busy=false;}}reset{mutating_,world_.updating_};
    for(unsigned slot=0;slot<capacity;++slot){
        const auto actor=world_.resolve(slots_[slot]);if(!actor)return{ScenePrimaryStatus::invalid_identity};
        if(actor->active)continue;
        actor->slot=std::uint8_t(slot);return{ScenePrimaryStatus::completed,std::uint8_t(slot),slots_[slot]};
    }
    return{ScenePrimaryStatus::full};
}
ScenePrimaryStatus ScenePrimaryActorPool::close()noexcept{
    if(closed_)return ScenePrimaryStatus::completed;
    if(mutating_||world_.updating_)return ScenePrimaryStatus::busy;
    if(!world_.closed()&&world_.busy())return ScenePrimaryStatus::busy;
    if(!world_.closed())for(const auto& id:slots_){const auto actor=world_.resolve(id);if(actor&&(actor->model||(actor->animation&&actor->animation->model())))return ScenePrimaryStatus::model_in_use;}
    mutating_=world_.updating_=true;
    struct Reset{bool& busy;bool& world;~Reset(){world=false;busy=false;}}reset{mutating_,world_.updating_};
    std::array<std::shared_ptr<actors::Entity>,capacity> retained;
    for(unsigned slot=0;slot<capacity;++slot)retained[slot]=world_.entities_.acquire(slots_[slot]);
    const auto previous=std::move(slots_);slots_.fill({});closed_=true;initialized_=false;
    for(const auto& id:previous)if(id)(void)world_.entities_.retire(id);
    return ScenePrimaryStatus::completed;
}
}
