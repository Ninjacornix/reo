#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B9BA0
// Address: 0x1b9ba0 - 0x1b9e7c
void sub_001B9BA0_0x1b9ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B9BA0_0x1b9ba0");
#endif

    switch (ctx->pc) {
        case 0x1b9c14u: goto label_1b9c14;
        case 0x1b9c54u: goto label_1b9c54;
        case 0x1b9c70u: goto label_1b9c70;
        case 0x1b9c88u: goto label_1b9c88;
        case 0x1b9ca0u: goto label_1b9ca0;
        case 0x1b9cb4u: goto label_1b9cb4;
        case 0x1b9ce0u: goto label_1b9ce0;
        case 0x1b9e40u: goto label_1b9e40;
        case 0x1b9e50u: goto label_1b9e50;
        case 0x1b9e64u: goto label_1b9e64;
        default: break;
    }

    ctx->pc = 0x1b9ba0u;

    // 0x1b9ba0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1b9ba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1b9ba4: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1b9ba4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1b9ba8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b9ba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b9bac: 0x24a54c10  addiu       $a1, $a1, 0x4C10
    ctx->pc = 0x1b9bacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19472));
    // 0x1b9bb0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b9bb0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b9bb4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b9bb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9bb8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b9bb8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b9bbc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b9bbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b9bc0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b9bc0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9bc4: 0x84860038  lh          $a2, 0x38($a0)
    ctx->pc = 0x1b9bc4u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 56)));
    // 0x1b9bc8: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1b9bc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1b9bcc: 0x80840004  lb          $a0, 0x4($a0)
    ctx->pc = 0x1b9bccu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1b9bd0: 0x1083003a  beq         $a0, $v1, . + 4 + (0x3A << 2)
    ctx->pc = 0x1B9BD0u;
    {
        const bool branch_taken_0x1b9bd0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B9BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9BD0u;
            // 0x1b9bd4: 0x80b00000  lb          $s0, 0x0($a1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9bd0) {
            ctx->pc = 0x1B9CBCu;
            goto label_1b9cbc;
        }
    }
    ctx->pc = 0x1B9BD8u;
    // 0x1b9bd8: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B9BD8u;
    {
        const bool branch_taken_0x1b9bd8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9bd8) {
            ctx->pc = 0x1B9BE8u;
            goto label_1b9be8;
        }
    }
    ctx->pc = 0x1B9BE0u;
    // 0x1b9be0: 0x100000a1  b           . + 4 + (0xA1 << 2)
    ctx->pc = 0x1B9BE0u;
    {
        const bool branch_taken_0x1b9be0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9BE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9BE0u;
            // 0x1b9be4: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9be0) {
            ctx->pc = 0x1B9E68u;
            goto label_1b9e68;
        }
    }
    ctx->pc = 0x1B9BE8u;
label_1b9be8:
    // 0x1b9be8: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1b9be8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1b9bec: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1b9becu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b9bf0: 0xa2220004  sb          $v0, 0x4($s1)
    ctx->pc = 0x1b9bf0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b9bf4: 0x2624002c  addiu       $a0, $s1, 0x2C
    ctx->pc = 0x1b9bf4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9bf8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b9bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b9bfc: 0x26260014  addiu       $a2, $s1, 0x14
    ctx->pc = 0x1b9bfcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
    // 0x1b9c00: 0x24424bf0  addiu       $v0, $v0, 0x4BF0
    ctx->pc = 0x1b9c00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19440));
    // 0x1b9c04: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b9c04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9c08: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1b9c08u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b9c0c: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1B9C0Cu;
    SET_GPR_U32(ctx, 31, 0x1B9C14u);
    ctx->pc = 0x1B9C10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C0Cu;
            // 0x1b9c10: 0x26270018  addiu       $a3, $s1, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C14u; }
        if (ctx->pc != 0x1B9C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C14u; }
        if (ctx->pc != 0x1B9C14u) { return; }
    }
    ctx->pc = 0x1B9C14u;
