#include "actors.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_collision::actors {
namespace {
Vec3 add(Vec3 a,Vec3 b){return{a.x+b.x,a.y+b.y,a.z+b.z};}
Vec3 sub(Vec3 a,Vec3 b){return{a.x-b.x,a.y-b.y,a.z-b.z};}
Vec3 mul(Vec3 a,float b){return{a.x*b,a.y*b,a.z*b};}
float dot(Vec3 a,Vec3 b){return(a.x*b.x+a.y*b.y)+a.z*b.z;}
float length(Vec3 a){return std::sqrt(dot(a,a));}
std::uint32_t word(std::span<const std::byte> b,std::size_t at){if(at>b.size()||4>b.size()-at)throw std::invalid_argument("Truncated collision shape");std::uint32_t r{};for(unsigned i=0;i<4;++i)r|=std::uint32_t(std::to_integer<unsigned char>(b[at+i]))<<(8*i);return r;}
Vec3 vector(std::span<const std::byte> b,std::size_t at){return{std::bit_cast<float>(word(b,at)),std::bit_cast<float>(word(b,at+4)),std::bit_cast<float>(word(b,at+8))};}
Vec3 center(const Actor& actor,const Center& c){
    if(!c.first_joint&&!c.second_joint)return actor.position;
    const auto transformed=[&](std::uint16_t index,Vec3 offset){if(index>=actor.joints.size())throw std::invalid_argument("Native collision joint is not in retained pose");return actor.joints[index].point(offset);};
    if(!c.first_joint)return transformed(*c.second_joint,c.second_offset);
    if(!c.second_joint)return transformed(*c.first_joint,c.first_offset);
    return add(mul(add(transformed(*c.first_joint,c.first_offset),transformed(*c.second_joint,c.second_offset)),0.5f),sub(actor.position,actor.previous));
}
Vec3 midpoint(const Shape& shape){if(const auto* sphere=std::get_if<Sphere>(&shape))return sphere->center;return std::get<response::Capsule>(shape).midpoint;}
float bound(const Shape& shape){if(const auto* sphere=std::get_if<Sphere>(&shape))return sphere->radius;return std::get<response::Capsule>(shape).bound_radius;}
std::optional<Contact> contact(const Shape& current,const Shape& target){
    if(const auto* a=std::get_if<Sphere>(&current)){
        if(const auto* b=std::get_if<Sphere>(&target))return sphere_contact(*a,*b);
        auto result=response::capsule_sphere(std::get<response::Capsule>(target),*a);if(result)result->correction=mul(result->correction,-1);return result;
    }
    if(const auto* b=std::get_if<Sphere>(&target))return response::capsule_sphere(std::get<response::Capsule>(current),*b);
    // Original capsule/capsule is invoked with the selected target FIRST.
    return response::capsules(std::get<response::Capsule>(target),std::get<response::Capsule>(current));
}
Actor* find(std::span<Actor> actors,EntityId id){for(auto& actor:actors)if(actor.id==id)return &actor;return nullptr;}
}
Vec3 Basis::direction(Vec3 p)const noexcept{return{(x.x*p.x+y.x*p.y)+z.x*p.z,(x.y*p.x+y.y*p.y)+z.y*p.z,(x.z*p.x+y.z*p.y)+z.z*p.z};}
Vec3 Basis::point(Vec3 p)const noexcept{return add(direction(p),translation);}
ShapeDefinition import_shape(std::span<const std::byte> bytes){
    if(bytes.size()<56)throw std::invalid_argument("Collision shape requires complete owned descriptor");
    const auto header=word(bytes,0);const auto kind=std::bit_cast<std::int16_t>(std::uint16_t(header));
    if(kind!=0&&kind!=1)throw std::invalid_argument("Unknown collision shape kind");
    ShapeDefinition result;result.kind=kind==0?ShapeKind::sphere:ShapeKind::capsule;result.radius=float(std::bit_cast<std::int16_t>(std::uint16_t(header>>16)));
    const auto joint=[&](unsigned at)->std::optional<std::uint16_t>{const auto id=std::to_integer<std::uint8_t>(bytes[at]);if(id==255)return{};return id;};
    result.first={joint(4),joint(5),vector(bytes,8),vector(bytes,20)};result.second={joint(6),joint(7),vector(bytes,32),vector(bytes,44)};return result;
}
Shape build(const Actor& actor,const ShapeDefinition& definition,Vec3 accumulated){
    auto first=center(actor,definition.first);first.x+=accumulated.x;first.z+=accumulated.z;
    if(definition.kind==ShapeKind::sphere)return Sphere{first,definition.radius};
    auto second=center(actor,definition.second);second.x+=accumulated.x;second.z+=accumulated.z;
    return response::make_capsule(first,second,definition.radius);
}
Summary summarize(const Shape& shape)noexcept{
    const auto mid=midpoint(shape);Summary result;result.x=mid.x;result.z=mid.z;
    if(const auto* capsule=std::get_if<response::Capsule>(&shape)){
        const auto d=sub(capsule->start,mid);const auto distance=std::sqrt(d.x*d.x+d.z*d.z);
        if(std::isfinite(distance)&&double(distance)<4294967296.0)result.half_length=std::uint16_t(std::uint32_t(std::trunc(double(distance))));else result.half_length=65535;



    }
    auto x=0.0f,z=0.0f;if(const auto* capsule=std::get_if<response::Capsule>(&shape)){x=capsule->end.x-capsule->start.x;z=capsule->end.z-capsule->start.z;}if(x==0)x=0.00009999999747378752f;
    float degrees=(180.0f*std::atan2(x,z))/3.1415927410125732f;if(degrees<0)degrees+=360;
    result.heading=std::uint16_t(std::uint32_t(std::trunc(182.04444885253906f*degrees)));
    return result;
}
bool Registry::add(Registration entry){if(!entry.actor||count_==registrations_.size())return false;registrations_[count_++]=std::move(entry);return true;}
SolveReport Registry::solve(std::span<Actor> actors,bool limited,bool fast){
    // Validate all retained actor identities/poses before publishing mutations.
    for(std::size_t i=0;i<count_;++i){const auto* actor=find(actors,registrations_[i].actor);if(!actor)throw std::invalid_argument("Stale native collision actor");if(actor->definition&&actor->definition->radius>0)(void)build(*actor,*actor->definition);}
    for(std::size_t i=0;i<actors.size();++i)for(std::size_t j=0;j<i;++j)if(actors[i].id&&actors[i].id==actors[j].id)throw std::invalid_argument("Ambiguous native actor identity");
    std::array<Vec3,32> accumulated{};SolveReport report;
    for(std::size_t i=0;i<count_;++i){auto* actor=find(actors,registrations_[i].actor);if(actor->actor_class==0)actor->contact=false;}
    for(std::size_t i=0;i<count_;++i){const auto& entry=registrations_[i];auto& actor=*find(actors,entry.actor);if(!actor.definition||actor.definition->radius<=0)continue;
        ++report.visited;const auto shape=build(actor,*actor.definition,accumulated[i]);actor.summary=summarize(shape);if(!entry.source_mask)continue;
        std::optional<std::size_t> selected;float overlap=0.0010000000474974513f;
        for(std::size_t j=0;j<count_;++j){const auto& other=registrations_[j];if(!(entry.source_mask&other.collision_class)||other.actor==entry.actor)continue;
            auto& target=*find(actors,other.actor);if(!target.definition||target.definition->radius<=0)continue;
            ++report.candidates;const auto candidate=build(target,*target.definition);const auto delta=sub(midpoint(candidate),midpoint(shape));
            auto combined=bound(shape)+target.definition->radius;
            if(const auto* capsule=std::get_if<response::Capsule>(&candidate))combined+=length(sub(capsule->start,capsule->midpoint));
            const auto penetration=combined-length(delta);
            if(!(penetration>overlap))continue;
            if(entry.collision_class==1&&dot(actor.candidate_direction,delta)<0)continue;
            overlap=penetration;selected=j;
        }
        if(!selected)continue;
        const auto j=*selected;auto& target=*find(actors,registrations_[j].actor);const auto target_shape=build(target,*target.definition,accumulated[j]);const auto collision=contact(shape,target_shape);
        if(collision){++report.contacts;if(actor.actor_class==0){actor.contact=true;actor.peer=target.id;}if(target.actor_class==0){target.contact=true;target.peer=actor.id;}}
        if(entry.collision_class==1||entry.collision_class==2){
            if(!collision){actor.separation_count=0;continue;}
            Body first{actor.position,actor.previous,accumulated[i],actor.priority,actor.separation_count},second{target.position,target.previous,accumulated[j],target.priority,target.separation_count};
            (void)separate(first,second,collision->correction,limited,fast);
            actor.position=first.position;target.position=second.position;accumulated[i]=first.accumulated;accumulated[j]=second.accumulated;actor.separation_count=first.separation_count;target.separation_count=second.separation_count;
        }else if(collision){actor.position.x=actor.previous.x;actor.position.z=actor.previous.z;}
    }
    clear();return report;
}
bool AuxiliaryBoundary::set(std::uint8_t kind,EntityId id)noexcept{if(kind!=0||!id)return false;owner_=std::move(id);return true;}
void AuxiliaryBoundary::apply(std::span<Actor> actors,bool offline,std::uint16_t room,EntityId selected)const noexcept{
    if(!owner_)return;
    const auto* boundary=find(actors,owner_);if(!boundary)return;
    for(auto& actor:actors){if(offline?actor.room!=room:actor.id!=selected)continue;const float maximum=boundary->position.z-200;if(actor.position.z>maximum&&actor.position.y<-870){actor.position.z=maximum;actor.boundary_clamped=true;}}
}
}
