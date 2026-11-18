#pragma once
#include "scene_resources.hpp"
#include "../gameplay_scene/records.hpp"
#include <stdexcept>
namespace reo::native::gameplay_scenario {
// Descriptor secondary+20 retains a real shared128 scene/control/proxy record.
// It has no primary-model flag capability and allocates no parallel scene node.
class SceneRecordAttachment final:public SceneAttachment {
public:
    SceneRecordAttachment(std::shared_ptr<gameplay_scene::Records> owner,const gameplay_scene::RecordId& id):owner_(std::move(owner)),id_(id){
        if(!owner_||!owner_->acquire(id_))throw std::invalid_argument("Native resource secondary owner foreign or stale");
    }
    bool bound_to(const gameplay_scene::Records& owner)const noexcept{return owner_.get()==&owner;}
    bool current()const noexcept{return bool(owner_->acquire(id_));}
    const gameplay_scene::RecordId& identity()const noexcept{return id_;}
    bool retire()noexcept{return owner_->retire(id_);}
private:
    std::shared_ptr<gameplay_scene::Records> owner_;
    gameplay_scene::RecordId id_;
};
}
