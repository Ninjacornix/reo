#pragma once
#include <cstdint>
#include <cstring>
#include <stdexcept>
struct FixtureVec { std::uint64_t words[2]{}; };
struct R5900Context { FixtureVec gpr[32];std::uint32_t pc{},branch_pc{};bool in_delay_slot{};std::uint64_t lo{},hi{}; };
struct PS2Runtime {
    using Function=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*);
    bool hasFunction(std::uint32_t)const{return false;}
    Function lookupFunction(std::uint32_t)const{throw std::runtime_error("Unexpected original dynamic dispatch");}
    bool shouldPreemptGuestExecution()const{return false;}
};
template<class T>T fixture_read(const std::uint8_t* ram,std::uint32_t at){
    if(at>0x400000-sizeof(T))throw std::runtime_error("Original fixture read bound");
    T result;std::memcpy(&result,ram+at,sizeof(T));return result;
}
template<class T>void fixture_write(std::uint8_t* ram,std::uint32_t at,T value){
    if(at>0x400000-sizeof(T))throw std::runtime_error("Original fixture write bound");
    std::memcpy(ram+at,&value,sizeof(T));
}
#define GPR_U64(c,n) ((c)->gpr[n].words[0])
#define GPR_U32(c,n) (std::uint32_t(GPR_U64(c,n)))
#define GPR_S64(c,n) (std::int64_t(GPR_U64(c,n)))
#define GPR_S32(c,n) (std::int32_t(GPR_U32(c,n)))
#define GPR_VEC(c,n) ((c)->gpr[n])
#define SET_GPR_U64(c,n,v) (GPR_U64(c,n)=std::uint64_t(v))
#define SET_GPR_S64(c,n,v) SET_GPR_U64(c,n,std::int64_t(v))
#define SET_GPR_U32(c,n,v) SET_GPR_U64(c,n,std::uint32_t(v))
#define SET_GPR_S32(c,n,v) SET_GPR_S64(c,n,std::int32_t(v))
#define SET_GPR_VEC(c,n,v) ((c)->gpr[n]=(v))
#define ADD32(a,b) (std::uint32_t(std::uint32_t(a)+std::uint32_t(b)))
#define SLL32(a,b) (std::uint32_t(std::uint32_t(a)<<(std::uint32_t(b)&31)))
#define READ8(a) fixture_read<std::uint8_t>(rdram,a)
#define READ16(a) fixture_read<std::uint16_t>(rdram,a)
#define READ32(a) fixture_read<std::uint32_t>(rdram,a)
#define READ64(a) fixture_read<std::uint64_t>(rdram,a)
#define READ128(a) fixture_read<FixtureVec>(rdram,a)
#define WRITE8(a,v) fixture_write<std::uint8_t>(rdram,a,v)
#define WRITE16(a,v) fixture_write<std::uint16_t>(rdram,a,v)
#define WRITE64(a,v) fixture_write<std::uint64_t>(rdram,a,v)
#define WRITE128(a,v) fixture_write<FixtureVec>(rdram,a,v)
