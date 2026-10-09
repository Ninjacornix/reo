#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0B80
// Address: 0x1b0b80 - 0x1b0da8
void sub_001B0B80_0x1b0b80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0B80_0x1b0b80");
#endif

    switch (ctx->pc) {
        case 0x1b0b9cu: goto label_1b0b9c;
        case 0x1b0bc8u: goto label_1b0bc8;
        default: break;
    }

    ctx->pc = 0x1b0b80u;

    // 0x1b0b80: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b0b80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b0b84: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b0b84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b0b88: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b0b88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b0b8c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0b8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b0b90: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b0b90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0b94: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B0B94u;
    SET_GPR_U32(ctx, 31, 0x1B0B9Cu);
    ctx->pc = 0x1B0B98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0B94u;
            // 0x1b0b98: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0B9Cu; }
        if (ctx->pc != 0x1B0B9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0B9Cu; }
        if (ctx->pc != 0x1B0B9Cu) { return; }
    }
    ctx->pc = 0x1B0B9Cu;
label_1b0b9c:
    // 0x1b0b9c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b0b9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0ba0: 0x14430007  bne         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B0BA0u;
    {
        const bool branch_taken_0x1b0ba0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B0BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0BA0u;
            // 0x1b0ba4: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0ba0) {
            ctx->pc = 0x1B0BC0u;
            goto label_1b0bc0;
        }
    }
    ctx->pc = 0x1B0BA8u;
    // 0x1b0ba8: 0x92040003  lbu         $a0, 0x3($s0)
    ctx->pc = 0x1b0ba8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1b0bac: 0x9023aded  lbu         $v1, -0x5213($at)
    ctx->pc = 0x1b0bacu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946285)));
    // 0x1b0bb0: 0x10830011  beq         $a0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1B0BB0u;
    {
        const bool branch_taken_0x1b0bb0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B0BB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0BB0u;
            // 0x1b0bb4: 0x111e3c  dsll32      $v1, $s1, 24 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0bb0) {
            ctx->pc = 0x1B0BF8u;
            goto label_1b0bf8;
        }
    }
    ctx->pc = 0x1B0BB8u;
    // 0x1b0bb8: 0x10000077  b           . + 4 + (0x77 << 2)
    ctx->pc = 0x1B0BB8u;
    {
        const bool branch_taken_0x1b0bb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0BB8u;
            // 0x1b0bbc: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0bb8) {
            ctx->pc = 0x1B0D98u;
            goto label_1b0d98;
        }
    }
    ctx->pc = 0x1B0BC0u;
label_1b0bc0:
    // 0x1b0bc0: 0xc06c0b4  jal         func_1B02D0
    ctx->pc = 0x1B0BC0u;
    SET_GPR_U32(ctx, 31, 0x1B0BC8u);
    ctx->pc = 0x1B02D0u;
    if (runtime->hasFunction(0x1B02D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B02D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0BC8u; }
        if (ctx->pc != 0x1B0BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B02D0_0x1b02d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0BC8u; }
        if (ctx->pc != 0x1B0BC8u) { return; }
    }
    ctx->pc = 0x1B0BC8u;
label_1b0bc8:
    // 0x1b0bc8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B0BC8u;
    {
        const bool branch_taken_0x1b0bc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b0bc8) {
            ctx->pc = 0x1B0BE8u;
            goto label_1b0be8;
        }
    }
    ctx->pc = 0x1B0BD0u;
    // 0x1b0bd0: 0x92040003  lbu         $a0, 0x3($s0)
    ctx->pc = 0x1b0bd0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1b0bd4: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1b0bd4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1b0bd8: 0x24638e90  addiu       $v1, $v1, -0x7170
    ctx->pc = 0x1b0bd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938256));
    // 0x1b0bdc: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b0bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b0be0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B0BE0u;
    {
        const bool branch_taken_0x1b0be0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0BE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0BE0u;
            // 0x1b0be4: 0x80710000  lb          $s1, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0be0) {
            ctx->pc = 0x1B0BF4u;
            goto label_1b0bf4;
        }
    }
    ctx->pc = 0x1B0BE8u;
