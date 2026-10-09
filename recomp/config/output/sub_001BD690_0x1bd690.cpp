#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BD690
// Address: 0x1bd690 - 0x1bd980
void sub_001BD690_0x1bd690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BD690_0x1bd690");
#endif

    switch (ctx->pc) {
        case 0x1bd730u: goto label_1bd730;
        case 0x1bd73cu: goto label_1bd73c;
        case 0x1bd748u: goto label_1bd748;
        case 0x1bd754u: goto label_1bd754;
        case 0x1bd774u: goto label_1bd774;
        case 0x1bd794u: goto label_1bd794;
        case 0x1bd7d4u: goto label_1bd7d4;
        case 0x1bd804u: goto label_1bd804;
        case 0x1bd958u: goto label_1bd958;
        default: break;
    }

    ctx->pc = 0x1bd690u;

    // 0x1bd690: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bd690u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bd694: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1bd694u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1bd698: 0x8c245008  lw          $a0, 0x5008($at)
    ctx->pc = 0x1bd698u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20488)));
    // 0x1bd69c: 0x1082000b  beq         $a0, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1BD69Cu;
    {
        const bool branch_taken_0x1bd69c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BD6A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD69Cu;
            // 0x1bd6a0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd69c) {
            ctx->pc = 0x1BD6CCu;
            goto label_1bd6cc;
        }
    }
    ctx->pc = 0x1BD6A4u;
    // 0x1bd6a4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bd6a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bd6a8: 0x10830008  beq         $a0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1BD6A8u;
    {
        const bool branch_taken_0x1bd6a8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1bd6a8) {
            ctx->pc = 0x1BD6CCu;
            goto label_1bd6cc;
        }
    }
    ctx->pc = 0x1BD6B0u;
    // 0x1bd6b0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bd6b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bd6b4: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD6B4u;
    {
        const bool branch_taken_0x1bd6b4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BD6B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD6B4u;
            // 0x1bd6b8: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd6b4) {
            ctx->pc = 0x1BD6C4u;
            goto label_1bd6c4;
        }
    }
    ctx->pc = 0x1BD6BCu;
    // 0x1bd6bc: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BD6BCu;
    {
        const bool branch_taken_0x1bd6bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD6C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD6BCu;
            // 0x1bd6c0: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd6bc) {
            ctx->pc = 0x1BD6D4u;
            goto label_1bd6d4;
        }
    }
    ctx->pc = 0x1BD6C4u;
label_1bd6c4:
    // 0x1bd6c4: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1BD6C4u;
    {
        const bool branch_taken_0x1bd6c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd6c4) {
            ctx->pc = 0x1BD6FCu;
            goto label_1bd6fc;
        }
    }
    ctx->pc = 0x1BD6CCu;
label_1bd6cc:
    // 0x1bd6cc: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1BD6CCu;
    {
        const bool branch_taken_0x1bd6cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd6cc) {
            ctx->pc = 0x1BD6FCu;
            goto label_1bd6fc;
        }
    }
    ctx->pc = 0x1BD6D4u;
label_1bd6d4:
    // 0x1bd6d4: 0x8c2244e0  lw          $v0, 0x44E0($at)
    ctx->pc = 0x1bd6d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17632)));
    // 0x1bd6d8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BD6D8u;
    {
        const bool branch_taken_0x1bd6d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd6d8) {
            ctx->pc = 0x1BD6F8u;
            goto label_1bd6f8;
        }
    }
    ctx->pc = 0x1BD6E0u;
    // 0x1bd6e0: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD6E0u;
    {
        const bool branch_taken_0x1bd6e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1bd6e0) {
            ctx->pc = 0x1BD6F0u;
            goto label_1bd6f0;
        }
    }
    ctx->pc = 0x1BD6E8u;
    // 0x1bd6e8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1BD6E8u;
    {
        const bool branch_taken_0x1bd6e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD6ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD6E8u;
            // 0x1bd6ec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd6e8) {
            ctx->pc = 0x1BD6FCu;
            goto label_1bd6fc;
        }
    }
    ctx->pc = 0x1BD6F0u;
