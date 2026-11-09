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
void SceneModels::visibility(std::uint32_t authored,bool set)noexcept{
    const auto slot=resolve(authored);
    if(slot<128){auto& byte=state_.visibility[slot];byte=set?std::uint8_t(byte|0x80u):std::uint8_t(byte&0x7fu);}
    else{
        // The original byte-indexed command crosses into the adjacent style
        // words. Preserve that observed effect explicitly, without an overrun
        // or a second independent flag value that could diverge from style.
        const unsigned index=(slot-128u)/4,shift=7u+8u*((slot-128u)%4);const auto mask=std::uint32_t(1)<<shift;
        auto& word=state_.styles[index];word=set?word|mask:word&~mask;
    }
}
ModelStatus SceneModels::style(std::uint32_t authored,std::uint32_t word)noexcept{
    const auto id=std::uint8_t(authored);if(id>=32)return ModelStatus::invalid_authored_id;
    const auto slot=remap_[id];if(slot>=128)return ModelStatus::invalid_pose_slot;
    state_.styles[slot]=word;return ModelStatus::completed;
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
    const auto slot=resolve(authored);if(slot>=128)return ModelStatus::invalid_pose_slot;
    try{
        transform_math::require_profile();const auto& old=state_.poses[slot];const auto& preset=presets[index];
        const auto offset=transform_math::direction(old,preset.offset);const auto rotated=rotation(preset.radians);auto next=old;
        for(unsigned column=0;column<3;++column){const auto v=transform_math::direction(old,{rotated[column][0],rotated[column][1],rotated[column][2]});next[column][0]=v.x;next[column][1]=v.y;next[column][2]=v.z;}
        next[3][0]=finite_add(old[3][0],offset.x);next[3][1]=finite_add(old[3][1],offset.y);next[3][2]=finite_add(old[3][2],offset.z);
        state_.poses[slot]=next;return ModelStatus::completed;
    }catch(const std::exception&){return ModelStatus::unsupported_numeric;}
}
} // namespace reo::native::gameplay_scenario