label_1b9c14:
    // 0x1b9c14: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1b9c14u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9c18: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x1b9c18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9c1c: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x1b9c1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x1b9c20: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x1b9c20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1b9c24: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x1b9c24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x1b9c28: 0x82220001  lb          $v0, 0x1($s1)
    ctx->pc = 0x1b9c28u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x1b9c2c: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B9C2Cu;
    {
        const bool branch_taken_0x1b9c2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9c2c) {
            ctx->pc = 0x1B9C78u;
            goto label_1b9c78;
        }
    }
    ctx->pc = 0x1B9C34u;
    // 0x1b9c34: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9c34u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9c38: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9c38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9c3c: 0x8e270014  lw          $a3, 0x14($s1)
    ctx->pc = 0x1b9c3cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9c40: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9c40u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9c44: 0x8e280018  lw          $t0, 0x18($s1)
    ctx->pc = 0x1b9c44u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1b9c48: 0x2409ffff  addiu       $t1, $zero, -0x1
    ctx->pc = 0x1b9c48u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b9c4c: 0xc06b1fc  jal         func_1AC7F0
    ctx->pc = 0x1B9C4Cu;
    SET_GPR_U32(ctx, 31, 0x1B9C54u);
    ctx->pc = 0x1B9C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C4Cu;
            // 0x1b9c50: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AC7F0u;
    if (runtime->hasFunction(0x1AC7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AC7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C54u; }
        if (ctx->pc != 0x1B9C54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AC7F0_0x1ac7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C54u; }
        if (ctx->pc != 0x1B9C54u) { return; }
    }
    ctx->pc = 0x1B9C54u;
label_1b9c54:
    // 0x1b9c54: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9c54u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9c58: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9c58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9c5c: 0x8e270014  lw          $a3, 0x14($s1)
    ctx->pc = 0x1b9c5cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9c60: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9c60u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9c64: 0x8e280018  lw          $t0, 0x18($s1)
    ctx->pc = 0x1b9c64u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1b9c68: 0xc06b2d8  jal         func_1ACB60
    ctx->pc = 0x1B9C68u;
    SET_GPR_U32(ctx, 31, 0x1B9C70u);
    ctx->pc = 0x1B9C6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C68u;
            // 0x1b9c6c: 0x24092000  addiu       $t1, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACB60u;
    if (runtime->hasFunction(0x1ACB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ACB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C70u; }
        if (ctx->pc != 0x1B9C70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACB60_0x1acb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C70u; }
        if (ctx->pc != 0x1B9C70u) { return; }
    }
    ctx->pc = 0x1B9C70u;
label_1b9c70:
    // 0x1b9c70: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1B9C70u;
    {
        const bool branch_taken_0x1b9c70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C70u;
            // 0x1b9c74: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9c70) {
            ctx->pc = 0x1B9CB8u;
            goto label_1b9cb8;
        }
    }
    ctx->pc = 0x1B9C78u;
label_1b9c78:
    // 0x1b9c78: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9c78u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9c7c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9c7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9c80: 0xc06e85c  jal         func_1BA170
    ctx->pc = 0x1B9C80u;
    SET_GPR_U32(ctx, 31, 0x1B9C88u);
    ctx->pc = 0x1B9C84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C80u;
            // 0x1b9c84: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA170u;
    if (runtime->hasFunction(0x1BA170u)) {
        auto targetFn = runtime->lookupFunction(0x1BA170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C88u; }
        if (ctx->pc != 0x1B9C88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA170_0x1ba170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C88u; }
        if (ctx->pc != 0x1B9C88u) { return; }
    }
    ctx->pc = 0x1B9C88u;
