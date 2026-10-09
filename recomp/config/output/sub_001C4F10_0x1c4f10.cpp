#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C4F10
// Address: 0x1c4f10 - 0x1c51b0
void sub_001C4F10_0x1c4f10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C4F10_0x1c4f10");
#endif

    switch (ctx->pc) {
        case 0x1c4f58u: goto label_1c4f58;
        case 0x1c4f64u: goto label_1c4f64;
        case 0x1c4f70u: goto label_1c4f70;
        case 0x1c4f84u: goto label_1c4f84;
        case 0x1c4f94u: goto label_1c4f94;
        case 0x1c4fa4u: goto label_1c4fa4;
        case 0x1c4fbcu: goto label_1c4fbc;
        case 0x1c4fccu: goto label_1c4fcc;
        case 0x1c4fe8u: goto label_1c4fe8;
        case 0x1c500cu: goto label_1c500c;
        case 0x1c501cu: goto label_1c501c;
        case 0x1c5034u: goto label_1c5034;
        case 0x1c504cu: goto label_1c504c;
        case 0x1c505cu: goto label_1c505c;
        case 0x1c5074u: goto label_1c5074;
        case 0x1c5094u: goto label_1c5094;
        case 0x1c50a0u: goto label_1c50a0;
        case 0x1c50b0u: goto label_1c50b0;
        case 0x1c50c8u: goto label_1c50c8;
        case 0x1c50e4u: goto label_1c50e4;
        case 0x1c5108u: goto label_1c5108;
        case 0x1c5120u: goto label_1c5120;
        case 0x1c5140u: goto label_1c5140;
        case 0x1c5164u: goto label_1c5164;
        case 0x1c5180u: goto label_1c5180;
        default: break;
    }

    ctx->pc = 0x1c4f10u;

    // 0x1c4f10: 0x27bdfeb0  addiu       $sp, $sp, -0x150
    ctx->pc = 0x1c4f10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966960));
    // 0x1c4f14: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1c4f14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1c4f18: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x1c4f18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x1c4f1c: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1c4f1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1c4f20: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1c4f20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1c4f24: 0x3c170032  lui         $s7, 0x32
    ctx->pc = 0x1c4f24u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)50 << 16));
    // 0x1c4f28: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1c4f28u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1c4f2c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1c4f2cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1c4f30: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c4f30u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c4f34: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c4f34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c4f38: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1c4f38u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c4f3c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c4f3cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c4f40: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c4f40u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c4f44: 0x8c84002c  lw          $a0, 0x2C($a0)
    ctx->pc = 0x1c4f44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x1c4f48: 0x1080008d  beqz        $a0, . + 4 + (0x8D << 2)
    ctx->pc = 0x1C4F48u;
    {
        const bool branch_taken_0x1c4f48 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4F48u;
            // 0x1c4f4c: 0x26f743c0  addiu       $s7, $s7, 0x43C0 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 17344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4f48) {
            ctx->pc = 0x1C5180u;
            goto label_1c5180;
        }
    }
    ctx->pc = 0x1C4F50u;
    // 0x1c4f50: 0xc0707a8  jal         func_1C1EA0
    ctx->pc = 0x1C4F50u;
    SET_GPR_U32(ctx, 31, 0x1C4F58u);
    ctx->pc = 0x1C1EA0u;
    if (runtime->hasFunction(0x1C1EA0u)) {
        auto targetFn = runtime->lookupFunction(0x1C1EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4F58u; }
        if (ctx->pc != 0x1C4F58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1EA0_0x1c1ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4F58u; }
        if (ctx->pc != 0x1C4F58u) { return; }
    }
    ctx->pc = 0x1C4F58u;
label_1c4f58:
    // 0x1c4f58: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1c4f58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c4f5c: 0xc06d574  jal         func_1B55D0
    ctx->pc = 0x1C4F5Cu;
    SET_GPR_U32(ctx, 31, 0x1C4F64u);
    ctx->pc = 0x1C4F60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4F5Cu;
            // 0x1c4f60: 0x24040014  addiu       $a0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B55D0u;
    if (runtime->hasFunction(0x1B55D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4F64u; }
        if (ctx->pc != 0x1C4F64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55D0_0x1b55d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4F64u; }
        if (ctx->pc != 0x1C4F64u) { return; }
    }
    ctx->pc = 0x1C4F64u;
