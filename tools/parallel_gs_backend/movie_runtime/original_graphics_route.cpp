#include "reo_movie_game_addresses.h"
// GAME-only numerical producer replacement. All original CPU integer
// header/player/counter/callback bodies remain registered and execute normally.
#include "original_graphics_route.h"
#include <array>
void REO_MS_144500(uint8_t*, R5900Context*, PS2Runtime*);
void REO_MS_1477A0(uint8_t*, R5900Context*, PS2Runtime*);
void REO_MS_1469A8(uint8_t*, R5900Context*, PS2Runtime*);

void REO_MS_174030(uint8_t*, R5900Context*, PS2Runtime*);
void reo_movie_native_174030(uint8_t*, R5900Context*, PS2Runtime*);

namespace reo_gpu_movie_graphics {
namespace {
template <uint32_t Entry, Operation Kind, void (*Original)(uint8_t*, R5900Context*, PS2Runtime*)>
void numerical(uint8_t* ram, R5900Context* context, PS2Runtime* runtime) {
    auto& owner = binding;
    if (owner.runtime != runtime || !owner.owns || !owner.owns(owner.owner, runtime, context)) {
        Original(ram, context, runtime);
        return;
    }
    // No already-running original numerical continuation may become owned.
    // Activation must occur at the genuine outer quiescent producer boundary.
    if (context->pc != Entry)
        throw std::runtime_error("Owned movie entered a stale CPU graphics continuation");
    const uint32_t returnPC = GPR_U32(context, 31);
    switch (owner.receive(owner.owner, Kind, ram, context, runtime, returnPC)) {
        case Result::Completed:
            if (context->pc != returnPC)
                throw std::logic_error("GPU movie completion lost original caller continuation");
            return;
        case Result::Yielded:
            if (context->pc == Entry || context->pc == returnPC ||
                !runtime->hasFunction(context->pc))
                throw std::logic_error(
                    "GPU movie pending work lacks a real registered wait continuation");
            return;
        case Result::Refused:
            throw std::runtime_error(
                "Owned GPU movie operation refused; CPU graphics fallback prohibited");
    }
    throw std::logic_error("Invalid original movie GPU receiver status");
}
} // namespace
bool install(PS2Runtime& runtime, void* owner, Owns owns, Receiver receiver) {
    if (!owner || !owns || !receiver || binding.receive)
        return false;
    constexpr uint32_t aliases144500[]{REO_MA(0x144500), REO_MA(0x144550), REO_MA(0x144554), REO_MA(0x14455c), REO_MA(0x144578),
                                       REO_MA(0x144580), REO_MA(0x1445a8), REO_MA(0x1445dc), REO_MA(0x1445f4)};
    for (auto pc : aliases144500)
        if (runtime.lookupFunction(pc) != REO_MS_144500)
            return false;
    constexpr uint32_t aliases1477A0[]{REO_MA(0x1477a0), REO_MA(0x1477e8), REO_MA(0x147818), REO_MA(0x147840), REO_MA(0x147850), REO_MA(0x1478ac),
                                       REO_MA(0x1478c8), REO_MA(0x1478d0), REO_MA(0x14790c), REO_MA(0x147944), REO_MA(0x14795c), REO_MA(0x147964),
                                       REO_MA(0x147970), REO_MA(0x147980), REO_MA(0x1479c0), REO_MA(0x1479d8), REO_MA(0x1479f0), REO_MA(0x147a04)};
    for (auto pc : aliases1477A0)
        if (runtime.lookupFunction(pc) != REO_MS_1477A0)
            return false;
    constexpr uint32_t aliases1469A8[]{REO_MA(0x1469a8), REO_MA(0x146a90), REO_MA(0x146aa0), REO_MA(0x146aa8), REO_MA(0x146aec),
                                       REO_MA(0x146b00), REO_MA(0x146b24), REO_MA(0x146b68), REO_MA(0x146b78), REO_MA(0x146ba0)};
    for (auto pc : aliases1469A8)
        if (runtime.lookupFunction(pc) != REO_MS_1469A8)
            return false;
    constexpr uint32_t releaseAliases[]{REO_MA(0x174030), REO_MA(0x17404c)};
    for (auto pc : releaseAliases)
        if (runtime.lookupFunction(pc) != REO_MS_174030)
            return false;
    binding = {&runtime, owner, owns, receiver};
    for (auto pc : releaseAliases)
        runtime.registerFunction(pc, reo_movie_native_174030);
    for (auto pc : aliases144500)
        runtime.registerFunction(
            pc, numerical<REO_MA(0x144500), Operation::Decode144500, REO_MS_144500>);
    for (auto pc : aliases1477A0)
        runtime.registerFunction(pc,
                                 numerical<REO_MA(0x1477A0), Operation::Csc1477A0, REO_MS_1477A0>);
    for (auto pc : aliases1469A8)
        runtime.registerFunction(pc,
                                 numerical<REO_MA(0x1469A8), Operation::Copy1469A8, REO_MS_1469A8>);
    return true;
}
} // namespace reo_gpu_movie_graphics
