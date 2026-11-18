#pragma once
#include "ps2_runtime.h"
#define GPR_U32(c,n) ((n)==0?0u:static_cast<std::uint32_t>((c)->r[n].low))
#define GPR_U64(c,n) ((n)==0?0ULL:(c)->r[n].low)
#define SET_GPR_S32(c,n,v) ((c)->r[n].low=static_cast<std::uint64_t>(static_cast<std::int64_t>(static_cast<std::int32_t>(v))))
