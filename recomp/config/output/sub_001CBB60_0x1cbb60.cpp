#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CBB60
// Address: 0x1cbb60 - 0x1cbbc0
void sub_001CBB60_0x1cbb60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CBB60_0x1cbb60");
#endif

    ctx->pc = 0x1cbb60u;

    // 0x1cbb60: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x1cbb60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x1cbb64: 0x24020067  addiu       $v0, $zero, 0x67
    ctx->pc = 0x1cbb64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 103));
    // 0x1cbb68: 0x8c239d10  lw          $v1, -0x62F0($at)
    ctx->pc = 0x1cbb68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294941968)));
    // 0x1cbb6c: 0x10620012  beq         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1CBB6Cu;
    {
        const bool branch_taken_0x1cbb6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CBB70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBB6Cu;
            // 0x1cbb70: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbb6c) {
            ctx->pc = 0x1CBBB8u;
            goto label_1cbbb8;
        }
    }
    ctx->pc = 0x1CBB74u;
    // 0x1cbb74: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1cbb74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1cbb78: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CBB78u;
    {
        const bool branch_taken_0x1cbb78 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CBB7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBB78u;
            // 0x1cbb7c: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbb78) {
            ctx->pc = 0x1CBBB0u;
            goto label_1cbbb0;
        }
    }
    ctx->pc = 0x1CBB80u;
    // 0x1cbb80: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1cbb80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1cbb84: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1CBB84u;
    {
        const bool branch_taken_0x1cbb84 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CBB88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBB84u;
            // 0x1cbb88: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbb84) {
            ctx->pc = 0x1CBBA8u;
            goto label_1cbba8;
        }
    }
    ctx->pc = 0x1CBB8Cu;
    // 0x1cbb8c: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1cbb8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1cbb90: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CBB90u;
    {
        const bool branch_taken_0x1cbb90 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CBB94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBB90u;
            // 0x1cbb94: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbb90) {
            ctx->pc = 0x1CBBA0u;
            goto label_1cbba0;
        }
    }
    ctx->pc = 0x1CBB98u;
    // 0x1cbb98: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CBB98u;
    {
        const bool branch_taken_0x1cbb98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CBB9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBB98u;
            // 0x1cbb9c: 0x2402fff0  addiu       $v0, $zero, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbb98) {
            ctx->pc = 0x1CBBB8u;
            goto label_1cbbb8;
        }
    }
    ctx->pc = 0x1CBBA0u;
label_1cbba0:
    // 0x1cbba0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CBBA0u;
    {
        const bool branch_taken_0x1cbba0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbba0) {
            ctx->pc = 0x1CBBB8u;
            goto label_1cbbb8;
        }
    }
    ctx->pc = 0x1CBBA8u;
label_1cbba8:
    // 0x1cbba8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1CBBA8u;
    {
        const bool branch_taken_0x1cbba8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbba8) {
            ctx->pc = 0x1CBBB8u;
            goto label_1cbbb8;
        }
    }
    ctx->pc = 0x1CBBB0u;
label_1cbbb0:
    // 0x1cbbb0: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1CBBB0u;
    {
        const bool branch_taken_0x1cbbb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbbb0) {
            ctx->pc = 0x1CBBB8u;
            goto label_1cbbb8;
        }
    }
    ctx->pc = 0x1CBBB8u;
label_1cbbb8:
    // 0x1cbbb8: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBBB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBBA0u: goto label_1cbba0;
            case 0x1CBBA8u: goto label_1cbba8;
            case 0x1CBBB0u: goto label_1cbbb0;
            case 0x1CBBB8u: goto label_1cbbb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBBC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
