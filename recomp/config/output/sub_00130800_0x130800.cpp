#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130800
// Address: 0x130800 - 0x130b78
void sub_00130800_0x130800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130800_0x130800");
#endif

    switch (ctx->pc) {
        case 0x130830u: goto label_130830;
        case 0x130838u: goto label_130838;
        case 0x130858u: goto label_130858;
        case 0x130878u: goto label_130878;
        case 0x130890u: goto label_130890;
        case 0x1308a8u: goto label_1308a8;
        case 0x130910u: goto label_130910;
        case 0x130974u: goto label_130974;
        case 0x13098cu: goto label_13098c;
        case 0x1309a0u: goto label_1309a0;
        case 0x1309b4u: goto label_1309b4;
        case 0x130a04u: goto label_130a04;
        case 0x130a1cu: goto label_130a1c;
        case 0x130a58u: goto label_130a58;
        case 0x130ac0u: goto label_130ac0;
        case 0x130ad0u: goto label_130ad0;
        case 0x130b04u: goto label_130b04;
        case 0x130b18u: goto label_130b18;
        default: break;
    }

    ctx->pc = 0x130800u;

    // 0x130800: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x130800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x130804: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x130804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x130808: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x130808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x13080c: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x13080cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130810: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x130810u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x130814: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x130814u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130818: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x130818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x13081c: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x13081cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x130820: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x130820u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x130824: 0x8e640008  lw          $a0, 0x8($s3)
    ctx->pc = 0x130824u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x130828: 0xc04d7d4  jal         func_135F50
    ctx->pc = 0x130828u;
    SET_GPR_U32(ctx, 31, 0x130830u);
    ctx->pc = 0x13082Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130828u;
            // 0x13082c: 0x8e740004  lw          $s4, 0x4($s3) (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135F50u;
    if (runtime->hasFunction(0x135F50u)) {
        auto targetFn = runtime->lookupFunction(0x135F50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130830u; }
        if (ctx->pc != 0x130830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135F50_0x135f50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130830u; }
        if (ctx->pc != 0x130830u) { return; }
    }
    ctx->pc = 0x130830u;
label_130830:
    // 0x130830: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x130830u;
    SET_GPR_U32(ctx, 31, 0x130838u);
    ctx->pc = 0x130834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130830u;
            // 0x130834: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130838u; }
        if (ctx->pc != 0x130838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130838u; }
        if (ctx->pc != 0x130838u) { return; }
    }
    ctx->pc = 0x130838u;
label_130838:
    // 0x130838: 0x82620002  lb          $v0, 0x2($s3)
    ctx->pc = 0x130838u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 2)));
    // 0x13083c: 0x5451005a  bnel        $v0, $s1, . + 4 + (0x5A << 2)
    ctx->pc = 0x13083Cu;
    {
        const bool branch_taken_0x13083c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        if (branch_taken_0x13083c) {
            ctx->pc = 0x130840u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13083Cu;
            // 0x130840: 0xa2710002  sb          $s1, 0x2($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 2), (uint8_t)GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1309A8u;
            goto label_1309a8;
        }
    }
    ctx->pc = 0x130844u;
    // 0x130844: 0x56110046  bnel        $s0, $s1, . + 4 + (0x46 << 2)
    ctx->pc = 0x130844u;
    {
        const bool branch_taken_0x130844 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 17));
        if (branch_taken_0x130844) {
            ctx->pc = 0x130848u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x130844u;
            // 0x130848: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130960u;
            goto label_130960;
        }
    }
    ctx->pc = 0x13084Cu;
    // 0x13084c: 0xa2600002  sb          $zero, 0x2($s3)
    ctx->pc = 0x13084cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x130850: 0xc0505ba  jal         func_1416E8
    ctx->pc = 0x130850u;
    SET_GPR_U32(ctx, 31, 0x130858u);
    ctx->pc = 0x130854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130850u;
            // 0x130854: 0x26720020  addiu       $s2, $s3, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 19), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130858u; }
        if (ctx->pc != 0x130858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416E8_0x1416e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130858u; }
        if (ctx->pc != 0x130858u) { return; }
    }
    ctx->pc = 0x130858u;
label_130858:
    // 0x130858: 0x8e70001c  lw          $s0, 0x1C($s3)
    ctx->pc = 0x130858u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x13085c: 0x27b10010  addiu       $s1, $sp, 0x10
    ctx->pc = 0x13085cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x130860: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x130860u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130864: 0x1082c0  sll         $s0, $s0, 11
    ctx->pc = 0x130864u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 11));
    // 0x130868: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x130868u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13086c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x13086cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130870: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x130870u;
    SET_GPR_U32(ctx, 31, 0x130878u);
    ctx->pc = 0x130874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130870u;
            // 0x130874: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130878u; }
        if (ctx->pc != 0x130878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130878u; }
        if (ctx->pc != 0x130878u) { return; }
    }
    ctx->pc = 0x130878u;
