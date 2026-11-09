#include "trace.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <limits>
#include <stdexcept>
namespace reo::native::gameplay_collision::trace {
namespace {
Vec3 sub(Vec3 a,Vec3 b){return{a.x-b.x,a.y-b.y,a.z-b.z};}
Vec3 add(Vec3 a,Vec3 b){return{a.x+b.x,a.y+b.y,a.z+b.z};}
Vec3 mul(Vec3 a,float b){return{a.x*b,a.y*b,a.z*b};}
float dot(Vec3 a,Vec3 b){return(a.x*b.x+a.y*b.y)+a.z*b.z;}
float length(Vec3 a){return std::sqrt(dot(a,a));}
Vec3 normalized(Vec3 v){const auto n=length(v);return n==0?Vec3{}:mul(v,1/n);}
std::uint16_t angle(float radians){const auto units=182.04444885253906f*((180.0f*radians)/3.1415927410125732f);if(!std::isfinite(units))return 0;return std::uint16_t(std::uint32_t(std::trunc(units)));}
std::span<const std::uint32_t> cell(const response::Grid& grid,Cell index){const auto& h=grid.header();return grid.cell({float(h.origin_x)+(float(index.column)+0.5f)*float(h.step_x),0,float(h.origin_z)+(float(index.row)+0.5f)*float(h.step_z)});}
Hit hit(const response::Triangle& t,std::uint32_t index,Vec3 point,bool two_sided,std::uint8_t side){auto normal=t.normal;if(two_sided&&side)normal=mul(normal,-1);return{point,normal,two_sided?std::uint8_t(t.flags):(t.flags&0xffff0000u)|(1u<<(t.flags&15)),index};}
std::optional<Hit> first(std::span<const response::Triangle> triangles,std::span<const std::uint32_t> ids,Vec3 start,Vec3 end,const response::Filter& filter){for(const auto id:ids){const auto& t=triangles[id];if(!response::admits(t.flags,filter))continue;const auto result=triangle(t,start,end);if(result.hit)return hit(t,id,*result.written_point,false,0);}return{};}
std::vector<std::uint32_t> indices(std::size_t count){std::vector<std::uint32_t> result;result.reserve(count);for(std::uint32_t i=0;i<count;++i)result.push_back(i);return result;}
}
bool angle_contains(const response::Triangle& t,Vec3 point)noexcept{
    std::array<Vec3,3> directions;for(unsigned i=0;i<3;++i)directions[i]=normalized(sub(t.vertices[i],point));std::uint32_t sum{};
    for(unsigned i=0;i<3;++i){const auto cosine=std::clamp(dot(directions[i],directions[(i+1)%3]),-1.0f,1.0f);sum+=angle(std::acos(cosine));}
    return sum>=0xfff0;
}
SegmentResult triangle(const response::Triangle& t,Vec3 start,Vec3 end,std::uint8_t side)noexcept{
    SegmentResult result;const auto delta=sub(end,start);
    if(!side&&(dot(sub(t.vertices[0],start),t.normal)>0||dot(delta,t.normal)>0))return result;
    auto multiplier=-(t.plane_d+dot(t.normal,start));const auto denominator=dot(t.normal,delta);if(denominator!=0)multiplier/=denominator;
    const auto point=add(start,mul(delta,multiplier));result.written_point=point;result.side=side?1:0;
    const auto towards_start=normalized(sub(start,point)),towards_end=normalized(sub(end,point));
    if(!(dot(towards_start,towards_end)<0)||!angle_contains(t,point))return result;
    result.hit=true;result.written_point=add(point,mul(normalized(towards_start),0.0010000000474974513f));return result;
}
Samples sample(const response::Grid& grid,Vec3 start,Vec3 end,bool floor_bank,std::size_t capacity){
    Samples result;const auto& h=grid.header();Vec3 delta{end.x-start.x,0,end.z-start.z};const auto distance=length(delta);const auto direction=normalized(delta);const auto step=length({float(h.step_x),0,float(h.step_z)})/(floor_bank?2.0f:2.5f);
    if(!std::isfinite(distance)||!std::isfinite(step)||!(step>0)){result.status=SamplingStatus::nonprogress;return result;}
    float travel{};for(;;){const auto point=integer_xz(add(start,mul(direction,travel)));if(!point){result.status=SamplingStatus::left_grid;break;}
        const auto x=(std::uint32_t(point->x)-h.origin_x)/h.step_x,z=(std::uint32_t(point->z)-h.origin_z)/h.step_z;
        if(x>=h.columns||z>=h.rows||std::bit_cast<std::int32_t>(x)<0||std::bit_cast<std::int32_t>(z)<0){result.status=SamplingStatus::left_grid;break;}
        const Cell index{x,z};if(result.cells.size()==capacity){result.status=SamplingStatus::capacity;break;}result.cells.push_back(index);
        if(travel==distance)break;
        const auto next=std::min(travel+step,distance);if(!(next>travel)){result.status=SamplingStatus::nonprogress;break;}travel=next;
    }return result;
}
ListResult list(std::span<const response::Triangle> triangles,std::span<const std::uint32_t> ids,Vec3 start,Vec3 end,const response::Filter& filter,bool two_sided){
    ListResult result;float nearest{};for(const auto id:ids){if(id>=triangles.size())throw std::invalid_argument("Foreign native collision triangle");const auto& t=triangles[id];if(!two_sided&&!response::admits(t.flags,filter))continue;
        const auto candidate=triangle(t,start,end,two_sided?1:0);if(!candidate.hit)continue;++result.count;const auto distance=length(sub(start,*candidate.written_point));
        if(result.nearest&&nearest<=distance)continue;
        nearest=distance;result.nearest=hit(t,id,*candidate.written_point,two_sided,*candidate.side);
    }return result;
}
Result shorten(const response::Grid& grid,Vec3 start,Vec3 end,const response::Filter& filter,std::span<const response::Triangle> dynamic){
    const auto sampled=sample(grid,start,end);Result result;result.status=sampled.status;if(sampled.status==SamplingStatus::capacity||sampled.status==SamplingStatus::nonprogress)return result;
    for(const auto index:sampled.cells){const auto found=list(grid.triangles(),cell(grid,index),start,end,filter);if(found.nearest){result.hit=found.nearest;end=found.nearest->point;}}
    const auto found=list(dynamic,indices(dynamic.size()),start,end,filter);if(found.nearest)result.hit=found.nearest;return result;
}
Result any(const response::Grid& grid,Vec3 start,Vec3 end,const response::Filter& filter,std::span<const response::Triangle> dynamic){
    const auto sampled=sample(grid,start,end);Result result;result.status=sampled.status;if(sampled.status==SamplingStatus::capacity||sampled.status==SamplingStatus::nonprogress)return result;
    for(const auto index:sampled.cells){result.hit=first(grid.triangles(),cell(grid,index),start,end,filter);if(result.hit)return result;}result.hit=first(dynamic,indices(dynamic.size()),start,end,filter);return result;
}
Result floor(const response::Grid& grid,Vec3 start,Vec3 end){const auto sampled=sample(grid,start,end,true);Result result;result.status=sampled.status;if(sampled.status==SamplingStatus::capacity||sampled.status==SamplingStatus::nonprogress)return result;for(const auto index:sampled.cells){result.hit=list(grid.triangles(),cell(grid,index),start,end,{},true).nearest;if(result.hit)break;}return result;}
bool floor_any(const response::Grid& grid,Vec3 start,Vec3 end,std::uint8_t required,std::uint8_t excluded){const auto sampled=sample(grid,start,end,true);if(sampled.status==SamplingStatus::capacity||sampled.status==SamplingStatus::nonprogress)return false;for(const auto index:sampled.cells)for(const auto id:cell(grid,index)){const auto& t=grid.triangles()[id];const auto type=std::uint8_t(t.flags);if(type==excluded||(required!=255&&type!=required))continue;if(triangle(t,start,end,1).hit)return true;}return false;}
}
