// GAME-only numerical producer replacement. All original CPU integer
// header/player/counter/callback bodies remain registered and execute normally.
#include "original_graphics_route.h"
#include <array>
void sub_00144500_0x144500(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001477A0_0x1477a0(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001469A8_0x1469a8(uint8_t*, R5900Context*, PS2Runtime*);

void sub_00174030_0x174030(uint8_t*, R5900Context*, PS2Runtime*);
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
    constexpr uint32_t aliases144500[]{0x144500, 0x144550, 0x144554, 0x14455c, 0x144578,
                                       0x144580, 0x1445a8, 0x1445dc, 0x1445f4};
    for (auto pc : aliases144500)
        if (runtime.lookupFunction(pc) != sub_00144500_0x144500)
            return false;
    constexpr uint32_t aliases1477A0[]{0x1477a0, 0x1477e8, 0x147818, 0x147840, 0x147850, 0x1478ac,
                                       0x1478c8, 0x1478d0, 0x14790c, 0x147944, 0x14795c, 0x147964,
                                       0x147970, 0x147980, 0x1479c0, 0x1479d8, 0x1479f0, 0x147a04};
    for (auto pc : aliases1477A0)
        if (runtime.lookupFunction(pc) != sub_001477A0_0x1477a0)
            return false;
    constexpr uint32_t aliases1469A8[]{0x1469a8, 0x146a90, 0x146aa0, 0x146aa8, 0x146aec,
                                       0x146b00, 0x146b24, 0x146b68, 0x146b78, 0x146ba0};
    for (auto pc : aliases1469A8)
        if (runtime.lookupFunction(pc) != sub_001469A8_0x1469a8)
            return false;
    constexpr uint32_t releaseAliases[]{0x174030, 0x17404c};
    for (auto pc : releaseAliases)
        if (runtime.lookupFunction(pc) != sub_00174030_0x174030)
            return false;
    binding = {&runtime, owner, owns, receiver};
    for (auto pc : releaseAliases)
        runtime.registerFunction(pc, reo_movie_native_174030);
    for (auto pc : aliases144500)
        runtime.registerFunction(
            pc, numerical<0x144500, Operation::Decode144500, sub_00144500_0x144500>);
    for (auto pc : aliases1477A0)
        runtime.registerFunction(pc,
                                 numerical<0x1477A0, Operation::Csc1477A0, sub_001477A0_0x1477a0>);
    for (auto pc : aliases1469A8)
        runtime.registerFunction(pc,
                                 numerical<0x1469A8, Operation::Copy1469A8, sub_001469A8_0x1469a8>);
    return true;
}
} // namespace reo_gpu_movie_graphics