label_1bd6f0:
    // 0x1bd6f0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1BD6F0u;
    {
        const bool branch_taken_0x1bd6f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD6F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD6F0u;
            // 0x1bd6f4: 0x2402fffa  addiu       $v0, $zero, -0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967290));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd6f0) {
            ctx->pc = 0x1BD6FCu;
            goto label_1bd6fc;
        }
    }
    ctx->pc = 0x1BD6F8u;
label_1bd6f8:
    // 0x1bd6f8: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x1bd6f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
label_1bd6fc:
    // 0x1bd6fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1BD6FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD6C4u: goto label_1bd6c4;
            case 0x1BD6CCu: goto label_1bd6cc;
            case 0x1BD6D4u: goto label_1bd6d4;
            case 0x1BD6F0u: goto label_1bd6f0;
            case 0x1BD6F8u: goto label_1bd6f8;
            case 0x1BD6FCu: goto label_1bd6fc;
            case 0x1BD730u: goto label_1bd730;
            case 0x1BD73Cu: goto label_1bd73c;
            case 0x1BD748u: goto label_1bd748;
            case 0x1BD754u: goto label_1bd754;
            case 0x1BD774u: goto label_1bd774;
            case 0x1BD794u: goto label_1bd794;
            case 0x1BD79Cu: goto label_1bd79c;
            case 0x1BD7D4u: goto label_1bd7d4;
            case 0x1BD804u: goto label_1bd804;
            case 0x1BD824u: goto label_1bd824;
            case 0x1BD864u: goto label_1bd864;
            case 0x1BD874u: goto label_1bd874;
            case 0x1BD894u: goto label_1bd894;
            case 0x1BD8B4u: goto label_1bd8b4;
            case 0x1BD8D4u: goto label_1bd8d4;
            case 0x1BD8F4u: goto label_1bd8f4;
            case 0x1BD938u: goto label_1bd938;
            case 0x1BD958u: goto label_1bd958;
            case 0x1BD964u: goto label_1bd964;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD704u;
    // 0x1bd704: 0x0  nop
    ctx->pc = 0x1bd704u;
    // NOP
    // 0x1bd708: 0x0  nop
    ctx->pc = 0x1bd708u;
    // NOP
    // 0x1bd70c: 0x0  nop
    ctx->pc = 0x1bd70cu;
    // NOP
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
            case 0x1BD6C4u: goto label_1bd6c4;
            case 0x1BD6CCu: goto label_1bd6cc;
            case 0x1BD6D4u: goto label_1bd6d4;
            case 0x1BD6F0u: goto label_1bd6f0;
            case 0x1BD6F8u: goto label_1bd6f8;
            case 0x1BD6FCu: goto label_1bd6fc;
            case 0x1BD730u: goto label_1bd730;
            case 0x1BD73Cu: goto label_1bd73c;
            case 0x1BD748u: goto label_1bd748;
            case 0x1BD754u: goto label_1bd754;
            case 0x1BD774u: goto label_1bd774;
            case 0x1BD794u: goto label_1bd794;
            case 0x1BD79Cu: goto label_1bd79c;
            case 0x1BD7D4u: goto label_1bd7d4;
            case 0x1BD804u: goto label_1bd804;
            case 0x1BD824u: goto label_1bd824;
            case 0x1BD864u: goto label_1bd864;
            case 0x1BD874u: goto label_1bd874;
            case 0x1BD894u: goto label_1bd894;
            case 0x1BD8B4u: goto label_1bd8b4;
            case 0x1BD8D4u: goto label_1bd8d4;
            case 0x1BD8F4u: goto label_1bd8f4;
            case 0x1BD938u: goto label_1bd938;
            case 0x1BD958u: goto label_1bd958;
            case 0x1BD964u: goto label_1bd964;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD7A8u;
    // 0x1bd7a8: 0x0  nop
    ctx->pc = 0x1bd7a8u;
    // NOP
    // 0x1bd7ac: 0x0  nop
    ctx->pc = 0x1bd7acu;
    // NOP
    // 0x1bd7b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bd7b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bd7b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd7b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd7b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bd7b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bd7bc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bd7bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd7c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bd7c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bd7c4: 0x24060044  addiu       $a2, $zero, 0x44
    ctx->pc = 0x1bd7c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
    // 0x1bd7c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1bd7c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd7cc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1BD7CCu;
    SET_GPR_U32(ctx, 31, 0x1BD7D4u);
    ctx->pc = 0x1BD7D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD7CCu;
            // 0x1bd7d0: 0xac3044f0  sw          $s0, 0x44F0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17648), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD7D4u; }
        if (ctx->pc != 0x1BD7D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD7D4u; }
        if (ctx->pc != 0x1BD7D4u) { return; }
    }
    ctx->pc = 0x1BD7D4u;
