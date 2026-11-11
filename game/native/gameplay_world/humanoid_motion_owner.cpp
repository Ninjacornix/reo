#include "humanoid_motion_owner.hpp"
#include <algorithm>
#include <stdexcept>
#include <new>
namespace reo::native::gameplay_world {
HumanoidMotionOwner::HumanoidMotionOwner(World& world):world_(world){
    if(world_.closed()||world_.busy()||world_.humanoid_motion_source_)throw std::invalid_argument("Native humanoid motion owner unavailable or already bound");
    world_.humanoid_motion_source_=this;world_.humanoid_motion_source_closed_=false;
}
HumanoidMotionOwner::~HumanoidMotionOwner(){if(running_||world_.busy())std::terminate();(void)close();}
std::shared_ptr<const animation::MotionBank> HumanoidMotionOwner::bank(HumanoidMotionAlias alias)const noexcept{
    return !closed_&&!world_.closed()&&current_?current_->bank(alias):nullptr;
}
HumanoidPublicationStatus HumanoidMotionOwner::close()noexcept{
    if(running_||world_.busy())return HumanoidPublicationStatus::busy;
    closed_=true;
    if(world_.humanoid_motion_source_==this){world_.humanoid_motion_source_=nullptr;world_.humanoid_motion_source_closed_=true;}
    current_.reset();return HumanoidPublicationStatus::completed;
}
HumanoidPublished HumanoidMotionOwner::publish(std::shared_ptr<const HumanoidMotionBanks> candidate)noexcept{
    return publish_nested(std::move(candidate),false);
}
HumanoidPublished HumanoidMotionOwner::publish_nested(std::shared_ptr<const HumanoidMotionBanks> candidate,bool nested)noexcept{
    if(closed_||world_.closed())return{HumanoidPublicationStatus::closed};
    if(running_||(world_.busy()&&!nested)||(nested&&!world_.updating_))return{HumanoidPublicationStatus::busy};
    if(!candidate)return{};
    if(current_&&!candidate->follows(*current_))return{HumanoidPublicationStatus::stale};
    const bool previous_busy=world_.updating_;running_=true;world_.updating_=true;
    struct Reset{bool& running;bool& world;bool previous;~Reset(){world=previous;running=false;}}reset{running_,world_.updating_,previous_busy};
    try{
        struct Plan {
            std::shared_ptr<Actor> actor;std::shared_ptr<animation::Playback> playback;
            // Retain all old resources until the complete publication is visible.
            std::array<std::shared_ptr<const animation::MotionBank>,3> previous,next;
        };
        std::vector<Plan> plans;HumanoidPublished result{HumanoidPublicationStatus::completed,0,0,current_!=candidate};
        for(const auto& id:world_.entities_.identities()){
            const auto actor=world_.resolve(id);
            if(!actor)return{};
            if(std::none_of(actor->motion_bank_aliases.begin(),actor->motion_bank_aliases.end(),[](const auto& alias){return alias.has_value();}))continue;
            if(!actor->animation||!actor->animation->resources_known||actor->animation->model()!=actor->model)return{};
            Plan plan{actor,actor->animation,actor->animation->resources,actor->animation->resources};
            for(unsigned index=0;index<actor->motion_bank_aliases.size();++index){
                if(!actor->motion_bank_aliases[index])continue;
                auto resource=candidate->bank(*actor->motion_bank_aliases[index]);if(!resource)return{};
                plan.next[index]=std::move(resource);++result.bindings;
            }
            plans.push_back(std::move(plan));++result.actors;
        }
        const auto previous=std::move(current_);current_=std::move(candidate);
        (void)previous;
        for(auto& plan:plans)plan.playback->resources=std::move(plan.next);
        return result;
    }catch(const std::bad_alloc&){return{HumanoidPublicationStatus::no_memory};}
    catch(...){return{};}
}
}
