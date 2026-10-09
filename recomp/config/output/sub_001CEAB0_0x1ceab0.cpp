#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CEAB0
// Address: 0x1ceab0 - 0x1ced20
void sub_001CEAB0_0x1ceab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CEAB0_0x1ceab0");
#endif

    switch (ctx->pc) {
        case 0x1ceaf8u: goto label_1ceaf8;
        case 0x1ceb1cu: goto label_1ceb1c;
        case 0x1ceb60u: goto label_1ceb60;
        case 0x1ceb78u: goto label_1ceb78;
        case 0x1ceb84u: goto label_1ceb84;
        case 0x1ceba0u: goto label_1ceba0;
        case 0x1cebb0u: goto label_1cebb0;
        case 0x1cebbcu: goto label_1cebbc;
        case 0x1cebdcu: goto label_1cebdc;
        case 0x1cebecu: goto label_1cebec;
        case 0x1cebf8u: goto label_1cebf8;
        case 0x1cec04u: goto label_1cec04;
        case 0x1cec48u: goto label_1cec48;
        case 0x1cec58u: goto label_1cec58;
        case 0x1cec78u: goto label_1cec78;
        case 0x1cec8cu: goto label_1cec8c;
        case 0x1ceca0u: goto label_1ceca0;
        case 0x1cecb0u: goto label_1cecb0;
        case 0x1cecc0u: goto label_1cecc0;
        case 0x1cecd0u: goto label_1cecd0;
        default: break;
    }

    ctx->pc = 0x1ceab0u;

    // 0x1ceab0: 0x27bdfc90  addiu       $sp, $sp, -0x370
    ctx->pc = 0x1ceab0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966416));
    // 0x1ceab4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1ceab4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1ceab8: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1ceab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1ceabc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1ceabcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1ceac0: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1ceac0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1ceac4: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    ctx->pc = 0x1ceac4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1ceac8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1ceac8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1ceacc: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x1ceaccu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cead0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1cead0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1cead4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1cead4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cead8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cead8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ceadc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ceadcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ceae0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ceae0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ceae4: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x1ceae4u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ceae8: 0x8c3166c8  lw          $s1, 0x66C8($at)
    ctx->pc = 0x1ceae8u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26312)));
    // 0x1ceaec: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1ceaecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ceaf0: 0xc0735c4  jal         func_1CD710
    ctx->pc = 0x1CEAF0u;
    SET_GPR_U32(ctx, 31, 0x1CEAF8u);
    ctx->pc = 0x1CEAF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEAF0u;
            // 0x1ceaf4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD710u;
    if (runtime->hasFunction(0x1CD710u)) {
        auto targetFn = runtime->lookupFunction(0x1CD710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEAF8u; }
        if (ctx->pc != 0x1CEAF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD710_0x1cd710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEAF8u; }
        if (ctx->pc != 0x1CEAF8u) { return; }
    }
    ctx->pc = 0x1CEAF8u;
label_1ceaf8:
    // 0x1ceaf8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1ceaf8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ceafc: 0x1200007d  beqz        $s0, . + 4 + (0x7D << 2)
    ctx->pc = 0x1CEAFCu;
    {
        const bool branch_taken_0x1ceafc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEB00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEAFCu;
            // 0x1ceb00: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ceafc) {
            ctx->pc = 0x1CECF4u;
            goto label_1cecf4;
        }
    }
    ctx->pc = 0x1CEB04u;
    // 0x1ceb04: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1ceb04u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1ceb08: 0x10400027  beqz        $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x1CEB08u;
    {
        const bool branch_taken_0x1ceb08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEB0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEB08u;
            // 0x1ceb0c: 0x27a40270  addiu       $a0, $sp, 0x270 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 624));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ceb08) {
            ctx->pc = 0x1CEBA8u;
            goto label_1ceba8;
        }
    }
    ctx->pc = 0x1CEB10u;
    // 0x1ceb10: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ceb10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ceb14: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CEB14u;
    SET_GPR_U32(ctx, 31, 0x1CEB1Cu);
    ctx->pc = 0x1CEB18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEB14u;
            // 0x1ceb18: 0x2405005c  addiu       $a1, $zero, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEB1Cu; }
        if (ctx->pc != 0x1CEB1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEB1Cu; }
        if (ctx->pc != 0x1CEB1Cu) { return; }
    }
    ctx->pc = 0x1CEB1Cu;
