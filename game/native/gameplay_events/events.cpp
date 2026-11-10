#include "events.hpp"
#include <algorithm>
#include <bit>
namespace reo::native::gameplay_events {
struct Domain {};
namespace {
constexpr std::array<std::int8_t,39> priorities{
#include "event_priority_profile.inc"
};
constexpr std::uint32_t timestamp_limit=0xa4c478;
}
Events::Events(std::uint64_t limit):domain_(std::make_shared<Domain>()),max_serial_(limit){(void)reset();}
Status Events::reset()noexcept{
    if(closed_)return Status::closed;
    slots_={};for(unsigned i=0;i<free_.size();++i)free_[i]=std::uint8_t(i);free_count_=128;head_.reset();tail_.reset();threshold_=0;return Status::completed;
}
void Events::close()noexcept{if(closed_)return;(void)reset();closed_=true;}
EventId Events::identity(std::uint8_t slot)const noexcept{EventId result;result.domain_=domain_;result.serial_=slots_[slot].serial;result.slot_=slot;return result;}
std::optional<std::uint8_t> Events::physical_slot(const EventId& id)const noexcept{
    if(closed_||id.domain_!=domain_||id.slot_>=slots_.size())return{};
    const auto& node=slots_[id.slot_];if(!node.active||node.serial!=id.serial_)return{};
    return id.slot_;
}
std::optional<Event> Events::get(const EventId& id)const noexcept{const auto slot=physical_slot(id);return slot?std::optional<Event>(slots_[*slot].value):std::nullopt;}
Created Events::allocate(Event value)noexcept{
    if(!free_count_)return{Status::full,{}};
    if(serial_==max_serial_)return{Status::serial_exhausted,{}};
    const auto slot=free_[--free_count_];auto& node=slots_[slot];node={};node.value=value;node.active=true;node.serial=++serial_;node.previous=tail_;
    if(tail_)slots_[*tail_].next=slot;else head_=slot;tail_=slot;return{Status::completed,identity(slot)};
}
bool Events::retire(const EventId& id)noexcept{
    const auto slot=physical_slot(id);if(!slot)return false;auto& node=slots_[*slot];free_[free_count_++]=*slot;
    if(node.previous)slots_[*node.previous].next=node.next;else head_=node.next;
    if(node.next)slots_[*node.next].previous=node.previous;else tail_=node.previous;
    node.active=false;return true;
}
bool Events::prune()noexcept{
    if(closed_||threshold_>=9||free_count_==128)return false;
    for(auto current=head_;current;){auto& node=slots_[*current];const auto next=node.next;if(std::int32_t(node.value.priority)<=std::int32_t(threshold_))(void)retire(identity(*current));current=next;}
    threshold_=std::bit_cast<std::int8_t>(std::uint8_t(std::uint8_t(threshold_)+1u));return true;
}
Created Events::simple(std::uint32_t event,std::uint32_t counter){
    if(closed_)return{Status::closed,{}};
    while(!free_count_){if(!prune())return{Status::full,{}};}
    Event value;value.timestamp=std::min(counter,timestamp_limit);value.id=std::uint16_t(event);value.type=1;value.priority=9;return allocate(value);
}
Created Events::typed(std::uint32_t full_event,std::uint32_t first,std::uint32_t second,std::uint32_t counter,std::uint16_t room){
    if(closed_)return{Status::closed,{}};
    const auto event=std::uint16_t(full_event);
    for(;;){
        if(free_count_){
            if(event>=priorities.size())return{Status::unavailable,{}};
            const auto priority=priorities[event];if(priority<threshold_)return{Status::priority_rejected,{}};
            Event value;value.timestamp=std::min(counter,timestamp_limit);value.id=event;value.type=2;value.priority=std::bit_cast<std::uint8_t>(priority);value.room=room;value.first=std::uint16_t(first);value.second=std::uint16_t(second);return allocate(value);
        }
        if(!prune())return{Status::full,{}};
    }
}
std::vector<View> Events::snapshot()const{
    std::vector<View> result;if(closed_)return result;result.reserve(128-free_count_);for(auto current=head_;current;current=slots_[*current].next)result.push_back({identity(*current),slots_[*current].value});return result;
}
}
