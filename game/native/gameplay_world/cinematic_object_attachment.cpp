#include "cinematic_object_attachment.hpp"
#include "../animation/constraint_math.hpp"
#include <bit>
#include <cmath>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
float finite(float value){if(!std::isfinite(value))throw std::domain_error("Native cinematic attachment finite pose required");return value;}
}
CinematicObjectAttachment CinematicObjectAttachment::read(std::span<const std::byte> bytes){
    if(bytes.size()!=36)throw std::invalid_argument("Native cinematic attachment requires one36-byte command");
    CinematicObjectAttachment result;std::memcpy(&result.offset,bytes.data()+12,12);std::memcpy(result.rotation.data(),bytes.data()+24,6);return result;
}
void attach_cinematic_object(CinematicObject& output,const animation::Instance& parent,std::uint32_t node,
                             animation::Vector scale,const CinematicObjectAttachment& request){
    if(node>=parent.nodes().size())throw std::out_of_range("Native cinematic attachment node unavailable");
    output.basis=parent.nodes()[node].world;
    output.position={output.basis[3][0],output.basis[3][1],output.basis[3][2]};
    for(unsigned axis=0;axis<3;++axis){
        const auto unit=animation::constraint_math::normalize({output.basis[axis][0],output.basis[axis][1],output.basis[axis][2]});
        output.basis[axis][0]=unit.x;output.basis[axis][1]=unit.y;output.basis[axis][2]=unit.z;
    }
    const animation::Vector scaled{finite(request.offset.x*scale.x),finite(request.offset.y*scale.y),finite(request.offset.z*scale.z)};
    const auto delta=transform_math::direction(output.basis,scaled);
    output.position={finite(output.position.x+delta.x),finite(output.position.y+delta.y),finite(output.position.z+delta.z)};
    const auto radians=[](std::uint16_t turn){const auto product=finite(std::bit_cast<float>(0x40c90fdbu)*float(turn));return finite(product/65536.f);};
    auto rotation=transform_math::identity();transform_math::compose_euler_radians(rotation,{radians(request.rotation[0]),radians(request.rotation[1]),radians(request.rotation[2])});
    const auto normalized=output.basis;
    for(unsigned axis=0;axis<3;++axis){
        const auto rotated=transform_math::direction(normalized,{rotation[axis][0],rotation[axis][1],rotation[axis][2]});
        output.basis[axis][0]=rotated.x;output.basis[axis][1]=rotated.y;output.basis[axis][2]=rotated.z;
    }
}
}
