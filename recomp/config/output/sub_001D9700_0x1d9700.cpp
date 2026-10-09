#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9700
// Address: 0x1d9700 - 0x1d97d4
void sub_001D9700_0x1d9700(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9700_0x1d9700");
#endif

    switch (ctx->pc) {
        case 0x1d9738u: goto label_1d9738;
        case 0x1d976cu: goto label_1d976c;
        case 0x1d9780u: goto label_1d9780;
        case 0x1d97a0u: goto label_1d97a0;
        case 0x1d97b8u: goto label_1d97b8;
        default: break;
    }

    ctx->pc = 0x1d9700u;

    // 0x1d9700: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d9700u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d9704: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d9704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d9708: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d9708u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d970c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d970cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d9710: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d9710u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9714: 0x6000004  bltz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9714u;
    {
        const bool branch_taken_0x1d9714 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x1D9718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9714u;
            // 0x1d9718: 0x2a020003  slti        $v0, $s0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9714) {
            ctx->pc = 0x1D9728u;
            goto label_1d9728;
        }
    }
    ctx->pc = 0x1D971Cu;
    // 0x1d971c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D971Cu;
    {
        const bool branch_taken_0x1d971c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d971c) {
            ctx->pc = 0x1D9730u;
            goto label_1d9730;
        }
    }
    ctx->pc = 0x1D9724u;
    // 0x1d9724: 0x0  nop
    ctx->pc = 0x1d9724u;
    // NOP
label_1d9728:
    // 0x1d9728: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1D9728u;
    {
        const bool branch_taken_0x1d9728 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D972Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9728u;
            // 0x1d972c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9728) {
            ctx->pc = 0x1D97C0u;
            goto label_1d97c0;
        }
    }
    ctx->pc = 0x1D9730u;
label_1d9730:
    // 0x1d9730: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9730u;
    SET_GPR_U32(ctx, 31, 0x1D9738u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9738u; }
        if (ctx->pc != 0x1D9738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9738u; }
        if (ctx->pc != 0x1D9738u) { return; }
    }
    ctx->pc = 0x1D9738u;
label_1d9738:
    // 0x1d9738: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9738u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d973c: 0x108080  sll         $s0, $s0, 2
    ctx->pc = 0x1d973cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1d9740: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1d9740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1d9744: 0x508821  addu        $s1, $v0, $s0
    ctx->pc = 0x1d9744u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d9748: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1d9748u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d974c: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x1d974cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1d9750: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D9750u;
    {
        const bool branch_taken_0x1d9750 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D9754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9750u;
            // 0x1d9754: 0x3c020035  lui         $v0, 0x35 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9750) {
            ctx->pc = 0x1D9778u;
            goto label_1d9778;
        }
    }
    ctx->pc = 0x1D9758u;
    // 0x1d9758: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d9758u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d975c: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1d975cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1d9760: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1d9760u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d9764: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9764u;
    SET_GPR_U32(ctx, 31, 0x1D976Cu);
    ctx->pc = 0x1D9768u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9764u;
            // 0x1d9768: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D976Cu; }
        if (ctx->pc != 0x1D976Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D976Cu; }
        if (ctx->pc != 0x1D976Cu) { return; }
    }
    ctx->pc = 0x1D976Cu;
label_1d976c:
    // 0x1d976c: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1D976Cu;
    {
        const bool branch_taken_0x1d976c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D976Cu;
            // 0x1d9770: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d976c) {
            ctx->pc = 0x1D97C0u;
            goto label_1d97c0;
        }
    }
    ctx->pc = 0x1D9774u;
    // 0x1d9774: 0x0  nop
    ctx->pc = 0x1d9774u;
    // NOP
label_1d9778:
    // 0x1d9778: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9778u;
    SET_GPR_U32(ctx, 31, 0x1D9780u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9780u; }
        if (ctx->pc != 0x1D9780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9780u; }
        if (ctx->pc != 0x1D9780u) { return; }
    }
    ctx->pc = 0x1D9780u;
label_1d9780:
    // 0x1d9780: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1d9780u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d9784: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9784u;
    {
        const bool branch_taken_0x1d9784 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1D9788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9784u;
            // 0x1d9788: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9784) {
            ctx->pc = 0x1D9798u;
            goto label_1d9798;
        }
    }
    ctx->pc = 0x1D978Cu;
    // 0x1d978c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1D978Cu;
    {
        const bool branch_taken_0x1d978c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d978c) {
            ctx->pc = 0x1D97C0u;
            goto label_1d97c0;
        }
    }
    ctx->pc = 0x1D9794u;
    // 0x1d9794: 0x0  nop
    ctx->pc = 0x1d9794u;
    // NOP
label_1d9798:
    // 0x1d9798: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9798u;
    SET_GPR_U32(ctx, 31, 0x1D97A0u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D97A0u; }
        if (ctx->pc != 0x1D97A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D97A0u; }
        if (ctx->pc != 0x1D97A0u) { return; }
    }
    ctx->pc = 0x1D97A0u;
label_1d97a0:
    // 0x1d97a0: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d97a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d97a4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d97a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d97a8: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1d97a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1d97ac: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1d97acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d97b0: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D97B0u;
    SET_GPR_U32(ctx, 31, 0x1D97B8u);
    ctx->pc = 0x1D97B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D97B0u;
            // 0x1d97b4: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D97B8u; }
        if (ctx->pc != 0x1D97B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D97B8u; }
        if (ctx->pc != 0x1D97B8u) { return; }
    }
    ctx->pc = 0x1D97B8u;
label_1d97b8:
    // 0x1d97b8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d97b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d97bc: 0x0  nop
    ctx->pc = 0x1d97bcu;
    // NOP
label_1d97c0:
    // 0x1d97c0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d97c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d97c4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d97c4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d97c8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d97c8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d97cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D97CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D97D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D97CCu;
            // 0x1d97d0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9728u: goto label_1d9728;
            case 0x1D9730u: goto label_1d9730;
            case 0x1D9738u: goto label_1d9738;
            case 0x1D976Cu: goto label_1d976c;
            case 0x1D9778u: goto label_1d9778;
            case 0x1D9780u: goto label_1d9780;
            case 0x1D9798u: goto label_1d9798;
            case 0x1D97A0u: goto label_1d97a0;
            case 0x1D97B8u: goto label_1d97b8;
            case 0x1D97C0u: goto label_1d97c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D97D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
