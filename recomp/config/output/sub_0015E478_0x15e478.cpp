#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E478
// Address: 0x15e478 - 0x15e570
void sub_0015E478_0x15e478(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E478_0x15e478");
#endif

    switch (ctx->pc) {
        case 0x15e48cu: goto label_15e48c;
        case 0x15e4a0u: goto label_15e4a0;
        case 0x15e4d8u: goto label_15e4d8;
        case 0x15e504u: goto label_15e504;
        case 0x15e51cu: goto label_15e51c;
        case 0x15e534u: goto label_15e534;
        case 0x15e548u: goto label_15e548;
        case 0x15e554u: goto label_15e554;
        default: break;
    }

    ctx->pc = 0x15e478u;

    // 0x15e478: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15e478u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15e47c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15e47cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15e480: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15e480u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15e484: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15E484u;
    SET_GPR_U32(ctx, 31, 0x15E48Cu);
    ctx->pc = 0x15E488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E484u;
            // 0x15e488: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E48Cu; }
        if (ctx->pc != 0x15E48Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E48Cu; }
        if (ctx->pc != 0x15E48Cu) { return; }
    }
    ctx->pc = 0x15E48Cu;
label_15e48c:
    // 0x15e48c: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x15E48Cu;
    {
        const bool branch_taken_0x15e48c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15e48c) {
            ctx->pc = 0x15E490u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15E48Cu;
            // 0x15e490: 0x8e020084  lw          $v0, 0x84($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15E4A4u;
            goto label_15e4a4;
        }
    }
    ctx->pc = 0x15E494u;
    // 0x15e494: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15e494u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15e498: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15E498u;
    SET_GPR_U32(ctx, 31, 0x15E4A0u);
    ctx->pc = 0x15E49Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E498u;
            // 0x15e49c: 0x2484ed90  addiu       $a0, $a0, -0x1270 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962576));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E4A0u; }
        if (ctx->pc != 0x15E4A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E4A0u; }
        if (ctx->pc != 0x15E4A0u) { return; }
    }
    ctx->pc = 0x15E4A0u;
label_15e4a0:
    // 0x15e4a0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15e4a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_15e4a4:
    // 0x15e4a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15e4a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e4a8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15e4a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e4ac: 0x3e00008  jr          $ra
    ctx->pc = 0x15E4ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E4B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E4ACu;
            // 0x15e4b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E48Cu: goto label_15e48c;
            case 0x15E4A0u: goto label_15e4a0;
            case 0x15E4A4u: goto label_15e4a4;
            case 0x15E4D8u: goto label_15e4d8;
            case 0x15E504u: goto label_15e504;
            case 0x15E51Cu: goto label_15e51c;
            case 0x15E52Cu: goto label_15e52c;
            case 0x15E534u: goto label_15e534;
            case 0x15E540u: goto label_15e540;
            case 0x15E548u: goto label_15e548;
            case 0x15E554u: goto label_15e554;
            case 0x15E558u: goto label_15e558;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E4B4u;
    // 0x15e4b4: 0x0  nop
    ctx->pc = 0x15e4b4u;
    // NOP
    // 0x15e4b8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15e4b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15e4bc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15e4bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15e4c0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15e4c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e4c4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15e4c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15e4c8: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x15e4c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x15e4cc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x15e4ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15e4d0: 0xc05d668  jal         func_1759A0
    ctx->pc = 0x15E4D0u;
    SET_GPR_U32(ctx, 31, 0x15E4D8u);
    ctx->pc = 0x15E4D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E4D0u;
            // 0x15e4d4: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1759A0u;
    if (runtime->hasFunction(0x1759A0u)) {
        auto targetFn = runtime->lookupFunction(0x1759A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E4D8u; }
        if (ctx->pc != 0x15E4D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001759A0_0x1759a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E4D8u; }
        if (ctx->pc != 0x15E4D8u) { return; }
    }
    ctx->pc = 0x15E4D8u;
label_15e4d8:
    // 0x15e4d8: 0x1440001f  bnez        $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x15E4D8u;
    {
        const bool branch_taken_0x15e4d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15E4DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E4D8u;
            // 0x15e4dc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e4d8) {
            ctx->pc = 0x15E558u;
            goto label_15e558;
        }
    }
    ctx->pc = 0x15E4E0u;
    // 0x15e4e0: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x15e4e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15e4e4: 0x2ca20800  sltiu       $v0, $a1, 0x800
    ctx->pc = 0x15e4e4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)2048) ? 1 : 0);
    // 0x15e4e8: 0x5440001b  bnel        $v0, $zero, . + 4 + (0x1B << 2)
    ctx->pc = 0x15E4E8u;
    {
        const bool branch_taken_0x15e4e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15e4e8) {
            ctx->pc = 0x15E4ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15E4E8u;
            // 0x15e4ec: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15E558u;
            goto label_15e558;
        }
    }
    ctx->pc = 0x15E4F0u;
    // 0x15e4f0: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x15e4f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e4f4: 0x50800018  beql        $a0, $zero, . + 4 + (0x18 << 2)
    ctx->pc = 0x15E4F4u;
    {
        const bool branch_taken_0x15e4f4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x15e4f4) {
            ctx->pc = 0x15E4F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15E4F4u;
            // 0x15e4f8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15E558u;
            goto label_15e558;
        }
    }
    ctx->pc = 0x15E4FCu;
    // 0x15e4fc: 0xc05e43c  jal         func_1790F0
    ctx->pc = 0x15E4FCu;
    SET_GPR_U32(ctx, 31, 0x15E504u);
    ctx->pc = 0x1790F0u;
    if (runtime->hasFunction(0x1790F0u)) {
        auto targetFn = runtime->lookupFunction(0x1790F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E504u; }
        if (ctx->pc != 0x15E504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001790F0_0x1790f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E504u; }
        if (ctx->pc != 0x15E504u) { return; }
    }
    ctx->pc = 0x15E504u;
