#pragma once
// Test-only surroundings for byte-verified generated original bodies. These
// types/macros are never included by native gameplay collision production code.
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include "third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h"
struct Lane { std::uint64_t lo{},hi{}; };
struct R5900Context { Lane g[32]; float f[32]{}; std::uint64_t lo{},hi{},lo1{},hi1{}; std::uint32_t pc{},branch_pc{},fcr31{}; bool in_delay_slot{}; };
class PS2Runtime {
public:
    using Fn=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*);
    bool hasFunction(std::uint32_t)const { return false; }
    bool shouldPreemptGuestExecution()const { return false; }
    Fn lookupFunction(std::uint32_t)const;
};
template<class T>T ref_read(const std::uint8_t* p,std::uint32_t at){T v;std::memcpy(&v,p+at,sizeof v);return v;}
template<class T>void ref_write(std::uint8_t* p,std::uint32_t at,T v){std::memcpy(p+at,&v,sizeof v);}
#define GPR_U32(c,n) (std::uint32_t((c)->g[n].lo))
#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))
#define GPR_U64(c,n) ((c)->g[n].lo)
#define GPR_S64(c,n) (std::bit_cast<std::int64_t>((c)->g[n].lo))
#define GPR_VEC(c,n) ((c)->g[n])
#define SET_GPR_U32(c,n,v) ((c)->g[n].lo=std::uint32_t(v))
#define SET_GPR_S32(c,n,v) ((c)->g[n].lo=std::uint64_t(std::int64_t(std::int32_t(v))))
#define SET_GPR_U64(c,n,v) ((c)->g[n].lo=std::uint64_t(v))
#define SET_GPR_S64(c,n,v) ((c)->g[n].lo=std::uint64_t(v))
#define SET_GPR_VEC(c,n,v) ((c)->g[n]=(v))
#define ADD32(a,b) (std::uint32_t(a)+std::uint32_t(b))
#define SUB32(a,b) (std::uint32_t(a)-std::uint32_t(b))
#define SLL32(a,b) (std::uint32_t(a)<<(b))
#define READ32(at) ref_read<std::uint32_t>(rdram,at)
#define READ16(at) ref_read<std::uint16_t>(rdram,at)
#define READ8(at) ref_read<std::uint8_t>(rdram,at)
#define READ64(at) ref_read<std::uint64_t>(rdram,at)
#define READ128(at) ref_read<Lane>(rdram,at)
#define WRITE32(at,v) ref_write(rdram,at,std::uint32_t(v))
#define WRITE8(at,v) ref_write(rdram,at,std::uint8_t(v))
#define WRITE64(at,v) ref_write(rdram,at,std::uint64_t(v))
#define WRITE128(at,v) ref_write(rdram,at,v)
#define FPU_CVT_W_S(a) Ps2FpuConvertWord(a)
#define FPU_CVT_S_W(a) (float(a))
#define FPU_C_OLE_S(a,b) ((a)<=(b))
#define FPU_C_OLT_S(a,b) ((a)<(b))
#define FPU_ADD_S(a,b) ((a)+(b))
#define FPU_SUB_S(a,b) ((a)-(b))
#define FPU_MUL_S(a,b) ((a)*(b))
#define FPU_MOV_S(a) (a)
#define FPU_NEG_S(a) (-(a))
void o0_00370760_0x370760(std::uint8_t*,R5900Context*,PS2Runtime*);
void o0_003707A0_0x3707a0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o0_00370960_0x370960(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_005DC9B0_0x5dc9b0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_005DC570_0x5dc570(std::uint8_t*,R5900Context*,PS2Runtime*);
void o0_00370DD0_0x370dd0(std::uint8_t*,R5900Context*,PS2Runtime*);
void o0_00371200_0x371200(std::uint8_t*,R5900Context*,PS2Runtime*);
// Declared numeric subtract and scenario dispatch/admission ports only.
inline void o0_00370490_0x370490(std::uint8_t* memory,R5900Context* c,PS2Runtime*) {
    const auto out=GPR_U32(c,4),a=GPR_U32(c,5),b=GPR_U32(c,6);
    for(unsigned i=0;i<2;++i){ref_write(memory,out+4*i,ref_read<float>(memory,a+4*i)-ref_read<float>(memory,b+4*i));}
    c->pc=GPR_U32(c,31);
}
inline void o2_005C1710_0x5c1710(std::uint8_t* memory,R5900Context* c,PS2Runtime*){ref_write(memory,64,GPR_U32(c,4));c->pc=GPR_U32(c,31);}
inline void o2_005C2B00_0x5c2b00(std::uint8_t* memory,R5900Context* c,PS2Runtime*){c->g[2].lo=memory[68];c->pc=GPR_U32(c,31);}
inline void o2_005C59F0_0x5c59f0(std::uint8_t* memory,R5900Context* c,PS2Runtime*){c->g[2].lo=memory[69];c->pc=GPR_U32(c,31);}
inline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t address)const {
    if(address==0x370960)return o0_00370960_0x370960;
    if(address==0x370dd0)return o0_00370DD0_0x370dd0;
    if(address==0x371200)return o0_00371200_0x371200;
    if(address==0x370490)return o0_00370490_0x370490;
    if(address==0x5c1710)return o2_005C1710_0x5c1710;
    if(address==0x5c2b00)return o2_005C2B00_0x5c2b00;
    if(address==0x5c59f0)return o2_005C59F0_0x5c59f0;
    throw std::runtime_error("Undeclared original support call");
}
