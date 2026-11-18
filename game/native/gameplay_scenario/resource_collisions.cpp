#include "resource_collisions.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
constexpr std::array<std::array<std::int32_t,10>,20> profiles{{
#include "resource_collision_profile.inc"
}};
std::int32_t integer(float value){
    if(!std::isfinite(value)||value < -2147483648.f||value>=2147483648.f)throw std::domain_error("Native resource footprint integer conversion unavailable");
    return static_cast<std::int32_t>(value);
}
std::int32_t add(std::int32_t a,std::int32_t b){return std::bit_cast<std::int32_t>(std::uint32_t(a)+std::uint32_t(b));}
}
ResourceFootprint resource_footprint(transform_math::Vector position,std::uint16_t yaw,std::int8_t profile){
    if(profile<0||unsigned(profile)>=profiles.size())throw std::out_of_range("Native resource collision shape profile unavailable");
    transform_math::require_profile();const auto& row=profiles[unsigned(profile)];auto basis=transform_math::identity();transform_math::reset_euler_axes(basis,{0,yaw,0});ResourceFootprint result;
    for(unsigned i=0;i<4;++i){const auto offset=transform_math::direction(basis,{float(row[2*i]),0,float(row[2*i+1])});result.bounds[i]={integer(position.x+offset.x),integer(position.z+offset.z)};}
    const auto height=integer(position.y);result.lower=add(height,row[8]);result.upper=add(height,row[9]);return result;
}
ResourceCollisions::ResourceCollisions(SceneResources& resources,std::shared_ptr<gameplay_scene::Records> records):resources_(resources),records_(std::move(records)){
    if(!records_)throw std::invalid_argument("Native resource collision shared owner missing");
}
ResourceCollisionCreated ResourceCollisions::replace(const SceneResourceId& id)noexcept{
    auto descriptor=resources_.get(id);if(!descriptor)return{ResourceCollisionStatus::invalid_identity,{}};
    std::optional<gameplay_scene::RecordId> allocated;
    try{
        const auto shape=resource_footprint(descriptor->position,descriptor->yaw,descriptor->shape_profile);
        const auto previous=std::dynamic_pointer_cast<SceneRecordAttachment>(descriptor->secondary);
        if(descriptor->secondary&&(!previous||!previous->bound_to(*records_)||!previous->current()))return{};
        if(previous&&!previous->retire())return{};
        descriptor->secondary.reset();
        if(resources_.replace(id,*descriptor)!=SceneStatus::completed)return{ResourceCollisionStatus::invalid_identity,{}};
        gameplay_scene::Record record;record.authored_id=descriptor->instance_index;record.enabled=1;record.counter=3;record.body=ControlOther{0x80};
        record.collision=gameplay_scene::CollisionShape{shape.bounds,shape.lower,shape.upper,0,false,{}};
        record.other_content=0xffff0000u;record.other_resource_class=0;
        allocated=records_->create(std::move(record),gameplay_scene::Placement::newest);
        if(!allocated)return{ResourceCollisionStatus::full,{}};
        auto attachment=std::make_shared<SceneRecordAttachment>(records_,*allocated);descriptor->secondary=attachment;
        if(resources_.replace(id,*descriptor)!=SceneStatus::completed){records_->retire(*allocated);return{ResourceCollisionStatus::invalid_identity,{}};}
        return{ResourceCollisionStatus::completed,std::move(attachment)};
    }catch(const std::exception&){if(allocated)records_->retire(*allocated);return{};}
}
}