label_1ceb1c:
    // 0x1ceb1c: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CEB1Cu;
    {
        const bool branch_taken_0x1ceb1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ceb1c) {
            ctx->pc = 0x1CEB28u;
            goto label_1ceb28;
        }
    }
    ctx->pc = 0x1CEB24u;
    // 0x1ceb24: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ceb24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1ceb28:
    // 0x1ceb28: 0x80440000  lb          $a0, 0x0($v0)
    ctx->pc = 0x1ceb28u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ceb2c: 0x24030048  addiu       $v1, $zero, 0x48
    ctx->pc = 0x1ceb2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x1ceb30: 0x14830002  bne         $a0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CEB30u;
    {
        const bool branch_taken_0x1ceb30 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1CEB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEB30u;
            // 0x1ceb34: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ceb30) {
            ctx->pc = 0x1CEB3Cu;
            goto label_1ceb3c;
        }
    }
    ctx->pc = 0x1CEB38u;
    // 0x1ceb38: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1ceb38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1ceb3c:
    // 0x1ceb3c: 0x80640000  lb          $a0, 0x0($v1)
    ctx->pc = 0x1ceb3cu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ceb40: 0x24030045  addiu       $v1, $zero, 0x45
    ctx->pc = 0x1ceb40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
    // 0x1ceb44: 0x14830008  bne         $a0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1CEB44u;
    {
        const bool branch_taken_0x1ceb44 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1CEB48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEB44u;
            // 0x1ceb48: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ceb44) {
            ctx->pc = 0x1CEB68u;
            goto label_1ceb68;
        }
    }
    ctx->pc = 0x1CEB4Cu;
    // 0x1ceb4c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1ceb4cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1ceb50: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1ceb50u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ceb54: 0x27a40170  addiu       $a0, $sp, 0x170
    ctx->pc = 0x1ceb54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
    // 0x1ceb58: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CEB58u;
    SET_GPR_U32(ctx, 31, 0x1CEB60u);
    ctx->pc = 0x1CEB5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEB58u;
            // 0x1ceb5c: 0x24a56168  addiu       $a1, $a1, 0x6168 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24936));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEB60u; }
        if (ctx->pc != 0x1CEB60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEB60u; }
        if (ctx->pc != 0x1CEB60u) { return; }
    }
    ctx->pc = 0x1CEB60u;
label_1ceb60:
    // 0x1ceb60: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1CEB60u;
    {
        const bool branch_taken_0x1ceb60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEB64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEB60u;
            // 0x1ceb64: 0x27a40170  addiu       $a0, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ceb60) {
            ctx->pc = 0x1CEB7Cu;
            goto label_1ceb7c;
        }
    }
    ctx->pc = 0x1CEB68u;
label_1ceb68:
    // 0x1ceb68: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1ceb68u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ceb6c: 0x27a40170  addiu       $a0, $sp, 0x170
    ctx->pc = 0x1ceb6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
    // 0x1ceb70: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CEB70u;
    SET_GPR_U32(ctx, 31, 0x1CEB78u);
    ctx->pc = 0x1CEB74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEB70u;
            // 0x1ceb74: 0x24a56170  addiu       $a1, $a1, 0x6170 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24944));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEB78u; }
        if (ctx->pc != 0x1CEB78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEB78u; }
        if (ctx->pc != 0x1CEB78u) { return; }
    }
    ctx->pc = 0x1CEB78u;
label_1ceb78:
    // 0x1ceb78: 0x27a40170  addiu       $a0, $sp, 0x170
    ctx->pc = 0x1ceb78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
label_1ceb7c:
    // 0x1ceb7c: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CEB7Cu;
    SET_GPR_U32(ctx, 31, 0x1CEB84u);
    ctx->pc = 0x1CEB80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEB7Cu;
            // 0x1ceb80: 0x2405002e  addiu       $a1, $zero, 0x2E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEB84u; }
        if (ctx->pc != 0x1CEB84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEB84u; }
        if (ctx->pc != 0x1CEB84u) { return; }
    }
    ctx->pc = 0x1CEB84u;
label_1ceb84:
    // 0x1ceb84: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CEB84u;
    {
        const bool branch_taken_0x1ceb84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEB88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEB84u;
            // 0x1ceb88: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ceb84) {
            ctx->pc = 0x1CEB90u;
            goto label_1ceb90;
        }
    }
    ctx->pc = 0x1CEB8Cu;
    // 0x1ceb8c: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x1ceb8cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
