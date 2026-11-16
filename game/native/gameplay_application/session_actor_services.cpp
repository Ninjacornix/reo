#include "session_actor_services.hpp"
#include "../gameplay_world/color_fade.hpp"
#include "../gameplay_world/motion.hpp"
#include "../gameplay_world/secondary_pose_links.hpp"
#include "../gameplay_world/actor_state.hpp"
#include "../gameplay_collision/object_queries.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
#include <string>
namespace reo::native::gameplay_application {
namespace w=gameplay_world;
namespace {
#include "ai_offline_frame_policy.inc"
std::uint8_t health_band(const w::Actor& actor)noexcept{
    const float ratio=actor.maximum?float(actor.current)/float(actor.maximum):1.f;
    if(!(ratio<.75f))return 0;
    if(!(ratio<.5f))return 1;
    if(!(ratio<.25f))return 2;
    return 3;
}
std::optional<std::uint8_t> gauge_band(const w::Actor& actor)noexcept{
    if(!actor.gauge_value||actor.character>=w::actor_gauge_limits.size())return {};
    const float percentage=100.f*(w::gauge_unsigned_float(*actor.gauge_value)/
                                  w::gauge_unsigned_float(w::actor_gauge_limits[actor.character]));
    const auto truncated=std::int32_t(percentage);
    return std::uint8_t(truncated>=90?3:truncated>=80?2:truncated>=50?1:0);
}
}
SessionActorServices::SessionActorServices(gameplay_update::Owner& update,w::ActorResourceOperations& resources,
    std::shared_ptr<SessionRooms> rooms):update_(update),resources_(resources),rooms_(std::move(rooms)){
    if(!update_.open()||!resources_.bound_to(update_.world()))
        throw std::invalid_argument("Canonical actor service owners required");
    if(rooms_){
        if(rooms_->world().get()!=&update_.world())throw std::invalid_argument("Foreign actor room owner");
        room_=rooms_->retain(update_.world().room);
        if(!room_||!room_->current(room_->identity())||!rooms_->objects()||
           update_.room_objects()!=rooms_->objects().get())
            throw std::invalid_argument("Canonical actor room geometry unavailable");
    }
}
w::actors::EntityId SessionActorServices::admit(w::World& world,w::Actor& actor)const{
    if(!update_.open()||&world!=&update_.world()||!resources_.bound_to(world))
        throw std::runtime_error("Native actor services retired or foreign");
    const auto id=world.identity_of(actor);
    if(!id||world.resolve(id).get()!=&actor)throw std::runtime_error("Native actor identity unavailable");
    return id;
}
std::shared_ptr<gameplay_collision::room_objects::Owner> SessionActorServices::objects(w::World& world)const{
    if(!update_.open()||&world!=&update_.world()||!rooms_||rooms_->world().get()!=&world||
       !room_||room_->room_number()!=world.room||!room_->current(room_->identity()))
        throw std::runtime_error("Native actor room geometry retired or unavailable");
    auto table=rooms_->objects();
    if(!table||!table->initialized()||update_.room_objects()!=table.get())
        throw std::runtime_error("Native actor room object table unavailable");
    return table;
}
void SessionActorServices::begin_offline_frame(w::World& world){
    if(!update_.open()||&world!=&update_.world()||!resources_.bound_to(world))
        throw std::runtime_error("Native offline actor session retired or foreign");
    // 8122B0 runs over all eight physical records, not only active roster slots.
    // Missing capabilities stop at their source order and retain earlier writes.
    for(std::size_t i=0;i<w::World::primary_capacity;++i){
        const auto actor=world.primary(i);
        if(!actor||!actor->ai_execution)throw std::runtime_error("Native offline primary record unavailable");
        auto& state=*actor->ai_execution;
        state.reference_signal=0;state.weight_mode=0;
        if(!actor->speech.display_style)throw std::runtime_error("Native offline display style unavailable");
        const auto style=std::bit_cast<std::uint8_t>(*actor->speech.display_style);
        if(state.previous_display_style_1076!=style)state.reference_signal=1;
        state.previous_display_style_1076=style;
        state.previous_motion_class_106f=actor->motion_class;
        state.previous_health_band_1079=state.health_band_1078;
        state.previous_gauge_band_107b=state.gauge_band_107a;
        state.health_band_1078=health_band(*actor);
        const auto gauge=gauge_band(*actor);
        if(!gauge)throw std::runtime_error("Native offline actor gauge unavailable");
        state.gauge_band_107a=*gauge;
        // The original adds character*18 + control*9 without a row guard.
        // Retain aliases within the pinned table and reject reads outside it.
        const auto row=std::size_t(actor->character)*2u+actor->ai_control;
        if(row>=offline_policy.size())throw std::runtime_error("Native offline actor policy unavailable");
        const auto& policy=offline_policy[row];
        if(policy[state.health_band_1078]||policy[4u+state.gauge_band_107a]||
           ((actor->status&3u)&&policy[8]))state.weight_mode=1;
    }
}
void SessionActorServices::run(w::Stage stage,w::World& world,w::Actor& actor){
    const auto id=admit(world,actor);
    switch(stage){
    case w::Stage::prepare_contacts:{
        const auto result=w::restore_secondary_pose_links(actor);
        if(result.status==w::SecondaryPoseLinksStatus::unavailable||result.status==w::SecondaryPoseLinksStatus::no_memory)
            throw std::runtime_error("Native actor secondary links 61A6A0 unavailable");
        return;
    }
    case w::Stage::prepare_authority:
        // Complete669790; the source's inventory return is deliberately ignored.
        if((actor.auxiliary_status&0x80u)&&(actor.status&0x1a0u))actor.status|=0x1160u;
        if(actor.room!=world.room||!(actor.status&0x40u))return;
        if(actor.status&0x1000u){actor.visible=false;return;}
        actor.visible=true;
        if(actor.primary==4&&actor.secondary==1)return;
        (void)resources_.transfer_inventory(id,0);
        actor.motion_class=0xa0;actor.primary=4;actor.secondary=1;actor.phase=actor.subphase=0;
        w::save_action_pose(actor);return;
    case w::Stage::finish_actor:
        if(w::finish_color_fade(world,id)!=w::FadeStatus::completed)
            throw std::runtime_error("Native actor color fade 6655F0 unavailable");
        return;
    case w::Stage::refresh_grid_position:
        actor.collision.previous_center_offset=actor.collision.basis.direction(actor.collision.local_center);return;
    case w::Stage::publish_notice:
        if(update_.record_actor_action(id)!=gameplay_update::PublicationStatus::completed)
            throw std::runtime_error("Native actor action publication 67E230 unavailable");
        return;
    default:throw std::runtime_error("Native actor frame stage unavailable: "+std::to_string(static_cast<unsigned>(stage)));
    }
}
bool SessionActorServices::remote_motion(w::World& world,w::Actor& actor){
    (void)admit(world,actor);
    // Complete source early gates 664804..664864; remaining remote
    // interpolation requires the canonical network observation owner.
    if(!world.filter_nonselected_input||world.mode==0||actor.category!=0||actor.slot==world.selected_actor)return false;
    throw std::runtime_error("Native remote motion 6647F0 unavailable");
}
bool SessionActorServices::find_grid(w::World& world,w::Actor& actor,std::int8_t& selected){
    (void)admit(world,actor);const auto table=objects(world);
    const auto& p=actor.position;
    if(!std::isfinite(p.x)||!std::isfinite(p.y)||!std::isfinite(p.z))
        throw std::runtime_error("Native actor grid position unavailable");
    // The room installer executes 6AD820's zero-grid reset before an optional
    // section14 install. Zero width/depth cannot admit a cell.
    if(!table->grid())return false;
    gameplay_collision::room_objects::InteractionOwner interactions(*table);
    const auto found=gameplay_collision::object_queries::elevated(*table,interactions,{p.x,p.y,p.z});
    if(found.status!=gameplay_collision::object_queries::Status::complete)
        throw std::runtime_error("Native actor grid selection 6AFD70 unavailable");
    if(found.written)selected=std::bit_cast<std::int8_t>(found.authored_ordinal);
    return bool(found.object);
}
void SessionActorServices::switch_grid(w::World& world,std::int32_t next,std::int32_t previous){
    const auto table=objects(world);gameplay_collision::room_objects::InteractionOwner interactions(*table);
    // 6AFAE0 increments its first selector and decrements its second.
    interactions.transfer(std::bit_cast<std::int8_t>(std::uint8_t(next)),
                          std::bit_cast<std::int8_t>(std::uint8_t(previous)));
}
float SessionActorServices::grid_response(w::World& world,std::uint8_t grid){
    const auto table=objects(world);gameplay_collision::room_objects::InteractionOwner interactions(*table);
    const auto id=interactions.masked(grid);
    return id?gameplay_collision::object_queries::height_offset(*table,*id):0.f;
}
}
