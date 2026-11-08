#pragma once
#include <array>
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#define PS2_RUNTIME_HAS_EXTERNAL_WORKERS 1
// Declared registry/guest/runtime ports, not an actual runtime acquisition proof.
struct R5900Context {std::array<std::array<std::uint64_t,2>,32> r{};std::uint32_t pc{},branch_pc{};bool in_delay_slot{};std::uint64_t hi{},lo{};};
class PS2Runtime {
public:
    using RecompiledFunction=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*);
    class ExternalWorker {public:virtual ~ExternalWorker()=default;virtual void requestStop()noexcept=0;virtual bool join()noexcept=0;};
    struct Memory {std::uint8_t* ram{};std::uint8_t* getRDRAM()noexcept{return ram;}} storage;
    struct Setup {bool admitted;explicit operator bool()const noexcept{return admitted;}};
    bool phase_open{true},worker_allowed{true},stopped{};unsigned changes{},fail_change{};
    std::vector<std::shared_ptr<ExternalWorker>> workers;
    std::unordered_map<std::uint32_t,RecompiledFunction> functions;
    Setup acquirePreRunSetup()noexcept{return{phase_open && !stopped};}
    Memory& memory()noexcept{return storage;}
    bool hasFunction(std::uint32_t at)const{return functions.contains(at);}
    RecompiledFunction lookupFunction(std::uint32_t at)const{return functions.at(at);}
    void registerFunction(std::uint32_t at,RecompiledFunction fn){if(++changes==fail_change)throw std::runtime_error("declared registry publication fault");functions[at]=fn;}
    bool registerExternalWorker(std::shared_ptr<ExternalWorker> worker)noexcept{if(!worker_allowed)return false;workers.push_back(std::move(worker));return true;}
    void requestStop()noexcept{stopped=true;phase_open=false;for(const auto& worker:workers)worker->requestStop();}
    bool join(){for(const auto& worker:workers)if(!worker->join())return false;return true;}
};