label_1c4f64:
    // 0x1c4f64: 0x3c028080  lui         $v0, 0x8080
    ctx->pc = 0x1c4f64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32896 << 16));
    // 0x1c4f68: 0xc06d594  jal         func_1B5650
    ctx->pc = 0x1C4F68u;
    SET_GPR_U32(ctx, 31, 0x1C4F70u);
    ctx->pc = 0x1C4F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4F68u;
            // 0x1c4f6c: 0x34448080  ori         $a0, $v0, 0x8080 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32896);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5650u;
    if (runtime->hasFunction(0x1B5650u)) {
        auto targetFn = runtime->lookupFunction(0x1B5650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4F70u; }
        if (ctx->pc != 0x1C4F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5650_0x1b5650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4F70u; }
        if (ctx->pc != 0x1C4F70u) { return; }
    }
    ctx->pc = 0x1C4F70u;
label_1c4f70:
    // 0x1c4f70: 0x8e7200d8  lw          $s2, 0xD8($s3)
    ctx->pc = 0x1c4f70u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 216)));
    // 0x1c4f74: 0xb02d  daddu       $s6, $zero, $zero
    ctx->pc = 0x1c4f74u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c4f78: 0x8e7100d4  lw          $s1, 0xD4($s3)
    ctx->pc = 0x1c4f78u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 212)));
    // 0x1c4f7c: 0x10000069  b           . + 4 + (0x69 << 2)
    ctx->pc = 0x1C4F7Cu;
    {
        const bool branch_taken_0x1c4f7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4F80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4F7Cu;
            // 0x1c4f80: 0x27be0142  addiu       $fp, $sp, 0x142 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), 322));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4f7c) {
            ctx->pc = 0x1C5124u;
            goto label_1c5124;
        }
    }
    ctx->pc = 0x1C4F84u;
label_1c4f84:
    // 0x1c4f84: 0x27b500a0  addiu       $s5, $sp, 0xA0
    ctx->pc = 0x1c4f84u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1c4f88: 0xa3a000f0  sb          $zero, 0xF0($sp)
    ctx->pc = 0x1c4f88u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 240), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c4f8c: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1C4F8Cu;
    SET_GPR_U32(ctx, 31, 0x1C4F94u);
    ctx->pc = 0x1C4F90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4F8Cu;
            // 0x1c4f90: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4F94u; }
        if (ctx->pc != 0x1C4F94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4F94u; }
        if (ctx->pc != 0x1C4F94u) { return; }
    }
    ctx->pc = 0x1C4F94u;
label_1c4f94:
    // 0x1c4f94: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c4f94u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c4f98: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1c4f98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c4f9c: 0xc042e02  jal         func_10B808
    ctx->pc = 0x1C4F9Cu;
    SET_GPR_U32(ctx, 31, 0x1C4FA4u);
    ctx->pc = 0x1C4FA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4F9Cu;
            // 0x1c4fa0: 0x24a52d18  addiu       $a1, $a1, 0x2D18 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11544));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B808u;
    if (runtime->hasFunction(0x10B808u)) {
        auto targetFn = runtime->lookupFunction(0x10B808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4FA4u; }
        if (ctx->pc != 0x1C4FA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B808_0x10b808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4FA4u; }
        if (ctx->pc != 0x1C4FA4u) { return; }
    }
    ctx->pc = 0x1C4FA4u;
label_1c4fa4:
    // 0x1c4fa4: 0x1040001f  beqz        $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x1C4FA4u;
    {
        const bool branch_taken_0x1c4fa4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4FA4u;
            // 0x1c4fa8: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4fa4) {
            ctx->pc = 0x1C5024u;
            goto label_1c5024;
        }
    }
    ctx->pc = 0x1C4FACu;
    // 0x1c4fac: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x1c4facu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c4fb0: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c4fb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c4fb4: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C4FB4u;
    SET_GPR_U32(ctx, 31, 0x1C4FBCu);
    ctx->pc = 0x1C4FB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4FB4u;
            // 0x1c4fb8: 0xa2800000  sb          $zero, 0x0($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4FBCu; }
        if (ctx->pc != 0x1C4FBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4FBCu; }
        if (ctx->pc != 0x1C4FBCu) { return; }
    }
    ctx->pc = 0x1C4FBCu;
