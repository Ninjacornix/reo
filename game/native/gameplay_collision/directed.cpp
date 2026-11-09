#include "directed.hpp"
#include <algorithm>
#include <cmath>
namespace reo::native::gameplay_collision::directed {
namespace {
Vec3 add(Vec3 a,Vec3 b){return{a.x+b.x,a.y+b.y,a.z+b.z};}
Vec3 sub(Vec3 a,Vec3 b){return{a.x-b.x,a.y-b.y,a.z-b.z};}
Vec3 mul(Vec3 a,float b){return{a.x*b,a.y*b,a.z*b};}
float dot(Vec3 a,Vec3 b){return(a.x*b.x+a.y*b.y)+a.z*b.z;}
float square(Vec3 a){return(a.x*a.x+a.y*a.y)+a.z*a.z;}
float length(Vec3 a){return std::sqrt(square(a));}
Vec3 normalize(Vec3 a){const auto n=length(a);return n==0?Vec3{}:mul(a,1/n);}
}
Pair ratios(Extents extents)noexcept{
    const auto angle=std::atan2(extents.second,extents.first);const auto phase=1.5707963705062866f-angle;
    const auto second=phase*phase,fourth=second*second,sixth=second*fourth,eighth=fourth*fourth;
    auto polynomial=phase+second*(-0.16666656732559204f*phase);
    polynomial+=fourth*(0.008333025500178337f*phase);
    polynomial+=sixth*(-0.00019807413627859205f*phase);
    polynomial+=eighth*(0.000002601886990305502f*phase);
    return{std::sqrt(std::max(0.0f,1-polynomial*polynomial)),polynomial};
}
std::optional<spatial::Point> contact(Sphere sphere,Vec3 origin,Vec3 direction,Extents extents)noexcept{
    if(sphere.radius<=0||extents.first<=0||extents.second<=0)return{};
    const auto pair=ratios(extents);if(pair.first==0||pair.second==0)return{};
    if(!(length(sub(sphere.center,origin))<=sphere.radius+extents.first/pair.second))return{};
    direction=normalize(direction);const auto delta=sub(sphere.center,origin);const auto shifted=add(mul(direction,sphere.radius/pair.first),delta);const auto axis=dot(shifted,direction);const auto cos_square=pair.second*pair.second;
    if(axis<=0||axis*axis<square(shifted)*cos_square)return{};
    const auto delta_square=square(delta),back=-dot(delta,direction);if(back>0&&!(back*back<delta_square*(pair.first*pair.first))&&!(delta_square<=sphere.radius*sphere.radius))return{};
    const auto surface=[&]{return spatial::Point{add(sphere.center,mul(delta,-(sphere.radius/std::sqrt(delta_square))))};};
    if(delta_square<=sphere.radius*sphere.radius)return surface();
    const auto projection=dot(delta,direction);if(!(projection*projection<delta_square*cos_square)&&!(projection<=0))return surface();
    const auto perpendicular=std::sqrt(std::abs(delta_square-projection*projection));const auto along=pair.second*projection+pair.first*perpendicular;const auto travel=along-std::sqrt(sphere.radius*sphere.radius+(along*along-delta_square));const auto radial=add(mul(direction,-projection),delta);const auto scale=pair.first/perpendicular;
    return spatial::Point{{travel*(pair.second*direction.x+scale*radial.x),travel*(pair.second*direction.y+scale*radial.y),travel*(pair.second*direction.z+scale*radial.z)},spatial::PointSpace::origin_vector};
}
spatial::Scan scan(std::span<const spatial::Target> targets,const spatial::Source& source,spatial::Policy policy,Vec3 origin,Vec3 direction,Extents extents,const spatial::Occlusion* obstacles){
    spatial::Scan result;if(targets.size()>64){result.status=spatial::Status::invalid_target_count;return result;}for(const auto& t:targets)if(t.regions.size()>255){result.status=spatial::Status::invalid_region_count;return result;}if(policy.occlusion&&!obstacles){result.status=spatial::Status::missing_occlusion;return result;}std::optional<spatial::Contact> nearest;float distance{};
    for(const auto& target:targets){result.last_scanned=target.entity;if(target.entity==source.entity||target.entity==source.related||!spatial::admits(target,policy,result.status))continue;result.advanced_direction_owner=target.entity;
        for(unsigned i=0;i<target.regions.size();++i){const auto& region=target.regions[i];if(policy.occlusion&&obstacles&&obstacles->blocked(origin,region.center))continue;const auto point=contact(region,origin,direction,extents);if(!point)continue;++result.region_hits;spatial::Contact candidate{target.entity,target.identity,std::uint8_t(i),*point,region.center};
            if(policy.per_actor){result.deliveries.push_back(candidate);break;}
            const auto current=std::abs(length(sub(origin,point->value)));if(!nearest||current<distance){nearest=candidate;distance=current;}
        }
    }if(nearest){result.deliveries.push_back(*nearest);result.advanced_direction_unknown=true;}return result;
}
}
