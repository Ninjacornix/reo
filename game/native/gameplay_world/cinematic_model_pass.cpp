#include "cinematic_model_pass.hpp"
#include "scene_primary_actors.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
CinematicModelPass::~CinematicModelPass(){if(running_)std::terminate();}
CinematicModelsPublished CinematicModelPass::run(){
    if(world_.closed())return{CinematicModelStatus::closed};
    if(running_||world_.busy())return{CinematicModelStatus::busy};
    running_=world_.updating_=true;
    struct Reset{bool& running;bool& world;~Reset(){world=false;running=false;}}reset{running_,world_.updating_};
    CinematicModelsPublished result;
    if(const auto* pool=world_.scene_primary_actors_.get();pool&&pool->initialized()){
        for(unsigned slot=0;slot<ScenePrimaryActorPool::capacity;++slot){
            const auto actor=world_.resolve(pool->identity_at(slot));++result.visited;
            if(!actor)throw std::runtime_error("Cinematic native model actor identity unavailable");
            if(!actor->active)continue;
            rebuild_cinematic_primary_model(world_,*actor,scales_);++result.published;
        }
    }
    return result;
}
}
