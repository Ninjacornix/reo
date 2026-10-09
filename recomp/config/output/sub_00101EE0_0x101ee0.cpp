#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101EE0
// Address: 0x101ee0 - 0x101f10
void sub_00101EE0_0x101ee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101EE0_0x101ee0");
#endif

    ctx->pc = 0x101ee0u;

    // 0x101ee0: 0x4843e000  cfc2.ni     $v1, $vi28
    ctx->pc = 0x101ee0u;
    SET_GPR_U32(ctx, 3, ctx->vu0_itop);
    // 0x101ee4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x101ee4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x101ee8: 0x14820003  bne         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101EE8u;
    {
        const bool branch_taken_0x101ee8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x101ee8) {
            ctx->pc = 0x101EF8u;
            goto label_101ef8;
        }
    }
    ctx->pc = 0x101EF0u;
    // 0x101ef0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x101EF0u;
    {
        const bool branch_taken_0x101ef0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101EF0u;
            // 0x101ef4: 0x34630004  ori         $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x101ef0) {
            ctx->pc = 0x101F04u;
            goto label_101f04;
        }
    }
    ctx->pc = 0x101EF8u;
label_101ef8:
    // 0x101ef8: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x101ef8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x101efc: 0x3442fffb  ori         $v0, $v0, 0xFFFB
    ctx->pc = 0x101efcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65531);
    // 0x101f00: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x101f00u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
label_101f04:
    // 0x101f04: 0x48c3e000  ctc2.ni     $v1, $vi28
    ctx->pc = 0x101f04u;
    ctx->vu0_itop = GPR_U32(ctx, 3) & 0x3FF;
    // 0x101f08: 0x3e00008  jr          $ra
    ctx->pc = 0x101F08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101EF8u: goto label_101ef8;
            case 0x101F04u: goto label_101f04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101F10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
