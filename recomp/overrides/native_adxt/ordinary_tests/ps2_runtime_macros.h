#pragma once
#include "ps2_runtime.h"
#define GPR_U32(c,n) ((n)==0?0u:static_cast<std::uint32_t>((c)->r[(n)][0]))
#define SET_GPR_S32(c,n,v) ((c)->r[(n)][0]=static_cast<std::uint64_t>(static_cast<std::int64_t>(static_cast<std::int32_t>(v))))