label_1b9c88:
    // 0x1b9c88: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B9C88u;
    {
        const bool branch_taken_0x1b9c88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9c88) {
            ctx->pc = 0x1B9CB4u;
            goto label_1b9cb4;
        }
    }
    ctx->pc = 0x1B9C90u;
    // 0x1b9c90: 0x16400005  bnez        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B9C90u;
    {
        const bool branch_taken_0x1b9c90 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C90u;
            // 0x1b9c94: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9c90) {
            ctx->pc = 0x1B9CA8u;
            goto label_1b9ca8;
        }
    }
    ctx->pc = 0x1B9C98u;
    // 0x1b9c98: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1B9C98u;
    SET_GPR_U32(ctx, 31, 0x1B9CA0u);
    ctx->pc = 0x1B9C9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C98u;
            // 0x1b9c9c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CA0u; }
        if (ctx->pc != 0x1B9CA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CA0u; }
        if (ctx->pc != 0x1B9CA0u) { return; }
    }
    ctx->pc = 0x1B9CA0u;
label_1b9ca0:
    // 0x1b9ca0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9CA0u;
    {
        const bool branch_taken_0x1b9ca0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9ca0) {
            ctx->pc = 0x1B9CB4u;
            goto label_1b9cb4;
        }
    }
    ctx->pc = 0x1B9CA8u;
label_1b9ca8:
    // 0x1b9ca8: 0x8e250014  lw          $a1, 0x14($s1)
    ctx->pc = 0x1b9ca8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9cac: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1B9CACu;
    SET_GPR_U32(ctx, 31, 0x1B9CB4u);
    ctx->pc = 0x1B9CB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9CACu;
            // 0x1b9cb0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CB4u; }
        if (ctx->pc != 0x1B9CB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CB4u; }
        if (ctx->pc != 0x1B9CB4u) { return; }
    }
    ctx->pc = 0x1B9CB4u;
label_1b9cb4:
    // 0x1b9cb4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1b9cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_1b9cb8:
    // 0x1b9cb8: 0xa6220008  sh          $v0, 0x8($s1)
    ctx->pc = 0x1b9cb8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 2));
label_1b9cbc:
    // 0x1b9cbc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b9cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b9cc0: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1b9cc0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b9cc4: 0x24424bf0  addiu       $v0, $v0, 0x4BF0
    ctx->pc = 0x1b9cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19440));
    // 0x1b9cc8: 0x2624002c  addiu       $a0, $s1, 0x2C
    ctx->pc = 0x1b9cc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9ccc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b9cccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9cd0: 0x27a6004c  addiu       $a2, $sp, 0x4C
    ctx->pc = 0x1b9cd0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 76));
    // 0x1b9cd4: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1b9cd4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b9cd8: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1B9CD8u;
    SET_GPR_U32(ctx, 31, 0x1B9CE0u);
    ctx->pc = 0x1B9CDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9CD8u;
            // 0x1b9cdc: 0x27a70048  addiu       $a3, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CE0u; }
        if (ctx->pc != 0x1B9CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CE0u; }
        if (ctx->pc != 0x1B9CE0u) { return; }
    }
    ctx->pc = 0x1B9CE0u;
label_1b9ce0:
    // 0x1b9ce0: 0x8fa5004c  lw          $a1, 0x4C($sp)
    ctx->pc = 0x1b9ce0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1b9ce4: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1b9ce4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9ce8: 0x1065000e  beq         $v1, $a1, . + 4 + (0xE << 2)
    ctx->pc = 0x1B9CE8u;
    {
        const bool branch_taken_0x1b9ce8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1b9ce8) {
            ctx->pc = 0x1B9D24u;
            goto label_1b9d24;
        }
    }
    ctx->pc = 0x1B9CF0u;
    // 0x1b9cf0: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x1b9cf0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b9cf4: 0x3c034080  lui         $v1, 0x4080
    ctx->pc = 0x1b9cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16512 << 16));
    // 0x1b9cf8: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1b9cf8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b9cfc: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1b9cfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b9d00: 0xa42023  subu        $a0, $a1, $a0
    ctx->pc = 0x1b9d00u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1b9d04: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1b9d04u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b9d08: 0x0  nop
    ctx->pc = 0x1b9d08u;
    // NOP
    // 0x1b9d0c: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1b9d0cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1b9d10: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1b9d10u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1b9d14: 0xe620001c  swc1        $f0, 0x1C($s1)
    ctx->pc = 0x1b9d14u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 28), bits); }
    // 0x1b9d18: 0x8fa4004c  lw          $a0, 0x4C($sp)
    ctx->pc = 0x1b9d18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1b9d1c: 0xae240014  sw          $a0, 0x14($s1)
    ctx->pc = 0x1b9d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 4));
    // 0x1b9d20: 0xa6230008  sh          $v1, 0x8($s1)
    ctx->pc = 0x1b9d20u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 3));
