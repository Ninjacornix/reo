#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B4100
// Address: 0x1b4100 - 0x1b4450
void sub_001B4100_0x1b4100(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B4100_0x1b4100");
#endif

    switch (ctx->pc) {
        case 0x1b414cu: goto label_1b414c;
        case 0x1b4154u: goto label_1b4154;
        case 0x1b4174u: goto label_1b4174;
        case 0x1b417cu: goto label_1b417c;
        case 0x1b41a4u: goto label_1b41a4;
        case 0x1b41b0u: goto label_1b41b0;
        case 0x1b41ccu: goto label_1b41cc;
        case 0x1b41e8u: goto label_1b41e8;
        case 0x1b421cu: goto label_1b421c;
        case 0x1b42bcu: goto label_1b42bc;
        case 0x1b4344u: goto label_1b4344;
        case 0x1b4368u: goto label_1b4368;
        case 0x1b439cu: goto label_1b439c;
        case 0x1b43acu: goto label_1b43ac;
        case 0x1b43e0u: goto label_1b43e0;
        case 0x1b43ecu: goto label_1b43ec;
        case 0x1b440cu: goto label_1b440c;
        case 0x1b441cu: goto label_1b441c;
        default: break;
    }

    ctx->pc = 0x1b4100u;

    // 0x1b4100: 0x27bdfd10  addiu       $sp, $sp, -0x2F0
    ctx->pc = 0x1b4100u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966544));
    // 0x1b4104: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1b4104u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1b4108: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x1b4108u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x1b410c: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1b410cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1b4110: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1b4110u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1b4114: 0x80b82d  daddu       $s7, $a0, $zero
    ctx->pc = 0x1b4114u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4118: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1b4118u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1b411c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b411cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b4120: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1b4120u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4124: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b4124u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b4128: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1b4128u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b412c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b412cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b4130: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1b4130u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4134: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b4134u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b4138: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x1b4138u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b413c: 0x126000b7  beqz        $s3, . + 4 + (0xB7 << 2)
    ctx->pc = 0x1B413Cu;
    {
        const bool branch_taken_0x1b413c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B413Cu;
            // 0x1b4140: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b413c) {
            ctx->pc = 0x1B441Cu;
            goto label_1b441c;
        }
    }
    ctx->pc = 0x1B4144u;
    // 0x1b4144: 0xc06d574  jal         func_1B55D0
    ctx->pc = 0x1B4144u;
    SET_GPR_U32(ctx, 31, 0x1B414Cu);
    ctx->pc = 0x1B4148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4144u;
            // 0x1b4148: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B55D0u;
    if (runtime->hasFunction(0x1B55D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B414Cu; }
        if (ctx->pc != 0x1B414Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55D0_0x1b55d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B414Cu; }
        if (ctx->pc != 0x1B414Cu) { return; }
    }
    ctx->pc = 0x1B414Cu;
label_1b414c:
    // 0x1b414c: 0xc06d590  jal         func_1B5640
    ctx->pc = 0x1B414Cu;
    SET_GPR_U32(ctx, 31, 0x1B4154u);
    ctx->pc = 0x1B4150u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B414Cu;
            // 0x1b4150: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5640u;
    if (runtime->hasFunction(0x1B5640u)) {
        auto targetFn = runtime->lookupFunction(0x1B5640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4154u; }
        if (ctx->pc != 0x1B4154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5640_0x1b5640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4154u; }
        if (ctx->pc != 0x1B4154u) { return; }
    }
    ctx->pc = 0x1B4154u;
label_1b4154:
    // 0x1b4154: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1b4154u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1b4158: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1b4158u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b415c: 0xafa200c0  sw          $v0, 0xC0($sp)
    ctx->pc = 0x1b415cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 192), GPR_U32(ctx, 2));
    // 0x1b4160: 0x2e0802d  daddu       $s0, $s7, $zero
    ctx->pc = 0x1b4160u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4164: 0xa3a000e0  sb          $zero, 0xE0($sp)
    ctx->pc = 0x1b4164u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 224), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b4168: 0x27b100e0  addiu       $s1, $sp, 0xE0
    ctx->pc = 0x1b4168u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
    // 0x1b416c: 0xc06d574  jal         func_1B55D0
    ctx->pc = 0x1B416Cu;
    SET_GPR_U32(ctx, 31, 0x1B4174u);
    ctx->pc = 0x1B4170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B416Cu;
            // 0x1b4170: 0xafa000d0  sw          $zero, 0xD0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 208), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B55D0u;
    if (runtime->hasFunction(0x1B55D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4174u; }
        if (ctx->pc != 0x1B4174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55D0_0x1b55d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4174u; }
        if (ctx->pc != 0x1B4174u) { return; }
    }
    ctx->pc = 0x1B4174u;
