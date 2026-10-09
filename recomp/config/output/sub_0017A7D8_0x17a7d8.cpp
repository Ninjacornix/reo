#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A7D8
// Address: 0x17a7d8 - 0x17a7f4
void sub_0017A7D8_0x17a7d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A7D8_0x17a7d8");
#endif

    ctx->pc = 0x17a7d8u;

    // 0x17a7d8: 0x24820008  addiu       $v0, $a0, 0x8
    ctx->pc = 0x17a7d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x17a7dc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17a7dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a7e0: 0xac460008  sw          $a2, 0x8($v0)
    ctx->pc = 0x17a7e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 6));
    // 0x17a7e4: 0xac470000  sw          $a3, 0x0($v0)
    ctx->pc = 0x17a7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 7));
    // 0x17a7e8: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x17a7e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x17a7ec: 0x3e00008  jr          $ra
    ctx->pc = 0x17A7ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A7F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A7ECu;
            // 0x17a7f0: 0xac830004  sw          $v1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17A7F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
