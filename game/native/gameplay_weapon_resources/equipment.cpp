#include "equipment.hpp"
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_weapon_resources {
Equipment::Equipment(Owner& weapons,gameplay_world::ResourceFactory& factory):weapons_(weapons),factory_(factory){
    if(!factory_.frames_.open()||!weapons_.bound_to(factory_.frames_.world_,factory_.frames_.resources_,factory_.templates_))throw std::invalid_argument("Native equipment owners unavailable or foreign");
}
bool Equipment::bound_to(const gameplay_world::World& world)const noexcept{return factory_.frames_.open()&&&factory_.frames_.world_==&world;}
Selected Equipment::reconcile(const gameplay_actors::EntityId& id)noexcept{
    using namespace gameplay_scenario;using gameplay_world::ResourceModelStatus;
    Selected result;auto& frames=factory_.frames_;
    if(!frames.open()){result.status=SceneStatus::provider_unavailable;return result;}
    const auto actor=frames.world_.resolve(id);if(!actor){result.status=SceneStatus::invalid_identity;return result;}
    if(!actor->selected_resource)return result;
    try{
        const auto resource=frames.resources_.slot(actor->selected_resource);auto descriptor=resource?frames.resources_.get(*resource):std::nullopt;
        if(!descriptor)throw std::runtime_error("Native received equipment descriptor unavailable");
        const auto tag=actor->category==0?unsigned(actor->slot)+1u:unsigned(actor->model_variant)+5u;
        // Source compares the full tag against the stored halfword; large
        // model variants must not be narrowed before this comparison.
        if(!descriptor->primary||descriptor->ownership_tag!=tag){
            descriptor->ownership_tag=std::uint16_t(tag);descriptor->flags|=1u;
            if(frames.resources_.replace(*resource,*descriptor)!=SceneStatus::completed)throw std::runtime_error("Native received equipment descriptor retired");
            result.changed=true;result.attachment=attach(actor->selected_resource);
            if(result.attachment->primary.status!=ResourceModelStatus::completed&&result.attachment->primary.status!=ResourceModelStatus::full)throw std::runtime_error("Native received equipment attachment unavailable");
        }
        const auto selected_id=frames.resources_.slot(actor->selected_resource);const auto selected=selected_id?frames.resources_.get(*selected_id):std::nullopt;
        if(!selected)throw std::runtime_error("Native received equipment action descriptor unavailable");
        const auto action=actor->selected_resource&&selected->active&&selected->template_index!=255?factory_.templates_.action_kind(selected->template_index):std::int8_t(0);
        actor->resource_action=std::uint16_t(std::int16_t(action));
    }catch(const std::exception&){result.status=SceneStatus::provider_unavailable;}
    return result;
}
Attached Equipment::attach(std::uint8_t slot)noexcept{
    using namespace gameplay_world;using namespace gameplay_scenario;
    Attached result{{ResourceModelStatus::completed,{},{}},{}};
    auto& frames=factory_.frames_;
    if(!frames.open()){result.primary.status=ResourceModelStatus::closed;return result;}
    try{
        const auto id=frames.resources_.slot(slot);auto descriptor=id?frames.resources_.get(*id):std::nullopt;
        if(!descriptor){result.primary.status=ResourceModelStatus::foreign_or_stale;return result;}
        if(!descriptor->active||!descriptor->ownership_tag)return result;
        frames.release(slot,false);descriptor=frames.resources_.get(*id);
        if(!descriptor)throw std::runtime_error("Native equipment descriptor retired");
        descriptor->flags|=0x20000u;
        if(frames.resources_.replace(*id,*descriptor)!=SceneStatus::completed)throw std::runtime_error("Native equipment descriptor retired");
        result.primary=factory_.create(descriptor->attachment_id);
        if(result.primary.status!=ResourceModelStatus::completed&&result.primary.status!=ResourceModelStatus::full)return result;
        descriptor->primary=result.primary.model;
        if(result.primary.model){result.primary.model->flags=descriptor->flags;result.primary.model->resource_slot=slot;}
        if(frames.resources_.replace(*id,*descriptor)!=SceneStatus::completed)throw std::runtime_error("Native equipment descriptor retired");
        const auto index=descriptor->template_index==255?std::uint8_t(128):descriptor->template_index;
        if(index>=factory_.templates_.state().templates.size())throw std::runtime_error("Native equipment metadata unavailable");
        if(factory_.templates_.flags(index)&1u){
            const auto population=frames.world_.session().primary_population;
            if(!population)throw std::runtime_error("Native equipment population unavailable");
            if(descriptor->ownership_tag<=*population){
                const unsigned actor_index=unsigned(descriptor->ownership_tag)-1;
                if(actor_index>=4||!frames.world_.primary(actor_index))throw std::runtime_error("Native equipment primary owner unavailable");
                result.weapons=weapons_.refresh(frames.world_.identity(actor_index));
                if(result.weapons->status!=Status::completed)throw std::runtime_error("Native equipment weapon resources unavailable");
            }
        }
    }catch(const std::bad_alloc&){result.primary.status=ResourceModelStatus::no_memory;}
    catch(const std::exception&){result.primary.status=ResourceModelStatus::unavailable;}
    return result;
}
Selected Equipment::select(const gameplay_actors::EntityId& id,std::uint8_t slot)noexcept{
    using namespace gameplay_scenario;using gameplay_world::ResourceModelStatus;
    Selected result;if(!slot)return result;
    auto& frames=factory_.frames_;
    if(!frames.open()){result.status=SceneStatus::provider_unavailable;return result;}
    const auto actor=frames.world_.resolve(id);if(!actor){result.status=SceneStatus::invalid_identity;return result;}
    try{
        const auto target_id=frames.resources_.slot(slot);auto target=target_id?frames.resources_.get(*target_id):std::nullopt;
        if(!target)throw std::runtime_error("Native equipment selection descriptor unavailable");
        const auto metadata_id=frames.resources_.slot(target->instance_index);const auto metadata=metadata_id?frames.resources_.get(*metadata_id):std::nullopt;
        if(!metadata)throw std::runtime_error("Native equipment selection self-index unavailable");
        if(!metadata->active||metadata->template_index==255||!(factory_.templates_.flags(metadata->template_index)&1u))return result;
        if(actor->slot>=4||frames.world_.primary(actor->slot)!=actor)throw std::runtime_error("Native equipment selection primary owner unavailable");
        actor->selected_resource=slot;result.changed=true;
        target->ownership_tag=std::uint16_t(actor->slot+1);
        if(frames.resources_.replace(*target_id,*target)!=SceneStatus::completed)throw std::runtime_error("Native equipment selection descriptor retired");
        result.attachment=attach(slot);
        if(result.attachment->primary.status!=ResourceModelStatus::completed&&result.attachment->primary.status!=ResourceModelStatus::full)throw std::runtime_error("Native equipment selection attachment unavailable");
        const auto selected_id=frames.resources_.slot(actor->selected_resource);const auto selected=selected_id?frames.resources_.get(*selected_id):std::nullopt;
        if(!selected)throw std::runtime_error("Native equipment selected action descriptor unavailable");
        const auto action=actor->selected_resource&&selected->active&&selected->template_index!=255?factory_.templates_.action_kind(selected->template_index):std::int8_t(0);
        actor->resource_action=std::uint16_t(std::int16_t(action));
    }catch(const std::exception&){result.status=SceneStatus::provider_unavailable;}
    return result;
}
}
