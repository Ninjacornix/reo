#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135000
// Address: 0x135000 - 0x13501c
void sub_00135000_0x135000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135000_0x135000");
#endif

    ctx->pc = 0x135000u;

    // 0x135000: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x135000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x135004: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x135004u;
    {
        const bool branch_taken_0x135004 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x135008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135004u;
            // 0x135008: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135004) {
            ctx->pc = 0x135014u;
            goto label_135014;
        }
    }
    ctx->pc = 0x13500Cu;
    // 0x13500c: 0xac800010  sw          $zero, 0x10($a0)
    ctx->pc = 0x13500cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x135010: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x135010u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
label_135014:
    // 0x135014: 0x3e00008  jr          $ra
    ctx->pc = 0x135014u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135014u: goto label_135014;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13501Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
