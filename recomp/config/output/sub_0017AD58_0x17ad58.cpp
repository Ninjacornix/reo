#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017AD58
// Address: 0x17ad58 - 0x17ada8
void sub_0017AD58_0x17ad58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017AD58_0x17ad58");
#endif

    ctx->pc = 0x17ad58u;

    // 0x17ad58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17ad58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17ad5c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17ad5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17ad60: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17ad60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17ad64: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x17ad64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ad68: 0x100302d  daddu       $a2, $t0, $zero
    ctx->pc = 0x17ad68u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ad6c: 0x8ca30074  lw          $v1, 0x74($a1)
    ctx->pc = 0x17ad6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 116)));
    // 0x17ad70: 0x14620007  bne         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17AD70u;
    {
        const bool branch_taken_0x17ad70 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x17AD74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AD70u;
            // 0x17ad74: 0xe0282d  daddu       $a1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ad70) {
            ctx->pc = 0x17AD90u;
            goto label_17ad90;
        }
    }
    ctx->pc = 0x17AD78u;
    // 0x17ad78: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x17AD78u;
    {
        const bool branch_taken_0x17ad78 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AD7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AD78u;
            // 0x17ad7c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ad78) {
            ctx->pc = 0x17AD88u;
            goto label_17ad88;
        }
    }
    ctx->pc = 0x17AD80u;
    // 0x17ad80: 0x805249c  j           func_149270
    ctx->pc = 0x17AD80u;
    ctx->pc = 0x17AD84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AD80u;
            // 0x17ad84: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149270u;
    if (runtime->hasFunction(0x149270u)) {
        auto targetFn = runtime->lookupFunction(0x149270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00149270_0x149270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17AD88u;
label_17ad88:
    // 0x17ad88: 0x805249a  j           func_149268
    ctx->pc = 0x17AD88u;
    ctx->pc = 0x17AD8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AD88u;
            // 0x17ad8c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149268u;
    if (runtime->hasFunction(0x149268u)) {
        auto targetFn = runtime->lookupFunction(0x149268u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00149268_0x149268(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17AD90u;
label_17ad90:
    // 0x17ad90: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x17AD90u;
    {
        const bool branch_taken_0x17ad90 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AD94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AD90u;
            // 0x17ad94: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ad90) {
            ctx->pc = 0x17ADA0u;
            goto label_17ada0;
        }
    }
    ctx->pc = 0x17AD98u;
    // 0x17ad98: 0x805249c  j           func_149270
    ctx->pc = 0x17AD98u;
    ctx->pc = 0x17AD9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AD98u;
            // 0x17ad9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149270u;
    if (runtime->hasFunction(0x149270u)) {
        auto targetFn = runtime->lookupFunction(0x149270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00149270_0x149270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17ADA0u;
label_17ada0:
    // 0x17ada0: 0x805249a  j           func_149268
    ctx->pc = 0x17ADA0u;
    ctx->pc = 0x17ADA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17ADA0u;
            // 0x17ada4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149268u;
    if (runtime->hasFunction(0x149268u)) {
        auto targetFn = runtime->lookupFunction(0x149268u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00149268_0x149268(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17ADA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
