#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BDC30
// Address: 0x1bdc30 - 0x1bdda4
void sub_001BDC30_0x1bdc30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BDC30_0x1bdc30");
#endif

    switch (ctx->pc) {
        case 0x1bdc90u: goto label_1bdc90;
        case 0x1bdcb8u: goto label_1bdcb8;
        case 0x1bdcc4u: goto label_1bdcc4;
        case 0x1bdcd0u: goto label_1bdcd0;
        case 0x1bdcd8u: goto label_1bdcd8;
        case 0x1bdce8u: goto label_1bdce8;
        case 0x1bdd04u: goto label_1bdd04;
        case 0x1bdd0cu: goto label_1bdd0c;
        case 0x1bdd28u: goto label_1bdd28;
        case 0x1bdd38u: goto label_1bdd38;
        case 0x1bdd68u: goto label_1bdd68;
        case 0x1bdd70u: goto label_1bdd70;
        default: break;
    }

    ctx->pc = 0x1bdc30u;

    // 0x1bdc30: 0x27bdfe80  addiu       $sp, $sp, -0x180
    ctx->pc = 0x1bdc30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966912));
    // 0x1bdc34: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1bdc34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1bdc38: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1bdc38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1bdc3c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1bdc3cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1bdc40: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1bdc40u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1bdc44: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bdc44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bdc48: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1bdc48u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1bdc4c: 0x24424fc0  addiu       $v0, $v0, 0x4FC0
    ctx->pc = 0x1bdc4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20416));
    // 0x1bdc50: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1bdc50u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1bdc54: 0x24a50440  addiu       $a1, $a1, 0x440
    ctx->pc = 0x1bdc54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1088));
    // 0x1bdc58: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1bdc58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1bdc5c: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1bdc5cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdc60: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1bdc60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1bdc64: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1bdc64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1bdc68: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bdc68u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bdc6c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bdc6cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bdc70: 0x8c324860  lw          $s2, 0x4860($at)
    ctx->pc = 0x1bdc70u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18528)));
    // 0x1bdc74: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bdc74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bdc78: 0x8c234868  lw          $v1, 0x4868($at)
    ctx->pc = 0x1bdc78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18536)));
    // 0x1bdc7c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bdc7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bdc80: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bdc80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bdc84: 0x8c530000  lw          $s3, 0x0($v0)
    ctx->pc = 0x1bdc84u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bdc88: 0xc06f918  jal         func_1BE460
    ctx->pc = 0x1BDC88u;
    SET_GPR_U32(ctx, 31, 0x1BDC90u);
    ctx->pc = 0x1BDC8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDC88u;
            // 0x1bdc8c: 0x24061234  addiu       $a2, $zero, 0x1234 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4660));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE460u;
    if (runtime->hasFunction(0x1BE460u)) {
        auto targetFn = runtime->lookupFunction(0x1BE460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDC90u; }
        if (ctx->pc != 0x1BDC90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE460_0x1be460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDC90u; }
        if (ctx->pc != 0x1BDC90u) { return; }
    }
    ctx->pc = 0x1BDC90u;
label_1bdc90:
    // 0x1bdc90: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1bdc90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1bdc94: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1bdc94u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1bdc98: 0x121940  sll         $v1, $s2, 5
    ctx->pc = 0x1bdc98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 5));
    // 0x1bdc9c: 0x24424520  addiu       $v0, $v0, 0x4520
    ctx->pc = 0x1bdc9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17696));
    // 0x1bdca0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bdca0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bdca4: 0x27a40100  addiu       $a0, $sp, 0x100
    ctx->pc = 0x1bdca4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x1bdca8: 0x24470010  addiu       $a3, $v0, 0x10
    ctx->pc = 0x1bdca8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1bdcac: 0x24a50458  addiu       $a1, $a1, 0x458
    ctx->pc = 0x1bdcacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1112));
    // 0x1bdcb0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1BDCB0u;
    SET_GPR_U32(ctx, 31, 0x1BDCB8u);
    ctx->pc = 0x1BDCB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDCB0u;
            // 0x1bdcb4: 0x27a60080  addiu       $a2, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDCB8u; }
        if (ctx->pc != 0x1BDCB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDCB8u; }
        if (ctx->pc != 0x1BDCB8u) { return; }
    }
    ctx->pc = 0x1BDCB8u;
label_1bdcb8:
    // 0x1bdcb8: 0x27a40100  addiu       $a0, $sp, 0x100
    ctx->pc = 0x1bdcb8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x1bdcbc: 0xc04629c  jal         func_118A70
    ctx->pc = 0x1BDCBCu;
    SET_GPR_U32(ctx, 31, 0x1BDCC4u);
    ctx->pc = 0x1BDCC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDCBCu;
            // 0x1bdcc0: 0x24050203  addiu       $a1, $zero, 0x203 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 515));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDCC4u; }
        if (ctx->pc != 0x1BDCC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDCC4u; }
        if (ctx->pc != 0x1BDCC4u) { return; }
    }
    ctx->pc = 0x1BDCC4u;
