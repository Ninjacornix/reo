#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CB9A0
// Address: 0x1cb9a0 - 0x1cba4c
void sub_001CB9A0_0x1cb9a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CB9A0_0x1cb9a0");
#endif

    switch (ctx->pc) {
        case 0x1cb9acu: goto label_1cb9ac;
        case 0x1cb9c4u: goto label_1cb9c4;
        case 0x1cb9d8u: goto label_1cb9d8;
        case 0x1cb9e4u: goto label_1cb9e4;
        case 0x1cba08u: goto label_1cba08;
        case 0x1cba20u: goto label_1cba20;
        case 0x1cba38u: goto label_1cba38;
        case 0x1cba40u: goto label_1cba40;
        default: break;
    }

    ctx->pc = 0x1cb9a0u;

    // 0x1cb9a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cb9a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cb9a4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1CB9A4u;
    {
        const bool branch_taken_0x1cb9a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB9A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB9A4u;
            // 0x1cb9a8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb9a4) {
            ctx->pc = 0x1CB9E4u;
            goto label_1cb9e4;
        }
    }
    ctx->pc = 0x1CB9ACu;
label_1cb9ac:
    // 0x1cb9ac: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1cb9acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cb9b0: 0x8c236008  lw          $v1, 0x6008($at)
    ctx->pc = 0x1cb9b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24584)));
    // 0x1cb9b4: 0x10620011  beq         $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1CB9B4u;
    {
        const bool branch_taken_0x1cb9b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb9b4) {
            ctx->pc = 0x1CB9FCu;
            goto label_1cb9fc;
        }
    }
    ctx->pc = 0x1CB9BCu;
    // 0x1cb9bc: 0xc073000  jal         func_1CC000
    ctx->pc = 0x1CB9BCu;
    SET_GPR_U32(ctx, 31, 0x1CB9C4u);
    ctx->pc = 0x1CC000u;
    if (runtime->hasFunction(0x1CC000u)) {
        auto targetFn = runtime->lookupFunction(0x1CC000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9C4u; }
        if (ctx->pc != 0x1CB9C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC000_0x1cc000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9C4u; }
        if (ctx->pc != 0x1CB9C4u) { return; }
    }
    ctx->pc = 0x1CB9C4u;
label_1cb9c4:
    // 0x1cb9c4: 0x3c05001d  lui         $a1, 0x1D
    ctx->pc = 0x1cb9c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)29 << 16));
    // 0x1cb9c8: 0x24040100  addiu       $a0, $zero, 0x100
    ctx->pc = 0x1cb9c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1cb9cc: 0x24a5b970  addiu       $a1, $a1, -0x4690
    ctx->pc = 0x1cb9ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294949232));
    // 0x1cb9d0: 0xc0450e8  jal         func_1143A0
    ctx->pc = 0x1CB9D0u;
    SET_GPR_U32(ctx, 31, 0x1CB9D8u);
    ctx->pc = 0x1CB9D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB9D0u;
            // 0x1cb9d4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1143A0u;
    if (runtime->hasFunction(0x1143A0u)) {
        auto targetFn = runtime->lookupFunction(0x1143A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9D8u; }
        if (ctx->pc != 0x1CB9D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001143A0_0x1143a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9D8u; }
        if (ctx->pc != 0x1CB9D8u) { return; }
    }
    ctx->pc = 0x1CB9D8u;
label_1cb9d8:
    // 0x1cb9d8: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb9d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb9dc: 0xc045198  jal         func_114660
    ctx->pc = 0x1CB9DCu;
    SET_GPR_U32(ctx, 31, 0x1CB9E4u);
    ctx->pc = 0x1CB9E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB9DCu;
            // 0x1cb9e0: 0x8c246008  lw          $a0, 0x6008($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24584)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9E4u; }
        if (ctx->pc != 0x1CB9E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB9E4u; }
        if (ctx->pc != 0x1CB9E4u) { return; }
    }
    ctx->pc = 0x1CB9E4u;
label_1cb9e4:
    // 0x1cb9e4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb9e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb9e8: 0x8c22da08  lw          $v0, -0x25F8($at)
    ctx->pc = 0x1cb9e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957576)));
    // 0x1cb9ec: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1cb9ecu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1cb9f0: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1cb9f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1cb9f4: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1CB9F4u;
    {
        const bool branch_taken_0x1cb9f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CB9F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB9F4u;
            // 0x1cb9f8: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb9f4) {
            ctx->pc = 0x1CB9ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cb9ac;
        }
    }
    ctx->pc = 0x1CB9FCu;
label_1cb9fc:
    // 0x1cb9fc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb9fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cba00: 0xc04518c  jal         func_114630
    ctx->pc = 0x1CBA00u;
    SET_GPR_U32(ctx, 31, 0x1CBA08u);
    ctx->pc = 0x1CBA04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBA00u;
            // 0x1cba04: 0x8c246008  lw          $a0, 0x6008($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24584)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA08u; }
        if (ctx->pc != 0x1CBA08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA08u; }
        if (ctx->pc != 0x1CBA08u) { return; }
    }
    ctx->pc = 0x1CBA08u;
label_1cba08:
    // 0x1cba08: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cba08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cba0c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1cba0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cba10: 0x8c245fe8  lw          $a0, 0x5FE8($at)
    ctx->pc = 0x1cba10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24552)));
    // 0x1cba14: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cba14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cba18: 0xc04518c  jal         func_114630
    ctx->pc = 0x1CBA18u;
    SET_GPR_U32(ctx, 31, 0x1CBA20u);
    ctx->pc = 0x1CBA1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBA18u;
            // 0x1cba1c: 0xac226008  sw          $v0, 0x6008($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 24584), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA20u; }
        if (ctx->pc != 0x1CBA20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA20u; }
        if (ctx->pc != 0x1CBA20u) { return; }
    }
    ctx->pc = 0x1CBA20u;
label_1cba20:
    // 0x1cba20: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cba20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cba24: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1cba24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cba28: 0x8c246000  lw          $a0, 0x6000($at)
    ctx->pc = 0x1cba28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24576)));
    // 0x1cba2c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cba2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cba30: 0xc045190  jal         func_114640
    ctx->pc = 0x1CBA30u;
    SET_GPR_U32(ctx, 31, 0x1CBA38u);
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA38u; }
        if (ctx->pc != 0x1CBA38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA38u; }
        if (ctx->pc != 0x1CBA38u) { return; }
    }
    ctx->pc = 0x1CBA38u;
label_1cba38:
    // 0x1cba38: 0xc045118  jal         func_114460
    ctx->pc = 0x1CBA38u;
    SET_GPR_U32(ctx, 31, 0x1CBA40u);
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA40u; }
        if (ctx->pc != 0x1CBA40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114460_0x114460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBA40u; }
        if (ctx->pc != 0x1CBA40u) { return; }
    }
    ctx->pc = 0x1CBA40u;
label_1cba40:
    // 0x1cba40: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cba40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cba44: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBA44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBA48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBA44u;
            // 0x1cba48: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB9ACu: goto label_1cb9ac;
            case 0x1CB9C4u: goto label_1cb9c4;
            case 0x1CB9D8u: goto label_1cb9d8;
            case 0x1CB9E4u: goto label_1cb9e4;
            case 0x1CB9FCu: goto label_1cb9fc;
            case 0x1CBA08u: goto label_1cba08;
            case 0x1CBA20u: goto label_1cba20;
            case 0x1CBA38u: goto label_1cba38;
            case 0x1CBA40u: goto label_1cba40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBA4Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
