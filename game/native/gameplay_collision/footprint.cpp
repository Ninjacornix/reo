#include "footprint.hpp"
#include <bit>
#include <cmath>
#include <limits>
namespace reo::native::gameplay_collision::footprint {
namespace {
float length(Vec3 p){return std::sqrt((p.x*p.x+p.y*p.y)+p.z*p.z);}
std::int32_t signed_cell(std::int32_t v){return std::bit_cast<std::int8_t>(std::uint8_t(v));}
std::optional<std::int32_t> integer(float value){const auto x=std::trunc(double(value));if(!std::isfinite(x)||x<-2147483648.0||x>2147483647.0)return{};return std::int32_t(x);}
bool unknown(room_objects::Classification value){return value==room_objects::Classification::unknown_height||value==room_objects::Classification::missing_floor;}
}
Result constrain(const room_objects::Owner& owner,Vec3 proposed,Vec3 previous,bool enabled,bool height_layers,const response::Grid* floors){
    Result result{proposed};const auto* grid=owner.grid();if(!enabled||!grid)return result;
    bool elevated{};float radius=49.5f;if(height_layers&&previous.y-grid->origin.y>50&&owner.cell_at(previous).inside){elevated=true;radius=20;}
    Vec3 direction{proposed.x-previous.x,0,proposed.z-previous.z};const auto distance=length(direction);if(distance==0)return result;
    const auto reciprocal=1/distance;direction.x*=reciprocal;direction.z*=reciprocal;
    const auto initial=owner.classify({previous.x+direction.x*radius,previous.y,previous.z+direction.z*radius},height_layers,floors);
    if(unknown(initial.status)){result.position=previous;result.status=Status::missing_classification;return result;}
    if(unsigned(initial.status)>=2){
        const auto id=owner.at_cell(signed_cell(initial.cell.x),signed_cell(initial.cell.z));if(!id)return result;const auto* object=owner.get(*id);const auto expanded=radius+1;
        const std::array<float,4> candidates{(grid->origin.z+float(object->z)*50)-expanded,(expanded+grid->origin.z)+float(std::int32_t(object->z)+object->depth)*50,(grid->origin.x+float(object->x)*50)-expanded,(expanded+grid->origin.x)+float(std::int32_t(object->x)+object->width)*50};
        float best=10000;std::optional<unsigned> selected;for(unsigned i=0;i<4;++i){const auto d=std::abs(candidates[i]-(i<2?previous.z:previous.x));if(d<best){best=d;selected=i;}}
        if(!selected){result.position=previous;result.status=Status::invalid_geometry;return result;}if(*selected<2)result.position.z=candidates[*selected];else result.position.x=candidates[*selected];return result;
    }
    if(!elevated)return result;
    if(proposed.x+radius<grid->origin.x||grid->origin.x+float(grid->width)*50<=proposed.x-radius||proposed.z+radius<grid->origin.z||grid->origin.z+float(grid->depth)*50<=proposed.z-radius){const auto classification=owner.classify(proposed,height_layers,floors);if(unknown(classification.status)){result.position=previous;result.status=Status::missing_classification;}else if(classification.status==room_objects::Classification::incompatible)result.position=previous;return result;}
    auto current=previous;const auto signed_x=direction.x>0?radius:direction.x<0?-radius:0,signed_z=direction.z>0?radius:direction.z<0?-radius:0;
    std::optional<room_objects::ObjectId> excluded;const auto previous_cell=owner.cell_at(previous);if(previous.y-grid->origin.y>=50&&previous_cell.inside)excluded=owner.at_cell(signed_cell(previous_cell.x),signed_cell(previous_cell.z));
    bool missing{};const auto blocked=[&](Vec3 p){const auto value=owner.refine(p,height_layers,excluded,floors).status;if(unknown(value)){missing=true;return true;}return unsigned(value)>=2;};
    for(unsigned pass=0;pass<4;++pass){result.passes=std::uint8_t(pass+1);float ratio_x=1000,ratio_z=1000,boundary_x{},boundary_z{};const auto leading_x=current.x+radius,trailing_x=current.x-radius,leading_z=current.z+radius,trailing_z=current.z-radius;
        const auto boundary=[&](float leading,float origin,float delta)->std::optional<float>{auto index=integer((leading-origin)/50);if(!index)return{};if((delta>0&&origin<=leading))++*index;else if(delta<0&&leading<origin)--*index;return origin+float(*index)*50;};
        if(direction.x!=0){const auto leading=direction.x>0?leading_x:trailing_x;const auto value=boundary(leading,grid->origin.x,direction.x);if(!value){result.position=previous;result.status=Status::invalid_geometry;return result;}boundary_x=*value;ratio_x=(boundary_x-leading)/direction.x;}
        if(direction.z!=0){const auto leading=direction.z>0?leading_z:trailing_z;const auto value=boundary(leading,grid->origin.z,direction.z);if(!value){result.position=previous;result.status=Status::invalid_geometry;return result;}boundary_z=*value;ratio_z=(boundary_z-leading)/direction.z;}
        bool z_axis;if(ratio_x<0||ratio_z<0){if(ratio_x<0){ratio_x=1000;z_axis=true;}else{ratio_z=1000;z_axis=false;}}else z_axis=!(ratio_x<ratio_z);
        if(ratio_x==1000&&ratio_z==1000)break;
        Vec3 candidate{0,previous.y,boundary_z-signed_z},probe{0,previous.y,0};
        if(!z_axis){
            candidate.x=boundary_x-signed_x;candidate.z=current.z+direction.z*((candidate.x-current.x)/direction.x);
            if((direction.x>0&&proposed.x<=candidate.x)||(direction.x<0&&candidate.x<=proposed.x))return result;
            probe.x=boundary_x+direction.x;probe.z=(signed_z+candidate.z)+direction.z;bool stopped=blocked(probe);
            if(!stopped){probe.z=candidate.z+direction.z;stopped=blocked(probe);}if(!stopped){probe.z=(candidate.z+direction.z)-signed_z;stopped=blocked(probe);}if(!stopped){probe.z=(signed_z+candidate.z)+direction.z;probe.x-=signed_x;stopped=blocked(probe);}if(!stopped){probe.x-=signed_x;stopped=blocked(probe);}
            if(stopped){current.x=candidate.x-direction.x;probe.x=boundary_x-direction.x;probe.z=proposed.z+signed_z;bool fallback=blocked(probe);if(!fallback){probe.x-=signed_x;fallback=blocked(probe);}if(!fallback){probe.x-=signed_x;fallback=blocked(probe);}if(!fallback)current.z=proposed.z;else{current.z=boundary_z;if((direction.z<=0||proposed.z<=boundary_z)&&(direction.z>=0||boundary_z<=proposed.z))current.z=candidate.z;}break;}
            current=proposed;
        }else{
            candidate.x=current.x+direction.x*((candidate.z-current.z)/direction.z);
            if((direction.z>0&&proposed.z<=candidate.z)||(direction.z<0&&candidate.z<=proposed.z))return result;
            probe.z=boundary_z+direction.z;probe.x=(signed_x+candidate.x)+direction.x;bool stopped=blocked(probe);
            if(!stopped){probe.x=candidate.x+direction.x;stopped=blocked(probe);}if(!stopped){probe.x=(candidate.x+direction.x)-signed_x;stopped=blocked(probe);}if(!stopped){probe.x=(signed_x+candidate.x)+direction.x;probe.z-=signed_z;stopped=blocked(probe);}if(!stopped){probe.z-=signed_z;stopped=blocked(probe);}
            if(stopped){probe.z=boundary_z-direction.z;current.z=candidate.z-direction.z;probe.x=proposed.x+signed_x;bool fallback=blocked(probe);if(!fallback){probe.z-=signed_z;fallback=blocked(probe);}if(!fallback){probe.z-=signed_z;fallback=blocked(probe);}if(!fallback)current.x=proposed.x;else{current.x=boundary_x;if((direction.x<=0||proposed.x<=boundary_x)&&(direction.x>=0||boundary_x<=proposed.x))current.x=candidate.x;}break;}
            current=proposed;
        }
        if((direction.x>0&&current.x<=previous.x)||(direction.x<0&&previous.x<=current.x)||(direction.z>0&&current.z<=previous.z)||(direction.z<0&&previous.z<=current.z)){current=previous;break;}
    }
    result.position=missing?previous:current;if(missing)result.status=Status::missing_classification;return result;
}
}
