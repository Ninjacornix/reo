#include "object_scene.hpp"
namespace reo::native::gameplay_collision::room_objects {
Scene::Scene(Owner& objects,gameplay_actors::EntityStore& entities,ownership::Proxies& proxies,
    ModelBindings& bindings,const response::Grid& walls,const response::Grid& floors):
    objects_(objects),interactions_(objects),lifetime_(interactions_,entities,proxies,bindings,walls,floors){}
SceneResult Scene::initialize(std::uint16_t room,response::Filter filter){
    if(closed_)return {SceneStatus::closed};
    if(started_)return {SceneStatus::already_started};
    if(!objects_.initialized())return {SceneStatus::unavailable_owner};
    if(objects_.grid_room()&&*objects_.grid_room()!=room)return {SceneStatus::unavailable_owner};
    const auto ids=objects_.objects();
    // Native retirement must precede the original raw-handle clear. Refuse a
    // caller trying to abandon another active instance/proxy owner.
    for(const auto& id:ids){const auto& object=*objects_.get(id);
        if(object.instance)return {SceneStatus::stale_lifetime};
        for(const auto& proxy:object.proxies)if(proxy)return {SceneStatus::stale_lifetime};
    }
    started_=true;SceneResult result;
    for(const auto& id:ids){
        if(!interactions_.initialize_scene_slot(id)){result.status=SceneStatus::unavailable_owner;return result;}
        ++result.visited;const auto& object=*objects_.get(id);
        if(!objects_.grid()||!(object.control_flags&1)||object.room!=room)continue;
        result.last=lifetime_.create(id);
        if(result.last.status!=InstanceStatus::complete&&result.last.status!=InstanceStatus::explicit_shape&&result.last.status!=InstanceStatus::pool_full){
            result.status=SceneStatus::construction_refused;return result;
        }
        if(result.last.instance)++result.constructed;
        if(lifetime_.append_dynamic(id,filter)!=InstanceStatus::complete){result.status=SceneStatus::dynamic_refused;return result;}
        ++count_;++result.selected;
    }
    return result;
}
InstanceStatus Scene::close()noexcept{
    const auto status=lifetime_.close_checked();if(status!=InstanceStatus::busy)closed_=true;return status;
}
}
