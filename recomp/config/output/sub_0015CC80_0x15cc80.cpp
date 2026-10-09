#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015CC80
// Address: 0x15cc80 - 0x15cff4
void sub_0015CC80_0x15cc80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015CC80_0x15cc80");
#endif

    switch (ctx->pc) {
        case 0x15ccc0u: goto label_15ccc0;
        case 0x15ccd4u: goto label_15ccd4;
        case 0x15ccf8u: goto label_15ccf8;
        case 0x15cd30u: goto label_15cd30;
        case 0x15cd48u: goto label_15cd48;
        case 0x15cd5cu: goto label_15cd5c;
        case 0x15cd7cu: goto label_15cd7c;
        case 0x15cd88u: goto label_15cd88;
        case 0x15cdf4u: goto label_15cdf4;
        case 0x15ce18u: goto label_15ce18;
        case 0x15ce38u: goto label_15ce38;
        case 0x15ce4cu: goto label_15ce4c;
        case 0x15ce54u: goto label_15ce54;
        case 0x15ce74u: goto label_15ce74;
        case 0x15cec8u: goto label_15cec8;
        case 0x15cef4u: goto label_15cef4;
        case 0x15cf00u: goto label_15cf00;
        case 0x15cf10u: goto label_15cf10;
        case 0x15cf20u: goto label_15cf20;
        case 0x15cf28u: goto label_15cf28;
        case 0x15cf3cu: goto label_15cf3c;
        case 0x15cf44u: goto label_15cf44;
        case 0x15cf60u: goto label_15cf60;
        case 0x15cf84u: goto label_15cf84;
        case 0x15cf8cu: goto label_15cf8c;
        case 0x15cf98u: goto label_15cf98;
        case 0x15cfb0u: goto label_15cfb0;
        case 0x15cfb8u: goto label_15cfb8;
        case 0x15cfc8u: goto label_15cfc8;
        default: break;
    }

    ctx->pc = 0x15cc80u;

    // 0x15cc80: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x15cc80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x15cc84: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x15cc84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x15cc88: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x15cc88u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cc8c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x15cc8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x15cc90: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x15cc90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x15cc94: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x15cc94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x15cc98: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x15cc98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x15cc9c: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x15cc9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x15cca0: 0x16400005  bnez        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x15CCA0u;
    {
        const bool branch_taken_0x15cca0 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x15CCA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CCA0u;
            // 0x15cca4: 0xffbf0050  sd          $ra, 0x50($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cca0) {
            ctx->pc = 0x15CCB8u;
            goto label_15ccb8;
        }
    }
    ctx->pc = 0x15CCA8u;
    // 0x15cca8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15cca8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15ccac: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x15CCACu;
    {
        const bool branch_taken_0x15ccac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CCB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CCACu;
            // 0x15ccb0: 0x2484e950  addiu       $a0, $a0, -0x16B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961488));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ccac) {
            ctx->pc = 0x15CD54u;
            goto label_15cd54;
        }
    }
    ctx->pc = 0x15CCB4u;
    // 0x15ccb4: 0x0  nop
    ctx->pc = 0x15ccb4u;
    // NOP
label_15ccb8:
    // 0x15ccb8: 0xc057428  jal         func_15D0A0
    ctx->pc = 0x15CCB8u;
    SET_GPR_U32(ctx, 31, 0x15CCC0u);
    ctx->pc = 0x15D0A0u;
    if (runtime->hasFunction(0x15D0A0u)) {
        auto targetFn = runtime->lookupFunction(0x15D0A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CCC0u; }
        if (ctx->pc != 0x15CCC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D0A0_0x15d0a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CCC0u; }
        if (ctx->pc != 0x15CCC0u) { return; }
    }
    ctx->pc = 0x15CCC0u;
label_15ccc0:
    // 0x15ccc0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15ccc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15ccc4: 0x144300c2  bne         $v0, $v1, . + 4 + (0xC2 << 2)
    ctx->pc = 0x15CCC4u;
    {
        const bool branch_taken_0x15ccc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x15CCC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CCC4u;
            // 0x15ccc8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ccc4) {
            ctx->pc = 0x15CFD0u;
            goto label_15cfd0;
        }
    }
    ctx->pc = 0x15CCCCu;
    // 0x15cccc: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15CCCCu;
    SET_GPR_U32(ctx, 31, 0x15CCD4u);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CCD4u; }
        if (ctx->pc != 0x15CCD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CCD4u; }
        if (ctx->pc != 0x15CCD4u) { return; }
    }
    ctx->pc = 0x15CCD4u;
label_15ccd4:
    // 0x15ccd4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x15ccd4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ccd8: 0x24500068  addiu       $s0, $v0, 0x68
    ctx->pc = 0x15ccd8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 104));
    // 0x15ccdc: 0x24510004  addiu       $s1, $v0, 0x4
    ctx->pc = 0x15ccdcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x15cce0: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x15cce0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x15cce4: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x15CCE4u;
    {
        const bool branch_taken_0x15cce4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CCE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CCE4u;
            // 0x15cce8: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cce4) {
            ctx->pc = 0x15CD20u;
            goto label_15cd20;
        }
    }
    ctx->pc = 0x15CCECu;
    // 0x15ccec: 0x200182d  daddu       $v1, $s0, $zero
    ctx->pc = 0x15ccecu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ccf0: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x15ccf0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x15ccf4: 0x0  nop
    ctx->pc = 0x15ccf4u;
    // NOP
