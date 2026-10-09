#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150AF0
// Address: 0x150af0 - 0x150b04
void sub_00150AF0_0x150af0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150AF0_0x150af0");
#endif

    ctx->pc = 0x150af0u;

    // 0x150af0: 0x2484011c  addiu       $a0, $a0, 0x11C
    ctx->pc = 0x150af0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 284));
    // 0x150af4: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x150af4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x150af8: 0xac860004  sw          $a2, 0x4($a0)
    ctx->pc = 0x150af8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 6));
    // 0x150afc: 0x3e00008  jr          $ra
    ctx->pc = 0x150AFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150AFCu;
            // 0x150b00: 0xac800008  sw          $zero, 0x8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x150B04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
