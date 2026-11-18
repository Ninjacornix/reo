#include "snapshot.hpp"
#include <algorithm>

namespace reo::native::gameplay_save {
namespace {
std::uint16_t half(const std::byte* p) noexcept {
    return std::uint16_t(std::to_integer<unsigned>(p[0])|(std::to_integer<unsigned>(p[1])<<8));
}
void half(std::byte* p,std::uint16_t value) noexcept {
    p[0]=std::byte(value&255);p[1]=std::byte(value>>8);
}
std::uint16_t next(std::uint16_t seed) noexcept {
    // Zero is replaced only AFTER the current word has used it.
    return std::uint16_t((std::uint32_t(seed?seed:1)*176)%0xff53);
}
HeaderView header(ContainerView c) noexcept{return HeaderView(c.data()+8,header_bytes);}
DataView data(ContainerView c) noexcept{return DataView(c.data()+0x108,data_bytes);}
}
void encode(ContainerView c,std::uint32_t seed_value) noexcept {
    auto seed=std::uint16_t(seed_value);std::uint16_t sum{};
    half(c.data(),0x5963);half(c.data()+2,seed);half(c.data()+4,0);half(c.data()+6,0);
    for(std::size_t i=8;i<container_bytes;i+=2){
        const auto plain=half(c.data()+i);sum=std::uint16_t(sum+plain);
        half(c.data()+i,std::uint16_t(plain^seed));seed=next(seed);
    }
    half(c.data()+4,sum);
}
DecodeResult decode(ContainerView c) noexcept {
    if(half(c.data())!=0x5963)return DecodeResult::bad_magic;
    auto seed=half(c.data()+2);const auto expected=half(c.data()+4);std::uint16_t sum{};
    for(std::size_t i=8;i<container_bytes;i+=2){
        const auto plain=std::uint16_t(half(c.data()+i)^seed);
        half(c.data()+i,plain);sum=std::uint16_t(sum+plain);seed=next(seed);
    }
    return sum==expected?DecodeResult::ok:DecodeResult::bad_checksum;
}
void capture_header(HeaderView h,const LiveState& s) noexcept {
    std::copy(s.settings.begin(),s.settings.end(),h.begin()+8);
    h[0x18]=s.profile_flag;h[0x19]=h[0x1b]=std::byte{};
}
void capture_first(DataView d,const LiveState& s) noexcept {
    std::fill_n(d.begin(),0x10000,std::byte{});std::copy(s.first.begin(),s.first.end(),d.begin());
}
void capture_second(HeaderView h,DataView d,const LiveState& s) noexcept {
    h[0x19]=s.second_flag;h[0x1b]=s.resume_selector;
    std::fill_n(d.begin()+0x10000,0x1fbc0,std::byte{});
    std::copy(s.second.begin(),s.second.end(),d.begin()+0x10000);
}
void capture_tail(DataView d,const LiveState& s) noexcept {
    std::copy(s.third.begin(),s.third.end(),d.begin()+0x2fbc0);
    std::copy(s.tail.begin(),s.tail.end(),d.begin()+0x37bc0);
}
bool restore_header(ConstHeaderView h,LiveState& s,const Services& services) noexcept {
    if(!services.settings_changed)return false;
    std::copy_n(h.begin()+8,16,s.settings.begin());
    if(services.settings_changed)services.settings_changed(services.context,s);
    s.profile_flag=h[0x18];s.second_flag=h[0x19];s.resume_selector=h[0x1b];
    return true;
}
void restore_first(ConstDataView d,LiveState& s) noexcept {std::copy_n(d.begin(),s.first.size(),s.first.begin());}
void restore_second(ConstDataView d,LiveState& s) noexcept {std::copy_n(d.begin()+0x10000,s.second.size(),s.second.begin());}
void restore_tail(ConstDataView d,LiveState& s) noexcept {
    std::copy_n(d.begin()+0x2fbc0,s.third.size(),s.third.begin());
    std::copy_n(d.begin()+0x37bc0,s.tail.size(),s.tail.begin());
    // The original loop tests the SAME first byte up to eight times.
    if(s.tail[0]!=std::byte{})std::copy_n(s.tail.begin(),8,s.conditional_tail.begin());
}
void clear_second_for_root_mode(LiveState& s,std::uint32_t mode) noexcept {
    if(mode==0||mode==1){s.second_flag=std::byte{};s.second.fill(std::byte{});}
}
bool capture(ContainerView c,const LiveState& s,const Services& services) noexcept {
    if(!services.timestamp||!services.random)return false;
    const auto h=header(c);const auto d=data(c);
    services.timestamp(services.context,h);capture_header(h,s);capture_first(d,s);capture_second(h,d,s);capture_tail(d,s);
    encode(c,services.random(services.context,1));return true;
}
RestoreResult restore(ContainerView c,LiveState& s,const Services& services) noexcept {
    // Refuse absent dependency before decode mutates caller-owned container.
    if(!services.settings_changed)return{-1,DecodeResult::dependency_unavailable};
    const auto result=decode(c);
    if(result!=DecodeResult::ok)return{-1,result};
    restore_header(header(c),s,services);restore_first(data(c),s);restore_second(data(c),s);restore_tail(data(c),s);
    return{0,result};
}
} // namespace reo::native::gameplay_save
