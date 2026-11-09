#include "response.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <limits>
#include <map>
#include <stdexcept>
namespace reo::native::gameplay_collision::response {
namespace {
constexpr float epsilon=0.0010000000474974513f;
Vec3 add(Vec3 a,Vec3 b){return{a.x+b.x,a.y+b.y,a.z+b.z};}
Vec3 sub(Vec3 a,Vec3 b){return{a.x-b.x,a.y-b.y,a.z-b.z};}
Vec3 mul(Vec3 a,float b){return{a.x*b,a.y*b,a.z*b};}
float dot(Vec3 a,Vec3 b){return(a.x*b.x+a.y*b.y)+a.z*b.z;}
Vec3 cross(Vec3 a,Vec3 b){return{a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};}
float length(Vec3 a){return std::sqrt(dot(a,a));}
Vec3 normalized(Vec3 a){const auto distance=length(a);return distance==0?Vec3{}:mul(a,1.0f/distance);}
Vec3 correction(Vec3 delta,float radius,float distance){return distance==0?Vec3{}:mul(delta,(radius-distance)/std::max(distance,epsilon));}
Vec3 clamped(Vec3 start,Vec3 end,Vec3 unit,Vec3 point,float distance){
    const auto amount=dot(sub(point,start),unit);
    if(amount<0)return start;
    if(amount>distance)return end;
    return add(start,mul(unit,amount));
}
std::optional<Contact> endpoint(Vec3 delta,float sum){const auto distance=length(delta);if(distance>sum)return{};return Contact{correction(delta,sum,distance)};}
float orientation(Vec3 a,Vec3 b,Vec3 c){return(b.x-a.x)*(c.z-a.z)-(b.z-a.z)*(c.x-a.x);}
bool triangle_contains(const std::array<Vec3,3>& v,Vec3 p){
    const float area=orientation(v[0],v[1],v[2]);
    if(area==0||!std::isfinite(area)||(area>0&&std::trunc(area)==0))return false;
    const float a=orientation(v[0],v[1],p),b=orientation(v[1],v[2],p),c=orientation(v[2],v[0],p);
    return area<0?(a<=0&&b<=0&&c<=0):(a>=0&&b>=0&&c>=0);
}
std::uint32_t word(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||4>bytes.size()-at)throw std::invalid_argument("Truncated native collision input");
    std::uint32_t value{};for(unsigned i=0;i<4;++i)value|=std::uint32_t(std::to_integer<unsigned char>(bytes[at+i]))<<(8*i);return value;
}
float real(std::span<const std::byte> bytes,std::size_t at){return std::bit_cast<float>(word(bytes,at));}
Vec3 vector(std::span<const std::byte> bytes,std::size_t at){return{real(bytes,at),real(bytes,at+4),real(bytes,at+8)};}
}
Capsule make_capsule(Vec3 a,Vec3 b,float radius)noexcept{
    const auto midpoint=mul(add(a,b),0.5f);
    return{a,b,radius,sub(b,a),midpoint,radius+length(sub(a,midpoint))};
}
std::optional<Contact> capsule_sphere(Capsule capsule,Sphere sphere)noexcept{
    const auto delta=sub(capsule.start,sphere.center);
    const auto normal=normalized(cross(capsule.direction,cross(capsule.direction,delta)));
    const auto sum=capsule.radius+sphere.radius,separation=dot(normal,delta);
    if(std::abs(separation)>sum)return{};
    const auto projected=add(sphere.center,mul(normal,separation));
    if(dot(sub(projected,capsule.start),capsule.direction)<0){
        const auto distance=length(delta);if(distance>sum)return{};
        return Contact{mul(normalized(delta),sum-distance)};
    }
    const auto reverse=mul(capsule.direction,-1);
    if(dot(sub(projected,capsule.end),reverse)<0){
        const auto end_delta=sub(capsule.end,sphere.center);const auto distance=length(end_delta);if(distance>sum)return{};
        return Contact{mul(normalized(end_delta),sum-distance)};
    }
    return Contact{mul(normal,separation<0?-sum-separation:sum-separation)};
}
std::optional<Contact> capsules(Capsule a,Capsule b)noexcept{
    const auto length_a=std::max((a.bound_radius-a.radius)*2,epsilon),length_b=std::max((b.bound_radius-b.radius)*2,epsilon);
    const Vec3 unit_a{a.direction.x/length_a,a.direction.y/length_a,a.direction.z/length_a};
    const Vec3 unit_b{b.direction.x/length_b,b.direction.y/length_b,b.direction.z/length_b};
    const auto cosine=dot(unit_a,unit_b),sum=a.radius+b.radius;
    const auto delta=sub(b.start,a.start);
    if(1.0f-std::abs(cosine)<epsilon){
        const auto amount=dot(delta,unit_a),squared=dot(delta,delta)-amount*amount;
        if(squared<0)return{};
        const auto distance=std::sqrt(squared);if(sum<distance)return{};
        Vec3 normal;
        if(distance<epsilon){
            auto other=unit_a;other.x+=5;normal=cross(unit_a,other);
            if(std::abs(normal.x)<epsilon&&std::abs(normal.y)<epsilon&&std::abs(normal.z)<epsilon){other.y+=5;normal=cross(unit_a,other);}
            normal=mul(normalized(normal),sum);
        }else normal=mul(sub(b.start,add(a.start,mul(unit_a,amount))),(sum-distance)/distance);
        if(amount<0){
            const auto to_end=sub(b.end,a.start);const auto projected=dot(to_end,unit_a);
            if(projected>=0)return Contact{normal};
            return endpoint(amount<projected?to_end:delta,sum);
        }
        if(amount<=length_b)return Contact{normal};
        const auto to_end=sub(a.end,b.start);const auto projected=dot(to_end,unit_b);
        if(projected<=length_b)return Contact{normal};
        const auto distance_to_end=std::sqrt(amount<projected?distance*distance+amount*amount:projected*projected+distance*distance);
        if(distance_to_end>sum)return{};
        const auto chosen=amount<projected?delta:to_end;
        return Contact{distance_to_end==0?Vec3{}:mul(chosen,(sum-distance_to_end)/distance_to_end)};
    }
    const auto da=dot(delta,unit_a),db=dot(delta,unit_b),denominator=1.0f-cosine*cosine;
    const auto along_b=(da*cosine-db)/denominator,along_a=(da-db*cosine)/denominator;
    const auto classify=[](float position,float distance){return position<0?0:position<=distance?1:2;};
    const int region_a=classify(along_a,length_a),region_b=classify(along_b,length_b);
    if(region_a==1&&region_b==1){
        const auto closest=sub(add(b.start,mul(unit_b,along_b)),add(a.start,mul(unit_a,along_a)));
        const auto distance=length(closest);if(distance>sum)return{};
        return Contact{distance<epsilon?mul(cross(unit_a,unit_b),sum):correction(closest,sum,distance)};
    }
    const auto b_endpoint=region_b==0?b.start:b.end;
    const auto candidate_b=sub(b_endpoint,clamped(a.start,a.end,unit_a,b_endpoint,length_a));
    if(region_a==1)return endpoint(candidate_b,sum);
    const auto a_endpoint=region_a==0?a.start:a.end;
    const auto candidate_a=sub(clamped(b.start,b.end,unit_b,a_endpoint,length_b),a_endpoint);
    if(region_b==1)return endpoint(candidate_a,sum);
    return endpoint(length(candidate_a)<length(candidate_b)?candidate_a:candidate_b,sum);
}
Floor floor_at(Vec3 p,std::span<const Triangle> triangles,std::uint8_t required)noexcept{
    Floor result;result.height=p.y;
    for(std::size_t i=0;i<triangles.size();++i){const auto& t=triangles[i];
        if((required!=255&&std::uint8_t(t.flags)!=required)||(t.flags&0x80)||t.normal.y<=0||!triangle_contains(t.vertices,p))continue;
        const auto y=-((t.normal.x*p.x+t.normal.z*p.z)+t.plane_d)/t.normal.y;
        if(y<p.y+100&&(!result.triangle||result.height<y))result={y,t.normal,std::uint8_t(t.flags),std::uint8_t(t.flags>>8),std::uint16_t(t.flags>>16),std::uint32_t(i)};
    }
    return result;
}
bool admits(std::uint32_t flags,const Filter& filter)noexcept{
    const auto type=std::uint8_t(flags);const auto high=flags&0xffff0000u;
    if(type>=16||!(filter.include&(1u<<type))||!(high&filter.include))return false;
    if((filter.exclude&(1u<<type))||(high&filter.exclude)||(high&filter.disabled))return false;
    if(type==1){const auto& slot=filter.slots[(flags>>24)&15];
        if(filter.dynamic_kind_gate&&slot.kind!=2)return true;
        if(slot.state==2&&!(flags&0x400000u))return false;
    }
    return true;
}
Grid Grid::import(std::span<const std::byte> bytes){
    Grid result;auto& h=result.header_;h={word(bytes,8),word(bytes,12),word(bytes,16),word(bytes,20),word(bytes,24),word(bytes,28)};
    if(!h.step_x||!h.step_z||!h.columns||!h.rows||std::uint64_t(h.columns)*h.rows>1048576)throw std::invalid_argument("Invalid collision grid dimensions");
    const auto cells=std::size_t(h.columns)*h.rows;const auto directory=std::uint64_t(word(bytes,32))+8,records=std::uint64_t(word(bytes,36))+8;
    if(directory>bytes.size()||cells>(bytes.size()-directory)/4||records>bytes.size())throw std::invalid_argument("Invalid collision grid directory");
    result.cells_.resize(cells);std::map<std::uint32_t,std::uint32_t> imported;
    for(std::size_t i=0;i<cells;++i){auto cursor=std::uint64_t(word(bytes,std::size_t(directory)+4*i))+8;
        for(;;cursor+=4){const auto relative=word(bytes,std::size_t(cursor));if(relative==0xffffffffu)break;
            const auto at=records+relative;if(at>bytes.size()||56>bytes.size()-at)throw std::invalid_argument("Invalid collision triangle extent");
            auto found=imported.find(relative);std::uint32_t index;
            if(found==imported.end()){index=std::uint32_t(result.triangles_.size());const auto offset=std::size_t(at);
                result.triangles_.push_back({word(bytes,offset),{vector(bytes,offset+4),vector(bytes,offset+16),vector(bytes,offset+28)},vector(bytes,offset+40),real(bytes,offset+52)});imported.emplace(relative,index);
            }else index=found->second;
            result.cells_[i].push_back(index);
        }
    }
    return result;
}
bool Grid::contains(Vec3 p)const noexcept{
    const auto& h=header_;return p.x>=float(h.origin_x)&&p.x<float(h.origin_x+h.step_x*h.columns)&&p.z>=float(h.origin_z)&&p.z<float(h.origin_z+h.step_z*h.rows);
}
std::span<const std::uint32_t> Grid::cell(Vec3 p)const noexcept{
    if(!contains(p))return{};
    const auto x=std::uint32_t((p.x-float(header_.origin_x))/float(header_.step_x)),z=std::uint32_t((p.z-float(header_.origin_z))/float(header_.step_z));
    if(x>=header_.columns||z>=header_.rows)return{};
    return cells_[std::size_t(x)*header_.rows+z];
}
Floor Grid::floor(Vec3 p,std::uint8_t required)const noexcept{
    Floor result;result.height=p.y;
    for(const auto index:cell(p)){const auto candidate=floor_at(p,std::span(triangles_).subspan(index,1),required);
        if(candidate.triangle&&(!result.triangle||result.height<candidate.height)){result=candidate;result.triangle=index;}}
    return result;
}
}