label_1b9d24:
    // 0x1b9d24: 0x8fa50048  lw          $a1, 0x48($sp)
    ctx->pc = 0x1b9d24u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1b9d28: 0x8e230018  lw          $v1, 0x18($s1)
    ctx->pc = 0x1b9d28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1b9d2c: 0x1065000e  beq         $v1, $a1, . + 4 + (0xE << 2)
    ctx->pc = 0x1B9D2Cu;
    {
        const bool branch_taken_0x1b9d2c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1b9d2c) {
            ctx->pc = 0x1B9D68u;
            goto label_1b9d68;
        }
    }
    ctx->pc = 0x1B9D34u;
    // 0x1b9d34: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x1b9d34u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1b9d38: 0x3c034080  lui         $v1, 0x4080
    ctx->pc = 0x1b9d38u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16512 << 16));
    // 0x1b9d3c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1b9d3cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b9d40: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1b9d40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b9d44: 0xa42023  subu        $a0, $a1, $a0
    ctx->pc = 0x1b9d44u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1b9d48: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1b9d48u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b9d4c: 0x0  nop
    ctx->pc = 0x1b9d4cu;
    // NOP
    // 0x1b9d50: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1b9d50u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1b9d54: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1b9d54u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1b9d58: 0xe6200020  swc1        $f0, 0x20($s1)
    ctx->pc = 0x1b9d58u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 32), bits); }
    // 0x1b9d5c: 0x8fa40048  lw          $a0, 0x48($sp)
    ctx->pc = 0x1b9d5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1b9d60: 0xae240018  sw          $a0, 0x18($s1)
    ctx->pc = 0x1b9d60u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 4));
    // 0x1b9d64: 0xa623000a  sh          $v1, 0xA($s1)
    ctx->pc = 0x1b9d64u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 3));
label_1b9d68:
    // 0x1b9d68: 0x86230008  lh          $v1, 0x8($s1)
    ctx->pc = 0x1b9d68u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1b9d6c: 0x10600013  beqz        $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B9D6Cu;
    {
        const bool branch_taken_0x1b9d6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9D70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9D6Cu;
            // 0x1b9d70: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9d6c) {
            ctx->pc = 0x1B9DBCu;
            goto label_1b9dbc;
        }
    }
    ctx->pc = 0x1B9D74u;
    // 0x1b9d74: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b9d74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b9d78: 0xa6230008  sh          $v1, 0x8($s1)
    ctx->pc = 0x1b9d78u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b9d7c: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1b9d7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b9d80: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b9d80u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b9d84: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9D84u;
    {
        const bool branch_taken_0x1b9d84 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9d84) {
            ctx->pc = 0x1B9D98u;
            goto label_1b9d98;
        }
    }
    ctx->pc = 0x1B9D8Cu;
    // 0x1b9d8c: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1b9d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9d90: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B9D90u;
    {
        const bool branch_taken_0x1b9d90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9D90u;
            // 0x1b9d94: 0xae23000c  sw          $v1, 0xC($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9d90) {
            ctx->pc = 0x1B9DB8u;
            goto label_1b9db8;
        }
    }
    ctx->pc = 0x1B9D98u;