label_1b4174:
    // 0x1b4174: 0xc06d590  jal         func_1B5640
    ctx->pc = 0x1B4174u;
    SET_GPR_U32(ctx, 31, 0x1B417Cu);
    ctx->pc = 0x1B4178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4174u;
            // 0x1b4178: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5640u;
    if (runtime->hasFunction(0x1B5640u)) {
        auto targetFn = runtime->lookupFunction(0x1B5640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B417Cu; }
        if (ctx->pc != 0x1B417Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5640_0x1b5640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B417Cu; }
        if (ctx->pc != 0x1B417Cu) { return; }
    }
    ctx->pc = 0x1B417Cu;
label_1b417c:
    // 0x1b417c: 0x324200ff  andi        $v0, $s2, 0xFF
    ctx->pc = 0x1b417cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1b4180: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b4180u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b4184: 0x8c23449c  lw          $v1, 0x449C($at)
    ctx->pc = 0x1b4184u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17564)));
    // 0x1b4188: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x1b4188u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1b418c: 0xafa200a0  sw          $v0, 0xA0($sp)
    ctx->pc = 0x1b418cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 2));
    // 0x1b4190: 0x8fa200a0  lw          $v0, 0xA0($sp)
    ctx->pc = 0x1b4190u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1b4194: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1b4194u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1b4198: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1b4198u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1b419c: 0xc06d594  jal         func_1B5650
    ctx->pc = 0x1B419Cu;
    SET_GPR_U32(ctx, 31, 0x1B41A4u);
    ctx->pc = 0x1B41A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B419Cu;
            // 0x1b41a0: 0x432025  or          $a0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5650u;
    if (runtime->hasFunction(0x1B5650u)) {
        auto targetFn = runtime->lookupFunction(0x1B5650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B41A4u; }
        if (ctx->pc != 0x1B41A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5650_0x1b5650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B41A4u; }
        if (ctx->pc != 0x1B41A4u) { return; }
    }
    ctx->pc = 0x1B41A4u;
label_1b41a4:
    // 0x1b41a4: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1b41a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b41a8: 0xc06d57c  jal         func_1B55F0
    ctx->pc = 0x1B41A8u;
    SET_GPR_U32(ctx, 31, 0x1B41B0u);
    ctx->pc = 0x1B41ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B41A8u;
            // 0x1b41ac: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B55F0u;
    if (runtime->hasFunction(0x1B55F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B41B0u; }
        if (ctx->pc != 0x1B41B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55F0_0x1b55f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B41B0u; }
        if (ctx->pc != 0x1B41B0u) { return; }
    }
    ctx->pc = 0x1B41B0u;
label_1b41b0:
    // 0x1b41b0: 0x141043  sra         $v0, $s4, 1
    ctx->pc = 0x1b41b0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 20), 1));
    // 0x1b41b4: 0xf02d  daddu       $fp, $zero, $zero
    ctx->pc = 0x1b41b4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b41b8: 0x6810004  bgez        $s4, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B41B8u;
    {
        const bool branch_taken_0x1b41b8 = (GPR_S64(ctx, 20) >= 0);
        ctx->pc = 0x1B41BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B41B8u;
            // 0x1b41bc: 0xafa200b0  sw          $v0, 0xB0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 176), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b41b8) {
            ctx->pc = 0x1B41CCu;
            goto label_1b41cc;
        }
    }
    ctx->pc = 0x1B41C0u;
    // 0x1b41c0: 0x26820001  addiu       $v0, $s4, 0x1
    ctx->pc = 0x1b41c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1b41c4: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1b41c4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1b41c8: 0xafa200b0  sw          $v0, 0xB0($sp)
    ctx->pc = 0x1b41c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 176), GPR_U32(ctx, 2));