label_1bdcc4:
    // 0x1bdcc4: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1BDCC4u;
    {
        const bool branch_taken_0x1bdcc4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1BDCC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDCC4u;
            // 0x1bdcc8: 0x40a82d  daddu       $s5, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdcc4) {
            ctx->pc = 0x1BDCE0u;
            goto label_1bdce0;
        }
    }
    ctx->pc = 0x1BDCCCu;
    // 0x1bdccc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1bdcccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_1bdcd0:
    // 0x1bdcd0: 0xc06f660  jal         func_1BD980
    ctx->pc = 0x1BDCD0u;
    SET_GPR_U32(ctx, 31, 0x1BDCD8u);
    ctx->pc = 0x1BDCD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDCD0u;
            // 0x1bdcd4: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD980u;
    if (runtime->hasFunction(0x1BD980u)) {
        auto targetFn = runtime->lookupFunction(0x1BD980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDCD8u; }
        if (ctx->pc != 0x1BDCD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD980_0x1bd980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDCD8u; }
        if (ctx->pc != 0x1BDCD8u) { return; }
    }
    ctx->pc = 0x1BDCD8u;
label_1bdcd8:
    // 0x1bdcd8: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1BDCD8u;
    {
        const bool branch_taken_0x1bdcd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDCDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDCD8u;
            // 0x1bdcdc: 0xdfbf0070  ld          $ra, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdcd8) {
            ctx->pc = 0x1BDD80u;
            goto label_1bdd80;
        }
    }
    ctx->pc = 0x1BDCE0u;
label_1bdce0:
    // 0x1bdce0: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1BDCE0u;
    {
        const bool branch_taken_0x1bdce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDCE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDCE0u;
            // 0x1bdce4: 0x2a0882d  daddu       $s1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdce0) {
            ctx->pc = 0x1BDD4Cu;
            goto label_1bdd4c;
        }
    }
    ctx->pc = 0x1BDCE8u;
label_1bdce8:
    // 0x1bdce8: 0x121940  sll         $v1, $s2, 5
    ctx->pc = 0x1bdce8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 5));
    // 0x1bdcec: 0x80500000  lb          $s0, 0x0($v0)
    ctx->pc = 0x1bdcecu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bdcf0: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1bdcf0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1bdcf4: 0x24424520  addiu       $v0, $v0, 0x4520
    ctx->pc = 0x1bdcf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17696));
    // 0x1bdcf8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bdcf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bdcfc: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1BDCFCu;
    {
        const bool branch_taken_0x1bdcfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDD00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDCFCu;
            // 0x1bdd00: 0x24560010  addiu       $s6, $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdcfc) {
            ctx->pc = 0x1BDD44u;
            goto label_1bdd44;
        }
    }
    ctx->pc = 0x1BDD04u;
label_1bdd04:
    // 0x1bdd04: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1BDD04u;
    SET_GPR_U32(ctx, 31, 0x1BDD0Cu);
    ctx->pc = 0x1BDD08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDD04u;
            // 0x1bdd08: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDD0Cu; }
        if (ctx->pc != 0x1BDD0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDD0Cu; }
        if (ctx->pc != 0x1BDD0Cu) { return; }
    }
    ctx->pc = 0x1BDD0Cu;
label_1bdd0c:
    // 0x1bdd0c: 0x24470001  addiu       $a3, $v0, 0x1
    ctx->pc = 0x1bdd0cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bdd10: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1bdd10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdd14: 0x24056801  addiu       $a1, $zero, 0x6801
    ctx->pc = 0x1bdd14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 26625));
    // 0x1bdd18: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x1bdd18u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdd1c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bdd1cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdd20: 0xc046652  jal         func_119948
    ctx->pc = 0x1BDD20u;
    SET_GPR_U32(ctx, 31, 0x1BDD28u);
    ctx->pc = 0x1BDD24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDD20u;
            // 0x1bdd24: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119948u;
    if (runtime->hasFunction(0x119948u)) {
        auto targetFn = runtime->lookupFunction(0x119948u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDD28u; }
        if (ctx->pc != 0x1BDD28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119948_0x119948(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDD28u; }
        if (ctx->pc != 0x1BDD28u) { return; }
    }
    ctx->pc = 0x1BDD28u;
label_1bdd28:
    // 0x1bdd28: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BDD28u;
    {
        const bool branch_taken_0x1bdd28 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1BDD2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDD28u;
            // 0x1bdd2c: 0x40a82d  daddu       $s5, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdd28) {
            ctx->pc = 0x1BDD40u;
            goto label_1bdd40;
        }
    }
    ctx->pc = 0x1BDD30u;
    // 0x1bdd30: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1BDD30u;
    SET_GPR_U32(ctx, 31, 0x1BDD38u);
    ctx->pc = 0x1BDD34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDD30u;
            // 0x1bdd34: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDD38u; }
        if (ctx->pc != 0x1BDD38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDD38u; }
        if (ctx->pc != 0x1BDD38u) { return; }
    }
    ctx->pc = 0x1BDD38u;
