#include "regions.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_collision::regions {
namespace {
std::uint32_t word(std::span<const std::byte> b,std::size_t at){if(at>b.size()||4>b.size()-at)throw std::invalid_argument("Truncated authored-region resource");std::uint32_t value{};for(unsigned i=0;i<4;++i)value|=std::uint32_t(std::to_integer<std::uint8_t>(b[at+i]))<<(8*i);return value;}
Vec3 vector(Vertex v){return{float(v.x),float(v.y),float(v.z)};}
Vec3 sub(Vec3 a,Vec3 b){return{a.x-b.x,a.y-b.y,a.z-b.z};}
float dot(Vec3 a,Vec3 b){return(a.x*b.x+a.y*b.y)+a.z*b.z;}
Plane plane(Vertex a,Vertex b,Vertex c){const auto first=vector(a);const auto x=sub(first,vector(b)),y=sub(first,vector(c));auto normal=Vec3{x.y*y.z-x.z*y.y,x.z*y.x-x.x*y.z,x.x*y.y-x.y*y.x};const auto length=std::sqrt(dot(normal,normal));if(length==0)return{first,{},false};const auto reciprocal=1/length;normal={normal.x*reciprocal,normal.y*reciprocal,normal.z*reciprocal};return{first,normal,std::sqrt(dot(normal,normal))!=0};}
}
Region prepare(std::uint8_t priority,std::uint16_t selector,std::array<Vertex,8> vertices)noexcept{
    Region result;result.priority=priority;result.selector=selector;result.vertices=vertices;constexpr std::array<std::array<unsigned,3>,6> faces{{{{0,3,1}},{{0,1,4}},{{0,4,3}},{{6,7,5}},{{6,2,7}},{{6,5,2}}}};
    for(unsigned i=0;i<faces.size();++i){const auto face=faces[i];result.planes[i]=plane(vertices[face[0]],vertices[face[1]],vertices[face[2]]);}return result;
}
bool contains(const Region& region,Vec3 point)noexcept{point.y+=10;for(const auto& plane:region.planes)if(!plane.valid||!(dot(sub(point,plane.vertex),plane.normal)<=0))return false;return true;}
World World::import(std::span<const std::byte> bytes){
    World result;const auto count=word(bytes,0),auxiliary=word(bytes,4);if(count>32||auxiliary>4)throw std::invalid_argument("Authored-region count exceeds owned physical capacity");if(!count&&!auxiliary)return result;const auto table_end=8+std::size_t(count+auxiliary)*4;if(table_end>bytes.size())throw std::invalid_argument("Authored-region directory outside resource");
    result.regions_.reserve(count);for(unsigned i=0;i<count;++i){const auto at=word(bytes,8+4*i);if(at<table_end||at>bytes.size()||104>bytes.size()-at)throw std::invalid_argument("Authored region outside resource");std::array<Vertex,8> vertices;for(unsigned v=0;v<8;++v)vertices[v]={std::bit_cast<std::int32_t>(word(bytes,at+4+12*v)),std::bit_cast<std::int32_t>(word(bytes,at+8+12*v)),std::bit_cast<std::int32_t>(word(bytes,at+12+12*v))};result.regions_.push_back(prepare(std::uint8_t(word(bytes,at)),std::uint16_t(word(bytes,at+100)),vertices));}
    result.auxiliary_.reserve(auxiliary);for(unsigned i=0;i<auxiliary;++i){const auto at=word(bytes,8+4*(count+i));if(at<table_end||at>bytes.size()||28>bytes.size()-at)throw std::invalid_argument("Authored auxiliary record outside resource");result.auxiliary_.push_back({std::uint8_t(word(bytes,at)),std::uint8_t(word(bytes,at+20)),std::uint16_t(word(bytes,at+4)),std::uint16_t(word(bytes,at+24)),{std::bit_cast<float>(word(bytes,at+8)),std::bit_cast<float>(word(bytes,at+12)),std::bit_cast<float>(word(bytes,at+16))}});}
    const auto trailer=table_end+std::size_t(count)*104+std::size_t(auxiliary)*28;result.defaults_={std::uint16_t(word(bytes,trailer)),std::uint8_t(word(bytes,trailer+4)),std::uint8_t(word(bytes,trailer+12)),std::uint8_t(word(bytes,trailer+16)),word(bytes,trailer+8)|0x80000000u};return result;
}
std::uint16_t World::select(std::optional<Vec3> point)const noexcept{const Region* selected{};if(point)for(const auto& region:regions_)if(region.priority&&(region.flags&1)&&(!selected||region.priority>selected->priority)&&contains(region,*point))selected=&region;return selected?selected->selector:defaults_.selector;}
}