label_1b41cc:
    // 0x1b41cc: 0x17c00014  bnez        $fp, . + 4 + (0x14 << 2)
    ctx->pc = 0x1B41CCu;
    {
        const bool branch_taken_0x1b41cc = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b41cc) {
            ctx->pc = 0x1B4220u;
            goto label_1b4220;
        }
    }
    ctx->pc = 0x1B41D4u;
    // 0x1b41d4: 0x8fa200d0  lw          $v0, 0xD0($sp)
    ctx->pc = 0x1b41d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x1b41d8: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1B41D8u;
    {
        const bool branch_taken_0x1b41d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B41DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B41D8u;
            // 0x1b41dc: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b41d8) {
            ctx->pc = 0x1B4220u;
            goto label_1b4220;
        }
    }
    ctx->pc = 0x1B41E0u;
    // 0x1b41e0: 0xc06cfe8  jal         func_1B3FA0
    ctx->pc = 0x1B41E0u;
    SET_GPR_U32(ctx, 31, 0x1B41E8u);
    ctx->pc = 0x1B3FA0u;
    if (runtime->hasFunction(0x1B3FA0u)) {
        auto targetFn = runtime->lookupFunction(0x1B3FA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B41E8u; }
        if (ctx->pc != 0x1B41E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3FA0_0x1b3fa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B41E8u; }
        if (ctx->pc != 0x1B41E8u) { return; }
    }
    ctx->pc = 0x1B41E8u;
label_1b41e8:
    // 0x1b41e8: 0x1040008c  beqz        $v0, . + 4 + (0x8C << 2)
    ctx->pc = 0x1B41E8u;
    {
        const bool branch_taken_0x1b41e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b41e8) {
            ctx->pc = 0x1B441Cu;
            goto label_1b441c;
        }
    }
    ctx->pc = 0x1B41F0u;
    // 0x1b41f0: 0x8fa300b0  lw          $v1, 0xB0($sp)
    ctx->pc = 0x1b41f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1b41f4: 0x431018  mult        $v0, $v0, $v1
    ctx->pc = 0x1b41f4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1b41f8: 0x24030280  addiu       $v1, $zero, 0x280
    ctx->pc = 0x1b41f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1b41fc: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1b41fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b4200: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B4200u;
    {
        const bool branch_taken_0x1b4200 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1B4204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4200u;
            // 0x1b4204: 0x28043  sra         $s0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4200) {
            ctx->pc = 0x1B4210u;
            goto label_1b4210;
        }
    }
    ctx->pc = 0x1B4208u;
    // 0x1b4208: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b4208u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b420c: 0x28043  sra         $s0, $v0, 1
    ctx->pc = 0x1b420cu;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 2), 1));
label_1b4210:
    // 0x1b4210: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b4210u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4214: 0xc06d57c  jal         func_1B55F0
    ctx->pc = 0x1B4214u;
    SET_GPR_U32(ctx, 31, 0x1B421Cu);
    ctx->pc = 0x1B4218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4214u;
            // 0x1b4218: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B55F0u;
    if (runtime->hasFunction(0x1B55F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B421Cu; }
        if (ctx->pc != 0x1B421Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55F0_0x1b55f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B421Cu; }
        if (ctx->pc != 0x1B421Cu) { return; }
    }
    ctx->pc = 0x1B421Cu;
label_1b421c:
    // 0x1b421c: 0x241e0001  addiu       $fp, $zero, 0x1
    ctx->pc = 0x1b421cu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b4220:
    // 0x1b4220: 0x92720000  lbu         $s2, 0x0($s3)
    ctx->pc = 0x1b4220u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1b4224: 0x12400076  beqz        $s2, . + 4 + (0x76 << 2)
    ctx->pc = 0x1B4224u;
    {
        const bool branch_taken_0x1b4224 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4224u;
            // 0x1b4228: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4224) {
            ctx->pc = 0x1B4400u;
            goto label_1b4400;
        }
    }
    ctx->pc = 0x1B422Cu;
    // 0x1b422c: 0x2402000d  addiu       $v0, $zero, 0xD
    ctx->pc = 0x1b422cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1b4230: 0x12420074  beq         $s2, $v0, . + 4 + (0x74 << 2)
    ctx->pc = 0x1B4230u;
    {
        const bool branch_taken_0x1b4230 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B4234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4230u;
            // 0x1b4234: 0x27a400e0  addiu       $a0, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4230) {
            ctx->pc = 0x1B4404u;
            goto label_1b4404;
        }
    }
    ctx->pc = 0x1B4238u;
    // 0x1b4238: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1b4238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1b423c: 0x16420005  bne         $s2, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B423Cu;
    {
        const bool branch_taken_0x1b423c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B4240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B423Cu;
            // 0x1b4240: 0x2e420080  sltiu       $v0, $s2, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b423c) {
            ctx->pc = 0x1B4254u;
            goto label_1b4254;
        }
    }
    ctx->pc = 0x1B4244u;
    // 0x1b4244: 0x2e0802d  daddu       $s0, $s7, $zero
    ctx->pc = 0x1b4244u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4248: 0x2b4a821  addu        $s5, $s5, $s4
    ctx->pc = 0x1b4248u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 20)));
    // 0x1b424c: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1B424Cu;
    {
        const bool branch_taken_0x1b424c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B424Cu;
            // 0x1b4250: 0xf02d  daddu       $fp, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b424c) {
            ctx->pc = 0x1B4390u;
            goto label_1b4390;
        }
    }
    ctx->pc = 0x1B4254u;