label_15ccf8:
    // 0x15ccf8: 0x28820008  slti        $v0, $a0, 0x8
    ctx->pc = 0x15ccf8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x15ccfc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15CCFCu;
    {
        const bool branch_taken_0x15ccfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CD00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CCFCu;
            // 0x15cd00: 0x24630210  addiu       $v1, $v1, 0x210 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 528));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ccfc) {
            ctx->pc = 0x15CD1Cu;
            goto label_15cd1c;
        }
    }
    ctx->pc = 0x15CD04u;
    // 0x15cd04: 0x60802d  daddu       $s0, $v1, $zero
    ctx->pc = 0x15cd04u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cd08: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x15cd08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x15cd0c: 0x0  nop
    ctx->pc = 0x15cd0cu;
    // NOP
    // 0x15cd10: 0x0  nop
    ctx->pc = 0x15cd10u;
    // NOP
    // 0x15cd14: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x15CD14u;
    {
        const bool branch_taken_0x15cd14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15cd14) {
            ctx->pc = 0x15CD18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15CD14u;
            // 0x15cd18: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15CCF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15ccf8;
        }
    }
    ctx->pc = 0x15CD1Cu;
label_15cd1c:
    // 0x15cd1c: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x15cd1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_15cd20:
    // 0x15cd20: 0x54820007  bnel        $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15CD20u;
    {
        const bool branch_taken_0x15cd20 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x15cd20) {
            ctx->pc = 0x15CD24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15CD20u;
            // 0x15cd24: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15CD40u;
            goto label_15cd40;
        }
    }
    ctx->pc = 0x15CD28u;
    // 0x15cd28: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15CD28u;
    SET_GPR_U32(ctx, 31, 0x15CD30u);
    ctx->pc = 0x15CD2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CD28u;
            // 0x15cd2c: 0x2404fff5  addiu       $a0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CD30u; }
        if (ctx->pc != 0x15CD30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CD30u; }
        if (ctx->pc != 0x15CD30u) { return; }
    }
    ctx->pc = 0x15CD30u;
label_15cd30:
    // 0x15cd30: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15cd30u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15cd34: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x15CD34u;
    {
        const bool branch_taken_0x15cd34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CD38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CD34u;
            // 0x15cd38: 0x2484e980  addiu       $a0, $a0, -0x1680 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961536));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cd34) {
            ctx->pc = 0x15CD54u;
            goto label_15cd54;
        }
    }
    ctx->pc = 0x15CD3Cu;
    // 0x15cd3c: 0x0  nop
    ctx->pc = 0x15cd3cu;
    // NOP
label_15cd40:
    // 0x15cd40: 0xc0573fe  jal         func_15CFF8
    ctx->pc = 0x15CD40u;
    SET_GPR_U32(ctx, 31, 0x15CD48u);
    ctx->pc = 0x15CD44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CD40u;
            // 0x15cd44: 0x2415ffff  addiu       $s5, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15CFF8u;
    if (runtime->hasFunction(0x15CFF8u)) {
        auto targetFn = runtime->lookupFunction(0x15CFF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CD48u; }
        if (ctx->pc != 0x15CD48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015CFF8_0x15cff8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CD48u; }
        if (ctx->pc != 0x15CD48u) { return; }
    }
    ctx->pc = 0x15CD48u;
label_15cd48:
    // 0x15cd48: 0x14550007  bne         $v0, $s5, . + 4 + (0x7 << 2)
    ctx->pc = 0x15CD48u;
    {
        const bool branch_taken_0x15cd48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 21));
        ctx->pc = 0x15CD4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CD48u;
            // 0x15cd4c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cd48) {
            ctx->pc = 0x15CD68u;
            goto label_15cd68;
        }
    }
    ctx->pc = 0x15CD50u;
    // 0x15cd50: 0x2484e9b0  addiu       $a0, $a0, -0x1650
    ctx->pc = 0x15cd50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961584));
label_15cd54:
    // 0x15cd54: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15CD54u;
    SET_GPR_U32(ctx, 31, 0x15CD5Cu);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CD5Cu; }
        if (ctx->pc != 0x15CD5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CD5Cu; }
        if (ctx->pc != 0x15CD5Cu) { return; }
    }
    ctx->pc = 0x15CD5Cu;
label_15cd5c:
    // 0x15cd5c: 0x1000009c  b           . + 4 + (0x9C << 2)
    ctx->pc = 0x15CD5Cu;
    {
        const bool branch_taken_0x15cd5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CD60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CD5Cu;
            // 0x15cd60: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cd5c) {
            ctx->pc = 0x15CFD0u;
            goto label_15cfd0;
        }
    }
    ctx->pc = 0x15CD64u;
    // 0x15cd64: 0x0  nop
    ctx->pc = 0x15cd64u;
    // NOP
