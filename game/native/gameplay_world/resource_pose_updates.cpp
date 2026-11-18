#include "resource_pose_updates.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
ResourcePoseUpdates::ResourcePoseUpdates(World& world,PoseWorkPool& pool,gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates,gameplay_collision::delivery::Packets& packets,
    const gameplay_collision::delivery::Catalog& catalog,PoseWorkUpdates* remaining)
    :world_(world),pool_(pool),resources_(resources),templates_(templates),packets_(packets),catalog_(catalog),remaining_(remaining){
    if(!bound_to(world))throw std::invalid_argument("Native resource pose-update owners unavailable");
}
bool ResourcePoseUpdates::bound_to(const World& world)const noexcept{return &world==&world_&&pool_.bound_to(world)&&(!remaining_||remaining_->bound_to(world));}
bool ResourcePoseUpdates::update(PoseWorkPool& pool,const actors::EntityId& id,std::uint8_t kind){
    if(&pool!=&pool_||!bound_to(world_))return false;
    const auto actor=pool_.resolve(id);if(!actor||!actor->pose_work)return false;
    auto& state=*actor->pose_work;
    if(kind==1){
        // Complete582E30 performs this lookup even in unhandled phases.
        const auto action=resources_.action_kind(actor->slot,templates_);
        if(actor->primary==0){actor->primary=1;actor->visible=true;return true;}
        if(actor->primary!=1)return true;
        ++actor->primary;
        const auto valid=[](const auto& value){return value.category!=255&&value.token!=255;};
        if(actor->contact.serial&&(valid(actor->contact.recipient)||valid(actor->contact.related_recipient))){
            actor->contact.serial=0;actor->auxiliary_status|=1;state.lifetime=1;return true;
        }
        if(action<0||packets_.closed())return false;
        const auto descriptor=std::uint32_t(metadata_.contact_id(std::uint16_t(action)))+0x100u;
        const auto created=packets_.attach(catalog_,0,std::int32_t(descriptor),{id,*actor,actor->contact,actor->character,actor->position,actor->normalized_marker});
        return created.status==gameplay_collision::delivery::PacketStatus::completed||created.status==gameplay_collision::delivery::PacketStatus::full;
    }
    if(kind==2){
        if(actor->primary==0){actor->primary=1;actor->visible=false;}
        if(actor->primary!=1)return true;
        const auto parent=world_.resolve(actor->contact.related);if(!parent)return false;
        const auto key=resources_.slot(actor->slot);const auto descriptor=key?resources_.get(*key):std::nullopt;
        const auto model=descriptor?std::dynamic_pointer_cast<ResourceModel>(descriptor->primary):nullptr;
        if(descriptor&&descriptor->primary&&(!model||!model->current()))return false;
        if(actor->response_class||!model||(parent->auxiliary_status&1u)){
            ++actor->primary;actor->auxiliary_status|=1;state.lifetime=1;parent->auxiliary_status&=~1u;return true;
        }
        actor->position={model->position.x,model->position.y,model->position.z};state.basis=model->pose;return true;
    }
    if(kind==10){
        if(actor->primary==0){actor->primary=1;actor->visible=true;}
        if(actor->primary==1&&actor->response_class){
            ++actor->primary;actor->auxiliary_status|=1;return pool_.retire(id,true)==PoseWorkStatus::completed;
        }
        return true;
    }
    if(kind==14){
        if(actor->primary==0){
            actor->primary=1;state.timer=10;
            const auto parent=world_.resolve(actor->contact.related);if(!parent)return false;
            actor->previous_position=parent->position;return true;
        }
        if(actor->primary!=1)return true;
        state.timer=std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(state.timer)-1));
        return state.timer>0||pool_.retire(id,true)==PoseWorkStatus::completed;
    }
    return remaining_&&remaining_->update(pool_,id,kind);
}
}
