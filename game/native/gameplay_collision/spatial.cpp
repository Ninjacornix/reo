#include "spatial.hpp"
#include "nearest.hpp"
#include <cmath>
namespace reo::native::gameplay_collision::spatial {
namespace {
Vec3 sub(Vec3 a,Vec3 b){return{a.x-b.x,a.y-b.y,a.z-b.z};}
Vec3 add(Vec3 a,Vec3 b){return{a.x+b.x,a.y+b.y,a.z+b.z};}
Vec3 mul(Vec3 a,float b){return{a.x*b,a.y*b,a.z*b};}
float dot(Vec3 a,Vec3 b){return(a.x*b.x+a.y*b.y)+a.z*b.z;}
float length(Vec3 a){return std::sqrt(dot(a,a));}
Vec3 normalize(Vec3 a){const auto n=length(a);return n==0?Vec3{}:mul(a,1/n);}
Vec3 projection(Vec3 start,Vec3 end,Vec3 point){const auto delta=sub(end,start);const auto denominator=(-delta.x*delta.x-delta.y*delta.y)-delta.z*delta.z;if(denominator==0)return start;const auto first=start.x*delta.x-delta.x*point.x;const auto second=(start.y*delta.y+first)-delta.y*point.y;const auto numerator=(start.z*delta.z+second)-delta.z*point.z;return add(start,mul(delta,numerator/denominator));}
Vec3 offset(Vec3 direction,Vec3 origin,float distance){return add(origin,mul(normalize(direction),distance));}
bool equal(Vec3 a,Vec3 b){return a.x==b.x&&a.y==b.y&&a.z==b.z;}
}
std::optional<Point> sphere_segment(Vec3 start,Vec3 end,Sphere sphere)noexcept{
    if(length(sub(sphere.center,start))<sphere.radius)return Point{start};
    const auto projected=projection(start,end,sphere.center);const auto side=dot(sub(sphere.center,start),sub(sphere.center,end));
    if(side<0){const auto d=length(sub(sphere.center,projected));if(!(d<=sphere.radius))return{};const auto along=std::sqrt(sphere.radius*sphere.radius-d*d);return Point{offset(sub(start,projected),projected,along)};}
    if(!(length(sub(sphere.center,end))<=sphere.radius))return{};
    const auto d=length(sub(sphere.center,projected));const auto along=std::sqrt(sphere.radius*sphere.radius-d*d);return Point{offset(sub(start,end),projected,along)};
}
std::optional<Point> sphere_margin(Vec3 start,Vec3 end,Sphere sphere,float margin)noexcept{
    const auto first=dot(sub(sphere.center,start),sub(end,start)),second=dot(sub(sphere.center,end),sub(start,end));
    if(first>=0&&second>=0){const auto projected=projection(start,end,sphere.center);const auto d=length(sub(sphere.center,projected));if(!(d<=sphere.radius+margin))return{};if(d<sphere.radius){const auto along=std::sqrt(sphere.radius*sphere.radius-d*d);if(length(sub(start,projected))<along)return Point{start};return Point{offset(sub(start,projected),projected,along)};}return Point{offset(sub(projected,sphere.center),sphere.center,sphere.radius)};}
    if(first<0){const auto d=length(sub(sphere.center,start));if(!(d<=sphere.radius+margin))return{};if(d<sphere.radius)return Point{start};return Point{offset(sub(start,sphere.center),sphere.center,sphere.radius)};}
    const auto d=length(sub(sphere.center,end));if(!(d<=sphere.radius+margin))return{};if(d<sphere.radius){const auto projected=projection(start,end,sphere.center);const auto perpendicular=length(sub(sphere.center,projected));const auto along=std::sqrt(sphere.radius*sphere.radius-perpendicular*perpendicular);return Point{offset(sub(start,end),projected,along)};}return Point{offset(sub(end,sphere.center),sphere.center,sphere.radius)};
}
std::optional<Point> overlap(Sphere sphere,Vec3 point,float margin)noexcept{if(length(sub(point,sphere.center))>sphere.radius+margin)return{};return Point{mul(normalize(sub(point,sphere.center)),sphere.radius),PointSpace::origin_vector};}
bool sphere_edge(Vec3 start,Vec3 end,Sphere sphere)noexcept{const auto projected=projection(start,end,sphere.center);if(!(length(sub(projected,sphere.center))<=sphere.radius))return false;if(dot(sub(start,projected),sub(end,projected))<0)return true;return length(sub(start,sphere.center))<sphere.radius||length(sub(end,sphere.center))<sphere.radius;}
bool admits(const Target& target,const Policy& policy,Status& status)noexcept{auto mask=policy.recipient_mask;if(policy.special_mode&&(mask&2))mask=std::uint8_t(mask|(target.identity.category==0?5:1));if(target.identity.category==0)return(mask&(target.movement_flags&0x80?2:1))!=0;if(!mask)return false;if(target.identity.category>=policy.class_masks.size()){status=Status::unknown_class_domain;return false;}return(mask&policy.class_masks[target.identity.category])!=0;}
Scan scan(std::span<const Target> targets,const Source& source,Policy policy,Vec3 start,Vec3 end,float margin,Mode mode,const Occlusion* obstacles){
    Scan result;if(targets.size()>64){result.status=Status::invalid_target_count;return result;}for(const auto& target:targets)if(target.regions.size()>255){result.status=Status::invalid_region_count;return result;}if(mode==Mode::segment&&policy.occlusion&&!obstacles){result.status=Status::missing_occlusion;return result;}std::optional<Contact> best;float best_distance{};
    for(const auto& target:targets){result.last_scanned=target.entity;if(target.entity==source.entity||target.entity==source.related||!admits(target,policy,result.status))continue;result.advanced_direction_owner=target.entity;std::optional<Contact> actor_best;float actor_distance{};
        for(std::size_t i=0;i<target.regions.size();++i){const auto& region=target.regions[i];if(mode==Mode::segment&&policy.occlusion&&obstacles&&obstacles->blocked(start,region.center))continue;
            const auto point=mode==Mode::margin?(equal(start,end)?overlap(region,end,margin):sphere_margin(start,end,region,margin)):(margin<=0?sphere_segment(start,end,region):sphere_margin(start,end,region,margin));if(!point)continue;++result.region_hits;Contact contact{target.entity,target.identity,std::uint8_t(i),*point,region.center};const auto distance=length(sub(start,point->value));
            if(policy.per_actor){if(detail::replaces(bool(actor_best),distance,actor_distance)){actor_distance=distance;actor_best=contact;}if(mode==Mode::margin)break;}
            else if(detail::replaces(bool(best),distance,best_distance)){best_distance=distance;best=contact;}
        }
        if(actor_best)result.deliveries.push_back(*actor_best);
    }
    if(best){result.deliveries.push_back(*best);result.advanced_direction_unknown=mode==Mode::margin;}return result;
}
}