label_1bd7d4:
    // 0x1bd7d4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bd7d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bd7d8: 0x26030100  addiu       $v1, $s0, 0x100
    ctx->pc = 0x1bd7d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
    // 0x1bd7dc: 0xae040008  sw          $a0, 0x8($s0)
    ctx->pc = 0x1bd7dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 4));
    // 0x1bd7e0: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1bd7e0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1bd7e4: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x1bd7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
    // 0x1bd7e8: 0x24844f30  addiu       $a0, $a0, 0x4F30
    ctx->pc = 0x1bd7e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20272));
    // 0x1bd7ec: 0x3c030002  lui         $v1, 0x2
    ctx->pc = 0x1bd7ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)2 << 16));
    // 0x1bd7f0: 0xae040018  sw          $a0, 0x18($s0)
    ctx->pc = 0x1bd7f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 4));
    // 0x1bd7f4: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x1bd7f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x1bd7f8: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x1bd7f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x1bd7fc: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1BD7FCu;
    {
        const bool branch_taken_0x1bd7fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD7FCu;
            // 0x1bd800: 0x8e050018  lw          $a1, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd7fc) {
            ctx->pc = 0x1BD874u;
            goto label_1bd874;
        }
    }
    ctx->pc = 0x1BD804u;
label_1bd804:
    // 0x1bd804: 0x8e03001c  lw          $v1, 0x1C($s0)
    ctx->pc = 0x1bd804u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1bd808: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bd808u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bd80c: 0xae03001c  sw          $v1, 0x1C($s0)
    ctx->pc = 0x1bd80cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 3));
    // 0x1bd810: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1bd810u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd814: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD814u;
    {
        const bool branch_taken_0x1bd814 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD814u;
            // 0x1bd818: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd814) {
            ctx->pc = 0x1BD824u;
            goto label_1bd824;
        }
    }
    ctx->pc = 0x1BD81Cu;
    // 0x1bd81c: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd81cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd820: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd820u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd824:
    // 0x1bd824: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd824u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd828: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd828u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd82c: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd82cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1bd830: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1bd830u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd834: 0x8ca30004  lw          $v1, 0x4($a1)
    ctx->pc = 0x1bd834u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1bd838: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd838u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd83c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1bd83cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1bd840: 0x64001a  div         $zero, $v1, $a0
    ctx->pc = 0x1bd840u;
    { int32_t divisor = GPR_S32(ctx, 4);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1bd844: 0x0  nop
    ctx->pc = 0x1bd844u;
    // NOP
    // 0x1bd848: 0x0  nop
    ctx->pc = 0x1bd848u;
    // NOP
    // 0x1bd84c: 0x1812  mflo        $v1
    ctx->pc = 0x1bd84cu;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1bd850: 0x831818  mult        $v1, $a0, $v1
    ctx->pc = 0x1bd850u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1bd854: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD854u;
    {
        const bool branch_taken_0x1bd854 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD854u;
            // 0x1bd858: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd854) {
            ctx->pc = 0x1BD864u;
            goto label_1bd864;
        }
    }
    ctx->pc = 0x1BD85Cu;
    // 0x1bd85c: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd85cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd860: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd860u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd864:
    // 0x1bd864: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd864u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd868: 0x24a5000c  addiu       $a1, $a1, 0xC
    ctx->pc = 0x1bd868u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 12));
    // 0x1bd86c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd86cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd870: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd870u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