label_15cd68:
    // 0x15cd68: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x15CD68u;
    {
        const bool branch_taken_0x15cd68 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CD6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CD68u;
            // 0x15cd6c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cd68) {
            ctx->pc = 0x15CD7Cu;
            goto label_15cd7c;
        }
    }
    ctx->pc = 0x15CD70u;
    // 0x15cd70: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15cd70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cd74: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x15CD74u;
    SET_GPR_U32(ctx, 31, 0x15CD7Cu);
    ctx->pc = 0x15CD78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CD74u;
            // 0x15cd78: 0x24060210  addiu       $a2, $zero, 0x210 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CD7Cu; }
        if (ctx->pc != 0x15CD7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CD7Cu; }
        if (ctx->pc != 0x15CD7Cu) { return; }
    }
    ctx->pc = 0x15CD7Cu;
label_15cd7c:
    // 0x15cd7c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15cd7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cd80: 0xc057412  jal         func_15D048
    ctx->pc = 0x15CD80u;
    SET_GPR_U32(ctx, 31, 0x15CD88u);
    ctx->pc = 0x15CD84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CD80u;
            // 0x15cd84: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D048u;
    if (runtime->hasFunction(0x15D048u)) {
        auto targetFn = runtime->lookupFunction(0x15D048u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CD88u; }
        if (ctx->pc != 0x15CD88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D048_0x15d048(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CD88u; }
        if (ctx->pc != 0x15CD88u) { return; }
    }
    ctx->pc = 0x15CD88u;
label_15cd88:
    // 0x15cd88: 0x6a420007  ldl         $v0, 0x7($s2)
    ctx->pc = 0x15cd88u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x15cd8c: 0x6e420000  ldr         $v0, 0x0($s2)
    ctx->pc = 0x15cd8cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x15cd90: 0x6a43000f  ldl         $v1, 0xF($s2)
    ctx->pc = 0x15cd90u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x15cd94: 0x6e430008  ldr         $v1, 0x8($s2)
    ctx->pc = 0x15cd94u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x15cd98: 0x6a440017  ldl         $a0, 0x17($s2)
    ctx->pc = 0x15cd98u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x15cd9c: 0x6e440010  ldr         $a0, 0x10($s2)
    ctx->pc = 0x15cd9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x15cda0: 0x6a45001f  ldl         $a1, 0x1F($s2)
    ctx->pc = 0x15cda0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x15cda4: 0x6e450018  ldr         $a1, 0x18($s2)
    ctx->pc = 0x15cda4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x15cda8: 0xb2020013  sdl         $v0, 0x13($s0)
    ctx->pc = 0x15cda8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 19); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cdac: 0xb602000c  sdr         $v0, 0xC($s0)
    ctx->pc = 0x15cdacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 12); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cdb0: 0xb203001b  sdl         $v1, 0x1B($s0)
    ctx->pc = 0x15cdb0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 27); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cdb4: 0xb6030014  sdr         $v1, 0x14($s0)
    ctx->pc = 0x15cdb4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 20); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cdb8: 0xb2040023  sdl         $a0, 0x23($s0)
    ctx->pc = 0x15cdb8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 35); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cdbc: 0xb604001c  sdr         $a0, 0x1C($s0)
    ctx->pc = 0x15cdbcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 28); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cdc0: 0xb205002b  sdl         $a1, 0x2B($s0)
    ctx->pc = 0x15cdc0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 43); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cdc4: 0xb6050024  sdr         $a1, 0x24($s0)
    ctx->pc = 0x15cdc4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 36); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cdc8: 0x6a420027  ldl         $v0, 0x27($s2)
    ctx->pc = 0x15cdc8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x15cdcc: 0x6e420020  ldr         $v0, 0x20($s2)
    ctx->pc = 0x15cdccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x15cdd0: 0x6a43002f  ldl         $v1, 0x2F($s2)
    ctx->pc = 0x15cdd0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x15cdd4: 0x6e430028  ldr         $v1, 0x28($s2)
    ctx->pc = 0x15cdd4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x15cdd8: 0xb2020033  sdl         $v0, 0x33($s0)
    ctx->pc = 0x15cdd8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 51); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cddc: 0xb602002c  sdr         $v0, 0x2C($s0)
    ctx->pc = 0x15cddcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 44); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cde0: 0xb203003b  sdl         $v1, 0x3B($s0)
    ctx->pc = 0x15cde0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 59); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cde4: 0xb6030034  sdr         $v1, 0x34($s0)
    ctx->pc = 0x15cde4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 52); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15cde8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15cde8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cdec: 0xc057084  jal         func_15C210
    ctx->pc = 0x15CDECu;
    SET_GPR_U32(ctx, 31, 0x15CDF4u);
    ctx->pc = 0x15CDF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CDECu;
            // 0x15cdf0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15C210u;
    if (runtime->hasFunction(0x15C210u)) {
        auto targetFn = runtime->lookupFunction(0x15C210u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CDF4u; }
        if (ctx->pc != 0x15CDF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015C210_0x15c210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CDF4u; }
        if (ctx->pc != 0x15CDF4u) { return; }
    }
    ctx->pc = 0x15CDF4u;
