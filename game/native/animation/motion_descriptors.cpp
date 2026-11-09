#include "motion_descriptors.hpp"
#include <span>
#include <stdexcept>
namespace reo::native::animation {
namespace {
#include "motion_descriptor_profile.inc"
std::uint16_t half(const PackedMotion& p,unsigned i){return std::uint16_t(p.bytes[i]|(unsigned(p.bytes[i+1])<<8));}
std::uint16_t selected(std::span<const std::uint16_t> table,std::size_t index){if(index>=table.size())throw std::out_of_range("Native motion descriptor indexed content unavailable");return table[index];}
}
const PackedMotion& File1MotionDescriptors::at(std::size_t id)const{if(id>=descriptors.size())throw std::out_of_range("Native packed motion descriptor unavailable");return descriptors[id];}
const PackedMotion& File1MotionDescriptors::resolve(const MotionIdentity& actor,std::uint32_t code)const{
    auto state=actor.class_marker;if(actor.status&0x18)state=3;if(actor.status&0x20)state=0;const std::uint16_t low=std::uint16_t(code),key=low&0xfff;const unsigned family=low>>12;
    if(family==1)return at(selected(direct,key));
    if(family==2){if(actor.resource_action>=resource_classes.size())throw std::out_of_range("Native motion resource action class unavailable");const auto kind=actor.resource_action?resource_classes[actor.resource_action]:0;const std::array<std::span<const std::uint16_t>,4> tables{class_zero,class_one,class_two,class_three};return at(selected(tables.at(kind),std::size_t(key)*4+state));}
    if(family==3)return at(selected(state_map,std::size_t(key)*4+state));
    return at(0);
}
DecodedMotion File1MotionDescriptors::unpack(const MotionIdentity& actor,const PackedMotion& source)const{
    const PackedMotion* p=&source;unsigned family=p->bytes[0]>>4;
    if(family==15){if(actor.category==0){p=&at(std::size_t(half(*p,6))+actor.character);family=p->bytes[0]>>4;}else if(actor.category==1)p=&at(std::size_t(half(*p,6))+actor.subtype);}
    if(actor.category==1&&(family==15||family==2))family=1;
    DecodedMotion out;out.family=std::uint8_t(family);out.offset_selector=p->bytes[2]>>4;out.shape_selector=p->bytes[2]&15;out.flags=std::uint8_t(((p->bytes[0]&12)<<3)|((p->bytes[0]&3)<<1));out.threshold=std::uint8_t(((half(*p,4)&0xf000)>>8)|((half(*p,6)&0xf000)>>12));out.channel_one=half(*p,4)&0xfff;out.channel_zero=half(*p,6)&0xfff;out.alternate_threshold=p->bytes[3];return out;
}
} // namespace reo::native::animation
