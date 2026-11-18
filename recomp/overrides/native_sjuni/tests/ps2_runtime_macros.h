#pragma once
#include <array>
#include <bit>
#include <cstdint>
#include <unordered_map>
#include <vector>
#include <new>
#include <stdexcept>
constexpr std::uint32_t PS2_RAM_SIZE = 32u * 1024u * 1024u;
struct R5900Context {
    std::array<std::uint64_t, 32> gpr{};
    std::uint32_t pc{};
    std::uint32_t branch_pc{};
    bool in_delay_slot{};
};
struct MockMemory {
    std::vector<std::uint8_t> bytes = std::vector<std::uint8_t>(PS2_RAM_SIZE);
    std::uint8_t* getRDRAM() {
        return bytes.data();
    }
};
class PS2Runtime {
  public:
    using RecompiledFunction = void (*)(std::uint8_t*, R5900Context*, PS2Runtime*);
    MockMemory mem;
    std::unordered_map<std::uint32_t, RecompiledFunction> functions;
    unsigned depth = 0;
    unsigned registrations_before_throw = ~0u;
    class GuestExecutionScope {
        PS2Runtime* p;

      public:
        explicit GuestExecutionScope(PS2Runtime* r) noexcept : p(r) {
            ++p->depth;
        }
        ~GuestExecutionScope() {
            --p->depth;
        }
    };
    MockMemory& memory() {
        return mem;
    }
    RecompiledFunction lookupFunction(std::uint32_t a) {
        auto i = functions.find(a);
        return i == functions.end() ? missing : i->second;
    }
    // The real runtime returns a non-NULL default function when absent. A
    // lookup pointer alone is NOT proof of an installed original binding.
    static void missing(std::uint8_t*, R5900Context*, PS2Runtime*) {
        throw std::logic_error("missing guest function dispatched");
    }
    bool hasFunction(std::uint32_t a) {
        return functions.find(a) != functions.end();
    }
    void registerFunction(std::uint32_t a, RecompiledFunction f) {
        if (registrations_before_throw == 0)
            throw std::bad_alloc();
        --registrations_before_throw;
        functions[a] = f;
    }
};
#define GPR_U32(c, r) (static_cast<std::uint32_t>((c)->gpr[r]))
#define GPR_U64(c, r) ((c)->gpr[r])
#define SET_GPR_U64(c, r, v)                                                                       \
    do {                                                                                           \
        (c)->gpr[r] = static_cast<std::uint64_t>(v);                                               \
    } while (0)
#define SET_GPR_S32(c, r, v)                                                                       \
    do {                                                                                           \
        (c)->gpr[r] = static_cast<std::uint64_t>(static_cast<std::int64_t>(v));                    \
    } while (0)