label_15cdf4:
    // 0x15cdf4: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x15cdf4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cdf8: 0x16600005  bnez        $s3, . + 4 + (0x5 << 2)
    ctx->pc = 0x15CDF8u;
    {
        const bool branch_taken_0x15cdf8 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x15CDFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CDF8u;
            // 0x15cdfc: 0xae130040  sw          $s3, 0x40($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cdf8) {
            ctx->pc = 0x15CE10u;
            goto label_15ce10;
        }
    }
    ctx->pc = 0x15CE00u;
    // 0x15ce00: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15ce00u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15ce04: 0x10000068  b           . + 4 + (0x68 << 2)
    ctx->pc = 0x15CE04u;
    {
        const bool branch_taken_0x15ce04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CE08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CE04u;
            // 0x15ce08: 0x2484e9f0  addiu       $a0, $a0, -0x1610 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961648));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ce04) {
            ctx->pc = 0x15CFA8u;
            goto label_15cfa8;
        }
    }
    ctx->pc = 0x15CE0Cu;
    // 0x15ce0c: 0x0  nop
    ctx->pc = 0x15ce0cu;
    // NOP
label_15ce10:
    // 0x15ce10: 0xc057230  jal         func_15C8C0
    ctx->pc = 0x15CE10u;
    SET_GPR_U32(ctx, 31, 0x15CE18u);
    ctx->pc = 0x15CE14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CE10u;
            // 0x15ce14: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15C8C0u;
    if (runtime->hasFunction(0x15C8C0u)) {
        auto targetFn = runtime->lookupFunction(0x15C8C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CE18u; }
        if (ctx->pc != 0x15CE18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015C8C0_0x15c8c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CE18u; }
        if (ctx->pc != 0x15CE18u) { return; }
    }
    ctx->pc = 0x15CE18u;
label_15ce18:
    // 0x15ce18: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15ce18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ce1c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15ce1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ce20: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x15ce20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x15ce24: 0x27a70008  addiu       $a3, $sp, 0x8
    ctx->pc = 0x15ce24u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x15ce28: 0x27a8000c  addiu       $t0, $sp, 0xC
    ctx->pc = 0x15ce28u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x15ce2c: 0x27a90010  addiu       $t1, $sp, 0x10
    ctx->pc = 0x15ce2cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x15ce30: 0xc056ee8  jal         func_15BBA0
    ctx->pc = 0x15CE30u;
    SET_GPR_U32(ctx, 31, 0x15CE38u);
    ctx->pc = 0x15CE34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CE30u;
            // 0x15ce34: 0x27aa0014  addiu       $t2, $sp, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BBA0u;
    if (runtime->hasFunction(0x15BBA0u)) {
        auto targetFn = runtime->lookupFunction(0x15BBA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CE38u; }
        if (ctx->pc != 0x15CE38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BBA0_0x15bba0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CE38u; }
        if (ctx->pc != 0x15CE38u) { return; }
    }
    ctx->pc = 0x15CE38u;
label_15ce38:
    // 0x15ce38: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15ce38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ce3c: 0x8e260004  lw          $a2, 0x4($s1)
    ctx->pc = 0x15ce3cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x15ce40: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x15ce40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ce44: 0xc05729a  jal         func_15CA68
    ctx->pc = 0x15CE44u;
    SET_GPR_U32(ctx, 31, 0x15CE4Cu);
    ctx->pc = 0x15CE48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CE44u;
            // 0x15ce48: 0x8e270008  lw          $a3, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15CA68u;
    if (runtime->hasFunction(0x15CA68u)) {
        auto targetFn = runtime->lookupFunction(0x15CA68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CE4Cu; }
        if (ctx->pc != 0x15CE4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015CA68_0x15ca68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CE4Cu; }
        if (ctx->pc != 0x15CE4Cu) { return; }
    }
    ctx->pc = 0x15CE4Cu;
label_15ce4c:
    // 0x15ce4c: 0xc057316  jal         func_15CC58
    ctx->pc = 0x15CE4Cu;
    SET_GPR_U32(ctx, 31, 0x15CE54u);
    ctx->pc = 0x15CE50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CE4Cu;
            // 0x15ce50: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15CC58u;
    if (runtime->hasFunction(0x15CC58u)) {
        auto targetFn = runtime->lookupFunction(0x15CC58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CE54u; }
        if (ctx->pc != 0x15CE54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015CC58_0x15cc58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CE54u; }
        if (ctx->pc != 0x15CE54u) { return; }
    }
    ctx->pc = 0x15CE54u;
label_15ce54:
    // 0x15ce54: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x15CE54u;
    {
        const bool branch_taken_0x15ce54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15CE58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CE54u;
            // 0x15ce58: 0xae02012c  sw          $v0, 0x12C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 300), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ce54) {
            ctx->pc = 0x15CE68u;
            goto label_15ce68;
        }
    }
    ctx->pc = 0x15CE5Cu;
    // 0x15ce5c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15ce5cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15ce60: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x15CE60u;
    {
        const bool branch_taken_0x15ce60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CE64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CE60u;
            // 0x15ce64: 0x2484ea18  addiu       $a0, $a0, -0x15E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961688));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ce60) {
            ctx->pc = 0x15CFA8u;
            goto label_15cfa8;
        }
    }
    ctx->pc = 0x15CE68u;