label_1b4254:
    // 0x1b4254: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B4254u;
    {
        const bool branch_taken_0x1b4254 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4254u;
            // 0x1b4258: 0x2e4100a0  sltiu       $at, $s2, 0xA0 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)160) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4254) {
            ctx->pc = 0x1B4264u;
            goto label_1b4264;
        }
    }
    ctx->pc = 0x1B425Cu;
    // 0x1b425c: 0x14200007  bnez        $at, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B425Cu;
    {
        const bool branch_taken_0x1b425c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b425c) {
            ctx->pc = 0x1B427Cu;
            goto label_1b427c;
        }
    }
    ctx->pc = 0x1B4264u;
label_1b4264:
    // 0x1b4264: 0x2e4200e0  sltiu       $v0, $s2, 0xE0
    ctx->pc = 0x1b4264u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
    // 0x1b4268: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1B4268u;
    {
        const bool branch_taken_0x1b4268 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B426Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4268u;
            // 0x1b426c: 0x2402003c  addiu       $v0, $zero, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4268) {
            ctx->pc = 0x1B42A0u;
            goto label_1b42a0;
        }
    }
    ctx->pc = 0x1B4270u;
    // 0x1b4270: 0x2e410100  sltiu       $at, $s2, 0x100
    ctx->pc = 0x1b4270u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x1b4274: 0x1020000a  beqz        $at, . + 4 + (0xA << 2)
    ctx->pc = 0x1B4274u;
    {
        const bool branch_taken_0x1b4274 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b4274) {
            ctx->pc = 0x1B42A0u;
            goto label_1b42a0;
        }
    }
    ctx->pc = 0x1B427Cu;
label_1b427c:
    // 0x1b427c: 0xa2320000  sb          $s2, 0x0($s1)
    ctx->pc = 0x1b427cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 18));
    // 0x1b4280: 0x92620000  lbu         $v0, 0x0($s3)
    ctx->pc = 0x1b4280u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1b4284: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b4284u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1b4288: 0x1040005d  beqz        $v0, . + 4 + (0x5D << 2)
    ctx->pc = 0x1B4288u;
    {
        const bool branch_taken_0x1b4288 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B428Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4288u;
            // 0x1b428c: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4288) {
            ctx->pc = 0x1B4400u;
            goto label_1b4400;
        }
    }
    ctx->pc = 0x1B4290u;
    // 0x1b4290: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1b4290u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b4294: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b4294u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4298: 0x10000056  b           . + 4 + (0x56 << 2)
    ctx->pc = 0x1B4298u;
    {
        const bool branch_taken_0x1b4298 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B429Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4298u;
            // 0x1b429c: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4298) {
            ctx->pc = 0x1B43F4u;
            goto label_1b43f4;
        }
    }
    ctx->pc = 0x1B42A0u;
label_1b42a0:
    // 0x1b42a0: 0x16420037  bne         $s2, $v0, . + 4 + (0x37 << 2)
    ctx->pc = 0x1B42A0u;
    {
        const bool branch_taken_0x1b42a0 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b42a0) {
            ctx->pc = 0x1B4380u;
            goto label_1b4380;
        }
    }
    ctx->pc = 0x1B42A8u;
    // 0x1b42a8: 0xa3b202e8  sb          $s2, 0x2E8($sp)
    ctx->pc = 0x1b42a8u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 744), (uint8_t)GPR_U32(ctx, 18));
    // 0x1b42ac: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b42acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b42b0: 0x2e440080  sltiu       $a0, $s2, 0x80
    ctx->pc = 0x1b42b0u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b42b4: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1B42B4u;
    {
        const bool branch_taken_0x1b42b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B42B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B42B4u;
            // 0x1b42b8: 0x2e4300e0  sltiu       $v1, $s2, 0xE0 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b42b4) {
            ctx->pc = 0x1B4300u;
            goto label_1b4300;
        }
    }
    ctx->pc = 0x1B42BCu;