label_130878:
    // 0x130878: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x130878u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x13087c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x13087cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130880: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x130880u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130884: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x130884u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x130888: 0x40f809  jalr        $v0
    ctx->pc = 0x130888u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x130890u);
        ctx->pc = 0x13088Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130888u;
            // 0x13088c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x130890u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130830u: goto label_130830;
            case 0x130838u: goto label_130838;
            case 0x130858u: goto label_130858;
            case 0x130878u: goto label_130878;
            case 0x130890u: goto label_130890;
            case 0x1308A8u: goto label_1308a8;
            case 0x130910u: goto label_130910;
            case 0x130914u: goto label_130914;
            case 0x130950u: goto label_130950;
            case 0x130960u: goto label_130960;
            case 0x130974u: goto label_130974;
            case 0x13098Cu: goto label_13098c;
            case 0x130998u: goto label_130998;
            case 0x1309A0u: goto label_1309a0;
            case 0x1309A8u: goto label_1309a8;
            case 0x1309B4u: goto label_1309b4;
            case 0x1309E8u: goto label_1309e8;
            case 0x1309FCu: goto label_1309fc;
            case 0x130A04u: goto label_130a04;
            case 0x130A10u: goto label_130a10;
            case 0x130A1Cu: goto label_130a1c;
            case 0x130A40u: goto label_130a40;
            case 0x130A58u: goto label_130a58;
            case 0x130AC0u: goto label_130ac0;
            case 0x130AD0u: goto label_130ad0;
            case 0x130B04u: goto label_130b04;
            case 0x130B18u: goto label_130b18;
            case 0x130B24u: goto label_130b24;
            case 0x130B50u: goto label_130b50;
            case 0x130B58u: goto label_130b58;
            case 0x130B5Cu: goto label_130b5c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x130890u; }
            if (ctx->pc != 0x130890u) { return; }
        }
        }
    }
    ctx->pc = 0x130890u;
label_130890:
    // 0x130890: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x130890u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x130894: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x130894u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130898: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x130898u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13089c: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x13089cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1308a0: 0x40f809  jalr        $v0
    ctx->pc = 0x1308A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1308A8u);
        ctx->pc = 0x1308A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1308A0u;
            // 0x1308a4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1308A8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130830u: goto label_130830;
            case 0x130838u: goto label_130838;
            case 0x130858u: goto label_130858;
            case 0x130878u: goto label_130878;
            case 0x130890u: goto label_130890;
            case 0x1308A8u: goto label_1308a8;
            case 0x130910u: goto label_130910;
            case 0x130914u: goto label_130914;
            case 0x130950u: goto label_130950;
            case 0x130960u: goto label_130960;
            case 0x130974u: goto label_130974;
            case 0x13098Cu: goto label_13098c;
            case 0x130998u: goto label_130998;
            case 0x1309A0u: goto label_1309a0;
            case 0x1309A8u: goto label_1309a8;
            case 0x1309B4u: goto label_1309b4;
            case 0x1309E8u: goto label_1309e8;
            case 0x1309FCu: goto label_1309fc;
            case 0x130A04u: goto label_130a04;
            case 0x130A10u: goto label_130a10;
            case 0x130A1Cu: goto label_130a1c;
            case 0x130A40u: goto label_130a40;
            case 0x130A58u: goto label_130a58;
            case 0x130AC0u: goto label_130ac0;
            case 0x130AD0u: goto label_130ad0;
            case 0x130B04u: goto label_130b04;
            case 0x130B18u: goto label_130b18;
            case 0x130B24u: goto label_130b24;
            case 0x130B50u: goto label_130b50;
            case 0x130B58u: goto label_130b58;
            case 0x130B5Cu: goto label_130b5c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1308A8u; }
            if (ctx->pc != 0x1308A8u) { return; }
        }
        }
    }
    ctx->pc = 0x1308A8u;
