#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BFA50
// Address: 0x1bfa50 - 0x1bfb40
void sub_001BFA50_0x1bfa50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BFA50_0x1bfa50");
#endif

    switch (ctx->pc) {
        case 0x1bfa84u: goto label_1bfa84;
        case 0x1bfab4u: goto label_1bfab4;
        case 0x1bfadcu: goto label_1bfadc;
        default: break;
    }

    ctx->pc = 0x1bfa50u;

    // 0x1bfa50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bfa50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bfa54: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bfa54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bfa58: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bfa58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bfa5c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bfa5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bfa60: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1bfa60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1bfa64: 0x1062001b  beq         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1BFA64u;
    {
        const bool branch_taken_0x1bfa64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BFA68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFA64u;
            // 0x1bfa68: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfa64) {
            ctx->pc = 0x1BFAD4u;
            goto label_1bfad4;
        }
    }
    ctx->pc = 0x1BFA6Cu;
    // 0x1bfa6c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFA6Cu;
    {
        const bool branch_taken_0x1bfa6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bfa6c) {
            ctx->pc = 0x1BFA7Cu;
            goto label_1bfa7c;
        }
    }
    ctx->pc = 0x1BFA74u;
    // 0x1bfa74: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1BFA74u;
    {
        const bool branch_taken_0x1bfa74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFA78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFA74u;
            // 0x1bfa78: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfa74) {
            ctx->pc = 0x1BFB30u;
            goto label_1bfb30;
        }
    }
    ctx->pc = 0x1BFA7Cu;
label_1bfa7c:
    // 0x1bfa7c: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFA7Cu;
    SET_GPR_U32(ctx, 31, 0x1BFA84u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFA84u; }
        if (ctx->pc != 0x1BFA84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFA84u; }
        if (ctx->pc != 0x1BFA84u) { return; }
    }
    ctx->pc = 0x1BFA84u;
label_1bfa84:
    // 0x1bfa84: 0x4400029  bltz        $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x1BFA84u;
    {
        const bool branch_taken_0x1bfa84 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfa84) {
            ctx->pc = 0x1BFB2Cu;
            goto label_1bfb2c;
        }
    }
    ctx->pc = 0x1BFA8Cu;
    // 0x1bfa8c: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bfa8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bfa90: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1bfa90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1bfa94: 0x3c060032  lui         $a2, 0x32
    ctx->pc = 0x1bfa94u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)50 << 16));
    // 0x1bfa98: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1bfa98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1bfa9c: 0x26050044  addiu       $a1, $s0, 0x44
    ctx->pc = 0x1bfa9cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
    // 0x1bfaa0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bfaa0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bfaa4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bfaa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bfaa8: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1bfaa8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bfaac: 0xc06043c  jal         func_1810F0
    ctx->pc = 0x1BFAACu;
    SET_GPR_U32(ctx, 31, 0x1BFAB4u);
    ctx->pc = 0x1BFAB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFAACu;
            // 0x1bfab0: 0x24c66ab0  addiu       $a2, $a2, 0x6AB0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 27312));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1810F0u;
    if (runtime->hasFunction(0x1810F0u)) {
        auto targetFn = runtime->lookupFunction(0x1810F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFAB4u; }
        if (ctx->pc != 0x1BFAB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001810F0_0x1810f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFAB4u; }
        if (ctx->pc != 0x1BFAB4u) { return; }
    }
    ctx->pc = 0x1BFAB4u;
label_1bfab4:
    // 0x1bfab4: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFAB4u;
    {
        const bool branch_taken_0x1bfab4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1bfab4) {
            ctx->pc = 0x1BFAC4u;
            goto label_1bfac4;
        }
    }
    ctx->pc = 0x1BFABCu;
    // 0x1bfabc: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1BFABCu;
    {
        const bool branch_taken_0x1bfabc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFAC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFABCu;
            // 0x1bfac0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfabc) {
            ctx->pc = 0x1BFB30u;
            goto label_1bfb30;
        }
    }
    ctx->pc = 0x1BFAC4u;
label_1bfac4:
    // 0x1bfac4: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1bfac4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bfac8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bfac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bfacc: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1BFACCu;
    {
        const bool branch_taken_0x1bfacc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFAD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFACCu;
            // 0x1bfad0: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfacc) {
            ctx->pc = 0x1BFB2Cu;
            goto label_1bfb2c;
        }
    }
    ctx->pc = 0x1BFAD4u;
