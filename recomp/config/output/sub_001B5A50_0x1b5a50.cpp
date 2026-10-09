#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B5A50
// Address: 0x1b5a50 - 0x1b5ae0
void sub_001B5A50_0x1b5a50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B5A50_0x1b5a50");
#endif

    switch (ctx->pc) {
        case 0x1b5a98u: goto label_1b5a98;
        case 0x1b5aa0u: goto label_1b5aa0;
        case 0x1b5ac0u: goto label_1b5ac0;
        case 0x1b5ad0u: goto label_1b5ad0;
        default: break;
    }

    ctx->pc = 0x1b5a50u;

    // 0x1b5a50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b5a50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b5a54: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5a54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5a58: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b5a58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b5a5c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b5a5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b5a60: 0x8c22ab78  lw          $v0, -0x5488($at)
    ctx->pc = 0x1b5a60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945656)));
    // 0x1b5a64: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1b5a64u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1b5a68: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B5A68u;
    {
        const bool branch_taken_0x1b5a68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5A6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5A68u;
            // 0x1b5a6c: 0x2610aa40  addiu       $s0, $s0, -0x55C0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5a68) {
            ctx->pc = 0x1B5A7Cu;
            goto label_1b5a7c;
        }
    }
    ctx->pc = 0x1B5A70u;
    // 0x1b5a70: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b5a70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b5a74: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5a74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5a78: 0xac22ab78  sw          $v0, -0x5488($at)
    ctx->pc = 0x1b5a78u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945656), GPR_U32(ctx, 2));
label_1b5a7c:
    // 0x1b5a7c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b5a7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b5a80: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b5a80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b5a84: 0x902343c3  lbu         $v1, 0x43C3($at)
    ctx->pc = 0x1b5a84u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17347)));
    // 0x1b5a88: 0x1062000f  beq         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1B5A88u;
    {
        const bool branch_taken_0x1b5a88 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B5A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5A88u;
            // 0x1b5a8c: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5a88) {
            ctx->pc = 0x1B5AC8u;
            goto label_1b5ac8;
        }
    }
    ctx->pc = 0x1B5A90u;
    // 0x1b5a90: 0xc06d59c  jal         func_1B5670
    ctx->pc = 0x1B5A90u;
    SET_GPR_U32(ctx, 31, 0x1B5A98u);
    ctx->pc = 0x1B5670u;
    if (runtime->hasFunction(0x1B5670u)) {
        auto targetFn = runtime->lookupFunction(0x1B5670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5A98u; }
        if (ctx->pc != 0x1B5A98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5670_0x1b5670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5A98u; }
        if (ctx->pc != 0x1B5A98u) { return; }
    }
    ctx->pc = 0x1B5A98u;
label_1b5a98:
    // 0x1b5a98: 0xc1b7a00  jal         func_6DE800
    ctx->pc = 0x1B5A98u;
    SET_GPR_U32(ctx, 31, 0x1B5AA0u);
    ctx->pc = 0x6DE800u;
    {
        auto targetFn = runtime->lookupFunction(0x6DE800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5AA0u; }
        if (ctx->pc != 0x1B5AA0u) { return; }
    }
    ctx->pc = 0x1B5AA0u;
label_1b5aa0:
    // 0x1b5aa0: 0x8e05004c  lw          $a1, 0x4C($s0)
    ctx->pc = 0x1b5aa0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x1b5aa4: 0x3c03f000  lui         $v1, 0xF000
    ctx->pc = 0x1b5aa4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)61440 << 16));
    // 0x1b5aa8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b5aa8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5aac: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1b5aacu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1b5ab0: 0xaca00004  sw          $zero, 0x4($a1)
    ctx->pc = 0x1b5ab0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 0));
    // 0x1b5ab4: 0xaca00008  sw          $zero, 0x8($a1)
    ctx->pc = 0x1b5ab4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 0));
    // 0x1b5ab8: 0xc06d59c  jal         func_1B5670
    ctx->pc = 0x1B5AB8u;
    SET_GPR_U32(ctx, 31, 0x1B5AC0u);
    ctx->pc = 0x1B5ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5AB8u;
            // 0x1b5abc: 0xaca0000c  sw          $zero, 0xC($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5670u;
    if (runtime->hasFunction(0x1B5670u)) {
        auto targetFn = runtime->lookupFunction(0x1B5670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5AC0u; }
        if (ctx->pc != 0x1B5AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5670_0x1b5670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5AC0u; }
        if (ctx->pc != 0x1B5AC0u) { return; }
    }
    ctx->pc = 0x1B5AC0u;
label_1b5ac0:
    // 0x1b5ac0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B5AC0u;
    {
        const bool branch_taken_0x1b5ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5AC0u;
            // 0x1b5ac4: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5ac0) {
            ctx->pc = 0x1B5AD4u;
            goto label_1b5ad4;
        }
    }
    ctx->pc = 0x1B5AC8u;
label_1b5ac8:
    // 0x1b5ac8: 0xc1b7a00  jal         func_6DE800
    ctx->pc = 0x1B5AC8u;
    SET_GPR_U32(ctx, 31, 0x1B5AD0u);
    ctx->pc = 0x6DE800u;
    {
        auto targetFn = runtime->lookupFunction(0x6DE800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5AD0u; }
        if (ctx->pc != 0x1B5AD0u) { return; }
    }
    ctx->pc = 0x1B5AD0u;
label_1b5ad0:
    // 0x1b5ad0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b5ad0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b5ad4:
    // 0x1b5ad4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b5ad4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b5ad8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5AD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B5ADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5AD8u;
            // 0x1b5adc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B5A7Cu: goto label_1b5a7c;
            case 0x1B5A98u: goto label_1b5a98;
            case 0x1B5AA0u: goto label_1b5aa0;
            case 0x1B5AC0u: goto label_1b5ac0;
            case 0x1B5AC8u: goto label_1b5ac8;
            case 0x1B5AD0u: goto label_1b5ad0;
            case 0x1B5AD4u: goto label_1b5ad4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B5AE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
