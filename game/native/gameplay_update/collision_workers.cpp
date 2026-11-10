#include "collision_workers.hpp"
#include <stdexcept>
namespace reo::native::gameplay_update {
namespace {
struct Attempt {
    CollisionProgress& progress;
    ~Attempt(){if(progress==CollisionProgress::acquiring)progress=CollisionProgress::failed;}
};
}
void CollisionWorkers::verify(Owner& owner)const{
    if(&owner.world()!=&world_)throw std::invalid_argument("Collision worker belongs to another native World");
}
void CollisionWorkers::run(Worker stage,Owner& owner){
    verify(owner);
    if(stage==Worker::target_caches){
        body_result_.reset();body_progress_=CollisionProgress::never_run;
        height_result_.reset();height_progress_=CollisionProgress::never_run;
        target_result_.reset();target_progress_=CollisionProgress::acquiring;Attempt attempt{target_progress_};
        auto& cache=world_.target_metrics();cache.invalidate();
        const auto room=participants_.room(owner);
        target_result_=cache.rebuild({room.walls,room.floors,room.filter,room.dynamic});
        if(target_result_->status!=world::TargetMetricStatus::completed)
            throw std::runtime_error("Native target metric worker incomplete; preceding effects retained");
        target_progress_=CollisionProgress::completed;
    }else if(stage==Worker::actor_collision_shapes){
        height_result_.reset();height_progress_=CollisionProgress::never_run;
        body_result_.reset();body_progress_=CollisionProgress::acquiring;Attempt attempt{body_progress_};
        const auto frame=participants_.bodies(owner);
        std::vector<gameplay_collision::actors::View> additional;additional.reserve(frame.additional.size());
        for(const auto& actor:frame.additional){
            if(!actor.id || !actor.actor)throw std::invalid_argument("Native additional body lease unavailable");
            additional.push_back(world::body_view(*actor.actor,actor.id,
                actor.pose?std::span<const gameplay_collision::actors::Basis>(actor.pose->joints):std::span<const gameplay_collision::actors::Basis>{}));
        }
        body_result_=bodies_.solve(poses_,frame.selected,frame.limit_repeated,frame.fast_tick,additional);
        if(body_result_->status!=world::BodyStatus::completed)
            throw std::runtime_error("Native actor body worker incomplete; preceding effects retained");
        body_progress_=CollisionProgress::completed;
    }else if(stage==Worker::collision_heights){
        height_result_.reset();height_progress_=CollisionProgress::acquiring;Attempt attempt{height_progress_};
        auto frame=participants_.heights(owner);
        if(frame.secondary.size()!=frame.secondary_owners.size())
            throw std::invalid_argument("Native secondary collision leases unavailable");
        for(const auto& entity:frame.secondary_owners)if(!entity)
            throw std::invalid_argument("Native secondary collision lease unavailable");
        const auto room=participants_.room(owner);
        height_result_=world::update_collision_heights(world_,room,frame.auxiliary,frame.secondary,walls_);
        if(height_result_->status!=world::HeightStatus::completed)
            throw std::runtime_error("Native collision height worker incomplete; preceding effects retained");
        height_progress_=CollisionProgress::completed;
    }else remaining_.run(stage,owner);
}
bool CollisionWorkers::button(Button button,Owner& owner){verify(owner);return remaining_.button(button,owner);}
bool CollisionWorkers::transition_request(Owner& owner){verify(owner);return remaining_.transition_request(owner);}
void CollisionWorkers::effect(PhaseEffect effect,Owner& owner,std::uint32_t argument){verify(owner);remaining_.effect(effect,owner,argument);}
}
