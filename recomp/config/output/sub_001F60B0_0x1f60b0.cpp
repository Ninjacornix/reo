#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F60B0
// Address: 0x1f60b0 - 0x1f6210
void sub_001F60B0_0x1f60b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F60B0_0x1f60b0");
#endif

    switch (ctx->pc) {
        case 0x1f6118u: goto label_1f6118;
        case 0x1f6148u: goto label_1f6148;
        case 0x1f615cu: goto label_1f615c;
        case 0x1f619cu: goto label_1f619c;
        case 0x1f61b4u: goto label_1f61b4;
        case 0x1f61dcu: goto label_1f61dc;
        default: break;
    }

    ctx->pc = 0x1f60b0u;

    // 0x1f60b0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1f60b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1f60b4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f60b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f60b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f60b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f60bc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f60bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f60c0: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f60c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f60c4: 0x8c830024  lw          $v1, 0x24($a0)
    ctx->pc = 0x1f60c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1f60c8: 0x1040004c  beqz        $v0, . + 4 + (0x4C << 2)
    ctx->pc = 0x1F60C8u;
    {
        const bool branch_taken_0x1f60c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F60CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F60C8u;
            // 0x1f60cc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f60c8) {
            ctx->pc = 0x1F61FCu;
            goto label_1f61fc;
        }
    }
    ctx->pc = 0x1F60D0u;
    // 0x1f60d0: 0x80630006  lb          $v1, 0x6($v1)
    ctx->pc = 0x1f60d0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 6)));
    // 0x1f60d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1f60d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f60d8: 0x1462000d  bne         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1F60D8u;
    {
        const bool branch_taken_0x1f60d8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1F60DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F60D8u;
            // 0x1f60dc: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f60d8) {
            ctx->pc = 0x1F6110u;
            goto label_1f6110;
        }
    }
    ctx->pc = 0x1F60E0u;
    // 0x1f60e0: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f60e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f60e4: 0xae02008c  sw          $v0, 0x8C($s0)
    ctx->pc = 0x1f60e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 2));
    // 0x1f60e8: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1f60e8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f60ec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f60ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f60f0: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f60f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f60f4: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f60f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f60f8: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f60f8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f60fc: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f60fcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6100: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6100u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6104: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6104u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6108: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x1F6108u;
    {
        const bool branch_taken_0x1f6108 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F610Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6108u;
            // 0x1f610c: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6108) {
            ctx->pc = 0x1F6200u;
            goto label_1f6200;
        }
    }
    ctx->pc = 0x1F6110u;
label_1f6110:
    // 0x1f6110: 0xc07d1f8  jal         func_1F47E0
    ctx->pc = 0x1F6110u;
    SET_GPR_U32(ctx, 31, 0x1F6118u);
    ctx->pc = 0x1F47E0u;
    if (runtime->hasFunction(0x1F47E0u)) {
        auto targetFn = runtime->lookupFunction(0x1F47E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6118u; }
        if (ctx->pc != 0x1F6118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F47E0_0x1f47e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6118u; }
        if (ctx->pc != 0x1F6118u) { return; }
    }
    ctx->pc = 0x1F6118u;
label_1f6118:
    // 0x1f6118: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1f6118u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1f611c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F611Cu;
    {
        const bool branch_taken_0x1f611c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F6120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F611Cu;
            // 0x1f6120: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f611c) {
            ctx->pc = 0x1F6140u;
            goto label_1f6140;
        }
    }
    ctx->pc = 0x1F6124u;
    // 0x1f6124: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f6124u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f6128: 0x24030012  addiu       $v1, $zero, 0x12
    ctx->pc = 0x1f6128u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1f612c: 0x8c2457c0  lw          $a0, 0x57C0($at)
    ctx->pc = 0x1f612cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 22464)));
    // 0x1f6130: 0x2402ffc2  addiu       $v0, $zero, -0x3E
    ctx->pc = 0x1f6130u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967234));
    // 0x1f6134: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1f6134u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6138: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1F6138u;
    {
        const bool branch_taken_0x1f6138 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F613Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6138u;
            // 0x1f613c: 0xa2030001  sb          $v1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6138) {
            ctx->pc = 0x1F6200u;
            goto label_1f6200;
        }
    }
    ctx->pc = 0x1F6140u;
label_1f6140:
    // 0x1f6140: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F6140u;
    SET_GPR_U32(ctx, 31, 0x1F6148u);
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6148u; }
        if (ctx->pc != 0x1F6148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6148u; }
        if (ctx->pc != 0x1F6148u) { return; }
    }
    ctx->pc = 0x1F6148u;
label_1f6148:
    // 0x1f6148: 0xae020078  sw          $v0, 0x78($s0)
    ctx->pc = 0x1f6148u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 120), GPR_U32(ctx, 2));
    // 0x1f614c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f614cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6150: 0x8e060074  lw          $a2, 0x74($s0)
    ctx->pc = 0x1f6150u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 116)));
    // 0x1f6154: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F6154u;
    SET_GPR_U32(ctx, 31, 0x1F615Cu);
    ctx->pc = 0x1F6158u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6154u;
            // 0x1f6158: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F615Cu; }
        if (ctx->pc != 0x1F615Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F615Cu; }
        if (ctx->pc != 0x1F615Cu) { return; }
    }
    ctx->pc = 0x1F615Cu;