label_1b9d98:
    // 0x1b9d98: 0xc621000c  lwc1        $f1, 0xC($s1)
    ctx->pc = 0x1b9d98u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b9d9c: 0xc620001c  lwc1        $f0, 0x1C($s1)
    ctx->pc = 0x1b9d9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b9da0: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1b9da0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1b9da4: 0x46000800  add.s       $f0, $f1, $f0
    ctx->pc = 0x1b9da4u;
    ctx->f[0] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x1b9da8: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b9da8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b9dac: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1b9dacu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b9db0: 0x0  nop
    ctx->pc = 0x1b9db0u;
    // NOP
    // 0x1b9db4: 0xae23000c  sw          $v1, 0xC($s1)
    ctx->pc = 0x1b9db4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 3));
label_1b9db8:
    // 0x1b9db8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9db8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b9dbc:
    // 0x1b9dbc: 0x8623000a  lh          $v1, 0xA($s1)
    ctx->pc = 0x1b9dbcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 10)));
    // 0x1b9dc0: 0x10600013  beqz        $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B9DC0u;
    {
        const bool branch_taken_0x1b9dc0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9dc0) {
            ctx->pc = 0x1B9E10u;
            goto label_1b9e10;
        }
    }
    ctx->pc = 0x1B9DC8u;
    // 0x1b9dc8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b9dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b9dcc: 0xa623000a  sh          $v1, 0xA($s1)
    ctx->pc = 0x1b9dccu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b9dd0: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1b9dd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b9dd4: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b9dd4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b9dd8: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9DD8u;
    {
        const bool branch_taken_0x1b9dd8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9dd8) {
            ctx->pc = 0x1B9DECu;
            goto label_1b9dec;
        }
    }
    ctx->pc = 0x1B9DE0u;
    // 0x1b9de0: 0x8e230018  lw          $v1, 0x18($s1)
    ctx->pc = 0x1b9de0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1b9de4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B9DE4u;
    {
        const bool branch_taken_0x1b9de4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9DE4u;
            // 0x1b9de8: 0xae230010  sw          $v1, 0x10($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9de4) {
            ctx->pc = 0x1B9E0Cu;
            goto label_1b9e0c;
        }
    }
    ctx->pc = 0x1B9DECu;
label_1b9dec:
    // 0x1b9dec: 0xc6210010  lwc1        $f1, 0x10($s1)
    ctx->pc = 0x1b9decu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b9df0: 0xc6200020  lwc1        $f0, 0x20($s1)
    ctx->pc = 0x1b9df0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b9df4: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1b9df4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1b9df8: 0x46000800  add.s       $f0, $f1, $f0
    ctx->pc = 0x1b9df8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x1b9dfc: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b9dfcu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b9e00: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1b9e00u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b9e04: 0x0  nop
    ctx->pc = 0x1b9e04u;
    // NOP
    // 0x1b9e08: 0xae230010  sw          $v1, 0x10($s1)
    ctx->pc = 0x1b9e08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 3));
label_1b9e0c:
    // 0x1b9e0c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9e0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b9e10:
    // 0x1b9e10: 0x10800014  beqz        $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1B9E10u;
    {
        const bool branch_taken_0x1b9e10 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9e10) {
            ctx->pc = 0x1B9E64u;
            goto label_1b9e64;
        }
    }
    ctx->pc = 0x1B9E18u;
    // 0x1b9e18: 0x82220001  lb          $v0, 0x1($s1)
    ctx->pc = 0x1b9e18u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x1b9e1c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B9E1Cu;
    {
        const bool branch_taken_0x1b9e1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9E1Cu;
            // 0x1b9e20: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9e1c) {
            ctx->pc = 0x1B9E48u;
            goto label_1b9e48;
        }
    }
    ctx->pc = 0x1B9E24u;
    // 0x1b9e24: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9e24u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9e28: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9e28u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9e2c: 0x8e27000c  lw          $a3, 0xC($s1)
    ctx->pc = 0x1b9e2cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b9e30: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9e30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9e34: 0x8e280010  lw          $t0, 0x10($s1)
    ctx->pc = 0x1b9e34u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1b9e38: 0xc06b2d8  jal         func_1ACB60
    ctx->pc = 0x1B9E38u;
    SET_GPR_U32(ctx, 31, 0x1B9E40u);
    ctx->pc = 0x1B9E3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9E38u;
            // 0x1b9e3c: 0x24092000  addiu       $t1, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACB60u;
    if (runtime->hasFunction(0x1ACB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ACB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E40u; }
        if (ctx->pc != 0x1B9E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACB60_0x1acb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E40u; }
        if (ctx->pc != 0x1B9E40u) { return; }
    }
    ctx->pc = 0x1B9E40u;
