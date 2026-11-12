#include "projectile_trail.hpp"
namespace reo::native::gameplay_effects {
ProjectileTrailStep advance_projectile_trail(ProjectileTrailState& state,const ProjectileTrailMotion& motion,std::uint8_t variant,ProjectileTrailEmission& emissions){
    if(state.phase!=0&&state.phase!=1)return{true,true};
    if(state.phase==0){state.phase=1;state.visible=true;}
    if(!motion.active||motion.kind!=15){state.phase=2;state.visible=false;return{};}
    state.basis=motion.basis;state.basis[3][0]=motion.position.x;state.basis[3][1]=motion.position.y;state.basis[3][2]=motion.position.z;
    WorkRequest request;request.position=motion.position;request.variant=variant;request.effect=0x10;request.child_mask=UINT32_MAX;request.flags=0x1a193;
    return{emissions.emit(request)!=WorkStatus::unavailable,false};
}
}
