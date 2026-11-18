#include "session_collision_inputs.hpp"
#include "../gameplay_collision/ownership.hpp"
#include "../gameplay_world/auxiliary_actors.hpp"
#include "../gameplay_world/linked_models.hpp"
#include <stdexcept>

namespace reo::native::gameplay_application {
namespace collision=gameplay_collision;
namespace world=gameplay_world;

SessionCollisionPopulation::SessionCollisionPopulation(std::shared_ptr<NativeSession> session)
    :session_(std::move(session)) {
    if(!session_||!session_->open())throw std::invalid_argument("Collision population session unavailable");
}
world::World& SessionCollisionPopulation::world(gameplay_update::Owner& owner) const {
    if(!session_->open()||&owner!=&session_->update()||&owner.world()!=&session_->world())
        throw std::runtime_error("Collision population session retired or foreign");
    return owner.world();
}
gameplay_update::BodyFrame SessionCollisionPopulation::bodies(gameplay_update::Owner& owner) {
    auto& w=world(owner);
    gameplay_update::BodyFrame result;
    // 6EF720 calls 1B0310, which tests exactly message-phase values 1/2.
    const auto phase=w.session().message_phase;
    result.limit_repeated=phase==1||phase==2;
    result.fast_tick=w.session().clock_mode!=0;
    result.selected=w.identity(w.selected_actor);
    world::WorldModelPoses poses(w);
    const auto append=[&](const auto& id,const std::shared_ptr<world::Actor>& actor) {
        if(!actor||w.resolve(id)!=actor)throw std::runtime_error("Collision body actor retired");
        std::shared_ptr<const world::JointPose> pose;
        if(actor->model&&actor->collision.body_definition)
            pose=poses.retain(id,*actor);
        result.additional.push_back({id,actor,std::move(pose)});
    };
    auto& auxiliary=w.auxiliary_actors();
    for(auto id=auxiliary.head();id;id=auxiliary.next(id))append(id,w.resolve(id));
    auto& linked=w.linked_models();
    for(auto id=linked.tail();id;id=linked.previous(id))append(id,linked.resolve(id));
    return result;
}
gameplay_update::HeightFrame SessionCollisionPopulation::secondary_heights(gameplay_update::Owner& owner) {
    auto& w=world(owner);
    gameplay_update::HeightFrame result;
    auto& linked=w.linked_models();
    for(auto id=linked.tail();id;id=linked.previous(id)) {
        auto actor=linked.resolve(id);
        if(!actor||w.resolve(id)!=actor)
            throw std::runtime_error("Secondary collision actor retired");
        if(!actor->linked_frame)throw std::runtime_error("Secondary actor clear state unavailable");
        auto& a=*actor;
        collision::ground::View view{a.position,a.surface_normal,a.sampled_surface_height,
            a.surface_kind,a.surface_material,a.surface_attributes,a.auxiliary_status,
            {a.orientation[0],a.orientation[1],a.orientation[2]}};
        auto& state=*a.linked_frame;
        collision::ground::ProbeRefs probes{state.ground_kind_one,state.ground_kind_twenty_nine,
            a.material_uv?&a.material_uv->u:nullptr};
        result.secondary.push_back({id,view,a.collision.displacement,a.contact_flags,a.slot,probes});
        result.secondary_owners.push_back(std::move(actor));
    }
    return result;
}
void SessionCollisionPopulation::correct(const gameplay_actors::EntityId& id,
    collision::ground::View view,const world::CollisionRoom& room) {
    if(!session_->open())throw std::runtime_error("Collision wall session retired");
    auto& w=session_->world();
    auto& pool=w.linked_models();
    auto actor=pool.resolve(id);
    if(!actor||w.resolve(id)!=actor)
        throw std::runtime_error("Secondary wall actor retired");
    if(&view.position.x!=&actor->position.x||&view.position.y!=&actor->position.y||
       &view.position.z!=&actor->position.z||&view.normal.x!=&actor->surface_normal.x||
       &view.normal.y!=&actor->surface_normal.y||&view.normal.z!=&actor->surface_normal.z||
       &view.height!=&actor->sampled_surface_height||&view.surface!=&actor->surface_kind||
       &view.material!=&actor->surface_material||&view.attributes!=&actor->surface_attributes||
       &view.auxiliary_status!=&actor->auxiliary_status||
       &view.rotation.x!=&actor->orientation[0]||&view.rotation.y!=&actor->orientation[1]||
       &view.rotation.z!=&actor->orientation[2])
        throw std::invalid_argument("Secondary wall actor view mismatch");
    auto& c=actor->collision;
    collision::ownership::WallState state{
        {actor->position.x,actor->position.y,actor->position.z},
        {actor->previous_position.x,actor->previous_position.y,actor->previous_position.z},
        c.local_center,c.previous_center_offset,c.radius,actor->response_mask,actor->response_value,
        (actor->contact_flags&1)!=0,actor->category==2,c.contact,c.point,c.normal};
    const auto result=collision::ownership::move_against_walls(state,c.basis,room.walls,room.filter,room.dynamic);
    actor->position.x=state.position.x;actor->position.z=state.position.z;
    c.previous_center_offset=state.previous_center_offset;c.contact=state.contact;
    c.point=state.point;c.normal=state.normal;
    if(result.resolution.status!=collision::sweep::Status::ok&&
       result.resolution.status!=collision::sweep::Status::source_face_recovered)
        throw std::runtime_error("Secondary wall geometry unavailable");
}
}
