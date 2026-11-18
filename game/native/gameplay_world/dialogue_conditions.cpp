#include "dialogue_conditions.hpp"
#include "auxiliary_actors.hpp"
#include "linked_models.hpp"
#include "dialogue_inventory_traits.hpp"
#include "../gameplay_scenario/flags.hpp"
#include <algorithm>
#include <cmath>
#include <bit>
#include <new>
namespace reo::native::gameplay_world {
namespace {
template<class T>bool compare(std::uint8_t operation,T actual,T value)noexcept{
    switch(operation){case 0:return actual==value;case 1:return actual!=value;case 2:return actual<value;case 3:return actual>value;case 4:return actual<=value;case 5:return actual>=value;default:return false;}
}
bool equal(std::uint8_t operation,std::int32_t actual,std::int32_t value)noexcept{return operation<2&&compare(operation,actual,value);}
float distance(const Actor& a,const Actor& b)noexcept{
    const float x=a.position.x-b.position.x,z=a.position.z-b.position.z;
    return std::sqrt(std::max(0.f,(x*x)+(z*z)));
}
bool distance_matches(std::uint8_t operation,float actual,float threshold)noexcept{
    switch(operation){
    case 0:case 4:return actual<=threshold;
    case 1:case 3:return !(actual<=threshold);
    case 2:return actual<threshold;
    case 5:return !(actual<threshold);
    default:return false;
    }
}
bool has_leaf(std::uint8_t kind)noexcept{return kind<=0x30&&kind!=0x1c&&kind!=0x2d;}
}
DialogueConditionResult evaluate_dialogue_condition(World& world,const DialoguePool* pool,
    const gameplay_scenario::DialogueCondition& condition,const actors::EntityId& id,const DialogueConditionBindings& bindings)noexcept{
    const auto result=[](bool value){return DialogueConditionResult{DialogueStatus::completed,std::int16_t(value)};};
    const auto unavailable=[](){return DialogueConditionResult{DialogueStatus::unavailable,0};};
    if(world.closed())return{DialogueStatus::closed,0};
    if(condition.kind==255)return result(true);
    if(!has_leaf(condition.kind))return result(false);
    const auto operation=condition.comparison;const auto value=condition.value;
    if(condition.kind==0||condition.kind==1){
        if(!pool||!pool->bound_to(world))return unavailable();
        const auto flag=pool->flag(condition.parameter);if(!flag)return unavailable();
        if(condition.kind==0)return result(equal(operation,*flag?1:0,value));
        if(!*flag)return result(false);
        // Source flag duration divides signed wrapped ticks by30/60, unlike
        // the two unsigned actor elapsed fields which always divide by60.
        if(operation>=6)return result(false);
        const auto duration=pool->flag_duration(condition.parameter);if(!duration)return unavailable();
        return result(compare(operation,*duration/(world.session().clock_mode?30:60),value));
    }
    if(condition.kind==14){const auto sample=std::int32_t(world.session().random.request(1)%10);return result(compare(operation,sample,value));}
    if(condition.kind==27){const auto population=world.session().primary_population;if(!population)return unavailable();return result(compare(operation,std::int32_t(std::uint8_t(*population)),value));}
    if(condition.kind==6||condition.kind==7){
        std::int32_t count{};
        for(std::size_t i=0;i<World::primary_capacity;++i){
            const auto candidate=world.primary(i);
            if(!candidate||!candidate->active||candidate->slot==world.selected_actor)continue;
            if(condition.kind==6){
                if(!candidate->visible)continue;
                const auto selected=world.primary(world.selected_actor);
                if(!selected)return unavailable();
                if(candidate->room!=selected->room)continue;
            }
            ++count;
        }
        return result(compare(operation,count,value));
    }
    if(condition.kind==8){
        if(condition.parameter>=World::primary_capacity)return{DialogueStatus::unsupported_profile,0};
        const auto selected=world.primary(condition.parameter);
        const bool excluded=!selected||!selected->active||(selected->status&0x5e0u);
        return result(operation==(excluded?1:0));
    }
    bool auxiliary_unavailable{};
    const auto auxiliary=[&](std::int32_t identifier)->std::shared_ptr<Actor>{
        try{return world.resolve(world.auxiliary_actors().find(std::uint32_t(identifier),true));}
        catch(const std::bad_alloc&){auxiliary_unavailable=true;return{};}
    };
    if(condition.kind==9){
        const auto selected=auxiliary(condition.parameter);
        if(auxiliary_unavailable)return{DialogueStatus::no_memory,0};
        if(!selected)return result(false);
        return result(operation==((selected->status&0x5e0u)?1:0));
    }
    if(condition.kind==15||condition.kind==47){
        if(!bindings.flags)return unavailable();
        const auto flag=bindings.flags->get(condition.kind==15?gameplay_scenario::FlagBank::scenario:gameplay_scenario::FlagBank::bounded_byte,condition.parameter);
        if(!flag)return unavailable();
        if(condition.kind==15)return result(*flag);
        return result(operation?(std::int32_t(*flag)!=value):(std::int32_t(*flag)==value));
    }
    const auto actor=world.resolve(id);if(!actor)return unavailable();
    switch(condition.kind){
    case 2:{
        if(!bindings.resources)return unavailable();
        const auto resource=bindings.resources->find_inventory_content(actor->inventory,condition.parameter);
        return result(bool(resource)==bool(value));
    }
    case 35:{
        const auto trait=dialogue_inventory_trait(*actor,bindings.resources,bindings.templates,condition.parameter);
        if(!trait)return unavailable();
        return result(operation<2&&(*trait==bool(value))==(operation==0));
    }
    case 10:case 11:{
        if(!actor->speech.selection)return unavailable();
        const auto& speech=*actor->speech.selection;
        if(speech.target_context>=0||speech.target_identifier<0)return result(false);
        return result(equal(operation,speech.target_identifier,value));
    }
    case 12:case 13:{
        if(!actor->speech.selection)return unavailable();
        const auto& speech=*actor->speech.selection;
        if(speech.target_context<0||speech.target_identifier<0)return result(false);
        AuxiliaryActorPool* auxiliary_pool{};
        try{auxiliary_pool=&world.auxiliary_actors();}catch(const std::bad_alloc&){return{DialogueStatus::no_memory,0};}
        for(auto candidate_id=auxiliary_pool->head();candidate_id;candidate_id=auxiliary_pool->next(candidate_id)){
            const auto candidate=world.resolve(candidate_id);
            if(!candidate)return unavailable();
            // Source inactive branch skips the next-pointer load and would
            // repeat this same node forever. Preserve that admission boundary.
            if(!candidate->active)return{DialogueStatus::unsupported_profile,0};
            if(candidate->model_variant==speech.target_identifier)return result(equal(operation,candidate->model_variant,value));
        }
        return result(false);
    }
    case 20:case 22:case 26:{
        if(!actor->speech.selection)return unavailable();
        const auto& speech=*actor->speech.selection;
        std::shared_ptr<Actor> selected;
        if(speech.target_context>=0){
            selected=auxiliary(speech.target_identifier);
            if(auxiliary_unavailable)return{DialogueStatus::no_memory,0};
            if(!selected)return result(false);
        }else if(speech.target_identifier<0)return result(false);
        // Actual5F87D0 checks that an auxiliary target exists, then still
        // reads the primary array at that target identifier. Preserve it.
        if(condition.kind==20||speech.target_context<0){
            if(std::uint32_t(speech.target_identifier)>=World::primary_capacity)return{DialogueStatus::unsupported_profile,0};
            selected=world.primary(std::uint16_t(speech.target_identifier));
            if(!selected)return unavailable();
        }
        if(condition.kind==20)return result(compare(operation,std::int32_t(selected->current),value));
        if(condition.kind==26)return result(std::int32_t(selected->motion_class)==value);
        if(operation>1||std::uint32_t(value)>5||value==3)return result(false);
        constexpr std::array<std::uint32_t,6> masks{0x33,1,2,0,0x10,0x20};
        const bool set=bool(selected->status&masks[std::size_t(value)]);
        return result(value==0?(operation==0?!set:set):(operation==0?set:!set));
    }
    case 16:return result(equal(operation,actor->room,value));
    case 19:return result(compare(operation,std::int32_t(actor->current),value));
    case 21:{
        if(operation>1||std::uint32_t(value)>6)return result(false);
        // Jump-table entry3 always returns0, even for inverse comparisons.
        if(value==3)return result(false);
        constexpr std::array<std::uint32_t,7> masks{0xb3,1,2,0,0x10,0x20,0x80};
        const bool set=bool(actor->status&masks[std::size_t(value)]);
        return result(value==0?(operation==0?!set:set):(operation==0?set:!set));
    }
    case 17:case 18:case 33:{
        LinkedModelPool* linked{};
        try{linked=&world.linked_models();}catch(const std::bad_alloc&){return{DialogueStatus::no_memory,0};}
        std::int32_t count{};bool any{};
        for(std::size_t i=0;i<LinkedModelPool::capacity;++i){
            const auto candidate=world.resolve(linked->identity_at(i));
            if(!candidate||!candidate->active||!candidate->visible||(candidate->action_flags&1))continue;
            if(condition.kind==33){++count;continue;}
            if(!candidate->targeting)return unavailable();
            if(candidate->targeting->flags&8)continue;
            const auto threshold=condition.kind==17?800.f:float(condition.parameter);
            any=distance_matches(operation,distance(*candidate,*actor),threshold)||any;
        }
        if(condition.kind==33)return result(compare(operation==1?std::uint8_t(3):operation,count,value));
        return result(std::int32_t(any)==value);
    }
    case 31:case 32:case 44:{
        bool any{};
        for(std::size_t i=0;i<World::primary_capacity;++i){
            const auto candidate=world.primary(i);
            if(!candidate||!candidate->active||!candidate->visible||candidate->room!=actor->room)continue;
            if(candidate==actor&&(condition.kind!=44||actor->category==0))continue;
            const auto threshold=condition.kind==31?800.f:condition.kind==32?200.f:float(condition.parameter);
            any=distance_matches(operation,distance(*candidate,*actor),threshold)||any;
        }
        return result(value?any:!any);
    }
    case 23:return result(compare(operation,actor->control_elapsed/60u,std::uint32_t(value)));
    case 24:return result(compare(operation,actor->action_elapsed/60u,std::uint32_t(value)));
    case 25:return result(std::int32_t(actor->motion_class)==value);
    case 29:{if(!actor->related_target_state)return unavailable();const bool same=std::uint8_t(*actor->related_target_state)==condition.parameter;return result(operation==(same?0:1));}
    case 46:{
        if(!actor->speech.variant)return unavailable();
        const auto variant=*actor->speech.variant;
        if(!variant||(std::uint8_t(variant)&0x80))return result(false);
        return result(operation?variant!=value:variant==value);
    }
    case 48:{
        if(!actor->speech.variant)return unavailable();
        const auto variant=std::uint8_t(*actor->speech.variant);
        if(!(variant&0x80))return result(false);
        const auto index=unsigned(variant&0x7f);
        if(index>=4)return{DialogueStatus::unsupported_profile,0};
        if(!actor->speech.partner_characters)return unavailable();
        const auto character=std::int32_t((*actor->speech.partner_characters)[index]);
        return result(operation?character!=value:character==value);
    }
    default:return{DialogueStatus::unsupported_profile,0};
    }
}
} // namespace reo::native::gameplay_world