label_1bd874:
    // 0x1bd874: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1bd874u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1bd878: 0x1460ffe2  bnez        $v1, . + 4 + (-0x1E << 2)
    ctx->pc = 0x1BD878u;
    {
        const bool branch_taken_0x1bd878 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bd878) {
            ctx->pc = 0x1BD804u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd804;
        }
    }
    ctx->pc = 0x1BD880u;
    // 0x1bd880: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1bd880u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd884: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD884u;
    {
        const bool branch_taken_0x1bd884 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD884u;
            // 0x1bd888: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd884) {
            ctx->pc = 0x1BD894u;
            goto label_1bd894;
        }
    }
    ctx->pc = 0x1BD88Cu;
    // 0x1bd88c: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd88cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd890: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd890u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd894:
    // 0x1bd894: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd894u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd898: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd898u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd89c: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd89cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1bd8a0: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1bd8a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd8a4: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD8A4u;
    {
        const bool branch_taken_0x1bd8a4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD8A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD8A4u;
            // 0x1bd8a8: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd8a4) {
            ctx->pc = 0x1BD8B4u;
            goto label_1bd8b4;
        }
    }
    ctx->pc = 0x1BD8ACu;
    // 0x1bd8ac: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd8acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd8b0: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd8b0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd8b4:
    // 0x1bd8b4: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd8b8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd8b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd8bc: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1bd8c0: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1bd8c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd8c4: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD8C4u;
    {
        const bool branch_taken_0x1bd8c4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD8C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD8C4u;
            // 0x1bd8c8: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd8c4) {
            ctx->pc = 0x1BD8D4u;
            goto label_1bd8d4;
        }
    }
    ctx->pc = 0x1BD8CCu;
    // 0x1bd8cc: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd8ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd8d0: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd8d0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd8d4:
    // 0x1bd8d4: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd8d8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd8d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd8dc: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1bd8e0: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1bd8e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd8e4: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD8E4u;
    {
        const bool branch_taken_0x1bd8e4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD8E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD8E4u;
            // 0x1bd8e8: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd8e4) {
            ctx->pc = 0x1BD8F4u;
            goto label_1bd8f4;
        }
    }
    ctx->pc = 0x1BD8ECu;
    // 0x1bd8ec: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd8ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd8f0: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd8f0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd8f4:
    // 0x1bd8f4: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd8f8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd8f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd8fc: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1bd900: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bd900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bd904: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bd904u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bd908: 0x3e00008  jr          $ra
    ctx->pc = 0x1BD908u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BD90Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD908u;
            // 0x1bd90c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD6C4u: goto label_1bd6c4;
            case 0x1BD6CCu: goto label_1bd6cc;
            case 0x1BD6D4u: goto label_1bd6d4;
            case 0x1BD6F0u: goto label_1bd6f0;
            case 0x1BD6F8u: goto label_1bd6f8;
            case 0x1BD6FCu: goto label_1bd6fc;
            case 0x1BD730u: goto label_1bd730;
            case 0x1BD73Cu: goto label_1bd73c;
            case 0x1BD748u: goto label_1bd748;
            case 0x1BD754u: goto label_1bd754;
            case 0x1BD774u: goto label_1bd774;
            case 0x1BD794u: goto label_1bd794;
            case 0x1BD79Cu: goto label_1bd79c;
            case 0x1BD7D4u: goto label_1bd7d4;
            case 0x1BD804u: goto label_1bd804;
            case 0x1BD824u: goto label_1bd824;
            case 0x1BD864u: goto label_1bd864;
            case 0x1BD874u: goto label_1bd874;
            case 0x1BD894u: goto label_1bd894;
            case 0x1BD8B4u: goto label_1bd8b4;
            case 0x1BD8D4u: goto label_1bd8d4;
            case 0x1BD8F4u: goto label_1bd8f4;
            case 0x1BD938u: goto label_1bd938;
            case 0x1BD958u: goto label_1bd958;
            case 0x1BD964u: goto label_1bd964;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD910u;
    // 0x1bd910: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1bd910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1bd914: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd914u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd918: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1bd918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1bd91c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bd91cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bd920: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bd920u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bd924: 0x8c3044f0  lw          $s0, 0x44F0($at)
    ctx->pc = 0x1bd924u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17648)));
    // 0x1bd928: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD928u;
    {
        const bool branch_taken_0x1bd928 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BD92Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD928u;
            // 0x1bd92c: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd928) {
            ctx->pc = 0x1BD938u;
            goto label_1bd938;
        }
    }
    ctx->pc = 0x1BD930u;
    // 0x1bd930: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1BD930u;
    {
        const bool branch_taken_0x1bd930 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD930u;
            // 0x1bd934: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd930) {
            ctx->pc = 0x1BD964u;
            goto label_1bd964;
        }
    }
    ctx->pc = 0x1BD938u;
