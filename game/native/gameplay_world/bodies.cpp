#include "bodies.hpp"
#include <algorithm>
#include <stdexcept>
namespace reo::native::gameplay_world {
gameplay_collision::actors::View body_view(Actor& a,actors::EntityId id,
    std::span<const gameplay_collision::actors::Basis> joints)noexcept{
    auto& c=a.collision;
    return{std::move(id),a.position,a.previous_position,a.candidate_direction,joints,c.body_definition,
        a.category,c.body_priority,c.separation_count,a.room_marker,c.body_peer,a.room,c.body_summary,a.transient_marker};
}
void WorldBodies::enqueue(World& w,Actor& actor,std::uint16_t kind,std::uint16_t mask){
    if(&w!=&world_){++counts_.retired_or_foreign;return;}
    if(solving_){++counts_.busy;return;}
    for(std::size_t i=0;i<World::primary_capacity;++i){
        const auto candidate=world_.primary(i);if(candidate.get()!=&actor)continue;
        if(add({world_.identity(i),mask,kind}))++counts_.accepted;
        else ++counts_.full;
        return;
    }
    // Retiring an entity invalidates future lookup/work. A surviving invocation
    // lease must never redirect queued work to a new primary generation.
    ++counts_.retired_or_foreign;
}
bool WorldBodies::add(gameplay_collision::actors::Registration value){
    if(solving_)return false;
    const auto index=registry_.size();
    if(!registry_.add(value))return false;
    queued_[index]=std::move(value.actor);return true;
}
bool WorldBodies::clear()noexcept{
    if(solving_)return false;
    registry_.clear();queued_.fill({});return true;
}
BodyReport WorldBodies::solve(BodyPoses& poses,actors::EntityId selected,bool limited,bool fast,
    std::span<const gameplay_collision::actors::View> additional){
    if(solving_)return{BodyStatus::busy,{},{}};
    solving_=true;
    struct Guard{bool& active;~Guard(){active=false;}} guard{solving_};
    using View=gameplay_collision::actors::View;
    std::vector<std::shared_ptr<Actor>> actors;
    std::vector<std::shared_ptr<const JointPose>> retained;
    std::array<std::size_t,World::primary_capacity> primary_indices{};
    std::vector<View> views;actors.reserve(World::primary_capacity);retained.reserve(World::primary_capacity);
    views.reserve(World::primary_capacity+additional.size());
    for(std::size_t i=0;i<World::primary_capacity;++i){
        auto actor=world_.primary(i);if(!actor)continue;const auto id=world_.identity(i);
        std::shared_ptr<const JointPose> pose;
        const bool queued=std::find(queued_.begin(),queued_.begin()+registry_.size(),id)!=queued_.begin()+registry_.size();
        if(queued && actor->collision.body_definition && actor->collision.body_definition->radius>0){
            const auto& definition=*actor->collision.body_definition;
            const auto needs=[](const auto& center){return bool(center.first_joint)||bool(center.second_joint);};
            if(needs(definition.first) || (definition.kind==gameplay_collision::actors::ShapeKind::capsule && needs(definition.second))){
                pose=poses.retain(id,*actor);if(!pose)return{BodyStatus::pose_unavailable,{},id};
            }
        }
        if(world_.identity(i)!=id || world_.primary(i).get()!=actor.get())return{BodyStatus::roster_changed,{},id};
        views.push_back(body_view(*actor,id,pose?std::span<const gameplay_collision::actors::Basis>(pose->joints):std::span<const gameplay_collision::actors::Basis>{}));
        primary_indices[actors.size()]=i;actors.push_back(std::move(actor));retained.push_back(std::move(pose));
    }
    for(std::size_t i=0;i<actors.size();++i)
        if(world_.identity(primary_indices[i])!=views[i].id || world_.primary(primary_indices[i]).get()!=actors[i].get())
            return{BodyStatus::roster_changed,{},views[i].id};
    for(const auto& view:additional)views.push_back(view);
    BodyReport result;
    try{result.solve=registry_.solve(views,limited,fast);}
    catch(const std::invalid_argument&){result.status=BodyStatus::invalid_geometry;return result;}
    queued_.fill({});
    boundary_.apply(views,world_.mode==0,world_.room,std::move(selected));return result;
}
}
