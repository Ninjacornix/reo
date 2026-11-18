#include "primary_actor_postprocess.hpp"
#include <bit>
#include <exception>
#include <new>
namespace reo::native::gameplay_world {
PrimaryActorPostprocess::PrimaryActorPostprocess(World& world,gameplay_scene::Records& records,gameplay_scenario::SceneMatrixPrograms& programs,gameplay_scenario::FlagState& flags,gameplay_events::Statistics& statistics,const gameplay_collision::response::Grid* floors,ActorWeaponActions* weapons)noexcept:
    world_(world),records_(records),programs_(programs),flags_(flags),statistics_(statistics),floors_(floors),weapons_(weapons){}
PrimaryActorPostprocess::~PrimaryActorPostprocess(){if(running_)std::terminate();}
PrimaryPostprocessReport PrimaryActorPostprocess::run(const HeadReactionContext& context)noexcept{
    if(world_.closed())return{PrimaryPostprocessStatus::closed};
    if(running_||world_.busy())return{PrimaryPostprocessStatus::busy};
    PrimaryPostprocessReport report;running_=world_.updating_=true;
    struct Reset{PrimaryActorPostprocess& owner;~Reset(){owner.world_.executing_.reset();owner.world_.updating_=false;owner.running_=false;}}reset{*this};
    try{
        for(std::size_t index=0;index<World::primary_capacity;++index){
            const auto actor=world_.primary(index);if(!actor||!actor->active)continue;
            const auto id=world_.identity(index);world_.executing_=index;++report.visited;report.failed=id;
            if(world_.mode==0)world_.selected_actor=actor->slot;
            actor->auxiliary_status&=~std::uint32_t(0x80);
            if(actor->status&0x80000000u){
                //65EC40 clears this request before its known-zero C7C return.
                actor->status&=~std::uint32_t(0x80000000u);
                if(actor->selected_resource){
                    if(!weapons_||!weapons_->bound_to(world_)||!weapons_->refresh(id)){report.status=PrimaryPostprocessStatus::unavailable;return report;}
                    ++report.weapons;
                }
            }
            if(actor->room!=world_.room)continue;
            ++report.same_room;
            const auto scene=update_actor_scene_triggers(world_,*actor,records_,programs_,flags_);
            if(scene.status!=ActorSceneTriggerStatus::completed){report.status=PrimaryPostprocessStatus::unavailable;return report;}
            report.scene_triggers+=scene.triggered;
            if(!(actor->contact_flags&2)&&actor->primary==1){
                if(!floors_){report.status=PrimaryPostprocessStatus::unavailable;return report;}
                const auto transition=update_surface_transition(*actor,*floors_,actor->surface_transition_flags);
                if(transition==SurfaceTransitionStatus::unavailable){report.status=PrimaryPostprocessStatus::unavailable;return report;}
                report.surface_transitions+=transition==SurfaceTransitionStatus::applied;
            }
            const auto reaction=finish_ordinary_actor_reactions(world_,*actor,context);
            if(reaction==HeadReactionStatus::no_memory){report.status=PrimaryPostprocessStatus::no_memory;return report;}
            if(reaction==HeadReactionStatus::unavailable){report.status=PrimaryPostprocessStatus::unavailable;return report;}
            ++report.reactions;
            if(world_.locally_controlled(*actor)&&!(actor->status&4u)){
                if(!statistics_.actor_frame(actor->root_motion_delta.z,std::bit_cast<std::int16_t>(actor->current),std::bit_cast<std::int16_t>(actor->maximum),actor->status)){report.status=PrimaryPostprocessStatus::unavailable;return report;}
                ++report.statistics;
            }
        }
        if(world_.mode==0)world_.selected_actor=0;
        report.failed={};return report;
    }catch(const std::bad_alloc&){report.status=PrimaryPostprocessStatus::no_memory;return report;}
    catch(...){report.status=PrimaryPostprocessStatus::unavailable;return report;}
}
}
