#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101F10
// Address: 0x101f10 - 0x101f40
void sub_00101F10_0x101f10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101F10_0x101f10");
#endif

    ctx->pc = 0x101f10u;

    // 0x101f10: 0x4843e000  cfc2.ni     $v1, $vi28
    ctx->pc = 0x101f10u;
    SET_GPR_U32(ctx, 3, ctx->vu0_itop);
    // 0x101f14: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x101f14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x101f18: 0x14820003  bne         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101F18u;
    {
        const bool branch_taken_0x101f18 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x101f18) {
            ctx->pc = 0x101F28u;
            goto label_101f28;
        }
    }
    ctx->pc = 0x101F20u;
    // 0x101f20: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x101F20u;
    {
        const bool branch_taken_0x101f20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101F24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F20u;
            // 0x101f24: 0x34630008  ori         $v1, $v1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
        if (branch_taken_0x101f20) {
            ctx->pc = 0x101F34u;
            goto label_101f34;
        }
    }
    ctx->pc = 0x101F28u;
label_101f28:
    // 0x101f28: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x101f28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x101f2c: 0x3442fff7  ori         $v0, $v0, 0xFFF7
    ctx->pc = 0x101f2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65527);
    // 0x101f30: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x101f30u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
label_101f34:
    // 0x101f34: 0x48c3e000  ctc2.ni     $v1, $vi28
    ctx->pc = 0x101f34u;
    ctx->vu0_itop = GPR_U32(ctx, 3) & 0x3FF;
    // 0x101f38: 0x3e00008  jr          $ra
    ctx->pc = 0x101F38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101F28u: goto label_101f28;
            case 0x101F34u: goto label_101f34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101F40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
