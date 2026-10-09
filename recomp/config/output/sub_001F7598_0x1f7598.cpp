#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F7598
// Address: 0x1f7598 - 0x1f7599
void sub_001F7598_0x1f7598(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F7598_0x1f7598");
#endif

    ctx->pc = 0x1f7598u;

    // 0x1f7598: 0x1e20003  .word       0x01E20003                   # sra         $zero, $v0, 0 # 01E00000 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x1f7598u;
    SET_GPR_S32(ctx, 0, SRA32(GPR_S32(ctx, 2), 0));
    ctx->pc = GPR_U32(ctx, 31); return;
}
