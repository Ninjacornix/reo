#include "actor_ownership_copy.hpp"
#include "../animation/playback.hpp"
#include "../animation/constraints.hpp"
#include <new>
namespace reo::native::gameplay_world {
ActorCopied copy_actor_owned(const Actor& source)noexcept{
    if((source.animation&&source.animation->model()!=source.model)||(source.constraints&&!source.constraints->model()))return{ActorCopyStatus::inconsistent_model,{}};
    try{
        auto next=std::make_unique<Actor>(source);
        if(source.animation){next->animation=source.animation->clone_independent();next->model=next->animation->model();}
        else if(source.model)next->model=std::make_shared<animation::Instance>(*source.model);
        if(source.constraints){
            const auto& previous=source.constraints->model();std::shared_ptr<animation::Instance> model;
            if(previous==source.model)model=next->model;
            else if(source.animation&&previous==source.animation->secondary_model())model=next->animation->secondary_model();
            else model=std::make_shared<animation::Instance>(*previous);
            next->constraints=source.constraints->clone_for_model(std::move(model));
        }
        return{ActorCopyStatus::completed,std::move(next)};
    }catch(const std::bad_alloc&){return{ActorCopyStatus::no_memory,{}};}catch(...){return{ActorCopyStatus::unavailable,{}};}
}
}