label_1ceb90:
    // 0x1ceb90: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1ceb90u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ceb94: 0x27a40170  addiu       $a0, $sp, 0x170
    ctx->pc = 0x1ceb94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
    // 0x1ceb98: 0xc06ab48  jal         func_1AAD20
    ctx->pc = 0x1CEB98u;
    SET_GPR_U32(ctx, 31, 0x1CEBA0u);
    ctx->pc = 0x1CEB9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEB98u;
            // 0x1ceb9c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AAD20u;
    if (runtime->hasFunction(0x1AAD20u)) {
        auto targetFn = runtime->lookupFunction(0x1AAD20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEBA0u; }
        if (ctx->pc != 0x1CEBA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AAD20_0x1aad20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEBA0u; }
        if (ctx->pc != 0x1CEBA0u) { return; }
    }
    ctx->pc = 0x1CEBA0u;
label_1ceba0:
    // 0x1ceba0: 0x10000055  b           . + 4 + (0x55 << 2)
    ctx->pc = 0x1CEBA0u;
    {
        const bool branch_taken_0x1ceba0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEBA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEBA0u;
            // 0x1ceba4: 0xdfbf0060  ld          $ra, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ceba0) {
            ctx->pc = 0x1CECF8u;
            goto label_1cecf8;
        }
    }
    ctx->pc = 0x1CEBA8u;
label_1ceba8:
    // 0x1ceba8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1CEBA8u;
    SET_GPR_U32(ctx, 31, 0x1CEBB0u);
    ctx->pc = 0x1CEBACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEBA8u;
            // 0x1cebac: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEBB0u; }
        if (ctx->pc != 0x1CEBB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEBB0u; }
        if (ctx->pc != 0x1CEBB0u) { return; }
    }
    ctx->pc = 0x1CEBB0u;
label_1cebb0:
    // 0x1cebb0: 0x27a40270  addiu       $a0, $sp, 0x270
    ctx->pc = 0x1cebb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 624));
    // 0x1cebb4: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CEBB4u;
    SET_GPR_U32(ctx, 31, 0x1CEBBCu);
    ctx->pc = 0x1CEBB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEBB4u;
            // 0x1cebb8: 0x2405005c  addiu       $a1, $zero, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEBBCu; }
        if (ctx->pc != 0x1CEBBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEBBCu; }
        if (ctx->pc != 0x1CEBBCu) { return; }
    }
    ctx->pc = 0x1CEBBCu;
label_1cebbc:
    // 0x1cebbc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1cebbcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cebc0: 0xa0400001  sb          $zero, 0x1($v0)
    ctx->pc = 0x1cebc0u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cebc4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cebc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cebc8: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1cebc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cebcc: 0x8c300ae0  lw          $s0, 0xAE0($at)
    ctx->pc = 0x1cebccu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2784)));
    // 0x1cebd0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1cebd0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cebd4: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1CEBD4u;
    SET_GPR_U32(ctx, 31, 0x1CEBDCu);
    ctx->pc = 0x1CEBD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEBD4u;
            // 0x1cebd8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEBDCu; }
        if (ctx->pc != 0x1CEBDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEBDCu; }
        if (ctx->pc != 0x1CEBDCu) { return; }
    }
    ctx->pc = 0x1CEBDCu;
label_1cebdc:
    // 0x1cebdc: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x1cebdcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cebe0: 0x1a800044  blez        $s4, . + 4 + (0x44 << 2)
    ctx->pc = 0x1CEBE0u;
    {
        const bool branch_taken_0x1cebe0 = (GPR_S64(ctx, 20) <= 0);
        ctx->pc = 0x1CEBE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEBE0u;
            // 0x1cebe4: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cebe0) {
            ctx->pc = 0x1CECF4u;
            goto label_1cecf4;
        }
    }
    ctx->pc = 0x1CEBE8u;
    // 0x1cebe8: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1cebe8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cebec:
    // 0x1cebec: 0x27a40170  addiu       $a0, $sp, 0x170
    ctx->pc = 0x1cebecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
    // 0x1cebf0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1CEBF0u;
    SET_GPR_U32(ctx, 31, 0x1CEBF8u);
    ctx->pc = 0x1CEBF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEBF0u;
            // 0x1cebf4: 0x27a50270  addiu       $a1, $sp, 0x270 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEBF8u; }
        if (ctx->pc != 0x1CEBF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEBF8u; }
        if (ctx->pc != 0x1CEBF8u) { return; }
    }
    ctx->pc = 0x1CEBF8u;
