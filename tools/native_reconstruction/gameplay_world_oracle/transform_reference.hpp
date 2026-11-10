#pragma once
// Test-only original-body surroundings. No part of this SIMD/register context
// is included by native transform production code. These finite scalar/SIMD
// definitions match the audited SDK131 profile, not physical PS2 exceptions.
#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <immintrin.h>
#include <stdexcept>

struct alignas(16) Register {union{__m128i vector;std::uint64_t lane[2];};Register():vector(_mm_setzero_si128()){};};
struct R5900Context {
    Register r[32];float f[32]{};std::uint64_t hi{},lo{};std::uint32_t pc{},branch_pc{},fcr31{};bool in_delay_slot{};
    __m128 vu0_vf[32],vu0_acc;float vu0_q{};std::uint16_t vi[16]{};
    R5900Context():vu0_acc(_mm_setzero_ps()){
        for(auto& v:vu0_vf){v=_mm_setzero_ps();}
        vu0_vf[0]=_mm_set_ps(1,0,0,0);
    }
};
void original_transform_port(std::uint8_t*,R5900Context*,struct PS2Runtime*);
struct PS2Runtime {
    using Function=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*);
    bool hasFunction(std::uint32_t)const noexcept{return true;}
    bool shouldPreemptGuestExecution()const noexcept{return false;}
    Function lookupFunction(std::uint32_t)const noexcept{return original_transform_port;}
    void SignalException(R5900Context*,unsigned){throw std::runtime_error("unexpected original transform exception");}
};
template<class T>T transform_read(const std::uint8_t* p,std::uint32_t at){if(at>0x2000000 || sizeof(T)>0x2000000-at)throw std::runtime_error("original transform read bound");T value;std::memcpy(&value,p+at,sizeof value);return value;}
template<class T>void transform_write(std::uint8_t* p,std::uint32_t at,T value){if(at>0x2000000 || sizeof(T)>0x2000000-at)throw std::runtime_error("original transform write bound");std::memcpy(p+at,&value,sizeof value);}
inline void transform_set32(R5900Context* c,unsigned reg,std::uint32_t value){if(reg)c->r[reg].lane[0]=std::uint64_t(std::int64_t(std::bit_cast<std::int32_t>(value)));}
#define GPR_U64(c,n) ((n)==0?std::uint64_t(0):(c)->r[n].lane[0])
#define GPR_S64(c,n) (std::bit_cast<std::int64_t>(GPR_U64(c,n)))
#define GPR_U32(c,n) (std::uint32_t(GPR_U64(c,n)))
#define GPR_VEC(c,n) ((c)->r[n].vector)
#define SET_GPR_U32(c,n,v) transform_set32(c,n,std::uint32_t(v))
#define SET_GPR_S32(c,n,v) transform_set32(c,n,std::uint32_t(v))
#define SET_GPR_U64(c,n,v) ((c)->r[n].lane[0]=std::uint64_t(v))
#define SET_GPR_S64(c,n,v) ((c)->r[n].lane[0]=std::uint64_t(v))
#define SET_GPR_VEC(c,n,v) ((c)->r[n].vector=(v))
#define ADD32(a,b) (std::uint32_t(a)+std::uint32_t(b))
#define SUB32(a,b) (std::uint32_t(a)-std::uint32_t(b))
#define SLL32(a,b) (std::uint32_t(a)<<unsigned(b))
#define SRL32(a,b) (std::uint32_t(a)>>unsigned(b))
inline void ADD32_OV(std::uint32_t a,std::int32_t b,std::uint32_t& value,bool& overflow){const auto wide=std::int64_t(std::bit_cast<std::int32_t>(a))+b;overflow=wide<INT32_MIN||wide>INT32_MAX;value=std::uint32_t(wide);}
#define EXCEPTION_INTEGER_OVERFLOW 12
#define READ8(at) transform_read<std::uint8_t>(rdram,at)
#define READ16(at) transform_read<std::uint16_t>(rdram,at)
#define READ32(at) transform_read<std::uint32_t>(rdram,at)
#define READ64(at) transform_read<std::uint64_t>(rdram,at)
#define READ128(at) transform_read<__m128i>(rdram,at)
#define WRITE8(at,v) transform_write(rdram,at,std::uint8_t(v))
#define WRITE16(at,v) transform_write(rdram,at,std::uint16_t(v))
#define WRITE32(at,v) transform_write(rdram,at,std::uint32_t(v))
#define WRITE64(at,v) transform_write(rdram,at,std::uint64_t(v))
#define WRITE128(at,v) transform_write(rdram,at,v)
#define FPU_ADD_S(a,b) ((a)+(b))
#define FPU_SUB_S(a,b) ((a)-(b))
#define FPU_MUL_S(a,b) ((a)*(b))
#define FPU_NEG_S(a) (-(a))
#define FPU_MOV_S(a) (a)
#define FPU_CVT_S_W(a) float(a)
#define FPU_C_OLE_S(a,b) ((a)<=(b))
#define FPU_C_OLT_S(a,b) ((a)<(b))
#define PS2_VMUL(a,b) _mm_mul_ps((a),(b))
#define PS2_VADD(a,b) _mm_add_ps((a),(b))
#define PS2_VSUB(a,b) _mm_sub_ps((a),(b))
#define PS2_VBLEND(a,b,m) _mm_blendv_ps((a),(b),(m))