label_1b0be8:
    // 0x1b0be8: 0x92030ff0  lbu         $v1, 0xFF0($s0)
    ctx->pc = 0x1b0be8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4080)));
    // 0x1b0bec: 0x14600069  bnez        $v1, . + 4 + (0x69 << 2)
    ctx->pc = 0x1B0BECu;
    {
        const bool branch_taken_0x1b0bec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b0bec) {
            ctx->pc = 0x1B0D94u;
            goto label_1b0d94;
        }
    }
    ctx->pc = 0x1B0BF4u;
label_1b0bf4:
    // 0x1b0bf4: 0x111e3c  dsll32      $v1, $s1, 24
    ctx->pc = 0x1b0bf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 24));
label_1b0bf8:
    // 0x1b0bf8: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1b0bf8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b0bfc: 0x31e3f  dsra32      $v1, $v1, 24
    ctx->pc = 0x1b0bfcu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 24));
    // 0x1b0c00: 0x10640064  beq         $v1, $a0, . + 4 + (0x64 << 2)
    ctx->pc = 0x1B0C00u;
    {
        const bool branch_taken_0x1b0c00 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1b0c00) {
            ctx->pc = 0x1B0D94u;
            goto label_1b0d94;
        }
    }
    ctx->pc = 0x1B0C08u;
    // 0x1b0c08: 0x8e0a0f88  lw          $t2, 0xF88($s0)
    ctx->pc = 0x1b0c08u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3976)));
    // 0x1b0c0c: 0x32040  sll         $a0, $v1, 1
    ctx->pc = 0x1b0c0cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b0c10: 0x833821  addu        $a3, $a0, $v1
    ctx->pc = 0x1b0c10u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b0c14: 0x3c060032  lui         $a2, 0x32
    ctx->pc = 0x1b0c14u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)50 << 16));
    // 0x1b0c18: 0x3c090023  lui         $t1, 0x23
    ctx->pc = 0x1b0c18u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)35 << 16));
    // 0x1b0c1c: 0x3c080023  lui         $t0, 0x23
    ctx->pc = 0x1b0c1cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)35 << 16));
    // 0x1b0c20: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0c20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0c24: 0x24c64248  addiu       $a2, $a2, 0x4248
    ctx->pc = 0x1b0c24u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16968));
    // 0x1b0c28: 0x73900  sll         $a3, $a3, 4
    ctx->pc = 0x1b0c28u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
    // 0x1b0c2c: 0x252943c0  addiu       $t1, $t1, 0x43C0
    ctx->pc = 0x1b0c2cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 17344));
    // 0x1b0c30: 0xc73021  addu        $a2, $a2, $a3
    ctx->pc = 0x1b0c30u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1b0c34: 0x250843c4  addiu       $t0, $t0, 0x43C4
    ctx->pc = 0x1b0c34u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 17348));
    // 0x1b0c38: 0xae0a0f8c  sw          $t2, 0xF8C($s0)
    ctx->pc = 0x1b0c38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 3980), GPR_U32(ctx, 10));
    // 0x1b0c3c: 0x3c070023  lui         $a3, 0x23
    ctx->pc = 0x1b0c3cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
    // 0x1b0c40: 0x8e0a0f84  lw          $t2, 0xF84($s0)
    ctx->pc = 0x1b0c40u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3972)));
    // 0x1b0c44: 0x24e743c8  addiu       $a3, $a3, 0x43C8
    ctx->pc = 0x1b0c44u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 17352));
    // 0x1b0c48: 0x26050f78  addiu       $a1, $s0, 0xF78
    ctx->pc = 0x1b0c48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 3960));
    // 0x1b0c4c: 0xae0a0f88  sw          $t2, 0xF88($s0)
    ctx->pc = 0x1b0c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 3976), GPR_U32(ctx, 10));
    // 0x1b0c50: 0x8e0a0f80  lw          $t2, 0xF80($s0)
    ctx->pc = 0x1b0c50u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3968)));
    // 0x1b0c54: 0xae0a0f84  sw          $t2, 0xF84($s0)
    ctx->pc = 0x1b0c54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 3972), GPR_U32(ctx, 10));
    // 0x1b0c58: 0x902b43ec  lbu         $t3, 0x43EC($at)
    ctx->pc = 0x1b0c58u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17388)));
    // 0x1b0c5c: 0x8ccc0000  lw          $t4, 0x0($a2)
    ctx->pc = 0x1b0c5cu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1b0c60: 0xb5040  sll         $t2, $t3, 1
    ctx->pc = 0x1b0c60u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 11), 1));
    // 0x1b0c64: 0x14b5021  addu        $t2, $t2, $t3
    ctx->pc = 0x1b0c64u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 11)));
    // 0x1b0c68: 0x31860100  andi        $a2, $t4, 0x100
    ctx->pc = 0x1b0c68u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)256);
    // 0x1b0c6c: 0xa5080  sll         $t2, $t2, 2
    ctx->pc = 0x1b0c6cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 2));
    // 0x1b0c70: 0x12a4821  addu        $t1, $t1, $t2
    ctx->pc = 0x1b0c70u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 10)));
    // 0x1b0c74: 0x10a4021  addu        $t0, $t0, $t2
    ctx->pc = 0x1b0c74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 10)));
    // 0x1b0c78: 0xea3821  addu        $a3, $a3, $t2
    ctx->pc = 0x1b0c78u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x1b0c7c: 0x8d290000  lw          $t1, 0x0($t1)
    ctx->pc = 0x1b0c7cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1b0c80: 0x8d080000  lw          $t0, 0x0($t0)
    ctx->pc = 0x1b0c80u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1b0c84: 0x8ce70000  lw          $a3, 0x0($a3)
    ctx->pc = 0x1b0c84u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1b0c88: 0x10c00002  beqz        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B0C88u;
    {
        const bool branch_taken_0x1b0c88 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0C88u;
            // 0x1b0c8c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0c88) {
            ctx->pc = 0x1B0C94u;
            goto label_1b0c94;
        }
    }
    ctx->pc = 0x1B0C90u;
    // 0x1b0c90: 0x892025  or          $a0, $a0, $t1
    ctx->pc = 0x1b0c90u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 9));
