#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102448
// Address: 0x102448 - 0x102478
void sub_00102448_0x102448(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102448_0x102448");
#endif

    ctx->pc = 0x102448u;

    // 0x102448: 0x4843e000  cfc2.ni     $v1, $vi28
    ctx->pc = 0x102448u;
    SET_GPR_U32(ctx, 3, ctx->vu0_itop);
    // 0x10244c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10244cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102450: 0x14820003  bne         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x102450u;
    {
        const bool branch_taken_0x102450 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x102450) {
            ctx->pc = 0x102460u;
            goto label_102460;
        }
    }
    ctx->pc = 0x102458u;
    // 0x102458: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x102458u;
    {
        const bool branch_taken_0x102458 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10245Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102458u;
            // 0x10245c: 0x34630800  ori         $v1, $v1, 0x800 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2048);
        ctx->in_delay_slot = false;
        if (branch_taken_0x102458) {
            ctx->pc = 0x10246Cu;
            goto label_10246c;
        }
    }
    ctx->pc = 0x102460u;
label_102460:
    // 0x102460: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x102460u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x102464: 0x3442f7ff  ori         $v0, $v0, 0xF7FF
    ctx->pc = 0x102464u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)63487);
    // 0x102468: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x102468u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
label_10246c:
    // 0x10246c: 0x48c3e000  ctc2.ni     $v1, $vi28
    ctx->pc = 0x10246cu;
    ctx->vu0_itop = GPR_U32(ctx, 3) & 0x3FF;
    // 0x102470: 0x3e00008  jr          $ra
    ctx->pc = 0x102470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102460u: goto label_102460;
            case 0x10246Cu: goto label_10246c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102478u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