label_15ce68:
    // 0x15ce68: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x15ce68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ce6c: 0xc04fcd8  jal         func_13F360
    ctx->pc = 0x15CE6Cu;
    SET_GPR_U32(ctx, 31, 0x15CE74u);
    ctx->pc = 0x15CE70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CE6Cu;
            // 0x15ce70: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F360u;
    if (runtime->hasFunction(0x13F360u)) {
        auto targetFn = runtime->lookupFunction(0x13F360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CE74u; }
        if (ctx->pc != 0x15CE74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F360_0x13f360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CE74u; }
        if (ctx->pc != 0x15CE74u) { return; }
    }
    ctx->pc = 0x15CE74u;
label_15ce74:
    // 0x15ce74: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x15CE74u;
    {
        const bool branch_taken_0x15ce74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15CE78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CE74u;
            // 0x15ce78: 0xae02014c  sw          $v0, 0x14C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 332), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ce74) {
            ctx->pc = 0x15CE88u;
            goto label_15ce88;
        }
    }
    ctx->pc = 0x15CE7Cu;
    // 0x15ce7c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15ce7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15ce80: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x15CE80u;
    {
        const bool branch_taken_0x15ce80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CE84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CE80u;
            // 0x15ce84: 0x2484ea40  addiu       $a0, $a0, -0x15C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961728));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ce80) {
            ctx->pc = 0x15CFA8u;
            goto label_15cfa8;
        }
    }
    ctx->pc = 0x15CE88u;
label_15ce88:
    // 0x15ce88: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x15ce88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ce8c: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x15ce8cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15ce90: 0xae14003c  sw          $s4, 0x3C($s0)
    ctx->pc = 0x15ce90u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 20));
    // 0x15ce94: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x15ce94u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15ce98: 0xae020058  sw          $v0, 0x58($s0)
    ctx->pc = 0x15ce98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 2));
    // 0x15ce9c: 0x2463dce8  addiu       $v1, $v1, -0x2318
    ctx->pc = 0x15ce9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294958312));
    // 0x15cea0: 0xae000068  sw          $zero, 0x68($s0)
    ctx->pc = 0x15cea0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 104), GPR_U32(ctx, 0));
    // 0x15cea4: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x15cea4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x15cea8: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x15cea8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x15ceac: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x15ceacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ceb0: 0x8e420020  lw          $v0, 0x20($s2)
    ctx->pc = 0x15ceb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 32)));
    // 0x15ceb4: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x15ceb4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x15ceb8: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x15ceb8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x15cebc: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x15cebcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cec0: 0xc05d63c  jal         func_1758F0
    ctx->pc = 0x15CEC0u;
    SET_GPR_U32(ctx, 31, 0x15CEC8u);
    ctx->pc = 0x15CEC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CEC0u;
            // 0x15cec4: 0xae020050  sw          $v0, 0x50($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1758F0u;
    if (runtime->hasFunction(0x1758F0u)) {
        auto targetFn = runtime->lookupFunction(0x1758F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CEC8u; }
        if (ctx->pc != 0x15CEC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001758F0_0x1758f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CEC8u; }
        if (ctx->pc != 0x15CEC8u) { return; }
    }
    ctx->pc = 0x15CEC8u;
label_15cec8:
    // 0x15cec8: 0x54400001  bnel        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x15CEC8u;
    {
        const bool branch_taken_0x15cec8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15cec8) {
            ctx->pc = 0x15CECCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15CEC8u;
            // 0x15cecc: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15CED0u;
            goto label_15ced0;
        }
    }
    ctx->pc = 0x15CED0u;
label_15ced0:
    // 0x15ced0: 0xae14006c  sw          $s4, 0x6C($s0)
    ctx->pc = 0x15ced0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 108), GPR_U32(ctx, 20));
    // 0x15ced4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15ced4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ced8: 0xa2000070  sb          $zero, 0x70($s0)
    ctx->pc = 0x15ced8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 112), (uint8_t)GPR_U32(ctx, 0));
    // 0x15cedc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15cedcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cee0: 0xa2000071  sb          $zero, 0x71($s0)
    ctx->pc = 0x15cee0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 113), (uint8_t)GPR_U32(ctx, 0));
    // 0x15cee4: 0xa2000072  sb          $zero, 0x72($s0)
    ctx->pc = 0x15cee4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 114), (uint8_t)GPR_U32(ctx, 0));
    // 0x15cee8: 0xa2000073  sb          $zero, 0x73($s0)
    ctx->pc = 0x15cee8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 115), (uint8_t)GPR_U32(ctx, 0));
    // 0x15ceec: 0xc0590ae  jal         func_1642B8
    ctx->pc = 0x15CEECu;
    SET_GPR_U32(ctx, 31, 0x15CEF4u);
    ctx->pc = 0x15CEF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CEECu;
            // 0x15cef0: 0xae00005c  sw          $zero, 0x5C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1642B8u;
    if (runtime->hasFunction(0x1642B8u)) {
        auto targetFn = runtime->lookupFunction(0x1642B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CEF4u; }
        if (ctx->pc != 0x15CEF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001642B8_0x1642b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CEF4u; }
        if (ctx->pc != 0x15CEF4u) { return; }
    }
    ctx->pc = 0x15CEF4u;
