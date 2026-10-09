#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001619D8
// Address: 0x1619d8 - 0x1619f8
void sub_001619D8_0x1619d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001619D8_0x1619d8");
#endif

    ctx->pc = 0x1619d8u;

    // 0x1619d8: 0x24820100  addiu       $v0, $a0, 0x100
    ctx->pc = 0x1619d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 256));
    // 0x1619dc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1619dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1619e0: 0xac400008  sw          $zero, 0x8($v0)
    ctx->pc = 0x1619e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 0));
    // 0x1619e4: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1619e4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1619e8: 0xac400004  sw          $zero, 0x4($v0)
    ctx->pc = 0x1619e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x1619ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1619ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1619F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1619ECu;
            // 0x1619f0: 0xac8300fc  sw          $v1, 0xFC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 252), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1619F4u;
    // 0x1619f4: 0x0  nop
    ctx->pc = 0x1619f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
