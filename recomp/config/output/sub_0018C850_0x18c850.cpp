#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C850
// Address: 0x18c850 - 0x18c870
void sub_0018C850_0x18c850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C850_0x18c850");
#endif

    ctx->pc = 0x18c850u;

    // 0x18c850: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x18c850u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x18c854: 0x3c025100  lui         $v0, 0x5100
    ctx->pc = 0x18c854u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20736 << 16));
    // 0x18c858: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x18c858u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x18c85c: 0xa21025  or          $v0, $a1, $v0
    ctx->pc = 0x18c85cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x18c860: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x18c860u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x18c864: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x18c864u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x18c868: 0x3e00008  jr          $ra
    ctx->pc = 0x18C868u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C86Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C868u;
            // 0x18c86c: 0x24820010  addiu       $v0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18C870u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
