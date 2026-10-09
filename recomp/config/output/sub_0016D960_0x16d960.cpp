#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D960
// Address: 0x16d960 - 0x16d988
void sub_0016D960_0x16d960(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D960_0x16d960");
#endif

    ctx->pc = 0x16d960u;

    // 0x16d960: 0x2482000c  addiu       $v0, $a0, 0xC
    ctx->pc = 0x16d960u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x16d964: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x16d964u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16d968: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x16d968u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x16d96c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x16d96cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x16d970: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x16d970u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x16d974: 0xac400004  sw          $zero, 0x4($v0)
    ctx->pc = 0x16d974u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x16d978: 0xac430008  sw          $v1, 0x8($v0)
    ctx->pc = 0x16d978u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x16d97c: 0x3e00008  jr          $ra
    ctx->pc = 0x16D97Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D97Cu;
            // 0x16d980: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16D984u;
    // 0x16d984: 0x0  nop
    ctx->pc = 0x16d984u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