label_1c4fbc:
    // 0x1c4fbc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c4fbcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c4fc0: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c4fc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c4fc4: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C4FC4u;
    SET_GPR_U32(ctx, 31, 0x1C4FCCu);
    ctx->pc = 0x1C4FC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4FC4u;
            // 0x1c4fc8: 0x24a52d20  addiu       $a1, $a1, 0x2D20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11552));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4FCCu; }
        if (ctx->pc != 0x1C4FCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4FCCu; }
        if (ctx->pc != 0x1C4FCCu) { return; }
    }
    ctx->pc = 0x1C4FCCu;
label_1c4fcc:
    // 0x1c4fcc: 0x92e2003d  lbu         $v0, 0x3D($s7)
    ctx->pc = 0x1c4fccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 23), 61)));
    // 0x1c4fd0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C4FD0u;
    {
        const bool branch_taken_0x1c4fd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C4FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4FD0u;
            // 0x1c4fd4: 0x26950002  addiu       $s5, $s4, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 20), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4fd0) {
            ctx->pc = 0x1C4FF0u;
            goto label_1c4ff0;
        }
    }
    ctx->pc = 0x1C4FD8u;
    // 0x1c4fd8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c4fd8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c4fdc: 0x27a40140  addiu       $a0, $sp, 0x140
    ctx->pc = 0x1c4fdcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
    // 0x1c4fe0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1C4FE0u;
    SET_GPR_U32(ctx, 31, 0x1C4FE8u);
    ctx->pc = 0x1C4FE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4FE0u;
            // 0x1c4fe4: 0x24a52d28  addiu       $a1, $a1, 0x2D28 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11560));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4FE8u; }
        if (ctx->pc != 0x1C4FE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4FE8u; }
        if (ctx->pc != 0x1C4FE8u) { return; }
    }
    ctx->pc = 0x1C4FE8u;
label_1c4fe8:
    // 0x1c4fe8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C4FE8u;
    {
        const bool branch_taken_0x1c4fe8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4FE8u;
            // 0x1c4fec: 0xa3c00000  sb          $zero, 0x0($fp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 30), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4fe8) {
            ctx->pc = 0x1C5000u;
            goto label_1c5000;
        }
    }
    ctx->pc = 0x1C4FF0u;
label_1c4ff0:
    // 0x1c4ff0: 0x24020031  addiu       $v0, $zero, 0x31
    ctx->pc = 0x1c4ff0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
    // 0x1c4ff4: 0xa3a20140  sb          $v0, 0x140($sp)
    ctx->pc = 0x1c4ff4u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 320), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c4ff8: 0x27a20141  addiu       $v0, $sp, 0x141
    ctx->pc = 0x1c4ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 321));
    // 0x1c4ffc: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x1c4ffcu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
label_1c5000:
    // 0x1c5000: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c5000u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c5004: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C5004u;
    SET_GPR_U32(ctx, 31, 0x1C500Cu);
    ctx->pc = 0x1C5008u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5004u;
            // 0x1c5008: 0x27a50140  addiu       $a1, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C500Cu; }
        if (ctx->pc != 0x1C500Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C500Cu; }
        if (ctx->pc != 0x1C500Cu) { return; }
    }
    ctx->pc = 0x1C500Cu;
label_1c500c:
    // 0x1c500c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c500cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c5010: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c5010u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c5014: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C5014u;
    SET_GPR_U32(ctx, 31, 0x1C501Cu);
    ctx->pc = 0x1C5018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5014u;
            // 0x1c5018: 0x24a52d30  addiu       $a1, $a1, 0x2D30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11568));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C501Cu; }
        if (ctx->pc != 0x1C501Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C501Cu; }
        if (ctx->pc != 0x1C501Cu) { return; }
    }
    ctx->pc = 0x1C501Cu;
label_1c501c:
    // 0x1c501c: 0x1000ffdd  b           . + 4 + (-0x23 << 2)
    ctx->pc = 0x1C501Cu;
    {
        const bool branch_taken_0x1c501c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c501c) {
            ctx->pc = 0x1C4F94u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c4f94;
        }
    }
    ctx->pc = 0x1C5024u;
