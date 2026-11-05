#pragma once
#include <array>
#include <cstdint>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#define PS2_RUNTIME_HAS_EXTERNAL_WORKERS 1
constexpr std::uint32_t PS2_RAM_SIZE=32u*1024u*1024u;
struct R5900Context {
    struct Register {std::uint64_t low{},high{};friend bool operator==(const Register&,const Register&)=default;};
    std::array<Register,32> r{};
    std::array<std::uint64_t,24> unrelated{};
    std::uint32_t pc{},branch_pc{};bool in_delay_slot{};
    friend bool operator==(const R5900Context&,const R5900Context&)=default;
};
class PS2Runtime {
public:
    using RecompiledFunction=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*);
    class ExternalWorker {public:virtual ~ExternalWorker()=default;virtual void requestStop()noexcept=0;virtual bool join()noexcept=0;};
    struct Memory {std::vector<std::uint8_t> bytes=std::vector<std::uint8_t>(PS2_RAM_SIZE,0xA5);std::uint8_t* getRDRAM(){return bytes.data();}};
    class GuestExecutionScope {
        PS2Runtime* p_;std::unique_lock<std::recursive_mutex> lock_;
    public:
        explicit GuestExecutionScope(PS2Runtime* p):p_(p),lock_(p->mutex_){++p_->depth;}
        ~GuestExecutionScope(){--p_->depth;}
    };
    ~PS2Runtime(){requestStop();for(auto& w:workers)if(!w->join())std::terminate();}
    bool hasFunction(std::uint32_t pc)const{return functions.contains(pc);}
    static void missing(std::uint8_t*,R5900Context*,PS2Runtime*){}
    RecompiledFunction lookupFunction(std::uint32_t pc)const{auto i=functions.find(pc);return i==functions.end()?missing:i->second;}
    void registerFunction(std::uint32_t pc,RecompiledFunction f){functions[pc]=f;if(throw_after_publish)throw std::runtime_error("publish failure");}
    bool registerExternalWorker(std::shared_ptr<ExternalWorker> w){if(started||stopping)return false;workers.push_back(std::move(w));return true;}
    void requestStop(){stopping=true;for(auto& w:workers)w->requestStop();}
    bool isStopRequested()const{return stopping;}
    Memory& memory(){return memory_;}
    std::unordered_map<std::uint32_t,RecompiledFunction> functions;
    std::vector<std::shared_ptr<ExternalWorker>> workers;
    unsigned depth{};bool started{},stopping{},throw_after_publish{};
private:Memory memory_;std::recursive_mutex mutex_;
};
