#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001297E0
// Address: 0x1297e0 - 0x129998
void sub_001297E0_0x1297e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001297E0_0x1297e0");
#endif

    switch (ctx->pc) {
        case 0x12980cu: goto label_12980c;
        case 0x129820u: goto label_129820;
        case 0x12985cu: goto label_12985c;
        case 0x129870u: goto label_129870;
        case 0x129878u: goto label_129878;
        case 0x129880u: goto label_129880;
        case 0x129894u: goto label_129894;
        case 0x12989cu: goto label_12989c;
        case 0x1298b4u: goto label_1298b4;
        case 0x1298fcu: goto label_1298fc;
        case 0x129910u: goto label_129910;
        case 0x12994cu: goto label_12994c;
        case 0x129960u: goto label_129960;
        case 0x12997cu: goto label_12997c;
        default: break;
    }

    ctx->pc = 0x1297e0u;

    // 0x1297e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1297e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1297e4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1297e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1297e8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1297e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1297ec: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1297ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1297f0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1297f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1297f4: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1297f4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1297f8: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1297f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1297fc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1297fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x129800: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x129800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x129804: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x129804u;
    SET_GPR_U32(ctx, 31, 0x12980Cu);
    ctx->pc = 0x129808u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129804u;
            // 0x129808: 0x2408ffff  addiu       $t0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12980Cu; }
        if (ctx->pc != 0x12980Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12980Cu; }
        if (ctx->pc != 0x12980Cu) { return; }
    }
    ctx->pc = 0x12980Cu;
label_12980c:
    // 0x12980c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12980cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129810: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x129810u;
    {
        const bool branch_taken_0x129810 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x129814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129810u;
            // 0x129814: 0x2484a058  addiu       $a0, $a0, -0x5FA8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942808));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129810) {
            ctx->pc = 0x129828u;
            goto label_129828;
        }
    }
    ctx->pc = 0x129818u;
    // 0x129818: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129818u;
    SET_GPR_U32(ctx, 31, 0x129820u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129820u; }
        if (ctx->pc != 0x129820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129820u; }
        if (ctx->pc != 0x129820u) { return; }
    }
    ctx->pc = 0x129820u;
label_129820:
    // 0x129820: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x129820u;
    {
        const bool branch_taken_0x129820 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129820u;
            // 0x129824: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129820) {
            ctx->pc = 0x1298B8u;
            goto label_1298b8;
        }
    }
    ctx->pc = 0x129828u;
label_129828:
    // 0x129828: 0x82030001  lb          $v1, 0x1($s0)
    ctx->pc = 0x129828u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x12982c: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12982cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x129830: 0x10710020  beq         $v1, $s1, . + 4 + (0x20 << 2)
    ctx->pc = 0x129830u;
    {
        const bool branch_taken_0x129830 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 17));
        ctx->pc = 0x129834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129830u;
            // 0x129834: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129830) {
            ctx->pc = 0x1298B4u;
            goto label_1298b4;
        }
    }
    ctx->pc = 0x129838u;
    // 0x129838: 0x54620003  bnel        $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x129838u;
    {
        const bool branch_taken_0x129838 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x129838) {
            ctx->pc = 0x12983Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129838u;
            // 0x12983c: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129848u;
            goto label_129848;
        }
    }
    ctx->pc = 0x129840u;
    // 0x129840: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x129840u;
    {
        const bool branch_taken_0x129840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129840u;
            // 0x129844: 0xa2110001  sb          $s1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129840) {
            ctx->pc = 0x1298B4u;
            goto label_1298b4;
        }
    }
    ctx->pc = 0x129848u;
