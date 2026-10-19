#pragma once
// GAME-only seam for the entire original171D10 caller. Runtime providers own
// the actual stream, GPU commands, retained continuations and guest/DMA permits.
// This seam never reads a decoded buffer or creates a completion receipt.
#include "ps2_runtime.h"
#include <atomic>
#include <stdexcept>

namespace reo_gpu_movie_player {
enum class Operation { InputRestore, InputDrain, PictureRgba, PictureNative, InputSave };
enum class Result { Original, Completed, Yielded, Refused };
using Receiver = Result (*)(void*, Operation, uint8_t*, R5900Context*, PS2Runtime*,
                            uint32_t returnPC);
struct Binding {
    PS2Runtime* runtime = nullptr;
    void* owner = nullptr;
    Receiver receiver = nullptr;
};
// Set before guest execution; clear only after genuine pending GPU/guest
// continuations drain. No concurrent install/uninstall is supported.
inline Binding binding;
inline bool route(Operation operation, uint8_t* ram, R5900Context* context, PS2Runtime* runtime,
                  uint32_t returnPC) {
    if (binding.runtime != runtime || !binding.receiver)
        return false;
    const auto entry = context->pc;
    switch (binding.receiver(binding.owner, operation, ram, context, runtime, returnPC)) {
        case Result::Original:
            return false;
        case Result::Completed:
            if (context->pc != returnPC)
                throw std::logic_error(
                    "Movie backend completed without its genuine original continuation");
            return true;
        case Result::Yielded:
            // The generated same-entry return convention must never turn a
            // pending GPU picture into completion. Resume requires a backend
            // wait entry, which must eventually re-enter the genuine label.
            if (context->pc == entry || context->pc == returnPC ||
                !runtime->hasFunction(context->pc))
                throw std::logic_error("Movie GPU wait lacks a registered distinct continuation");
            return true;
        case Result::Refused:
            throw std::runtime_error(
                "Owned native movie operation refused; CPU decode fallback prohibited");
    }
    throw std::logic_error("Invalid movie backend receiver result");
}
// All nine real registration aliases must still name the original171D10.
// Receiver policy must select all five operations consistently for an owned
// request. Root's source/owner registration supplies that authority.
bool install(PS2Runtime&, void* owner, Receiver);
} // namespace reo_gpu_movie_player
