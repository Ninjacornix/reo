#pragma once
#include "bodies.hpp"
#include "../animation/model.hpp"

namespace reo::native::gameplay_world {
class ModelCorrectionScales {
public:
    virtual ~ModelCorrectionScales()=default;
    virtual float character(std::uint8_t)const=0;
    virtual float variant(std::uint16_t)const=0;
};
// Owned File1 metadata: eight player types and the125 original named NPC asset
// variants admitted by the identity-checked loader/table profile.
class File1ModelCorrectionScales final:public ModelCorrectionScales {
public:
    float character(std::uint8_t)const override;
    float variant(std::uint16_t)const override;
};
// Complete5D6FC0 correction policy. Scales come from required admitted native
// character/variant metadata; missing data is never replaced with unit scale.
void correct_model_height(World&,Actor&,const ModelCorrectionScales&);
enum class ModelPoseKind {primary,linked_actor};
// Common model scale/position/correction then376D50/193240 publication.
// Unpaused primary flags requiring5D6400 constraints fail visibly after the
// original prelude. The proven paused fast-path remains admitted; there is no
// dummy pose or after-effects legacy fallback.
void rebuild_standard_model(World&,Actor&,ModelPoseKind,const ModelCorrectionScales&);
//376CF0: standard publication from the CURRENT actor basis. It scales/corrects
// the model but does not replace basis translation from Actor.position or select
//5D6400 constraints. The enclosing cinematic phase owns prior basis updates.
void rebuild_cinematic_primary_model(World&,Actor&,const ModelCorrectionScales&);

class WorldModelPoses final:public BodyPoses {
public:
    explicit WorldModelPoses(World& world):world_(world){}
    std::shared_ptr<const JointPose> retain(const actors::EntityId&,const Actor&)override;
private:
    World& world_;
};
} // namespace reo::native::gameplay_world
