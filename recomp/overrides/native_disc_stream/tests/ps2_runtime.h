#pragma once
#include <array>
#include <cstdint>
#include <mutex>
#include <stdexcept>
#include <unordered_map>
#include <vector>
constexpr std::uint32_t PS2_RAM_SIZE=32u*1024u*1024u;
struct R5900Context {
    struct Register {
        std::uint64_t low{},high{};
        friend bool operator==(const Register&,const Register&)=default;
    };
    std::array<Register,32> r{};
    std::array<std::uint64_t,16> preserved{};
    std::uint32_t pc{},branch_pc{};
    bool in_delay_slot{};
    friend bool operator==(const R5900Context&,const R5900Context&)=default;
};
class PS2Runtime {
public:
    using RecompiledFunction=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*);
    struct Memory {
        std::vector<std::uint8_t> bytes=std::vector<std::uint8_t>(PS2_RAM_SIZE,0xA5);
        std::uint8_t* getRDRAM(){return bytes.data();}
    };
    class GuestExecutionScope {
        PS2Runtime* runtime_;
        std::unique_lock<std::recursive_mutex> lock_;
    public:
        explicit GuestExecutionScope(PS2Runtime* p):runtime_(p),lock_(p->mutex){++p->depth;}
        ~GuestExecutionScope(){--runtime_->depth;}
    };
    Memory& memory(){return memory_;}
    bool isStopRequested()const{return stopping;}
    bool hasFunction(std::uint32_t address)const{return functions.contains(address);}
    static void missing(std::uint8_t*,R5900Context*,PS2Runtime*){}
    RecompiledFunction lookupFunction(std::uint32_t address)const {
        const auto found=functions.find(address);
        return found==functions.end()?missing:found->second;
    }
    void registerFunction(std::uint32_t address,RecompiledFunction function) {
        if(throw_registration&&++registrations==throw_registration)
            throw std::runtime_error("injected partial registration failure");
        functions[address]=function;
    }
    std::unordered_map<std::uint32_t,RecompiledFunction> functions;
    bool stopping{};
    unsigned depth{},registrations{},throw_registration{};
private:
    Memory memory_;
    std::recursive_mutex mutex;
};