label_1cebf8:
    // 0x1cebf8: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1cebf8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1cebfc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CEBFCu;
    {
        const bool branch_taken_0x1cebfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEC00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEBFCu;
            // 0x1cec00: 0x2403000a  addiu       $v1, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cebfc) {
            ctx->pc = 0x1CEC1Cu;
            goto label_1cec1c;
        }
    }
    ctx->pc = 0x1CEC04u;
label_1cec04:
    // 0x1cec04: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1cec04u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1cec08: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1cec08u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1cec0c: 0x274082a  slt         $at, $s3, $s4
    ctx->pc = 0x1cec0cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x1cec10: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1cec10u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1cec14: 0x10200033  beqz        $at, . + 4 + (0x33 << 2)
    ctx->pc = 0x1CEC14u;
    {
        const bool branch_taken_0x1cec14 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEC18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEC14u;
            // 0x1cec18: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cec14) {
            ctx->pc = 0x1CECE4u;
            goto label_1cece4;
        }
    }
    ctx->pc = 0x1CEC1Cu;
label_1cec1c:
    // 0x1cec1c: 0x82050000  lb          $a1, 0x0($s0)
    ctx->pc = 0x1cec1cu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cec20: 0x10a30003  beq         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CEC20u;
    {
        const bool branch_taken_0x1cec20 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1cec20) {
            ctx->pc = 0x1CEC30u;
            goto label_1cec30;
        }
    }
    ctx->pc = 0x1CEC28u;
    // 0x1cec28: 0x14a0fff6  bnez        $a1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1CEC28u;
    {
        const bool branch_taken_0x1cec28 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cec28) {
            ctx->pc = 0x1CEC04u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cec04;
        }
    }
    ctx->pc = 0x1CEC30u;
label_1cec30:
    // 0x1cec30: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1cec30u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cec34: 0x2405002e  addiu       $a1, $zero, 0x2E
    ctx->pc = 0x1cec34u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1cec38: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1cec38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1cec3c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1cec3cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1cec40: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CEC40u;
    SET_GPR_U32(ctx, 31, 0x1CEC48u);
    ctx->pc = 0x1CEC44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEC40u;
            // 0x1cec44: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEC48u; }
        if (ctx->pc != 0x1CEC48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEC48u; }
        if (ctx->pc != 0x1CEC48u) { return; }
    }
    ctx->pc = 0x1CEC48u;
label_1cec48:
    // 0x1cec48: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CEC48u;
    {
        const bool branch_taken_0x1cec48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CEC4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEC48u;
            // 0x1cec4c: 0x27a40070  addiu       $a0, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cec48) {
            ctx->pc = 0x1CEC68u;
            goto label_1cec68;
        }
    }
    ctx->pc = 0x1CEC50u;
    // 0x1cec50: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CEC50u;
    SET_GPR_U32(ctx, 31, 0x1CEC58u);
    ctx->pc = 0x1CEC54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEC50u;
            // 0x1cec54: 0x2405002c  addiu       $a1, $zero, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEC58u; }
        if (ctx->pc != 0x1CEC58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEC58u; }
        if (ctx->pc != 0x1CEC58u) { return; }
    }
    ctx->pc = 0x1CEC58u;
label_1cec58:
    // 0x1cec58: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CEC58u;
    {
        const bool branch_taken_0x1cec58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEC5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEC58u;
            // 0x1cec5c: 0x27a40070  addiu       $a0, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cec58) {
            ctx->pc = 0x1CEC70u;
            goto label_1cec70;
        }
    }
    ctx->pc = 0x1CEC60u;
    // 0x1cec60: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1CEC60u;
    {
        const bool branch_taken_0x1cec60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEC64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEC60u;
            // 0x1cec64: 0xa0400000  sb          $zero, 0x0($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cec60) {
            ctx->pc = 0x1CEC6Cu;
            goto label_1cec6c;
        }
    }
    ctx->pc = 0x1CEC68u;
label_1cec68:
    // 0x1cec68: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x1cec68u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