label_1c5024:
    // 0x1c5024: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c5024u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c5028: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1c5028u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c502c: 0xc042e02  jal         func_10B808
    ctx->pc = 0x1C502Cu;
    SET_GPR_U32(ctx, 31, 0x1C5034u);
    ctx->pc = 0x1C5030u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C502Cu;
            // 0x1c5030: 0x24a52d38  addiu       $a1, $a1, 0x2D38 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11576));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B808u;
    if (runtime->hasFunction(0x10B808u)) {
        auto targetFn = runtime->lookupFunction(0x10B808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5034u; }
        if (ctx->pc != 0x1C5034u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B808_0x10b808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5034u; }
        if (ctx->pc != 0x1C5034u) { return; }
    }
    ctx->pc = 0x1C5034u;
label_1c5034:
    // 0x1c5034: 0x10400020  beqz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1C5034u;
    {
        const bool branch_taken_0x1c5034 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5034u;
            // 0x1c5038: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5034) {
            ctx->pc = 0x1C50B8u;
            goto label_1c50b8;
        }
    }
    ctx->pc = 0x1C503Cu;
    // 0x1c503c: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x1c503cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5040: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c5040u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c5044: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C5044u;
    SET_GPR_U32(ctx, 31, 0x1C504Cu);
    ctx->pc = 0x1C5048u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5044u;
            // 0x1c5048: 0xa2800000  sb          $zero, 0x0($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C504Cu; }
        if (ctx->pc != 0x1C504Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C504Cu; }
        if (ctx->pc != 0x1C504Cu) { return; }
    }
    ctx->pc = 0x1C504Cu;
label_1c504c:
    // 0x1c504c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c504cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c5050: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c5050u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c5054: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C5054u;
    SET_GPR_U32(ctx, 31, 0x1C505Cu);
    ctx->pc = 0x1C5058u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5054u;
            // 0x1c5058: 0x24a52d20  addiu       $a1, $a1, 0x2D20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11552));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C505Cu; }
        if (ctx->pc != 0x1C505Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C505Cu; }
        if (ctx->pc != 0x1C505Cu) { return; }
    }
    ctx->pc = 0x1C505Cu;
label_1c505c:
    // 0x1c505c: 0x92e2003d  lbu         $v0, 0x3D($s7)
    ctx->pc = 0x1c505cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 23), 61)));
    // 0x1c5060: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C5060u;
    {
        const bool branch_taken_0x1c5060 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5060u;
            // 0x1c5064: 0x26950002  addiu       $s5, $s4, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 20), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5060) {
            ctx->pc = 0x1C5080u;
            goto label_1c5080;
        }
    }
    ctx->pc = 0x1C5068u;
    // 0x1c5068: 0x8e650028  lw          $a1, 0x28($s3)
    ctx->pc = 0x1c5068u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 40)));
    // 0x1c506c: 0xc0708f8  jal         func_1C23E0
    ctx->pc = 0x1C506Cu;
    SET_GPR_U32(ctx, 31, 0x1C5074u);
    ctx->pc = 0x1C5070u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C506Cu;
            // 0x1c5070: 0x27a40140  addiu       $a0, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C23E0u;
    if (runtime->hasFunction(0x1C23E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C23E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5074u; }
        if (ctx->pc != 0x1C5074u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C23E0_0x1c23e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5074u; }
        if (ctx->pc != 0x1C5074u) { return; }
    }
    ctx->pc = 0x1C5074u;
label_1c5074:
    // 0x1c5074: 0x27a20146  addiu       $v0, $sp, 0x146
    ctx->pc = 0x1c5074u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 326));
    // 0x1c5078: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C5078u;
    {
        const bool branch_taken_0x1c5078 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C507Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5078u;
            // 0x1c507c: 0xa0400000  sb          $zero, 0x0($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5078) {
            ctx->pc = 0x1C5094u;
            goto label_1c5094;
        }
    }
    ctx->pc = 0x1C5080u;
