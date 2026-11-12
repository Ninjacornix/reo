#include "actor_model_passes.hpp"
#include <exception>
#include <stdexcept>
namespace reo::native::gameplay_world {
ActorModelPasses::ActorModelPasses(World& world,const ModelCorrectionScales& scales,
    WorldResourceAttachments& attachments,std::shared_ptr<const gameplay_collision::response::Grid> floors)
    :world_(world),scales_(scales),attachments_(attachments),floors_(std::move(floors)){
    if(world_.closed()||!attachments_.bound_to(world_))
        throw std::invalid_argument("Native actor model passes require the canonical World/resource owner");
    (void)world_.auxiliary_actors();
}
ActorModelPasses::~ActorModelPasses(){if(running_)std::terminate();(void)close();}
ActorModelPassStatus ActorModelPasses::close()noexcept{
    if(running_||world_.busy())return ActorModelPassStatus::busy;
    closed_=true;return ActorModelPassStatus::completed;
}
ActorModelsPublished ActorModelPasses::primary(){
    if(closed_||world_.closed())return{ActorModelPassStatus::closed};
    if(running_||world_.busy())return{ActorModelPassStatus::busy};
    running_=world_.updating_=true;
    struct Reset{bool& running;bool& updating;~Reset(){updating=running=false;}}reset{running_,world_.updating_};
    ActorModelsPublished result;
    for(std::size_t slot=0;slot<World::primary_capacity;++slot){
        ++result.visited;
        const auto id=world_.identity(slot);const auto actor=world_.resolve(id);
        if(!actor||!actor->active)continue;
        result.failed=id;
        (void)rebuild_primary_model_with_attachments(world_,id,scales_,floors_.get(),attachments_);
        if(world_.resolve(id)!=actor){result.status=ActorModelPassStatus::unavailable;return result;}
        ++result.published;
    }
    result.failed={};return result;
}
ActorModelsPublished ActorModelPasses::auxiliary(){
    if(closed_||world_.closed())return{ActorModelPassStatus::closed};
    if(running_||world_.busy())return{ActorModelPassStatus::busy};
    auto& pool=world_.auxiliary_actors();
    if(pool.busy()||pool.closed_)return{ActorModelPassStatus::unavailable};
    running_=world_.updating_=pool.updating_=true;
    struct Reset{bool& running;bool& world;bool& pool;~Reset(){pool=world=running=false;}}reset{running_,world_.updating_,pool.updating_};
    ActorModelsPublished result;
    for(auto id=pool.head();id;id=pool.next(id)){
        ++result.visited;const auto actor=world_.resolve(id);
        if(!actor){result.status=ActorModelPassStatus::unavailable;result.failed=id;return result;}
        if(!actor->active)continue;
        result.failed=id;
        rebuild_standard_model(world_,*actor,ModelPoseKind::linked_actor,scales_);
        if(world_.resolve(id)!=actor){result.status=ActorModelPassStatus::unavailable;return result;}
        attachments_.bind(id,actor->selected_resource,19);
        if(world_.resolve(id)!=actor){result.status=ActorModelPassStatus::unavailable;return result;}
        ++result.published;
    }
    result.failed={};return result;
}
}
