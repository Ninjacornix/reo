#include "resource_debris.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_effects {
namespace {
bool finite(transform_math::Vector v){return std::isfinite(v.x)&&std::isfinite(v.y)&&std::isfinite(v.z);}
std::int16_t half(std::int32_t v){return std::bit_cast<std::int16_t>(std::uint16_t(v));}
}
ResourceDebrisStep advance_resource_debris(ResourceDebrisState& state,gameplay_session::Random& random){
    transform_math::require_profile();
    switch(state.phase){
    case 0:
        if(!finite(state.initial_position))throw std::domain_error("Native resource debris finite initial position required");
        state.visible=true;state.phase=1;state.position=state.previous_position=state.initial_position;
        state.angular_velocity[1]=std::int16_t(random.request(1)&0x7fffu);
        state.angular_velocity[0]=std::int16_t(random.request(1)&0x7fffu);
        (void)random.request(1);state.angular_velocity[2]=0;
        state.velocity.x=float(random.request(1)&7u)-3.5f;state.velocity.y=5;
        (void)random.request(1);state.velocity.z=0;
        state.acceleration={0,std::bit_cast<float>(0xbf7ae148u),0};state.delay=5;state.fade_step=std::bit_cast<float>(0x3d4ccccdu);
        return{};
    case 1:
        if(!finite(state.position)||!finite(state.velocity)||!finite(state.acceleration)||!std::isfinite(state.alpha)||!std::isfinite(state.fade_step))throw std::domain_error("Native resource debris finite integration profile required");
        for(unsigned i=0;i<3;++i)state.angles[i]=half(std::int32_t(state.angles[i])+state.angular_velocity[i]);
        state.previous_position=state.position;
        state.position.x=state.position.x+state.velocity.x;state.position.y=state.position.y+state.velocity.y;state.position.z=state.position.z+state.velocity.z;
        state.velocity.x=state.velocity.x+state.acceleration.x;state.velocity.y=state.velocity.y+state.acceleration.y;state.velocity.z=state.velocity.z+state.acceleration.z;
        state.delay=half(std::int32_t(state.delay)-1);
        if(state.delay<0){state.alpha=state.alpha-state.fade_step;if(state.alpha<0){state.alpha=0;state.phase=2;state.visible=false;}}
        if(!finite(state.position)||!finite(state.velocity)||!std::isfinite(state.alpha))throw std::domain_error("Native resource debris integration exceeds finite profile");
        return{false,true};
    case 2:return{true,false};
    default:throw std::domain_error("Native resource debris phase unavailable");
    }
}
void complete_resource_debris_floor(ResourceDebrisState& state,bool hit)noexcept{if(hit){state.phase=2;state.visible=false;}}
}