label_15cef4:
    // 0x15cef4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15cef4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cef8: 0xc0590b2  jal         func_1642C8
    ctx->pc = 0x15CEF8u;
    SET_GPR_U32(ctx, 31, 0x15CF00u);
    ctx->pc = 0x15CEFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CEF8u;
            // 0x15cefc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1642C8u;
    if (runtime->hasFunction(0x1642C8u)) {
        auto targetFn = runtime->lookupFunction(0x1642C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF00u; }
        if (ctx->pc != 0x15CF00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001642C8_0x1642c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF00u; }
        if (ctx->pc != 0x15CF00u) { return; }
    }
    ctx->pc = 0x15CF00u;
label_15cf00:
    // 0x15cf00: 0xae000054  sw          $zero, 0x54($s0)
    ctx->pc = 0x15cf00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 0));
    // 0x15cf04: 0xae000084  sw          $zero, 0x84($s0)
    ctx->pc = 0x15cf04u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 132), GPR_U32(ctx, 0));
    // 0x15cf08: 0xc059170  jal         func_1645C0
    ctx->pc = 0x15CF08u;
    SET_GPR_U32(ctx, 31, 0x15CF10u);
    ctx->pc = 0x15CF0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF08u;
            // 0x15cf0c: 0x8e04012c  lw          $a0, 0x12C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 300)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1645C0u;
    if (runtime->hasFunction(0x1645C0u)) {
        auto targetFn = runtime->lookupFunction(0x1645C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF10u; }
        if (ctx->pc != 0x15CF10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001645C0_0x1645c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF10u; }
        if (ctx->pc != 0x15CF10u) { return; }
    }
    ctx->pc = 0x15CF10u;
label_15cf10:
    // 0x15cf10: 0x10400027  beqz        $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x15CF10u;
    {
        const bool branch_taken_0x15cf10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CF14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF10u;
            // 0x15cf14: 0xae020044  sw          $v0, 0x44($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cf10) {
            ctx->pc = 0x15CFB0u;
            goto label_15cfb0;
        }
    }
    ctx->pc = 0x15CF18u;
    // 0x15cf18: 0xc057d6c  jal         func_15F5B0
    ctx->pc = 0x15CF18u;
    SET_GPR_U32(ctx, 31, 0x15CF20u);
    ctx->pc = 0x15CF1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF18u;
            // 0x15cf1c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F5B0u;
    if (runtime->hasFunction(0x15F5B0u)) {
        auto targetFn = runtime->lookupFunction(0x15F5B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF20u; }
        if (ctx->pc != 0x15CF20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F5B0_0x15f5b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF20u; }
        if (ctx->pc != 0x15CF20u) { return; }
    }
    ctx->pc = 0x15CF20u;
label_15cf20:
    // 0x15cf20: 0xc04f2ec  jal         func_13CBB0
    ctx->pc = 0x15CF20u;
    SET_GPR_U32(ctx, 31, 0x15CF28u);
    ctx->pc = 0x15CF24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF20u;
            // 0x15cf24: 0x8e04012c  lw          $a0, 0x12C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 300)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CBB0u;
    if (runtime->hasFunction(0x13CBB0u)) {
        auto targetFn = runtime->lookupFunction(0x13CBB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF28u; }
        if (ctx->pc != 0x15CF28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CBB0_0x13cbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF28u; }
        if (ctx->pc != 0x15CF28u) { return; }
    }
    ctx->pc = 0x15CF28u;
label_15cf28:
    // 0x15cf28: 0xae000074  sw          $zero, 0x74($s0)
    ctx->pc = 0x15cf28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 116), GPR_U32(ctx, 0));
    // 0x15cf2c: 0xae02004c  sw          $v0, 0x4C($s0)
    ctx->pc = 0x15cf2cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 2));
    // 0x15cf30: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15cf30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cf34: 0xc04f342  jal         func_13CD08
    ctx->pc = 0x15CF34u;
    SET_GPR_U32(ctx, 31, 0x15CF3Cu);
    ctx->pc = 0x15CF38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF34u;
            // 0x15cf38: 0x8e050044  lw          $a1, 0x44($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CD08u;
    if (runtime->hasFunction(0x13CD08u)) {
        auto targetFn = runtime->lookupFunction(0x13CD08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF3Cu; }
        if (ctx->pc != 0x15CF3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CD08_0x13cd08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF3Cu; }
        if (ctx->pc != 0x15CF3Cu) { return; }
    }
    ctx->pc = 0x15CF3Cu;
