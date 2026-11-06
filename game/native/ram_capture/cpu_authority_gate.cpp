#include "cpu_authority_gate.hpp"
#include <limits>
#include <utility>

namespace reo::native::ram_capture {
CpuGroup::CpuGroup(CpuGroup&& other)noexcept {*this=std::move(other);}
CpuGroup& CpuGroup::operator=(CpuGroup&& other)noexcept {
    if(this!=&other){release();owner_=std::exchange(other.owner_,nullptr);backing_=other.backing_;slot_=other.slot_;generation_=other.generation_;}return *this;
}
CpuGroup::~CpuGroup(){release();}
void CpuGroup::release()noexcept {if(auto* owner=std::exchange(owner_,nullptr))owner->release_cpu(backing_,slot_,generation_);}
GraphicsActivity::GraphicsActivity(GraphicsActivity&& other)noexcept {*this=std::move(other);}
GraphicsActivity& GraphicsActivity::operator=(GraphicsActivity&& other)noexcept {
    if(this!=&other){release();owner_=std::exchange(other.owner_,nullptr);backing_=other.backing_;}return *this;
}
GraphicsActivity::~GraphicsActivity(){release();}
void GraphicsActivity::release()noexcept {if(auto* owner=std::exchange(owner_,nullptr))owner->release_graphics(backing_);}
std::size_t Coordinator::find_or_create(const void* backing)noexcept {
    for(std::size_t i=0;i<entries_.size();++i)if(entries_[i].backing==backing)return i;
    for(std::size_t i=0;i<entries_.size();++i)if(!entries_[i].backing){entries_[i].backing=backing;return i;}
    return entries_.size();
}
Result<CpuGroup> Coordinator::try_cpu_group(const void* backing)noexcept {
    if(!backing)return {Status::invalid_backing,{}};
    std::lock_guard lock(mutex_);auto at=find_or_create(backing);
    if(at==entries_.size())return {Status::capacity,{}};
    auto& entry=entries_[at];
    if(entry.graphics_ever)return {Status::graphics_owned,{}};
    for(std::size_t i=0;i<entry.slots.size();++i){auto& slot=entry.slots[i];
        if(slot.used || slot.generation==std::numeric_limits<std::uint64_t>::max())continue;
        ++slot.generation;slot.thread=std::this_thread::get_id();slot.used=true;++entry.groups;
        CpuGroup result;result.owner_=this;result.backing_=at;result.slot_=i;result.generation_=slot.generation;
        return {Status::ok,std::move(result)};
    }
    return {Status::capacity,{}};
}
Result<GraphicsActivity> Coordinator::begin_graphics(const void* backing) {
    if(!backing)return {Status::invalid_backing,{}};
    std::unique_lock lock(mutex_);auto at=find_or_create(backing);
    if(at==entries_.size())return {Status::capacity,{}};
    auto& entry=entries_[at];
    for(const auto& slot:entry.slots)if(slot.used && slot.thread==std::this_thread::get_id())return {Status::self_wait,{}};
    if(entry.waiting+entry.graphics>=maximum_groups)return {Status::capacity,{}};
    entry.graphics_ever=true;++entry.waiting;
    try {changed_.wait(lock,[&]{return entry.groups==0;});}
    catch(...){--entry.waiting;throw;} // Sticky exclusion survives failed construction.
    --entry.waiting;++entry.graphics;
    GraphicsActivity result;result.owner_=this;result.backing_=at;
    return {Status::ok,std::move(result)};
}
void Coordinator::release_cpu(std::size_t backing,std::size_t slot,std::uint64_t generation)noexcept {
    {std::lock_guard lock(mutex_);auto& entry=entries_[backing];auto& record=entry.slots[slot];
        if(!record.used || record.generation!=generation)std::terminate();
        record.used=false;record.thread={};--entry.groups;}
    changed_.notify_all();
}
void Coordinator::release_graphics(std::size_t backing)noexcept {
    std::lock_guard lock(mutex_);auto& entry=entries_[backing];if(!entry.graphics)std::terminate();--entry.graphics;
}
Observation Coordinator::observe(const void* backing)const noexcept {
    std::lock_guard lock(mutex_);
    for(const auto& entry:entries_)if(backing && entry.backing==backing)return {true,entry.graphics_ever,entry.groups,entry.waiting,entry.graphics};
    return {};
}
Coordinator& process_coordinator()noexcept {static Coordinator coordinator;return coordinator;}
} // namespace reo::native::ram_capture