label_1308a8:
    // 0x1308a8: 0x8e660054  lw          $a2, 0x54($s3)
    ctx->pc = 0x1308a8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 84)));
    // 0x1308ac: 0x8e620010  lw          $v0, 0x10($s3)
    ctx->pc = 0x1308acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1308b0: 0x8e650030  lw          $a1, 0x30($s3)
    ctx->pc = 0x1308b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 48)));
    // 0x1308b4: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x1308b4u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1308b8: 0x244707ff  addiu       $a3, $v0, 0x7FF
    ctx->pc = 0x1308b8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x1308bc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1308bcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1308c0: 0x8e68001c  lw          $t0, 0x1C($s3)
    ctx->pc = 0x1308c0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1308c4: 0xe4180b  movn        $v1, $a3, $a0
    ctx->pc = 0x1308c4u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 7));
    // 0x1308c8: 0x8e69002c  lw          $t1, 0x2C($s3)
    ctx->pc = 0x1308c8u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 44)));
    // 0x1308cc: 0x31ac3  sra         $v1, $v1, 11
    ctx->pc = 0x1308ccu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 11));
    // 0x1308d0: 0xb02821  addu        $a1, $a1, $s0
    ctx->pc = 0x1308d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x1308d4: 0x322c0  sll         $a0, $v1, 11
    ctx->pc = 0x1308d4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x1308d8: 0xc83021  addu        $a2, $a2, $t0
    ctx->pc = 0x1308d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x1308dc: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x1308dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1308e0: 0xae650030  sw          $a1, 0x30($s3)
    ctx->pc = 0x1308e0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 48), GPR_U32(ctx, 5));
    // 0x1308e4: 0x2102a  slt         $v0, $zero, $v0
    ctx->pc = 0x1308e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1308e8: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1308e8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1308ec: 0x628021  addu        $s0, $v1, $v0
    ctx->pc = 0x1308ecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1308f0: 0xae660054  sw          $a2, 0x54($s3)
    ctx->pc = 0x1308f0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 84), GPR_U32(ctx, 6));
    // 0x1308f4: 0x14c90006  bne         $a2, $t1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1308F4u;
    {
        const bool branch_taken_0x1308f4 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 9));
        ctx->pc = 0x1308F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1308F4u;
            // 0x1308f8: 0xae600024  sw          $zero, 0x24($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1308f4) {
            ctx->pc = 0x130910u;
            goto label_130910;
        }
    }
    ctx->pc = 0x1308FCu;
    // 0x1308fc: 0x8e620034  lw          $v0, 0x34($s3)
    ctx->pc = 0x1308fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 52)));
    // 0x130900: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x130900u;
    {
        const bool branch_taken_0x130900 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x130900) {
            ctx->pc = 0x130904u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x130900u;
            // 0x130904: 0x8e620054  lw          $v0, 0x54($s3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 84)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130914u;
            goto label_130914;
        }
    }
    ctx->pc = 0x130908u;
    // 0x130908: 0x40f809  jalr        $v0
    ctx->pc = 0x130908u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x130910u);
        ctx->pc = 0x13090Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130908u;
            // 0x13090c: 0x8e640038  lw          $a0, 0x38($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 56)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x130910u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130830u: goto label_130830;
            case 0x130838u: goto label_130838;
            case 0x130858u: goto label_130858;
            case 0x130878u: goto label_130878;
            case 0x130890u: goto label_130890;
            case 0x1308A8u: goto label_1308a8;
            case 0x130910u: goto label_130910;
            case 0x130914u: goto label_130914;
            case 0x130950u: goto label_130950;
            case 0x130960u: goto label_130960;
            case 0x130974u: goto label_130974;
            case 0x13098Cu: goto label_13098c;
            case 0x130998u: goto label_130998;
            case 0x1309A0u: goto label_1309a0;
            case 0x1309A8u: goto label_1309a8;
            case 0x1309B4u: goto label_1309b4;
            case 0x1309E8u: goto label_1309e8;
            case 0x1309FCu: goto label_1309fc;
            case 0x130A04u: goto label_130a04;
            case 0x130A10u: goto label_130a10;
            case 0x130A1Cu: goto label_130a1c;
            case 0x130A40u: goto label_130a40;
            case 0x130A58u: goto label_130a58;
            case 0x130AC0u: goto label_130ac0;
            case 0x130AD0u: goto label_130ad0;
            case 0x130B04u: goto label_130b04;
            case 0x130B18u: goto label_130b18;
            case 0x130B24u: goto label_130b24;
            case 0x130B50u: goto label_130b50;
            case 0x130B58u: goto label_130b58;
            case 0x130B5Cu: goto label_130b5c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x130910u; }
            if (ctx->pc != 0x130910u) { return; }
        }
        }
    }
    ctx->pc = 0x130910u;
label_130910:
    // 0x130910: 0x8e620054  lw          $v0, 0x54($s3)
    ctx->pc = 0x130910u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 84)));
label_130914:
    // 0x130914: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x130914u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x130918: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x130918u;
    {
        const bool branch_taken_0x130918 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13091Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130918u;
            // 0x13091c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130918) {
            ctx->pc = 0x130950u;
            goto label_130950;
        }
    }
    ctx->pc = 0x130920u;
    // 0x130920: 0x8e620030  lw          $v0, 0x30($s3)
    ctx->pc = 0x130920u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 48)));
    // 0x130924: 0x8e630058  lw          $v1, 0x58($s3)
    ctx->pc = 0x130924u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 88)));
    // 0x130928: 0x212c2  srl         $v0, $v0, 11
    ctx->pc = 0x130928u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 11));
    // 0x13092c: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x13092cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x130930: 0x54400089  bnel        $v0, $zero, . + 4 + (0x89 << 2)
    ctx->pc = 0x130930u;
    {
        const bool branch_taken_0x130930 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x130930) {
            ctx->pc = 0x130934u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x130930u;
            // 0x130934: 0xa2600003  sb          $zero, 0x3($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 3), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130B58u;
            goto label_130b58;
        }
    }
    ctx->pc = 0x130938u;
    // 0x130938: 0x3c02000f  lui         $v0, 0xF
    ctx->pc = 0x130938u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
    // 0x13093c: 0x3442fffe  ori         $v0, $v0, 0xFFFE
    ctx->pc = 0x13093cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65534);
    // 0x130940: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x130940u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x130944: 0x54400084  bnel        $v0, $zero, . + 4 + (0x84 << 2)
    ctx->pc = 0x130944u;
    {
        const bool branch_taken_0x130944 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x130944) {
            ctx->pc = 0x130948u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x130944u;
            // 0x130948: 0xa2600003  sb          $zero, 0x3($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 3), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130B58u;
            goto label_130b58;
        }
    }
    ctx->pc = 0x13094Cu;
    // 0x13094c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x13094cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_130950:
    // 0x130950: 0xa2620001  sb          $v0, 0x1($s3)
    ctx->pc = 0x130950u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x130954: 0x10000080  b           . + 4 + (0x80 << 2)
    ctx->pc = 0x130954u;
    {
        const bool branch_taken_0x130954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x130958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130954u;
            // 0x130958: 0xa2600003  sb          $zero, 0x3($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 3), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130954) {
            ctx->pc = 0x130B58u;
            goto label_130b58;
        }
    }
    ctx->pc = 0x13095Cu;
    // 0x13095c: 0x0  nop
    ctx->pc = 0x13095cu;
    // NOP