label_15cf3c:
    // 0x15cf3c: 0xc057442  jal         func_15D108
    ctx->pc = 0x15CF3Cu;
    SET_GPR_U32(ctx, 31, 0x15CF44u);
    ctx->pc = 0x15CF40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF3Cu;
            // 0x15cf40: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D108u;
    if (runtime->hasFunction(0x15D108u)) {
        auto targetFn = runtime->lookupFunction(0x15D108u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF44u; }
        if (ctx->pc != 0x15CF44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D108_0x15d108(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF44u; }
        if (ctx->pc != 0x15CF44u) { return; }
    }
    ctx->pc = 0x15CF44u;
label_15cf44:
    // 0x15cf44: 0x1055001a  beq         $v0, $s5, . + 4 + (0x1A << 2)
    ctx->pc = 0x15CF44u;
    {
        const bool branch_taken_0x15cf44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 21));
        if (branch_taken_0x15cf44) {
            ctx->pc = 0x15CFB0u;
            goto label_15cfb0;
        }
    }
    ctx->pc = 0x15CF4Cu;
    // 0x15cf4c: 0x8e47000c  lw          $a3, 0xC($s2)
    ctx->pc = 0x15cf4cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x15cf50: 0x8e0400ac  lw          $a0, 0xAC($s0)
    ctx->pc = 0x15cf50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 172)));
    // 0x15cf54: 0x8e0500b0  lw          $a1, 0xB0($s0)
    ctx->pc = 0x15cf54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 176)));
    // 0x15cf58: 0xc0582d8  jal         func_160B60
    ctx->pc = 0x15CF58u;
    SET_GPR_U32(ctx, 31, 0x15CF60u);
    ctx->pc = 0x15CF5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF58u;
            // 0x15cf5c: 0x8e460008  lw          $a2, 0x8($s2) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B60u;
    if (runtime->hasFunction(0x160B60u)) {
        auto targetFn = runtime->lookupFunction(0x160B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF60u; }
        if (ctx->pc != 0x15CF60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B60_0x160b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF60u; }
        if (ctx->pc != 0x15CF60u) { return; }
    }
    ctx->pc = 0x15CF60u;
label_15cf60:
    // 0x15cf60: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x15CF60u;
    {
        const bool branch_taken_0x15cf60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15cf60) {
            ctx->pc = 0x15CF64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF60u;
            // 0x15cf64: 0xae0200a8  sw          $v0, 0xA8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 168), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15CF78u;
            goto label_15cf78;
        }
    }
    ctx->pc = 0x15CF68u;
    // 0x15cf68: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15cf68u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15cf6c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x15CF6Cu;
    {
        const bool branch_taken_0x15cf6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CF70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF6Cu;
            // 0x15cf70: 0x2484ea68  addiu       $a0, $a0, -0x1598 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cf6c) {
            ctx->pc = 0x15CFA8u;
            goto label_15cfa8;
        }
    }
    ctx->pc = 0x15CF74u;
    // 0x15cf74: 0x0  nop
    ctx->pc = 0x15cf74u;
    // NOP
label_15cf78:
    // 0x15cf78: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15cf78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cf7c: 0xc05853a  jal         func_1614E8
    ctx->pc = 0x15CF7Cu;
    SET_GPR_U32(ctx, 31, 0x15CF84u);
    ctx->pc = 0x15CF80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF7Cu;
            // 0x15cf80: 0x8e05002c  lw          $a1, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1614E8u;
    if (runtime->hasFunction(0x1614E8u)) {
        auto targetFn = runtime->lookupFunction(0x1614E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF84u; }
        if (ctx->pc != 0x15CF84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001614E8_0x1614e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF84u; }
        if (ctx->pc != 0x15CF84u) { return; }
    }
    ctx->pc = 0x15CF84u;
label_15cf84:
    // 0x15cf84: 0xc05863a  jal         func_1618E8
    ctx->pc = 0x15CF84u;
    SET_GPR_U32(ctx, 31, 0x15CF8Cu);
    ctx->pc = 0x15CF88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF84u;
            // 0x15cf88: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1618E8u;
    if (runtime->hasFunction(0x1618E8u)) {
        auto targetFn = runtime->lookupFunction(0x1618E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF8Cu; }
        if (ctx->pc != 0x15CF8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001618E8_0x1618e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF8Cu; }
        if (ctx->pc != 0x15CF8Cu) { return; }
    }
    ctx->pc = 0x15CF8Cu;
label_15cf8c:
    // 0x15cf8c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15cf8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15cf90: 0xc05865e  jal         func_161978
    ctx->pc = 0x15CF90u;
    SET_GPR_U32(ctx, 31, 0x15CF98u);
    ctx->pc = 0x15CF94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CF90u;
            // 0x15cf94: 0xae0200e8  sw          $v0, 0xE8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 232), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161978u;
    if (runtime->hasFunction(0x161978u)) {
        auto targetFn = runtime->lookupFunction(0x161978u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF98u; }
        if (ctx->pc != 0x15CF98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00161978_0x161978(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CF98u; }
        if (ctx->pc != 0x15CF98u) { return; }
    }
    ctx->pc = 0x15CF98u;
label_15cf98:
    // 0x15cf98: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x15CF98u;
    {
        const bool branch_taken_0x15cf98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15cf98) {
            ctx->pc = 0x15CFC0u;
            goto label_15cfc0;
        }
    }
    ctx->pc = 0x15CFA0u;
    // 0x15cfa0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15cfa0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15cfa4: 0x2484ea88  addiu       $a0, $a0, -0x1578
    ctx->pc = 0x15cfa4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961800));
