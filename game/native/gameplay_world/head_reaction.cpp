#include "head_reaction.hpp"
#include "target_metrics.hpp"
#include "linked_models.hpp"
#include "auxiliary_actors.hpp"
#include "scene_primary_actors.hpp"
#include "secondary_pose_dynamics.hpp"
#include "../animation/model.hpp"
#include "../animation/playback.hpp"
#include "../animation/constraint_math.hpp"
#include "../transform_math/heading.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <limits>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
namespace t=transform_math;
namespace m=animation::constraint_math;
constexpr float tau=std::bit_cast<float>(0x40c90fdbu);
std::int16_t narrow(int v){return std::bit_cast<std::int16_t>(std::uint16_t(v));}
float finite(float v){if(!std::isfinite(v))throw std::domain_error("Native head reaction finite profile required");return v;}
std::int32_t integer(float v){finite(v);if(double(v)<double(INT32_MIN)||double(v)>=2147483648.)throw std::domain_error("Native head turn conversion unavailable");return std::int32_t(v);}
std::int16_t sampled_turn(float v){return narrow(integer(.5f+finite(finite(65536.f*v)/tau)));}
std::int16_t angle_turn(float angle){float degrees=finite((180.f*angle)/std::bit_cast<float>(0x40490fdbu));if(degrees<0)degrees=finite(degrees+360.f);return narrow(integer(finite(std::bit_cast<float>(0x43360b61u)*degrees)));}
animation::Instance& model(Actor& actor){if(!actor.model||actor.model->nodes().size()<=21)throw std::runtime_error("Native head model unavailable");return *actor.model;}
const animation::Instance& model(const Actor& actor){return model(const_cast<Actor&>(actor));}
HeadReactionState& state(Actor& actor){if(!actor.head_reaction)throw std::runtime_error("Native humanoid head state unavailable");return *actor.head_reaction;}
t::Vector point(const Actor& actor,std::size_t node){const auto& instance=model(actor);if(!instance.retain()||node>=instance.nodes().size())throw std::runtime_error("Native head point unavailable");return instance.world_translation(node);}
t::Vector vector(Position p){return {p.x,p.y,p.z};}
t::Vector actor_point(const Actor& actor,std::size_t node){if(!actor.model||actor.model->nodes().empty())return vector(actor.position);if(!actor.model->retain()||node>=actor.model->nodes().size())throw std::runtime_error("Native reaction target point unavailable");return actor.model->world_translation(node);}
std::uint8_t target_node(const Actor& actor){if(!actor.targeting||!actor.targeting->head_model_point)throw std::runtime_error("Native reaction target node552 unavailable");return *actor.targeting->head_model_point;}
std::array<std::int16_t,3> sample_angles(const Actor& actor){const auto& p=model(actor).nodes()[21].parameters;return {sampled_turn(p[3]),sampled_turn(p[4]),sampled_turn(p[5])};}
std::array<std::int16_t,3> relative_angles(t::Vector from,t::Vector to,std::int16_t yaw){auto result=head_direction_turns(from,to);result[0]=narrow(-int(result[0]));result[1]=narrow(int(result[1])-int(yaw));return result;}
void choose_duration(HeadReactionState& h,std::array<std::int16_t,3> angles,float step,bool absolute_axes){
    if(h.mode==(absolute_axes?6u:1u))return;
    const auto first=absolute_axes?std::abs(float(angles[0])):std::abs(float(int(angles[0])-int(h.current[0])));
    const auto second=absolute_axes?std::abs(float(angles[1])):std::abs(float(int(angles[1])-int(h.current[1])));
    const auto delta=first<=second?std::abs(float(int(angles[1])-int(h.current[1]))):std::abs(float(int(angles[0])-int(h.current[0])));
    h.ticks=narrow(integer(1.f+delta/((first<=second?8192.f:6144.f)/step)));
}
std::int16_t relation_ticks(const ScriptedActorState& script,std::uint8_t clock){const auto value=narrow(std::bit_cast<std::int32_t>(script.relation_parameter));return narrow((clock?int(value)/2:int(value))+1);}
void refresh_target_timer(World& world,HeadReactionState& h){h.retarget_ticks=narrow(int((std::uint32_t(world.session().random.request(1))%120u+30u)/(world.session().clock_mode?2u:1u)));}
void update_impl(World& world,Actor& actor,std::uint8_t requested,const HeadReactionContext& context){
    if(world.session().session_state==1&&!world.paused)return;
    auto& h=state(actor);auto& instance=model(actor);if(!instance.retain()||!actor.animation)throw std::runtime_error("Native head published animation unavailable");
    const auto status=actor.status;
    if((status&0x8000u)||(status&0x38u))requested=0;
    if((actor.animation->channel(animation::ModelBank::primary,1).timing.flags&0x18u)&&requested){requested=0;h.mode=1;}
    const auto sampled=sample_angles(actor);
    if(h.target){const auto target=world.resolve(h.target);if(!target||!target->active||!target->model)h.target={};}
    const float step=world.session().clock_mode?6.f:12.f;
    switch(requested){
    case 0:{
        if(h.mode){h.mode=0;h.ticks=10;if(world.paused&&actor.scripted&&std::bit_cast<std::int32_t>(actor.scripted->relation_parameter)>0)h.ticks=relation_ticks(*actor.scripted,world.session().clock_mode);}
        if(h.mode||!h.ticks)return;
        advance_head_reaction(actor,sampled);if(!h.ticks)reset_head_reaction(actor);return;
    }
    case 1:{
        auto selected=select_head_target(world,actor,1000,1,INT16_MIN,0);
        if(!h.mode){
            if(h.ticks){update_impl(world,actor,0,context);return;}
            if(h.retarget_ticks){h.retarget_ticks=narrow(int(h.retarget_ticks)-1);return;}
            if(!h.target&&!selected)return;
            h.target=selected;h.ticks=1;refresh_target_timer(world,h);
        }
        if(h.target){const auto target=world.resolve(h.target);if(!target)throw std::runtime_error("Native head target retired");const auto origin=point(actor,20),endpoint=actor_point(*target,target_node(*target));const auto delta=m::subtract(endpoint,origin);const auto bearing=t::direction_turn(delta.x,delta.z);const auto relative=narrow(int(std::bit_cast<std::int16_t>(bearing))-int(actor.orientation[1]));if(std::abs(float(relative))>16384.f||m::square_root(m::squared_length(delta))>1000.f){h.ticks=0;h.retarget_ticks=0;}}
        if(!h.ticks){
            if(!h.retarget_ticks){auto next=select_head_target(world,actor,1000,1,INT16_MIN,1);if(next==h.target||!next)next=select_head_target(world,actor,1000,1,INT16_MIN,0);h.mode=0;h.target=next;refresh_target_timer(world,h);}
            else h.retarget_ticks=narrow(int(h.retarget_ticks)-1);
        }
        if(!h.target){h.mode=1;update_impl(world,actor,0,context);return;}
        const auto target=world.resolve(h.target);if(!target)throw std::runtime_error("Native head target retired");
        const auto inverse=m::inverse_scaled(instance.nodes()[20].world);const auto transformed=m::add(t::direction(inverse,actor_point(*target,target_node(*target))),{inverse[3][0],inverse[3][1],inverse[3][2]});
        const auto& p=instance.nodes()[21].parameters;auto angles=relative_angles({p[6],p[7],p[8]},transformed,sampled[1]);angles[2]=sampled[2];choose_duration(h,angles,step,false);h.mode=1;advance_head_reaction(actor,angles);return;
    }
    case 2:{
        if(h.mode==2&&h.ticks){h.ticks=narrow(int(h.ticks)-1);for(unsigned i=0;i<2;++i)h.current[i]=narrow(int(h.current[i])+int(h.step[i]));auto local=instance.nodes()[21].local;t::reset_euler_axes(local,{std::uint16_t(h.current[0]),std::uint16_t(h.current[1]),std::uint16_t(sampled_turn(instance.skeleton().nodes()[21].defaults[5]))});const std::array<animation::LocalPosePatch,1> patches{{{21,local}}};instance.patch_local_poses(patches);return;}
        if(!context.camera)throw std::runtime_error("Native reaction scene camera unavailable");
        auto endpoint=vector(*context.camera);endpoint.y=finite(endpoint.y+170.f);
        //661CB4 returns after preparing the camera angles. It does not call
        //661160 or install those temporary angles in this first mode2 pass.
        (void)relative_angles(point(actor,21),endpoint,actor.orientation[1]);h.mode=2;return;
    }
    case 3:return;
    case 4:{
        if(!actor.scripted)throw std::runtime_error("Native scripted head relation unavailable");
        const auto& script=*actor.scripted;
        if(std::bit_cast<std::int32_t>(script.relation_parameter)>0){h.ticks=relation_ticks(script,world.session().clock_mode);h.mode=4;}
        if(!script.relation_parameter){update_impl(world,actor,0,context);return;}
        t::Vector endpoint{};
        if(script.relation_mode==0)endpoint={script.relation_offset[0],script.relation_offset[1],script.relation_offset[2]};
        else if(script.relation_mode==1){const auto related=world.resolve(script.related_actor);if(!related)throw std::runtime_error("Native related head actor unavailable");endpoint=actor_point(*related,2);endpoint.y=finite(actor_point(*related,0).y+float(std::bit_cast<std::int32_t>(script.relation_options)));}
        else throw std::runtime_error("Native reaction relation has no authored endpoint");
        const auto inverse=m::inverse_scaled(instance.nodes()[20].world);const auto origin=m::add(t::direction(inverse,point(actor,21)),{inverse[3][0],inverse[3][1],inverse[3][2]});endpoint=m::add(t::direction(inverse,endpoint),{inverse[3][0],inverse[3][1],inverse[3][2]});auto angles=relative_angles(origin,endpoint,sampled[1]);angles[2]=sampled[2];advance_head_reaction(actor,angles);return;
    }
    case 5:{
        if(h.mode!=5){h.mode=5;h.ticks=1;h.current={sampled[0],sampled[1]};}
        const auto x=narrow(integer(float(int(h.input[1])*6144)/127.f)),y=narrow(integer(float(int(h.input[0])*8192)/127.f));
        advance_head_reaction(actor,{narrow(int(sampled[0])+int(x)),narrow(int(sampled[1])-int(y)),sampled_turn(instance.skeleton().nodes()[21].defaults[5])});return;
    }
    case 6:{
        if(h.mode==6&&h.ticks){h.ticks=narrow(int(h.ticks)-1);for(unsigned i=0;i<2;++i)h.current[i]=narrow(int(h.current[i])+int(h.step[i]));advance_head_reaction(actor,{h.current[0],h.current[1],sampled_turn(instance.skeleton().nodes()[21].defaults[5])});return;}
        auto angles=relative_angles(point(actor,21),{0,170,0},actor.orientation[1]);choose_duration(h,angles,step,true);h.mode=6;advance_head_reaction(actor,angles);return;
    }
    default:return;
    }
}
}
std::array<std::int16_t,3> head_direction_turns(t::Vector from,t::Vector to){auto delta=m::subtract(to,from);if(delta.x==0.f)delta.x=std::bit_cast<float>(0x38d1b717u);float horizontal=m::square_root(finite(finite(delta.x*delta.x)+finite(delta.z*delta.z)));if(horizontal==0.f)horizontal=std::bit_cast<float>(0x38d1b717u);const auto yaw=angle_turn(t::quadrant_angle(delta.x,delta.z)),pitch=angle_turn(t::quadrant_angle(delta.y,horizontal));return {pitch,yaw,0};}
void advance_head_reaction(Actor& actor,std::array<std::int16_t,3> angles){
    auto& h=state(actor);auto& instance=model(actor);const auto pitch=std::clamp<int>(angles[0],-0x17ff,0x17ff),yaw=std::clamp<int>(angles[1],-0x1fff,0x1fff);
    if(!h.ticks)h.ticks=1;
    h.step={narrow((pitch-int(h.current[0]))/int(h.ticks)),narrow((yaw-int(h.current[1]))/int(h.ticks))};h.ticks=narrow(int(h.ticks)-1);
    for(unsigned i=0;i<2;++i)h.current[i]=narrow(int(h.current[i])+int(h.step[i]));
    h.applied=h.current;
    instance.patch_local_rotation_axes(21,{std::uint16_t(h.current[0]),std::uint16_t(h.current[1]),std::uint16_t(sampled_turn(instance.nodes()[21].parameters[5]))});h.local=instance.nodes()[21].local;
}
void reset_head_reaction(Actor& actor){auto& h=state(actor);const auto sampled=sample_angles(actor);h.current={sampled[0],sampled[1]};h.step={};h.mode=0;h.ticks=0;h.retarget_ticks=0;h.target={};}
actors::EntityId select_head_target(World& world,const Actor& actor,float maximum,std::uint8_t selector,std::int16_t aperture,std::uint8_t ordinal){
    const auto* metrics=world.target_metrics().state();if(!metrics)throw std::runtime_error("Native head target metrics unavailable");finite(maximum);
    const auto source=actor.slot;const auto half=int(aperture)/2;const auto limit=std::abs(float(half));unsigned accepted=0;
    const auto scan=[&](const auto& order,const auto& rows,const auto& sources)->actors::EntityId{
        if(source>=order.size()||sources[source]!=world.identity_of(actor))throw std::runtime_error("Native head target source identity unavailable");
        for(const auto physical:order[source]){
            if(physical==255)break;
            if(physical>=50)throw std::runtime_error("Native head target physical index unavailable");
            const auto target=world.resolve(metrics->linked_identity[physical]);
            if(!target||!target->active||!target->model)continue;
            if(!target->targeting)throw std::runtime_error("Native head target flags unavailable");
            if(target->targeting->flags&1u)continue;
            const auto& metric=rows[source][physical];if(!metric)throw std::runtime_error("Native head target metric unavailable");if(!(metric->pair.distance<=maximum)||!(target->position.y-actor.position.y<=300.f)||!(actor.position.y-target->position.y<=100.f)||metric->wall)continue;
            std::int16_t bearing=std::bit_cast<std::int16_t>(metric->pair.bearing);
            if(selector==1){const auto delta=m::subtract(actor_point(*target,target_node(*target)),point(actor,11));bearing=std::bit_cast<std::int16_t>(t::direction_turn(delta.x,delta.z));}
            if(std::abs(float(narrow(int(bearing)-int(actor.orientation[1]))))>limit)continue;
            if(accepted++==ordinal)return metrics->linked_identity[physical];
        }return {};
    };
    return actor.category==0?scan(metrics->primary_linked_order,metrics->primary_linked,metrics->primary_identity):scan(metrics->auxiliary_linked_order,metrics->auxiliary_linked,metrics->auxiliary_identity);
}
HeadReactionStatus update_head_reaction(World& world,Actor& actor,std::uint8_t requested,const HeadReactionContext& context)noexcept{
    if(world.session().session_state==1&&!world.paused)return HeadReactionStatus::unchanged;
    try{update_impl(world,actor,requested,context);return HeadReactionStatus::applied;}catch(const std::bad_alloc&){return HeadReactionStatus::no_memory;}catch(...){return HeadReactionStatus::unavailable;}
}
HeadReactionStatus update_scripted_head_reaction(World& world,Actor& actor,const HeadReactionContext& context)noexcept{
    try{
        if(!actor.scripted)return HeadReactionStatus::unavailable;
        auto& script=*actor.scripted;
        if(script.request_flags&4u){script.request_flags&=~4u;if(script.relation_mode==2)return update_head_reaction(world,actor,0,context);if(!script.relation_parameter){auto& h=state(actor);h.mode=0;h.ticks=0;script.relation_parameter=UINT32_MAX;return update_head_reaction(world,actor,4,context);}}
        if(script.relation_parameter){auto& h=state(actor);if(script.relation_parameter==UINT32_MAX)return update_head_reaction(world,actor,4,context);h.mode=0;h.ticks=0;const auto result=update_head_reaction(world,actor,4,context);script.relation_parameter=UINT32_MAX;return result;}
        const auto angles=sample_angles(actor);state(actor).current={angles[0],angles[1]};return HeadReactionStatus::applied;
    }catch(const std::bad_alloc&){return HeadReactionStatus::no_memory;}catch(...){return HeadReactionStatus::unavailable;}
}
OrdinaryHeadAction ordinary_head_action(const Actor& actor)noexcept{
    if(actor.category)return OrdinaryHeadAction::unchanged;
    bool reset=actor.primary!=1||(actor.status&0x80u);
    if(!reset)switch(actor.motion_class){
    case 0:reset=actor.secondary!=0;break;
    case 1:case 3:case 25:break;
    case 2:
        if(!actor.animation)return OrdinaryHeadAction::unavailable;
        reset=actor.animation->motion==0x2011||actor.animation->motion==0x2014;break;
    default:reset=true;break;
    }
    return reset?OrdinaryHeadAction::reset:OrdinaryHeadAction::track;
}
HeadReactionStatus update_ordinary_head_reaction(World& world,Actor& actor,const HeadReactionContext& context)noexcept{
    switch(ordinary_head_action(actor)){
    case OrdinaryHeadAction::unchanged:return HeadReactionStatus::unchanged;
    case OrdinaryHeadAction::unavailable:return HeadReactionStatus::unavailable;
    case OrdinaryHeadAction::track:return update_head_reaction(world,actor,1,context);
    case OrdinaryHeadAction::reset:break;
    }
    try{reset_head_reaction(actor);return HeadReactionStatus::applied;}
    catch(const std::bad_alloc&){return HeadReactionStatus::no_memory;}
    catch(...){return HeadReactionStatus::unavailable;}
}
HeadReactionStatus finish_ordinary_actor_reactions(World& world,Actor& actor,const HeadReactionContext& context)noexcept{
    const auto head=update_ordinary_head_reaction(world,actor,context);
    if(head==HeadReactionStatus::unavailable||head==HeadReactionStatus::no_memory)return head;
    const auto secondary=update_secondary_pose(actor,world.session().session_state,world.paused);
    switch(secondary){
    case SecondaryPoseStatus::unavailable:return HeadReactionStatus::unavailable;
    case SecondaryPoseStatus::no_memory:return HeadReactionStatus::no_memory;
    case SecondaryPoseStatus::applied:return HeadReactionStatus::applied;
    case SecondaryPoseStatus::unchanged:return head;
    }
    return HeadReactionStatus::unavailable;
}
CinematicActorReactions::~CinematicActorReactions(){if(running_)std::terminate();}
CinematicReactionsUpdated CinematicActorReactions::run()noexcept{
    if(running_||world_.busy()||world_.closed())return{HeadReactionStatus::unavailable};
    bool* auxiliary_busy=nullptr;running_=world_.updating_=true;
    struct Reset{bool& running;bool& world;bool*& pool;~Reset(){if(pool)*pool=false;world=false;running=false;}}reset{running_,world_.updating_,auxiliary_busy};
    CinematicReactionsUpdated report;
    const auto tick=[&](actors::EntityId id){
        const auto actor=world_.resolve(id);
        if(!actor){report.status=HeadReactionStatus::unavailable;report.failed=id;return false;}
        if(!actor->active||!actor->visible)return true;
        const auto head=update_scripted_head_reaction(world_,*actor);
        if(head==HeadReactionStatus::unavailable||head==HeadReactionStatus::no_memory){report.status=head;report.failed=id;return false;}
        ++report.heads;const auto secondary=update_secondary_pose(*actor,world_.session().session_state,world_.paused);
        if(secondary==SecondaryPoseStatus::unavailable||secondary==SecondaryPoseStatus::no_memory){report.status=secondary==SecondaryPoseStatus::no_memory?HeadReactionStatus::no_memory:HeadReactionStatus::unavailable;report.failed=id;return false;}
        ++report.secondary;return true;
    };
    try{
        if(const auto* temporary=world_.scene_primary_actors_.get();temporary&&temporary->initialized())for(unsigned slot=0;slot<ScenePrimaryActorPool::capacity;++slot){++report.temporary_visits;if(!tick(temporary->identity_at(slot)))return report;}
        if(auto* auxiliary=world_.auxiliary_actors_.get()){
            auxiliary_busy=&auxiliary->updating_;*auxiliary_busy=true;
            for(auto id=auxiliary->head();id;id=auxiliary->next(id)){++report.auxiliary_visits;if(!tick(id))return report;}
        }
        return report;
    }catch(const std::bad_alloc&){report.status=HeadReactionStatus::no_memory;return report;}
    catch(...){report.status=HeadReactionStatus::unavailable;return report;}
}
}