label_1c5080:
    // 0x1c5080: 0x8e660028  lw          $a2, 0x28($s3)
    ctx->pc = 0x1c5080u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 40)));
    // 0x1c5084: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c5084u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c5088: 0x27a40140  addiu       $a0, $sp, 0x140
    ctx->pc = 0x1c5088u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
    // 0x1c508c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C508Cu;
    SET_GPR_U32(ctx, 31, 0x1C5094u);
    ctx->pc = 0x1C5090u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C508Cu;
            // 0x1c5090: 0x24a52d40  addiu       $a1, $a1, 0x2D40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11584));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5094u; }
        if (ctx->pc != 0x1C5094u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5094u; }
        if (ctx->pc != 0x1C5094u) { return; }
    }
    ctx->pc = 0x1C5094u;
label_1c5094:
    // 0x1c5094: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c5094u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c5098: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C5098u;
    SET_GPR_U32(ctx, 31, 0x1C50A0u);
    ctx->pc = 0x1C509Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5098u;
            // 0x1c509c: 0x27a50140  addiu       $a1, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C50A0u; }
        if (ctx->pc != 0x1C50A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C50A0u; }
        if (ctx->pc != 0x1C50A0u) { return; }
    }
    ctx->pc = 0x1C50A0u;
label_1c50a0:
    // 0x1c50a0: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c50a0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c50a4: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c50a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c50a8: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C50A8u;
    SET_GPR_U32(ctx, 31, 0x1C50B0u);
    ctx->pc = 0x1C50ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C50A8u;
            // 0x1c50ac: 0x24a52d30  addiu       $a1, $a1, 0x2D30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11568));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C50B0u; }
        if (ctx->pc != 0x1C50B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C50B0u; }
        if (ctx->pc != 0x1C50B0u) { return; }
    }
    ctx->pc = 0x1C50B0u;
label_1c50b0:
    // 0x1c50b0: 0x1000ffb8  b           . + 4 + (-0x48 << 2)
    ctx->pc = 0x1C50B0u;
    {
        const bool branch_taken_0x1c50b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c50b0) {
            ctx->pc = 0x1C4F94u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c4f94;
        }
    }
    ctx->pc = 0x1C50B8u;
label_1c50b8:
    // 0x1c50b8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c50b8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c50bc: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1c50bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c50c0: 0xc042e02  jal         func_10B808
    ctx->pc = 0x1C50C0u;
    SET_GPR_U32(ctx, 31, 0x1C50C8u);
    ctx->pc = 0x1C50C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C50C0u;
            // 0x1c50c4: 0x24a52d48  addiu       $a1, $a1, 0x2D48 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11592));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B808u;
    if (runtime->hasFunction(0x10B808u)) {
        auto targetFn = runtime->lookupFunction(0x10B808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C50C8u; }
        if (ctx->pc != 0x1C50C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B808_0x10b808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C50C8u; }
        if (ctx->pc != 0x1C50C8u) { return; }
    }
    ctx->pc = 0x1C50C8u;
label_1c50c8:
    // 0x1c50c8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C50C8u;
    {
        const bool branch_taken_0x1c50c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C50CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C50C8u;
            // 0x1c50cc: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c50c8) {
            ctx->pc = 0x1C50DCu;
            goto label_1c50dc;
        }
    }
    ctx->pc = 0x1C50D0u;
    // 0x1c50d0: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x1c50d0u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c50d4: 0x1000ffaf  b           . + 4 + (-0x51 << 2)
    ctx->pc = 0x1C50D4u;
    {
        const bool branch_taken_0x1c50d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C50D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C50D4u;
            // 0x1c50d8: 0x24160001  addiu       $s6, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c50d4) {
            ctx->pc = 0x1C4F94u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c4f94;
        }
    }
    ctx->pc = 0x1C50DCu;
label_1c50dc:
    // 0x1c50dc: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C50DCu;
    SET_GPR_U32(ctx, 31, 0x1C50E4u);
    ctx->pc = 0x1C50E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C50DCu;
            // 0x1c50e0: 0x27a400f0  addiu       $a0, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C50E4u; }
        if (ctx->pc != 0x1C50E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C50E4u; }
        if (ctx->pc != 0x1C50E4u) { return; }
    }
    ctx->pc = 0x1C50E4u;
