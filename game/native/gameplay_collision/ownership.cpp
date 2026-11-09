#include "ownership.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace reo::native::gameplay_collision::ownership {
namespace {
Vec3 add(Vec3 a,Vec3 b){return{a.x+b.x,a.y+b.y,a.z+b.z};}
Vec3 sub(Vec3 a,Vec3 b){return{a.x-b.x,a.y-b.y,a.z-b.z};}
float dot(Vec3 a,Vec3 b){return(a.x*b.x+a.y*b.y)+a.z*b.z;}
std::optional<std::array<Vec3,4>> local(const Quad& points,const actors::Basis& basis){
    const std::array<Vec3,3> axes{basis.x,basis.y,basis.z};std::array<float,3> reciprocal;
    for(unsigned i=0;i<3;++i){const auto squared=dot(axes[i],axes[i]);if(!(squared>0)||!std::isfinite(squared))return{};reciprocal[i]=1/std::sqrt(squared);}
    std::array<Vec3,4> result;
    for(unsigned i=0;i<4;++i){const auto p=sub({float(points[i].x),0,float(points[i].z)},basis.translation);float values[3];
        for(unsigned j=0;j<3;++j){const auto a=axes[j];const auto r=reciprocal[j];values[j]=(((a.x*r)*r)*p.x+((a.y*r)*r)*p.y)+((a.z*r)*r)*p.z;}
        result[i]={values[0],values[1],values[2]};}
    return result;
}
std::optional<Quad> world(const std::array<Vec3,4>& points,const actors::Basis& basis){
    Quad result;for(unsigned i=0;i<4;++i){const auto point=integer_xz(basis.point(points[i]));if(!point)return{};result[i]=*point;}return result;
}
}
namespace {
gameplay_scene::Record canonical_record(Record value){
    using namespace gameplay_scenario;
    gameplay_scene::Record result;
    const auto& p=value.geometry;
    result.authored_id=p.identifier;result.enabled=p.active?1:0;result.counter=p.priority;
    result.body=ControlOther{p.kind};
    if(p.kind==0&&value.door){
        ControlTypeZero zero;zero.destination=ControlRouteDestination{value.door->destination_room,value.door->destination_door};
        result.body=zero;result.door=gameplay_scene::DoorDetails{value.door->selector};
    }
    result.collision=gameplay_scene::CollisionShape{p.bounds,p.lower,p.upper,p.query_class,p.busy,p.object};
    result.other_content=p.content_id;
    result.other_resource_class=value.door?std::uint32_t(value.door->heading):(p.bypass_slot_guard?2u:0u);
    result.owner=std::move(value.owner);result.source=std::move(value.source);
    result.owner_snapshot=value.owner_snapshot;result.extra=value.extra;
    return result;
}
Record projected_record(const gameplay_scene::Record& source){
    Record result;result.geometry=gameplay_scene::collision_view(source);
    result.owner=source.owner;result.source=source.source;
    result.owner_snapshot=source.owner_snapshot;result.extra=source.extra;
    if(source.door){
        const auto* zero=std::get_if<gameplay_scenario::ControlTypeZero>(&source.body);
        if(zero&&zero->destination&&source.other_resource_class){
            const auto selector=zero->matrix_program?std::optional<std::uint32_t>(zero->matrix_program->resource_class):source.door->selector_without_matrix;
            if(selector)result.door=Door{source.authored_id,zero->destination->room,zero->destination->edge,std::uint16_t(*source.other_resource_class),*selector};
        }
    }
    return result;
}
}
Proxies::Proxies(std::uint32_t capacity,std::uint64_t maximum):pool_(std::make_shared<gameplay_scene::Records>(capacity,maximum)){}
Proxies::Proxies(std::shared_ptr<gameplay_scene::Records> pool):pool_(std::move(pool)){
    if(!pool_)throw std::invalid_argument("Missing canonical scene record owner");
}
Proxies::~Proxies()=default;
Proxies::InvocationLease Proxies::acquire(const Handle& id)const noexcept{InvocationLease lease;lease.node_=pool_->acquire(id);return lease;}
std::optional<Handle> Proxies::create(Record record,bool prepend){return pool_->create(canonical_record(std::move(record)),prepend?gameplay_scene::Placement::oldest:gameplay_scene::Placement::newest);}
bool Proxies::retire(const Handle& id)noexcept{return pool_->retire(id);}
const Record* Proxies::get(const Handle& id)const noexcept{
    const auto node=pool_->acquire(id);if(!node)return nullptr;
    if(projection_revision_!=pool_->revision()){
        for(auto& item:projections_)item.value.reset();
        projection_revision_=pool_->revision();
    }
    for(const auto& item:projections_)if(item.value&&item.id==id)return &*item.value;
    for(auto& item:projections_)if(!item.value){item.id=id;item.value=projected_record(node->value);return &*item.value;}
    return nullptr;
}
bool Proxies::replace(const Handle& id,Record value)noexcept{
    const auto node=pool_->acquire(id);if(!node)return false;
    // A geometry/ownership edit cannot erase script-owned parameters. Update
    // only the shared fields actually exposed by the collision projection.
    auto& record=node->value;const auto& p=value.geometry;
    if(p.kind!=gameplay_scene::kind(record.body))return false;
    pool_->touch();record.authored_id=p.identifier;record.counter=p.priority;
    if((record.enabled!=0)!=p.active)record.enabled=p.active?1:0;
    record.collision=gameplay_scene::CollisionShape{p.bounds,p.lower,p.upper,p.query_class,p.busy,p.object};
    if(auto* zero=std::get_if<gameplay_scenario::ControlTypeZero>(&record.body);zero&&zero->destination){
        zero->destination->edge=p.content_id;
        if(value.door){zero->destination=gameplay_scenario::ControlRouteDestination{value.door->destination_room,value.door->destination_door};record.door=gameplay_scene::DoorDetails{};
            record.other_resource_class=value.door->heading;
            if(zero->matrix_program)zero->matrix_program->resource_class=value.door->selector;else record.door->selector_without_matrix=value.door->selector;}
    }else if(auto* two=std::get_if<gameplay_scenario::ControlTypeTwo>(&record.body);two&&two->model_reference)two->model_reference->descriptor=p.content_id;
    else record.other_content=p.content_id;
    if(auto* two=std::get_if<gameplay_scenario::ControlTypeTwo>(&record.body)){
        if((two->matrix_resource_class==2)!=p.bypass_slot_guard)two->matrix_resource_class=p.bypass_slot_guard?2u:0u;
    }else if((record.other_resource_class==2)!=p.bypass_slot_guard)record.other_resource_class=p.bypass_slot_guard?2u:0u;
    record.owner=std::move(value.owner);record.source=std::move(value.source);record.owner_snapshot=value.owner_snapshot;record.extra=value.extra;
    return true;
}
std::vector<Handle> Proxies::ordered()const{return pool_->ordered();}
std::optional<Selected> Proxies::select(const ActorQuery& query,gameplay_actors::EntityId actor,std::span<const ProxyState> states)const{
    if(!actor||states.size()!=pool_->size())return{};
    const auto order=pool_->ordered();
    if(!snapshot_||snapshot_revision_!=pool_->revision()){
        std::vector<Proxy> proxies;proxies.reserve(order.size());
        for(const auto& id:order)proxies.push_back(gameplay_scene::collision_view(pool_->acquire(id)->value));
        snapshot_.emplace(1,std::move(proxies));snapshot_revision_=pool_->revision();
    }
    const auto selected=snapshot_->select(query,states);if(!selected)return{};
    return Selected{order[selected->id.index],std::move(actor),selected->query_class};
}
void Proxies::clear()noexcept{pool_->clear();}
std::optional<Proxy> depth_extension(const Proxy& source,const actors::Basis& basis)noexcept{
    auto points=local(source.bounds,basis);if(!points)return{};std::array<unsigned,2> selected{4,4};
    for(unsigned scan=0;scan<2;++scan){float best=10000;for(unsigned i=0;i<4;++i){if(scan&&i==selected[0])continue;const auto value=std::abs((*points)[i].z);if(value<best){best=value;selected[scan]=i;}}if(selected[scan]==4)return{};}
    const auto base=(*points)[selected[0]].z;float depth=40;for(unsigned i=0;i<4;++i)if(i!=selected[0]&&i!=selected[1]){depth=(*points)[i].z-base;break;}
    for(unsigned i=0;i<4;++i)(*points)[i].z=base+((i==selected[0]||i==selected[1])?0.5f*depth:-4.0f*depth);
    const auto bounds=world(*points,basis);if(!bounds)return{};Proxy result;result.bounds=*bounds;result.lower=source.lower;result.upper=source.upper;result.kind=0x84;result.query_class=1;result.priority=source.priority;result.active=true;return result;
}
std::optional<Proxy> depth_sixty(const Proxy& source,const actors::Basis& basis,bool bound)noexcept{
    if(bound)return{};
    auto points=local(source.bounds,basis);if(!points)return{};
    for(unsigned i=0;i<4;++i)(*points)[i].z=(i==1||i==2)?60.0f:-60.0f;
    const auto bounds=world(*points,basis);if(!bounds)return{};Proxy result;result.bounds=*bounds;result.lower=source.lower;result.upper=source.upper;result.kind=0x85;result.query_class=1;result.priority=source.priority;result.active=false;return result;
}
std::optional<Quad> reproject_middle(const Quad& source,const actors::Basis& basis)noexcept{
    auto points=local(source,basis);if(!points)return{};const auto transformed=world(*points,basis);if(!transformed)return{};auto result=source;result[1]=(*transformed)[1];result[2]=(*transformed)[2];return result;
}
Record owned_region(std::uint8_t kind,Quad bounds,std::int32_t lower,std::int32_t upper,gameplay_actors::EntityId owner,std::uint8_t snapshot,std::uint8_t extra){
    if(kind<0x80||kind>0x83||!owner)throw std::invalid_argument("Invalid native owned proxy region");
    Record result;auto& p=result.geometry;p.bounds=bounds;p.lower=lower;p.upper=upper;p.kind=kind;p.priority=kind==0x80?3:1;p.query_class=kind==0x81?7:0;p.active=true;p.busy=kind==0x83;result.owner=std::move(owner);
    if(kind!=0x80)result.owner_snapshot=snapshot;
    if(kind==0x82)result.extra=extra;
    return result;
}
sweep::Result move_against_walls(WallState& state,const actors::Basis& basis,const response::Grid& grid,response::Filter filter,std::span<const response::Triangle> dynamic){
    state.contact=false;const auto offset=basis.direction(state.local_center);const auto current=add(state.position,offset),previous=add(state.previous,state.previous_center_offset);state.previous_center_offset=offset;
    if(state.disabled)return{};
    filter.include=state.include;filter.exclude=state.exclude;filter.dynamic_kind_gate=state.dynamic_kind_gate;
    auto result=sweep::query(grid,sweep::input(current,previous,state.radius),filter,dynamic);
    if(result.resolution.contact_count){state.contact=true;state.position.x=(current.x+result.resolution.correction.x)-offset.x;state.position.z=(current.z+result.resolution.correction.z)-offset.z;state.point=result.reported_point;state.normal=result.reported_normal;}
    return result;
}
}