label_130960:
    // 0x130960: 0x1602000d  bne         $s0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x130960u;
    {
        const bool branch_taken_0x130960 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x130960) {
            ctx->pc = 0x130998u;
            goto label_130998;
        }
    }
    ctx->pc = 0x130968u;
    // 0x130968: 0xa2600002  sb          $zero, 0x2($s3)
    ctx->pc = 0x130968u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x13096c: 0xc0505ba  jal         func_1416E8
    ctx->pc = 0x13096Cu;
    SET_GPR_U32(ctx, 31, 0x130974u);
    ctx->pc = 0x130970u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13096Cu;
            // 0x130970: 0x26700020  addiu       $s0, $s3, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130974u; }
        if (ctx->pc != 0x130974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416E8_0x1416e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130974u; }
        if (ctx->pc != 0x130974u) { return; }
    }
    ctx->pc = 0x130974u;
label_130974:
    // 0x130974: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x130974u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x130978: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x130978u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13097c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13097cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130980: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x130980u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x130984: 0x40f809  jalr        $v0
    ctx->pc = 0x130984u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13098Cu);
        ctx->pc = 0x130988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130984u;
            // 0x130988: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13098Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130830u: goto label_130830;
            case 0x130838u: goto label_130838;
            case 0x130858u: goto label_130858;
            case 0x130878u: goto label_130878;
            case 0x130890u: goto label_130890;
            case 0x1308A8u: goto label_1308a8;
            case 0x130910u: goto label_130910;
            case 0x130914u: goto label_130914;
            case 0x130950u: goto label_130950;
            case 0x130960u: goto label_130960;
            case 0x130974u: goto label_130974;
            case 0x13098Cu: goto label_13098c;
            case 0x130998u: goto label_130998;
            case 0x1309A0u: goto label_1309a0;
            case 0x1309A8u: goto label_1309a8;
            case 0x1309B4u: goto label_1309b4;
            case 0x1309E8u: goto label_1309e8;
            case 0x1309FCu: goto label_1309fc;
            case 0x130A04u: goto label_130a04;
            case 0x130A10u: goto label_130a10;
            case 0x130A1Cu: goto label_130a1c;
            case 0x130A40u: goto label_130a40;
            case 0x130A58u: goto label_130a58;
            case 0x130AC0u: goto label_130ac0;
            case 0x130AD0u: goto label_130ad0;
            case 0x130B04u: goto label_130b04;
            case 0x130B18u: goto label_130b18;
            case 0x130B24u: goto label_130b24;
            case 0x130B50u: goto label_130b50;
            case 0x130B58u: goto label_130b58;
            case 0x130B5Cu: goto label_130b5c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13098Cu; }
            if (ctx->pc != 0x13098Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13098Cu;
label_13098c:
    // 0x13098c: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13098cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x130990: 0x10000064  b           . + 4 + (0x64 << 2)
    ctx->pc = 0x130990u;
    {
        const bool branch_taken_0x130990 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x130994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130990u;
            // 0x130994: 0xae600024  sw          $zero, 0x24($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130990) {
            ctx->pc = 0x130B24u;
            goto label_130b24;
        }
    }
    ctx->pc = 0x130998u;
label_130998:
    // 0x130998: 0xc0505ba  jal         func_1416E8
    ctx->pc = 0x130998u;
    SET_GPR_U32(ctx, 31, 0x1309A0u);
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1309A0u; }
        if (ctx->pc != 0x1309A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416E8_0x1416e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1309A0u; }
        if (ctx->pc != 0x1309A0u) { return; }
    }
    ctx->pc = 0x1309A0u;
label_1309a0:
    // 0x1309a0: 0x1000006e  b           . + 4 + (0x6E << 2)
    ctx->pc = 0x1309A0u;
    {
        const bool branch_taken_0x1309a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1309A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1309A0u;
            // 0x1309a4: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1309a0) {
            ctx->pc = 0x130B5Cu;
            goto label_130b5c;
        }
    }
    ctx->pc = 0x1309A8u;
label_1309a8:
    // 0x1309a8: 0xae600020  sw          $zero, 0x20($s3)
    ctx->pc = 0x1309a8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 32), GPR_U32(ctx, 0));
    // 0x1309ac: 0xc0505ba  jal         func_1416E8
    ctx->pc = 0x1309ACu;
    SET_GPR_U32(ctx, 31, 0x1309B4u);
    ctx->pc = 0x1309B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1309ACu;
            // 0x1309b0: 0xae600024  sw          $zero, 0x24($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1309B4u; }
        if (ctx->pc != 0x1309B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416E8_0x1416e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1309B4u; }
        if (ctx->pc != 0x1309B4u) { return; }
    }
    ctx->pc = 0x1309B4u;
