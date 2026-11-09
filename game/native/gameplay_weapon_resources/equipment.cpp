#include "equipment.hpp"
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_weapon_resources {
Equipment::Equipment(Owner& weapons,gameplay_world::ResourceFactory& factory):weapons_(weapons),factory_(factory){
    if(!factory_.frames_.open()||!weapons_.bound_to(factory_.frames_.world_,factory_.frames_.resources_,factory_.templates_))throw std::invalid_argument("Native equipment owners unavailable or foreign");
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
}
