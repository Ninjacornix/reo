#pragma once
#include <array>
#include <atomic>
#include <cstdint>
#include <cstring>
#include <functional>
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#define PS2_RUNTIME_HAS_EXTERNAL_WORKERS 1
struct FixtureVec {std::uint64_t words[2]{};};
struct R5900Context {FixtureVec gpr[32]{};std::uint32_t pc{},branch_pc{};bool in_delay_slot{};std::uint64_t lo{},hi{};};
class PS2Runtime {
public:
 using RecompiledFunction=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*);
 class ExternalWorker {public:virtual ~ExternalWorker()=default;virtual void requestStop()noexcept=0;virtual bool join()noexcept=0;};
 struct Memory {std::uint8_t* ram{};std::uint8_t* getRDRAM()noexcept{return ram;}} storage;
 struct Setup {bool admitted;explicit operator bool()const noexcept{return admitted;}};
 bool phase_open{true},worker_allowed{true},stopped{},provider_mutation{},bad_return{},provider_throw{},reenter{};
 std::atomic<std::uint32_t> depth{1};unsigned changes{},fail_change{},provider_count{};std::uint32_t active_container{};
 std::vector<std::shared_ptr<ExternalWorker>> workers;std::vector<std::uint32_t> events;
 std::unordered_map<std::uint32_t,RecompiledFunction> functions;
 Setup acquirePreRunSetup()noexcept{return{phase_open&&!stopped};}
 Memory& memory()noexcept{return storage;}
 bool hasFunction(std::uint32_t at)const{return functions.contains(at);}
 RecompiledFunction lookupFunction(std::uint32_t at)const{return functions.at(at);}
 void registerFunction(std::uint32_t at,RecompiledFunction f){if(++changes==fail_change)throw std::runtime_error("fixture publication fault");functions[at]=f;}
 bool registerExternalWorker(std::shared_ptr<ExternalWorker> w)noexcept{if(!worker_allowed)return false;workers.push_back(std::move(w));return true;}
 void requestStop()noexcept{stopped=true;phase_open=false;for(const auto& w:workers)w->requestStop();}
 bool shouldPreemptGuestExecution()const noexcept{return false;}
 bool join(){for(const auto& w:workers)if(!w->join())return false;return true;}
};
inline void(*fixture_before_write)(const void*,std::uint32_t,std::size_t){};
template<class T>T fixture_read(const std::uint8_t* ram,std::uint32_t at){if(at>0x2000000-sizeof(T))throw std::runtime_error("Original read bound");T v;std::memcpy(&v,ram+at,sizeof(v));return v;}
template<class T>void fixture_write(std::uint8_t* ram,std::uint32_t at,T v){if(at>0x2000000-sizeof(T))throw std::runtime_error("Original write bound");if(fixture_before_write)fixture_before_write(ram,at,sizeof(v));std::memcpy(ram+at,&v,sizeof(v));}
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
