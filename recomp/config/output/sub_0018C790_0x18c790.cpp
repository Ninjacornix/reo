#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C790
// Address: 0x18c790 - 0x18c7c0
void sub_0018C790_0x18c790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C790_0x18c790");
#endif

    ctx->pc = 0x18c790u;

    // 0x18c790: 0x3c036000  lui         $v1, 0x6000
    ctx->pc = 0x18c790u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)24576 << 16));
    // 0x18c794: 0x7c800000  sq          $zero, 0x0($a0)
    ctx->pc = 0x18c794u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 0));
    // 0x18c798: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x18c798u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x18c79c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18c79cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18c7a0: 0x14c20005  bne         $a2, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18C7A0u;
    {
        const bool branch_taken_0x18c7a0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x18C7A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C7A0u;
            // 0x18c7a4: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c7a0) {
            ctx->pc = 0x18C7B8u;
            goto label_18c7b8;
        }
    }
    ctx->pc = 0x18C7A8u;
    // 0x18c7a8: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x18c7a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18c7ac: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x18c7acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x18c7b0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x18c7b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18c7b4: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x18c7b4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_18c7b8:
    // 0x18c7b8: 0x3e00008  jr          $ra
    ctx->pc = 0x18C7B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C7BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C7B8u;
            // 0x18c7bc: 0x24820010  addiu       $v0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C7B8u: goto label_18c7b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C7C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
