#pragma once
#include "ps2_runtime.h"
#define GPR_U32(c, r) static_cast<std::uint32_t>((c)->gpr[r])
#define SET_GPR_U32(c, r, v) ((c)->gpr[r] = static_cast<std::uint32_t>(v))
#define SET_GPR_S32(c, r, v) ((c)->gpr[r] = static_cast<std::uint64_t>(static_cast<std::int64_t>(v)))
