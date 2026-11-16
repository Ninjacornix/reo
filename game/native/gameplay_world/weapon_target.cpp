#include "weapon_target.hpp"
#include "target_metrics.hpp"
#include "linked_models.hpp"
#include "../animation/model.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
#include "weapon_target_profile.inc"
[[noreturn]] void unavailable(){throw std::runtime_error("Native weapon targeting producer unavailable");}
}
actors::EntityId select_weapon_target(World& world,Actor& actor,float maximum_distance){
    const auto self=world.identity_of(actor);
    if(!self||world.closed())unavailable();
    const auto* metrics=world.target_metrics().state();
    if(!metrics)unavailable();
    if(world.mode==0&&actor.category==0&&actor.ai_control){
        if(!actor.ai_target)unavailable();
        if(*actor.ai_target){
            const auto target=world.resolve(*actor.ai_target);
            const auto slot=world.linked_models().physical_slot(*actor.ai_target);
            if(!target||!slot||actor.slot>=metrics->primary_linked.size()||
               metrics->primary_identity[actor.slot]!=self||metrics->linked_identity[*slot]!=*actor.ai_target)unavailable();
            const auto& metric=metrics->primary_linked[actor.slot][*slot];
            if(!metric)unavailable();
            if(metric->wall||metric->floor){actor.aim_target_index=255;return {};}
            actor.aim_target_index=target->character;return *actor.ai_target;
        }
    }
    const std::array<std::uint8_t,50>* order{};
    const std::array<std::optional<TargetLinkedMetric>,50>* row{};
    if(actor.category==0){
        if(actor.slot>=metrics->primary_linked.size()||metrics->primary_identity[actor.slot]!=self)unavailable();
        order=&metrics->primary_linked_order[actor.slot];row=&metrics->primary_linked[actor.slot];
    }else{
        if(actor.slot>=metrics->auxiliary_linked.size()||metrics->auxiliary_identity[actor.slot]!=self)unavailable();
        order=&metrics->auxiliary_linked_order[actor.slot];row=&metrics->auxiliary_linked[actor.slot];
    }
    for(const auto slot:*order){
        if(slot==255)break;
        if(slot>=metrics->linked_identity.size())unavailable();
        const auto id=world.linked_models().identity_at(slot);
        const auto target=world.resolve(id);
        if(!target||metrics->linked_identity[slot]!=id||!target->targeting)unavailable();
        if(target->targeting->flags&1u)continue;
        const auto& metric=(*row)[slot];if(!metric)unavailable();
        if(!(metric->pair.distance<=maximum_distance))continue;
        if(!target->targeting->model_point||!target->model||!target->model->retain()||
           *target->targeting->model_point>=target->model->nodes().size())unavailable();
        const auto point=target->model->world_translation(*target->targeting->model_point);
        if(!(point.y-actor.position.y<=300.f))continue;
        if(!(actor.position.y-target->position.y<=100.f)||metric->wall)continue;
        const auto difference=std::bit_cast<std::int16_t>(std::uint16_t(metric->pair.bearing-std::uint16_t(actor.orientation[1])));
        if(actor.character>=aim_angles.size())unavailable();
        if(!(std::fabs(float(difference))<=float(aim_angles[actor.character])))continue;
        actor.aim_target_pitch=0;
        actor.aim_target_yaw=std::bit_cast<std::int16_t>(metric->pair.bearing);
        actor.aim_target_roll=0;actor.aim_pitch_adjustment=0;
        actor.aim_target_index=target->character;return id;
    }
    actor.aim_target_index=255;return {};
}
void prepare_weapon_target(World& world,Actor& actor,bool automatic){
    if(!world.identity_of(actor)||world.closed())unavailable();
    if(automatic){
        if(actor.resource_action>=aim_range_hundreds.size())unavailable();
        actor.weapon_target=select_weapon_target(world,actor,100.f*float(aim_range_hundreds[actor.resource_action]));
    }else{actor.weapon_target=actors::EntityId{};actor.aim_target_index=255;}
}
}
