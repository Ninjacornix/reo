#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189B28
// Address: 0x189b28 - 0x189b80
void sub_00189B28_0x189b28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189B28_0x189b28");
#endif

    ctx->pc = 0x189b28u;

label_189b28:
    // 0x189b28: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x189b28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189b2c: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x189b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x189b30: 0x8c880008  lw          $t0, 0x8($a0)
    ctx->pc = 0x189b30u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x189b34: 0x8c89000c  lw          $t1, 0xC($a0)
    ctx->pc = 0x189b34u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x189b38: 0x8c8a0010  lw          $t2, 0x10($a0)
    ctx->pc = 0x189b38u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x189b3c: 0x8c8b0014  lw          $t3, 0x14($a0)
    ctx->pc = 0x189b3cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x189b40: 0x8c8c0018  lw          $t4, 0x18($a0)
    ctx->pc = 0x189b40u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x189b44: 0x8c8d001c  lw          $t5, 0x1C($a0)
    ctx->pc = 0x189b44u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x189b48: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x189b48u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x189b4c: 0xaca30004  sw          $v1, 0x4($a1)
    ctx->pc = 0x189b4cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 3));
    // 0x189b50: 0xaca80008  sw          $t0, 0x8($a1)
    ctx->pc = 0x189b50u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 8));
    // 0x189b54: 0xaca9000c  sw          $t1, 0xC($a1)
    ctx->pc = 0x189b54u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 9));
    // 0x189b58: 0xacaa0010  sw          $t2, 0x10($a1)
    ctx->pc = 0x189b58u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 10));
    // 0x189b5c: 0xacab0014  sw          $t3, 0x14($a1)
    ctx->pc = 0x189b5cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 11));
    // 0x189b60: 0xacac0018  sw          $t4, 0x18($a1)
    ctx->pc = 0x189b60u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 12));
    // 0x189b64: 0xacad001c  sw          $t5, 0x1C($a1)
    ctx->pc = 0x189b64u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 13));
    // 0x189b68: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189b68u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189b6c: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x189b6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x189b70: 0x14c0ffed  bnez        $a2, . + 4 + (-0x13 << 2)
    ctx->pc = 0x189B70u;
    {
        const bool branch_taken_0x189b70 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189B74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189B70u;
            // 0x189b74: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189b70) {
            ctx->pc = 0x189B28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189b28;
        }
    }
    ctx->pc = 0x189B78u;
    // 0x189b78: 0x3e00008  jr          $ra
    ctx->pc = 0x189B78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189B28u: goto label_189b28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189B80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
