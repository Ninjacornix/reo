#include "pose_work_pool.hpp"
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_world {
PoseWorkPool::PoseWorkPool(World& world):world_(world){
    if(world_.closed()||world_.busy()||world_.pose_work_owner_)throw std::invalid_argument("Native pose work requires an unbound idle World");
    for(unsigned i=0;i<capacity;++i)free_[i]=std::uint8_t(i);
    world_.pose_work_owner_=this;
}
PoseWorkPool::~PoseWorkPool(){
    if(busy_||world_.busy())std::terminate();
    (void)close();
    if(world_.pose_work_owner_==this)world_.pose_work_owner_=nullptr;
}
bool PoseWorkPool::bound_to(const World& world)const noexcept{return !closed_&&!world_.closed()&&&world==&world_&&world_.pose_work_owner_==this;}
std::optional<std::uint8_t> PoseWorkPool::physical_slot(const actors::EntityId& id)const noexcept{
    if(!id)return{};
    for(unsigned i=0;i<capacity;++i)if(slots_[i].id==id&&world_.resolve(id))return std::uint8_t(i);
    return{};
}
std::shared_ptr<Actor> PoseWorkPool::resolve(const actors::EntityId& id)const noexcept{return bound_to(world_)&&physical_slot(id)?world_.resolve(id):nullptr;}
actors::EntityId PoseWorkPool::head()const noexcept{return bound_to(world_)&&head_?slots_[*head_].id:actors::EntityId{};}
actors::EntityId PoseWorkPool::tail()const noexcept{return bound_to(world_)&&tail_?slots_[*tail_].id:actors::EntityId{};}
PoseWorkCreated PoseWorkPool::allocate(bool prepend)noexcept{
    if(!bound_to(world_))return{PoseWorkStatus::closed,{}};
    if(resetting_)return{PoseWorkStatus::busy,{}};
    if(world_.busy()&&!busy_)return{PoseWorkStatus::busy,{}};
    if(!remaining_)return{PoseWorkStatus::full,{}};
    try{
        auto actor=std::make_unique<Actor>();actor->pose_work.emplace();
        // Complete581FE0 clears only its1F0 record. Do not grant ordinary
        // large-record capabilities such as the BAC gauge or aim metadata.
        actor->model_scale={};actor->surface_kind=actor->surface_material=0;actor->surface_normal={};
        actor->collision.basis.x={};actor->collision.basis.y={};actor->collision.basis.z={};actor->collision.basis.translation={};
        actor->contact.recipient={0,0};actor->contact.related_recipient={0,0};actor->contact.source_related={0,0};
        const auto physical=free_[remaining_-1];actor->contact.authored_id=physical;
        const auto created=world_.entities_.create(std::move(actor));
        if(created.status!=actors::EntityStatus::completed)return{created.status==actors::EntityStatus::no_memory?PoseWorkStatus::no_memory:PoseWorkStatus::unavailable,{}};
        --remaining_;auto& slot=slots_[physical];slot={created.id,{},{}};
        if(!head_)head_=tail_=physical;
        else if(prepend){slot.next=head_;slots_[*head_].previous=physical;head_=physical;}
        else{slot.previous=tail_;slots_[*tail_].next=physical;tail_=physical;}
        return{PoseWorkStatus::completed,created.id};
    }catch(const std::bad_alloc&){return{PoseWorkStatus::no_memory,{}};}
}
PoseWorkStatus PoseWorkPool::retire_impl(const actors::EntityId& id,bool clear_visible)noexcept{
    const auto retired_id=id;
    const auto physical=physical_slot(id);if(!physical)return PoseWorkStatus::invalid_identity;
    auto& slot=slots_[*physical];const auto actor=world_.resolve(id);if(!actor)return PoseWorkStatus::invalid_identity;
    actor->active=false;if(clear_visible)actor->visible=false;
    if(slot.previous)slots_[*slot.previous].next=slot.next;else head_=slot.next;
    if(slot.next)slots_[*slot.next].previous=slot.previous;else tail_=slot.previous;
    free_[remaining_++]=*physical;slot.id={};
    // Preserve physical link payload for source continuation after callback
    // retirement/reallocation; a retained actor ID itself never retargets.
    return world_.entities_.retire(retired_id)==actors::EntityStatus::completed?PoseWorkStatus::completed:PoseWorkStatus::invalid_identity;
}
PoseWorkStatus PoseWorkPool::retire(const actors::EntityId& id,bool clear_visible)noexcept{
    if(!bound_to(world_))return PoseWorkStatus::closed;
    if(resetting_)return PoseWorkStatus::busy;
    if(world_.busy()&&!busy_)return PoseWorkStatus::busy;
    return retire_impl(id,clear_visible);
}
PoseWorkStatus PoseWorkPool::clear(bool closing)noexcept{
    if(closed_)return PoseWorkStatus::closed;
    if(busy_||resetting_||world_.busy())return PoseWorkStatus::busy;
    resetting_=world_.updating_=true;
    struct Guard{bool& a;bool& b;~Guard(){a=false;b=false;}}guard{resetting_,world_.updating_};
    if(world_.closed()){
        for(auto& slot:slots_)slot.id={};
        head_.reset();tail_.reset();remaining_=capacity;
    }else while(head_){const auto status=retire_impl(slots_[*head_].id,true);if(status!=PoseWorkStatus::completed)return status;}
    slots_={};head_.reset();tail_.reset();remaining_=capacity;
    for(unsigned i=0;i<capacity;++i)free_[i]=std::uint8_t(i);
    if(closing){closed_=true;if(world_.pose_work_owner_==this)world_.pose_work_owner_=nullptr;}
    return PoseWorkStatus::completed;
}
PoseWorkStatus PoseWorkPool::reset()noexcept{return clear(false);}
PoseWorkStatus PoseWorkPool::close()noexcept{return clear(true);}
PoseWorkPass PoseWorkPool::update(PoseWorkUpdates* updates,std::size_t budget){
    PoseWorkPass report;if(!bound_to(world_)){report.status=PoseWorkStatus::closed;return report;}
    if(busy_||resetting_||world_.busy()){report.status=PoseWorkStatus::busy;return report;}
    if(updates&&!updates->bound_to(world_)){report.status=PoseWorkStatus::unavailable;return report;}
    busy_=world_.updating_=true;struct Guard{bool& a;bool& b;~Guard(){a=false;b=false;}}guard{busy_,world_.updating_};
    auto cursor=tail_;
    while(cursor){
        if(report.called==budget){report.status=PoseWorkStatus::budget_exhausted;return report;}
        const auto physical=*cursor;const auto id=slots_[physical].id;const auto actor=resolve(id);
        if(!actor||!actor->pose_work){report.status=PoseWorkStatus::invalid_identity;return report;}
        auto& state=*actor->pose_work;if(!state.update_bound){report.status=PoseWorkStatus::unavailable;return report;}
        ++report.called;const auto step=gameplay_effects::advance_pose_lifetime(state.lifetime,state.kind);
        if(step.retire){const auto status=retire_impl(id,true);if(status!=PoseWorkStatus::completed){report.status=status;return report;}++report.retired;}
        else if(step.update){
            if(*step.update==0){if(actor->primary==0){actor->primary=1;actor->visible=true;}}
            else if(!updates||!updates->update(*this,id,*step.update)){report.status=PoseWorkStatus::unavailable;return report;}
        }
        // The original loads previous after the callback, including a new
        // occupant's continuation when that physical slot was reused.
        cursor=slots_[physical].previous;
    }
    return report;
}
}
