#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A658
// Address: 0x12a658 - 0x12a6b8
void sub_0012A658_0x12a658(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A658_0x12a658");
#endif

    switch (ctx->pc) {
        case 0x12a690u: goto label_12a690;
        case 0x12a6a8u: goto label_12a6a8;
        default: break;
    }

    ctx->pc = 0x12a658u;

    // 0x12a658: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a658u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a65c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12a65cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12a660: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x12a660u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a664: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12a664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12a668: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12A668u;
    {
        const bool branch_taken_0x12a668 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x12A66Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A668u;
            // 0x12a66c: 0x8c820094  lw          $v0, 0x94($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 148)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a668) {
            ctx->pc = 0x12A688u;
            goto label_12a688;
        }
    }
    ctx->pc = 0x12A670u;
    // 0x12a670: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12a670u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12a674: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12a674u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a678: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12a678u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a67c: 0x2484a2f0  addiu       $a0, $a0, -0x5D10
    ctx->pc = 0x12a67cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943472));
    // 0x12a680: 0x804a034  j           func_1280D0
    ctx->pc = 0x12A680u;
    ctx->pc = 0x12A684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A680u;
            // 0x12a684: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A688u;
label_12a688:
    // 0x12a688: 0xc04f344  jal         func_13CD10
    ctx->pc = 0x12A688u;
    SET_GPR_U32(ctx, 31, 0x12A690u);
    ctx->pc = 0x12A68Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A688u;
            // 0x12a68c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CD10u;
    if (runtime->hasFunction(0x13CD10u)) {
        auto targetFn = runtime->lookupFunction(0x13CD10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A690u; }
        if (ctx->pc != 0x12A690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CD10_0x13cd10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A690u; }
        if (ctx->pc != 0x12A690u) { return; }
    }
    ctx->pc = 0x12A690u;
label_12a690:
    // 0x12a690: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12a690u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12a694: 0x2484a320  addiu       $a0, $a0, -0x5CE0
    ctx->pc = 0x12a694u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943520));
    // 0x12a698: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12A698u;
    {
        const bool branch_taken_0x12a698 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x12A69Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A698u;
            // 0x12a69c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a698) {
            ctx->pc = 0x12A6A8u;
            goto label_12a6a8;
        }
    }
    ctx->pc = 0x12A6A0u;
    // 0x12a6a0: 0xc04a04a  jal         func_128128
    ctx->pc = 0x12A6A0u;
    SET_GPR_U32(ctx, 31, 0x12A6A8u);
    ctx->pc = 0x128128u;
    if (runtime->hasFunction(0x128128u)) {
        auto targetFn = runtime->lookupFunction(0x128128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A6A8u; }
        if (ctx->pc != 0x12A6A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128128_0x128128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A6A8u; }
        if (ctx->pc != 0x12A6A8u) { return; }
    }
    ctx->pc = 0x12A6A8u;
label_12a6a8:
    // 0x12a6a8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12a6a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a6ac: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12a6acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a6b0: 0x3e00008  jr          $ra
    ctx->pc = 0x12A6B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A6B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A6B0u;
            // 0x12a6b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A688u: goto label_12a688;
            case 0x12A690u: goto label_12a690;
            case 0x12A6A8u: goto label_12a6a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A6B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
