#include "behavior.hpp"
#include "motion.hpp"
#include <limits>
#include <stdexcept>

namespace reo::native::gameplay_world {
namespace {
class BoundHitGauge final:public actors::HitProgression {
public:
    BoundHitGauge(World& world,Actor& actor,GaugeApplication& gauge):world_(world),actor_(actor),gauge_(gauge){}
    bool apply(actors::HitActor& actor,actors::HitSession& session,std::uint16_t amount)override{
        if(&actor!=static_cast<actors::HitActor*>(&actor_)||&session!=static_cast<actors::HitSession*>(&world_.session()))return false;
        return gauge_.apply_hit_gauge(world_,actor_,amount);
    }
private:World& world_;Actor& actor_;GaugeApplication& gauge_;
};
}
BehaviorFrameServices::BehaviorFrameServices(Services& frame,BehaviorServices& behavior,
    std::span<const std::int16_t> amounts,ActivityPublication* publication,GaugeApplication* gauge,TerminalTiming* terminal,ProgressionTiming* progression,ZeroHealthApplication* zero_health):frame_(frame),behavior_(behavior),
    hit_timer_amounts_(amounts.begin(),amounts.end()),publication_(publication),gauge_(gauge),terminal_(terminal),progression_(progression),zero_health_(zero_health){}
BehaviorFrameServices::BehaviorFrameServices(Services& frame,BehaviorServices& behavior,
    const gameplay_collision::response::Grid& floors,std::span<const std::int16_t> amounts,ActivityPublication* publication,GaugeApplication* gauge,TerminalTiming* terminal,ProgressionTiming* progression,ZeroHealthApplication* zero_health):
    BehaviorFrameServices(frame,behavior,amounts,publication,gauge,terminal,progression,zero_health){floors_=&floors;}
void BehaviorFrameServices::begin_offline_frame(World& w){frame_.begin_offline_frame(w);}
void BehaviorFrameServices::run(Stage stage,World& w,Actor& a){
    if(stage==Stage::update_behavior)update_behavior(w,a,behavior_,hit_timer_amounts_,floors_,publication_,gauge_,terminal_,progression_,zero_health_,control_);
    else frame_.run(stage,w,a);
}
bool BehaviorFrameServices::remote_motion(World& w,Actor& a){return frame_.remote_motion(w,a);}
bool BehaviorFrameServices::find_grid(World& w,Actor& a,std::int8_t& grid){return frame_.find_grid(w,a,grid);}
void BehaviorFrameServices::switch_grid(World& w,std::int32_t next,std::int32_t previous){frame_.switch_grid(w,next,previous);}
float BehaviorFrameServices::grid_response(World& w,std::uint8_t grid){return frame_.grid_response(w,grid);}
void update_behavior(World& w,Actor& a,BehaviorServices& services,
                     std::span<const std::int16_t> hit_timer_amounts,
                     const gameplay_collision::response::Grid* floors,ActivityPublication* publication,GaugeApplication* gauge,TerminalTiming* terminal,ProgressionTiming* progression,ZeroHealthApplication* zero_health,ControlPreparation* control){
    auto& s=w.session();
    if(floors){sample_surface(a,*floors);resolve_surface(a,*floors);}
    else{
        services.run(BehaviorStage::sample_surface,w,a);
        services.run(BehaviorStage::resolve_surface,w,a);
    }
    a.previous_position=a.position;a.previous_orientation=a.orientation;
    if(a.category==0 && a.action_elapsed!=std::numeric_limits<std::uint32_t>::max())++a.action_elapsed;
    if(a.category==0 && a.control_elapsed!=std::numeric_limits<std::uint32_t>::max())++a.control_elapsed;
    if(a.category!=0 || (!s.paused && (!s.authority_filter || a.slot==s.selected_actor))){
        s.previous_primary=a.primary;s.previous_secondary=a.secondary;
        services.run(BehaviorStage::prepare_inventory,w,a);
        actors::tick_status(a,s,services,s.random);
        if(zero_health){if(!zero_health->apply_zero_health(w,a,services))throw std::runtime_error("Native zero-health transition unavailable");}
        else actors::select_zero_health_action(a,s,services);
        if(gauge){BoundHitGauge bound(w,a,*gauge);actors::consume_pending_hit(a,s,services,hit_timer_amounts,&bound);}
        else actors::consume_pending_hit(a,s,services,hit_timer_amounts);
        if(progression){if(!progression->apply_progression_timer(w,a))throw std::runtime_error("Native actor gauge timing unavailable");}
        else services.run(BehaviorStage::progression,w,a);
        services.run(BehaviorStage::interaction,w,a);
        if(terminal){if(!terminal->apply_terminal_timer(w,a))throw std::runtime_error("Native actor terminal timing unavailable");}
        else services.run(BehaviorStage::terminal_timer,w,a);
        if(a.category==0){
            if(control){if(!control->prepare_control(w,a))throw std::runtime_error("Native actor control preparation unavailable");}
            else services.run(BehaviorStage::prepare_control,w,a);
            services.run(BehaviorStage::analog_control,w,a);
            services.run(BehaviorStage::cooperation,w,a);
            if(services.locally_controlled(a,s) && s.inventory_owner)
                services.run(BehaviorStage::consume_control_request,w,a);
            else services.dispatch(ActionPass::primary,a.primary,w,a);
            if(a.primary!=s.previous_primary || a.secondary!=s.previous_secondary || a.phase==0xff){
                if(a.phase==0xff)save_action_pose(a);
                if(a.primary==3 || a.primary==4 || a.primary==5)services.publish(a,s,5);
                else if(!services.suppress_action_notice(w,a,s.previous_primary,s.previous_secondary))
                    services.publish(a,s,1);
            }
            if(publication){
                if(!publication->publish_activity(w,a))throw std::runtime_error("Native actor activity publication unavailable");
            }else services.run(BehaviorStage::activity_notice,w,a);
        }
    }
    a.status&=0xff7fffffu;a.auxiliary_status&=0xfffefeffu;
    if(!s.authority_filter || a.room==s.room || s.paused)
        services.dispatch(ActionPass::secondary,a.primary,w,a);
    a.auxiliary_status&=~std::uint32_t(0x400);
    if(a.response_lock)a.auxiliary_status&=~std::uint32_t(0x100);
    services.run(BehaviorStage::update_attachment,w,a);
    if(a.status&0x80)services.run(BehaviorStage::update_terminal_attachment,w,a);
}
} // namespace reo::native::gameplay_world