label_129848:
    // 0x129848: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x129848u;
    {
        const bool branch_taken_0x129848 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x129848) {
            ctx->pc = 0x129868u;
            goto label_129868;
        }
    }
    ctx->pc = 0x129850u;
    // 0x129850: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129850u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129854: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129854u;
    SET_GPR_U32(ctx, 31, 0x12985Cu);
    ctx->pc = 0x129858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129854u;
            // 0x129858: 0x2484a080  addiu       $a0, $a0, -0x5F80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942848));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12985Cu; }
        if (ctx->pc != 0x12985Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12985Cu; }
        if (ctx->pc != 0x12985Cu) { return; }
    }
    ctx->pc = 0x12985Cu;
label_12985c:
    // 0x12985c: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x12985Cu;
    {
        const bool branch_taken_0x12985c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12985Cu;
            // 0x129860: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12985c) {
            ctx->pc = 0x1298B8u;
            goto label_1298b8;
        }
    }
    ctx->pc = 0x129864u;
    // 0x129864: 0x0  nop
    ctx->pc = 0x129864u;
    // NOP
label_129868:
    // 0x129868: 0xc04c1d2  jal         func_130748
    ctx->pc = 0x129868u;
    SET_GPR_U32(ctx, 31, 0x129870u);
    ctx->pc = 0x130748u;
    if (runtime->hasFunction(0x130748u)) {
        auto targetFn = runtime->lookupFunction(0x130748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129870u; }
        if (ctx->pc != 0x129870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130748_0x130748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129870u; }
        if (ctx->pc != 0x129870u) { return; }
    }
    ctx->pc = 0x129870u;
label_129870:
    // 0x129870: 0xc049938  jal         func_1264E0
    ctx->pc = 0x129870u;
    SET_GPR_U32(ctx, 31, 0x129878u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129878u; }
        if (ctx->pc != 0x129878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129878u; }
        if (ctx->pc != 0x129878u) { return; }
    }
    ctx->pc = 0x129878u;
label_129878:
    // 0x129878: 0xc04c182  jal         func_130608
    ctx->pc = 0x129878u;
    SET_GPR_U32(ctx, 31, 0x129880u);
    ctx->pc = 0x12987Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129878u;
            // 0x12987c: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130608u;
    if (runtime->hasFunction(0x130608u)) {
        auto targetFn = runtime->lookupFunction(0x130608u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129880u; }
        if (ctx->pc != 0x129880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130608_0x130608(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129880u; }
        if (ctx->pc != 0x129880u) { return; }
    }
    ctx->pc = 0x129880u;
label_129880:
    // 0x129880: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x129880u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x129884: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x129884u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129888: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x129888u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x12988c: 0xc04a4b8  jal         func_1292E0
    ctx->pc = 0x12988Cu;
    SET_GPR_U32(ctx, 31, 0x129894u);
    ctx->pc = 0x129890u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12988Cu;
            // 0x129890: 0xae020020  sw          $v0, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1292E0u;
    if (runtime->hasFunction(0x1292E0u)) {
        auto targetFn = runtime->lookupFunction(0x1292E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129894u; }
        if (ctx->pc != 0x129894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001292E0_0x1292e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129894u; }
        if (ctx->pc != 0x129894u) { return; }
    }
    ctx->pc = 0x129894u;
label_129894:
    // 0x129894: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x129894u;
    SET_GPR_U32(ctx, 31, 0x12989Cu);
    ctx->pc = 0x129898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129894u;
            // 0x129898: 0xa2110001  sb          $s1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12989Cu; }
        if (ctx->pc != 0x12989Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12989Cu; }
        if (ctx->pc != 0x12989Cu) { return; }
    }
    ctx->pc = 0x12989Cu;
label_12989c:
    // 0x12989c: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x12989cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1298a0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1298a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1298a4: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1298a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1298a8: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1298a8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1298ac: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x1298ACu;
    SET_GPR_U32(ctx, 31, 0x1298B4u);
    ctx->pc = 0x1298B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1298ACu;
            // 0x1298b0: 0x2408ffff  addiu       $t0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1298B4u; }
        if (ctx->pc != 0x1298B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1298B4u; }
        if (ctx->pc != 0x1298B4u) { return; }
    }
    ctx->pc = 0x1298B4u;