label_1b42bc:
    // 0x1b42bc: 0x8042ffff  lb          $v0, -0x1($v0)
    ctx->pc = 0x1b42bcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294967295)));
    // 0x1b42c0: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B42C0u;
    {
        const bool branch_taken_0x1b42c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B42C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B42C0u;
            // 0x1b42c4: 0xbd1021  addu        $v0, $a1, $sp (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 29)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b42c0) {
            ctx->pc = 0x1B4310u;
            goto label_1b4310;
        }
    }
    ctx->pc = 0x1B42C8u;
    // 0x1b42c8: 0x24a2ffff  addiu       $v0, $a1, -0x1
    ctx->pc = 0x1b42c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1b42cc: 0x2621021  addu        $v0, $s3, $v0
    ctx->pc = 0x1b42ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1b42d0: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B42D0u;
    {
        const bool branch_taken_0x1b42d0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B42D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B42D0u;
            // 0x1b42d4: 0x90560000  lbu         $s6, 0x0($v0) (Delay Slot)
        SET_GPR_U32(ctx, 22, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b42d0) {
            ctx->pc = 0x1B42E4u;
            goto label_1b42e4;
        }
    }
    ctx->pc = 0x1B42D8u;
    // 0x1b42d8: 0x2e4100a0  sltiu       $at, $s2, 0xA0
    ctx->pc = 0x1b42d8u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)160) ? 1 : 0);
    // 0x1b42dc: 0x1420000b  bnez        $at, . + 4 + (0xB << 2)
    ctx->pc = 0x1B42DCu;
    {
        const bool branch_taken_0x1b42dc = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b42dc) {
            ctx->pc = 0x1B430Cu;
            goto label_1b430c;
        }
    }
    ctx->pc = 0x1B42E4u;
label_1b42e4:
    // 0x1b42e4: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B42E4u;
    {
        const bool branch_taken_0x1b42e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B42E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B42E4u;
            // 0x1b42e8: 0xbd1021  addu        $v0, $a1, $sp (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 29)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b42e4) {
            ctx->pc = 0x1B42F8u;
            goto label_1b42f8;
        }
    }
    ctx->pc = 0x1B42ECu;
    // 0x1b42ec: 0x2e410100  sltiu       $at, $s2, 0x100
    ctx->pc = 0x1b42ecu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x1b42f0: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B42F0u;
    {
        const bool branch_taken_0x1b42f0 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b42f0) {
            ctx->pc = 0x1B430Cu;
            goto label_1b430c;
        }
    }
    ctx->pc = 0x1B42F8u;
label_1b42f8:
    // 0x1b42f8: 0xa05602e8  sb          $s6, 0x2E8($v0)
    ctx->pc = 0x1b42f8u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 744), (uint8_t)GPR_U32(ctx, 22));
    // 0x1b42fc: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1b42fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_1b4300:
    // 0x1b4300: 0x28a20004  slti        $v0, $a1, 0x4
    ctx->pc = 0x1b4300u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1b4304: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1B4304u;
    {
        const bool branch_taken_0x1b4304 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4304u;
            // 0x1b4308: 0x2651021  addu        $v0, $s3, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4304) {
            ctx->pc = 0x1B42BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b42bc;
        }
    }
    ctx->pc = 0x1B430Cu;
label_1b430c:
    // 0x1b430c: 0xbd1021  addu        $v0, $a1, $sp
    ctx->pc = 0x1b430cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 29)));
label_1b4310:
    // 0x1b4310: 0xa04002e8  sb          $zero, 0x2E8($v0)
    ctx->pc = 0x1b4310u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 744), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b4314: 0x27a202ea  addiu       $v0, $sp, 0x2EA
    ctx->pc = 0x1b4314u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 746));
    // 0x1b4318: 0x80420000  lb          $v0, 0x0($v0)
    ctx->pc = 0x1b4318u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b431c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B431Cu;
    {
        const bool branch_taken_0x1b431c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b431c) {
            ctx->pc = 0x1B4334u;
            goto label_1b4334;
        }
    }
    ctx->pc = 0x1B4324u;
    // 0x1b4324: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x1b4324u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4328: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x1b4328u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1b432c: 0x27a202ea  addiu       $v0, $sp, 0x2EA
    ctx->pc = 0x1b432cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 746));
    // 0x1b4330: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x1b4330u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
