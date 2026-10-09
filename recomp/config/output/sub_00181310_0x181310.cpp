#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181310
// Address: 0x181310 - 0x1813f0
void sub_00181310_0x181310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181310_0x181310");
#endif

    switch (ctx->pc) {
        case 0x181360u: goto label_181360;
        case 0x181390u: goto label_181390;
        case 0x1813b8u: goto label_1813b8;
        case 0x1813c8u: goto label_1813c8;
        default: break;
    }

    ctx->pc = 0x181310u;

    // 0x181310: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x181310u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x181314: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x181314u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x181318: 0x8c69fa10  lw          $t1, -0x5F0($v1)
    ctx->pc = 0x181318u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x18131c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18131cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181320: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x181320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x181324: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x181324u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181328: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x181328u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x18132c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x18132cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181330: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x181330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x181334: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x181334u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181338: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x181338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x18133c: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x18133cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181340: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x181340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x181344: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x181344u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181348: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x181348u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x18134c: 0x34428001  ori         $v0, $v0, 0x8001
    ctx->pc = 0x18134cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
    // 0x181350: 0x1120001e  beqz        $t1, . + 4 + (0x1E << 2)
    ctx->pc = 0x181350u;
    {
        const bool branch_taken_0x181350 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        ctx->pc = 0x181354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181350u;
            // 0x181354: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181350) {
            ctx->pc = 0x1813CCu;
            goto label_1813cc;
        }
    }
    ctx->pc = 0x181358u;
    // 0x181358: 0xc061e90  jal         func_187A40
    ctx->pc = 0x181358u;
    SET_GPR_U32(ctx, 31, 0x181360u);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181360u; }
        if (ctx->pc != 0x181360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181360u; }
        if (ctx->pc != 0x181360u) { return; }
    }
    ctx->pc = 0x181360u;
label_181360:
    // 0x181360: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x181360u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x181364: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181364u;
    {
        const bool branch_taken_0x181364 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181364u;
            // 0x181368: 0x24709500  addiu       $s0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181364) {
            ctx->pc = 0x181378u;
            goto label_181378;
        }
    }
    ctx->pc = 0x18136Cu;
    // 0x18136c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18136cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181370: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x181370u;
    {
        const bool branch_taken_0x181370 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181370u;
            // 0x181374: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181370) {
            ctx->pc = 0x1813CCu;
            goto label_1813cc;
        }
    }
    ctx->pc = 0x181378u;
label_181378:
    // 0x181378: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x181378u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x18137c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18137cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181380: 0x14600012  bnez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x181380u;
    {
        const bool branch_taken_0x181380 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x181384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181380u;
            // 0x181384: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181380) {
            ctx->pc = 0x1813CCu;
            goto label_1813cc;
        }
    }
    ctx->pc = 0x181388u;
    // 0x181388: 0xc042c56  jal         func_10B158
    ctx->pc = 0x181388u;
    SET_GPR_U32(ctx, 31, 0x181390u);
    ctx->pc = 0x18138Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181388u;
            // 0x18138c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181390u; }
        if (ctx->pc != 0x181390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181390u; }
        if (ctx->pc != 0x181390u) { return; }
    }
    ctx->pc = 0x181390u;
label_181390:
    // 0x181390: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x181390u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181394: 0x2c430080  sltiu       $v1, $v0, 0x80
    ctx->pc = 0x181394u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x181398: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181398u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18139c: 0x2604041c  addiu       $a0, $s0, 0x41C
    ctx->pc = 0x18139cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
    // 0x1813a0: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1813A0u;
    {
        const bool branch_taken_0x1813a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1813A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1813A0u;
            // 0x1813a4: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1813a0) {
            ctx->pc = 0x1813CCu;
            goto label_1813cc;
        }
    }
    ctx->pc = 0x1813A8u;
    // 0x1813a8: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1813a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1813ac: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x1813acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x1813b0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1813B0u;
    SET_GPR_U32(ctx, 31, 0x1813B8u);
    ctx->pc = 0x1813B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1813B0u;
            // 0x1813b4: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1813B8u; }
        if (ctx->pc != 0x1813B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1813B8u; }
        if (ctx->pc != 0x1813B8u) { return; }
    }
    ctx->pc = 0x1813B8u;
label_1813b8:
    // 0x1813b8: 0xae14000c  sw          $s4, 0xC($s0)
    ctx->pc = 0x1813b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 20));
    // 0x1813bc: 0xae130014  sw          $s3, 0x14($s0)
    ctx->pc = 0x1813bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 19));
    // 0x1813c0: 0xc062228  jal         func_1888A0
    ctx->pc = 0x1813C0u;
    SET_GPR_U32(ctx, 31, 0x1813C8u);
    ctx->pc = 0x1813C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1813C0u;
            // 0x1813c4: 0xae150010  sw          $s5, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1813C8u; }
        if (ctx->pc != 0x1813C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1813C8u; }
        if (ctx->pc != 0x1813C8u) { return; }
    }
    ctx->pc = 0x1813C8u;
label_1813c8:
    // 0x1813c8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1813c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1813cc:
    // 0x1813cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1813ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1813d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1813d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1813d4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1813d4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1813d8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1813d8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1813dc: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1813dcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1813e0: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1813e0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1813e4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1813e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1813e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1813E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1813ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1813E8u;
            // 0x1813ec: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181360u: goto label_181360;
            case 0x181378u: goto label_181378;
            case 0x181390u: goto label_181390;
            case 0x1813B8u: goto label_1813b8;
            case 0x1813C8u: goto label_1813c8;
            case 0x1813CCu: goto label_1813cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1813F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
