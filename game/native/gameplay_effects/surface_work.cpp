#include "surface_work.hpp"
#include <bit>
#include <cmath>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_effects {
namespace {
bool finite(transform_math::Vector v){return std::isfinite(v.x)&&std::isfinite(v.y)&&std::isfinite(v.z);}
float thousandths(std::uint32_t value){
    float converted;
    if(value&0x80000000u){const float half=static_cast<float>(std::int32_t((value>>1)|(value&1)));converted=half+half;}
    else converted=static_cast<float>(std::int32_t(value));
    return converted/1000.f;
}
}
Modulation::Modulation(ModulationState state):state_(state){
    if(!finite(state.color)||!std::isfinite(state.intensity))throw std::invalid_argument("Native effect modulation requires finite state");
}
bool Modulation::configure(std::uint32_t selector,const std::array<std::uint32_t,4>& words)noexcept{
    if(selector!=1)return false;
    state_.flags|=1;state_.color={thousandths(words[0]),thousandths(words[1]),thousandths(words[2])};state_.intensity=thousandths(words[3]);return true;
}
SurfaceProfile SurfaceProfile::import(std::span<const std::byte> bytes,std::uint8_t first,std::uint8_t second){
    static_assert(std::endian::native==std::endian::little);
    if(bytes.size()!=11*24)throw std::invalid_argument("Native surface joint table extent unavailable");
    SurfaceProfile result;result.first_mask_=first;result.second_mask_=second;
    for(std::size_t i=0;i<11;++i){auto& row=result.joints_[i];const auto* at=bytes.data()+i*24;
        std::memcpy(&row.joint,at,4);std::memcpy(&row.lower,at+4,4);std::memcpy(&row.upper,at+8,4);std::memcpy(&row.scale,at+12,12);
        if(!std::isfinite(row.lower)||!std::isfinite(row.upper)||!finite(row.scale))throw std::invalid_argument("Native surface joint table finite profile unavailable");
    }return result;
}
SurfaceGate prepare_surface(SurfaceState& state,const Modulation& modulation,const gameplay_world::Actor& actor,std::uint16_t current_room)noexcept{
    if(state.phase==0){
        if(!(modulation.state().flags&1))return SurfaceGate::retire;
        state.second.fill(1);state.phase=1;
    }
    return actor.room!=current_room||!actor.collision.pose_ready?SurfaceGate::skip:SurfaceGate::sample;
}
SurfaceStep advance_surface(SurfaceState& state,const SurfaceProfile& profile,const Modulation& modulation,
    const gameplay_world::Actor& actor,std::uint16_t current_room,const gameplay_collision::response::Grid& floors,
    gameplay_session::Random& random,SurfaceVisuals& visuals)noexcept{
    SurfaceStep result;
    if(!visuals.bound_to(random)){result.status=SurfaceStatus::unavailable;return result;}
    const auto gate=prepare_surface(state,modulation,actor,current_room);
    if(gate!=SurfaceGate::sample){result.retire=gate==SurfaceGate::retire;return result;}
    const gameplay_collision::Vec3 query{actor.position.x,actor.position.y+200.f,actor.position.z};
    if(!std::isfinite(query.x)||!std::isfinite(query.y)||!std::isfinite(query.z)){result.status=SurfaceStatus::unavailable;return result;}
    const auto floor=floors.floor(query,0x81);if(floor.type!=0x81)return result;
    const auto pose=actor.model?actor.model->retain():nullptr;
    if(!pose){result.status=SurfaceStatus::unavailable;return result;}
    const auto& settings=modulation.state();const float emission_y=3.f+floor.height;
    const auto joints=profile.joints();
    for(std::size_t i=0;i<11;++i){
        const auto& row=joints[i];
        if(row.joint>=pose->joints.size()){result.status=SurfaceStatus::unavailable;return result;}
        const auto& matrix=pose->joints[row.joint];const transform_math::Vector current{matrix[3][0],matrix[3][1],matrix[3][2]};const auto previous=state.previous[i];
        if(!finite(current)||!finite(previous)){result.status=SurfaceStatus::unavailable;return result;}
        const float lower=floor.height+row.lower,upper=floor.height+row.upper;
        if(state.first[i]>=0)--state.first[i];
        unsigned selected{};
        if(current.y>=lower&&current.y<=upper){selected=4;if(state.first[i]<0)selected|=1;}
        if(state.second[i]>=0)--state.second[i];
        if(state.second[i]<0){
            if((previous.y<=upper&&current.y>upper)||(previous.y>=upper&&current.y<upper))selected|=2;
            else if(selected&4){const float dx=current.x-previous.x,dz=current.z-previous.z;const float xx=dx*dx,zz=dz*dz;const float distance=std::sqrt(xx+zz);if(distance>=8.f)selected|=2;}
        }
        state.previous[i]=current;
        if(!(selected&3))continue;
        const auto angle=std::bit_cast<std::int16_t>(random.request(1));
        const auto emit=[&](bool first){
            SurfaceEmission emission;emission.work.position=transform_math::Vector{current.x,emission_y,current.z};
            emission.work.effect=first?0x36:0x33;emission.work.child_mask=first?profile.first_mask():profile.second_mask();
            emission.work.update=WorkUpdate::scaled;emission.scale=row.scale;emission.attributes=first?6:4;
            if(first)emission.second_angle=angle;
            emission.color=settings.color;emission.intensity=settings.intensity;
            ++result.attempted;const auto status=visuals.emit_surface(emission);
            if(status==WorkStatus::completed)++result.created;
            return status;
        };
        if(selected&1){const auto status=emit(true);if(status==WorkStatus::completed)state.first[i]=10;if(status==WorkStatus::unavailable){result.status=SurfaceStatus::unavailable;return result;}}
        if(selected&2){const auto status=emit(false);if(status==WorkStatus::completed)state.second[i]=15;if(status==WorkStatus::unavailable){result.status=SurfaceStatus::unavailable;return result;}}
    }return result;
}
}
