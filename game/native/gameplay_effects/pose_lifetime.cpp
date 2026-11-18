#include "pose_lifetime.hpp"
#include <bit>
namespace reo::native::gameplay_effects {
PoseLifetimeStep advance_pose_lifetime(std::int16_t& lifetime,std::uint8_t kind)noexcept{
    lifetime=std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(lifetime)-1));
    if(lifetime==0)return{true,{}};
    switch(kind){
    case 0:case 3:case 4:case 5:return{false,0};
    case 1:case 2:case 6:case 9:case 10:case 11:case 12:case 13:
    case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 100:return{false,kind};
    default:return{};
    }
}
}
