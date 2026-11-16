#include "resource_factory.hpp"
#include "../gameplay_effects/periodic_visuals.hpp"
#include <bit>
#include <cmath>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
constexpr std::array<std::array<std::uint32_t,7>,8> orientations{{
#include "resource_orientation_profile.inc"
}};
float finite(float value){if(!std::isfinite(value))throw std::domain_error("Native resource placement finite arithmetic required");return value;}
}
ResourceFactory::ResourceFactory(ResourceModels& models,ResourceFrames& frames,
    const gameplay_scenario::ResourceTemplates& templates,std::shared_ptr<const ResourceStaticAssets> assets):models_(models),frames_(frames),templates_(templates),assets_(std::move(assets)),token_(std::make_shared<ResourceFactoryToken>(ResourceFactoryToken{this})){
    if(!assets_||!frames_.open()||!frames_.bound_to(models_)||!frames_.templates_bound_to(templates_))throw std::invalid_argument("Native resource factory owners unavailable or foreign");
}
ResourceFactory::~ResourceFactory(){token_->owner=nullptr;}
bool ResourceFactory::replace_static_assets(std::shared_ptr<const ResourceStaticAssets> assets)noexcept{
    if(!frames_.open()||models_.busy())return false;
    assets_=std::move(assets);return true;
}
DelayedResourceWork::DelayedResourceWork(ResourceFactory& factory):owner_(factory.token_){}
void DelayedResourceWork::update(ResourceModels& models,const ResourceModelId& id,ResourceModel& model){
    const auto token=owner_.lock();if(!token||!token->owner)throw std::runtime_error("Native delayed resource factory retired");
    token->owner->delayed_frame(models,id,model);
}
bool ResourceFactory::bind_companions(gameplay_effects::PeriodicVisuals& owner)noexcept{
    if(!owner.companions_bound_to(frames_.world_,frames_.resources_,models_,templates_))return false;
    companions_=&owner;return true;
}
ResourceModelCreated ResourceFactory::create(std::uint16_t content,std::int8_t companion_argument){
    if(!frames_.open())return{ResourceModelStatus::closed,{},{}};
    if(!assets_)return{ResourceModelStatus::unavailable,{},{}};
    auto created=models_.create(ResourceModelPlacement::front);
    if(created.status!=ResourceModelStatus::completed)return created;
    try{
        const auto selector=std::bit_cast<std::uint8_t>(templates_.selector(std::bit_cast<std::int16_t>(content)));
        unsigned callback_class{};
        if(selector!=255){
            if(selector>=templates_.state().templates.size())throw std::runtime_error("Native resource callback template unavailable");
            callback_class=std::to_integer<std::uint8_t>(templates_.state().templates[selector].encoded[20]);
        }
        if(callback_class>3)throw std::runtime_error("Native resource factory callback consumer unavailable");
        bool special{};switch(content){case 0x75:case 0x135:case 0x1d:case 0x1c:case 0x3200:case 0x72:special=true;break;default:break;}
        if(special&&(!companions_||!companions_->companions_bound_to(frames_.world_,frames_.resources_,models_,templates_)))throw std::runtime_error("Native resource companion visual consumer unavailable");
        const auto index=assets_->find(std::bit_cast<std::int16_t>(content));
        auto& model=*created.model;
        model.content_id=content;model.active=true;model.category=8;model.draw_tag=255;model.asset_index=index;
        model.pose=transform_math::identity();model.axis_scale={1,1,1};
        if(index>=0){
            model.base_parts=assets_->parts(index);model.visible=true;
            for(unsigned part=0;part<model.base_parts->count;++part){model.parts[part]=model.base_parts->poses[part];model.part_enabled[part]=1;}
        }
        if(callback_class==1)model.work=std::make_shared<WeaponModelWork>(frames_);
        else if(callback_class==2)model.work=std::make_shared<DelayedResourceWork>(*this);
        else model.work=std::make_shared<CommonModelWork>(frames_);
        if(special){
            const auto effects=companions_->create_resource_companions(created.id,companion_argument);
            if(effects.status==gameplay_effects::WorkStatus::unavailable){
                for(const auto& id:effects.identities)if(id)(void)companions_->retire(id);
                throw std::runtime_error("Native resource companion construction unavailable");
            }
        }
        return created;
    }catch(const std::bad_alloc&){(void)models_.retire(created.id);return{ResourceModelStatus::no_memory,{},{}};}
    catch(const std::exception&){(void)models_.retire(created.id);return{ResourceModelStatus::unavailable,{},{}};}
}
ResourceModelCreated ResourceFactory::create_delayed(std::uint16_t content,std::int16_t ticks){
    if(!frames_.open())return{ResourceModelStatus::closed,{},{}};
    if(!assets_)return{ResourceModelStatus::unavailable,{},{}};
    auto result=models_.create(ResourceModelPlacement::front);if(result.status!=ResourceModelStatus::completed)return result;
    try{
        auto& model=*result.model;model.active=true;model.category=8;model.content_id=content;model.draw_tag=255;model.asset_index=assets_->find(std::bit_cast<std::int16_t>(content));
        model.program.elapsed=frames_.world_.session().clock_mode?std::int16_t(ticks/2):ticks;model.pose=transform_math::identity();model.axis_scale={1,1,1};model.work=std::make_shared<DelayedResourceWork>(*this);return result;
    }catch(const std::bad_alloc&){(void)models_.retire(result.id);return{ResourceModelStatus::no_memory,{},{}};}
    catch(const std::exception&){(void)models_.retire(result.id);return{ResourceModelStatus::unavailable,{},{}};}
}
void ResourceFactory::rebind(const ResourceModelId& id,std::uint16_t content){
    const auto held=models_.retain(id);if(!held)throw std::runtime_error("Native resource rebind identity foreign or retired");
    auto& model=*held;frames_.admit(id,model);model.content_id=content;
    const auto descriptor=frames_.descriptor(model.resource_slot);
    const auto selector=descriptor.active&&descriptor.template_index!=255?unsigned(descriptor.template_index):128u;
    if(selector>=templates_.state().templates.size())throw std::runtime_error("Native resource rebind template unavailable");
    const auto callback_class=std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(templates_.state().templates[selector].encoded[20]));
    if(callback_class<0||callback_class>3)throw std::runtime_error("Native resource rebind callback consumer unavailable");
    if(callback_class==1)model.work=std::make_shared<WeaponModelWork>(frames_);
    else if(callback_class==2)model.work=std::make_shared<DelayedResourceWork>(*this);
    else model.work=std::make_shared<CommonModelWork>(frames_);
    if(!assets_)throw std::runtime_error("Native static resource asset publication unavailable");
    model.asset_index=assets_->find(std::bit_cast<std::int16_t>(content));
    if(model.asset_index<0){model.visible=false;model.base_parts.reset();return;}
    model.visible=true;model.base_parts=assets_->parts(model.asset_index);
    for(unsigned part=0;part<model.base_parts->count;++part){model.part_enabled[part]=1;model.parts[part]=model.base_parts->poses[part];}
}
void ResourceFactory::delayed_frame(ResourceModels& models,const ResourceModelId& id,ResourceModel& model){
    using namespace gameplay_scenario;
    if(&models!=&models_)throw std::runtime_error("Native delayed resource model owner foreign");
    frames_.admit(id,model);
    model.visible=false;model.program.elapsed=std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(model.program.elapsed)-1));
    if(model.program.elapsed)return;
    const auto descriptor_id=frames_.resources_.slot(model.resource_slot);auto descriptor=descriptor_id?frames_.resources_.get(*descriptor_id):std::nullopt;
    if(!descriptor)throw std::runtime_error("Native delayed resource descriptor unavailable");
    if(!descriptor->active)return;
    if(descriptor->room==frames_.world_.room&&!descriptor->ownership_tag){
        const auto placed=place(*descriptor_id);if(placed.status!=ResourceModelStatus::completed&&placed.status!=ResourceModelStatus::full)throw std::runtime_error("Native delayed resource primary construction unavailable");
        descriptor=frames_.resources_.get(*descriptor_id);if(!descriptor)throw std::runtime_error("Native delayed resource descriptor changed");
        if(!(descriptor->flags&0x200000u))return;
        descriptor->flags&=~0x200000u;if(frames_.resources_.replace(*descriptor_id,*descriptor)!=SceneStatus::completed)throw std::runtime_error("Native delayed resource descriptor changed");
        if(!descriptor->ownership_tag){
            if(!collisions_||scene_room_!=frames_.world_.room)throw std::runtime_error("Native delayed resource secondary owner unavailable");
            const auto secondary=collisions_->replace(*descriptor_id);if(secondary.status!=ResourceCollisionStatus::completed&&secondary.status!=ResourceCollisionStatus::full)throw std::runtime_error("Native delayed resource secondary construction unavailable");
        }
    }else{
        descriptor->flags&=~0x200000u;if(frames_.resources_.replace(*descriptor_id,*descriptor)!=SceneStatus::completed)throw std::runtime_error("Native delayed resource descriptor changed");
    }
}
bool ResourceFactory::bind_scene(gameplay_scenario::ResourceCollisions& collisions,
    std::shared_ptr<const gameplay_collision::response::Grid> floors,std::uint16_t room)noexcept{
    if(!frames_.open()||frames_.world_.room!=room||!floors||!collisions.bound_to(frames_.resources_)||frames_.scene_records_!=collisions.records())return false;
    collisions_=&collisions;floors_=std::move(floors);scene_room_=room;return true;
}
ResourceModelCreated ResourceFactory::place(const gameplay_scenario::SceneResourceId& id){
    using namespace gameplay_scenario;
    if(!frames_.open())return{ResourceModelStatus::closed,{},{}};
    auto descriptor=frames_.resources_.get(id);if(!descriptor)return{ResourceModelStatus::foreign_or_stale,{},{}};
    if(!descriptor->ownership_tag&&(!collisions_||!floors_||scene_room_!=frames_.world_.room))return{ResourceModelStatus::unavailable,{},{}};
    if(descriptor->primary){
        const auto previous=std::dynamic_pointer_cast<ResourceModel>(descriptor->primary);const auto identity=previous?models_.identity_of(*previous):ResourceModelId{};
        if(!identity||models_.retire(identity)!=ResourceModelStatus::completed)return{ResourceModelStatus::unavailable,{},{}};
        descriptor->primary.reset();
        if(frames_.resources_.replace(id,*descriptor)!=SceneStatus::completed)return{ResourceModelStatus::foreign_or_stale,{},{}};
    }
    auto result=create(descriptor->attachment_id);
    if(result.status!=ResourceModelStatus::completed)return result;
    auto& model=*result.model;model.position=descriptor->position;model.angles[2]=descriptor->tilt;model.angles[1]=descriptor->yaw;model.flags=descriptor->flags;model.resource_slot=descriptor->instance_index;descriptor->primary=result.model;
    if(frames_.resources_.replace(id,*descriptor)!=SceneStatus::completed)return{ResourceModelStatus::foreign_or_stale,result.id,result.model};
    if(descriptor->ownership_tag)return result;
    try{
        model.flags|=0x80000u;
        //5B4380 selects metadata through the descriptor's self index, which is
        // not replaced by a second content lookup.128 is its real fallback row.
        const auto selected_id=frames_.resources_.slot(descriptor->instance_index);const auto selected=selected_id?frames_.resources_.get(*selected_id):std::nullopt;
        if(!selected)throw std::runtime_error("Native resource placement metadata descriptor unavailable");
        const auto index=selected->active&&selected->template_index!=255?selected->template_index:std::uint8_t(128);
        if(index>=templates_.state().templates.size())throw std::runtime_error("Native resource placement template index unavailable");
        const auto& metadata=templates_.state().templates[index].encoded;
        const auto angle_index=std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(metadata[12]));const auto offset_index=std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(metadata[13]));
        bool offset{};
        if(!descriptor->kind){
            if(descriptor->orientation_variant<0||unsigned(descriptor->orientation_variant)>=orientations.size()||angle_index<0||angle_index>=3)throw std::runtime_error("Native resource placement orientation profile unavailable");
            const auto tilt=std::uint16_t(orientations[unsigned(descriptor->orientation_variant)][unsigned(angle_index)]);
            if(tilt){
                model.angles[2]=tilt;offset=true;
                if(offset_index<0||unsigned(offset_index)>=templates_.state().offsets.size())throw std::runtime_error("Native resource placement offset profile unavailable");
                model.pulse_distance=finite(templates_.state().offsets[unsigned(offset_index)]);
            }
        }
        if(!offset){
            if(descriptor->template_index>=templates_.state().y_offsets.size())throw std::runtime_error("Native resource placement Y offset unavailable");
            model.position.y=finite(model.position.y+finite(templates_.state().y_offsets[descriptor->template_index]));model.pulse_distance=0;
        }
        if(!descriptor->kind){descriptor->flags&=~0x200000u;model.flags&=~0x200000u;if(frames_.resources_.replace(id,*descriptor)!=SceneStatus::completed)throw std::runtime_error("Native resource placement descriptor changed");}
        if(!(descriptor->flags&0x200000u)){
            const auto secondary=collisions_->replace(id);
            if(secondary.status!=ResourceCollisionStatus::completed&&secondary.status!=ResourceCollisionStatus::full)throw std::runtime_error("Native resource placement collision unavailable");
        }
        if(model.flags&0x800u){model.pulse_timer=std::int16_t(60+(frames_.world_.session().random.request(1)&31));model.pulse_packed=0;}
        const auto floor=floors_->floor({model.position.x,model.position.y,model.position.z},255);model.draw_layer=floor.material;
        return result;
    }catch(const std::exception&){result.status=ResourceModelStatus::unavailable;return result;}
}
gameplay_scenario::SceneStatus ResourceFactory::apply(gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::SceneResourceId& id,gameplay_scenario::SceneEffect effect,std::uint8_t index)noexcept{
    using namespace gameplay_scenario;
    if(&resources!=&frames_.resources_||!resources.get(id))return SceneStatus::invalid_identity;
    if(!frames_.open())return SceneStatus::provider_unavailable;
    try{
        switch(effect){
        case SceneEffect::construct_primary:{const auto result=place(id);return result.status==ResourceModelStatus::completed||result.status==ResourceModelStatus::full?SceneStatus::completed:SceneStatus::provider_unavailable;}
        case SceneEffect::construct_alternate:{
            if(!collisions_||scene_room_!=frames_.world_.room)return SceneStatus::provider_unavailable;
            const auto result=collisions_->replace(id);return result.status==ResourceCollisionStatus::completed||result.status==ResourceCollisionStatus::full?SceneStatus::completed:SceneStatus::provider_unavailable;
        }
        case SceneEffect::release:frames_.release(index,false);return SceneStatus::completed;
        case SceneEffect::retire_instance:{const auto target=resources.slot(index);return target?resources.deactivate(*target):SceneStatus::invalid_slot;}
        }
    }catch(const std::exception&){return SceneStatus::provider_unavailable;}
    return SceneStatus::provider_unavailable;
}
}
