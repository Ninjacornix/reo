#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B0C8
// Address: 0x16b0c8 - 0x16b218
void sub_0016B0C8_0x16b0c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B0C8_0x16b0c8");
#endif

    switch (ctx->pc) {
        case 0x16b120u: goto label_16b120;
        case 0x16b148u: goto label_16b148;
        case 0x16b180u: goto label_16b180;
        case 0x16b1b0u: goto label_16b1b0;
        case 0x16b1d0u: goto label_16b1d0;
        default: break;
    }

    ctx->pc = 0x16b0c8u;

    // 0x16b0c8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16b0c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16b0cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16b0ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16b0d0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16b0d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b0d4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16b0d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16b0d8: 0x26111ae4  addiu       $s1, $s0, 0x1AE4
    ctx->pc = 0x16b0d8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 6884));
    // 0x16b0dc: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x16b0dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x16b0e0: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x16b0e0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b0e4: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x16b0e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x16b0e8: 0xe0b02d  daddu       $s6, $a3, $zero
    ctx->pc = 0x16b0e8u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b0ec: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16b0ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16b0f0: 0x2aa20004  slti        $v0, $s5, 0x4
    ctx->pc = 0x16b0f0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x16b0f4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16b0f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16b0f8: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x16b0f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b0fc: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16b0fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16b100: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x16b100u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x16b104: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x16b104u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x16b108: 0x8e330008  lw          $s3, 0x8($s1)
    ctx->pc = 0x16b108u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x16b10c: 0x8e340010  lw          $s4, 0x10($s1)
    ctx->pc = 0x16b10cu;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x16b110: 0x14400017  bnez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x16B110u;
    {
        const bool branch_taken_0x16b110 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16B114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B110u;
            // 0x16b114: 0x8e170028  lw          $s7, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b110) {
            ctx->pc = 0x16B170u;
            goto label_16b170;
        }
    }
    ctx->pc = 0x16B118u;
    // 0x16b118: 0xc055f4a  jal         func_157D28
    ctx->pc = 0x16B118u;
    SET_GPR_U32(ctx, 31, 0x16B120u);
    ctx->pc = 0x157D28u;
    if (runtime->hasFunction(0x157D28u)) {
        auto targetFn = runtime->lookupFunction(0x157D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B120u; }
        if (ctx->pc != 0x16B120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00157D28_0x157d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B120u; }
        if (ctx->pc != 0x16B120u) { return; }
    }
    ctx->pc = 0x16B120u;
label_16b120:
    // 0x16b120: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x16b120u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b124: 0x3c020008  lui         $v0, 0x8
    ctx->pc = 0x16b124u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8 << 16));
    // 0x16b128: 0x1642000d  bne         $s2, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x16B128u;
    {
        const bool branch_taken_0x16b128 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x16b128) {
            ctx->pc = 0x16B160u;
            goto label_16b160;
        }
    }
    ctx->pc = 0x16B130u;
    // 0x16b130: 0x8e220020  lw          $v0, 0x20($s1)
    ctx->pc = 0x16b130u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x16b134: 0x4430007  bgezl       $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16B134u;
    {
        const bool branch_taken_0x16b134 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x16b134) {
            ctx->pc = 0x16B138u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16B134u;
            // 0x16b138: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16B154u;
            goto label_16b154;
        }
    }
    ctx->pc = 0x16B13Cu;
    // 0x16b13c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b13cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b140: 0xc059d4a  jal         func_167528
    ctx->pc = 0x16B140u;
    SET_GPR_U32(ctx, 31, 0x16B148u);
    ctx->pc = 0x16B144u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B140u;
            // 0x16b144: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167528u;
    if (runtime->hasFunction(0x167528u)) {
        auto targetFn = runtime->lookupFunction(0x167528u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B148u; }
        if (ctx->pc != 0x16B148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167528_0x167528(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B148u; }
        if (ctx->pc != 0x16B148u) { return; }
    }
    ctx->pc = 0x16B148u;
label_16b148:
    // 0x16b148: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x16b148u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x16b14c: 0xae220020  sw          $v0, 0x20($s1)
    ctx->pc = 0x16b14cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 32), GPR_U32(ctx, 2));
    // 0x16b150: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16b150u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_16b154:
    // 0x16b154: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x16B154u;
    {
        const bool branch_taken_0x16b154 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16B158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B154u;
            // 0x16b158: 0xae620030  sw          $v0, 0x30($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 48), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b154) {
            ctx->pc = 0x16B174u;
            goto label_16b174;
        }
    }
    ctx->pc = 0x16B15Cu;
    // 0x16b15c: 0x0  nop
    ctx->pc = 0x16b15cu;
    // NOP
label_16b160:
    // 0x16b160: 0x56400004  bnel        $s2, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x16B160u;
    {
        const bool branch_taken_0x16b160 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x16b160) {
            ctx->pc = 0x16B164u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16B160u;
            // 0x16b164: 0xae600030  sw          $zero, 0x30($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16B174u;
            goto label_16b174;
        }
    }
    ctx->pc = 0x16B168u;
    // 0x16b168: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x16B168u;
    {
        const bool branch_taken_0x16b168 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16B16Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B168u;
            // 0x16b16c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b168) {
            ctx->pc = 0x16B178u;
            goto label_16b178;
        }
    }
    ctx->pc = 0x16B170u;
