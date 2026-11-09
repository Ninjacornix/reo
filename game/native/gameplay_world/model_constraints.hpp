#pragma once
#include "model_poses.hpp"
#include "../animation/constraints.hpp"
#include "../gameplay_collision/response.hpp"
namespace reo::native::gameplay_world {
struct ModelConstraintReport {
    bool visited{},contexts_consulted{};
    unsigned floor_queries{},raised_mask{};
    std::optional<float> base_height;
};
// Actual5D6850 creation/paused preservation. Explicit model replacement creates
// a new owner, retaining source context values until the constructor rewrites
// its fields; externally retained old owners never retarget another Instance.
void initialize_model_constraints(World&,Actor&);
// Full5D6400 policy after the common model prelude. A missing Grid is permitted
// only for actual branches that do not query it. Active attachments remain a
// separate required frameModel phase after this model/constraint publication.
ModelConstraintReport rebuild_model_constraints(World&,Actor&,ModelPoseKind,
    const ModelCorrectionScales&,const gameplay_collision::response::Grid* floors);
} // namespace reo::native::gameplay_world
