#include "dialogue_targeting.hpp"
#include "auxiliary_actors.hpp"
#include "../transform_math/heading.hpp"
#include <bit>
#include <cmath>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
float distance(const Actor& from,const Actor& to){
    const float x=to.position.x-from.position.x,y=to.position.y-from.position.y,z=to.position.z-from.position.z;
    const float xx=x*x,yy=y*y,zz=z*z,sum=xx+yy,total=sum+zz,result=std::sqrt(total);
    if(!std::isfinite(result))throw std::domain_error("Native dialogue target finite distance required");
    return result;
}
}
DialogueStatus update_dialogue_target(World& world,const actors::EntityId& id)noexcept{
    if(world.closed())return DialogueStatus::closed;
    const auto actor=world.resolve(id);if(!actor||!actor->speech.selection)return DialogueStatus::unavailable;
    try{
        std::array<std::shared_ptr<Actor>,18> candidates;std::size_t count{};
        for(std::size_t i=0;i<World::primary_capacity;++i){const auto candidate=world.primary(i);if(candidate&&candidate->active&&candidate->visible)candidates[count++]=candidate;}
        auto& auxiliary=world.auxiliary_actors();
        for(auto next=auxiliary.head();next;next=auxiliary.next(next)){
            const auto candidate=world.resolve(next);if(!candidate)return DialogueStatus::unavailable;
            if(candidate->active&&candidate->visible){if(count==candidates.size())return DialogueStatus::unsupported_profile;candidates[count++]=candidate;}
        }
        float best=100.f;std::uint16_t identifier=65535,context=65535;
        for(std::size_t i=0;i<count;++i){const auto& candidate=*candidates[i];if(!candidate.active)continue;
            if((candidate.category==0&&candidate.slot==actor->slot)||candidate.room!=actor->room)continue;
            const auto bearing=transform_math::direction_turn(candidate.position.x-actor->position.x,candidate.position.z-actor->position.z);
            const auto delta=std::bit_cast<std::int16_t>(std::uint16_t(bearing-std::bit_cast<std::uint16_t>(actor->orientation[1])));
            if(!(std::fabs(float(delta))<24576.f))continue;
            const auto separation=distance(*actor,candidate);if(best<=separation)continue;
            best=separation;
            if(candidate.category==0){identifier=candidate.character;context=65535;}
            else{identifier=candidate.model_variant;context=actor->slot;}
        }
        if(!actor->speech.target_lock)return DialogueStatus::unavailable;
        auto& speech=*actor->speech.selection;
        if(*actor->speech.target_lock){
            if(speech.target_context<0){
                if(speech.target_identifier>=0){
                    if(std::uint16_t(speech.target_identifier)>=World::primary_capacity)return DialogueStatus::unsupported_profile;
                    const auto target=world.primary(std::uint16_t(speech.target_identifier));if(!target)return DialogueStatus::unavailable;
                    if(distance(*actor,*target)<300.f)return DialogueStatus::completed;
                }
            }else{
                for(auto next=auxiliary.head();next;next=auxiliary.next(next)){
                    const auto target=world.resolve(next);if(!target)return DialogueStatus::unavailable;
                    if(target->active&&target->model_variant==speech.target_identifier&&distance(*actor,*target)<300.f)return DialogueStatus::completed;
                }
            }
        }
        // The source zero-extends the nearest identifier before its signed
        // branch, so the branch is always taken; DC5 clears in its delay slot.
        actor->speech.target_lock=0;speech.target_identifier=std::bit_cast<std::int16_t>(identifier);speech.target_context=std::bit_cast<std::int8_t>(std::uint8_t(context));
        if(actor->category){speech.target_identifier=-1;speech.target_context=-1;}
        return DialogueStatus::completed;
    }catch(const std::bad_alloc&){return DialogueStatus::no_memory;}
    catch(const std::domain_error&){return DialogueStatus::unsupported_profile;}
}
}