label_1b9e40:
    // 0x1b9e40: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B9E40u;
    {
        const bool branch_taken_0x1b9e40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9e40) {
            ctx->pc = 0x1B9E64u;
            goto label_1b9e64;
        }
    }
    ctx->pc = 0x1B9E48u;
label_1b9e48:
    // 0x1b9e48: 0xc06b91c  jal         func_1AE470
    ctx->pc = 0x1B9E48u;
    SET_GPR_U32(ctx, 31, 0x1B9E50u);
    ctx->pc = 0x1AE470u;
    if (runtime->hasFunction(0x1AE470u)) {
        auto targetFn = runtime->lookupFunction(0x1AE470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E50u; }
        if (ctx->pc != 0x1B9E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE470_0x1ae470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E50u; }
        if (ctx->pc != 0x1B9E50u) { return; }
    }
    ctx->pc = 0x1B9E50u;
label_1b9e50:
    // 0x1b9e50: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9E50u;
    {
        const bool branch_taken_0x1b9e50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9e50) {
            ctx->pc = 0x1B9E64u;
            goto label_1b9e64;
        }
    }
    ctx->pc = 0x1B9E58u;
    // 0x1b9e58: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x1b9e58u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b9e5c: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1B9E5Cu;
    SET_GPR_U32(ctx, 31, 0x1B9E64u);
    ctx->pc = 0x1B9E60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9E5Cu;
            // 0x1b9e60: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E64u; }
        if (ctx->pc != 0x1B9E64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E64u; }
        if (ctx->pc != 0x1B9E64u) { return; }
    }
    ctx->pc = 0x1B9E64u;
label_1b9e64:
    // 0x1b9e64: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b9e64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1b9e68:
    // 0x1b9e68: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b9e68u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b9e6c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b9e6cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b9e70: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b9e70u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b9e74: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9E74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B9E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9E74u;
            // 0x1b9e78: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9BE8u: goto label_1b9be8;
            case 0x1B9C14u: goto label_1b9c14;
            case 0x1B9C54u: goto label_1b9c54;
            case 0x1B9C70u: goto label_1b9c70;
            case 0x1B9C78u: goto label_1b9c78;
            case 0x1B9C88u: goto label_1b9c88;
            case 0x1B9CA0u: goto label_1b9ca0;
            case 0x1B9CA8u: goto label_1b9ca8;
            case 0x1B9CB4u: goto label_1b9cb4;
            case 0x1B9CB8u: goto label_1b9cb8;
            case 0x1B9CBCu: goto label_1b9cbc;
            case 0x1B9CE0u: goto label_1b9ce0;
            case 0x1B9D24u: goto label_1b9d24;
            case 0x1B9D68u: goto label_1b9d68;
            case 0x1B9D98u: goto label_1b9d98;
            case 0x1B9DB8u: goto label_1b9db8;
            case 0x1B9DBCu: goto label_1b9dbc;
            case 0x1B9DECu: goto label_1b9dec;
            case 0x1B9E0Cu: goto label_1b9e0c;
            case 0x1B9E10u: goto label_1b9e10;
            case 0x1B9E40u: goto label_1b9e40;
            case 0x1B9E48u: goto label_1b9e48;
            case 0x1B9E50u: goto label_1b9e50;
            case 0x1B9E64u: goto label_1b9e64;
            case 0x1B9E68u: goto label_1b9e68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9E7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