label_1309b4:
    // 0x1309b4: 0x82620040  lb          $v0, 0x40($s3)
    ctx->pc = 0x1309b4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 64)));
    // 0x1309b8: 0x50510067  beql        $v0, $s1, . + 4 + (0x67 << 2)
    ctx->pc = 0x1309B8u;
    {
        const bool branch_taken_0x1309b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        if (branch_taken_0x1309b8) {
            ctx->pc = 0x1309BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1309B8u;
            // 0x1309bc: 0xa2600002  sb          $zero, 0x2($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130B58u;
            goto label_130b58;
        }
    }
    ctx->pc = 0x1309C0u;
    // 0x1309c0: 0x82620044  lb          $v0, 0x44($s3)
    ctx->pc = 0x1309c0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 68)));
    // 0x1309c4: 0x50510064  beql        $v0, $s1, . + 4 + (0x64 << 2)
    ctx->pc = 0x1309C4u;
    {
        const bool branch_taken_0x1309c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        if (branch_taken_0x1309c4) {
            ctx->pc = 0x1309C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1309C4u;
            // 0x1309c8: 0xa2600002  sb          $zero, 0x2($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130B58u;
            goto label_130b58;
        }
    }
    ctx->pc = 0x1309CCu;
    // 0x1309cc: 0x8e620010  lw          $v0, 0x10($s3)
    ctx->pc = 0x1309ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1309d0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1309D0u;
    {
        const bool branch_taken_0x1309d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1309D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1309D0u;
            // 0x1309d4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1309d0) {
            ctx->pc = 0x1309E8u;
            goto label_1309e8;
        }
    }
    ctx->pc = 0x1309D8u;
    // 0x1309d8: 0xa2600002  sb          $zero, 0x2($s3)
    ctx->pc = 0x1309d8u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1309dc: 0xa2620001  sb          $v0, 0x1($s3)
    ctx->pc = 0x1309dcu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1309e0: 0x1000005d  b           . + 4 + (0x5D << 2)
    ctx->pc = 0x1309E0u;
    {
        const bool branch_taken_0x1309e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1309E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1309E0u;
            // 0x1309e4: 0xae60001c  sw          $zero, 0x1C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1309e0) {
            ctx->pc = 0x130B58u;
            goto label_130b58;
        }
    }
    ctx->pc = 0x1309E8u;
label_1309e8:
    // 0x1309e8: 0x12800004  beqz        $s4, . + 4 + (0x4 << 2)
    ctx->pc = 0x1309E8u;
    {
        const bool branch_taken_0x1309e8 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        if (branch_taken_0x1309e8) {
            ctx->pc = 0x1309FCu;
            goto label_1309fc;
        }
    }
    ctx->pc = 0x1309F0u;
    // 0x1309f0: 0x8e820000  lw          $v0, 0x0($s4)
    ctx->pc = 0x1309f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1309f4: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x1309F4u;
    {
        const bool branch_taken_0x1309f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1309f4) {
            ctx->pc = 0x1309F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1309F4u;
            // 0x1309f8: 0x8c420024  lw          $v0, 0x24($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130A10u;
            goto label_130a10;
        }
    }
    ctx->pc = 0x1309FCu;
label_1309fc:
    // 0x1309fc: 0xc04c1fa  jal         func_1307E8
    ctx->pc = 0x1309FCu;
    SET_GPR_U32(ctx, 31, 0x130A04u);
    ctx->pc = 0x130A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1309FCu;
            // 0x130a00: 0xa2600002  sb          $zero, 0x2($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1307E8u;
    if (runtime->hasFunction(0x1307E8u)) {
        auto targetFn = runtime->lookupFunction(0x1307E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130A04u; }
        if (ctx->pc != 0x130A04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001307E8_0x1307e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130A04u; }
        if (ctx->pc != 0x130A04u) { return; }
    }
    ctx->pc = 0x130A04u;
label_130a04:
    // 0x130a04: 0x10000055  b           . + 4 + (0x55 << 2)
    ctx->pc = 0x130A04u;
    {
        const bool branch_taken_0x130a04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x130A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130A04u;
            // 0x130a08: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130a04) {
            ctx->pc = 0x130B5Cu;
            goto label_130b5c;
        }
    }
    ctx->pc = 0x130A0Cu;
    // 0x130a0c: 0x0  nop
    ctx->pc = 0x130a0cu;
    // NOP
label_130a10:
    // 0x130a10: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x130a10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130a14: 0x40f809  jalr        $v0
    ctx->pc = 0x130A14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x130A1Cu);
        ctx->pc = 0x130A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130A14u;
            // 0x130a18: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x130A1Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130830u: goto label_130830;
            case 0x130838u: goto label_130838;
            case 0x130858u: goto label_130858;
            case 0x130878u: goto label_130878;
            case 0x130890u: goto label_130890;
            case 0x1308A8u: goto label_1308a8;
            case 0x130910u: goto label_130910;
            case 0x130914u: goto label_130914;
            case 0x130950u: goto label_130950;
            case 0x130960u: goto label_130960;
            case 0x130974u: goto label_130974;
            case 0x13098Cu: goto label_13098c;
            case 0x130998u: goto label_130998;
            case 0x1309A0u: goto label_1309a0;
            case 0x1309A8u: goto label_1309a8;
            case 0x1309B4u: goto label_1309b4;
            case 0x1309E8u: goto label_1309e8;
            case 0x1309FCu: goto label_1309fc;
            case 0x130A04u: goto label_130a04;
            case 0x130A10u: goto label_130a10;
            case 0x130A1Cu: goto label_130a1c;
            case 0x130A40u: goto label_130a40;
            case 0x130A58u: goto label_130a58;
            case 0x130AC0u: goto label_130ac0;
            case 0x130AD0u: goto label_130ad0;
            case 0x130B04u: goto label_130b04;
            case 0x130B18u: goto label_130b18;
            case 0x130B24u: goto label_130b24;
            case 0x130B50u: goto label_130b50;
            case 0x130B58u: goto label_130b58;
            case 0x130B5Cu: goto label_130b5c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x130A1Cu; }
            if (ctx->pc != 0x130A1Cu) { return; }
        }
        }
    }
    ctx->pc = 0x130A1Cu;
