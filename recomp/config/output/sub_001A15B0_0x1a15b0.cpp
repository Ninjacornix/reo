#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A15B0
// Address: 0x1a15b0 - 0x1a1600
void sub_001A15B0_0x1a15b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A15B0_0x1a15b0");
#endif

    ctx->pc = 0x1a15b0u;

    // 0x1a15b0: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x1a15b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1a15b4: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1A15B4u;
    {
        const bool branch_taken_0x1a15b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a15b4) {
            ctx->pc = 0x1A15DCu;
            goto label_1a15dc;
        }
    }
    ctx->pc = 0x1A15BCu;
    // 0x1a15bc: 0x8c860014  lw          $a2, 0x14($a0)
    ctx->pc = 0x1a15bcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1a15c0: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x1a15c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a15c4: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x1a15c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1a15c8: 0x8c820020  lw          $v0, 0x20($a0)
    ctx->pc = 0x1a15c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x1a15cc: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x1a15ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1a15d0: 0x831823  subu        $v1, $a0, $v1
    ctx->pc = 0x1a15d0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1a15d4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A15D4u;
    {
        const bool branch_taken_0x1a15d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A15D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A15D4u;
            // 0x1a15d8: 0x621023  subu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a15d4) {
            ctx->pc = 0x1A15F8u;
            goto label_1a15f8;
        }
    }
    ctx->pc = 0x1A15DCu;
label_1a15dc:
    // 0x1a15dc: 0x8c860014  lw          $a2, 0x14($a0)
    ctx->pc = 0x1a15dcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1a15e0: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x1a15e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a15e4: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x1a15e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1a15e8: 0x8c820020  lw          $v0, 0x20($a0)
    ctx->pc = 0x1a15e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x1a15ec: 0xc52023  subu        $a0, $a2, $a1
    ctx->pc = 0x1a15ecu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1a15f0: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x1a15f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a15f4: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1a15f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1a15f8:
    // 0x1a15f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A15F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A15DCu: goto label_1a15dc;
            case 0x1A15F8u: goto label_1a15f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1600u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
