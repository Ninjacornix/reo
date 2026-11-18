#include "auxiliary_actor_postprocess.hpp"
#include "auxiliary_actors.hpp"
#include "secondary_pose_dynamics.hpp"
#include <exception>
#include <new>
namespace reo::native::gameplay_world {
AuxiliaryActorPostprocess::AuxiliaryActorPostprocess(World& world,gameplay_scene::Records& records,
    gameplay_scenario::SceneMatrixPrograms& programs,gameplay_scenario::FlagState& flags,
    const gameplay_collision::response::Grid* floors,ActorWeaponActions* weapons)noexcept
    :world_(world),records_(records),programs_(programs),flags_(flags),floors_(floors),weapons_(weapons){}
AuxiliaryActorPostprocess::~AuxiliaryActorPostprocess(){if(running_)std::terminate();}
AuxiliaryPostprocessReport AuxiliaryActorPostprocess::run()noexcept{
    if(world_.closed())return{AuxiliaryPostprocessStatus::closed};
    if(running_||world_.busy())return{AuxiliaryPostprocessStatus::busy};
    AuxiliaryPostprocessReport report;
    try{
        auto& pool=world_.auxiliary_actors();
        if(pool.closed_)return{AuxiliaryPostprocessStatus::closed};
        if(pool.busy())return{AuxiliaryPostprocessStatus::busy};
        running_=world_.updating_=pool.updating_=true;
        struct Reset{bool& running;bool& world;bool& pool;~Reset(){pool=world=running=false;}}reset{running_,world_.updating_,pool.updating_};
        for(auto id=pool.head();id;id=pool.next(id)){
            ++report.visited;report.failed=id;const auto actor=world_.resolve(id);
            if(!actor){report.status=AuxiliaryPostprocessStatus::unavailable;return report;}
            //68330C branches to the loop condition without changing its node.
            // This source profile does not terminate; it is never a skip gate.
            if(!actor->active){report.status=AuxiliaryPostprocessStatus::inactive_nonadvancing;return report;}
            const auto selected=world_.primary(world_.selected_actor);
            if(!selected){report.status=AuxiliaryPostprocessStatus::unavailable;return report;}
            if(actor->room!=selected->room)continue;
            ++report.same_room;
            const auto scene=update_actor_scene_triggers(world_,*actor,records_,programs_,flags_);
            if(scene.status!=ActorSceneTriggerStatus::completed){report.status=AuxiliaryPostprocessStatus::unavailable;return report;}
            report.scene_triggers+=scene.triggered;
            actor->auxiliary_status&=~std::uint32_t(0x80);
            if(actor->status&0x80000000u){
                actor->status&=~std::uint32_t(0x80000000u);
                if(actor->selected_resource){
                    if(!weapons_||!weapons_->bound_to(world_)||!weapons_->refresh(id)){report.status=AuxiliaryPostprocessStatus::unavailable;return report;}
                    ++report.weapons;
                }
            }
            if(!(actor->contact_flags&2)&&actor->primary==1){
                if(!floors_){report.status=AuxiliaryPostprocessStatus::unavailable;return report;}
                const auto surface=update_surface_transition(*actor,*floors_,actor->surface_transition_flags);
                if(surface==SurfaceTransitionStatus::unavailable){report.status=AuxiliaryPostprocessStatus::unavailable;return report;}
                report.surface_transitions+=surface==SurfaceTransitionStatus::applied;
            }
            const auto secondary=update_secondary_pose(*actor,world_.session().session_state,world_.paused);
            if(secondary==SecondaryPoseStatus::unavailable){report.status=AuxiliaryPostprocessStatus::unavailable;return report;}
            if(secondary==SecondaryPoseStatus::no_memory){report.status=AuxiliaryPostprocessStatus::no_memory;return report;}
            report.secondary_poses+=secondary==SecondaryPoseStatus::applied;
            if(world_.resolve(id)!=actor){report.status=AuxiliaryPostprocessStatus::unavailable;return report;}
        }
        report.failed={};return report;
    }catch(const std::bad_alloc&){report.status=AuxiliaryPostprocessStatus::no_memory;return report;}
    catch(...){report.status=AuxiliaryPostprocessStatus::unavailable;return report;}
}
}
