#pragma once

#include <cstddef>
#include <cstdint>
#include "ram_configuration.h"

class PS2Runtime;
struct R5900Context;

// Temporary File #1 adapter: native worker ownership, original disc protocol.
namespace reo_cd_async {
extern bool enabled;
void configure(const char* serial, std::uint8_t* memory, std::size_t bytes,
               PS2Runtime& runtime) noexcept;
void sifCallRpc(std::uint8_t* memory, R5900Context* context, PS2Runtime* runtime);
void finish(PS2Runtime& runtime) noexcept;

class Lifetime final {
public:
    explicit Lifetime(PS2Runtime& runtime) noexcept : runtime_(runtime) {}
    ~Lifetime() { finish(runtime_); }
    Lifetime(const Lifetime&) = delete;
    Lifetime& operator=(const Lifetime&) = delete;
private:
    PS2Runtime& runtime_;
};
} // namespace reo_cd_async
