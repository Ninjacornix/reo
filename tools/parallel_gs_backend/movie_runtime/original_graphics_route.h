#pragma once
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <stdexcept>

namespace reo_gpu_movie_graphics {
enum class Operation { Decode144500, Csc1477A0, Copy1469A8 };
enum class Result { Completed, Yielded, Refused };
using Owns = bool (*)(void*, PS2Runtime*, R5900Context*);
using Receiver = Result (*)(void*, Operation, uint8_t*, R5900Context*, PS2Runtime*,
                            uint32_t originalReturnPC);
struct Binding {
    PS2Runtime* runtime = nullptr;
    void* owner = nullptr;
    Owns owns = nullptr;
    Receiver receive = nullptr;
};
inline Binding binding;
// GAME-only install at a quiescent original movie boundary, before entering
// CPU numerical code. Root supplies real Runtime/context/source ownership and
// a receiver which schedules LiveMovieProducer on the actual GS owner thread.
bool install(PS2Runtime&, void* owner, Owns, Receiver);
} // namespace reo_gpu_movie_graphics