label_1b0c94:
    // 0x1b0c94: 0x31860010  andi        $a2, $t4, 0x10
    ctx->pc = 0x1b0c94u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)16);
    // 0x1b0c98: 0x10c00002  beqz        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B0C98u;
    {
        const bool branch_taken_0x1b0c98 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0C98u;
            // 0x1b0c9c: 0x31860020  andi        $a2, $t4, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)32);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0c98) {
            ctx->pc = 0x1B0CA4u;
            goto label_1b0ca4;
        }
    }
    ctx->pc = 0x1B0CA0u;
    // 0x1b0ca0: 0x882025  or          $a0, $a0, $t0
    ctx->pc = 0x1b0ca0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 8));
label_1b0ca4:
    // 0x1b0ca4: 0x10c00002  beqz        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B0CA4u;
    {
        const bool branch_taken_0x1b0ca4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b0ca4) {
            ctx->pc = 0x1B0CB0u;
            goto label_1b0cb0;
        }
    }
    ctx->pc = 0x1B0CACu;
    // 0x1b0cac: 0x872025  or          $a0, $a0, $a3
    ctx->pc = 0x1b0cacu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 7));
label_1b0cb0:
    // 0x1b0cb0: 0x2407fecf  addiu       $a3, $zero, -0x131
    ctx->pc = 0x1b0cb0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966991));
    // 0x1b0cb4: 0x33040  sll         $a2, $v1, 1
    ctx->pc = 0x1b0cb4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b0cb8: 0x1873824  and         $a3, $t4, $a3
    ctx->pc = 0x1b0cb8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 12) & GPR_U64(ctx, 7));
    // 0x1b0cbc: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x1b0cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1b0cc0: 0xe42025  or          $a0, $a3, $a0
    ctx->pc = 0x1b0cc0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) | GPR_U64(ctx, 4));
    // 0x1b0cc4: 0x37100  sll         $t6, $v1, 4
    ctx->pc = 0x1b0cc4u;
    SET_GPR_S32(ctx, 14, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1b0cc8: 0xaca40008  sw          $a0, 0x8($a1)
    ctx->pc = 0x1b0cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 4));
    // 0x1b0ccc: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1b0cccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1b0cd0: 0x8ca6000c  lw          $a2, 0xC($a1)
    ctx->pc = 0x1b0cd0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x1b0cd4: 0x24634264  addiu       $v1, $v1, 0x4264
    ctx->pc = 0x1b0cd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16996));
    // 0x1b0cd8: 0x8ca40008  lw          $a0, 0x8($a1)
    ctx->pc = 0x1b0cd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x1b0cdc: 0x6e5821  addu        $t3, $v1, $t6
    ctx->pc = 0x1b0cdcu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x1b0ce0: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1b0ce0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1b0ce4: 0x24634266  addiu       $v1, $v1, 0x4266
    ctx->pc = 0x1b0ce4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16998));
    // 0x1b0ce8: 0x6e5021  addu        $t2, $v1, $t6
    ctx->pc = 0x1b0ce8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x1b0cec: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1b0cecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1b0cf0: 0xc06027  not         $t4, $a2
    ctx->pc = 0x1b0cf0u;
    SET_GPR_U64(ctx, 12, ~(GPR_U64(ctx, 6) | GPR_U64(ctx, 0)));
    // 0x1b0cf4: 0x2463426c  addiu       $v1, $v1, 0x426C
    ctx->pc = 0x1b0cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17004));
    // 0x1b0cf8: 0x8c2024  and         $a0, $a0, $t4
    ctx->pc = 0x1b0cf8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 12));
    // 0x1b0cfc: 0x6e4821  addu        $t1, $v1, $t6
    ctx->pc = 0x1b0cfcu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x1b0d00: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x1b0d00u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x1b0d04: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1b0d04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1b0d08: 0x8cad0008  lw          $t5, 0x8($a1)
    ctx->pc = 0x1b0d08u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x1b0d0c: 0x2463426e  addiu       $v1, $v1, 0x426E
    ctx->pc = 0x1b0d0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17006));
    // 0x1b0d10: 0x8cac000c  lw          $t4, 0xC($a1)
    ctx->pc = 0x1b0d10u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x1b0d14: 0x6e4021  addu        $t0, $v1, $t6
    ctx->pc = 0x1b0d14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x1b0d18: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1b0d18u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1b0d1c: 0x24634260  addiu       $v1, $v1, 0x4260
    ctx->pc = 0x1b0d1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16992));
    // 0x1b0d20: 0x6e3821  addu        $a3, $v1, $t6
    ctx->pc = 0x1b0d20u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x1b0d24: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1b0d24u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1b0d28: 0x1a06827  not         $t5, $t5
    ctx->pc = 0x1b0d28u;
    SET_GPR_U64(ctx, 13, ~(GPR_U64(ctx, 13) | GPR_U64(ctx, 0)));
    // 0x1b0d2c: 0x24634268  addiu       $v1, $v1, 0x4268
    ctx->pc = 0x1b0d2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17000));
    // 0x1b0d30: 0x18d6024  and         $t4, $t4, $t5
    ctx->pc = 0x1b0d30u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & GPR_U64(ctx, 13));
    // 0x1b0d34: 0x6e3021  addu        $a2, $v1, $t6
    ctx->pc = 0x1b0d34u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x1b0d38: 0xacac0004  sw          $t4, 0x4($a1)
    ctx->pc = 0x1b0d38u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 12));
    // 0x1b0d3c: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1b0d3cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1b0d40: 0x856b0000  lh          $t3, 0x0($t3)
    ctx->pc = 0x1b0d40u;
    SET_GPR_S32(ctx, 11, (int16_t)READ16(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x1b0d44: 0x24634262  addiu       $v1, $v1, 0x4262
    ctx->pc = 0x1b0d44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16994));
    // 0x1b0d48: 0x6e2021  addu        $a0, $v1, $t6
    ctx->pc = 0x1b0d48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x1b0d4c: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1b0d4cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1b0d50: 0x2463426a  addiu       $v1, $v1, 0x426A
    ctx->pc = 0x1b0d50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17002));
    // 0x1b0d54: 0x6e1821  addu        $v1, $v1, $t6
    ctx->pc = 0x1b0d54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x1b0d58: 0xa4ab0024  sh          $t3, 0x24($a1)
    ctx->pc = 0x1b0d58u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 36), (uint16_t)GPR_U32(ctx, 11));
    // 0x1b0d5c: 0x854a0000  lh          $t2, 0x0($t2)
    ctx->pc = 0x1b0d5cu;
    SET_GPR_S32(ctx, 10, (int16_t)READ16(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x1b0d60: 0xa4aa0026  sh          $t2, 0x26($a1)
    ctx->pc = 0x1b0d60u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 38), (uint16_t)GPR_U32(ctx, 10));
    // 0x1b0d64: 0x85290000  lh          $t1, 0x0($t1)
    ctx->pc = 0x1b0d64u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1b0d68: 0xa4a9002c  sh          $t1, 0x2C($a1)
    ctx->pc = 0x1b0d68u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 44), (uint16_t)GPR_U32(ctx, 9));
    // 0x1b0d6c: 0x85080000  lh          $t0, 0x0($t0)
    ctx->pc = 0x1b0d6cu;
    SET_GPR_S32(ctx, 8, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1b0d70: 0xa4a8002e  sh          $t0, 0x2E($a1)
    ctx->pc = 0x1b0d70u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 46), (uint16_t)GPR_U32(ctx, 8));
    // 0x1b0d74: 0x84e70000  lh          $a3, 0x0($a3)
    ctx->pc = 0x1b0d74u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1b0d78: 0xa4a70020  sh          $a3, 0x20($a1)
    ctx->pc = 0x1b0d78u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 32), (uint16_t)GPR_U32(ctx, 7));
    // 0x1b0d7c: 0x84c60000  lh          $a2, 0x0($a2)
    ctx->pc = 0x1b0d7cu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1b0d80: 0xa4a60028  sh          $a2, 0x28($a1)
    ctx->pc = 0x1b0d80u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 40), (uint16_t)GPR_U32(ctx, 6));
    // 0x1b0d84: 0x84840000  lh          $a0, 0x0($a0)
    ctx->pc = 0x1b0d84u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b0d88: 0xa4a40022  sh          $a0, 0x22($a1)
    ctx->pc = 0x1b0d88u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 34), (uint16_t)GPR_U32(ctx, 4));
    // 0x1b0d8c: 0x84630000  lh          $v1, 0x0($v1)
    ctx->pc = 0x1b0d8cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b0d90: 0xa4a3002a  sh          $v1, 0x2A($a1)
    ctx->pc = 0x1b0d90u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 42), (uint16_t)GPR_U32(ctx, 3));
label_1b0d94:
    // 0x1b0d94: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b0d94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1b0d98:
    // 0x1b0d98: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b0d98u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b0d9c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b0d9cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0da0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0DA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0DA0u;
            // 0x1b0da4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0B9Cu: goto label_1b0b9c;
            case 0x1B0BC0u: goto label_1b0bc0;
            case 0x1B0BC8u: goto label_1b0bc8;
            case 0x1B0BE8u: goto label_1b0be8;
            case 0x1B0BF4u: goto label_1b0bf4;
            case 0x1B0BF8u: goto label_1b0bf8;
            case 0x1B0C94u: goto label_1b0c94;
            case 0x1B0CA4u: goto label_1b0ca4;
            case 0x1B0CB0u: goto label_1b0cb0;
            case 0x1B0D94u: goto label_1b0d94;
            case 0x1B0D98u: goto label_1b0d98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0DA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
