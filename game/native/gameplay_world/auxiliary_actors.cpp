#include "auxiliary_actors.hpp"
#include "actor_initial_state.hpp"
#include <new>
#include <exception>
#include <utility>
namespace reo::native::gameplay_world {
AuxiliaryActorPool::AuxiliaryActorPool(World& world)noexcept:world_(world){for(unsigned i=0;i<capacity;++i){free_[i]=std::uint8_t(i);slots_[i].byte_on_reuse=std::uint8_t(i);}}
AuxiliaryActorPool::~AuxiliaryActorPool(){if(mutating_||updating_)std::terminate();(void)close();}
std::optional<std::uint8_t> AuxiliaryActorPool::physical_slot(const actors::EntityId& id)const noexcept{
    if(closed_||world_.closed()||!id)return{};
    for(unsigned i=0;i<capacity;++i)if(slots_[i].id==id)return std::uint8_t(i);
    return{};
}
actors::EntityId AuxiliaryActorPool::head()const noexcept{return !closed_&&!world_.closed()&&head_?slots_[*head_].id:actors::EntityId{};}
actors::EntityId AuxiliaryActorPool::tail()const noexcept{return !closed_&&!world_.closed()&&tail_?slots_[*tail_].id:actors::EntityId{};}
actors::EntityId AuxiliaryActorPool::next(const actors::EntityId& id)const noexcept{const auto index=physical_slot(id);return index&&slots_[*index].next?slots_[*slots_[*index].next].id:actors::EntityId{};}
actors::EntityId AuxiliaryActorPool::previous(const actors::EntityId& id)const noexcept{const auto index=physical_slot(id);return index&&slots_[*index].previous?slots_[*slots_[*index].previous].id:actors::EntityId{};}
actors::EntityId AuxiliaryActorPool::find(std::uint32_t identifier,bool active_only)const noexcept{
    for(auto id=head();id;id=next(id)){const auto actor=world_.resolve(id);if(!actor)return{};if((!active_only||actor->active)&&actor->model_variant==identifier)return id;}return{};
}
AuxiliaryAttachment AuxiliaryActorPool::claim_attachment()noexcept{
    if(closed_)return{AuxiliaryStatus::closed,{}};
    if(mutating_)return{AuxiliaryStatus::busy,{}};
    if(world_.closed())return{AuxiliaryStatus::world_unavailable,{}};
    for(unsigned i=0;i<attachments_.size();++i)if(!attachments_[i]){attachments_[i]=true;return{AuxiliaryStatus::completed,std::uint8_t(i)};}
    return{AuxiliaryStatus::full,{}};
}
AuxiliaryCreated AuxiliaryActorPool::allocate(std::uint32_t at_tail){
    if(closed_)return{AuxiliaryStatus::closed,{}};
    if(mutating_)return{AuxiliaryStatus::busy,{}};
    if(world_.closed())return{AuxiliaryStatus::world_unavailable,{}};
    if(!remaining_)return{AuxiliaryStatus::full,{}};
    std::unique_ptr<Actor> actor;try{actor=std::make_unique<Actor>();}catch(const std::bad_alloc&){return{AuxiliaryStatus::no_memory,{}};}
    const auto index=free_[remaining_-1];initialize_cleared_actor_defaults(*actor);actor->slot=slots_[index].byte_on_reuse;actor->contact.authored_id=index;
    const auto created=world_.spawn_linked(std::move(actor));if(created.status!=actors::EntityStatus::completed)return{created.status==actors::EntityStatus::no_memory?AuxiliaryStatus::no_memory:AuxiliaryStatus::world_unavailable,{}};
    --remaining_;auto& slot=slots_[index];slot.id=created.id;slot.previous.reset();slot.next.reset();
    if(!head_)head_=tail_=index;
    else if(at_tail){slot.previous=tail_;slots_[*tail_].next=index;tail_=index;}
    else{slot.next=head_;slots_[*head_].previous=index;head_=index;}
    return{AuxiliaryStatus::completed,created.id};
}
AuxiliaryStatus AuxiliaryActorPool::release(const actors::EntityId& id)noexcept{
    if(closed_)return AuxiliaryStatus::closed;
    if(mutating_)return AuxiliaryStatus::busy;
    if(world_.closed())return AuxiliaryStatus::world_unavailable;
    const auto index=physical_slot(id);const auto actor=world_.resolve(id);if(!index||!actor)return AuxiliaryStatus::invalid_identity;
    mutating_=true;auto& slot=slots_[*index];
    if(slot.previous)slots_[*slot.previous].next=slot.next;else head_=slot.next;
    if(slot.next)slots_[*slot.next].previous=slot.previous;else tail_=slot.previous;
    slot.byte_on_reuse=actor->slot;slot.id={};slot.previous.reset();slot.next.reset();free_[remaining_++]=*index;
    const auto result=world_.entities_.retire(id);mutating_=false;
    return result==actors::EntityStatus::completed?AuxiliaryStatus::completed:AuxiliaryStatus::invalid_identity;
}
AuxiliaryStatus AuxiliaryActorPool::clear(bool seal)noexcept{
    if(closed_)return seal?AuxiliaryStatus::completed:AuxiliaryStatus::closed;
    if(mutating_||updating_)return AuxiliaryStatus::busy;
    if(world_.closed()&&!seal)return AuxiliaryStatus::world_unavailable;
    mutating_=true;closed_=seal;auto previous=std::move(slots_);slots_={};head_.reset();tail_.reset();remaining_=capacity;attachments_.fill(false);
    for(unsigned i=0;i<capacity;++i){free_[i]=std::uint8_t(i);slots_[i].byte_on_reuse=std::uint8_t(i);}
    for(const auto& slot:previous)if(slot.id)(void)world_.entities_.retire(slot.id);
    mutating_=false;return AuxiliaryStatus::completed;
}
AuxiliaryStatus AuxiliaryActorPool::reset()noexcept{return clear(false);}
AuxiliaryStatus AuxiliaryActorPool::close()noexcept{return clear(true);}
}
