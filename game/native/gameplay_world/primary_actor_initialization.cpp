#include "primary_actor_initialization_internal.hpp"
#include "primary_custom_statistics.hpp"
#include "model_constraints.hpp"
#include "motion_profiles.hpp"
#include "enemy_initialization.hpp"
#include "../gameplay_actors/health_class.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
#include "../gameplay_scenario/resource_templates.hpp"
#include "../gameplay_update/update.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
#include "primary_actor_definitions.inc"
void finish(Actor& actor){actor.auxiliary_status=(actor.auxiliary_status|2u)&0xffff3fffu;actor.color_fade=ColorFade{0xffffffffu,0,0};}
}
const PrimaryDefaultDefinition& primary_actor_default(std::uint8_t character){
    if(character>=primary_default_definitions.size())throw std::out_of_range("Native primary character profile unavailable");
    return primary_default_definitions[character];
}
PrimaryInitializationStatus PrimaryActorInitialization::defaults(World& world,actors::EntityId id,std::uint8_t character,const HumanoidMotionBanks& banks,bool custom,const PrimaryEquipmentContext* equipment,bool nested)noexcept{
        if(world.closed())return PrimaryInitializationStatus::closed;
        if((world.busy()&&!nested)||(nested&&!world.updating_))return PrimaryInitializationStatus::busy;
        const auto actor=world.resolve(id);
        if(!actor||(!custom&&(actor->model_variant||world.session().primary_initialization_snapshot))||character>=8||actor->slot>=World::primary_capacity||world.primary(actor->slot)!=actor||!actor->model_asset||!actor->model||!actor->animation||actor->animation->model()!=actor->model)return PrimaryInitializationStatus::unavailable;
        const bool previous_busy=world.updating_;world.updating_=true;struct Reset{bool& value;bool previous;~Reset(){value=previous;}}reset{world.updating_,previous_busy};
        try{
            const auto& definition=primary_actor_default(character);
            const auto substitution=actor->model_variant?&primary_substitution_definition(actor->model_variant):nullptr;
            const auto style=substitution?npc_actor_definition(std::uint16_t(actor->model_variant-1)).motion_style:std::bit_cast<std::uint8_t>(definition.motion_style);
            const std::array<HumanoidMotionAlias,3> aliases{{{HumanoidMotionFamily::primary,0},{style?HumanoidMotionFamily::alternate:HumanoidMotionFamily::general,0},{HumanoidMotionFamily::character,character}}};
            std::array<std::shared_ptr<const animation::MotionBank>,3> resources;
            for(unsigned i=0;i<aliases.size();++i){resources[i]=resolve_humanoid_motion_bank(world,aliases[i],banks.bank(aliases[i]));if(!resources[i])return PrimaryInitializationStatus::unavailable;}
            PrimaryActorState state;state.model_group=character;state.default_motion_aliases=aliases;state.part_visibility.assign(actor->model_asset->part_count(),1);
            if(actor->model_pose_class!=1&&state.part_visibility.size()>1)state.part_visibility[1]=0;
            if(actor->model_pose_class!=1&&substitution)for(unsigned part=0;part<std::min<std::size_t>(32,state.part_visibility.size());++part)if(substitution->hidden_parts&(1u<<part))state.part_visibility[part]=0;
            gameplay_collision::hit_regions::Regions regions;regions.set(std::vector(definition.hit_regions.begin(),definition.hit_regions.end()));
            const File1MotionProfiles profiles;const auto body=profiles.body(character,0);const auto shape=profiles.shape(character,0).target;
            // Old leases retire after all observable stores, while World is busy.
            const auto previous_resources=actor->animation->resources;auto previous_state=std::move(actor->primary_state);
            (void)previous_resources;(void)previous_state;
            actor->primary_state=std::move(state);actor->active=true;actor->contact.authored_id=actor->slot;actor->category=0;actor->character=character;
            if(substitution){const auto status=apply_primary_custom_statistics(*actor,world.session().random);if(status!=PrimaryInitializationStatus::completed)return status;}
            else{
                actor->motion_style=std::bit_cast<std::uint8_t>(definition.motion_style);actor->motion_subtype=definition.motion_subtype;
                actor->current=actor->maximum=definition.health;actor->model_scale=definition.scale;actor->model_height_correction=definition.height_correction;actor->primary_state->statistic_multiplier=1;actor->contact.damage_scale=1;
            }
            if(world.session().primary_initialization_snapshot){
                const auto& saved=(*world.session().primary_initialization_snapshot)[actor->slot];
                actor->current=saved.health;actor->class_marker=saved.class_marker;actor->selected_resource=saved.selected_resource;
                if(actor->selected_resource&&!equipment)return PrimaryInitializationStatus::unavailable;
                const auto action=actor->selected_resource?equipment->resources.action_kind(actor->selected_resource,equipment->templates):std::int8_t(0);
                actor->resource_action=std::uint16_t(std::int16_t(action));
            }
            const std::array<float,2> thresholds{50,25};
            if(actors::derive_health_class(*actor,thresholds)==actors::ClassResult::invalid_maximum)return PrimaryInitializationStatus::unavailable;
            actor->previous_motion_class=actor->class_marker;actor->primary_state->model_adjustment={};
            actor->animation->resources=std::move(resources);actor->motion_bank_aliases={aliases[0],aliases[1],aliases[2]};actor->animation->resources_known=true;actor->animation->channel_count=5;
            actor->local_impulse=actor->world_impulse={};actor->motion_multiplier=1;
            actor->collision.body_definition=body;actor->collision.local_center=actor->collision.previous_local_center=shape.center;actor->collision.radius=actor->collision.previous_radius=shape.radius;actor->collision.interpolation_target=shape;
            actor->contact.regions=std::move(regions);actor->primary_state->initialization_marker=0;
            initialize_model_constraints(world,*actor);
            const auto priority=actor_body_priority(world,*actor);if(!priority)return PrimaryInitializationStatus::unavailable;actor->collision.body_priority=*priority;
            finish(*actor);return PrimaryInitializationStatus::completed;
        }catch(const std::bad_alloc&){return PrimaryInitializationStatus::no_memory;}catch(...){return PrimaryInitializationStatus::unavailable;}
    }