label_1298b4:
    // 0x1298b4: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1298b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
label_1298b8:
    // 0x1298b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1298b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1298bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1298bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1298c0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1298c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1298c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1298C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1298C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1298C4u;
            // 0x1298c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12980Cu: goto label_12980c;
            case 0x129820u: goto label_129820;
            case 0x129828u: goto label_129828;
            case 0x129848u: goto label_129848;
            case 0x12985Cu: goto label_12985c;
            case 0x129868u: goto label_129868;
            case 0x129870u: goto label_129870;
            case 0x129878u: goto label_129878;
            case 0x129880u: goto label_129880;
            case 0x129894u: goto label_129894;
            case 0x12989Cu: goto label_12989c;
            case 0x1298B4u: goto label_1298b4;
            case 0x1298B8u: goto label_1298b8;
            case 0x1298FCu: goto label_1298fc;
            case 0x129910u: goto label_129910;
            case 0x129918u: goto label_129918;
            case 0x129938u: goto label_129938;
            case 0x12994Cu: goto label_12994c;
            case 0x129958u: goto label_129958;
            case 0x129960u: goto label_129960;
            case 0x12997Cu: goto label_12997c;
            case 0x129980u: goto label_129980;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1298CCu;
    // 0x1298cc: 0x0  nop
    ctx->pc = 0x1298ccu;
    // NOP
    // 0x1298d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1298d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1298d4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1298d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1298d8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1298d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1298dc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1298dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1298e0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1298e0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1298e4: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1298e4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1298e8: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x1298e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1298ec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1298ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1298f0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1298f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1298f4: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x1298F4u;
    SET_GPR_U32(ctx, 31, 0x1298FCu);
    ctx->pc = 0x1298F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1298F4u;
            // 0x1298f8: 0x2408ffff  addiu       $t0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1298FCu; }
        if (ctx->pc != 0x1298FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1298FCu; }
        if (ctx->pc != 0x1298FCu) { return; }
    }
    ctx->pc = 0x1298FCu;
label_1298fc:
    // 0x1298fc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1298fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129900: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x129900u;
    {
        const bool branch_taken_0x129900 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x129904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129900u;
            // 0x129904: 0x2484a0b0  addiu       $a0, $a0, -0x5F50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942896));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129900) {
            ctx->pc = 0x129918u;
            goto label_129918;
        }
    }
    ctx->pc = 0x129908u;
    // 0x129908: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129908u;
    SET_GPR_U32(ctx, 31, 0x129910u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129910u; }
        if (ctx->pc != 0x129910u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129910u; }
        if (ctx->pc != 0x129910u) { return; }
    }
    ctx->pc = 0x129910u;
label_129910:
    // 0x129910: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x129910u;
    {
        const bool branch_taken_0x129910 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129910u;
            // 0x129914: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129910) {
            ctx->pc = 0x129980u;
            goto label_129980;
        }
    }
    ctx->pc = 0x129918u;
label_129918:
    // 0x129918: 0x82030001  lb          $v1, 0x1($s0)
    ctx->pc = 0x129918u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x12991c: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12991cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x129920: 0x10710016  beq         $v1, $s1, . + 4 + (0x16 << 2)
    ctx->pc = 0x129920u;
    {
        const bool branch_taken_0x129920 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 17));
        ctx->pc = 0x129924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129920u;
            // 0x129924: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129920) {
            ctx->pc = 0x12997Cu;
            goto label_12997c;
        }
    }
    ctx->pc = 0x129928u;
    // 0x129928: 0x54620003  bnel        $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x129928u;
    {
        const bool branch_taken_0x129928 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x129928) {
            ctx->pc = 0x12992Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129928u;
            // 0x12992c: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129938u;
            goto label_129938;
        }
    }
    ctx->pc = 0x129930u;
    // 0x129930: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x129930u;
    {
        const bool branch_taken_0x129930 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129930u;
            // 0x129934: 0xa2110001  sb          $s1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129930) {
            ctx->pc = 0x12997Cu;
            goto label_12997c;
        }
    }
    ctx->pc = 0x129938u;
