#include "secondary_pose_math.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::animation {
namespace {
namespace m=constraint_math;
float finite(float value){if(!std::isfinite(value))throw std::domain_error("Native secondary pose finite arithmetic required");return value;}
void finite(Vector value){finite(value.x);finite(value.y);finite(value.z);}
float radius(float value){if(finite(value)<0)throw std::domain_error("Native secondary pose nonnegative radius required");return value;}
float dot(Vector a,Vector b){return finite(finite(finite(a.x*b.x)+finite(a.y*b.y))+finite(a.z*b.z));}
Vector cross(Vector a,Vector b){return{finite(finite(a.y*b.z)-finite(a.z*b.y)),finite(finite(a.z*b.x)-finite(a.x*b.z)),finite(finite(a.x*b.y)-finite(a.y*b.x))};}
Vector scale(Vector a,float value){return{finite(a.x*value),finite(a.y*value),finite(a.z*value)};}
float distance(Vector a,Vector b){return m::square_root(m::squared_length(m::subtract(a,b)));}
bool overlaps(Vector first,float a,Vector last,float b){const auto delta=m::subtract(first,last);const auto total=finite(a+b);return m::squared_length(delta)<=finite(total*total);}
}
PoseCapsule prepare_pose_capsule(Vector first,Vector last,float extent){
    finite(first);finite(last);radius(extent);
    const auto direction=m::subtract(last,first);
    const auto center=scale(m::add(first,last),.5f);
    return{first,last,extent,direction,center,finite(distance(first,center)+extent)};
}
bool constrain_pose_point(Vector point,float particle_radius,const PoseCapsule& capsule,Vector& output){
    finite(point);radius(particle_radius);radius(capsule.radius);finite(capsule.first);finite(capsule.last);finite(capsule.direction);finite(capsule.center);radius(capsule.bounding_radius);
    if(!overlaps(point,particle_radius,capsule.center,capsule.bounding_radius))return false;
    auto direction=capsule.direction;
    const auto first_delta=m::subtract(capsule.first,point);
    const auto normal=m::normalize(cross(direction,cross(direction,first_delta)));
    const auto signed_distance=dot(normal,first_delta),limit=finite(particle_radius+capsule.radius);
    if(!(std::abs(signed_distance)<=limit))return false;
    auto projection=m::add(point,scale(normal,signed_distance));
    if(dot(m::subtract(projection,capsule.first),direction)<0){
        if(!(distance(capsule.first,point)<=limit))return false;
        output=m::add(capsule.first,scale(m::normalize(m::subtract(point,capsule.first)),capsule.radius));return true;
    }
    direction={-direction.x,-direction.y,-direction.z};
    if(dot(m::subtract(projection,capsule.last),direction)<0){
        if(!(distance(capsule.last,point)<=limit))return false;
        output=m::add(capsule.last,scale(m::normalize(m::subtract(point,capsule.last)),capsule.radius));return true;
    }
    Vector radial;
    constexpr auto epsilon=std::bit_cast<float>(0x3a83126fu);
    if(std::abs(signed_distance)<epsilon){
        auto displaced=projection;displaced.x=finite(displaced.x+5.f);
        auto delta=m::subtract(displaced,capsule.last);
        auto perpendicular=cross(delta,direction);
        if(dot(perpendicular,perpendicular)<epsilon){
            // Source61B7F4 changes projected.y, while the displaced copy used
            // to recompute the cross product retains its original y value.
            projection.y=finite(projection.y+5.f);
            delta=m::subtract(displaced,capsule.last);perpendicular=cross(delta,direction);
        }
        radial=m::normalize(cross(perpendicular,direction));
    }else radial=m::normalize(m::subtract(point,projection));
    output=m::add(projection,scale(radial,capsule.radius));return true;
}
}
