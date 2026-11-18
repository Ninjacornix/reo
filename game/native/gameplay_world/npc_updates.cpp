#include "npc_updates.hpp"
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
float finite(float value){if(!std::isfinite(value))throw std::domain_error("Native NPC camera finite profile required");return value;}
}
bool npc_camera_suppressed(const World& world,Position actor,Position camera){
    if(world.paused!=0)return false;
    // Complete5C0870 selector1: raise the actor probe by100, then compare the
    // ordered FP32 Euclidean distance strictly against owned threshold80.
    const float x=finite(finite(actor.x)-finite(camera.x));
    const float y=finite(finite(finite(actor.y)+100.f)-finite(camera.y));
    const float z=finite(finite(actor.z)-finite(camera.z));
    const float distance=std::sqrt(finite(finite(finite(x*x)+finite(y*y))+finite(z*z)));
    return distance<80.f;
}
NpcActorUpdates::NpcActorUpdates(World& world,Services& behavior,MotionTransformServices& pose,
    const Position& camera,const std::uint8_t& inhibition,NpcAttachmentFrames* attachments):world_(world),frame_(world,behavior,pose),camera_(camera),inhibition_(inhibition),attachments_(attachments){
    if(world_.closed()||world_.npc_update_owner_)throw std::invalid_argument("Native NPC update owner unavailable or already bound");
    (void)world_.auxiliary_actors();world_.npc_update_owner_=this;
}
NpcActorUpdates::~NpcActorUpdates(){if(running_)std::terminate();(void)close();}
NpcUpdateStatus NpcActorUpdates::close()noexcept{
    if(running_)return NpcUpdateStatus::busy;
    closed_=true;if(world_.npc_update_owner_==this)world_.npc_update_owner_=nullptr;
    return NpcUpdateStatus::completed;
}
NpcUpdated NpcActorUpdates::run(){
    if(closed_||world_.closed())return{NpcUpdateStatus::closed};
    auto& pool=world_.auxiliary_actors();
    if(running_||world_.busy())return{NpcUpdateStatus::busy};
    running_=true;pool.updating_=true;world_.updating_=true;
    struct Reset{bool& running;bool& pool;bool& world;~Reset(){world=false;pool=false;running=false;}}reset{running_,pool.updating_,world_.updating_};
    NpcUpdated result;
    for(auto id=pool.head();id;id=pool.next(id)){
        const auto actor=world_.resolve(id);++result.visited;
        if(!actor){result.status=NpcUpdateStatus::unavailable;return result;}
        if(!actor->active||!actor->visible||npc_camera_suppressed(world_,actor->position,camera_)||inhibition_){actor->collision.pose_ready=false;++result.suppressed;continue;}
        if(!actor->npc){result.status=NpcUpdateStatus::unavailable;return result;}
        frame_.tick(id);++result.called;
        if(world_.resolve(id)!=actor||!actor->npc){result.status=NpcUpdateStatus::unavailable;return result;}
        actor->collision.pose_ready=true;
        const auto slot=actor->npc->attachment;
        if(!slot)continue;
        if(*slot>=4||!attachments_){result.status=NpcUpdateStatus::unavailable;return result;}
        const bool active=attachments_->active(world_,*slot);
        if(world_.resolve(id)!=actor||!actor->npc||actor->npc->attachment!=slot){result.status=NpcUpdateStatus::unavailable;return result;}
        if(active){
            if(!attachments_->update(world_,id,*slot,actor->model_variant)){result.status=NpcUpdateStatus::unavailable;return result;}
            ++result.attachments;
            if(world_.resolve(id)!=actor){result.status=NpcUpdateStatus::unavailable;return result;}
        }
    }
    return result;
}
}
