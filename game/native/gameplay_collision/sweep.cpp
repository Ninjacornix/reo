#include "sweep.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
namespace reo::native::gameplay_collision::sweep {
namespace {
constexpr float epsilon=0.0010000000474974513f;
Vec3 add(Vec3 a,Vec3 b){return{a.x+b.x,a.y+b.y,a.z+b.z};}
Vec3 sub(Vec3 a,Vec3 b){return{a.x-b.x,a.y-b.y,a.z-b.z};}
Vec3 mul(Vec3 a,float b){return{a.x*b,a.y*b,a.z*b};}
float dot(Vec3 a,Vec3 b){return(a.x*b.x+a.y*b.y)+a.z*b.z;}
float length(Vec3 a){return std::sqrt(dot(a,a));}
Vec3 normal(Vec3 a){const float l=length(a);return l==0?Vec3{}:mul(a,1.0f/l);}
Vec3 cross(Vec3 a,Vec3 b){return{a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};}
bool equal(Vec3 a,Vec3 b){return a.x==b.x&&a.y==b.y&&a.z==b.z;}
bool inside(Vec3 p,const Triangle& t){
    for(unsigned i=0;i<3;++i){const auto a=t.vertices[i],b=t.vertices[(i+1)%3];
        if(dot(normal(cross(sub(b,a),sub(p,a))),t.normal)<0)return false;}
    return true;
}
Vec3 cleaned(Vec3 n){if(std::abs(n.x)<epsilon)n.x=0;if(std::abs(n.y)<epsilon)n.y=0;if(std::abs(n.z)<epsilon)n.z=0;return n;}
std::optional<Vec3> correction(const StoredContact& c,float radius){
    Vec3 delta;
    if(c.kind==Kind::edge){const auto reference=c.side==0?c.start:c.plane_point;
        delta=sub(add(c.point,mul(normal(sub(reference,c.point)),radius)),c.start);
        if(length(delta)==0)return{};
    }else delta=sub(add(c.point,mul(c.triangle.normal,radius)),c.start);
    return mul(normal(delta),length(delta));
}
Vec3 capped(Vec3 v,float movement){const auto distance=length(v);const auto limit=movement==0?distance:std::min(distance,1.8f*movement);return mul(normal(v),limit);}
bool horizontal(const Triangle& t){return t.normal.y==1||t.normal.y==-1;}
std::optional<unsigned> unshared_vertex(const Triangle& a,const Triangle& b){
    std::array<unsigned,3> shared{};unsigned count{};
    for(auto v:a.vertices)for(unsigned i=0;i<3;++i)if(equal(v,b.vertices[i])){shared[count++]=i;break;}
    if(count<2)return{};
    for(unsigned i=0;i<3;++i)if(i!=shared[0]&&i!=shared[1])return i;
    return{};
}
}
Input input(Vec3 start,Vec3 end,float radius)noexcept{return{start,end,radius,length(sub(start,end))};}
bool Contacts::collect(const Triangle& t)noexcept{
    const auto start_distance=dot(sub(input_.start,t.vertices[0]),t.normal),end_distance=dot(sub(input_.end,t.vertices[0]),t.normal);
    std::uint8_t side=start_distance<=0?1:0;Vec3 projected;
    if(std::abs(start_distance)<input_.radius)projected=sub(input_.start,mul(t.normal,start_distance));
    else{
        const unsigned crossing=(start_distance>=0?1u:0u)|(end_distance>=0?2u:0u);
        if(crossing==0||crossing==3)return false;
        const auto direction=crossing==2?sub(input_.end,input_.start):sub(input_.start,input_.end);
        const auto denominator=dot(direction,t.normal);
        if(denominator==0){status_=Status::indeterminate_projection;return false;}
        const auto anchor=crossing==2?input_.end:input_.start;
        const auto distance=crossing==2?end_distance:start_distance;
        projected=sub(anchor,mul(direction,distance/denominator));side|=2;
    }
    if(!(end_distance>0))return false;
    StoredContact record;record.triangle=t;record.triangle.normal=cleaned(t.normal);record.start=input_.start;record.side=side;record.point=projected;record.plane_point=projected;
    if(!inside(projected,t)){
        record.kind=Kind::edge;const auto source=(side&2)?projected:input_.start;float nearest=8000;Vec3 closest;
        for(unsigned i=0;i<3;++i){const auto a=t.vertices[i],b=t.vertices[(i+1)%3],unit=normal(sub(b,a));
            const auto before=dot(sub(source,a),unit),after=dot(sub(source,b),unit);
            const unsigned flags=(before<0?1u:0u)|(after>0?2u:0u);if(flags==3)return false;
            const auto point=flags==2?b:flags==1?a:add(b,mul(unit,after));const auto distance=length(sub(source,point));
            if(distance<nearest){nearest=distance;closest=point;}
        }
        if(!(nearest<input_.radius)||count_==records_.size())return false;
        record.point=closest;
        if(nearest<10000){reported_point_=projected;reported_normal_=t.normal;}
    }else{
        if(count_==records_.size())return false;
        if(length(sub(input_.start,projected))>10000){reported_point_=projected;reported_normal_=t.normal;}
    }
    records_[count_++]=record;return true;
}
Resolution Contacts::resolve(Vec3 initial)const noexcept{
    Resolution result;result.correction=initial;result.contact_count=count_;result.status=status_;
    if(!count_)return result;
    if(count_==1){if(const auto value=correction(records_[0],input_.radius)){result.correction=add(initial,capped(*value,input_.movement_length));result.selected[result.selected_count++]=0;}return result;}
    std::array<std::uint8_t,6> faces{},edges{};unsigned face_count{},edge_count{};
    for(unsigned i=0;i<count_;++i){if(records_[i].kind==Kind::face)faces[face_count++]=std::uint8_t(i);else edges[edge_count++]=std::uint8_t(i);}
    struct Exclusion{std::uint8_t edge,type,source_face;};std::array<Exclusion,64> excluded{};unsigned excluded_count{};
    const auto exclude=[&](std::uint8_t edge,std::uint8_t type,std::uint8_t source_face=255){
        if(excluded_count==excluded.size()){result.status=Status::original_exclusion_overflow;return;}
        // Original exclusion scratch has eight entries. Native ownership stays
        // bounded and safe, but overflowing the original scratch has no stable
        // result with which a reconstructed game rule can be compared.
        if(excluded_count>=8&&result.status==Status::ok)result.status=Status::original_exclusion_overflow;
        excluded[excluded_count++]={edge,type,source_face};
    };
    const auto is_excluded=[&](std::uint8_t edge){for(unsigned i=0;i<excluded_count;++i)if(excluded[i].edge==edge)return true;return false;};
    for(unsigned f=0;f<face_count;++f)for(unsigned e=0;e<edge_count;++e){
        const auto& a=records_[faces[f]].triangle;const auto& b=records_[edges[e]].triangle;
        if(equal(a.normal,b.normal))exclude(edges[e],1,faces[f]);
        else if(!horizontal(a)&&!horizontal(b)){if(const auto index=unshared_vertex(a,b))if(dot(sub(b.vertices[*index],a.vertices[0]),a.normal)<=0)exclude(edges[e],2);}
    }
    for(unsigned e=0;e+1<edge_count;++e){if(is_excluded(edges[e]))continue;
        for(unsigned other=1;other<edge_count;++other){if(edges[e]!=edges[other]&&!is_excluded(edges[other])&&equal(records_[edges[e]].point,records_[edges[other]].point))exclude(edges[other],3);}}
    if(excluded_count&&excluded_count<edge_count){
        for(unsigned i=0;i<excluded_count;++i){if(excluded[i].type!=1)continue;
            const auto source=excluded[i].edge;const auto& a=records_[source].triangle;
            for(unsigned e=0;e<edge_count;++e){if(edges[e]==source)continue;const auto& b=records_[edges[e]].triangle;
                if(horizontal(a)||horizontal(b))continue;
                if(const auto index=unshared_vertex(a,b)){
                    // Defined original face-list indexing remains unchanged.
                    // Where the original reads an uninitialized face slot,
                    // retain the actual face that created this exclusion.
                    const auto face_id=i<face_count?faces[i]:excluded[i].source_face;
                    if(i>=face_count&&result.status==Status::ok)result.status=Status::source_face_recovered;
                    const auto& face=records_[face_id].triangle;
                    if(dot(sub(b.vertices[*index],face.vertices[0]),face.normal)<=0)exclude(edges[e],2);
                }
            }
        }
    }
    Extrema extrema;
    const auto include=[&](std::uint8_t index){if(const auto value=correction(records_[index],input_.radius)){accumulate(extrema,*value);result.selected[result.selected_count++]=index;}};
    for(unsigned i=0;i<face_count;++i)include(faces[i]);
    for(unsigned i=0;i<edge_count;++i)if(!is_excluded(edges[i]))include(edges[i]);
    result.correction=add(initial,capped(combine(extrema),input_.movement_length));return result;
}
Result query(const response::Grid& grid,Input input,const response::Filter& filter,std::span<const Triangle> dynamic){
    if(dynamic.size()>31)throw std::invalid_argument("Native dynamic triangle capacity exceeded");
    Result result;if(!grid.contains(input.start))return result;result.inside_grid=true;Contacts contacts(input);
    const auto& h=grid.header();const auto raw_diameter=(input.radius*2)/float(std::min(h.step_x,h.step_z));
    if(!std::isfinite(raw_diameter)||raw_diameter<0||double(raw_diameter)>double(std::numeric_limits<int>::max()-2))throw std::invalid_argument("Finite collision radius required");
    const auto diameter=int(raw_diameter)+2;
    Vec3 base=input.start;
    if(diameter==2){const auto cx=std::uint32_t((input.start.x-float(h.origin_x))/float(h.step_x)),cz=std::uint32_t((input.start.z-float(h.origin_z))/float(h.step_z));
        const auto fx=input.start.x-float(h.origin_x)-float(cx*h.step_x),fz=input.start.z-float(h.origin_z)-float(cz*h.step_z);
        const auto quadrant=(fx>=float(h.step_x/2)?1u:0u)|(fz>=float(h.step_z/2)?2u:0u);
        constexpr std::array<std::array<float,2>,4> offsets{{{-1,-1},{0,-1},{-1,0},{0,0}}};base.x+=float(h.step_x)*offsets[quadrant][0];base.z+=float(h.step_z)*offsets[quadrant][1];
    }else{const int half=diameter/2;base.x-=float(half)*float(h.step_x);base.z-=float(half)*float(h.step_z);}
    std::array<std::uint64_t,20> recent{};unsigned recent_count{};std::array<std::uint64_t,6> accepted{};unsigned accepted_count{};
    const auto visit=[&](const Triangle& t,std::uint64_t id,const response::Filter& f){
        if(!response::admits(t.flags,f))return;
        for(unsigned i=0;i<recent_count;++i)if(recent[i]==id)return;
        for(unsigned i=0;i<accepted_count;++i)if(accepted[i]==id)return;
        if(contacts.collect(t))accepted[accepted_count++]=id;
        recent[recent_count++]=id;if(recent_count==recent.size())recent_count=0;
    };
    for(unsigned x=0;x<2;++x)for(unsigned z=0;z<2;++z){auto p=base;p.x+=float(h.step_x*x);p.z+=float(h.step_z*z);for(auto id:grid.cell(p))visit(grid.triangles()[id],id,filter);}
    auto dynamic_filter=filter;dynamic_filter.dynamic_kind_gate=false;
    for(unsigned i=0;i<dynamic.size();++i)visit(dynamic[i],(std::uint64_t{1}<<32)|i,dynamic_filter);
    result.resolution=contacts.resolve();result.reported_point=contacts.reported_point();result.reported_normal=contacts.reported_normal();return result;
}
}