label_1c50e4:
    // 0x1c50e4: 0x8e630020  lw          $v1, 0x20($s3)
    ctx->pc = 0x1c50e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 32)));
    // 0x1c50e8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c50e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c50ec: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C50ECu;
    {
        const bool branch_taken_0x1c50ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C50F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C50ECu;
            // 0x1c50f0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c50ec) {
            ctx->pc = 0x1C5110u;
            goto label_1c5110;
        }
    }
    ctx->pc = 0x1C50F4u;
    // 0x1c50f4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c50f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c50f8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1c50f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c50fc: 0x27a600f0  addiu       $a2, $sp, 0xF0
    ctx->pc = 0x1c50fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c5100: 0xc070848  jal         func_1C2120
    ctx->pc = 0x1C5100u;
    SET_GPR_U32(ctx, 31, 0x1C5108u);
    ctx->pc = 0x1C5104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5100u;
            // 0x1c5104: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2120u;
    if (runtime->hasFunction(0x1C2120u)) {
        auto targetFn = runtime->lookupFunction(0x1C2120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5108u; }
        if (ctx->pc != 0x1C5108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2120_0x1c2120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5108u; }
        if (ctx->pc != 0x1C5108u) { return; }
    }
    ctx->pc = 0x1C5108u;
label_1c5108:
    // 0x1c5108: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C5108u;
    {
        const bool branch_taken_0x1c5108 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C510Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5108u;
            // 0x1c510c: 0x26520016  addiu       $s2, $s2, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5108) {
            ctx->pc = 0x1C5124u;
            goto label_1c5124;
        }
    }
    ctx->pc = 0x1C5110u;
label_1c5110:
    // 0x1c5110: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1c5110u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5114: 0x27a600f0  addiu       $a2, $sp, 0xF0
    ctx->pc = 0x1c5114u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c5118: 0xc070800  jal         func_1C2000
    ctx->pc = 0x1C5118u;
    SET_GPR_U32(ctx, 31, 0x1C5120u);
    ctx->pc = 0x1C511Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5118u;
            // 0x1c511c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2000u;
    if (runtime->hasFunction(0x1C2000u)) {
        auto targetFn = runtime->lookupFunction(0x1C2000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5120u; }
        if (ctx->pc != 0x1C5120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2000_0x1c2000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5120u; }
        if (ctx->pc != 0x1C5120u) { return; }
    }
    ctx->pc = 0x1C5120u;
label_1c5120:
    // 0x1c5120: 0x26520016  addiu       $s2, $s2, 0x16
    ctx->pc = 0x1c5120u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 22));
label_1c5124:
    // 0x1c5124: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x1c5124u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c5128: 0x14a0ff96  bnez        $a1, . + 4 + (-0x6A << 2)
    ctx->pc = 0x1C5128u;
    {
        const bool branch_taken_0x1c5128 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C512Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5128u;
            // 0x1c512c: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5128) {
            ctx->pc = 0x1C4F84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c4f84;
        }
    }
    ctx->pc = 0x1C5130u;
    // 0x1c5130: 0x12c00013  beqz        $s6, . + 4 + (0x13 << 2)
    ctx->pc = 0x1C5130u;
    {
        const bool branch_taken_0x1c5130 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5130u;
            // 0x1c5134: 0x2404001f  addiu       $a0, $zero, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5130) {
            ctx->pc = 0x1C5180u;
            goto label_1c5180;
        }
    }
    ctx->pc = 0x1C5138u;
    // 0x1c5138: 0xc0707a8  jal         func_1C1EA0
    ctx->pc = 0x1C5138u;
    SET_GPR_U32(ctx, 31, 0x1C5140u);
    ctx->pc = 0x1C1EA0u;
    if (runtime->hasFunction(0x1C1EA0u)) {
        auto targetFn = runtime->lookupFunction(0x1C1EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5140u; }
        if (ctx->pc != 0x1C5140u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1EA0_0x1c1ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5140u; }
        if (ctx->pc != 0x1C5140u) { return; }
    }
    ctx->pc = 0x1C5140u;
