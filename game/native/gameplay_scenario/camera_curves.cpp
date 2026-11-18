#include "camera_curves.hpp"
#include <bit>
#include <cmath>
#include <limits>

namespace reo::native::gameplay_scenario {
namespace {
float quadratic(float first,float control,float last,float t) noexcept {
    const float a=first+(control-first)*t;
    const float b=control+(last-control)*t;
    return a+(b-a)*t;
}
transform_math::Vector point(const CameraSegment& segment,float t) noexcept {
    const auto& a=segment.current.point;const auto& b=segment.current.control;const auto& c=segment.next.point;
    return {quadratic(a.x,b.x,c.x,t),quadratic(a.y,b.y,c.y,t),quadratic(a.z,b.z,c.z,t)};
}
float parameter(const CameraSegment& segment,std::uint32_t frame) noexcept {
    const auto denominator=std::int32_t(segment.next.frame)-std::int32_t(segment.current.frame);
    if(!denominator)return 1.0f;
    return float(std::bit_cast<std::int32_t>(frame-std::uint32_t(segment.current.frame)))/float(denominator);
}
float eased(float first,float last,float t,float control) noexcept {
    const float middle=(1.0f+control)/2.0f;
    return first+quadratic(0.0f,middle,1.0f,t)*(last-first);
}
std::uint32_t truncate_word(float value) noexcept {
    // The original CVT.W.S contract is truncation with signed saturation.
    if(!std::isfinite(value)||value>=2147483648.0f||value<-2147483648.0f)
        return std::signbit(value)?0x80000000u:0x7fffffffu;
    return std::bit_cast<std::uint32_t>(static_cast<std::int32_t>(value));
}
}
bool sample_camera_parameters(CameraParameters& value,const std::optional<CameraSegment>& eye,
                              const std::optional<CameraSegment>& aim,std::uint32_t frame) noexcept {
    if(!eye||!aim)return false;
    const auto& first=eye->current;
    if(eye->next.frame==65535){value.pose.eye=first.point;value.lens=first.lens;value.pose.roll=first.roll;}
    else{
        const auto t=parameter(*eye,frame);value.pose.eye=point(*eye,t);
        if(first.roll==eye->next.roll)value.pose.roll=first.roll;
        else if(first.roll_control!=0.0f)
            value.pose.roll=truncate_word(eased(float(std::bit_cast<std::int32_t>(first.roll)),
                float(std::bit_cast<std::int32_t>(eye->next.roll)),t,first.roll_control))&65535u;
        else value.pose.roll=first.roll+truncate_word(t*float(std::bit_cast<std::int32_t>(eye->next.roll-first.roll)));
        if(first.lens==eye->next.lens)value.lens=first.lens;
        else if(first.lens_control!=0.0f)value.lens=eased(first.lens,eye->next.lens,t,first.lens_control);
        else value.lens=first.lens+t*(eye->next.lens-first.lens);
    }
    value.pose.aim=aim->next.frame==65535?aim->current.point:point(*aim,parameter(*aim,frame));
    return true;
}
} // namespace reo::native::gameplay_scenario