label_1b4334:
    // 0x1b4334: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1b4334u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1b4338: 0x27a402e8  addiu       $a0, $sp, 0x2E8
    ctx->pc = 0x1b4338u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 744));
    // 0x1b433c: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1B433Cu;
    SET_GPR_U32(ctx, 31, 0x1B4344u);
    ctx->pc = 0x1B4340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B433Cu;
            // 0x1b4340: 0x24a5ff10  addiu       $a1, $a1, -0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967056));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4344u; }
        if (ctx->pc != 0x1B4344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4344u; }
        if (ctx->pc != 0x1B4344u) { return; }
    }
    ctx->pc = 0x1B4344u;
label_1b4344:
    // 0x1b4344: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B4344u;
    {
        const bool branch_taken_0x1b4344 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4344u;
            // 0x1b4348: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4344) {
            ctx->pc = 0x1B435Cu;
            goto label_1b435c;
        }
    }
    ctx->pc = 0x1B434Cu;
    // 0x1b434c: 0x26c2ffd0  addiu       $v0, $s6, -0x30
    ctx->pc = 0x1b434cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 4294967248));
    // 0x1b4350: 0x26730003  addiu       $s3, $s3, 0x3
    ctx->pc = 0x1b4350u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 3));
    // 0x1b4354: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1B4354u;
    {
        const bool branch_taken_0x1b4354 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4354u;
            // 0x1b4358: 0xafa200d0  sw          $v0, 0xD0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 208), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4354) {
            ctx->pc = 0x1B4390u;
            goto label_1b4390;
        }
    }
    ctx->pc = 0x1B435Cu;
label_1b435c:
    // 0x1b435c: 0x27a402e8  addiu       $a0, $sp, 0x2E8
    ctx->pc = 0x1b435cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 744));
    // 0x1b4360: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1B4360u;
    SET_GPR_U32(ctx, 31, 0x1B4368u);
    ctx->pc = 0x1B4364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4360u;
            // 0x1b4364: 0x24a5ff18  addiu       $a1, $a1, -0xE8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4368u; }
        if (ctx->pc != 0x1B4368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4368u; }
        if (ctx->pc != 0x1B4368u) { return; }
    }
    ctx->pc = 0x1B4368u;
label_1b4368:
    // 0x1b4368: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B4368u;
    {
        const bool branch_taken_0x1b4368 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b4368) {
            ctx->pc = 0x1B4380u;
            goto label_1b4380;
        }
    }
    ctx->pc = 0x1B4370u;
    // 0x1b4370: 0x26c2ffd0  addiu       $v0, $s6, -0x30
    ctx->pc = 0x1b4370u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 4294967248));
    // 0x1b4374: 0x26730003  addiu       $s3, $s3, 0x3
    ctx->pc = 0x1b4374u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 3));
    // 0x1b4378: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1B4378u;
    {
        const bool branch_taken_0x1b4378 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B437Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4378u;
            // 0x1b437c: 0xafa200c0  sw          $v0, 0xC0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 192), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4378) {
            ctx->pc = 0x1B4390u;
            goto label_1b4390;
        }
    }
    ctx->pc = 0x1B4380u;
label_1b4380:
    // 0x1b4380: 0xa2320000  sb          $s2, 0x0($s1)
    ctx->pc = 0x1b4380u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 18));
    // 0x1b4384: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b4384u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b4388: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1B4388u;
    {
        const bool branch_taken_0x1b4388 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B438Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4388u;
            // 0x1b438c: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4388) {
            ctx->pc = 0x1B43F4u;
            goto label_1b43f4;
        }
    }
    ctx->pc = 0x1B4390u;
label_1b4390:
    // 0x1b4390: 0x27a400e0  addiu       $a0, $sp, 0xE0
    ctx->pc = 0x1b4390u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
    // 0x1b4394: 0xc06db1c  jal         func_1B6C70
    ctx->pc = 0x1B4394u;
    SET_GPR_U32(ctx, 31, 0x1B439Cu);
    ctx->pc = 0x1B4398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4394u;
            // 0x1b4398: 0xa2200000  sb          $zero, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6C70u;
    if (runtime->hasFunction(0x1B6C70u)) {
        auto targetFn = runtime->lookupFunction(0x1B6C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B439Cu; }
        if (ctx->pc != 0x1B439Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6C70_0x1b6c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B439Cu; }
        if (ctx->pc != 0x1B439Cu) { return; }
    }
    ctx->pc = 0x1B439Cu;