label_130a1c:
    // 0x130a1c: 0x8e63003c  lw          $v1, 0x3C($s3)
    ctx->pc = 0x130a1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 60)));
    // 0x130a20: 0x8e640018  lw          $a0, 0x18($s3)
    ctx->pc = 0x130a20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x130a24: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x130a24u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x130a28: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x130a28u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x130a2c: 0x54600004  bnel        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x130A2Cu;
    {
        const bool branch_taken_0x130a2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x130a2c) {
            ctx->pc = 0x130A30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x130A2Cu;
            // 0x130a30: 0x8e830000  lw          $v1, 0x0($s4) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130A40u;
            goto label_130a40;
        }
    }
    ctx->pc = 0x130A34u;
    // 0x130a34: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x130A34u;
    {
        const bool branch_taken_0x130a34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x130A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130A34u;
            // 0x130a38: 0xa2600002  sb          $zero, 0x2($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130a34) {
            ctx->pc = 0x130B58u;
            goto label_130b58;
        }
    }
    ctx->pc = 0x130A3Cu;
    // 0x130a3c: 0x0  nop
    ctx->pc = 0x130a3cu;
    // NOP
label_130a40:
    // 0x130a40: 0x27a70010  addiu       $a3, $sp, 0x10
    ctx->pc = 0x130a40u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x130a44: 0x8e660014  lw          $a2, 0x14($s3)
    ctx->pc = 0x130a44u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 20)));
    // 0x130a48: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x130a48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130a4c: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x130a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x130a50: 0x40f809  jalr        $v0
    ctx->pc = 0x130A50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x130A58u);
        ctx->pc = 0x130A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130A50u;
            // 0x130a54: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x130A58u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130830u: goto label_130830;
            case 0x130838u: goto label_130838;
            case 0x130858u: goto label_130858;
            case 0x130878u: goto label_130878;
            case 0x130890u: goto label_130890;
            case 0x1308A8u: goto label_1308a8;
            case 0x130910u: goto label_130910;
            case 0x130914u: goto label_130914;
            case 0x130950u: goto label_130950;
            case 0x130960u: goto label_130960;
            case 0x130974u: goto label_130974;
            case 0x13098Cu: goto label_13098c;
            case 0x130998u: goto label_130998;
            case 0x1309A0u: goto label_1309a0;
            case 0x1309A8u: goto label_1309a8;
            case 0x1309B4u: goto label_1309b4;
            case 0x1309E8u: goto label_1309e8;
            case 0x1309FCu: goto label_1309fc;
            case 0x130A04u: goto label_130a04;
            case 0x130A10u: goto label_130a10;
            case 0x130A1Cu: goto label_130a1c;
            case 0x130A40u: goto label_130a40;
            case 0x130A58u: goto label_130a58;
            case 0x130AC0u: goto label_130ac0;
            case 0x130AD0u: goto label_130ad0;
            case 0x130B04u: goto label_130b04;
            case 0x130B18u: goto label_130b18;
            case 0x130B24u: goto label_130b24;
            case 0x130B50u: goto label_130b50;
            case 0x130B58u: goto label_130b58;
            case 0x130B5Cu: goto label_130b5c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x130A58u; }
            if (ctx->pc != 0x130A58u) { return; }
        }
        }
    }
    ctx->pc = 0x130A58u;
