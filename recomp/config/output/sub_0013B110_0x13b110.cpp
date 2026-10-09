#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B110
// Address: 0x13b110 - 0x13b1d8
void sub_0013B110_0x13b110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B110_0x13b110");
#endif

    switch (ctx->pc) {
        case 0x13b134u: goto label_13b134;
        case 0x13b13cu: goto label_13b13c;
        case 0x13b1b0u: goto label_13b1b0;
        default: break;
    }

    ctx->pc = 0x13b110u;

    // 0x13b110: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13b110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13b114: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13b114u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13b118: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13b118u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b11c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x13b11cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13b120: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x13b120u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x13b124: 0x50400028  beql        $v0, $zero, . + 4 + (0x28 << 2)
    ctx->pc = 0x13B124u;
    {
        const bool branch_taken_0x13b124 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13b124) {
            ctx->pc = 0x13B128u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13B124u;
            // 0x13b128: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13B1C8u;
            goto label_13b1c8;
        }
    }
    ctx->pc = 0x13B12Cu;
    // 0x13b12c: 0xc0505c0  jal         func_141700
    ctx->pc = 0x13B12Cu;
    SET_GPR_U32(ctx, 31, 0x13B134u);
    ctx->pc = 0x141700u;
    if (runtime->hasFunction(0x141700u)) {
        auto targetFn = runtime->lookupFunction(0x141700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B134u; }
        if (ctx->pc != 0x13B134u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141700_0x141700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B134u; }
        if (ctx->pc != 0x13B134u) { return; }
    }
    ctx->pc = 0x13B134u;
label_13b134:
    // 0x13b134: 0xc04dd82  jal         func_137608
    ctx->pc = 0x13B134u;
    SET_GPR_U32(ctx, 31, 0x13B13Cu);
    ctx->pc = 0x13B138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B134u;
            // 0x13b138: 0x8e04002c  lw          $a0, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137608u;
    if (runtime->hasFunction(0x137608u)) {
        auto targetFn = runtime->lookupFunction(0x137608u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B13Cu; }
        if (ctx->pc != 0x13B13Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137608_0x137608(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B13Cu; }
        if (ctx->pc != 0x13B13Cu) { return; }
    }
    ctx->pc = 0x13B13Cu;
label_13b13c:
    // 0x13b13c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x13b13cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b140: 0x2c62000a  sltiu       $v0, $v1, 0xA
    ctx->pc = 0x13b140u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x13b144: 0x5040001c  beql        $v0, $zero, . + 4 + (0x1C << 2)
    ctx->pc = 0x13B144u;
    {
        const bool branch_taken_0x13b144 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13b144) {
            ctx->pc = 0x13B148u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13B144u;
            // 0x13b148: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13B1B8u;
            goto label_13b1b8;
        }
    }
    ctx->pc = 0x13B14Cu;
    // 0x13b14c: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x13b14cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x13b150: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x13b150u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x13b154: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13b154u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13b158: 0x8c63ce30  lw          $v1, -0x31D0($v1)
    ctx->pc = 0x13b158u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294954544)));
    // 0x13b15c: 0x600008  jr          $v1
    ctx->pc = 0x13B15Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B168u: goto label_13b168;
            case 0x13B178u: goto label_13b178;
            case 0x13B1A0u: goto label_13b1a0;
            case 0x13B1B4u: goto label_13b1b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B164u;
    // 0x13b164: 0x0  nop
    ctx->pc = 0x13b164u;
    // NOP
label_13b168:
    // 0x13b168: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x13b168u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x13b16c: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x13b16cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x13b170: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x13B170u;
    {
        const bool branch_taken_0x13b170 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B170u;
            // 0x13b174: 0xa2020002  sb          $v0, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b170) {
            ctx->pc = 0x13B1A8u;
            goto label_13b1a8;
        }
    }
    ctx->pc = 0x13B178u;
label_13b178:
    // 0x13b178: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x13b178u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13b17c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x13b17cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13b180: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x13b180u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13b184: 0xae040028  sw          $a0, 0x28($s0)
    ctx->pc = 0x13b184u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 4));
    // 0x13b188: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x13b188u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x13b18c: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x13b18cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x13b190: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x13b190u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x13b194: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x13B194u;
    {
        const bool branch_taken_0x13b194 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B194u;
            // 0x13b198: 0xae02001c  sw          $v0, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b194) {
            ctx->pc = 0x13B1A8u;
            goto label_13b1a8;
        }
    }
    ctx->pc = 0x13B19Cu;
    // 0x13b19c: 0x0  nop
    ctx->pc = 0x13b19cu;
    // NOP
label_13b1a0:
    // 0x13b1a0: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x13b1a0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x13b1a4: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x13b1a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
label_13b1a8:
    // 0x13b1a8: 0xc04dcf2  jal         func_1373C8
    ctx->pc = 0x13B1A8u;
    SET_GPR_U32(ctx, 31, 0x13B1B0u);
    ctx->pc = 0x1373C8u;
    if (runtime->hasFunction(0x1373C8u)) {
        auto targetFn = runtime->lookupFunction(0x1373C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B1B0u; }
        if (ctx->pc != 0x13B1B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001373C8_0x1373c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B1B0u; }
        if (ctx->pc != 0x13B1B0u) { return; }
    }
    ctx->pc = 0x13B1B0u;
label_13b1b0:
    // 0x13b1b0: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x13b1b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
label_13b1b4:
    // 0x13b1b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13b1b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13b1b8:
    // 0x13b1b8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13b1b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13b1bc: 0x80505de  j           func_141778
    ctx->pc = 0x13B1BCu;
    ctx->pc = 0x13B1C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B1BCu;
            // 0x13b1c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141778u;
    if (runtime->hasFunction(0x141778u)) {
        auto targetFn = runtime->lookupFunction(0x141778u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141778_0x141778(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13B1C4u;
    // 0x13b1c4: 0x0  nop
    ctx->pc = 0x13b1c4u;
    // NOP
label_13b1c8:
    // 0x13b1c8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13b1c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13b1cc: 0x3e00008  jr          $ra
    ctx->pc = 0x13B1CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B1D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B1CCu;
            // 0x13b1d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B134u: goto label_13b134;
            case 0x13B13Cu: goto label_13b13c;
            case 0x13B168u: goto label_13b168;
            case 0x13B178u: goto label_13b178;
            case 0x13B1A0u: goto label_13b1a0;
            case 0x13B1A8u: goto label_13b1a8;
            case 0x13B1B0u: goto label_13b1b0;
            case 0x13B1B4u: goto label_13b1b4;
            case 0x13B1B8u: goto label_13b1b8;
            case 0x13B1C8u: goto label_13b1c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B1D4u;
    // 0x13b1d4: 0x0  nop
    ctx->pc = 0x13b1d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
