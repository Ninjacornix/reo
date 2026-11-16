#include "scene_model_bindings.hpp"
#include <utility>

namespace reo::native::gameplay_scenario {
namespace {
struct Exit {bool& busy;~Exit(){busy=false;}};
ModelMatrix matrix(const gameplay_collision::actors::Basis& b,const std::array<float,4>& w)noexcept{
    return {{{b.x.x,b.x.y,b.x.z,w[0]},{b.y.x,b.y.y,b.y.z,w[1]},{b.z.x,b.z.y,b.z.z,w[2]},{b.translation.x,b.translation.y,b.translation.z,w[3]}}};
}
void copy_pose(SceneModelBindings::ObjectInstance& object,const ModelMatrix& m)noexcept{
    object.basis={{m[0][0],m[0][1],m[0][2]},{m[1][0],m[1][1],m[1][2]},{m[2][0],m[2][1],m[2][2]},{m[3][0],m[3][1],m[3][2]}};
    for(unsigned i=0;i<4;++i)object.pose_w[i]=m[i][3];
}
}
SceneModelBindings::SceneModelBindings(SceneModels& models,gameplay_actors::EntityStore& scene)noexcept:models_(models),scene_(scene){}
SceneModelBindings::~SceneModelBindings(){(void)close();}
void SceneModelBindings::fail(ModelBindingError code,std::uint8_t slot)noexcept{
    if(failure_.code==ModelBindingError::none)failure_={code,slot};
}
bool SceneModelBindings::enter(std::uint8_t slot,bool cleanup)noexcept{
    if(closed_){fail(ModelBindingError::closed,slot);return false;}
    if(busy_){fail(ModelBindingError::busy,slot);return false;}
    if(!cleanup&&failure_.code!=ModelBindingError::none)return false;
    busy_=true;return true;
}
std::uint8_t SceneModelBindings::resolve(std::uint8_t authored)const noexcept{return models_.resolve(authored);}
bool SceneModelBindings::admit(std::uint8_t authored,gameplay_collision::room_objects::ModelOperation operation)noexcept{
    if(closed_){fail(ModelBindingError::closed,authored);return false;}
    if(busy_){fail(ModelBindingError::busy,authored);return false;}
    if(operation==gameplay_collision::room_objects::ModelOperation::create&&!healthy())return false;
    const auto slot=resolve(authored);
    if(slot>=128&&(slot!=255||operation!=gameplay_collision::room_objects::ModelOperation::create)){fail(ModelBindingError::invalid_slot,slot);return false;}
    return true;
}
void SceneModelBindings::mark(std::uint8_t slot)noexcept{
    if(!enter(slot))return;
    const Exit exit{busy_};models_.mark_slot_byte(slot,1);
}
void SceneModelBindings::bind(std::uint8_t slot,EntityId id)noexcept{
    if(!enter(slot))return;
    const Exit exit{busy_};
    const auto pose=models_.pose(slot);if(!pose){fail(ModelBindingError::invalid_slot,slot);return;}
    const auto entity=scene_.acquire(id);if(!entity){fail(ModelBindingError::foreign_or_stale,slot);return;}
    auto object=std::dynamic_pointer_cast<ObjectInstance>(entity);if(!object){fail(ModelBindingError::wrong_entity_kind,slot);return;}
    Binding next{id,std::move(object),{}};auto old=std::exchange(bindings_[slot],std::move(next));copy_pose(*bindings_[slot].object,*pose);
}
bool SceneModelBindings::bind_pose(std::uint8_t slot,std::shared_ptr<ModelMatrix> target)noexcept{
    if(!enter(slot))return false;
    const Exit exit{busy_};const auto pose=models_.pose(slot);if(!pose){fail(ModelBindingError::invalid_slot,slot);return false;}
    if(!target){fail(ModelBindingError::missing_target,slot);return false;}
    Binding next{{},{},std::move(target)};auto old=std::exchange(bindings_[slot],std::move(next));*bindings_[slot].matrix=*pose;
    old={};return failure_.code==ModelBindingError::none;
}
void SceneModelBindings::unbind(std::uint8_t slot)noexcept{
    if(!enter(slot,true))return;
    const Exit exit{busy_};if(slot>=128){fail(ModelBindingError::invalid_slot,slot);return;}
    auto old=std::exchange(bindings_[slot],Binding{});
}
void SceneModelBindings::retain_pose(std::uint8_t slot,const gameplay_collision::actors::Basis&)noexcept{
    fail(ModelBindingError::missing_full_pose,slot);
}
void SceneModelBindings::retain_pose_full(std::uint8_t slot,const gameplay_collision::actors::Basis& basis,const std::array<float,4>& w)noexcept{
    if(!enter(slot,true))return;
    const Exit exit{busy_};if(models_.pose(slot,matrix(basis,w))!=ModelStatus::completed)fail(ModelBindingError::invalid_slot,slot);
}
std::optional<ModelMatrix> SceneModelBindings::live_pose(std::uint8_t slot)noexcept{
    if(!enter(slot))return{};
    const Exit exit{busy_};if(slot>=128){fail(ModelBindingError::invalid_slot,slot);return{};}
    const auto& binding=bindings_[slot];
    if(binding.object){if(scene_.acquire(binding.id)!=binding.object){fail(ModelBindingError::foreign_or_stale,slot);return{};}
        return matrix(binding.object->basis,binding.object->pose_w);
    }
    if(binding.matrix)return *binding.matrix;
    return models_.pose(slot);
}
bool SceneModelBindings::admit_reference(const ModelReference& ref,gameplay_collision::room_objects::ModelOperation operation)noexcept{
    if(ref.absent()&&operation==gameplay_collision::room_objects::ModelOperation::retire)return true;
    const auto code=std::uint8_t(ref.encoded());
    if(closed_){fail(ModelBindingError::closed,code);return false;}
    if(busy_){fail(ModelBindingError::busy,code);return false;}
    if(!healthy())return false;
    if(!models_.admits(ref)){fail(ref.absent()?ModelBindingError::foreign_or_stale:ModelBindingError::invalid_slot,code);return false;}
    return true;
}
void SceneModelBindings::mark(const ModelReference& ref)noexcept{
    if(const auto slot=ref.slot()){mark(*slot);return;}
    if(!enter(std::uint8_t(ref.encoded())))return;
    const Exit exit{busy_};if(!models_.admits(ref))fail(ref.absent()?ModelBindingError::foreign_or_stale:ModelBindingError::invalid_slot,std::uint8_t(ref.encoded()));
}
void SceneModelBindings::bind(const ModelReference& ref,EntityId id)noexcept{
    if(const auto slot=ref.slot()){bind(*slot,std::move(id));return;}
    if(!enter(std::uint8_t(ref.encoded())))return;
    const Exit exit{busy_};if(!models_.admits(ref))fail(ref.absent()?ModelBindingError::foreign_or_stale:ModelBindingError::invalid_slot,std::uint8_t(ref.encoded()));
}
void SceneModelBindings::retain_pose_full(const ModelReference& ref,const gameplay_collision::actors::Basis& value,const std::array<float,4>& w)noexcept{
    if(const auto slot=ref.slot()){retain_pose_full(*slot,value,w);return;}
    if(ref.absent())return; // no mesh/pose storage exists, including at teardown
    if(!enter(std::uint8_t(ref.encoded()),true))return;
    const Exit exit{busy_};fail(ModelBindingError::invalid_slot,std::uint8_t(ref.encoded()));
}
bool SceneModelBindings::bind_pose(const ModelReference& ref,std::shared_ptr<ModelMatrix> target)noexcept{
    if(const auto slot=ref.slot())return bind_pose(*slot,std::move(target));
    if(!enter(std::uint8_t(ref.encoded())))return false;
    const Exit exit{busy_};
    const auto pose=models_.pose(ref);if(!pose){fail(ref.absent()?ModelBindingError::foreign_or_stale:ModelBindingError::invalid_slot,std::uint8_t(ref.encoded()));return false;}
    if(!target){fail(ModelBindingError::missing_target,255);return false;}
    *target=*pose;return failure_.code==ModelBindingError::none;
}
void SceneModelBindings::unbind(const ModelReference& ref)noexcept{
    if(const auto slot=ref.slot()){unbind(*slot);return;}
    // NoModel has no registered target or mask to release, including after its
    // installation lease expires. Cleanup cannot touch an unrelated owner.
    if(ref.absent())return;
    if(!enter(std::uint8_t(ref.encoded()),true))return;
    const Exit exit{busy_};fail(ModelBindingError::invalid_slot,std::uint8_t(ref.encoded()));
}
std::optional<ModelMatrix> SceneModelBindings::live_pose(const ModelReference& ref)noexcept{
    if(const auto slot=ref.slot())return live_pose(*slot);
    if(!enter(std::uint8_t(ref.encoded())))return{};
    const Exit exit{busy_};const auto pose=models_.pose(ref);
    if(!pose)fail(ref.absent()?ModelBindingError::foreign_or_stale:ModelBindingError::invalid_slot,std::uint8_t(ref.encoded()));
    return pose;
}
std::array<std::uint32_t,4> SceneModelBindings::mask()const noexcept{
    std::array<std::uint32_t,4> result{};for(unsigned i=0;i<128;++i)if(bindings_[i].object||bindings_[i].matrix)result[i/32]|=std::uint32_t(1)<<(i%32);return result;
}
SceneModelBindings::EntityId SceneModelBindings::target(std::uint8_t slot)const noexcept{return slot<128?bindings_[slot].id:EntityId{};}
ModelBindingError SceneModelBindings::reset()noexcept{
    if(closed_)return ModelBindingError::closed;
    if(busy_)return ModelBindingError::busy;
    busy_=true;const Exit exit{busy_};
    // Keep the owner guarded while releasing the previous native leases.
    auto previous=std::move(bindings_);bindings_={};failure_={};previous={};
    return ModelBindingError::none;
}
ModelBindingError SceneModelBindings::close()noexcept{
    if(closed_)return failure_.code;
    if(busy_){fail(ModelBindingError::busy,0);return failure_.code;}
    closed_=true;busy_=true;auto previous=std::move(bindings_);bindings_={};previous={};busy_=false;return failure_.code;
}
} // namespace reo::native::gameplay_scenario