label_1cec6c:
    // 0x1cec6c: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1cec6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
label_1cec70:
    // 0x1cec70: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1CEC70u;
    SET_GPR_U32(ctx, 31, 0x1CEC78u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEC78u; }
        if (ctx->pc != 0x1CEC78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEC78u; }
        if (ctx->pc != 0x1CEC78u) { return; }
    }
    ctx->pc = 0x1CEC78u;
label_1cec78:
    // 0x1cec78: 0x1040001b  beqz        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1CEC78u;
    {
        const bool branch_taken_0x1cec78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEC7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEC78u;
            // 0x1cec7c: 0x2a410007  slti        $at, $s2, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)7) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cec78) {
            ctx->pc = 0x1CECE8u;
            goto label_1cece8;
        }
    }
    ctx->pc = 0x1CEC80u;
    // 0x1cec80: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1cec80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1cec84: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CEC84u;
    SET_GPR_U32(ctx, 31, 0x1CEC8Cu);
    ctx->pc = 0x1CEC88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEC84u;
            // 0x1cec88: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEC8Cu; }
        if (ctx->pc != 0x1CEC8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEC8Cu; }
        if (ctx->pc != 0x1CEC8Cu) { return; }
    }
    ctx->pc = 0x1CEC8Cu;
label_1cec8c:
    // 0x1cec8c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CEC8Cu;
    {
        const bool branch_taken_0x1cec8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEC90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEC8Cu;
            // 0x1cec90: 0x27a40170  addiu       $a0, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cec8c) {
            ctx->pc = 0x1CECA8u;
            goto label_1ceca8;
        }
    }
    ctx->pc = 0x1CEC94u;
    // 0x1cec94: 0x24450001  addiu       $a1, $v0, 0x1
    ctx->pc = 0x1cec94u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cec98: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CEC98u;
    SET_GPR_U32(ctx, 31, 0x1CECA0u);
    ctx->pc = 0x1CEC9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEC98u;
            // 0x1cec9c: 0x27a40170  addiu       $a0, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CECA0u; }
        if (ctx->pc != 0x1CECA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CECA0u; }
        if (ctx->pc != 0x1CECA0u) { return; }
    }
    ctx->pc = 0x1CECA0u;
label_1ceca0:
    // 0x1ceca0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1CECA0u;
    {
        const bool branch_taken_0x1ceca0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ceca0) {
            ctx->pc = 0x1CECB0u;
            goto label_1cecb0;
        }
    }
    ctx->pc = 0x1CECA8u;
label_1ceca8:
    // 0x1ceca8: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CECA8u;
    SET_GPR_U32(ctx, 31, 0x1CECB0u);
    ctx->pc = 0x1CECACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CECA8u;
            // 0x1cecac: 0x27a50070  addiu       $a1, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CECB0u; }
        if (ctx->pc != 0x1CECB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CECB0u; }
        if (ctx->pc != 0x1CECB0u) { return; }
    }
    ctx->pc = 0x1CECB0u;
label_1cecb0:
    // 0x1cecb0: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cecb0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cecb4: 0x27a40170  addiu       $a0, $sp, 0x170
    ctx->pc = 0x1cecb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
    // 0x1cecb8: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CECB8u;
    SET_GPR_U32(ctx, 31, 0x1CECC0u);
    ctx->pc = 0x1CECBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CECB8u;
            // 0x1cecbc: 0x24a560c0  addiu       $a1, $a1, 0x60C0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24768));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CECC0u; }
        if (ctx->pc != 0x1CECC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CECC0u; }
        if (ctx->pc != 0x1CECC0u) { return; }
    }
    ctx->pc = 0x1CECC0u;
label_1cecc0:
    // 0x1cecc0: 0x27a40170  addiu       $a0, $sp, 0x170
    ctx->pc = 0x1cecc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
    // 0x1cecc4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1cecc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cecc8: 0xc073364  jal         func_1CCD90
    ctx->pc = 0x1CECC8u;
    SET_GPR_U32(ctx, 31, 0x1CECD0u);
    ctx->pc = 0x1CECCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CECC8u;
            // 0x1ceccc: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCD90u;
    if (runtime->hasFunction(0x1CCD90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CECD0u; }
        if (ctx->pc != 0x1CECD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCD90_0x1ccd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CECD0u; }
        if (ctx->pc != 0x1CECD0u) { return; }
    }
    ctx->pc = 0x1CECD0u;
