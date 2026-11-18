#include "contact_styles.hpp"
#include <bit>
namespace reo::native::gameplay_effects {
namespace {
bool natural(WorkStatus status){return status==WorkStatus::completed||status==WorkStatus::pool_full||status==WorkStatus::resource_missing;}
}
WorkStatus construct_contact_style(WorkBackend& work,ContactStyleContext context,
    const std::optional<transform_math::Matrix>& basis,transform_math::Vector point,std::uint32_t style){
    if(style>=9)return WorkStatus::completed;
    if(style==3||style==7){
        if(!context.channels)return WorkStatus::unavailable;
        const auto result=context.channels->create(basis,point,style==3?0u:4u,0);
        return natural(result)?WorkStatus::completed:result;
    }
    std::uint16_t resource{};
    switch(style){
    case 0:resource=0xa;break;
    case 1:resource=0xc;break;
    case 2:resource=0xb;break;
    case 4:case 6:resource=0xe;break;
    case 5:
        if(!context.discriminator)return WorkStatus::unavailable;
        resource=*context.discriminator==0?0xau:0x13u;break;
    case 8:resource=0x11;break;
    default:return WorkStatus::unavailable;
    }
    if(style==6){
        if(!basis)return WorkStatus::unavailable;
        auto extra=transform_math::identity();transform_math::reset_euler_axes(extra,{0,0x8000,0});
        //1913E0 composes axis XYZ only; translation and W stay initialized.
        for(unsigned i=0;i<3;++i){
            const auto v=transform_math::direction(*basis,{extra[i][0],extra[i][1],extra[i][2]});
            extra[i][0]=v.x;extra[i][1]=v.y;extra[i][2]=v.z;
        }
        const auto offset=transform_math::direction(*basis,{0,0,std::bit_cast<float>(0xc2d4b958u)});
        const transform_math::Vector position{offset.x+point.x,offset.y+point.y,offset.z+point.z};
        const auto result=work.create({extra,position,-1,0xe,1,0x1a193,WorkUpdate::ordinary});
        if(!natural(result.status))return result.status;
    }
    const auto result=work.create({basis,point,-1,resource,1,0x1a193,WorkUpdate::ordinary});
    return natural(result.status)?WorkStatus::completed:result.status;
}
}
