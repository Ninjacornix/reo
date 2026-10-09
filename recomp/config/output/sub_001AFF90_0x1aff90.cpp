#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFF90
// Address: 0x1aff90 - 0x1b0004
void sub_001AFF90_0x1aff90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFF90_0x1aff90");
#endif

    switch (ctx->pc) {
        case 0x1affa4u: goto label_1affa4;
        case 0x1affe0u: goto label_1affe0;
        case 0x1afff4u: goto label_1afff4;
        default: break;
    }

    ctx->pc = 0x1aff90u;

    // 0x1aff90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1aff90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1aff94: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1aff94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1aff98: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aff98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aff9c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFF9Cu;
    SET_GPR_U32(ctx, 31, 0x1AFFA4u);
    ctx->pc = 0x1AFFA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF9Cu;
            // 0x1affa0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFFA4u; }
        if (ctx->pc != 0x1AFFA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFFA4u; }
        if (ctx->pc != 0x1AFFA4u) { return; }
    }
    ctx->pc = 0x1AFFA4u;
label_1affa4:
    // 0x1affa4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1affa4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1affa8: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1AFFA8u;
    {
        const bool branch_taken_0x1affa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFFACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFA8u;
            // 0x1affac: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1affa8) {
            ctx->pc = 0x1AFFF4u;
            goto label_1afff4;
        }
    }
    ctx->pc = 0x1AFFB0u;
    // 0x1affb0: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AFFB0u;
    {
        const bool branch_taken_0x1affb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1affb0) {
            ctx->pc = 0x1AFFF4u;
            goto label_1afff4;
        }
    }
    ctx->pc = 0x1AFFB8u;
    // 0x1affb8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1affb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1affbc: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1AFFBCu;
    {
        const bool branch_taken_0x1affbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFFC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFBCu;
            // 0x1affc0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1affbc) {
            ctx->pc = 0x1AFFE8u;
            goto label_1affe8;
        }
    }
    ctx->pc = 0x1AFFC4u;
    // 0x1affc4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFFC4u;
    {
        const bool branch_taken_0x1affc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFFC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFC4u;
            // 0x1affc8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1affc4) {
            ctx->pc = 0x1AFFD4u;
            goto label_1affd4;
        }
    }
    ctx->pc = 0x1AFFCCu;
    // 0x1affcc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1AFFCCu;
    {
        const bool branch_taken_0x1affcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFFD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFCCu;
            // 0x1affd0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1affcc) {
            ctx->pc = 0x1AFFF8u;
            goto label_1afff8;
        }
    }
    ctx->pc = 0x1AFFD4u;
label_1affd4:
    // 0x1affd4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1affd4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1affd8: 0xc20465c  jal         func_811970
    ctx->pc = 0x1AFFD8u;
    SET_GPR_U32(ctx, 31, 0x1AFFE0u);
    ctx->pc = 0x1AFFDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFD8u;
            // 0x1affdc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811970u;
    {
        auto targetFn = runtime->lookupFunction(0x811970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFFE0u; }
        if (ctx->pc != 0x1AFFE0u) { return; }
    }
    ctx->pc = 0x1AFFE0u;
label_1affe0:
    // 0x1affe0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1AFFE0u;
    {
        const bool branch_taken_0x1affe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1affe0) {
            ctx->pc = 0x1AFFF4u;
            goto label_1afff4;
        }
    }
    ctx->pc = 0x1AFFE8u;
label_1affe8:
    // 0x1affe8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1affe8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1affec: 0xc204450  jal         func_811140
    ctx->pc = 0x1AFFECu;
    SET_GPR_U32(ctx, 31, 0x1AFFF4u);
    ctx->pc = 0x1AFFF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFECu;
            // 0x1afff0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811140u;
    {
        auto targetFn = runtime->lookupFunction(0x811140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFFF4u; }
        if (ctx->pc != 0x1AFFF4u) { return; }
    }
    ctx->pc = 0x1AFFF4u;
label_1afff4:
    // 0x1afff4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1afff4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1afff8:
    // 0x1afff8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1afff8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1afffc: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFFFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFFCu;
            // 0x1b0000: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0004u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
