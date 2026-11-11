#include "linked_updates.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
const gameplay_collision::response::Grid& require_floors(const std::shared_ptr<const gameplay_collision::response::Grid>& value){
    if(!value)throw std::invalid_argument("Native linked actor floor owner unavailable");
    return *value;
}
}
LinkedActorUpdates::LinkedActorUpdates(World& world,ScriptedMotionBanks banks,
    std::shared_ptr<const gameplay_collision::response::Grid> floors,LinkedExpirySink* publication):
    world_(world),floors_(std::move(floors)),motion_(world_,std::move(banks)),
    cutscene_(world_,motion_,require_floors(floors_)),pose_(require_floors(floors_)),publication_(publication){
    if(world_.linked_update_owner_)throw std::invalid_argument("Native World already has a linked update owner");
    world_.linked_update_owner_=this;
}
LinkedActorUpdates::~LinkedActorUpdates(){if(running_)std::terminate();(void)close();}
LinkedUpdateStatus LinkedActorUpdates::close()noexcept {
    if(running_)return LinkedUpdateStatus::busy;
    closed_=true;
    if(world_.linked_update_owner_==this)world_.linked_update_owner_=nullptr;
    return LinkedUpdateStatus::completed;
}
LinkedUpdated LinkedActorUpdates::run(){
    if(closed_||world_.closed())return{LinkedUpdateStatus::closed};
    auto& pool=world_.linked_models();
    if(running_||pool.busy())return{LinkedUpdateStatus::busy};
    running_=true;pool.updating_=true;
    struct Reset {bool& running;bool& pool;~Reset(){pool=false;running=false;}}reset{running_,pool.updating_};
    LinkedUpdated result;
    auto& session=world_.session();
    result.periodic=session.linked_updates.prepare(session.timer_seconds(),session.clock_mode);
    if(result.periodic){
        for(unsigned index=0;index<gameplay_scenario::EnemyDescriptors::capacity;++index){
            if(!session.enemy_descriptors.decrement_expiry(index))continue;
            ++result.expired;
            const auto& record=session.enemy_descriptors.records()[index];
            if((session.message_phase==1||session.message_phase==2)&&record.owner_mode!=1&&(world_.mode==0||world_.mode==1)){
                if(!publication_||!publication_->expired({world_.mode,record.ordinal}))++result.publication_failures;
            }
        }
    }
    for(auto id=pool.tail();id;id=pool.previous(id)){
        const auto actor=pool.resolve(id);++result.visited;
        if(!actor->active){
            if(!actor->linked_frame){result.status=LinkedUpdateStatus::unavailable;return result;}
            actor->linked_frame->transient_marker=0;
            continue;
        }
        auto* record=session.enemy_descriptors.record(actor->character);
        record->runtime_flags&=std::uint8_t(~0x10u);
        if(!actor->scripted){result.status=LinkedUpdateStatus::unavailable;return result;}
        cutscene_.tick(id);++result.called;
        if(world_.resolve(id)!=actor||!actor->targeting||!actor->linked_frame){result.status=LinkedUpdateStatus::unavailable;return result;}
        if(!(actor->targeting->flags&4)){rebuild_actor_pose(world_,*actor,pose_);++result.poses;}
        auto& frame=*actor->linked_frame;
        if(frame.center_cache_state==0){
            frame.center_cache_state=1;
            actor->collision.previous_center_offset=actor->collision.basis.direction(actor->collision.local_center);
            ++result.center_initializations;
        }
        frame.transient_marker=0;
    }
    return result;
}
}