label_1bd938:
    // 0x1bd938: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1bd938u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bd93c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1bd93cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1bd940: 0x24425020  addiu       $v0, $v0, 0x5020
    ctx->pc = 0x1bd940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20512));
    // 0x1bd944: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bd944u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bd948: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bd948u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bd94c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1bd94cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bd950: 0x40f809  jalr        $v0
    ctx->pc = 0x1BD950u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1BD958u);
        ctx->pc = 0x1BD954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD950u;
            // 0x1bd954: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1BD958u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD6C4u: goto label_1bd6c4;
            case 0x1BD6CCu: goto label_1bd6cc;
            case 0x1BD6D4u: goto label_1bd6d4;
            case 0x1BD6F0u: goto label_1bd6f0;
            case 0x1BD6F8u: goto label_1bd6f8;
            case 0x1BD6FCu: goto label_1bd6fc;
            case 0x1BD730u: goto label_1bd730;
            case 0x1BD73Cu: goto label_1bd73c;
            case 0x1BD748u: goto label_1bd748;
            case 0x1BD754u: goto label_1bd754;
            case 0x1BD774u: goto label_1bd774;
            case 0x1BD794u: goto label_1bd794;
            case 0x1BD79Cu: goto label_1bd79c;
            case 0x1BD7D4u: goto label_1bd7d4;
            case 0x1BD804u: goto label_1bd804;
            case 0x1BD824u: goto label_1bd824;
            case 0x1BD864u: goto label_1bd864;
            case 0x1BD874u: goto label_1bd874;
            case 0x1BD894u: goto label_1bd894;
            case 0x1BD8B4u: goto label_1bd8b4;
            case 0x1BD8D4u: goto label_1bd8d4;
            case 0x1BD8F4u: goto label_1bd8f4;
            case 0x1BD938u: goto label_1bd938;
            case 0x1BD958u: goto label_1bd958;
            case 0x1BD964u: goto label_1bd964;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1BD958u; }
            if (ctx->pc != 0x1BD958u) { return; }
        }
        }
    }
    ctx->pc = 0x1BD958u;
label_1bd958:
    // 0x1bd958: 0xc6000038  lwc1        $f0, 0x38($s0)
    ctx->pc = 0x1bd958u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1bd95c: 0xe6200000  swc1        $f0, 0x0($s1)
    ctx->pc = 0x1bd95cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x1bd960: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1bd960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_1bd964:
    // 0x1bd964: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1bd964u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bd968: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bd968u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bd96c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bd96cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bd970: 0x3e00008  jr          $ra
    ctx->pc = 0x1BD970u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BD974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD970u;
            // 0x1bd974: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD6C4u: goto label_1bd6c4;
            case 0x1BD6CCu: goto label_1bd6cc;
            case 0x1BD6D4u: goto label_1bd6d4;
            case 0x1BD6F0u: goto label_1bd6f0;
            case 0x1BD6F8u: goto label_1bd6f8;
            case 0x1BD6FCu: goto label_1bd6fc;
            case 0x1BD730u: goto label_1bd730;
            case 0x1BD73Cu: goto label_1bd73c;
            case 0x1BD748u: goto label_1bd748;
            case 0x1BD754u: goto label_1bd754;
            case 0x1BD774u: goto label_1bd774;
            case 0x1BD794u: goto label_1bd794;
            case 0x1BD79Cu: goto label_1bd79c;
            case 0x1BD7D4u: goto label_1bd7d4;
            case 0x1BD804u: goto label_1bd804;
            case 0x1BD824u: goto label_1bd824;
            case 0x1BD864u: goto label_1bd864;
            case 0x1BD874u: goto label_1bd874;
            case 0x1BD894u: goto label_1bd894;
            case 0x1BD8B4u: goto label_1bd8b4;
            case 0x1BD8D4u: goto label_1bd8d4;
            case 0x1BD8F4u: goto label_1bd8f4;
            case 0x1BD938u: goto label_1bd938;
            case 0x1BD958u: goto label_1bd958;
            case 0x1BD964u: goto label_1bd964;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD978u;
    // 0x1bd978: 0x0  nop
    ctx->pc = 0x1bd978u;
    // NOP
    // 0x1bd97c: 0x0  nop
    ctx->pc = 0x1bd97cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
