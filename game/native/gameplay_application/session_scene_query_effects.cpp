#include "session_scene_query_effects.hpp"
#include "native_session.hpp"
#include "session_resources.hpp"
#include "../gameplay_collision/object_interactions.hpp"
#include "../gameplay_collision/object_queries.hpp"
#include "../transform_math/transform_math.hpp"
#include <cmath>

namespace reo::native::gameplay_application {
namespace world = gameplay_world;
namespace collision = gameplay_collision;

SessionSceneQueryEffects::SessionSceneQueryEffects(NativeSession& session,
    SessionRooms& rooms) noexcept : session_(session),rooms_(rooms) {}

std::optional<std::uint16_t> SessionSceneQueryEffects::selected_content(
    world::World&,world::Actor& actor,const collision::Proxy&) {
    if(!actor.collision_resource_selector)return{};
    auto* resources=session_.resources();
    if(!resources||!resources->initialized())return{};
    const auto id=resources->descriptors().slot(*actor.collision_resource_selector);
    if(!id)return{};
    const auto descriptor=resources->descriptors().get(*id);
    if(!descriptor)return{};
    return descriptor->attachment_id; //3C5630 + 0x3C*C82 + 6
}

std::optional<bool> SessionSceneQueryEffects::room_grid_contact(
    world::World& world,world::Actor& actor,const gameplay_scene::Record& record,
    const collision::ownership::Selected& selected) noexcept {
    if(actor.category==2){
        actor.scene_contact_request=1; //5C5A30 C9C write, before room/object reads
        return true;
    }
    if(actor.category!=0)return false;
    auto objects=rooms_.objects();
    if(!objects||!objects->initialized()||objects->grid_room()!=
       std::optional<std::uint16_t>(world.room))return{};
    collision::room_objects::InteractionOwner interactions(*objects);
    const auto all=objects->objects();
    std::optional<collision::room_objects::ObjectId> object_id;
    for(const auto& candidate:all){
        const auto* object=objects->get(candidate);
        if(!object)return{};
        for(const auto& proxy:object->proxies)if(proxy==selected.proxy){object_id=candidate;break;}
        if(object_id)break;
    }
    if(!object_id)return{};
    const auto ordinal=interactions.source_ordinal(*object_id);
    const auto* object=objects->get(*object_id);
    if(!ordinal||!object)return{};

    const auto center=objects->center(*object);
    const float dx=center.x-actor.position.x,dy=center.y-actor.position.y,dz=center.z-actor.position.z;
    const float magnitude=std::sqrt((dx*dx+dy*dy)+dz*dz);
    const float nx=dx/magnitude,nz=dz/magnitude; //source normalization has no zero-vector guard
    const auto forward=transform_math::sin_cos(transform_math::radians(
        static_cast<std::uint16_t>(actor.orientation[1])));
    const float dot=(nx*forward.sine+nz*forward.cosine);
    const float threshold=transform_math::sin_cos(transform_math::radians(0x2000)).cosine; //370100(0x2000)
    if(dot<threshold)return false; //ordered comparison preserves NaN admission

    const auto predicate=collision::object_queries::probe(*objects,interactions,
        *object_id,*ordinal,actor.collision.basis,actor.collision.local_center,
        {actor.position.x,actor.position.y,actor.position.z},
        static_cast<std::uint16_t>(actor.orientation[1])); //6B0CF0
    if(predicate.status!=collision::object_queries::Status::complete)return{};
    if(!predicate.value)return false;
    if(!actor.interaction_request_count||!record.owner_snapshot)return{};
    if(*actor.interaction_request_count!=0xff)++*actor.interaction_request_count;
    actor.interaction_control_selector=*record.owner_snapshot;
    return true;
}

std::optional<bool> SessionSceneQueryEffects::object_interaction(
    world::Actor& actor,const gameplay_scene::Record& record,
    std::uint8_t mode) noexcept {
    if(!record.owner_snapshot)return{};
    if(mode==2){
        if(!(actor.status&0x4000u)){
            if(!actor.interaction_control_selector)return{};
            if(*actor.interaction_control_selector==*record.owner_snapshot)return false;
        }
    }
    auto objects=rooms_.objects();
    if(!objects||!objects->initialized())return{};
    collision::room_objects::InteractionOwner interactions(*objects);
    const auto object=interactions.masked(*record.owner_snapshot);
    if(!object)return false;
    if(mode==1){ //5C5B50: 6AF430 before the source actor-state gates
        if(!interactions.below_capacity(*object))return false;
        if(actor.status&0x4000u){
            if(!actor.interaction_control_selector)return{};
            if(*actor.interaction_control_selector==*record.owner_snapshot)return false;
        }
        if(!record.extra||!actor.interaction_control_request)return{};
        actor.interaction_control_request->pending=1;
        actor.interaction_control_request->variant=1;
        actor.interaction_control_request->parameter=*record.extra;
        actor.interaction_control_selector=*record.owner_snapshot;
        return true;
    }
    if(mode==2){ //5C5BD0's early source no-op is complete without geometry.
        if(!record.collision)return{};
        const auto* value=objects->get(*object);if(!value)return{};
        const auto& polygon=record.collision->bounds;
        float min_x=float(polygon[0].x),max_x=min_x,min_z=float(polygon[0].z),max_z=min_z;
        for(std::size_t i=1;i<polygon.size();++i){
            const float x=float(polygon[i].x),z=float(polygon[i].z);
            if(x<min_x)min_x=x;if(x>max_x)max_x=x;
            if(z<min_z)min_z=z;if(z>max_z)max_z=z;
        }
        const auto yaw=static_cast<std::uint16_t>(actor.orientation[1]);
        const auto forward=transform_math::sin_cos(transform_math::radians(yaw));
        const float px=actor.position.x,pz=actor.position.z;
        float dx=1000.0f,dz=1000.0f;std::optional<std::uint8_t> side_x,side_z;
        if(forward.sine>0){dx=(max_x-px)/forward.sine;side_x=2;}
        else if(forward.sine<0){dx=(min_x-px)/forward.sine;side_x=8;}
        if(forward.cosine>0){dz=(max_z-pz)/forward.cosine;side_z=1;}
        else if(forward.cosine<0){dz=(min_z-pz)/forward.cosine;side_z=4;}
        // The original leaves a winning zero-component side uninitialized.
        const auto side=dz<=dx?side_z:side_x;
        if(!side)return{};
        const auto edge=collision::object_queries::padded_direction(*objects,*object,*side); //6AF4B0
        if(edge.status!=collision::object_queries::Status::complete)return{};
        if(!edge.value)return false;
        if(!actor.interaction_request||!actor.interaction_control_request)return{};
        actor.interaction_control_request->pending=1;
        actor.interaction_control_request->variant=2;
        actor.interaction_control_selector=*record.owner_snapshot;
        switch(*side){case 1:actor.interaction_request->orientation=0;break;
        case 2:actor.interaction_request->orientation=0x4000;break;
        case 4:actor.interaction_request->orientation=0x8000;break;
        case 8:actor.interaction_request->orientation=0xc000;break;
        default:return{};}
        return true;
    }
    return{};
}

std::optional<bool> SessionSceneQueryEffects::scene_trigger(
    world::World& world,world::Actor& actor,const gameplay_scene::Record& record) noexcept {
    if(!session_.scene_matrices().inspect(record.authored_id))return{};
    auto& flags=session_.update().flags();
    if(actor.category==0){
        if(world.locally_controlled(actor)){
            if(!flags.strided(world.room,record.authored_id&31u,1,true,false))return{};
            actor.auxiliary_status|=0x20000u;
        }
        if(world.mode==0)actor.auxiliary_status|=0x20000u;
    }
    if(session_.scene_matrices().interaction(record.authored_id,1)!=
       gameplay_scenario::SceneMatrixStatus::completed)return{};
    return true;
}

std::optional<bool> SessionSceneQueryEffects::flag_policy(world::World& world,
    world::Actor& actor,const gameplay_scene::Record& record) noexcept {
    if(actor.category!=0)return true; //5C3FF8/FFFC exits before reading policy payload
    const auto* parameters=record.flag_policy?&*record.flag_policy:nullptr;
    const auto* source=std::get_if<gameplay_scenario::ControlTypeThree>(&record.body);
    if(!parameters||!source)return{};
    const auto local=world.locally_controlled(actor); //1B0340
    const auto mode_zero=world.mode==0; //1B02D0 returns(mode byte3243F2==0)
    bool admitted=true;
    switch(parameters->gate){
    case 0:break;
    case 1:admitted=std::uint32_t(actor.slot!=parameters->expected)==parameters->inequality;break;
    case 2:admitted=std::uint32_t(actor.character!=parameters->expected)==parameters->inequality;break;
    case 3:admitted=mode_zero&&!local;break;
    case 4:admitted=local;break;
    default:break; //5C3FE0's default admission path
    }
    if(!admitted)return true;
    const auto flag=record.authored_id&0x1ffu; //P40 ANDI1FF
    const auto set_scenario=[&](){return session_.update().flags().scenario(
        flag,1,gameplay_scenario::NotifyOwner::selected_actor_plus_one,
        std::uint8_t(world.selected_actor+1u));}; //5703E0 -> 67DBD0
    const auto set_actor=[&](std::uint8_t owner){
        return session_.update().flags().actor_flag(
            gameplay_scenario::ActorFlagFamily::primary,
            gameplay_scenario::ActorFlagSelection{false,owner},flag,true);
    };
    const auto operation=source->mode; //P44
    bool publish_actor_flag=false;
    switch(operation){
    case 0:if(!set_scenario())return{};break;
    case 1:publish_actor_flag=true;break;
    case 2:if(!set_scenario())return{};break;
    case 3:publish_actor_flag=true;break;
    default:return true;
    }
    if(publish_actor_flag){
        if(mode_zero){if(!set_actor(actor.slot))return{};}
        else if(local){if(!set_actor(0))return{};}
        //5C3FE0 skips this flag write outside mode zero for remote actors.
    }
    if((operation==2||operation==3)&&parameters->event!=0xffff&&local){
        const auto result=session_.timed_scene_text().request(
            gameplay_scenario::TimedTextRequest{parameters->event,60,0,4,0}); //570120(event,60,4)
        if(result!=gameplay_scenario::TimedTextStatus::completed)return{};
    }
    return true;
}

std::optional<bool> SessionSceneQueryEffects::inventory_policy(
    world::World& world,world::Actor& actor,const gameplay_scene::Record& record) {
    if(actor.category!=0)return true; //5C4268..5C4278 category no-op
    const auto* parameters=record.inventory_policy?&*record.inventory_policy:nullptr;
    if(!parameters)return{};
    const bool mode_zero=world.mode==0; //1B02D0
    const bool local=world.locally_controlled(actor); //1B0340
    bool admitted=true;
    switch(parameters->gate){
    case 0:break;
    case 1:admitted=std::uint32_t(actor.slot!=parameters->expected)==parameters->inequality;break;
    case 2:admitted=std::uint32_t(actor.character!=parameters->expected)==parameters->inequality;break;
    case 3:admitted=mode_zero&&!local;break;
    case 4:admitted=local;break;
    default:break; //5C4230's default admission path
    }
    if(!admitted)return false;

    const auto flag=record.authored_id&0x1ffu; //P40 ANDI1FF
    const auto publish_flag=[&]()->bool{
        switch(parameters->flag_bank){
        case 0:return session_.update().flags().scenario(flag,1,
            gameplay_scenario::NotifyOwner::selected_actor_plus_one,
            std::uint8_t(world.selected_actor+1u)); //5703E0(ID,1)
        case 1:return session_.update().flags().actor_flag(
            gameplay_scenario::ActorFlagFamily::primary,
            gameplay_scenario::ActorFlagSelection{false,
                std::uint8_t(mode_zero?actor.slot:0)},flag,true); //5705F0(ID,1,owner)
        default:return true; //other banks skip only the flag write
        }
    };
    const auto resources=session_.resources();
    const auto actor_id=world.identity_of(actor);
    const auto content=record.other_content;
    const auto query_content=[&](std::uint32_t id)->std::optional<bool>{
        if(!resources||!resources->initialized()||!actor_id)return{};
        try{return resources->inventory().find_by_content(actor_id,id)!=0;}
        catch(...){return{};}
    };
    const auto event=[&]()->std::optional<bool>{
        if(parameters->event_word==0xffffffffu)return true; //signed P68 == -1
        const auto result=session_.timed_scene_text().request(
            gameplay_scenario::TimedTextRequest{
                std::uint16_t(parameters->event_word),40,20,3,0}); //570100→570140(event,0,20,40,3)
        return result==gameplay_scenario::TimedTextStatus::completed?
            std::optional<bool>(true):std::nullopt;
    };
    const auto close_inventory=[&]()->bool{
        world.session().inventory_owner=0; //5F4FD0 delay-slot prefix
        return session_.inventory_ui().close(); //6E1430; active phases refuse
    };
    switch(parameters->operation){
    case 0:
        if(!publish_flag())return{}; //flag is source-ordered before all later work
        if(!local)return true;
        if(!content||!resources||!resources->initialized()||!actor_id)return{};
        try{resources->consumption().consume_carried_content(actor_id,*content);}catch(...){return{};}
        if(!close_inventory())return{};
        return event();
    case 1: {
        if(!content)return{};
        const auto item=query_content(*content);if(!item)return{};if(!*item)return false;
        return publish_flag()?std::optional<bool>(true):std::nullopt;
    }
    case 2: {
        if(!content)return{};
        const auto first=query_content(*content);if(!first)return{};if(!*first)return false;
        const auto second=query_content(parameters->second_content);if(!second)return{};if(!*second)return false;
        return publish_flag()?std::optional<bool>(true):std::nullopt;
    }
    case 3:
        if(!publish_flag())return{};
        if(!content||!resources||!resources->initialized()||!actor_id)return{};
        try{resources->consumption().destroy_content(actor_id,*content);}catch(...){return{};}
        if(!local)return true;
        if(!close_inventory())return{};
        return event();
    default:return true; //5C4230 ignores other operations after outer gates
    }
}

std::optional<bool> SessionSceneQueryEffects::conditional_event_policy(
    world::World& world,world::Actor& actor,const gameplay_scene::Record& record) {
    if(actor.category!=0)return true; //5C4624 exits before local/task state.
    if(!world.locally_controlled(actor))return true; //5C4634.
    const auto* policy=record.conditional_event?&*record.conditional_event:nullptr;
    if(!policy)return{};
    const auto& source=policy->condition;
    auto& flags=session_.update().flags();
    std::uint16_t event=policy->base_event;
    if(source!=0xffffu){
        if(source&0x8000u){
            const auto bit=std::uint32_t(source&0x3fffu)&15u; //570A10 masks ID with 0xF.
            const auto present=flags.get(gameplay_scenario::FlagBank::bounded_halfword,bit);
            if(!present)return{};
            if(*present)event=policy->alternate_event;
            else if((source&0x3fffu)<16u){
                if(!flags.write(gameplay_scenario::FlagBank::bounded_halfword,
                    source&0x3fffu,true))return{}; //5709E0 ignores ids >=16.
            }
        }else if(source&0x4000u){
            //5C46D4..4748 captures the event and record pointer in the task
            //bank before returning. Its required per-actor task payload is
            //not yet represented by a native callback owner.
            return{};
        }else{
            const auto present=flags.get(gameplay_scenario::FlagBank::bounded_byte,source);
            if(!present)return{}; //5709B0 has an unchecked guest read beyond 0x80.
            if(*present)event=policy->alternate_event;
            else{
                //5C474C..47C0 installs type7 callback state before continuing.
                //The scheduled 5BA9B0 consumer is not yet natively owned.
                return{};
            }
        }
    }

    const auto selected=world.primary(world.selected_actor);
    if(!selected)return{};
    if(policy->category_mask){
        const auto category=selected->category;
        if((policy->category_mask&(std::uint8_t(1u<<(category&31u))))==0)return true;
        if(category>=policy->category_events.size())return{}; //source would read beyond P+68.
        event=policy->category_events[category];
    }

    auto current=record;
    if(policy->flag_mode!=0xffffffffu&&policy->counter>=policy->counter_limit){
        if(policy->flag_mode==0){
            if(!flags.scenario(policy->flag_id,1,
                gameplay_scenario::NotifyOwner::selected_actor_plus_one,
                std::uint8_t(world.selected_actor+1u)))return{}; //5703E0.
        }else if(policy->flag_mode==1){
            const auto owner=std::uint8_t(world.mode==1?actor.slot:0);
            if(!flags.actor_flag(gameplay_scenario::ActorFlagFamily::primary,
                gameplay_scenario::ActorFlagSelection{false,owner},policy->flag_id,true))return{}; //5705F0.
        }
    }
    if(policy->counter_limit!=0){
        event=std::uint16_t(event+std::uint16_t(policy->counter));
        current.conditional_event->counter=policy->counter<policy->counter_limit?
            std::int16_t(policy->counter+1):policy->counter_limit;
        const auto pool=session_.scene_records();
        if(!pool)return{};
        const auto node=pool->acquire(record.source);if(!node)return{};
        node->value.conditional_event=current.conditional_event;pool->touch();
    }
    if(source!=0xffffu){
        const auto status=session_.timed_scene_text().request(
            gameplay_scenario::TimedTextRequest{event,60,0,4,0}); //570120(event,60,4).
        if(status!=gameplay_scenario::TimedTextStatus::completed)return{};
    }
    if(policy->callback_parameter!=0xffu){
        //5BF0F0 is a separate global task-record producer. Keep its prefix
        //mutations above, but refuse until that record has a typed owner.
        return{};
    }
    if(policy->deactivate){
        const auto pool=session_.scene_records();if(!pool)return{};
        const auto node=pool->acquire(record.source);if(!node)return{};
        node->value.enabled=0;pool->touch(); //5C4910 clears original P+3C.
    }
    return true;
}

std::optional<bool> SessionSceneQueryEffects::scene_anchor(world::World& world,
    world::Actor& actor,const gameplay_scene::Record& record) noexcept {
    const auto* parameters=std::get_if<gameplay_scenario::ControlTypeSix>(&record.body);
    if(!parameters)return{};
    if(actor.category!=0&&actor.category!=1)return true; //5C4974..4984
    const auto mode=record.ladder_entry?record.ladder_entry->mode:0u; //P4C
    if(mode==3)return true; //5C498C..4994
    if(!record.other_content||!record.other_resource_class||!record.collision)return{};
    const auto matrix=session_.scene_matrices().inspect(parameters->scene_matrix_index);
    if(!matrix)return{};
    const auto& base=matrix->matrix;
    const transform_math::Vector origin{base[3][0],base[3][1],base[3][2]}; //49FA10 + 40*P60
    const auto yaw=std::uint16_t(*record.other_content); //P48;370320 consumes low half
    const auto special=actor.motion_class==0x1a;
    auto& session=world.session();
    const auto model=session_.scene_models().resolve(parameters->scene_matrix_index);
    const auto publish_common=[&](std::uint8_t kind){
        if(!actor.interaction_request)return false;
        actor.interaction_request->kind=kind; //AB9
        actor.transient_action=1; //AB8
        actor.interaction_request->orientation=*record.other_content; //AC8=P48
        actor.scene_model=gameplay_scenario::ModelReference{model}; //ABB resolves the byte through the room remap
        return true;
    };
    if(special){
        if(mode==4||mode==5){
            const auto kind=std::uint8_t(mode==4?0x0f:0x10);
            if(actor.category==0){
                if(world.locally_controlled(actor)){
                    if(!session.scenario)return{};
                    const auto variant=std::uint8_t(mode==4?
                        (parameters->scene_mode_value|0x80u):parameters->scene_mode_value);
                    session.scene_transition_publication=world::SceneTransitionPublication{
                        4,variant,*session.scenario,std::uint16_t(*record.other_resource_class)};
                }
                if(!actor.interaction_request)return{};
                actor.interaction_request->kind=kind;actor.interaction_request->parameter=1;
            }else{
                if(!actor.interaction_request)return{};
                actor.interaction_request->kind=kind;
                actor.interaction_request->parameter=1; //5C4AE4..5C4AEC writes ABA for class1 too.
            }
            actor.transient_action=1;
            return true;
        }
        if(mode==2||(mode==6&&actor.category==0))return true;
        if(!publish_common(0x0e))return{};
        actor.interaction_request->anchor={origin.x,origin.y,origin.z};
        actor.interaction_request->anchor.y=float(record.collision->bounds[3].x);
        return true;
    }
    if(mode==4)return true;

    transform_math::Matrix rotation=transform_math::identity();
    transform_math::reset_euler_axes(rotation,{0,yaw,0});
    transform_math::Vector offset{};
    if(actor.category==0){
        offset={0,0,mode==2?-50.0f:mode==6?-100.0f:-40.0f};
    }else{
        offset={0,0,mode==2?-50.0f:-40.0f};
    }
    offset=transform_math::direction(rotation,offset);
    const auto length=std::sqrt((offset.x*offset.x+offset.y*offset.y)+offset.z*offset.z);
    const transform_math::Vector normalized{offset.x/length,offset.y/length,offset.z/length};
    transform_math::Matrix actor_rotation=transform_math::identity();
    transform_math::reset_euler_axes(actor_rotation,{0,
        static_cast<std::uint16_t>(actor.orientation[1]),0});
    const auto forward=transform_math::direction(actor_rotation,{0,0,1});
    const float dot=(normalized.x*forward.x+normalized.y*forward.y)+normalized.z*forward.z;
    if(!(dot<=0.0f))return true; //ordered original comparison rejects NaN
    const std::uint8_t kind=actor.category==0?
        std::uint8_t(mode==2?0x0d:mode==6?0x10:0x0b):
        std::uint8_t(mode==2?0x0d:0x0b);
    if(!publish_common(kind))return{};
    actor.interaction_request->anchor={origin.x+offset.x,origin.y+offset.y,origin.z+offset.z};
    return true;
}

std::optional<bool> SessionSceneQueryEffects::dispatch(world::World& world,
    world::Actor& actor,const collision::ownership::Selected& selected,
    const gameplay_scene::Record& record) {
    switch(gameplay_scene::kind(record.body)){
    case 3:return flag_policy(world,actor,record); //5C3FE0
    case 4:return inventory_policy(world,actor,record); //5C4230
    case 5:return conditional_event_policy(world,actor,record); //5C4600
    case 6:return scene_anchor(world,actor,record); //5C4940
    case 0x0c:{ //5C5860 clears the selected proxy's active byte in its delay slot.
        auto& proxies=session_.scene_proxies();
        auto* current=proxies.get(selected.proxy);
        if(!current)return{};
        auto replacement=*current;replacement.geometry.active=false;
        return proxies.replace(selected.proxy,std::move(replacement));
    }
    case 0x81:return room_grid_contact(world,actor,record,selected);
    case 0x82:return object_interaction(actor,record,1);
    case 0x83:return object_interaction(actor,record,2);
    case 0x85:return scene_trigger(world,actor,record);
    default:return{};
    }
}

} // namespace reo::native::gameplay_application