label_16b170:
    // 0x16b170: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x16b170u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16b174:
    // 0x16b174: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b174u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_16b178:
    // 0x16b178: 0xc05ac86  jal         func_16B218
    ctx->pc = 0x16B178u;
    SET_GPR_U32(ctx, 31, 0x16B180u);
    ctx->pc = 0x16B17Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B178u;
            // 0x16b17c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B218u;
    if (runtime->hasFunction(0x16B218u)) {
        auto targetFn = runtime->lookupFunction(0x16B218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B180u; }
        if (ctx->pc != 0x16B180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B218_0x16b218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B180u; }
        if (ctx->pc != 0x16B180u) { return; }
    }
    ctx->pc = 0x16B180u;
label_16b180:
    // 0x16b180: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16B180u;
    {
        const bool branch_taken_0x16b180 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16B184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B180u;
            // 0x16b184: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b180) {
            ctx->pc = 0x16B198u;
            goto label_16b198;
        }
    }
    ctx->pc = 0x16B188u;
    // 0x16b188: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16b188u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16b18c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x16B18Cu;
    {
        const bool branch_taken_0x16b18c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16B190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B18Cu;
            // 0x16b190: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b18c) {
            ctx->pc = 0x16B1C8u;
            goto label_16b1c8;
        }
    }
    ctx->pc = 0x16B194u;
    // 0x16b194: 0x0  nop
    ctx->pc = 0x16b194u;
    // NOP
label_16b198:
    // 0x16b198: 0x2ac20004  slti        $v0, $s6, 0x4
    ctx->pc = 0x16b198u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x16b19c: 0x5040000e  beql        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x16B19Cu;
    {
        const bool branch_taken_0x16b19c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16b19c) {
            ctx->pc = 0x16B1A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16B19Cu;
            // 0x16b1a0: 0x2b7102a  slt         $v0, $s5, $s7 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 23)) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x16B1D8u;
            goto label_16b1d8;
        }
    }
    ctx->pc = 0x16B1A4u;
    // 0x16b1a4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x16b1a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b1a8: 0xc059f40  jal         func_167D00
    ctx->pc = 0x16B1A8u;
    SET_GPR_U32(ctx, 31, 0x16B1B0u);
    ctx->pc = 0x16B1ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B1A8u;
            // 0x16b1ac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D00u;
    if (runtime->hasFunction(0x167D00u)) {
        auto targetFn = runtime->lookupFunction(0x167D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B1B0u; }
        if (ctx->pc != 0x16B1B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D00_0x167d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B1B0u; }
        if (ctx->pc != 0x16B1B0u) { return; }
    }
    ctx->pc = 0x16B1B0u;
label_16b1b0:
    // 0x16b1b0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x16b1b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16b1b4: 0x54430008  bnel        $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x16B1B4u;
    {
        const bool branch_taken_0x16b1b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x16b1b4) {
            ctx->pc = 0x16B1B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16B1B4u;
            // 0x16b1b8: 0x2b7102a  slt         $v0, $s5, $s7 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 23)) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x16B1D8u;
            goto label_16b1d8;
        }
    }
    ctx->pc = 0x16B1BCu;
    // 0x16b1bc: 0x8e660030  lw          $a2, 0x30($s3)
    ctx->pc = 0x16b1bcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 48)));
    // 0x16b1c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b1c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b1c4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16b1c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_16b1c8:
    // 0x16b1c8: 0xc05abf2  jal         func_16AFC8
    ctx->pc = 0x16B1C8u;
    SET_GPR_U32(ctx, 31, 0x16B1D0u);
    ctx->pc = 0x16AFC8u;
    if (runtime->hasFunction(0x16AFC8u)) {
        auto targetFn = runtime->lookupFunction(0x16AFC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B1D0u; }
        if (ctx->pc != 0x16B1D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016AFC8_0x16afc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B1D0u; }
        if (ctx->pc != 0x16B1D0u) { return; }
    }
    ctx->pc = 0x16B1D0u;
label_16b1d0:
    // 0x16b1d0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x16B1D0u;
    {
        const bool branch_taken_0x16b1d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16B1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B1D0u;
            // 0x16b1d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b1d0) {
            ctx->pc = 0x16B1ECu;
            goto label_16b1ec;
        }
    }
    ctx->pc = 0x16B1D8u;
label_16b1d8:
    // 0x16b1d8: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x16B1D8u;
    {
        const bool branch_taken_0x16b1d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16b1d8) {
            ctx->pc = 0x16B1DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16B1D8u;
            // 0x16b1dc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16B1ECu;
            goto label_16b1ec;
        }
    }
    ctx->pc = 0x16B1E0u;
    // 0x16b1e0: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x16b1e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x16b1e4: 0x2421026  xor         $v0, $s2, $v0
    ctx->pc = 0x16b1e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) ^ GPR_U64(ctx, 2));
    // 0x16b1e8: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x16b1e8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_16b1ec:
    // 0x16b1ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b1ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b1f0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16b1f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b1f4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16b1f4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16b1f8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16b1f8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16b1fc: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16b1fcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16b200: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x16b200u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16b204: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x16b204u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16b208: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x16b208u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16b20c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x16b20cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16b210: 0x3e00008  jr          $ra
    ctx->pc = 0x16B210u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B210u;
            // 0x16b214: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B120u: goto label_16b120;
            case 0x16B148u: goto label_16b148;
            case 0x16B154u: goto label_16b154;
            case 0x16B160u: goto label_16b160;
            case 0x16B170u: goto label_16b170;
            case 0x16B174u: goto label_16b174;
            case 0x16B178u: goto label_16b178;
            case 0x16B180u: goto label_16b180;
            case 0x16B198u: goto label_16b198;
            case 0x16B1B0u: goto label_16b1b0;
            case 0x16B1C8u: goto label_16b1c8;
            case 0x16B1D0u: goto label_16b1d0;
            case 0x16B1D8u: goto label_16b1d8;
            case 0x16B1ECu: goto label_16b1ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B218u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