label_15e504:
    // 0x15e504: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x15e504u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e508: 0x12200013  beqz        $s1, . + 4 + (0x13 << 2)
    ctx->pc = 0x15E508u;
    {
        const bool branch_taken_0x15e508 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E50Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E508u;
            // 0x15e50c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e508) {
            ctx->pc = 0x15E558u;
            goto label_15e558;
        }
    }
    ctx->pc = 0x15E510u;
    // 0x15e510: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15e510u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e514: 0xc05e4c2  jal         func_179308
    ctx->pc = 0x15E514u;
    SET_GPR_U32(ctx, 31, 0x15E51Cu);
    ctx->pc = 0x15E518u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E514u;
            // 0x15e518: 0x27a50008  addiu       $a1, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179308u;
    if (runtime->hasFunction(0x179308u)) {
        auto targetFn = runtime->lookupFunction(0x179308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E51Cu; }
        if (ctx->pc != 0x15E51Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179308_0x179308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E51Cu; }
        if (ctx->pc != 0x15E51Cu) { return; }
    }
    ctx->pc = 0x15E51Cu;
label_15e51c:
    // 0x15e51c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15E51Cu;
    {
        const bool branch_taken_0x15e51c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E51Cu;
            // 0x15e520: 0x8fa20008  lw          $v0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e51c) {
            ctx->pc = 0x15E52Cu;
            goto label_15e52c;
        }
    }
    ctx->pc = 0x15E524u;
    // 0x15e524: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15E524u;
    {
        const bool branch_taken_0x15e524 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15e524) {
            ctx->pc = 0x15E540u;
            goto label_15e540;
        }
    }
    ctx->pc = 0x15E52Cu;
label_15e52c:
    // 0x15e52c: 0xc05e46e  jal         func_1791B8
    ctx->pc = 0x15E52Cu;
    SET_GPR_U32(ctx, 31, 0x15E534u);
    ctx->pc = 0x15E530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E52Cu;
            // 0x15e530: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1791B8u;
    if (runtime->hasFunction(0x1791B8u)) {
        auto targetFn = runtime->lookupFunction(0x1791B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E534u; }
        if (ctx->pc != 0x15E534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001791B8_0x1791b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E534u; }
        if (ctx->pc != 0x15E534u) { return; }
    }
    ctx->pc = 0x15E534u;
label_15e534:
    // 0x15e534: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x15E534u;
    {
        const bool branch_taken_0x15e534 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E534u;
            // 0x15e538: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e534) {
            ctx->pc = 0x15E558u;
            goto label_15e558;
        }
    }
    ctx->pc = 0x15E53Cu;
    // 0x15e53c: 0x0  nop
    ctx->pc = 0x15e53cu;
    // NOP
label_15e540:
    // 0x15e540: 0xc05795c  jal         func_15E570
    ctx->pc = 0x15E540u;
    SET_GPR_U32(ctx, 31, 0x15E548u);
    ctx->pc = 0x15E544u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E540u;
            // 0x15e544: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E570u;
    if (runtime->hasFunction(0x15E570u)) {
        auto targetFn = runtime->lookupFunction(0x15E570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E548u; }
        if (ctx->pc != 0x15E548u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E570_0x15e570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E548u; }
        if (ctx->pc != 0x15E548u) { return; }
    }
    ctx->pc = 0x15E548u;
label_15e548:
    // 0x15e548: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15e548u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e54c: 0xc05e46e  jal         func_1791B8
    ctx->pc = 0x15E54Cu;
    SET_GPR_U32(ctx, 31, 0x15E554u);
    ctx->pc = 0x15E550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E54Cu;
            // 0x15e550: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1791B8u;
    if (runtime->hasFunction(0x1791B8u)) {
        auto targetFn = runtime->lookupFunction(0x1791B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E554u; }
        if (ctx->pc != 0x15E554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001791B8_0x1791b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E554u; }
        if (ctx->pc != 0x15E554u) { return; }
    }
    ctx->pc = 0x15E554u;
label_15e554:
    // 0x15e554: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x15e554u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_15e558:
    // 0x15e558: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15e558u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15e55c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15e55cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15e560: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15e560u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15e564: 0x3e00008  jr          $ra
    ctx->pc = 0x15E564u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E568u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E564u;
            // 0x15e568: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E48Cu: goto label_15e48c;
            case 0x15E4A0u: goto label_15e4a0;
            case 0x15E4A4u: goto label_15e4a4;
            case 0x15E4D8u: goto label_15e4d8;
            case 0x15E504u: goto label_15e504;
            case 0x15E51Cu: goto label_15e51c;
            case 0x15E52Cu: goto label_15e52c;
            case 0x15E534u: goto label_15e534;
            case 0x15E540u: goto label_15e540;
            case 0x15E548u: goto label_15e548;
            case 0x15E554u: goto label_15e554;
            case 0x15E558u: goto label_15e558;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E56Cu;
    // 0x15e56c: 0x0  nop
    ctx->pc = 0x15e56cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
