#include "world.hpp"
#include "linked_models.hpp"
#include "auxiliary_actors.hpp"
#include "target_metrics.hpp"
#include "../gameplay_navigation/bank.hpp"
#include <bit>
#include <exception>
#include <stdexcept>
#include <utility>

namespace reo::native::gameplay_world {
namespace {
std::shared_ptr<Session> admitted(std::shared_ptr<Session> session){
    if(!session)throw std::invalid_argument("Native primary world requires a session owner");
    return session;
}
}
World::World(Profile profile,std::shared_ptr<Session> session):session_(admitted(std::move(session))),
    mode(session_->mode),selected_actor(session_->selected_actor),paused(session_->paused),
    filter_nonselected_input(session_->authority_filter),room(session_->room),scenario(session_->scenario),frame_shared_counter(session_->actor_message_suppression),entities_(profile.entities),
    layouts_(std::move(profile.layouts)),controllers_(profile.controller_count){
    if(layouts_.empty() || layouts_.size()>256 || controllers_.empty() || controllers_.size()>128)
        throw std::invalid_argument("Native primary world requires an admitted session/input profile");
}
World::~World(){
    // Destroying an owner during its own active member call is a violated C++
    // lifetime precondition. It cannot be repaired by returning to that call.
    if(updating_||(linked_models_&&linked_models_->busy()))std::terminate();
    (void)close(); // Reentrant actor destruction sees a sealed, intact owner.
}
gameplay_navigation::Bank& World::navigation(){
    if(closed_)throw std::runtime_error("Native navigation owner is closed");
    if(!navigation_)navigation_.reset(new gameplay_navigation::Bank(session_->room_variants));
    return *navigation_;
}
TargetMetricCache& World::target_metrics(){
    if(closed_)throw std::runtime_error("Native target metric owner is closed");
    if(!target_metrics_)target_metrics_.reset(new TargetMetricCache(*this));
    return *target_metrics_;
}
actors::EntityCreated World::spawn_primary(std::size_t index,std::unique_ptr<Actor> actor)noexcept{
    if(closed_)return{actors::EntityStatus::closed,{}};
    if(index>=primary_.size() || !actor || primary_[index])return{actors::EntityStatus::invalid,{}};
    auto result=entities_.create(std::move(actor));
    if(result.status==actors::EntityStatus::completed)primary_[index]=result.id;
    return result;
}
actors::EntityStatus World::retire_primary(std::size_t index)noexcept{
    if(closed_)return actors::EntityStatus::closed;
    if(index>=primary_.size())return actors::EntityStatus::invalid;
    auto id=std::exchange(primary_[index],{});
    return entities_.retire(id);
}
actors::EntityCreated World::spawn_linked(std::unique_ptr<Actor> actor)noexcept{
    if(closed_)return{actors::EntityStatus::closed,{}};
    if(!actor)return{actors::EntityStatus::invalid,{}};
    return entities_.create(std::move(actor));
}
actors::EntityStatus World::retire_linked(const actors::EntityId& id)noexcept{
    if(closed_)return actors::EntityStatus::closed;
    for(const auto& primary:primary_)if(primary==id)return actors::EntityStatus::invalid;
    if(auxiliary_actors_&&auxiliary_actors_->physical_slot(id))return actors::EntityStatus::invalid;
    return entities_.retire(id);
}
LinkedModelPool& World::linked_models(){
    if(closed_)throw std::runtime_error("Native linked model owner is closed");
    if(!linked_models_)linked_models_.reset(new LinkedModelPool(*this));
    return *linked_models_;
}
AuxiliaryActorPool& World::auxiliary_actors(){
    if(closed_)throw std::runtime_error("Native auxiliary actor owner is closed");
    if(!auxiliary_actors_)auxiliary_actors_.reset(new AuxiliaryActorPool(*this));
    return *auxiliary_actors_;
}
std::shared_ptr<Actor> World::resolve(const actors::EntityId& id)const noexcept{
    if(closed_)return{};
    return std::dynamic_pointer_cast<Actor>(entities_.acquire(id));
}
std::shared_ptr<Actor> World::referenced_actor(const actors::ActorReference& reference)const noexcept{
    if(closed_)return{};
    switch(reference.kind){
    case actors::ActorReference::Kind::primary:return primary(reference.identifier);
    case actors::ActorReference::Kind::auxiliary:return auxiliary_actors_?resolve(auxiliary_actors_->find(reference.identifier)):nullptr;
    default:return{};
    }
}
actors::EntityId World::identity_of(const Actor& actor)const noexcept{
    return closed_?actors::EntityId{}:entities_.identity_of(actor);
}
std::shared_ptr<Actor> World::primary(std::size_t index)const noexcept{
    return index<primary_.size()?resolve(primary_[index]):nullptr;
}
actors::EntityId World::identity(std::size_t index)const noexcept{
    return index<primary_.size()?primary_[index]:actors::EntityId{};
}
Status World::close()noexcept{
    if(updating_||(linked_models_&&linked_models_->busy())||(auxiliary_actors_&&auxiliary_actors_->busy()))return Status::busy;
    closed_=true;primary_.fill({});
    if(linked_models_)(void)linked_models_->close();
    if(auxiliary_actors_)(void)auxiliary_actors_->close();
    if(navigation_)navigation_->close();
    if(target_metrics_)target_metrics_->close();
    entities_.shutdown();return Status::completed;
}
Result World::update_primary(Services& services){
    if(closed_)return{Status::closed};
    if(updating_)return{Status::busy};
    updating_=true;
    struct Finish {World& world;~Finish(){world.executing_.reset();world.updating_=false;}} finish{*this};
    Result result;
    if(mode==0)services.begin_offline_frame(*this);
    for(std::size_t index=0;index<primary_.size();++index){
        // Keep this generation alive for its admitted invocation, even if a
        // service retires/replaces the primary slot. The replacement is first
        // eligible on its next traversal; later slots are resolved afresh.
        auto lease=primary(index);if(!lease || !lease->active)continue;
        auto& actor=*lease;executing_=index;++result.visited;
        frame_shared_counter=0;actor.response_mask=0x1ffff;actor.response_value=0;
        actor.motion_override=0;actor.pending_notice=0;actor.interaction_marker=0;
        actor.contact_flags=0;actor.frame_value_a=actor.frame_value_b=0;
        actor.status&=0xddfdffff;actor.auxiliary_status&=~std::uint32_t(0x40);
        actor.movement_enabled=1;if(actor.normalized_marker==0xff)actor.normalized_marker=0;
        if(mode==0){selected_actor=actor.slot;if(actor.ai_control)services.run(Stage::offline_ai,*this,actor);}
        if(!paused && actor.room!=room){
            actor.visible=false;if(mode==0)services.run(Stage::leave_room,*this,actor);
            actor.room_marker=0;actor.status&=0xff7fbfff;actor.auxiliary_status&=0xfa9cfeff;continue;
        }
        if(!paused && !(actor.status&0x100))actor.visible=true;
        services.run(Stage::prepare_contacts,*this,actor);
        input::Routing routing; routing.mode=mode;routing.selected_actor=selected_actor;
        routing.layout=session_->options.controller_profile;routing.actor_ports=controller_bindings;
        const auto routed=input::route(actor.input,{actor.slot,actor.ai_control},routing,controllers_,layouts_);
        if(routed!=input::Routed::updated && routed!=input::Routed::skipped){result.status=Status::input_unavailable;return result;}
        actor.auxiliary_status&=0xfa9dffff;
        if(filter_nonselected_input && actor.slot!=selected_actor)actor.input={};
        services.run(Stage::prepare_authority,*this,actor);services.run(Stage::update_behavior,*this,actor);
        if(services.remote_motion(*this,actor)){services.run(Stage::update_pose,*this,actor);actor.contact_flags|=4;}
        else{services.run(Stage::update_local_motion,*this,actor);services.run(Stage::update_pose,*this,actor);}
        services.run(Stage::update_auxiliary_motion,*this,actor);services.run(Stage::finish_motion,*this,actor);
        if(actor.auxiliary_status&0x08000000){actor.auxiliary_status&=~std::uint32_t(0x08000000);services.run(Stage::refresh_grid_position,*this,actor);}
        std::int8_t selected{};
        if(services.find_grid(*this,actor,selected)){
            actor.status|=0x4000;
            if(std::int32_t(actor.grid)!=std::int32_t(selected))services.switch_grid(*this,selected,std::bit_cast<std::int8_t>(actor.grid));
            actor.grid=std::bit_cast<std::uint8_t>(selected);actor.grid_response+=services.grid_response(*this,actor.grid);actor.contact_flags|=1;
        }else{
            if((actor.status&0x4000) && !(actor.contact_flags&2)){services.switch_grid(*this,-1,std::bit_cast<std::int8_t>(actor.grid));actor.grid=0;}
            actor.status&=~std::uint32_t(0x4000);
        }
        services.run(Stage::finish_actor,*this,actor);
        if(actor.pending_notice){services.run(Stage::publish_notice,*this,actor);actor.pending_notice=0;}
        actor.room_marker=actor.transient_marker=0;actor.status&=~std::uint32_t(0x400000);
        if(actor.slot==selected_actor)selected_frame_marker=0;
        ++result.updated;
    }
    if(mode==0)selected_actor=0;
    return result;
}
} // namespace reo::native::gameplay_world