label_1b439c:
    // 0x1b439c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B439Cu;
    {
        const bool branch_taken_0x1b439c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B43A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B439Cu;
            // 0x1b43a0: 0x27a400e0  addiu       $a0, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b439c) {
            ctx->pc = 0x1B43B4u;
            goto label_1b43b4;
        }
    }
    ctx->pc = 0x1B43A4u;
    // 0x1b43a4: 0xc06d5a8  jal         func_1B56A0
    ctx->pc = 0x1B43A4u;
    SET_GPR_U32(ctx, 31, 0x1B43ACu);
    ctx->pc = 0x1B56A0u;
    if (runtime->hasFunction(0x1B56A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B56A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B43ACu; }
        if (ctx->pc != 0x1B43ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B56A0_0x1b56a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B43ACu; }
        if (ctx->pc != 0x1B43ACu) { return; }
    }
    ctx->pc = 0x1B43ACu;
label_1b43ac:
    // 0x1b43ac: 0xa3a000e0  sb          $zero, 0xE0($sp)
    ctx->pc = 0x1b43acu;
    WRITE8(ADD32(GPR_U32(ctx, 29), 224), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b43b0: 0x27b100e0  addiu       $s1, $sp, 0xE0
    ctx->pc = 0x1b43b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
label_1b43b4:
    // 0x1b43b4: 0x8fa200c0  lw          $v0, 0xC0($sp)
    ctx->pc = 0x1b43b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x1b43b8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1b43b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1b43bc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b43bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b43c0: 0x24424480  addiu       $v0, $v0, 0x4480
    ctx->pc = 0x1b43c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17536));
    // 0x1b43c4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b43c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b43c8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1b43c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b43cc: 0x21a3c  dsll32      $v1, $v0, 8
    ctx->pc = 0x1b43ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 8));
    // 0x1b43d0: 0x8fa200a0  lw          $v0, 0xA0($sp)
    ctx->pc = 0x1b43d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1b43d4: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1b43d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1b43d8: 0xc06d594  jal         func_1B5650
    ctx->pc = 0x1B43D8u;
    SET_GPR_U32(ctx, 31, 0x1B43E0u);
    ctx->pc = 0x1B43DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B43D8u;
            // 0x1b43dc: 0x432025  or          $a0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5650u;
    if (runtime->hasFunction(0x1B5650u)) {
        auto targetFn = runtime->lookupFunction(0x1B5650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B43E0u; }
        if (ctx->pc != 0x1B43E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5650_0x1b5650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B43E0u; }
        if (ctx->pc != 0x1B43E0u) { return; }
    }
    ctx->pc = 0x1B43E0u;
label_1b43e0:
    // 0x1b43e0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b43e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b43e4: 0xc06d57c  jal         func_1B55F0
    ctx->pc = 0x1B43E4u;
    SET_GPR_U32(ctx, 31, 0x1B43ECu);
    ctx->pc = 0x1B43E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B43E4u;
            // 0x1b43e8: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B55F0u;
    if (runtime->hasFunction(0x1B55F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B43ECu; }
        if (ctx->pc != 0x1B43ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55F0_0x1b55f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B43ECu; }
        if (ctx->pc != 0x1B43ECu) { return; }
    }
    ctx->pc = 0x1B43ECu;
label_1b43ec:
    // 0x1b43ec: 0x1000ff77  b           . + 4 + (-0x89 << 2)
    ctx->pc = 0x1B43ECu;
    {
        const bool branch_taken_0x1b43ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b43ec) {
            ctx->pc = 0x1B41CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b41cc;
        }
    }
    ctx->pc = 0x1B43F4u;
label_1b43f4:
    // 0x1b43f4: 0x541007  srav        $v0, $s4, $v0
    ctx->pc = 0x1b43f4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 20), GPR_U32(ctx, 2) & 0x1F));
    // 0x1b43f8: 0x1000ff74  b           . + 4 + (-0x8C << 2)
    ctx->pc = 0x1B43F8u;
    {
        const bool branch_taken_0x1b43f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B43FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B43F8u;
            // 0x1b43fc: 0x2028021  addu        $s0, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b43f8) {
            ctx->pc = 0x1B41CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b41cc;
        }
    }
    ctx->pc = 0x1B4400u;