label_1c5140:
    // 0x1c5140: 0x8e640020  lw          $a0, 0x20($s3)
    ctx->pc = 0x1c5140u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 32)));
    // 0x1c5144: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c5144u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c5148: 0x14830008  bne         $a0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C5148u;
    {
        const bool branch_taken_0x1c5148 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1c5148) {
            ctx->pc = 0x1C516Cu;
            goto label_1c516c;
        }
    }
    ctx->pc = 0x1C5150u;
    // 0x1c5150: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1c5150u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c5154: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c5154u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5158: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1c5158u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c515c: 0xc070848  jal         func_1C2120
    ctx->pc = 0x1C515Cu;
    SET_GPR_U32(ctx, 31, 0x1C5164u);
    ctx->pc = 0x1C5160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C515Cu;
            // 0x1c5160: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2120u;
    if (runtime->hasFunction(0x1C2120u)) {
        auto targetFn = runtime->lookupFunction(0x1C2120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5164u; }
        if (ctx->pc != 0x1C5164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2120_0x1c2120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5164u; }
        if (ctx->pc != 0x1C5164u) { return; }
    }
    ctx->pc = 0x1C5164u;
label_1c5164:
    // 0x1c5164: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C5164u;
    {
        const bool branch_taken_0x1c5164 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5164u;
            // 0x1c5168: 0xdfbf0090  ld          $ra, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5164) {
            ctx->pc = 0x1C5184u;
            goto label_1c5184;
        }
    }
    ctx->pc = 0x1C516Cu;
label_1c516c:
    // 0x1c516c: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1c516cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c5170: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c5170u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5174: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1c5174u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5178: 0xc070800  jal         func_1C2000
    ctx->pc = 0x1C5178u;
    SET_GPR_U32(ctx, 31, 0x1C5180u);
    ctx->pc = 0x1C517Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5178u;
            // 0x1c517c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2000u;
    if (runtime->hasFunction(0x1C2000u)) {
        auto targetFn = runtime->lookupFunction(0x1C2000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5180u; }
        if (ctx->pc != 0x1C5180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2000_0x1c2000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5180u; }
        if (ctx->pc != 0x1C5180u) { return; }
    }
    ctx->pc = 0x1C5180u;
label_1c5180:
    // 0x1c5180: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1c5180u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1c5184:
    // 0x1c5184: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x1c5184u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1c5188: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1c5188u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1c518c: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1c518cu;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1c5190: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1c5190u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1c5194: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1c5194u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c5198: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c5198u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c519c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c519cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c51a0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c51a0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c51a4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c51a4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c51a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C51A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C51ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C51A8u;
            // 0x1c51ac: 0x27bd0150  addiu       $sp, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C4F58u: goto label_1c4f58;
            case 0x1C4F64u: goto label_1c4f64;
            case 0x1C4F70u: goto label_1c4f70;
            case 0x1C4F84u: goto label_1c4f84;
            case 0x1C4F94u: goto label_1c4f94;
            case 0x1C4FA4u: goto label_1c4fa4;
            case 0x1C4FBCu: goto label_1c4fbc;
            case 0x1C4FCCu: goto label_1c4fcc;
            case 0x1C4FE8u: goto label_1c4fe8;
            case 0x1C4FF0u: goto label_1c4ff0;
            case 0x1C5000u: goto label_1c5000;
            case 0x1C500Cu: goto label_1c500c;
            case 0x1C501Cu: goto label_1c501c;
            case 0x1C5024u: goto label_1c5024;
            case 0x1C5034u: goto label_1c5034;
            case 0x1C504Cu: goto label_1c504c;
            case 0x1C505Cu: goto label_1c505c;
            case 0x1C5074u: goto label_1c5074;
            case 0x1C5080u: goto label_1c5080;
            case 0x1C5094u: goto label_1c5094;
            case 0x1C50A0u: goto label_1c50a0;
            case 0x1C50B0u: goto label_1c50b0;
            case 0x1C50B8u: goto label_1c50b8;
            case 0x1C50C8u: goto label_1c50c8;
            case 0x1C50DCu: goto label_1c50dc;
            case 0x1C50E4u: goto label_1c50e4;
            case 0x1C5108u: goto label_1c5108;
            case 0x1C5110u: goto label_1c5110;
            case 0x1C5120u: goto label_1c5120;
            case 0x1C5124u: goto label_1c5124;
            case 0x1C5140u: goto label_1c5140;
            case 0x1C5164u: goto label_1c5164;
            case 0x1C516Cu: goto label_1c516c;
            case 0x1C5180u: goto label_1c5180;
            case 0x1C5184u: goto label_1c5184;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C51B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