label_1bdd38:
    // 0x1bdd38: 0x1000ffe5  b           . + 4 + (-0x1B << 2)
    ctx->pc = 0x1BDD38u;
    {
        const bool branch_taken_0x1bdd38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDD3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDD38u;
            // 0x1bdd3c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdd38) {
            ctx->pc = 0x1BDCD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bdcd0;
        }
    }
    ctx->pc = 0x1BDD40u;
label_1bdd40:
    // 0x1bdd40: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x1bdd40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
label_1bdd44:
    // 0x1bdd44: 0x1e00ffef  bgtz        $s0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1BDD44u;
    {
        const bool branch_taken_0x1bdd44 = (GPR_S64(ctx, 16) > 0);
        if (branch_taken_0x1bdd44) {
            ctx->pc = 0x1BDD04u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bdd04;
        }
    }
    ctx->pc = 0x1BDD4Cu;
label_1bdd4c:
    // 0x1bdd4c: 0x2652ffff  addiu       $s2, $s2, -0x1
    ctx->pc = 0x1bdd4cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x1bdd50: 0x641ffe5  bgez        $s2, . + 4 + (-0x1B << 2)
    ctx->pc = 0x1BDD50u;
    {
        const bool branch_taken_0x1bdd50 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x1BDD54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDD50u;
            // 0x1bdd54: 0x2721021  addu        $v0, $s3, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdd50) {
            ctx->pc = 0x1BDCE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bdce8;
        }
    }
    ctx->pc = 0x1BDD58u;
    // 0x1bdd58: 0x8e85000c  lw          $a1, 0xC($s4)
    ctx->pc = 0x1bdd58u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 12)));
    // 0x1bdd5c: 0x8e860030  lw          $a2, 0x30($s4)
    ctx->pc = 0x1bdd5cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 48)));
    // 0x1bdd60: 0xc0464c4  jal         func_119310
    ctx->pc = 0x1BDD60u;
    SET_GPR_U32(ctx, 31, 0x1BDD68u);
    ctx->pc = 0x1BDD64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDD60u;
            // 0x1bdd64: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119310u;
    if (runtime->hasFunction(0x119310u)) {
        auto targetFn = runtime->lookupFunction(0x119310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDD68u; }
        if (ctx->pc != 0x1BDD68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119310_0x119310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDD68u; }
        if (ctx->pc != 0x1BDD68u) { return; }
    }
    ctx->pc = 0x1BDD68u;
label_1bdd68:
    // 0x1bdd68: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1BDD68u;
    SET_GPR_U32(ctx, 31, 0x1BDD70u);
    ctx->pc = 0x1BDD6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDD68u;
            // 0x1bdd6c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDD70u; }
        if (ctx->pc != 0x1BDD70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDD70u; }
        if (ctx->pc != 0x1BDD70u) { return; }
    }
    ctx->pc = 0x1BDD70u;
label_1bdd70:
    // 0x1bdd70: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x1bdd70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1bdd74: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bdd74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bdd78: 0xae830000  sw          $v1, 0x0($s4)
    ctx->pc = 0x1bdd78u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 3));
    // 0x1bdd7c: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1bdd7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
label_1bdd80:
    // 0x1bdd80: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1bdd80u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1bdd84: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1bdd84u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1bdd88: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1bdd88u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1bdd8c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1bdd8cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1bdd90: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1bdd90u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bdd94: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bdd94u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bdd98: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bdd98u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bdd9c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BDD9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BDDA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDD9Cu;
            // 0x1bdda0: 0x27bd0180  addiu       $sp, $sp, 0x180 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 384));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BDC90u: goto label_1bdc90;
            case 0x1BDCB8u: goto label_1bdcb8;
            case 0x1BDCC4u: goto label_1bdcc4;
            case 0x1BDCD0u: goto label_1bdcd0;
            case 0x1BDCD8u: goto label_1bdcd8;
            case 0x1BDCE0u: goto label_1bdce0;
            case 0x1BDCE8u: goto label_1bdce8;
            case 0x1BDD04u: goto label_1bdd04;
            case 0x1BDD0Cu: goto label_1bdd0c;
            case 0x1BDD28u: goto label_1bdd28;
            case 0x1BDD38u: goto label_1bdd38;
            case 0x1BDD40u: goto label_1bdd40;
            case 0x1BDD44u: goto label_1bdd44;
            case 0x1BDD4Cu: goto label_1bdd4c;
            case 0x1BDD68u: goto label_1bdd68;
            case 0x1BDD70u: goto label_1bdd70;
            case 0x1BDD80u: goto label_1bdd80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BDDA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
