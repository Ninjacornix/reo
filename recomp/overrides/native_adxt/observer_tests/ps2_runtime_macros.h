#pragma once
#include "ps2_runtime.h"
#define GPR_U32(c,n) ((n)==0?0u:static_cast<std::uint32_t>((c)->r[(n)][0]))