label_1f615c:
    // 0x1f615c: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F615Cu;
    {
        const bool branch_taken_0x1f615c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F6160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F615Cu;
            // 0x1f6160: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f615c) {
            ctx->pc = 0x1F618Cu;
            goto label_1f618c;
        }
    }
    ctx->pc = 0x1F6164u;
    // 0x1f6164: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6164u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6168: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f6168u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f616c: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f616cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6170: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6170u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6174: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f6174u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6178: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f6178u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f617c: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f617cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6180: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6180u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6184: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6184u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6188: 0xa600000a  sh          $zero, 0xA($s0)
    ctx->pc = 0x1f6188u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f618c:
    // 0x1f618c: 0x8e050070  lw          $a1, 0x70($s0)
    ctx->pc = 0x1f618cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 112)));
    // 0x1f6190: 0x8e060074  lw          $a2, 0x74($s0)
    ctx->pc = 0x1f6190u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 116)));
    // 0x1f6194: 0xc042d10  jal         func_10B440
    ctx->pc = 0x1F6194u;
    SET_GPR_U32(ctx, 31, 0x1F619Cu);
    ctx->pc = 0x1F6198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6194u;
            // 0x1f6198: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F619Cu; }
        if (ctx->pc != 0x1F619Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F619Cu; }
        if (ctx->pc != 0x1F619Cu) { return; }
    }
    ctx->pc = 0x1F619Cu;
label_1f619c:
    // 0x1f619c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F619Cu;
    {
        const bool branch_taken_0x1f619c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F61A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F619Cu;
            // 0x1f61a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f619c) {
            ctx->pc = 0x1F61ACu;
            goto label_1f61ac;
        }
    }
    ctx->pc = 0x1F61A4u;
    // 0x1f61a4: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1F61A4u;
    {
        const bool branch_taken_0x1f61a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F61A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F61A4u;
            // 0x1f61a8: 0x2402ffc3  addiu       $v0, $zero, -0x3D (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967235));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f61a4) {
            ctx->pc = 0x1F6200u;
            goto label_1f6200;
        }
    }
    ctx->pc = 0x1F61ACu;
label_1f61ac:
    // 0x1f61ac: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F61ACu;
    SET_GPR_U32(ctx, 31, 0x1F61B4u);
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F61B4u; }
        if (ctx->pc != 0x1F61B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F61B4u; }
        if (ctx->pc != 0x1F61B4u) { return; }
    }
    ctx->pc = 0x1F61B4u;
label_1f61b4:
    // 0x1f61b4: 0xae02007c  sw          $v0, 0x7C($s0)
    ctx->pc = 0x1f61b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 124), GPR_U32(ctx, 2));
    // 0x1f61b8: 0x8e02007c  lw          $v0, 0x7C($s0)
    ctx->pc = 0x1f61b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x1f61bc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F61BCu;
    {
        const bool branch_taken_0x1f61bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f61bc) {
            ctx->pc = 0x1F61D0u;
            goto label_1f61d0;
        }
    }
    ctx->pc = 0x1F61C4u;
    // 0x1f61c4: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1f61c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1f61c8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1F61C8u;
    {
        const bool branch_taken_0x1f61c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F61CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F61C8u;
            // 0x1f61cc: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f61c8) {
            ctx->pc = 0x1F61F4u;
            goto label_1f61f4;
        }
    }
    ctx->pc = 0x1F61D0u;
label_1f61d0:
    // 0x1f61d0: 0xae000084  sw          $zero, 0x84($s0)
    ctx->pc = 0x1f61d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 132), GPR_U32(ctx, 0));
    // 0x1f61d4: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1F61D4u;
    SET_GPR_U32(ctx, 31, 0x1F61DCu);
    ctx->pc = 0x1F61D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F61D4u;
            // 0x1f61d8: 0x8e040070  lw          $a0, 0x70($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 112)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F61DCu; }
        if (ctx->pc != 0x1F61DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F61DCu; }
        if (ctx->pc != 0x1F61DCu) { return; }
    }
    ctx->pc = 0x1F61DCu;
label_1f61dc:
    // 0x1f61dc: 0x2443000c  addiu       $v1, $v0, 0xC
    ctx->pc = 0x1f61dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1f61e0: 0x240202fe  addiu       $v0, $zero, 0x2FE
    ctx->pc = 0x1f61e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 766));
    // 0x1f61e4: 0x431823  subu        $v1, $v0, $v1
    ctx->pc = 0x1f61e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f61e8: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1f61e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1f61ec: 0xa6030080  sh          $v1, 0x80($s0)
    ctx->pc = 0x1f61ecu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 128), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f61f0: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1f61f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f61f4:
    // 0x1f61f4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F61F4u;
    {
        const bool branch_taken_0x1f61f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F61F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F61F4u;
            // 0x1f61f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f61f4) {
            ctx->pc = 0x1F6200u;
            goto label_1f6200;
        }
    }
    ctx->pc = 0x1F61FCu;
label_1f61fc:
    // 0x1f61fc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f61fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f6200:
    // 0x1f6200: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f6200u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f6204: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f6204u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f6208: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6208u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F620Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6208u;
            // 0x1f620c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F6110u: goto label_1f6110;
            case 0x1F6118u: goto label_1f6118;
            case 0x1F6140u: goto label_1f6140;
            case 0x1F6148u: goto label_1f6148;
            case 0x1F615Cu: goto label_1f615c;
            case 0x1F618Cu: goto label_1f618c;
            case 0x1F619Cu: goto label_1f619c;
            case 0x1F61ACu: goto label_1f61ac;
            case 0x1F61B4u: goto label_1f61b4;
            case 0x1F61D0u: goto label_1f61d0;
            case 0x1F61DCu: goto label_1f61dc;
            case 0x1F61F4u: goto label_1f61f4;
            case 0x1F61FCu: goto label_1f61fc;
            case 0x1F6200u: goto label_1f6200;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6210u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
