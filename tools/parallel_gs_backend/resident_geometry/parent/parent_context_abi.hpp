#pragma once
// Private backend inclusion can follow Windows/GS headers. Preserve the SDK
// macro while parsing the canonical R5900Context declaration/ABI exactly once.
#if defined(EXCEPTION_BREAKPOINT)
#pragma push_macro("EXCEPTION_BREAKPOINT")
#undef EXCEPTION_BREAKPOINT
#define REO_PARENT_RESTORE_EXCEPTION_BREAKPOINT
#endif
#include "ps2_runtime.h"
#if defined(REO_PARENT_RESTORE_EXCEPTION_BREAKPOINT)
#pragma pop_macro("EXCEPTION_BREAKPOINT")
#undef REO_PARENT_RESTORE_EXCEPTION_BREAKPOINT
#endif
