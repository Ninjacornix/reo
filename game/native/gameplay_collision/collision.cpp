#include "collision.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <limits>
#include <stdexcept>

namespace reo::native::gameplay_collision {
namespace {
Vec3 sub(Vec3 a,Vec3 b){return{a.x-b.x,a.y-b.y,a.z-b.z};}
Vec3 mul(Vec3 a,float b){return{a.x*b,a.y*b,a.z*b};}
float dot(Vec3 a,Vec3 b){return(a.x*b.x+a.y*b.y)+a.z*b.z;}
float length(Vec3 a){return std::sqrt(dot(a,a));}
std::int32_t orientation(Point a,Point b,Point c){
    // Original SUBU/MULT low-word arithmetic, defined without signed overflow.
    const auto dx=std::uint32_t(b.x)-std::uint32_t(a.x),dz=std::uint32_t(b.z)-std::uint32_t(a.z);
    const auto px=std::uint32_t(c.x)-std::uint32_t(a.x),pz=std::uint32_t(c.z)-std::uint32_t(a.z);
    return std::bit_cast<std::int32_t>(dx*pz-dz*px);
}
unsigned triangle(Point a,Point b,Point c,Point p){
    const auto winding=orientation(a,b,c);
    if(!winding)return 0;
    const auto ab=orientation(a,b,p),bc=orientation(b,c,p),ca=orientation(c,a,p);
    if(winding<0)return ab<=0&&bc<=0&&ca<=0?1u:0u;
    return ab>=0&&bc>=0&&ca>=0?2u:0u;
}
bool object_admits(const Proxy& p,const ActorQuery& q){
    if(p.query_class==2 || p.object.mode==6)return false;
    const auto policy=p.object.policy;
    if(q.actor_class==0){
        if(policy>6 || !q.local)return false;
        if(policy>=1&&policy<=3&&!q.primary_owner)return false;
        if(policy>=4&&!q.secondary_owner)return false;
        if((policy==2||policy==5)&&q.character_id!=p.object.selected_id)return false;
        if((policy==3||policy==6)&&q.actor_id!=p.object.selected_id)return false;
        return true;
    }
    if(q.actor_class==1)return policy==0;
    if(q.actor_class==2)return policy==0||policy==7||(policy==8&&q.actor_id==p.object.selected_id);
    return true;
}
bool query_class_admits(const Proxy& p,const ActorQuery& q){
    const auto c=q.query_class;
    if(p.query_class==4)return c==0||c==2||c==4||c==5||c==6;
    if(p.query_class==2)return c==2&&p.content_id==q.selected_content;
    if(p.query_class==6)return(c==2||c==6)&&q.selected_content>=0x19e&&q.selected_content<0x1a2;
    return p.query_class==c;
}
std::uint32_t word(std::span<const std::byte> b,std::size_t at){
    if(at>b.size()||4>b.size()-at)throw std::invalid_argument("Truncated room proxy section");
    std::uint32_t r{};for(unsigned i=0;i<4;++i)r|=std::uint32_t(std::to_integer<unsigned char>(b[at+i]))<<(8*i);return r;
}
}
bool contains(std::span<const Point> polygon,Point p)noexcept{
    if(polygon.size()<3 || polygon.size()>128)return false;
    std::uint32_t sum{};
    for(std::size_t i=0;i+2<polygon.size();++i)sum+=std::bit_cast<std::uint32_t>(orientation(polygon[i],polygon[i+1],polygon[i+2]));
    const bool nonpositive=std::bit_cast<std::int32_t>(sum)<=0;
    std::uint8_t score{};
    for(std::size_t i=1;i+1<polygon.size();++i){
        const auto c=triangle(polygon[0],polygon[i],polygon[i+1],p);
        if(c)score=static_cast<std::uint8_t>(score+((c==(nonpositive?1u:2u))?1:-1));
    }
    return std::bit_cast<std::int8_t>(score)>0;
}
bool overlaps(const Quad& q,Point p,float radius)noexcept{
    if(contains(q,p))return true;
    const float squared=radius*radius;
    for(std::size_t i=0;i<q.size();++i){
        const auto a=q[i],b=q[(i+1)%q.size()];
        const float ax=static_cast<float>(a.x),az=static_cast<float>(a.z),bx=static_cast<float>(b.x),bz=static_cast<float>(b.z);
        const float px=static_cast<float>(p.x),pz=static_cast<float>(p.z),dx=bx-ax,dz=bz-az;
        // Original line projection divides by zero on a zero-length edge;
        // comparisons then fail. Endpoint tests still run below.
        const float left=ax*dx-dx*px;
        const float numerator=(az*dz+left)-dz*pz;
        const float denominator=-(dx*dx)-dz*dz;
        const float t=numerator/denominator;
        const float x=ax+t*dx,z=az+t*dz;
        const float ex=x-px,ez=z-pz;
        if(ex*ex+ez*ez<=squared && (x-ax)*(x-bx)+(z-az)*(z-bz)<0)return true;
        const float da=px-ax,ea=pz-az,db=px-bx,eb=pz-bz;
        if(da*da+ea*ea<squared || db*db+eb*eb<squared)return true;
    }
    return false;
}
bool admits_height(std::int32_t lower,std::int32_t upper,float y)noexcept{
    const float lo=static_cast<float>(lower),hi=static_cast<float>(upper);
    if(lo>y)return lo<=y+200.0f;
    if(lo==y)return true;
    return lo<y&&hi>=y;
}
std::optional<Point> integer_xz(Vec3 p)noexcept{
    // Owned CVT.W.S is fixed truncation, independent of host rounding mode.
    const double x=std::trunc(double(p.x)),z=std::trunc(double(p.z));
    constexpr auto lo=std::numeric_limits<std::int32_t>::min(),hi=std::numeric_limits<std::int32_t>::max();
    if(!std::isfinite(x)||!std::isfinite(z)||x<lo||x>hi||z<lo||z>hi)return{};
    return Point{static_cast<std::int32_t>(x),static_cast<std::int32_t>(z)};
}
Vec3 forward_probe(Vec3 p,std::uint16_t heading,float offset)noexcept{
    const float angle=float(heading)*0.0000958738019107841f;
    return{p.x+offset*std::sin(angle),p.y,p.z+offset*std::cos(angle)};
}
World::World(std::uint64_t generation,std::vector<Proxy> proxies):generation_(generation),proxies_(std::move(proxies)){
    if(!generation_ || proxies_.size()>128)throw std::invalid_argument("Room proxy ownership requires generation and bounded capacity");
}
const Proxy* World::get(ProxyId id)const noexcept{
    return id.room_generation==generation_&&id.index<proxies_.size()?&proxies_[id.index]:nullptr;
}
std::optional<Selection> World::select(const ActorQuery& q,std::span<const ProxyState> state)const noexcept{
    if(state.size()!=proxies_.size())return{};
    const auto point=integer_xz(q.point),actor=integer_xz(q.position);
    if(!point||!actor)return{};
    std::optional<Selection> best;unsigned priority=256;
    for(std::size_t remaining=proxies_.size();remaining;--remaining){
        const auto i=remaining-1;
        const auto& p=proxies_[i];
        if(!p.active||p.busy||!query_class_admits(p,q))continue;
        if(p.kind==1&&!object_admits(p,q))continue;
        if(p.kind==2&&!p.bypass_slot_guard&&!state[i].slot_idle)continue;
        if(p.kind==0x81&&!state[i].grid_span_admitted)continue;
        const bool geometry=p.kind==0x80||p.kind==0x81?overlaps(p.bounds,*point,q.radius):contains(p.bounds,p.kind==0x85?*actor:*point);
        if(!geometry||!admits_height(p.lower,p.upper,q.point.y))continue;
        if(p.priority<priority){priority=p.priority;best=Selection{{generation_,static_cast<std::uint32_t>(i)},q.actor_id,q.query_class};}
    }
    return best;
}
std::vector<ImportedProxy> import_proxy_section(std::span<const std::byte> bytes,ImportContext context){
    const auto count=word(bytes,4);
    if(count>128||bytes.size()<8+std::size_t(count)*4)throw std::invalid_argument("Invalid room proxy count");
    constexpr std::array<std::uint8_t,14> priority{2,2,2,1,1,5,2,2,4,4,2,4,1,2};
    std::vector<ImportedProxy> result;result.reserve(count);
    for(std::uint32_t i=0;i<count;++i){
        const auto at=word(bytes,8+4*i);
        if(at<8+4*count||at>bytes.size()||0xb0>bytes.size()-at)throw std::invalid_argument("Invalid room proxy extent");
        const auto record=bytes.subspan(at,0xb0);const auto kind=word(record,0),event=word(record,4);
        if(kind>=priority.size()||event>255)throw std::invalid_argument("Unsupported imported room proxy type");
        ImportedProxy value;auto& p=value.proxy;p.kind=static_cast<std::uint8_t>(kind);p.query_class=static_cast<std::uint8_t>(event);p.priority=priority[kind];
        for(unsigned k=0;k<4;++k)p.bounds[k]={std::bit_cast<std::int32_t>(word(record,8+8*k)),std::bit_cast<std::int32_t>(word(record,12+8*k))};
        p.lower=std::bit_cast<std::int32_t>(word(record,0x28));p.upper=std::bit_cast<std::int32_t>(word(record,0x2c));p.identifier=word(record,0x30);p.content_id=word(record,0x38);
        p.bypass_slot_guard=word(record,0x48)==2;
        p.active=kind==0||kind==1||kind==2||kind==6||kind==7;
        if(kind==2&&context.scenario==1&&context.room==1)p.active=false;
        if(kind==0)value.door=Door{p.identifier,word(record,0x34),word(record,0x38),static_cast<std::uint16_t>(word(record,0x48)),word(record,0x50)};
        if(kind==1){p.object.mode=std::bit_cast<std::int32_t>(word(record,0x5c));p.object.policy=static_cast<std::uint8_t>(word(record,0x6c));p.object.selected_id=word(record,0x70);}
        result.push_back(value);
    }
    return result;
}
std::optional<Contact> sphere_contact(Sphere a,Sphere b)noexcept{
    const auto delta=sub(a.center,b.center);const float distance=length(delta),radius=a.radius+b.radius;
    if(distance>radius)return{};
    if(distance<=0.001f)return Contact{};
    return Contact{mul(delta,(radius-distance)/distance)};
}
bool separate(Body& a,Body& b,Vec3 correction,bool limited,bool fast)noexcept{
    if(limited){if(a.separation_count>=(fast?60:120))return false;++a.separation_count;++b.separation_count;}
    float first{},second{};
    if(a.priority<b.priority)first=1;
    else if(b.priority<a.priority)second=1;
    else{const bool moving_a=length(sub(a.position,a.previous))!=0,moving_b=length(sub(b.position,b.previous))!=0;
        if(moving_a==moving_b)first=second=0.5f;else if(moving_a)first=1;else second=1;}
    a.position.x+=correction.x*first;a.position.z+=correction.z*first;a.accumulated.x+=correction.x*first;a.accumulated.z+=correction.z*first;
    b.position.x-=correction.x*second;b.position.z-=correction.z*second;b.accumulated.x-=correction.x*second;b.accumulated.z-=correction.z*second;
    return true;
}
void accumulate(Extrema& e,Vec3 v)noexcept{
    const auto one=[](float v,float& p,float& n){if(v>=0){if(v>p)p=v;}else if(v<n)n=v;};
    one(v.x,e.positive.x,e.negative.x);one(v.y,e.positive.y,e.negative.y);one(v.z,e.positive.z,e.negative.z);
}
Vec3 combine(const Extrema& e)noexcept{
    const auto one=[](float p,float n){return p!=0&&n!=0?(p+n)/2:p+n;};
    return{one(e.positive.x,e.negative.x),one(e.positive.y,e.negative.y),one(e.positive.z,e.negative.z)};
}
}
