#include "scene_models.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>

namespace reo::native::gameplay_scenario {
namespace {
float finite_add(float a,float b){const float value=a+b;if(!std::isfinite(value))throw std::domain_error("Scene model finite FP32 profile");return value;}
float finite_subtract(float a,float b){const float value=a-b;if(!std::isfinite(value))throw std::domain_error("Scene model finite FP32 profile");return value;}
ModelMatrix rotation(transform_math::Vector angles){
    auto matrix=transform_math::identity();
    const auto apply=[&](const std::array<transform_math::Vector,3>& axes){
        auto factor=transform_math::identity();for(unsigned i=0;i<3;++i){factor[i][0]=axes[i].x;factor[i][1]=axes[i].y;factor[i][2]=axes[i].z;}
        const auto previous=matrix;
        for(unsigned i=0;i<3;++i){const auto result=transform_math::direction(factor,{previous[i][0],previous[i][1],previous[i][2]});matrix[i][0]=result.x;matrix[i][1]=result.y;matrix[i][2]=result.z;}
    };
    const auto x=transform_math::sin_cos(angles.x);
    apply({{{1,0,0},{0,finite_add(0,x.cosine),finite_add(0,x.sine)},{0,finite_subtract(0,x.sine),finite_add(0,x.cosine)}}});
    const auto y=transform_math::sin_cos(angles.y);
    apply({{{finite_add(0,y.cosine),0,finite_subtract(0,y.sine)},{0,1,0},{finite_add(0,y.sine),0,finite_add(0,y.cosine)}}});
    const auto z=transform_math::sin_cos(angles.z);
    apply({{{finite_add(0,z.cosine),finite_add(0,z.sine),0},{finite_subtract(0,z.sine),finite_add(0,z.cosine),0},{0,0,1}}});
    return matrix;
}
constexpr float value(std::uint32_t bits){return std::bit_cast<float>(bits);}
constexpr std::array<ModelTransformPreset,8> stock_presets{{
#include "model_transform_presets.inc"
}};
}
RoomModelRemap import_room_model_remap(const content::ScriptBank& bank){
    if(bank.format()!=content::BankFormat::room_section)throw std::invalid_argument("Room model remap requires room section");
    const auto object=bank.object(1);if(!object)throw std::invalid_argument("Missing room model remap");
    const auto bytes=bank.view(*object);if(bytes.size()<32)throw std::invalid_argument("Truncated room model remap");
    RoomModelRemap result;for(unsigned i=0;i<32;++i)result[i]=std::to_integer<std::uint8_t>(bytes[i]);return result;
}
std::span<const ModelTransformPreset,8> stock_model_transform_presets()noexcept{return stock_presets;}
std::uint8_t SceneModels::resolve(std::uint32_t authored)const noexcept{
    const auto id=std::uint8_t(authored);return id<32?remap_[id]:0;
}
ModelReference SceneModels::reference(std::uint32_t authored)const noexcept{
    const auto mapped=resolve(authored);
    const auto id=std::uint8_t(authored);
    return absent_origin_&&id<32&&(absent_authored_&(std::uint32_t(1)<<id))?ModelReference::authored(mapped,absent_origin_):ModelReference(mapped);
}
void SceneModels::room_remap(const RoomModelRemap& value)noexcept{
    remap_=value;
    if(const auto lease=absent_lease_.lock();lease&&lease->mapping_!=value)absent_lease_.reset();
}
bool SceneModels::admits_visibility(std::uint32_t authored)const noexcept{
    const auto ref=reference(authored);return !ref.absent()||admits(ref);
}
ModelStatus SceneModels::visibility(std::uint32_t authored,bool set)noexcept{
    const auto ref=reference(authored);
    if(ref.absent())return admits(ref)?ModelStatus::completed:ModelStatus::invalid_pose_slot;
    const auto slot=resolve(authored);
    if(slot<128){auto& byte=state_.visibility[slot];byte=set?std::uint8_t(byte|0x80u):std::uint8_t(byte&0x7fu);}
    else{
        // The original byte-indexed command crosses into the adjacent style
        // words. Preserve that observed effect explicitly, without an overrun
        // or a second independent flag value that could diverge from style.
        const unsigned index=(slot-128u)/4,shift=7u+8u*((slot-128u)%4);const auto mask=std::uint32_t(1)<<shift;
        auto& word=state_.styles[index];word=set?word|mask:word&~mask;
    }
    return ModelStatus::completed;
}
ModelStatus SceneModels::style(std::uint32_t authored,std::uint32_t word)noexcept{
    const auto id=std::uint8_t(authored);if(id>=32)return ModelStatus::invalid_authored_id;
    const auto slot=remap_[id];if(slot>=128)return ModelStatus::invalid_pose_slot;
    state_.styles[slot]=word;return ModelStatus::completed;
}
ModelStatus SceneModels::sound_resource(std::uint32_t model,std::uint8_t value)noexcept{
    if(model>=128)return ModelStatus::invalid_pose_slot;
    state_.sound_resources[model]=value;return ModelStatus::completed;
}
void SceneModels::mark_slot_byte(std::uint8_t slot,std::uint8_t byte)noexcept{
    if(slot<128)state_.visibility[slot]=byte;
    else{const unsigned index=(slot-128u)/4,shift=8u*((slot-128u)%4);const auto mask=std::uint32_t(255)<<shift;
        auto& word=state_.styles[index];word=(word&~mask)|(std::uint32_t(byte)<<shift);
    }
}
void SceneModels::reset_styles()noexcept{state_.styles.fill(UINT32_MAX);}
std::optional<ModelMatrix> SceneModels::pose(std::uint32_t slot)const noexcept{
    if(slot>=128)return{};
    return state_.poses[slot];
}
ModelStatus SceneModels::pose(std::uint32_t slot,const ModelMatrix& matrix)noexcept{
    if(slot>=128)return ModelStatus::invalid_pose_slot;
    state_.poses[slot]=matrix;return ModelStatus::completed;
}
ModelStatus SceneModels::adjust(std::uint32_t authored,std::size_t index,std::span<const ModelTransformPreset> presets)noexcept{
    if(index>=presets.size())return ModelStatus::invalid_preset;
    const auto reference_value=reference(authored);
    if(reference_value.absent()&&admits(reference_value))return ModelStatus::completed;
    const auto slot=resolve(authored);if(slot>=128)return ModelStatus::invalid_pose_slot;
    try{
        transform_math::require_profile();const auto& old=state_.poses[slot];const auto& preset=presets[index];
        const auto offset=transform_math::direction(old,preset.offset);const auto rotated=rotation(preset.radians);auto next=old;
        for(unsigned column=0;column<3;++column){const auto v=transform_math::direction(old,{rotated[column][0],rotated[column][1],rotated[column][2]});next[column][0]=v.x;next[column][1]=v.y;next[column][2]=v.z;}
        next[3][0]=finite_add(old[3][0],offset.x);next[3][1]=finite_add(old[3][1],offset.y);next[3][2]=finite_add(old[3][2],offset.z);
        state_.poses[slot]=next;return ModelStatus::completed;
    }catch(const std::exception&){return ModelStatus::unsupported_numeric;}
}
bool SceneModels::admits(const ModelReference& ref)const noexcept{
    if(ref.slot())return true;
    if(!ref.absent())return false;
    const auto lease=absent_lease_.lock();return lease&&lease->origin_==ref.origin_;
}
bool SceneModels::admits_channel(const ModelReference& ref,std::size_t index)const noexcept{
    if(index>=16)return false;
    if(ref.slot())return true;
    const auto lease=absent_lease_.lock();
    return ref.absent()&&lease&&lease->origin_==ref.origin_&&(lease->channels_&(std::uint16_t(1)<<index));
}
void SceneModels::authored_absence(std::shared_ptr<const AuthoredModelLease> lease)noexcept{
    absent_origin_=lease?lease->origin_:nullptr;absent_authored_=0;
    if(lease)for(unsigned i=0;i<32;++i)if(lease->mapping_[i]==255)absent_authored_|=std::uint32_t(1)<<i;
    absent_lease_=std::move(lease);state_.absent_sound_resource.reset();
}
std::optional<ModelMatrix> SceneModels::pose(const ModelReference& ref)const noexcept{
    if(const auto slot=ref.slot())return pose(std::uint32_t(*slot));
    return admits(ref)?std::optional<ModelMatrix>(ModelMatrix{}):std::nullopt;
}
ModelStatus SceneModels::pose(const ModelReference& ref,const ModelMatrix& value)noexcept{
    if(const auto slot=ref.slot())return pose(std::uint32_t(*slot),value);
    return admits(ref)?ModelStatus::completed:ModelStatus::invalid_pose_slot;
}
std::optional<std::uint8_t> SceneModels::sound_resource(const ModelReference& ref)const noexcept{
    if(const auto slot=ref.slot())return state_.sound_resources[*slot];
    return admits(ref)?state_.absent_sound_resource:std::nullopt;
}
ModelStatus SceneModels::sound_resource(const ModelReference& ref,std::uint8_t value)noexcept{
    if(const auto slot=ref.slot())return sound_resource(std::uint32_t(*slot),value);
    if(!admits(ref))return ModelStatus::invalid_pose_slot;
    state_.absent_sound_resource=value;return ModelStatus::completed;
}
} // namespace reo::native::gameplay_scenario
