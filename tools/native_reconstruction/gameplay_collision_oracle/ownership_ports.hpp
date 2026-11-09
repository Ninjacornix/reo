#pragma once
// Declared scalar matrix/vector and qualified sweep ports around unchanged
// allocation/derived-region/caller bodies. No VU execution equivalence claim.
#include "game/native/gameplay_collision/ownership.hpp"
namespace ownership_fixture {
namespace c=reo::native::gameplay_collision;
inline c::sweep::Result result;
inline c::Vec3 previous,current;
inline float radius;
inline std::uint32_t include,exclude,gate;
}
inline void port_memset(std::uint8_t* m,R5900Context* c,PS2Runtime*){std::memset(m+GPR_U32(c,4),int(GPR_U32(c,5)&255),GPR_U32(c,6));c->g[2].lo=GPR_U32(c,4);c->pc=GPR_U32(c,31);}
inline void port_memcpy(std::uint8_t* m,R5900Context* c,PS2Runtime*){std::memcpy(m+GPR_U32(c,4),m+GPR_U32(c,5),GPR_U32(c,6));c->g[2].lo=GPR_U32(c,4);c->pc=GPR_U32(c,31);}
inline void port_matrix_copy(std::uint8_t* m,R5900Context* c,PS2Runtime*){std::memcpy(m+GPR_U32(c,4),m+GPR_U32(c,5)+48,12);c->pc=GPR_U32(c,31);}
inline void port_vector(std::uint8_t* m,R5900Context* c,PS2Runtime*){const auto at=GPR_U32(c,4),a=GPR_U32(c,5),b=GPR_U32(c,6);const auto x=ref_read<std::array<float,3>>(m,a),y=ref_read<std::array<float,3>>(m,b);for(unsigned i=0;i<3;++i)ref_write(m,at+4*i,c->pc==0x370570?x[i]-y[i]:x[i]+y[i]);c->pc=GPR_U32(c,31);}
inline void port_transform(std::uint8_t* m,R5900Context* c,PS2Runtime*){const auto p=ref_read<std::array<float,3>>(m,GPR_U32(c,5));const auto matrix=ref_read<std::array<float,16>>(m,GPR_U32(c,6));for(unsigned i=0;i<3;++i)ref_write(m,GPR_U32(c,4)+4*i,(matrix[i]*p[0]+matrix[4+i]*p[1])+matrix[8+i]*p[2]);c->pc=GPR_U32(c,31);}
inline void port_inverse(std::uint8_t* m,R5900Context* c,PS2Runtime*){const auto matrix=ref_read<std::array<float,16>>(m,GPR_U32(c,5));std::array<float,16> inverse{};inverse[15]=1;for(unsigned i=0;i<3;++i){const auto base=4*i;const auto reciprocal=1/std::sqrt((matrix[base]*matrix[base]+matrix[base+1]*matrix[base+1])+matrix[base+2]*matrix[base+2]);for(unsigned j=0;j<3;++j)inverse[4*j+i]=(matrix[base+j]*reciprocal)*reciprocal;}ref_write(m,GPR_U32(c,4),inverse);c->pc=GPR_U32(c,31);}
inline void port_abs(std::uint8_t*,R5900Context* c,PS2Runtime*){c->f[0]=std::abs(c->f[12]);c->pc=GPR_U32(c,31);}
inline void o2_006177C0_0x6177c0(std::uint8_t* m,R5900Context* c,PS2Runtime*){
    using namespace ownership_fixture;previous=ref_read<ownership_fixture::c::Vec3>(m,GPR_U32(c,4));current=ref_read<ownership_fixture::c::Vec3>(m,GPR_U32(c,5));radius=c->f[12];include=GPR_U32(c,9);exclude=GPR_U32(c,10);gate=GPR_U32(c,11);
    c->g[2].lo=result.resolution.contact_count;
    if(result.resolution.contact_count){ref_write(m,GPR_U32(c,7),result.resolution.correction);if(result.reported_point)ref_write(m,GPR_U32(c,6),*result.reported_point);if(result.reported_normal)ref_write(m,GPR_U32(c,8),*result.reported_normal);}
    c->pc=GPR_U32(c,31);
}
