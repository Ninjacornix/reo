#include "cinematic_actor_frames.hpp"
#include "scene_primary_actors.hpp"
#include "auxiliary_actors.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
CinematicActorFrames::CinematicActorFrames(World& world,Services& behavior,MotionTransformServices& pose):world_(world),frame_(world,behavior,pose){
    if(world_.closed()||world_.cinematic_frame_owner_)throw std::invalid_argument("Native cinematic frame owner unavailable or already bound");
    world_.cinematic_frame_owner_=this;
}
CinematicActorFrames::~CinematicActorFrames(){if(running_)std::terminate();(void)close();}
CinematicFrameStatus CinematicActorFrames::close()noexcept{
    if(running_)return CinematicFrameStatus::busy;
    closed_=true;if(world_.cinematic_frame_owner_==this)world_.cinematic_frame_owner_=nullptr;
    return CinematicFrameStatus::completed;
}
CinematicFramesUpdated CinematicActorFrames::run(){
    if(closed_||world_.closed())return{CinematicFrameStatus::closed};
    if(running_||world_.busy())return{CinematicFrameStatus::busy};
    bool* auxiliary_busy=nullptr;running_=world_.updating_=true;
    struct Reset{bool& running;bool& world;bool*& pool;~Reset(){if(pool)*pool=false;world=false;running=false;}}reset{running_,world_.updating_,auxiliary_busy};
    CinematicFramesUpdated result;
    const auto tick=[&](const actors::EntityId& id)->bool{
        const auto actor=world_.resolve(id);
        if(!actor){result.status=CinematicFrameStatus::unavailable;result.failed=id;return false;}
        if(!actor->active)return true;
        const auto restored=restore_secondary_pose_links(*actor);
        if(restored.status==SecondaryPoseLinksStatus::unavailable||restored.status==SecondaryPoseLinksStatus::no_memory){
            result.status=restored.status==SecondaryPoseLinksStatus::no_memory?CinematicFrameStatus::no_memory:CinematicFrameStatus::unavailable;result.failed=id;return false;
        }
        if(restored.status==SecondaryPoseLinksStatus::restored)++result.links_restored;
        frame_.tick(id);++result.called;return true;
    };
    if(const auto* temporary=world_.scene_primary_actors_.get();temporary&&temporary->initialized()){
        for(unsigned slot=0;slot<ScenePrimaryActorPool::capacity;++slot){
            ++result.temporary_visits;if(!tick(temporary->identity_at(slot)))return result;
        }
    }
    // The original reads the auxiliary head only after all fixed callbacks.
    if(auto* auxiliary=world_.auxiliary_actors_.get()){
        auxiliary_busy=&auxiliary->updating_;*auxiliary_busy=true;
        for(auto id=auxiliary->head();id;id=auxiliary->next(id)){
            ++result.auxiliary_visits;if(!tick(id))return result;
        }
    }
    return result;
}
}
