#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F759A
// Address: 0x1f759a - 0x1f759b
void sub_001F759A_0x1f759a(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F759A_0x1f759a");
#endif

    ctx->pc = 0x1f759au;

    // 0x1f759a: 0x2ff01e2  .word       0x02FF01E2                   # sub         $zero, $s7, $ra # 000001C0 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x1f759au;
    { uint32_t tmp; bool ov; SUB32_OV(GPR_U32(ctx, 23), GPR_U32(ctx, 31), tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 0, (int32_t)tmp); }
    ctx->pc = GPR_U32(ctx, 31); return;
}
