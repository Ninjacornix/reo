#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A6B8
// Address: 0x12a6b8 - 0x12a780
void sub_0012A6B8_0x12a6b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A6B8_0x12a6b8");
#endif

    switch (ctx->pc) {
        case 0x12a6f4u: goto label_12a6f4;
        case 0x12a714u: goto label_12a714;
        case 0x12a730u: goto label_12a730;
        case 0x12a748u: goto label_12a748;
        case 0x12a758u: goto label_12a758;
        case 0x12a768u: goto label_12a768;
        default: break;
    }

    ctx->pc = 0x12a6b8u;

    // 0x12a6b8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12a6b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12a6bc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x12a6bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a6c0: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x12a6c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x12a6c4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x12a6c4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a6c8: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x12a6c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x12a6cc: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x12a6ccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a6d0: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x12a6d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x12a6d4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12a6d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a6d8: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12a6d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12a6dc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x12a6dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a6e0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12A6E0u;
    {
        const bool branch_taken_0x12a6e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12A6E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A6E0u;
            // 0x12a6e4: 0x8c520094  lw          $s2, 0x94($v0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 148)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a6e0) {
            ctx->pc = 0x12A700u;
            goto label_12a700;
        }
    }
    ctx->pc = 0x12A6E8u;
    // 0x12a6e8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12a6e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12a6ec: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x12A6ECu;
    SET_GPR_U32(ctx, 31, 0x12A6F4u);
    ctx->pc = 0x12A6F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A6ECu;
            // 0x12a6f0: 0x2484a340  addiu       $a0, $a0, -0x5CC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943552));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A6F4u; }
        if (ctx->pc != 0x12A6F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A6F4u; }
        if (ctx->pc != 0x12A6F4u) { return; }
    }
    ctx->pc = 0x12A6F4u;
label_12a6f4:
    // 0x12a6f4: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x12A6F4u;
    {
        const bool branch_taken_0x12a6f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12A6F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A6F4u;
            // 0x12a6f8: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a6f4) {
            ctx->pc = 0x12A76Cu;
            goto label_12a76c;
        }
    }
    ctx->pc = 0x12A6FCu;
    // 0x12a6fc: 0x0  nop
    ctx->pc = 0x12a6fcu;
    // NOP
label_12a700:
    // 0x12a700: 0x8c4600b0  lw          $a2, 0xB0($v0)
    ctx->pc = 0x12a700u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 176)));
    // 0x12a704: 0x27a70010  addiu       $a3, $sp, 0x10
    ctx->pc = 0x12a704u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x12a708: 0x27a80014  addiu       $t0, $sp, 0x14
    ctx->pc = 0x12a708u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    // 0x12a70c: 0xc04a786  jal         func_129E18
    ctx->pc = 0x12A70Cu;
    SET_GPR_U32(ctx, 31, 0x12A714u);
    ctx->pc = 0x12A710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A70Cu;
            // 0x12a710: 0x27a90018  addiu       $t1, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129E18u;
    if (runtime->hasFunction(0x129E18u)) {
        auto targetFn = runtime->lookupFunction(0x129E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A714u; }
        if (ctx->pc != 0x12A714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129E18_0x129e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A714u; }
        if (ctx->pc != 0x12A714u) { return; }
    }
    ctx->pc = 0x12A714u;
label_12a714:
    // 0x12a714: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12a714u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a718: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x12a718u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a71c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x12a71cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a720: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x12A720u;
    {
        const bool branch_taken_0x12a720 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12A724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A720u;
            // 0x12a724: 0x24070010  addiu       $a3, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a720) {
            ctx->pc = 0x12A750u;
            goto label_12a750;
        }
    }
    ctx->pc = 0x12A728u;
    // 0x12a728: 0xc04a7dc  jal         func_129F70
    ctx->pc = 0x12A728u;
    SET_GPR_U32(ctx, 31, 0x12A730u);
    ctx->pc = 0x129F70u;
    if (runtime->hasFunction(0x129F70u)) {
        auto targetFn = runtime->lookupFunction(0x129F70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A730u; }
        if (ctx->pc != 0x12A730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129F70_0x129f70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A730u; }
        if (ctx->pc != 0x12A730u) { return; }
    }
    ctx->pc = 0x12A730u;
label_12a730:
    // 0x12a730: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x12a730u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a734: 0x8fa60010  lw          $a2, 0x10($sp)
    ctx->pc = 0x12a734u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12a738: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12a738u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a73c: 0x8fa70014  lw          $a3, 0x14($sp)
    ctx->pc = 0x12a73cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x12a740: 0xc04f34e  jal         func_13CD38
    ctx->pc = 0x12A740u;
    SET_GPR_U32(ctx, 31, 0x12A748u);
    ctx->pc = 0x12A744u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A740u;
            // 0x12a744: 0x8fa80018  lw          $t0, 0x18($sp) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CD38u;
    if (runtime->hasFunction(0x13CD38u)) {
        auto targetFn = runtime->lookupFunction(0x13CD38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A748u; }
        if (ctx->pc != 0x12A748u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CD38_0x13cd38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A748u; }
        if (ctx->pc != 0x12A748u) { return; }
    }
    ctx->pc = 0x12A748u;
label_12a748:
    // 0x12a748: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x12A748u;
    {
        const bool branch_taken_0x12a748 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12A74Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A748u;
            // 0x12a74c: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a748) {
            ctx->pc = 0x12A76Cu;
            goto label_12a76c;
        }
    }
    ctx->pc = 0x12A750u;
label_12a750:
    // 0x12a750: 0xc04a0a8  jal         func_1282A0
    ctx->pc = 0x12A750u;
    SET_GPR_U32(ctx, 31, 0x12A758u);
    ctx->pc = 0x1282A0u;
    if (runtime->hasFunction(0x1282A0u)) {
        auto targetFn = runtime->lookupFunction(0x1282A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A758u; }
        if (ctx->pc != 0x12A758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001282A0_0x1282a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A758u; }
        if (ctx->pc != 0x12A758u) { return; }
    }
    ctx->pc = 0x12A758u;
label_12a758:
    // 0x12a758: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12a758u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12a75c: 0x2484a370  addiu       $a0, $a0, -0x5C90
    ctx->pc = 0x12a75cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943600));
    // 0x12a760: 0xc04a04a  jal         func_128128
    ctx->pc = 0x12A760u;
    SET_GPR_U32(ctx, 31, 0x12A768u);
    ctx->pc = 0x12A764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A760u;
            // 0x12a764: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128128u;
    if (runtime->hasFunction(0x128128u)) {
        auto targetFn = runtime->lookupFunction(0x128128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A768u; }
        if (ctx->pc != 0x12A768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128128_0x128128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A768u; }
        if (ctx->pc != 0x12A768u) { return; }
    }
    ctx->pc = 0x12A768u;
label_12a768:
    // 0x12a768: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x12a768u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_12a76c:
    // 0x12a76c: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x12a76cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12a770: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x12a770u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12a774: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12a774u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12a778: 0x3e00008  jr          $ra
    ctx->pc = 0x12A778u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A77Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A778u;
            // 0x12a77c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A6F4u: goto label_12a6f4;
            case 0x12A700u: goto label_12a700;
            case 0x12A714u: goto label_12a714;
            case 0x12A730u: goto label_12a730;
            case 0x12A748u: goto label_12a748;
            case 0x12A750u: goto label_12a750;
            case 0x12A758u: goto label_12a758;
            case 0x12A768u: goto label_12a768;
            case 0x12A76Cu: goto label_12a76c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A780u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
