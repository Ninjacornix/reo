#include "cpu_authority_gate.hpp"
#include <limits>
#include <utility>

namespace reo::native::ram_capture::v2 {
CpuGroup::CpuGroup(CpuGroup&& x)noexcept{*this=std::move(x);}
CpuGroup& CpuGroup::operator=(CpuGroup&& x)noexcept{if(this!=&x){release();owner_=std::exchange(x.owner_,nullptr);backing_=x.backing_;slot_=x.slot_;generation_=x.generation_;}return *this;}
CpuGroup::~CpuGroup(){release();}
void CpuGroup::release()noexcept{if(auto* p=std::exchange(owner_,nullptr))p->release_cpu(backing_,slot_,generation_);}
CpuWriter::CpuWriter(CpuWriter&& x)noexcept{*this=std::move(x);}
CpuWriter& CpuWriter::operator=(CpuWriter&& x)noexcept{if(this!=&x){release();owner_=std::exchange(x.owner_,nullptr);backing_=x.backing_;slot_=x.slot_;generation_=x.generation_;}return *this;}
CpuWriter::~CpuWriter(){release();}
void CpuWriter::release()noexcept{if(auto* p=std::exchange(owner_,nullptr))p->release_writer(backing_,slot_,generation_);}
GraphicsActivity::GraphicsActivity(GraphicsActivity&& x)noexcept{*this=std::move(x);}
GraphicsActivity& GraphicsActivity::operator=(GraphicsActivity&& x)noexcept{if(this!=&x){release();owner_=std::exchange(x.owner_,nullptr);backing_=x.backing_;}return *this;}
GraphicsActivity::~GraphicsActivity(){release();}
void GraphicsActivity::release()noexcept{if(auto* p=std::exchange(owner_,nullptr))p->release_graphics(backing_);}
std::size_t Coordinator::find_or_create(const void* backing)noexcept{
    for(std::size_t i=0;i<entries_.size();++i)if(entries_[i].backing==backing)return i;
    for(std::size_t i=0;i<entries_.size();++i)if(!entries_[i].backing){entries_[i].backing=backing;return i;}return entries_.size();
}
Result<CpuGroup> Coordinator::try_cpu_group(const void* backing)noexcept{
    if(!backing)return {Status::invalid_backing,{}};std::lock_guard lock(mutex_);if(cpu_capture_disabled_)return {Status::unavailable,{}};const auto at=find_or_create(backing);
    if(at==entries_.size())return {Status::capacity,{}};auto& e=entries_[at];
    if(e.graphics_ever)return {Status::graphics_owned,{}};
    if(e.writers_waiting||e.writers_active)return {Status::writer_busy,{}};
    for(std::size_t i=0;i<e.readers.size();++i){auto& s=e.readers[i];if(s.used||s.generation==std::numeric_limits<std::uint64_t>::max())continue;
        ++s.generation;s.thread=std::this_thread::get_id();s.used=true;++e.groups;
        CpuGroup result;result.owner_=this;result.backing_=at;result.slot_=i;result.generation_=s.generation;return {Status::ok,std::move(result)};}
    return {Status::capacity,{}};
}
Result<CpuWriter> Coordinator::begin_cpu_writer(const void* backing){
    if(!backing)return {Status::invalid_backing,{}};std::unique_lock lock(mutex_);const auto at=find_or_create(backing);
    if(at==entries_.size())return {Status::capacity,{}};auto& e=entries_[at];const auto thread=std::this_thread::get_id();
    for(const auto& s:e.readers)if(s.used&&s.thread==thread)return {Status::self_wait,{}};
    for(const auto& s:e.writers)if(s.used&&s.thread==thread)return {Status::self_wait,{}};
    if(e.next_ticket==std::numeric_limits<std::uint64_t>::max())return {Status::capacity,{}};
    std::size_t slot=0;for(;slot<e.writers.size();++slot)if(!e.writers[slot].used&&e.writers[slot].generation!=std::numeric_limits<std::uint64_t>::max())break;
    if(slot==e.writers.size())return {Status::capacity,{}};auto& s=e.writers[slot];
    ++s.generation;s.ticket=e.next_ticket++;s.thread=thread;s.used=s.waiting=true;++e.writers_waiting;
    try{changed_.wait(lock,[&]{
        if(e.groups||e.writers_active)return false;
        for(const auto& r:e.readers)if(r.used&&r.waiting&&r.ticket<s.ticket)return false;
        for(const auto& w:e.writers)if(w.used&&w.waiting&&w.ticket<s.ticket)return false;
        return true;
    });}
    catch(...){--e.writers_waiting;s.used=s.waiting=false;s.thread={};lock.unlock();changed_.notify_all();throw;}
    --e.writers_waiting;s.waiting=false;++e.writers_active;
    CpuWriter result;result.owner_=this;result.backing_=at;result.slot_=slot;result.generation_=s.generation;return {Status::ok,std::move(result)};
}
Result<CpuGroup> Coordinator::wait_cpu_group(const void* backing){
    if(!backing)return {Status::invalid_backing,{}};std::unique_lock lock(mutex_);
    if(cpu_capture_disabled_)return {Status::unavailable,{}};const auto at=find_or_create(backing);
    if(at==entries_.size())return {Status::capacity,{}};auto& e=entries_[at];
    if(e.graphics_ever)return {Status::graphics_owned,{}};const auto thread=std::this_thread::get_id();
    for(const auto& s:e.readers)if(s.used&&s.thread==thread)return {Status::self_wait,{}};
    for(const auto& s:e.writers)if(s.used&&s.thread==thread)return {Status::self_wait,{}};
    if(e.next_ticket==std::numeric_limits<std::uint64_t>::max())return {Status::capacity,{}};
    std::size_t slot=0;for(;slot<e.readers.size();++slot)if(!e.readers[slot].used&&e.readers[slot].generation!=std::numeric_limits<std::uint64_t>::max())break;
    if(slot==e.readers.size())return {Status::capacity,{}};auto& s=e.readers[slot];
    ++s.generation;s.ticket=e.next_ticket++;s.thread=thread;s.used=s.waiting=true;++e.readers_waiting;
    const auto abandon=[&]{--e.readers_waiting;s.used=s.waiting=false;s.thread={};lock.unlock();changed_.notify_all();};
    try{changed_.wait(lock,[&]{
        if(cpu_capture_disabled_||e.graphics_ever)return true;
        if(e.writers_active)return false;
        for(const auto& w:e.writers)if(w.used&&w.waiting&&w.ticket<s.ticket)return false;
        return true;
    });}
    catch(...){abandon();throw;}
    if(cpu_capture_disabled_||e.graphics_ever){const auto status=cpu_capture_disabled_?Status::unavailable:Status::graphics_owned;abandon();return {status,{}};}
    --e.readers_waiting;s.waiting=false;++e.groups;
    CpuGroup result;result.owner_=this;result.backing_=at;result.slot_=slot;result.generation_=s.generation;return {Status::ok,std::move(result)};
}
Result<GraphicsActivity> Coordinator::begin_graphics(const void* backing){
    if(!backing)return {Status::invalid_backing,{}};std::unique_lock lock(mutex_);const auto at=find_or_create(backing);
    if(at==entries_.size())return {Status::capacity,{}};auto& e=entries_[at];const auto thread=std::this_thread::get_id();
    for(const auto& s:e.readers)if(s.used&&s.thread==thread)return {Status::self_wait,{}};
    for(const auto& s:e.writers)if(s.used&&s.thread==thread)return {Status::self_wait,{}};
    if(e.graphics_waiting+e.graphics_active>=maximum_groups)return {Status::capacity,{}};
    e.graphics_ever=true;++e.graphics_waiting;changed_.notify_all();
    try{changed_.wait(lock,[&]{return !e.groups&&!e.writers_waiting&&!e.writers_active;});}
    catch(...){--e.graphics_waiting;throw;}
    --e.graphics_waiting;++e.graphics_active;GraphicsActivity result;result.owner_=this;result.backing_=at;return {Status::ok,std::move(result)};
}
Status Coordinator::withdraw_cpu_capture(){
    std::unique_lock lock(mutex_);const auto thread=std::this_thread::get_id();
    for(const auto& e:entries_)for(const auto& s:e.readers)if(s.used&&s.thread==thread)return Status::self_wait;
    cpu_capture_disabled_=true;changed_.notify_all();
    changed_.wait(lock,[&]{for(const auto& e:entries_)if(e.groups)return false;return true;});return Status::ok;
}
void Coordinator::release_cpu(std::size_t at,std::size_t slot,std::uint64_t generation)noexcept{
    {std::lock_guard lock(mutex_);auto& e=entries_[at];auto& s=e.readers[slot];if(!s.used||s.waiting||s.generation!=generation||s.thread!=std::this_thread::get_id())std::terminate();s.used=false;s.thread={};--e.groups;}changed_.notify_all();
}
void Coordinator::release_writer(std::size_t at,std::size_t slot,std::uint64_t generation)noexcept{
    {std::lock_guard lock(mutex_);auto& e=entries_[at];auto& s=e.writers[slot];if(!s.used||s.waiting||s.generation!=generation||s.thread!=std::this_thread::get_id()||e.writers_active!=1)std::terminate();s.used=false;s.thread={};--e.writers_active;}changed_.notify_all();
}
void Coordinator::release_graphics(std::size_t at)noexcept{std::lock_guard lock(mutex_);auto& e=entries_[at];if(!e.graphics_active)std::terminate();--e.graphics_active;}
Observation Coordinator::observe(const void* backing)const noexcept{
    std::lock_guard lock(mutex_);for(const auto& e:entries_)if(backing&&e.backing==backing)return {true,e.graphics_ever,e.groups,e.graphics_waiting,e.graphics_active,e.writers_waiting,e.writers_active,cpu_capture_disabled_,e.readers_waiting};Observation result;result.cpu_capture_disabled=cpu_capture_disabled_;return result;
}
Coordinator& process_coordinator()noexcept{static Coordinator value;return value;}
} // namespace reo::native::ram_capture::v2
