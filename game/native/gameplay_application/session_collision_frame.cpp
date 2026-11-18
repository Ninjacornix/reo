#include "session_collision_frame.hpp"
#include "session_control_preparation.hpp"
#include "session_behavior_services.hpp"
#include "session_primary_actions.hpp"
#include "session_scene_query_effects.hpp"
#include "../gameplay_world/auxiliary_actors.hpp"
#include "../gameplay_world/motion_transforms.hpp"
#include "../gameplay_world/surface_orientation.hpp"
#include <stdexcept>

namespace reo::native::gameplay_application {
namespace {
NativeSession& require_session(const std::shared_ptr<NativeSession>& session){
    if(!session||!session->open())throw std::invalid_argument("Native collision session unavailable");
    return *session;
}
class CheckedBodyQueue final:public gameplay_world::MotionServices {
public:
    explicit CheckedBodyQueue(gameplay_world::WorldBodies& bodies):bodies_(bodies){}
    void enqueue(gameplay_world::World& world,gameplay_world::Actor& actor,
        std::uint16_t kind,std::uint16_t mask)override{
        const auto before=bodies_.counts();
        bodies_.enqueue(world,actor,kind,mask);
        const auto after=bodies_.counts();
        if(after.accepted!=before.accepted+1)
            throw std::runtime_error("Native actor collision registration refused");
    }
private:
    gameplay_world::WorldBodies& bodies_;
};
}
SessionCollisionFrame::SessionCollisionFrame(std::shared_ptr<NativeSession> session,
    std::shared_ptr<SessionRooms> rooms,gameplay_update::PhaseServices& phases,
    gameplay_world::Services& actors,SessionCollisionInputs& inputs,
    gameplay_world::SecondaryCollisionWalls& walls):session_(std::move(session)),rooms_(std::move(rooms)),
    actors_(actors),inputs_(inputs),bodies_(require_session(session_).world()),poses_(session_->world()),
    workers_(session_->world(),phases,bodies_,poses_,*this,walls){
    if(!rooms_||rooms_->world().get()!=&session_->world())
        throw std::invalid_argument("Collision rooms belong to another session");
}
void SessionCollisionFrame::verify(gameplay_update::Owner& owner)const{
    if(!session_->open()||&owner!=&session_->update()||rooms_->world().get()!=&owner.world())
        throw std::runtime_error("Native collision session retired or foreign");
    if(!room_lease_||room_lease_->room_number()!=owner.world().room||
       !room_lease_->current(room_lease_->identity()))
        throw std::runtime_error("Native collision room retired or unavailable");
}
gameplay_update::BodyFrame SessionCollisionFrame::bodies(gameplay_update::Owner& owner){
    verify(owner);auto frame=inputs_.bodies(owner);verify(owner);
    frame.selected=owner.world().identity(owner.world().selected_actor);
    for(const auto& entry:frame.additional){
        if(!entry.id||!entry.actor||owner.world().resolve(entry.id)!=entry.actor)
            throw std::runtime_error("Native collision body identity unavailable");
    }
    return frame;
}
gameplay_update::HeightFrame SessionCollisionFrame::heights(gameplay_update::Owner& owner){
    verify(owner);auto frame=inputs_.secondary_heights(owner);verify(owner);
    if(!frame.auxiliary.empty())throw std::invalid_argument("Auxiliary collision actors belong to the canonical pool");
    auto& pool=owner.world().auxiliary_actors();
    for(auto id=pool.head();id;id=pool.next(id)){
        auto actor=owner.world().resolve(id);
        if(!actor)throw std::runtime_error("Native auxiliary collision actor retired");
        frame.auxiliary.push_back(std::move(actor));
    }
    return frame;
}
gameplay_world::CollisionRoom SessionCollisionFrame::room(gameplay_update::Owner& owner){
    verify(owner);return room_lease_->geometry();
}
FrameStep SessionCollisionFrame::advance(std::size_t script_budget,std::size_t task_budget){
    return advance_impl(nullptr,{},nullptr,nullptr,nullptr,script_budget,task_budget);
}
FrameStep SessionCollisionFrame::advance_native_behavior(std::span<const std::int16_t> amounts,
    std::size_t script_budget,std::size_t task_budget){
    if(!session_->open())return{SessionStatus::closed,{}};
    SessionSceneQueryEffects effects(*session_,*rooms_);
    SessionActorQueries queries(*session_,*rooms_,effects);
    SessionPrimaryActions actions(*session_,*rooms_,queries);
    SessionBehaviorServices behavior(*session_,actions);
    return advance_behavior(behavior,amounts,nullptr,nullptr,nullptr,script_budget,task_budget);
}
FrameStep SessionCollisionFrame::advance_behavior(gameplay_world::BehaviorServices& behavior,
    std::span<const std::int16_t> amounts,gameplay_world::TerminalTiming* terminal,
    gameplay_world::ProgressionTiming* progression,gameplay_world::ZeroHealthApplication* zero_health,
    std::size_t script_budget,std::size_t task_budget){
    return advance_impl(&behavior,amounts,terminal,progression,zero_health,script_budget,task_budget);
}
FrameStep SessionCollisionFrame::advance_impl(gameplay_world::BehaviorServices* behavior,
    std::span<const std::int16_t> amounts,gameplay_world::TerminalTiming* terminal,
    gameplay_world::ProgressionTiming* progression,gameplay_world::ZeroHealthApplication* zero_health,
    std::size_t script_budget,std::size_t task_budget){
    if(running_)return{SessionStatus::busy,{}};
    if(!session_->open())return{SessionStatus::closed,{}};
    if(!session_->room())return{SessionStatus::missing_room,{}};
    if(session_->update().busy()||session_->world().busy())return{SessionStatus::busy,{}};
    if(bodies_.pending())throw std::runtime_error("Native collision queue requires explicit recovery");
    running_=true;struct Reset{bool& running;~Reset(){running=false;}} reset{running_};
    room_lease_=rooms_->retain(session_->world().room);
    if(!room_lease_||!room_lease_->current(room_lease_->identity()))
        return{SessionStatus::missing_providers,{}};
    gameplay_world::GridSurfaceOrientation surface(room_lease_->geometry().floors);
    CheckedBodyQueue queue(bodies_);
    gameplay_world::MotionFrameServices motion(actors_,queue);
    gameplay_world::MotionTransformFrameServices transforms(motion,surface);
    if(behavior){
        SessionControlPreparation control(session_->world());
        gameplay_world::BehaviorFrameServices actual(transforms,*behavior,room_lease_->geometry().floors,
            amounts,&session_->update(),&session_->update(),terminal,progression,zero_health);
        actual.bind_control_preparation(control);
        return session_->advance(&workers_,&actual,script_budget,task_budget);
    }
    return session_->advance(&workers_,&transforms,script_budget,task_budget);
}
}
