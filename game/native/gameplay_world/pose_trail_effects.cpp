#include "pose_trail_effects.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
std::array<float,6> pose_trail_parameters(std::uint8_t policy){
    constexpr std::array<std::array<float,6>,4> rows{{{{.6f,1,.95f,1,.7f,1}},{{.5f,1,.6f,.6f,.45f,.8f}},{{1,0,1,1,1,1}},{{.6f,1,.6f,.6f,.45f,.8f}}}};
    if(policy>=rows.size())throw std::out_of_range("Native trail policy outside owned table");
    return rows[policy];
}
MappedPoseTrailEffects::MappedPoseTrailEffects(World& world,gameplay_effects::WorkBackend& work,gameplay_contact_world::RoomResources& rooms,PoseTrails* inherited)
    :world_(world),work_(work),rooms_(rooms),inherited_(inherited){if(!bound_to(world))throw std::invalid_argument("Native pose trail effect owners unavailable");}
bool MappedPoseTrailEffects::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed()&&work_.admitted()&&work_.bound_to(world_.session().random)&&(!inherited_||inherited_->bound_to(world));}
std::optional<gameplay_collision::response::Floor> MappedPoseTrailEffects::water_floor(transform_math::Vector point){
    const auto number=world_.room;const auto room=rooms_.retain(number);const auto id=room?room->identity():gameplay_contact_world::RoomId{};
    if(!room||!id||room->room_number()!=number||!room->current(id)||world_.room!=number)return{};
    const auto result=room->geometry().floors.floor({point.x,point.y,point.z},0x81);return room->current(id)&&world_.room==number?std::optional(result):std::nullopt;
}
bool MappedPoseTrailEffects::emit(const actors::EntityId& owner,const actors::EntityId& motion,std::uint8_t mode){return emit_at(owner,motion,mode,{},0);}
bool MappedPoseTrailEffects::emit_at(const actors::EntityId& owner,const actors::EntityId& motion,std::uint8_t mode,std::optional<transform_math::Vector> point,std::int32_t delay){
    if(!bound_to(world_))return false;
    if(mode>=4)return true;
    const auto actor=world_.resolve(owner);if(!actor)return false;
    const auto selected=select_pose_trail(actor->slot,mode);if(!selected)return true;
    std::shared_ptr<Actor> moving;
    if(!point||mode==1){moving=world_.resolve(motion);if(!moving)return false;}
    if(mode==1){
        // The current PoseTrails capability represents the actual zero-delay,
        // implicit-position call used by scene pose callbacks. Wider mode1
        // inputs require its extended constructor, never silent narrowing.
        if(point||delay)return false;
        return inherited_&&inherited_->emit(owner,motion,mode);
    }
    if(!point)point=transform_math::Vector{moving->position.x,moving->position.y,moving->position.z};
    if(!std::isfinite(point->x)||!std::isfinite(point->y)||!std::isfinite(point->z))return false;
    if(mode==3){
        point->y=point->y+200.f;const auto sampled=water_floor(*point);if(!sampled)return false;
        point->y=std::bit_cast<float>(0x4039999au)+sampled->height;
        if(sampled->type!=0x81)return true;
    }
    gameplay_effects::WorkRequest request;request.position=*point;request.effect=selected->resource;
    request.child_mask=selected->resource==0x88?0xffu:0u; // exact selected7123A0 entries
    const auto made=work_.create(request);
    if(made.status==gameplay_effects::WorkStatus::pool_full||made.status==gameplay_effects::WorkStatus::resource_missing)return true;
    if(made.status!=gameplay_effects::WorkStatus::completed||!made.edit)return false;
    const auto edit=std::dynamic_pointer_cast<gameplay_effects::ParticleEdit>(made.edit);if(!edit)return false;
    return edit->configure_particle(mode,std::bit_cast<std::int16_t>(std::uint16_t(delay)),pose_trail_parameters(selected->policy));
}
}