PrimaryInitializationStatus PrimaryActorInitialization::restore(World& world,actors::EntityId id,bool nested)noexcept{
        if(world.closed())return PrimaryInitializationStatus::closed;
        if((world.busy()&&!nested)||(nested&&!world.updating_))return PrimaryInitializationStatus::busy;
        const auto actor=world.resolve(id);if(!actor||world.paused!=0||actor->slot>=World::primary_capacity||world.primary(actor->slot)!=actor)return PrimaryInitializationStatus::unavailable;
        const bool previous_busy=world.updating_;world.updating_=true;struct Reset{bool& value;bool previous;~Reset(){value=previous;}}reset{world.updating_,previous_busy};
        try{
            if(!world.session().exit_requested){
                initialize_model_constraints(world,*actor);
                const auto& saved=actor->saved_action_position;
                if(!std::isfinite(saved.x)||!std::isfinite(saved.y)||!std::isfinite(saved.z))return PrimaryInitializationStatus::unavailable;
                if(saved.x!=0||saved.y!=0||saved.z!=0||actor->saved_action_yaw!=0){actor->position=saved;actor->orientation[1]=actor->saved_action_yaw;}
            }
            finish(*actor);return PrimaryInitializationStatus::completed;
        }catch(const std::bad_alloc&){return PrimaryInitializationStatus::no_memory;}catch(...){return PrimaryInitializationStatus::unavailable;}
    }
PrimaryInitializationStatus initialize_primary_defaults(World& world,actors::EntityId id,std::uint8_t character,const HumanoidMotionBanks& banks)noexcept{return PrimaryActorInitialization::defaults(world,std::move(id),character,banks);}
PrimaryInitializationStatus initialize_primary_slot(World& world,actors::EntityId id,std::uint8_t character,const HumanoidMotionBanks& banks,const PrimaryEquipmentContext* equipment)noexcept{return PrimaryActorInitialization::defaults(world,std::move(id),character,banks,true,equipment);}
PrimaryInitializationStatus restore_primary_slot(World& world,actors::EntityId id)noexcept{return PrimaryActorInitialization::restore(world,std::move(id));}
PrimaryInitializationStatus initialize_primary_actor(World& world,const gameplay_update::State& state,actors::EntityId id,std::uint8_t character,const HumanoidMotionBanks& banks,const PrimaryEquipmentContext* equipment)noexcept{
    return PrimaryActorInitialization::select(world,state,std::move(id),character,banks,equipment);
}
PrimaryInitializationStatus PrimaryActorInitialization::select(World& world,const gameplay_update::State& state,actors::EntityId id,std::uint8_t character,const HumanoidMotionBanks& banks,const PrimaryEquipmentContext* equipment,bool nested)noexcept{
    if(state.notification_pending&&world.paused==0)return restore(world,std::move(id),nested);
    return defaults(world,std::move(id),character,banks,true,equipment,nested);
}
bool select_primary_appearance(World& world,actors::EntityId id,std::uint8_t character,std::uint8_t model_class)noexcept{
    if(world.closed()||world.busy())return false;
    const auto actor=world.resolve(id);if(!actor)return false;
    actor->character=character;actor->model_pose_class=model_class;actor->appearance_variant=0;actor->movement_enabled=1;return true;
}
}
