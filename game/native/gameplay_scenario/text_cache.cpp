#include "text_cache.hpp"
#include <algorithm>
#include <bit>
namespace reo::native::gameplay_scenario {
namespace {
std::span<const std::byte> logical(std::span<const std::byte> text)noexcept{if(text.empty())return text;return text.first(std::size_t(std::find(text.begin(),text.end(),std::byte{})-text.begin()));}
bool same(std::span<const std::byte> a,std::span<const std::byte> b)noexcept{a=logical(a);b=logical(b);return std::equal(a.begin(),a.end(),b.begin(),b.end());}
std::int32_t add(std::int32_t a,std::int32_t b)noexcept{return std::bit_cast<std::int32_t>(std::uint32_t(a)+std::uint32_t(b));}
std::int16_t half(std::int32_t value)noexcept{return std::bit_cast<std::int16_t>(std::uint16_t(value));}
bool overlap(std::int32_t y,std::int32_t height,const CachedText& other)noexcept{return other.y<add(y,height)&&y<other.y+other.height;}
}
void TextCache::reset()noexcept{records_={};initialized_=true;}
CachedTextResult TextCache::request(std::int32_t priority,std::int32_t x,std::int32_t y,std::int32_t duration,std::int32_t height,std::span<const std::byte> text,std::int32_t fade)noexcept{
    if(!initialized_)return{TextCacheStatus::unbound,{}};
    for(const auto& record:records_)if(record.active&&record.priority<priority&&overlap(y,height,record))return{};
    const auto free=std::find_if(records_.begin(),records_.end(),[](const auto& record){return !record.active;});if(free==records_.end())return{};
    for(const auto& record:records_)if(record.active&&record.y==y&&same(record.text,text))return{};
    auto& record=*free;record.active=true;record.priority=std::uint8_t(priority);record.x=half(std::int32_t(std::uint32_t(x)&0xfffeu));record.y=half(std::int32_t(std::uint32_t(y)&0xfffeu));
    text=logical(text);const auto index=std::size_t(free-records_.begin());
    if(text.size()>=record.text.size())return{TextCacheStatus::unsupported_profile,index};
    std::copy(text.begin(),text.end(),record.text.begin());record.text[text.size()]=std::byte{};
    record.duration=half(duration);record.height=std::uint8_t(height);record.alpha=fade?0:0x80;record.fade=std::uint8_t(fade);
    return{TextCacheStatus::completed,index};
}
CachedTextResult TextCache::dialogue(std::int16_t x,std::uint16_t y,std::span<const std::byte> text,std::uint8_t alpha)noexcept{
    auto result=request(1,x,y,1,20,text,0);if(result.status==TextCacheStatus::completed&&result.index)records_[*result.index].alpha=alpha;return result;
}
TextCacheStatus TextCache::erase(std::span<const std::byte> text)noexcept{
    if(!initialized_)return TextCacheStatus::unbound;
    for(auto& record:records_)if(record.active&&same(record.text,text))record.active=false;
    return TextCacheStatus::completed;
}
TextCacheStatus TextCache::expire()noexcept{
    if(!initialized_)return TextCacheStatus::unbound;
    for(const auto& record:records_)if(record.active&&record.duration&&record.priority)(void)erase(record.text);
    return TextCacheStatus::completed;
}
TextCacheStatus TextCache::cull()noexcept{
    if(!initialized_)return TextCacheStatus::unbound;
    for(auto& record:records_)if(record.active)for(const auto& other:records_)if(other.active&&other.priority<record.priority&&overlap(record.y,record.height,other)){record.active=false;break;}
    return TextCacheStatus::completed;
}
} // namespace reo::native::gameplay_scenario
