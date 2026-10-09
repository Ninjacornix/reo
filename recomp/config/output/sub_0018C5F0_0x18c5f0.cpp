#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C5F0
// Address: 0x18c5f0 - 0x18c620
void sub_0018C5F0_0x18c5f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C5F0_0x18c5f0");
#endif

    ctx->pc = 0x18c5f0u;

    // 0x18c5f0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x18c5f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x18c5f4: 0x7c800000  sq          $zero, 0x0($a0)
    ctx->pc = 0x18c5f4u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 0));
    // 0x18c5f8: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x18c5f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x18c5fc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18c5fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18c600: 0x14c20005  bne         $a2, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18C600u;
    {
        const bool branch_taken_0x18c600 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x18C604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C600u;
            // 0x18c604: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c600) {
            ctx->pc = 0x18C618u;
            goto label_18c618;
        }
    }
    ctx->pc = 0x18C608u;
    // 0x18c608: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x18c608u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18c60c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x18c60cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x18c610: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x18c610u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18c614: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x18c614u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_18c618:
    // 0x18c618: 0x3e00008  jr          $ra
    ctx->pc = 0x18C618u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C61Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C618u;
            // 0x18c61c: 0x24820010  addiu       $v0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C618u: goto label_18c618;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C620u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
