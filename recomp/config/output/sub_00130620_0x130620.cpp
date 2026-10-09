#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130620
// Address: 0x130620 - 0x130658
void sub_00130620_0x130620(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130620_0x130620");
#endif

    ctx->pc = 0x130620u;

    // 0x130620: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x130620u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x130624: 0xac800030  sw          $zero, 0x30($a0)
    ctx->pc = 0x130624u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 0));
    // 0x130628: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x130628u;
    {
        const bool branch_taken_0x130628 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13062Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130628u;
            // 0x13062c: 0xa0800003  sb          $zero, 0x3($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130628) {
            ctx->pc = 0x130638u;
            goto label_130638;
        }
    }
    ctx->pc = 0x130630u;
    // 0x130630: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x130630u;
    {
        const bool branch_taken_0x130630 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x130634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130630u;
            // 0x130634: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130630) {
            ctx->pc = 0x13063Cu;
            goto label_13063c;
        }
    }
    ctx->pc = 0x130638u;
label_130638:
    // 0x130638: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x130638u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_13063c:
    // 0x13063c: 0xa0820001  sb          $v0, 0x1($a0)
    ctx->pc = 0x13063cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x130640: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130640u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130644: 0xa0800002  sb          $zero, 0x2($a0)
    ctx->pc = 0x130644u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x130648: 0xac800020  sw          $zero, 0x20($a0)
    ctx->pc = 0x130648u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 0));
    // 0x13064c: 0xac800024  sw          $zero, 0x24($a0)
    ctx->pc = 0x13064cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 0));
    // 0x130650: 0x3e00008  jr          $ra
    ctx->pc = 0x130650u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130650u;
            // 0x130654: 0xa0820043  sb          $v0, 0x43($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 67), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130638u: goto label_130638;
            case 0x13063Cu: goto label_13063c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130658u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
