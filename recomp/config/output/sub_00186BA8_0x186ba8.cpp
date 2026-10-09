#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00186BA8
// Address: 0x186ba8 - 0x186be0
void sub_00186BA8_0x186ba8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00186BA8_0x186ba8");
#endif

    switch (ctx->pc) {
        case 0x186bb8u: goto label_186bb8;
        default: break;
    }

    ctx->pc = 0x186ba8u;

    // 0x186ba8: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x186ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x186bac: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x186bacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x186bb0: 0x24427080  addiu       $v0, $v0, 0x7080
    ctx->pc = 0x186bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 28800));
    // 0x186bb4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x186bb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_186bb8:
    // 0x186bb8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x186bb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x186bbc: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x186bbcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x186bc0: 0xac40000c  sw          $zero, 0xC($v0)
    ctx->pc = 0x186bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 0));
    // 0x186bc4: 0x0  nop
    ctx->pc = 0x186bc4u;
    // NOP
    // 0x186bc8: 0x0  nop
    ctx->pc = 0x186bc8u;
    // NOP
    // 0x186bcc: 0x461fffa  bgez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x186BCCu;
    {
        const bool branch_taken_0x186bcc = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x186BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186BCCu;
            // 0x186bd0: 0x24422010  addiu       $v0, $v0, 0x2010 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8208));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186bcc) {
            ctx->pc = 0x186BB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_186bb8;
        }
    }
    ctx->pc = 0x186BD4u;
    // 0x186bd4: 0x3e00008  jr          $ra
    ctx->pc = 0x186BD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x186BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186BD4u;
            // 0x186bd8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x186BB8u: goto label_186bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x186BDCu;
    // 0x186bdc: 0x0  nop
    ctx->pc = 0x186bdcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
