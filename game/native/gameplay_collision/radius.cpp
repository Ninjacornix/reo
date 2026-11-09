#include "radius.hpp"
#include "spatial.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
namespace reo::native::gameplay_collision::radius {
namespace {
Vec3 add(Vec3 a,Vec3 b){return{a.x+b.x,a.y+b.y,a.z+b.z};}
Vec3 sub(Vec3 a,Vec3 b){return{a.x-b.x,a.y-b.y,a.z-b.z};}
Vec3 mul(Vec3 a,float b){return{a.x*b,a.y*b,a.z*b};}
float length(Vec3 a){return std::sqrt((a.x*a.x+a.y*a.y)+a.z*a.z);}
bool equal(Vec3 a,Vec3 b){return a.x==b.x&&a.y==b.y&&a.z==b.z;}
std::vector<std::uint32_t> indices(std::size_t n){std::vector<std::uint32_t> result;result.reserve(n);for(std::uint32_t i=0;i<n;++i)result.push_back(i);return result;}
}
Result list(std::span<const response::Triangle> triangles,std::span<const std::uint32_t> ids,Vec3 start,Vec3 end,float radius,const response::Filter& filter,std::optional<Vec3> initial){
    Result result;result.scratch=initial;float nearest{};bool unknown_selection{};
    if(!std::isfinite(radius)||radius<0){result.status=Status::invalid_radius;return result;}
    const auto point=[&](const response::Triangle& t,Vec3 finish){const auto p=trace::triangle(t,start,finish);if(p.written_point)result.scratch=p.written_point;return p.hit;};
    auto admitted=filter;admitted.dynamic_kind_gate=false; // Original617430 fourth argument is zero.
    for(const auto id:ids){if(id>=triangles.size())throw std::invalid_argument("Foreign native radius triangle");const auto& t=triangles[id];if(!response::admits(t.flags,admitted))continue;
        bool found=!equal(start,end)&&point(t,end);
        if(!found)found=point(t,add(mul(t.normal,-radius),end));
        if(!found)for(unsigned edge=0;edge<3;++edge)if(spatial::sphere_edge(t.vertices[edge],t.vertices[(edge+1)%3],{end,radius})){found=true;break;}
        if(!found)continue;
        ++result.contacts;
        if(!result.scratch){unknown_selection=true;continue;}
        const auto distance=length(sub(start,*result.scratch));
        if(result.hit&&nearest<=distance)continue;
        nearest=distance;result.hit=trace::Hit{*result.scratch,t.normal,(t.flags&0xffff0000u)|(1u<<(t.flags&15)),id};
    }
    if(unknown_selection){result.status=Status::uninitialized_point;result.hit.reset();}return result;
}
Result query(const response::Grid& grid,Vec3 start,Vec3 end,float radius,const response::Filter& filter,std::span<const response::Triangle> dynamic){
    Result result;if(!std::isfinite(radius)||radius<0){result.status=Status::invalid_radius;return result;}
    const auto samples=trace::sample(grid,start,end);if(samples.status==trace::SamplingStatus::capacity){result.status=Status::capacity;return result;}if(samples.status==trace::SamplingStatus::nonprogress){result.status=Status::nonprogress;return result;}
    const auto& h=grid.header();const auto quotient=(radius*2)/float(std::min(h.step_x,h.step_z));if(!std::isfinite(quotient)||double(quotient)>double(std::numeric_limits<int>::max()-2)){result.status=Status::invalid_radius;return result;}
    if(dynamic.size()>31)throw std::invalid_argument("Native dynamic radius triangle capacity exceeded");
    std::vector<std::span<const std::uint32_t>> lists;lists.reserve(samples.cells.size()+5);
    for(const auto cell:samples.cells)lists.push_back(grid.cell({float(h.origin_x)+(float(cell.column)+0.5f)*float(h.step_x),0,float(h.origin_z)+(float(cell.row)+0.5f)*float(h.step_z)}));
    const auto diameter=int(quotient)+2;Vec3 base=end;
    if(diameter==2){const auto x=std::trunc((end.x-float(h.origin_x))/float(h.step_x)),z=std::trunc((end.z-float(h.origin_z))/float(h.step_z));const auto quadrant=(end.x-float(h.origin_x)>=float(h.step_x/2)+x*float(h.step_x)?1u:0u)|(end.z-float(h.origin_z)>=float(h.step_z/2)+z*float(h.step_z)?2u:0u);constexpr std::array<std::array<float,2>,4> offsets{{{-1,-1},{0,-1},{-1,0},{0,0}}};base.x+=float(h.step_x)*offsets[quadrant][0];base.z+=float(h.step_z)*offsets[quadrant][1];}
    else{base.x-=float(diameter/2)*float(h.step_x);base.z-=float(diameter/2)*float(h.step_z);}
    for(unsigned x=0;x<2;++x)for(unsigned z=0;z<2;++z){auto p=base;p.x+=float(h.step_x*x);p.z+=float(h.step_z*z);if(grid.contains(p))lists.push_back(grid.cell(p));}
    for(const auto ids:lists){result=list(grid.triangles(),ids,start,end,radius,filter);if(result.contacts)return result;}
    return list(dynamic,indices(dynamic.size()),start,end,radius,filter);
}
}
