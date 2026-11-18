#include "cutscene_light_curves.hpp"
#include <bit>
namespace reo::native::gameplay_scenario {
namespace {
float quadratic(float first,float control,float last,float t)noexcept{
    const auto a=first+(control-first)*t,b=control+(last-control)*t;return a+(b-a)*t;
}
float normalized(std::uint8_t value)noexcept{return float(value)/255.0f;}
}
transform_math::Vector cutscene_light_point(const CutsceneLightSegment& segment,std::uint32_t frame)noexcept{
    const auto& a=segment.current;const auto& b=segment.next;
    if(b.frame==65535)return a.point;
    const auto denominator=std::int32_t(b.frame)-std::int32_t(a.frame);
    const float t=denominator?float(std::bit_cast<std::int32_t>(frame-std::uint32_t(a.frame)))/float(denominator):1.0f;
    return{quadratic(a.point.x,a.control.x,b.point.x,t),quadratic(a.point.y,a.control.y,b.point.y,t),quadratic(a.point.z,a.control.z,b.point.z,t)};
}
void initialize_cutscene_light(NativeLight& light,const CutsceneLightKey& key,std::uint8_t material)noexcept{
    auto& d=light.descriptor;
    for(unsigned lane=0;lane<3;++lane){d.vector0[lane]=normalized(key.first[lane]);d.vector1[lane]=normalized(key.second[lane]);}
    d.vector0[3]=d.vector1[3]=0;d.position={key.point.x,key.point.y,key.point.z};d.parameter=key.radius;d.attenuation=key.extra;
    light.tag=material;light.mode=std::uint8_t(2+(key.flags&1));
}
std::optional<LightDescriptor> sample_cutscene_light(NativeLight& light,const CutsceneLightSegment& segment,
    std::int8_t end_enabled,std::uint32_t frame,std::uint8_t clock_mode,std::uint8_t material)noexcept{
    auto& d=light.descriptor;const auto& a=segment.current;const auto& b=segment.next;
    const auto point=cutscene_light_point(segment,frame);d.position={point.x,point.y,point.z};light.tag=material;
    if(b.frame==65535){
        d.parameter=a.radius;d.attenuation=a.extra;
        for(unsigned lane=0;lane<3;++lane){d.vector0[lane]=normalized(a.first[lane]);d.vector1[lane]=normalized(a.second[lane]);}
    }else{
        auto duration=float(std::int32_t(b.frame)-std::int32_t(a.frame));if(clock_mode)duration=duration/2.0f;
        if(duration>1.0f){
            d.parameter=d.parameter+(b.radius-a.radius)/duration;
            for(unsigned lane=0;lane<3;++lane){
                d.vector0[lane]=d.vector0[lane]+((float(b.first[lane])-float(a.first[lane]))/255.0f)/duration;
                d.vector1[lane]=d.vector1[lane]+((float(b.second[lane])-float(a.second[lane]))/255.0f)/duration;
            }
            d.attenuation=d.attenuation+(b.extra-a.extra)/duration;
        }
    }
    const auto mirror=light.mode==2?std::optional(d):std::nullopt;
    if(!end_enabled)d.attenuation=0;
    return mirror;
}
} // namespace reo::native::gameplay_scenario