label_1b4400:
    // 0x1b4400: 0x27a400e0  addiu       $a0, $sp, 0xE0
    ctx->pc = 0x1b4400u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
label_1b4404:
    // 0x1b4404: 0xc06db1c  jal         func_1B6C70
    ctx->pc = 0x1B4404u;
    SET_GPR_U32(ctx, 31, 0x1B440Cu);
    ctx->pc = 0x1B4408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4404u;
            // 0x1b4408: 0xa2200000  sb          $zero, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6C70u;
    if (runtime->hasFunction(0x1B6C70u)) {
        auto targetFn = runtime->lookupFunction(0x1B6C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B440Cu; }
        if (ctx->pc != 0x1B440Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6C70_0x1b6c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B440Cu; }
        if (ctx->pc != 0x1B440Cu) { return; }
    }
    ctx->pc = 0x1B440Cu;
label_1b440c:
    // 0x1b440c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B440Cu;
    {
        const bool branch_taken_0x1b440c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B440Cu;
            // 0x1b4410: 0x27a400e0  addiu       $a0, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b440c) {
            ctx->pc = 0x1B441Cu;
            goto label_1b441c;
        }
    }
    ctx->pc = 0x1B4414u;
    // 0x1b4414: 0xc06d5a8  jal         func_1B56A0
    ctx->pc = 0x1B4414u;
    SET_GPR_U32(ctx, 31, 0x1B441Cu);
    ctx->pc = 0x1B56A0u;
    if (runtime->hasFunction(0x1B56A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B56A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B441Cu; }
        if (ctx->pc != 0x1B441Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B56A0_0x1b56a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B441Cu; }
        if (ctx->pc != 0x1B441Cu) { return; }
    }
    ctx->pc = 0x1B441Cu;
label_1b441c:
    // 0x1b441c: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1b441cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1b4420: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x1b4420u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1b4424: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1b4424u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1b4428: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1b4428u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1b442c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1b442cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b4430: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b4430u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b4434: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b4434u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b4438: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b4438u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b443c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b443cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b4440: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b4440u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4444: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4444u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B4448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4444u;
            // 0x1b4448: 0x27bd02f0  addiu       $sp, $sp, 0x2F0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 752));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B414Cu: goto label_1b414c;
            case 0x1B4154u: goto label_1b4154;
            case 0x1B4174u: goto label_1b4174;
            case 0x1B417Cu: goto label_1b417c;
            case 0x1B41A4u: goto label_1b41a4;
            case 0x1B41B0u: goto label_1b41b0;
            case 0x1B41CCu: goto label_1b41cc;
            case 0x1B41E8u: goto label_1b41e8;
            case 0x1B4210u: goto label_1b4210;
            case 0x1B421Cu: goto label_1b421c;
            case 0x1B4220u: goto label_1b4220;
            case 0x1B4254u: goto label_1b4254;
            case 0x1B4264u: goto label_1b4264;
            case 0x1B427Cu: goto label_1b427c;
            case 0x1B42A0u: goto label_1b42a0;
            case 0x1B42BCu: goto label_1b42bc;
            case 0x1B42E4u: goto label_1b42e4;
            case 0x1B42F8u: goto label_1b42f8;
            case 0x1B4300u: goto label_1b4300;
            case 0x1B430Cu: goto label_1b430c;
            case 0x1B4310u: goto label_1b4310;
            case 0x1B4334u: goto label_1b4334;
            case 0x1B4344u: goto label_1b4344;
            case 0x1B435Cu: goto label_1b435c;
            case 0x1B4368u: goto label_1b4368;
            case 0x1B4380u: goto label_1b4380;
            case 0x1B4390u: goto label_1b4390;
            case 0x1B439Cu: goto label_1b439c;
            case 0x1B43ACu: goto label_1b43ac;
            case 0x1B43B4u: goto label_1b43b4;
            case 0x1B43E0u: goto label_1b43e0;
            case 0x1B43ECu: goto label_1b43ec;
            case 0x1B43F4u: goto label_1b43f4;
            case 0x1B4400u: goto label_1b4400;
            case 0x1B4404u: goto label_1b4404;
            case 0x1B440Cu: goto label_1b440c;
            case 0x1B441Cu: goto label_1b441c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B444Cu;
    // 0x1b444c: 0x0  nop
    ctx->pc = 0x1b444cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
