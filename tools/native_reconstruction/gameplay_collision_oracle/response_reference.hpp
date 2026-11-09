#pragma once
#define PS2Runtime ProxyOracleRuntime
#include "reference.hpp"
#undef PS2Runtime
// Response oracle has declared scalar vector-math and cell-lookup surroundings.
// Full original shape/floor/filter bodies below retain their own control flow.
class PS2Runtime {
public:
    using Fn=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*);
    bool hasFunction(std::uint32_t)const{return false;}
    bool shouldPreemptGuestExecution()const{return false;}
    Fn lookupFunction(std::uint32_t)const;
};
#define FPU_C_OEQ_S(a,b) ((a)==(b))
#define FPU_C_EQ_S(a,b) ((a)==(b))
#define FPU_ABS_S(a) std::abs(a)
#define FPU_DIV_S(a,b) ((a)/(b))
#define SRL32(a,b) (std::uint32_t(a)>>(b))
#define SRA32(a,b) (std::bit_cast<std::int32_t>(std::uint32_t(a))>>(b))
#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))
void o2_006F00D0_0x6f00d0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_006F0310_0x6f0310(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_006F0E00_0x6f0e00(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_006F0E60_0x6f0e60(std::uint8_t*,R5900Context*,PS2Runtime*);
void o0_00370AC0_0x370ac0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o0_00370B00_0x370b00(std::uint8_t*,R5900Context*,PS2Runtime*);
void o0_00370C70_0x370c70(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_00617000_0x617000(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_00617430_0x617430(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_006161E0_0x6161e0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_00616310_0x616310(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_00619A50_0x619a50(std::uint8_t*,R5900Context*,PS2Runtime*);
namespace response_oracle {
using Vector=std::array<float,3>;
inline Vector read(const std::uint8_t* m,std::uint32_t p){return ref_read<Vector>(m,p);}
inline void write(std::uint8_t* m,std::uint32_t p,Vector v){ref_write(m,p,v);}
inline float dot(Vector a,Vector b){return(a[0]*b[0]+a[1]*b[1])+a[2]*b[2];}
inline Vector sub(Vector a,Vector b){return{a[0]-b[0],a[1]-b[1],a[2]-b[2]};}
inline float length(Vector a){return std::sqrt(dot(a,a));}
inline Vector scale(Vector a,float f){return{a[0]*f,a[1]*f,a[2]*f};}
inline void finish(R5900Context* c){c->pc=GPR_U32(c,31);}
}
#define RESPONSE_PORT(name,body) inline void name(std::uint8_t* m,R5900Context* c,PS2Runtime*) {using namespace response_oracle;body;finish(c);}
RESPONSE_PORT(sub_00191CC0_0x191cc0,c->f[0]=length(read(m,GPR_U32(c,4))))
RESPONSE_PORT(sub_00191D10_0x191d10,c->f[0]=length(sub(read(m,GPR_U32(c,4)),read(m,GPR_U32(c,5)))))
RESPONSE_PORT(sub_00191D80_0x191d80,const auto v=read(m,GPR_U32(c,4));const auto n=length(v);write(m,GPR_U32(c,4),n==0?Vector{}:scale(v,1/n)))
RESPONSE_PORT(sub_00191DF0_0x191df0,c->f[0]=dot(read(m,GPR_U32(c,4)),read(m,GPR_U32(c,5))))
inline void sub_00191E50_0x191e50(std::uint8_t* m,R5900Context* c,PS2Runtime*){
    using namespace response_oracle;const auto a=read(m,GPR_U32(c,5)),b=read(m,GPR_U32(c,6));
    write(m,GPR_U32(c,4),{a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]});finish(c);
}
RESPONSE_PORT(sub_00191ED0_0x191ed0,write(m,GPR_U32(c,4),read(m,GPR_U32(c,5))))
RESPONSE_PORT(sub_001920A0_0x1920a0,c->f[0]=std::abs(c->f[12]))
RESPONSE_PORT(o0_00371880_0x371880,c->f[0]=std::sqrt(c->f[12]))
RESPONSE_PORT(o0_00370570_0x370570,write(m,GPR_U32(c,4),sub(read(m,GPR_U32(c,5)),read(m,GPR_U32(c,6)))))
RESPONSE_PORT(o0_003705E0_0x3705e0,write(m,GPR_U32(c,4),scale(read(m,GPR_U32(c,5)),c->f[12])))
inline void o0_00370500_0x370500(std::uint8_t* m,R5900Context* c,PS2Runtime*){
    using namespace response_oracle;const auto a=read(m,GPR_U32(c,5)),b=read(m,GPR_U32(c,6));
    write(m,GPR_U32(c,4),{a[0]+b[0],a[1]+b[1],a[2]+b[2]});finish(c);
}
RESPONSE_PORT(o2_00616720_0x616720,c->g[2].lo=m[64])
RESPONSE_PORT(o2_006172F0_0x6172f0,c->g[2].lo=ref_read<std::uint32_t>(m,68))
inline void o0_00371480_0x371480(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Matrix output outside floor oracle");}
inline void sub_0018FDF0_0x18fdf0(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Matrix output outside floor oracle");}
inline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{
    switch(at){
    case 0x191cc0:return sub_00191CC0_0x191cc0;case 0x191d10:return sub_00191D10_0x191d10;case 0x191d80:return sub_00191D80_0x191d80;
    case 0x191df0:return sub_00191DF0_0x191df0;case 0x191e50:return sub_00191E50_0x191e50;case 0x191ed0:return sub_00191ED0_0x191ed0;
    case 0x1920a0:return sub_001920A0_0x1920a0;case 0x371880:return o0_00371880_0x371880;
    case 0x370570:return o0_00370570_0x370570;case 0x3705e0:return o0_003705E0_0x3705e0;case 0x370500:return o0_00370500_0x370500;
    case 0x370ac0:return o0_00370AC0_0x370ac0;case 0x370b00:return o0_00370B00_0x370b00;case 0x370c70:return o0_00370C70_0x370c70;
    case 0x616720:return o2_00616720_0x616720;case 0x6172f0:return o2_006172F0_0x6172f0;
    case 0x371480:return o0_00371480_0x371480;case 0x18fdf0:return sub_0018FDF0_0x18fdf0;
    case 0x619a50:return o2_00619A50_0x619a50;
    default:throw std::runtime_error("Undeclared response oracle call");}
}
#undef RESPONSE_PORT
