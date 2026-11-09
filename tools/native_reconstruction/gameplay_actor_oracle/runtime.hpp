#pragma once
#include <array>
#include <cstdint>
#include <cstring>
#include <stdexcept>

struct R5900Context {
    std::array<std::array<std::uint64_t,2>,32> r{};
    std::array<float,32> f{};
    std::uint32_t pc{}, branch_pc{};
    bool in_delay_slot{};
};
struct PS2Runtime {
    using Function=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*);
    Function port{};
    bool hasFunction(std::uint32_t)const noexcept{return true;}
    Function lookupFunction(std::uint32_t)const noexcept{return port;}
    bool shouldPreemptGuestExecution()const noexcept{return false;}
};
template<class T>T oracle_read(const std::uint8_t* ram,std::uint32_t address){
    if(address>0x2000000u || sizeof(T)>0x2000000u-address)throw std::runtime_error("original read outside fixture RAM");
    T value;std::memcpy(&value,ram+address,sizeof(value));return value;
}
template<class T>void oracle_write(std::uint8_t* ram,std::uint32_t address,T value){
    if(address>0x2000000u || sizeof(T)>0x2000000u-address)throw std::runtime_error("original write outside fixture RAM");
    std::memcpy(ram+address,&value,sizeof(value));
}
#define GPR_U64(c,n) ((n)==0?std::uint64_t(0):(c)->r[n][0])
#define GPR_S64(c,n) static_cast<std::int64_t>(GPR_U64(c,n))
#define GPR_U32(c,n) static_cast<std::uint32_t>(GPR_U64(c,n))
#define GPR_VEC(c,n) ((c)->r[n])
#define SET_GPR_S32(c,n,v) ((c)->r[n][0]=static_cast<std::uint64_t>(static_cast<std::int64_t>(static_cast<std::int32_t>(v))))
#define SET_GPR_U32(c,n,v) ((c)->r[n][0]=static_cast<std::uint32_t>(v))
#define SET_GPR_U64(c,n,v) ((c)->r[n][0]=static_cast<std::uint64_t>(v))
#define SET_GPR_S64(c,n,v) ((c)->r[n][0]=static_cast<std::uint64_t>(static_cast<std::int64_t>(v)))
#define SET_GPR_VEC(c,n,v) ((c)->r[n]=(v))
#define ADD32(a,b) (static_cast<std::uint32_t>(a)+static_cast<std::uint32_t>(b))
#define SUB32(a,b) (static_cast<std::uint32_t>(a)-static_cast<std::uint32_t>(b))
#define SLL32(a,b) (static_cast<std::uint32_t>(a)<<static_cast<unsigned>(b))
#define READ8(a) oracle_read<std::uint8_t>(rdram,static_cast<std::uint32_t>(a))
#define READ16(a) oracle_read<std::uint16_t>(rdram,static_cast<std::uint32_t>(a))
#define READ32(a) oracle_read<std::uint32_t>(rdram,static_cast<std::uint32_t>(a))
#define READ64(a) oracle_read<std::uint64_t>(rdram,static_cast<std::uint32_t>(a))
#define READ128(a) (oracle_read<std::array<std::uint64_t,2>>(rdram,static_cast<std::uint32_t>(a)))
#define WRITE8(a,v) oracle_write<std::uint8_t>(rdram,static_cast<std::uint32_t>(a),v)
#define WRITE16(a,v) oracle_write<std::uint16_t>(rdram,static_cast<std::uint32_t>(a),v)
#define WRITE32(a,v) oracle_write<std::uint32_t>(rdram,static_cast<std::uint32_t>(a),v)
#define WRITE64(a,v) oracle_write<std::uint64_t>(rdram,static_cast<std::uint32_t>(a),v)
#define WRITE128(a,v) (oracle_write<std::array<std::uint64_t,2>>(rdram,static_cast<std::uint32_t>(a),v))
// Corpus floats are finite, exactly representable quarter/eighth integers and
// sums. This declared port does not qualify exceptional PS2 FPU behavior.
#define FPU_ADD_S(a,b) ((a)+(b))
