#include "resource_companion.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_effects {
namespace {
std::int16_t half(std::int32_t n){return std::bit_cast<std::int16_t>(std::uint16_t(n));}
bool finite(transform_math::Vector v){return std::isfinite(v.x)&&std::isfinite(v.y)&&std::isfinite(v.z);}
}
ResourceCompanionStep advance_resource_companion(ResourceCompanionState& s,
    const ResourceCompanionModel& model,const std::optional<ResourceCompanionActor>& actor,
    gameplay_session::Random& random){
    ResourceCompanionStep result;
    const bool attacking=actor&&actor->primary==2&&actor->secondary==11;
    const bool matches=model.active&&model.content==s.content&&model.resource_slot==s.resource_slot;
    switch(s.phase){
    case 0:
        s.local_offset=s.position;s.resource_slot=model.resource_slot;s.pending=s.frozen=s.emitted=0;
        if(s.attributes&8u){s.visible=false;s.phase=4;return result;}
        s.phase=1;s.child_attributes=std::uint16_t((s.attributes&0x20u)|6u);
        [[fallthrough]];
    case 1:
        if(!model.active||model.content!=s.content||model.resource_slot!=s.resource_slot){result.retire=true;return result;}
        s.visible=model.visible;s.scale=model.scale;
        if(s.attributes&4u){
            if(!actor){s.phase=2;return result;}
            if((s.attributes&0x10u)&&attacking){s.visible=false;s.phase=4;return result;}
            if((s.attributes&8u)&&!attacking){s.remaining=0;s.age=1;}
        }
        if(!s.frozen){
            transform_math::require_profile();s.basis=transform_math::identity();
            if(!(s.attributes&1u))for(unsigned c=0;c<3;++c)for(unsigned r=0;r<3;++r)s.basis[c][r]=model.pose[c][r];
            const auto offset=transform_math::direction(model.pose,s.local_offset);
            s.position={offset.x+model.position.x,offset.y+model.position.y,offset.z+model.position.z};
            if(!finite(s.position)||!finite(s.scale))throw std::domain_error("Native resource companion finite transform required");
            if(s.attributes&2u)s.frozen=1;
        }
        if((s.attributes&0x44u)==0x44u&&!s.emitted){s.emitted=1;result.spawn_gameplay=true;}
        s.remaining=half(std::int32_t(s.remaining)-2);
        if(s.remaining<0){
            s.remaining=s.loop_lifetime;s.age=0;
            switch(s.subtype){
            case 0:break;
            case 1:s.visible=false;s.phase=2;return result;
            case 2:s.phase=3;return result;
            case 3:s.visible=false;s.phase=4;s.pending=1;return result;
            case 4:s.pending=1;break;
            case 5:
                s.visible=false;s.phase=5;s.delay=std::int16_t(random.request(1)&63u);
                if(s.attributes&0x80u)s.angles[2]=std::bit_cast<std::int16_t>(random.request(1));
                return result;
            case 6:s.phase=6;s.pending=s.frozen=0;return result;
            default:s.visible=false;s.phase=2;return result;
            }
        }
        if(model.flags&0x100u){s.child_attributes|=0x100u;s.material_scale=float(std::bit_cast<std::int16_t>(model.draw_tag))/255.f;}
        else s.child_attributes&=~std::uint16_t(0x100u);
        result.render=true;result.sample_time=s.age;s.age=half(std::int32_t(s.age)+2);return result;
    case 2:result.retire=true;return result;
    case 3:return result;
    case 4:
        if(!actor){s.phase=2;return result;}
        if(attacking){if(!s.pending&&(s.attributes&8u)){s.phase=5;s.delay=8;}return result;}
        s.pending=0;if(s.attributes&0x10u)s.phase=1;return result;
    case 5:
        s.delay=half(std::int32_t(s.delay)-1);if(s.delay>=0)return result;
        s.phase=1;s.frozen=s.emitted=0;s.delay=0;
        if(s.content==0x75&&actor)result.resource_cue=std::uint16_t((random.request(1)&1u)?20:21);
        return result;
    case 6:
        if(!s.pending){
            if(matches&&s.visible)return result;
            s.pending=1;s.fade_delta=s.alpha/30.f;return result;
        }
        s.alpha=s.alpha-s.fade_delta;
        if(!std::isfinite(s.alpha)||!std::isfinite(s.fade_delta))throw std::domain_error("Native resource companion finite fade required");
        if(s.alpha<0){result.retire=true;return result;}
        result.fade_children=true;return result;
    default:return result;
    }
}
}