label_129938:
    // 0x129938: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x129938u;
    {
        const bool branch_taken_0x129938 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x129938) {
            ctx->pc = 0x129958u;
            goto label_129958;
        }
    }
    ctx->pc = 0x129940u;
    // 0x129940: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129940u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129944: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129944u;
    SET_GPR_U32(ctx, 31, 0x12994Cu);
    ctx->pc = 0x129948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129944u;
            // 0x129948: 0x2484a0d8  addiu       $a0, $a0, -0x5F28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942936));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12994Cu; }
        if (ctx->pc != 0x12994Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12994Cu; }
        if (ctx->pc != 0x12994Cu) { return; }
    }
    ctx->pc = 0x12994Cu;
label_12994c:
    // 0x12994c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x12994Cu;
    {
        const bool branch_taken_0x12994c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12994Cu;
            // 0x129950: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12994c) {
            ctx->pc = 0x129980u;
            goto label_129980;
        }
    }
    ctx->pc = 0x129954u;
    // 0x129954: 0x0  nop
    ctx->pc = 0x129954u;
    // NOP
label_129958:
    // 0x129958: 0xc04c1b8  jal         func_1306E0
    ctx->pc = 0x129958u;
    SET_GPR_U32(ctx, 31, 0x129960u);
    ctx->pc = 0x1306E0u;
    if (runtime->hasFunction(0x1306E0u)) {
        auto targetFn = runtime->lookupFunction(0x1306E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129960u; }
        if (ctx->pc != 0x129960u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001306E0_0x1306e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129960u; }
        if (ctx->pc != 0x129960u) { return; }
    }
    ctx->pc = 0x129960u;
label_129960:
    // 0x129960: 0xa2110003  sb          $s1, 0x3($s0)
    ctx->pc = 0x129960u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 17));
    // 0x129964: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x129964u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x129968: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x129968u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12996c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x12996cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129970: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x129970u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x129974: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x129974u;
    SET_GPR_U32(ctx, 31, 0x12997Cu);
    ctx->pc = 0x129978u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129974u;
            // 0x129978: 0x2408ffff  addiu       $t0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12997Cu; }
        if (ctx->pc != 0x12997Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12997Cu; }
        if (ctx->pc != 0x12997Cu) { return; }
    }
    ctx->pc = 0x12997Cu;
label_12997c:
    // 0x12997c: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x12997cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
label_129980:
    // 0x129980: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x129980u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129984: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x129984u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129988: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x129988u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12998c: 0x3e00008  jr          $ra
    ctx->pc = 0x12998Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12998Cu;
            // 0x129990: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12980Cu: goto label_12980c;
            case 0x129820u: goto label_129820;
            case 0x129828u: goto label_129828;
            case 0x129848u: goto label_129848;
            case 0x12985Cu: goto label_12985c;
            case 0x129868u: goto label_129868;
            case 0x129870u: goto label_129870;
            case 0x129878u: goto label_129878;
            case 0x129880u: goto label_129880;
            case 0x129894u: goto label_129894;
            case 0x12989Cu: goto label_12989c;
            case 0x1298B4u: goto label_1298b4;
            case 0x1298B8u: goto label_1298b8;
            case 0x1298FCu: goto label_1298fc;
            case 0x129910u: goto label_129910;
            case 0x129918u: goto label_129918;
            case 0x129938u: goto label_129938;
            case 0x12994Cu: goto label_12994c;
            case 0x129958u: goto label_129958;
            case 0x129960u: goto label_129960;
            case 0x12997Cu: goto label_12997c;
            case 0x129980u: goto label_129980;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129994u;
    // 0x129994: 0x0  nop
    ctx->pc = 0x129994u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
