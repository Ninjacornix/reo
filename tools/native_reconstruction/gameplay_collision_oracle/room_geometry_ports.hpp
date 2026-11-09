#pragma once
#include "game/native/gameplay_collision/room_geometry.hpp"
// Scalar Y-only matrix and previously-qualified native trace surroundings.
namespace geometry_fixture {
namespace collision=reo::native::gameplay_collision;
inline const collision::response::Grid* walls;
inline collision::response::Filter filter;
inline unsigned rays{};
}
inline void geometry_yaw(std::uint8_t* m,R5900Context* c,PS2Runtime*){if(c->f[12]!=0||c->f[14]!=0)throw std::runtime_error("Only source Y rotation admitted");const auto sine=std::sin(c->f[13]),cosine=std::cos(c->f[13]);ref_write(m,GPR_U32(c,4),std::array<float,16>{cosine,0,-sine,0,0,1,0,0,sine,0,cosine,0,0,0,0,1});c->pc=GPR_U32(c,31);}
inline void geometry_transform(std::uint8_t* m,R5900Context* c,PS2Runtime*){const auto value=ref_read<std::array<float,3>>(m,GPR_U32(c,4));const auto matrix=ref_read<std::array<float,16>>(m,GPR_U32(c,5));std::array<float,3> out;for(unsigned i=0;i<3;++i)out[i]=(matrix[i]*value[0]+matrix[4+i]*value[1])+matrix[8+i]*value[2];ref_write(m,GPR_U32(c,4),out);c->pc=GPR_U32(c,31);}
inline void o2_00579980_0x579980(std::uint8_t* m,R5900Context* c,PS2Runtime*){using namespace geometry_fixture;const auto count=ref_read<std::uint32_t>(m,0x743ea0);if(count>31)throw std::runtime_error("Original dynamic count outside admitted fixture");std::array<collision::response::Triangle,31> existing;for(unsigned i=0;i<count;++i)existing[i]=ref_read<collision::response::Triangle>(m,0x7437a0+56*i);auto applied=filter;applied.include=GPR_U32(c,6);applied.exclude=GPR_U32(c,7);const auto result=collision::trace::any(*walls,ref_read<collision::Vec3>(m,GPR_U32(c,4)),ref_read<collision::Vec3>(m,GPR_U32(c,5)),applied,std::span(existing).first(count));c->g[2].lo=bool(result.hit);ref_write(m,GPR_U32(c,8),result.hit?result.hit->type:255u);++rays;c->pc=GPR_U32(c,31);}

inline void geometry_scale(std::uint8_t* m,R5900Context* c,PS2Runtime*){auto value=ref_read<std::array<float,3>>(m,GPR_U32(c,5));for(auto& x:value)x*=c->f[12];ref_write(m,GPR_U32(c,4),value);c->pc=GPR_U32(c,31);}