label_130a58:
    // 0x130a58: 0x8e67002c  lw          $a3, 0x2C($s3)
    ctx->pc = 0x130a58u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 44)));
    // 0x130a5c: 0x8fa40014  lw          $a0, 0x14($sp)
    ctx->pc = 0x130a5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x130a60: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x130a60u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130a64: 0x8e620010  lw          $v0, 0x10($s3)
    ctx->pc = 0x130a64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x130a68: 0x8e6a0054  lw          $t2, 0x54($s3)
    ctx->pc = 0x130a68u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 84)));
    // 0x130a6c: 0x248807ff  addiu       $t0, $a0, 0x7FF
    ctx->pc = 0x130a6cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), 2047));
    // 0x130a70: 0x28850000  slti        $a1, $a0, 0x0
    ctx->pc = 0x130a70u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x130a74: 0x244907ff  addiu       $t1, $v0, 0x7FF
    ctx->pc = 0x130a74u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x130a78: 0x105200b  movn        $a0, $t0, $a1
    ctx->pc = 0x130a78u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 8));
    // 0x130a7c: 0x8e65000c  lw          $a1, 0xC($s3)
    ctx->pc = 0x130a7cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x130a80: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x130a80u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x130a84: 0xea3823  subu        $a3, $a3, $t2
    ctx->pc = 0x130a84u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x130a88: 0x123100b  movn        $v0, $t1, $v1
    ctx->pc = 0x130a88u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 9));
    // 0x130a8c: 0x422c3  sra         $a0, $a0, 11
    ctx->pc = 0x130a8cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 11));
    // 0x130a90: 0x87182a  slt         $v1, $a0, $a3
    ctx->pc = 0x130a90u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x130a94: 0x212c3  sra         $v0, $v0, 11
    ctx->pc = 0x130a94u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
    // 0x130a98: 0x83380b  movn        $a3, $a0, $v1
    ctx->pc = 0x130a98u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 4));
    // 0x130a9c: 0x8e640008  lw          $a0, 0x8($s3)
    ctx->pc = 0x130a9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x130aa0: 0x4a1023  subu        $v0, $v0, $t2
    ctx->pc = 0x130aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x130aa4: 0x8e700028  lw          $s0, 0x28($s3)
    ctx->pc = 0x130aa4u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 40)));
    // 0x130aa8: 0xe2182a  slt         $v1, $a3, $v0
    ctx->pc = 0x130aa8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x130aac: 0xaa2821  addu        $a1, $a1, $t2
    ctx->pc = 0x130aacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 10)));
    // 0x130ab0: 0xe3100b  movn        $v0, $a3, $v1
    ctx->pc = 0x130ab0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 7));
    // 0x130ab4: 0x50182a  slt         $v1, $v0, $s0
    ctx->pc = 0x130ab4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x130ab8: 0xc04d758  jal         func_135D60
    ctx->pc = 0x130AB8u;
    SET_GPR_U32(ctx, 31, 0x130AC0u);
    ctx->pc = 0x130ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130AB8u;
            // 0x130abc: 0x43800b  movn        $s0, $v0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135D60u;
    if (runtime->hasFunction(0x135D60u)) {
        auto targetFn = runtime->lookupFunction(0x135D60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130AC0u; }
        if (ctx->pc != 0x130AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135D60_0x135d60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130AC0u; }
        if (ctx->pc != 0x130AC0u) { return; }
    }
    ctx->pc = 0x130AC0u;
label_130ac0:
    // 0x130ac0: 0x8fa60010  lw          $a2, 0x10($sp)
    ctx->pc = 0x130ac0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x130ac4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x130ac4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130ac8: 0xc04d772  jal         func_135DC8
    ctx->pc = 0x130AC8u;
    SET_GPR_U32(ctx, 31, 0x130AD0u);
    ctx->pc = 0x130ACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130AC8u;
            // 0x130acc: 0x8e640008  lw          $a0, 0x8($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135DC8u;
    if (runtime->hasFunction(0x135DC8u)) {
        auto targetFn = runtime->lookupFunction(0x135DC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130AD0u; }
        if (ctx->pc != 0x130AD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135DC8_0x135dc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130AD0u; }
        if (ctx->pc != 0x130AD0u) { return; }
    }
    ctx->pc = 0x130AD0u;
label_130ad0:
    // 0x130ad0: 0x8fa40014  lw          $a0, 0x14($sp)
    ctx->pc = 0x130ad0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x130ad4: 0x8fa30010  lw          $v1, 0x10($sp)
    ctx->pc = 0x130ad4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x130ad8: 0xae640024  sw          $a0, 0x24($s3)
    ctx->pc = 0x130ad8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 36), GPR_U32(ctx, 4));
    // 0x130adc: 0xae630020  sw          $v1, 0x20($s3)
    ctx->pc = 0x130adcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 32), GPR_U32(ctx, 3));
    // 0x130ae0: 0x1c40001d  bgtz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x130AE0u;
    {
        const bool branch_taken_0x130ae0 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x130AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130AE0u;
            // 0x130ae4: 0xae62001c  sw          $v0, 0x1C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130ae0) {
            ctx->pc = 0x130B58u;
            goto label_130b58;
        }
    }
    ctx->pc = 0x130AE8u;
    // 0x130ae8: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x130ae8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x130aec: 0x26700020  addiu       $s0, $s3, 0x20
    ctx->pc = 0x130aecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 32));
    // 0x130af0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x130af0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130af4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x130af4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130af8: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x130af8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x130afc: 0x40f809  jalr        $v0
    ctx->pc = 0x130AFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x130B04u);
        ctx->pc = 0x130B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130AFCu;
            // 0x130b00: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x130B04u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130830u: goto label_130830;
            case 0x130838u: goto label_130838;
            case 0x130858u: goto label_130858;
            case 0x130878u: goto label_130878;
            case 0x130890u: goto label_130890;
            case 0x1308A8u: goto label_1308a8;
            case 0x130910u: goto label_130910;
            case 0x130914u: goto label_130914;
            case 0x130950u: goto label_130950;
            case 0x130960u: goto label_130960;
            case 0x130974u: goto label_130974;
            case 0x13098Cu: goto label_13098c;
            case 0x130998u: goto label_130998;
            case 0x1309A0u: goto label_1309a0;
            case 0x1309A8u: goto label_1309a8;
            case 0x1309B4u: goto label_1309b4;
            case 0x1309E8u: goto label_1309e8;
            case 0x1309FCu: goto label_1309fc;
            case 0x130A04u: goto label_130a04;
            case 0x130A10u: goto label_130a10;
            case 0x130A1Cu: goto label_130a1c;
            case 0x130A40u: goto label_130a40;
            case 0x130A58u: goto label_130a58;
            case 0x130AC0u: goto label_130ac0;
            case 0x130AD0u: goto label_130ad0;
            case 0x130B04u: goto label_130b04;
            case 0x130B18u: goto label_130b18;
            case 0x130B24u: goto label_130b24;
            case 0x130B50u: goto label_130b50;
            case 0x130B58u: goto label_130b58;
            case 0x130B5Cu: goto label_130b5c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x130B04u; }
            if (ctx->pc != 0x130B04u) { return; }
        }
        }
    }
    ctx->pc = 0x130B04u;
