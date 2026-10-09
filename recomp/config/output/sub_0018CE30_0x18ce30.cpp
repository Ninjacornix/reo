#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018CE30
// Address: 0x18ce30 - 0x18cef0
void sub_0018CE30_0x18ce30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018CE30_0x18ce30");
#endif

    switch (ctx->pc) {
        case 0x18ce60u: goto label_18ce60;
        case 0x18ce74u: goto label_18ce74;
        case 0x18cea0u: goto label_18cea0;
        case 0x18ceb0u: goto label_18ceb0;
        case 0x18cec4u: goto label_18cec4;
        default: break;
    }

    ctx->pc = 0x18ce30u;

    // 0x18ce30: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x18ce30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x18ce34: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x18ce34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x18ce38: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x18ce38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x18ce3c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x18ce3cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x18ce40: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x18ce40u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ce44: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18ce44u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18ce48: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x18ce48u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ce4c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18ce4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18ce50: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x18ce50u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ce54: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18ce54u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18ce58: 0x58880  sll         $s1, $a1, 2
    ctx->pc = 0x18ce58u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x18ce5c: 0xac850004  sw          $a1, 0x4($a0)
    ctx->pc = 0x18ce5cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 5));
label_18ce60:
    // 0x18ce60: 0x121080  sll         $v0, $s2, 2
    ctx->pc = 0x18ce60u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x18ce64: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x18ce64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ce68: 0x2828021  addu        $s0, $s4, $v0
    ctx->pc = 0x18ce68u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x18ce6c: 0xc063714  jal         func_18DC50
    ctx->pc = 0x18CE6Cu;
    SET_GPR_U32(ctx, 31, 0x18CE74u);
    ctx->pc = 0x18CE70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18CE6Cu;
            // 0x18ce70: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DC50u;
    if (runtime->hasFunction(0x18DC50u)) {
        auto targetFn = runtime->lookupFunction(0x18DC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CE74u; }
        if (ctx->pc != 0x18CE74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC50_0x18dc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CE74u; }
        if (ctx->pc != 0x18CE74u) { return; }
    }
    ctx->pc = 0x18CE74u;
label_18ce74:
    // 0x18ce74: 0xae02000c  sw          $v0, 0xC($s0)
    ctx->pc = 0x18ce74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x18ce78: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x18ce78u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x18ce7c: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x18ce7cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x18ce80: 0x2a420002  slti        $v0, $s2, 0x2
    ctx->pc = 0x18ce80u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x18ce84: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x18ce84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x18ce88: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x18CE88u;
    {
        const bool branch_taken_0x18ce88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18CE8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18CE88u;
            // 0x18ce8c: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ce88) {
            ctx->pc = 0x18CE60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18ce60;
        }
    }
    ctx->pc = 0x18CE90u;
    // 0x18ce90: 0x8e840000  lw          $a0, 0x0($s4)
    ctx->pc = 0x18ce90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x18ce94: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x18ce94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ce98: 0xc0450cc  jal         func_114330
    ctx->pc = 0x18CE98u;
    SET_GPR_U32(ctx, 31, 0x18CEA0u);
    ctx->pc = 0x18CE9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18CE98u;
            // 0x18ce9c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114330u;
    if (runtime->hasFunction(0x114330u)) {
        auto targetFn = runtime->lookupFunction(0x114330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CEA0u; }
        if (ctx->pc != 0x18CEA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114330_0x114330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CEA0u; }
        if (ctx->pc != 0x18CEA0u) { return; }
    }
    ctx->pc = 0x18CEA0u;
label_18cea0:
    // 0x18cea0: 0xae820008  sw          $v0, 0x8($s4)
    ctx->pc = 0x18cea0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 2));
    // 0x18cea4: 0xae800030  sw          $zero, 0x30($s4)
    ctx->pc = 0x18cea4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 48), GPR_U32(ctx, 0));
    // 0x18cea8: 0xc04548e  jal         func_115238
    ctx->pc = 0x18CEA8u;
    SET_GPR_U32(ctx, 31, 0x18CEB0u);
    ctx->pc = 0x18CEACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18CEA8u;
            // 0x18ceac: 0x8e840000  lw          $a0, 0x0($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115238u;
    if (runtime->hasFunction(0x115238u)) {
        auto targetFn = runtime->lookupFunction(0x115238u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CEB0u; }
        if (ctx->pc != 0x18CEB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115238_0x115238(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CEB0u; }
        if (ctx->pc != 0x18CEB0u) { return; }
    }
    ctx->pc = 0x18CEB0u;
label_18ceb0:
    // 0x18ceb0: 0x3c050019  lui         $a1, 0x19
    ctx->pc = 0x18ceb0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)25 << 16));
    // 0x18ceb4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18ceb4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ceb8: 0x24a5cd70  addiu       $a1, $a1, -0x3290
    ctx->pc = 0x18ceb8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954352));
    // 0x18cebc: 0xc0450c0  jal         func_114300
    ctx->pc = 0x18CEBCu;
    SET_GPR_U32(ctx, 31, 0x18CEC4u);
    ctx->pc = 0x18CEC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18CEBCu;
            // 0x18cec0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114300u;
    if (runtime->hasFunction(0x114300u)) {
        auto targetFn = runtime->lookupFunction(0x114300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CEC4u; }
        if (ctx->pc != 0x18CEC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114300_0x114300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CEC4u; }
        if (ctx->pc != 0x18CEC4u) { return; }
    }
    ctx->pc = 0x18CEC4u;
label_18cec4:
    // 0x18cec4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18cec4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18cec8: 0xac22f6e0  sw          $v0, -0x920($at)
    ctx->pc = 0x18cec8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294964960), GPR_U32(ctx, 2));
    // 0x18cecc: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x18ceccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18ced0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x18ced0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18ced4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x18ced4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18ced8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18ced8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18cedc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18cedcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18cee0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18cee0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18cee4: 0x3e00008  jr          $ra
    ctx->pc = 0x18CEE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18CEE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18CEE4u;
            // 0x18cee8: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CE60u: goto label_18ce60;
            case 0x18CE74u: goto label_18ce74;
            case 0x18CEA0u: goto label_18cea0;
            case 0x18CEB0u: goto label_18ceb0;
            case 0x18CEC4u: goto label_18cec4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18CEECu;
    // 0x18ceec: 0x0  nop
    ctx->pc = 0x18ceecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
