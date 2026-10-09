#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124E50
// Address: 0x124e50 - 0x124e5c
void sub_00124E50_0x124e50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124E50_0x124e50");
#endif

    ctx->pc = 0x124e50u;

    // 0x124e50: 0xac860084  sw          $a2, 0x84($a0)
    ctx->pc = 0x124e50u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 132), GPR_U32(ctx, 6));
    // 0x124e54: 0x3e00008  jr          $ra
    ctx->pc = 0x124E54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124E54u;
            // 0x124e58: 0xac850080  sw          $a1, 0x80($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 128), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x124E5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