label_15cfa8:
    // 0x15cfa8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15CFA8u;
    SET_GPR_U32(ctx, 31, 0x15CFB0u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CFB0u; }
        if (ctx->pc != 0x15CFB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CFB0u; }
        if (ctx->pc != 0x15CFB0u) { return; }
    }
    ctx->pc = 0x15CFB0u;
label_15cfb0:
    // 0x15cfb0: 0xc057474  jal         func_15D1D0
    ctx->pc = 0x15CFB0u;
    SET_GPR_U32(ctx, 31, 0x15CFB8u);
    ctx->pc = 0x15CFB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CFB0u;
            // 0x15cfb4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D1D0u;
    if (runtime->hasFunction(0x15D1D0u)) {
        auto targetFn = runtime->lookupFunction(0x15D1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CFB8u; }
        if (ctx->pc != 0x15CFB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D1D0_0x15d1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CFB8u; }
        if (ctx->pc != 0x15CFB8u) { return; }
    }
    ctx->pc = 0x15CFB8u;
label_15cfb8:
    // 0x15cfb8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15CFB8u;
    {
        const bool branch_taken_0x15cfb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15CFBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CFB8u;
            // 0x15cfbc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15cfb8) {
            ctx->pc = 0x15CFD0u;
            goto label_15cfd0;
        }
    }
    ctx->pc = 0x15CFC0u;
label_15cfc0:
    // 0x15cfc0: 0xc058676  jal         func_1619D8
    ctx->pc = 0x15CFC0u;
    SET_GPR_U32(ctx, 31, 0x15CFC8u);
    ctx->pc = 0x15CFC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CFC0u;
            // 0x15cfc4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1619D8u;
    if (runtime->hasFunction(0x1619D8u)) {
        auto targetFn = runtime->lookupFunction(0x1619D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CFC8u; }
        if (ctx->pc != 0x15CFC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001619D8_0x1619d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15CFC8u; }
        if (ctx->pc != 0x15CFC8u) { return; }
    }
    ctx->pc = 0x15CFC8u;
label_15cfc8:
    // 0x15cfc8: 0xae140004  sw          $s4, 0x4($s0)
    ctx->pc = 0x15cfc8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 20));
    // 0x15cfcc: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x15cfccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_15cfd0:
    // 0x15cfd0: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x15cfd0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15cfd4: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x15cfd4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15cfd8: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x15cfd8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15cfdc: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x15cfdcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15cfe0: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x15cfe0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15cfe4: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x15cfe4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x15cfe8: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x15cfe8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x15cfec: 0x3e00008  jr          $ra
    ctx->pc = 0x15CFECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15CFF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15CFECu;
            // 0x15cff0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15CCB8u: goto label_15ccb8;
            case 0x15CCC0u: goto label_15ccc0;
            case 0x15CCD4u: goto label_15ccd4;
            case 0x15CCF8u: goto label_15ccf8;
            case 0x15CD1Cu: goto label_15cd1c;
            case 0x15CD20u: goto label_15cd20;
            case 0x15CD30u: goto label_15cd30;
            case 0x15CD40u: goto label_15cd40;
            case 0x15CD48u: goto label_15cd48;
            case 0x15CD54u: goto label_15cd54;
            case 0x15CD5Cu: goto label_15cd5c;
            case 0x15CD68u: goto label_15cd68;
            case 0x15CD7Cu: goto label_15cd7c;
            case 0x15CD88u: goto label_15cd88;
            case 0x15CDF4u: goto label_15cdf4;
            case 0x15CE10u: goto label_15ce10;
            case 0x15CE18u: goto label_15ce18;
            case 0x15CE38u: goto label_15ce38;
            case 0x15CE4Cu: goto label_15ce4c;
            case 0x15CE54u: goto label_15ce54;
            case 0x15CE68u: goto label_15ce68;
            case 0x15CE74u: goto label_15ce74;
            case 0x15CE88u: goto label_15ce88;
            case 0x15CEC8u: goto label_15cec8;
            case 0x15CED0u: goto label_15ced0;
            case 0x15CEF4u: goto label_15cef4;
            case 0x15CF00u: goto label_15cf00;
            case 0x15CF10u: goto label_15cf10;
            case 0x15CF20u: goto label_15cf20;
            case 0x15CF28u: goto label_15cf28;
            case 0x15CF3Cu: goto label_15cf3c;
            case 0x15CF44u: goto label_15cf44;
            case 0x15CF60u: goto label_15cf60;
            case 0x15CF78u: goto label_15cf78;
            case 0x15CF84u: goto label_15cf84;
            case 0x15CF8Cu: goto label_15cf8c;
            case 0x15CF98u: goto label_15cf98;
            case 0x15CFA8u: goto label_15cfa8;
            case 0x15CFB0u: goto label_15cfb0;
            case 0x15CFB8u: goto label_15cfb8;
            case 0x15CFC0u: goto label_15cfc0;
            case 0x15CFC8u: goto label_15cfc8;
            case 0x15CFD0u: goto label_15cfd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15CFF4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