label_1cecd0:
    // 0x1cecd0: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1cecd0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1cecd4: 0xa6a20000  sh          $v0, 0x0($s5)
    ctx->pc = 0x1cecd4u;
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cecd8: 0x2a410007  slti        $at, $s2, 0x7
    ctx->pc = 0x1cecd8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)7) ? 1 : 0);
    // 0x1cecdc: 0x1420ffc3  bnez        $at, . + 4 + (-0x3D << 2)
    ctx->pc = 0x1CECDCu;
    {
        const bool branch_taken_0x1cecdc = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CECE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CECDCu;
            // 0x1cece0: 0x26b50002  addiu       $s5, $s5, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cecdc) {
            ctx->pc = 0x1CEBECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cebec;
        }
    }
    ctx->pc = 0x1CECE4u;
label_1cece4:
    // 0x1cece4: 0x2a410007  slti        $at, $s2, 0x7
    ctx->pc = 0x1cece4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)7) ? 1 : 0);
label_1cece8:
    // 0x1cece8: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CECE8u;
    {
        const bool branch_taken_0x1cece8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CECECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CECE8u;
            // 0x1cecec: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cece8) {
            ctx->pc = 0x1CECF4u;
            goto label_1cecf4;
        }
    }
    ctx->pc = 0x1CECF0u;
    // 0x1cecf0: 0xa6a30000  sh          $v1, 0x0($s5)
    ctx->pc = 0x1cecf0u;
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 3));
label_1cecf4:
    // 0x1cecf4: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1cecf4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_1cecf8:
    // 0x1cecf8: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1cecf8u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1cecfc: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1cecfcu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ced00: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ced00u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ced04: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ced04u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ced08: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ced08u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ced0c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ced0cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ced10: 0x3e00008  jr          $ra
    ctx->pc = 0x1CED10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CED14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CED10u;
            // 0x1ced14: 0x27bd0370  addiu       $sp, $sp, 0x370 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 880));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CEAF8u: goto label_1ceaf8;
            case 0x1CEB1Cu: goto label_1ceb1c;
            case 0x1CEB28u: goto label_1ceb28;
            case 0x1CEB3Cu: goto label_1ceb3c;
            case 0x1CEB60u: goto label_1ceb60;
            case 0x1CEB68u: goto label_1ceb68;
            case 0x1CEB78u: goto label_1ceb78;
            case 0x1CEB7Cu: goto label_1ceb7c;
            case 0x1CEB84u: goto label_1ceb84;
            case 0x1CEB90u: goto label_1ceb90;
            case 0x1CEBA0u: goto label_1ceba0;
            case 0x1CEBA8u: goto label_1ceba8;
            case 0x1CEBB0u: goto label_1cebb0;
            case 0x1CEBBCu: goto label_1cebbc;
            case 0x1CEBDCu: goto label_1cebdc;
            case 0x1CEBECu: goto label_1cebec;
            case 0x1CEBF8u: goto label_1cebf8;
            case 0x1CEC04u: goto label_1cec04;
            case 0x1CEC1Cu: goto label_1cec1c;
            case 0x1CEC30u: goto label_1cec30;
            case 0x1CEC48u: goto label_1cec48;
            case 0x1CEC58u: goto label_1cec58;
            case 0x1CEC68u: goto label_1cec68;
            case 0x1CEC6Cu: goto label_1cec6c;
            case 0x1CEC70u: goto label_1cec70;
            case 0x1CEC78u: goto label_1cec78;
            case 0x1CEC8Cu: goto label_1cec8c;
            case 0x1CECA0u: goto label_1ceca0;
            case 0x1CECA8u: goto label_1ceca8;
            case 0x1CECB0u: goto label_1cecb0;
            case 0x1CECC0u: goto label_1cecc0;
            case 0x1CECD0u: goto label_1cecd0;
            case 0x1CECE4u: goto label_1cece4;
            case 0x1CECE8u: goto label_1cece8;
            case 0x1CECF4u: goto label_1cecf4;
            case 0x1CECF8u: goto label_1cecf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CED18u;
    // 0x1ced18: 0x0  nop
    ctx->pc = 0x1ced18u;
    // NOP
    // 0x1ced1c: 0x0  nop
    ctx->pc = 0x1ced1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
