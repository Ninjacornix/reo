#include "scripted_actor_construction.hpp"
#include "../animation/playback.hpp"
#include <new>
#include <stdexcept>

namespace reo::native::gameplay_update {
namespace world=gameplay_world;
ScriptedActorConstruction::ScriptedActorConstruction(world::World& world,MaterialAnimations& materials):world_(world),materials_(materials){
    if(!materials_.bound_to(world_))throw std::invalid_argument("Native scripted actor task owner mismatch");
}
std::shared_ptr<const PreparedScriptedActor> ScriptedActorConstruction::prepare(const ScriptedActorRequest& request,const world::ActorAssets& assets)const {
    auto prepared=std::shared_ptr<PreparedScriptedActor>(new PreparedScriptedActor);
    prepared->group_=std::uint8_t(request.model_group);prepared->type_=std::uint8_t(request.type);
    prepared->variant_=std::uint8_t(request.variant);prepared->definition_=std::uint8_t(request.definition_index);
    const world::File1LinkedModelProfiles profiles;
    prepared->scale_=profiles.definition(prepared->type_,prepared->definition_).scale;
    const auto bank=prepared->definition_==1?world::ModelDefinitionBank::alternate:world::ModelDefinitionBank::ordinary;
    const auto& selected=profiles.definition(prepared->type_,prepared->variant_,bank);
    // The shadow selector always uses the ordinary BBA row, even when the
    // model constructor selects the alternate bank through54D==1.
    const auto& shadow=profiles.definition(prepared->type_,prepared->variant_);
    prepared->render_={bank,selected.model,selected.texture,selected.construction_mode,shadow.shadow_enabled,shadow.shadow_asset};
    prepared->asset_=assets.read(prepared->type_,prepared->variant_,bank);
    if(prepared->asset_&&prepared->asset_->part_count()>32)
        throw std::invalid_argument("Native scripted actor part visibility profile unavailable");
    return prepared;
}
ScriptedConstructed ScriptedActorConstruction::create(const PreparedScriptedActor& prepared)noexcept {
    if(!materials_.bound_to(world_))return{};
    try {
        // Prepare allocations before admitting a live actor. Missing content
        // already failed prepare, preserving the current World and task pool.
        auto model=prepared.asset_?prepared.asset_->make_instance():nullptr;
        auto animation=model?std::make_shared<animation::Playback>(model):nullptr;
        // Fresh6BA300 actors have zero524 and three known null bank bindings.
        // A later scene motion owner supplies their actual resources/count.
        if(animation){animation->channel_count=0;animation->resources_known=true;}
        world::ScriptedActorState state;
        state.model_group=prepared.group_;state.color.fill(255);state.alpha_mode=-1;state.alpha=255;
        state.part_visibility.assign(prepared.asset_?prepared.asset_->part_count():0,1);
        state.render=prepared.render_;
        const auto created=world_.linked_models().allocate(true);
        if(created.status==world::LinkedStatus::full)return{ScriptedConstructionStatus::full,{},{}};
        if(created.status==world::LinkedStatus::no_memory)return{ScriptedConstructionStatus::no_memory,{},{}};
        if(created.status!=world::LinkedStatus::completed)return{};
        const auto actor=world_.resolve(created.id);
        actor->active=false;actor->visible=false;actor->category=2;actor->slot=prepared.type_;
        actor->linked_model_variant=prepared.variant_;actor->model_pose_class=prepared.definition_;
        actor->motion_multiplier=1;actor->model_scale={prepared.scale_,prepared.scale_,prepared.scale_};
        actor->model=std::move(model);actor->animation=std::move(animation);actor->model_asset=prepared.asset_;
        actor->scripted=std::move(state);
        ScriptedConstructed result{ScriptedConstructionStatus::completed,created.id,{}};
        if(actor->slot==27)result.material_task=materials_.create(created.id);
        return result;
    }catch(const std::bad_alloc&){return{ScriptedConstructionStatus::no_memory,{},{}};}
}
}
