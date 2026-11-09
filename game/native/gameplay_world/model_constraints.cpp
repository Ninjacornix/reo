#include "model_constraints.hpp"
#include <cmath>
#include <stdexcept>

namespace reo::native::gameplay_world {
namespace {
float finite(float v){if(!std::isfinite(v))throw std::domain_error("Native model ground finite arithmetic required");return v;}
auto matrix(const gameplay_collision::actors::Basis& b){return animation::Matrix{{{b.x.x,b.x.y,b.x.z,0},{b.y.x,b.y.y,b.y.z,0},{b.z.x,b.z.y,b.z.z,0},{b.translation.x,b.translation.y,b.translation.z,1}}};}
animation::Vector translation(const animation::Matrix& m){return{m[3][0],m[3][1],m[3][2]};}
animation::Vector offset(const animation::Matrix& m,bool positive){const auto lane=[&](unsigned i){const float delta=finite(50.f*m[0][i]);return positive?finite(m[3][i]+delta):finite(m[3][i]-delta);};return{lane(0),lane(1),lane(2)};}
void joint_two(Actor& actor){
    if(actor.model->nodes().size()>2){const auto p=actor.model->world_translation(2);actor.collision.joint_two_position=gameplay_collision::Vec3{p.x,p.y,p.z};}
    else actor.collision.joint_two_position.reset();
}
float base_height(const Actor& actor,const ModelCorrectionScales& scales){
    if(actor.category==0||actor.category==1){
        if(actor.character>=8)throw std::out_of_range("Native ground character height profile unavailable");
        const float start=actor.class_marker==3?3.f:13.f;
        const float reference=actor.model_variant?scales.variant(actor.model_variant):scales.character(actor.character);
        return finite(start+finite(actor.model_height_correction*finite(actor.model_scale.y/reference)));
    }
    return finite(10.f+actor.model_height_correction);
}
}
void initialize_model_constraints(World& world,Actor& actor){
    if(world.paused!=0)return;
    if(!actor.model)throw std::runtime_error("Required canonical model for constraint creation unavailable");
    if(!actor.constraints)actor.constraints=std::make_shared<animation::Constraints>(actor.model);
    else if(actor.constraints->model()!=actor.model)actor.constraints=actor.constraints->replacement(actor.model);
    actor.constraints->initialize_mirrored(world.paused,{actor.model_scale.x,actor.model_scale.y,actor.model_scale.z});
}
ModelConstraintReport rebuild_model_constraints(World& world,Actor& actor,ModelPoseKind kind,const ModelCorrectionScales& scales,const gameplay_collision::response::Grid* floors){
    if(!actor.active)return {};
    if(!actor.model)throw std::runtime_error("Required canonical native model unavailable");
    actor.collision.basis.translation={actor.position.x,actor.position.y,actor.position.z};
    actor.model->root_scale({actor.model_scale.x,actor.model_scale.y,actor.model_scale.z});
    correct_model_height(world,actor,scales);
    return rebuild_model_after_prelude(world,actor,kind,scales,floors);
}
ModelConstraintReport rebuild_model_after_prelude(World& world,Actor& actor,ModelPoseKind kind,const ModelCorrectionScales& scales,const gameplay_collision::response::Grid* floors){
    ModelConstraintReport report;report.visited=true;
    if(!actor.model)throw std::runtime_error("Required canonical native model unavailable");
    const auto parent=matrix(actor.collision.basis);
    if(kind==ModelPoseKind::linked_actor||(actor.contact_flags&0x12)||world.paused!=0){actor.model->rebuild(parent);joint_two(actor);return report;}
    if(!actor.constraints||actor.constraints->model()!=actor.model)throw std::runtime_error("Native model constraint owner missing, foreign or stale");
    report.contexts_consulted=true;auto& constraints=*actor.constraints;
    try{
        if(!constraints.any_enabled()){actor.model->rebuild(parent);joint_two(actor);return report;}
        report.base_height=base_height(actor,scales);
        actor.model->rebuild(parent);
        if(!(constraints.contexts()[0].enabled||constraints.contexts()[1].enabled)){joint_two(actor);return report;}
        const auto& poses=actor.model->nodes();
        if(poses.size()<=9)throw std::invalid_argument("Native two-target model joint profile unavailable");
        constraints.target(0,translation(poses[9].world));constraints.reference(0,offset(poses[7].world,false));
        constraints.target(1,translation(poses[6].world));constraints.reference(1,offset(poses[4].world,true));
        if(!floors)throw std::runtime_error("Required native model floor Grid unavailable");
        if(actor.surface_kind==1&&actor.category>2)throw std::domain_error("Original model floor mask inherits an unassigned register for this category");
        for(unsigned i=0;i<2;++i){const auto target=constraints.contexts()[i].target;const float height=floors->floor({target.x,actor.position.y,target.z},255).height;++report.floor_queries;const float base=actor.surface_kind==1?finite(*report.base_height+0.f):*report.base_height;constraints.floor_height(i,finite(height+base));}
        // Both complete floor observations precede either endpoint update.
        for(unsigned i=0;i<2;++i){auto target=constraints.contexts()[i].target;if(target.y<constraints.floor_heights()[i]){target.y=constraints.floor_heights()[i];constraints.target(i,target);report.raised_mask|=1u<<i;}}
        if(report.raised_mask)constraints.rebuild(parent);
        joint_two(actor);return report;
    }catch(...){constraints.invalidate_pose();throw;}
}
} // namespace reo::native::gameplay_world
