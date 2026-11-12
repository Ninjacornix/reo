#include "weapon_fire.hpp"
#include "resource_actor_contact_pose.hpp"
#include "../animation/constraint_math.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
constexpr float f(std::uint32_t bits){return std::bit_cast<float>(bits);}
struct FireProfile {std::uint8_t kind,style;animation::Vector offset;};
#include "weapon_fire_profile.inc"
const FireProfile& profile(std::uint16_t action){
    if(action>=fire_profiles.size())throw std::out_of_range("Native weapon firing action profile unavailable");
    return fire_profiles[action];
}
void compose_axes(animation::Matrix& destination,const animation::Matrix& source){
    for(unsigned i=0;i<3;++i){
        const auto v=transform_math::direction(source,{destination[i][0],destination[i][1],destination[i][2]});
        destination[i][0]=v.x;destination[i][1]=v.y;destination[i][2]=v.z;
    }
}
animation::Matrix firing_basis(const animation::Matrix& source){
    // Actual1901A0(-pi/2), then190100(+pi/2), then1913E0. Applying a
    // generic Euler helper here would change the noncommuting rotation order.
    const auto y=transform_math::sin_cos(f(0xbfc90fdb));auto result=transform_math::identity();
    result[0]={0.f+y.cosine,0,0.f-y.sine,0};result[2]={0.f+y.sine,0,0.f+y.cosine,0};
    compose_axes(result,animation::constraint_math::rotation_x(f(0x3fc90fdb)));
    compose_axes(result,source);return result;
}
}
ResourceActorContactPoses::ResourceActorContactPoses(World& world,gameplay_scenario::SceneResources& resources)
    :world_(world),resources_(resources){if(!bound_to(world))throw std::invalid_argument("Native actor contact pose owners unavailable");}
bool ResourceActorContactPoses::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed();}
bool ResourceActorContactPoses::rebind(const actors::EntityId& id,gameplay_effects::ActorContactState& state){
    if(!bound_to(world_))return false;
    const auto actor=world_.resolve(id);if(!actor)return false;
    const auto key=resources_.slot(actor->selected_resource);const auto descriptor=key?resources_.get(*key):std::nullopt;
    const auto model=descriptor?std::dynamic_pointer_cast<ResourceModel>(descriptor->primary):nullptr;
    if(!model||!model->current())return false;
    const auto offset=transform_math::direction(model->pose,profile(actor->resource_action).offset);
    const auto basis=firing_basis(model->pose);
    // The source always overwrites its stored50 matrix, but does not change
    // the optional1F0 binding. A NULL binding remains NULL for child sampling.
    if(state.basis)state.basis=basis;
    state.base_position={offset.x+model->position.x,offset.y+model->position.y,offset.z+model->position.z};
    return world_.resolve(id)==actor&&model->current();
}
ResourceWeaponFire::ResourceWeaponFire(World& world,gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates,animation_events::BasicAudio& audio,
    WorldResourcePrograms& programs,ResourceHealthUi* ui,WeaponEffects* effects)
    :world_(world),resources_(resources),templates_(templates),audio_(audio),programs_(programs),ui_(ui),effects_(effects){
    if(!bound_to(world_,resources_,templates_))throw std::invalid_argument("Native weapon firing owners foreign or unavailable");
}
bool ResourceWeaponFire::bound_to(const World& world,const gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates)const noexcept{
    return &world_==&world&&&resources_==&resources&&&templates_==&templates&&!world_.closed()&&
        audio_.bound_to(world_,resources_,templates_)&&programs_.bound_to(world_,resources_)&&
        (!ui_||ui_->bound_to(world_))&&(!effects_||effects_->bound_to(world_));
}
bool ResourceWeaponFire::fire(const actors::EntityId& actor,std::uint8_t resource){return fire_resource(actor,resource);}
bool ResourceWeaponFire::fire_resource(const actors::EntityId& id,std::uint32_t resource){
    if(!bound_to(world_,resources_,templates_))return false;
    const auto actor=world_.resolve(id);if(!actor)return false;
    if(!(metadata_.action_flags(actor->resource_action)&0x10u))return true;
    const auto key=resources_.slot(std::uint8_t(resource));const auto item=key?resources_.get(*key):std::nullopt;
    if(!item)return false;
    if(!item->primary)return true;
    const auto model=std::dynamic_pointer_cast<ResourceModel>(item->primary);
    if(!model||!model->current()||!ui_||!ui_->feedback(id,5))return false;
    const auto live=[&]{return world_.resolve(id)==actor&&model->current();};
    if(!live())return false;
    const auto origin=animation::constraint_math::add(transform_math::direction(model->pose,profile(actor->resource_action).offset),model->position);
    const auto basis=firing_basis(model->pose); //191500 copies all sixteen lanes.
    const auto effect_owner=[&]{return effects_&&effects_->bound_to(world_)&&live();};
    if(actor->primary==5){
        if(actor->resource_action==0||!(metadata_.action_flags(actor->resource_action)&0x800u))return true;
        audio_.resource(*actor,0);if(!live())return false;
        if(!(metadata_.action_flags(actor->resource_action)&0x20000u)){
            if(!effect_owner()||!effects_->transient_light(id,model->position)||!live())return false;
            if(!effects_->contact_style(id,basis,origin,profile(actor->resource_action).style)||!live())return false;
            if(!effects_->flight(id,model->pose,std::uint32_t(actor->resource_action)-1u)||!live())return false;
        }
    }else{
        const auto kind=profile(actor->resource_action).kind;
        if(actor->character>=8||kind>=fire_distances.size())return false;
        const auto position=animation::constraint_math::add(origin,transform_math::direction(basis,{0,0,fire_distances[kind][actor->character]}));
        if(!effect_owner()||!effects_->pose_work(id,basis,position,resource)||!live())return false;
        audio_.resource(*actor,0);if(!live())return false;
        if(!(metadata_.action_flags(actor->resource_action)&0x20000u)){
            if(!effects_->transient_light(id,model->position)||!live())return false;
            if(actor->resource_action!=12&&(!effects_->flight(id,model->pose,std::uint32_t(actor->resource_action)-1u)||!live()))return false;
            if(actor->primary==2&&(actor->secondary==2||actor->secondary==12)&&actor->subphase==0){
                if(!effects_->contact_style(id,basis,origin,profile(actor->resource_action).style)||!live())return false;
            }
        }
    }
    programs_.select(*actor,0);return live();
}
}
