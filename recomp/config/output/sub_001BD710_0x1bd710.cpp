#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BD710
// Address: 0x1bd710 - 0x1bd7a8
void sub_001BD710_0x1bd710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BD710_0x1bd710");
#endif

    switch (ctx->pc) {
        case 0x1bd730u: goto label_1bd730;
        case 0x1bd73cu: goto label_1bd73c;
        case 0x1bd748u: goto label_1bd748;
        case 0x1bd754u: goto label_1bd754;
        case 0x1bd774u: goto label_1bd774;
        case 0x1bd794u: goto label_1bd794;
        default: break;
    }

    ctx->pc = 0x1bd710u;

    // 0x1bd710: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bd710u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bd714: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bd714u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bd718: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bd718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bd71c: 0x8c235018  lw          $v1, 0x5018($at)
    ctx->pc = 0x1bd71cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20504)));
    // 0x1bd720: 0x460001e  bltz        $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1BD720u;
    {
        const bool branch_taken_0x1bd720 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1BD724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD720u;
            // 0x1bd724: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd720) {
            ctx->pc = 0x1BD79Cu;
            goto label_1bd79c;
        }
    }
    ctx->pc = 0x1BD728u;
    // 0x1bd728: 0xc0401ba  jal         func_1006E8
    ctx->pc = 0x1BD728u;
    SET_GPR_U32(ctx, 31, 0x1BD730u);
    ctx->pc = 0x1BD72Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD728u;
            // 0x1bd72c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1006E8u;
    if (runtime->hasFunction(0x1006E8u)) {
        auto targetFn = runtime->lookupFunction(0x1006E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD730u; }
        if (ctx->pc != 0x1BD730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001006E8_0x1006e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD730u; }
        if (ctx->pc != 0x1BD730u) { return; }
    }
    ctx->pc = 0x1BD730u;
label_1bd730:
    // 0x1bd730: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bd730u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bd734: 0xc04511c  jal         func_114470
    ctx->pc = 0x1BD734u;
    SET_GPR_U32(ctx, 31, 0x1BD73Cu);
    ctx->pc = 0x1BD738u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD734u;
            // 0x1bd738: 0x8c245018  lw          $a0, 0x5018($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20504)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114470u;
    if (runtime->hasFunction(0x114470u)) {
        auto targetFn = runtime->lookupFunction(0x114470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD73Cu; }
        if (ctx->pc != 0x1BD73Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114470_0x114470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD73Cu; }
        if (ctx->pc != 0x1BD73Cu) { return; }
    }
    ctx->pc = 0x1BD73Cu;
label_1bd73c:
    // 0x1bd73c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bd73cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bd740: 0xc04510c  jal         func_114430
    ctx->pc = 0x1BD740u;
    SET_GPR_U32(ctx, 31, 0x1BD748u);
    ctx->pc = 0x1BD744u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD740u;
            // 0x1bd744: 0x8c245018  lw          $a0, 0x5018($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20504)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114430u;
    if (runtime->hasFunction(0x114430u)) {
        auto targetFn = runtime->lookupFunction(0x114430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD748u; }
        if (ctx->pc != 0x1BD748u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114430_0x114430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD748u; }
        if (ctx->pc != 0x1BD748u) { return; }
    }
    ctx->pc = 0x1BD748u;
label_1bd748:
    // 0x1bd748: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bd748u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bd74c: 0xc04518c  jal         func_114630
    ctx->pc = 0x1BD74Cu;
    SET_GPR_U32(ctx, 31, 0x1BD754u);
    ctx->pc = 0x1BD750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD74Cu;
            // 0x1bd750: 0x8c245010  lw          $a0, 0x5010($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20496)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD754u; }
        if (ctx->pc != 0x1BD754u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD754u; }
        if (ctx->pc != 0x1BD754u) { return; }
    }
    ctx->pc = 0x1BD754u;
label_1bd754:
    // 0x1bd754: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd754u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd758: 0x24055003  addiu       $a1, $zero, 0x5003
    ctx->pc = 0x1bd758u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20483));
    // 0x1bd75c: 0x24840420  addiu       $a0, $a0, 0x420
    ctx->pc = 0x1bd75cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1056));
    // 0x1bd760: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd760u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd764: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd764u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd768: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd768u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd76c: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD76Cu;
    SET_GPR_U32(ctx, 31, 0x1BD774u);
    ctx->pc = 0x1BD770u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD76Cu;
            // 0x1bd770: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD774u; }
        if (ctx->pc != 0x1BD774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD774u; }
        if (ctx->pc != 0x1BD774u) { return; }
    }
    ctx->pc = 0x1BD774u;
label_1bd774:
    // 0x1bd774: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd774u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd778: 0x24054402  addiu       $a1, $zero, 0x4402
    ctx->pc = 0x1bd778u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17410));
    // 0x1bd77c: 0x24840418  addiu       $a0, $a0, 0x418
    ctx->pc = 0x1bd77cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1048));
    // 0x1bd780: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd780u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd784: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd784u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd788: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd788u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd78c: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD78Cu;
    SET_GPR_U32(ctx, 31, 0x1BD794u);
    ctx->pc = 0x1BD790u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD78Cu;
            // 0x1bd790: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD794u; }
        if (ctx->pc != 0x1BD794u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD794u; }
        if (ctx->pc != 0x1BD794u) { return; }
    }
    ctx->pc = 0x1BD794u;
label_1bd794:
    // 0x1bd794: 0x440fff7  bltz        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1BD794u;
    {
        const bool branch_taken_0x1bd794 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bd794) {
            ctx->pc = 0x1BD774u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd774;
        }
    }
    ctx->pc = 0x1BD79Cu;
label_1bd79c:
    // 0x1bd79c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bd79cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bd7a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1BD7A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BD7A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD7A0u;
            // 0x1bd7a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD730u: goto label_1bd730;
            case 0x1BD73Cu: goto label_1bd73c;
            case 0x1BD748u: goto label_1bd748;
            case 0x1BD754u: goto label_1bd754;
            case 0x1BD774u: goto label_1bd774;
            case 0x1BD794u: goto label_1bd794;
            case 0x1BD79Cu: goto label_1bd79c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD7A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
