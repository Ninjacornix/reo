#include "resource_pose_work.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
ResourcePoseWork::ResourcePoseWork(World& world,PoseWorkPool& pool,gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates,gameplay_collision::delivery::Packets& packets,
    const gameplay_collision::delivery::Catalog& catalog)
    :world_(world),pool_(pool),resources_(resources),templates_(templates),packets_(packets),catalog_(catalog){
    if(!bound_to(world))throw std::invalid_argument("Native resource pose-work owners unavailable");
}
bool ResourcePoseWork::bound_to(const World& world)const noexcept{return &world==&world_&&pool_.bound_to(world)&&!packets_.closed();}
ResourcePoseCreated ResourcePoseWork::attach(const actors::EntityId& parent,std::uint32_t descriptor,
    std::uint32_t kind,std::uint32_t bank,const transform_math::Matrix* basis,
    const transform_math::Vector* point,std::int32_t lifetime){
    ResourcePoseCreated result;if(!bound_to(world_))return result;
    // Source only retains this pointer. Null is admitted; foreign/stale is not.
    if(parent&&!world_.resolve(parent))return result;
    const auto made=pool_.allocate();result.status=made.status;result.work=made.id;
    if(made.status!=PoseWorkStatus::completed)return result;
    const auto actor=pool_.resolve(made.id);if(!actor||!actor->pose_work){result.status=PoseWorkStatus::unavailable;return result;}
    auto& state=*actor->pose_work;actor->active=true;actor->category=9;actor->slot=std::uint8_t(descriptor);
    state.kind=std::uint8_t(kind);state.selector=255;state.update_bound=true;
    actor->contact.related=parent;state.ordinal=std::uint8_t(PoseWorkPool::capacity-pool_.remaining());
    state.lifetime=std::bit_cast<std::int16_t>(std::uint16_t(lifetime));
    if(point)actor->position={point->x,point->y,point->z};
    if(basis)state.basis=*basis;
    if(bank>255){result.status=PoseWorkStatus::unavailable;return result;}
    const auto made_packet=packets_.attach(catalog_,std::uint8_t(bank),std::uint8_t(descriptor),
        {made.id,*actor,actor->contact,actor->character,actor->position,actor->normalized_marker});
    result.packet=made_packet.id;
    if(made_packet.status!=gameplay_collision::delivery::PacketStatus::completed&&made_packet.status!=gameplay_collision::delivery::PacketStatus::full)result.status=PoseWorkStatus::unavailable;
    return result;
}
ResourcePoseCreated ResourcePoseWork::create(const actors::EntityId& owner,const transform_math::Matrix& basis,transform_math::Vector point,std::uint32_t resource){
    ResourcePoseCreated result;if(!bound_to(world_))return result;
    const auto actor=world_.resolve(owner);if(!actor)return result;
    //5B4D50 precedes the room/resource/model admission tests.
    const auto action=resources_.action_kind(resource,templates_);
    const auto selected=std::uint8_t(resource);
    if(actor->room!=world_.room||!selected){result.status=PoseWorkStatus::completed;return result;}
    const auto key=resources_.slot(selected);const auto descriptor=key?resources_.get(*key):std::nullopt;
    if(!descriptor||!descriptor->primary){result.status=PoseWorkStatus::completed;return result;}
    const auto model=std::dynamic_pointer_cast<ResourceModel>(descriptor->primary);
    if(!model||!model->current())return result;
    const auto created=pool_.allocate();result.status=created.status;result.work=created.id;
    if(created.status!=PoseWorkStatus::completed)return result;
    const auto work=pool_.resolve(created.id);if(!work||!work->pose_work){result.status=PoseWorkStatus::unavailable;return result;}
    auto& state=*work->pose_work;work->active=true;work->category=9;work->slot=selected;state.kind=0;state.selector=255;
    state.update_bound=true;work->contact.related=owner;state.ordinal=std::uint8_t(PoseWorkPool::capacity-pool_.remaining());state.lifetime=1;
    state.velocity={};actor->auxiliary_status&=~1u;
    //5B4380 selects fallback row128 for inactive/FF descriptors.
    const auto index=descriptor->active&&descriptor->template_index!=255?descriptor->template_index:std::uint8_t(128);
    const auto flags=templates_.flags(index);
    if(flags&0x1000000u){
        state.kind=9;state.lifetime=-1;work->position={model->position.x,model->position.y,model->position.z};state.basis=model->pose;work->orientation=actor->orientation;
    }else{
        if(action<0){result.status=PoseWorkStatus::unavailable;return result;}
        const auto action_flags=metadata_.action_flags(std::uint16_t(action));
        if(action_flags&0x10400u){state.kind=2;state.lifetime=-1;work->position={model->position.x,model->position.y,model->position.z};state.basis=model->pose;}
        else{
            work->position={point.x,point.y,point.z};state.basis=basis;
            if(action_flags&0x10u){state.kind=1;state.lifetime=3;}
            if(action_flags&0x100000u){state.kind=15;state.variant=std::uint8_t(action);state.lifetime=-1;}
        }
    }
    if(action<0){result.status=PoseWorkStatus::unavailable;return result;}
    const auto contact=metadata_.contact_id(std::uint16_t(action));
    // Reached invalid native catalog data refuses after its constructor prefix.
    const auto packet=packets_.attach(catalog_,0,contact,{created.id,*work,work->contact,work->character,work->position,work->normalized_marker});
    result.packet=packet.id;
    if(packet.status!=gameplay_collision::delivery::PacketStatus::completed&&packet.status!=gameplay_collision::delivery::PacketStatus::full)result.status=PoseWorkStatus::unavailable;
    return result;
}
}