label_1bfad4:
    // 0x1bfad4: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFAD4u;
    SET_GPR_U32(ctx, 31, 0x1BFADCu);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFADCu; }
        if (ctx->pc != 0x1BFADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFADCu; }
        if (ctx->pc != 0x1BFADCu) { return; }
    }
    ctx->pc = 0x1BFADCu;
label_1bfadc:
    // 0x1bfadc: 0x4400013  bltz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1BFADCu;
    {
        const bool branch_taken_0x1bfadc = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfadc) {
            ctx->pc = 0x1BFB2Cu;
            goto label_1bfb2c;
        }
    }
    ctx->pc = 0x1BFAE4u;
    // 0x1bfae4: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1bfae4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1bfae8: 0x34029002  ori         $v0, $zero, 0x9002
    ctx->pc = 0x1bfae8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36866);
    // 0x1bfaec: 0x9603001c  lhu         $v1, 0x1C($s0)
    ctx->pc = 0x1bfaecu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1bfaf0: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1BFAF0u;
    {
        const bool branch_taken_0x1bfaf0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BFAF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFAF0u;
            // 0x1bfaf4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfaf0) {
            ctx->pc = 0x1BFB24u;
            goto label_1bfb24;
        }
    }
    ctx->pc = 0x1BFAF8u;
    // 0x1bfaf8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1bfaf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bfafc: 0x10620007  beq         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BFAFCu;
    {
        const bool branch_taken_0x1bfafc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1bfafc) {
            ctx->pc = 0x1BFB1Cu;
            goto label_1bfb1c;
        }
    }
    ctx->pc = 0x1BFB04u;
    // 0x1bfb04: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFB04u;
    {
        const bool branch_taken_0x1bfb04 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bfb04) {
            ctx->pc = 0x1BFB14u;
            goto label_1bfb14;
        }
    }
    ctx->pc = 0x1BFB0Cu;
    // 0x1bfb0c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BFB0Cu;
    {
        const bool branch_taken_0x1bfb0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bfb0c) {
            ctx->pc = 0x1BFB24u;
            goto label_1bfb24;
        }
    }
    ctx->pc = 0x1BFB14u;
label_1bfb14:
    // 0x1bfb14: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFB14u;
    {
        const bool branch_taken_0x1bfb14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFB18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFB14u;
            // 0x1bfb18: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfb14) {
            ctx->pc = 0x1BFB24u;
            goto label_1bfb24;
        }
    }
    ctx->pc = 0x1BFB1Cu;
label_1bfb1c:
    // 0x1bfb1c: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1BFB1Cu;
    {
        const bool branch_taken_0x1bfb1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFB20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFB1Cu;
            // 0x1bfb20: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfb1c) {
            ctx->pc = 0x1BFB24u;
            goto label_1bfb24;
        }
    }
    ctx->pc = 0x1BFB24u;
label_1bfb24:
    // 0x1bfb24: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFB24u;
    {
        const bool branch_taken_0x1bfb24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFB28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFB24u;
            // 0x1bfb28: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfb24) {
            ctx->pc = 0x1BFB34u;
            goto label_1bfb34;
        }
    }
    ctx->pc = 0x1BFB2Cu;
label_1bfb2c:
    // 0x1bfb2c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1bfb2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1bfb30:
    // 0x1bfb30: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bfb30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1bfb34:
    // 0x1bfb34: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bfb34u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bfb38: 0x3e00008  jr          $ra
    ctx->pc = 0x1BFB38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BFB3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFB38u;
            // 0x1bfb3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BFA7Cu: goto label_1bfa7c;
            case 0x1BFA84u: goto label_1bfa84;
            case 0x1BFAB4u: goto label_1bfab4;
            case 0x1BFAC4u: goto label_1bfac4;
            case 0x1BFAD4u: goto label_1bfad4;
            case 0x1BFADCu: goto label_1bfadc;
            case 0x1BFB14u: goto label_1bfb14;
            case 0x1BFB1Cu: goto label_1bfb1c;
            case 0x1BFB24u: goto label_1bfb24;
            case 0x1BFB2Cu: goto label_1bfb2c;
            case 0x1BFB30u: goto label_1bfb30;
            case 0x1BFB34u: goto label_1bfb34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BFB40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
