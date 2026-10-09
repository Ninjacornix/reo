#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE9F0
// Address: 0x1ae9f0 - 0x1aea64
void sub_001AE9F0_0x1ae9f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE9F0_0x1ae9f0");
#endif

    switch (ctx->pc) {
        case 0x1aea10u: goto label_1aea10;
        case 0x1aea38u: goto label_1aea38;
        case 0x1aea50u: goto label_1aea50;
        default: break;
    }

    ctx->pc = 0x1ae9f0u;

    // 0x1ae9f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1ae9f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ae9f4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ae9f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ae9f8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ae9f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ae9fc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae9fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aea00: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1aea00u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aea04: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1aea04u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aea08: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AEA08u;
    SET_GPR_U32(ctx, 31, 0x1AEA10u);
    ctx->pc = 0x1AEA0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA08u;
            // 0x1aea0c: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA10u; }
        if (ctx->pc != 0x1AEA10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA10u; }
        if (ctx->pc != 0x1AEA10u) { return; }
    }
    ctx->pc = 0x1AEA10u;
label_1aea10:
    // 0x1aea10: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1AEA10u;
    {
        const bool branch_taken_0x1aea10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA10u;
            // 0x1aea14: 0x3c03002c  lui         $v1, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aea10) {
            ctx->pc = 0x1AEA50u;
            goto label_1aea50;
        }
    }
    ctx->pc = 0x1AEA18u;
    // 0x1aea18: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x1aea18u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1aea1c: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1aea1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1aea20: 0x648021  addu        $s0, $v1, $a0
    ctx->pc = 0x1aea20u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1aea24: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1aea24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aea28: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AEA28u;
    {
        const bool branch_taken_0x1aea28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AEA2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA28u;
            // 0x1aea2c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aea28) {
            ctx->pc = 0x1AEA50u;
            goto label_1aea50;
        }
    }
    ctx->pc = 0x1AEA30u;
    // 0x1aea30: 0xc06acbc  jal         func_1AB2F0
    ctx->pc = 0x1AEA30u;
    SET_GPR_U32(ctx, 31, 0x1AEA38u);
    ctx->pc = 0x1AB2F0u;
    if (runtime->hasFunction(0x1AB2F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA38u; }
        if (ctx->pc != 0x1AEA38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB2F0_0x1ab2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA38u; }
        if (ctx->pc != 0x1AEA38u) { return; }
    }
    ctx->pc = 0x1AEA38u;
label_1aea38:
    // 0x1aea38: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1aea38u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aea3c: 0x4c00004  bltz        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AEA3Cu;
    {
        const bool branch_taken_0x1aea3c = (GPR_S64(ctx, 6) < 0);
        if (branch_taken_0x1aea3c) {
            ctx->pc = 0x1AEA50u;
            goto label_1aea50;
        }
    }
    ctx->pc = 0x1AEA44u;
    // 0x1aea44: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1aea44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aea48: 0xc04a9ae  jal         func_12A6B8
    ctx->pc = 0x1AEA48u;
    SET_GPR_U32(ctx, 31, 0x1AEA50u);
    ctx->pc = 0x1AEA4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA48u;
            // 0x1aea4c: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A6B8u;
    if (runtime->hasFunction(0x12A6B8u)) {
        auto targetFn = runtime->lookupFunction(0x12A6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA50u; }
        if (ctx->pc != 0x1AEA50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A6B8_0x12a6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA50u; }
        if (ctx->pc != 0x1AEA50u) { return; }
    }
    ctx->pc = 0x1AEA50u;
label_1aea50:
    // 0x1aea50: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1aea50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1aea54: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1aea54u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aea58: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aea58u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aea5c: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEA5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AEA60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA5Cu;
            // 0x1aea60: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AEA10u: goto label_1aea10;
            case 0x1AEA38u: goto label_1aea38;
            case 0x1AEA50u: goto label_1aea50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEA64u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