label_130b04:
    // 0x130b04: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x130b04u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x130b08: 0xae600024  sw          $zero, 0x24($s3)
    ctx->pc = 0x130b08u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 36), GPR_U32(ctx, 0));
    // 0x130b0c: 0xa2600002  sb          $zero, 0x2($s3)
    ctx->pc = 0x130b0cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x130b10: 0xc04d7d4  jal         func_135F50
    ctx->pc = 0x130B10u;
    SET_GPR_U32(ctx, 31, 0x130B18u);
    ctx->pc = 0x130B14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130B10u;
            // 0x130b14: 0x8e640008  lw          $a0, 0x8($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135F50u;
    if (runtime->hasFunction(0x135F50u)) {
        auto targetFn = runtime->lookupFunction(0x135F50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130B18u; }
        if (ctx->pc != 0x130B18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135F50_0x135f50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130B18u; }
        if (ctx->pc != 0x130B18u) { return; }
    }
    ctx->pc = 0x130B18u;
label_130b18:
    // 0x130b18: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x130b18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x130b1c: 0x1443000f  bne         $v0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x130B1Cu;
    {
        const bool branch_taken_0x130b1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x130B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130B1Cu;
            // 0x130b20: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130b1c) {
            ctx->pc = 0x130B5Cu;
            goto label_130b5c;
        }
    }
    ctx->pc = 0x130B24u;
label_130b24:
    // 0x130b24: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x130b24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x130b28: 0x8c43a8b4  lw          $v1, -0x574C($v0)
    ctx->pc = 0x130b28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294944948)));
    // 0x130b2c: 0x460000b  bltz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x130B2Cu;
    {
        const bool branch_taken_0x130b2c = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x130B30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130B2Cu;
            // 0x130b30: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130b2c) {
            ctx->pc = 0x130B5Cu;
            goto label_130b5c;
        }
    }
    ctx->pc = 0x130B34u;
    // 0x130b34: 0x82620003  lb          $v0, 0x3($s3)
    ctx->pc = 0x130b34u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 3)));
    // 0x130b38: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x130b38u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x130b3c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x130B3Cu;
    {
        const bool branch_taken_0x130b3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x130B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130B3Cu;
            // 0x130b40: 0x92640003  lbu         $a0, 0x3($s3) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130b3c) {
            ctx->pc = 0x130B50u;
            goto label_130b50;
        }
    }
    ctx->pc = 0x130B44u;
    // 0x130b44: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x130b44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x130b48: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x130B48u;
    {
        const bool branch_taken_0x130b48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x130B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130B48u;
            // 0x130b4c: 0xa2620001  sb          $v0, 0x1($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130b48) {
            ctx->pc = 0x130B5Cu;
            goto label_130b5c;
        }
    }
    ctx->pc = 0x130B50u;
label_130b50:
    // 0x130b50: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x130b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x130b54: 0xa2620003  sb          $v0, 0x3($s3)
    ctx->pc = 0x130b54u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 3), (uint8_t)GPR_U32(ctx, 2));
label_130b58:
    // 0x130b58: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x130b58u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_130b5c:
    // 0x130b5c: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x130b5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x130b60: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x130b60u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x130b64: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x130b64u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x130b68: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x130b68u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x130b6c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x130b6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x130b70: 0x3e00008  jr          $ra
    ctx->pc = 0x130B70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130B74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130B70u;
            // 0x130b74: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130830u: goto label_130830;
            case 0x130838u: goto label_130838;
            case 0x130858u: goto label_130858;
            case 0x130878u: goto label_130878;
            case 0x130890u: goto label_130890;
            case 0x1308A8u: goto label_1308a8;
            case 0x130910u: goto label_130910;
            case 0x130914u: goto label_130914;
            case 0x130950u: goto label_130950;
            case 0x130960u: goto label_130960;
            case 0x130974u: goto label_130974;
            case 0x13098Cu: goto label_13098c;
            case 0x130998u: goto label_130998;
            case 0x1309A0u: goto label_1309a0;
            case 0x1309A8u: goto label_1309a8;
            case 0x1309B4u: goto label_1309b4;
            case 0x1309E8u: goto label_1309e8;
            case 0x1309FCu: goto label_1309fc;
            case 0x130A04u: goto label_130a04;
            case 0x130A10u: goto label_130a10;
            case 0x130A1Cu: goto label_130a1c;
            case 0x130A40u: goto label_130a40;
            case 0x130A58u: goto label_130a58;
            case 0x130AC0u: goto label_130ac0;
            case 0x130AD0u: goto label_130ad0;
            case 0x130B04u: goto label_130b04;
            case 0x130B18u: goto label_130b18;
            case 0x130B24u: goto label_130b24;
            case 0x130B50u: goto label_130b50;
            case 0x130B58u: goto label_130b58;
            case 0x130B5Cu: goto label_130b5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130B78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
